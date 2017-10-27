
// SelfServiceBankClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "SelfServiceBankClientDlg.h"
#include "afxdialogex.h"

#include "MyCommonDefine.h"
#include "LogDialog.h"
#include "MyStg.h"
#include "ZCMsgManager.h"
#include "MyStatic1.h"
#include "MyListBox1.h"
#include "ApplyRecordDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//��������
#include "TYServerSDK.h"
//�����
#include "LoadTJTY_Play.h"

stVideoInfo g_stVideInfo;

namespace {
	using std::vector;
	using std::shared_ptr;
	using std::make_shared;
	using std::placeholders::_1;
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
	//
	
	
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_vecApplyRecordDlg.resize(cstnApplyRecordCnt);
	for (int i = 0; i < cstnApplyRecordCnt; ++i) {
		m_vecApplyRecordDlg[i] = make_shared<CApplyRecordDlg>(i, this);
	}

	m_oLogDlg = make_shared<CLogDialog>();
	m_oStg = make_shared<CStgOperator>();

	m_oCloseWindow = make_shared<CMyStatic1>();
	m_oApplyList = make_shared<CMyListBox1>(this);

	//ZCMsg��Ϣӳ��
	InitZCMsgHandler();
}

CSelfServiceBankClientDlg::~CSelfServiceBankClientDlg()
{
	//TJTY_PLAY_StopPlay(g_stVideInfo.nPlayID);
	//TY_Server_StopPlay(g_stVideInfo.nPlayID, g_stVideInfo.nLinkType);
}

void CSelfServiceBankClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CloseWindow, *m_oCloseWindow);
	//  DDX_Control(pDX, IDC_ApplyList, m_oApplyList);
	//DDX_Control(pDX, IDC_ApplyList, m_oApplyList);
	//  DDX_Control(pDX, IDC_demoVideo, m_oDemoVideo);
	DDX_Control(pDX, IDC_demoVideo, m_demoVideo);
}

BEGIN_MESSAGE_MAP(CSelfServiceBankClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	//ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_CloseWindow, &CSelfServiceBankClientDlg::OnStnClickedClosewindow)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CSelfServiceBankClientDlg::OnBnClickedButton1)
	ON_STN_DBLCLK(IDC_demoVideo, &CSelfServiceBankClientDlg::OnDblclkDemovideo)
END_MESSAGE_MAP()


// CSelfServiceBankClientDlg message handlers

BOOL CSelfServiceBankClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��ӡ����ڡ����˵���

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		vector<std::tuple<int, CString>> vecMenu = { 
			{ IDM_ABOUTBOX,_T("����")}/*,
			{ IDM_Log,_T("��־") }*/ };
		//vector<int> vecMenu = { IDM_ABOUTBOX , IDM_Log };

		//BOOL bNameValid;
		//CString strAboutMenu;
		//bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		//ASSERT(bNameValid);
		//if (!strAboutMenu.IsEmpty())
		//{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		for (const auto& tpl : vecMenu) {
			pSysMenu->AppendMenu(MF_STRING, std::get<0>(tpl), std::get<1>(tpl));
		}
		
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	/*����*/
	//�ƶ������棬������С�ߴ磬����С��Ļ��ť����������
	int cx = ::GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = ::GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rc(0, 0, cx, cy);
	rc.DeflateRect(cx / 5, cy / 15);//���Ҹ���С1/4���߿����
	if (rc.Width() < 1000)
		rc.SetRect(rc.left, rc.top, rc.left + 1000, rc.bottom);
	SetWindowPos(nullptr, rc.left, rc.top, rc.Width(), rc.Height(), SWP_NOZORDER);//��Ļ����

	//���������ͻ����б�������֤��¼����SetRect����������ֵ
	ScreenToClient(&rc);
	m_rcCaption.SetRect(rc.left, rc.top, rc.Width(), theApp.m_oGobal->cstnTitleHeight);
	m_rcClient.SetRect(rc.left, rc.top + theApp.m_oGobal->cstnTitleHeight, rc.Width(), rc.Height());
	m_rcList.SetRect(m_rcClient.left + 1, m_rcClient.top + 1, m_rcClient.Width() / 6, m_rcClient.bottom);
	m_rcRecord.SetRect(m_rcList.right + 5, m_rcList.top, m_rcClient.right, m_rcList.bottom);
	//GetClientRect(&m_rcClient);


	//�ƶ��رհ�ť
	/*�Ի�����ؼ��ĵ���˳��1���ؼ����໯��2��OnInitDialog��3���Ի���OnPaint��4���ؼ�OnPaint*/
	m_oCloseWindow->Set(_T("res\\�������رճ�̬.png"), _T("res\\�������ر���ͣ.png"), false);
	rc.SetRect(rc.right - 24, rc.top, 0, 0);
	m_oCloseWindow->SetWindowPos(nullptr, rc.left, rc.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);//Ҫ�ͻ�������


	//�����б�
	m_oApplyList->Create(LBS_OWNERDRAWFIXED | LBS_HASSTRINGS | LBS_NOTIFY 
		| /*LBS_EXTENDEDSEL |*/ WS_CHILD | WS_VISIBLE /*| LBS_SORT*/, 
		CRect(0, 0, 0, 0), this, 1);
	//�ڱʼǱ���ʵ�ʸ߶Ȳ�����m_rcList.Height()����
	m_oApplyList->SetWindowPos(nullptr, m_rcList.left, m_rcList.top, m_rcList.Width(), m_rcList.Height(), SWP_NOZORDER);
	//m_oApplyList.MySetItemData(m_vecApplyInfo); //
	//m_oApplyList->Set(this);


	//������֤����Ի���
	int nDlgHeight = 
		m_rcClient.Height() / cstnApplyRecordCnt;//ÿ����¼�ĸ߶��� 1/n ������ - �ָ��� - ��� 30px��
	int i = 0;
	for (/*auto i = 0; i < cstnApplyRecordCnt; ++i*/auto& dlg : m_vecApplyRecordDlg) {
		//auto& dlg = m_liApplyRecordDlg;
		int x = m_rcRecord.left, y = m_rcRecord.top + i++ * nDlgHeight;
		dlg->SetRectInParent(CRect(x, y, m_rcRecord.right,
			y + nDlgHeight/*x + m_rcRecord.Width(), y + nDlgHeight*/));//�����ڸ������е�����

		dlg->Create(IDD_ApplyRecordDlg, this);
	}

#ifdef DEBUG
	//demo��Ƶ
	m_demoVideo.SetWindowPos(0, m_rcRecord.left + 10, m_rcRecord.top + 100, 200, 200, SWP_NOZORDER);

#endif // DEBUG

	//��ʼ����Ϣ������Ϊ����Ԫ�ؿ�����һ���۲��ߣ�����Ҫ�Ƚ����ʼ�����
	if (!CZCMsgManager::Instance()->Init(0))
		return FALSE;
	
	//��ȡ��ʷ�����¼����ʾ
	GetHistoryApplyAndDisplay();
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSelfServiceBankClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	//��4λϵͳʹ��
	UINT id = nID & 0xFFF0;
	if (IDM_ABOUTBOX == id)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if (IDM_Log == id) {
		//auto& pDlg = theApp.GetLogDlg();
		if(nullptr == m_oLogDlg->GetSafeHwnd()){
			m_oLogDlg->Create(IDD_Log, this);
		}
		m_oLogDlg->ShowWindow(SW_NORMAL);
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
	SolidBrush sbr(theApp.m_oGobal->cstClrTitle);
	gh.FillRectangle(&sbr, x, y, w, theApp.m_oGobal->cstnTitleHeight);

	//д����
	FontFamily ff(_T("΢���ź�"));
	Gdiplus::Font font(&ff, 16, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color(255, 255, 255));
	PointF pf(5.0f, 5.0f);
	gh.DrawString(_T("�Ž���֤��Ϣ"), -1, &font, pf, &sbrText);

	//��û�и������֤��Ϣ�� ��ʾ
	//if (0 == m_oApplyList->GetCount()) {
	//	StringFormat sf;
	//	//sf.SetAlignment(StringAlignmentCenter);//�ı�����
	//	//sf.SetLineAlignment(StringAlignmentCenter);//���¾���
	//	RectF rcGdiF((m_rcRecord.left + 10) * 1.0f, (m_rcRecord.top + 10) * 1.0f,
	//		m_rcRecord.right * 1.0f, m_rcRecord.bottom * 1.0f / 3);
	//	sbrText.SetColor(Color(255, 0, 0));
	//	Gdiplus::Font fontTip1(&ff, 20, FontStyleRegular, UnitPixel);
	//	gh.DrawString(_T("����û��������֤��Ϣ��"), -1, &fontTip1, rcGdiF, &sf, &sbrText);
	//}


#ifdef _DEBUG

	//CMyButton1 btn1;
	//btn1.Create(_T("BTN1"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
	//	CRect(0, 0, 0, 0), this, 123);
	//btn1.SetUICfg("underline,0");
	//btn1.SetWindowPos(nullptr, m_rcList.left, m_rcList.top, m_rcList.Width(), m_rcList.Width(), SWP_NOZORDER);

	//btn1.ShowWindow(SW_NORMAL);
#endif // _DEBUG

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


//��ȡ��ʷ�����¼����ʾ
void CSelfServiceBankClientDlg::GetHistoryApplyAndDisplay()
{
	//��ȡ��ǰ����id
	m_dwApplyID = m_oStg->GetApplyID();

	//��ȡstg����ʾ��ʷ��¼��ǰN�������죬���죬��������ͬ�ķ������������
	vector<stApplyInfo> vecApplyLog;
	m_oStg->GetRecentNRecord(100, vecApplyLog);

	for (const auto& stLog : vecApplyLog) {
		//auto& sp = make_shared<stApplyInfo>();

		//InsertApplyInfo
	}
	
}

void CSelfServiceBankClientDlg::InsertApplyInfo(const shared_ptr<stApplyInfo>& sp)
{
	//���뵽��������б�
	m_oApplyList->MyInsertString(sp);
	
	//���뵽�Ҳ���������
	MyInsertRecord(sp);
}




//���ܼ򵥵Ĳ��룬����Ƕ������룬��Ա��ϢҪ����ش��ݸ�CListCtrl
void CSelfServiceBankClientDlg::MyInsertRecord(const shared_ptr<stApplyInfo>& st)
{
	//if (st->nSlave > -1) {//����ˢ��
	//					  //�����Ƿ��и����㡢��λ��ˢ����Ϣ
	//	auto it = std::find_if(m_vecApplyInfo.begin(), m_vecApplyInfo.end(),
	//		std::bind(Lambda_FindApplyInfo, _1, st->strWebSiteName, st->strPartName));
	//	if (m_vecApplyInfo.end() != it) {
	//		return;
	//	}
	//}


	//��st���ĸ�ʱ���磬����m_liApplyRecordDlg�����궼���ˣ����Բ��ܶ�m_vecApplyRecordDlg
	
	vector<shared_ptr<stApplyInfo>> vec;
	for (auto& st : m_vecApplyRecordDlg)
		vec.push_back(st->GetApplyInfo());

	auto it = std::find_if(vec.begin(), vec.end(),
		std::bind(lambda_InsertRecord, _1, st));
	if (vec.end() != it) {//����Ϊ�ջ����ļ�¼��������ɶҲ����
		int i = std::distance(vec.begin(), it);
		auto itDlg = m_vecApplyRecordDlg.begin();
		std::advance(itDlg, i);
		if (nullptr == *it) {//�ռ�¼
			(*itDlg)->SetApplyInfo(st, true);
			//(*itDlg)->Update();
		}
		else {//�滻���������
			auto& last = *vec.rbegin();
			last = st;
			sort(vec.begin(), vec.end(), lambda_SortApplyVector);
			for (/*auto& st : vec*/int i = 0; i < (int)vec.size(); ++i) {
				auto& dlg = m_vecApplyRecordDlg[i];
				if (vec[i] == dlg->GetApplyInfo())
					continue;
				dlg->SetApplyInfo(vec[i], true);
				//dlg->Update();
			}
		}
	}
}

void CSelfServiceBankClientDlg::DisplayDetail(const shared_ptr<stApplyInfo>& st)
{
	//���Ҳ��һ����ʾ��ԭ�Ҳ��һ����Ϣ�����������������ʾ
	//int n = m_liApplyRecordDlg.size();
	auto& dlg = *m_vecApplyRecordDlg.begin();
	dlg->SetApplyInfo(st);
	//dlg->Update();
}

//�رռ�¼��ɾ����ߣ��ұ�
void CSelfServiceBankClientDlg::DeleteRecord(int idx)
{
	if (idx >= 0 && idx < cstnApplyRecordCnt) {
		auto& pDlg = m_vecApplyRecordDlg[idx];
		//���
		m_oApplyList->MyDeleteString(pDlg->GetApplyInfo());
		//�ұ�
		pDlg->SetApplyInfo(0);
	}
}

//ʧЧ����
void CSelfServiceBankClientDlg::RemoveApply(const shared_ptr<stApplyInfo>& st)
{
	auto it = std::find_if(m_vecApplyInfo.begin(), m_vecApplyInfo.end(),
		std::bind(lambda_FindApplyInfo, _1, st));
	if (m_vecApplyInfo.end() == it)
		return;

	m_vecApplyInfo.erase(it);
}

void CSelfServiceBankClientDlg::Update(bool bOK, DWORD dwType, DWORD dwMsgID, PBYTE pMsg, INT nMsgLen)
{
	if (bOK) {
		auto it = m_mapZCMsgHandler.find(dwType);
		if (m_mapZCMsgHandler.end() != it) {
			auto& pfun = it->second;
			(this->*pfun)(pMsg, dwMsgID, nMsgLen);
		}
	}
	//else {
	//	extern std::map<DWORD, TCHAR*> g_mapZCMsgErrInfo;
	//	theApp.WriteLog(error, g_mapZCMsgErrInfo[dwType]);
	//}
}



void CSelfServiceBankClientDlg::InitZCMsgHandler()
{
	//ע���Լ�����Ȥ����Ϣ������������
	m_mapZCMsgHandler = { /*<������ ������>*/
		{ ZC_MSG_ALARM_NEWALARMINFO_EX, &CSelfServiceBankClientDlg::ZCMsgAuthentication },//ˢ����֤��Ϣ
		//{ ZC_MSG_ALARM_NEWALARMINFO, &CSelfServiceBankClientDlg::ZCMsgAuthentication }//ˢ����֤��Ϣ����������
		{ ZC_MSG_COMMON_CONTROLACSHOST , &CSelfServiceBankClientDlg::ZCMsgOpenDoor}//�����š� + ����
	};
}



//ˢ����֤����
void CSelfServiceBankClientDlg::ZCMsgAuthentication(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	//T_TRANSMITALARMINFO
	int nStructLen = sizeof(T_TRANSMITALARMINFO_EX);
	if (nMsgLen != nStructLen) {
		theApp.WriteLog(error, _T("ˢ����Ϣ��������"));
		return;
	}

	T_TRANSMITALARMINFO_EX* pAuthInfo = (T_TRANSMITALARMINFO_EX*)pMsg;
	//���Ž���Ϣ
	int nDevID = pAuthInfo->tTransmitAlarmInfo.nDevNumber; //ˢ���豸id
	const auto& mapACSHostInfo = theApp.m_mapACSHostInfo;
	
	auto itACSHost = std::find_if(mapACSHostInfo.begin(), mapACSHostInfo.end(),
		std::bind(lambda_FindACSHostByDevNo, _1, nDevID)); //itACSHost��һ��pair
	
	if (mapACSHostInfo.end() == itACSHost) {
		theApp.WriteLog(error, _T("û���ҵ��Ž�������"));
		return;
	}
	const auto& pHostInfo = (itACSHost->second);//�Ž�������Ϣ
	const auto& stCtrlPlan = theApp.GetCtrlPlanInfo(pHostInfo->nCtrlLevel);//��Ӧ�Ĺܿز���

	//��ǰ�û��Ƿ�������Ž�
	const auto& pVecDealHost = theApp.m_mapUserInfo[theApp.m_strCurUserName]->pDealedACSHost;
	if (!pVecDealHost || pVecDealHost->empty()) return; //�������κ��Ž�

	auto itDealHost = std::find_if(pVecDealHost->begin(), pVecDealHost->end(),
		std::bind(lambda_FindDealHostByID, _1, nDevID));
	if (pVecDealHost->end() == itDealHost) return; //��������Ž�


	if (1 == stCtrlPlan->nAuthType) {//Զ����֤
		RemoteAuth(pAuthInfo->tTransmitAlarmInfo, pHostInfo);
	}
	else if (pHostInfo->nCtrlLevel > 0) {//������֤�����ز��ܿأ����ļ�أ�
		LocalAuth(pAuthInfo->tTransmitAlarmInfo, pHostInfo);
	}
	else {//������֤�����عܿأ��������ļ�أ�
		theApp.WriteLog(warning, _T("������֤�����عܿأ��������ļ�أ�������ʾ��"));
		return;
	}

}



CTime CSelfServiceBankClientDlg::ZCMsgHelper_ParseTime(const char* szTime)
{
	//CString strTime(szTime);
	int nYear, nMonth, nDate, nHour, nMin, nSec;
	sscanf_s(szTime, "%d-%d-%d %d:%d:%d", &nYear, &nMonth, &nDate, &nHour, &nMin, &nSec);
	return CTime(nYear, nMonth, nDate, nHour, nMin, nSec);
}


//�Ƿ�������

bool CSelfServiceBankClientDlg::IfDealTheApplyMsg(const CString& strCardNum/*, const CTime& tmApply*/)
{
	//�ÿ��ŵ������Ƿ��ڶ�����
	auto it = std::find_if(m_vecApplyInfo.begin(), m_vecApplyInfo.end(),
		std::bind(lambda_FindApplyInfoByCardID, _1, strCardNum));
	if (m_vecApplyInfo.end() == it) { //����
		return true;
	}
	//ʧЧ�Զ�ɾ�����ѷ���ɾ����������
	return false;
}


//"����" + ���� = ���ţ����ζ��᷵��
void CSelfServiceBankClientDlg::ZCMsgOpenDoor(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	//

	static UINT8 cnt[cstnApplyRecordCnt] = { 0 };
	if (dwMsgID >= 0 && dwMsgID < cstnApplyRecordCnt) {
		cnt[dwMsgID] = ++cnt[dwMsgID] % 2;
		//�ı�ͼ�꣬"����" + ����������
		if (0 == cnt[dwMsgID]) {//����
			//Ҫ���ʳ�Ա���ֲ����CApplyRecordDlg��Ϊ�۲��ߣ���Ҫ�鷳����
			auto& dlg = m_vecApplyRecordDlg[dwMsgID];
			dlg->m_oPicDoor->Set(_T("res\\����_58-74-_��.bmp"));
			dlg->m_oPicDoor->Invalidate();

			vector<emButton> vecBtn = { OpenDoorBtn };
			dlg->EnableButton(vecBtn, false);
			//AfxMessageBox(_T("���ųɹ���"));
		}
		else {//����
			//����Ҫ�ص�
		}
	}
	
	//��������š���������һ�����ɹ�������ֻ�᷵�سɹ���

}




// Ԥ������Ƶ�ص�
void __stdcall RealPlayDataCallBack2(long lHandle, DWORD dwDataType, BYTE *pBuffer,
	DWORD dwBufSize, DWORD dwUser)
{
	//��������
	//CSelfServiceBankClientDlg* pDlg = (CSelfServiceBankClientDlg*)dwUser;
	const stVideoInfo& st = g_stVideInfo;
	bool bRet = false;

	static DWORD dwBuffSize = (1024 << 10); //����������������������С
	static int nBuffNum = 25;//��������������󻺴�֡��
	static UINT8 nWndNo = 1;  //��st.nPlayID������

	switch (dwDataType)
	{
	case SYSHEAD_DATA: //ϵͳͷ��Ϣ
	{
		bRet = TJTY_PLAY_InitplayStyle(nWndNo, st.nFactoryType);
		bRet = TJTY_PLAY_SetStreamOpenMode(nWndNo, 0);				//����Ϊʵʱ�����ţ�Hik��dh��Ч

		int nHeaderSize = 40;		//�����󻪵�����������ƵͷΪ40�ֽ�
		if (TJTY_DVR_BSR == st.nFactoryType || TJTY_DVR_BSR7 == st.nFactoryType) {//����ϵ��Ϊ256�ֽ���Ƶͷ
			nHeaderSize = 256;
		}
		bRet = TJTY_PLAY_StartPlay(nWndNo, (BYTE*)pBuffer, nHeaderSize, dwBuffSize, st.pWnd->GetSafeHwnd(), nBuffNum);
		if (!bRet) {
			theApp.WriteLog(warning, _T("������Ƶʧ�ܣ�����id��%d"), st.nFactoryType);
			//LOG(ERROR) << "TJTY_PLAY_StartPlay failed. Error:" << TJTY_PLAY_GetLastError(TJTY_PLAY_PORT_NUM);
		}
		break;
	}
	case AUDIO_AND_VIDEO_DATA://����Ƶ�������
	{
		bRet = TJTY_PLAY_InputData(nWndNo, (BYTE*)pBuffer, dwBufSize);
		UINT uiFailCount = 3;
		while (!bRet && uiFailCount--)
		{
			//Ͷ��ʧ�ܱ����������������ԵȺ�����Ͷ��
			Sleep(40);
			bRet = TJTY_PLAY_InputData(nWndNo, (BYTE*)pBuffer, dwBufSize);
			if (!bRet && uiFailCount == 0)
			{
				//LOG(ERROR) << "TJTY_PLAY_InputData failed. Error:" << TJTY_PLAY_GetLastError(TJTY_PLAY_PORT_NUM);
			}
		}
	}
	default:
		break;
	}

	//�ط�¼��
}


void CSelfServiceBankClientDlg::OnBnClickedButton1()
{
	if (g_stVideInfo.pWnd)
		return;

	//��������Ԥ���ṹ
	T_VIEW_APPLYINFO tViewInfo = { 0 };
	tViewInfo.TDEVIDInfo.lDEVID = 8; //��Ծ��ǹ��3
	//vector<long> vecTmp = { itDealHost->nCenterNo,0,0,0,0 };
	//for(int i=0;i<5;++i)
	tViewInfo.TDEVIDInfo.lCMSCascadeInfo[0] = 102;
	tViewInfo.nStreamType = TJTY_SOFT_EMAP; //����
	tViewInfo.nViewMode = 0;	// ��ͨԤ��
	tViewInfo.nChannel = 3;

	int nLinkType = -1;
	T_DEV_LOGIN_INFO stLoginInfo;
	//����Ԥ�����������-1ʧ�ܣ�TY_Server����ͬ���ģ���㰴ť���½��濨��
	long nPlayID = TY_Server_RequestPlay(theApp.m_oGobal->nCMSHander, &tViewInfo, nLinkType, &stLoginInfo);
	DWORD dwErr = TY_Server_GetLastError();
	if (-1 == nPlayID) {
		theApp.WriteLog(error, _T("����Ԥ��ʧ�ܣ��豸id��%d"), 8);
		return;
	}

	//static stVideoInfo vi;
	g_stVideInfo.nPlayID = nPlayID;
	g_stVideInfo.pWnd = &m_demoVideo;
	g_stVideInfo.nLinkType = nLinkType;
	g_stVideInfo.nFactoryType = 1;

	//��ʼԤ����ֻ�в����˾�ý��ת���ķ�ʽ�ŵ��ø÷�����ֱ��Ҫʹ�������
	int nRet = TY_Server_StartPlay(nPlayID, RealPlayDataCallBack2, 0);
	if (nRet != 0) {//0�ɹ�������ʧ��
		theApp.WriteLog(error, _T("��ʼԤ��ʧ�ܣ��豸id��%d"), 8);
		return;
	}
}


void CSelfServiceBankClientDlg::OnDblclkDemovideo()
{
	static bool bZoom = false;
	CRect rc;
	m_demoVideo.GetWindowRect(&rc);
	ScreenToClient(&rc);
	static CRect rcOri = rc; //����

	int x = 0, y = 0, w = 0, h = 0;
	if (bZoom) {//�Ŵ�˫������С
		x = rcOri.left, y = rcOri.top, w = rcOri.Width(), h = rcOri.Height();
		bZoom = false;
	}
	else {
		x = m_rcClient.left, y = m_rcClient.top, w = m_rcClient.Width(), h = m_rcClient.Height();
		bZoom = true;
	}
	m_demoVideo.SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
}



//������֤
void CSelfServiceBankClientDlg::LocalAuth(const T_TRANSMITALARMINFO& pAuthInfo, const shared_ptr<stACSHostInfo>& pHostInfo)
{
	bool bRet = CreateApplyInfo(pAuthInfo, pHostInfo, 0);
	if (!bRet)
		return;
}

//Զ����֤
void CSelfServiceBankClientDlg::RemoteAuth(const T_TRANSMITALARMINFO& stAuthInfo, const shared_ptr<stACSHostInfo>& pHostInfo)
{
	bool bRet = CreateApplyInfo(stAuthInfo, pHostInfo, 1);
	if (!bRet)
		return;
}


//����������Ϣ
bool CSelfServiceBankClientDlg::CreateApplyInfo(const T_TRANSMITALARMINFO& stAuthInfo, 
	const shared_ptr<stACSHostInfo>& pHostInfo, UINT8 nLocal)
{
	//��������ˢ����Ϣ
	CString strAuthMemo(stAuthInfo.tAlarmInfo.chMemo);
	theApp.WriteLog(trace, _T("�յ�ˢ����֤��Ϣ��%s"), strAuthMemo);

	//����ˢ����Ϣ���ִ��ֶΣ��Ƿ�Ϸ� | ���� | ���֤�� "0"--�Ƿ���"1"--�Ϸ�����2��--��Ȩ��
	vector<CString> vecMemo;
	SplitString(strAuthMemo, _T('|'), vecMemo);
	assert(vecMemo.size() >= 2);

	//���ݿ����ж��Ƿ���Ҫ�����������룬���磺1�����������
	if (!IfDealTheApplyMsg(vecMemo[1])) {
		theApp.WriteLog(warning, _T("�ظ����룡"));
		return false;
	}

	//����������Ϣ
	auto& spApplyInfo = std::make_shared<stApplyInfo>();
	spApplyInfo->stPersonInfo = std::make_shared<stApplyPersonInfo>();
	auto& spApplyPersonInfo = spApplyInfo->stPersonInfo;

	spApplyInfo->nApplyID = ++m_dwApplyID % 10000; 
	spApplyInfo->nLocal = nLocal;//����orԶ����֤
	spApplyInfo->nImportance = pHostInfo->nCtrlLevel;//�ܿصȼ�
	spApplyInfo->nDevID = stAuthInfo.nDevNumber;//ˢ���豸id
	spApplyInfo->strDevName = CString(pHostInfo->stBaseInfo.chDevName); //ˢ���豸����

	spApplyInfo->nSlave = pHostInfo->nSlave;//�Ƿ�����ˢ��
	spApplyPersonInfo->nCardType = _ttoi(vecMemo[0]);	//�������

	//�ҹ�Ͻ��Ա
	const auto& vecCtrlPInfo = theApp.m_vecCtrlPersonInfo;

	auto itCtrlPInfo = std::find_if(vecCtrlPInfo.begin(), vecCtrlPInfo.end(),
		std::bind(lambda_FindCtrlInfoByCardID, _1, vecMemo[1]));
	
	if (vecCtrlPInfo.end() == itCtrlPInfo) {
		theApp.WriteLog(error, _T("û���ҵ��ù�Ͻ��Ա��Ϣ��"));
		return false;
	}
	const auto& stCtrlPInfo = *itCtrlPInfo;//��Ͻ��Ա��Ϣ

	CTime tmApply = ZCMsgHelper_ParseTime(stAuthInfo.chAlarmDateTime);
	spApplyPersonInfo->stPersonInfo = stCtrlPInfo;
	spApplyInfo->strWebSiteName = stAuthInfo.chArea;//����
	spApplyInfo->strPartName = stAuthInfo.chKeyPart;//��λ
	spApplyPersonInfo->tmApply = spApplyInfo->tmApply = std::move(tmApply);//����ʱ��

	m_vecApplyInfo.push_back(spApplyInfo);//Ϊʲô������InsertApplyInfo���Ϊ����ʷ��¼��
	//������ؼ�
	InsertApplyInfo(spApplyInfo);

	//д����־��
	m_oStg->WriteApplyLog(spApplyInfo);

	return true;
}