#pragma once


// CMyListCtrl1
/*
自定义的“项”，显示申请人员信息
*/

class CMyListCtrl1 : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListCtrl1)

public:
	CMyListCtrl1();
	virtual ~CMyListCtrl1();

protected:
	std::vector<stApplyPersonInfo> m_vecStPersonInfo;//申请认证人员信息
	DECLARE_MESSAGE_MAP()

public:
	virtual void PreSubclassWindow();
	//afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	//decltype(m_vecStPersonInfo)不是引用类型
	decltype((m_vecStPersonInfo)) GetInfoVec() { return m_vecStPersonInfo; }
	
	//afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


