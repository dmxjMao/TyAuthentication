#pragma once
#include "ConnectAppProtocol.h"
#include "ZCProtocol.h"

/*��������*/

//ZCMsg��Ϣͷ��С
#define ZCMsgHeaderLen sizeof(ZC_MSG_RESP_RESULT)
//��Ϣ������������ȡ��
#define ZCMsgMacro_beginfor(T, pMsg, nMsgLen)	\
const int nStructLen = sizeof(T);	\
int iCount = (nMsgLen - ZCMsgHeaderLen) / nStructLen;	\
for (int i = 0; i < iCount; ++i) {	\
	//T* pInfo = (T*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);	

#define ZCMsgMacro_endfor	}

/*���������
������ɫ
����߶�
*/
const Color cstClrTitle = Color(54, 132, 215);
const int cstnTitleHeight = 30;


//Ĭ������  ���ɹ�����ΪGDI+��û�г�ʼ������Ȼ��ȫ�ֱ�����Ϊʲô���������
//const FontFamily cstFontFamily(_T("΢���ź�"));
//const Gdiplus::Font cstFont(&cstFontFamily, 12, FontStyleRegular, UnitPixel);
//const SolidBrush cstSolidBrushText(Color(125, 125, 125));


/*
��ťö��
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


/*�ṹ��
*/
/*������֤��Ա��Ϣ
��������ơ���·��Ƶ��������֤��Ա��Ϣ����Ƭ����λ�����ࣩ��������֤ʱ�䣨������ʱ���룩
���紫�䣻֧�ֱ��ش洢��
*/
struct stApplyPersonInfo {
	CString strPic;//��Ƭ
	CString strName;//����
	CString strOffice;//��λ
	CString strCategory;//����

	stApplyPersonInfo(CString pic,
		CString name, CString office, CString cate)
		: strPic(pic), strName(name),
		strOffice(office), strCategory(cate) {}
};


/*������Ϣ
һ����һ��������Ϣ
*/
//struct stApplyInfo {
//	CString strWebSiteName;//��������
//	int nImportance;//��Ҫ�̶�
//	CTime tmApply;//������֤ʱ�䣬CString����תCTime
//	//��·��Ƶ
//	stApplyPersonInfo stPersonInfo;//������Ա��Ϣ����һ���˻��Ƕ������
//
//	stApplyInfo(CString wbName, int nImp, CTime tm, stApplyPersonInfo&& st)
//		: strWebSiteName(wbName), nImportance(nImp), tmApply(tm), 
//		stPersonInfo(st) {}
//};


/*������Ϣ
ȫ����һ��������Ϣ
*/
struct stApplyInfo {
	CString strWebSiteName;//��������
	int nImportance;//��Ҫ�̶ȣ�Ϊ0���ܿ�
	CTime tmApply;//������֤ʱ�䣬CString����תCTime
				  //��·��Ƶ
	//��֤��ʽ��Զ����֤��������֤
	std::vector<stApplyPersonInfo> vecPersonInfo;//������Ա��Ϣ

	stApplyInfo(CString wbName, int nImp, CTime tm, std::vector<stApplyPersonInfo>&& vec)
		: strWebSiteName(wbName), nImportance(nImp), tmApply(tm),
		vecPersonInfo(vec) {}
};



/*Ԥ����Ϣ
*/
//Ԥ������
struct stEmergPlanStep {
	int nNo;//���
	CString strName;//����

	stEmergPlanStep(int n, CString name)
		: nNo(n), strName(name) {}
};
struct stEmergPlan {
	CString strPlanName;//Ԥ����
	std::vector<stEmergPlanStep> vecStep;//Ԥ������

	stEmergPlan(CString name, std::vector<stEmergPlanStep>&& vec)
		: strPlanName(name), vecStep(vec) {}
};




/*�û���Ϣ
������Ϣ��Ȩ��
*/
struct stUserInfo {
	S_New_UserInfo stBaseInfo;//����
	T_OPENDOORPOSALINFO stDisposalInfo;//Ȩ��
};


/*��Ͻ��Ա��Ϣ
*/
struct stControledPersonInfo {
	TAGDOAPERSONINFO_S stBaseInfo;//����
	TCHAR szHeadPic[MAX_PATH] = { 0 };//ͷ��ȫ·��
};