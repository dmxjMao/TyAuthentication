#include "stdafx.h"
#include "MyCommonDefine.h"

using std::shared_ptr;

//通过id查找节点
bool lambda_FindNodeByID(const shared_ptr<stNode>& st, const int id) {
	return st->nID == id;
}

//通过节点名查找节点
bool lambda_FindNodeByName(const std::shared_ptr<stNode>& st, const CString& name) {
	return CString(st->strName.c_str()) == name;
}

//查找当前用户是否受理该门禁
bool lambda_FindDealHostByID(const USERDOORCAMERARELATION_CLIENT_GET_S& st, const int id) {
	return st.nDoorId == id;
}

//查找申请记录
bool lambda_FindApplyInfo(const shared_ptr<stApplyInfo>& stElm, const shared_ptr<stApplyInfo>& stDest) {
	return stElm == stDest;
}

//通过设备id查找主机信息
bool lambda_FindACSHostByDevNo(const std::pair<CString, shared_ptr<stACSHostInfo>>& p, const int nDevNo) {
	return p.second->stBaseInfo.nID == nDevNo;
}

//通过卡号查找管辖人员
bool lambda_FindCtrlInfoByCardID(const shared_ptr<stCtrlPersonInfo>& st, const CString& chID) {
	return CString(st->stBaseInfo.chCardNum) == chID;
}

//通过卡号查找申请信息
bool lambda_FindApplyInfoByCardID(const shared_ptr<stApplyInfo>& st, const CString& chID) {
	return CString(st->stPersonInfo->stPersonInfo->stBaseInfo.chCardNum) == chID;
}

//查找记录的申请时间比哪条记录更早 或者找到一条空记录
bool lambda_InsertRecord(const shared_ptr<stApplyInfo>& sp, const shared_ptr<stApplyInfo>& st){
	return nullptr == sp || st->tmApply < sp->tmApply;
}

//排序申请记录，申请时间早的 > 空的
bool lambda_SortApplyVector(const std::shared_ptr<stApplyInfo>& sp1,
	const std::shared_ptr<stApplyInfo>& sp2)
{
	if (sp1 && !sp2)
		return true;
	if (!sp1 && !sp2 || !sp1 && sp2)
		return false;

	return sp1->tmApply < sp2->tmApply;
}