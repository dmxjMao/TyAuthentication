#pragma once


// CMyLogListCtrl
/*日志列表
表头
日志
*/

class CMyLogListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CMyLogListCtrl)

public:
	CMyLogListCtrl();
	virtual ~CMyLogListCtrl();
#ifdef _DEBUG
	bool Init(); //测试数据
#endif // _DEBUG

	

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();

};


