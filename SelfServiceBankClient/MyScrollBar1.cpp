// MyScrollBar1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyScrollBar1.h"


// CMyScrollBar1

IMPLEMENT_DYNAMIC(CMyScrollBar1, CStatic)

CMyScrollBar1::CMyScrollBar1()
{
	m_imgLArrow = Image::FromFile(_T("res\\滚动条\\HorizontalScrollBarLeftArrow.bmp"));
	m_imgRArrow = Image::FromFile(_T("res\\滚动条\\HorizontalScrollBarRightArrow.bmp"));
	m_imgHThumb = Image::FromFile(_T("res\\滚动条\\HorizontalScrollBarThumb.bmp"));
	m_imgHSpan = Image::FromFile(_T("res\\滚动条\\HorizontalScrollBarSpan.bmp"));
	
	m_imgUArrow = Image::FromFile(_T("res\\滚动条\\VerticleScrollBarUpArrow.bmp"));
	m_imgDArrow = Image::FromFile(_T("res\\滚动条\\VerticleScrollBarDownArrow.bmp"));
	m_imgVThumb = Image::FromFile(_T("res\\滚动条\\VerticleScrollBarThumb.bmp"));

	m_imgH = m_imgLArrow->GetHeight();
	//m_imgW = 
}

CMyScrollBar1::~CMyScrollBar1()
{
	MySafeDelete(m_imgLArrow); MySafeDelete(m_imgRArrow); MySafeDelete(m_imgHThumb);
	MySafeDelete(m_imgUArrow); MySafeDelete(m_imgDArrow); MySafeDelete(m_imgVThumb);
}


BEGIN_MESSAGE_MAP(CMyScrollBar1, CStatic)
	//ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CMyScrollBar1 message handlers

//UINT CMyScrollBar1::GetSize()
//{
//	return m_imgLArrow ? m_imgLArrow->GetHeight() : 0;
//}

void CMyScrollBar1::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	CRect clientRect;
	GetClientRect(&clientRect);

	int w = m_imgLArrow->GetWidth();
	int nWidth = clientRect.Width() - w;

	//左右箭头 + 滑块区域
	CRect rectLeftArrow(0, 0, w, m_imgH);
	CRect rectRightArrow(nWidth, 0, nWidth + w, m_imgH);
	CRect rectThumb(nThumbLeft, 0, nThumbLeft + w, m_imgH);

	if (rectThumb.PtInRect(point))
	{
		bMouseDown = true;
	}


	if (rectRightArrow.PtInRect(point))
	{
		bMouseDownArrowRight = true;
		//利用计时器每250ms响应一次
		SetTimer(2, 250, NULL);
	}

	if (rectLeftArrow.PtInRect(point))
	{
		bMouseDownArrowLeft = true;
		SetTimer(2, 250, NULL);
	}

	CStatic::OnLButtonDown(nFlags, point);
}

void CMyScrollBar1::OnLButtonUp(UINT nFlags, CPoint point)
{
	UpdateThumbPosition();
	KillTimer(1);
	ReleaseCapture();

	bool bInChannel = true;

	CRect clientRect;
	GetClientRect(&clientRect);
	int w = m_imgLArrow->GetWidth();

	int nWidth = clientRect.Width() - w;

	CRect rectLeftArrow(0, 0, w, m_imgH);
	CRect rectThumb(nThumbLeft, 0, nThumbLeft + w, m_imgH);

	if (rectLeftArrow.PtInRect(point))
	{
		ScrollLeft();
		bInChannel = false;
	}

	CRect rectRightArrow(nWidth, 0, nWidth + w, m_imgH);


	if (rectRightArrow.PtInRect(point))
	{
		ScrollRight();
		bInChannel = false;
	}

	if (rectThumb.PtInRect(point))
	{
		bInChannel = false;
	}

	if (bInChannel == true && !bMouseDown)
	{
		if (point.x > nThumbLeft)
		{
			PageRight();
		}
		else
		{
			PageLeft();
		}
	}

	//reset all variables
	bMouseDown = false;
	bDragging = false;
	bMouseDownArrowLeft = false;
	bMouseDownArrowRight = false;

	CStatic::OnLButtonUp(nFlags, point);
}

void CMyScrollBar1::OnMouseMove(UINT nFlags, CPoint point)
{
	CRect clientRect;
	GetClientRect(&clientRect);

	if (bMouseDown)
	{
		nThumbTop = point.y - 13; //-13 so mouse is in middle of thumb

		double nMax = pList->GetScrollLimit(SB_VERT);
		int nPos = pList->GetScrollPos(SB_VERT);

		double nHeight = clientRect.Height() - 98;
		double nVar = nMax;
		dbThumbInterval = nHeight / nVar;

		//figure out how many times to scroll total from top
		//then minus the current position from it
		int nScrollTimes = (int)((nThumbTop - 36) / dbThumbInterval) - nPos;

		//grab the row height dynamically
		//so if the font size or type changes
		//our scroll will still work properly
		CRect itemrect;
		pList->GetItemRect(0, &itemrect, LVIR_BOUNDS);

		CSize size;
		size.cx = 0;
		size.cy = nScrollTimes*itemrect.Height();


		pList->Scroll(size);


		LimitThumbPosition();

		//Draw();

	}
	CStatic::OnMouseMove(nFlags, point);
}

void CMyScrollBar1::OnPaint()
{
	CPaintDC dc(this);
	Graphics gh(dc.GetSafeHdc());

	CRect rcClient;
	GetClientRect(&rcClient);
	//RGB(76,85,118)
	

	if (m_bHorizontal) {
		//画左箭头
		int w = m_imgLArrow->GetWidth();
		gh.DrawImage(m_imgLArrow, 
			rcClient.left, rcClient.top, w, m_imgH);
		//画拉伸
		ImageAttributes imgAtt;
		imgAtt.SetWrapMode(WrapModeTile);//拉伸模式
		gh.DrawImage(m_imgHSpan,
			Rect(rcClient.left + w, rcClient.top, rcClient.Width() - w/*右箭头*/, m_imgH),
			0, 0, m_imgHSpan->GetWidth(), m_imgHSpan->GetHeight(), UnitPixel, &imgAtt);
		//画右箭头
		gh.DrawImage(m_imgRArrow,
			rcClient.right - w, rcClient.top, w, m_imgH);
		//画滑块
		w = m_imgHThumb->GetWidth();
		if (pList->GetScrollLimit(SB_HORZ) != 0) {
			gh.DrawImage(m_imgHThumb,
				rcClient.left + nThumbLeft, rcClient.top, w, m_imgH);
		}
	}
}

void CMyScrollBar1::OnTimer(UINT nIDEvent)
{
	if (nIDEvent == 1)
	{
		if (bMouseDownArrowRight)
		{
			ScrollRight();
		}

		if (bMouseDownArrowLeft)
		{
			ScrollLeft();
		}
	}
	else if (nIDEvent == 2)
	{
		if (bMouseDownArrowRight)
		{
			KillTimer(2);
			SetTimer(1, 50, NULL);
		}

		if (bMouseDownArrowLeft)
		{
			KillTimer(2);
			SetTimer(1, 50, NULL);
		}
	}
	CStatic::OnTimer(nIDEvent);
}


/*
wParam低字节 SB_XXX，
SB_LINEUP or SB_LINELEFT箭头
SB_PAGEUP or SB_PAGELEFT空格
SB_THUMBTRACK 按住鼠标， SB_THUMBPOSITION 释放鼠标
高字节在SB_THUMBPOSITION时代表位置，其他忽略
*/
void CMyScrollBar1::PageDown()
{
	pList->SendMessage(WM_VSCROLL, MAKELONG(SB_PAGEDOWN, 0), NULL);
	UpdateThumbPosition();
}

void CMyScrollBar1::PageUp()
{
	pList->SendMessage(WM_VSCROLL, MAKELONG(SB_PAGEUP, 0), NULL);
	UpdateThumbPosition();
}

void CMyScrollBar1::ScrollUp()
{
	pList->SendMessage(WM_VSCROLL, MAKELONG(SB_LINEUP, 0), NULL);
	UpdateThumbPosition();
}

void CMyScrollBar1::ScrollDown()
{
	pList->SendMessage(WM_VSCROLL, MAKELONG(SB_LINEDOWN, 0), NULL);
	UpdateThumbPosition();
}



void CMyScrollBar1::PageRight()
{
	pList->SendMessage(WM_HSCROLL, MAKELONG(SB_PAGEDOWN, 0), NULL);
	UpdateThumbPosition();
}

void CMyScrollBar1::PageLeft()
{
	pList->SendMessage(WM_HSCROLL, MAKELONG(SB_PAGEUP, 0), NULL);
	UpdateThumbPosition();
}


void CMyScrollBar1::ScrollLeft()
{
	pList->SendMessage(WM_HSCROLL, MAKELONG(SB_LINELEFT, 0), NULL);
	UpdateThumbPosition();
}

void CMyScrollBar1::ScrollRight()
{
	pList->SendMessage(WM_HSCROLL, MAKELONG(SB_LINERIGHT, 0), NULL);
	UpdateThumbPosition();
}


void CMyScrollBar1::UpdateThumbPosition()
{
	CRect clientRect;
	GetClientRect(&clientRect);
	//获取滑块当前位置以及最大值
	double nPos = pList->GetScrollPos(SB_HORZ);
	double nMax = pList->GetScrollLimit(SB_HORZ);
	UINT w = m_imgLArrow->GetWidth()/* - 1*/;//左右箭头 + 滑块宽度
	double nWidth = (clientRect.Width() - 3 * w);
	double nVar = nMax;

	dbThumbInterval = nWidth / nVar;//滑块单位移动距离

	double nNewdbValue = dbThumbInterval * (nPos);
	int nNewValue = (int)nNewdbValue;
	double nExtra = nNewdbValue - nNewValue;
	dbThumbRemainder = nExtra;

	nThumbLeft = w + nNewValue;//滑块左坐标

	LimitThumbPosition();
	//重绘
	Invalidate();
	//Draw();
}

//
//void CMyScrollBar1::Draw()
//{
//
//	CClientDC dc(this);
//	CRect clientRect;
//	GetClientRect(&clientRect);
//	CMemDC memDC(&dc, &clientRect);
//	memDC.FillSolidRect(&clientRect, RGB(74, 82, 107));
//	CDC bitmapDC;
//	bitmapDC.CreateCompatibleDC(&dc);
//
//	CBitmap bitmap;
//	bitmap.LoadBitmap(IDB_VERTICLE_SCROLLBAR_TOP);
//	CBitmap* pOldBitmap = bitmapDC.SelectObject(&bitmap);
//	memDC.BitBlt(clientRect.left, clientRect.top, 12, 11, &bitmapDC, 0, 0, SRCCOPY);
//	bitmapDC.SelectObject(pOldBitmap);
//	bitmap.DeleteObject();
//	pOldBitmap = NULL;
//
//	bitmap.LoadBitmap(IDB_VERTICLE_SCROLLBAR_UPARROW);
//	pOldBitmap = bitmapDC.SelectObject(&bitmap);
//	memDC.BitBlt(clientRect.left, clientRect.top + 11, 12, 26, &bitmapDC, 0, 0, SRCCOPY);
//	bitmapDC.SelectObject(pOldBitmap);
//	bitmap.DeleteObject();
//	pOldBitmap = NULL;
//
//	//draw the background (span)
//	bitmap.LoadBitmap(IDB_VERTICLE_SCROLLBAR_SPAN);
//	pOldBitmap = bitmapDC.SelectObject(&bitmap);
//	int nHeight = clientRect.Height() - 37;
//
//	memDC.StretchBlt(clientRect.left, clientRect.top + 37, 12, nHeight, &bitmapDC, 0, 0, 12, 1, SRCCOPY);
//
//	bitmapDC.SelectObject(pOldBitmap);
//	bitmap.DeleteObject();
//	pOldBitmap = NULL;
//
//	//draw the down arrow of the scrollbar
//	bitmap.LoadBitmap(IDB_VERTICLE_SCROLLBAR_DOWNARROW);
//	pOldBitmap = bitmapDC.SelectObject(&bitmap);
//	memDC.BitBlt(clientRect.left, nHeight, 12, 26, &bitmapDC, 0, 0, SRCCOPY);
//	bitmapDC.SelectObject(pOldBitmap);
//	bitmap.DeleteObject();
//	pOldBitmap = NULL;
//
//	//draw the down arrow of the scrollbar
//	bitmap.LoadBitmap(IDB_VERTICLE_SCROLLBAR_BOTTOM);
//	pOldBitmap = bitmapDC.SelectObject(&bitmap);
//	memDC.BitBlt(clientRect.left + 1, nHeight + 26, 11, 11, &bitmapDC, 0, 0, SRCCOPY);
//	bitmapDC.SelectObject(pOldBitmap);
//	bitmap.DeleteObject();
//	pOldBitmap = NULL;
//
//	//If there is nothing to scroll then don't
//	//show the thumb control otherwise show it
//	if (pList->GetScrollLimit(SB_VERT) != 0)
//	{
//		//draw the thumb control
//		bitmap.LoadBitmap(IDB_VERTICLE_SCROLLBAR_THUMB);
//		pOldBitmap = bitmapDC.SelectObject(&bitmap);
//		memDC.BitBlt(clientRect.left, clientRect.top + nThumbTop, 12, 26, &bitmapDC, 0, 0, SRCCOPY);
//		bitmapDC.SelectObject(pOldBitmap);
//		bitmap.DeleteObject();
//		pOldBitmap = NULL;
//	}
//
//
//}

void CMyScrollBar1::LimitThumbPosition()
{
	CRect clientRect;
	GetClientRect(&clientRect);
	int w = m_imgLArrow->GetWidth();
	//滑块超过右箭头
	if (nThumbLeft + w > (clientRect.Width() - w))
	{
		nThumbLeft = clientRect.Width() - 2 * w;
	}
	//滑块比左箭头小
	if (nThumbLeft < (clientRect.left + w))
	{
		nThumbLeft = clientRect.left + w;
	}
}