// MyListCtrl1.cpp : implementation file
//

#include "stdafx.h"
#include "SelfServiceBankClient.h"
#include "MyListCtrl1.h"

/*
�Ի��б��
��дDrawItem��MeasureItem����ʽҪOWNDRAW...
��DrawItem֮ǰ���յ�Measure��߶ȵ���Ϣ�������ʽ��fix�ģ���ֻ��һ�Σ�
*/

// CMyListCtrl1

IMPLEMENT_DYNAMIC(CMyListCtrl1, CListCtrl)

CMyListCtrl1::CMyListCtrl1()
{

}

CMyListCtrl1::~CMyListCtrl1()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl1, CListCtrl)
END_MESSAGE_MAP()



// CMyListCtrl1 message handlers




void CMyListCtrl1::PreSubclassWindow()
{
	//������ʧȥ����Ҳѡ����ͣ������˫����
	ModifyStyle(LVS_SORTASCENDING, LVS_SHOWSELALWAYS);
	SetExtendedStyle(GetExtendedStyle() | LVS_EX_ONECLICKACTIVATE
		| LVS_EX_DOUBLEBUFFER);

	CListCtrl::PreSubclassWindow();
}
