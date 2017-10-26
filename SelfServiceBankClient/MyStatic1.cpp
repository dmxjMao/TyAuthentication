// MyStatic1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h" //commondef.h
#include "MyStatic1.h"


// CMyStatic1

IMPLEMENT_DYNAMIC(CMyStatic1, CStatic)

CMyStatic1::CMyStatic1(/*TCHAR* pszImgPath*/)
{

}

CMyStatic1::~CMyStatic1()
{
	MySafeDelete(m_oImg);
	MySafeDelete(m_oImgHover);
}


BEGIN_MESSAGE_MAP(CMyStatic1, CStatic)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CMyStatic1 message handlers

void CMyStatic1::Set(TCHAR* pszImgNormalPath, TCHAR* pszImgHoverPath, bool bFixOrImg)
{
	Image img(pszImgNormalPath);
	MySafeDelete(m_oImg);
	m_oImg = img.Clone();
	//pszImgHoverPath为空但m_oImgHover不是
	if (pszImgHoverPath) {
		Image imgHover(pszImgHoverPath);
		MySafeDelete(m_oImgHover);
		m_oImgHover = imgHover.Clone();
		m_bMouseTrack = true;//追踪鼠标悬停消息
	}

	m_bFixOrImg = bFixOrImg;
}


void CMyStatic1::OnPaint()
{
	CPaintDC dc(this); 
	
	Graphics gh(dc.GetSafeHdc());

	//画指定的图片
	if (m_oImg) { //没有初始化为nullptr，0xCCCCC也会进来！
		Image* img = (m_bHover && m_oImgHover) ? m_oImgHover : m_oImg;
		
		UINT w = img->GetWidth();
		UINT h = img->GetHeight();
		//设置大小
		if(!m_bFixOrImg)
			SetWindowPos(nullptr, 0, 0, w, h, SWP_NOMOVE | SWP_NOZORDER);
		//清空背景，白色
		//gh.Clear(Color::Transparent);
		gh.DrawImage(img, 0, 0, w, h);
	}
}


//void CMyStatic1::PreSubclassWindow()
//{
//	//SetWindowPos不能在构造函数里
//	UINT w = m_oImg->GetWidth();
//	UINT h = m_oImg->GetHeight();
//	SetWindowPos(nullptr, 0, 0, w, h, SWP_NOMOVE | SWP_NOZORDER);
//
//	CStatic::PreSubclassWindow();
//}


void CMyStatic1::OnMouseMove(UINT nFlags, CPoint point)
{
	//追踪鼠标悬停消息
	if (m_bMouseTrack)
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


void CMyStatic1::OnMouseHover(UINT nFlags, CPoint point)
{
	m_bHover = true;
	Invalidate();
	CStatic::OnMouseHover(nFlags, point);
}


void CMyStatic1::OnMouseLeave()
{
	m_bMouseTrack = true;
	m_bHover = false;
	Invalidate();
	CStatic::OnMouseLeave();
}




//void CMyStatic1::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
//{
//	CClientDC dc(this);
//	Graphics gh(dc.GetSafeHdc());
//
//	//画指定的图片
//	gh.DrawImage(m_oImg, 0, 0, m_oImg->GetWidth(), m_oImg->GetHeight());
//}


void CMyStatic1::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{

	// TODO:  Add your code to draw the specified item
}
