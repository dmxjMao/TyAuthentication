// MyListBox2.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListBox2.h"
#include "MyCommonDefine.h"

// CMyListBox2

IMPLEMENT_DYNAMIC(CMyListBox2, CListBox)

CMyListBox2::CMyListBox2()
{

}

CMyListBox2::~CMyListBox2()
{
}


BEGIN_MESSAGE_MAP(CMyListBox2, CListBox)
END_MESSAGE_MAP()



// CMyListBox2 message handlers




void CMyListBox2::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	lpMeasureItemStruct->itemHeight = 20;
}


void CMyListBox2::DrawItem(LPDRAWITEMSTRUCT lpDis/*lpDrawItemStruct*/)
{

	CClientDC dc(this);

	UINT idx = lpDis->itemID;
	if (idx != (UINT)-1) {//空列表框会收到-1
		Graphics gh(dc.GetSafeHdc());

		const CRect& rc = lpDis->rcItem;
		const Rect rcGdi(rc.left, rc.top, rc.Width(), rc.Height());

		SolidBrush sbrSelect(Color(255, 223, 112));//选择颜色
		//SolidBrush sbrHover(Color(174, 154, 250)); //高亮颜色
		SolidBrush sbrNormal(Color(250, 250, 250));//常态颜色

		gh.FillRectangle(&sbrNormal, rcGdi);

		//是否选择
		UINT nSel = lpDis->itemState & ODS_SELECTED;
		if (nSel) {
			gh.FillRectangle(&sbrSelect, rcGdi);
		}

		FontFamily ff(_T("微软雅黑"));
		Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
		SolidBrush sbrText(theApp.m_oGobal->cstClrTitle);
		PointF pF(rcGdi.X * 1.0f, rcGdi.Y * 1.0f);

		CString str;
		GetText(idx, str); //LBS_HASSTRING程序帮你保存，LBS_SORT不会
		gh.DrawString(str, -1, &font, pF, &sbrText);
	}
}
