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
	//ON_WM_CTLCOLOR_REFLECT() //������
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
	//UINT nSBHeight = m_oScrollBar.GetSize();//�������߶�
	lpMeasureItemStruct->itemHeight = rc.Height()/* - nSBHeight*/;
	
	//CListCtrl::MeasureItem(lpMeasureItemStruct);
}


//InsertItem�˲Ż���������ұ�����д
//WM_DRAWITEM�������ݣ�ֻ���������յ� -> OnDrawItem -> DrawItem
//OnCtlColor����������dc���ԣ�OnCtlColor -> OnDrawItem �������
//��ӦOnPaint��WM_ERASEBACK����WM_PAINT֮ǰ�����ڲ��ж��Ƿ���WM_DRAWITEM��
void CMyListCtrl1::DrawItem(LPDRAWITEMSTRUCT lpDis/*lpDrawItemStruct*/)
{
	//TRACE("ABC\n");
	//SetRedraw(FALSE);
	//UINT idx = lpDis->itemID; ֻ��һ�� idx = 0
	auto nItemCnt = (int)m_vecPersonInfo.size();//��Ա������Ϊ0��Update�᷵�أ��ʲ���ִ������
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
	//Rect rcGdi(lpDis->rcItem.left, lpDis->rcItem.top, lpDis->rcItem.right, lpDis->rcItem.bottom);
	//SolidBrush sbr(Color(255, 255, 255));
	//gh.FillRectangle(&sbr, rcGdi);

	//��Ƭ�����ֿ�ȣ�����
	int nPicWidth = w / 3 - 5, nOtherWidth = w - nPicWidth;
	static FontFamily ff(_T("΢���ź�"));
	static Gdiplus::Font font(&ff, 12, FontStyleRegular, UnitPixel);
	static SolidBrush sbrText(Color(0, 0, 0));
	static float nLineHeight = font.GetHeight(0.0); //һ�еĸ߶�
	
	//��ʱ������y���꣬�߶ȡ�����
	int y = lpDis->rcItem.top, h = lpDis->rcItem.bottom - lpDis->rcItem.top;
	CString str;
	//std::vector<tuple<CString,PointF>> tmpVec;
	//str.Format(_T("������%s"), st.strName)

	//TRACE("rcItem : %d, %d, %d, %d\n", lpDis->rcItem.left, lpDis->rcItem.top, lpDis->rcItem.right, lpDis->rcItem.bottom);

	for (auto i = 0; i < nItemCnt; ++i){
		const auto& st = m_vecPersonInfo[i];

		//����Ƭ����������λ�����ࡢ��֤ʱ�䡣����
		//Image pic(st.strPic); //��Ƭ

		int x = lpDis->rcItem.left;  //left����������仯�ģ���ȻͼƬ�ص�
		if (i > 0)
			x = lpDis->rcItem.left += w; //lpDisҪ�ı䣬��Ϊ���Ǹ��������
		
		Rect rcPic(x, y, nPicWidth, h);
		//����Ƭ
		gh.DrawImage(&pic, rcPic);

		const auto& stBase = st->stPersonInfo->stBaseInfo;
		//������ǩ & ����
		PointF pf(x + nPicWidth * 1.0f, y * 1.0f);
		str.Format(_T("������%s"), /*_T("")*/CString(stBase.chUserName));
		gh.DrawString(str, -1, &font, pf, &sbrText);   pf.Y += nLineHeight;
		//��λ��ǩ & ��λ
		str.Format(_T("��λ��%s"), /*_T("")*/CString(stBase.chDepartmentName));
		gh.DrawString(str, -1, &font, pf, &sbrText);	pf.Y += nLineHeight;
		//�����ǩ & ����
		str.Format(_T("���ࣺ%s"), /*_T("")*/CString(stBase.chUserType));
		gh.DrawString(str, -1, &font, pf, &sbrText);	pf.Y += nLineHeight;
		//��֤ʱ���ǩ & ��֤ʱ��
		str.Format(_T("��֤ ʱ�䣺%s"), st->tmApply.Format(_T("\n%Y-%m-%d %H:%M:%S")));
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
		return false; //û��������Ա
	nInfoCnt = min(10, nInfoCnt);//�����ʾ10����¼
	
	//ɾ����
	auto nColCnt = GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < nColCnt; ++i)
		DeleteColumn(0); //����DeleteColumn(i);

	//����nInfoCnt��
	CRect rc;
	GetClientRect(&rc);
	int w = rc.Width() / 2; //�п�
	for (auto i = 0; i < nInfoCnt; ++i) {
		InsertColumn(i, _T("col"), LVCFMT_LEFT, w);
	}

	//����һ��
	//const CString str2[] = { _T("item"), _T("item"), _T("item"), _T("item"), _T("item") };
	//ɾ���У���Ȼ֮ǰ�Ļ��ڣ���ֱ����
	DeleteAllItems();
	InsertItem(0, _T("item"));
	//SetItemState(0, )
	for (auto i = 1; i < nInfoCnt; ++i) {
		SetItemText(0, i, _T("item"));
	}

	
	//������
	//CListCtrl�Ĺ������ǻ���ȥ�ģ��������ͽ�FlatSB
	//InitializeFlatSB(m_hWnd);
	//////FlatSB_EnableScrollBar(m_hWnd, SB_BOTH, ESB_DISABLE_BOTH);
	//FlatSB_ShowScrollBar(m_hWnd, SB_VERT, FALSE);


	//m_oScrollBar.Create(0, WS_CHILD | SS_LEFT | SS_NOTIFY | WS_VISIBLE | WS_GROUP,
	//	CRect(0, 0, 0, 0), /*this*///�������ǶԻ���
	////m_oScrollBar.pList = this; //������ģ��
	//m_oScrollBar.Set(this); 
	////λ�ã���Ϊ�ǻ���CListCtrl���ϵģ���ԶԻ���ͻ�������
	////��ȡCListCtrl����
	//CRect rcList;
	//GetWindowRect(&rcList);
	////ת���ڶԻ����е����꣬��Ϊ�ޱ߿����Բ��ÿ���WS_CAPTION��WS_BORDER��WS_THICKFRAME��С
	//GetParent()->ScreenToClient(&rcList); 
	//UINT nHeight = m_oScrollBar.GetSize();
	////CRect rcSBar(rcList.left, rcList.bottom - nHeight, rcList.right, rcList.bottom);

	//m_oScrollBar.SetWindowPos(0, rcList.left, rcList.bottom - nHeight, rcList.Width(), nHeight, SWP_NOZORDER);
	////m_oScrollBar.ShowWindow(SW_NORMAL);
	//m_oScrollBar.UpdateThumbPosition();

	
	return true;
}


//����OnPaint�Ͳ���DrawItem �� OnEraseBkgnd
void CMyListCtrl1::OnPaint()
{
	CPaintDC dc(this); 
	DRAWITEMSTRUCT dis;
	dis.itemID = 0;
	dis.hDC = dc.GetSafeHdc();

	SCROLLINFO si;
	GetScrollInfo(SB_HORZ, &si, SIF_POS | SIF_RANGE);
	//InsertColumn�޶����г�
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


//OnPaint������
//DefWindowProcʹ�ô�����ı�����ˢ����ɫ
//BOOL CMyListCtrl1::OnEraseBkgnd(CDC* pDC)
//{
//	return CListCtrl::OnEraseBkgnd(pDC); //��ɫ������������DrawItem�����ǵ������һ��
//	//return FALSE; //�������������޻��棬����DrawItem��
//	//return TRUE;  //�����������������ص�������DrawItem��
//
//}




//BOOL CMyListCtrl1::PreCreateWindow(CREATESTRUCT& cs)
//{
//	cs.style &= ~WS_VSCROLL;
//
//	return CListCtrl::PreCreateWindow(cs);
//}
