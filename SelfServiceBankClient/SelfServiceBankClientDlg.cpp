
// SelfServiceBankClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "SelfServiceBankClientDlg.h"
#include "afxdialogex.h"

#include "LogDialog.h"
#include "ZCMsgManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#include "MyButton1.h"
#endif


namespace {
	using std::vector;
	using std::shared_ptr;
	using std::placeholders::_1;
	const UINT cstnApplyRecordCnt = 3; //申请记录详情行数

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
	m_oLogDlg = std::make_shared<CLogDialog>();
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

	// 添加“关于”、菜单项

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		vector<std::tuple<int, CString>> vecMenu = { 
			{ IDM_ABOUTBOX,_T("关于")}/*,
			{ IDM_Log,_T("日志") }*/ };
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

	/*布局*/
	//移动主界面
	int cx = ::GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = ::GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rc(0, 0, cx, cy);
	rc.DeflateRect(cx / 5, cy / 15);//左右各缩小1/4，高宽相等
	SetWindowPos(nullptr, rc.left, rc.top, rc.Width(), rc.Height(), SWP_NOZORDER);//屏幕坐标

	//标题栏、客户、列表、申请认证记录区，SetRect参数是坐标值
	ScreenToClient(&rc);
	m_rcCaption.SetRect(rc.left, rc.top, rc.Width(), cstnTitleHeight);
	m_rcClient.SetRect(rc.left, rc.top + cstnTitleHeight, rc.Width(), rc.Height());
	m_rcList.SetRect(m_rcClient.left + 1, m_rcClient.top + 1, m_rcClient.Width() / 6, m_rcClient.bottom);
	m_rcRecord.SetRect(m_rcList.right + 5, m_rcList.top, m_rcClient.right, m_rcList.bottom);
	//GetClientRect(&m_rcClient);

	//移动关闭按钮
	/*对话框与控件的调用顺序：1）控件子类化；2）OnInitDialog；3）对话框OnPaint；4）控件OnPaint*/
	m_oCloseWindow.Set(_T("res\\标题栏关闭常态.png"), _T("res\\标题栏关闭悬停.png"), false);
	rc.SetRect(rc.right - 24, rc.top, 0, 0);
	m_oCloseWindow.SetWindowPos(nullptr, rc.left, rc.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);//要客户区坐标


	//申请列表
	m_oApplyList.Create(LBS_OWNERDRAWFIXED | LBS_HASSTRINGS | LBS_NOTIFY 
		| /*LBS_EXTENDEDSEL |*/ WS_CHILD | WS_VISIBLE /*| LBS_SORT*/, 
		CRect(0, 0, 0, 0), this, 1);
	//在笔记本上实际高度并不是m_rcList.Height()，？
	m_oApplyList.SetWindowPos(nullptr, m_rcList.left, m_rcList.top, m_rcList.Width(), m_rcList.Height(), SWP_NOZORDER);
	//m_oApplyList.MySetItemData(m_vecApplyInfo); //
	m_oApplyList.Set(this);

#ifdef  _DEBUG
	//CMyListBox1::ItemData d1 = { _T("大华abc"), 2, CTime(2017,10,3,1,1,1) };
	//m_oApplyList.MyInsertString(d1);
	btn1 = std::make_shared<CMyButton1>();
	btn1->Create(_T("BTN1"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
		CRect(0, 0, 0, 0), this, 123);
	//enum emCfg { emUnderline = 1, emFontsize, emBgcolor, emTextcolor, emMousetrack,
	btn1->SetUICfg("underline,0;emfontsize,16;emmousetrack=1;");
	btn1->SetWindowPos(nullptr, m_rcList.left + 200, m_rcList.top + 100, 80, 50, SWP_NOZORDER);

	btn1->ShowWindow(SW_NORMAL);
#endif //  _DEBUG

	//申请认证详情对话框
	int nDlgHeight = 
		m_rcClient.Height() / cstnApplyRecordCnt;//每条记录的高度是 1/n （包含 - 分割线 - 间距 30px）
	int i = 0;
	for (/*auto i = 0; i < cstnApplyRecordCnt; ++i*/auto& dlg : m_vecApplyRecordDlg) {
		//auto& dlg = m_liApplyRecordDlg;
		int x = m_rcRecord.left, y = m_rcRecord.top + i++ * nDlgHeight;
		dlg.SetRectInParent(CRect(x, y, m_rcRecord.right,
			y + nDlgHeight/*x + m_rcRecord.Width(), y + nDlgHeight*/));//设置在父窗口中的坐标

		dlg.Create(IDD_ApplyRecordDlg, this);
		/*dlg.SetWindowPos(nullptr,
			m_rcRecord.left, m_rcRecord.top + i * nDlgHeight,
			m_rcRecord.Width(), nDlgHeight - 15, SWP_NOZORDER);*/
		//dlg.ShowWindow(SW_NORMAL);
	}

#ifdef  _DEBUG
	//插入一些申请人员，Create之后是OnInitDialog，所以OnInitDialog里还没有数据，
	//应该在OnPaint处理
	//_DebugInsertSomeApplyPersonInfo();
	/*模拟来了一个申请（一个人还是所有相关的人？）
	一个一个来较复杂，结构体成员如何标识这是一个申请？左ListBox要合并、右ListCtrl要合并；
	暂时用全部申请人员；
	//左：haoyun->测试->大华-》大华-》数码  //右：数码-》haoyun-》测试
	*/
	/*_DebugInsertApplyInfo(stApplyInfo(_T("数码"), 0, CTime(CTime::GetCurrentTime()),
	{ stApplyPersonInfo(_T("person1.jpg"), _T("person1"), _T("张江地铁站"), _T("内部人员")),
	stApplyPersonInfo(_T("person2.jpg"),_T("person2"), _T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person3.jpg"),_T("person3"), _T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person4.jpg"),_T("person4"),_T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person5.jpg"),_T("person5"),_T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person6.jpg"),_T("person6"),_T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person7.jpg"),_T("person7"),_T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person8.jpg"),_T("person8"),_T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person9.jpg"),_T("person9"),_T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person10.jpg"),_T("person10"),_T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person11.jpg"),_T("person11"),_T("张江地铁站"),_T("内部人员")),
	stApplyPersonInfo(_T("person12.jpg"),_T("person12"),_T("张江地铁站"),_T("内部人员"))
	}));
	_DebugInsertApplyInfo(stApplyInfo(_T("测试"), 0, CTime(CTime::GetCurrentTime()),
	{ stApplyPersonInfo(_T("person1.jpg"), _T("person1"), _T("张江地铁站"), _T("内部人员"))
	}));
	_DebugInsertApplyInfo(stApplyInfo(_T("haoyun"), 1, CTime(CTime::GetCurrentTime()),
	{ stApplyPersonInfo(_T("person1.jpg"), _T("person1"), _T("张江地铁站"), _T("内部人员")),
		stApplyPersonInfo(_T("person3.jpg"),_T("person3"), _T("张江地铁站"),_T("内部人员"))
	}));
	_DebugInsertApplyInfo(stApplyInfo(_T("大华"), 3, CTime(2017, 10, 9, 10, 34, 34),
	{ stApplyPersonInfo(_T("person1.jpg"), _T("person1"), _T("张江地铁站"), _T("内部人员")),
		stApplyPersonInfo(_T("person3.jpg"),_T("person3"), _T("张江地铁站"),_T("内部人员"))
	}));*/
#endif //  _DEBUG

	//初始化消息服务，因为界面元素可能是一个观察者
	if (!CZCMsgManager::Instance()->Init(0))
		return FALSE;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSelfServiceBankClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	//低4位系统使用
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

	//布局用的参数：坐标、宽高
	const auto& rc = m_rcCaption;
	int x = rc.left, y = rc.top;
	int	w = rc.Width(), h = 0;

	//画标题栏
	Graphics gh(dc.GetSafeHdc());
	SolidBrush sbr(cstClrTitle);
	gh.FillRectangle(&sbr, x, y, w, cstnTitleHeight);

	//写标题
	FontFamily ff(_T("微软雅黑"));
	Gdiplus::Font font(&ff, 16, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color(255, 255, 255));
	PointF pf(5.0f, 5.0f);
	gh.DrawString(_T("门禁认证信息"), -1, &font, pf, &sbrText);

	//“没有更多的认证信息” 提示
	StringFormat sf;
	//sf.SetAlignment(StringAlignmentCenter);//文本居中
	//sf.SetLineAlignment(StringAlignmentCenter);//上下居中
	RectF rcGdiF((m_rcRecord.left + 10) * 1.0f, (m_rcRecord.top+10) * 1.0f, 
		m_rcRecord.right * 1.0f, m_rcRecord.bottom * 1.0f / 3);
	sbrText.SetColor(Color(255, 0, 0));
	Gdiplus::Font fontTip1(&ff, 20, FontStyleRegular, UnitPixel);
	gh.DrawString(_T("现在没有申请认证信息！"), -1, &fontTip1, rcGdiF, &sf, &sbrText);


#ifdef _DEBUG

	CMyButton1 btn1;
	btn1.Create(_T("BTN1"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
		CRect(0, 0, 0, 0), this, 123);
	btn1.SetUICfg("underline,0");
	btn1.SetWindowPos(nullptr, m_rcList.left, m_rcList.top, m_rcList.Width(), m_rcList.Width(), SWP_NOZORDER);

	btn1.ShowWindow(SW_NORMAL);
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
		// 发送WM_NCLBUTTONDOWN消息
		// 使Windows认为鼠标在标题栏上
		PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
		//或SendMessage(WM_SYSCOMMAND,0xF012,0);   //0xF012 = SC_MOVE | HTCAPTION
	}
}



void CSelfServiceBankClientDlg::InsertApplyInfo(const shared_ptr<stApplyInfo>& sp)
{

	//sp引用1，m_vecApplyInfo引用2，MyInsertString参数是引用不算
	//auto& sp = std::make_shared<stApplyInfo>(st);
	m_vecApplyInfo.push_back(sp);

	//插入到左侧申请列表
	m_oApplyList.MyInsertString(sp);
	
	//插入到右侧申请详情
	MyInsertRecord(sp);
}


//查找申请时间
bool Lambda_InsertRecord(/*CApplyRecordDlg& dlg*/const shared_ptr<stApplyInfo>& sp, const shared_ptr<stApplyInfo>& st)
{
	//auto& sp = dlg.GetApplyInfo();
	return nullptr == sp || st->tmApply < sp->tmApply;
}

//bool Lambda_SortRecordList(const CApplyRecordDlg& dlg1,
//	const CApplyRecordDlg& dlg2)
//{
//	//排序不是按顺序来的
//	const auto& st1 = dlg1.GetApplyInfo();
//	const auto& st2 = dlg2.GetApplyInfo();
//	//两个都为空 或者 st2为空，不用交换
//	//if (!st1 && !st2 || st1 && !st2)
//	//	return false;
//	//if (!st1 && st2)
//	//	return true;
//
//	//return st1->tmApply < st2->tmApply;
//	if (st1 && !st2)
//		return true;
//	if (!st1 && !st2 || !st1 && st2)
//		return false;
//
//	return st1->tmApply < st2->tmApply;
//}

bool Lambda_SortRecordVector(const std::shared_ptr<stApplyInfo>& sp1,
	const std::shared_ptr<stApplyInfo>& sp2)
{
	if (sp1 && !sp2)
		return true;
	if (!sp1 && !sp2 || !sp1 && sp2)
		return false;
	
	return sp1->tmApply < sp2->tmApply;
}

//（对话框程序对数据发生变化的更新显示贼烦！）
//仿Doc-View，右侧用一个类CView类管理vector<CRecord>
void CSelfServiceBankClientDlg::MyInsertRecord(const shared_ptr<stApplyInfo>& st)
{
	//找st比哪个时间早，排序m_liApplyRecordDlg把坐标都换了

	vector<shared_ptr<stApplyInfo>> vec;
	for (auto& st : m_vecApplyRecordDlg)
		vec.push_back(st.GetApplyInfo());

	auto it = std::find_if(vec.begin(), vec.end(),
		std::bind(Lambda_InsertRecord, _1, st));
	if (vec.end() != it) {
		//存在为空或更晚的记录
		int i = std::distance(vec.begin(), it);
		auto itDlg = m_vecApplyRecordDlg.begin();
		std::advance(itDlg, i);
		if (nullptr == *it) {
			itDlg->SetApplyInfo(st);
			itDlg->Update();
		}
		else {
			auto& last = *vec.rbegin();
			last = st;
			sort(vec.begin(), vec.end(), Lambda_SortRecordVector);
			for (/*auto& st : vec*/int i = 0; i < (int)vec.size(); ++i) {
				auto& dlg = m_vecApplyRecordDlg[i];
				if (vec[i] == dlg.GetApplyInfo())
					continue;
				dlg.SetApplyInfo(vec[i]);
				dlg.Update();
			}
		}
	}
	//auto it = std::find_if(m_liApplyRecordDlg.begin(), m_liApplyRecordDlg.end(),
	//	std::bind(Lambda_InsertRecord, _1, st));

	//if (m_liApplyRecordDlg.end() != it) {
	//	if (nullptr == it->GetApplyInfo()) {
	//		it->SetApplyInfo(st);
	//	}
	//	else {
	//		auto& lastDlg = *m_liApplyRecordDlg.rbegin();
	//		lastDlg.SetApplyInfo(st);
	//	}

	//	//把窗口坐标都换了！改为排临时变量
	//	m_liApplyRecordDlg.sort(Lambda_SortRecordList);
	//	for (auto& dlg : m_liApplyRecordDlg) {
	//		dlg.Update();
	//	}
	//}

	//如果有：替换最后一个，并向后顺延
	//if (m_liApplyRecordDlg.end() != it) {
	//	//
	//	if (nullptr == it->GetApplyInfo()) {
	//		it->SetApplyInfo(st);
	//		return;
	//	}

	//	//替换最后一个并显示
	//	auto& lastDlg = m_vecApplyRecordDlg[cstnApplyRecordCnt - 1];
	//	lastDlg.SetApplyInfo(st);
	//	//将它移动到it所在位置
	//	int nDis = std::distance(m_vecApplyRecordDlg.begin(), it);
	//	CRect rc;
	//	lastDlg.GetClientRect(&rc);
	//	lastDlg.SetWindowPos(0, m_rcRecord.left,
	//		m_rcRecord.top + nDis*rc.Height(), 0, 0, 
	//		SWP_NOZORDER | SWP_NOSIZE);
	//	//其它顺延
	//	for (int i = cstnApplyRecordCnt - 2; i >= nDis; --i) {
	//		auto& moveDlg = m_vecApplyRecordDlg[i];
	//		moveDlg.SetWindowPos(0, m_rcRecord.left,
	//			m_rcRecord.top + (i + 1)*rc.Height(), 0, 0,
	//			SWP_NOZORDER | SWP_NOSIZE);
	//	}
	//	
	//}
	//else { //st没有比谁早
	//	for (auto& dlg : m_vecApplyRecordDlg) {
	//		if (nullptr == dlg.GetApplyInfo())
	//			dlg.SetApplyInfo(st);
	//	}
	//}

	
}

void CSelfServiceBankClientDlg::DisplayDetail(const std::shared_ptr<stApplyInfo>& st)
{
	//在右侧第一行显示，原右侧第一行信息将在左侧参与排序后显示
	//int n = m_liApplyRecordDlg.size();
	auto& dlg = *m_vecApplyRecordDlg.begin();
	dlg.SetApplyInfo(st);
	dlg.Update();
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
	//注册自己感兴趣的消息，其他不处理
	m_mapZCMsgHandler = { /*<反馈， 处理方法>*/
		{ ZC_MSG_ALARM_NEWALARMINFO_EX, &CSelfServiceBankClientDlg::ZCMsgAuthentication }//刷卡认证信息
	};
}


bool lambda_FindACSHostByDevNo(const std::pair<CString, shared_ptr<stACSHostInfo>>& p, const int nDevNo) {
	return p.second->stBaseInfo.nID == nDevNo;
}
bool lambda_FindCtrlInfoByID(const shared_ptr<stCtrlPersonInfo>& st, const CString& chID) {
	return CString(st->stBaseInfo.chId) == chID;
}
//刷卡认证申请
void CSelfServiceBankClientDlg::ZCMsgAuthentication(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	int nStructLen = sizeof(T_TRANSMITALARMINFO_EX);
	if (nMsgLen != nStructLen) {
		theApp.WriteLog(error, _T("刷卡信息长度有误！"));
		return;
	}
	//构造申请信息：1）根据身份证查找用户信息，2）
	auto& spApplyInfo = std::make_shared<stApplyInfo>();
	spApplyInfo->stPersonInfo = std::make_shared<stApplyPersonInfo>();
	auto& spApplyPInfo = spApplyInfo->stPersonInfo;
	
	//if(0 == spApplyInfo->stPersonInfo

	T_TRANSMITALARMINFO_EX* pAuthInfo = (T_TRANSMITALARMINFO_EX*)pMsg;
	//传过来的刷卡信息
	CString strAuthMemo(pAuthInfo->tTransmitAlarmInfo.tAlarmInfo.chMemo);
	theApp.WriteLog(trace, _T("收到刷卡认证信息：%s"), strAuthMemo);
	
	//解析刷卡信息：字串分段：是否合法 | 卡号 | 身份证      "0"--非法，"1"--合法，“2”--无权限
	vector<CString> vecMemo;
	SplitString(strAuthMemo, _T('|'), vecMemo);
	assert(vecMemo.size() != 3);

	//卡的类别
	spApplyPInfo->nCardType = _ttoi(vecMemo[0]);

	//管辖人员信息（和用户信息不是一个）
	const auto& vecCtrlPInfo = theApp.m_vecCtrlPersonInfo;
	auto itCtrlPInfo = std::find_if(vecCtrlPInfo.begin(), vecCtrlPInfo.end(),
		std::bind(lambda_FindCtrlInfoByID, _1, vecMemo[2]));
	if (vecCtrlPInfo.end() == itCtrlPInfo) {
		theApp.WriteLog(error, _T("没有找到该管辖人员信息！"));
		return;
	}
	const auto& stCtrlPInfo = *itCtrlPInfo;//管控人员信息

	spApplyPInfo->stPersonInfo = stCtrlPInfo;//刷卡人员信息
	spApplyInfo->strWebSiteName = pAuthInfo->tTransmitAlarmInfo.chArea;//网点
	spApplyInfo->tmApply = ZCMsgHelper_ParseTime(pAuthInfo->tTransmitAlarmInfo.chAlarmDateTime);

	//管控等级
	int nDevNo = pAuthInfo->tTransmitAlarmInfo.nDevNumber; //设备id
	//CString nDevName = pAuthInfo->tTransmitAlarmInfo 没有设备名
	
	//门禁信息
	const auto& mapACSHostInfo = theApp.m_mapACSHostInfo;
	auto itACSHost = std::find_if(mapACSHostInfo.begin(), mapACSHostInfo.end(),
		std::bind(lambda_FindACSHostByDevNo, _1, nDevNo)); //itACSHost是一个pair
	if (mapACSHostInfo.end() == itACSHost) {
		theApp.WriteLog(error, _T("没有找到门禁主机！"));
		return;
	}
	const auto& pHostInfo = (itACSHost->second);//门禁信息
	spApplyInfo->nImportance = pHostInfo->nCtrlLevel;//管控等级

	//赋值各控件
	InsertApplyInfo(spApplyInfo);
}



CTime CSelfServiceBankClientDlg::ZCMsgHelper_ParseTime(const char* szTime)
{
	//CString strTime(szTime);
	int nYear, nMonth, nDate, nHour, nMin, nSec;
	sscanf_s(szTime, "%d-%d-%d %d:%d:%d", &nYear, &nMonth, &nDate, &nHour, &nMin, &nSec);
	return CTime(nYear, nMonth, nDate, nHour, nMin, nSec);
}