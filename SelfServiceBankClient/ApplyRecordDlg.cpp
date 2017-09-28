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

	/*����
	Create֮�����OnInitDialog�����Ի���SetWindowPos�����ĳߴ粻����
	SetWindowPos���������Ӵ�����
	*/
	//SetWindowPos(nullptr, m_rcClient.left, m_rcClient.top, m_rcClient.Width(), m_rcClient.Height(), SWP_NOZORDER);
	//GetClientRect(&m_rcClient); 
	//const auto& rc = m_rcClient;
	//���Ͽ�ߣ�rc����ʱ����
	CRect rc = m_rcInParent;
	int x = rc.left, y = rc.top, w = rc.Width(), h = rc.Height();
	
	SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
	GetClientRect(&m_rcClient);

	//���ڲ��ֿؼ������궼Ҫ����ڿͻ�����
	//��������
	x = 0, y = 0, h /= 10; rc.bottom = h;
	GetDlgItem(IDC_title)->SetWindowPos(0, x, y, w, h, SWP_NOZORDER);

	//��·��Ƶ
	y = rc.bottom; w = h = m_rcInParent.Height() - y - 15/*15�� - �ָ��� - ���*/;
	m_oVideo1.SetWindowPos(nullptr, x, y, w, h, SWP_NOZORDER);
	x += w + 1;
	m_oVideo2.SetWindowPos(nullptr, x, y, w, h, SWP_NOZORDER);

	//��֤��Ա��ǩ����Բ���û��
	x += w + 4;
	GetDlgItem(IDC_Title2)->SetWindowPos(0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

	//���ָ��ߣ�OnInitDialog�Ի����Լ���û������
	//CClientDC dc(this);
	//Graphics gh(dc.GetSafeHdc());
	//Pen pen(Color(255,0,0), 2.0f);
	//
	//GetDlgItem(IDC_Title2)->GetWindowRect(&rc);
	//y += rc.Height() + 1;
	//gh.DrawLine(&pen, x, y, m_rcClient.right - 5, y);


	//������֤��Ա��Ϣ
	GetDlgItem(IDC_Title2)->GetWindowRect(&rc);
	y += rc.Height() + 2;
	//LVS_EX_FLATSB  ��InsertItem֮����й�����
	m_oPersonInfo.CreateEx(LVS_EX_FLATSB, LVS_REPORT | LVS_OWNERDRAWFIXED | WS_CHILD | WS_VISIBLE, CRect(x, y, m_rcClient.right, y + m_rcClient.Height() / 2), this, 1);
#ifdef _DEBUG
	_DebugInsertPersonInfoListColumn(); //����������֤��Ա��Ϣ
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
	
	//������֤��Ա�� - �ָ���
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
	const CString str[] = { _T("��1"),_T("��2"),_T("��3"),_T("��4"),_T("��5"),_T("��6"),_T("��7"),_T("��8"),_T("��9"),_T("��10") };
	int n = _countof(str);
	CRect rc;
	m_oPersonInfo.GetClientRect(&rc);
	int w = rc.Width() / 2;
	for (auto i = 0; i < n; ++i) {
		m_oPersonInfo.InsertColumn(i, str[i], LVCFMT_LEFT, w);
	}

	const CString str2[] = { _T("�����"), _T("����ɽ"),_T("�鳤��"),_T("�����ǰ"),_T("��5"),_T("��6"),_T("��7"),_T("��8"),_T("��9"),_T("��10") };
	m_oPersonInfo.InsertItem(0, str2[0]);
	for (auto i = 1; i < n; ++i) {	
		m_oPersonInfo.SetItemText(0, i, str2[i]);
	}

}
#endif // _DEBUG
