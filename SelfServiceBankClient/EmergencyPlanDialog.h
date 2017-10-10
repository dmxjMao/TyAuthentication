#pragma once


// CEmergencyPlanDialog dialog
class CMyStatic3;
class CMyButton1;
class CMyButton2;
class CMyStatic1;
class CMyListBox2;
class CEmergencyPlanDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CEmergencyPlanDialog)

public:
	CEmergencyPlanDialog(CWnd* pParent = NULL);   // standard constructor
	CEmergencyPlanDialog(const std::shared_ptr<std::vector<stEmergPlan>>& sp, CWnd* pParent = NULL);
	virtual ~CEmergencyPlanDialog();
	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EmergencyPlan };
#endif

protected:
	std::shared_ptr<std::vector<stEmergPlan>> m_vecEmergPlan = nullptr;//Ԥ����Ϣ
	//�ؼ�
	CWnd* m_pParent = nullptr; //������
	std::shared_ptr<CMyStatic3> m_oName = nullptr;//Ԥ����
	std::shared_ptr<CMyButton1> m_oOther = nullptr;//����Ԥ��
	std::shared_ptr<CMyListBox2> m_oOtherLB = nullptr;//����Ԥ���б�
	std::vector<std::shared_ptr<CMyButton2>> m_vecStep;//Ԥ������
	std::shared_ptr<CMyButton1> m_oSubmit = nullptr;//�ύ
	std::shared_ptr<CMyStatic1> m_oCloseWindow = nullptr;//�رհ�ť

	std::shared_ptr<Image> m_img1 = nullptr;//ͼ1
	std::shared_ptr<Image> m_img2 = nullptr;//ͼ2
	CToolTipCtrl m_tt;//tooltip

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg BOOL OnTtnNeedText(UINT id, NMHDR * pTTTStruct, LRESULT * pResult);//��ʾ
	afx_msg void OnBtnClickedOtherEMPlan(); //�������Ԥ��
	afx_msg void OnOtherEMPlanSelchange();//ѡ������Ԥ��
	afx_msg void OnStnClickedClosewindow();//�رմ���
	virtual BOOL PreTranslateMessage(MSG* pMsg);//��ʾ

private:
	void DrawEMPlanStep(const stEmergPlan& st);//��Ԥ������

};
