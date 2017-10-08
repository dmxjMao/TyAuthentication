#pragma once

/*
����ɫ����ͣɫ����������
���Դ��� ��
Ϊʲô����CButton����CMFCButton��
*/

// CMyStatic2

class CMyStatic2 : public CStatic
{
	DECLARE_DYNAMIC(CMyStatic2)

public:
	CMyStatic2();
	virtual ~CMyStatic2();
	inline void Set(bool bEnable = true, Color bg = Color(54, 132, 215), 
		Color hoverBG = Color(24, 100, 100), 
		Color text = Color(255, 255, 255)) {
		m_bEnable = bEnable;  m_clrBG = bg; m_clrHoverBG = hoverBG; m_clrText = text;
	}

protected:
	bool m_bEnable = true;
	Color m_clrBG = Color(54, 132, 215);//����ɫ
	Color m_clrHoverBG = Color(24, 100, 100);//��ͣ����ɫ
	Color m_clrText = Color(255,255,255);//�ı�ɫ
	Color m_clrGray = Color(125, 125, 125);//��ɫ
	//Color m_clrHoverText = Color(255, 255, 255);
	bool m_bMouseTrack = true;//׷�������ͣ
	bool m_bHover = false;//����Ƿ���ͣ
	//CRgn m_rgn;//��������

	DECLARE_MESSAGE_MAP()


	afx_msg void OnPaint();
	virtual void PreSubclassWindow();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();

private:
	//��Բ�Ǿ���
	GraphicsPath* MakeRoundRect(Point topLeft, Point bottomRight, INT percentageRounded);
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnStnClicked();
};


