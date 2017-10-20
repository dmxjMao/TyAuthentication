#include "stdafx.h"
//#include <objbase.h >
#include "ZCMsgManager.h"

#include "SelfServiceBankClient.h" //�۲���1
#include "SelfServiceBankClientDlg.h" //�۲���2

#pragma comment(lib,"..\\ZCMsgManager\\TjtyTcpClientModule.lib")
CZCMsgManager* CZCMsgManager::m_pZcInst = NULL;



/*
��Ϣ�ķ��������ǰ�˳�����ģ�����Ҫ��������Ȼ����ʱ���ң�
���� ��ͬ�������ȴ���������ݻ�ȡ����
*/

//��Ϣ����
//��������
std::map<DWORD, TCHAR*> g_mapZCMsgReqInfo = {
	{ ZC_MSG_APP_CURUSERINFOEX, _T("����ǰ�û���Ϣ...") },//29004
	{ ZC_MSG_APP_OPENDOOR_DISPOSALINFO, _T("����ǰ�û�Ȩ��...") }, //20426
	{ ZC_MSG_APP_ALLAREAINFO, _T("����������Ϣ...") },//29050
	{ ZC_MSG_APP_ALLDEVICEINFO, _T("����ƽ̨����������Ϣ...") },//29057
	{ ZC_MSG_APP_SYSDORCTOR_CAMERAINFO, _T("����ƽ̨����̽ͷ��Ϣ...") },//20513
	{ ZC_MSG_APP_OPENDOOR_GETALLPEPOLEINFO, _T("�����������Ͻ�ĳ�����Ա��Ϣ...") },//20416
	//{ ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO, _T("��������Ϣ...") },//
	{ ZC_MSG_APP_OPENDOOR_ACCESSRELATION, _T("�����Ž����ӹ�ϵ...") },//20427
	{ ZC_MSG_APP_OPENDOOR_GETALLACSHOSTINFO, _T("���������Ž�������Ϣ...") },//20413
	{ ZC_MSG_APP_OPENDOOR_CTRLLEVELMULINFO, _T("�������йܿ���Ϣ...") },//20428
	{ ZC_MSG_APP_OPENDOOR_CTRLLEVELPLAN, _T("�������йܿز�����Ϣ...") },//20427
	//{ ZC_MSG_APP_ALLKEYPARTINFO, _T("�������в�λ��Ϣ...") },//
	{ ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKINFO, _T("�����Ž�������������ͷ�豸...") },//20414
	{ ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKTALKINFO, _T("�����Ž����������Խ��豸...") },//20415
	{ ZC_MSG_APP_ALLUSERINFO, _T("�������д���������...") },//29005
	{ ZC_MSG_APP_OPENDOOR_USERDOORCAMERARELATION, _T("�����ȡ�û��Ž�����ͷ������Ϣ...") },//20432
	{ ZC_MSG_APP_PLANINFO, _T("��������Ԥ����Ϣ...") }//29002
	
	
	
};
//��������
std::map<DWORD, TCHAR*> g_mapZCMsgErrInfo = {
	{ ZC_MSG_COMMON_CURUSERINFOEX, _T("��ȡ��ǰ�û���Ϣʧ�ܣ�") },//2003
	{ ZC_MSG_COMMON_USERALLINFO, _T("��ȡ�û�������Ϣʧ�ܣ�") },//2006
	{ ZC_MSG_OPENDOOR_DISPOSALINFO, _T("��ȡ��ǰ�û�Ȩ����Ϣʧ�ܣ�") },//51176
	{ ZC_MSG_COMMON_ALLAREAINFO, _T("��ȡ������Ϣʧ�ܣ�") },//2050
	{ ZC_MSG_COMMON_ALLDEVICEINFO, _T("��ȡƽ̨����������Ϣʧ�ܣ�") },//2057
	{ ZC_MSG_SYSDORCTOR_CAMERAINFO, _T("��ȡƽ̨����̽ͷ��Ϣʧ�ܣ�") },//52031
	{ ZC_MSG_OPENDOOR_GETALLPEPOLEINFO, _T("��ȡ��Ͻ��Ա��Ϣʧ�ܣ�") },//51166
	{ ZC_MSG_COMMON_DOWNLOADPIC, _T("��ȡͷ����Ϣʧ�ܣ�") },//2001
	//{ ZC_MSG_OPENDOOR_DEPARTMENTINFO, _T("��ȡ������Ϣʧ�ܣ�") },//
	{ ZC_MSG_OPENDOOR_ACCESSRELATION, _T("��ȡ�Ž����ӹ�ϵʧ�ܣ�") },//51177
	{ ZC_MSG_OPENDOOR_GETALLACSHOSTINFO, _T("��ȡ�����Ž�������Ϣʧ�ܣ�") },//51163
	{ ZC_MSG_OPENDOOR_CTRLLEVELMULINFO, _T("��ȡ���йܿ���Ϣʧ�ܣ�") },//51178
	{ ZC_MSG_OPENDOOR_CTRLLEVELPLAN, _T("��ȡ���йܿز�����Ϣʧ�ܣ�") },//51179
	//{ ZC_MSG_COMMON_ALLKEYPARTINFO, _T("��ȡ���в�λ��Ϣʧ�ܣ�") },
	{ ZC_MSG_OPENDOOR_GETACSHOSTLINKINFO, _T("��ȡ�Ž�������������ͷ�豸ʧ�ܣ�") },//51164
	{ ZC_MSG_OPENDOOR_GETACSHOSTLINKTALKINFO, _T("��ȡ�Ž����������Խ��豸ʧ�ܣ�") },//51165
	{ ZC_MSG_COMMON_ALLUSERINFO, _T("��ȡ���д���������ʧ�ܣ�") },//2004
	{ ZC_MSG_OPENDOOR_USERDOORCAMERARELATION, _T("��ȡ�û��Ž�����ͷ������Ϣʧ�ܣ�") },//51182
	{ ZC_MSG_COMMON_PLANINFO, _T("��ȡ����Ԥ����Ϣʧ�ܣ�") },//102
	
	
};



//��Ϣ�ص�����
void _stdcall pfCallback(ZC_MSG_HEAD zMsgHead, void* pMessage, INT pnMessageSize, DWORD dwUser)
{
	PBYTE pBuf = (PBYTE)pMessage;
	ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	bool bOK = pResult->nOK ? true : false; //�����Ƿ�ɹ�
	
	//ZCMsgManager.exe�汾���ԣ���Ϣ���վͻ�������
	CZCMsgManager::Instance()->NotifyObserver(bOK, zMsgHead.dwMsgType, zMsgHead.dwMsgId, pBuf, pnMessageSize);
	
}

void _stdcall pfStateCallback(DWORD dwState, void* pMessage, INT pnMessageSize, DWORD dwUser)
{
	CZCMsgManager* pZCMsgManager = (CZCMsgManager*)dwUser;
	if(pZCMsgManager == NULL)
	{
		return;
	}
	switch(dwState)
	{
	case CM_ONCONNECT:
		{
			pZCMsgManager->SetInitState(true);
			break;
		}
	default:
		break; 
	}
}

CZCMsgManager::CZCMsgManager(void): m_bInit(false)
{
	//for(int i=0;i<MESSAGENUM;++i)
	//{
	//	m_bError[i]=true;
	//	m_iErrorCode[i]=0;
	//}
	//m_iShow=0;
	//memcpy(m_CurrentUserInfo.chUserName,"\0",64);
	//m_CurrentUserInfo.chUserName[0] = 0;
	//InitializeCriticalSection(&g_csPreCaptureVector);
	//CString strDebugName = _T("��������֤");
	//char* tmp =NULL;
	//CStringToChar(strDebugName, &tmp);
	//m_cDebugLog =new CDebugLogService(tmp);
	//free(tmp);
	//tmp = NULL;
	
	//memset(&m_cImage, 0, 512);
	//try
	//{
	//m_pUserDetail = new S_New_UserInfo;
	//}
	//catch (std::bad_alloc)
	//{
	//	CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("<<ERROR>>class = CZCMsgManager: func = CZCMsgManager(void) detail = �����ڴ�ʧ��");
	//}
	//memset(m_pUserDetail, 0 , sizeof(S_New_UserInfo));
	//memset(&m_tOpenDoorDisposalInfo, 0, sizeof(m_tOpenDoorDisposalInfo));

	m_hConnectEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	m_dwMsgID = 0;
}

CZCMsgManager::~CZCMsgManager(void)
{
	//DeleteCriticalSection(&g_csPreCaptureVector);
	//std::map<int,char*>::iterator mapPhotoIter = CZCMsgManager::Instance()->m_vPersonPhoto.begin();
	//for (; mapPhotoIter != CZCMsgManager::Instance()->m_vPersonPhoto.end(); mapPhotoIter++)
	//{
	//	delete(mapPhotoIter->second);
	//	mapPhotoIter->second = NULL;
	//}	
	
	/*CZCMsgManager::Instance()->m_vPersonPhoto.clear();
	delete m_pUserDetail;
	if (NULL != m_cDebugLog)
	{
		delete m_cDebugLog;
		m_cDebugLog = NULL;
	}*/

	//CZCMsgManager::Instance()->m_vecStaffDepartment.clear();

	//CZCMsgManager::Instance()->m_vecfAuthGroup.clear();

	//CZCMsgManager::Instance()->m_vecStaffinfo.clear();

	//CZCMsgManager::Instance()->m_vecStaffOperationinfo.clear();

	CloseHandle(m_hConnectEvent); m_hConnectEvent = 0;
}

bool CZCMsgManager::Init(DWORD dwUser)
{
	//exeĿ¼
	CString str = theApp.m_oGobal->GetExePath();

	//����
	int iPort = 5555, iFlag = 0;

	TJTY_TcpClient_SetThreadCount(1,1);

	TCPCLIENTMODULE_INIT_INFO info = {0};
	info.dwUser = (DWORD)this;;
	info.pfCallback = pfCallback;
	info.pfStateCallBack = pfStateCallback;
	info.wLoaclModuleType = ZC_MODULE_OPENDOOR; //������֤ģ��
	info.wPort = iPort;
	info.wProtocolVersion = 0;
	TJTY_TcpClient_Init(info);
	//m_bInit = true;
	if(1==iFlag) 
	{//д��־
		TJTY_TcpClient_SetLogWriteType(true);
	}

	//�����ȣ��Է���ʼ��������������ʱ��״̬�ص��޷���
	if(WaitForSingleObject(m_hConnectEvent, 2000) != WAIT_OBJECT_0)
	{
		//��ZCMsgService.exe
		theApp.WriteLog(error, _T("CZCMsgManager::Init failed !"));
		AfxMessageBox(_T("������Ϣ����ʧ�ܣ�"));
		return false;
	}

	//��ӹ۲���
	extern CSelfServiceBankClientDlg* g_pMainDlg;
	AddObserver(&theApp);
	AddObserver(g_pMainDlg);

	//�����ʼ��Ϣ
	RequestInitMsg();

	return m_bInit;
}

void CZCMsgManager::SetInitState(bool bInit)
{
	m_bInit = bInit;
	SetEvent(m_hConnectEvent);
}


bool CZCMsgManager::RequestMsg(WORD wModlueType, DWORD dwMsgType, PBYTE pBuf, DWORD nBufSize)
{
	DWORD dwMsgID = GetValidMsgID();
	AddSendMsg(wModlueType, dwMsgID, dwMsgType, pBuf, nBufSize);
	return true;
}

bool CZCMsgManager::RequestMsgWithMsgID(WORD wModlueType, DWORD dwMsgType, DWORD dwMsgID, PBYTE pBuf, DWORD nBufSize)
{
	return AddSendMsg(wModlueType, dwMsgID, dwMsgType, pBuf, nBufSize);
}

bool CZCMsgManager::AddSendMsg(WORD wModlueType,DWORD dwMsgId,DWORD dwMsgType,BYTE* pBuf,DWORD nBufSize)
{
	if(!m_bInit)
	{
		MessageBox(NULL,_T("��Ϣ��������ʧ�ܣ�"),_T("��ʾ"),MB_OK);
		return false;
	}

	TCPCLIENTMODULE_SEND_INFO info = {0};

	info.wReservedEx = 0;
	info.wModuleType = wModlueType; 
	info.dwMsgId = dwMsgId;
	info.dwMsgType = dwMsgType;
	info.dwLength = nBufSize;
	info.pBuffer = pBuf;

	//����info������pBuffer����delete
	return TJTY_TcpClient_AddWaitSendMsg(info);
}

void CZCMsgManager::AddObserver(CZCMsgObserver* ob)
{
	m_liObserver.push_back(ob);
	m_liObserver.unique();
}


//bool Lambda_RemoveObserver(const CZCMsgObserver* ob) {
//	return 
//}
void CZCMsgManager::RemoveObserver(CZCMsgObserver* ob)
{
	m_liObserver.remove_if(
		[=](const CZCMsgObserver* o) { return ob == o; });
}


void CZCMsgManager::NotifyObserver(bool bOK, DWORD dwMsgType, DWORD dwMsgID, PBYTE pMsg, INT nMsgLen)
{
	for (auto& ob : m_liObserver) {
		ob->Update(bOK, dwMsgType, dwMsgID, pMsg, nMsgLen);
	}
}

bool CZCMsgManager::UnInit()
{
	m_bInit = false; 
	return TJTY_TcpClient_UnInit();
}

//void CZCMsgManager::SetLastError(DWORD nError)
//{
//	m_LastError = nError;
//}

DWORD CZCMsgManager::GetValidMsgID()
{
	++m_dwMsgID;
	if(m_dwMsgID > ZC_MSG_SERIAL_ID_MAX_VALUE)
	{
		m_dwMsgID = 0;
	}
	return m_dwMsgID;
}


void CZCMsgManager::RequestInitMsg()
{
	std::vector<DWORD> vecMsgID = {
		ZC_MSG_APP_CURUSERINFOEX ,//��ǰ�û���Ϣ
		ZC_MSG_APP_OPENDOOR_DISPOSALINFO,//Ȩ����Ϣ
		ZC_MSG_APP_ALLAREAINFO,//������Ϣ
		ZC_MSG_APP_ALLDEVICEINFO,//ƽ̨����������Ϣ
		ZC_MSG_APP_SYSDORCTOR_CAMERAINFO,//ƽ̨����̽ͷ��Ϣ
		ZC_MSG_APP_OPENDOOR_GETALLPEPOLEINFO,//�������Ͻ�ĳ�����Ա��Ϣ
		//ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO,//������Ϣ
		ZC_MSG_APP_OPENDOOR_ACCESSRELATION,//�Ž����ӹ�ϵ
		ZC_MSG_APP_OPENDOOR_GETALLACSHOSTINFO,//�����Ž�������Ϣ
		ZC_MSG_APP_OPENDOOR_CTRLLEVELMULINFO,//�ܿ���Ϣ
		ZC_MSG_APP_OPENDOOR_CTRLLEVELPLAN,//�ܿز�����Ϣ
		//ZC_MSG_APP_ALLKEYPARTINFO,//��λ��Ϣ
		ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKINFO, //�Ž�������������ͷ�豸
		ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKTALKINFO,//�Ž����������Խ��豸
		ZC_MSG_APP_ALLUSERINFO,//���д���������
		ZC_MSG_APP_OPENDOOR_USERDOORCAMERARELATION, //�û��Ž�����ͷ������Ϣ
		ZC_MSG_APP_PLANINFO//��������Ԥ����Ϣ
	};

	for (auto id : vecMsgID) {
		theApp.WriteLog(trace, g_mapZCMsgReqInfo[id]);
		RequestMsg(ZC_MODULE_APP, id);
	}

}


