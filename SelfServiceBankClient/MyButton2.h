#pragma once


// CMyButton2
/*预案步骤
*/

class CMyButton2 : public CButton
{
	DECLARE_DYNAMIC(CMyButton2)

public:
	CMyButton2();
	CMyButton2(const std::shared_ptr<Image>& img1, const std::shared_ptr<Image>& img2);
	//CMyButton2(const CMyButton2&) {}
	virtual ~CMyButton2();
	inline const CString& GetFullText() const { return m_str; }

protected:
	std::shared_ptr<Image> m_img1 = nullptr;//图1
	std::shared_ptr<Image> m_img2 = nullptr;//图2
	CString m_str;//全文本
	//CToolTipCtrl m_tt;//提示
	bool m_bMouseTrack = true, m_bHover = false;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	//afx_msg BOOL OnTtnNeedText(UINT id, NMHDR * pTTTStruct, LRESULT * pResult);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	//virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
};


