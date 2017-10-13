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
/*申请认证人员信息
网点的名称、两路视频、申请认证人员信息（照片、单位、分类）及申请认证时间（年月日时分秒）
网络传输；支持本地存储；
*/
struct stApplyPersonInfo {
	CString strPic;//照片
	CString strName;//姓名
	CString strOffice;//单位
	CString strCategory;//分类

	stApplyPersonInfo(CString pic,
		CString name, CString office, CString cate)
		: strPic(pic), strName(name),
		strOffice(office), strCategory(cate) {}
};


/*申请信息
一个人一条申请信息
*/
//struct stApplyInfo {
//	CString strWebSiteName;//申请网点
//	int nImportance;//重要程度
//	CTime tmApply;//申请认证时间，CString不好转CTime
//	//两路视频
//	stApplyPersonInfo stPersonInfo;//申请人员信息（是一个人还是多个？）
//
//	stApplyInfo(CString wbName, int nImp, CTime tm, stApplyPersonInfo&& st)
//		: strWebSiteName(wbName), nImportance(nImp), tmApply(tm), 
//		stPersonInfo(st) {}
//};


/*申请信息
全部人一条申请信息
*/
struct stApplyInfo {
	CString strWebSiteName;//申请网点
	int nImportance;//重要程度，为0不管控
	CTime tmApply;//申请认证时间，CString不好转CTime
				  //两路视频
	//认证方式：远程认证、本地认证
	std::vector<stApplyPersonInfo> vecPersonInfo;//申请人员信息

	stApplyInfo(CString wbName, int nImp, CTime tm, std::vector<stApplyPersonInfo>&& vec)
		: strWebSiteName(wbName), nImportance(nImp), tmApply(tm),
		vecPersonInfo(vec) {}
};



/*预案信息
*/
//预案步骤
struct stEmergPlanStep {
	int nNo;//编号
	CString strName;//名称

	stEmergPlanStep(int n, CString name)
		: nNo(n), strName(name) {}
};
struct stEmergPlan {
	CString strPlanName;//预案名
	std::vector<stEmergPlanStep> vecStep;//预案步骤

	stEmergPlan(CString name, std::vector<stEmergPlanStep>&& vec)
		: strPlanName(name), vecStep(vec) {}
};




/*用户信息
基础信息、权限
*/
struct stUserInfo {
	S_New_UserInfo stBaseInfo;//基础
	T_OPENDOORPOSALINFO stDisposalInfo;//权限
};


/*管辖人员信息
*/
struct stControledPersonInfo {
	TAGDOAPERSONINFO_S stBaseInfo;//基础
	TCHAR szHeadPic[MAX_PATH] = { 0 };//头像全路径
};