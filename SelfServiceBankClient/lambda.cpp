#include "stdafx.h"
#include "MyCommonDefine.h"

using std::shared_ptr;

//ͨ��id���ҽڵ�
bool lambda_FindNodeByID(const shared_ptr<stNode>& st, const int id) {
	return st->nID == id;
}

//ͨ���ڵ������ҽڵ�
bool lambda_FindNodeByName(const std::shared_ptr<stNode>& st, const CString& name) {
	return CString(st->strName.c_str()) == name;
}

//���ҵ�ǰ�û��Ƿ�������Ž�
bool lambda_FindDealHostByID(const USERDOORCAMERARELATION_CLIENT_GET_S& st, const int id) {
	return st.nDoorId == id;
}

//���������¼
bool lambda_FindApplyInfo(const shared_ptr<stApplyInfo>& stElm, const shared_ptr<stApplyInfo>& stDest) {
	return stElm == stDest;
}

//ͨ���豸id����������Ϣ
bool lambda_FindACSHostByDevNo(const std::pair<CString, shared_ptr<stACSHostInfo>>& p, const int nDevNo) {
	return p.second->stBaseInfo.nID == nDevNo;
}

//ͨ�����Ų��ҹ�Ͻ��Ա
bool lambda_FindCtrlInfoByCardID(const shared_ptr<stCtrlPersonInfo>& st, const CString& chID) {
	return CString(st->stBaseInfo.chCardNum) == chID;
}

//ͨ�����Ų���������Ϣ
bool lambda_FindApplyInfoByCardID(const shared_ptr<stApplyInfo>& st, const CString& chID) {
	return CString(st->stPersonInfo->stPersonInfo->stBaseInfo.chCardNum) == chID;
}

//���Ҽ�¼������ʱ���������¼���� �����ҵ�һ���ռ�¼
bool lambda_InsertRecord(const shared_ptr<stApplyInfo>& sp, const shared_ptr<stApplyInfo>& st){
	return nullptr == sp || st->tmApply < sp->tmApply;
}

//���������¼������ʱ����� > �յ�
bool lambda_SortApplyVector(const std::shared_ptr<stApplyInfo>& sp1,
	const std::shared_ptr<stApplyInfo>& sp2)
{
	if (sp1 && !sp2)
		return true;
	if (!sp1 && !sp2 || !sp1 && sp2)
		return false;

	return sp1->tmApply < sp2->tmApply;
}