// MyButton1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyButton1.h"


// CMyButton1

IMPLEMENT_DYNAMIC(CMyButton1, CButton)

CMyButton1::CMyButton1()
{

}

CMyButton1::~CMyButton1()
{
}


BEGIN_MESSAGE_MAP(CMyButton1, CButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &CMyButton1::OnBnClicked)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyButton1 message handlers




void CMyButton1::OnBnClicked()
{
	AfxMessageBox(_T("����Ԥ��"));
}


void CMyButton1::OnPaint()
{
	CPaintDC dc(this); 
	Graphics gh(dc.GetSafeHdc());

	//���ñ���͸��
	CRect rc;
	GetClientRect(&rc);
	Rect rcGdi(rc.left, rc.top, rc.right, rc.bottom);
	SolidBrush sbr(Color(0, 0, 0, 0));//͸��
	gh.FillRectangle(&sbr, rcGdi);

	//д����
	CString str;
	GetWindowText(str);

	FontFamily ff(_T("΢���ź�"));
	Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(cstClrTitle);//��ɫ
	StringFormat sf;
	//sf.SetAlignment(StringAlignmentCenter);//�ı�����
	sf.SetLineAlignment(StringAlignmentCenter);//���¾���

	RectF rcGdiF(rcGdi.X * 1.0f, rcGdi.Y * 1.0f, rcGdi.Width * 1.0f, rcGdi.Height * 1.0f);
	//PointF pf(rcGdi.X * 1.0f, rcGdi.Y * 1.0f);
	gh.DrawString(str, -1, &font, rcGdiF, &sf, &sbrText);

	//�»���
	Pen pen(cstClrTitle);
	//RectF boundRect; //�Ǳ߽磬���ǿؼ��ͻ���
	//gh.MeasureString(str, -1, &font, rcGdiF, &boundRect);
	auto nTextH = font.GetHeight(0.0);//һ�и߶�
	//auto y = pf.Y + nTextH;
	auto y = rcGdiF.Y + nTextH + 2;
	auto w = 12 * 1.0f/*px*/ * str.GetLength();
	//PointF pfLineFrom(rcGdiF.X, y); //���У�
	//PointF pfLineTo(rc)

	gh.DrawLine(&pen, rcGdiF.X, y, rcGdiF.X + w, y);
}


//void CMyButton1::PreSubclassWindow()
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	CButton::PreSubclassWindow();
//}


void CMyButton1::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{
}
