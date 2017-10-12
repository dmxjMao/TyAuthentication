
// SelfServiceBankClient.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "SelfServiceBankClientDlg.h"

#include <boost/log/expressions.hpp> //��ʽ��
#include <boost/date_time/posix_time/posix_time_types.hpp> //ʱ���ʽ
#include <boost/log/support/date_time.hpp>
#include <boost/locale/generator.hpp>

//#include <boost/smart_ptr/shared_ptr.hpp>
//#include <boost/smart_ptr/make_shared_object.hpp>
//#include <boost/log/sinks/sync_frontend.hpp>
//#include <boost/log/sinks/text_ostream_backend.hpp>
//#include <boost/log/sources/record_ostream.hpp>
//#include <boost/core/null_deleter.hpp>

#include <boost/log/sources/severity_logger.hpp> //���� Դ
#include <boost/log/utility/setup/common_attributes.hpp> //��������
#include <boost/log/utility/setup/file.hpp> //sink �ļ�

#include "ZCMsgManager.h"
#include "LogDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//boost��־
namespace logging = boost::log;
namespace src = logging::sources;
namespace sinks = logging::sinks;
namespace keywords = logging::keywords;
namespace expr = boost::log::expressions;
using namespace logging::trivial;

src::wseverity_logger< severity_level > g_slog;//������־��
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
CGobalVariable g_GobalVariable; //ȫ�ֱ���

// CSelfServiceBankClientApp initialization

BOOL CSelfServiceBankClientApp::InitInstance()
{
	//�ڴ���
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

	//ȫ�ֱ�����ʼ��
	g_GobalVariable.Init();

	//��ʼ����־
	InitLog();

	//��ʼ����Ϣ������
	InitZCMsgHandler();

	//��ʼ����Ϣ����
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
	//�ڴ���
	_CrtDumpMemoryLeaks();

	return CWinApp::ExitInstance();
}

bool CSelfServiceBankClientApp::InitLog()
{
	//ע�� �ؼ�sink  �ؼ�������theApp::InitInstance�����֮ǰ��log���ü�¼
	//�ָ�Ϊ��IDM_Log��ȡ��־�ļ�

	bool bWriteToFile = true;//�Ƿ�д���ļ�������
	if (bWriteToFile) {
		CString& strExePath = const_cast<CString&>(g_GobalVariable.GetExePath());//���ڽ�g_GobalVariable�ϵ�theApp��
		
		CString str = strExePath + _T("log");
		if(! PathFileExists(str))
			::CreateDirectory(str, 0);//����Ŀ¼��ֻ�ܴ���һ��

		TCHAR szCurPath[MAX_PATH] = { 0 };
		::GetCurrentDirectory(MAX_PATH, szCurPath);
		::SetCurrentDirectory(str);

		//ע�� �ļ�sink �����޸�ȫ����־�����ȳ�ʼ��
		auto& sink = logging::add_file_log(
			keywords::file_name = "applog_%N.log",
			keywords::rotation_size = 10 * 1024 * 1024, //10M�������ļ�
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),//����
			//keywords::format = "[%TimeStamp%]: %Message%"
			keywords::format = (
				//expr::stream << expr::format<wchar_t>(L"%1%��<%2%>, [ %3% ], { %4% }")
				//% expr::attr< unsigned int >("LineID") % logging::trivial::severity
				//% expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S")
				//% expr::wmessage
				expr::stream << expr::attr< unsigned int >("LineID")
				<< ": <" << logging::trivial::severity
				<< "> " << ",[ "<< expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S") << " ] " << ",{ " << expr::message << " } "
				)
		);

		
		//sink���Զ�ת��
		std::locale loc = boost::locale::generator()("en_US.UTF-8");
		sink->imbue(loc);

		logging::add_common_attributes();//��������

		//��־�Ի���
		//if(nullptr == m_oLogDlg){
		//	m_oLogDlg = std::make_shared<CLogDialog>();
		//	//m_oLogDlg->Create(IDD_Log, this); CWinApp����CWnd��û��
		//}

		//��һ����־
		WriteLog(trace, _T("boost log init success."));

		::SetCurrentDirectory(szCurPath);
	}

	return true;
}

void CSelfServiceBankClientApp::InitZCMsgHandler()
{
	//m_mapZCMsgHandler[ZC_MSG_COMMON_CURUSERINFOEX] = ZCMsgCurrentUserInfo;
	//ע���Լ�����Ȥ����Ϣ������������
	m_mapZCMsgHandler = { /*<������ ������>*/
		{ ZC_MSG_COMMON_CURUSERINFOEX, &CSelfServiceBankClientApp::ZCMsgCurrentUserInfo },//��ǰ�û���Ϣ
		{ ZC_MSG_COMMON_USERALLINFO, &CSelfServiceBankClientApp::ZCMsgUserDetailInfo },//�û�����
		{ ZC_MSG_OPENDOOR_DISPOSALINFO, &CSelfServiceBankClientApp::ZCMsgDisposalInfo },//Ȩ����Ϣ
		{ ZC_MSG_OPENDOOR_GETALLPEPOLEINFO, &CSelfServiceBankClientApp::ZCMsgControledPersonInfo },//��Ͻ��Ա��Ϣ
		{ ZC_MSG_COMMON_DOWNLOADPIC, &CSelfServiceBankClientApp::ZCMsgControledHeadPic },//��Ͻ��Աͷ�� 
		{ ZC_MSG_OPENDOOR_DEPARTMENTINFO, &CSelfServiceBankClientApp::ZCMsgDepartmentInfo }//������Ϣ
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
		WriteLog(error, _T("������Ϣ����ʧ�ܣ���Ϣ�룺%d"), dwType);
	}
}


//��ȡ�û���Ϣ
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
	
	//�����û�
	CreateOrGetUserInfo(strName);

	//����ǰ�û�����ϸ��Ϣ
	CZCMsgManager::Instance()->RequestMsgWithMsgID(ZC_MODULE_APP, ZC_MSG_APP_USERALLINFO,
		-1, (PBYTE)pInfo->chUserName, 64);
}


//�û���ϸ��Ϣ : ������Ȩ����Ϣ֮���յ�
void CSelfServiceBankClientApp::ZCMsgUserDetailInfo(PBYTE pMsg, DWORD dwMsgID)
{
	S_New_UserInfo* pInfo = (S_New_UserInfo*)(&pMsg[ZCMsgHeaderLen]);
	CString strName(pInfo->chUserName);
	//if (-1 == dwMsgID) {//dwMsgID = -1�ǵ�ǰ��¼�û�
	//	m_strCurUserName = strName;
	//}
	//��α��� pInfo��Чʱ��m_mapUserInfo�ڴ����⣿
	auto& spUserInfo = CreateOrGetUserInfo(strName);

	spUserInfo->stBaseInfo = std::move(*pInfo);
}

//��ǰ�û�Ȩ����Ϣ �� ZCMsgManger.exe�����˵�¼��
void CSelfServiceBankClientApp::ZCMsgDisposalInfo(PBYTE pMsg, DWORD dwMsgID)
{
	T_OPENDOORPOSALINFO* pInfo = (T_OPENDOORPOSALINFO*)(&pMsg[ZCMsgHeaderLen]);
	auto& spUserInfo = CreateOrGetUserInfo(m_strCurUserName);
	spUserInfo->stDisposalInfo = std::move(*pInfo);
}

//��Ͻ��Ա��Ϣ
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
		//��ȡ��Ƭ��Ϣ
		PBYTE pImage = 
			(TRUE == IsBadReadPtr(pInfo->chHeadImage, sizeof(int))) ? (PBYTE)"" : (PBYTE)pInfo->chHeadImage;
		
		pZCMsg->RequestMsgWithMsgID(ZC_MODULE_BCBCLIENT, ZC_MSG_BCBCLIENT_DOWNLOADPIC, i, pImage, 512);
	}
}

//��Ͻ��Աͷ��һ��һ��
void CSelfServiceBankClientApp::ZCMsgControledHeadPic(PBYTE pMsg, DWORD dwMsgID)
{
	assert(dwMsgID < 0 || dwMsgID > m_vecControledPersonInfo.size());

	auto& sp = m_vecControledPersonInfo[dwMsgID];
	PBYTE pImgPath = &pMsg[ZCMsgHeaderLen];
	memcpy(sp->szHeadPic, pImgPath, MAX_PATH);
}

//������Ϣ
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


//д��־
void _cdecl CSelfServiceBankClientApp::WriteLog(severity_level level, const TCHAR* szMsg, ...)
{
	TCHAR szBuffer[1024];
	va_list pArgList; //char*
	va_start(pArgList, szMsg); //��ָ�������һ���̶����������a

	//ר��д��szBuffer�ĺ���
	_vsntprintf_s(szBuffer, _countof(szBuffer), szMsg, pArgList);
	
	BOOST_LOG_SEV(g_slog, level) << szBuffer/*L"���"*//*"abc"*/;

	va_end(pArgList); //����
}


/*****  ȫ����  */
CGobalVariable::CGobalVariable()
{
	//GDI+��ʼ��
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//m_hEventReadStgCfg = CreateEvent(nullptr, TRUE, FALSE, nullptr);//�ֶ�δ����

}

CGobalVariable::~CGobalVariable()
{
	//GDI+�ͷ���Դ
	GdiplusShutdown(gdiplusToken);
}


bool CGobalVariable::Init()
{
	bool bRet = true;

	//��������Ŀ¼
	m_strExePath = MyGetExePath();

	//�����ļ�·��
	//m_strStgCfgPath = m_strExePath + _T("stgcfg");

	//��ȡ����
	//vecCfg.resize(StgCfgEnum_Buff);
	//vecCfg[StgCfgEnum_LoginUser] = new StgCfgLoginUser;

	//unsigned int nThreadID(0);
	//HANDLE hThread = (HANDLE)_beginthreadex(nullptr, 0, ReadStgCfgThread, nullptr, 0, &nThreadID);
	//CloseHandle(hThread); hThread = nullptr;

	return bRet;
}