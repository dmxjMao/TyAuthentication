#pragma once

/*�ṹ���洢

��¼��־
�����ͣ�1��������֤��¼ ��������2���ɱ�����3����������

���ṹͼ
			root@(0)
		/			\
	������~		�����¼��~

*/


//������
enum StgStreamType {
	StgAssist,//������
	StgApply,//�����¼
	StgStreamTypeBuff
};

//���ࣺ��д
struct StgBase{
	virtual void Read(LPSTREAM) = 0;
	virtual void Write(LPSTREAM) = 0;
};

//���ù���
struct stStgAction : StgBase {
	TCHAR szActType[32];//<��������
	char chActDate[32];//<����ʱ��
	TCHAR chActPerson[32];//<������
	
	void Read(LPSTREAM);
	void Write(LPSTREAM);
};

//�����¼����
struct stStgApplyIndex : StgBase {
	int nApplyID = 0;//����id
	int nPos = 0;//�����е���ʵλ��
	int nSize = 0;//��¼��С

	void Read(LPSTREAM);
	void Write(LPSTREAM);
};

//���ṹ��������Ϣ
struct stStgAssist : StgBase {
	unsigned long nCurApplyID = 0;//��ǰ����id

	stStgApplyIndex* pIndex = 0;
	int nIndexCnt = 0;

	void Read(LPSTREAM);
	void Write(LPSTREAM);
};

//���ṹ��������־
struct stStgApplyLog : StgBase{
	//������Ϣ
	unsigned long nApplyID = -1;//����id
	TCHAR szDevName[32] = { 0 };//�豸��
	TCHAR szAreaName[32] = { 0 };//����������
	TCHAR szPartName[32] = { 0 };//���ڲ�λ��
	TCHAR szContactManName[64] = { 0 };//��ϵ����
	TCHAR szApplyTime[32] = { 0 };//<����ʱ��
	TCHAR szContactInfo[16] = { 0 };//<��ϵ��ʽ
	TCHAR szPlanName[64] = { 0 };//<Ԥ������
	UINT8 nMethod = -1;//<���÷�ʽ -1-δ����  0-���� 1-������Ȩ 2-Ӧ������  3-�������� 4-�ܾ�����
	UINT8 nProcessType = -1;//<���״̬	1-ͨ�� 2-�ܾ�
	UINT8 nProcessStatus = 1;//<��֤״ֵ̬ 1-δ���� 2-������ 3-����� 4-�Ѵ��� 5-��ʧЧ
	//int nIsCollection;//<�Ƿ��ղ� 1-�ղ� 0-��
	UINT8 nPassStatus;//<ͨ�����	1-ͬ�⿪�� 2-�ܾ�����
	//int nIsNormal; //<�Ƿ���������
	TCHAR szHandleMan[32] = { 0 };//<������
	TCHAR szApplyType[32] = { 0 };//<��֤ģʽ
	//TCHAR chDoorGUID[64] = { 0 };//<��֤GUID

	//���ù���
	//ִ��Ԥ����������Ȩ + ����/����/�������ܾ����š�����
	stStgAction* pAction = 0;
	UINT8 nActionNum = 0;
	//

	void Read(LPSTREAM);
	void Write(LPSTREAM);
};

//Stg������
struct stApplyInfo;

class CStgOperator {
public:
	//
	struct StreamNode {//stream�ڵ�����
		StgStreamType em;//������
		CString name;//������
		//StgBase* cfg;//����

		StreamNode(StgStreamType e, CString nm)
			: em(e), name(nm){}
	};
	
	enum LogType { Write, Update, LogTypeBuff }; //�������ͣ�д������

	//��stg
	CStgOperator();
	//�ر�stg
	~CStgOperator();
	
	//����ͻ��Ľӿ�
	//��ȡ����id
	unsigned long GetApplyID();
	//��ȡ���n�������¼
	bool GetRecentNRecord(const int nCnt, std::vector<stApplyInfo>&);
	//д��������־
	void WriteApplyLog(const std::shared_ptr<stApplyInfo>&, bool bResumeOrDo = true);
	//�޸�������־
	void ModifyApplyLog(const std::shared_ptr<stApplyInfo>&/*��Ա����ֵ*/, bool bResumeOrDo = true);
	//�ϴ���־��db�����ˡ�ֵ�೤�鿴��������
	bool UploadApplyLog();

private:
	//����̳й�ϵ
	//void TransformBase2Derived(StreamNode& node, void*& pv, ULONG& len);
	//����Ĭ�Ͻṹ
	bool CreateDefaultStg();

	//����ͻ��Ľӿ�
	

public:
	LogType m_emLogType = LogTypeBuff;//��������
	std::shared_ptr<stApplyInfo> m_pCurApplyInfo = 0;//��ǰ�����¼
	CWinThread* m_pThread = 0; //CWinThread��Աm_autodelete����

private:
	bool m_bOpen = false;
	LPSTORAGE m_pRootStg = 0;	
	DWORD m_mode = STGM_READWRITE | STGM_SHARE_EXCLUSIVE;
};