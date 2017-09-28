
// SelfServiceBankClientDlg.h : header file
//

#pragma once
#include "MyStatic1.h"
//#include "MyListCtrl1.h"
#include "MyListBox1.h"
#include "ApplyRecordDlg.h"

// CSelfServiceBankClientDlg dialog
class CSelfServiceBankClientDlg : public CDialogEx
{
// Construction
public:
	CSelfServiceBankClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELFSERVICEBANKCLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CRect m_rcClient, m_rcCaption, m_rcList, m_rcRecord; //客户区、标题区，列表区，记录区
	CMyStatic1 m_oCloseWindow;//关闭按钮
//	CMyListCtrl1 m_oApplyList;
	CMyListBox1 m_oApplyList;//申请列表
	std::vector<CApplyRecordDlg> m_vecApplyRecordDlg; //申请记录详细信息

	// Generated message map functions
	virtual BOOL OnInitDialog();
	//afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	//afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	
public:
	afx_msg void OnStnClickedClosewindow();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);


private:
#ifdef _DEBUG
	void _DebugInsertListItem();//插入列表数据
	void _DebugInsertSomeApplyPersonInfo();//插入申请认证人员信息

#endif
	
};
