#pragma once

// CMyListBox1
/*左边的网点信息
*/
class CSelfServiceBankClientDlg;
struct stApplyInfo;

class CMyListBox1 : public CListBox
{
	DECLARE_DYNAMIC(CMyListBox1)

public:
	//using ItemData = std::tuple<CString, int, CTime>;
	//typedef std::tuple<CString, int, CTime> ItemData;

	CMyListBox1();
	virtual ~CMyListBox1();
	//void MySetItemData(int, CString, int, CTime);
	//void MyInsertString(ItemData& t);
	//inline void MySetItemData(std::vector<stApplyInfo>& vec) { 
	//	m_spVecItemData = std::make_shared<decltype(vec)>(vec);
	//}
	inline void Set(CSelfServiceBankClientDlg* pMediator) {
		m_oMediator = pMediator;
	}
	void MyInsertString(const std::shared_ptr<stApplyInfo>&);

protected:
	//bool m_bMouseTrack = true, m_bMouseHover = false;
	//DRAWITEMSTRUCT m_disMouseHover;//鼠标悬停项结构
	//UINT m_curItem;//当前点击的区域
	//DRAWITEMSTRUCT m_prevDIS;//之前的item
	//共享申请数据，但不共享排序
	//std::shared_ptr<std::vector<stApplyInfo>> m_spVecItemData = nullptr;
	std::vector<std::shared_ptr<stApplyInfo>> m_vecApplyInfo;

	//中介者，复杂的控件通信逻辑交给中介
	//两种实现：1）Observer；2）直接提供接口；
	CSelfServiceBankClientDlg* m_oMediator;

	DECLARE_MESSAGE_MAP()
	//virtual void PreSubclassWindow();
	//virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	virtual void MeasureItem(LPMEASUREITEMSTRUCT /*lpMeasureItemStruct*/);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	//afx_msg void OnPaint();
	//afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	//afx_msg void OnMouseLeave();
	//virtual int CompareItem(LPCOMPAREITEMSTRUCT /*lpCompareItemStruct*/);
public:
	afx_msg void OnLbnSelchange();
};


