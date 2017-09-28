#pragma once


// CMyListCtrl1

class CMyListCtrl1 : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListCtrl1)

public:
	CMyListCtrl1();
	virtual ~CMyListCtrl1();

protected:
	DECLARE_MESSAGE_MAP()

	virtual void PreSubclassWindow();
};


