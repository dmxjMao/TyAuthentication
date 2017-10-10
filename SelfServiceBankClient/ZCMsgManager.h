#pragma once
#ifndef ZCMsgManagerH
#define ZCMsgManagerH
#include "TjtyTcpClientModule.h"
#include "ConnectAppProtocol.h"
#include "ZCProtocol.h"
//#include "DeBugLog.h"
//
//#define MESSAGENUM                70  //��Ϣ���� 
//#define EROCURRENTUSER            0   //��ǰ�û���Ϣ
//#define EROAREA                   1   //������Ϣ
//#define EROCERTIFICATION          2   //��֤��ѯ
//#define EROSTAFFSEARCH            3   //��Ա��ѯ��ˢ����Ϣ��
//#define EROSTATISTIC              4   //ͳ����Ϣ
//#define EROACSHOSTINFO            5   //�Ž�������Ϣ
//#define EROINTOALARMLAYER         6   //����ͼ��
//#define EROWATCHVIDEO             7   //�ۿ���Ƶ
//#define EROREPLAYVIDEO            8   //�ط���Ƶ
//#define ERODIALLING               9   //��绰
//#define EROIPTALK                 10  //�Խ�
//#define EROOPENDOOR               11  //����
//#define EROMANULCAPTUREINFO       12  //����ץͼ��Ϣ����
//#define EROCLOSEMANULCAPTUREINFO  13  //�ر���Ϣ����
//#define EROLINKSWIPCARDRECORD     14  //����ˢ����֤��¼
//#define EROADDSUGGESTION          15  //������֤�������
//#define EROADDLOGINFO             16  //����ϵͳ��־
//#define EROADDOPERAINFO           17  //������֤���ò�����Ϣ
//#define EROGETOPERAINFO           18  //��ȡ��֤������ϸ��Ϣ 
//#define EROGETAPPLYPLAN           19  //��ȡԤ��ִ����Ϣ
//#define EROGETSUGGESTIONINFO      20  //��ȡ��֤���������Ϣ
//#define EROGETLOGINFO             21  //��ȡ��֤ϵͳ��־
//#define EROGETACCESSLOGINFO       22  //��ȡ��֤����ˢ����Ϣ
//#define EROSUBMITAUDITORDEALINFO  24  //�ύ�������
//#define EROADDDEALPLANINFO        25  //�ύԤ��ִ������
//#define EROMODIFYDEALTYPE         26  //�޸���֤���÷�ʽ
//#define EROSUBMITDEALINFO         27  //������֤�����¼
//#define EROGETUSERBASEINFO        28  //�����ȡ�û���Ϣ
//#define EROMODIFYREQUESTSTATE     29  //�����޸���֤����״̬
//#define EROGETALLPEPOLEINFO       30  //�����ȡ�������Ͻ��Ա��Ϣ
//#define EROTRANSMSG               31  //����ͻ���ת����Ϣ
//#define EROCOLLECTCHART           32  //�ղص�ͼ����Ϣ
//#define EROCHANGECOLLECTCHART     33  //��ɾ���ղص�ͼ����Ϣ
//#define EROSUBSCRIBE              34  //�����ȡ�û�������Ϣ
//#define EROCHANGESUBSCRIBE        35  //��������ɾ���Ķ�����Ϣ
//#define EROREPORT                 36  //�����ȡ������Ϣ
//#define EROCHANGEREPORTSTATUS     37  //�޸ı���״̬��Ϣ
//#define EROACCESSRELATION         38  //�����ȡ�Ž����ӹ�ϵ��Ϣ
//#define EROCTRLLEVELMULINFO       39  //�����ȡ�ܿصȼ���Ϣ
//#define EROCTRLLEVELPLAN          40  //�����ȡ�ܿز�����Ϣ
//#define ERODEPARTMENT             41  //������Ϣ
//#define EROGETPLANINFO            42  //��ȡԤ����Ϣ 
//#define EROGETALLPARTINFO         43  //��ȡ���в�λ��Ϣ
//#define EROPHOTO                  44  //��ȡ��Ƭ
//#define EROUPLOADATTACTMENT       45  //�ϴ�����
//#define ERODOWNLOADATTACTMENT     46  //���ظ���
//#define EROCAPTURE				  47  //ץͼ
//#define EROBASICSETTING           48  //��������
//#define EROAPPLYDETAILINFO		  50  //����������ϸ��Ϣ
//#define EROISCOLLECTIONS          51  //�����޸��ղ�״̬
//#define EROPRECAPTURE             52  //Ԥץͼ
//#define EROGETACSHOSTLINKINFO     53  //��ȡ����������������ͷ
//#define EROSENDSHORTMSG			  54  //���Ͷ���
//#define EROSENDEMAIL			  55  //�����ʼ�
//#define EROIFSETDEFENSE			  56  //������
//#define EROCONTRODEVICE			  57  //��������
//#define EROEXCEPTINPUT            58  //�쳣¼��
//#define EROHOSTTALKINFO			  59  //��ȡ�Խ�������Ϣ
//#define EROALLUSER	     		  60  //�����û�
//#define EROCLOSEVIDEO             61  //����ر���Ƶ
//#define EROESCORTACCESSRELATION   62  //�����ȡ�Ž�����Ѻ���豸
//#define EROLINKESCORTCARDRECORD   63  //����Ѻ����֤��¼
//#define EROGETESCORTINFOFROMWEB   64  //��ȡweb��Ѻ����Ϣ
//
//#define ZC_MSG_SERIAL_ID_MAX_VALUE				10000	// ��Ϣ���к����ֵ
//#define USER_MSG_SERIAL_ID_DELETE_DEPARTMENT	10001	// ɾ��������Ϣ���к�


class CZCMsgManager
{
public:
	static CZCMsgManager* m_pZcInst;
	CZCMsgManager(void);

private:
	bool m_bInit;
	HANDLE m_hEvent;

public:
	bool Init(DWORD dwUser);
	bool UnInit();
	void SetInitState(bool bInit);
	bool AddSendMsg(WORD wModlueType,DWORD dwMsgId,DWORD dwMsgType,BYTE* pBuf,DWORD nBufSize);
	void SetLastError(DWORD nError);
	DWORD GetValidMsgID();

public:
	~CZCMsgManager(void);

	static CZCMsgManager* Instance(){ return ( m_pZcInst == NULL ? m_pZcInst=new CZCMsgManager() : m_pZcInst);}

	static void FreeInstance()
	{
		if(m_pZcInst)
		{
			delete m_pZcInst;
			m_pZcInst = NULL;
		}
	}

//public:
//	DWORD m_dwMsgID;
//	DWORD m_LastError;
//	bool m_bError[MESSAGENUM];
//	int m_iErrorCode[MESSAGENUM];
//	DWORD m_dGroup;  
//	char m_cImage[512];
//	bool m_bIsAbnormalId;  //�궨�Ƿ�Ϊ�쳣¼��������֤ID
//	bool m_bIsAttachment;  //��־����ΪOpenDoolApplyDlg����
//	int m_iShow;    //�����Ƿ���ʾ
//	CDebugLogService* m_cDebugLog;
//	std::map<int,char*> m_vPersonPhoto;

public:
	//������
//	bool RequestCurrentUserInfo();   //����ǰ�û���Ϣ
//	T_CURUSER_INFO_EX m_CurrentUserInfo;
//	bool RequestOpenDoorDisposalInfo();		// �������������Ȩ��
//	T_OPENDOORPOSALINFO m_tOpenDoorDisposalInfo;
//	void AddCurrentUserInfo(T_CURUSER_INFO_EX *info);
//	bool RequestAreaInfo();   //����������Ϣ
//	std::vector<T_AREA_INFO> m_AreaInfo;
//	void AddAreaInfo(T_AREA_INFO &info, bool bClear);
//	bool RequestCertificationSearchInfo(TAGDOAHISTORYINFO_P info);   //������֤��ѯ
//	std::vector<TAGDOAHISTORYINFO_S> m_CertificationSearchInfo;
//	void AddCertificationSearchInfo(TAGDOAHISTORYINFO_S &info, bool bClear);
//	bool RequestStaffSearchInfo(TAGDOABYCARDINFO_P info);   //������Ա��ѯ��ˢ����Ϣ��
//	std::vector<TAGDOABYCARDINFO_NEW_S> m_StaffSearchInfo;
//	void AddStaffSearchInfo(TAGDOABYCARDINFO_NEW_S &info, bool bClear);
//	bool RequestStatisticInfo(TAGDOASTATISTICS_P info);   //����ͳ����Ϣ
//	bool RequestStatisticInfo(TAGDOASTATISTICS_P info,DWORD dwMsgID);   //����ͳ����Ϣ
//	std::vector<TAGDOASTATISTICS_S> m_StatisticInfo;
//	void AddStatisticInfo(TAGDOASTATISTICS_S &info, bool bClear);
//	bool RequestCollectChartInfo(P_NEW_SHOWUSERGRAPHINFO info);   //�����ȡ�ղص�ͼ����Ϣ
//	std::vector<S_NEW_SHOWUSERGRAPHINFO> m_CollectChartInfo;
//	void AddCollectChartInfo(S_NEW_SHOWUSERGRAPHINFO &info, bool bClear);
//	bool RequestChangeCollectChartInfo(P_NEW_OPUSERGRAPHINFO info);   //��ɾ���ղص�ͼ����Ϣ
//	bool RequestSubscribeInfo(P_NEW_SHOWUSERREPORTBOOKINFO info);   //�����ȡ�û�������Ϣ
//	std::vector<S_NEW_SHOWUSERREPORTBOOKINFO> m_SubscribeInfo;
//	void AddSubscribeInfo(S_NEW_SHOWUSERREPORTBOOKINFO &info, bool bClear);
//	bool RequestChangeSubscribeInfo(P_NEW_OPUSERREPORTINFO info);   //��������ɾ���Ķ�����Ϣ
//	bool RequestReportInfo(P_NEW_SHOWUSERREPORTINFO info);   //�����ȡ������Ϣ
//	std::vector<S_NEW_SHOWUSERREPORTINFO> m_ReportInfo;
//	void AddReportInfo(S_NEW_SHOWUSERREPORTINFO &info, bool bClear);
//	bool RequestChangeReportStatusInfo(P_NEW_MODSTATUSUSERREPORT info);   //�޸ı���״̬��Ϣ
//	bool RequestDepartmentInfo();   //��ȡ������Ϣ
//	std::vector<TAGDOADEPARTMENTINFO_S> m_DepartmentInfo;
//	void AddDepartmentInfo(TAGDOADEPARTMENTINFO_S &info, bool bClear);
//	bool RequrstDownLoadPic(char* chImage,DWORD m_dwMsgID);                 //�����û�ͼƬ
//	bool RequestDownAttachment(char* chImage,DWORD m_dwMsgID);
//	bool SetBasicSettingInfo(TAGDOA_USERINFO_P info);   //���û�����Ϣ
//
//	
//	std::vector<TAGDOAACCESSINFO_S> m_vAllACSHostInfo;
//	void AddACSHostInfo(TAGDOAACCESSINFO_S &st_info, bool bClear);
//	bool RequestACSHostInfo();   //���������Ž�������Ϣ
//
//	bool RequestIntoLayer(char* chAreaName);     //�������ͼ�� 1
//
//	bool RequestWatchVideo(T_ALARMLINKOPERATEPRARM info, DWORD dwMsgID);   //���������Ƶ 2
//	bool RequestCloseVideo();   //���������Ƶ 2
//
//	bool RequestReplayVideo(T_ALARMREPLAYPARAM info, DWORD dwMsgID);  //����ط�¼�� 3 
//
//	bool RequestDialling(T_TELEPHONECALLINFO info, DWORD dwMsgID);     //�����绰 4 
//
//	T_ATTACHMENTINFO m_stAttachmentInfo;
//	void AddAttachmentInfo(T_ATTACHMENTINFO *info);
//	bool RequestIPTalk(int nDeviceID, DWORD dwMsgID);       //����Խ� 5
//
//	bool RequestOpenDoor(T_CONTROLACSHOSTPRARM info, DWORD dwMsgID);     //������/���� 6
//
//	bool RequestManulCaptureInfo();  //���������ֶ�ץͼ��Ϣ
//
//	bool RequestCloseManulCaptureInfo();  //����ر��ƶ��ֶ�ץͼ��Ϣ
//
//	bool RequestLinkSwipCardRecord(TAGOPENDOOR_P info);  //�������ˢ����֤��¼
//
//	bool RequestLinkEscortCardRecord(DOOROPENSYRELATION_SET_P info);//�������Ѻ����֤��¼
//
//	bool RequestEscortPlanInfo(int nOrgId);  //�����ȡָ�������Ѻ���Ű���Ϣ(��Ѻ)
//
//	bool RequestEscortPhotoInfo(struct TSyGetImage info);  //�����ȡ�������͵�ͼƬ(��Ѻ)
//
//	bool RequestEscortRouteInfo(int nOrgId);  //�����ȡָ������Ѻ��·�ߵ�״̬(��Ѻ)
//
//	bool RequestEscortRFIDInfo(struct TSyGetTagData info);  //������ӱ�ǩ������ϸ��Ϣ(��Ѻ)
//	
//	bool RequestAddSuggestion(TAGDOA_PROCESSMEMO_P info);  //����������֤�������
//
//	bool RequestAddLogInfo(TAGDOA_APPLYACTLOG_P info);    //��������ϵͳ��־
//
//	bool RequestAddOperaInfo(TAGDOA_ATTACHMENT_P info);   //�����������ò���
//
//	std::vector<TAGDOAATTACHMENT_S> m_vOperaInfo;
//	void AddOperationInfo(TAGDOAATTACHMENT_S &info, bool bClear);  //��ȡ��֤������ϸ��Ϣ
//	bool RequestOperationInfo(int nId);
//
//	std::vector<TAGDOAACTIONDETAIL_S> m_vActionDetail;  //��ȡԤ��ִ����Ϣ
//	void AddActionDetail(TAGDOAACTIONDETAIL_S &info, bool bClear);
//	bool RequestActionDetail(int nId);
//
//	std::vector<TAGDOAPROCESSMEMO_S> m_vSuggestionInfo;  //��ȡ��֤���������Ϣ
//	void AddSuggestionInfo(TAGDOAPROCESSMEMO_S &info, bool bClear);
//	bool RequestSuggestionInfo(int nId);
//
//	std::vector<TAGDOAACTLOG_S>  m_vSystemLog;  //��ȡ��֤ϵͳ��־��Ϣ
//	void AddSystemLog(TAGDOAACTLOG_S &info, bool bClear);
//	bool RequestSystemLog(int nId);
//
//	std::vector<TAGDOADOORACCESSLOG_S> m_vDoorAccessLog;  //��ȡ��֤ˢ����Ϣ
//	void AddDoorAccessLog(TAGDOADOORACCESSLOG_S &info, bool bClear);
//	bool RequestDoorAccessLog(int nId);
//
//	bool RequestSubmitAuditorDealInfo(TAGDOA_AUDITOR_P info);  //�ύ�������
//
//	bool RequestAddDealPlanInfo(TAGOPENDOORPLANINFO_P info);  //�ύԤ��ִ������
//
//	bool RequestModifyDealType(TAGDOOROPENAPPLY_METHOD_P info);  //�޸���֤���÷�ʽ��ֵ-1-δ���� 0-����-������Ȩ2-Ӧ������ 3-��������4-�ܾ�����
//
//    TAGDOA_INFO_S m_tNewOpenDoorApply;
//	void AddNewOpenDoorApply(TAGDOA_INFO_S* info);
//	bool RequestSubmitDealInfo(TAGDOA_INFO_P info, DWORD dwMsgID);  //������֤�����¼
//
//	TAGDOAPPASSWORD_S m_stPassWord;  //�����ȡ�û���Ϣ
//	void AddUserPassWord(TAGDOAPPASSWORD_S *info);
//	bool RequestUserPassWord(TAGDOAPPASSWORD_P info);
//
//	bool RequestModifyRequestState(TAGDOA_PROCESSSTATUS_P info);  //�����޸���֤����״̬ ��֤״ֵ̬ 1-δ����2-������ 3-�����4-�Ѵ���5-��ʧЧ
//
//	std::vector<TAGDOAPERSONINFO_S> m_vAllPersonInfo;  //�����ȡ�������Ͻ��Ա��Ϣ
//	void AddAllPersonInfo(TAGDOAPERSONINFO_S &info, bool bClear);
//	bool RequestAllPersonInfo();
//
//	char m_chManualCapturePath[512];   //��������ץͼ��ַ
//
//	void AddManualCapture(char* chPath); 
//	bool RequestTransMSG(T_TRANS_COMMONHEADINFO info, T_TRANS_OPENDOOR_INFO msgInfo);  //����ת����Ϣ
//	bool RequestTransMSG(T_TRANS_COMMONHEADINFO info, void* msgInfo, int nMessageType);  //����ת����Ϣ
//	std::map<long, long> m_mapAccessRelation;
//	void AddAccessRelation(TAGDOACCESSRELATION_S &info, bool bIsClear);
//	bool RequestAccessRelation();   //�����ȡ�����Ž�ID
//	bool CheckIsMasterEntranceGuard(long nDeviceId);
//
//	std::vector<S_NEW_CTRLLEVELINFO>  m_vCtrlLevelInfo;  //�����ȡ�ܿصȼ���Ϣ
//	void AddCtrlLevelInfo(S_NEW_CTRLLEVELINFO &info, bool bClear);
//	bool RequestCtrlLevelInfo();
//
//	bool RequestAddAccessLogInfo(TAGDOA_LOG_P info);
//	std::vector<TAGCTRLEVELPLAN_S> m_vCtrlLevelPlan;  //�����ȡ�ܿز�����Ϣ
//	void AddCtrlLevelPlan(TAGCTRLEVELPLAN_S &info, bool bClear);
//	bool RequestCtrlLevelPlan();
//	
//
//	bool RequestAppyDetailInfo(int nId/*������֤ID*/, int nMsgId = -1);  //����������֤ID��ȡ������ϸ��Ϣ
//	TAGDOAAPPLYDETAIL_S m_tagApplyDetails;	//������ϸ����
//	void SetApplyDetailInfo(TAGDOAAPPLYDETAIL_S tagApplyDetails);
//
//	bool RequestIsCollection(TAGDOA_ISCOLLECTION_P info);  //�����޸��ղ�״̬
//
//	std::vector<S_NEW_SHOWPLANLIB>  m_vGetPlanLib;  //��ȡԤ����Ϣ
//	void AddPlanLib(S_NEW_SHOWPLANLIB &info, bool bIsClear);
//	bool RequestPlanLib(P_NEW_SHOWPLANLIB info);
//	
//	std::vector<S_NEW_SHOWPOSITIONINFO> m_vPartInfo;   //��ȡ���в�λ��Ϣ
//	void AddPartInfo(S_NEW_SHOWPOSITIONINFO &info, bool bIsClear);
//	bool RequestPartInfo();
//
//	char m_chAttachment[32];  //�ϴ�����
//	void AddAttachmentId(char* strId);
//	bool RequestAttachmentId(T_UPLOADATTACHMENT_INFO& info,  DWORD dMsgFrom);  //1Ϊץͼ 2Ϊ�Խ�
//
//	
//	std::map<DWORD, vector<CString > > m_mapPreCapture;   //Ԥץͼ
//	bool AddPreCapture(DWORD dwDeviceID, char* strPreCapture, bool bIsClear);
//	bool RequestPreCapture(T_CAPTUREWITHOUTOPEN_INFO info,DWORD dwDeviceId);
//
//	std::vector<S_FrontendTalkInfo> m_vFrontendTalkInfo;  //��ȡǰ������ͷ�豸
//	void AddFrontendTalkInfo(S_FrontendTalkInfo &info, bool bIsClear);
//	bool RequestFrontendTalkInfo();
//
//	bool RequestIssueShortMessage(T_SENDSHORTMESSAGEINFO info);	//���󷢶���
//
//	bool RequestSendEmail(char * pcEmailMsg);		//�������ʼ���Ϣ
//
//	bool RequestSetUnSetDefenseDevice(T_ALARMLINKOPERATEPRARM info);//���󲼳����豸
//
//	bool RequestCapture();			//����ץͼ
//	T_ATTACHMENTINFO  m_CaptureAttachment;	//ץͼ����
//	void AddCaptureAttachment(T_ATTACHMENTINFO &info, bool bClear);
//
//	bool RequestExceptionInfo(TAGDOAEXCEPINFO_P info);  //�����쳣¼��
//
//	std::vector<S_HostTalkInfo> m_vHostTalkInfo;
//	void AddHostTalkInfo(S_HostTalkInfo &info, bool bIsClear);  //�����ȡ�����Խ�
//	bool RequestHostTalkInfo();
//
//	std::vector<CString> m_AllDealerInfo;            //���д�����������Ϣ
//	std::map<CString, S_New_UserInfo*> m_AllDearerDetails;
//	void AddUserInfoToMap(S_New_UserInfo* tUserInfo, int nIndex);
//	void AddAllDealerInfo(CString info, bool bClear);
//	bool RequestAllDealerInfo();   //�����ȡ���д�����������Ϣ
//
//	CString OnGetSwipPersonIDNumber(CString csMemo);		//�õ�ˢ�������֤����
//	CString OnGetSwipPersonCardNumber(CString csMemo);		//�õ�ˢ���˿���
//	CString OnGetSwipCardPersonImgId(CString csIdNumber);	//�õ�ˢ���˶�Ӧ��ͷ��
//
//	/**
//	* @brief �����ȡ�����û���Ϣ
//	**/
//	bool RequestUserDetail(char chUserName[64], int nIndex);
//	//�û�����ϸ��Ϣ
//	S_New_UserInfo* m_pUserDetail;
//
//		/**
//	* @brief ����رջط�����
//	**/
//	bool RequestCloseReplay();
//     /**
//	 * @brief ���������Ƶ ����GUID
//	 **/
//	bool RequestLinkAlarmVideo(T_OPENDOORLINKVIDEOPRARM info,  DWORD dwMsgID);
//     /**
//	 * @brief ������Ƶ�����б�
//	 **/
//	bool RequestVideoAttachmentList(CLIENTGETMEDIASTORAGEATTACHMENT_P info);
//     /**
//	 * @brief ���󲥷���Ƶ�����б�
//	 **/
//	bool RequestPlayAttachmentList(void* pInfo, int nLength);
//     /**
//	 * @brief ����رղ�����Ƶ�����б�
//	 **/
//	bool RequestClosePlayAttachmentList();
//	/**
//	*  @brief �����ȡˢ����ʷ��Ϣ
//	**/
//	bool RequestStaffSearchInfo(TAGDOABYCARDINFO_NEW_P info);
//	/**
//	*  @brief �����ȡ�û��Ž�����ͷ������Ϣ
//	**/
//	bool RequestUserDoorCameraRelation();
//	/**
//	*  @brief �û��Ž�����ͷ������Ϣ���뵽map��
//	**/
//	void AddUserDoorCameraRelationInfo( USERDOORCAMERARELATION_CLIENT_GET_S* pInfo );
//	//�û��Ž�����ͷ������Ϣmap
//	std::map<int, USERDOORCAMERARELATION_CLIENT_GET_S*> m_mapUserDoorCameraRelationInfo;
//
//	/**
//	*  @breif �����ȡ�Ž�Ѻ���豸������Ϣ
//	 **/
//	bool RequestEscortAccessRelation();
//	std::map<long, long> m_mapEscortAccessRelation;
//	/**
//	*  @breif �Ž�Ѻ���豸������Ϣ���뵽map��
//	**/
//	void AddEscortAccessRelation(ACCESSSYRELATION_GET_S &info, bool bIsClear);
//
//public:
//	/**
//	* @breif ��ȡ���豸��������Ϣ
//	* @param int nDeviceID
//	**/
//	TAGDOAACCESSINFO_S* GetAccessHostInfo(int nDeviceID);
//		/**
//	* @breif ��ȡ���豸�Ĳ��Եȼ���Ϣ
//	* @param char* chDeviceName
//	**/
//    S_NEW_CTRLLEVELINFO* GetCTRLevelInfo(char* chDeviceName);	
//	/**
//	* @breif ��ȡ��֤������Ϣ
//	* @param int nDevNumber
//	**/
//	OPENDOORAPPLYCONFIG* GetOpenDoorApplyConfig(int nDevNumber);
//
//	/**
//	* @brief ����������֤����
//	* @param info-��GUID����֤���� dwMsgID-��ϢID
//	**/
//	bool RequestSubmitDealInfo(TAGDOA_INFO_P_NEW info, DWORD dwMsgID);  
//	/**
//	* @brief ����GUID
//	**/
//    char* GenerateGUID();
//   /**
//   * @brief �ж��Ƿ�ΪGUID
//   **/
//	bool IsGUID(std::string str);
//   /**
//   * @brief ��ȡ����豸�����ĵ��û���Ϣ 
//   **/
//	USERDOORCAMERARELATION_CLIENT_GET_S* GetUserDoorRelation(int nDeviceId);
//   /**
//   * @brief ���ݱ�����Ϣ��ȡ��Ա��Ϣ 
//   **/
//	S_RECV_CARDLOGINFO* GetCardPersonInfo(T_TRANSMITALARMINFO_EX* pAlarmInfo);
//	/** 
//	*  @brief ��������\���������ļ� 
//	**/
//	bool RequestLockOrUnlockAttachment(ALARMSTORAGEFILELOCKED_SET_P info);
//	/** 
//	*  @brief �����ѯ������״̬����ʷ��¼ 
//	**/
//	bool RequestLockOrUnlockStateHistory(TAGDOAHISTORYINFOWITHLOCK_P info);
//   /**
//   * @brief �����ѯ�Ž�״̬
//   **/
//
//	/**
//	* @brief ����������Ա��Ϣ
//	**/
//	bool RequestSetStaffInfo(STAFFINFOOPERATION_P info, DWORD dwMsgId);
//	/**
//	* @brief �������ò�����Ϣ
//	**/
//	bool RequestDepartmentOperation(DEPARTMENTINFOOPERATION_P info, DWORD dwMsgId);
//	/**
//	* @brief ����������Ա״̬
//	**/
//	bool RequestStaffStateOperation(STAFFSTATUS_SET_P info);
//	/**
//	* @brief �����ȡ������Ϣ
//	**/
//	bool RequestDepartmentInfo(DEPARTMENTINFO_GET_P& info);
//	/**
//	* @brief �����ȡȨ������Ϣ
//	**/
//	bool RequestAuthgroupInfo();
//	/**
//	* @brief ������Ա��ȡȨ������Ϣ
//	**/
//	bool RequestStaffAuthgroupInfo(STAFFAUTHINFO_GET_P &info);
//	/**
//	* @brief �����ȡ��Ա��Ϣ
//	**/
//	bool RequestStaffInfoOperation(STAFFINFO_GET_P info, DWORD dwMsgID = 0);
//	/**
//	* @brief �����ȡ��Ա������Ϣ
//	**/
//	bool RequestOperationInfo(STAFFOPERATION_GET_P info);
//	/**
//	 * @breif �����ȡ���������豸��Ϣ
//	**/
//	bool RequstLocalDeviceNodeInfo();
//	/**
//	* @brief ��Ӳ�����Ϣ������������
//	**/
//	std::vector<DEPARTMENTINFO_GET_S> m_vecStaffDepartment;
//    void AddStaffDepartment(DEPARTMENTINFO_GET_S *info, bool bClear);
//	/**
//	* @brief ���Ȩ������Ϣ��������
//	**/
//	std::vector<AUTHGROUP_GET_S> m_vecfAuthGroup;
//    void AddAuthgroup(AUTHGROUP_GET_S *info, bool bClear);
//	/**
//	* @brief �����ԱȨ������Ϣ��������
//	**/
//	std::vector<STAFFAUTHINFO_GET_S> m_vecStaffAuthgroup;
//    void AddStaffAuthgroup(STAFFAUTHINFO_GET_S info, bool bClear);
//	/**
//	* @brief �����Ա��Ϣ��������
//	**/
//	std::vector<STAFFINFO_GET_S> m_vecStaffinfo;
//	void AddStaffinfo(STAFFINFO_GET_S *info, bool bClear);
//	/**
//	* @brief �����Ա������Ϣ��������
//	**/
//	std::vector<STAFFOPERATION_GET_S> m_vecStaffOperationinfo;
//	void AddStaffOperationinfo(STAFFOPERATION_GET_S *info, bool bClear);
//	/**
//	* @brief ����StaffManagerUI���
//	**/
//	void SetStaffManagerUIHandle(HWND hUI);
//	HWND hStaffManagerUI;
//	/**
//	* @brief ����AddStaffInfoUI���
//	**/
//	void SetAddStaffInfoUIHandle(HWND hUI);
//	HWND hAddStaffInfoUI;
//	/**
//	* @brief ����OperationInfoUI���
//	**/
//	void SetOperationInfoUIHandle(HWND hUI);
//	HWND hOperationInfoUI;

};
#endif