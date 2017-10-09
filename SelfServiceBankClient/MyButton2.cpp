// MyButton2.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyButton2.h"


// CMyButton2

IMPLEMENT_DYNAMIC(CMyButton2, CButton)

CMyButton2::CMyButton2()
{

}

CMyButton2::CMyButton2(const std::shared_ptr<Image>& img1, const std::shared_ptr<Image>& img2)
	: m_img1(img1), m_img2(img2)
{

}

CMyButton2::~CMyButton2()
{
}


BEGIN_MESSAGE_MAP(CMyButton2, CButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyButton2 message handlers




void CMyButton2::OnPaint()
{
	CPaintDC dc(this);
	Graphics gh(dc.GetSafeHdc());

	CRect rc;
	GetClientRect(&rc);
	//Rect rcGdi(rc.left, rc.top, rc.right, rc.bottom);
	//»­img1
	int w1 = m_img1 ? m_img1->GetWidth() : 0;
	int h = m_img1 ? m_img1->GetHeight() : 0;
	gh.DrawImage(m_img1.get(), 0, 0, w1, h);

	//»­img2
	int x = w1;
	int w2 = m_img2 ? m_img2->GetWidth() : 0;
	gh.DrawImage(m_img2.get(), x, 0, w2, rc.Height());

	//Ð´×Ö
	x = w1 + 40;
	FontFamily ff(_T("Î¢ÈíÑÅºÚ"));
	Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color(255, 255, 255));
	auto nTextHeight = font.GetHeight(0.0f);
	PointF pf(x * 1.0f, rc.Height() - nTextHeight - 2.0f);

	CString str;
	GetWindowText(str);
	gh.DrawString(str, -1, &font, pf, &sbrText);
}


void CMyButton2::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{
}
