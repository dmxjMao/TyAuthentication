// MyListBox1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListBox1.h"

#include "SelfServiceBankClientDlg.h" //�н�
#include "MyCommonDefine.h"

//using std::get;
using std::placeholders::_1;

/*
�Ի��б��
��дDrawItem��MeasureItem����ʽҪOWNDRAW...
����Ŀ��Ҫ���ƻ��ػ�ʱ��������Ϣ������DrawItem��
��DrawItem֮ǰ���յ�Measure��߶ȵ���Ϣ�������ʽ��fix�ģ���ֻ��һ�Σ�
*/

//#ifdef _DEBUG
//struct ApplyMsg {
//	CString strName;//��������
//	int nImportance;//��Ҫ�̶�
//	CTime tmApply;//����ʱ��
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
	//CRect rc;
	//GetClientRect(&rc);
	lpMeasureItemStruct->itemHeight = 20;
}


void CMyListBox1::DrawItem(LPDRAWITEMSTRUCT lpDis/*lpDrawItemStruct*/)
{
	CClientDC dc(this);
	
	UINT idx = lpDis->itemID;
	if (idx != (UINT)-1/* && (idx < m_vecApplyInfo.size())*/) {//���б����յ�-1
		Graphics gh(dc.GetSafeHdc());

		const CRect& rc = lpDis->rcItem;
		const Rect rcGdi(rc.left, rc.top, rc.Width(), rc.Height());

		static SolidBrush sbrSelect(Color(255, 223, 112));//ѡ����ɫ
		static SolidBrush sbrHover(Color(174, 154, 250)); //������ɫ
		static SolidBrush sbrNormal(Color(250, 250, 250));//��̬��ɫ

		gh.FillRectangle(&sbrNormal, rcGdi);

		//if (m_bMouseHover) {
		//	gh.FillRectangle(&sbrHover, rcGdi);
		//}

		//UINT nHover = lpDis->itemState & ODS_HOTLIGHT;
		//if (nHover) {
		//	gh.FillRectangle(&sbrHover, rcGdi);
		//}

		//�Ƿ�ܿ�
		auto& st = m_vecApplyInfo[idx];
		if (st->nImportance) {
			gh.FillRectangle(&sbrHover, rcGdi);
		}

		//�Ƿ�ѡ��
		UINT nSel = lpDis->itemState & ODS_SELECTED;
		if (nSel) {
			gh.FillRectangle(&sbrSelect, rcGdi);
			//m_curItem = idx;//��¼��ǰѡ����
		}

		static FontFamily ff(_T("΢���ź�"));
		static Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
		static SolidBrush sbrText(Color(0, 0, 0));
		//RectF rcFGdi(rcGdi.x, rcGdi.y, rcGdi.cx, rcGdi.cy);
		PointF pF(rcGdi.X * 1.0f, rcGdi.Y * 1.0f);

		//LPCTSTR lpszText = (LPCTSTR)lpDis->itemData;  //���Դ洢ͼƬ
		CString str;
		GetText(idx, str); //LBS_HASSTRING������㱣�棬LBS_SORT����
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


//��ͣ����ʵ�֣���ȡ��������DrawItem��ItemFromPoint��GetItemRect
//void CMyListBox1::OnMouseMove(UINT nFlags, CPoint point)
//{
//	//static DRAWITEMSTRUCT prevDIS;
//	//prevDIS.itemID = -1;
//	//TRACE("prevDIS.itemID��%d", prevDIS.itemID);
//
//	BOOL bOutSide = TRUE;
//	UINT idx = ItemFromPoint(point, bOutSide);
//	
//	if (!bOutSide) { //����item��
//		//m_bMouseHover = true;
//		//Invalidate();   ֻ��OnPaint�ᴥ��
//		//�뿪��֮ǰ�����򣬽����µ�����
//		if (m_prevDIS.itemID != idx /*&& prevDIS.itemID != -1*/ ) {
//			if (m_prevDIS.itemID != m_curItem) {//��һ���ǵ������ûָ�
//				m_prevDIS.itemState = ODS_DEFAULT;
//				DrawItem(&m_prevDIS);
//			}
//
//			DRAWITEMSTRUCT dis;
//			GetItemRect(idx, &dis.rcItem);
//			dis.itemID = idx;
//
//			if (idx != m_curItem) {//���������ǵ������ø���
//				dis.itemState = ODS_HOTLIGHT;
//				DrawItem(&dis);
//			}
//
//			m_prevDIS = std::move(dis);
//		}	
//
//		//m_disMouseHover = std::move(dis);
//	}
//	//else {//�㲻��item��
//	//	prevDIS.itemState = ODS_DEFAULT;
//	//	DrawItem(&prevDIS);
//	//}
//
//	//׷�������ͣ��Ϣ��ע�ᣩ
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
//	//if (m_bMouseHover) {
//	//	DRAWITEMSTRUCT dis = std::move(m_disMouseHover);
//	//	dis.itemState = ODS_DEFAULT;
//	//	DrawItem(&dis);
//	//	m_bMouseHover = false;7
//	//}
//	if (m_curItem != m_prevDIS.itemID) {
//		//ȥ������
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
//	//����ZC��������Ϣʱ�����Ľṹ
//	//ApplyMsg* msg1 = (ApplyMsg*)GetItemData(lpCompareItemStruct->itemID1);
//	//ApplyMsg* msg2 = (ApplyMsg*)GetItemData(lpCompareItemStruct->itemID2);
//
//	//ֻ���������ʱ��lpCompareItemStruct->itemID2����Чֵ
//	//auto& st1 = m_vecItemData[lpCompareItemStruct->itemID1];
//	//auto& st2 = m_vecItemData[lpCompareItemStruct->itemID2];
//	
//	//��Ҫ�̶� �� ����ʱ��
//	/*using std::get;
//	if (get<1>(st1) > get<1>(st2))
//		return -1;
//	else if (get<1>(st1) == get<1>(st2) && get<2>(st1) > get<2>(st2))
//		return -1;
//	else
//		return 1;*/
//
//	//����
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

//����Ҫ�̶ȡ�����ʱ������
bool Lambda_InsertString(const std::shared_ptr<stApplyInfo>& st1, 
	const std::shared_ptr<stApplyInfo>& st2)
{
	int nImp1 = st1->nImportance;
	int nImp2 = st2->nImportance;
	if (nImp1 > nImp2) { //st2��Ҫ�̶ȱ�st1��
		return true;
	}
	else if (nImp1 == nImp2 && st1->tmApply > st2->tmApply) { //st2����ʱ���st1��
		return true;
	}
	else
		return false;
}
//����������Ϣ
bool Lambda_FindApplyInfo(const std::shared_ptr<stApplyInfo>& st, const CString& webName, const CString& partName) {
	return (st->strWebSiteName == webName && st->strPartName == partName);
}
void CMyListBox1::MyInsertString(const std::shared_ptr<stApplyInfo>& st)
{
	
	//if (st->nSlave > -1) {//����ˢ��
	//	//�����Ƿ��и����㡢��λ��ˢ����Ϣ
	//	auto it = std::find_if(m_vecApplyInfo.begin(), m_vecApplyInfo.end(),
	//		std::bind(Lambda_FindApplyInfo, _1, st->strWebSiteName, st->strPartName));
	//	if (m_vecApplyInfo.end() != it) {
	//		return;
	//	}
	//}
		

	//�ҵ�tӦ����m_spVecItemData�е�����
	//if(m_spVecItemData){
	using std::placeholders::_1;
	auto it = std::find_if(m_vecApplyInfo.begin(), m_vecApplyInfo.end(),
		std::bind(Lambda_InsertString, _1, st));
	
	if (m_vecApplyInfo.end() == it) {
		m_vecApplyInfo.push_back(st);
		//InsertString����DrawItem��DrawItemʹ������
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
	//�н��ߣ����ؼ�֮��Ĺ�ϵ
	//��ȡ��ѡitem����-�������н飬�н��ȡ�Ҳ��һ����Ϣ����
	int nSel = GetCurSel();
	//����հף�nSel = -1;
	if (nSel < 0) return;
	const auto& st = m_vecApplyInfo[nSel];
	m_oMediator->DisplayDetail(st); //m_oMediator=0xcccc��ȻҲ�ܽ�ȥ������m_li����
}
