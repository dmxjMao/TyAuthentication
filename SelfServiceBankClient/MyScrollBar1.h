#pragma once
//考虑用CScrollBar重绘

// CMyScrollBar1

class CMyScrollBar1 : public CStatic
{
	DECLARE_DYNAMIC(CMyScrollBar1)

public:
	CMyScrollBar1();
	virtual ~CMyScrollBar1();
	//设置父窗口、水平还是垂直
	inline void Set(CListCtrl* pParent, bool bHor = true) { 
		pList = pParent; m_bHorizontal = bHor;
	}
	inline UINT GetSize() { //获取尺寸（窄边）
		//m_bHorizontal ? m_imgH : m_imgW;
		return m_imgH;
	}
	//更新滑块位置
	void UpdateThumbPosition();

protected:
	bool m_bHorizontal = true;//是否是水平滚动条
	CListCtrl* pList = 0; //父窗口
	int nThumbTop = 36, nThumbLeft = 25;
	double dbThumbInterval = 0.0, dbThumbRemainder = 0.0;
	bool bMouseDownArrowUp = false, bMouseDownArrowDown = false;
	bool bMouseDownArrowRight = false, bMouseDownArrowLeft = false;
	bool bDragging = false;
	bool bMouseDown = false; //在滑块上
	
	//左右上下箭头、滑块。。。也可以自己画，中间的填充可以是图片拉伸、纯色、渐变。。。
	Image* m_imgLArrow, *m_imgRArrow, *m_imgHThumb, *m_imgHSpan;
	Image* m_imgUArrow, *m_imgDArrow, *m_imgVThumb;
	UINT m_imgW = 0, m_imgH = 0;//宽高

protected:
	void LimitThumbPosition();
	//void Draw();

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


