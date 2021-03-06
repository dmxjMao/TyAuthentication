#pragma once


// CEmergencyPlanDialog dialog
class CMyStatic3;
class CMyButton1;
class CMyButton2;
class CMyStatic1;
class CMyListBox2;
struct stEmergPlan;
class CStgOperator;

class CEmergencyPlanDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CEmergencyPlanDialog)

public:
	CEmergencyPlanDialog(const WORD id, CString planName,
		std::shared_ptr<CStgOperator>&, CWnd* pParent = NULL);   // standard constructor
	virtual ~CEmergencyPlanDialog();
	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EmergencyPlan };
#endif

protected:
	//std::shared_ptr<std::vector<std::shared_ptr<stEmergPlan>>> m_vecEmergPlan = nullptr;//预案信息
	//控件
	CWnd* m_pParent = nullptr; //父窗口
	std::shared_ptr<CMyStatic3> m_oName = nullptr;//预案名
	std::shared_ptr<CMyButton1> m_oOther = nullptr;//其他预案
	std::shared_ptr<CMyListBox2> m_oOtherLB = nullptr;//其他预案列表
	std::vector<std::shared_ptr<CMyButton2>> m_vecStep;//预案步骤
	std::shared_ptr<CMyButton1> m_oSubmit = nullptr;//提交
	std::shared_ptr<CMyStatic1> m_oCloseWindow = nullptr;//关闭按钮

	std::shared_ptr<Image> m_img1 = nullptr;//图1
	std::shared_ptr<Image> m_img2 = nullptr;//图2
	CToolTipCtrl m_tt;//tooltip

	CString m_strCurPlanName;//当前预案名称
	WORD m_nApplyID = 0;//当前申请id
	std::shared_ptr<CStgOperator>& m_oStg;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg BOOL OnTtnNeedText(UINT id, NMHDR * pTTTStruct, LRESULT * pResult);//提示
	afx_msg void OnBtnClickedOtherEMPlan(); //点击其他预案
	afx_msg void OnOtherEMPlanSelchange();//选择其他预案
	afx_msg void OnStnClickedClosewindow();//关闭窗口
	afx_msg void OnClickEMPlanStep(UINT id);//双击预案步骤
	virtual BOOL PreTranslateMessage(MSG* pMsg);//提示

private:
	void DrawEMPlanStep(const std::shared_ptr<stEmergPlan>& st);//画预案步骤

};
