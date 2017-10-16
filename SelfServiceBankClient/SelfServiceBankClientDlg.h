
// SelfServiceBankClientDlg.h : header file
//

#pragma once
#include "MyStatic1.h"
//#include "MyListCtrl1.h"
#include "MyListBox1.h"
#include "ApplyRecordDlg.h"

//class CLogDialog;

// CSelfServiceBankClientDlg dialog
#ifdef _DEBUG
class CMyButton1;
#endif
class CSelfServiceBankClientDlg : public CDialogEx, public CZCMsgObserver
{
// Construction
public:
	CSelfServiceBankClientDlg(CWnd* pParent = NULL);
	//�н鷽��
	//�����࣬��ʾ�Ҳ�
	void DisplayDetail(const std::shared_ptr<stApplyInfo>& st);
	//��Ϣ֪ͨ
	virtual void Update(bool, DWORD, DWORD, PBYTE, INT);
	//ˢ����֤��Ϣ
	
	//���������¼
	void MyInsertRecord(const std::shared_ptr<stApplyInfo>& st);
	//������Ȩ�ظ��������ţ���־


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
	CMyStatic1 m_oCloseWindow;//�رհ�ť
	
#ifdef DEBUG
	std::shared_ptr<CMyButton1> btn1;
#endif // DEBUG

	CMyListBox1 m_oApplyList;//�����б�
	//std::list<CApplyRecordDlg> m_liApplyRecordDlg; //�����¼��ϸ�Ի���
	std::vector<CApplyRecordDlg> m_vecApplyRecordDlg; //�����¼��ϸ�Ի���
	std::vector<std::shared_ptr<stApplyInfo>> m_vecApplyInfo;//������Ϣ

	std::shared_ptr<CLogDialog> m_oLogDlg = 0;//��־�Ի���

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
	void InsertApplyInfo(const std::shared_ptr<stApplyInfo>&);//����������Ϣ
	
	//��ʼ��ZCMsgManager��Ϣ������
	void InitZCMsgHandler();
	std::map<DWORD, void(CSelfServiceBankClientDlg::*)(PBYTE, DWORD, INT)> m_mapZCMsgHandler;//ZCMsgManager��Ϣ������
	//ˢ����֤��Ϣ
	void ZCMsgAuthentication(PBYTE, DWORD, INT);
	//����ˢ����Ϣ
	//bool ZCMsgHelper_ParseMemo(CString&, std::vector<CString>&);
	//��������ʱ��
	CTime ZCMsgHelper_ParseTime(const char*);
};
