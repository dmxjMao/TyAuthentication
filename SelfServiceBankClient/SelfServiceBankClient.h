
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

class CLogDialog;
class CSelfServiceBankClientApp : public CWinApp
{
public:
	CSelfServiceBankClientApp();

public:
	virtual BOOL InitInstance();
	//inline const std::shared_ptr<CLogDialog>& GetLogDlg() const { return m_oLogDlg; }
	//写日志
	void _cdecl WriteLog(severity_level, const TCHAR* szMsg, ...);


	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();

private:
	bool InitLog();
	//std::shared_ptr<CLogDialog> m_oLogDlg = 0;//日志对话框
};

extern CSelfServiceBankClientApp theApp;



//全局类，后期作为theApp成员
struct StgCfg;
class CGobalVariable {
private:
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
	const CString& GetExePath() const { return m_strExePath; }
};
extern CGobalVariable g_GobalVariable; //全局变量