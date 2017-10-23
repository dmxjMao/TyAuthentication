#pragma once

// CApplyRecordDlg dialog
enum emButton;
struct stApplyInfo;
class CMyListCtrl1;
class CMyStatic1;
class CMyStatic2;

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

class CApplyRecordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CApplyRecordDlg)

public:
	CApplyRecordDlg(CWnd* pParent = NULL);   // standard constructor
	//CApplyRecordDlg(const CApplyRecordDlg&) {} //vector<CApplyRecordDlg>��Ҫ
	virtual ~CApplyRecordDlg();


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ApplyRecordDlg };
#endif

protected:
	CRect m_rcInParent, m_rcClient/*, m_rcPerson*/;//�ڸ������е��������ꡢ�ͻ�����
	//������������
	std::shared_ptr<stApplyInfo> m_stApplyInfo = nullptr;
	//std::vector<stApplyPersonInfo> m_vecStPersonInfo;//������֤��Ա��Ϣ

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
	inline const std::shared_ptr<stApplyInfo>& 
		GetApplyInfo() const { return m_stApplyInfo; }
	void SetApplyInfo(const std::shared_ptr<stApplyInfo>& st, bool bAdd = false);
	//���öԻ����ڸ������е�������ΪCreate->OnInitDialog->SetWindowPos
	inline void SetRectInParent(const CRect& rc) { m_rcInParent = rc; }
	//ˢ����ʾ
	void Update();
	//��ť�һ�/���ô�����Ϊ��ť
	void EnableButton(std::vector<emButton> em, bool b);
	//������Ƶ
	bool ReqVideo();

public:
	std::vector<stVideoInfo> m_vecVideoInfo;//��Ƶ��Ϣ
	afx_msg void OnDblclkVideo1();
};
