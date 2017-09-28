
// AuthenticationClient.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "CommonDefine.h"	//公共定义


// CAuthenticationClientApp:
// See AuthenticationClient.cpp for the implementation of this class
//

class CAuthenticationClientApp : public CWinApp
{
public:
	CAuthenticationClientApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CAuthenticationClientApp theApp;

//全局类
struct StgCfg;
class CGobalVariable {
public:
	//GDI+初始化
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;

	CString m_strExePath;//exe路径
	CString m_strStgCfgPath;//配置文档路径
	std::vector<StgCfg*> m_vecCfg;//配置
	HANDLE m_hEventReadStgCfg;//读取配置线程完成事件


public:
	CGobalVariable();
	~CGobalVariable();
	bool Init();
};
extern CGobalVariable g_GobalVariable; //全局变量