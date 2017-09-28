
// AuthenticationClientDlg.h : header file
//

#pragma once
#include "MyStatic1.h"
//#include "MyDialog1.h"

//class CMyStatic1;
// CAuthenticationClientDlg dialog
class CAuthenticationClientDlg : public CDialogEx
{
// Construction
public:
	CAuthenticationClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTHENTICATIONCLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;//程序图标:tab、任务栏、系统托盘。。。
	CRect m_rcClient;//客户端区域
	CRect m_rcCaption;//标题栏区域
	
	//标题栏三兄弟（用指针没弄出来好尴尬）
	CMyStatic1 m_oMinWindow;
	CMyStatic1 m_oMaxWindow;
	CMyStatic1 m_oCloseWindow;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	//afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	//afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedClosewindow();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
