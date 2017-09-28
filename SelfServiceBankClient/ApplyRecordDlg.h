#pragma once
#include "CommonDefine.h"  //struct
#include "afxwin.h"
#include "MyListCtrl1.h"

// CApplyRecordDlg dialog

class CApplyRecordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CApplyRecordDlg)

public:
	CApplyRecordDlg(CWnd* pParent = NULL);   // standard constructor
	CApplyRecordDlg(const CApplyRecordDlg&) {} //vector<CApplyRecordDlg>需要
	virtual ~CApplyRecordDlg();

	virtual BOOL OnInitDialog();
	//设置对话框在父窗口中的区域，因为Create->OnInitDialog->SetWindowPos
	inline void SetRectInParent(const CRect& rc) { m_rcInParent = rc; }
	//设置网点名称
	inline void SetWebSiteName(const CString& wsName) {
		GetDlgItem(IDC_title)->SetWindowText(wsName);
	}
	//设置视频信息
	void SetVideInfo(const std::vector<CString>& vec);
	//设置人员信息
	void SetPersonInfo(const std::vector<stApplyPersonInfo>& vec);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ApplyRecordDlg };
#endif

protected:
	CRect m_rcInParent, m_rcClient/*, m_rcPerson*/;//在父窗口中的区域坐标、客户区域

	//std::vector<stApplyPersonInfo> m_vecStPersonInfo;//申请认证人员信息
	//CString m_strWebSiteName;//网点名称
	std::vector<CString> m_vecVideoInfo;//视频信息

	CStatic m_oVideo1;
	CStatic m_oVideo2;
	CStatic m_oPicDoor;
	//CScrollBar m_oSBar;
	CStatic m_oEmergency;
	CStatic m_oGrant;
	CStatic m_oOpen;
	CStatic m_oEnterMapLayer;
	CStatic m_oLock;
	CStatic m_oRefuseOpen;
	CStatic m_oConfirm;
	CMyListCtrl1 m_oPersonInfo;  //申请认证人员信息

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	
private:
#ifdef _DEBUG
	void _DebugInsertPersonInfoListColumn(); //插入表头
#endif
};
