#pragma once

/*
背景色，悬停色，居中文字
异性窗口 ？
为什么不用CButton或者CMFCButton？
*/

// CMyStatic2

class CMyStatic2 : public CStatic
{
	DECLARE_DYNAMIC(CMyStatic2)

public:
	CMyStatic2();
	virtual ~CMyStatic2();
	inline void Set(bool bEnable = true, Color bg = Color(54, 132, 215), 
		Color hoverBG = Color(24, 100, 100), 
		Color text = Color(255, 255, 255)) {
		m_bEnable = bEnable;  m_clrBG = bg; m_clrHoverBG = hoverBG; m_clrText = text;
	}

protected:
	bool m_bEnable = true;
	Color m_clrBG = Color(54, 132, 215);//背景色
	Color m_clrHoverBG = Color(24, 100, 100);//悬停背景色
	Color m_clrText = Color(255,255,255);//文本色
	Color m_clrGray = Color(125, 125, 125);//灰色
	//Color m_clrHoverText = Color(255, 255, 255);
	bool m_bMouseTrack = true;//追踪鼠标悬停
	bool m_bHover = false;//鼠标是否悬停
	//CRgn m_rgn;//窗口区域

	DECLARE_MESSAGE_MAP()


	afx_msg void OnPaint();
	virtual void PreSubclassWindow();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();

private:
	//画圆角矩形
	GraphicsPath* MakeRoundRect(Point topLeft, Point bottomRight, INT percentageRounded);
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnStnClicked();
};


