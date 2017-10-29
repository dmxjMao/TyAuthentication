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
	HRESULT hr = pStream->Read(pv, len, &ulRead);	\
	if(FAILED(hr))	\
		return false;	\

#define StgHelper_Write(T)	\
	void* pv = this;	\
	ULONG len = sizeof(stStgAction);	\
	ULONG ulWritten = 0;	\
	HRESULT hr = pStream->Write(pv, len, &ulWritten);	\
	if(FAILED(hr))	\
		return false;	\

//��������Ϣ
bool stStgAssist::Read(LPSTREAM pStream)
{
	StgHelper_Read(stStgAssist);
	return true;
}

bool stStgAssist::Write(LPSTREAM pStream)
{
	StgHelper_Write(stStgAssist);
	return true;
}


//���ö�����Ϣ
bool stStgAction::Read(LPSTREAM pStream)
{
	StgHelper_Read(stStgAction);
	return true;
}

bool stStgAction::Write(LPSTREAM pStream)
{
	StgHelper_Write(stStgAction);
	return true;
}


//�����¼��
bool stStgApplyLog::Read(LPSTREAM pStream)
{
	StgHelper_Read(stStgApplyLog);

	//��ȡpAction
	pAction = new stStgAction[nActionNum];
	for (UINT8 i = 0; i < nActionNum; ++i) {
		pAction[i].Read(pStream);
	}
	return true;
}

bool stStgApplyLog::Write(LPSTREAM pStream)
{
	StgHelper_Write(stStgApplyLog);

	//д��pAction
	for (UINT8 i = 0; i < nActionNum; ++i) {
		pAction[i].Write(pStream);
	}
	return true;
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
			pStg->AddApplyActionLog(pStg->m_dwCurApplyID, pStg->m_strCurAction, false);
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

	//��־�����߳�
	m_pThread = AfxBeginThread(DealLogThread, this, 0, CREATE_SUSPENDED);
	
}

CStgOperator::~CStgOperator()
{
	m_pRootStg->Release();
}


//����Ĭ�Ͻṹ
bool CStgOperator::CreateDefaultStg()
{		
	assert(0 != m_pRootStg);

	LPSTREAM pStream = 0;
	HRESULT hr = m_pRootStg->CreateStream(_T("������"), m_mode, 0, 0, &pStream);
	if (FAILED(hr)) {
		theApp.WriteLog(error, _T("����������ʧ�ܣ�"));
		return false;
	}
	pStream->Release();//һ��Ҫ�ͷ�

	return true;
}



//����ͻ��Ľӿ�
//��ȡ����id
WORD CStgOperator::GetApplyID()
{
	if (m_bOpen) {
		LPSTREAM pAssist = 0;

		HRESULT hr = m_pRootStg->OpenStream(_T("������"), 0, m_mode, 0, &pAssist);
		if (FAILED(hr)) {
			theApp.WriteLog(error, _T("��ȡ����idʱ���򿪸�����ʧ�ܣ�"));
			return 1;
		}

		WORD id = 0;
		pAssist->Read(&id, sizeof(id), 0);

		pAssist->Release();
		return id;
	}

	return 1;
}

//��ȡ�����¼
bool CStgOperator::GetApplyRecord(const WORD id, std::shared_ptr<stApplyInfo>& sp)
{
	LPSTREAM pAssist = 0, pRecord = 0;
	if (!OpenLogStream(pAssist, id, pRecord))
		return false;

	stStgApplyLog stLog;
	stLog.Read(pRecord);

	//����stApplyInfo

	return false;
	//return true;
}

//��ȡ���n�������¼
//bool CStgOperator::GetRecentNRecord(const int nCnt, std::vector<stApplyInfo>& vecResult)
//{
//	if (m_bOpen) {
//		LPSTREAM pRecordStream = 0;
//
//		HRESULT hr = m_pRootStg->OpenStream(_T("�����¼��"), 0, m_mode, 0, &pRecordStream);
//		if (FAILED(hr)) {
//			theApp.WriteLog(warning, _T("�򿪸������������¼��ʧ�ܣ�"));
//			return false;
//		}
//
//		DWORD lastID = GetApplyID();
//		int iBegin = 0, iCnt = 0; //��ʼ��ȡ��¼����������ȡ����
//		if (lastID < (DWORD)nCnt)
//			iBegin = 0, iCnt = lastID;
//		else
//			iBegin = lastID - 100, iCnt = 100;
//
//		for (int i = 0; i < iCnt; ++i) {
//			//pRecordStream->Seek()
//		}
//		pRecordStream->Release();
//	}
//
//	return true;
//}

//д��������־��bResumeOrDo= true�����߳� false д��־
void CStgOperator::WriteApplyLog(const std::shared_ptr<stApplyInfo>& sp, bool bResumeOrDo)
{
	if (bResumeOrDo) {
		m_emLogType = Write;
		m_pCurApplyInfo = sp;
		m_pThread->ResumeThread();
	}
	else { //д��־
		//�򿪸������������¼��
		LPSTREAM pAssist = 0, pRecord = 0;
		WORD id = sp->nApplyID;
		bool bSuccess = false;

		if (!OpenLogStream(pAssist, id, pRecord))
			return;

		//������־�ṹ
		stStgApplyLog stLog;
		SetLogStruct(sp, stLog);
		

		/*д��stg
		*/
		bSuccess = stLog.Write(pRecord);

		pRecord->Release();

		if (bSuccess) {//�ɹ�д��һ����־
			pAssist->Write(&id, sizeof(id), 0);
		}
		pAssist->Release();

	}//else { //д��־

}

//������봦�ö�����־
void CStgOperator::AddApplyActionLog(const WORD dwApplyID, const TCHAR* szActionName, bool bResumeOrDo)
{
	if (bResumeOrDo) {
		m_emLogType = Update;
		m_dwCurApplyID = dwApplyID;
		m_strCurAction = szActionName;
		m_pThread->ResumeThread();
	}
	else { //�޸���־
		LPSTREAM pAssist = 0, pRecord = 0;
		if (!OpenLogStream(pAssist, dwApplyID, pRecord))
			return;

		CTime tmCur = CTime::GetCurrentTime();
		CString strTmp = tmCur.Format(_T("%Y-%m-%d %H:%M:%S"));

		stStgAction stAction(szActionName, strTmp, theApp.m_strCurUserName);

		LARGE_INTEGER liMove = { 0 }; 
		pRecord->Seek(liMove, STREAM_SEEK_END, 0); //��λ�����
		if (stAction.Write(pRecord)) {
			liMove.LowPart = offsetof(stStgApplyLog, nActionNum);

			ULARGE_INTEGER uliPos = { 0 };
			pRecord->Seek(liMove, STREAM_SEEK_SET, &uliPos);
			//�ȶ���д
			UINT8 nActCnt = 0;
			pRecord->Read(&nActCnt, sizeof(nActCnt), 0);

			++nActCnt;
			pRecord->Write(&nActCnt, sizeof(nActCnt), 0);
		}

		pAssist->Release();
		pRecord->Release();
	}

}

//�ϴ���־��db�����ˡ�ֵ�೤�鿴��������
bool CStgOperator::UploadApplyLog(bool bClear)
{
	LPSTREAM pAssist = 0, pRecord = 0;
	if (!OpenLogStream(pAssist, 1, pRecord))
		return false;

	stStgAssist stAssist;
	stAssist.Read(pAssist);

	WORD nAID = stAssist.nCurApplyID;
	WORD nUID = stAssist.nUploadID;
	if (nAID != nUID) {
		//���µ������¼��
		WORD nCnt = nAID - nUID;
		for (WORD i = 0; i < nCnt; ++i) {
			//��ȡ��־���ݣ������ϴ��ӿ�
		}
	}

	if (bClear) {
		CString str;
		for (WORD i = 0; i < nAID; ++i) {
			str.Format(_T("�����¼��%d"), i);
			m_pRootStg->DestroyElement(str);
		}
	}

	pAssist->Release();
	if(!bClear)
		pRecord->Release();

	return true;
}


//����־��
bool CStgOperator::OpenLogStream(LPSTREAM& pAssist, const WORD id, LPSTREAM& pRecord)
{
	if (m_bOpen) {
		
		//���Ե�ʱ�򣬵�ǰĿ¼��cpp�£����㴴��.stgʱ����exeĿ¼�£����������ʧ��
		//�������Ĭ�Ͻṹʱ��û��pStream->Release()������Ҳ��ʧ�ܣ�
		//�����ж��ˣ�shift + F5��m_pRootStg->Releaseû�е���Ҳ��ʧ��;
		HRESULT hr = m_pRootStg->OpenStream(_T("������"), 0, m_mode, 0, &pAssist);
		if (FAILED(hr)) {
			theApp.WriteLog(error, _T("�򿪸�����ʧ�ܣ�"));
			return false;
		}

		CString strRecord;
		strRecord.Format(_T("�����¼��%d"), id);
		hr = m_pRootStg->OpenStream(strRecord, 0, m_mode, 0, &pRecord);
		if (FAILED(hr)) {
			hr = m_pRootStg->CreateStream(strRecord, m_mode, 0, 0, &pRecord);
			if (FAILED(hr)) {
				theApp.WriteLog(error, _T("���������¼��ʧ�ܣ�����id��%d"), id);
				return false;
			}
		}
		return true;
	}

	return false;
}


//����������־�ṹ
void CStgOperator::SetLogStruct(const std::shared_ptr<stApplyInfo>& sp, stStgApplyLog& stLog)
{
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

}