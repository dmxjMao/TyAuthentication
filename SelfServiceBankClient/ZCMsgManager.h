#pragma once

#include "TjtyTcpClientModule.h"
#include "ConnectAppProtocol.h"
#include "ZCProtocol.h"
//#include "DeBugLog.h"

/*后期ZCMsg放到dll工程中，以组件形式给出接口，
入接口：发送消息，
出接口：注册感兴趣的消息及处理方法
*/
//
#define MESSAGENUM                70  //消息条数 

//
#define ZC_MSG_SERIAL_ID_MAX_VALUE				10000	// 消息序列号最大值
//#define USER_MSG_SERIAL_ID_DELETE_DEPARTMENT	10001	// 删除部门消息序列号

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
	//msgid有特殊作用
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

	void RequestInitMsg();//请求初始信息

private:
	std::list<CZCMsgObserver*> m_liObserver;//观察者
	bool m_bInit; //是否初始化完成
	HANDLE m_hConnectEvent;//连接ZCMsgManager.exe事件

	DWORD m_dwMsgID = 0; //消息码
	//DWORD m_LastError; //上一条错误信息
	//bool m_bError[MESSAGENUM] = { true }; //错误
	//int m_iErrorCode[MESSAGENUM] = { 0 };//错误码
//	DWORD m_dGroup;  
//	char m_cImage[512];
//	bool m_bIsAbnormalId;  //标定是否为异常录入请求认证ID
//	bool m_bIsAttachment;  //标志否是为OpenDoolApplyDlg请求
//	int m_iShow;    //浮窗是否显示
//	CDebugLogService* m_cDebugLog;
//	std::map<int,char*> m_vPersonPhoto;

};
