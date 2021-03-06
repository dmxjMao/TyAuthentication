
// AuthenticationClient.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "AuthenticationClient.h"
#include "AuthenticationClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAuthenticationClientApp

BEGIN_MESSAGE_MAP(CAuthenticationClientApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CAuthenticationClientApp construction

CAuthenticationClientApp::CAuthenticationClientApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CAuthenticationClientApp object

CAuthenticationClientApp theApp;
CGobalVariable g_GobalVariable; //全局变量

// CAuthenticationClientApp initialization

BOOL CAuthenticationClientApp::InitInstance()
{
	//内存检查
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(78);
	
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

	CAuthenticationClientDlg dlg;
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



int CAuthenticationClientApp::ExitInstance()
{
	//内存检查
	_CrtDumpMemoryLeaks();

	return CWinApp::ExitInstance();
}



/*****  全局类  */
CGobalVariable::CGobalVariable()
{
	//GDI+初始化
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	m_hEventReadStgCfg = CreateEvent(nullptr, TRUE, FALSE, nullptr);//手动未触发

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
	//TCHAR szPath[MAX_PATH] = { 0 };
	//GetModuleFileName(AfxGetInstanceHandle(), szPath, MAX_PATH);
	//TCHAR* pFind = _tcsrchr(szPath, '\\');
	//szPath[_tcslen(szPath) - _tcslen(pFind) + 1] = '\0';
	//m_strExePath = szPath;
	m_strExePath = MyGetExePath();

	//配置文件路径
	m_strStgCfgPath = m_strExePath + _T("stgcfg");

	//读取配置
	//vecCfg.resize(StgCfgEnum_Buff);
	//vecCfg[StgCfgEnum_LoginUser] = new StgCfgLoginUser;

	//unsigned int nThreadID(0);
	//HANDLE hThread = (HANDLE)_beginthreadex(nullptr, 0, ReadStgCfgThread, nullptr, 0, &nThreadID);
	//CloseHandle(hThread); hThread = nullptr;

	return bRet;
}