#pragma once

/*�ṹ���洢

��¼��־
�����ͣ�1��������֤��¼ ��������2���ɱ�����3����������

���ṹͼ
			root@(0)
		/			\
	������~		�����¼��N~

*/

//����
struct StgBase{
	virtual bool Read(LPSTREAM) = 0;
	virtual bool Write(LPSTREAM) = 0;
};



//���ṹ��������Ϣ
struct stStgAssist : StgBase {
	WORD nCurApplyID = 0;//��ǰ����id
	WORD nUploadID = 0;//��һ���ϴ���id

	bool Read(LPSTREAM);
	bool Write(LPSTREAM);
};

//���ṹ�����ö���
struct stStgAction : StgBase {
	TCHAR szActType[32] = { 0 };//<��������
	TCHAR szActDate[32] = { 0 };//<����ʱ��
	TCHAR szActPerson[32] = { 0 };//<������

	stStgAction() {}
	stStgAction(const TCHAR* ActName, const TCHAR* ActDate, const TCHAR* ActMan) {
		//memcpy_s(szActType, _countof(szActType), ActName, _TRUNCATE); //����
		memcpy_s(szActType, _countof(szActType), ActName, _countof(szActType));
		memcpy_s(szActDate, _countof(szActDate), ActDate, _countof(szActDate));
		memcpy_s(szActPerson, _countof(szActPerson), ActMan, _countof(szActPerson));
	}

	bool Read(LPSTREAM);
	bool Write(LPSTREAM);
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

	//���ö���
	//ִ��Ԥ����������Ȩ + ����/����/�������ܾ����š�����
	stStgAction* pAction = 0;
	UINT8 nActionNum = 0;
	//

	bool Read(LPSTREAM);
	bool Write(LPSTREAM);
};

//Stg������
struct stApplyInfo;

class CStgOperator {
public:
	
	enum LogType { Write, Update, LogTypeBuff }; //�������ͣ�д������

	//��stg
	CStgOperator();
	//�ر�stg
	~CStgOperator();
	
	//����ͻ��Ľӿ�
	//��ȡ����id
	WORD GetApplyID();
	//��ȡ�����¼
	bool GetApplyRecord(const WORD, std::shared_ptr<stApplyInfo>&);
	//��ȡ���n�������¼
	//bool GetRecentNRecord(const int nCnt, std::vector<stApplyInfo>&);
	//д��������־
	void WriteApplyLog(const std::shared_ptr<stApplyInfo>&, bool bResumeOrDo = true);
	//������봦�ö�����־
	void AddApplyActionLog(const WORD, const TCHAR*, bool bResumeOrDo = true);
	//�ϴ���־��db�����ˡ�ֵ�೤�鿴��������
	bool UploadApplyLog(bool bClear = false);

private:
	//����Ĭ�Ͻṹ
	bool CreateDefaultStg();
	//����־��
	bool OpenLogStream(LPSTREAM& pAssist, const WORD id, LPSTREAM& pRecord);
	//����������־�ṹ
	void SetLogStruct(const std::shared_ptr<stApplyInfo>& sp, stStgApplyLog& stLog);

public:
	//�߳�ʹ��
	LogType m_emLogType = LogTypeBuff;//��������
	//emStgActionType m_emCurAction = StgActionTypeBuff;//��ǰҪ��¼�Ķ�������
	CString m_strCurAction;//��ǰ������
	WORD m_dwCurApplyID = 0;//��ǰҪ���������id
	std::shared_ptr<stApplyInfo> m_pCurApplyInfo = 0;//��ǰ�����¼
	CWinThread* m_pThread = 0; //CWinThread��Աm_autodelete����

private:
	bool m_bOpen = false;
	LPSTORAGE m_pRootStg = 0;	
	DWORD m_mode = STGM_READWRITE | STGM_SHARE_EXCLUSIVE;
};