// MyListCtrl1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListCtrl1.h"


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
	//ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyListCtrl1 message handlers



//void CMyListCtrl1::PreSubclassWindow()
//{	
//	SetExtendedStyle(GetExtendedStyle() | LVS_EX_FLATSB);
//	CListCtrl::PreSubclassWindow();
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
	UINT nSBHeight = m_oScrollBar.GetSize();//滚动条高度
	lpMeasureItemStruct->itemHeight = rc.Height() - nSBHeight;
	
	//CListCtrl::MeasureItem(lpMeasureItemStruct);
}


//只有InsertItem了才会进来，而且必须重写
void CMyListCtrl1::DrawItem(LPDRAWITEMSTRUCT lpDis/*lpDrawItemStruct*/)
{
	//SetRedraw(FALSE);
	//UINT idx = lpDis->itemID; 只有一行 idx = 0
	auto nItemCnt = (int)m_vecStPersonInfo.size();//人员个数，为0，InitUpdate会返回，故不会执行下面
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
	//照片，文字宽度
	int nPicWidth = w / 3, nOtherWidth = w - nPicWidth;
	
	//y，高度
	int y = lpDis->rcItem.top, h = lpDis->rcItem.bottom - lpDis->rcItem.top;

	for (auto i = 0; i < nItemCnt; ++i){
		const auto& st = m_vecStPersonInfo[i];

		//画照片、姓名、单位、分类、认证时间。。。
		//Image pic(st.strPic); //照片

		int x =/* w * i*/ lpDis->rcItem.left;  //left是随滚动条变化的，不然图片重叠
		if (i > 0)
			x = lpDis->rcItem.left += w; //lpDis要改变，因为这是个输出参数
		//lpDis->rcItem.left = w * i;
		//lpDis->rcItem.right = lpDis->rcItem.left + w;
		Rect rcPic(x, y, nPicWidth, h);

		gh.DrawImage(&pic, rcPic);

		if (!i) {
			Status s = gh.GetLastStatus();
			//TRACE("Status: %d, rcPic: %d,%d,%d,%d\n", s, rcPic.X, rcPic.Y, rcPic.Width, rcPic.Height);
			TRACE("rcItem:%d,%d,%d,%d\n", lpDis->rcItem.left, lpDis->rcItem.top, lpDis->rcItem.right, lpDis->rcItem.bottom);
		}
	}
	 
	//
	//SetRedraw();
}



bool CMyListCtrl1::InitUpdate()
{
	auto nInfoCnt = (int)m_vecStPersonInfo.size();
	if (0 == nInfoCnt) 
		return false; //没有申请人员
	nInfoCnt = min(10, nInfoCnt);//最多显示10条记录
	
	//删除列
	auto nColCnt = GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < nColCnt; ++i)
		DeleteColumn(i);

	//插入nInfoCnt列
	CRect rc;
	GetClientRect(&rc);
	int w = rc.Width() / 2; //列宽
	for (auto i = 0; i < nInfoCnt; ++i) {
		InsertColumn(i, _T("col"), LVCFMT_LEFT, w);
	}

	//插入一行
	//const CString str2[] = { _T("item"), _T("item"), _T("item"), _T("item"), _T("item") };
	InsertItem(0, _T("item"));
	for (auto i = 1; i < nInfoCnt; ++i) {
		SetItemText(0, i, _T("item"));
	}

	//滚动条,CListCtrl的滚动条是画上去的，这种类型叫FlatSB
	InitializeFlatSB(m_hWnd);
	//FlatSB_EnableScrollBar(m_hWnd, SB_HORZ, ESB_DISABLE_BOTH);
	FlatSB_ShowScrollBar(m_hWnd, SB_BOTH, FALSE);


	m_oScrollBar.Create(0, WS_CHILD | SS_LEFT | SS_NOTIFY | WS_VISIBLE | WS_GROUP,
		CRect(0, 0, 0, 0), /*this*/GetParent());//父窗口是对话框
	//m_oScrollBar.pList = this; //可以用模板
	m_oScrollBar.Set(this); 
	//位置，因为是画在CListCtrl边上的，相对对话框客户区坐标
	//获取CListCtrl坐标
	CRect rcList;
	GetWindowRect(&rcList);
	//转成在对话框中的坐标，因为无边框，所以不用考虑WS_CAPTION、WS_BORDER、WS_THICKFRAME大小
	GetParent()->ScreenToClient(&rcList); 
	UINT nHeight = m_oScrollBar.GetSize();
	//CRect rcSBar(rcList.left, rcList.bottom - nHeight, rcList.right, rcList.bottom);

	m_oScrollBar.SetWindowPos(0, rcList.left, rcList.bottom - nHeight, rcList.Width(), nHeight, SWP_NOZORDER);
	//m_oScrollBar.ShowWindow(SW_NORMAL);

	return true;
}

//void CMyListCtrl1::OnPaint()
//{
//	CPaintDC dc(this); 
//
//	//CListCtrl::OnPaint();
//}
