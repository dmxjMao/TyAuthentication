#pragma once

// CApplyRecordDlg dialog
enum emButton;
struct stApplyInfo;
class CMyListCtrl1;
class CMyStatic1;
class CMyStatic2;

class CApplyRecordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CApplyRecordDlg)

public:
	CApplyRecordDlg(CWnd* pParent = NULL);   // standard constructor
	CApplyRecordDlg(const CApplyRecordDlg&) {} //vector<CApplyRecordDlg>需要
	virtual ~CApplyRecordDlg();

	virtual BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ApplyRecordDlg };
#endif

protected:
	CRect m_rcInParent, m_rcClient/*, m_rcPerson*/;//在父窗口中的区域坐标、客户区域
	//共享申请数据
	std::shared_ptr<stApplyInfo> m_stApplyInfo = nullptr;
	//std::vector<stApplyPersonInfo> m_vecStPersonInfo;//申请认证人员信息

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

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

public:
	//获取成员m_stApplyInfo
	inline const std::shared_ptr<stApplyInfo>& 
		GetApplyInfo() const { return m_stApplyInfo; }
	inline void SetApplyInfo(const std::shared_ptr<stApplyInfo>& st) {
		m_stApplyInfo = st; 
	}
	//设置对话框在父窗口中的区域，因为Create->OnInitDialog->SetWindowPos
	inline void SetRectInParent(const CRect& rc) { m_rcInParent = rc; }
	//刷新显示
	void Update();
	//按钮灰化/可用处理，改为按钮
	void EnableButton(std::vector<emButton> em, bool b);


public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedEmergency();
};
