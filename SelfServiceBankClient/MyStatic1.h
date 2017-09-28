#pragma once


/*
能显示图片
*/

class CMyStatic1 : public CStatic
{
	DECLARE_DYNAMIC(CMyStatic1)

public:
	CMyStatic1(/*TCHAR* pszImgPath*/);
	virtual ~CMyStatic1();
	//设置图片路径
	void Set(TCHAR* pszImgNormalPath, TCHAR* pszImgHoverPath = nullptr, 
		bool bFixOrImg = true/*固定大小还是按图片大小，默认固定*/);

protected:
	Image* m_oImg = nullptr;//常态图片
	Image* m_oImgHover = nullptr;//悬停图片
	bool m_bMouseTrack = true;//追踪鼠标悬停
	bool m_bHover = false;//鼠标是否悬停
	bool m_bFixOrImg = true; //固定大小还是按图片大小

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	//virtual void PreSubclassWindow();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	//virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


