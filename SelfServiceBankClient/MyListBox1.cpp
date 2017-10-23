// MyListBox1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListBox1.h"

#include "SelfServiceBankClientDlg.h" //中介
#include "MyCommonDefine.h"

//using std::get;
using std::placeholders::_1;

/*
自绘列表框
重写DrawItem、MeasureItem，样式要OWNDRAW...
当项目需要绘制或重画时，发送消息，调用DrawItem，
在DrawItem之前，收到Measure项高度的消息，如果样式是fix的，就只来一次，
*/

//#ifdef _DEBUG
//struct ApplyMsg {
//	CString strName;//网点名称
//	int nImportance;//重要程度
//	CTime tmApply;//申请时间
//};
//#endif // _DEBUG


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
	ON_WM_MOUSELEAVE()
	ON_CONTROL_REFLECT(LBN_SELCHANGE, &CMyListBox1::OnLbnSelchange)
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
	//CRect rc;
	//GetClientRect(&rc);
	lpMeasureItemStruct->itemHeight = 20;
}


void CMyListBox1::DrawItem(LPDRAWITEMSTRUCT lpDis/*lpDrawItemStruct*/)
{
	CClientDC dc(this);
	
	UINT idx = lpDis->itemID;
	if (idx != (UINT)-1/* && (idx < m_vecApplyInfo.size())*/) {//空列表框会收到-1
		Graphics gh(dc.GetSafeHdc());

		const CRect& rc = lpDis->rcItem;
		const Rect rcGdi(rc.left, rc.top, rc.Width(), rc.Height());

		static SolidBrush sbrSelect(Color(255, 223, 112));//选择颜色
		static SolidBrush sbrHover(Color(174, 154, 250)); //高亮颜色
		static SolidBrush sbrNormal(Color(250, 250, 250));//常态颜色

		gh.FillRectangle(&sbrNormal, rcGdi);

		//if (m_bMouseHover) {
		//	gh.FillRectangle(&sbrHover, rcGdi);
		//}

		//UINT nHover = lpDis->itemState & ODS_HOTLIGHT;
		//if (nHover) {
		//	gh.FillRectangle(&sbrHover, rcGdi);
		//}

		//是否管控
		auto& st = m_vecApplyInfo[idx];
		if (st->nImportance) {
			gh.FillRectangle(&sbrHover, rcGdi);
		}

		//是否选择
		UINT nSel = lpDis->itemState & ODS_SELECTED;
		if (nSel) {
			gh.FillRectangle(&sbrSelect, rcGdi);
			//m_curItem = idx;//记录当前选择项
		}

		static FontFamily ff(_T("微软雅黑"));
		static Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
		static SolidBrush sbrText(Color(0, 0, 0));
		//RectF rcFGdi(rcGdi.x, rcGdi.y, rcGdi.cx, rcGdi.cy);
		PointF pF(rcGdi.X * 1.0f, rcGdi.Y * 1.0f);

		//LPCTSTR lpszText = (LPCTSTR)lpDis->itemData;  //可以存储图片
		CString str;
		GetText(idx, str); //LBS_HASSTRING程序帮你保存，LBS_SORT不会
		//auto& st = m_vecItemData[idx];

		//gh.DrawString(str, -1, &cstFont, pF, &cstSolidBrushText);
		gh.DrawString(str, -1, &font, pF, &sbrText);
		
	}
}


//void CMyListBox1::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: Add your message handler code here
//					   // Do not call CListBox::OnPaint() for painting messages
//}


//悬停高亮实现：获取所在区域，DrawItem、ItemFromPoint、GetItemRect
//void CMyListBox1::OnMouseMove(UINT nFlags, CPoint point)
//{
//	//static DRAWITEMSTRUCT prevDIS;
//	//prevDIS.itemID = -1;
//	//TRACE("prevDIS.itemID：%d", prevDIS.itemID);
//
//	BOOL bOutSide = TRUE;
//	UINT idx = ItemFromPoint(point, bOutSide);
//	
//	if (!bOutSide) { //点在item上
//		//m_bMouseHover = true;
//		//Invalidate();   只是OnPaint会触发
//		//离开了之前的区域，进入新的区域
//		if (m_prevDIS.itemID != idx /*&& prevDIS.itemID != -1*/ ) {
//			if (m_prevDIS.itemID != m_curItem) {//上一个是点击项，不用恢复
//				m_prevDIS.itemState = ODS_DEFAULT;
//				DrawItem(&m_prevDIS);
//			}
//
//			DRAWITEMSTRUCT dis;
//			GetItemRect(idx, &dis.rcItem);
//			dis.itemID = idx;
//
//			if (idx != m_curItem) {//如果这个项是点击项，不用高亮
//				dis.itemState = ODS_HOTLIGHT;
//				DrawItem(&dis);
//			}
//
//			m_prevDIS = std::move(dis);
//		}	
//
//		//m_disMouseHover = std::move(dis);
//	}
//	//else {//点不在item上
//	//	prevDIS.itemState = ODS_DEFAULT;
//	//	DrawItem(&prevDIS);
//	//}
//
//	//追踪鼠标悬停消息（注册）
//	if (m_bMouseTrack)
//	{
//		m_bMouseTrack = false;
//		TRACKMOUSEEVENT tme;
//		tme.cbSize = sizeof(TRACKMOUSEEVENT);
//		tme.dwFlags = TME_HOVER | TME_LEAVE;
//		//tme.dwHoverTime = HOVER_DEFAULT;  
//		tme.dwHoverTime = 50;
//		tme.hwndTrack = GetSafeHwnd();
//		TrackMouseEvent(&tme);
//	}
//
//	CListBox::OnMouseMove(nFlags, point);
//}


//void CMyListBox1::OnMouseHover(UINT nFlags, CPoint point)
//{
//	BOOL bOutSide = TRUE;
//	UINT idx = ItemFromPoint(point, bOutSide);
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
//	//if (m_bMouseHover) {
//	//	DRAWITEMSTRUCT dis = std::move(m_disMouseHover);
//	//	dis.itemState = ODS_DEFAULT;
//	//	DrawItem(&dis);
//	//	m_bMouseHover = false;7
//	//}
//	if (m_curItem != m_prevDIS.itemID) {
//		//去掉高亮
//		m_prevDIS.itemState = m_prevDIS.itemState &~ODS_HOTLIGHT;
//		DrawItem(&m_prevDIS);
//	}
//
//	CListBox::OnMouseLeave();
//}


//int CMyListBox1::CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct)
//{
//	// TODO:  Add your code to determine the sorting order of the specified items
//	// return -1 = item 1 sorts before item 2
//	// return 0 = item 1 and item 2 sort the same
//	// return 1 = item 1 sorts after item 2
//
//	//这是ZC有申请消息时传来的结构
//	//ApplyMsg* msg1 = (ApplyMsg*)GetItemData(lpCompareItemStruct->itemID1);
//	//ApplyMsg* msg2 = (ApplyMsg*)GetItemData(lpCompareItemStruct->itemID2);
//
//	//只有两个项的时候，lpCompareItemStruct->itemID2是无效值
//	//auto& st1 = m_vecItemData[lpCompareItemStruct->itemID1];
//	//auto& st2 = m_vecItemData[lpCompareItemStruct->itemID2];
//	
//	//重要程度 ， 申请时间
//	/*using std::get;
//	if (get<1>(st1) > get<1>(st2))
//		return -1;
//	else if (get<1>(st1) == get<1>(st2) && get<2>(st1) > get<2>(st2))
//		return -1;
//	else
//		return 1;*/
//
//	//乱码
//	/*ASSERT(lpCompareItemStruct->CtlType == ODT_LISTBOX);
//	LPCTSTR lpszText1 = (LPCTSTR)lpCompareItemStruct->itemData1;
//	ASSERT(lpszText1 != NULL);
//	LPCTSTR lpszText2 = (LPCTSTR)lpCompareItemStruct->itemData2;
//	ASSERT(lpszText2 != NULL);
//
//	return _tcscmp(lpszText2, lpszText1);*/
//
//	return 0;
//}


//void CMyListBox1::MySetItemData(int idx, /*CString name, int n, CTime tm*/)
//{
//	int nCnt = (int)m_vecItemData.size();
//	if (idx > nCnt - 1) {
//		m_vecItemData.push_back(std::make_tuple(name, n, tm));
//	}
//	else {
//		m_vecItemData[idx] = std::make_tuple(name, n, tm);
//	}
//}

//按重要程度、申请时间排序
bool Lambda_InsertString(const std::shared_ptr<stApplyInfo>& st1, 
	const std::shared_ptr<stApplyInfo>& st2)
{
	int nImp1 = st1->nImportance;
	int nImp2 = st2->nImportance;
	if (nImp1 > nImp2) { //st2重要程度比st1大
		return true;
	}
	else if (nImp1 == nImp2 && st1->tmApply > st2->tmApply) { //st2申请时间比st1早
		return true;
	}
	else
		return false;
}
//查找申请信息
bool Lambda_FindApplyInfo(const std::shared_ptr<stApplyInfo>& st, const CString& webName, const CString& partName) {
	return (st->strWebSiteName == webName && st->strPartName == partName);
}
void CMyListBox1::MyInsertString(const std::shared_ptr<stApplyInfo>& st)
{
	
	//if (st->nSlave > -1) {//多人刷卡
	//	//查找是否有该网点、部位的刷卡信息
	//	auto it = std::find_if(m_vecApplyInfo.begin(), m_vecApplyInfo.end(),
	//		std::bind(Lambda_FindApplyInfo, _1, st->strWebSiteName, st->strPartName));
	//	if (m_vecApplyInfo.end() != it) {
	//		return;
	//	}
	//}
		

	//找到t应该在m_spVecItemData中的索引
	//if(m_spVecItemData){
	using std::placeholders::_1;
	auto it = std::find_if(m_vecApplyInfo.begin(), m_vecApplyInfo.end(),
		std::bind(Lambda_InsertString, _1, st));
	
	if (m_vecApplyInfo.end() == it) {
		m_vecApplyInfo.push_back(st);
		//InsertString触发DrawItem，DrawItem使用数据
		InsertString(m_vecApplyInfo.size() - 1, st->strWebSiteName);
	}
	else {
		int idx = std::distance(m_vecApplyInfo.begin(), it);
		m_vecApplyInfo.insert(it, st);
		InsertString(idx, st->strWebSiteName);
	}
	//}
}

void CMyListBox1::OnLbnSelchange()
{
	//中介者，各控件之间的关系
	//获取所选item内容-》传给中介，中介获取右侧第一行信息排序
	int nSel = GetCurSel();
	//点击空白，nSel = -1;
	if (nSel < 0) return;
	const auto& st = m_vecApplyInfo[nSel];
	m_oMediator->DisplayDetail(st); //m_oMediator=0xcccc竟然也能进去，所以m_li崩溃
}
