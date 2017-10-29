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

//辅助流信息
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


//处置动作信息
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


//申请记录流
bool stStgApplyLog::Read(LPSTREAM pStream)
{
	StgHelper_Read(stStgApplyLog);

	//读取pAction
	pAction = new stStgAction[nActionNum];
	for (UINT8 i = 0; i < nActionNum; ++i) {
		pAction[i].Read(pStream);
	}
	return true;
}

bool stStgApplyLog::Write(LPSTREAM pStream)
{
	StgHelper_Write(stStgApplyLog);

	//写入pAction
	for (UINT8 i = 0; i < nActionNum; ++i) {
		pAction[i].Write(pStream);
	}
	return true;
}

//处理日志线程
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
	//打开复合文档
	bool bRet = true;
	CString strStgFilePath(theApp.m_oGobal->GetExePath());

#ifdef DEBUG
	strStgFilePath = _T("STGCFG.stg");
#else
	strStgFilePath += _T("STGCFG.stg");
#endif // DEBUG

	bRet = (S_OK == ::StgOpenStorage(strStgFilePath, 0, m_mode, 0, 0, &m_pRootStg));
	if ( !bRet ) {//失败就创建
		if (S_OK != ::StgCreateDocfile(strStgFilePath, m_mode, 0, &m_pRootStg)) {
			theApp.WriteLog(error, _T("创建结构化存储失败！"));
			return;
		}

		//创建默认stg结构
		if (!CreateDefaultStg()) {
			theApp.WriteLog(error, _T("创建默认stg结构失败！"));
			return;
		}
	}

	m_bOpen = true;

	//日志处理线程
	m_pThread = AfxBeginThread(DealLogThread, this, 0, CREATE_SUSPENDED);
	
}

CStgOperator::~CStgOperator()
{
	m_pRootStg->Release();
}


//创建默认结构
bool CStgOperator::CreateDefaultStg()
{		
	assert(0 != m_pRootStg);

	LPSTREAM pStream = 0;
	HRESULT hr = m_pRootStg->CreateStream(_T("辅助流"), m_mode, 0, 0, &pStream);
	if (FAILED(hr)) {
		theApp.WriteLog(error, _T("创建辅助流失败！"));
		return false;
	}
	pStream->Release();//一定要释放

	return true;
}



//面向客户的接口
//获取申请id
WORD CStgOperator::GetApplyID()
{
	if (m_bOpen) {
		LPSTREAM pAssist = 0;

		HRESULT hr = m_pRootStg->OpenStream(_T("辅助流"), 0, m_mode, 0, &pAssist);
		if (FAILED(hr)) {
			theApp.WriteLog(error, _T("获取申请id时，打开辅助流失败！"));
			return 1;
		}

		WORD id = 0;
		pAssist->Read(&id, sizeof(id), 0);

		pAssist->Release();
		return id;
	}

	return 1;
}

//获取申请记录
bool CStgOperator::GetApplyRecord(const WORD id, std::shared_ptr<stApplyInfo>& sp)
{
	LPSTREAM pAssist = 0, pRecord = 0;
	if (!OpenLogStream(pAssist, id, pRecord))
		return false;

	stStgApplyLog stLog;
	stLog.Read(pRecord);

	//构造stApplyInfo

	return false;
	//return true;
}

//读取最近n条申请记录
//bool CStgOperator::GetRecentNRecord(const int nCnt, std::vector<stApplyInfo>& vecResult)
//{
//	if (m_bOpen) {
//		LPSTREAM pRecordStream = 0;
//
//		HRESULT hr = m_pRootStg->OpenStream(_T("申请记录流"), 0, m_mode, 0, &pRecordStream);
//		if (FAILED(hr)) {
//			theApp.WriteLog(warning, _T("打开辅助流或申请记录流失败！"));
//			return false;
//		}
//
//		DWORD lastID = GetApplyID();
//		int iBegin = 0, iCnt = 0; //开始获取记录的索引，获取条数
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

//写入申请日志，bResumeOrDo= true唤醒线程 false 写日志
void CStgOperator::WriteApplyLog(const std::shared_ptr<stApplyInfo>& sp, bool bResumeOrDo)
{
	if (bResumeOrDo) {
		m_emLogType = Write;
		m_pCurApplyInfo = sp;
		m_pThread->ResumeThread();
	}
	else { //写日志
		//打开辅助流，申请记录流
		LPSTREAM pAssist = 0, pRecord = 0;
		WORD id = sp->nApplyID;
		bool bSuccess = false;

		if (!OpenLogStream(pAssist, id, pRecord))
			return;

		//构造日志结构
		stStgApplyLog stLog;
		SetLogStruct(sp, stLog);
		

		/*写入stg
		*/
		bSuccess = stLog.Write(pRecord);

		pRecord->Release();

		if (bSuccess) {//成功写入一条日志
			pAssist->Write(&id, sizeof(id), 0);
		}
		pAssist->Release();

	}//else { //写日志

}

//添加申请处置动作日志
void CStgOperator::AddApplyActionLog(const WORD dwApplyID, const TCHAR* szActionName, bool bResumeOrDo)
{
	if (bResumeOrDo) {
		m_emLogType = Update;
		m_dwCurApplyID = dwApplyID;
		m_strCurAction = szActionName;
		m_pThread->ResumeThread();
	}
	else { //修改日志
		LPSTREAM pAssist = 0, pRecord = 0;
		if (!OpenLogStream(pAssist, dwApplyID, pRecord))
			return;

		CTime tmCur = CTime::GetCurrentTime();
		CString strTmp = tmCur.Format(_T("%Y-%m-%d %H:%M:%S"));

		stStgAction stAction(szActionName, strTmp, theApp.m_strCurUserName);

		LARGE_INTEGER liMove = { 0 }; 
		pRecord->Seek(liMove, STREAM_SEEK_END, 0); //定位到最后
		if (stAction.Write(pRecord)) {
			liMove.LowPart = offsetof(stStgApplyLog, nActionNum);

			ULARGE_INTEGER uliPos = { 0 };
			pRecord->Seek(liMove, STREAM_SEEK_SET, &uliPos);
			//先读再写
			UINT8 nActCnt = 0;
			pRecord->Read(&nActCnt, sizeof(nActCnt), 0);

			++nActCnt;
			pRecord->Write(&nActCnt, sizeof(nActCnt), 0);
		}

		pAssist->Release();
		pRecord->Release();
	}

}

//上传日志到db（复核、值班长查看。。。）
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
		//有新的申请记录了
		WORD nCnt = nAID - nUID;
		for (WORD i = 0; i < nCnt; ++i) {
			//获取日志内容，请求上传接口
		}
	}

	if (bClear) {
		CString str;
		for (WORD i = 0; i < nAID; ++i) {
			str.Format(_T("申请记录流%d"), i);
			m_pRootStg->DestroyElement(str);
		}
	}

	pAssist->Release();
	if(!bClear)
		pRecord->Release();

	return true;
}


//打开日志流
bool CStgOperator::OpenLogStream(LPSTREAM& pAssist, const WORD id, LPSTREAM& pRecord)
{
	if (m_bOpen) {
		
		//调试的时候，当前目录在cpp下，而你创建.stg时是在exe目录下，所以这里会失败
		//如果创建默认结构时，没有pStream->Release()，这里也会失败；
		//调试中断了，shift + F5，m_pRootStg->Release没有调，也会失败;
		HRESULT hr = m_pRootStg->OpenStream(_T("辅助流"), 0, m_mode, 0, &pAssist);
		if (FAILED(hr)) {
			theApp.WriteLog(error, _T("打开辅助流失败！"));
			return false;
		}

		CString strRecord;
		strRecord.Format(_T("申请记录流%d"), id);
		hr = m_pRootStg->OpenStream(strRecord, 0, m_mode, 0, &pRecord);
		if (FAILED(hr)) {
			hr = m_pRootStg->CreateStream(strRecord, m_mode, 0, 0, &pRecord);
			if (FAILED(hr)) {
				theApp.WriteLog(error, _T("创建申请记录流失败！申请id：%d"), id);
				return false;
			}
		}
		return true;
	}

	return false;
}


//构造申请日志结构
void CStgOperator::SetLogStruct(const std::shared_ptr<stApplyInfo>& sp, stStgApplyLog& stLog)
{
	stLog.nApplyID = sp->nApplyID;//申请id
	_tcscpy_s(stLog.szDevName, sp->strDevName);//设备名
	_tcscpy_s(stLog.szAreaName, sp->strWebSiteName);//所在网点名
	_tcscpy_s(stLog.szPartName, sp->strPartName);//所在部位名

	const auto& vecArea = theApp.m_mapNodeInfo[AreaNode];
	auto itArea = std::find_if(vecArea.begin(), vecArea.end(),
		std::bind(lambda_FindNodeByName, _1, sp->strWebSiteName));

	if (vecArea.end() != itArea) {
		auto& pInfo = (shared_ptr<stArea>&)(*itArea);
		CString str1(pInfo->strContactManName.c_str());
		_tcscpy_s(stLog.szContactManName, str1);//联系人名

		CString str2(pInfo->strContactInfo.c_str());
		_tcscpy_s(stLog.szContactInfo, str2);//<联系方式
	}

	CString strTime = sp->tmApply.Format(_T("%Y-%m-%d %H:%M:%S"));
	_tcscpy_s(stLog.szApplyTime, strTime);//<申请时间

	const auto& spCtrlPlan = theApp.GetCtrlPlanInfo(sp->nImportance);
	CString strEMPlanName(spCtrlPlan->szEMPlanName);
	_tcscpy_s(stLog.szPlanName, strEMPlanName);//<预案名称

	_tcscpy_s(stLog.szHandleMan, theApp.m_strCurUserName);//处置人

														  //认证模式
	_stprintf_s(stLog.szApplyType, _countof(stLog.szApplyType),
		_T("%d人%s+%d人%s+%s"), spCtrlPlan->nDoor1Num,
		1 == spCtrlPlan->nDoor1Type ? _T("指纹") : _T("刷卡"),
		spCtrlPlan->nDoor2Num, 1 == spCtrlPlan->nDoor2Type ? _T("指纹") : _T("刷卡"),
		_T("中心授权"));

}