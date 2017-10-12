
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

/*ZCMsgManager�Ĺ۲���
*/
class CZCMsgObserver {
public:
	//֪ͨ
	virtual void Update(bool bOK, DWORD/*��Ϣ����*/, DWORD/*��ϢID*/, PBYTE/*��Ϣ����*/) = 0;
	//�쳣֪ͨ  �ӿھ������٣���Ȼ����ʵ�ֺ��鷳
	//virtual void Abnormal() = 0;
};


class CLogDialog;
//struct S_New_UserInfo; //��typedef������ض���
//typedef struct S_New_UserInfo S_New_UserInfo;


class CSelfServiceBankClientApp : public CWinApp, public CZCMsgObserver
{
public:
	//using ZCMsgHandler = void(CSelfServiceBankClientApp::*)(PBYTE);
	CSelfServiceBankClientApp();

public:
	virtual BOOL InitInstance();
	//inline const std::shared_ptr<CLogDialog>& GetLogDlg() const { return m_oLogDlg; }
	//д��־
	void _cdecl WriteLog(severity_level level, const TCHAR* szMsg, ...);
	//��Ϣ֪ͨ
	virtual void Update(bool, DWORD, DWORD, PBYTE);
	//virtual void Abnormal();

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();

private:
	//��ʼ����־
	bool InitLog();
	
	//��ʼ��ZCMsgManager��Ϣ������
	void InitZCMsgHandler();
	//��ǰ�û���Ϣ
	void ZCMsgCurrentUserInfo(PBYTE, DWORD);
	//�������ȡ�û���Ϣ
	std::shared_ptr<stUserInfo>& CreateOrGetUserInfo(const CString& str);
	//�û���ϸ��Ϣ
	void ZCMsgUserDetailInfo(PBYTE, DWORD);
	//�û�Ȩ����Ϣ
	void ZCMsgDisposalInfo(PBYTE, DWORD);
	//��Ͻ��Ա��Ϣ
	void ZCMsgControledPersonInfo(PBYTE, DWORD);
	//��Ͻ��Աͷ��
	void ZCMsgControledHeadPic(PBYTE, DWORD);
	//������Ϣ
	void ZCMsgDepartmentInfo(PBYTE, DWORD);

	//std::shared_ptr<CLogDialog> m_oLogDlg = 0;//��־�Ի���

private:
	std::map<DWORD, void(CSelfServiceBankClientApp::*)(PBYTE, DWORD)> m_mapZCMsgHandler;//ZCMsgManager��Ϣ������
	std::map<CString, std::shared_ptr<stUserInfo>> m_mapUserInfo;//�û�������Ϣ
	CString m_strCurUserName; //��ǰ�û���
	std::vector<std::shared_ptr<stControledPersonInfo>> m_vecControledPersonInfo;//��Ͻ��Ա��Ϣ
	//std::vector<std::shared_ptr<TAGDOADEPARTMENTINFO_S>>

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

