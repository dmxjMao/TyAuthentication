
// SelfServiceBankClient.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "SelfServiceBankClientDlg.h"

#include <boost\log\expressions.hpp> //��ʽ��
#include <boost\date_time\posix_time\posix_time_types.hpp>
#include <boost\log\support\date_time.hpp>

#include <boost\log\sources\severity_logger.hpp> //source Դ
#include <boost\log\utility\setup\common_attributes.hpp> //��������
//#include <boost\log\core.hpp> //core ����
#include <boost\log\utility\setup\file.hpp> //sink �ļ�

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

src::severity_logger< severity_level > g_slog;//������־��

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

		//ע�� �ļ�sink
		logging::add_file_log(
			keywords::file_name = "applog_%N.log",
			keywords::rotation_size = 10 * 1024 * 1024, //10M�������ļ�
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),//����
			//keywords::format = "[%TimeStamp%]: %Message%"
			keywords::format = (
				expr::stream
				<< expr::attr< unsigned int >("LineID")
				<< ": <" << logging::trivial::severity
				<< "> " << ",[ "<< expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S") << " ] " << ",{ " << expr::smessage << " } "
				)
		);

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

void _cdecl CSelfServiceBankClientApp::WriteLog(severity_level, const TCHAR* szMsg, ...)
{
	TCHAR szBuffer[1024];
	va_list pArgList; //char*
	va_start(pArgList, szMsg); //��ָ�������һ���̶����������a

	//ר��д��szBuffer�ĺ���
	_vsntprintf_s(szBuffer, _countof(szBuffer), szMsg, pArgList);
	va_end(pArgList); //����

	BOOST_LOG_SEV(g_slog, trace) << szBuffer;
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