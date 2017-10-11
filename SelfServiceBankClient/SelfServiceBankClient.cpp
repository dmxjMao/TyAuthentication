
// SelfServiceBankClient.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "SelfServiceBankClientDlg.h"

#include <boost\log\expressions.hpp> //格式化
#include <boost\date_time\posix_time\posix_time_types.hpp>
#include <boost\log\support\date_time.hpp>

#include <boost\log\sources\severity_logger.hpp> //source 源
#include <boost\log\utility\setup\common_attributes.hpp> //公共属性
//#include <boost\log\core.hpp> //core 核心
#include <boost\log\utility\setup\file.hpp> //sink 文件

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

src::severity_logger< severity_level > g_slog;//级别日志器

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

		//注册 文件sink
		logging::add_file_log(
			keywords::file_name = "applog_%N.log",
			keywords::rotation_size = 10 * 1024 * 1024, //10M生成新文件
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),//按天
			//keywords::format = "[%TimeStamp%]: %Message%"
			keywords::format = (
				expr::stream
				<< expr::attr< unsigned int >("LineID")
				<< ": <" << logging::trivial::severity
				<< "> " << ",[ "<< expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S") << " ] " << ",{ " << expr::smessage << " } "
				)
		);

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

void _cdecl CSelfServiceBankClientApp::WriteLog(severity_level, const TCHAR* szMsg, ...)
{
	TCHAR szBuffer[1024];
	va_list pArgList; //char*
	va_start(pArgList, szMsg); //将指针与最后一个固定参数关联

	//专门写进szBuffer的函数
	_vsntprintf_s(szBuffer, _countof(szBuffer), szMsg, pArgList);
	va_end(pArgList); //清理

	BOOST_LOG_SEV(g_slog, trace) << szBuffer;
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