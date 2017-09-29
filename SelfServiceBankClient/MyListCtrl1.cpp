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
//		DWORD     dwDrawStage;  �׶� CDDS_POSTPAINT
//		HDC       hdc;
//		RECT      rc; CDDS_ITEMPREPAINT CDDS_PREPAINT �׶γ�ʼ��
//		DWORD_PTR dwItemSpec; ��ؼ��й�
//		UINT      uItemState; ״̬����ѡ�����㡢��ͣ�������á�����
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

//ע��Ҫ�ֶ���� ON_WM_MEASUREITEM_REFLECT�������򵼵�ON_WM_MEASUREITEM
void CMyListCtrl1::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	CRect rc;
	GetClientRect(&rc); //���˱�ͷ�����ǰ���������
	UINT nSBHeight = m_oScrollBar.GetSize();//�������߶�
	lpMeasureItemStruct->itemHeight = rc.Height() - nSBHeight;
	
	//CListCtrl::MeasureItem(lpMeasureItemStruct);
}


//ֻ��InsertItem�˲Ż���������ұ�����д
void CMyListCtrl1::DrawItem(LPDRAWITEMSTRUCT lpDis/*lpDrawItemStruct*/)
{
	//SetRedraw(FALSE);
	//UINT idx = lpDis->itemID; ֻ��һ�� idx = 0
	auto nItemCnt = (int)m_vecStPersonInfo.size();//��Ա������Ϊ0��InitUpdate�᷵�أ��ʲ���ִ������
	nItemCnt = min(nItemCnt, 10);

	//�п� cx
	LV_COLUMN lvCol = { 0 };
	lvCol.mask = LVCF_WIDTH | LVCF_FMT;
	GetColumn(0, &lvCol);
	int w = lvCol.cx;

	//CClientDC dc(this); //CPaintDC���У������ص�
	Graphics gh(lpDis->hDC);

#ifdef _DEBUG
	static Image pic(_T("res\\Security_guard_64px.ico"));
#endif // _DEBUG

	//lpDis->rcItem right=1590���У�bottom=21Ĭ�ϣ������������߶�
	CRect rcClient;
	GetClientRect(&rcClient);
	//��Ƭ�����ֿ��
	int nPicWidth = w / 3, nOtherWidth = w - nPicWidth;
	
	//y���߶�
	int y = lpDis->rcItem.top, h = lpDis->rcItem.bottom - lpDis->rcItem.top;

	for (auto i = 0; i < nItemCnt; ++i){
		const auto& st = m_vecStPersonInfo[i];

		//����Ƭ����������λ�����ࡢ��֤ʱ�䡣����
		//Image pic(st.strPic); //��Ƭ

		int x =/* w * i*/ lpDis->rcItem.left;  //left����������仯�ģ���ȻͼƬ�ص�
		if (i > 0)
			x = lpDis->rcItem.left += w; //lpDisҪ�ı䣬��Ϊ���Ǹ��������
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
		return false; //û��������Ա
	nInfoCnt = min(10, nInfoCnt);//�����ʾ10����¼
	
	//ɾ����
	auto nColCnt = GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < nColCnt; ++i)
		DeleteColumn(i);

	//����nInfoCnt��
	CRect rc;
	GetClientRect(&rc);
	int w = rc.Width() / 2; //�п�
	for (auto i = 0; i < nInfoCnt; ++i) {
		InsertColumn(i, _T("col"), LVCFMT_LEFT, w);
	}

	//����һ��
	//const CString str2[] = { _T("item"), _T("item"), _T("item"), _T("item"), _T("item") };
	InsertItem(0, _T("item"));
	for (auto i = 1; i < nInfoCnt; ++i) {
		SetItemText(0, i, _T("item"));
	}

	//������,CListCtrl�Ĺ������ǻ���ȥ�ģ��������ͽ�FlatSB
	InitializeFlatSB(m_hWnd);
	//FlatSB_EnableScrollBar(m_hWnd, SB_HORZ, ESB_DISABLE_BOTH);
	FlatSB_ShowScrollBar(m_hWnd, SB_BOTH, FALSE);


	m_oScrollBar.Create(0, WS_CHILD | SS_LEFT | SS_NOTIFY | WS_VISIBLE | WS_GROUP,
		CRect(0, 0, 0, 0), /*this*/GetParent());//�������ǶԻ���
	//m_oScrollBar.pList = this; //������ģ��
	m_oScrollBar.Set(this); 
	//λ�ã���Ϊ�ǻ���CListCtrl���ϵģ���ԶԻ���ͻ�������
	//��ȡCListCtrl����
	CRect rcList;
	GetWindowRect(&rcList);
	//ת���ڶԻ����е����꣬��Ϊ�ޱ߿����Բ��ÿ���WS_CAPTION��WS_BORDER��WS_THICKFRAME��С
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
