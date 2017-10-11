#pragma once
#include "MyLogListCtrl.h"
#include "afxwin.h"


// CLogDialog dialog

class CLogDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CLogDialog)

public:
	CLogDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLogDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Log };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CMyLogListCtrl m_oLogList;
	CListBox m_oFileList;
public:
	virtual BOOL OnInitDialog();

};
