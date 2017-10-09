#pragma once
#include "CommonDefine.h"  //struct
#include "afxwin.h"
#include "MyListCtrl1.h" //申请认证人员
#include "MyStatic1.h" //门
#include "MyStatic2.h" //按钮

// CApplyRecordDlg dialog

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
	CMyListCtrl1 m_oPersonInfo;  //申请认证人员信息

	CMyStatic1 m_oPicDoor;//门

	CMyStatic2 m_oEmergency;//应急处置
	CMyStatic2 m_oGrant;//申请授权
	CMyStatic2 m_oOpen;//开门
	CMyStatic2 m_oEnterMapLayer;//进入图层
	CMyStatic2 m_oLock;//锁门
	CMyStatic2 m_oRefuseOpen;//拒绝开门
	CMyStatic2 m_oConfirm;//确认并关闭

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

public:
	//获取成员m_stApplyInfo
	inline /*decltype(m_stApplyInfo)*/const std::shared_ptr<stApplyInfo>& 
		GetApplyInfo() const { return m_stApplyInfo; }
	inline void SetApplyInfo(const std::shared_ptr<stApplyInfo>& st) {
		m_stApplyInfo = st; 
		//Update();
	}
	//设置对话框在父窗口中的区域，因为Create->OnInitDialog->SetWindowPos
	inline void SetRectInParent(const CRect& rc) { m_rcInParent = rc; }
	//刷新显示
	void Update();
	//按钮灰化/可用处理
	void EnableButton(emButton em);

private:
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedEmergency();
};
