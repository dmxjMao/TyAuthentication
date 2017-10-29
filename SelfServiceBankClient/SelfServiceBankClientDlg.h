
// SelfServiceBankClientDlg.h : header file
//

#pragma once
//#include "afxwin.h"

//class CLogDialog;

// CSelfServiceBankClientDlg dialog
class CMyStatic1;
class CMyListBox1;
struct stApplyInfo;
class CApplyRecordDlg;
struct T_TRANSMITALARMINFO;
class CStgOperator;

class CSelfServiceBankClientDlg : public CDialogEx, public CZCMsgObserver
{
// Construction
public:
	CSelfServiceBankClientDlg(CWnd* pParent = NULL);
	~CSelfServiceBankClientDlg();
	//中介方法，维护各控件之间的逻辑
	//点击左侧，显示右侧
	void DisplayDetail(const std::shared_ptr<stApplyInfo>& st);
	//关闭记录，删除左边，右边
	void DeleteRecord(int idx);
	//删除申请
	void RemoveApply(const std::shared_ptr<stApplyInfo>& st);

	//消息通知
	virtual void Update(bool, DWORD, DWORD, PBYTE, INT);
	//插入申请记录
	void MyInsertRecord(const std::shared_ptr<stApplyInfo>& st);
	


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELFSERVICEBANKCLIENT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CRect m_rcClient, m_rcCaption, m_rcList, m_rcRecord; //客户区、标题区，列表区，记录区
	WORD m_dwApplyID = 0;//申请id
	
	std::shared_ptr<CMyStatic1> m_oCloseWindow = 0;//关闭按钮
	std::shared_ptr<CMyListBox1> m_oApplyList = 0;//申请列表
	//std::list<CApplyRecordDlg> m_liApplyRecordDlg; //申请记录详细对话框
	std::vector<std::shared_ptr<CApplyRecordDlg>> m_vecApplyRecordDlg; //申请记录详细对话框
	std::vector<std::shared_ptr<stApplyInfo>> m_vecApplyInfo;//单人刷卡申请消息
	//std::vector<tplMultiApplyInfo> m_vecMultiApplyInfo;//多人刷卡信息

	std::shared_ptr<CLogDialog> m_oLogDlg = 0;//日志对话框
	std::shared_ptr<CStgOperator> m_oStg = 0;//结构化存储

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	//afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	
	//关闭窗口
	afx_msg void OnStnClickedClosewindow();
	//拖动窗口
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
	//读取历史申请记录并显示
	void GetHistoryApplyAndDisplay();
	//插入申请消息
	void InsertApplyInfo(const std::shared_ptr<stApplyInfo>&);
	
	//初始化ZCMsgManager消息处理函数
	void InitZCMsgHandler();
	std::map<DWORD, void(CSelfServiceBankClientDlg::*)(PBYTE, DWORD, INT)> m_mapZCMsgHandler;//ZCMsgManager消息处理函数
	//刷卡认证信息
	void ZCMsgAuthentication(PBYTE, DWORD, INT);
	//解析刷卡信息
	//bool ZCMsgHelper_ParseMemo(CString&, std::vector<CString>&);
	//解析触发时间
	CTime ZCMsgHelper_ParseTime(const char*);
	//是否处理申请
	bool IfDealTheApplyMsg(const CString& strCardNum/*, const CTime& tmApply*/);
	//本地认证
	void LocalAuth(const T_TRANSMITALARMINFO&, const std::shared_ptr<stACSHostInfo>&);
	//远程认证
	void RemoteAuth(const T_TRANSMITALARMINFO&, const std::shared_ptr<stACSHostInfo>&);
	//构造刷卡信息
	bool CreateApplyInfo(const T_TRANSMITALARMINFO&, const std::shared_ptr<stACSHostInfo>&, UINT8 nLocal);
	//开门
	void ZCMsgOpenDoor(PBYTE, DWORD, INT);

#ifdef DEBUG

#endif // DEBUG

public:
//	CStatic m_oDemoVideo;
//demo获取视频
	CStatic m_demoVideo;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDblclkDemovideo();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
