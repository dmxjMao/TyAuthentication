#pragma once


// CMyLogListCtrl
/*��־�б�
��ͷ
��־
*/

class CMyLogListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CMyLogListCtrl)

public:
	CMyLogListCtrl();
	virtual ~CMyLogListCtrl();
#ifdef _DEBUG
	bool Init(); //��������
#endif // _DEBUG

	

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();

};


