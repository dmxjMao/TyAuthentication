
// SelfServiceBankClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "SelfServiceBankClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


namespace {
	using std::vector;

	const UINT cstnApplyRecordCnt = 3; //�����¼��������

};

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSelfServiceBankClientDlg dialog



CSelfServiceBankClientDlg::CSelfServiceBankClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SELFSERVICEBANKCLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_vecApplyRecordDlg.resize(cstnApplyRecordCnt);
}

void CSelfServiceBankClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CloseWindow, m_oCloseWindow);
	//  DDX_Control(pDX, IDC_ApplyList, m_oApplyList);
	//DDX_Control(pDX, IDC_ApplyList, m_oApplyList);
}

BEGIN_MESSAGE_MAP(CSelfServiceBankClientDlg, CDialogEx)
	//ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	//ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_CloseWindow, &CSelfServiceBankClientDlg::OnStnClickedClosewindow)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSelfServiceBankClientDlg message handlers

BOOL CSelfServiceBankClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	/*����*/
	//�ƶ�������
	int cx = ::GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = ::GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rc(0, 0, cx, cy);
	rc.DeflateRect(cx / 5, cy / 15);//���Ҹ���С1/4���߿����
	SetWindowPos(nullptr, rc.left, rc.top, rc.Width(), rc.Height(), SWP_NOZORDER);//��Ļ����

	//���������ͻ����б�������֤��¼��
	ScreenToClient(&rc);
	m_rcCaption.SetRect(rc.left, rc.top, rc.Width(), cstnTitleHeight);
	m_rcClient.SetRect(rc.left, rc.top + cstnTitleHeight, rc.Width(), rc.Height());
	m_rcList.SetRect(m_rcClient.left + 1, m_rcClient.top + 1, m_rcClient.Width() / 6, m_rcClient.Height() - 1);
	m_rcRecord.SetRect(m_rcList.right + 5, m_rcList.top, m_rcClient.right, m_rcList.bottom);
	//GetClientRect(&m_rcClient);

	//�ƶ��رհ�ť
	/*�Ի�����ؼ��ĵ���˳��1���ؼ����໯��2��OnInitDialog��3���Ի���OnPaint��4���ؼ�OnPaint*/
	m_oCloseWindow.Set(_T("res\\�������رճ�̬.png"), _T("res\\�������ر���ͣ.png"), false);
	rc.SetRect(rc.right - 24, rc.top, 0, 0);
	m_oCloseWindow.SetWindowPos(nullptr, rc.left, rc.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);//Ҫ�ͻ�������


	//�����б�
	m_oApplyList.Create(LBS_OWNERDRAWFIXED | LBS_HASSTRINGS | LBS_NOTIFY | /*LBS_EXTENDEDSEL |*/ WS_CHILD | WS_VISIBLE, 
		CRect(0, 0, 0, 0), this, 1);
	m_oApplyList.SetWindowPos(nullptr, m_rcList.left, m_rcList.top, m_rcList.Width(), m_rcList.Height(), SWP_NOZORDER);
#ifdef  _DEBUG
	//�����������
	_DebugInsertListItem();
	////����һЩ������Ա���Ի���û������
	//_DebugInsertSomeApplyPersonInfo();
#endif //  _DEBUG

	//�ƶ���������Ի���
	int nDlgHeight = 
		m_rcClient.Height() / cstnApplyRecordCnt;//ÿ����¼�ĸ߶��� 1/n ������ - �ָ��� - ��� 15px��
	for (auto i = 0; i < cstnApplyRecordCnt; ++i) {
		auto& dlg = m_vecApplyRecordDlg[i];
		int x = m_rcRecord.left, y = m_rcRecord.top + i * nDlgHeight;
		dlg.SetRectInParent(CRect(x, y, x + m_rcRecord.Width(), y + nDlgHeight));//�����ڸ������е�����
		//dlg.SetWindowPos(nullptr,
		//	x, y, m_rcRecord.Width(), nDlgHeight, SWP_NOZORDER);

		dlg.Create(IDD_ApplyRecordDlg, this);
		/*dlg.SetWindowPos(nullptr,
			m_rcRecord.left, m_rcRecord.top + i * nDlgHeight,
			m_rcRecord.Width(), nDlgHeight - 15, SWP_NOZORDER);*/
		dlg.ShowWindow(SW_NORMAL);
	}

#ifdef  _DEBUG
	//����һЩ������Ա��Create֮����OnInitDialog������OnInitDialog�ﻹû�����ݣ�
	//Ӧ����OnPaint����
	_DebugInsertSomeApplyPersonInfo();
#endif //  _DEBUG

	return TRUE;  // return TRUE  unless you set the focus to a control
}

//void CSelfServiceBankClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
//{
//	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
//	{
//		CAboutDlg dlgAbout;
//		dlgAbout.DoModal();
//	}
//	else
//	{
//		CDialogEx::OnSysCommand(nID, lParam);
//	}
//}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSelfServiceBankClientDlg::OnPaint()
{
	CPaintDC dc(this);

	//�����õĲ��������ꡢ���
	const auto& rc = m_rcCaption;
	int x = rc.left, y = rc.top;
	int	w = rc.Width(), h = 0;

	//��������
	Graphics gh(dc.GetSafeHdc());
	SolidBrush sbr(cstClrTitle);
	gh.FillRectangle(&sbr, x, y, w, cstnTitleHeight);

	//if (IsIconic())
	//{
	//	CPaintDC dc(this); // device context for painting

	//	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

	//	// Center icon in client rectangle
	//	int cxIcon = GetSystemMetrics(SM_CXICON);
	//	int cyIcon = GetSystemMetrics(SM_CYICON);
	//	CRect rect;
	//	GetClientRect(&rect);
	//	int x = (rect.Width() - cxIcon + 1) / 2;
	//	int y = (rect.Height() - cyIcon + 1) / 2;

	//	// Draw the icon
	//	dc.DrawIcon(x, y, m_hIcon);
	//}
	//else
	//{
	//	CDialogEx::OnPaint();
	//}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
//HCURSOR CSelfServiceBankClientDlg::OnQueryDragIcon()
//{
//	return static_cast<HCURSOR>(m_hIcon);
//}



void CSelfServiceBankClientDlg::OnStnClickedClosewindow()
{
	PostQuitMessage(0);
}


void CSelfServiceBankClientDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonDown(nFlags, point);

	if (m_rcCaption.PtInRect(point)) {
		// ����WM_NCLBUTTONDOWN��Ϣ
		// ʹWindows��Ϊ����ڱ�������
		PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
		//��SendMessage(WM_SYSCOMMAND,0xF012,0);   //0xF012 = SC_MOVE | HTCAPTION
	}
}



#ifdef _DEBUG
void CSelfServiceBankClientDlg::_DebugInsertSomeApplyPersonInfo()
{
	const CString strWsName[] = { _T("�ҵĽ��1") ,_T("�ҵĽ��2") ,_T("�ҵĽ��3") };
	const vector<vector<CString>> vec = {
		{ _T("�ҵĽ��1̽ͷ1"),_T("�ҵĽ��1̽ͷ2") },
		{ _T("�ҵĽ��2̽ͷ1"),_T("�ҵĽ��2̽ͷ2") },
		{ _T("�ҵĽ��3̽ͷ1"),_T("�ҵĽ��3̽ͷ2") }
	};
	const vector<vector<stApplyPersonInfo>> vecPInfo = {
		{
			stApplyPersonInfo(_T("person1.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,7,34)),
			stApplyPersonInfo(_T("person2.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,7,34)),
			stApplyPersonInfo(_T("person3.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,8,34)),
			stApplyPersonInfo(_T("person4.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,9,34)),
			stApplyPersonInfo(_T("person5.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,10,34)),
			stApplyPersonInfo(_T("person6.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,11,34)),
			stApplyPersonInfo(_T("person7.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,12,34)),
			stApplyPersonInfo(_T("person8.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,13,34)),
			stApplyPersonInfo(_T("person9.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,7,34)),
			stApplyPersonInfo(_T("person10.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,7,4)),
			stApplyPersonInfo(_T("person11.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,7,54)),
			stApplyPersonInfo(_T("person12.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,7,54)),
		},
		{
			stApplyPersonInfo(_T("person1.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,7,34))
		},
		{
			stApplyPersonInfo(_T("person1.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,7,34)),
			stApplyPersonInfo(_T("person2.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,7,34)),
			stApplyPersonInfo(_T("person3.jpg"),_T("�Ž�����վ"),_T("�ڲ���Ա"),CTime(2017,9,28,10,8,34))
		}
	};


	for (auto i = 0; i < cstnApplyRecordCnt;++i) {
		auto& dlg = m_vecApplyRecordDlg[i];
		dlg.SetWebSiteName(strWsName[i]);
		dlg.SetVideInfo(vec[i]);
		dlg.SetPersonInfo(vecPInfo[i]);
	}

}

void CSelfServiceBankClientDlg::_DebugInsertListItem()
{
	const CString str[] = { _T("����"),_T("Ӫҵ����"), _T("����"), _T("�Ϻ�ũ����"), _T("haoyun") };
	const int n = _countof(str);
	for (auto i = 0; i < n; ++i) {
		m_oApplyList.AddString(str[i]);
	}
}
#endif //_DEBUG

