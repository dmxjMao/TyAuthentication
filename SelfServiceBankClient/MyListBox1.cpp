// MyListBox1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListBox1.h"


/*
自绘列表框
重写DrawItem、MeasureItem，样式要OWNDRAW...
当项目需要绘制或重画时，发送消息，调用DrawItem，
在DrawItem之前，收到Measure项高度的消息，如果样式是fix的，就只来一次，
*/

// CMyListBox1

IMPLEMENT_DYNAMIC(CMyListBox1, CListBox)

CMyListBox1::CMyListBox1()
{

}

CMyListBox1::~CMyListBox1()
{
}


BEGIN_MESSAGE_MAP(CMyListBox1, CListBox)
	//ON_WM_MEASUREITEM_REFLECT()
	//ON_WM_DRAWITEM_REFLECT()
	//ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	//ON_WM_MOUSEHOVER()
	//ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CMyListBox1 message handlers




//void CMyListBox1::PreSubclassWindow()
//{
//	//不排序，自绘（此处无效，只能属性设置）
//	//ModifyStyle(LBS_SORT | LBS_OWNERDRAWVARIABLE, LBS_OWNERDRAWVARIABLE);
//
//	CListBox::PreSubclassWindow();
//}

//如果你是拖动控件的，不走这；只有动态Create才会走
//BOOL CMyListBox1::PreCreateWindow(CREATESTRUCT& cs)
//{
//	//ModifyStyle(LBS_SORT, LBS_OWNERDRAWFIXED);
//
//	return CListBox::PreCreateWindow(cs);
//}

//
//void CMyListBox1::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
//{
//	lpMeasureItemStruct->itemHeight = 32;
//}
//
//
////每个要画的项都会进来
//void CMyListBox1::DrawItem(LPDRAWITEMSTRUCT lpDis)
//{
//	CClientDC dc(this);
//	Graphics gh(dc.GetSafeHdc());
//
//	const CRect& rc = lpDis->rcItem;
//	const Rect rcGdi(rc.left, rc.top, rc.Width(), rc.Height());
//	UINT idx = lpDis->itemID;
//
//	SolidBrush sbrHover(Color(255, 223, 112)); //高亮和选择的颜色
//	SolidBrush sbrNormal(Color(250, 250, 250));//常态颜色
//	UINT nSel = lpDis->itemState & ODS_SELECTED;
//	if (nSel) {
//		gh.FillRectangle(&sbrHover, rcGdi);
//	}
//	else {
//		gh.FillRectangle(&sbrNormal, rcGdi);
//	}
//
//
//	if (idx != (UINT)-1) {//空列表框会收到
//		
//	}
//}


//动态Create才会走这，拖动不会进来
void CMyListBox1::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	lpMeasureItemStruct->itemHeight = 20;
}


void CMyListBox1::DrawItem(LPDRAWITEMSTRUCT lpDis/*lpDrawItemStruct*/)
{
	CClientDC dc(this);
	Graphics gh(dc.GetSafeHdc());
	
	const CRect& rc = lpDis->rcItem;
	const Rect rcGdi(rc.left, rc.top, rc.Width(), rc.Height());
	UINT idx = lpDis->itemID;
	
	static SolidBrush sbrSelect(Color(255, 223, 112));//选择颜色
	static SolidBrush sbrHover(Color(174, 154, 250)); //高亮颜色
	static SolidBrush sbrNormal(Color(250, 250, 250));//常态颜色
	
	gh.FillRectangle(&sbrNormal, rcGdi);

	//if (m_bMouseHover) {
	//	gh.FillRectangle(&sbrHover, rcGdi);
	//}
	UINT nHover = lpDis->itemState & ODS_HOTLIGHT;
	if (nHover) {
		gh.FillRectangle(&sbrHover, rcGdi);
	}

	UINT nSel = lpDis->itemState & ODS_SELECTED;
	if (nSel) {
		gh.FillRectangle(&sbrSelect, rcGdi);
		m_curItem = idx;//记录当前选择项
	}
	
	
	if (idx != (UINT)-1) {//空列表框会收到
		auto n = GetItemHeight(idx);

		static FontFamily ff(_T("微软雅黑"));
		static Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
		static SolidBrush sbrText(Color(0, 0, 0));
		//RectF rcFGdi(rcGdi.x, rcGdi.y, rcGdi.cx, rcGdi.cy);
		PointF pF(rcGdi.X * 1.0f, rcGdi.Y * 1.0f);
		
		//LPCTSTR lpszText = (LPCTSTR)lpDis->itemData;  //可以存储图片
		CString str;
		GetText(idx, str);
		gh.DrawString(str.GetBuffer(), -1, &font, pF, &sbrText);
	}
}


//void CMyListBox1::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: Add your message handler code here
//					   // Do not call CListBox::OnPaint() for painting messages
//}


//悬停高亮实现：获取所在区域，DrawItem、ItemFromPoint、GetItemRect
void CMyListBox1::OnMouseMove(UINT nFlags, CPoint point)
{
	static DRAWITEMSTRUCT prevDIS;
	//prevDIS.itemID = -1;
	//TRACE("prevDIS.itemID：%d", prevDIS.itemID);

	BOOL bOutSide = TRUE;
	UINT idx = ItemFromPoint(point, bOutSide);
	
	if (!bOutSide) { //点在item上
		//m_bMouseHover = true;
		//Invalidate();   只是OnPaint会触发
		//离开了之前的区域，进入新的区域
		if (prevDIS.itemID != idx /*&& prevDIS.itemID != -1*/ ) {
			if (prevDIS.itemID != m_curItem) {//上一个是点击项，不用恢复
				prevDIS.itemState = ODS_DEFAULT;
				DrawItem(&prevDIS);
			}

			DRAWITEMSTRUCT dis;
			GetItemRect(idx, &dis.rcItem);
			dis.itemID = idx;

			if (idx != m_curItem) {//如果这个项是点击项，不用高亮
				dis.itemState = ODS_HOTLIGHT;
				DrawItem(&dis);
			}

			prevDIS = std::move(dis);
		}	

		//m_disMouseHover = std::move(dis);
	}
	//else {//点不在item上
	//	prevDIS.itemState = ODS_DEFAULT;
	//	DrawItem(&prevDIS);
	//}

	//追踪鼠标悬停消息（注册）
	//if (m_bMouseTrack)
	//{
	//	TRACE("m_bMouseTrack");
	//	m_bMouseTrack = false;
	//	TRACKMOUSEEVENT tme;
	//	tme.cbSize = sizeof(TRACKMOUSEEVENT);
	//	tme.dwFlags = TME_HOVER | TME_LEAVE;
	//	//tme.dwHoverTime = HOVER_DEFAULT;  
	//	tme.dwHoverTime = 50;
	//	tme.hwndTrack = GetSafeHwnd();
	//	TrackMouseEvent(&tme);
	//}

	CListBox::OnMouseMove(nFlags, point);
}


//void CMyListBox1::OnMouseHover(UINT nFlags, CPoint point)
//{
//	BOOL bOutSide = TRUE;
//	UINT idx = ItemFromPoint(point, bOutSide);
//	TRACE("idx:%d, bOutSide:%d", idx, bOutSide);
//
//	if (!bOutSide) {
//		m_bMouseHover = true;
//		//Invalidate();   只是OnPaint会触发
//		DRAWITEMSTRUCT dis;
//		GetItemRect(idx, &dis.rcItem);
//		dis.itemID = idx;
//		dis.itemState = ODS_HOTLIGHT;
//		DrawItem(&dis);
//
//		m_disMouseHover = std::move(dis);
//	}
//
//	CListBox::OnMouseHover(nFlags, point);
//}


//问题是根本不会出去，因为不同的item还是在控件里！
//void CMyListBox1::OnMouseLeave()
//{
//	m_bMouseTrack = true;
//	TRACE("OnMouseLeave");
//	if (m_bMouseHover) {
//		DRAWITEMSTRUCT dis = std::move(m_disMouseHover);
//		dis.itemState = ODS_DEFAULT;
//		DrawItem(&dis);
//		m_bMouseHover = false;
//	}
//
//	CListBox::OnMouseLeave();
//}
