// ApplyRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "ApplyRecordDlg.h"
#include "afxdialogex.h"

using std::vector;

// CApplyRecordDlg dialog

IMPLEMENT_DYNAMIC(CApplyRecordDlg, CDialogEx)

CApplyRecordDlg::CApplyRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ApplyRecordDlg, pParent)
{

}

CApplyRecordDlg::~CApplyRecordDlg()
{
}

void CApplyRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Video1, m_oVideo1);
	DDX_Control(pDX, IDC_Video2, m_oVideo2);
	DDX_Control(pDX, IDC_pic2Door, m_oPicDoor);
	//DDX_Control(pDX, IDC_SCROLLBAR1, m_oSBar);
	DDX_Control(pDX, IDC_Emergency, m_oEmergency);
	DDX_Control(pDX, IDC_Grant, m_oGrant);
	DDX_Control(pDX, IDC_Open, m_oOpen);
	DDX_Control(pDX, IDC_EnterMapLayer, m_oEnterMapLayer);
	DDX_Control(pDX, IDC_Lock, m_oLock);
	DDX_Control(pDX, IDC_RefuseOpen, m_oRefuseOpen);
	DDX_Control(pDX, IDC_Confirm, m_oConfirm);
	//  DDX_Control(pDX, IDC_PersonInfo, m_oPersonInfo);
}


BEGIN_MESSAGE_MAP(CApplyRecordDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CApplyRecordDlg message handlers


BOOL CApplyRecordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*布局
	Create之后调用OnInitDialog，而对话框SetWindowPos传来的尺寸不能用
	SetWindowPos，这是在子窗口内
	*/
	//SetWindowPos(nullptr, m_rcClient.left, m_rcClient.top, m_rcClient.Width(), m_rcClient.Height(), SWP_NOZORDER);
	//GetClientRect(&m_rcClient); 
	//const auto& rc = m_rcClient;
	//左上宽高，rc是临时变量
	CRect rc = m_rcInParent;
	int x = rc.left, y = rc.top, w = rc.Width(), h = rc.Height();
	
	SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
	GetClientRect(&m_rcClient);

	//现在布局控件，坐标都要相对于客户区的
	//网点名称
	x = 0, y = 0, h /= 10; rc.bottom = h;
	GetDlgItem(IDC_title)->SetWindowPos(0, x, y, w, h, SWP_NOZORDER);

	//两路视频
	y = rc.bottom; w = h = m_rcInParent.Height() - y - 15/*15是 - 分割线 - 间隔*/;
	m_oVideo1.SetWindowPos(nullptr, x, y, w, h, SWP_NOZORDER);
	x += w + 1;
	m_oVideo2.SetWindowPos(nullptr, x, y, w, h, SWP_NOZORDER);

	//认证人员标签，相对布局没用
	x += w + 4;
	GetDlgItem(IDC_Title2)->SetWindowPos(0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

	//画分割线，OnInitDialog对话框自己还没画好呢
	//CClientDC dc(this);
	//Graphics gh(dc.GetSafeHdc());
	//Pen pen(Color(255,0,0), 2.0f);
	//
	//GetDlgItem(IDC_Title2)->GetWindowRect(&rc);
	//y += rc.Height() + 1;
	//gh.DrawLine(&pen, x, y, m_rcClient.right - 5, y);


	//申请认证人员信息
	GetDlgItem(IDC_Title2)->GetWindowRect(&rc);
	y += rc.Height() + 2;
	//LVS_EX_FLATSB  在InsertItem之后才有滚动条
	m_oPersonInfo.CreateEx(LVS_EX_FLATSB, LVS_REPORT | LVS_OWNERDRAWFIXED | WS_CHILD | WS_VISIBLE, CRect(x, y, m_rcClient.right, y + m_rcClient.Height() / 2), this, 1);
#ifdef _DEBUG
	_DebugInsertPersonInfoListColumn(); //插入申请认证人员信息
#endif // _DEBUG
	


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}





void CApplyRecordDlg::SetVideInfo(const vector<CString>& vec)
{
	m_vecVideoInfo = std::move(vec);
}


void CApplyRecordDlg::SetPersonInfo(const vector<stApplyPersonInfo>& vec)
{
	m_oPersonInfo.GetInfoVec() = std::move(vec);
}

void CApplyRecordDlg::OnPaint()
{
	CPaintDC dc(this); 
	Graphics gh(dc.GetSafeHdc());
	
	//画“认证人员” - 分割线
	Pen pen(Color(216, 216, 216), 2.0f);
	CRect rc;
	GetDlgItem(IDC_Title2)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	int x = rc.left, y = rc.bottom + 3;
	gh.DrawLine(&pen, x, y, m_rcClient.right - 5, y);
}



#ifdef _DEBUG
void CApplyRecordDlg::_DebugInsertPersonInfoListColumn()
{
	const CString str[] = { _T("列1"),_T("列2"),_T("列3"),_T("列4"),_T("列5"),_T("列6"),_T("列7"),_T("列8"),_T("列9"),_T("列10") };
	int n = _countof(str);
	CRect rc;
	m_oPersonInfo.GetClientRect(&rc);
	int w = rc.Width() / 2;
	for (auto i = 0; i < n; ++i) {
		m_oPersonInfo.InsertColumn(i, str[i], LVCFMT_LEFT, w);
	}

	const CString str2[] = { _T("孙悟空"), _T("花果山"),_T("灵长类"),_T("五百年前"),_T("列5"),_T("列6"),_T("列7"),_T("列8"),_T("列9"),_T("列10") };
	m_oPersonInfo.InsertItem(0, str2[0]);
	for (auto i = 1; i < n; ++i) {	
		m_oPersonInfo.SetItemText(0, i, str2[i]);
	}

}
#endif // _DEBUG
