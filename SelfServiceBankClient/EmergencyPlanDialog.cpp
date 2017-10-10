// EmergencyPlanDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "EmergencyPlanDialog.h"
#include "afxdialogex.h"

#include "ApplyRecordDlg.h"
#include "MyStatic1.h"
#include "MyStatic3.h"
#include "MyButton1.h"
#include "MyButton2.h"
#include "MyListBox2.h"

// CEmergencyPlanDialog dialog
namespace{
	#define IDC_CloseW 100 //�رհ�ť
	#define IDC_OtherEMPlan 101 //����Ԥ��
	#define IDC_EMPlanStep 102 //Ԥ�����裬Ԥ��10�� 102~111
	#define IDC_OtherEMPlanLB 112 //����Ԥ���б�
	#define IDC_Submit 113//�ύ��ť

	const int cstnCaptionH = 24;//�������߶�
};
IMPLEMENT_DYNAMIC(CEmergencyPlanDialog, CDialogEx)

CEmergencyPlanDialog::CEmergencyPlanDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EmergencyPlan, pParent)
{

}

CEmergencyPlanDialog::CEmergencyPlanDialog(const std::shared_ptr<std::vector<stEmergPlan>>& sp, CWnd* pParent)
	: m_vecEmergPlan(sp), m_pParent(pParent), CDialogEx(IDD_EmergencyPlan, pParent)
{
	std::shared_ptr<Image> sp1(Image::FromFile(_T("res\\Ԥ��_��ɫԲȦ.png")));
	m_img1 = std::move(sp1);
	std::shared_ptr<Image> sp2(Image::FromFile(_T("res\\Ԥ��_������̬.png")));
	m_img2 = std::move(sp2);

	//�رհ�ť��Ԥ�����ơ�����Ԥ�����ύ��ť
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
END_MESSAGE_MAP()


// CEmergencyPlanDialog message handlers


BOOL CEmergencyPlanDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//��������λ���ڡ�Ӧ�����á���ť�·�����������߽����ʾ���Ϸ�
	CRect rcBtn; //��ť����
	//CApplyRecordDlg* pParent = (CApplyRecordDlg*)GetParent();
	//auto p1 = pParent->GetDlgItem(IDC_Emergency);
	//CWnd* p = GetParentOwner();
	//auto p2 = pParent->GetDlgItem(IDC_Emergency);
	//p = GetOwner();
	//auto p3 = pParent->GetDlgItem(IDC_Emergency);

	m_pParent->GetDlgItem(IDC_Emergency)->GetWindowRect(&rcBtn);
	int x = rcBtn.left, y = rcBtn.bottom + 1;
	//int w = 4 * rcBtn.Width();
	CRect rcParent;
	m_pParent->GetWindowRect(&rcParent);
	int w = rcParent.right - rcBtn.left;
	
	CRect rc;//��ʱ����
	GetParent()->GetClientRect(&rc); //GetParent��������
	int h = rc.Height() / 2;
	//��������߽�
	int nScreenY = ::GetSystemMetrics(SM_CYFULLSCREEN);//��������
	if (y + h > nScreenY) {
		y = rcBtn.top - h - 1;
	}
	SetWindowPos(0, x, y, w, h, SWP_NOZORDER);

	//tooltip
	if (m_tt.Create(this, TTS_ALWAYSTIP)) {
		m_tt.Activate(TRUE);
		//BOOL b = m_tt.AddTool(this);
		m_tt.SetMaxTipWidth(150);
		m_tt.SetDelayTime(TTDT_INITIAL, 200);
	}

	//�رհ�ť
	GetClientRect(&rc);
	rc.SetRect(rc.right - 24, rc.top, rc.right, rc.bottom); //popup��child��һ��
	//m_oCloseWindow = std::make_shared<CMyStatic1>();
	m_oCloseWindow->Create(0, WS_CHILD | WS_VISIBLE | SS_NOTIFY | SS_OWNERDRAW, rc, this, IDC_CloseW);
	m_oCloseWindow->Set(_T("res\\�������رճ�̬.png"), _T("res\\�������ر���ͣ.png"), false);
	//m_oCloseWindow->SetWindowPos(0, rc.left, rc.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	//û��Ԥ��
	if (!m_vecEmergPlan || m_vecEmergPlan->empty())
		return FALSE;

	//Ԥ������
	//m_oName = std::make_shared<CMyStatic3>();
	auto& stPlan = m_vecEmergPlan->at(0); //Ĭ�ϵ�һ��
	GetClientRect(&rc);
	//x = rc.left, y = cstnCaptionH + 5;
	//w = rc.left + rc.Width() / 3, h = 2 * cstnCaptionH + 5;
	rc.SetRect(rc.left, cstnCaptionH + 5, rc.left + rc.Width() / 3, 2 * cstnCaptionH + 5);
	m_oName->Create(0, WS_CHILD | WS_VISIBLE | SS_OWNERDRAW, rc, this);
	//m_oName->Set(true, Color(54, 132, 215), Color(54, 132, 215));
	//m_oName->SetWindowPos(0, x, y, w, h, SWP_NOZORDER);

	//������Ԥ����
	//m_oOther = std::make_shared<CMyButton1>();
	GetClientRect(&rc);
	rc.SetRect(rc.right - 5 - rc.Width()/4, cstnCaptionH + 5, rc.right - 5, 2 * cstnCaptionH + 5);
	m_oOther->Create(_T("����Ԥ��"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rc, this, IDC_OtherEMPlan);
	//m_oOther->SetWindowPos(0, rc.left, rc.top, rc.Width(), rc.Height(), SWP_NOZORDER);

	//��Ԥ�����衱
	DrawEMPlanStep(stPlan);

	//�ύ
	//m_oSubmit = std::make_shared<CMyButton1>();
	GetClientRect(&rc);
	w = 40; h = 20; x = rc.right - w - 10; y = rc.bottom - h - 10;
	rc.SetRect(x, y, x + w, y + h);
	m_oSubmit->Create(_T("�ύ"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rc, this, IDC_Submit);
	m_oSubmit->Set(false, 16, cstClrTitle, Color(255, 255, 255));

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
	//��������
	SolidBrush sbr(cstClrTitle);
	gh.FillRectangle(&sbr, x, y, w, h);

	//д����
	FontFamily ff(_T("΢���ź�"));
	Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color(255, 255, 255));
	PointF pf(0.0f, 2.0f);
	gh.DrawString(_T("Ӧ��Ԥ��"), -1, &font, pf, &sbrText);


	if (!m_vecEmergPlan || m_vecEmergPlan->empty()) {//û��Ԥ��
		sbrText.SetColor(Color(255, 0, 0));
		pf.Y = cstnCaptionH + 1;
		gh.DrawString(_T("û��Ԥ����Ϣ��"), -1, &font, pf, &sbrText);
	}
	
}


void CEmergencyPlanDialog::OnStnClickedClosewindow()
{
	//PostQuitMessage(0);
	EndDialog(IDCANCEL);
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
		// nID��ʵ��HWND
		nID = ::GetDlgCtrlID((HWND)nID);
		if (nID >= IDC_EMPlanStep && nID < IDC_EMPlanStep + 10) { //Ԥ������
			CMyButton2* pBtn = (CMyButton2*)GetDlgItem(nID);
			auto& str = pBtn->GetFullText();
			_tcscpy_s(pTTT->szText, _countof(pTTT->szText), str);
		}
		
		bRet = TRUE;
		//if (nID)
		//{
		//	_stprintf_s(pTTT->szText, _countof(pTTT->szText),
		//		_T("Control ID = %d"), nID);
		//	pTTT->hinst = AfxGetResourceHandle();
		//	bRet = TRUE;
		//}
	}

	*pResult = 0;

	return bRet;
}

void CEmergencyPlanDialog::OnBtnClickedOtherEMPlan()
{
	//����Ԥ���б�
	static BOOL bCreate = FALSE;
	static bool bExpand = true;
	bExpand = !bExpand;
	if (bExpand){
		m_oOtherLB->ShowWindow(SW_HIDE);
		return;
	}
	

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

	
	if (bCreate) {
		m_oOtherLB->ResetContent();//���
		int nCnt = (int)m_vecEmergPlan->size();
		for (int i = 0; i < nCnt; ++i) {
			const auto& st = m_vecEmergPlan->at(i);
			m_oOtherLB->AddString(st.strPlanName);
			m_oOtherLB->SetItemData(i, (DWORD_PTR)&st);
		}
		m_oOtherLB->ShowWindow(SW_NORMAL);
	}
	
}


void CEmergencyPlanDialog::OnOtherEMPlanSelchange()
{
	int nSel = m_oOtherLB->GetCurSel();
	stEmergPlan& st = *(stEmergPlan*)m_oOtherLB->GetItemData(nSel);
	DrawEMPlanStep(st);
}


void CEmergencyPlanDialog::DrawEMPlanStep(const stEmergPlan& stPlan)
{
	CString str;
	m_oName->GetWindowText(str);
	if (str == stPlan.strPlanName)
		return;
	m_oName->SetWindowText(stPlan.strPlanName);
	m_oName->Invalidate(); //�Ի�����鷳

	int nStepCnt = (int)stPlan.vecStep.size();
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
		const auto& step = stPlan.vecStep[i];
		btn->Create(step.strName, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW /*| BS_NOTIFY*/,
			rc, this, IDC_EMPlanStep + i);
		//btn->SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
		m_tt.AddTool(btn.get());
	}
}