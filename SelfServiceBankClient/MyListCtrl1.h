#pragma once


// CMyListCtrl1
/*
�Զ���ġ������ʾ������Ա��Ϣ
�Ի������
*/
#include "MyScrollBar1.h"

class CMyListCtrl1 : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListCtrl1)

public:
	CMyListCtrl1();
	virtual ~CMyListCtrl1();

protected:
	CMyScrollBar1 m_oScrollBar;
	std::vector<stApplyPersonInfo> m_vecStPersonInfo;//������֤��Ա��Ϣ
	DECLARE_MESSAGE_MAP()

public:
	//virtual void PreSubclassWindow();
	//afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	//decltype(m_vecStPersonInfo)������������
	decltype((m_vecStPersonInfo)) GetInfoVec() { return m_vecStPersonInfo; }
	bool InitUpdate();//��ʼ��ʾ
	
	//afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	//afx_msg void OnPaint();  ��DrawItem��ͻ
};


