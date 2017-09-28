#pragma once


// CMyListBox1
/*
遗留问题：
1，多项选择 与 悬停冲突，m_curItem变为数组
2，鼠标移出控件，还是有高亮，追踪悬停消息
*/

class CMyListBox1 : public CListBox
{
	DECLARE_DYNAMIC(CMyListBox1)

public:
	CMyListBox1();
	virtual ~CMyListBox1();

protected:
	//bool m_bMouseTrack = true, m_bMouseHover = false;
	//DRAWITEMSTRUCT m_disMouseHover;//鼠标悬停项结构
	UINT m_curItem;//当前点击的区域

	DECLARE_MESSAGE_MAP()
	//virtual void PreSubclassWindow();
	//virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT /*lpMeasureItemStruct*/);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	//afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	//afx_msg void OnMouseLeave();
};


