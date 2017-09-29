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
	m_imgUArrow = Image::FromFile(_T("res\\滚动条\\VerticleScrollBarUpArrow.bmp"));
	m_imgDArrow = Image::FromFile(_T("res\\滚动条\\VerticleScrollBarDownArrow.bmp"));
	m_imgVThumb = Image::FromFile(_T("res\\滚动条\\VerticleScrollBarThumb.bmp"));
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

UINT CMyScrollBar1::GetSize()
{
	return m_imgLArrow ? m_imgLArrow->GetHeight() : 0;
}

void CMyScrollBar1::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	CRect clientRect;
	GetClientRect(&clientRect);

	int nHeight = clientRect.Height() - 37;


	CRect rectUpArrow(0, 11, 12, 37);
	CRect rectDownArrow(0, nHeight, 12, nHeight + 26);
	CRect rectThumb(0, nThumbTop, 12, nThumbTop + 26);

	if (rectThumb.PtInRect(point))
	{
		bMouseDown = true;
	}

	if (rectDownArrow.PtInRect(point))
	{
		bMouseDownArrowDown = true;
		SetTimer(2, 250, NULL);
	}

	if (rectUpArrow.PtInRect(point))
	{
		bMouseDownArrowUp = true;
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
	int nHeight = clientRect.Height() - 37;
	CRect rectUpArrow(0, 11, 12, 37);
	CRect rectDownArrow(0, nHeight, 12, nHeight + 26);
	CRect rectThumb(0, nThumbTop, 12, nThumbTop + 26);



	if (rectUpArrow.PtInRect(point) && bMouseDownArrowUp)
	{
		ScrollUp();
		bInChannel = false;
	}

	if (rectDownArrow.PtInRect(point) && bMouseDownArrowDown)
	{
		ScrollDown();
		bInChannel = false;
	}

	if (rectThumb.PtInRect(point))
	{
		bInChannel = false;
	}

	if (bInChannel == true && !bMouseDown)
	{
		if (point.y > nThumbTop)
		{
			PageDown();
		}
		else
		{
			PageUp();
		}
	}

	bMouseDown = false;
	bDragging = false;
	bMouseDownArrowUp = false;
	bMouseDownArrowDown = false;

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
	
	//CRect clientRect;
	//GetClientRect(&clientRect);
	//CMemDC memDC(&dc, &clientRect);
	//memDC.FillSolidRect(&clientRect, RGB(76, 85, 118));

	//CDC bitmapDC;
	//bitmapDC.CreateCompatibleDC(&dc);

	////draw left arrow of scrollbar
	//CBitmap bitmap;
	//bitmap.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_LEFTARROW);
	//CBitmap* pOldBitmap = bitmapDC.SelectObject(&bitmap);

	//memDC.BitBlt(clientRect.left, clientRect.top, 26, 12, &bitmapDC, 0, 0, SRCCOPY);

	//bitmapDC.SelectObject(pOldBitmap);
	//bitmap.DeleteObject();
	//pOldBitmap = NULL;


	//bitmap.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_SPAN);

	//pOldBitmap = bitmapDC.SelectObject(&bitmap);


	//int nWidth = clientRect.Width() - 26;

	//memDC.StretchBlt(clientRect.left + 26, clientRect.top, nWidth, 12, &bitmapDC, 0, 0, 1, 12, SRCCOPY);

	//bitmapDC.SelectObject(pOldBitmap);
	//bitmap.DeleteObject();
	//pOldBitmap = NULL;

	//bitmap.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_RIGHTARROW);

	//pOldBitmap = bitmapDC.SelectObject(&bitmap);
	//memDC.BitBlt(nWidth, clientRect.top, 26, 12, &bitmapDC, 0, 0, SRCCOPY);

	//bitmapDC.SelectObject(pOldBitmap);
	//bitmap.DeleteObject();
	//pOldBitmap = NULL;

	////If there is nothing to scroll then don't
	////show the thumb control otherwise show it
	//if (pList->GetScrollLimit(SB_HORZ) != 0)
	//{
	//	bitmap.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_THUMB);

	//	pOldBitmap = bitmapDC.SelectObject(&bitmap);
	//	memDC.BitBlt(clientRect.left + nThumbLeft, clientRect.top, 26, 12, &bitmapDC, 0, 0, SRCCOPY);

	//	bitmapDC.SelectObject(pOldBitmap);
	//	bitmap.DeleteObject();
	//	pOldBitmap = NULL;
	//}

	//Draw();
}

void CMyScrollBar1::OnTimer(UINT nIDEvent)
{
	if (nIDEvent == 1)
	{
		if (bMouseDownArrowDown)
		{
			ScrollDown();
		}

		if (bMouseDownArrowUp)
		{
			ScrollUp();
		}
	}
	else if (nIDEvent == 2)
	{
		if (bMouseDownArrowDown)
		{
			KillTimer(2);
			SetTimer(1, 50, NULL);
		}

		if (bMouseDownArrowUp)
		{
			KillTimer(2);
			SetTimer(1, 50, NULL);
		}
	}
	CStatic::OnTimer(nIDEvent);
}

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

	double nPos = pList->GetScrollPos(SB_VERT);
	double nMax = pList->GetScrollLimit(SB_VERT);
	double nHeight = (clientRect.Height() - 98);
	double nVar = nMax;

	dbThumbInterval = nHeight / nVar;

	double nNewdbValue = (dbThumbInterval * nPos);
	int nNewValue = (int)nNewdbValue;


	nThumbTop = 36 + nNewValue;

	LimitThumbPosition();

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

	if (nThumbTop + 26 > (clientRect.Height() - 37))
	{
		nThumbTop = clientRect.Height() - 62;
	}

	if (nThumbTop < (clientRect.top + 36))
	{
		nThumbTop = clientRect.top + 36;
	}
}