// MyStatic2.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyStatic2.h"


// CMyStatic2

IMPLEMENT_DYNAMIC(CMyStatic2, CStatic)

CMyStatic2::CMyStatic2()
{

}

CMyStatic2::~CMyStatic2()
{
}


BEGIN_MESSAGE_MAP(CMyStatic2, CStatic)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
	//ON_CONTROL_REFLECT(STN_CLICKED, &CMyStatic2::OnStnClicked)
END_MESSAGE_MAP()


void CMyStatic2::PreSubclassWindow()
{
	ModifyStyle(0, SS_NOTIFY | SS_OWNERDRAW);

	//区域
	//CRect rc;
	//GetClientRect(&rc);
	//m_rgn.CreateEllipticRgnIndirect(&rc);
	//SetWindowRgn((HRGN)m_rgn, true);
}

// CMyStatic2 message handlers

void CMyStatic2::OnPaint()
{
	CPaintDC dc(this);
	Graphics gh(dc.GetSafeHdc());
	//设置画图时的滤波模式为消除锯齿现象
	//gh.SetSmoothingMode(SmoothingModeHighQuality);

	CRect rc;
	GetClientRect(&rc);
	Rect rcGdi(rc.left, rc.top, rc.Width(), rc.Height());

	//画圆角矩形区域
	//GraphicsPath* path = MakeRoundRect(Point(rc.left, rc.top), Point(rc.right, rc.bottom), 10);
	//Region rgn(path);
	//gh.SetClip(&rgn);

	//填充背景色
	if (!m_bEnable) {
		SolidBrush sbr = m_clrGray;
		gh.FillRectangle(&sbr, rcGdi);
	}
	else {
		SolidBrush sbr = m_bHover ? m_clrHoverBG : m_clrBG;
		gh.FillRectangle(&sbr, rcGdi);
	}
	
	//画文字
	CString str;
	GetWindowText(str);
	
	static FontFamily ff(_T("微软雅黑"));
	static Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
	static SolidBrush sbrText(Color(255, 255, 255));
	StringFormat sf;
	sf.SetAlignment(StringAlignmentCenter);//文本居中
	sf.SetLineAlignment(StringAlignmentCenter);//上下居中
	//rcGdi.Inflate()
	//PointF pf()
	RectF rcGdiF(rcGdi.X * 1.0f, rcGdi.Y * 1.0f, rcGdi.Width * 1.0f, rcGdi.Height * 1.0f);

	gh.DrawString(str, -1, &font, rcGdiF, &sf, &sbrText);

	//MySafeDelete(path);
}

void CMyStatic2::OnMouseMove(UINT nFlags, CPoint point)
{
	//追踪鼠标悬停消息
	if (m_bMouseTrack && m_bEnable)
	{
		m_bMouseTrack = false;
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(TRACKMOUSEEVENT);
		tme.dwFlags = TME_HOVER | TME_LEAVE;
		//tme.dwHoverTime = HOVER_DEFAULT;  
		tme.dwHoverTime = 50;
		tme.hwndTrack = GetSafeHwnd();
		TrackMouseEvent(&tme);
	}

	CStatic::OnMouseMove(nFlags, point);
}


void CMyStatic2::OnMouseHover(UINT nFlags, CPoint point)
{
	m_bHover = true;
	Invalidate();
	CStatic::OnMouseHover(nFlags, point);
}


void CMyStatic2::OnMouseLeave()
{
	m_bMouseTrack = true;
	m_bHover = false;
	Invalidate();
	CStatic::OnMouseLeave();
}


//
//GraphicsPath* CMyStatic2::MakeRoundRect(Point topLeft, Point bottomRight, INT percentageRounded)
//{
//	ASSERT(percentageRounded >= 1 && percentageRounded <= 100);
//	//if(percentageRounded >= 1 && percentageRounded <= 100)
//
//	INT left = min(topLeft.X, bottomRight.X);
//	INT right = max(topLeft.X, bottomRight.X);
//
//	INT top = min(topLeft.Y, bottomRight.Y);
//	INT bottom = max(topLeft.Y, bottomRight.Y);
//
//	INT offsetX = (right - left)*percentageRounded / 100;
//	INT offsetY = (bottom - top)*percentageRounded / 100;
//
//	GraphicsPath pt;
//	GraphicsPath * path = pt.Clone();
//
//	//path->AddEllipse(Rect(left, top, right, bottom));
//	//画弧是顺时针画的：左上右上右下左下，角度顺时针指定，x轴和起始点之间的角度
//	path->AddArc(left, top, 2*offsetX, 2*offsetY, 180.0f, 90.0f);
//	path->AddArc(right - 2*offsetX, top, 2*offsetX, 2*offsetY, 90.0f, 90.0f);
//	path->AddArc(right - 2*offsetX,  bottom - 2*offsetY, 2*offsetX, 2*offsetY, 0.0f, 90.0f);
//	path->AddArc(left, bottom - 2*offsetY, 2*offsetX, 2*offsetY, 270.0f, 90.0f);
//	//画直线：顶部右侧底部左侧
//	// 边线修正  
//	//int lineMove = 1;
//	//path->AddLine(left + offsetX - lineMove, top, right - offsetX + lineMove, top);
//	//path->AddLine(right, top + offsetY - lineMove, right, bottom - offsetY + lineMove);
//	//path->AddLine(left + offsetX + lineMove, bottom, right - offsetX - lineMove, bottom);
//	////path->AddLine(left, top + offsetY, left, bottom - offsetY);
//	////线要首尾连接！
//	//path->AddLine(left, bottom - offsetY + lineMove, left, top + offsetY - lineMove);
//
//	path->AddLine(left + offsetX , top, right - offsetX , top);
//	path->AddLine(right, top + offsetY , right, bottom - offsetY );
//	path->AddLine(left + offsetX , bottom, right - offsetX, bottom);
//	//path->AddLine(left, top + offsetY, left, bottom - offsetY);
//	//线要首尾连接！
//	path->AddLine(left, bottom - offsetY , left, top + offsetY);
//
//
//	return path;
//}

void CMyStatic2::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{
	//自绘一定要重载，否则会蹦
}


//void CMyStatic2::OnStnClicked()
//{
//	if (!m_bEnable)
//		return;
//
//	CString str;
//	GetWindowText(str);
//	AfxMessageBox(str);
//}
