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
	CApplyRecordDlg(const CApplyRecordDlg&) {} //vector<CApplyRecordDlg>��Ҫ
	virtual ~CApplyRecordDlg();

	virtual BOOL OnInitDialog();
	//���öԻ����ڸ������е�������ΪCreate->OnInitDialog->SetWindowPos
	inline void SetRectInParent(const CRect& rc) { m_rcInParent = rc; }
	//������������
	inline void SetWebSiteName(const CString& wsName) {
		GetDlgItem(IDC_title)->SetWindowText(wsName);
	}
	//������Ƶ��Ϣ
	void SetVideInfo(const std::vector<CString>& vec);
	//������Ա��Ϣ
	void SetPersonInfo(const std::vector<stApplyPersonInfo>& vec);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ApplyRecordDlg };
#endif

protected:
	CRect m_rcInParent, m_rcClient/*, m_rcPerson*/;//�ڸ������е��������ꡢ�ͻ�����

	//std::vector<stApplyPersonInfo> m_vecStPersonInfo;//������֤��Ա��Ϣ
	//CString m_strWebSiteName;//��������
	std::vector<CString> m_vecVideoInfo;//��Ƶ��Ϣ

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
	CMyListCtrl1 m_oPersonInfo;  //������֤��Ա��Ϣ

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	
private:
#ifdef _DEBUG
	void _DebugInsertPersonInfoListColumn(); //�����ͷ
#endif
};
