#pragma once


/*
����ʾͼƬ
*/

class CMyStatic1 : public CStatic
{
	DECLARE_DYNAMIC(CMyStatic1)

public:
	CMyStatic1(/*TCHAR* pszImgPath*/);
	virtual ~CMyStatic1();
	//����ͼƬ·��
	void Set(TCHAR* pszImgNormalPath, TCHAR* pszImgHoverPath);

protected:
	Image* m_oImg = nullptr;//��̬ͼƬ
	Image* m_oImgHover = nullptr;//��ͣͼƬ
	bool m_bMouseTrack = true;//׷�������ͣ
	bool m_bHover = false;//����Ƿ���ͣ

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	//virtual void PreSubclassWindow();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	//virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


