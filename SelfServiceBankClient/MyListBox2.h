#pragma once


// CMyListBox2
/*������ɫ����С
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


