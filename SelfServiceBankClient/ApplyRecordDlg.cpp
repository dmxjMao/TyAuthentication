// ApplyRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "ApplyRecordDlg.h"
#include "afxdialogex.h"

#include "EmergencyPlanDialog.h" //Ӧ������

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

	/*����
	Create֮�����OnInitDialog�����Ի���SetWindowPos�����ĳߴ粻����
	SetWindowPos���������Ӵ�����
	*/
	//���Ͽ�ߣ�rc����ʱ����
	CRect rc = m_rcInParent;
	int x = rc.left, y = rc.top, w = rc.Width(), h = rc.Height();
	
	SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
	GetClientRect(&m_rcClient);

	//���ڲ��ֿؼ������궼Ҫ����ڿͻ�����
	//��������
	x = 10, y = 10, h /= 10; rc.bottom = y + h;
	GetDlgItem(IDC_title)->SetWindowPos(0, x, y, w - 30, h, SWP_NOZORDER);

	//��·��Ƶ��
	y = rc.bottom; w = h = m_rcInParent.Height() - y - 30/*30�� - �ָ��� - ���*/;
	m_oVideo1.SetWindowPos(nullptr, x, y, w, h, SWP_NOZORDER);
	x += w + 2;
	m_oVideo2.SetWindowPos(nullptr, x, y, w, h, SWP_NOZORDER);

	//��֤��Ա��ǩ����Բ���û��
	x += w + 4;
	GetDlgItem(IDC_Title2)->SetWindowPos(0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

	//���ָ��ߣ�OnInitDialog�Ի����Լ���û������

	//������֤��Ա��Ϣ
	GetDlgItem(IDC_Title2)->GetWindowRect(&rc);
	y += rc.Height() + 6;
	//LVS_EX_FLATSB  ��InsertItem֮����й�������LVS_NOCOLUMNHEADERռ�ͻ���
	m_oPersonInfo.CreateEx(LVS_EX_FLATSB | LVS_EX_DOUBLEBUFFER, LVS_REPORT | LVS_NOCOLUMNHEADER | LVS_OWNERDRAWFIXED | WS_CHILD | WS_VISIBLE,
		CRect(x, y, m_rcClient.right - 10, y + m_rcClient.Height() * 5 / 12 ), this, 1);
	//m_oPersonInfo.ShowScrollBar(SB_VERT, FALSE);
	//InitializeFlatSB(m_oPersonInfo.m_hWnd);
	//FlatSB_EnableScrollBar(m_oPersonInfo.m_hWnd, SB_BOTH, ESB_DISABLE_BOTH);
	//FlatSB_ShowScrollBar(m_oPersonInfo.m_hWnd, SB_VERT, FALSE);

	//�ţ�ͼƬ���ĵ�����
	m_oPersonInfo.GetClientRect(&rc);
	y += rc.Height() + 20/*���*/;
	m_oPicDoor.SetWindowPos(0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	m_oPicDoor.Set(_T("res\\closeddoor_32px.png"));

	//��ť���������ûһ�����
	y -= 15;
	w = rc.Width();//�����б���
	m_oPicDoor.GetClientRect(&rc);
	int nGap = 30;//��ť֮��ļ��
	//Ӧ������
	x += rc.Width() + 5; 
	w = (w - (rc.Width() + 5)/*��*/) / 3/*3����ť*/ - nGap;
	m_oEmergency.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//������Ȩ
	x += w + nGap;
	m_oGrant.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//����
	x += w + nGap;
	m_oOpen.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	m_oOpen.Set(false);
	//����ͼ��
	x -= 2 * (w + nGap);
	m_oEmergency.GetClientRect(&rc);
	y += rc.Height() + 2;
	m_oEnterMapLayer.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//����
	x += w + nGap;
	m_oLock.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	m_oLock.Set(false);
	//�ܾ�����
	x += w + nGap;
	m_oRefuseOpen.SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	m_oRefuseOpen.Set(false);
	//ȷ��
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
	
	//������֤��Ա�� - �ָ���
	Pen pen(Color(216, 216, 216), 2.0f);
	CRect rc;
	GetDlgItem(IDC_Title2)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	int x = rc.left, y = rc.bottom + 1;
	gh.DrawLine(&pen, x, y, m_rcClient.right - 20, y);

	//����¼֮��ķָ��� ֮����30px������
	GetDlgItem(IDC_Video1)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	x = rc.left, y = rc.bottom + 20;
	gh.DrawLine(&pen, x, y, m_rcClient.right - 5, y);

	//���֧�ֹܿأ������߿�
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
		//��ʱ����ʧЧ����N�룬������Ͳ���������
		//SetTimer(IDT_Valid, 5 * 1000, 0);
		//����ʣ��ʱ��
		CTimeSpan tmLeft = CTime::GetCurrentTime() - m_stApplyInfo->tmApply;
		if (tmLeft.GetTotalSeconds() < 30) {//С��10s
			SetTimer(IDT_Valid, (30 - (int)tmLeft.GetTotalSeconds()) * 1000, 0);
		}
		else {
			//OnTimer(IDT_Valid);  //���ڻ�û�����ã�����
			SetTimer(IDT_Valid, 0, 0);
		}
		

		//��������
		GetDlgItem(IDC_title)->SetWindowText(m_stApplyInfo->strWebSiteName);

		//������Ա�б�
		m_oPersonInfo.MyInsertSubItem(m_stApplyInfo->vecPersonInfo);
		//m_oPersonInfo.Update();  //���¶��˴�ֱ������
		//UpdateWindow();
		Invalidate();
		ShowWindow(SW_NORMAL);
	}
}

//��ť�һ�/���ô���
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
	case IDT_Valid: //����ʧЧ��
	{
		KillTimer(nIDEvent);
		//��ȡm_oVideo1.right������ʧЧ���Ŀ�
		CRect rc;
		m_oVideo1.GetWindowRect(&rc);
		ScreenToClient(&rc);
		Image img(_T("res\\��ʧЧ.png"));
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
		{stEmergPlan(_T("ҽԺ��ˮԤ��"), { stEmergPlanStep(1,_T("����")), stEmergPlanStep(2,_T("�ؾ������鿴ͣʬ���Ƿ�������˯����Ȼ��ػ�������������������ˮ�ܣ�������")) })},
		{ stEmergPlan(_T("��ɽ�緢Ԥ��"),{ stEmergPlanStep(1,_T("���´���")), stEmergPlanStep(2,_T("����ͷ����")) }) }
	};

	static auto sp = std::make_shared<vector<stEmergPlan>>(vecPlan);

	CEmergencyPlanDialog dlg(sp, this);
	dlg.DoModal();
}
