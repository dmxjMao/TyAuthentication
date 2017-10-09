#pragma once
#include "CommonDefine.h"  //struct
#include "afxwin.h"
#include "MyListCtrl1.h" //������֤��Ա
#include "MyStatic1.h" //��
#include "MyStatic2.h" //��ť

// CApplyRecordDlg dialog

class CApplyRecordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CApplyRecordDlg)

public:
	CApplyRecordDlg(CWnd* pParent = NULL);   // standard constructor
	CApplyRecordDlg(const CApplyRecordDlg&) {} //vector<CApplyRecordDlg>��Ҫ
	virtual ~CApplyRecordDlg();

	virtual BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ApplyRecordDlg };
#endif

protected:
	CRect m_rcInParent, m_rcClient/*, m_rcPerson*/;//�ڸ������е��������ꡢ�ͻ�����
	//������������
	std::shared_ptr<stApplyInfo> m_stApplyInfo = nullptr;
	//std::vector<stApplyPersonInfo> m_vecStPersonInfo;//������֤��Ա��Ϣ

	CStatic m_oVideo1;//��Ƶ
	CStatic m_oVideo2;
	CMyListCtrl1 m_oPersonInfo;  //������֤��Ա��Ϣ

	CMyStatic1 m_oPicDoor;//��

	CMyStatic2 m_oEmergency;//Ӧ������
	CMyStatic2 m_oGrant;//������Ȩ
	CMyStatic2 m_oOpen;//����
	CMyStatic2 m_oEnterMapLayer;//����ͼ��
	CMyStatic2 m_oLock;//����
	CMyStatic2 m_oRefuseOpen;//�ܾ�����
	CMyStatic2 m_oConfirm;//ȷ�ϲ��ر�

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

public:
	//��ȡ��Աm_stApplyInfo
	inline /*decltype(m_stApplyInfo)*/const std::shared_ptr<stApplyInfo>& 
		GetApplyInfo() const { return m_stApplyInfo; }
	inline void SetApplyInfo(const std::shared_ptr<stApplyInfo>& st) {
		m_stApplyInfo = st; 
		//Update();
	}
	//���öԻ����ڸ������е�������ΪCreate->OnInitDialog->SetWindowPos
	inline void SetRectInParent(const CRect& rc) { m_rcInParent = rc; }
	//ˢ����ʾ
	void Update();
	//��ť�һ�/���ô���
	void EnableButton(emButton em);

private:
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedEmergency();
};
