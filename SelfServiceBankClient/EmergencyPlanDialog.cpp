// EmergencyPlanDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "EmergencyPlanDialog.h"
#include "afxdialogex.h"

#include "MyCommonDefine.h"
//#include "ApplyRecordDlg.h"
#include "MyStatic1.h"
#include "MyStatic3.h"
#include "MyButton1.h"
#include "MyButton2.h"
#include "MyListBox2.h"
#include "MyStg.h"

// CEmergencyPlanDialog dialog
namespace{
	#define IDC_CloseW 100 //关闭按钮
	#define IDC_OtherEMPlan 101 //其他预案
	#define IDC_EMPlanStep 102 //预案步骤，预留10个 102~111
	#define IDC_OtherEMPlanLB 112 //其他预案列表
	#define IDC_Submit 113//提交按钮

	const int cstnCaptionH = 24;//标题栏高度

	using std::placeholders::_1;
};
IMPLEMENT_DYNAMIC(CEmergencyPlanDialog, CDialogEx)

CEmergencyPlanDialog::CEmergencyPlanDialog(const WORD id, CString planName,
	std::shared_ptr<CStgOperator>& pStg, CWnd* pParent /*=NULL*/)
	: m_nApplyID(id), m_strCurPlanName(planName), m_oStg(pStg),
	CDialogEx(IDD_EmergencyPlan, pParent), m_pParent(pParent)
{
	std::shared_ptr<Image> sp1(Image::FromFile(_T("res\\预案_灰色圆圈.png")));
	m_img1 = std::move(sp1);
	std::shared_ptr<Image> sp2(Image::FromFile(_T("res\\预案_背景常态.png")));
	m_img2 = std::move(sp2);

	//关闭按钮、预案名称、其他预案、提交按钮
	m_oCloseWindow = std::make_shared<CMyStatic1>();
	m_oName = std::make_shared<CMyStatic3>();
	m_oOther = std::make_shared<CMyButton1>();
	m_oSubmit = std::make_shared<CMyButton1>();
}

CEmergencyPlanDialog::~CEmergencyPlanDialog()
{
}

void CEmergencyPlanDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEmergencyPlanDialog, CDialogEx)
	ON_WM_PAINT()
	ON_STN_CLICKED(IDC_CloseW, &CEmergencyPlanDialog::OnStnClickedClosewindow)
	ON_BN_CLICKED(IDC_OtherEMPlan, &CEmergencyPlanDialog::OnBtnClickedOtherEMPlan)
	ON_LBN_SELCHANGE(IDC_OtherEMPlanLB, &CEmergencyPlanDialog::OnOtherEMPlanSelchange)
	ON_NOTIFY_EX(TTN_NEEDTEXT, 0, &CEmergencyPlanDialog::OnTtnNeedText)
	ON_COMMAND_RANGE(IDC_EMPlanStep, IDC_EMPlanStep+9, &CEmergencyPlanDialog::OnClickEMPlanStep)
END_MESSAGE_MAP()


// CEmergencyPlanDialog message handlers


BOOL CEmergencyPlanDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//调整窗口位置在“应急处置”按钮下方，如果超过边界就显示在上方
	CRect rcBtn; //按钮坐标

	m_pParent->GetDlgItem(IDC_Emergency)->GetWindowRect(&rcBtn);
	int x = rcBtn.left, y = rcBtn.bottom + 1; //dlg的左上取按钮的左上
	//int w = 4 * rcBtn.Width();
	CRect rcParent;
	m_pParent->GetWindowRect(&rcParent);
	int w = rcParent.right - rcBtn.left;//dlg宽度
	
	//GetParent()->GetClientRect(&rc); //GetParent是主窗口
	//int h = rc.Height() * 3 / 4;
	//高度取分辨率一半，根据y判断是在上面还是下面显示
	int nScreenY = ::GetSystemMetrics(SM_CYFULLSCREEN);//除任务栏
	int h = nScreenY / 2;
	if (y > h)
		y = rcBtn.top - h - 1;

	//if (y + h > nScreenY) {
	//	y = rcBtn.top - h - 1;
	//}
	SetWindowPos(0, x, y, w, h, SWP_NOZORDER);

	//tooltip
	if (m_tt.Create(this, TTS_ALWAYSTIP)) {
		m_tt.Activate(TRUE);
		//BOOL b = m_tt.AddTool(this);
		m_tt.SetMaxTipWidth(150);
		m_tt.SetDelayTime(TTDT_INITIAL, 200);
	}

	//关闭按钮
	CRect rc;//临时变量
	GetClientRect(&rc);
	rc.SetRect(rc.right - 24, rc.top, rc.right, rc.bottom); //popup和child不一样
	//m_oCloseWindow = std::make_shared<CMyStatic1>();
	m_oCloseWindow->Create(0, WS_CHILD | WS_VISIBLE | SS_NOTIFY | SS_OWNERDRAW, rc, this, IDC_CloseW);
	m_oCloseWindow->Set(_T("res\\标题栏关闭常态.png"), _T("res\\标题栏关闭悬停.png"), false);
	//m_oCloseWindow->SetWindowPos(0, rc.left, rc.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	
	const auto& vecPlan = theApp.m_vecEMPlanInfo;
	if (vecPlan.empty())
		return FALSE;//没有预案

	//预案名称
	//m_oName = std::make_shared<CMyStatic3>();
	GetClientRect(&rc);
	//x = rc.left, y = cstnCaptionH + 5;
	//w = rc.left + rc.Width() / 3, h = 2 * cstnCaptionH + 5;
	rc.SetRect(rc.left, cstnCaptionH + 5, rc.left + rc.Width() / 3, 2 * cstnCaptionH + 5);
	m_oName->Create(0, WS_CHILD | WS_VISIBLE | SS_OWNERDRAW, rc, this);
	//m_oName->Set(true, Color(54, 132, 215), Color(54, 132, 215));
	//m_oName->SetWindowPos(0, x, y, w, h, SWP_NOZORDER);

	//“其他预案”
	//m_oOther = std::make_shared<CMyButton1>();
	GetClientRect(&rc);
	rc.SetRect(rc.right - 5 - rc.Width()/4, cstnCaptionH + 5, rc.right - 5, 2 * cstnCaptionH + 5);
	m_oOther->Create(_T("其他预案"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rc, this, IDC_OtherEMPlan);
	m_oOther->SetUICfg("underline,0");
	//m_oOther->SetWindowPos(0, rc.left, rc.top, rc.Width(), rc.Height(), SWP_NOZORDER);

	//“预案步骤”
	auto it = std::find_if(theApp.m_vecEMPlanInfo.begin(), theApp.m_vecEMPlanInfo.end(),
		std::bind(lambda_FindEMPlanByName, _1, m_strCurPlanName));
	DrawEMPlanStep(*it);

	//提交
	//m_oSubmit = std::make_shared<CMyButton1>();
	GetClientRect(&rc);
	w = 40; h = 20; x = rc.right - w - 10; y = rc.bottom - h - 10;
	rc.SetRect(x, y, x + w, y + h);
	m_oSubmit->Create(_T("提交"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rc, this, IDC_Submit);
	//m_oSubmit->Set(false, 16, cstClrTitle, Color(255, 255, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CEmergencyPlanDialog::OnPaint()
{
	CPaintDC dc(this); 
	Graphics gh(dc.GetSafeHdc());

	CRect rc;
	GetClientRect(&rc);
	int x = rc.left, y = rc.top;
	int w = rc.Width(), h = cstnCaptionH;
	//画标题栏
	SolidBrush sbr(theApp.m_oGobal->cstClrTitle);
	gh.FillRectangle(&sbr, x, y, w, h);

	//写标题
	FontFamily ff(_T("微软雅黑"));
	Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color(255, 255, 255));
	PointF pf(0.0f, 2.0f);
	gh.DrawString(_T("应急预案"), -1, &font, pf, &sbrText);

	const auto& vecPlan = theApp.m_vecEMPlanInfo;
	if (vecPlan.empty()) {//没有预案
		sbrText.SetColor(Color(255, 0, 0));
		pf.Y = cstnCaptionH + 1;
		gh.DrawString(_T("没有预案信息！"), -1, &font, pf, &sbrText);
	}
	
	//时间
	CTime tmCur = CTime::GetCurrentTime();
	CString strTime = tmCur.Format(_T("%Y-%m-%d\n%H:%M:%S"));
}


void CEmergencyPlanDialog::OnStnClickedClosewindow()
{
	//PostQuitMessage(0);
	EndDialog(IDCANCEL);
}

//单击预案步骤
void CEmergencyPlanDialog::OnClickEMPlanStep(UINT id)
{
	//static std::vector<std::tuple<bool, CString>> vecStepInfo;
	//vecStepInfo.resize(10);//10个预案步骤
	const auto& btn = m_vecStep[id - IDC_EMPlanStep];
	btn->EnableWindow(FALSE);

	//时间
	CTime tmCur = CTime::GetCurrentTime();
	CString strTime = tmCur.Format(_T("%Y-%m-%d %H:%M:%S"));

	//画时间
	CClientDC dc(this);
	Graphics gh(dc.GetSafeHdc());
	CRect rc;
	btn->GetWindowRect(&rc);
	ScreenToClient(&rc);

	FontFamily ff(_T("微软雅黑"));
	Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color::Black);
	PointF pF((rc.right + 10) * 1.0f, (rc.top + 15) * 1.0f);

	gh.DrawString(strTime, -1, &font, pF, &sbrText);

	//预案执行信息传给父窗口保存
	/*vecStepInfo[id - IDC_EMPlanStep] = { true, strTmp };
	::SetWindowLongPtr(m_pParent->GetSafeHwnd(), GWLP_USERDATA, (LONG_PTR)&vecStepInfo);*/

	CString str;
	GetDlgItem(id)->GetWindowText(str);
	
	CString str2;
	str2 = m_strCurPlanName + _T("：") + str;
	//记录日志
	m_oStg->AddApplyActionLog(m_nApplyID, str2);

}

BOOL CEmergencyPlanDialog::PreTranslateMessage(MSG* pMsg)
{
	if (m_tt.GetSafeHwnd())
		m_tt.RelayEvent(pMsg);

	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CEmergencyPlanDialog::OnTtnNeedText(UINT id, NMHDR * pNMHDR, LRESULT * pResult)
{
	UNREFERENCED_PARAMETER(id);

	NMTTDISPINFO *pTTT = (NMTTDISPINFO *)pNMHDR;
	UINT_PTR nID = pNMHDR->idFrom;
	BOOL bRet = FALSE;

	if (pTTT->uFlags & TTF_IDISHWND)
	{
		// nID其实是HWND
		nID = ::GetDlgCtrlID((HWND)nID);
		if (nID >= IDC_EMPlanStep && nID < IDC_EMPlanStep + 10) { //预案步骤
			CMyButton2* pBtn = (CMyButton2*)GetDlgItem(nID);
			auto& str = pBtn->GetFullText();
			_tcscpy_s(pTTT->szText, _countof(pTTT->szText), str);
		}
		
		bRet = TRUE;
	}

	*pResult = 0;

	return bRet;
}

void CEmergencyPlanDialog::OnBtnClickedOtherEMPlan()
{
	//其他预案列表
	static BOOL bCreate = FALSE;
	static bool bExpand = true;
	bExpand = !bExpand;
	
	if (nullptr == m_oOtherLB) {
		m_oOtherLB = std::make_shared<CMyListBox2>();

		CRect rc;
		GetDlgItem(IDC_OtherEMPlan)->GetWindowRect(&rc);
		ScreenToClient(&rc);
		int x = rc.left, y = rc.bottom + 1;
		int w = 100, h = 100;
		rc.SetRect(x, y, x + w, y + h);
		bCreate = m_oOtherLB->Create(LBS_HASSTRINGS | LBS_NOTIFY | LBS_OWNERDRAWFIXED | WS_CHILD | WS_VISIBLE, rc, this, IDC_OtherEMPlanLB);
	}

	if (bExpand){
		//要在if (nullptr == m_oOtherLB)之后，因为客户可能直接关闭“预案”dlg，这时m_oOtherLB变为空
		m_oOtherLB->ShowWindow(SW_HIDE);
		return;
	}
	
	
	if (bCreate) {
		const auto& vecPlan = theApp.m_vecEMPlanInfo;
		m_oOtherLB->ResetContent();//清空
		int nCnt = (int)vecPlan.size();
		for (int i = 0; i < nCnt; ++i) {
			const auto& st = vecPlan[i];
			m_oOtherLB->AddString(st->strPlanName);
			m_oOtherLB->SetItemData(i, (DWORD_PTR)&st);
		}
		m_oOtherLB->ShowWindow(SW_NORMAL);
	}
	
}


void CEmergencyPlanDialog::OnOtherEMPlanSelchange()
{
	int nSel = m_oOtherLB->GetCurSel();
	std::shared_ptr<stEmergPlan>* st = (std::shared_ptr<stEmergPlan>*)m_oOtherLB->GetItemData(nSel);
	m_strCurPlanName = (*st)->strPlanName;
	DrawEMPlanStep(*st);
}


void CEmergencyPlanDialog::DrawEMPlanStep(const std::shared_ptr<stEmergPlan>& stPlan)
{
	CString str;
	m_oName->GetWindowText(str);
	if (str == stPlan->strPlanName)
		return;
	m_oName->SetWindowText(stPlan->strPlanName);
	m_oName->Invalidate(); //自绘就是麻烦

	int nStepCnt = (int)stPlan->vecStep.size();
	CRect rc;
	m_oName->GetWindowRect(&rc);
	ScreenToClient(&rc);
	int x = rc.left + 30, y = rc.bottom + 20;
	int w = 0, h = 0;
	if (m_img1 && m_img2)
		w = m_img1->GetWidth() + m_img2->GetWidth(), h = m_img1->GetHeight();

	m_vecStep.clear();
	m_vecStep.resize(nStepCnt);
	for (int i = 0; i < nStepCnt; ++i) {
		rc.SetRect(x, y + i*h, x + w, y + (i + 1)*h);
		auto& btn = m_vecStep[i];
		btn = std::make_shared<CMyButton2>(m_img1, m_img2);
		const auto& step = stPlan->vecStep[i];
		btn->Create(step.strName, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW /*| BS_NOTIFY*/,
			rc, this, IDC_EMPlanStep + i);
		//btn->SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
		m_tt.AddTool(btn.get());
	}
}
