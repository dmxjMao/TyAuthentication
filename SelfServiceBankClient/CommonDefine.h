#pragma once
#include "ConnectAppProtocol.h"
#include "ZCProtocol.h"

/*公共定义*/

//ZCMsg消息头大小
#define ZCMsgHeaderLen sizeof(ZC_MSG_RESP_RESULT)

//消息处理公共代码提取宏
#define ZCMsgMacro_beginfor(T, pMsg, nMsgLen)	\
const int nStructLen = sizeof(T);	\
int iCount = (nMsgLen - ZCMsgHeaderLen) / nStructLen;	\
for (int i = 0; i < iCount; ++i) {	\
	//T* pInfo = (T*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);	

#define ZCMsgMacro_endfor	}


/*
按钮枚举
*/
enum emButton {
	EmergencyBtn,
	GrantBtn,
	OpenDoorBtn,
	EnterMapLayerBtn,
	LockDoorBtn,
	RefuseOpenBtn,
	ConfirmBtn,
	emButtonBuff
};



/*结构体
*/


/*预案信息
*/
//预案步骤
struct stEmergPlanStep {
	int nNo = -1;//编号
	bool bMustDo = false;//是否必须执行
	CString strName;//名称

	stEmergPlanStep(int no, bool bDo, CString name)
		: nNo(no), bMustDo(bDo), strName(name) {}
};
//预案信息
struct stEmergPlan {
	int nPlanID;//预案ID
	CString strPlanName;//预案名称
	CString strCreateMan;//创建人
	std::vector<stEmergPlanStep> vecStep;//预案步骤

	//stEmergPlan(CString name, std::vector<stEmergPlanStep>&& vec)
	//	: strPlanName(name), vecStep(vec) {}
};




/*用户信息
*/
struct stUserInfo {
	S_New_UserInfo stBaseInfo;//基础信息
	T_OPENDOORPOSALINFO stDisposalInfo;//权限
};


/*管辖人员信息
*/
struct stCtrlPersonInfo {
	TAGDOAPERSONINFO_S stBaseInfo;//基础信息
	TCHAR szHeadPic[MAX_PATH] = { 0 };//头像全路径
};


/*策略配置信息
*/
struct stCtrlPlanInfo {
	UINT8 nAuthTimeLimit = 3;//认证时限
	UINT8 nAuthType = 1;//认证方式 1-远程、2-本地
	UINT8 nDoor1Type = 2;//认证识别一方式  1-指纹、  2-刷卡
	UINT8 nDoor1Num = 1;//识别一  人数
	UINT8 nDoor2Type = 2;//认证识别二  1-指纹、  2-刷卡
	UINT8 nDoor2Num = 1;//识别二 人数
	UINT8 nRecType = -1;//录像方式 1-主通道、2-全通道
	UINT8 nPreRecTime = 30;//预录时长
	UINT8 nRecTime = 60;//录像时长
	UINT8 nCapType = -1;//抓图方式  1-主通道、2-全通道
	UINT8 nCapDur = 5;//抓图间隔
	UINT8 nCapTime = 60;//抓图时长
	int nEMPlanID = -1;//预案ID
	UINT8 bEMPlanStep = 2;//预案按步执行    1-是      2-否
	UINT8 nOpenGrantType = -1;//开门授权    1-刷卡    2-密码
	UINT8 nSuperGrantType = -1;//上级授权    1-刷卡    2-密码
	//排班核对    1-是      2-否
	UINT8 bApproval = 2;//允许特批    1-是      2-否
	UINT8 bFCGrant = 2;//首卡授权    1-是      2-否
	
	char szEMPlanName[128] = { 0 }; //预案名称
};

/*门禁主机信息
*/
struct stACSHostInfo {
	TAGDOAACCESSINFO_S stBaseInfo;//基础信息，对应配置“修改..."
	bool bMaster = true; //是否是从门禁
	union {
		char szMasterName[128];//主门禁名
		char szSlaveName[128];//从门禁名
	}unMS;
	UINT8 nCtrlLevel = -1;//管控等级
	char szPlaceName[64] = { 0 };//所在场所名称
	char szPartName[64] = { 0 };//所在部位名称
	std::vector<int> vecRelChnl;//联动视频通道
	std::vector<int> vecRelTalk;//关联对讲设备
};


/*申请人员信息
*/
struct stApplyPersonInfo {
	std::shared_ptr<stCtrlPersonInfo> stPersonInfo = 0;//申请人员信息
	UINT8 nCardType = 1;//卡的类别：即1-合法卡、2-无权限卡、3-非法卡

};


/*申请信息
一个人一条申请信息
*/
struct stApplyInfo {
	CString strWebSiteName;//申请网点
	int nImportance = -1;//重要程度（管控等级）
	CString strMode;//刷卡模式：(如:XX人刷卡+中心授权)
	CTime tmApply;//申请认证时间，CString不好转CTime
	//两路视频
	//stApplyPersonInfo stPersonInfo;//申请人员信息
	std::shared_ptr<stApplyPersonInfo> stPersonInfo = 0;//申请人员信息

	//stApplyInfo(){}
	//stApplyInfo(CString wbName, int nImp, CTime tm, stApplyPersonInfo&& st)
	//	: strWebSiteName(wbName), nImportance(nImp), tmApply(tm), 
	//	stPersonInfo(st) {}
};

