
// SelfServiceBankClient.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "SelfServiceBankClientDlg.h"

#include <boost/log/expressions.hpp> //��ʽ��
#include <boost/date_time/posix_time/posix_time_types.hpp> //ʱ���ʽ
#include <boost/log/support/date_time.hpp>
#include <boost/locale/generator.hpp>
#include <boost/log/sources/severity_logger.hpp> //���� Դ
#include <boost/log/utility/setup/common_attributes.hpp> //��������
#include <boost/log/utility/setup/file.hpp> //sink �ļ�

#include "MyCommonDefine.h"
#include "ZCMsgManager.h"
#include "LogDialog.h"

//��������
#include "TYServerSDK.h"
#pragma comment(lib,"..\\TYServerSDK\\TYServerSDK.lib")
//�����
#include "LoadTJTY_Play.h"
#pragma comment(lib, "..\\TjtyPlayer\\Tjty_Play.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//boost��־
namespace logging = boost::log;
namespace src = logging::sources;
namespace sinks = logging::sinks;
namespace keywords = logging::keywords;
namespace expr = boost::log::expressions;
using namespace logging::trivial;

using std::shared_ptr;
using std::make_shared;
using std::placeholders::_1;

src::wseverity_logger< severity_level > g_slog;//������־��
//BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::logger_mt)

// CSelfServiceBankClientApp

BEGIN_MESSAGE_MAP(CSelfServiceBankClientApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSelfServiceBankClientApp construction

CSelfServiceBankClientApp::CSelfServiceBankClientApp()
{
	m_oGobal = std::make_shared<CGobalVariable>();
	//g_GobalVariable.Init();

	//��ʼ����Ϣ������
	InitZCMsgHandler();

	//���ؽ����
	LoadTJTY_Play(m_oGobal->GetExePath());
}


// The one and only CSelfServiceBankClientApp object

CSelfServiceBankClientApp theApp;
CSelfServiceBankClientDlg* g_pMainDlg = 0;//������Ի���


// CSelfServiceBankClientApp initialization

BOOL CSelfServiceBankClientApp::InitInstance()
{
	//�ڴ���
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	
	//��ʼ����־�����ڹ����оͻ����why��
	InitLog();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CSelfServiceBankClientDlg dlg;
	m_pMainWnd = &dlg;
	g_pMainDlg = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager; pShellManager = nullptr;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}



int CSelfServiceBankClientApp::ExitInstance()
{
	//�ڴ���
	_CrtDumpMemoryLeaks();
	TY_Server_Cleanup();

	return CWinApp::ExitInstance();
}

bool CSelfServiceBankClientApp::InitLog()
{
	//ע�� �ؼ�sink  �ؼ�������theApp::InitInstance�����֮ǰ��log���ü�¼
	//�ָ�Ϊ��IDM_Log��ȡ��־�ļ�

	bool bWriteToFile = true;//�Ƿ�д���ļ�������
	if (bWriteToFile) {
		CString& strExePath = const_cast<CString&>(m_oGobal->GetExePath());//���ڽ�g_GobalVariable�ϵ�theApp��
		
		CString str = strExePath + _T("log");
		if(! PathFileExists(str))
			::CreateDirectory(str, 0);//����Ŀ¼��ֻ�ܴ���һ��

		TCHAR szCurPath[MAX_PATH] = { 0 };
		::GetCurrentDirectory(MAX_PATH, szCurPath);
		::SetCurrentDirectory(str);

		//ע�� �ļ�sink �����޸�ȫ����־�����ȳ�ʼ��
		auto& sink = logging::add_file_log(
			keywords::file_name = "applog_%N.log",
			keywords::rotation_size = 10 * 1024 * 1024, //10M�������ļ�
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),//����
			//keywords::format = "[%TimeStamp%]: %Message%"
			keywords::format = (
				//expr::stream << expr::format<wchar_t>(L"%1%��<%2%>, [ %3% ], { %4% }")
				//% expr::attr< unsigned int >("LineID") % logging::trivial::severity
				//% expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S")
				//% expr::wmessage
				expr::stream << expr::attr< unsigned int >("LineID")
				<< ": <" << logging::trivial::severity
				<< "> " << ",[ "<< expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%H:%M:%S") << " ] " << ",{ " << expr::message << " } "
				)
		);

		
		//sink���Զ�ת��
		std::locale loc = boost::locale::generator()("en_US.UTF-8");
		sink->imbue(loc);

		logging::add_common_attributes();//��������

		//��־�Ի���
		//if(nullptr == m_oLogDlg){
		//	m_oLogDlg = std::make_shared<CLogDialog>();
		//	//m_oLogDlg->Create(IDD_Log, this); CWinApp����CWnd��û��
		//}

		//��һ����־
		WriteLog(trace, _T("boost log init success."));

		::SetCurrentDirectory(szCurPath);
	}

	return true;
}

void CSelfServiceBankClientApp::InitZCMsgHandler()
{
	//m_mapZCMsgHandler[ZC_MSG_COMMON_CURUSERINFOEX] = ZCMsgCurrentUserInfo;
	//ע���Լ�����Ȥ����Ϣ������������
	m_mapZCMsgHandler = { /*<������ ������>*/
		{ ZC_MSG_COMMON_CURUSERINFOEX, &CSelfServiceBankClientApp::ZCMsgCurrentUserInfo },//��ǰ�û�
		{ ZC_MSG_COMMON_USERALLINFO, &CSelfServiceBankClientApp::ZCMsgUserDetailInfo },//�û�����
		{ ZC_MSG_OPENDOOR_DISPOSALINFO, &CSelfServiceBankClientApp::ZCMsgDisposalInfo },//Ȩ��
		{ ZC_MSG_COMMON_ALLAREAINFO, &CSelfServiceBankClientApp::ZCMsgAreaInfo },//����
		{ ZC_MSG_COMMON_ALLDEVICEINFO, &CSelfServiceBankClientApp::ZCMsgDevHostInfo },//����
		{ ZC_MSG_SYSDORCTOR_CAMERAINFO, &CSelfServiceBankClientApp::ZCMsgDeviceInfo },//̽ͷ
		{ ZC_MSG_OPENDOOR_GETALLPEPOLEINFO, &CSelfServiceBankClientApp::ZCMsgCtrlPersonInfo },//��Ͻ��Ա
		{ ZC_MSG_COMMON_DOWNLOADPIC, &CSelfServiceBankClientApp::ZCMsgCtrlHeadPic },//��Ͻ��Աͷ�� 
		//{ ZC_MSG_OPENDOOR_DEPARTMENTINFO, &CSelfServiceBankClientApp::ZCMsgDepartmentInfo },//����
		{ ZC_MSG_OPENDOOR_ACCESSRELATION, &CSelfServiceBankClientApp::ZCMsgEntranceRelation },//�Ž����ӹ�ϵ
		{ ZC_MSG_OPENDOOR_GETALLACSHOSTINFO, &CSelfServiceBankClientApp::ZCMsgACSHostInfo },//�Ž�����
		{ ZC_MSG_OPENDOOR_CTRLLEVELMULINFO, &CSelfServiceBankClientApp::ZCMsgCtrlLevelInfo },//�ܿ�
		{ ZC_MSG_OPENDOOR_CTRLLEVELPLAN, &CSelfServiceBankClientApp::ZCMsgCtrlPlanInfo }, //�ܿز���
		//{ ZC_MSG_COMMON_ALLKEYPARTINFO, &CSelfServiceBankClientApp::ZCMsgKeypartInfo },//��λ
		{ ZC_MSG_OPENDOOR_GETACSHOSTLINKINFO, &CSelfServiceBankClientApp::ZCMsgACSHostLinkCameraInfo },//��Ȩ�Ž�������������ͷ�豸
		{ ZC_MSG_OPENDOOR_GETACSHOSTLINKTALKINFO, &CSelfServiceBankClientApp::ZCMsgACSHostLinkTalkInfo },//��֤�Ž������Խ��豸
		{ ZC_MSG_COMMON_ALLUSERINFO, &CSelfServiceBankClientApp::ZCMsgHandlerInfo },//����������
		{ ZC_MSG_OPENDOOR_USERDOORCAMERARELATION, &CSelfServiceBankClientApp::ZCMsgDoorRelationInfo },//��֤�Ž���������ͷ
		{ ZC_MSG_COMMON_PLANINFO, &CSelfServiceBankClientApp::ZCMsgEMPlanInfo },//Ԥ��
	};
}



void CSelfServiceBankClientApp::Update(bool bOK, DWORD dwType, DWORD dwMsgID, PBYTE pMsg, INT nMsgLen)
{
	if (bOK) {
		auto it = m_mapZCMsgHandler.find(dwType);
		if (m_mapZCMsgHandler.end() != it) {
			auto& pfun = it->second;
			(this->*pfun)(pMsg, dwMsgID, nMsgLen);
		}
	}
	else {
		extern std::map<DWORD, TCHAR*> g_mapZCMsgErrInfo;
		WriteLog(error, g_mapZCMsgErrInfo[dwType]);
	}
}


//��ȡ�û���Ϣ
std::shared_ptr<stUserInfo>& CSelfServiceBankClientApp::CreateOrGetUserInfo(const CString& strName)
{
	auto& spUserInfo = m_mapUserInfo[strName];
	if (nullptr == spUserInfo)
		spUserInfo = std::make_shared<stUserInfo>();
	return spUserInfo;
}

void CSelfServiceBankClientApp::ZCMsgCurrentUserInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	T_CURUSER_INFO_EX* pInfo = (T_CURUSER_INFO_EX*)(&pMsg[ZCMsgHeaderLen]);
	CString strName(pInfo->chUserName);
	m_strCurUserName = strName;
	
	//�����û�
	CreateOrGetUserInfo(strName);

	//����ǰ�û�����ϸ��Ϣ
	CZCMsgManager::Instance()->RequestMsgWithMsgID(ZC_MODULE_APP, ZC_MSG_APP_USERALLINFO,
		-1, (PBYTE)pInfo->chUserName, 64);

	//����� TY_Server_GetLastError
	if (TY_Server_InitSDK()) {//0�ɹ�
		theApp.WriteLog(error, _T("TY_Server_InitSDK ʧ�ܣ�")); return;
	}
	//ע���쳣�ص�
	if (TY_Server_SetExceptCallBack(ServerExcepCallBack, (DWORD)this)) {//0�ɹ�
		theApp.WriteLog(error, _T("TY_Server_SetExceptCallBack ʧ�ܣ�")); return;
	}
	//ע����Ϣ�ص�
	if (TY_Server_SetMsgCallBack(MsgCallBackFunc, (DWORD)this)) {
		theApp.WriteLog(error, _T("TY_Server_SetMsgCallBack ʧ�ܣ�")); return;
	}
}


//�û���ϸ��Ϣ : ������Ȩ����Ϣ֮���յ�
void CSelfServiceBankClientApp::ZCMsgUserDetailInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	S_New_UserInfo* pInfo = (S_New_UserInfo*)(&pMsg[ZCMsgHeaderLen]);
	CString strName(pInfo->chUserName);
	if (-1 == dwMsgID) {//dwMsgID = -1�ǵ�ǰ��¼�û�
		//��ȡ�������
		TJTY_TIME stTjtyTime = { 0 };
		T_CLIENT_USERINFO stCMSUseInfo = { 0 };
		memcpy(stCMSUseInfo.chUserName, pInfo->chUserName, _countof(stCMSUseInfo.chUserName));
		memcpy(stCMSUseInfo.chUserPwd, "ty123456", _countof(stCMSUseInfo.chUserPwd));
		//memcpy(stCMSUseInfo.chUserPwd, pInfo->chPassword, _countof(stCMSUseInfo.chUserPwd));
		stCMSUseInfo.nClientType = TJTY_SOFT_EMAP;//��ͨ�û�
		m_oGobal->nCMSHander = TY_Server_LogInCMS("192.168.2.65", 4000, &stCMSUseInfo, &stTjtyTime);
		if (-1 == m_oGobal->nCMSHander) {
			theApp.WriteLog(error, _T("��ȡ���Ĳ������ʧ�ܣ����޷�Ԥ����Ƶ���û�����%s"), pInfo->chUserName);
		}
	}
	//��α��� pInfo��Чʱ��m_mapUserInfo�ڴ����⣿
	auto& spUserInfo = CreateOrGetUserInfo(strName);

	spUserInfo->stBaseInfo = std::move(*pInfo);
}

//��ǰ�û�Ȩ����Ϣ �� ZCMsgManger.exe�����˵�¼��
void CSelfServiceBankClientApp::ZCMsgDisposalInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	T_OPENDOORPOSALINFO* pInfo = (T_OPENDOORPOSALINFO*)(&pMsg[ZCMsgHeaderLen]);
	auto& spUserInfo = CreateOrGetUserInfo(m_strCurUserName);
	spUserInfo->stDisposalInfo = std::move(*pInfo);
}

//������Ϣ
void CSelfServiceBankClientApp::ZCMsgAreaInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	auto& vecArea = m_mapNodeInfo[AreaNode];

	ZCMsgMacro_beginfor(T_AREA_INFO, pMsg, nMsgLen)
	T_AREA_INFO* pInfo = (T_AREA_INFO*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	
	auto sp = make_shared<stArea>(pInfo->nAreaId, pInfo->chCode, pInfo->chFatherNo, pInfo->chName);
	vecArea.push_back(std::move(sp));

	pInfo = 0;
	
	ZCMsgMacro_endfor
	
}


//������Ϣ
void CSelfServiceBankClientApp::ZCMsgDevHostInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	auto& vecHost = m_mapNodeInfo[HostNode];

	ZCMsgMacro_beginfor(S_DevNodeInfo, pMsg, nMsgLen)
	S_DevNodeInfo* pInfo = (S_DevNodeInfo*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	
	auto sp = make_shared<stHost>(pInfo->nID, pInfo->chDevCode, pInfo->chAreaCode, pInfo->chDevName, pInfo->nDevManufatureID);
	vecHost.push_back(std::move(sp));

	pInfo = 0;

	ZCMsgMacro_endfor

}

//ǰ���豸��Ϣ
void CSelfServiceBankClientApp::ZCMsgDeviceInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	auto& vecDevice = m_mapNodeInfo[DeviceNode];

	ZCMsgMacro_beginfor(CAMERA_NODE_INFO, pMsg, nMsgLen)

	CAMERA_NODE_INFO* pInfo = (CAMERA_NODE_INFO*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	auto sp = make_shared<stDevice>(pInfo->nId, pInfo->chCode, pInfo->chAreaCode, pInfo->chName, pInfo->nChannelNo, pInfo->chHostCode);
	vecDevice.push_back(std::move(sp));

	pInfo = 0;
	ZCMsgMacro_endfor
	
}


//��Ͻ��Ա��Ϣ
void CSelfServiceBankClientApp::ZCMsgCtrlPersonInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(TAGDOAPERSONINFO_S, pMsg, nMsgLen)
	
	TAGDOAPERSONINFO_S* pInfo = (TAGDOAPERSONINFO_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);

	auto sp = std::make_shared<stCtrlPersonInfo>();
	sp->stBaseInfo = std::move(*pInfo);
	m_vecCtrlPersonInfo.push_back(sp);
	//��ȡ��Ƭ��Ϣ
	PBYTE pImage =
		(TRUE == IsBadReadPtr(pInfo->chHeadImage, sizeof(int))) ? (PBYTE)"" : (PBYTE)pInfo->chHeadImage;

	CZCMsgManager::Instance()->RequestMsgWithMsgID(ZC_MODULE_BCBCLIENT, ZC_MSG_BCBCLIENT_DOWNLOADPIC, i, pImage, 512);
	
	pInfo = 0;
	
	ZCMsgMacro_endfor
}

//��Ͻ��Աͷ��һ��һ��
void CSelfServiceBankClientApp::ZCMsgCtrlHeadPic(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	assert(dwMsgID < 0 || dwMsgID > m_vecCtrlPersonInfo.size());

	auto& sp = m_vecCtrlPersonInfo[dwMsgID];
	PBYTE pImgPath = &pMsg[ZCMsgHeaderLen];
	memcpy(sp->szHeadPic, pImgPath, MAX_PATH);
}

//������Ϣ
void CSelfServiceBankClientApp::ZCMsgDepartmentInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(TAGDOADEPARTMENTINFO_S, pMsg, nMsgLen)
		TAGDOADEPARTMENTINFO_S* pInfo = (TAGDOADEPARTMENTINFO_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		pInfo = 0;
	ZCMsgMacro_endfor
}


//�Ž����ӹ�ϵ
void CSelfServiceBankClientApp::ZCMsgEntranceRelation(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(TAGDOACCESSRELATION_S, pMsg, nMsgLen)
	
	TAGDOACCESSRELATION_S* pInfo = (TAGDOACCESSRELATION_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	//���Ž������ô��Ž��������Ž��෴
	CString strM(pInfo->chMasterName);
	auto& spM = m_mapACSHostInfo[strM];
	if (0 == spM) {
		spM = make_shared<stACSHostInfo>();
	}
	spM->nSlave = FALSE;
	memcpy(spM->unMS.szSlaveName, pInfo->chSlaveName, _countof(spM->unMS.szSlaveName));

	CString strS(pInfo->chSlaveName);
	auto& spS = m_mapACSHostInfo[strS];
	if (0 == spS) {
		spS = make_shared<stACSHostInfo>();
	}
	spS->nSlave = TRUE;
	memcpy(spS->unMS.szMasterName, pInfo->chMasterName, _countof(spS->unMS.szMasterName));

	pInfo = 0;
	ZCMsgMacro_endfor
}

//�����Ž�������Ϣ access control system
void CSelfServiceBankClientApp::ZCMsgACSHostInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(TAGDOAACCESSINFO_S, pMsg, nMsgLen)

	TAGDOAACCESSINFO_S* pInfo = (TAGDOAACCESSINFO_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	CString strName(pInfo->chDevName);
	auto& sp = m_mapACSHostInfo[strName];
	if (0 == sp) {
		sp = make_shared<stACSHostInfo>();
	}
	sp->stBaseInfo = std::move(*pInfo);

	pInfo = 0;

	ZCMsgMacro_endfor
}

//�ܿصȼ���Ϣ������豸���豸���ڵĳ����Ͳ�λ�����Ĺܿصȼ�����
bool lambda_GetCtrlLevel(const std::tuple<CString, UINT8>& tpl, const CString& strLevel) {
	return std::get<0>(tpl) == strLevel;
}
void CSelfServiceBankClientApp::ZCMsgCtrlLevelInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(S_NEW_CTRLLEVELINFO, pMsg, nMsgLen)
	
	S_NEW_CTRLLEVELINFO* pInfo = (S_NEW_CTRLLEVELINFO*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	//auto it = std::find_if(m_mapACSHostInfo.begin(), m_mapACSHostInfo.end(),
	//	std::bind(lambda_FindACSHostByName, _1, pInfo->chDeviceName));
	CString strName(pInfo->chDeviceName);
	auto itHostInfo = m_mapACSHostInfo.find(strName);
	//shared_ptr<stACSHostInfo> sp = 0;
	if (m_mapACSHostInfo.end() == itHostInfo) {
		m_mapACSHostInfo[strName] = make_shared<stACSHostInfo>();
	}
	auto& sp = m_mapACSHostInfo[strName];
	
	//��ֵ�ܿصȼ����ܿس������ơ���λ����
	static std::vector<std::tuple<CString, UINT8>> vecLevel = {
		{_T("һ��"),1},{ _T("����"),2 },{ _T("����"),3 },{ _T("�ļ�"),4 }
	};
	CString strLevel(pInfo->chLevelName);
	auto itLevel = std::find_if(vecLevel.begin(), vecLevel.end(),
		std::bind(lambda_GetCtrlLevel, _1, strLevel));
	sp->nCtrlLevel = (vecLevel.end() == itLevel) ? 0 : std::get<1>(*itLevel);
	//����
	//mbstowcs_s(0, sp->szPlaceName, pInfo->chPlaceName, _countof(sp->szPlaceName));
	memcpy(sp->szPlaceName, pInfo->chPlaceName, _countof(sp->szPlaceName));
	//��λ
	//mbstowcs_s(0, sp->szPartName, pInfo->chKeyPartName, _countof(sp->szPartName));
	memcpy(sp->szPartName, pInfo->chKeyPartName, _countof(sp->szPartName));
	
	pInfo = 0;

	ZCMsgMacro_endfor
}

//�ܿز�����Ϣ��ֻ�����ù��Ż᷵��
void CSelfServiceBankClientApp::ZCMsgCtrlPlanInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	/*һ����Ϣ����Ӧһ��������������Ƕ���
	<����levelID[1-4]-> ��Ӧ���ܿصȼ���
	 ������planID[1-n]-> ��Ӧ���������á���1�ǻ�������
	 ��������methodID[1-n]-> ��Ӧ���������顱
	 ֵ-> nSetItem1-3 ��˳�� >
	 methodID��
	 1  //��֤ʱЧ
	 2  //��֤��ʽ    1-Զ�̡�  2-����
	 3  //��֤ʶ��һ  1-ָ�ơ�  2-ˢ��
	 4  //��֤ʶ���  1-ָ�ơ�  2-ˢ��
	 5  //¼��        1-��ͨ����2-ȫͨ��
	 6  //ץͼ        1-��ͨ����2-ȫͨ��
	 7  //Ԥ������    1-Ԥ��ID
	 8  //����ִ��    1-��      2-��
	 9  //������Ȩ    1-ˢ��    2-����
	 10 //�ϼ���Ȩ    1-ˢ��    2-����
	 11 //�Ű�˶�    1-��      2-��
	 12 //��������    1-��      2-��
	 13 //�׿���Ȩ    1-��      2-��
	 */
	ZCMsgMacro_beginfor(TAGCTRLEVELPLAN_S, pMsg, nMsgLen)

	TAGCTRLEVELPLAN_S* pInfo = (TAGCTRLEVELPLAN_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	UINT8 nItem1 = static_cast<UINT8>(pInfo->nSetItem1);
	UINT8 nItem2 = static_cast<UINT8>(pInfo->nSetItem2);
	UINT8 nItem3 = static_cast<UINT8>(pInfo->nSetItem3);

	auto& sp = m_mapCtrlPlan[pInfo->nLevelId];
	if (nullptr == sp) {
		sp = make_shared<stCtrlPlanInfo>();
	}
	switch (pInfo->nMethodId)
	{
	case 1:
		sp->nAuthTimeLimit = nItem1; break;
	case 2:
		sp->nAuthType = nItem1; break;
	case 3:
		sp->nDoor1Type = nItem1;
		sp->nDoor1Num = nItem2; break;
	case 4:
		sp->nDoor2Type = nItem1;
		sp->nDoor2Num = nItem2; break;
	case 5:
		sp->nRecType = nItem1;
		sp->nPreRecTime = nItem2;
		sp->nRecTime = nItem3; break;
	case 6:
		sp->nCapType = nItem1;
		sp->nCapDur = nItem2;
		sp->nCapTime = nItem3; break;
	case 7:
		sp->nEMPlanID = nItem1;
		memcpy(sp->szEMPlanName, pInfo->chSetItem4, _countof(sp->szEMPlanName)); break;
		//mbstowcs_s(0, sp->szEMPlanName, pInfo->chSetItem4, _countof(sp->szEMPlanName)); break;
	case 8:
		sp->bEMPlanStep = nItem1; break;
	case 9:
		sp->nOpenGrantType = nItem1; break;
	case 10:
		sp->nSuperGrantType = nItem1; break;
	case 12:
		sp->bApproval = nItem1; break;
	case 13:
		sp->bFCGrant = nItem1; break;
	default: break;
	}

	pInfo = 0;

		//}
	ZCMsgMacro_endfor
}

//��λ��Ϣ
void CSelfServiceBankClientApp::ZCMsgKeypartInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(S_NEW_SHOWPOSITIONINFO, pMsg, nMsgLen)
		S_NEW_SHOWPOSITIONINFO* pInfo = (S_NEW_SHOWPOSITIONINFO*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
		pInfo = 0;
	ZCMsgMacro_endfor
}

//��֤�Ž�����ͷ������Ϣ
bool lambda_FindACSHostByID(const std::pair<CString, shared_ptr<stACSHostInfo>>& p, const int id) {
	return p.second->stBaseInfo.nID == id;
}
void CSelfServiceBankClientApp::ZCMsgDoorRelationInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(USERDOORCAMERARELATION_CLIENT_GET_S, pMsg, nMsgLen)
	USERDOORCAMERARELATION_CLIENT_GET_S* pInfo = (USERDOORCAMERARELATION_CLIENT_GET_S*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	auto itACSHost = std::find_if(m_mapACSHostInfo.begin(), m_mapACSHostInfo.end(),
		std::bind(lambda_FindACSHostByID, _1, pInfo->nDoorId));
	if (m_mapACSHostInfo.end() == itACSHost) {
		return;
	}

	auto& st = itACSHost->second;
	st->vecGrantRelCameraID.resize(/*pInfo->nLinkNum*/1);
	for (int i = 0; i < /*pInfo->nLinkNum*/1; ++i) {
		st->vecGrantRelCameraID[i] = /*pInfo->nCameraID[i]*/pInfo->nDeviceId;
	}

	//ֻ���յ�ǰ�û���
	CString strName(pInfo->chUserName);
	if (strName != m_strCurUserName)
		return;
	auto& sp = m_mapUserInfo[m_strCurUserName]->pVecACSHostID;
	if (0 == sp) {
		sp = make_shared<std::vector<int>>();
	}
	sp->push_back(pInfo->nDoorId);

	pInfo = 0;
	ZCMsgMacro_endfor

}

//��Ȩ�Ž�������������ͷ�豸
void CSelfServiceBankClientApp::ZCMsgACSHostLinkCameraInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{

	ZCMsgMacro_beginfor(S_HostTalkInfo, pMsg, nMsgLen)
	S_HostTalkInfo* pInfo = (S_HostTalkInfo*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	//map[CString,..]����pInfoֻ��int������Ϣ����˳�򲻶�������ͬ������α�֤������
	//����дWaitForSingleObject���ݼٶ��ѻ�ȡ�ꡰ�Ž���Ϣ��
	auto itACSHost = std::find_if(m_mapACSHostInfo.begin(), m_mapACSHostInfo.end(),
		std::bind(lambda_FindACSHostByID, _1, pInfo->nDeviceID));
	if (m_mapACSHostInfo.end() == itACSHost) {
		return;
	}

	auto& st = itACSHost->second;
	st->vecGrantRelCameraID.resize(pInfo->nLinkNum);
	for (int i = 0; i < pInfo->nLinkNum; ++i) {
		st->vecGrantRelCameraID[i] = pInfo->nCameraID[i];
	}

	pInfo = 0;
	ZCMsgMacro_endfor
}

//��֤�Ž����������Խ��豸
void CSelfServiceBankClientApp::ZCMsgACSHostLinkTalkInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(S_HostTalkInfo, pMsg, nMsgLen)
	S_HostTalkInfo* pInfo = (S_HostTalkInfo*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	
	auto itACSHost = std::find_if(m_mapACSHostInfo.begin(), m_mapACSHostInfo.end(),
		std::bind(lambda_FindACSHostByID, _1, pInfo->nDeviceID));
	if (m_mapACSHostInfo.end() == itACSHost) {
		return;
	}

	auto& st = itACSHost->second;
	st->vecAuthRelTalkID.resize(pInfo->nLinkNum);
	for (int i = 0; i < pInfo->nLinkNum; ++i) {
		st->vecAuthRelTalkID[i] = pInfo->nCameraID[i];
	}

	pInfo = 0;
	ZCMsgMacro_endfor
}



//���д�������Ϣ
void CSelfServiceBankClientApp::ZCMsgHandlerInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	//����������������ϸ��Ϣ
	int iCount = (nMsgLen - ZCMsgHeaderLen) / 64;
	for (int i = 0; i < iCount; ++i) {
		char* pInfo = (char*)(&pMsg[ZCMsgHeaderLen + i * 64]);
		
		//�����û�����ϸ��Ϣ
		CZCMsgManager::Instance()->RequestMsgWithMsgID(ZC_MODULE_APP, ZC_MSG_APP_USERALLINFO,
			i, (PBYTE)pInfo, 64);
	}

}


//����Ԥ����Ϣ
bool lambda_FindEMPlanByID(const shared_ptr<stEmergPlan>& st, const int id) {
	return st->nPlanID == id;
}
void CSelfServiceBankClientApp::ZCMsgEMPlanInfo(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	ZCMsgMacro_beginfor(S_NEW_SHOWPLANLIB, pMsg, nMsgLen)
	
	S_NEW_SHOWPLANLIB* pInfo = (S_NEW_SHOWPLANLIB*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);
	auto itPlan = std::find_if(m_vecEMPlanInfo.begin(), m_vecEMPlanInfo.end(),
		std::bind(lambda_FindEMPlanByID, _1, pInfo->nPlanID));
	if (m_vecEMPlanInfo.end() == itPlan) {
		auto sp = make_shared<stEmergPlan>();
		sp->nPlanID = pInfo->nPlanID;
		sp->strPlanName = CString(pInfo->chPlanName);
		sp->strCreateMan = CString(pInfo->chMan);
		sp->vecStep.push_back(stEmergPlanStep(pInfo->nAI_Id, pInfo->bMustDo, CString(pInfo->chActionName)));

		m_vecEMPlanInfo.push_back(std::move(sp));
	}
	else {
		auto& sp = *itPlan;
		sp->vecStep.push_back(stEmergPlanStep(pInfo->nAI_Id, pInfo->bMustDo, CString(pInfo->chActionName)));
	}

	ZCMsgMacro_endfor
}


//д��־
void _cdecl CSelfServiceBankClientApp::WriteLog(severity_level level, const TCHAR* szMsg, ...)
{
	if (0 == szMsg)
		return; //_vsntprintf_s���

	TCHAR szBuffer[1024] = { 0 };
	va_list pArgList; //char*
	va_start(pArgList, szMsg); //��ָ�������һ���̶����������a

	//ר��д��szBuffer�ĺ���
	_vsntprintf_s(szBuffer, _countof(szBuffer), szMsg, pArgList);
	
	BOOST_LOG_SEV(g_slog, level) << szBuffer/*L"���"*//*"abc"*/;

	va_end(pArgList); //����
}


/*****  ȫ����  */
CGobalVariable::CGobalVariable()
{
	//GDI+��ʼ��
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//m_hEventReadStgCfg = CreateEvent(nullptr, TRUE, FALSE, nullptr);//�ֶ�δ����

	//��������Ŀ¼
	strExePath = MyGetExePath();

	/*UI*/
	//FontFamily cstFontFamily(_T("΢���ź�"));
	//Gdiplus::Font fontDefault(&cstFontFamily, 12, FontStyleRegular, UnitPixel);
	////cstFont = std::make_shared<Gdiplus::Font>(fontDefault.Clone()); //����private
	//cstFont = fontDefault.Clone();

	//SolidBrush sbr(Color(125, 125, 125));
	//cstSolidBrushText = sbr.Clone();
}

CGobalVariable::~CGobalVariable()
{
	//GDI+�ͷ���Դ
	GdiplusShutdown(gdiplusToken);

}


bool CGobalVariable::Init()
{
	bool bRet = true;

	//�����ļ�·��
	//m_strStgCfgPath = m_strExePath + _T("stgcfg");

	//��ȡ����
	//vecCfg.resize(StgCfgEnum_Buff);
	//vecCfg[StgCfgEnum_LoginUser] = new StgCfgLoginUser;

	//unsigned int nThreadID(0);
	//HANDLE hThread = (HANDLE)_beginthreadex(nullptr, 0, ReadStgCfgThread, nullptr, 0, &nThreadID);
	//CloseHandle(hThread); hThread = nullptr;

	return bRet;
}



void CUICfg::SetUICfg(std::string s)
{
	boost::sregex_iterator it(s.begin(), s.end(), m_uiregex), itend;
	for (; it != itend; ++it) {
		OnMatchUICfg(*it);
	}
}


bool lambda_FindUICfg(const std::string& s1, const std::string& s2) {
	return s1 == s2;
}
bool CUICfg::HasUICfg(const std::string& str)
{
	auto it = std::find_if(m_vecUICfg.begin(), m_vecUICfg.end(),
		std::bind(lambda_FindUICfg, _1, str));
	return m_vecUICfg.end() != it;
}



//ServerSDK�쳣�ص�����
void __stdcall CSelfServiceBankClientApp::ServerExcepCallBack(U_LONG_TY dwExceptMsg, LONG_TY lHandle, U_LONG_TY dwUser)
{
	if (USER_EXCHANGE_ERR == dwExceptMsg)
	{
		//�������⣬����ߣ���ʱδ����������������ԣ�
		theApp.WriteLog(error, _T("ServerSDK�쳣�ص����û������쳣��"));
	}
	else if (REALPLAY_ERR == dwExceptMsg)
	{
		theApp.WriteLog(error, _T("ServerSDK�쳣�ص���Ԥ���쳣��"));
	}
}

//ServerSDK��Ϣ�ص�����
void __stdcall CSelfServiceBankClientApp::MsgCallBackFunc(long lUserID, DWORD MsgType, BYTE *chMsgBuf, DWORD dwBufSize, unsigned int nMsgID, DWORD dwUser)
{
	if (MsgType == USER_LOGIN_CMS || MsgType == USER_LOGOUT_CMS){
		theApp.WriteLog(trace, _T("ServerSDK��Ϣ�ص����û���¼���ǳ�..."));
	}
	else if(MsgType == MSG_TRANS_BY_CMS){
		theApp.WriteLog(trace, _T("ServerSDK��Ϣ�ص�������ת����Ϣ..."));
	}
}