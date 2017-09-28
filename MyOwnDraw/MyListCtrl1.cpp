// MyListCtrl1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListCtrl1.h"

/*
自绘列表框
重写DrawItem、MeasureItem，样式要OWNDRAW...
在DrawItem之前，收到Measure项高度的消息，如果样式是fix的，就只来一次，
*/

// CMyListCtrl1

IMPLEMENT_DYNAMIC(CMyListCtrl1, CListCtrl)

CMyListCtrl1::CMyListCtrl1()
{

}

CMyListCtrl1::~CMyListCtrl1()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl1, CListCtrl)
END_MESSAGE_MAP()



// CMyListCtrl1 message handlers




void CMyListCtrl1::PreSubclassWindow()
{
	//不排序、失去焦点也选择、悬停高亮、双缓存
	ModifyStyle(LVS_SORTASCENDING, LVS_SHOWSELALWAYS);
	SetExtendedStyle(GetExtendedStyle() | LVS_EX_ONECLICKACTIVATE
		| LVS_EX_DOUBLEBUFFER);

	CListCtrl::PreSubclassWindow();
}
