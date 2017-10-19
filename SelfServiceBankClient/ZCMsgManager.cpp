#include "stdafx.h"
//#include <objbase.h >
#include "ZCMsgManager.h"

#include "SelfServiceBankClient.h" //观察者1
#include "SelfServiceBankClientDlg.h" //观察者2

#pragma comment(lib,"..\\ZCMsgManager\\TjtyTcpClientModule.lib")
CZCMsgManager* CZCMsgManager::m_pZcInst = NULL;

//
//extern CSearchStatisticsDlg  *g_SearchStatisticsDlg;
//extern CTyOpenDoorDlg  *g_cOpenDoorDlg;
//extern COpenDoorGeneralListDlg * g_cOpenDoorGeneralListDlg;
//extern COpenDoorApplyDlg* g_cOpenDoorApplyDlg ;
//extern CRemoteAuthenticationPopUpDLg* g_cRemotePopUpDlg;
//CRITICAL_SECTION g_csPreCaptureVector;  //保证std::map<DWORD, vector<CString > > m_mapPreCapture同步
//#define CTRLEVELNAMELENGTH   128
//#define GUIDLENGTH                         64
//
///*typedef std::map<DWORD, vector<CString> > STRNG2VECTOR;*/
//typedef std::map<DWORD, vector<CString > > STRING2VECTOR;

/*
消息的反馈并不是按顺序来的，所以要存下来，然后用时查找，
或者 做同步处理（等待必需的数据获取到）
*/

//消息描述
//请求描述
std::map<DWORD, TCHAR*> g_mapZCMsgReqInfo = {
	{ ZC_MSG_APP_CURUSERINFOEX, _T("请求当前用户信息...") },
	{ ZC_MSG_APP_OPENDOOR_DISPOSALINFO, _T("请求当前用户权限...") }, 
	{ ZC_MSG_APP_ALLAREAINFO, _T("请求区域信息...") },
	{ ZC_MSG_APP_ALLDEVICEINFO, _T("请求平台所有主机信息...") },
	{ ZC_MSG_APP_OPENDOOR_GETALLPEPOLEINFO, _T("请求所有需管辖的出入人员信息...") },
	//{ ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO, _T("请求部门信息...") },
	{ ZC_MSG_APP_OPENDOOR_ACCESSRELATION, _T("请求门禁主从关系...") },
	{ ZC_MSG_APP_OPENDOOR_GETALLACSHOSTINFO, _T("请求所有门禁主机信息...") },
	{ ZC_MSG_APP_OPENDOOR_CTRLLEVELMULINFO, _T("请求所有管控信息...") },
	{ ZC_MSG_APP_OPENDOOR_CTRLLEVELPLAN, _T("请求所有管控策略信息...") },
	//{ ZC_MSG_APP_ALLKEYPARTINFO, _T("请求所有部位信息...") },
	{ ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKINFO, _T("请求门禁主机关联摄像头设备...") },
	{ ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKTALKINFO, _T("请求门禁主机关联对讲设备...") },
	{ ZC_MSG_APP_ALLUSERINFO, _T("请求所有处置人姓名...") },
	{ ZC_MSG_APP_OPENDOOR_USERDOORCAMERARELATION, _T("请求获取用户门禁摄像头关联信息...") },
	{ ZC_MSG_APP_PLANINFO, _T("请求所有预案信息...") }
	//{ ZC_MSG_APP_SYSDORCTOR_CAMERAINFO, _T("请求平台前端设备信息...") },
	
	
	
};
//反馈描述
std::map<DWORD, TCHAR*> g_mapZCMsgErrInfo = {
	{ ZC_MSG_COMMON_CURUSERINFOEX, _T("获取当前用户信息失败！") },
	{ ZC_MSG_COMMON_USERALLINFO, _T("获取用户详情信息失败！") },
	{ ZC_MSG_OPENDOOR_DISPOSALINFO, _T("获取当前用户权限信息失败！") },
	{ ZC_MSG_COMMON_ALLAREAINFO, _T("获取区域信息失败！") },
	{ ZC_MSG_COMMON_ALLDEVICEINFO, _T("获取平台所有主机信息失败！") },
	{ ZC_MSG_OPENDOOR_GETALLPEPOLEINFO, _T("获取管辖人员信息失败！") },
	{ ZC_MSG_COMMON_DOWNLOADPIC, _T("获取头像信息失败！") },
	//{ ZC_MSG_OPENDOOR_DEPARTMENTINFO, _T("获取部门信息失败！") },
	{ ZC_MSG_OPENDOOR_ACCESSRELATION, _T("获取门禁主从关系失败！") },
	{ ZC_MSG_OPENDOOR_GETALLACSHOSTINFO, _T("获取所有门禁主机信息失败！") },
	{ ZC_MSG_OPENDOOR_CTRLLEVELMULINFO, _T("获取所有管控信息失败！") },
	{ ZC_MSG_OPENDOOR_CTRLLEVELPLAN, _T("获取所有管控策略信息失败！") },
	//{ ZC_MSG_COMMON_ALLKEYPARTINFO, _T("获取所有部位信息失败！") },
	{ ZC_MSG_OPENDOOR_GETACSHOSTLINKINFO, _T("获取门禁主机关联摄像头设备失败！") },
	{ ZC_MSG_OPENDOOR_GETACSHOSTLINKTALKINFO, _T("获取门禁主机关联对讲设备失败！") },
	{ ZC_MSG_COMMON_ALLUSERINFO, _T("获取所有处置人姓名失败！") },
	{ ZC_MSG_OPENDOOR_USERDOORCAMERARELATION, _T("获取用户门禁摄像头关联信息失败！") },
	{ ZC_MSG_COMMON_PLANINFO, _T("获取所有预案信息失败！") },
	//{ ZC_MSG_SYSDORCTOR_CAMERAINFO, _T("获取平台前端设备信息失败！") }
	
	
};



//消息回调函数
void _stdcall pfCallback(ZC_MSG_HEAD zMsgHead, void* pMessage, INT pnMessageSize, DWORD dwUser)
{
	PBYTE pBuf = (PBYTE)pMessage;
	ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	bool bOK = pResult->nOK ? true : false; //反馈是否成功
	
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
	//CString strDebugName = _T("第三方认证");
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
	//	CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("<<ERROR>>class = CZCMsgManager: func = CZCMsgManager(void) detail = 分配内存失败");
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
	//exe目录
	CString str = theApp.m_oGobal->GetExePath();

	//配置
	int iPort = 5555, iFlag = 0;

	TJTY_TcpClient_SetThreadCount(1,1);

	TCPCLIENTMODULE_INIT_INFO info = {0};
	info.dwUser = (DWORD)this;;
	info.pfCallback = pfCallback;
	info.pfStateCallBack = pfStateCallback;
	info.wLoaclModuleType = ZC_MODULE_OPENDOOR; //三方认证模块
	info.wPort = iPort;
	info.wProtocolVersion = 0;
	TJTY_TcpClient_Init(info);
	//m_bInit = true;
	if(1==iFlag) 
	{//写日志
		TJTY_TcpClient_SetLogWriteType(true);
	}

	//不死等，以防初始化函数连续调用时，状态回掉无反馈
	if(WaitForSingleObject(m_hConnectEvent, 2000) != WAIT_OBJECT_0)
	{
		//连ZCMsgService.exe
		theApp.WriteLog(error, _T("CZCMsgManager::Init failed !"));
		AfxMessageBox(_T("连接消息服务失败！"));
		return false;
	}

	//添加观察者
	extern CSelfServiceBankClientDlg* g_pMainDlg;
	AddObserver(&theApp);
	AddObserver(g_pMainDlg);

	//请求初始信息
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
		MessageBox(NULL,_T("消息服务连接失败！"),_T("提示"),MB_OK);
		return false;
	}

	TCPCLIENTMODULE_SEND_INFO info = {0};

	info.wReservedEx = 0;
	info.wModuleType = wModlueType; 
	info.dwMsgId = dwMsgId;
	info.dwMsgType = dwMsgType;
	info.dwLength = nBufSize;
	info.pBuffer = pBuf;

	//复制info，所以pBuffer可以delete
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
		ZC_MSG_APP_CURUSERINFOEX ,//当前用户信息
		ZC_MSG_APP_OPENDOOR_DISPOSALINFO,//权限信息
		ZC_MSG_APP_ALLAREAINFO,//区域信息
		ZC_MSG_APP_ALLDEVICEINFO,//请求平台所有主机信息
		ZC_MSG_APP_OPENDOOR_GETALLPEPOLEINFO,//所有需管辖的出入人员信息
		//ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO,//部门信息
		ZC_MSG_APP_OPENDOOR_ACCESSRELATION,//门禁主从关系
		ZC_MSG_APP_OPENDOOR_GETALLACSHOSTINFO,//所有门禁主机信息
		ZC_MSG_APP_OPENDOOR_CTRLLEVELMULINFO,//管控信息
		ZC_MSG_APP_OPENDOOR_CTRLLEVELPLAN,//管控策略信息
		//ZC_MSG_APP_ALLKEYPARTINFO,//部位信息
		ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKINFO, //门禁主机关联摄像头设备
		ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKTALKINFO,//门禁主机关联对讲设备
		ZC_MSG_APP_ALLUSERINFO,//所有处置人姓名
		ZC_MSG_APP_OPENDOOR_USERDOORCAMERARELATION, //用户门禁摄像头关联信息
		ZC_MSG_APP_PLANINFO//请求所有预案信息
		//ZC_MSG_APP_SYSDORCTOR_CAMERAINFO,//请求平台前端设备信息
	};

	for (auto id : vecMsgID) {
		theApp.WriteLog(trace, g_mapZCMsgReqInfo[id]);
		RequestMsg(ZC_MODULE_APP, id);
	}

}


