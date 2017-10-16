
// SelfServiceBankClient.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "SelfServiceBankClientDlg.h"

#include <boost/log/expressions.hpp> //格式化
#include <boost/date_time/posix_time/posix_time_types.hpp> //时间格式
#include <boost/log/support/date_time.hpp>
#include <boost/locale/generator.hpp>
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

using std::shared_ptr;
using std::make_shared;
using std::placeholders::_1;

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
CSelfServiceBankClientDlg* g_pMainDlg = 0;//主界面对话框


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
	g_pMainDlg = &dlg;
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
		{ ZC_MSG_COMMON_ALLAREAINFO, &CSelfServiceBankClientApp::ZCMsgAreaInfo },//权限信息
		{ ZC_MSG_OPENDOOR_GETALLPEPOLEINFO, &CSelfServiceBankClientApp::ZCMsgCtrlPersonInfo },//管辖人员信息
		{ ZC_MSG_COMMON_DOWNLOADPIC, &CSelfServiceBankClientApp::ZCMsgCtrlHeadPic },//管辖人员头像 
		{ ZC_MSG_OPENDOOR_DEPARTMENTINFO, &CSelfServiceBankClientApp::ZCMsgDepartmentInfo },//部门信息
		{ ZC_MSG_OPENDOOR_ACCESSRELATION, &CSelfServiceBankClientApp::ZCMsgEntranceRelation },//门禁主从关系
		{ ZC_MSG_OPENDOOR_GETALLACSHOSTINFO, &CSelfServiceBankClientApp::ZCMsgACSHostInfo },//所有门禁主机信息
		{ ZC_MSG_OPENDOOR_CTRLLEVELMULINFO, &CSelfServiceBankClientApp::ZCMsgCtrlLevelInfo },//获取管控等级信息
		{ ZC_MSG_OPENDOOR_CTRLLEVELPLAN, &CSelfServiceBankClientApp::ZCMsgCtrlPlanInfo }, //管控策略信息
		{ ZC_MSG_COMMON_ALLKEYPARTINFO, &CSelfServiceBankClientApp::ZCMsgKeypartInfo },//部位信息
		{ ZC_MSG_OPENDOOR_GETACSHOSTLINKINFO, &CSelfServiceBankClientApp::ZCMsgACSHostLinkCameraInfo },//门禁主机关联摄像头设备
		{ ZC_MSG_OPENDOOR_GETACSHOSTLINKTALKINFO, &CSelfServiceBankClientApp::ZCMsgACSHostLinkTalkInfo },//门禁主机关联对讲设备
		{ ZC_MSG_COMMON_ALLUSERINFO, &CSelfServiceBankClientApp::ZCMsgHandlerInfo },//所有处置人姓名
		{ ZC_MSG_OPENDOOR_USERDOORCAMERARELATION, &CSelfServiceBankClientApp::ZCMsgDoorRelationInfo },//用户门禁摄像头关联信息
		{ ZC_MSG_COMMON_PLANINFO, &CSelfServiceBankClientApp::ZCMsgEMPlanInfo }//所有预案信息
	};
}



void CSelfServiceBankClientApp::Update(bool bOK, DWORD dwType, DWORD dwMsgID, PBYTE pMsg, INT nMsgLen)
{
	if (bOK) {
		auto it = m_mapZCMsgHandler.find(dwType);
		if (m_mapZCMsgHandler.end() != it) {
			auto& pfun = it->second;
			(this->*pfun)(pMsg, dwMsgID, nMsgLen);
		}
	}
	else {
		extern std::map<DWORD, TCHAR*> g_mapZCMsgErrInfo;
		WriteLog(error, g_mapZCMsgErrInfo[dwType]);
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

void CSelfServiceBankClientApp::ZCMsgCurrentUserInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
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
void CSelfServiceBankClientApp::ZCMsgUserDetailInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
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
void CSelfServiceBankClientApp::ZCMsgDisposalInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	T_OPENDOORPOSALINFO* pInfo = (T_OPENDOORPOSALINFO*)(&pMsg[ZCMsgHeaderLen]);
	auto& spUserInfo = CreateOrGetUserInfo(m_strCurUserName);
	spUserInfo->stDisposalInfo = std::move(*pInfo);
}

//区域信息
void CSelfServiceBankClientApp::ZCMsgAreaInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(T_AREA_INFO, pMsg, nMsgLen)
		T_AREA_INFO* pInfo = (T_AREA_INFO*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		pInfo = 0;
	ZCMsgMacro_endfor
	
}

//管辖人员信息
void CSelfServiceBankClientApp::ZCMsgCtrlPersonInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(TAGDOAPERSONINFO_S, pMsg, nMsgLen)
	
	TAGDOAPERSONINFO_S* pInfo = (TAGDOAPERSONINFO_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);

	auto sp = std::make_shared<stCtrlPersonInfo>();
	sp->stBaseInfo = std::move(*pInfo);
	m_vecCtrlPersonInfo.push_back(sp);
	//获取照片信息
	PBYTE pImage =
		(TRUE == IsBadReadPtr(pInfo->chHeadImage, sizeof(int))) ? (PBYTE)"" : (PBYTE)pInfo->chHeadImage;

	CZCMsgManager::Instance()->RequestMsgWithMsgID(ZC_MODULE_BCBCLIENT, ZC_MSG_BCBCLIENT_DOWNLOADPIC, i, pImage, 512);
	
	pInfo = 0;
	
	ZCMsgMacro_endfor
}

//管辖人员头像：一条一条
void CSelfServiceBankClientApp::ZCMsgCtrlHeadPic(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	assert(dwMsgID < 0 || dwMsgID > m_vecCtrlPersonInfo.size());

	auto& sp = m_vecCtrlPersonInfo[dwMsgID];
	PBYTE pImgPath = &pMsg[ZCMsgHeaderLen];
	memcpy(sp->szHeadPic, pImgPath, MAX_PATH);
}

//部门信息
void CSelfServiceBankClientApp::ZCMsgDepartmentInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(TAGDOADEPARTMENTINFO_S, pMsg, nMsgLen)
		TAGDOADEPARTMENTINFO_S* pInfo = (TAGDOADEPARTMENTINFO_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		pInfo = 0;
	ZCMsgMacro_endfor
}


//门禁主从关系
void CSelfServiceBankClientApp::ZCMsgEntranceRelation(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(TAGDOACCESSRELATION_S, pMsg, nMsgLen)
		TAGDOACCESSRELATION_S* pInfo = (TAGDOACCESSRELATION_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		pInfo = 0;
	ZCMsgMacro_endfor
}

//所有门禁主机信息 access control system
void CSelfServiceBankClientApp::ZCMsgACSHostInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(TAGDOAACCESSINFO_S, pMsg, nMsgLen)

	TAGDOAACCESSINFO_S* pInfo = (TAGDOAACCESSINFO_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	CString strName(pInfo->chDevName);
	auto& sp = m_mapACSHostInfo[strName];
	if (0 == sp) {
		sp = make_shared<stACSHostInfo>();
	}
	sp->stBaseInfo = std::move(*pInfo);

	pInfo = 0;

	ZCMsgMacro_endfor
}

//管控等级信息：针对设备，设备所在的场所和部位，它的管控等级名称
//bool lambda_FindACSHostByName(const shared_ptr<stACSHostInfo>& st, const char* name) {
//	return (0 == strcmp(st->stBaseInfo.chDevName, name));
//}
bool lambda_GetCtrlLevel(const std::tuple<CString, UINT8>& tpl, const CString& strLevel) {
	return std::get<0>(tpl) == strLevel;
}
void CSelfServiceBankClientApp::ZCMsgCtrlLevelInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(S_NEW_CTRLLEVELINFO, pMsg, nMsgLen)
	
	S_NEW_CTRLLEVELINFO* pInfo = (S_NEW_CTRLLEVELINFO*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	//auto it = std::find_if(m_mapACSHostInfo.begin(), m_mapACSHostInfo.end(),
	//	std::bind(lambda_FindACSHostByName, _1, pInfo->chDeviceName));
	CString strName(pInfo->chDeviceName);
	auto itHostInfo = m_mapACSHostInfo.find(strName);
	//shared_ptr<stACSHostInfo> sp = 0;
	if (m_mapACSHostInfo.end() == itHostInfo) {
		m_mapACSHostInfo[strName] = make_shared<stACSHostInfo>();
	}
	auto& sp = m_mapACSHostInfo[strName];
	
	//赋值管控等级、管控场所名称、部位名称
	static std::vector<std::tuple<CString, UINT8>> vecLevel = {
		{_T("一级"),1},{ _T("二级"),2 },{ _T("三级"),3 },{ _T("四级"),4 }
	};
	CString strLevel(pInfo->chLevelName);
	auto itLevel = std::find_if(vecLevel.begin(), vecLevel.end(),
		std::bind(lambda_GetCtrlLevel, _1, strLevel));
	sp->nCtrlLevel = (vecLevel.end() == itLevel) ? 0 : std::get<1>(*itLevel);
	//场所
	mbstowcs_s(0, sp->szPlaceName, pInfo->chPlaceName, _countof(sp->szPlaceName));
	//部位
	mbstowcs_s(0, sp->szPartName, pInfo->chKeyPartName, _countof(sp->szPartName));
	
	pInfo = 0;

	ZCMsgMacro_endfor
}

//管控策略信息
void CSelfServiceBankClientApp::ZCMsgCtrlPlanInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	/*一条消息：对应一个配置项，来得真是恶心
	<级别levelID[1-4]-> 对应“管控等级”
	 配置项planID[1-n]-> 对应“策略设置”，1是基础设置
	 配置子项methodID[1-n]-> 对应“配置详情”
	 值-> nSetItem1-3 按顺序 >
	 methodID：
	 1  //认证时效
	 2  //认证方式    1-远程、  2-本地
	 3  //认证识别一  1-指纹、  2-刷卡
	 4  //认证识别二  1-指纹、  2-刷卡
	 5  //录像        1-主通道、2-全通道
	 6  //抓图        1-主通道、2-全通道
	 7  //预案处置    1-预案ID
	 8  //按步执行    1-是      2-否
	 9  //开门授权    1-刷卡    2-密码
	 10 //上级授权    1-刷卡    2-密码
	 11 //排版核对    1-是      2-否
	 12 //允许特批    1-是      2-否
	 13 //首卡授权    1-是      2-否
	 */
	ZCMsgMacro_beginfor(TAGCTRLEVELPLAN_S, pMsg, nMsgLen)
	
	TAGCTRLEVELPLAN_S* pInfo = (TAGCTRLEVELPLAN_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	UINT8 nItem1 = static_cast<UINT8>(pInfo->nSetItem1);
	UINT8 nItem2 = static_cast<UINT8>(pInfo->nSetItem2);
	UINT8 nItem3 = static_cast<UINT8>(pInfo->nSetItem3);

	auto& sp = m_mapCtrlPlan[pInfo->nLevelId];
	if (nullptr == sp) {
		sp = make_shared<stCtrlPlanInfo>();
	}
	switch (pInfo->nMethodId)
	{
	case 1:
		sp->nAuthTimeLimit = nItem1; break;
	case 2:
		sp->nAuthType = nItem1; break;
	case 3:
		sp->nDoor1Type = nItem1;
		sp->nDoor1Type = nItem2; break;
	case 4:
		sp->nDoor2Type = nItem1;
		sp->nDoor2Type = nItem2; break;
	case 5:
		sp->nRecType = nItem1;
		sp->nPreRecTime = nItem2;
		sp->nRecTime = nItem3; break;
	case 6:
		sp->nCapType = nItem1;
		sp->nCapDur = nItem2;
		sp->nCapTime = nItem3; break;
	case 7:
		sp->nEMPlanID = nItem1;
		mbstowcs_s(0, sp->szEMPlanName, pInfo->chSetItem4, _countof(sp->szEMPlanName)); break;
	case 8:
		sp->bEMPlanStep = nItem1; break;
	case 9:
		sp->nOpenGrantType = nItem1; break;
	case 10:
		sp->nSuperGrantType = nItem1; break;
	case 12:
		sp->bApproval = nItem1;
		break;
	case 13:
		sp->bFCGrant = nItem1; break;
	default: break;
	}

	pInfo = 0;

	ZCMsgMacro_endfor
}

//部位信息
void CSelfServiceBankClientApp::ZCMsgKeypartInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(S_NEW_SHOWPOSITIONINFO, pMsg, nMsgLen)
		S_NEW_SHOWPOSITIONINFO* pInfo = (S_NEW_SHOWPOSITIONINFO*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		pInfo = 0;
	ZCMsgMacro_endfor
}

//门禁主机关联摄像头设备
void CSelfServiceBankClientApp::ZCMsgACSHostLinkCameraInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	//复用了“对讲”结构体
	ZCMsgMacro_beginfor(S_HostTalkInfo, pMsg, nMsgLen)
		S_HostTalkInfo* pInfo = (S_HostTalkInfo*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		pInfo = 0;
	ZCMsgMacro_endfor
}

//门禁主机关联对讲设备
void CSelfServiceBankClientApp::ZCMsgACSHostLinkTalkInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(S_HostTalkInfo, pMsg, nMsgLen)
		S_HostTalkInfo* pInfo = (S_HostTalkInfo*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		pInfo = 0;
	ZCMsgMacro_endfor
}

//所有处置人信息
void CSelfServiceBankClientApp::ZCMsgHandlerInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	//根据姓名再请求详细信息
	int iCount = (nMsgLen - ZCMsgHeaderLen) / 64;
	for (int i = 0; i < iCount; ++i) {
		char* pInfo = (char*)(&pMsg[ZCMsgHeaderLen + i * 64]);
		
		//请求用户的详细信息
		CZCMsgManager::Instance()->RequestMsgWithMsgID(ZC_MODULE_APP, ZC_MSG_APP_USERALLINFO,
			i, (PBYTE)pInfo, 64);
	}

}

//用户门禁摄像头关联信息
void CSelfServiceBankClientApp::ZCMsgDoorRelationInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(USERDOORCAMERARELATION_CLIENT_GET_S, pMsg, nMsgLen)
		USERDOORCAMERARELATION_CLIENT_GET_S* pInfo = (USERDOORCAMERARELATION_CLIENT_GET_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		pInfo = 0;
	ZCMsgMacro_endfor
	
}

//所有预案信息
void CSelfServiceBankClientApp::ZCMsgEMPlanInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(S_NEW_SHOWPLANLIB, pMsg, nMsgLen)
	
	S_NEW_SHOWPLANLIB* pInfo = (S_NEW_SHOWPLANLIB*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	m_vecEMPlanInfo.push_back(make_shared<S_NEW_SHOWPLANLIB>(*pInfo));

	ZCMsgMacro_endfor
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



void CUICfg::SetUICfg(std::string s)
{
	boost::sregex_iterator it(s.begin(), s.end(), m_uiregex), itend;
	for (; it != itend; ++it) {
		OnMatchUICfg(*it);
	}
}


bool lambda_FindUICfg(const std::string& s1, const std::string& s2) {
	return s1 == s2;
}
bool CUICfg::HasUICfg(const std::string& str)
{
	auto it = std::find_if(m_vecUICfg.begin(), m_vecUICfg.end(),
		std::bind(lambda_FindUICfg, _1, str));
	return m_vecUICfg.end() != it;
}
