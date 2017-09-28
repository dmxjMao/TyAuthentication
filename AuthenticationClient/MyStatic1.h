#pragma once


/*
ƒ‹œ‘ æÕº∆¨
*/

class CMyStatic1 : public CStatic
{
	DECLARE_DYNAMIC(CMyStatic1)

public:
	CMyStatic1(/*TCHAR* pszImgPath*/);
	virtual ~CMyStatic1();
	//…Ë÷√Õº∆¨¬∑æ∂
	void Set(TCHAR* pszImgNormalPath, TCHAR* pszImgHoverPath);

protected:
	Image* m_oImg = nullptr;//≥£Ã¨Õº∆¨
	Image* m_oImgHover = nullptr;//–¸Õ£Õº∆¨
	bool m_bMouseTrack = true;//◊∑◊Ÿ Û±Í–¸Õ£
	bool m_bHover = false;// Û±Í «∑Ò–¸Õ£

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	//virtual void PreSubclassWindow();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	//virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


