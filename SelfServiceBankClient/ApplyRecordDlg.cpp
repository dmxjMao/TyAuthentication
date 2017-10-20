// ApplyRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "ApplyRecordDlg.h"
#include "afxdialogex.h"

#include "MyCommonDefine.h"  //struct
#include "MyListCtrl1.h" //申请认证人员
#include "MyStatic1.h" //门
#include "MyStatic2.h" //按钮
#include "EmergencyPlanDialog.h" //应急处置

//网络服务库
#include "TYServerSDK.h"
//解码库
#include "LoadTJTY_Play.h"


using std::vector;
using std::shared_ptr;
using std::placeholders::_1;

#define IDT_Valid	1


// 预览音视频回调
void __stdcall RealPlayDataCallBack(long lHandle, DWORD dwDataType, BYTE *pBuffer,
	DWORD dwBufSize, DWORD dwUser)
{
	//附件参数
	const stVideoInfo& st = *(stVideoInfo*)dwUser;
	bool bRet = false;

	static DWORD dwBuffSize = (1024 << 10); //播放器中数据流缓冲区大小
	static int nBuffNum = 25;//播放器缓冲区最大缓存帧数

	switch (dwDataType)
	{
	case SYSHEAD_DATA: //系统头信息
	{
		bRet = TJTY_PLAY_InitplayStyle(st.nPlayID, st.nFactoryType);
		bRet = TJTY_PLAY_SetStreamOpenMode(st.nPlayID, 0);				//设置为实时流播放，Hik，dh有效

		int nHeaderSize = 40;		//海康大华等其他厂家视频头为40字节
		if (TJTY_DVR_BSR == st.nFactoryType || TJTY_DVR_BSR7 == st.nFactoryType){//蓝星系列为256字节视频头
			nHeaderSize = 256;
		}
		bRet = TJTY_PLAY_StartPlay(st.nPlayID, (BYTE*)pBuffer, nHeaderSize, dwBuffSize, st.pWnd->GetSafeHwnd(), nBuffNum);
		if (! bRet){
			theApp.WriteLog(warning, _T("播放视频失败！厂家id：%d"), st.nFactoryType);
			//LOG(ERROR) << "TJTY_PLAY_StartPlay failed. Error:" << TJTY_PLAY_GetLastError(TJTY_PLAY_PORT_NUM);
		}
		break;
	}
	case AUDIO_AND_VIDEO_DATA://音视频混合数据
	{
		bRet = TJTY_PLAY_InputData(st.nPlayID, (BYTE*)pBuffer, dwBufSize);
		UINT uiFailCount = 3;
		while (!bRet && uiFailCount--)
		{
			//投递失败表明缓冲区已满，稍等后重新投递
			Sleep(40);
			bRet = TJTY_PLAY_InputData(st.nPlayID, (BYTE*)pBuffer, dwBufSize);
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


// CApplyRecordDlg dialog

IMPLEMENT_DYNAMIC(CApplyRecordDlg, CDialogEx)

CApplyRecordDlg::CApplyRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ApplyRecordDlg, pParent)
{
	m_oPersonInfo = std::make_shared<CMyListCtrl1>();
	m_oPicDoor = std::make_shared<CMyStatic1>();
	
	m_oEmergency = std::make_shared<CMyStatic2>();
	m_oGrant = std::make_shared<CMyStatic2>();
	m_oOpen = std::make_shared<CMyStatic2>();
	m_oEnterMapLayer = std::make_shared<CMyStatic2>();
	m_oLock = std::make_shared<CMyStatic2>();
	m_oRefuseOpen = std::make_shared<CMyStatic2>();
	m_oConfirm = std::make_shared<CMyStatic2>();
}

CApplyRecordDlg::~CApplyRecordDlg()
{
}

void CApplyRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Video1, m_oVideo1);
	DDX_Control(pDX, IDC_Video2, m_oVideo2);
	DDX_Control(pDX, IDC_pic2Door, *m_oPicDoor);
	//DDX_Control(pDX, IDC_SCROLLBAR1, m_oSBar);
	DDX_Control(pDX, IDC_Emergency, *m_oEmergency);
	DDX_Control(pDX, IDC_Grant, *m_oGrant);
	DDX_Control(pDX, IDC_Open, *m_oOpen);
	DDX_Control(pDX, IDC_EnterMapLayer, *m_oEnterMapLayer);
	DDX_Control(pDX, IDC_Lock, *m_oLock);
	DDX_Control(pDX, IDC_RefuseOpen, *m_oRefuseOpen);
	DDX_Control(pDX, IDC_Confirm, *m_oConfirm);
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
	m_oPersonInfo->CreateEx(LVS_EX_FLATSB | LVS_EX_DOUBLEBUFFER, LVS_REPORT | LVS_NOCOLUMNHEADER | LVS_OWNERDRAWFIXED | WS_CHILD | WS_VISIBLE,
		CRect(x, y, m_rcClient.right - 10, y + m_rcClient.Height() * 5 / 12 ), this, 1);
	//m_oPersonInfo.ShowScrollBar(SB_VERT, FALSE);
	//InitializeFlatSB(m_oPersonInfo.m_hWnd);
	//FlatSB_EnableScrollBar(m_oPersonInfo.m_hWnd, SB_BOTH, ESB_DISABLE_BOTH);
	//FlatSB_ShowScrollBar(m_oPersonInfo.m_hWnd, SB_VERT, FALSE);

	//门，图片从文档下载
	m_oPersonInfo->GetClientRect(&rc);
	y += rc.Height() + 20/*间距*/;
	m_oPicDoor->SetWindowPos(0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	m_oPicDoor->Set(_T("res\\closeddoor_32px.png"));

	//按钮，根据配置灰化处理
	y -= 15;
	w = rc.Width();//申请列表宽度
	m_oPicDoor->GetClientRect(&rc);
	int nGap = 30;//按钮之间的间距
	//应急处置
	x += rc.Width() + 5; 
	w = (w - (rc.Width() + 5)/*门*/) / 3/*3个按钮*/ - nGap;
	m_oEmergency->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//申请授权
	x += w + nGap;
	m_oGrant->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//开门
	x += w + nGap;
	m_oOpen->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//m_oOpen.Set(false);
	//进入图层
	x -= 2 * (w + nGap);
	m_oEmergency->GetClientRect(&rc);
	y += rc.Height() + 2;
	m_oEnterMapLayer->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//锁门
	x += w + nGap;
	m_oLock->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//m_oLock.Set(false);
	//拒绝开门
	x += w + nGap;
	m_oRefuseOpen->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//m_oRefuseOpen.Set(false);
	//确认
	m_oPersonInfo->GetWindowRect(&rc);
	ScreenToClient(&rc);
	w = rc.Width() / 2;
	x = rc.left + w / 2;
	m_oEmergency->GetClientRect(&rc);
	y += rc.Height() + 2;
	m_oConfirm->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);

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
		//请求视频
		ReqVideo();

		//计时“已失效”，N秒，点击左侧就不能这样了
		//SetTimer(IDT_Valid, 5 * 1000, 0);
		//点击ListBox、初始化，计算剩余时间
		CTimeSpan tmLeft = CTime::GetCurrentTime() - m_stApplyInfo->tmApply;
		int nLeftSecond = (int)tmLeft.GetTotalSeconds();
		//认证处理有效时长
		int nLimitSecond = 0; 
		auto& spCtrlPlan = theApp.m_mapCtrlPlan[m_stApplyInfo->nImportance];
		if (0 == spCtrlPlan) {//没有就用默认的
			stCtrlPlanInfo st;
			nLimitSecond = st.nAuthTimeLimit * 60;
		}
		else
			nLimitSecond = spCtrlPlan->nAuthTimeLimit * 60;
		if (nLeftSecond < nLimitSecond) {
			//EnableButton({ GrantBtn ,OpenDoorBtn ,LockDoorBtn ,RefuseOpenBtn }, true);
			SetTimer(IDT_Valid, (nLimitSecond - nLeftSecond) * 1000, 0);
		}
		else {
			//OnTimer(IDT_Valid);  //窗口还没创建好，崩溃
			SetTimer(IDT_Valid, 0, 0);//立即触发
		}

		//网点名称
		GetDlgItem(IDC_title)->SetWindowText(m_stApplyInfo->strWebSiteName);

		//申请人员列表
		//m_oPersonInfo->MyInsertSubItem(m_stApplyInfo->stPersonInfo);
		m_oPersonInfo->Update();
		//m_oPersonInfo.Update();  //导致多了垂直滚动条
		//UpdateWindow();

		//远程认证，未设置上级授权，灰化“申请授权”
		//设置了上级授权，灰化“开门”，“锁门”，“拒绝开门”
		//策略配置
		const auto& stPlan = theApp.m_mapCtrlPlan[m_stApplyInfo->nImportance];
		vector<emButton> vecDisable;
		if (1 == stPlan->nAuthType) {
			if (stPlan->nSuperGrantType > 0) {
				vecDisable = { OpenDoorBtn , LockDoorBtn, RefuseOpenBtn };
			}
			else {
				vecDisable = { GrantBtn };
			}
		}
		else { //本地认证
			vecDisable = { GrantBtn ,OpenDoorBtn,LockDoorBtn,RefuseOpenBtn,ConfirmBtn };
		}
		EnableButton(vecDisable, false);

		Invalidate();
		ShowWindow(SW_NORMAL);
	}
}

//按钮灰化/可用处理
void CApplyRecordDlg::EnableButton(std::vector<emButton> vec, bool b)
{
	//和枚举对应，不能用static
	/*static*/ vector<std::shared_ptr<CMyStatic2>> vecBtn = {
		m_oEmergency, m_oGrant, m_oOpen,
		m_oEnterMapLayer, m_oLock, m_oRefuseOpen,
		m_oConfirm
	};

	//static std::bitset<emButtonBuff> bs;
	for (auto em : vec) {
		if (em < emButtonBuff) {
			vecBtn[em]->Set(b);
			vecBtn[em]->Invalidate(); //一设置就要全部OnPaint,这样真的好么？
		}
	}
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

		//灰化按钮
		EnableButton({ GrantBtn ,OpenDoorBtn ,LockDoorBtn ,RefuseOpenBtn }, false);

		break;
	}	
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CApplyRecordDlg::OnClickedEmergency()
{
	
	/*static vector<stEmergPlan> vecPlan = { 
		{stEmergPlan(_T("医院洪水预案"), { stEmergPlanStep(1,_T("开门")), stEmergPlanStep(2,_T("关警报，查看停尸间是否有人在睡觉，然后回机房拿消防斧回来砍断水管，最后关门")) })},
		{ stEmergPlan(_T("火山喷发预案"),{ stEmergPlanStep(1,_T("扯下窗帘")), stEmergPlanStep(2,_T("裹在头上祈祷")) }) }
	};

	static auto sp = std::make_shared<vector<stEmergPlan>>(vecPlan);*/


	//CEmergencyPlanDialog dlg(sp, this);
	//dlg.DoModal();
}


//申请视频
//查找节点
bool Lambda_FindNodeByID(const shared_ptr<stNode>& st, const int id) {
	return st->nID == id;
}
//查找主机
bool Lambda_FindHostByCode(const shared_ptr<stNode>& st, const std::string& code) {
	return st->strCode == code;
}
bool CApplyRecordDlg::ReqVideo()
{
	//从申请过来的门禁信息中拿到关联探头id
	//在设备信息中查找对应设备信息
	//构造申请结构，调服务库申请视频，传入窗口句柄
	//在回调中，调解码库播放

	//在申请消息过来的时候已经find过了，直接用[]
	const auto& vecCameraID = theApp.m_mapACSHostInfo[m_stApplyInfo->strDevName]->vecAuthRelCameraID;
	if (vecCameraID.empty()) return true; //无联动视频
	
	//const vector<CStatic*> vecPlayWnd = { &m_oVideo1, &m_oVideo2 };
	m_vecVideoInfo.clear();
	m_vecVideoInfo.resize(2);
	m_vecVideoInfo[0].pWnd = &m_oVideo1;
	m_vecVideoInfo[1].pWnd = &m_oVideo2;
	//
	const auto& vecDevInfo = theApp.m_mapNodeInfo[DeviceNode];
	const auto& vecHostInfo = theApp.m_mapNodeInfo[HostNode];

	int nCameraCnt = min(vecCameraID.size(), 2);

	for (int i = 0; i < nCameraCnt/*(int)vecCameraID.size()*/; ++i) {
		const int nCameraID = vecCameraID[i];

		auto itDev = std::find_if(vecDevInfo.begin(), vecDevInfo.end(),
			std::bind(Lambda_FindNodeByID, _1, nCameraID));
		if (vecDevInfo.end() == itDev) {
			theApp.WriteLog(warning, _T("没有找到摄像头！设备id：%d"), nCameraID);
			continue;
		}
		const shared_ptr<stDevice>& spDevInfo = (shared_ptr<stDevice>&)(*itDev);

		//构造申请预览结构
		T_VIEW_APPLYINFO tViewInfo = { 0 };
		tViewInfo.TDEVIDInfo.lDEVID = nCameraID;
		vector<long> vecTmp = { 102,0,0,0,0 };
		for(int i=0;i<5;++i)
			tViewInfo.TDEVIDInfo.lCMSCascadeInfo[i] = vecTmp[i];
		//获取级联信息 {102,0,0,0,0}
		//memcpy(tViewInfo.TDEVIDInfo.lCMSCascadeInfo, cRequestVideoParam.m_nCMSId, sizeof(long)*MAX_CASCADE);
		tViewInfo.nStreamType = STREAM_TYPE_DEF; //标清
		tViewInfo.nViewMode = 0;	// 普通预览
		tViewInfo.nChannel = spDevInfo->nChnlNo;

		//int nLinkType = -1;
		T_DEV_LOGIN_INFO stLoginInfo;
		//返回预览操作句柄，-1失败
		long nPlayID = TY_Server_RequestPlay(theApp.m_oGobal->nCMSHander, &tViewInfo, m_vecVideoInfo[i].nLinkType, &stLoginInfo);
		DWORD dwErr = TY_Server_GetLastError();
		if (-1 == nPlayID) {
			theApp.WriteLog(error, _T("请求预览失败！设备id：%d"), nCameraID);
			continue;
		}
		m_vecVideoInfo[i].nPlayID = nPlayID;
		//根据探头所属主机编码，查找厂家类型
		auto itHost = std::find_if(vecHostInfo.begin(), vecHostInfo.end(),
			std::bind(Lambda_FindHostByCode, _1, spDevInfo->strFatherCode));
		//找不到探头之前就continue了，这里肯定能找到
		const shared_ptr<stHost>& spHostInfo = (shared_ptr<stHost>&)(*itHost);
		m_vecVideoInfo[i].nFactoryType = spHostInfo->nFactoryType;

		//开始预览，只有采用了经媒体转发的方式才调用该方法，直连要使用网络库
		int nRet = TY_Server_StartPlay(nPlayID, RealPlayDataCallBack, (DWORD)&m_vecVideoInfo[i]);
		if (nRet != 0) {//0成功，其他失败
			theApp.WriteLog(error, _T("开始预览失败！设备id：%d"), nCameraID);
			continue;
		}
	}

	return true;
}