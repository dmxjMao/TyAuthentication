
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
	HICON m_hIcon;//����ͼ��:tab����������ϵͳ���̡�����
	CRect m_rcClient;//�ͻ�������
	CRect m_rcCaption;//����������
	
	//���������ֵܣ���ָ��ûŪ���������Σ�
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
