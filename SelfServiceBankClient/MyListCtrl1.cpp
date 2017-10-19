// MyListCtrl1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListCtrl1.h"
#include "MyCommonDefine.h"

using std::tuple;

// CMyListCtrl1

IMPLEMENT_DYNAMIC(CMyListCtrl1, CListCtrl)

CMyListCtrl1::CMyListCtrl1()
{

}

CMyListCtrl1::~CMyListCtrl1()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl1, CListCtrl)
	//ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CMyListCtrl1::OnNMCustomdraw)
	//ON_WM_MEASUREITEM()
	ON_WM_MEASUREITEM_REFLECT()
	ON_WM_PAINT()
	//ON_NOTIFY_REFLECT(NM_CLICK, &CMyListCtrl1::OnNMClick)
	//ON_WM_ERASEBKGND()
	//ON_WM_CTLCOLOR_REFLECT() //不调用
END_MESSAGE_MAP()



// CMyListCtrl1 message handlers



//void CMyListCtrl1::PreSubclassWindow()
//{	
//	//SetExtendedStyle(GetExtendedStyle() &~ WS_VSCROLL);
//	//ModifyStyle(WS_VSCROLL, 0);
//	//CListCtrl::PreSubclassWindow();
//}


//void CMyListCtrl1::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
//	/*typedef struct tagNMCUSTOMDRAWINFO {
//		NMHDR     hdr;
//		DWORD     dwDrawStage;  阶段 CDDS_POSTPAINT
//		HDC       hdc;
//		RECT      rc; CDDS_ITEMPREPAINT CDDS_PREPAINT 阶段初始化
//		DWORD_PTR dwItemSpec; 与控件有关
//		UINT      uItemState; 状态：勾选、焦点、悬停、不可用。。。
//		LPARAM    lItemlParam;
//	} NMCUSTOMDRAW, *LPNMCUSTOMDRAW;*/
//
//
//	*pResult = 0;
//}


//void CMyListCtrl1::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
//{
//	CListCtrl::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
//}

//注意要手动添加 ON_WM_MEASUREITEM_REFLECT而不是向导的ON_WM_MEASUREITEM
void CMyListCtrl1::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	CRect rc;
	GetClientRect(&rc); //除了表头，但是包含滚动条
	//UINT nSBHeight = m_oScrollBar.GetSize();//滚动条高度
	lpMeasureItemStruct->itemHeight = rc.Height()/* - nSBHeight*/;
	
	//CListCtrl::MeasureItem(lpMeasureItemStruct);
}


//InsertItem了才会进来，而且必须重写
//WM_DRAWITEM画子内容，只有宿主会收到 -> OnDrawItem -> DrawItem
//OnCtlColor子内容设置dc属性，OnCtlColor -> OnDrawItem 不会调用
//响应OnPaint（WM_ERASEBACK总在WM_PAINT之前），内部判断是否发送WM_DRAWITEM，
void CMyListCtrl1::DrawItem(LPDRAWITEMSTRUCT lpDis/*lpDrawItemStruct*/)
{
	//TRACE("ABC\n");
	//SetRedraw(FALSE);
	//UINT idx = lpDis->itemID; 只有一行 idx = 0
	auto nItemCnt = (int)m_vecPersonInfo.size();//人员个数，为0，Update会返回，故不会执行下面
	nItemCnt = min(nItemCnt, 10);

	//列宽 cx
	LV_COLUMN lvCol = { 0 };
	lvCol.mask = LVCF_WIDTH | LVCF_FMT;
	GetColumn(0, &lvCol);
	int w = lvCol.cx;

	//CClientDC dc(this); //CPaintDC不行，画面重叠
	Graphics gh(lpDis->hDC);

#ifdef _DEBUG
	static Image pic(_T("res\\Security_guard_64px.ico"));
#endif // _DEBUG

	//lpDis->rcItem right=1590按列，bottom=21默认，包括滚动条高度
	CRect rcClient;
	GetClientRect(&rcClient);
	//Rect rcGdi(lpDis->rcItem.left, lpDis->rcItem.top, lpDis->rcItem.right, lpDis->rcItem.bottom);
	//SolidBrush sbr(Color(255, 255, 255));
	//gh.FillRectangle(&sbr, rcGdi);

	//照片，文字宽度，字体
	int nPicWidth = w / 3 - 5, nOtherWidth = w - nPicWidth;
	static FontFamily ff(_T("微软雅黑"));
	static Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
	static SolidBrush sbrText(Color(0, 0, 0));
	static float nLineHeight = font.GetHeight(0.0); //一行的高度
	
	//临时变量：y坐标，高度。。。
	int y = lpDis->rcItem.top, h = lpDis->rcItem.bottom - lpDis->rcItem.top;
	CString str;
	//std::vector<tuple<CString,PointF>> tmpVec;
	//str.Format(_T("姓名：%s"), st.strName)

	//TRACE("rcItem : %d, %d, %d, %d\n", lpDis->rcItem.left, lpDis->rcItem.top, lpDis->rcItem.right, lpDis->rcItem.bottom);

	for (auto i = 0; i < nItemCnt; ++i){
		const auto& st = m_vecPersonInfo[i];

		//画照片、姓名、单位、分类、认证时间。。。
		//Image pic(st.strPic); //照片

		int x = lpDis->rcItem.left;  //left是随滚动条变化的，不然图片重叠
		if (i > 0)
			x = lpDis->rcItem.left += w; //lpDis要改变，因为这是个输出参数
		
		Rect rcPic(x, y, nPicWidth, h);
		//画照片
		gh.DrawImage(&pic, rcPic);

		const auto& stBase = st->stPersonInfo->stBaseInfo;
		//姓名标签 & 姓名
		PointF pf(x + nPicWidth * 1.0f, y * 1.0f);
		str.Format(_T("姓名：%s"), /*_T("")*/CString(stBase.chUserName));
		gh.DrawString(str, -1, &font, pf, &sbrText);   pf.Y += nLineHeight;
		//单位标签 & 单位
		str.Format(_T("单位：%s"), /*_T("")*/CString(stBase.chDepartmentName));
		gh.DrawString(str, -1, &font, pf, &sbrText);	pf.Y += nLineHeight;
		//分类标签 & 分类
		str.Format(_T("分类：%s"), /*_T("")*/CString(stBase.chUserType));
		gh.DrawString(str, -1, &font, pf, &sbrText);	pf.Y += nLineHeight;
		//认证时间标签 & 认证时间
		str.Format(_T("认证 时间：%s"), st->tmApply.Format(_T("\n%Y-%m-%d %H:%M:%S")));
		gh.DrawString(str, -1, &font, pf, &sbrText);
	}
	 
	//
	//SetRedraw();
}

void CMyListCtrl1::MyInsertSubItem(const std::shared_ptr<stApplyPersonInfo>& st)
{
	//m_vecPersonInfo.push_back(st);
	//Update();

	m_vecPersonInfo.push_back(st);
	//Update();

	//m_vecPersonInfo.clear();
	//for (auto& st : vec) {
	//	m_vecPersonInfo.push_back(std::shared_ptr<stApplyPersonInfo>(&st));
	//}
}

bool CMyListCtrl1::Update()
{
	auto nInfoCnt = (int)m_vecPersonInfo.size();
	if (0 == nInfoCnt) 
		return false; //没有申请人员
	nInfoCnt = min(10, nInfoCnt);//最多显示10条记录
	
	//删除列
	auto nColCnt = GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < nColCnt; ++i)
		DeleteColumn(0); //不能DeleteColumn(i);

	//插入nInfoCnt列
	CRect rc;
	GetClientRect(&rc);
	int w = rc.Width() / 2; //列宽
	for (auto i = 0; i < nInfoCnt; ++i) {
		InsertColumn(i, _T("col"), LVCFMT_LEFT, w);
	}

	//插入一行
	//const CString str2[] = { _T("item"), _T("item"), _T("item"), _T("item"), _T("item") };
	//删除行，不然之前的还在，垂直滚动
	DeleteAllItems();
	InsertItem(0, _T("item"));
	//SetItemState(0, )
	for (auto i = 1; i < nInfoCnt; ++i) {
		SetItemText(0, i, _T("item"));
	}

	
	//滚动条
	//CListCtrl的滚动条是画上去的，这种类型叫FlatSB
	//InitializeFlatSB(m_hWnd);
	//////FlatSB_EnableScrollBar(m_hWnd, SB_BOTH, ESB_DISABLE_BOTH);
	//FlatSB_ShowScrollBar(m_hWnd, SB_VERT, FALSE);


	//m_oScrollBar.Create(0, WS_CHILD | SS_LEFT | SS_NOTIFY | WS_VISIBLE | WS_GROUP,
	//	CRect(0, 0, 0, 0), /*this*///父窗口是对话框
	////m_oScrollBar.pList = this; //可以用模板
	//m_oScrollBar.Set(this); 
	////位置，因为是画在CListCtrl边上的，相对对话框客户区坐标
	////获取CListCtrl坐标
	//CRect rcList;
	//GetWindowRect(&rcList);
	////转成在对话框中的坐标，因为无边框，所以不用考虑WS_CAPTION、WS_BORDER、WS_THICKFRAME大小
	//GetParent()->ScreenToClient(&rcList); 
	//UINT nHeight = m_oScrollBar.GetSize();
	////CRect rcSBar(rcList.left, rcList.bottom - nHeight, rcList.right, rcList.bottom);

	//m_oScrollBar.SetWindowPos(0, rcList.left, rcList.bottom - nHeight, rcList.Width(), nHeight, SWP_NOZORDER);
	////m_oScrollBar.ShowWindow(SW_NORMAL);
	//m_oScrollBar.UpdateThumbPosition();

	
	return true;
}


//走了OnPaint就不走DrawItem 和 OnEraseBkgnd
void CMyListCtrl1::OnPaint()
{
	CPaintDC dc(this); 
	DRAWITEMSTRUCT dis;
	dis.itemID = 0;
	dis.hDC = dc.GetSafeHdc();

	SCROLLINFO si;
	GetScrollInfo(SB_HORZ, &si, SIF_POS | SIF_RANGE);
	//InsertColumn限定了列长
	CRect rc;
	GetClientRect(&rc);
	//TRACE("si:min=%d,max=%d,pos=%d\n", si.nMin, si.nMax, si.nPos);
	dis.rcItem = { si.nMin - si.nPos, rc.top, si.nMax - si.nPos, rc.bottom };

	//ModifyStyle(WS_VSCROLL, 0);
	DrawItem(&dis);
	//CListCtrl::OnPaint();
}


//void CMyListCtrl1::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: Add your control notification handler code here
//	*pResult = 0;
//}


//OnPaint调用了
//DefWindowProc使用窗口类的背景画刷，白色
//BOOL CMyListCtrl1::OnEraseBkgnd(CDC* pDC)
//{
//	return CListCtrl::OnEraseBkgnd(pDC); //白色擦除背景，走DrawItem，但是点击又走一遍
//	//return FALSE; //不擦除背景，无画面，不走DrawItem；
//	//return TRUE;  //不擦除背景，画面重叠，不走DrawItem；
//
//}




//BOOL CMyListCtrl1::PreCreateWindow(CREATESTRUCT& cs)
//{
//	cs.style &= ~WS_VSCROLL;
//
//	return CListCtrl::PreCreateWindow(cs);
//}
