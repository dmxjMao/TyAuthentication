
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
	//д��־
	void _cdecl WriteLog(severity_level, const TCHAR* szMsg, ...);


	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();

private:
	bool InitLog();
	//std::shared_ptr<CLogDialog> m_oLogDlg = 0;//��־�Ի���
};

extern CSelfServiceBankClientApp theApp;



//ȫ���࣬������ΪtheApp��Ա
struct StgCfg;
class CGobalVariable {
private:
	//GDI+��ʼ��
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;

	CString m_strExePath;//exe·��
	//CString m_strStgCfgPath;//�����ĵ�·��
	//std::vector<StgCfg*> m_vecCfg;//����
	//HANDLE m_hEventReadStgCfg;//��ȡ�����߳�����¼�
	
	//const
	//����
	//const FontFamily cstFontFamily = _T("΢���ź�");
	//const Gdiplus::Font cstFont = Gdiplus::Font(&cstFontFamily, 12, FontStyleRegular, UnitPixel);
	//const SolidBrush cstSolidBrushText = Color(125, 125, 125);

public:
	CGobalVariable();
	~CGobalVariable();
	bool Init();
	const CString& GetExePath() const { return m_strExePath; }
};
extern CGobalVariable g_GobalVariable; //ȫ�ֱ���