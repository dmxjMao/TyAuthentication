#pragma once


/*公共定义*/


/*界面标题栏
颜色
高度
*/
const Color cstClrTitle = Color(54, 132, 215);
const int cstnTitleHeight = 25;




/*结构体
*/
/*申请认证人员信息
网点的名称、两路视频、申请认证人员信息（照片、单位、分类）及申请认证时间（年月日时分秒）
网络传输；支持本地存储；
*/
struct stApplyPersonInfo {
	//不属于人员信息，放入CApplyRecordDlg
	//CString strWebSiteName;//网点名称
	//std::vector<CString> vecVideoStr;//视频
	CString strPic;//照片
	CString strOffice;//单位
	CString strCategory;//分类
	CTime tmApply;//申请认证时间，CString不好转CTime

	stApplyPersonInfo(/*CString wsName, std::vector<CString> vec, */CString pic,
		CString office, CString cate, CTime tm) 
		: /*strWebSiteName(wsName), vecVideoStr(vec), */strPic(pic), 
		strOffice(office), strCategory(cate), tmApply(tm) {}
};

