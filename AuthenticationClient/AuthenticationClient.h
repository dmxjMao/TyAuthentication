
// AuthenticationClient.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "CommonDefine.h"	//��������


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

//ȫ����
struct StgCfg;
class CGobalVariable {
public:
	//GDI+��ʼ��
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;

	CString m_strExePath;//exe·��
	CString m_strStgCfgPath;//�����ĵ�·��
	std::vector<StgCfg*> m_vecCfg;//����
	HANDLE m_hEventReadStgCfg;//��ȡ�����߳�����¼�


public:
	CGobalVariable();
	~CGobalVariable();
	bool Init();
};
extern CGobalVariable g_GobalVariable; //ȫ�ֱ���