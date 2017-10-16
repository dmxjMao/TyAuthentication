
// SelfServiceBankClientDlg.h : header file
//

#pragma once
#include "MyStatic1.h"
//#include "MyListCtrl1.h"
#include "MyListBox1.h"
#include "ApplyRecordDlg.h"

//class CLogDialog;

// CSelfServiceBankClientDlg dialog
#ifdef _DEBUG
class CMyButton1;
#endif
class CSelfServiceBankClientDlg : public CDialogEx, public CZCMsgObserver
{
// Construction
public:
	CSelfServiceBankClientDlg(CWnd* pParent = NULL);
	//中介方法
	//点击左侧，显示右侧
	void DisplayDetail(const std::shared_ptr<stApplyInfo>& st);
	//消息通知
	virtual void Update(bool, DWORD, DWORD, PBYTE, INT);
	//刷卡认证信息
	
	//插入申请记录
	void MyInsertRecord(const std::shared_ptr<stApplyInfo>& st);
	//申请授权回复，开关门，日志


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
	CMyStatic1 m_oCloseWindow;//关闭按钮
	
#ifdef DEBUG
	std::shared_ptr<CMyButton1> btn1;
#endif // DEBUG

	CMyListBox1 m_oApplyList;//申请列表
	//std::list<CApplyRecordDlg> m_liApplyRecordDlg; //申请记录详细对话框
	std::vector<CApplyRecordDlg> m_vecApplyRecordDlg; //申请记录详细对话框
	std::vector<std::shared_ptr<stApplyInfo>> m_vecApplyInfo;//申请消息

	std::shared_ptr<CLogDialog> m_oLogDlg = 0;//日志对话框

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
	void InsertApplyInfo(const std::shared_ptr<stApplyInfo>&);//插入申请消息
	
	//初始化ZCMsgManager消息处理函数
	void InitZCMsgHandler();
	std::map<DWORD, void(CSelfServiceBankClientDlg::*)(PBYTE, DWORD, INT)> m_mapZCMsgHandler;//ZCMsgManager消息处理函数
	//刷卡认证信息
	void ZCMsgAuthentication(PBYTE, DWORD, INT);
	//解析刷卡信息
	//bool ZCMsgHelper_ParseMemo(CString&, std::vector<CString>&);
	//解析触发时间
	CTime ZCMsgHelper_ParseTime(const char*);
};
