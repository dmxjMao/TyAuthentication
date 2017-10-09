#pragma once


// CEmergencyPlanDialog dialog
class CMyStatic3;
class CMyButton1;
class CMyButton2;
class CMyStatic1;
class CEmergencyPlanDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CEmergencyPlanDialog)

public:
	CEmergencyPlanDialog(CWnd* pParent = NULL);   // standard constructor
	CEmergencyPlanDialog(const std::shared_ptr<std::vector<stEmergPlan>>& sp, CWnd* pParent = NULL);
	virtual ~CEmergencyPlanDialog();
	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EmergencyPlan };
#endif

protected:
	std::shared_ptr<std::vector<stEmergPlan>> m_vecEmergPlan = nullptr;//预案信息
	//控件
	CWnd* m_pParent = nullptr; //父窗口
	std::shared_ptr<CMyStatic3> m_oName = nullptr;//预案名
	std::shared_ptr<CMyButton1> m_oOther = nullptr;//其他预案
	std::vector<std::shared_ptr<CMyButton2>> m_vecStep;//预案步骤
	std::shared_ptr<CMyButton1> m_oSubmit = nullptr;//提交
	std::shared_ptr<CMyStatic1> m_oCloseWindow = nullptr;//关闭按钮

	std::shared_ptr<Image> m_img1 = nullptr;//图1
	std::shared_ptr<Image> m_img2 = nullptr;//图2

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//关闭窗口
	afx_msg void OnStnClickedClosewindow();
};
