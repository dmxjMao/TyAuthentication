#pragma once


// CMyStatic3
/*背景色，自适应换行，文字颜色，对齐*/

class CMyStatic3 : public CStatic
{
	DECLARE_DYNAMIC(CMyStatic3)

public:
	CMyStatic3();
	virtual ~CMyStatic3();
	inline void Set() {}

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


