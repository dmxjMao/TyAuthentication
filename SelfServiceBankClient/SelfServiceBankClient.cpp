
// SelfServiceBankClient.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "SelfServiceBankClientDlg.h"

#include <boost/log/expressions.hpp> //格式化
#include <boost/date_time/posix_time/posix_time_types.hpp> //时间格式
#include <boost/log/support/date_time.hpp>
#include <boost/locale/generator.hpp>

//#include <boost/smart_ptr/shared_ptr.hpp>
//#include <boost/smart_ptr/make_shared_object.hpp>
//#include <boost/log/sinks/sync_frontend.hpp>
//#include <boost/log/sinks/text_ostream_backend.hpp>
//#include <boost/log/sources/record_ostream.hpp>
//#include <boost/core/null_deleter.hpp>

#include <boost/log/sources/severity_logger.hpp> //级别 源
#include <boost/log/utility/setup/common_attributes.hpp> //公共属性
#include <boost/log/utility/setup/file.hpp> //sink 文件

#include "ZCMsgManager.h"
#include "LogDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//boost日志
namespace logging = boost::log;
namespace src = logging::sources;
namespace sinks = logging::sinks;
namespace keywords = logging::keywords;
namespace expr = boost::log::expressions;
using namespace logging::trivial;

src::wseverity_logger< severity_level > g_slog;//级别日志器
//BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::logger_mt)

// CSelfServiceBankClientApp

BEGIN_MESSAGE_MAP(CSelfServiceBankClientApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSelfServiceBankClientApp construction

CSelfServiceBankClientApp::CSelfServiceBankClientApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CSelfServiceBankClientApp object

CSelfServiceBankClientApp theApp;
CGobalVariable g_GobalVariable; //全局变量

// CSelfServiceBankClientApp initialization

BOOL CSelfServiceBankClientApp::InitInstance()
{
	//内存检查
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	//全局变量初始化
	g_GobalVariable.Init();

	//初始化日志
	InitLog();

	//初始化消息处理函数
	InitZCMsgHandler();

	//初始化消息服务
	if (! CZCMsgManager::Instance()->Init(0))
		return FALSE;

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CSelfServiceBankClientDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager; pShellManager = nullptr;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}



int CSelfServiceBankClientApp::ExitInstance()
{
	//内存检查
	_CrtDumpMemoryLeaks();

	return CWinApp::ExitInstance();
}

bool CSelfServiceBankClientApp::InitLog()
{
	//注册 控件sink  控件不能在theApp::InitInstance里，所以之前的log不好记录
	//现改为打开IDM_Log读取日志文件

	bool bWriteToFile = true;//是否写入文件，配置
	if (bWriteToFile) {
		CString& strExePath = const_cast<CString&>(g_GobalVariable.GetExePath());//后期将g_GobalVariable合到theApp里
		
		CString str = strExePath + _T("log");
		if(! PathFileExists(str))
			::CreateDirectory(str, 0);//创建目录，只能创建一级

		TCHAR szCurPath[MAX_PATH] = { 0 };
		::GetCurrentDirectory(MAX_PATH, szCurPath);
		::SetCurrentDirectory(str);

		//注册 文件sink 这在修改全局日志器，先初始化
		auto& sink = logging::add_file_log(
			keywords::file_name = "applog_%N.log",
			keywords::rotation_size = 10 * 1024 * 1024, //10M生成新文件
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),//按天
			//keywords::format = "[%TimeStamp%]: %Message%"
			keywords::format = (
				//expr::stream << expr::format<wchar_t>(L"%1%：<%2%>, [ %3% ], { %4% }")
				//% expr::attr< unsigned int >("LineID") % logging::trivial::severity
				//% expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S")
				//% expr::wmessage
				expr::stream << expr::attr< unsigned int >("LineID")
				<< ": <" << logging::trivial::severity
				<< "> " << ",[ "<< expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S") << " ] " << ",{ " << expr::message << " } "
				)
		);

		
		//sink会自动转化
		std::locale loc = boost::locale::generator()("en_US.UTF-8");
		sink->imbue(loc);

		logging::add_common_attributes();//公共属性

		//日志对话框
		//if(nullptr == m_oLogDlg){
		//	m_oLogDlg = std::make_shared<CLogDialog>();
		//	//m_oLogDlg->Create(IDD_Log, this); CWinApp不是CWnd，没用
		//}

		//第一条日志
		WriteLog(trace, _T("boost log init success."));

		::SetCurrentDirectory(szCurPath);
	}

	return true;
}

void CSelfServiceBankClientApp::InitZCMsgHandler()
{
	//m_mapZCMsgHandler[ZC_MSG_COMMON_CURUSERINFOEX] = ZCMsgCurrentUserInfo;
	//注册自己感兴趣的消息，其他不处理
	m_mapZCMsgHandler = { /*<反馈， 处理方法>*/
		{ ZC_MSG_COMMON_CURUSERINFOEX, &CSelfServiceBankClientApp::ZCMsgCurrentUserInfo },//当前用户信息
		{ ZC_MSG_COMMON_USERALLINFO, &CSelfServiceBankClientApp::ZCMsgUserDetailInfo },//用户详情
		{ ZC_MSG_OPENDOOR_DISPOSALINFO, &CSelfServiceBankClientApp::ZCMsgDisposalInfo },//权限信息
		{ ZC_MSG_OPENDOOR_GETALLPEPOLEINFO, &CSelfServiceBankClientApp::ZCMsgControledPersonInfo },//管辖人员信息
		{ ZC_MSG_COMMON_DOWNLOADPIC, &CSelfServiceBankClientApp::ZCMsgControledHeadPic },//管辖人员头像 
		{ ZC_MSG_OPENDOOR_DEPARTMENTINFO, &CSelfServiceBankClientApp::ZCMsgDepartmentInfo }//部门信息
	};
}



void CSelfServiceBankClientApp::Update(bool bOK, DWORD dwType, DWORD dwMsgID, PBYTE pMsg)
{
	if (bOK) {
		auto it = m_mapZCMsgHandler.find(dwType);
		if (m_mapZCMsgHandler.end() != it) {
			auto& pfun = it->second;
			(this->*pfun)(pMsg, dwMsgID);
		}
	}
	else {
		WriteLog(error, _T("请求消息反馈失败，消息码：%d"), dwType);
	}
}


//获取用户信息
std::shared_ptr<stUserInfo>& CSelfServiceBankClientApp::CreateOrGetUserInfo(const CString& strName)
{
	auto& spUserInfo = m_mapUserInfo[strName];
	if (nullptr == spUserInfo)
		spUserInfo = std::make_shared<stUserInfo>();
	return spUserInfo;
}

void CSelfServiceBankClientApp::ZCMsgCurrentUserInfo(PBYTE pMsg, DWORD dwMsgID)
{
	T_CURUSER_INFO_EX* pInfo = (T_CURUSER_INFO_EX*)(&pMsg[ZCMsgHeaderLen]);
	CString strName(pInfo->chUserName);
	m_strCurUserName = strName;
	
	//创建用户
	CreateOrGetUserInfo(strName);

	//请求当前用户的详细信息
	CZCMsgManager::Instance()->RequestMsgWithMsgID(ZC_MODULE_APP, ZC_MSG_APP_USERALLINFO,
		-1, (PBYTE)pInfo->chUserName, 64);
}


//用户详细信息 : 经常在权限信息之后收到
void CSelfServiceBankClientApp::ZCMsgUserDetailInfo(PBYTE pMsg, DWORD dwMsgID)
{
	S_New_UserInfo* pInfo = (S_New_UserInfo*)(&pMsg[ZCMsgHeaderLen]);
	CString strName(pInfo->chUserName);
	//if (-1 == dwMsgID) {//dwMsgID = -1是当前登录用户
	//	m_strCurUserName = strName;
	//}
	//如何避免 pInfo无效时的m_mapUserInfo内存问题？
	auto& spUserInfo = CreateOrGetUserInfo(strName);

	spUserInfo->stBaseInfo = std::move(*pInfo);
}

//当前用户权限信息 ： ZCMsgManger.exe保存了登录名
void CSelfServiceBankClientApp::ZCMsgDisposalInfo(PBYTE pMsg, DWORD dwMsgID)
{
	T_OPENDOORPOSALINFO* pInfo = (T_OPENDOORPOSALINFO*)(&pMsg[ZCMsgHeaderLen]);
	auto& spUserInfo = CreateOrGetUserInfo(m_strCurUserName);
	spUserInfo->stDisposalInfo = std::move(*pInfo);
}

//管辖人员信息
void CSelfServiceBankClientApp::ZCMsgControledPersonInfo(PBYTE pMsg, DWORD dwMsgID)
{
	int nMsgLen = sizeof(pMsg) / sizeof(BYTE);
	nMsgLen = strlen((char*)pMsg);

	const int nStructLen = sizeof(TAGDOAPERSONINFO_S);
	int iCount = (nMsgLen - ZCMsgHeaderLen) / nStructLen;
	auto pZCMsg = CZCMsgManager::Instance();
	for (int i = 0; i < iCount; ++i){
		TAGDOAPERSONINFO_S* pInfo = (TAGDOAPERSONINFO_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		
		auto sp = std::make_shared<stControledPersonInfo>();
		sp->stBaseInfo = std::move(*pInfo);
		m_vecControledPersonInfo.push_back(sp);
		//获取照片信息
		PBYTE pImage = 
			(TRUE == IsBadReadPtr(pInfo->chHeadImage, sizeof(int))) ? (PBYTE)"" : (PBYTE)pInfo->chHeadImage;
		
		pZCMsg->RequestMsgWithMsgID(ZC_MODULE_BCBCLIENT, ZC_MSG_BCBCLIENT_DOWNLOADPIC, i, pImage, 512);
	}
}

//管辖人员头像：一条一条
void CSelfServiceBankClientApp::ZCMsgControledHeadPic(PBYTE pMsg, DWORD dwMsgID)
{
	assert(dwMsgID < 0 || dwMsgID > m_vecControledPersonInfo.size());

	auto& sp = m_vecControledPersonInfo[dwMsgID];
	PBYTE pImgPath = &pMsg[ZCMsgHeaderLen];
	memcpy(sp->szHeadPic, pImgPath, MAX_PATH);
}

//部门信息
void CSelfServiceBankClientApp::ZCMsgDepartmentInfo(PBYTE pMsg, DWORD dwMsgID)
{
	int nMsgLen = sizeof(pMsg) / sizeof(BYTE);
	nMsgLen = strlen((char*)pMsg);

	const int nStructLen = sizeof(TAGDOADEPARTMENTINFO_S);
	int iCount = (nMsgLen - ZCMsgHeaderLen) / nStructLen;
	for (int i = 0; i < iCount; ++i) {
		TAGDOADEPARTMENTINFO_S* pInfo = (TAGDOADEPARTMENTINFO_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);

	}

}


//写日志
void _cdecl CSelfServiceBankClientApp::WriteLog(severity_level level, const TCHAR* szMsg, ...)
{
	TCHAR szBuffer[1024];
	va_list pArgList; //char*
	va_start(pArgList, szMsg); //将指针与最后一个固定参数关联

	//专门写进szBuffer的函数
	_vsntprintf_s(szBuffer, _countof(szBuffer), szMsg, pArgList);
	
	BOOST_LOG_SEV(g_slog, level) << szBuffer/*L"你好"*//*"abc"*/;

	va_end(pArgList); //清理
}


/*****  全局类  */
CGobalVariable::CGobalVariable()
{
	//GDI+初始化
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//m_hEventReadStgCfg = CreateEvent(nullptr, TRUE, FALSE, nullptr);//手动未触发

}

CGobalVariable::~CGobalVariable()
{
	//GDI+释放资源
	GdiplusShutdown(gdiplusToken);
}


bool CGobalVariable::Init()
{
	bool bRet = true;

	//程序所在目录
	m_strExePath = MyGetExePath();

	//配置文件路径
	//m_strStgCfgPath = m_strExePath + _T("stgcfg");

	//读取配置
	//vecCfg.resize(StgCfgEnum_Buff);
	//vecCfg[StgCfgEnum_LoginUser] = new StgCfgLoginUser;

	//unsigned int nThreadID(0);
	//HANDLE hThread = (HANDLE)_beginthreadex(nullptr, 0, ReadStgCfgThread, nullptr, 0, &nThreadID);
	//CloseHandle(hThread); hThread = nullptr;

	return bRet;
}