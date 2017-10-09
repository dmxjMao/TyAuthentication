#pragma once


// CMyButton2
/*‘§∞∏≤Ω÷Ë
*/

class CMyButton2 : public CButton
{
	DECLARE_DYNAMIC(CMyButton2)

public:
	CMyButton2();
	CMyButton2(const std::shared_ptr<Image>& img1, const std::shared_ptr<Image>& img2);
	//CMyButton2(const CMyButton2&) {}
	virtual ~CMyButton2();

protected:
	std::shared_ptr<Image> m_img1 = nullptr;//Õº1
	std::shared_ptr<Image> m_img2 = nullptr;//Õº2

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


