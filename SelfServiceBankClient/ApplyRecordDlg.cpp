// ApplyRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "ApplyRecordDlg.h"
#include "afxdialogex.h"

#include "EmergencyPlanDialog.h" //应急处置

using std::vector;
#define IDT_Valid	1

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
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_Emergency, &CApplyRecordDlg::OnClickedEmergency)
END_MESSAGE_MAP()


// CApplyRecordDlg message handlers


BOOL CApplyRecordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*布局
	Create之后调用OnInitDialog，而对话框SetWindowPos传来的尺寸不能用
	SetWindowPos，这是在子窗口内
	*/
	//左上宽高，rc是临时变量
	CRect rc = m_rcInParent;
	int x = rc.left, y = rc.top, w = rc.Width(), h = rc.Height();
	
	SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
	GetClientRect(&m_rcClient);

	//现在布局控件，坐标都要相对于客户区的
	//网点名称
	x = 10, y = 10, h /= 10; rc.bottom = y + h;
	GetDlgItem(IDC_title)->SetWindowPos(0, x, y, w - 30, h, SWP_NOZORDER);

	//两路视频框
	y = rc.bottom; w = h = m_rcInParent.Height() - y - 30/*30是 - 分割线 - 间隔*/;
	m_oVideo1.SetWindowPos(nullptr, x, y, w, h, SWP_NOZORDER);
	x += w + 2;
	m_oVideo2.SetWindowPos(nullptr, x, y, w, h, SWP_NOZORDER);

	//认证人员标签，相对布局没用
	x += w + 4;
	GetDlgItem(IDC_Title2)->SetWindowPos(0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

	//画分割线，OnInitDialog对话框自己还没画好呢

	//申请认证人员信息
	GetDlgItem(IDC_Title2)->GetWindowRect(&rc);
	y += rc.Height() + 6;
	//LVS_EX_FLATSB  在InsertItem之后才有滚动条；LVS_NOCOLUMNHEADER占客户区
	m_oPersonInfo.CreateEx(LVS_EX_FLATSB | LVS_EX_DOUBLEBUFFER, LVS_REPORT | LVS_NOCOLUMNHEADER | LVS_OWNERDRAWFIXED | WS_CHILD | WS_VISIBLE,
		CRect(x, y, m_rcClient.right - 10, y + m_rcClient.Height() * 5 / 12 ), this, 1);
	//m_oPersonInfo.ShowScrollBar(SB_VERT, FALSE);
	//InitializeFlatSB(m_oPersonInfo.m_hWnd);
	//FlatSB_EnableScrollBar(m_oPersonInfo.m_hWnd, SB_BOTH, ESB_DISABLE_BOTH);
	//FlatSB_ShowScrollBar(m_oPersonInfo.m_hWnd, SB_VERT, FALSE);

	//门，图片从文档下载
	m_oPersonInfo.GetClientRect(&rc);
	y += rc.Height() + 20/*间距*/;
	m_oPicDoor.SetWindowPos(0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	m_oPicDoor.Set(_T("res\\closeddoor_32px.png"));

	//按钮，根据配置灰化处理
	y -= 15;
	w = rc.Width();//申请列表宽度
	m_oPicDoor.GetClientRect(&rc);
	int nGap = 30;//按钮之间的间距
	//应急处置
	x += rc.Width() + 5; 
	w = (w - (rc.Width() + 5)/*门*/) / 3/*3个按钮*/ - nGap;
	m_oEmergency.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//申请授权
	x += w + nGap;
	m_oGrant.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//开门
	x += w + nGap;
	m_oOpen.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	m_oOpen.Set(false);
	//进入图层
	x -= 2 * (w + nGap);
	m_oEmergency.GetClientRect(&rc);
	y += rc.Height() + 2;
	m_oEnterMapLayer.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//锁门
	x += w + nGap;
	m_oLock.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	m_oLock.Set(false);
	//拒绝开门
	x += w + nGap;
	m_oRefuseOpen.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	m_oRefuseOpen.Set(false);
	//确认
	m_oPersonInfo.GetWindowRect(&rc);
	ScreenToClient(&rc);
	w = rc.Width() / 2;
	x = rc.left + w / 2;
	m_oEmergency.GetClientRect(&rc);
	y += rc.Height() + 2;
	m_oConfirm.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
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
	int x = rc.left, y = rc.bottom + 1;
	gh.DrawLine(&pen, x, y, m_rcClient.right - 20, y);

	//画记录之间的分割线 之间有30px的区域
	GetDlgItem(IDC_Video1)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	x = rc.left, y = rc.bottom + 20;
	gh.DrawLine(&pen, x, y, m_rcClient.right - 5, y);

	//如果支持管控，高亮边框
	if (m_stApplyInfo->nImportance) {
		Pen pen(Color(255, 123, 112), 3.0f);
		pen.SetAlignment(PenAlignmentInset);
		Rect rcGdi(m_rcClient.left, m_rcClient.top, m_rcClient.Width(), m_rcClient.Height());
		//rcGdi.Inflate(5, 5);
		gh.DrawRectangle(&pen, rcGdi);
		
		//SolidBrush sbrBG(Color(255, 223, 112));
		//gh.FillRectangle(&sbrBG, 
		//	Rect(m_rcClient.left, m_rcClient.top, m_rcClient.Width(), m_rcClient.Height()));
	}
}


void CApplyRecordDlg::Update()
{
	if (m_stApplyInfo) {
		//计时“已失效”，N秒，点击左侧就不能这样了
		//SetTimer(IDT_Valid, 5 * 1000, 0);
		//计算剩余时间
		CTimeSpan tmLeft = CTime::GetCurrentTime() - m_stApplyInfo->tmApply;
		if (tmLeft.GetTotalSeconds() < 30) {//小于10s
			SetTimer(IDT_Valid, (30 - (int)tmLeft.GetTotalSeconds()) * 1000, 0);
		}
		else {
			//OnTimer(IDT_Valid);  //窗口还没创建好，崩溃
			SetTimer(IDT_Valid, 0, 0);
		}
		

		//网点名称
		GetDlgItem(IDC_title)->SetWindowText(m_stApplyInfo->strWebSiteName);

		//申请人员列表
		m_oPersonInfo.MyInsertSubItem(m_stApplyInfo->vecPersonInfo);
		//m_oPersonInfo.Update();  //导致多了垂直滚动条
		//UpdateWindow();
		Invalidate();
		ShowWindow(SW_NORMAL);
	}
}

//按钮灰化/可用处理
void CApplyRecordDlg::EnableButton(emButton em)
{
	static vector<CStatic*> vec = {
		&m_oEmergency, &m_oGrant, &m_oOpen,
		&m_oEnterMapLayer, &m_oLock, &m_oRefuseOpen,
		&m_oConfirm
	};

	static std::bitset<emButtonBuff> bs;

}




void CApplyRecordDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent) {
	case IDT_Valid: //”已失效“
	{
		KillTimer(nIDEvent);
		//获取m_oVideo1.right，“已失效”的宽
		CRect rc;
		m_oVideo1.GetWindowRect(&rc);
		ScreenToClient(&rc);
		Image img(_T("res\\已失效.png"));
		int w = img.GetWidth(), h = img.GetHeight();
		int x = rc.right - w / 2;
		int y = rc.top + rc.Height() / 2 - h / 2;
		
		CClientDC dc(this);
		Graphics gh(dc.GetSafeHdc());
		gh.DrawImage(&img, x, y, w, h);

		break;
	}	
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CApplyRecordDlg::OnClickedEmergency()
{
	
	static vector<stEmergPlan> vecPlan = { 
		{stEmergPlan(_T("医院洪水预案"), { stEmergPlanStep(1,_T("开门")), stEmergPlanStep(2,_T("关警报，查看停尸间是否有人在睡觉，然后回机房拿消防斧回来砍断水管，最后关门")) })},
		{ stEmergPlan(_T("火山喷发预案"),{ stEmergPlanStep(1,_T("扯下窗帘")), stEmergPlanStep(2,_T("裹在头上祈祷")) }) }
	};

	static auto sp = std::make_shared<vector<stEmergPlan>>(vecPlan);

	CEmergencyPlanDialog dlg(sp, this);
	dlg.DoModal();
}
