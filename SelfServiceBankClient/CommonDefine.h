#pragma once


/*��������*/


/*���������
��ɫ
�߶�
*/
const Color cstClrTitle = Color(54, 132, 215);
const int cstnTitleHeight = 25;




/*�ṹ��
*/
/*������֤��Ա��Ϣ
��������ơ���·��Ƶ��������֤��Ա��Ϣ����Ƭ����λ�����ࣩ��������֤ʱ�䣨������ʱ���룩
���紫�䣻֧�ֱ��ش洢��
*/
struct stApplyPersonInfo {
	//��������Ա��Ϣ������CApplyRecordDlg
	//CString strWebSiteName;//��������
	//std::vector<CString> vecVideoStr;//��Ƶ
	CString strPic;//��Ƭ
	CString strOffice;//��λ
	CString strCategory;//����
	CTime tmApply;//������֤ʱ�䣬CString����תCTime

	stApplyPersonInfo(/*CString wsName, std::vector<CString> vec, */CString pic,
		CString office, CString cate, CTime tm) 
		: /*strWebSiteName(wsName), vecVideoStr(vec), */strPic(pic), 
		strOffice(office), strCategory(cate), tmApply(tm) {}
};

