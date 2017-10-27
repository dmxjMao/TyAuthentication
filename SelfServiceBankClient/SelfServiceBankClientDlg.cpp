
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

//网络服务库
#include "TYServerSDK.h"
//解码库
#include "LoadTJTY_Play.h"

stVideoInfo g_stVideInfo;

namespace {
	using std::vector;
	using std::shared_ptr;
	using std::make_shared;
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

	//ZCMsg消息映射
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
	//移动主界面，控制最小尺寸，否则小屏幕按钮都看不见了
	int cx = ::GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = ::GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rc(0, 0, cx, cy);
	rc.DeflateRect(cx / 5, cy / 15);//左右各缩小1/4，高宽相等
	if (rc.Width() < 1000)
		rc.SetRect(rc.left, rc.top, rc.left + 1000, rc.bottom);
	SetWindowPos(nullptr, rc.left, rc.top, rc.Width(), rc.Height(), SWP_NOZORDER);//屏幕坐标

	//标题栏、客户、列表、申请认证记录区，SetRect参数是坐标值
	ScreenToClient(&rc);
	m_rcCaption.SetRect(rc.left, rc.top, rc.Width(), theApp.m_oGobal->cstnTitleHeight);
	m_rcClient.SetRect(rc.left, rc.top + theApp.m_oGobal->cstnTitleHeight, rc.Width(), rc.Height());
	m_rcList.SetRect(m_rcClient.left + 1, m_rcClient.top + 1, m_rcClient.Width() / 6, m_rcClient.bottom);
	m_rcRecord.SetRect(m_rcList.right + 5, m_rcList.top, m_rcClient.right, m_rcList.bottom);
	//GetClientRect(&m_rcClient);


	//移动关闭按钮
	/*对话框与控件的调用顺序：1）控件子类化；2）OnInitDialog；3）对话框OnPaint；4）控件OnPaint*/
	m_oCloseWindow->Set(_T("res\\标题栏关闭常态.png"), _T("res\\标题栏关闭悬停.png"), false);
	rc.SetRect(rc.right - 24, rc.top, 0, 0);
	m_oCloseWindow->SetWindowPos(nullptr, rc.left, rc.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);//要客户区坐标


	//申请列表
	m_oApplyList->Create(LBS_OWNERDRAWFIXED | LBS_HASSTRINGS | LBS_NOTIFY 
		| /*LBS_EXTENDEDSEL |*/ WS_CHILD | WS_VISIBLE /*| LBS_SORT*/, 
		CRect(0, 0, 0, 0), this, 1);
	//在笔记本上实际高度并不是m_rcList.Height()，？
	m_oApplyList->SetWindowPos(nullptr, m_rcList.left, m_rcList.top, m_rcList.Width(), m_rcList.Height(), SWP_NOZORDER);
	//m_oApplyList.MySetItemData(m_vecApplyInfo); //
	//m_oApplyList->Set(this);


	//申请认证详情对话框
	int nDlgHeight = 
		m_rcClient.Height() / cstnApplyRecordCnt;//每条记录的高度是 1/n （包含 - 分割线 - 间距 30px）
	int i = 0;
	for (/*auto i = 0; i < cstnApplyRecordCnt; ++i*/auto& dlg : m_vecApplyRecordDlg) {
		//auto& dlg = m_liApplyRecordDlg;
		int x = m_rcRecord.left, y = m_rcRecord.top + i++ * nDlgHeight;
		dlg->SetRectInParent(CRect(x, y, m_rcRecord.right,
			y + nDlgHeight/*x + m_rcRecord.Width(), y + nDlgHeight*/));//设置在父窗口中的坐标

		dlg->Create(IDD_ApplyRecordDlg, this);
	}

#ifdef DEBUG
	//demo视频
	m_demoVideo.SetWindowPos(0, m_rcRecord.left + 10, m_rcRecord.top + 100, 200, 200, SWP_NOZORDER);

#endif // DEBUG

	//初始化消息服务，因为界面元素可能是一个观察者，所以要等界面初始化完成
	if (!CZCMsgManager::Instance()->Init(0))
		return FALSE;
	
	//获取历史申请记录并显示
	GetHistoryApplyAndDisplay();
	

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
	SolidBrush sbr(theApp.m_oGobal->cstClrTitle);
	gh.FillRectangle(&sbr, x, y, w, theApp.m_oGobal->cstnTitleHeight);

	//写标题
	FontFamily ff(_T("微软雅黑"));
	Gdiplus::Font font(&ff, 16, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color(255, 255, 255));
	PointF pf(5.0f, 5.0f);
	gh.DrawString(_T("门禁认证信息"), -1, &font, pf, &sbrText);

	//“没有更多的认证信息” 提示
	//if (0 == m_oApplyList->GetCount()) {
	//	StringFormat sf;
	//	//sf.SetAlignment(StringAlignmentCenter);//文本居中
	//	//sf.SetLineAlignment(StringAlignmentCenter);//上下居中
	//	RectF rcGdiF((m_rcRecord.left + 10) * 1.0f, (m_rcRecord.top + 10) * 1.0f,
	//		m_rcRecord.right * 1.0f, m_rcRecord.bottom * 1.0f / 3);
	//	sbrText.SetColor(Color(255, 0, 0));
	//	Gdiplus::Font fontTip1(&ff, 20, FontStyleRegular, UnitPixel);
	//	gh.DrawString(_T("现在没有申请认证信息！"), -1, &fontTip1, rcGdiF, &sf, &sbrText);
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
		// 发送WM_NCLBUTTONDOWN消息
		// 使Windows认为鼠标在标题栏上
		PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
		//或SendMessage(WM_SYSCOMMAND,0xF012,0);   //0xF012 = SC_MOVE | HTCAPTION
	}
}


//读取历史申请记录并显示
void CSelfServiceBankClientDlg::GetHistoryApplyAndDisplay()
{
	//获取当前申请id
	m_dwApplyID = m_oStg->GetApplyID();

	//读取stg，显示历史记录，前N条（今天，昨天，。。。不同的分类如何做？）
	vector<stApplyInfo> vecApplyLog;
	m_oStg->GetRecentNRecord(100, vecApplyLog);

	for (const auto& stLog : vecApplyLog) {
		//auto& sp = make_shared<stApplyInfo>();

		//InsertApplyInfo
	}
	
}

void CSelfServiceBankClientDlg::InsertApplyInfo(const shared_ptr<stApplyInfo>& sp)
{
	//插入到左侧申请列表
	m_oApplyList->MyInsertString(sp);
	
	//插入到右侧申请详情
	MyInsertRecord(sp);
}




//不能简单的插入，如果是多人申请，人员信息要合理地传递给CListCtrl
void CSelfServiceBankClientDlg::MyInsertRecord(const shared_ptr<stApplyInfo>& st)
{
	//if (st->nSlave > -1) {//多人刷卡
	//					  //查找是否有该网点、部位的刷卡信息
	//	auto it = std::find_if(m_vecApplyInfo.begin(), m_vecApplyInfo.end(),
	//		std::bind(Lambda_FindApplyInfo, _1, st->strWebSiteName, st->strPartName));
	//	if (m_vecApplyInfo.end() != it) {
	//		return;
	//	}
	//}


	//找st比哪个时间早，排序m_liApplyRecordDlg把坐标都换了，所以不能动m_vecApplyRecordDlg
	
	vector<shared_ptr<stApplyInfo>> vec;
	for (auto& st : m_vecApplyRecordDlg)
		vec.push_back(st->GetApplyInfo());

	auto it = std::find_if(vec.begin(), vec.end(),
		std::bind(lambda_InsertRecord, _1, st));
	if (vec.end() != it) {//存在为空或更晚的记录，不存在啥也不做
		int i = std::distance(vec.begin(), it);
		auto itDlg = m_vecApplyRecordDlg.begin();
		std::advance(itDlg, i);
		if (nullptr == *it) {//空记录
			(*itDlg)->SetApplyInfo(st, true);
			//(*itDlg)->Update();
		}
		else {//替换更晚的申请
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
	//在右侧第一行显示，原右侧第一行信息将在左侧参与排序后显示
	//int n = m_liApplyRecordDlg.size();
	auto& dlg = *m_vecApplyRecordDlg.begin();
	dlg->SetApplyInfo(st);
	//dlg->Update();
}

//关闭记录，删除左边，右边
void CSelfServiceBankClientDlg::DeleteRecord(int idx)
{
	if (idx >= 0 && idx < cstnApplyRecordCnt) {
		auto& pDlg = m_vecApplyRecordDlg[idx];
		//左边
		m_oApplyList->MyDeleteString(pDlg->GetApplyInfo());
		//右边
		pDlg->SetApplyInfo(0);
	}
}

//失效处理
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
	//注册自己感兴趣的消息，其他不处理
	m_mapZCMsgHandler = { /*<反馈， 处理方法>*/
		{ ZC_MSG_ALARM_NEWALARMINFO_EX, &CSelfServiceBankClientDlg::ZCMsgAuthentication },//刷卡认证信息
		//{ ZC_MSG_ALARM_NEWALARMINFO, &CSelfServiceBankClientDlg::ZCMsgAuthentication }//刷卡认证信息，先来这条
		{ ZC_MSG_COMMON_CONTROLACSHOST , &CSelfServiceBankClientDlg::ZCMsgOpenDoor}//“开门” + 解锁
	};
}



//刷卡认证申请
void CSelfServiceBankClientDlg::ZCMsgAuthentication(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	//T_TRANSMITALARMINFO
	int nStructLen = sizeof(T_TRANSMITALARMINFO_EX);
	if (nMsgLen != nStructLen) {
		theApp.WriteLog(error, _T("刷卡信息长度有误！"));
		return;
	}

	T_TRANSMITALARMINFO_EX* pAuthInfo = (T_TRANSMITALARMINFO_EX*)pMsg;
	//找门禁信息
	int nDevID = pAuthInfo->tTransmitAlarmInfo.nDevNumber; //刷卡设备id
	const auto& mapACSHostInfo = theApp.m_mapACSHostInfo;
	
	auto itACSHost = std::find_if(mapACSHostInfo.begin(), mapACSHostInfo.end(),
		std::bind(lambda_FindACSHostByDevNo, _1, nDevID)); //itACSHost是一个pair
	
	if (mapACSHostInfo.end() == itACSHost) {
		theApp.WriteLog(error, _T("没有找到门禁主机！"));
		return;
	}
	const auto& pHostInfo = (itACSHost->second);//门禁主机信息
	const auto& stCtrlPlan = theApp.GetCtrlPlanInfo(pHostInfo->nCtrlLevel);//对应的管控策略

	//当前用户是否受理该门禁
	const auto& pVecDealHost = theApp.m_mapUserInfo[theApp.m_strCurUserName]->pDealedACSHost;
	if (!pVecDealHost || pVecDealHost->empty()) return; //不处理任何门禁

	auto itDealHost = std::find_if(pVecDealHost->begin(), pVecDealHost->end(),
		std::bind(lambda_FindDealHostByID, _1, nDevID));
	if (pVecDealHost->end() == itDealHost) return; //不受理该门禁


	if (1 == stCtrlPlan->nAuthType) {//远程认证
		RemoteAuth(pAuthInfo->tTransmitAlarmInfo, pHostInfo);
	}
	else if (pHostInfo->nCtrlLevel > 0) {//本地认证、本地不管控（中心监控）
		LocalAuth(pAuthInfo->tTransmitAlarmInfo, pHostInfo);
	}
	else {//本地认证、本地管控（不用中心监控）
		theApp.WriteLog(warning, _T("本地认证、本地管控（不用中心监控），不显示。"));
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


//是否处理申请

bool CSelfServiceBankClientDlg::IfDealTheApplyMsg(const CString& strCardNum/*, const CTime& tmApply*/)
{
	//该卡号的申请是否在队列中
	auto it = std::find_if(m_vecApplyInfo.begin(), m_vecApplyInfo.end(),
		std::bind(lambda_FindApplyInfoByCardID, _1, strCardNum));
	if (m_vecApplyInfo.end() == it) { //不在
		return true;
	}
	//失效自动删除，已放入删除队列里了
	return false;
}


//"开门" + 解锁 = 开门，两次都会返回
void CSelfServiceBankClientDlg::ZCMsgOpenDoor(PBYTE pMsg, DWORD dwMsgID, INT nMsgLen)
{
	//

	static UINT8 cnt[cstnApplyRecordCnt] = { 0 };
	if (dwMsgID >= 0 && dwMsgID < cstnApplyRecordCnt) {
		cnt[dwMsgID] = ++cnt[dwMsgID] % 2;
		//改变图标，"开门" + 解锁都返回
		if (0 == cnt[dwMsgID]) {//开门
			//要访问成员，又不想把CApplyRecordDlg作为观察者，就要麻烦点了
			auto& dlg = m_vecApplyRecordDlg[dwMsgID];
			dlg->m_oPicDoor->Set(_T("res\\开门_58-74-_白.bmp"));
			dlg->m_oPicDoor->Invalidate();

			vector<emButton> vecBtn = { OpenDoorBtn };
			dlg->EnableButton(vecBtn, false);
			//AfxMessageBox(_T("开门成功！"));
		}
		else {//锁门
			//还是要回调
		}
	}
	
	//如果“开门”、解锁有一个不成功，这里只会返回成功！

}




// 预览音视频回调
void __stdcall RealPlayDataCallBack2(long lHandle, DWORD dwDataType, BYTE *pBuffer,
	DWORD dwBufSize, DWORD dwUser)
{
	//附件参数
	//CSelfServiceBankClientDlg* pDlg = (CSelfServiceBankClientDlg*)dwUser;
	const stVideoInfo& st = g_stVideInfo;
	bool bRet = false;

	static DWORD dwBuffSize = (1024 << 10); //播放器中数据流缓冲区大小
	static int nBuffNum = 25;//播放器缓冲区最大缓存帧数
	static UINT8 nWndNo = 1;  //用st.nPlayID还不行

	switch (dwDataType)
	{
	case SYSHEAD_DATA: //系统头信息
	{
		bRet = TJTY_PLAY_InitplayStyle(nWndNo, st.nFactoryType);
		bRet = TJTY_PLAY_SetStreamOpenMode(nWndNo, 0);				//设置为实时流播放，Hik，dh有效

		int nHeaderSize = 40;		//海康大华等其他厂家视频头为40字节
		if (TJTY_DVR_BSR == st.nFactoryType || TJTY_DVR_BSR7 == st.nFactoryType) {//蓝星系列为256字节视频头
			nHeaderSize = 256;
		}
		bRet = TJTY_PLAY_StartPlay(nWndNo, (BYTE*)pBuffer, nHeaderSize, dwBuffSize, st.pWnd->GetSafeHwnd(), nBuffNum);
		if (!bRet) {
			theApp.WriteLog(warning, _T("播放视频失败！厂家id：%d"), st.nFactoryType);
			//LOG(ERROR) << "TJTY_PLAY_StartPlay failed. Error:" << TJTY_PLAY_GetLastError(TJTY_PLAY_PORT_NUM);
		}
		break;
	}
	case AUDIO_AND_VIDEO_DATA://音视频混合数据
	{
		bRet = TJTY_PLAY_InputData(nWndNo, (BYTE*)pBuffer, dwBufSize);
		UINT uiFailCount = 3;
		while (!bRet && uiFailCount--)
		{
			//投递失败表明缓冲区已满，稍等后重新投递
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

	//回放录像
}


void CSelfServiceBankClientDlg::OnBnClickedButton1()
{
	if (g_stVideInfo.pWnd)
		return;

	//构造申请预览结构
	T_VIEW_APPLYINFO tViewInfo = { 0 };
	tViewInfo.TDEVIDInfo.lDEVID = 8; //天跃，枪机3
	//vector<long> vecTmp = { itDealHost->nCenterNo,0,0,0,0 };
	//for(int i=0;i<5;++i)
	tViewInfo.TDEVIDInfo.lCMSCascadeInfo[0] = 102;
	tViewInfo.nStreamType = TJTY_SOFT_EMAP; //标清
	tViewInfo.nViewMode = 0;	// 普通预览
	tViewInfo.nChannel = 3;

	int nLinkType = -1;
	T_DEV_LOGIN_INFO stLoginInfo;
	//返回预览操作句柄，-1失败，TY_Server都是同步的，狂点按钮导致界面卡死
	long nPlayID = TY_Server_RequestPlay(theApp.m_oGobal->nCMSHander, &tViewInfo, nLinkType, &stLoginInfo);
	DWORD dwErr = TY_Server_GetLastError();
	if (-1 == nPlayID) {
		theApp.WriteLog(error, _T("请求预览失败！设备id：%d"), 8);
		return;
	}

	//static stVideoInfo vi;
	g_stVideInfo.nPlayID = nPlayID;
	g_stVideInfo.pWnd = &m_demoVideo;
	g_stVideInfo.nLinkType = nLinkType;
	g_stVideInfo.nFactoryType = 1;

	//开始预览，只有采用了经媒体转发的方式才调用该方法，直连要使用网络库
	int nRet = TY_Server_StartPlay(nPlayID, RealPlayDataCallBack2, 0);
	if (nRet != 0) {//0成功，其他失败
		theApp.WriteLog(error, _T("开始预览失败！设备id：%d"), 8);
		return;
	}
}


void CSelfServiceBankClientDlg::OnDblclkDemovideo()
{
	static bool bZoom = false;
	CRect rc;
	m_demoVideo.GetWindowRect(&rc);
	ScreenToClient(&rc);
	static CRect rcOri = rc; //正常

	int x = 0, y = 0, w = 0, h = 0;
	if (bZoom) {//放大双击，缩小
		x = rcOri.left, y = rcOri.top, w = rcOri.Width(), h = rcOri.Height();
		bZoom = false;
	}
	else {
		x = m_rcClient.left, y = m_rcClient.top, w = m_rcClient.Width(), h = m_rcClient.Height();
		bZoom = true;
	}
	m_demoVideo.SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
}



//本地认证
void CSelfServiceBankClientDlg::LocalAuth(const T_TRANSMITALARMINFO& pAuthInfo, const shared_ptr<stACSHostInfo>& pHostInfo)
{
	bool bRet = CreateApplyInfo(pAuthInfo, pHostInfo, 0);
	if (!bRet)
		return;
}

//远程认证
void CSelfServiceBankClientDlg::RemoteAuth(const T_TRANSMITALARMINFO& stAuthInfo, const shared_ptr<stACSHostInfo>& pHostInfo)
{
	bool bRet = CreateApplyInfo(stAuthInfo, pHostInfo, 1);
	if (!bRet)
		return;
}


//构造申请信息
bool CSelfServiceBankClientDlg::CreateApplyInfo(const T_TRANSMITALARMINFO& stAuthInfo, 
	const shared_ptr<stACSHostInfo>& pHostInfo, UINT8 nLocal)
{
	//传过来的刷卡信息
	CString strAuthMemo(stAuthInfo.tAlarmInfo.chMemo);
	theApp.WriteLog(trace, _T("收到刷卡认证信息：%s"), strAuthMemo);

	//解析刷卡信息：字串分段：是否合法 | 卡号 | 身份证， "0"--非法，"1"--合法，“2”--无权限
	vector<CString> vecMemo;
	SplitString(strAuthMemo, _T('|'), vecMemo);
	assert(vecMemo.size() >= 2);

	//根据卡号判断是否需要处理这条申请，比如：1）已申请过了
	if (!IfDealTheApplyMsg(vecMemo[1])) {
		theApp.WriteLog(warning, _T("重复申请！"));
		return false;
	}

	//构造申请信息
	auto& spApplyInfo = std::make_shared<stApplyInfo>();
	spApplyInfo->stPersonInfo = std::make_shared<stApplyPersonInfo>();
	auto& spApplyPersonInfo = spApplyInfo->stPersonInfo;

	spApplyInfo->nApplyID = ++m_dwApplyID % 10000; 
	spApplyInfo->nLocal = nLocal;//本地or远程认证
	spApplyInfo->nImportance = pHostInfo->nCtrlLevel;//管控等级
	spApplyInfo->nDevID = stAuthInfo.nDevNumber;//刷卡设备id
	spApplyInfo->strDevName = CString(pHostInfo->stBaseInfo.chDevName); //刷卡设备名称

	spApplyInfo->nSlave = pHostInfo->nSlave;//是否主从刷卡
	spApplyPersonInfo->nCardType = _ttoi(vecMemo[0]);	//卡的类别

	//找管辖人员
	const auto& vecCtrlPInfo = theApp.m_vecCtrlPersonInfo;

	auto itCtrlPInfo = std::find_if(vecCtrlPInfo.begin(), vecCtrlPInfo.end(),
		std::bind(lambda_FindCtrlInfoByCardID, _1, vecMemo[1]));
	
	if (vecCtrlPInfo.end() == itCtrlPInfo) {
		theApp.WriteLog(error, _T("没有找到该管辖人员信息！"));
		return false;
	}
	const auto& stCtrlPInfo = *itCtrlPInfo;//管辖人员信息

	CTime tmApply = ZCMsgHelper_ParseTime(stAuthInfo.chAlarmDateTime);
	spApplyPersonInfo->stPersonInfo = stCtrlPInfo;
	spApplyInfo->strWebSiteName = stAuthInfo.chArea;//网点
	spApplyInfo->strPartName = stAuthInfo.chKeyPart;//部位
	spApplyPersonInfo->tmApply = spApplyInfo->tmApply = std::move(tmApply);//申请时间

	m_vecApplyInfo.push_back(spApplyInfo);//为什么不放在InsertApplyInfo里，因为“历史记录”
	//传入各控件
	InsertApplyInfo(spApplyInfo);

	//写入日志流
	m_oStg->WriteApplyLog(spApplyInfo);

	return true;
}