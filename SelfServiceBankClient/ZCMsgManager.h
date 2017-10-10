#pragma once
#ifndef ZCMsgManagerH
#define ZCMsgManagerH
#include "TjtyTcpClientModule.h"
#include "ConnectAppProtocol.h"
#include "ZCProtocol.h"
//#include "DeBugLog.h"
//
//#define MESSAGENUM                70  //消息条数 
//#define EROCURRENTUSER            0   //当前用户信息
//#define EROAREA                   1   //区域信息
//#define EROCERTIFICATION          2   //认证查询
//#define EROSTAFFSEARCH            3   //人员查询（刷卡信息）
//#define EROSTATISTIC              4   //统计信息
//#define EROACSHOSTINFO            5   //门禁主机信息
//#define EROINTOALARMLAYER         6   //进入图层
//#define EROWATCHVIDEO             7   //观看视频
//#define EROREPLAYVIDEO            8   //回放视频
//#define ERODIALLING               9   //打电话
//#define EROIPTALK                 10  //对讲
//#define EROOPENDOOR               11  //开门
//#define EROMANULCAPTUREINFO       12  //请求抓图消息推送
//#define EROCLOSEMANULCAPTUREINFO  13  //关闭消息推送
//#define EROLINKSWIPCARDRECORD     14  //关联刷卡认证记录
//#define EROADDSUGGESTION          15  //新增认证处置意见
//#define EROADDLOGINFO             16  //新增系统日志
//#define EROADDOPERAINFO           17  //新增认证处置操作信息
//#define EROGETOPERAINFO           18  //获取认证操作详细信息 
//#define EROGETAPPLYPLAN           19  //获取预案执行信息
//#define EROGETSUGGESTIONINFO      20  //获取认证处理意见信息
//#define EROGETLOGINFO             21  //获取认证系统日志
//#define EROGETACCESSLOGINFO       22  //获取认证关联刷卡信息
//#define EROSUBMITAUDITORDEALINFO  24  //提交审核数据
//#define EROADDDEALPLANINFO        25  //提交预案执行数据
//#define EROMODIFYDEALTYPE         26  //修改认证处置方式
//#define EROSUBMITDEALINFO         27  //新增认证申请记录
//#define EROGETUSERBASEINFO        28  //请求获取用户信息
//#define EROMODIFYREQUESTSTATE     29  //请求修改认证处置状态
//#define EROGETALLPEPOLEINFO       30  //请求获取所有需管辖人员信息
//#define EROTRANSMSG               31  //请求客户端转发消息
//#define EROCOLLECTCHART           32  //收藏的图表信息
//#define EROCHANGECOLLECTCHART     33  //增删改收藏的图表信息
//#define EROSUBSCRIBE              34  //请求获取用户订阅信息
//#define EROCHANGESUBSCRIBE        35  //请求增、删、改订阅信息
//#define EROREPORT                 36  //请求获取报告信息
//#define EROCHANGEREPORTSTATUS     37  //修改报告状态信息
//#define EROACCESSRELATION         38  //请求获取门禁主从关系信息
//#define EROCTRLLEVELMULINFO       39  //请求获取管控等级信息
//#define EROCTRLLEVELPLAN          40  //请求获取管控策略信息
//#define ERODEPARTMENT             41  //部门信息
//#define EROGETPLANINFO            42  //获取预案信息 
//#define EROGETALLPARTINFO         43  //获取所有部位信息
//#define EROPHOTO                  44  //获取照片
//#define EROUPLOADATTACTMENT       45  //上传附件
//#define ERODOWNLOADATTACTMENT     46  //下载附件
//#define EROCAPTURE				  47  //抓图
//#define EROBASICSETTING           48  //基本设置
//#define EROAPPLYDETAILINFO		  50  //请求申请详细信息
//#define EROISCOLLECTIONS          51  //请求修改收藏状态
//#define EROPRECAPTURE             52  //预抓图
//#define EROGETACSHOSTLINKINFO     53  //获取报警主机关联摄像头
//#define EROSENDSHORTMSG			  54  //发送短信
//#define EROSENDEMAIL			  55  //发送邮件
//#define EROIFSETDEFENSE			  56  //布撤防
//#define EROCONTRODEVICE			  57  //控制外设
//#define EROEXCEPTINPUT            58  //异常录入
//#define EROHOSTTALKINFO			  59  //获取对讲关联信息
//#define EROALLUSER	     		  60  //所有用户
//#define EROCLOSEVIDEO             61  //请求关闭视频
//#define EROESCORTACCESSRELATION   62  //请求获取门禁关联押运设备
//#define EROLINKESCORTCARDRECORD   63  //关联押运认证记录
//#define EROGETESCORTINFOFROMWEB   64  //获取web端押运信息
//
//#define ZC_MSG_SERIAL_ID_MAX_VALUE				10000	// 消息序列号最大值
//#define USER_MSG_SERIAL_ID_DELETE_DEPARTMENT	10001	// 删除部门消息序列号


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
//	bool m_bIsAbnormalId;  //标定是否为异常录入请求认证ID
//	bool m_bIsAttachment;  //标志否是为OpenDoolApplyDlg请求
//	int m_iShow;    //浮窗是否显示
//	CDebugLogService* m_cDebugLog;
//	std::map<int,char*> m_vPersonPhoto;

public:
	//请求函数
//	bool RequestCurrentUserInfo();   //请求当前用户信息
//	T_CURUSER_INFO_EX m_CurrentUserInfo;
//	bool RequestOpenDoorDisposalInfo();		// 请求第三方处理权限
//	T_OPENDOORPOSALINFO m_tOpenDoorDisposalInfo;
//	void AddCurrentUserInfo(T_CURUSER_INFO_EX *info);
//	bool RequestAreaInfo();   //请求区域信息
//	std::vector<T_AREA_INFO> m_AreaInfo;
//	void AddAreaInfo(T_AREA_INFO &info, bool bClear);
//	bool RequestCertificationSearchInfo(TAGDOAHISTORYINFO_P info);   //请求认证查询
//	std::vector<TAGDOAHISTORYINFO_S> m_CertificationSearchInfo;
//	void AddCertificationSearchInfo(TAGDOAHISTORYINFO_S &info, bool bClear);
//	bool RequestStaffSearchInfo(TAGDOABYCARDINFO_P info);   //请求人员查询（刷卡信息）
//	std::vector<TAGDOABYCARDINFO_NEW_S> m_StaffSearchInfo;
//	void AddStaffSearchInfo(TAGDOABYCARDINFO_NEW_S &info, bool bClear);
//	bool RequestStatisticInfo(TAGDOASTATISTICS_P info);   //请求统计信息
//	bool RequestStatisticInfo(TAGDOASTATISTICS_P info,DWORD dwMsgID);   //请求统计信息
//	std::vector<TAGDOASTATISTICS_S> m_StatisticInfo;
//	void AddStatisticInfo(TAGDOASTATISTICS_S &info, bool bClear);
//	bool RequestCollectChartInfo(P_NEW_SHOWUSERGRAPHINFO info);   //请求获取收藏的图表信息
//	std::vector<S_NEW_SHOWUSERGRAPHINFO> m_CollectChartInfo;
//	void AddCollectChartInfo(S_NEW_SHOWUSERGRAPHINFO &info, bool bClear);
//	bool RequestChangeCollectChartInfo(P_NEW_OPUSERGRAPHINFO info);   //增删改收藏的图表信息
//	bool RequestSubscribeInfo(P_NEW_SHOWUSERREPORTBOOKINFO info);   //请求获取用户订阅信息
//	std::vector<S_NEW_SHOWUSERREPORTBOOKINFO> m_SubscribeInfo;
//	void AddSubscribeInfo(S_NEW_SHOWUSERREPORTBOOKINFO &info, bool bClear);
//	bool RequestChangeSubscribeInfo(P_NEW_OPUSERREPORTINFO info);   //请求增、删、改订阅信息
//	bool RequestReportInfo(P_NEW_SHOWUSERREPORTINFO info);   //请求获取报告信息
//	std::vector<S_NEW_SHOWUSERREPORTINFO> m_ReportInfo;
//	void AddReportInfo(S_NEW_SHOWUSERREPORTINFO &info, bool bClear);
//	bool RequestChangeReportStatusInfo(P_NEW_MODSTATUSUSERREPORT info);   //修改报告状态信息
//	bool RequestDepartmentInfo();   //获取部门信息
//	std::vector<TAGDOADEPARTMENTINFO_S> m_DepartmentInfo;
//	void AddDepartmentInfo(TAGDOADEPARTMENTINFO_S &info, bool bClear);
//	bool RequrstDownLoadPic(char* chImage,DWORD m_dwMsgID);                 //请求用户图片
//	bool RequestDownAttachment(char* chImage,DWORD m_dwMsgID);
//	bool SetBasicSettingInfo(TAGDOA_USERINFO_P info);   //设置基本信息
//
//	
//	std::vector<TAGDOAACCESSINFO_S> m_vAllACSHostInfo;
//	void AddACSHostInfo(TAGDOAACCESSINFO_S &st_info, bool bClear);
//	bool RequestACSHostInfo();   //请求所有门禁主机信息
//
//	bool RequestIntoLayer(char* chAreaName);     //请求进入图层 1
//
//	bool RequestWatchVideo(T_ALARMLINKOPERATEPRARM info, DWORD dwMsgID);   //请求关联视频 2
//	bool RequestCloseVideo();   //请求关联视频 2
//
//	bool RequestReplayVideo(T_ALARMREPLAYPARAM info, DWORD dwMsgID);  //请求回放录像 3 
//
//	bool RequestDialling(T_TELEPHONECALLINFO info, DWORD dwMsgID);     //请求打电话 4 
//
//	T_ATTACHMENTINFO m_stAttachmentInfo;
//	void AddAttachmentInfo(T_ATTACHMENTINFO *info);
//	bool RequestIPTalk(int nDeviceID, DWORD dwMsgID);       //请求对讲 5
//
//	bool RequestOpenDoor(T_CONTROLACSHOSTPRARM info, DWORD dwMsgID);     //请求开门/关门 6
//
//	bool RequestManulCaptureInfo();  //请求推送手动抓图消息
//
//	bool RequestCloseManulCaptureInfo();  //请求关闭推动手动抓图消息
//
//	bool RequestLinkSwipCardRecord(TAGOPENDOOR_P info);  //请求关联刷卡认证记录
//
//	bool RequestLinkEscortCardRecord(DOOROPENSYRELATION_SET_P info);//请求关联押运认证记录
//
//	bool RequestEscortPlanInfo(int nOrgId);  //请求获取指定网点的押运排班信息(守押)
//
//	bool RequestEscortPhotoInfo(struct TSyGetImage info);  //请求获取各种类型的图片(守押)
//
//	bool RequestEscortRouteInfo(int nOrgId);  //请求获取指定网点押运路线的状态(守押)
//
//	bool RequestEscortRFIDInfo(struct TSyGetTagData info);  //请求电子标签卡的详细信息(守押)
//	
//	bool RequestAddSuggestion(TAGDOA_PROCESSMEMO_P info);  //请求新增认证处置意见
//
//	bool RequestAddLogInfo(TAGDOA_APPLYACTLOG_P info);    //请求新增系统日志
//
//	bool RequestAddOperaInfo(TAGDOA_ATTACHMENT_P info);   //请求新增处置操作
//
//	std::vector<TAGDOAATTACHMENT_S> m_vOperaInfo;
//	void AddOperationInfo(TAGDOAATTACHMENT_S &info, bool bClear);  //获取认证操作详细信息
//	bool RequestOperationInfo(int nId);
//
//	std::vector<TAGDOAACTIONDETAIL_S> m_vActionDetail;  //获取预案执行信息
//	void AddActionDetail(TAGDOAACTIONDETAIL_S &info, bool bClear);
//	bool RequestActionDetail(int nId);
//
//	std::vector<TAGDOAPROCESSMEMO_S> m_vSuggestionInfo;  //获取认证处理意见信息
//	void AddSuggestionInfo(TAGDOAPROCESSMEMO_S &info, bool bClear);
//	bool RequestSuggestionInfo(int nId);
//
//	std::vector<TAGDOAACTLOG_S>  m_vSystemLog;  //获取认证系统日志信息
//	void AddSystemLog(TAGDOAACTLOG_S &info, bool bClear);
//	bool RequestSystemLog(int nId);
//
//	std::vector<TAGDOADOORACCESSLOG_S> m_vDoorAccessLog;  //获取认证刷卡信息
//	void AddDoorAccessLog(TAGDOADOORACCESSLOG_S &info, bool bClear);
//	bool RequestDoorAccessLog(int nId);
//
//	bool RequestSubmitAuditorDealInfo(TAGDOA_AUDITOR_P info);  //提交审核数据
//
//	bool RequestAddDealPlanInfo(TAGOPENDOORPLANINFO_P info);  //提交预案执行数据
//
//	bool RequestModifyDealType(TAGDOOROPENAPPLY_METHOD_P info);  //修改认证处置方式：值-1-未处理 0-开门-申请授权2-应急处置 3-申请特批4-拒绝开门
//
//    TAGDOA_INFO_S m_tNewOpenDoorApply;
//	void AddNewOpenDoorApply(TAGDOA_INFO_S* info);
//	bool RequestSubmitDealInfo(TAGDOA_INFO_P info, DWORD dwMsgID);  //新增认证申请记录
//
//	TAGDOAPPASSWORD_S m_stPassWord;  //请求获取用户信息
//	void AddUserPassWord(TAGDOAPPASSWORD_S *info);
//	bool RequestUserPassWord(TAGDOAPPASSWORD_P info);
//
//	bool RequestModifyRequestState(TAGDOA_PROCESSSTATUS_P info);  //请求修改认证处置状态 认证状态值 1-未处置2-处置中 3-待审核4-已处理5-已失效
//
//	std::vector<TAGDOAPERSONINFO_S> m_vAllPersonInfo;  //请求获取所有需管辖人员信息
//	void AddAllPersonInfo(TAGDOAPERSONINFO_S &info, bool bClear);
//	bool RequestAllPersonInfo();
//
//	char m_chManualCapturePath[512];   //主动推送抓图地址
//
//	void AddManualCapture(char* chPath); 
//	bool RequestTransMSG(T_TRANS_COMMONHEADINFO info, T_TRANS_OPENDOOR_INFO msgInfo);  //请求转发消息
//	bool RequestTransMSG(T_TRANS_COMMONHEADINFO info, void* msgInfo, int nMessageType);  //请求转发消息
//	std::map<long, long> m_mapAccessRelation;
//	void AddAccessRelation(TAGDOACCESSRELATION_S &info, bool bIsClear);
//	bool RequestAccessRelation();   //请求获取主从门禁ID
//	bool CheckIsMasterEntranceGuard(long nDeviceId);
//
//	std::vector<S_NEW_CTRLLEVELINFO>  m_vCtrlLevelInfo;  //请求获取管控等级信息
//	void AddCtrlLevelInfo(S_NEW_CTRLLEVELINFO &info, bool bClear);
//	bool RequestCtrlLevelInfo();
//
//	bool RequestAddAccessLogInfo(TAGDOA_LOG_P info);
//	std::vector<TAGCTRLEVELPLAN_S> m_vCtrlLevelPlan;  //请求获取管控策略信息
//	void AddCtrlLevelPlan(TAGCTRLEVELPLAN_S &info, bool bClear);
//	bool RequestCtrlLevelPlan();
//	
//
//	bool RequestAppyDetailInfo(int nId/*申请认证ID*/, int nMsgId = -1);  //根据申请认证ID获取申请详细信息
//	TAGDOAAPPLYDETAIL_S m_tagApplyDetails;	//申请详细参数
//	void SetApplyDetailInfo(TAGDOAAPPLYDETAIL_S tagApplyDetails);
//
//	bool RequestIsCollection(TAGDOA_ISCOLLECTION_P info);  //请求修改收藏状态
//
//	std::vector<S_NEW_SHOWPLANLIB>  m_vGetPlanLib;  //获取预案信息
//	void AddPlanLib(S_NEW_SHOWPLANLIB &info, bool bIsClear);
//	bool RequestPlanLib(P_NEW_SHOWPLANLIB info);
//	
//	std::vector<S_NEW_SHOWPOSITIONINFO> m_vPartInfo;   //获取所有部位信息
//	void AddPartInfo(S_NEW_SHOWPOSITIONINFO &info, bool bIsClear);
//	bool RequestPartInfo();
//
//	char m_chAttachment[32];  //上传附件
//	void AddAttachmentId(char* strId);
//	bool RequestAttachmentId(T_UPLOADATTACHMENT_INFO& info,  DWORD dMsgFrom);  //1为抓图 2为对讲
//
//	
//	std::map<DWORD, vector<CString > > m_mapPreCapture;   //预抓图
//	bool AddPreCapture(DWORD dwDeviceID, char* strPreCapture, bool bIsClear);
//	bool RequestPreCapture(T_CAPTUREWITHOUTOPEN_INFO info,DWORD dwDeviceId);
//
//	std::vector<S_FrontendTalkInfo> m_vFrontendTalkInfo;  //获取前段摄像头设备
//	void AddFrontendTalkInfo(S_FrontendTalkInfo &info, bool bIsClear);
//	bool RequestFrontendTalkInfo();
//
//	bool RequestIssueShortMessage(T_SENDSHORTMESSAGEINFO info);	//请求发短信
//
//	bool RequestSendEmail(char * pcEmailMsg);		//请求发送邮件信息
//
//	bool RequestSetUnSetDefenseDevice(T_ALARMLINKOPERATEPRARM info);//请求布撤防设备
//
//	bool RequestCapture();			//请求抓图
//	T_ATTACHMENTINFO  m_CaptureAttachment;	//抓图附件
//	void AddCaptureAttachment(T_ATTACHMENTINFO &info, bool bClear);
//
//	bool RequestExceptionInfo(TAGDOAEXCEPINFO_P info);  //请求异常录入
//
//	std::vector<S_HostTalkInfo> m_vHostTalkInfo;
//	void AddHostTalkInfo(S_HostTalkInfo &info, bool bIsClear);  //请求获取主机对讲
//	bool RequestHostTalkInfo();
//
//	std::vector<CString> m_AllDealerInfo;            //所有处理人姓名信息
//	std::map<CString, S_New_UserInfo*> m_AllDearerDetails;
//	void AddUserInfoToMap(S_New_UserInfo* tUserInfo, int nIndex);
//	void AddAllDealerInfo(CString info, bool bClear);
//	bool RequestAllDealerInfo();   //请求获取所有处理人姓名信息
//
//	CString OnGetSwipPersonIDNumber(CString csMemo);		//得到刷卡人身份证号码
//	CString OnGetSwipPersonCardNumber(CString csMemo);		//得到刷卡人卡号
//	CString OnGetSwipCardPersonImgId(CString csIdNumber);	//得到刷卡人对应的头像
//
//	/**
//	* @brief 请求获取所有用户信息
//	**/
//	bool RequestUserDetail(char chUserName[64], int nIndex);
//	//用户的详细信息
//	S_New_UserInfo* m_pUserDetail;
//
//		/**
//	* @brief 请求关闭回放下载
//	**/
//	bool RequestCloseReplay();
//     /**
//	 * @brief 请求关联视频 并传GUID
//	 **/
//	bool RequestLinkAlarmVideo(T_OPENDOORLINKVIDEOPRARM info,  DWORD dwMsgID);
//     /**
//	 * @brief 请求视频附件列表
//	 **/
//	bool RequestVideoAttachmentList(CLIENTGETMEDIASTORAGEATTACHMENT_P info);
//     /**
//	 * @brief 请求播放视频附件列表
//	 **/
//	bool RequestPlayAttachmentList(void* pInfo, int nLength);
//     /**
//	 * @brief 请求关闭播放视频附件列表
//	 **/
//	bool RequestClosePlayAttachmentList();
//	/**
//	*  @brief 请求获取刷卡历史信息
//	**/
//	bool RequestStaffSearchInfo(TAGDOABYCARDINFO_NEW_P info);
//	/**
//	*  @brief 请求获取用户门禁摄像头关联信息
//	**/
//	bool RequestUserDoorCameraRelation();
//	/**
//	*  @brief 用户门禁摄像头关联信息插入到map中
//	**/
//	void AddUserDoorCameraRelationInfo( USERDOORCAMERARELATION_CLIENT_GET_S* pInfo );
//	//用户门禁摄像头关联信息map
//	std::map<int, USERDOORCAMERARELATION_CLIENT_GET_S*> m_mapUserDoorCameraRelationInfo;
//
//	/**
//	*  @breif 请求获取门禁押运设备关联信息
//	 **/
//	bool RequestEscortAccessRelation();
//	std::map<long, long> m_mapEscortAccessRelation;
//	/**
//	*  @breif 门禁押运设备关联信息插入到map中
//	**/
//	void AddEscortAccessRelation(ACCESSSYRELATION_GET_S &info, bool bIsClear);
//
//public:
//	/**
//	* @breif 获取该设备的主机信息
//	* @param int nDeviceID
//	**/
//	TAGDOAACCESSINFO_S* GetAccessHostInfo(int nDeviceID);
//		/**
//	* @breif 获取该设备的策略等级信息
//	* @param char* chDeviceName
//	**/
//    S_NEW_CTRLLEVELINFO* GetCTRLevelInfo(char* chDeviceName);	
//	/**
//	* @breif 获取认证配置信息
//	* @param int nDevNumber
//	**/
//	OPENDOORAPPLYCONFIG* GetOpenDoorApplyConfig(int nDevNumber);
//
//	/**
//	* @brief 请求新增认证申请
//	* @param info-带GUID的认证详情 dwMsgID-消息ID
//	**/
//	bool RequestSubmitDealInfo(TAGDOA_INFO_P_NEW info, DWORD dwMsgID);  
//	/**
//	* @brief 生成GUID
//	**/
//    char* GenerateGUID();
//   /**
//   * @brief 判断是否为GUID
//   **/
//	bool IsGUID(std::string str);
//   /**
//   * @brief 获取金库设备关联的的用户信息 
//   **/
//	USERDOORCAMERARELATION_CLIENT_GET_S* GetUserDoorRelation(int nDeviceId);
//   /**
//   * @brief 根据报警信息获取人员信息 
//   **/
//	S_RECV_CARDLOGINFO* GetCardPersonInfo(T_TRANSMITALARMINFO_EX* pAlarmInfo);
//	/** 
//	*  @brief 请求锁定\解锁联动文件 
//	**/
//	bool RequestLockOrUnlockAttachment(ALARMSTORAGEFILELOCKED_SET_P info);
//	/** 
//	*  @brief 请求查询带锁定状态的历史记录 
//	**/
//	bool RequestLockOrUnlockStateHistory(TAGDOAHISTORYINFOWITHLOCK_P info);
//   /**
//   * @brief 请求查询门禁状态
//   **/
//
//	/**
//	* @brief 请求设置人员信息
//	**/
//	bool RequestSetStaffInfo(STAFFINFOOPERATION_P info, DWORD dwMsgId);
//	/**
//	* @brief 请求设置部门信息
//	**/
//	bool RequestDepartmentOperation(DEPARTMENTINFOOPERATION_P info, DWORD dwMsgId);
//	/**
//	* @brief 请求设置人员状态
//	**/
//	bool RequestStaffStateOperation(STAFFSTATUS_SET_P info);
//	/**
//	* @brief 请求获取部门信息
//	**/
//	bool RequestDepartmentInfo(DEPARTMENTINFO_GET_P& info);
//	/**
//	* @brief 请求获取权限组信息
//	**/
//	bool RequestAuthgroupInfo();
//	/**
//	* @brief 请求人员获取权限组信息
//	**/
//	bool RequestStaffAuthgroupInfo(STAFFAUTHINFO_GET_P &info);
//	/**
//	* @brief 请求获取人员信息
//	**/
//	bool RequestStaffInfoOperation(STAFFINFO_GET_P info, DWORD dwMsgID = 0);
//	/**
//	* @brief 请求获取人员操作信息
//	**/
//	bool RequestOperationInfo(STAFFOPERATION_GET_P info);
//	/**
//	 * @breif 请求获取中心所有设备信息
//	**/
//	bool RequstLocalDeviceNodeInfo();
//	/**
//	* @brief 添加部门信息到部门向量中
//	**/
//	std::vector<DEPARTMENTINFO_GET_S> m_vecStaffDepartment;
//    void AddStaffDepartment(DEPARTMENTINFO_GET_S *info, bool bClear);
//	/**
//	* @brief 添加权限组信息到向量中
//	**/
//	std::vector<AUTHGROUP_GET_S> m_vecfAuthGroup;
//    void AddAuthgroup(AUTHGROUP_GET_S *info, bool bClear);
//	/**
//	* @brief 添加人员权限组信息到向量中
//	**/
//	std::vector<STAFFAUTHINFO_GET_S> m_vecStaffAuthgroup;
//    void AddStaffAuthgroup(STAFFAUTHINFO_GET_S info, bool bClear);
//	/**
//	* @brief 添加人员信息到向量中
//	**/
//	std::vector<STAFFINFO_GET_S> m_vecStaffinfo;
//	void AddStaffinfo(STAFFINFO_GET_S *info, bool bClear);
//	/**
//	* @brief 添加人员操作信息到向量中
//	**/
//	std::vector<STAFFOPERATION_GET_S> m_vecStaffOperationinfo;
//	void AddStaffOperationinfo(STAFFOPERATION_GET_S *info, bool bClear);
//	/**
//	* @brief 设置StaffManagerUI句柄
//	**/
//	void SetStaffManagerUIHandle(HWND hUI);
//	HWND hStaffManagerUI;
//	/**
//	* @brief 设置AddStaffInfoUI句柄
//	**/
//	void SetAddStaffInfoUIHandle(HWND hUI);
//	HWND hAddStaffInfoUI;
//	/**
//	* @brief 设置OperationInfoUI句柄
//	**/
//	void SetOperationInfoUIHandle(HWND hUI);
//	HWND hOperationInfoUI;

};
#endif