#pragma once


// CMyListBox1
/*
�������⣺
1������ѡ�� �� ��ͣ��ͻ��m_curItem��Ϊ����
2������Ƴ��ؼ��������и�����׷����ͣ��Ϣ
*/

class CMyListBox1 : public CListBox
{
	DECLARE_DYNAMIC(CMyListBox1)

public:
	CMyListBox1();
	virtual ~CMyListBox1();

protected:
	//bool m_bMouseTrack = true, m_bMouseHover = false;
	//DRAWITEMSTRUCT m_disMouseHover;//�����ͣ��ṹ
	UINT m_curItem;//��ǰ���������

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


