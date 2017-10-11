// LogDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "LogDialog.h"
#include "afxdialogex.h"


// CLogDialog dialog

IMPLEMENT_DYNAMIC(CLogDialog, CDialogEx)

CLogDialog::CLogDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Log, pParent)
{

}

CLogDialog::~CLogDialog()
{
}

void CLogDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_oLogList);
	DDX_Control(pDX, IDC_LIST2, m_oFileList);
}


BEGIN_MESSAGE_MAP(CLogDialog, CDialogEx)
END_MESSAGE_MAP()


// CLogDialog message handlers


BOOL CLogDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rc;
	GetClientRect(&rc);
	int x = rc.left + 100;
	int w = rc.right - x;
	m_oLogList.SetWindowPos(0, x , rc.top, w, rc.Height(), SWP_NOZORDER);
	
#ifdef _DEBUG
	m_oLogList.Init();
#endif // _DEBUG
	
	m_oFileList.ShowWindow(SW_HIDE);

	return TRUE; 
}
