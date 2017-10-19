
// SelfServiceBankClient.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "ConnectAppProtocol.h" //�ṹ��

// CSelfServiceBankClientApp:
// See SelfServiceBankClient.cpp for the implementation of this class
//

/*ZCMsgManager�Ĺ۲���
*/
class CZCMsgObserver {
public:
	//֪ͨ
	virtual void Update(bool bOK, DWORD/*��Ϣ����*/, DWORD/*��ϢID*/, PBYTE/*��Ϣ����*/, INT nMsgLen) = 0;
	//�쳣֪ͨ  �ӿھ������٣���Ȼ����ʵ�ֺ��鷳
	//virtual void Abnormal() = 0;
};


class CLogDialog;
//struct S_New_UserInfo; //��typedef������ض���
//typedef struct S_New_UserInfo S_New_UserInfo;
struct stUserInfo;
struct stCtrlPersonInfo;
struct stCtrlPlanInfo;
struct stACSHostInfo;
struct stEmergPlan;
struct stNode;
enum emNodeType;
class CGobalVariable;

class CSelfServiceBankClientApp : public CWinApp, public CZCMsgObserver
{
public:
	//using ZCMsgHandler = void(CSelfServiceBankClientApp::*)(PBYTE);
	CSelfServiceBankClientApp();
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//inline const std::shared_ptr<CLogDialog>& GetLogDlg() const { return m_oLogDlg; }
	//д��־
	void _cdecl WriteLog(severity_level level, const TCHAR* szMsg, ...);
	//��Ϣ֪ͨ
	virtual void Update(bool, DWORD, DWORD, PBYTE, INT);

	DECLARE_MESSAGE_MAP()
	
public:
	//ʹ��vector��Ϊ�˼����ڴ棻ʹ��map��1����Ϣ�������������Ϣ���鷳
	CString m_strCurUserName; //��ǰ�û���
	std::map<CString, std::shared_ptr<stUserInfo>> m_mapUserInfo;//�û�������Ϣ
	std::vector<std::shared_ptr<stCtrlPersonInfo>> m_vecCtrlPersonInfo;//��Ͻ��Ա��Ϣ
	//std::vector<std::shared_ptr<TAGDOADEPARTMENTINFO_S>> m_vecDepartmentInfo;//������Ϣ
	std::map<UINT8, std::shared_ptr<stCtrlPlanInfo>> m_mapCtrlPlan;//������Ϣ<�ܿصȼ�,���Խṹ>��������Ϣ���ö��ģ�Ϊ�˷������ʹ����map������û�����ù��Ͳ���
	//std::vector<std::shared_ptr<stACSHostInfo>> m_vecACSHostInfo;//�Ž�������Ϣ��Ҫ���Ϲܿصȼ�����Ϣ˭�ȵ��ֲ�ȷ��
	std::map<CString, std::shared_ptr<stACSHostInfo>> m_mapACSHostInfo;//�Ž�������Ϣ���������ֲ��ظ�
	std::vector<std::shared_ptr<stEmergPlan>> m_vecEMPlanInfo;//Ԥ����Ϣ
	std::map<emNodeType, std::vector<std::shared_ptr<stNode>>> m_mapNodeInfo;//�ڵ���Ϣ
	std::shared_ptr<CGobalVariable> m_oGobal;//ȫ�ֱ���

private:
	//��ʼ����־
	bool InitLog();	
	//��ʼ��ZCMsgManager��Ϣ������
	void InitZCMsgHandler();
	//��ǰ�û���Ϣ
	void ZCMsgCurrentUserInfo(PBYTE, DWORD, INT);
	//�������ȡ�û���Ϣ
	std::shared_ptr<stUserInfo>& CreateOrGetUserInfo(const CString& str);
	//�û���ϸ��Ϣ
	void ZCMsgUserDetailInfo(PBYTE, DWORD, INT);
	//�û�Ȩ����Ϣ
	void ZCMsgDisposalInfo(PBYTE, DWORD, INT);
	//������Ϣ
	void ZCMsgAreaInfo(PBYTE, DWORD, INT);
	//������Ϣ
	void ZCMsgDevHostInfo(PBYTE, DWORD, INT);
	//ǰ���豸��Ϣ
	void ZCMsgDeviceInfo(PBYTE, DWORD, INT);
	//��Ͻ��Ա��Ϣ
	void ZCMsgCtrlPersonInfo(PBYTE, DWORD, INT);
	//��Ͻ��Աͷ��
	void ZCMsgCtrlHeadPic(PBYTE, DWORD, INT);
	//������Ϣ
	void ZCMsgDepartmentInfo(PBYTE, DWORD, INT);
	//�Ž����ӹ�ϵ
	void ZCMsgEntranceRelation(PBYTE, DWORD, INT);
	//�����Ž�������Ϣ
	void ZCMsgACSHostInfo(PBYTE, DWORD, INT);
	//�ܿصȼ���Ϣ
	void ZCMsgCtrlLevelInfo(PBYTE, DWORD, INT);
	//�ܿز�����Ϣ
	void ZCMsgCtrlPlanInfo(PBYTE, DWORD, INT);
	//��λ��Ϣ
	void ZCMsgKeypartInfo(PBYTE, DWORD, INT);
	//�Ž�������������ͷ�豸
	void ZCMsgACSHostLinkCameraInfo(PBYTE, DWORD, INT);
	//�Ž����������Խ��豸
	void ZCMsgACSHostLinkTalkInfo(PBYTE, DWORD, INT);
	//��ֵ�����豸
	//shared_ptr<stACSHostInfo>& ZCMsgHelper_SetACSHostRelDeviceInfo(const int nDevID);
	//���д�������Ϣ
	void ZCMsgHandlerInfo(PBYTE, DWORD, INT);
	//�û��Ž�����ͷ������Ϣ
	void ZCMsgDoorRelationInfo(PBYTE, DWORD, INT);
	//����Ԥ����Ϣ
	void ZCMsgEMPlanInfo(PBYTE, DWORD, INT);
	//std::shared_ptr<CLogDialog> m_oLogDlg = 0;//��־�Ի���


	//�����ص�
	static void __stdcall ServerExcepCallBack(unsigned long dwExceptMsg, long lHandle, unsigned long dwUser);
	static void __stdcall MsgCallBackFunc(long lUserID, DWORD MsgType, BYTE *chMsgBuf, DWORD dwBufSize,
		unsigned int nMsgID, DWORD dwUser);

private:
	std::map<DWORD, void(CSelfServiceBankClientApp::*)(PBYTE, DWORD, INT)> m_mapZCMsgHandler;//ZCMsgManager��Ϣ������

};

extern CSelfServiceBankClientApp theApp;



//ȫ�ֱ���
class CGobalVariable {
private:
	//GDI+��ʼ��
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;
	CString strExePath;//exe·��
	
	//boost::log::sources::wseverity_logger< severity_level > m_slog;//������־��
	//CString m_strStgCfgPath;//�����ĵ�·��
	//std::vector<StgCfg*> m_vecCfg;//����
	//HANDLE m_hEventReadStgCfg;//��ȡ�����߳�����¼�
	
public:
	long nCMSHander = -1;//��¼���Ĺ���������ɹ����صĲ������
	/*UI���֣�������Ϊ������
	*/
	const Color cstClrTitle = Color(54, 132, 215);//������ɫ
	const int cstnTitleHeight = 30;//����߶�

	//Ĭ������  ���ɹ�����ΪGDI+��û�г�ʼ��
	//std::shared_ptr<FontFamily> cstFontFamily;
	//std::shared_ptr<Gdiplus::Font> cstFont = 0; //�����С������˽��
	//Gdiplus::Font* cstFont = 0;//�����С

	//std::shared_ptr<SolidBrush> cstSolidBrushText = 0;//�ı���ɫ
	//SolidBrush* cstSolidBrushText = 0;  Clone���ص���Brush*
	//static FontFamily cstFontFamily = (_T("΢���ź�"));

public:
	CGobalVariable();
	~CGobalVariable();
	bool Init();
	inline const CString& GetExePath() const { return strExePath; }
	//inline const long GetCMSHander() const { return nCMSHander; }
	//inline decltype(m_slog)& GetLog() { return m_slog; }
};




/*UI������
*/
class CUICfg {
public:
	//����ui����
	void SetUICfg(std::string s);

private:
	//ƥ�䵽ui����
	virtual bool OnMatchUICfg(const boost::smatch& what) = 0;
	//�Ƿ���ui����
	bool HasUICfg(const std::string& str);

protected:
	//���캯����ʼ��
	std::vector<std::string> m_vecUICfg;//ui����
	boost::regex m_uiregex;//ui����
};


