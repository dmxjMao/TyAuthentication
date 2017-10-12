#pragma once

#include "TjtyTcpClientModule.h"
#include "ConnectAppProtocol.h"
#include "ZCProtocol.h"
//#include "DeBugLog.h"

/*����ZCMsg�ŵ�dll�����У��������ʽ�����ӿڣ�
��ӿڣ�������Ϣ��
���ӿڣ�ע�����Ȥ����Ϣ��������
*/
//
#define MESSAGENUM                70  //��Ϣ���� 

//
#define ZC_MSG_SERIAL_ID_MAX_VALUE				10000	// ��Ϣ���к����ֵ
//#define USER_MSG_SERIAL_ID_DELETE_DEPARTMENT	10001	// ɾ��������Ϣ���к�

class CZCMsgObserver;
class CZCMsgManager
{
public:
	static CZCMsgManager* m_pZcInst;
	static CZCMsgManager* Instance() { return (m_pZcInst == NULL ? m_pZcInst = new CZCMsgManager() : m_pZcInst); }
	static void FreeInstance() { MySafeDelete(m_pZcInst); }

	bool Init(DWORD dwUser);
	void SetInitState(bool bInit);
	bool RequestMsg(WORD wModlueType, DWORD dwMsgType, PBYTE pBuf = 0, DWORD nBufSize = 0);
	//msgid����������
	bool RequestMsgWithMsgID(WORD wModlueType, DWORD dwMsgType, DWORD dwMsgID, PBYTE pBuf = 0, DWORD nBufSize = 0);
	void NotifyObserver(bool bOK, DWORD dwMsgType, PBYTE pMsg = 0, DWORD dwMsgID = 0);


private:
	CZCMsgManager(void);
	~CZCMsgManager(void);
	bool UnInit();
	bool AddSendMsg(WORD wModlueType, DWORD dwMsgId, DWORD dwMsgType, BYTE* pBuf, DWORD nBufSize);
	//void SetLastError(DWORD nError);
	DWORD GetValidMsgID();

	void AddObserver(CZCMsgObserver*);
	void RemoveObserver(CZCMsgObserver*);

	void RequestInitMsg();//�����ʼ��Ϣ

private:
	std::list<CZCMsgObserver*> m_liObserver;//�۲���
	bool m_bInit; //�Ƿ��ʼ�����
	HANDLE m_hConnectEvent;//����ZCMsgManager.exe�¼�

	DWORD m_dwMsgID = 0; //��Ϣ��
	//DWORD m_LastError; //��һ��������Ϣ
	//bool m_bError[MESSAGENUM] = { true }; //����
	//int m_iErrorCode[MESSAGENUM] = { 0 };//������
//	DWORD m_dGroup;  
//	char m_cImage[512];
//	bool m_bIsAbnormalId;  //�궨�Ƿ�Ϊ�쳣¼��������֤ID
//	bool m_bIsAttachment;  //��־����ΪOpenDoolApplyDlg����
//	int m_iShow;    //�����Ƿ���ʾ
//	CDebugLogService* m_cDebugLog;
//	std::map<int,char*> m_vPersonPhoto;

};
