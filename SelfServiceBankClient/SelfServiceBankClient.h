
// SelfServiceBankClient.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "CommonDefine.h"

// CSelfServiceBankClientApp:
// See SelfServiceBankClient.cpp for the implementation of this class
//

class CSelfServiceBankClientApp : public CWinApp
{
public:
	CSelfServiceBankClientApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CSelfServiceBankClientApp theApp;



//全局类
struct StgCfg;
class CGobalVariable {
public:
	//GDI+初始化
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;

	CString m_strExePath;//exe路径
	//CString m_strStgCfgPath;//配置文档路径
	//std::vector<StgCfg*> m_vecCfg;//配置
	//HANDLE m_hEventReadStgCfg;//读取配置线程完成事件
	
	//const
	//字体
	//const FontFamily cstFontFamily = _T("微软雅黑");
	//const Gdiplus::Font cstFont = Gdiplus::Font(&cstFontFamily, 12, FontStyleRegular, UnitPixel);
	//const SolidBrush cstSolidBrushText = Color(125, 125, 125);

public:
	CGobalVariable();
	~CGobalVariable();
	bool Init();
};
extern CGobalVariable g_GobalVariable; //全局变量