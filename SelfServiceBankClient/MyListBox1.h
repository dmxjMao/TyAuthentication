#pragma once

// CMyListBox1
/*��ߵ�������Ϣ
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
	//DRAWITEMSTRUCT m_disMouseHover;//�����ͣ��ṹ
	//UINT m_curItem;//��ǰ���������
	//DRAWITEMSTRUCT m_prevDIS;//֮ǰ��item
	//�����������ݣ�������������
	//std::shared_ptr<std::vector<stApplyInfo>> m_spVecItemData = nullptr;
	std::vector<std::shared_ptr<stApplyInfo>> m_vecApplyInfo;

	//�н��ߣ����ӵĿؼ�ͨ���߼������н�
	//����ʵ�֣�1��Observer��2��ֱ���ṩ�ӿڣ�
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


