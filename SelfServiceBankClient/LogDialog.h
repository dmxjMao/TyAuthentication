#pragma once



// CLogDialog dialog
class CMyLogListCtrl;

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
	std::shared_ptr<CMyLogListCtrl> m_oLogList = 0;
	CListBox m_oFileList;
public:
	virtual BOOL OnInitDialog();

};
