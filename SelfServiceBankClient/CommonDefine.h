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

/*界面标题栏
标题颜色
标题高度
*/
const Color cstClrTitle = Color(54, 132, 215);
const int cstnTitleHeight = 30;


//默认字体  不成功，因为GDI+还没有初始化，既然是全局变量，为什么不放在类里？
//const FontFamily cstFontFamily(_T("微软雅黑"));
//const Gdiplus::Font cstFont(&cstFontFamily, 12, FontStyleRegular, UnitPixel);
//const SolidBrush cstSolidBrushText(Color(125, 125, 125));


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
	int nNo;//编号
	CString strName;//名称

	stEmergPlanStep(int n, CString name)
		: nNo(n), strName(name) {}
};
//预案信息
struct stEmergPlan {
	CString strPlanName;//预案名
	std::vector<stEmergPlanStep> vecStep;//预案步骤

	stEmergPlan(CString name, std::vector<stEmergPlanStep>&& vec)
		: strPlanName(name), vecStep(vec) {}
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
	UINT8 nDoor1Type = -1;//认证识别一方式  1-指纹、  2-刷卡
	UINT8 nDoor1Num = 2;//识别一  人数
	UINT8 nDoor2Type = -1;//认证识别二  1-指纹、  2-刷卡
	UINT8 nDoor2Num = 0;//识别二 人数
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
	
	TCHAR szEMPlanName[64] = { 0 }; //预案名称
};

/*门禁主机信息
*/
struct stACSHostInfo {
	TAGDOAACCESSINFO_S stBaseInfo;//基础信息，对应配置“修改..."
	UINT8 nCtrlLevel = -1;//管控等级
	TCHAR szPlaceName[32] = { 0 };//所在场所名称
	TCHAR szPartName[32] = { 0 };//所在部位名称
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


/*申请信息
全部人一条申请信息
*/
//struct stApplyInfo {
//
//	CString strWebSiteName;//申请网点
//	int nImportance;//重要程度，为0不管控
//	CTime tmApply;//申请认证时间，CString不好转CTime
//				  //两路视频
//	//认证方式：远程认证、本地认证
//	std::vector<stApplyPersonInfo> vecPersonInfo;//申请人员信息
//
//	stApplyInfo(CString wbName, int nImp, CTime tm, std::vector<stApplyPersonInfo>&& vec)
//		: strWebSiteName(wbName), nImportance(nImp), tmApply(tm),
//		vecPersonInfo(vec) {}
//};