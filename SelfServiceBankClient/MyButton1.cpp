// MyButton1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyButton1.h"


// CMyButton1
namespace {
	enum emCfg { emUnderline = 1, emFontsize, emBgcolor, emTextcolor, emMousetrack,
		emCfgBuff};//配置项
};

IMPLEMENT_DYNAMIC(CMyButton1, CButton)

CMyButton1::CMyButton1()
{
	//ui属性
	m_vecUICfg = { "underline","fontsize","bgcolor","textcolor","mousetrack" };
	//ui正则
	try {
		//1）\\s*任意空白；2）[-:,]名和值分隔符；
		std::string s = "\\s*[-:,=]\\s*";
		//char ch = '|';
		std::string pattern = "underline" + s + "(0|1)|" + //下划线
			"fontsize" + s + "([0-9]+)|" + //字体大小
			"bgcolor" + s + "(rgb[^;]+)|" + //背景色
			"textcolor" + s + "(rgb[^;]+)|" + //字体颜色	
			"mousetrack" + s + "(0|1)"//鼠标追踪
			;
		m_uiregex.assign(pattern, boost::regex_constants::icase);
	}
	catch (boost::regex_error e) {

	}
}


CMyButton1::~CMyButton1()
{
}


BEGIN_MESSAGE_MAP(CMyButton1, CButton)
	//ON_CONTROL_REFLECT(BN_CLICKED, &CMyButton1::OnBnClicked)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CMyButton1 message handlers




//void CMyButton1::OnBnClicked()
//{
//	//AfxMessageBox(_T("其他预案"));
//}


void CMyButton1::OnPaint()
{
	CPaintDC dc(this); 
	Graphics gh(dc.GetSafeHdc());

	//设置背景
	CRect rc;
	GetClientRect(&rc);
	Rect rcGdi(rc.left, rc.top, rc.right, rc.bottom);
	SolidBrush sbr(Color(123, 123, 0)/*m_clrBG*/);
	gh.FillRectangle(&sbr, rcGdi);

	//写文字
	CString str;
	GetWindowText(str);

	FontFamily ff(_T("微软雅黑"));
	Gdiplus::Font font(&ff, m_nFontSize * 1.0f, FontStyleRegular, UnitPixel);
	SolidBrush sbrText(m_clrText);
	StringFormat sf;
	//sf.SetAlignment(StringAlignmentCenter);//文本居中
	sf.SetLineAlignment(StringAlignmentCenter);//上下居中

	RectF rcGdiF(rcGdi.X * 1.0f, rcGdi.Y * 1.0f, rcGdi.Width * 1.0f, rcGdi.Height * 1.0f);
	//PointF pf(rcGdi.X * 1.0f, rcGdi.Y * 1.0f);
	gh.DrawString(str, -1, &font, rcGdiF, &sf, &sbrText);

	if (m_bUnderLine) {
		//下划线
		Pen pen(cstClrTitle);
		//RectF boundRect; //是边界，就是控件客户区
		//gh.MeasureString(str, -1, &font, rcGdiF, &boundRect);
		auto nTextH = font.GetHeight(0.0);//一行高度
		auto y = rcGdiF.Y + nTextH + 2;
		auto w = 12 * 1.0f/*px*/ * str.GetLength();

		gh.DrawLine(&pen, rcGdiF.X, y, rcGdiF.X + w, y);
	}

	//悬停
	if (m_bHover) {
		Pen pen(Color(255, 125, 125), 3.0f);
		rcGdi.Inflate(-1, -1);
		gh.DrawRectangle(&pen, rcGdi);
	}
}


//void CMyButton1::PreSubclassWindow()
//{
//	CButton::PreSubclassWindow();
//}


void CMyButton1::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{
}


void CMyButton1::OnMouseMove(UINT nFlags, CPoint point)
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
	}

	CButton::OnMouseMove(nFlags, point);
}


void CMyButton1::OnMouseHover(UINT nFlags, CPoint point)
{
	m_bHover = true;
	Invalidate();

	CButton::OnMouseHover(nFlags, point);
}


void CMyButton1::OnMouseLeave()
{
	m_bMouseTrack = true;
	m_bHover = false;
	Invalidate();

	CButton::OnMouseLeave();
}


bool CMyButton1::OnMatchUICfg(const boost::smatch& sm)
{
	//static int nCfgCnt = (int)m_vecUICfg.size();
	int i = 1; //sm[0]代表整个匹配
	for (; i < emCfgBuff; ++i) {
		if (sm[i].matched)
			break;
	}

	//emUnderline = 1, emFontsize, emBgcolor, emTextcolor, emMousetrack,
	const std::string str = sm[i].str();
	switch (i) {
	case emUnderline:
		m_bUnderLine = stoi(str) ? true : false; break;
	case emFontsize:
		m_nFontSize = stoi(str); break;
	case emBgcolor:
		break;
	}
	return true;
}