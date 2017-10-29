#pragma once

// CApplyRecordDlg dialog
enum emButton;
struct stApplyInfo;
class CMyListCtrl1;
class CMyStatic1;
class CMyStatic2;
//class CApplyState;//申请状态
class CSelfServiceBankClientDlg;//中介
class CStgOperator;//结构化存储

//视频信息
struct stVideoInfo {
	//ENUM_PlayType emFactoryType;//厂家编号
	int nFactoryType;//厂家编号
	CStatic* pWnd = 0;//播放窗口
	long nPlayID = -1;//播放句柄
	int nLinkType = 1;//直连/转发
	UINT8 nWndNo = 1;//播放窗口号

	int nDevID = -1;//探头所在设备id
	int nChnlNo = -1;//通道号
};

class CApplyRecordDlg : public CDialogEx/*, public CZCMsgObserver*/
{
	DECLARE_DYNAMIC(CApplyRecordDlg)
	friend class CSelfServiceBankClientDlg;
public:
	CApplyRecordDlg(int nIdx, CSelfServiceBankClientDlg* pDlg,
		std::shared_ptr<CStgOperator>& pStg, CWnd* pParent = NULL);   // standard constructor
	//CApplyRecordDlg(const CApplyRecordDlg&) {} //vector<CApplyRecordDlg>需要
	virtual ~CApplyRecordDlg();
	//消息通知
	//virtual void Update(bool, DWORD, DWORD, PBYTE, INT);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ApplyRecordDlg };
#endif

protected:
	CRect m_rcInParent, m_rcClient/*, m_rcPerson*/;//在父窗口中的区域坐标、客户区域
	
	std::shared_ptr<stApplyInfo> m_stApplyInfo = 0;//申请数据
	//std::vector<stApplyPersonInfo> m_vecStPersonInfo;//申请认证人员信息
	//std::shared_ptr<CApplyState> m_pState = 0; //申请状态
	//std::map<DWORD, void(CApplyRecordDlg::*)(PBYTE, DWORD, INT)> m_mapZCMsgHandler;//ZCMsgManager消息处理函数
	//中介者，复杂的控件通信逻辑交给中介
	//两种实现：1）Observer；2）直接提供接口；
	CSelfServiceBankClientDlg* m_oMediator;
	std::shared_ptr<CStgOperator>& m_oStg;

	CStatic m_oVideo1;//视频
	CStatic m_oVideo2;

	std::shared_ptr<CMyListCtrl1> m_oPersonInfo = 0;  //申请认证人员信息

	std::shared_ptr<CMyStatic1> m_oPicDoor = 0;//门

	std::shared_ptr<CMyStatic2> m_oEmergency = 0;//应急处置
	std::shared_ptr<CMyStatic2> m_oGrant = 0;//申请授权
	std::shared_ptr<CMyStatic2> m_oOpen = 0;//开门
	std::shared_ptr<CMyStatic2> m_oEnterMapLayer = 0;//进入图层
	std::shared_ptr<CMyStatic2> m_oLock = 0;//锁门
	std::shared_ptr<CMyStatic2> m_oRefuseOpen = 0;//拒绝开门
	std::shared_ptr<CMyStatic2> m_oConfirm = 0;//确认并关闭

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedEmergency();

public:
	//获取成员m_stApplyInfo
	inline const std::shared_ptr<stApplyInfo>& GetApplyInfo() const { return m_stApplyInfo; }
	void SetApplyInfo(const std::shared_ptr<stApplyInfo>& st, bool bAdd = false);
	//设置对话框在父窗口中的区域，因为Create->OnInitDialog->SetWindowPos
	inline void SetRectInParent(const CRect& rc) { m_rcInParent = rc; }
	//刷新显示
	void Update();
	//灰化/可用处理，有空改为按钮，因为CStatic的可用是重绘的
	void EnableButton(std::vector<emButton> em, bool b);
	//申请视频
	void ReqVideo();
	//停止预览视频
	void StopVideo();

public:
	std::vector<stVideoInfo> m_vecVideoInfo;//视频信息
	int m_nIdx;//在父窗口中的索引
	afx_msg void OnDblclkVideo1();
	afx_msg void OnStnClickedEntermaplayer();
	afx_msg void OnStnClickedOpen();

private:
	//失效判断
	bool IsInvalid();
	//失效处理
	void DoInvalid();
	//远程认证分支
	void RemoteAuth();
	//本地认证分支
	void LocalAuth();

public:
	afx_msg void OnStnClickedLock();
	afx_msg void OnStnClickedRefuseopen();
	afx_msg void OnStnClickedConfirm();
	afx_msg void OnStnClickedGrant();
};
