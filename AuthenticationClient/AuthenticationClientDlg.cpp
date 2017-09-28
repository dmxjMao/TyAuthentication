
// AuthenticationClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AuthenticationClient.h"
#include "AuthenticationClientDlg.h"
#include "afxdialogex.h"
//#include "MyStatic1.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CAuthenticationClientDlg dialog



CAuthenticationClientDlg::CAuthenticationClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AUTHENTICATIONCLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_App);

	//创建子控件（必须先于DoDataExchange）
	//m_oCloseWindow = new CMyStatic1(_T("res\\标题栏\\标题栏关闭常态.png"));
}

void CAuthenticationClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MinWindow, m_oMinWindow);
	DDX_Control(pDX, IDC_MaxWindow, m_oMaxWindow);
	DDX_Control(pDX, IDC_CloseWindow, m_oCloseWindow);
}

BEGIN_MESSAGE_MAP(CAuthenticationClientDlg, CDialogEx)
	//ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	//ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_CloseWindow, &CAuthenticationClientDlg::OnStnClickedClosewindow)
	ON_WM_NCHITTEST()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CAuthenticationClientDlg message handlers

BOOL CAuthenticationClientDlg::OnInitDialog()
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

	// TODO: Add extra initialization here
	/*布局*/
	//移动主界面
	int cx = ::GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = ::GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rc(0,0,cx,cy);//屏幕坐标
	rc.DeflateRect(cx / 4, cy / 4);//缩小1/4
	SetWindowPos(nullptr, rc.left, rc.top, rc.Width(),rc.Height(), SWP_NOZORDER);

	//客户端区域
	GetClientRect(&m_rcClient);
	//标题栏区域
	m_rcCaption.SetRect(m_rcClient.left, m_rcClient.top, m_rcClient.Width(), cstnTitleHeight);

	//最小最大关闭按钮
	/*对话框与控件的调用顺序：1）控件子类化；2）OnInitDialog；3）对话框OnPaint；4）控件OnPaint*/
	//m_oMinWindow.Set(_T("res\\close_32px.png"));
	//m_oMaxWindow.Set(_T("res\\close_32px.png"));
	m_oCloseWindow.Set(_T("res\\标题栏\\标题栏关闭常态.png"), _T("res\\标题栏\\标题栏关闭悬停.png"));
	//m_oCloseWindow->Create(_T(""), WS_CHILD | WS_VISIBLE|SS_OWNERDRAW, CRect(0, 0, 0, 0), this);
	rc.SetRect(rc.right - 24 - 10, rc.top, 0, 0); ScreenToClient(&rc);
	m_oCloseWindow.SetWindowPos(nullptr, rc.left, rc.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	//m_oCloseWindow->ShowWindow(SW_NORMAL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

//void CAuthenticationClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAuthenticationClientDlg::OnPaint()
{
	CPaintDC dc(this);
	
	//布局用的参数：坐标、宽高
	const auto& rc = m_rcClient;
	int x = rc.left, y = rc.top;
	int	w = rc.Width(), h = rc.Height();

	//画标题栏
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
//HCURSOR CAuthenticationClientDlg::OnQueryDragIcon()
//{
//	return static_cast<HCURSOR>(m_hIcon);
//}





//点击关闭
void CAuthenticationClientDlg::OnStnClickedClosewindow()
{
	PostQuitMessage(0);
}

/*
程序一般不处理非客户区鼠标消息，系统先接收WM_NCHITTEST消息，再产生客户或
非客户区消息，
一个应用是，利用OnNcHitTest，使客户区有非客户区的功能，
*/
LRESULT CAuthenticationClientDlg::OnNcHitTest(CPoint point)
{
	//UINT nHitTest = CDialogEx::OnNcHitTest(point);

	//return (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest;
	return CDialogEx::OnNcHitTest(point);
}


void CAuthenticationClientDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonDown(nFlags, point);

	if(m_rcCaption.PtInRect(point)){
		// 发送WM_NCLBUTTONDOWN消息
		// 使Windows认为鼠标在标题栏上
		PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
		//或SendMessage(WM_SYSCOMMAND,0xF012,0);   //0xF012 = SC_MOVE | HTCAPTION
	}
}


