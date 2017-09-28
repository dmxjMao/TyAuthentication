// MyListCtrl1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListCtrl1.h"


// CMyListCtrl1

IMPLEMENT_DYNAMIC(CMyListCtrl1, CListCtrl)

CMyListCtrl1::CMyListCtrl1()
{

}

CMyListCtrl1::~CMyListCtrl1()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl1, CListCtrl)
	//ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CMyListCtrl1::OnNMCustomdraw)
	//ON_WM_MEASUREITEM()
	ON_WM_MEASUREITEM_REFLECT()
END_MESSAGE_MAP()



// CMyListCtrl1 message handlers



void CMyListCtrl1::PreSubclassWindow()
{	
	//不起作用
	//SetExtendedStyle(GetExtendedStyle() | LVS_EX_FLATSB);
	CListCtrl::PreSubclassWindow();
}


//void CMyListCtrl1::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
//	/*typedef struct tagNMCUSTOMDRAWINFO {
//		NMHDR     hdr;
//		DWORD     dwDrawStage;  阶段 CDDS_POSTPAINT
//		HDC       hdc;
//		RECT      rc; CDDS_ITEMPREPAINT CDDS_PREPAINT 阶段初始化
//		DWORD_PTR dwItemSpec; 与控件有关
//		UINT      uItemState; 状态：勾选、焦点、悬停、不可用。。。
//		LPARAM    lItemlParam;
//	} NMCUSTOMDRAW, *LPNMCUSTOMDRAW;*/
//
//
//	*pResult = 0;
//}


//void CMyListCtrl1::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
//{
//	CListCtrl::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
//}

//注意要手动添加 ON_WM_MEASUREITEM_REFLECT而不是向导的ON_WM_MEASUREITEM
void CMyListCtrl1::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	CRect rc;
	GetClientRect(&rc);
	lpMeasureItemStruct->itemHeight = rc.Height();
	
	//CListCtrl::MeasureItem(lpMeasureItemStruct);
}


//只有InsertItem了才会进来，而且必须重写
void CMyListCtrl1::DrawItem(LPDRAWITEMSTRUCT lpDis/*lpDrawItemStruct*/)
{
	UINT idx = lpDis->itemID;
	
}
