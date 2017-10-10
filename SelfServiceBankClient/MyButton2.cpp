// MyButton2.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyButton2.h"


// CMyButton2

IMPLEMENT_DYNAMIC(CMyButton2, CButton)

CMyButton2::CMyButton2()
{

}

CMyButton2::CMyButton2(const std::shared_ptr<Image>& img1, const std::shared_ptr<Image>& img2)
	: m_img1(img1), m_img2(img2)
{
	//GetWindowText(m_str);
	//tooltip放在父窗口更好，至少只有一个CToolTipCtrl
	//if (m_tt.Create(this, TTS_ALWAYSTIP)) {
	//	m_tt.Activate(TRUE);
	//	BOOL b = m_tt.AddTool(this);
	//	m_tt.SetMaxTipWidth(150);
	//	m_tt.SetDelayTime(TTDT_INITIAL, 200);
	//}
	
	
}

CMyButton2::~CMyButton2()
{
}


BEGIN_MESSAGE_MAP(CMyButton2, CButton)
	ON_WM_PAINT()
	//ON_NOTIFY_EX(TTN_NEEDTEXT, 0, &CMyButton2::OnTtnNeedText)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CMyButton2 message handlers




void CMyButton2::OnPaint()
{
	CPaintDC dc(this);
	Graphics gh(dc.GetSafeHdc());

	CRect rc;
	GetClientRect(&rc);
	//Rect rcGdi(rc.left, rc.top, rc.right, rc.bottom);
	//画img1
	int w1 = m_img1 ? m_img1->GetWidth() : 0;
	int h = m_img1 ? m_img1->GetHeight() : 0;
	gh.DrawImage(m_img1.get(), 0, 0, w1, h);

	//画img2
	int x = w1;
	int w2 = m_img2 ? m_img2->GetWidth() : 0;
	gh.DrawImage(m_img2.get(), x, 0, w2, rc.Height());

	//写字
	x = w1 + 40;
	FontFamily ff(_T("微软雅黑"));
	int nTextSize = 12;//字号
	Gdiplus::Font font(&ff, nTextSize*1.0f, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(Color(255, 255, 255));
	auto nTextHeight = font.GetHeight(0.0f);
	PointF pf(x * 1.0f, rc.Height() - nTextHeight - 8.0f);

	//CString str;
	GetWindowText(m_str);
	if (nTextSize * (m_str.GetLength() - 1) > w2) {
		//显示省略号，tooltip
		CString strTmp;
		strTmp.Format(_T("%s..."), m_str.Left((w2-40) / nTextSize - 1));
		gh.DrawString(strTmp, -1, &font, pf, &sbrText);
	}
	else
	{
		gh.DrawString(m_str, -1, &font, pf, &sbrText);
	}	
}


void CMyButton2::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{
}


//BOOL CMyButton2::PreTranslateMessage(MSG* pMsg)
//{
//	m_tt.RelayEvent(pMsg);
//
//	return CButton::PreTranslateMessage(pMsg);
//}


//没有TTN_NEEDTEXT消息过来
//BOOL CMyButton2::OnTtnNeedText(UINT id, NMHDR * pNMHDR, LRESULT * pResult)
//{
//	UNREFERENCED_PARAMETER(id);
//
//	NMTTDISPINFO *pTTT = (NMTTDISPINFO *)pNMHDR;
//	UINT_PTR nID = pNMHDR->idFrom;
//	BOOL bRet = FALSE;
//
//	if (pTTT->uFlags & TTF_IDISHWND)
//	{
//		// idFrom is actually the HWND of the tool
//		nID = ::GetDlgCtrlID((HWND)nID);
//		if (nID)
//		{
//			_stprintf_s(pTTT->szText, sizeof(pTTT->szText) / sizeof(TCHAR),
//				_T("Control ID = %d"), nID);
//			pTTT->hinst = AfxGetResourceHandle();
//			bRet = TRUE;
//		}
//	}
//
//	*pResult = 0;
//
//	return bRet;
//}




void CMyButton2::OnMouseMove(UINT nFlags, CPoint point)
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

		//tooltip
		//m_tt.UpdateTipText(m_str, this);
	}

	CButton::OnMouseMove(nFlags, point);
}


void CMyButton2::OnMouseHover(UINT nFlags, CPoint point)
{
	m_bHover = true;
	Invalidate();

	CButton::OnMouseHover(nFlags, point);
}


void CMyButton2::OnMouseLeave()
{
	m_bMouseTrack = true;
	m_bHover = false;
	Invalidate();

	CButton::OnMouseLeave();
}
