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


/*Ԥ����Ϣ
*/
//Ԥ������
struct stEmergPlanStep {
	int nNo;//���
	CString strName;//����

	stEmergPlanStep(int n, CString name)
		: nNo(n), strName(name) {}
};
//Ԥ����Ϣ
struct stEmergPlan {
	CString strPlanName;//Ԥ����
	std::vector<stEmergPlanStep> vecStep;//Ԥ������

	stEmergPlan(CString name, std::vector<stEmergPlanStep>&& vec)
		: strPlanName(name), vecStep(vec) {}
};




/*�û���Ϣ
*/
struct stUserInfo {
	S_New_UserInfo stBaseInfo;//������Ϣ
	T_OPENDOORPOSALINFO stDisposalInfo;//Ȩ��
};


/*��Ͻ��Ա��Ϣ
*/
struct stCtrlPersonInfo {
	TAGDOAPERSONINFO_S stBaseInfo;//������Ϣ
	TCHAR szHeadPic[MAX_PATH] = { 0 };//ͷ��ȫ·��
};


/*����������Ϣ
*/
struct stCtrlPlanInfo {
	UINT8 nAuthTimeLimit = 3;//��֤ʱ��
	UINT8 nAuthType = 1;//��֤��ʽ 1-Զ�̡�2-����
	UINT8 nDoor1Type = -1;//��֤ʶ��һ��ʽ  1-ָ�ơ�  2-ˢ��
	UINT8 nDoor1Num = 2;//ʶ��һ  ����
	UINT8 nDoor2Type = -1;//��֤ʶ���  1-ָ�ơ�  2-ˢ��
	UINT8 nDoor2Num = 0;//ʶ��� ����
	UINT8 nRecType = -1;//¼��ʽ 1-��ͨ����2-ȫͨ��
	UINT8 nPreRecTime = 30;//Ԥ¼ʱ��
	UINT8 nRecTime = 60;//¼��ʱ��
	UINT8 nCapType = -1;//ץͼ��ʽ  1-��ͨ����2-ȫͨ��
	UINT8 nCapDur = 5;//ץͼ���
	UINT8 nCapTime = 60;//ץͼʱ��
	int nEMPlanID = -1;//Ԥ��ID
	UINT8 bEMPlanStep = 2;//Ԥ������ִ��    1-��      2-��
	UINT8 nOpenGrantType = -1;//������Ȩ    1-ˢ��    2-����
	UINT8 nSuperGrantType = -1;//�ϼ���Ȩ    1-ˢ��    2-����
	//�Ű�˶�    1-��      2-��
	UINT8 bApproval = 2;//��������    1-��      2-��
	UINT8 bFCGrant = 2;//�׿���Ȩ    1-��      2-��
	
	TCHAR szEMPlanName[64] = { 0 }; //Ԥ������
};

/*�Ž�������Ϣ
*/
struct stACSHostInfo {
	TAGDOAACCESSINFO_S stBaseInfo;//������Ϣ����Ӧ���á��޸�..."
	UINT8 nCtrlLevel = -1;//�ܿصȼ�
	TCHAR szPlaceName[32] = { 0 };//���ڳ�������
	TCHAR szPartName[32] = { 0 };//���ڲ�λ����
};


/*������Ա��Ϣ
*/
struct stApplyPersonInfo {
	std::shared_ptr<stCtrlPersonInfo> stPersonInfo = 0;//������Ա��Ϣ
	UINT8 nCardType = 1;//������𣺼�1-�Ϸ�����2-��Ȩ�޿���3-�Ƿ���

};


/*������Ϣ
һ����һ��������Ϣ
*/
struct stApplyInfo {
	CString strWebSiteName;//��������
	int nImportance = -1;//��Ҫ�̶ȣ��ܿصȼ���
	CString strMode;//ˢ��ģʽ��(��:XX��ˢ��+������Ȩ)
	CTime tmApply;//������֤ʱ�䣬CString����תCTime
	//��·��Ƶ
	//stApplyPersonInfo stPersonInfo;//������Ա��Ϣ
	std::shared_ptr<stApplyPersonInfo> stPersonInfo = 0;//������Ա��Ϣ

	//stApplyInfo(){}
	//stApplyInfo(CString wbName, int nImp, CTime tm, stApplyPersonInfo&& st)
	//	: strWebSiteName(wbName), nImportance(nImp), tmApply(tm), 
	//	stPersonInfo(st) {}
};


/*������Ϣ
ȫ����һ��������Ϣ
*/
//struct stApplyInfo {
//
//	CString strWebSiteName;//��������
//	int nImportance;//��Ҫ�̶ȣ�Ϊ0���ܿ�
//	CTime tmApply;//������֤ʱ�䣬CString����תCTime
//				  //��·��Ƶ
//	//��֤��ʽ��Զ����֤��������֤
//	std::vector<stApplyPersonInfo> vecPersonInfo;//������Ա��Ϣ
//
//	stApplyInfo(CString wbName, int nImp, CTime tm, std::vector<stApplyPersonInfo>&& vec)
//		: strWebSiteName(wbName), nImportance(nImp), tmApply(tm),
//		vecPersonInfo(vec) {}
//};