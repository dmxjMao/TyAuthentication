// MyListBox1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListBox1.h"


/*
�Ի��б��
��дDrawItem��MeasureItem����ʽҪOWNDRAW...
����Ŀ��Ҫ���ƻ��ػ�ʱ��������Ϣ������DrawItem��
��DrawItem֮ǰ���յ�Measure��߶ȵ���Ϣ�������ʽ��fix�ģ���ֻ��һ�Σ�
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
//	//�������Ի棨�˴���Ч��ֻ���������ã�
//	//ModifyStyle(LBS_SORT | LBS_OWNERDRAWVARIABLE, LBS_OWNERDRAWVARIABLE);
//
//	CListBox::PreSubclassWindow();
//}

//��������϶��ؼ��ģ������⣻ֻ�ж�̬Create�Ż���
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
////ÿ��Ҫ����������
//void CMyListBox1::DrawItem(LPDRAWITEMSTRUCT lpDis)
//{
//	CClientDC dc(this);
//	Graphics gh(dc.GetSafeHdc());
//
//	const CRect& rc = lpDis->rcItem;
//	const Rect rcGdi(rc.left, rc.top, rc.Width(), rc.Height());
//	UINT idx = lpDis->itemID;
//
//	SolidBrush sbrHover(Color(255, 223, 112)); //������ѡ�����ɫ
//	SolidBrush sbrNormal(Color(250, 250, 250));//��̬��ɫ
//	UINT nSel = lpDis->itemState & ODS_SELECTED;
//	if (nSel) {
//		gh.FillRectangle(&sbrHover, rcGdi);
//	}
//	else {
//		gh.FillRectangle(&sbrNormal, rcGdi);
//	}
//
//
//	if (idx != (UINT)-1) {//���б����յ�
//		
//	}
//}


//��̬Create�Ż����⣬�϶��������
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
	
	static SolidBrush sbrSelect(Color(255, 223, 112));//ѡ����ɫ
	static SolidBrush sbrHover(Color(174, 154, 250)); //������ɫ
	static SolidBrush sbrNormal(Color(250, 250, 250));//��̬��ɫ
	
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
		m_curItem = idx;//��¼��ǰѡ����
	}
	
	
	if (idx != (UINT)-1) {//���б����յ�
		auto n = GetItemHeight(idx);

		static FontFamily ff(_T("΢���ź�"));
		static Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
		static SolidBrush sbrText(Color(0, 0, 0));
		//RectF rcFGdi(rcGdi.x, rcGdi.y, rcGdi.cx, rcGdi.cy);
		PointF pF(rcGdi.X * 1.0f, rcGdi.Y * 1.0f);
		
		//LPCTSTR lpszText = (LPCTSTR)lpDis->itemData;  //���Դ洢ͼƬ
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


//��ͣ����ʵ�֣���ȡ��������DrawItem��ItemFromPoint��GetItemRect
void CMyListBox1::OnMouseMove(UINT nFlags, CPoint point)
{
	static DRAWITEMSTRUCT prevDIS;
	//prevDIS.itemID = -1;
	//TRACE("prevDIS.itemID��%d", prevDIS.itemID);

	BOOL bOutSide = TRUE;
	UINT idx = ItemFromPoint(point, bOutSide);
	
	if (!bOutSide) { //����item��
		//m_bMouseHover = true;
		//Invalidate();   ֻ��OnPaint�ᴥ��
		//�뿪��֮ǰ�����򣬽����µ�����
		if (prevDIS.itemID != idx /*&& prevDIS.itemID != -1*/ ) {
			if (prevDIS.itemID != m_curItem) {//��һ���ǵ������ûָ�
				prevDIS.itemState = ODS_DEFAULT;
				DrawItem(&prevDIS);
			}

			DRAWITEMSTRUCT dis;
			GetItemRect(idx, &dis.rcItem);
			dis.itemID = idx;

			if (idx != m_curItem) {//���������ǵ������ø���
				dis.itemState = ODS_HOTLIGHT;
				DrawItem(&dis);
			}

			prevDIS = std::move(dis);
		}	

		//m_disMouseHover = std::move(dis);
	}
	//else {//�㲻��item��
	//	prevDIS.itemState = ODS_DEFAULT;
	//	DrawItem(&prevDIS);
	//}

	//׷�������ͣ��Ϣ��ע�ᣩ
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
//		//Invalidate();   ֻ��OnPaint�ᴥ��
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


//�����Ǹ��������ȥ����Ϊ��ͬ��item�����ڿؼ��
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
