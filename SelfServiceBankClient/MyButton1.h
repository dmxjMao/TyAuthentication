#pragma once


// CMyButton1


class CMyButton1 : public CButton, public CUICfg
{
	DECLARE_DYNAMIC(CMyButton1)

public:
	CMyButton1();
	virtual ~CMyButton1();
	//inline void Set(bool bUnderLine, int nFontSize, Color clrBG, Color clrText){
	//	m_bUnderLine = bUnderLine; m_nFontSize = nFontSize;  
	//	m_clrBG = clrBG; m_clrText = clrText;
	//}

protected:
	bool m_bUnderLine = true;//下划线
	int m_nFontSize = 12;//字体大小
	Color m_clrBG = Color(0, 0, 0, 0);//背景色
	Color m_clrText = cstClrTitle;//文本颜色

	bool m_bMouseTrack = true, m_bHover = false;
	DECLARE_MESSAGE_MAP()

public:
	//afx_msg void OnBnClicked();
	afx_msg void OnPaint();
	//virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();

private:
	virtual bool OnMatchUICfg(const boost::smatch& what);
};


