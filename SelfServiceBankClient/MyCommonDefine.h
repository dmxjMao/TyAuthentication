#pragma once
#include "ConnectAppProtocol.h"
#include "ZCProtocol.h"

/*��������*/

//ZCMsg��Ϣͷ��С
#define ZCMsgHeaderLen sizeof(ZC_MSG_RESP_RESULT)

//��Ϣ��������������ȡ��
#define ZCMsgMacro_beginfor(T, pMsg, nMsgLen)	\
const int nStructLen = sizeof(T);	\
int iCount = (nMsgLen - ZCMsgHeaderLen) / nStructLen;	\
for (int i = 0; i < iCount; ++i) {	\
	//T* pInfo = (T*)(&pMsg[ZCMsgHeaderLen + i * nStructLen]);	

#define ZCMsgMacro_endfor	}


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
	UINT8 nDoor1Type = 2;//��֤ʶ��һ��ʽ  1-ָ�ơ�  2-ˢ��
	UINT8 nDoor1Num = 1;//ʶ��һ  ����
	UINT8 nDoor2Type = 2;//��֤ʶ���  1-ָ�ơ�  2-ˢ��
	UINT8 nDoor2Num = 1;//ʶ��� ����
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
	
	char szEMPlanName[128] = { 0 }; //Ԥ������
};

/*�Ž�������Ϣ
*/
struct stACSHostInfo {
	TAGDOAACCESSINFO_S stBaseInfo;//������Ϣ����Ӧ���á��޸�..."
	UINT8 nSlave = -1; //�Ƿ��Ǵ��Ž���-1�ޣ�0���Ž���1���Ž�
	union {
		char szMasterName[128];//���Ž����������ظ�
		char szSlaveName[128];//���Ž���
	}unMS;
	//UINT8 nApplyNum = -1;//ˢ������
	UINT8 nCtrlLevel = -1;//�ܿصȼ�
	char szPlaceName[64] = { 0 };//���ڳ�������
	char szPartName[64] = { 0 };//���ڲ�λ����
	std::vector<int> vecRelChnl;//������Ƶͨ��id
	std::vector<int> vecRelTalk;//�����Խ��豸id
};


/*����������ǰ���豸��Ϣ
*/
//�ڵ�����
enum emNodeType {
	AreaNode,
	HostNode,
	DeviceNode,
	emNodeTypeBuff
};
//�ڵ㸸��
struct stNode {
	unsigned short nID;//id
	std::string strCode;//����
	std::string strFatherCode;//��һ������
	std::string strName;//����

	stNode(unsigned short id, std::string code, std::string fCode, std::string name)
		: nID(id), strCode(code), strFatherCode(fCode), strName(name) {}
};

struct stArea : stNode{
	stArea(unsigned short id, std::string code, std::string fCode, std::string name)
		: stNode(id, code, fCode, name) {}
};

struct stHost : stNode {
	stHost(unsigned short id, std::string code, std::string fCode, std::string name)
		: stNode(id, code, fCode, name) {}
};

struct stDevice : stNode {
	unsigned short nChnlNo;//ͨ����
	std::string strFatherName;//����������

	stDevice(unsigned short id, std::string code, std::string fCode, std::string name,
		unsigned short chnlNo, std::string fName) 
		: stNode(id,code,fCode,name), nChnlNo(chnlNo), strFatherName(fName){}
};



/*������Ա��Ϣ
*/
struct stApplyPersonInfo {
	std::shared_ptr<stCtrlPersonInfo> stPersonInfo = 0;//������Ա��Ϣ
	UINT8 nCardType = 1;//������𣺼�1-�Ϸ�����2-��Ȩ�޿���3-�Ƿ��� ���ú�� "0"--�Ƿ���"1"--�Ϸ�����2��--��Ȩ��
	CTime tmApply;//����ʱ��
};


/*������Ϣ
һ����һ��������Ϣ��
����ģʽ�£�ͬһ�����㣨��������ͬһ����λ����ͬһ������
*/
struct stApplyInfo {
	CString strWebSiteName;//��������
	CString strPartName;//���벿λ
	int nImportance = -1;//��Ҫ�̶ȣ��ܿصȼ���
	UINT8 nSlave = -1;//�Ƿ������Ž�ˢ����-1�ޣ�0����1��
	//CString strMode;//ˢ��ģʽ��(��:XX��ˢ��+������Ȩ)
	CTime tmApply;//������֤ʱ�䣬CString����תCTime
	//��·��Ƶ
	//stApplyPersonInfo stPersonInfo;//������Ա��Ϣ
	//std::vector<std::shared_ptr<stApplyPersonInfo>> vecPersonInfo;//������Ա��Ϣ
	std::shared_ptr<stApplyPersonInfo> stPersonInfo;//������Ա��Ϣ
};



/*Ԥ����Ϣ
*/
//Ԥ������
struct stEmergPlanStep {
	int nNo = -1;//���
	bool bMustDo = false;//�Ƿ����ִ��
	CString strName;//����

	stEmergPlanStep(int no, bool bDo, CString name)
		: nNo(no), bMustDo(bDo), strName(name) {}
};
//Ԥ����Ϣ
struct stEmergPlan {
	int nPlanID;//Ԥ��ID
	CString strPlanName;//Ԥ������
	CString strCreateMan;//������
	std::vector<stEmergPlanStep> vecStep;//Ԥ������
};

