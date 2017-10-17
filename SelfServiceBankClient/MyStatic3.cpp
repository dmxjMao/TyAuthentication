// MyStatic3.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyStatic3.h"
#include "CommonDefine.h"

// CMyStatic3

IMPLEMENT_DYNAMIC(CMyStatic3, CStatic)

CMyStatic3::CMyStatic3()
{

}

CMyStatic3::~CMyStatic3()
{
}


BEGIN_MESSAGE_MAP(CMyStatic3, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyStatic3 message handlers




void CMyStatic3::OnPaint()
{
	CPaintDC dc(this); 
	Graphics gh(dc.GetSafeHdc());

	CRect rc;
	GetClientRect(&rc);
	Rect rcGdi(rc.left, rc.top, rc.Width(), rc.Height());

	//填充背景色
	//Color clrBG(54, 132, 215);
	SolidBrush sbr(theApp.m_oGobal->cstClrTitle);
	gh.FillRectangle(&sbr, rcGdi);
	

	//画文字
	CString str;
	GetWindowText(str);

	FontFamily ff(_T("微软雅黑"));
	Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color(255, 255, 255));
	StringFormat sf;
	//sf.SetAlignment(StringAlignmentCenter);//文本居中
	sf.SetLineAlignment(StringAlignmentCenter);//上下居中

	RectF rcGdiF(rcGdi.X * 1.0f, rcGdi.Y * 1.0f, rcGdi.Width * 1.0f, rcGdi.Height * 1.0f);
	gh.DrawString(str, -1, &font, rcGdiF, &sf, &sbrText);
}


void CMyStatic3::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{
}
