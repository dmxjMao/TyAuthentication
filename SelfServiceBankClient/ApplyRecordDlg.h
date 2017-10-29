#pragma once

// CApplyRecordDlg dialog
enum emButton;
struct stApplyInfo;
class CMyListCtrl1;
class CMyStatic1;
class CMyStatic2;
//class CApplyState;//����״̬
class CSelfServiceBankClientDlg;//�н�
class CStgOperator;//�ṹ���洢

//��Ƶ��Ϣ
struct stVideoInfo {
	//ENUM_PlayType emFactoryType;//���ұ��
	int nFactoryType;//���ұ��
	CStatic* pWnd = 0;//���Ŵ���
	long nPlayID = -1;//���ž��
	int nLinkType = 1;//ֱ��/ת��
	UINT8 nWndNo = 1;//���Ŵ��ں�

	int nDevID = -1;//̽ͷ�����豸id
	int nChnlNo = -1;//ͨ����
};

class CApplyRecordDlg : public CDialogEx/*, public CZCMsgObserver*/
{
	DECLARE_DYNAMIC(CApplyRecordDlg)
	friend class CSelfServiceBankClientDlg;
public:
	CApplyRecordDlg(int nIdx, CSelfServiceBankClientDlg* pDlg,
		std::shared_ptr<CStgOperator>& pStg, CWnd* pParent = NULL);   // standard constructor
	//CApplyRecordDlg(const CApplyRecordDlg&) {} //vector<CApplyRecordDlg>��Ҫ
	virtual ~CApplyRecordDlg();
	//��Ϣ֪ͨ
	//virtual void Update(bool, DWORD, DWORD, PBYTE, INT);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ApplyRecordDlg };
#endif

protected:
	CRect m_rcInParent, m_rcClient/*, m_rcPerson*/;//�ڸ������е��������ꡢ�ͻ�����
	
	std::shared_ptr<stApplyInfo> m_stApplyInfo = 0;//��������
	//std::vector<stApplyPersonInfo> m_vecStPersonInfo;//������֤��Ա��Ϣ
	//std::shared_ptr<CApplyState> m_pState = 0; //����״̬
	//std::map<DWORD, void(CApplyRecordDlg::*)(PBYTE, DWORD, INT)> m_mapZCMsgHandler;//ZCMsgManager��Ϣ������
	//�н��ߣ����ӵĿؼ�ͨ���߼������н�
	//����ʵ�֣�1��Observer��2��ֱ���ṩ�ӿڣ�
	CSelfServiceBankClientDlg* m_oMediator;
	std::shared_ptr<CStgOperator>& m_oStg;

	CStatic m_oVideo1;//��Ƶ
	CStatic m_oVideo2;

	std::shared_ptr<CMyListCtrl1> m_oPersonInfo = 0;  //������֤��Ա��Ϣ

	std::shared_ptr<CMyStatic1> m_oPicDoor = 0;//��

	std::shared_ptr<CMyStatic2> m_oEmergency = 0;//Ӧ������
	std::shared_ptr<CMyStatic2> m_oGrant = 0;//������Ȩ
	std::shared_ptr<CMyStatic2> m_oOpen = 0;//����
	std::shared_ptr<CMyStatic2> m_oEnterMapLayer = 0;//����ͼ��
	std::shared_ptr<CMyStatic2> m_oLock = 0;//����
	std::shared_ptr<CMyStatic2> m_oRefuseOpen = 0;//�ܾ�����
	std::shared_ptr<CMyStatic2> m_oConfirm = 0;//ȷ�ϲ��ر�

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedEmergency();

public:
	//��ȡ��Աm_stApplyInfo
	inline const std::shared_ptr<stApplyInfo>& GetApplyInfo() const { return m_stApplyInfo; }
	void SetApplyInfo(const std::shared_ptr<stApplyInfo>& st, bool bAdd = false);
	//���öԻ����ڸ������е�������ΪCreate->OnInitDialog->SetWindowPos
	inline void SetRectInParent(const CRect& rc) { m_rcInParent = rc; }
	//ˢ����ʾ
	void Update();
	//�һ�/���ô����пո�Ϊ��ť����ΪCStatic�Ŀ������ػ��
	void EnableButton(std::vector<emButton> em, bool b);
	//������Ƶ
	void ReqVideo();
	//ֹͣԤ����Ƶ
	void StopVideo();

public:
	std::vector<stVideoInfo> m_vecVideoInfo;//��Ƶ��Ϣ
	int m_nIdx;//�ڸ������е�����
	afx_msg void OnDblclkVideo1();
	afx_msg void OnStnClickedEntermaplayer();
	afx_msg void OnStnClickedOpen();

private:
	//ʧЧ�ж�
	bool IsInvalid();
	//ʧЧ����
	void DoInvalid();
	//Զ����֤��֧
	void RemoteAuth();
	//������֤��֧
	void LocalAuth();

public:
	afx_msg void OnStnClickedLock();
	afx_msg void OnStnClickedRefuseopen();
	afx_msg void OnStnClickedConfirm();
	afx_msg void OnStnClickedGrant();
};
