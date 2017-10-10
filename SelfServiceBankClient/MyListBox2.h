#pragma once


// CMyListBox2
/*文字颜色、大小
*/

class CMyListBox2 : public CListBox
{
	DECLARE_DYNAMIC(CMyListBox2)

public:
	CMyListBox2();
	virtual ~CMyListBox2();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT /*lpMeasureItemStruct*/);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


