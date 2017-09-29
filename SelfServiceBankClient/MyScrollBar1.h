#pragma once


// CMyScrollBar1

class CMyScrollBar1 : public CStatic
{
	DECLARE_DYNAMIC(CMyScrollBar1)

public:
	CMyScrollBar1();
	virtual ~CMyScrollBar1();
	//���ø����ڡ�ˮƽ���Ǵ�ֱ
	inline void Set(CListCtrl* pParent, bool bHor = true) { 
		pList = pParent; m_bHorizontal = bHor;
	}
	UINT GetSize();//��ȡ�ߴ磨խ�ߣ�

protected:
	bool m_bHorizontal = true;//�Ƿ���ˮƽ������
	CListCtrl* pList = 0; //������
	int nThumbTop = 36, nThumbLeft = 25;
	double dbThumbInterval = 0.0, dbThumbRemainder = 0.0;
	bool bMouseDownArrowUp = false, bMouseDownArrowDown = false;
	bool bMouseDownArrowRight = false, bMouseDownArrowLeft = false;
	bool bDragging = false;
	bool bMouseDown = false;
	
	//�������¼�ͷ�����顣����Ҳ�����Լ������м����������ͼƬ���졢��ɫ�����䡣����
	Image* m_imgLArrow, *m_imgRArrow, *m_imgHThumb;
	Image* m_imgUArrow, *m_imgDArrow, *m_imgVThumb;

protected:
	void LimitThumbPosition();
	//void Draw();
	void UpdateThumbPosition();

	void ScrollDown();
	void ScrollUp();
	void PageUp();
	void PageDown();

	void ScrollLeft();
	void ScrollRight();
	void PageLeft();
	void PageRight();
	
	//afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);


	DECLARE_MESSAGE_MAP()

};


