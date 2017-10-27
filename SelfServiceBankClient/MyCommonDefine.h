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

/*认证状态
*/
enum emAuthState {
	Dealing,//处理中
	Verify,//待审核
	Dealed,//已处理
	Invalid,//已失效
	emAuthStateBuff
};

/*结构体
*/



/*用户信息
所有处理人不用获取了，这里只有当前用户了
*/
struct stUserInfo {
	S_New_UserInfo stBaseInfo;//基础信息
	T_OPENDOORPOSALINFO stDisposalInfo;//权限
	std::shared_ptr<std::vector<USERDOORCAMERARELATION_CLIENT_GET_S>> pDealedACSHost;//用户受理的门禁id及其关联的视频，只有当前用户有
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
	UINT8 nRecType = 0;//录像方式 1-主通道、2-全通道
	UINT8 nPreRecTime = 30;//预录时长
	UINT8 nRecTime = 60;//录像时长
	UINT8 nCapType = -1;//抓图方式  1-主通道、2-全通道
	UINT8 nCapDur = 5;//抓图间隔
	UINT8 nCapTime = 60;//抓图时长
	int nEMPlanID = 0;//预案ID
	UINT8 bEMPlanStep = 2;//预案按步执行    1-是      2-否
	UINT8 nOpenGrantType = 0;//开门授权    1-刷卡    2-密码
	UINT8 nSuperGrantType = 0;//上级授权    1-刷卡    2-密码
	//排班核对    1-是      2-否
	UINT8 bApproval = 2;//允许特批    1-是      2-否
	UINT8 bFCGrant = 2;//首卡授权    1-是      2-否
	
	char szEMPlanName[128] = { 0 }; //预案名称
};

/*门禁主机信息
*/
struct stACSHostInfo {
	TAGDOAACCESSINFO_S stBaseInfo;//基础信息，对应配置“修改..."
	UINT8 nSlave = -1; //是否是从门禁：-1无，0主门禁，1从门禁
	union {
		char szMasterName[128];//主门禁名，不会重复
		char szSlaveName[128];//从门禁名
	}unMS;
	//UINT8 nApplyNum = -1;//刷卡人数
	UINT8 nCtrlLevel = -1;//管控等级
	char szPlaceName[64] = { 0 };//所在场所名称
	char szPartName[64] = { 0 };//所在部位名称

	//std::vector<int> vecAuthRelCameraID;//认证联动视频通道id，非是要单独一条消息过来
	std::vector<int> vecGrantRelCameraID;//授权联动视频通道id
	std::vector<int> vecAuthRelTalkID;//认证关联对讲设备id
};


/*区域、主机、前端设备信息
*/
//节点类型
enum emNodeType {
	AreaNode,
	HostNode,
	DeviceNode,
	emNodeTypeBuff
};
//就不该设计这些结构，直接用那详细的结构一样
//节点父类
struct stNode {
	unsigned short nID;//id
	std::string strCode;//编码
	std::string strFatherCode;//上一级编码
	std::string strName;//名字

	stNode(unsigned short id, std::string code, std::string fCode, std::string name)
		: nID(id), strCode(code), strFatherCode(fCode), strName(name) {}
};

struct stArea : stNode{
	std::string strContactManName;//联系人
	std::string strContactInfo;//联系方式
	
	stArea(unsigned short id, std::string code, std::string fCode, std::string name,
		std::string contactName, std::string contactInfo)
		: stNode(id, code, fCode, name), 
		strContactManName(contactName), strContactInfo(contactInfo){}
};

struct stHost : stNode {
	int nFactoryType;//厂家类型
	
	stHost(unsigned short id, std::string code, std::string fCode, std::string name,
		int factory)
		: stNode(id, code, fCode, name), nFactoryType(factory) {}
};

struct stDevice : stNode {
	unsigned short nChnlNo;//通道号
	std::string strHostCode;//所属主机编码

	stDevice(unsigned short id, std::string code, std::string fCode, std::string name,
		unsigned short chnlNo, std::string HCode) 
		: stNode(id,code,fCode,name), nChnlNo(chnlNo), strHostCode(HCode){}
};



/*申请人员信息
*/
struct stApplyPersonInfo {
	std::shared_ptr<stCtrlPersonInfo> stPersonInfo = 0;//申请人员信息
	UINT8 nCardType = 1;//卡的类别：即1-合法卡、2-无权限卡、3-非法卡 暂用后边 "0"--非法，"1"--合法，“2”--无权限
	CTime tmApply;//申请时间
};


/*申请信息
一个人一条申请信息，
多人模式下，同一个网点（场所），同一个部位代表同一个申请
*/
struct stApplyInfo {
	unsigned long nApplyID = 0;//申请id
	CString strWebSiteName;//申请网点（区域）
	CString strPartName;//申请部位
	int nImportance = -1;//重要程度（管控等级）
	int nDevID = -1;//刷卡设备
	CString strDevName;//刷卡设备名称
	UINT8 nLocal = -1;//是否本地认证：0本地，1远程
	UINT8 nSlave = -1;//是否主从门禁刷卡：-1无，0主，1从
	//CString strMode;//刷卡模式：(如:XX人刷卡+中心授权)
	CTime tmApply;//申请认证时间，CString不好转CTime
	emAuthState emState = Dealing;//认证状态
	//std::vector<std::tuple<>>//两路视频
	std::shared_ptr<stApplyPersonInfo> stPersonInfo;//申请人员信息
};



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
};


//lambda方法
//通过节点id查找节点
bool lambda_FindNodeByID(const std::shared_ptr<stNode>& st, const int id);
//通过节点名查找节点
bool lambda_FindNodeByName(const std::shared_ptr<stNode>& st, const CString& name);
//查找当前用户是否受理该门禁
bool lambda_FindDealHostByID(const USERDOORCAMERARELATION_CLIENT_GET_S& st, const int id);
//查找申请记录
bool lambda_FindApplyInfo(const std::shared_ptr<stApplyInfo>& stElm, const std::shared_ptr<stApplyInfo>& stDest);
//通过设备id查找主机信息
bool lambda_FindACSHostByDevNo(const std::pair<CString, std::shared_ptr<stACSHostInfo>>& p, const int nDevNo);
//通过卡号查找管辖人员
bool lambda_FindCtrlInfoByCardID(const std::shared_ptr<stCtrlPersonInfo>& st, const CString& chID);
//通过卡号查找申请信息
bool lambda_FindApplyInfoByCardID(const std::shared_ptr<stApplyInfo>& st, const CString& chID);
//查找记录的申请时间比哪条记录更早 或者找到一条空记录
bool lambda_InsertRecord(const std::shared_ptr<stApplyInfo>& sp, const std::shared_ptr<stApplyInfo>& st);
//排序申请记录，申请时间早的 > 空的
bool lambda_SortApplyVector(const std::shared_ptr<stApplyInfo>& sp1, const std::shared_ptr<stApplyInfo>& sp2);