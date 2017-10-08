
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

	m_liApplyRecordDlg.resize(cstnApplyRecordCnt);
}

void CSelfServiceBankClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CloseWindow, m_oCloseWindow);
	//  DDX_Control(pDX, IDC_ApplyList, m_oApplyList);
	//DDX_Control(pDX, IDC_ApplyList, m_oApplyList);
}

BEGIN_MESSAGE_MAP(CSelfServiceBankClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
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

	//���������ͻ����б�������֤��¼����SetRect����������ֵ
	ScreenToClient(&rc);
	m_rcCaption.SetRect(rc.left, rc.top, rc.Width(), cstnTitleHeight);
	m_rcClient.SetRect(rc.left, rc.top + cstnTitleHeight, rc.Width(), rc.Height());
	m_rcList.SetRect(m_rcClient.left + 1, m_rcClient.top + 1, m_rcClient.Width() / 6, m_rcClient.bottom);
	m_rcRecord.SetRect(m_rcList.right + 5, m_rcList.top, m_rcClient.right, m_rcList.bottom);
	//GetClientRect(&m_rcClient);

	//�ƶ��رհ�ť
	/*�Ի�����ؼ��ĵ���˳��1���ؼ����໯��2��OnInitDialog��3���Ի���OnPaint��4���ؼ�OnPaint*/
	m_oCloseWindow.Set(_T("res\\�������رճ�̬.png"), _T("res\\�������ر���ͣ.png"), false);
	rc.SetRect(rc.right - 24, rc.top, 0, 0);
	m_oCloseWindow.SetWindowPos(nullptr, rc.left, rc.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);//Ҫ�ͻ�������


	//�����б�
	m_oApplyList.Create(LBS_OWNERDRAWFIXED | LBS_HASSTRINGS | LBS_NOTIFY 
		| /*LBS_EXTENDEDSEL |*/ WS_CHILD | WS_VISIBLE /*| LBS_SORT*/, 
		CRect(0, 0, 0, 0), this, 1);
	//�ڱʼǱ���ʵ�ʸ߶Ȳ�����m_rcList.Height()����
	m_oApplyList.SetWindowPos(nullptr, m_rcList.left, m_rcList.top, m_rcList.Width(), m_rcList.Height(), SWP_NOZORDER);
	//m_oApplyList.MySetItemData(m_vecApplyInfo); //
	m_oApplyList.Set(this);

#ifdef  _DEBUG
	//CMyListBox1::ItemData d1 = { _T("��abc"), 2, CTime(2017,10,3,1,1,1) };
	//m_oApplyList.MyInsertString(d1);
#endif //  _DEBUG

	//������֤����Ի���
	int nDlgHeight = 
		m_rcClient.Height() / cstnApplyRecordCnt;//ÿ����¼�ĸ߶��� 1/n ������ - �ָ��� - ��� 30px��
	int i = 0;
	for (/*auto i = 0; i < cstnApplyRecordCnt; ++i*/auto& dlg : m_liApplyRecordDlg) {
		//auto& dlg = m_liApplyRecordDlg;
		int x = m_rcRecord.left, y = m_rcRecord.top + i++ * nDlgHeight;
		dlg.SetRectInParent(CRect(x, y, m_rcRecord.right,
			y + nDlgHeight/*x + m_rcRecord.Width(), y + nDlgHeight*/));//�����ڸ������е�����

		dlg.Create(IDD_ApplyRecordDlg, this);
		/*dlg.SetWindowPos(nullptr,
			m_rcRecord.left, m_rcRecord.top + i * nDlgHeight,
			m_rcRecord.Width(), nDlgHeight - 15, SWP_NOZORDER);*/
		//dlg.ShowWindow(SW_NORMAL);
	}

#ifdef  _DEBUG
	//����һЩ������Ա��Create֮����OnInitDialog������OnInitDialog�ﻹû�����ݣ�
	//Ӧ����OnPaint����
	//_DebugInsertSomeApplyPersonInfo();
	/*ģ������һ�����루һ���˻���������ص��ˣ���
	һ��һ�����ϸ��ӣ��ṹ���Ա��α�ʶ����һ�����룿��ListBoxҪ�ϲ�����ListCtrlҪ�ϲ���
	��ʱ��ȫ��������Ա��
	//��haoyun->����->��-����-������  //�ң�����-��haoyun-������
	*/
	_DebugInsertApplyInfo(stApplyInfo(_T("����"), 0, CTime(2017, 8, 28, 10, 7, 34),
	{ stApplyPersonInfo(_T("person1.jpg"), _T("person1"), _T("�Ž�����վ"), _T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person2.jpg"),_T("person2"), _T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person3.jpg"),_T("person3"), _T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person4.jpg"),_T("person4"),_T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person5.jpg"),_T("person5"),_T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person6.jpg"),_T("person6"),_T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person7.jpg"),_T("person7"),_T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person8.jpg"),_T("person8"),_T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person9.jpg"),_T("person9"),_T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person10.jpg"),_T("person10"),_T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person11.jpg"),_T("person11"),_T("�Ž�����վ"),_T("�ڲ���Ա")),
	stApplyPersonInfo(_T("person12.jpg"),_T("person12"),_T("�Ž�����վ"),_T("�ڲ���Ա"))
	}));
	_DebugInsertApplyInfo(stApplyInfo(_T("����"), 0, CTime(2017, 9, 28, 10, 8, 34),
	{ stApplyPersonInfo(_T("person1.jpg"), _T("person1"), _T("�Ž�����վ"), _T("�ڲ���Ա"))
	}));
	_DebugInsertApplyInfo(stApplyInfo(_T("haoyun"), 1, CTime(2017, 9, 27, 10, 9, 34),
	{ stApplyPersonInfo(_T("person1.jpg"), _T("person1"), _T("�Ž�����վ"), _T("�ڲ���Ա")),
		stApplyPersonInfo(_T("person3.jpg"),_T("person3"), _T("�Ž�����վ"),_T("�ڲ���Ա"))
	}));
	_DebugInsertApplyInfo(stApplyInfo(_T("��"), 3, CTime(2017, 9, 1, 10, 7, 34),
	{ stApplyPersonInfo(_T("person1.jpg"), _T("person1"), _T("�Ž�����վ"), _T("�ڲ���Ա")),
		stApplyPersonInfo(_T("person3.jpg"),_T("person3"), _T("�Ž�����վ"),_T("�ڲ���Ա"))
	}));
#endif //  _DEBUG

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSelfServiceBankClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

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

	//д����
	FontFamily ff(_T("΢���ź�"));
	Gdiplus::Font font(&ff, 16, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color(255, 255, 255));
	PointF pf(5.0f, 5.0f);
	gh.DrawString(_T("�Ž���֤��Ϣ"), -1, &font, pf, &sbrText);

	//��û�и������֤��Ϣ�� ��ʾ
	StringFormat sf;
	//sf.SetAlignment(StringAlignmentCenter);//�ı�����
	//sf.SetLineAlignment(StringAlignmentCenter);//���¾���
	RectF rcGdiF((m_rcRecord.left + 10) * 1.0f, (m_rcRecord.top+10) * 1.0f, 
		m_rcRecord.right * 1.0f, m_rcRecord.bottom * 1.0f / 3);
	sbrText.SetColor(Color(255, 0, 0));
	Gdiplus::Font fontTip1(&ff, 20, FontStyleRegular, UnitPixel);
	gh.DrawString(_T("����û��������֤��Ϣ��"), -1, &fontTip1, rcGdiF, &sf, &sbrText);


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
void CSelfServiceBankClientDlg::_DebugInsertApplyInfo(stApplyInfo&& st)
{
	//�����Ϣ��һ����һ�������ģ��Ȳ����Ƿ��и�����ͨ��

	//sp����1��m_vecApplyInfo����2��MyInsertString���������ò���
	auto& sp = std::make_shared<stApplyInfo>(st);
	m_vecApplyInfo.push_back(sp);

	//���뵽��������б�
	m_oApplyList.MyInsertString(sp);
	
	//���뵽�Ҳ���������
	MyInsertRecord(sp);
}
#endif //_DEBUG

//��������ʱ��
bool Lambda_InsertRecord(CApplyRecordDlg& dlg, const std::shared_ptr<stApplyInfo>& st)
{
	auto& sp = dlg.GetApplyInfo();
	return nullptr == sp || st->tmApply < sp->tmApply;
}

bool Lambda_SortRecordList(const CApplyRecordDlg& dlg1,
	const CApplyRecordDlg& dlg2)
{
	const auto& st1 = dlg1.GetApplyInfo();
	const auto& st2 = dlg2.GetApplyInfo();
	if (!st1 || !st2)
		return false;
	return st1->tmApply < st2->tmApply;
}

//���Ի����������ݷ����仯�ĸ�����ʾ��������
//��Doc-View���Ҳ���һ����CView�����vector<CRecord>
void CSelfServiceBankClientDlg::MyInsertRecord(const std::shared_ptr<stApplyInfo>& st)
{
	//��st���ĸ�ʱ����
	using std::placeholders::_1;
	auto it = std::find_if(m_liApplyRecordDlg.begin(), m_liApplyRecordDlg.end(),
		std::bind(Lambda_InsertRecord, _1, st));

	if (m_liApplyRecordDlg.end() != it) {
		if (nullptr == it->GetApplyInfo()) {
			it->SetApplyInfo(st);
		}
		else {
			auto& lastDlg = *m_liApplyRecordDlg.rbegin();
			lastDlg.SetApplyInfo(st);
		}
	}
	m_liApplyRecordDlg.sort(Lambda_SortRecordList);
	for (auto& dlg : m_liApplyRecordDlg) {
		dlg.Update();
	}

	//����У��滻���һ���������˳��
	//if (m_liApplyRecordDlg.end() != it) {
	//	//
	//	if (nullptr == it->GetApplyInfo()) {
	//		it->SetApplyInfo(st);
	//		return;
	//	}

	//	//�滻���һ������ʾ
	//	auto& lastDlg = m_vecApplyRecordDlg[cstnApplyRecordCnt - 1];
	//	lastDlg.SetApplyInfo(st);
	//	//�����ƶ���it����λ��
	//	int nDis = std::distance(m_vecApplyRecordDlg.begin(), it);
	//	CRect rc;
	//	lastDlg.GetClientRect(&rc);
	//	lastDlg.SetWindowPos(0, m_rcRecord.left,
	//		m_rcRecord.top + nDis*rc.Height(), 0, 0, 
	//		SWP_NOZORDER | SWP_NOSIZE);
	//	//����˳��
	//	for (int i = cstnApplyRecordCnt - 2; i >= nDis; --i) {
	//		auto& moveDlg = m_vecApplyRecordDlg[i];
	//		moveDlg.SetWindowPos(0, m_rcRecord.left,
	//			m_rcRecord.top + (i + 1)*rc.Height(), 0, 0,
	//			SWP_NOZORDER | SWP_NOSIZE);
	//	}
	//	
	//}
	//else { //stû�б�˭��
	//	for (auto& dlg : m_vecApplyRecordDlg) {
	//		if (nullptr == dlg.GetApplyInfo())
	//			dlg.SetApplyInfo(st);
	//	}
	//}

	
}

void CSelfServiceBankClientDlg::DisplayDetail(const std::shared_ptr<stApplyInfo>& st)
{
	//���Ҳ��һ����ʾ��ԭ�Ҳ��һ����Ϣ�����������������ʾ
	//int n = m_liApplyRecordDlg.size();
	auto& dlg = *m_liApplyRecordDlg.begin();
	dlg.SetApplyInfo(st);
	dlg.Update();
}

