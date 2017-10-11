// MyLogListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyLogListCtrl.h"


// CMyLogListCtrl

IMPLEMENT_DYNAMIC(CMyLogListCtrl, CListCtrl)

CMyLogListCtrl::CMyLogListCtrl()
{

}

CMyLogListCtrl::~CMyLogListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyLogListCtrl, CListCtrl)
	
END_MESSAGE_MAP()



// CMyLogListCtrl message handlers




void CMyLogListCtrl::PreSubclassWindow()
{
	ModifyStyle(0, LVS_REPORT);
	SetExtendedStyle(GetExtendedStyle() | LVS_EX_FULLROWSELECT
		| LVS_EX_DOUBLEBUFFER | LVS_EX_HEADERDRAGDROP
		| LVS_EX_COLUMNSNAPPOINTS | LVS_EX_ONECLICKACTIVATE );

	EnableWindowTheme(m_hWnd, L"ListView", L"Explorer", NULL);

	CListCtrl::PreSubclassWindow();
}





bool CMyLogListCtrl::Init()
{
	CRect rc;
	GetClientRect(&rc);
	int w = rc.Width() - 50;
	//���֡����
	std::vector<std::tuple<CString, int>> vecCol = {
		{ _T("��־����") , w},
		{ _T("�����ļ� & �к�") , 50 }

	};
	//const CString strCol[] = { _T("��־����"),_T("�����ļ� & �к�") };
	int nColCnt = (int)vecCol.size();

	LVCOLUMN lvCol;
	lvCol.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM | LVCF_MINWIDTH;
	int colWidth = 0;//�п�
	for (int i = 0; i < nColCnt; ++i) {
		auto& tpl = vecCol[i];
		CString& str = std::get<0>(tpl);
		lvCol.pszText = str.GetBuffer();
		lvCol.cchTextMax = str.GetLength();
		lvCol.iSubItem = i;
		colWidth = 2 * GetStringWidth(str); //��С�п�
		lvCol.cxMin = colWidth;
		lvCol.cx = std::get<1>(tpl);

		InsertColumn(i, &lvCol);
	}
	

	return true;
}