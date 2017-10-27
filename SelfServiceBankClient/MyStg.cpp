#include "stdafx.h"
#include "MyStg.h"
#include "SelfServiceBankClient.h"//theApp
#include "MyCommonDefine.h"//stApplyInfo

using std::vector;
using std::shared_ptr;
using std::placeholders::_1;

#define StgHelper_Read(T)	\
	void* pv = this;	\
	ULONG len = sizeof(T);	\
	ULONG ulRead = 0;	\
	HRESULT hr = pStream->Read(pv, len, &ulRead);	

#define StgHelper_Write(T)	\
	void* pv = this;	\
	ULONG len = sizeof(stStgAction);	\
	ULONG ulWritten = 0;	\
	HRESULT hr = pStream->Write(pv, len, &ulWritten);	


void stStgApplyIndex::Read(LPSTREAM pStream)
{
	void* pv = this;
	ULONG len = sizeof(stStgApplyIndex);

	ULONG ulRead = 0;
	HRESULT hr = pStream->Read(pv, len, &ulRead);
	//if (FAILED(hr)) return;
}

void stStgApplyIndex::Write(LPSTREAM pStream)
{
	void* pv = this;
	ULONG len = sizeof(stStgApplyIndex);

	ULONG ulWritten = 0;
	HRESULT hr = pStream->Write(pv, len, &ulWritten);
	//if (FAILED(hr)) return;
}


void stStgAssist::Read(LPSTREAM pStream)
{
	void* pv = this;
	ULONG len = sizeof(stStgAssist);

	ULONG ulRead = 0;
	HRESULT hr = pStream->Read(pv, len, &ulRead);
	//if (FAILED(hr)) return;

	
}

void stStgAssist::Write(LPSTREAM pStream)
{
	void* pv = this;
	ULONG len = sizeof(stStgAssist);

	ULONG ulWritten = 0;
	HRESULT hr = pStream->Write(pv, len, &ulWritten);
	//if (FAILED(hr)) return;
}



void stStgAction::Read(LPSTREAM pStream)
{
	StgHelper_Read(stStgAction);
}

void stStgAction::Write(LPSTREAM pStream)
{
	StgHelper_Write(stStgAction);
}


void stStgApplyLog::Read(LPSTREAM pStream)
{
	void* pv = this;
	ULONG len = sizeof(stStgApplyLog);

	ULONG ulRead = 0;
	HRESULT hr = pStream->Read(pv, len, &ulRead);
	if (FAILED(hr)) return;

	//��ȡpAction
	pAction = new stStgAction[nActionNum];
	for (UINT8 i = 0; i < nActionNum; ++i) {
		pAction[i].Read(pStream);
	}
}

void stStgApplyLog::Write(LPSTREAM pStream)
{
	void* pv = this;
	ULONG len = sizeof(stStgApplyLog);

	ULONG ulWritten = 0;
	HRESULT hr = pStream->Write(pv, len, &ulWritten);
	if (FAILED(hr)) return;

	//д��pAction
	for (UINT8 i = 0; i < nActionNum; ++i) {
		pAction[i].Write(pStream);
	}

}

//������־�߳�
UINT DealLogThread(LPVOID lpParam)
{
	CStgOperator* pStg = (CStgOperator*)lpParam;

	while (1) {
		switch (pStg->m_emLogType)
		{
		case CStgOperator::Write:
			pStg->WriteApplyLog(pStg->m_pCurApplyInfo, false);
			break;
		case CStgOperator::Update:
			pStg->ModifyApplyLog(pStg->m_pCurApplyInfo, false);
			break;
		default:
			break;
		}
		pStg->m_pThread->SuspendThread();
	}

	return TRUE;
}

CStgOperator::CStgOperator()
{
	//�򿪸����ĵ�
	bool bRet = true;
	CString strStgFilePath(theApp.m_oGobal->GetExePath());

#ifdef DEBUG
	strStgFilePath = _T("STGCFG.stg");
#else
	strStgFilePath += _T("STGCFG.stg");
#endif // DEBUG

	bRet = (S_OK == ::StgOpenStorage(strStgFilePath, 0, m_mode, 0, 0, &m_pRootStg));
	if ( !bRet ) {//ʧ�ܾʹ���
		if (S_OK != ::StgCreateDocfile(strStgFilePath, m_mode, 0, &m_pRootStg)) {
			theApp.WriteLog(error, _T("�����ṹ���洢ʧ�ܣ�"));
			return;
		}

		//����Ĭ��stg�ṹ
		if (!CreateDefaultStg()) {
			theApp.WriteLog(error, _T("����Ĭ��stg�ṹʧ�ܣ�"));
			return;
		}
	}

	m_bOpen = true;

	m_pThread = AfxBeginThread(DealLogThread, this, 0, CREATE_SUSPENDED);
	//m_pThread->SuspendThread();
}

CStgOperator::~CStgOperator()
{
	m_pRootStg->Release();
}


//����Ĭ�Ͻṹ
bool CStgOperator::CreateDefaultStg()
{		
	//Ĭ����
	static vector<StreamNode> vecStreamNode = {
		StreamNode(StgAssist, _T("������")),
		StreamNode(StgApply, _T("�����¼��"))
	};

	assert(0 != m_pRootStg);

	DWORD mode = STGM_READWRITE | STGM_SHARE_EXCLUSIVE;
	HRESULT hr = S_OK;
	for (auto& node : vecStreamNode) {
		LPSTREAM pStream = nullptr;
		hr = m_pRootStg->CreateStream(node.name, mode, 0, 0, &pStream);
		if (FAILED(hr)) {
			theApp.WriteLog(error, _T("����Ĭ����ʧ�ܣ������ƣ�%s"), node.name);
			pStream->Release();
			return false;
		}
		pStream->Release();//һ��Ҫ�ͷ�
	}
	return true;
}



//����ͻ��Ľӿ�
//��ȡ����id
unsigned long CStgOperator::GetApplyID()
{
	if (m_bOpen) {
		LPSTREAM pAssistStream = 0;

		HRESULT hr = m_pRootStg->OpenStream(_T("������"), 0, m_mode, 0, &pAssistStream);
		if (FAILED(hr)) {
			theApp.WriteLog(error, _T("��ȡ����idʱ���򿪸�����ʧ�ܣ�"));
			return 1;
		}

		stStgAssist st;
		st.Read(pAssistStream);

		pAssistStream->Release();
		return st.nCurApplyID;
	}

	return 1;
}

//��ȡ���n�������¼
bool CStgOperator::GetRecentNRecord(const int nCnt, std::vector<stApplyInfo>& vecResult)
{
	if (m_bOpen) {
		LPSTREAM pRecordStream = 0;

		HRESULT hr = m_pRootStg->OpenStream(_T("�����¼��"), 0, m_mode, 0, &pRecordStream);
		if (FAILED(hr)) {
			theApp.WriteLog(warning, _T("�򿪸������������¼��ʧ�ܣ�"));
			return false;
		}

		DWORD lastID = GetApplyID();
		int iBegin = 0, iCnt = 0; //��ʼ��ȡ��¼����������ȡ����
		if (lastID < (DWORD)nCnt)
			iBegin = 0, iCnt = lastID;
		else
			iBegin = lastID - 100, iCnt = 100;

		for (int i = 0; i < iCnt; ++i) {
			//pRecordStream->Seek()
		}
	}

	return true;
}

//д��������־��bResumeOrDo= true�����߳� false д��־
void CStgOperator::WriteApplyLog(const std::shared_ptr<stApplyInfo>& sp, bool bResumeOrDo)
{
	if (bResumeOrDo) {
		m_emLogType = Write;
		m_pCurApplyInfo = sp;
		m_pThread->ResumeThread();
	}
	else { //д��־
		//��ȡ�������������¼��
		if (m_bOpen) {
			LPSTREAM pAssistStream = 0, pRecordStream = 0;

			//���Ե�ʱ�򣬵�ǰĿ¼��cpp�£����㴴��.stgʱ����exeĿ¼�£����������ʧ��
			//�������Ĭ�Ͻṹʱ��û��pStream->Release()������Ҳ��ʧ�ܣ�
			//�����ж��ˣ�shift + F5��m_pRootStg->Releaseû�е���Ҳ��ʧ��;
			HRESULT hr1 = m_pRootStg->OpenStream(_T("������"), 0, m_mode, 0, &pAssistStream);
			HRESULT hr2 = m_pRootStg->OpenStream(_T("�����¼��"), 0, m_mode, 0, &pRecordStream);
			if (FAILED(hr1) || FAILED(hr2)) {
				theApp.WriteLog(error, _T("�򿪸������������¼��ʧ�ܣ�"));
				return;
			}

			stStgApplyLog stLog;

			stLog.nApplyID = sp->nApplyID;//����id
			_tcscpy_s(stLog.szDevName, sp->strDevName);//�豸��
			_tcscpy_s(stLog.szAreaName, sp->strWebSiteName);//����������
			_tcscpy_s(stLog.szPartName, sp->strPartName);//���ڲ�λ��

			const auto& vecArea = theApp.m_mapNodeInfo[AreaNode];
			auto itArea = std::find_if(vecArea.begin(), vecArea.end(),
				std::bind(lambda_FindNodeByName, _1, sp->strWebSiteName));

			if (vecArea.end() != itArea) {
				auto& pInfo = (shared_ptr<stArea>&)(*itArea);
				CString str1(pInfo->strContactManName.c_str());
				_tcscpy_s(stLog.szContactManName, str1);//��ϵ����

				CString str2(pInfo->strContactInfo.c_str());
				_tcscpy_s(stLog.szContactInfo, str2);//<��ϵ��ʽ
			}

			CString strTime = sp->tmApply.Format(_T("%Y-%m-%d %H:%M:%S"));
			_tcscpy_s(stLog.szApplyTime, strTime);//<����ʱ��

			const auto& spCtrlPlan = theApp.GetCtrlPlanInfo(sp->nImportance);
			CString strEMPlanName(spCtrlPlan->szEMPlanName);
			_tcscpy_s(stLog.szPlanName, strEMPlanName);//<Ԥ������

			_tcscpy_s(stLog.szHandleMan, theApp.m_strCurUserName);//������

			//��֤ģʽ
			_stprintf_s(stLog.szApplyType, _countof(stLog.szApplyType),
				_T("%d��%s+%d��%s+%s"), spCtrlPlan->nDoor1Num,
				1 == spCtrlPlan->nDoor1Type ? _T("ָ��") : _T("ˢ��"),
				spCtrlPlan->nDoor2Num, 1 == spCtrlPlan->nDoor2Type ? _T("ָ��") : _T("ˢ��"),
				_T("������Ȩ"));

			//���ù���

			/*д��stg
			����������¼��ǰ����id��
			�����¼��������¼10000����¼�����Ұ� nApplyID * �ṹ���С
			*/
			stStgAssist st;
			st.nCurApplyID = sp->nApplyID;
			st.Write(pAssistStream);

			stLog.Write(pRecordStream);
			
			pAssistStream->Release(); 
			pRecordStream->Release();
		}//if (m_bOpen) {
	}//else { //д��־

}

//�޸�������־
void CStgOperator::ModifyApplyLog(const std::shared_ptr<stApplyInfo>& sp/*��Ա����ֵ*/, bool bResumeOrDo)
{
	
	m_emLogType = Update;
	m_pCurApplyInfo = sp;
	m_pThread->ResumeThread();

}

//�ϴ���־��db�����ˡ�ֵ�೤�鿴��������
bool CStgOperator::UploadApplyLog()
{
	return true;
}
