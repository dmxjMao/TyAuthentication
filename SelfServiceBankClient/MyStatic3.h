#pragma once


// CMyStatic3
/*����ɫ������Ӧ���У�������ɫ������*/

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


