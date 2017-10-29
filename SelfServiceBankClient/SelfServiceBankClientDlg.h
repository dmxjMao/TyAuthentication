
// SelfServiceBankClientDlg.h : header file
//

#pragma once
//#include "afxwin.h"

//class CLogDialog;

// CSelfServiceBankClientDlg dialog
class CMyStatic1;
class CMyListBox1;
struct stApplyInfo;
class CApplyRecordDlg;
struct T_TRANSMITALARMINFO;
class CStgOperator;

class CSelfServiceBankClientDlg : public CDialogEx, public CZCMsgObserver
{
// Construction
public:
	CSelfServiceBankClientDlg(CWnd* pParent = NULL);
	~CSelfServiceBankClientDlg();
	//�н鷽����ά�����ؼ�֮����߼�
	//�����࣬��ʾ�Ҳ�
	void DisplayDetail(const std::shared_ptr<stApplyInfo>& st);
	//�رռ�¼��ɾ����ߣ��ұ�
	void DeleteRecord(int idx);
	//ɾ������
	void RemoveApply(const std::shared_ptr<stApplyInfo>& st);

	//��Ϣ֪ͨ
	virtual void Update(bool, DWORD, DWORD, PBYTE, INT);
	//���������¼
	void MyInsertRecord(const std::shared_ptr<stApplyInfo>& st);
	


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELFSERVICEBANKCLIENT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CRect m_rcClient, m_rcCaption, m_rcList, m_rcRecord; //�ͻ��������������б�������¼��
	WORD m_dwApplyID = 0;//����id
	
	std::shared_ptr<CMyStatic1> m_oCloseWindow = 0;//�رհ�ť
	std::shared_ptr<CMyListBox1> m_oApplyList = 0;//�����б�
	//std::list<CApplyRecordDlg> m_liApplyRecordDlg; //�����¼��ϸ�Ի���
	std::vector<std::shared_ptr<CApplyRecordDlg>> m_vecApplyRecordDlg; //�����¼��ϸ�Ի���
	std::vector<std::shared_ptr<stApplyInfo>> m_vecApplyInfo;//����ˢ��������Ϣ
	//std::vector<tplMultiApplyInfo> m_vecMultiApplyInfo;//����ˢ����Ϣ

	std::shared_ptr<CLogDialog> m_oLogDlg = 0;//��־�Ի���
	std::shared_ptr<CStgOperator> m_oStg = 0;//�ṹ���洢

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	//afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	
	//�رմ���
	afx_msg void OnStnClickedClosewindow();
	//�϶�����
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
	//��ȡ��ʷ�����¼����ʾ
	void GetHistoryApplyAndDisplay();
	//����������Ϣ
	void InsertApplyInfo(const std::shared_ptr<stApplyInfo>&);
	
	//��ʼ��ZCMsgManager��Ϣ������
	void InitZCMsgHandler();
	std::map<DWORD, void(CSelfServiceBankClientDlg::*)(PBYTE, DWORD, INT)> m_mapZCMsgHandler;//ZCMsgManager��Ϣ������
	//ˢ����֤��Ϣ
	void ZCMsgAuthentication(PBYTE, DWORD, INT);
	//����ˢ����Ϣ
	//bool ZCMsgHelper_ParseMemo(CString&, std::vector<CString>&);
	//��������ʱ��
	CTime ZCMsgHelper_ParseTime(const char*);
	//�Ƿ�������
	bool IfDealTheApplyMsg(const CString& strCardNum/*, const CTime& tmApply*/);
	//������֤
	void LocalAuth(const T_TRANSMITALARMINFO&, const std::shared_ptr<stACSHostInfo>&);
	//Զ����֤
	void RemoteAuth(const T_TRANSMITALARMINFO&, const std::shared_ptr<stACSHostInfo>&);
	//����ˢ����Ϣ
	bool CreateApplyInfo(const T_TRANSMITALARMINFO&, const std::shared_ptr<stACSHostInfo>&, UINT8 nLocal);
	//����
	void ZCMsgOpenDoor(PBYTE, DWORD, INT);

#ifdef DEBUG

#endif // DEBUG

public:
//	CStatic m_oDemoVideo;
//demo��ȡ��Ƶ
	CStatic m_demoVideo;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDblclkDemovideo();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
