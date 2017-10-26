// ApplyRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "ApplyRecordDlg.h"
#include "afxdialogex.h"

#include "MyCommonDefine.h"  //struct
#include "MyListCtrl1.h" //������֤��Ա
#include "MyStatic1.h" //��
#include "MyStatic2.h" //��ť
#include "EmergencyPlanDialog.h" //Ӧ������
//#include "MyState.h"//����״̬
#include "SelfServiceBankClientDlg.h"

//��������
#include "TYServerSDK.h"
//�����
#include "LoadTJTY_Play.h"

#include "ZCMsgManager.h"

namespace {
	#define IDT_Valid	1

	using std::vector;
	using std::shared_ptr;
	using std::make_shared;
	using std::placeholders::_1;

	const UINT8 cstnVideoCnt = 1;


};



// Ԥ������Ƶ�ص�
void __stdcall RealPlayDataCallBack(long lHandle, DWORD dwDataType, BYTE *pBuffer,
	DWORD dwBufSize, DWORD dwUser)
{
	//��������
	const stVideoInfo& st = *(stVideoInfo*)dwUser;
	bool bRet = false;

	static DWORD dwBuffSize = (1024 << 10); //����������������������С
	static int nBuffNum = 25;//��������������󻺴�֡��
	UINT8 nWndNo = st.nWndNo;//st.nPlayID����

	switch (dwDataType)
	{
	case SYSHEAD_DATA: //ϵͳͷ��Ϣ
	{
		bRet = TJTY_PLAY_InitplayStyle(nWndNo, st.nFactoryType);
		bRet = TJTY_PLAY_SetStreamOpenMode(nWndNo, 0);				//����Ϊʵʱ�����ţ�Hik��dh��Ч

		int nHeaderSize = 40;		//�����󻪵�����������ƵͷΪ40�ֽ�
		if (TJTY_DVR_BSR == st.nFactoryType || TJTY_DVR_BSR7 == st.nFactoryType){//����ϵ��Ϊ256�ֽ���Ƶͷ
			nHeaderSize = 256;
		}
		bRet = TJTY_PLAY_StartPlay(nWndNo, (BYTE*)pBuffer, nHeaderSize, dwBuffSize, st.pWnd->GetSafeHwnd(), nBuffNum);
		if (! bRet){
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


// CApplyRecordDlg dialog

IMPLEMENT_DYNAMIC(CApplyRecordDlg, CDialogEx)

CApplyRecordDlg::CApplyRecordDlg(int nIdx, CSelfServiceBankClientDlg* pDlg, CWnd* pParent /*=NULL*/)
	: m_nIdx(nIdx), m_oMediator(pDlg), CDialogEx(IDD_ApplyRecordDlg, pParent)
{
	m_oPersonInfo = make_shared<CMyListCtrl1>();
	m_oPicDoor = make_shared<CMyStatic1>();
	
	m_oEmergency = make_shared<CMyStatic2>();
	m_oGrant = make_shared<CMyStatic2>();
	m_oOpen = make_shared<CMyStatic2>();
	m_oEnterMapLayer = make_shared<CMyStatic2>();
	m_oLock = make_shared<CMyStatic2>();
	m_oRefuseOpen = make_shared<CMyStatic2>();
	m_oConfirm = make_shared<CMyStatic2>();

	//��Ƶ��Ϣ
	CStatic* pWnd[] = { &m_oVideo1,&m_oVideo2 };
	m_vecVideoInfo.resize(cstnVideoCnt);
	for (int i = 0; i < cstnVideoCnt; ++i) {
		m_vecVideoInfo[i].nWndNo = i + 1;
		m_vecVideoInfo[i].pWnd = pWnd[i];
	}
	
	//m_pState = make_shared<CApplyState>();

}

CApplyRecordDlg::~CApplyRecordDlg()
{
	//ֹͣԤ����Ƶ
	StopVideo();
	
	//����ͼ�㣬��dlg�Ѿ������ˣ�ZC�ķ���ob->Update��obΪ�գ�����
	//CZCMsgManager::Instance()->RequestMsg(ZC_MODULE_BCBCLIENT, ZC_MSG_BCBCLIENT_ALARMPOSITION_UNLOCK);
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
	ON_STN_DBLCLK(IDC_Video1, &CApplyRecordDlg::OnDblclkVideo1)
	ON_STN_CLICKED(IDC_EnterMapLayer, &CApplyRecordDlg::OnStnClickedEntermaplayer)
	ON_STN_CLICKED(IDC_Open, &CApplyRecordDlg::OnStnClickedOpen)
	ON_STN_CLICKED(IDC_Lock, &CApplyRecordDlg::OnStnClickedLock)
	ON_STN_CLICKED(IDC_RefuseOpen, &CApplyRecordDlg::OnStnClickedRefuseopen)
	ON_STN_CLICKED(IDC_Confirm, &CApplyRecordDlg::OnStnClickedConfirm)
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
	m_oPersonInfo->CreateEx(LVS_EX_FLATSB | LVS_EX_DOUBLEBUFFER, LVS_REPORT | LVS_NOCOLUMNHEADER | LVS_OWNERDRAWFIXED | WS_CHILD | WS_VISIBLE,
		CRect(x, y, m_rcClient.right - 10, y + m_rcClient.Height() * 5 / 12 ), this, 1);
	//m_oPersonInfo.ShowScrollBar(SB_VERT, FALSE);
	//InitializeFlatSB(m_oPersonInfo.m_hWnd);
	//FlatSB_EnableScrollBar(m_oPersonInfo.m_hWnd, SB_BOTH, ESB_DISABLE_BOTH);
	//FlatSB_ShowScrollBar(m_oPersonInfo.m_hWnd, SB_VERT, FALSE);

	//�ţ�ͼƬ���ĵ�����
	m_oPersonInfo->GetClientRect(&rc);
	y += rc.Height() + 20/*���*/;
	m_oPicDoor->SetWindowPos(0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	m_oPicDoor->Set(_T("res\\closeddoor_32px.png"));
	//m_oPicDoor->Set(_T("res\\openeddoor_32px.png"));

	//��ť���������ûһ�����
	y -= 15;
	w = rc.Width();//�����б���
	m_oPicDoor->GetClientRect(&rc);
	int nGap = 30;//��ť֮��ļ��
	//Ӧ������
	x += rc.Width() + 5; 
	w = (w - (rc.Width() + 5)/*��*/) / 3/*3����ť*/ - nGap;
	m_oEmergency->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//������Ȩ
	x += w + nGap;
	m_oGrant->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//����
	x += w + nGap;
	m_oOpen->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//m_oOpen.Set(false);
	//����ͼ��
	x -= 2 * (w + nGap);
	m_oEmergency->GetClientRect(&rc);
	y += rc.Height() + 2;
	m_oEnterMapLayer->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//����
	x += w + nGap;
	m_oLock->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//m_oLock.Set(false);
	//�ܾ�����
	x += w + nGap;
	m_oRefuseOpen->SetWindowPos(0, x, y, w, 20, SWP_NOZORDER);
	//m_oRefuseOpen.Set(false);
	//ȷ��
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
		//������Ƶ
		ReqVideo();

		//ʧЧ�ж�
		IsInvalid();

		//��������
		GetDlgItem(IDC_title)->SetWindowText(m_stApplyInfo->strWebSiteName);

		//������Ա�б�
		//m_oPersonInfo->MyInsertSubItem(m_stApplyInfo->stPersonInfo);
		m_oPersonInfo->Update();
		//m_oPersonInfo.Update();  //���¶��˴�ֱ������
		//UpdateWindow();

		//��֤
		if (1 == m_stApplyInfo->nLocal) {//Զ����֤
			RemoteAuth();
		}
		else if(0 == m_stApplyInfo->nLocal){ //������֤���ǹܿأ����ļ�أ���������������������֤
			LocalAuth();	
		}

		Invalidate();
		ShowWindow(SW_NORMAL);
	}
}


void CApplyRecordDlg::SetApplyInfo(const std::shared_ptr<stApplyInfo>& st, bool bAdd) 
{
	m_stApplyInfo = st;
	if (bAdd) {//���������Ա
		m_oPersonInfo->MyInsertSubItem(st->stPersonInfo);
	}
	Update();
}

//��ť�һ�/���ô���
void CApplyRecordDlg::EnableButton(std::vector<emButton> vec, bool b)
{
	//��ö�ٶ�Ӧ��������static
	/*static*/ vector<std::shared_ptr<CMyStatic2>> vecBtn = {
		m_oEmergency, m_oGrant, m_oOpen,
		m_oEnterMapLayer, m_oLock, m_oRefuseOpen,
		m_oConfirm
	};

	//static std::bitset<emButtonBuff> bs;
	for (auto em : vec) {
		if (em < emButtonBuff) {
			vecBtn[em]->Set(b);
			vecBtn[em]->Invalidate(); //һ���þ�Ҫȫ��OnPaint,������ĺ�ô��
		}
	}
}




void CApplyRecordDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent) {
	case IDT_Valid: //����ʧЧ��
	{
		DoInvalid();
		break;
	}	
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CApplyRecordDlg::OnClickedEmergency()
{
	
	/*static vector<stEmergPlan> vecPlan = { 
		{stEmergPlan(_T("ҽԺ��ˮԤ��"), { stEmergPlanStep(1,_T("����")), stEmergPlanStep(2,_T("�ؾ������鿴ͣʬ���Ƿ�������˯����Ȼ��ػ�������������������ˮ�ܣ�������")) })},
		{ stEmergPlan(_T("��ɽ�緢Ԥ��"),{ stEmergPlanStep(1,_T("���´���")), stEmergPlanStep(2,_T("����ͷ����")) }) }
	};

	static auto sp = std::make_shared<vector<stEmergPlan>>(vecPlan);*/

	CEmergencyPlanDialog dlg(this);
	dlg.DoModal();
}


//������Ƶ
//��������
bool Lambda_FindNodeByID(const shared_ptr<stNode>& st, const int id) {
	return st->nID == id;
}
//�������������ͨ���Ų���̽ͷ�豸id
//bool Lambda_FindDevByHostCodeAndChnlID(const shared_ptr<stNode>& st, const std::string& code, const int chnlid) {
//	const shared_ptr<stDevice>& spDevInfo = (shared_ptr<stDevice>&)(st);
//	return (spDevInfo->strHostCode == code && spDevInfo->nChnlNo == chnlid);
//}
//���ҵ�ǰ�û��Ƿ�������Ž�
bool Lambda_FindDealHostByID(const USERDOORCAMERARELATION_CLIENT_GET_S& st, const int id) {
	return st.nDoorId == id;
}
//�̺߳������������Ƶ��
UINT TYServerVideoThread(LPVOID lpParam)
{
	CApplyRecordDlg& dlg = *(CApplyRecordDlg*)lpParam;

	//�õ�����̽ͷid
	//���豸��Ϣ�в��Ҷ�Ӧ�豸��Ϣ
	//��������ṹ���������������Ƶ�����봰�ھ��
	//�ڻص��У�������ⲥ��

	//�����û�������Ž�
	const auto& pVecDealHost = theApp.m_mapUserInfo[theApp.m_strCurUserName]->pDealedACSHost;
	if (!pVecDealHost || pVecDealHost->empty()) return true; //��������Ƶ

	auto itDealHost = std::find_if(pVecDealHost->begin(), pVecDealHost->end(),
		std::bind(Lambda_FindDealHostByID, _1, dlg.GetApplyInfo()->nDevID));

	if (pVecDealHost->end() == itDealHost) return true; //��������Ž�

	dlg.StopVideo();

	//
	//const auto& vecDevInfo = theApp.m_mapNodeInfo[DeviceNode];
	const auto& vecHostInfo = theApp.m_mapNodeInfo[HostNode];

	//int nCameraCnt = 1/*min(vecCameraID.size(), 2)*/;

	for (int i = 0; i < cstnVideoCnt/*(int)vecCameraID.size()*/; ++i) {
		//��������Ԥ���ṹ
		int nDevID = itDealHost->nDeviceId;
		auto& stVideo = dlg.m_vecVideoInfo[i];
		stVideo.nDevID = nDevID;
		stVideo.nChnlNo = itDealHost->nChannelNo;

		T_VIEW_APPLYINFO tViewInfo = { 0 };
		tViewInfo.TDEVIDInfo.lDEVID = nDevID;
		//vector<long> vecTmp = { itDealHost->nCenterNo,0,0,0,0 };
		//for(int i=0;i<5;++i)
		tViewInfo.TDEVIDInfo.lCMSCascadeInfo[0] = itDealHost->nCenterNo;
		tViewInfo.nStreamType = STREAM_TYPE_DEF; //����
		tViewInfo.nViewMode = 0;	// ��ͨԤ��
		tViewInfo.nChannel = /*spDevInfo->nChnlNo*/itDealHost->nChannelNo;

		//int nLinkType = -1;
		T_DEV_LOGIN_INFO stLoginInfo;
		//����Ԥ�����������-1ʧ��
		long nPlayID = TY_Server_RequestPlay(theApp.m_oGobal->nCMSHander, &tViewInfo, stVideo.nLinkType, &stLoginInfo);
		DWORD dwErr = TY_Server_GetLastError();
		if (-1 == nPlayID) {
			theApp.WriteLog(error, _T("����Ԥ��ʧ�ܣ��豸id��%d"), nDevID);
			continue;
		}

		//����������Ϣ����ȡ��������
		auto itHost = std::find_if(vecHostInfo.begin(), vecHostInfo.end(),
			std::bind(Lambda_FindNodeByID, _1, nDevID));
		const shared_ptr<stHost>& spHostInfo = (shared_ptr<stHost>&)(*itHost);

		stVideo.nPlayID = nPlayID;
		stVideo.nFactoryType = spHostInfo->nFactoryType;

		//��ʼԤ����ֻ�в����˾�ý��ת���ķ�ʽ�ŵ��ø÷�����ֱ��Ҫʹ�������
		int nRet = TY_Server_StartPlay(nPlayID, RealPlayDataCallBack, (DWORD)&stVideo);
		if (nRet != 0) {//0�ɹ�������ʧ��
			theApp.WriteLog(error, _T("��ʼԤ��ʧ�ܣ��豸id��%d"), nDevID);
			continue;
		}
	}

	return TRUE;
}
bool CApplyRecordDlg::ReqVideo()
{
	//���������ͬ��2·��Ƶ
	//if(m_stApplyInfo->nDevID == m_vecVideoInfo[0].nDevID &&
	//	m_stApplyInfo)

	//TY_Server����ͬ���ģ����������߳�
	AfxBeginThread(TYServerVideoThread, this);

	return true;
}

void CApplyRecordDlg::OnDblclkVideo1()
{
	static bool bZoom = false;
	CRect rc;
	m_oVideo1.GetWindowRect(&rc);
	ScreenToClient(&rc);//�ؼ��ڶԻ����е�λ��
	static CRect rcOri = rc; 

	CWnd* pParent = GetParent();
	int x = 0, y = 0, w = 0, h = 0;
	if (bZoom) {//�Ŵ�˫������С
		//���öԻ��������Ի����е�λ��
		x = m_rcInParent.left, y = m_rcInParent.top, w = m_rcInParent.Width(), h = m_rcInParent.Height();
		SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
		//���ÿؼ�λ��
		x = rcOri.left, y = rcOri.top, w = rcOri.Width(), h = rcOri.Height();

		bZoom = false;
	}
	else {//��С�Ŵ�
		//GetParent()->GetWindowRect(&rc); �޷�����CApplyRecordDlg�ı߽�
		pParent->GetClientRect(&rc);
		const int nHeight = theApp.m_oGobal->cstnTitleHeight;
		x = rc.left, y = rc.top + nHeight, w = rc.Width(), h = rc.Height() - nHeight;
		SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
		y -= nHeight;
		bZoom = true;
	}
	m_oVideo1.SetWindowPos(0, x, y, w, h, SWP_NOZORDER);
}

//����ͼ��
void CApplyRecordDlg::OnStnClickedEntermaplayer()
{
	//char buf[64] = { 0 };  �ʹ���ҳ�й�
	//wcstombs_s(0, buf, _countof(buf), m_stApplyInfo->strWebSiteName.GetBuffer(), _TRUNCATE);
	CT2A szBuf(m_stApplyInfo->strWebSiteName.GetBuffer());
	
	//�Ƚ������ڽ���
	const auto& pMgr = CZCMsgManager::Instance();
	pMgr->RequestMsg(ZC_MODULE_BCBCLIENT, ZC_MSG_BCBCLIENT_ALARMPOSITION_UNLOCK);
	pMgr->RequestMsg(ZC_MODULE_BCBCLIENT,
		ZC_MSG_BCBCLIENT_ALARMPOSITION, (PBYTE)(LPSTR)szBuf, /*strlen(szBuf)����64*/64);
}

//����
void CApplyRecordDlg::OnStnClickedOpen()
{
	T_CONTROLACSHOSTPRARM st = { 0 };

	CT2A szDevName(m_stApplyInfo->strDevName.GetBuffer());
	memcpy_s(st.chAlarmSource, _countof(st.chAlarmSource), szDevName, strlen(szDevName));

	st.nCmd = 2;//����
	auto& sp = MyStructToPBYTE(st);

	const auto& pMsg = CZCMsgManager::Instance();
	//pMsg->AddObserver();
	//"����" + ���� = ����
	pMsg->RequestMsgWithMsgID(ZC_MODULE_BCBCLIENT,
		ZC_MSG_BCBCLIENT_CONTROLACSHOST, m_nIdx, sp.get(), sizeof(T_CONTROLACSHOSTPRARM));

	
	st.nCmd = 1;//����
	sp = MyStructToPBYTE(st);
	pMsg->RequestMsgWithMsgID(ZC_MODULE_BCBCLIENT,
		ZC_MSG_BCBCLIENT_CONTROLACSHOST, m_nIdx, sp.get(), sizeof(T_CONTROLACSHOSTPRARM));

	//������Ϣ�����Ի���ZCMsgOpenDoor�д���
}


//����
void CApplyRecordDlg::OnStnClickedLock()
{
	T_CONTROLACSHOSTPRARM st = { 0 };

	CT2A szDevName(m_stApplyInfo->strDevName.GetBuffer());
	memcpy_s(st.chAlarmSource, _countof(st.chAlarmSource), szDevName, strlen(szDevName));

	st.nCmd = 2;
	auto& sp = MyStructToPBYTE(st);

	//pMsg->AddObserver();
	//"����" = ����
	CZCMsgManager::Instance()->RequestMsgWithMsgID(ZC_MODULE_BCBCLIENT,
		ZC_MSG_BCBCLIENT_CONTROLACSHOST, m_nIdx, sp.get(), sizeof(T_CONTROLACSHOSTPRARM));

}

//�ܾ�����
void CApplyRecordDlg::OnStnClickedRefuseopen()
{
	//��¼��־

}


void CApplyRecordDlg::IsInvalid()
{
	//��ʱ����ʧЧ����N�룬������Ͳ���������
	//SetTimer(IDT_Valid, 5 * 1000, 0);
	//���ListBox����ʼ��������ʣ��ʱ��
	CTimeSpan tmLeft = CTime::GetCurrentTime() - m_stApplyInfo->tmApply;
	int nLeftSecond = (int)tmLeft.GetTotalSeconds();
	//��֤������Чʱ��
	int nLimitSecond = 0;
	//auto& spCtrlPlan = theApp.m_mapCtrlPlan[m_stApplyInfo->nImportance];
	auto& spCtrlPlan = theApp.GetCtrlPlanInfo(m_stApplyInfo->nImportance);
	nLimitSecond = spCtrlPlan->nAuthTimeLimit * 60;
	//if (0 == spCtrlPlan) {//û�о���Ĭ�ϵ�
	//	stCtrlPlanInfo st;
	//	nLimitSecond = st.nAuthTimeLimit * 60;
	//}
	//else
	//	nLimitSecond = spCtrlPlan->nAuthTimeLimit * 60;
	if (nLeftSecond < nLimitSecond) {
		SetTimer(IDT_Valid, (nLimitSecond - nLeftSecond) * 1000, 0);
	}
	else {
		//OnTimer(IDT_Valid);  //���ڻ�û�����ã�����
		SetTimer(IDT_Valid, 0, 0);//��������
	}
}

//ʧЧ����
void CApplyRecordDlg::DoInvalid()
{
	KillTimer(IDT_Valid);

	//ֹͣԤ��
	StopVideo();

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

	//�һ���ť
	EnableButton({ GrantBtn ,OpenDoorBtn ,LockDoorBtn ,RefuseOpenBtn }, false);

}

//ֹͣԤ����Ƶ
void CApplyRecordDlg::StopVideo()
{
	for (int i = 0; i < cstnVideoCnt; ++i) {
		const auto& st = m_vecVideoInfo[i];
		TJTY_PLAY_StopPlay(st.nWndNo);
		TY_Server_StopPlay(st.nPlayID, st.nLinkType);
	}
}

//Զ����֤��֧
void CApplyRecordDlg::RemoteAuth()
{
	const auto& stPlan = theApp.GetCtrlPlanInfo(m_stApplyInfo->nImportance);
	//�Ƿ��ϼ���Ȩ
	if (stPlan->nSuperGrantType > 0) {//UINT8 = -1����255��ʼ��>0
		vector<emButton> vecDisable = { OpenDoorBtn , LockDoorBtn, RefuseOpenBtn };
		EnableButton(vecDisable, false);
	}
	else { //����Ҫ�ϼ���Ȩ
		vector<emButton> vecDisable = { GrantBtn };
		EnableButton(vecDisable, false);
	}
}

//������֤��֧
void CApplyRecordDlg::LocalAuth()
{
	//�һ���ť
	vector<emButton> vecDisable = { GrantBtn ,OpenDoorBtn,LockDoorBtn,RefuseOpenBtn,ConfirmBtn };
	EnableButton(vecDisable, false); 
}




void CApplyRecordDlg::OnStnClickedConfirm()
{
	emAuthState em = m_stApplyInfo->emState;
	if (Dealing == em || em == Verify) {//�����кʹ����
		AfxMessageBox(_T("���봦���л����ˣ�"));
		return;
	}

	//����֤����ʧЧ��ֱ�ӹر�
	//�н��ߣ����ؼ�֮��Ĺ�ϵ
	m_oMediator->DeleteRecord(m_nIdx);
}
