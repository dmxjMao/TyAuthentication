#pragma once


// CMyListCtrl1
/*
�Զ���ġ������ʾ������Ա��Ϣ
�Ի������
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
	std::vector<std::shared_ptr<stApplyPersonInfo>> m_vecPersonInfo;//������֤��Ա��Ϣ
	DECLARE_MESSAGE_MAP()

public:
	//virtual void PreSubclassWindow();
	//afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	//decltype(m_vecStPersonInfo)������������
	//decltype((m_vecSpPersonInfo)) GetInfoVec() { return m_vecSpPersonInfo; }
	void MyInsertSubItem(const std::shared_ptr<stApplyPersonInfo>&/*std::shared_ptr<stApplyPersonInfo>*/); //������Ա��Ϣ
	bool Update();//��ʾ
	
	//afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnPaint();  //��DrawItem��ͻ
	//afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
	//afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
	//virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


