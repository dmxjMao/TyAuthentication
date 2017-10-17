#pragma once


// CMyListCtrl1
/*
自定义的“项”，显示申请人员信息
自绘滚动条
*/
//#include "MyScrollBar1.h"

struct stApplyPersonInfo;

class CMyListCtrl1 : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListCtrl1)

public:
	CMyListCtrl1();
	virtual ~CMyListCtrl1();

protected:
	//CMyScrollBar1 m_oScrollBar;
	std::vector<std::shared_ptr<stApplyPersonInfo>> m_vecPersonInfo;//申请认证人员信息
	DECLARE_MESSAGE_MAP()

public:
	//virtual void PreSubclassWindow();
	//afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	//decltype(m_vecStPersonInfo)不是引用类型
	//decltype((m_vecSpPersonInfo)) GetInfoVec() { return m_vecSpPersonInfo; }
	void MyInsertSubItem(const std::shared_ptr<stApplyPersonInfo>&/*std::shared_ptr<stApplyPersonInfo>*/); //插入人员信息
	bool Update();//显示
	
	//afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnPaint();  //和DrawItem冲突
	//afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
	//afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
	//virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


