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

	//读取pAction
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

	//写入pAction
	for (UINT8 i = 0; i < nActionNum; ++i) {
		pAction[i].Write(pStream);
	}

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

	m_pThread = AfxBeginThread(DealLogThread, this, 0, CREATE_SUSPENDED);
	//m_pThread->SuspendThread();
}

CStgOperator::~CStgOperator()
{
	m_pRootStg->Release();
}


//创建默认结构
bool CStgOperator::CreateDefaultStg()
{		
	//默认流
	static vector<StreamNode> vecStreamNode = {
		StreamNode(StgAssist, _T("辅助流")),
		StreamNode(StgApply, _T("申请记录流"))
	};

	assert(0 != m_pRootStg);

	DWORD mode = STGM_READWRITE | STGM_SHARE_EXCLUSIVE;
	HRESULT hr = S_OK;
	for (auto& node : vecStreamNode) {
		LPSTREAM pStream = nullptr;
		hr = m_pRootStg->CreateStream(node.name, mode, 0, 0, &pStream);
		if (FAILED(hr)) {
			theApp.WriteLog(error, _T("创建默认流失败！流名称：%s"), node.name);
			pStream->Release();
			return false;
		}
		pStream->Release();//一定要释放
	}
	return true;
}



//面向客户的接口
//获取申请id
unsigned long CStgOperator::GetApplyID()
{
	if (m_bOpen) {
		LPSTREAM pAssistStream = 0;

		HRESULT hr = m_pRootStg->OpenStream(_T("辅助流"), 0, m_mode, 0, &pAssistStream);
		if (FAILED(hr)) {
			theApp.WriteLog(error, _T("获取申请id时，打开辅助流失败！"));
			return 1;
		}

		stStgAssist st;
		st.Read(pAssistStream);

		pAssistStream->Release();
		return st.nCurApplyID;
	}

	return 1;
}

//读取最近n条申请记录
bool CStgOperator::GetRecentNRecord(const int nCnt, std::vector<stApplyInfo>& vecResult)
{
	if (m_bOpen) {
		LPSTREAM pRecordStream = 0;

		HRESULT hr = m_pRootStg->OpenStream(_T("申请记录流"), 0, m_mode, 0, &pRecordStream);
		if (FAILED(hr)) {
			theApp.WriteLog(warning, _T("打开辅助流或申请记录流失败！"));
			return false;
		}

		DWORD lastID = GetApplyID();
		int iBegin = 0, iCnt = 0; //开始获取记录的索引，获取条数
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

//写入申请日志，bResumeOrDo= true唤醒线程 false 写日志
void CStgOperator::WriteApplyLog(const std::shared_ptr<stApplyInfo>& sp, bool bResumeOrDo)
{
	if (bResumeOrDo) {
		m_emLogType = Write;
		m_pCurApplyInfo = sp;
		m_pThread->ResumeThread();
	}
	else { //写日志
		//获取辅助流，申请记录流
		if (m_bOpen) {
			LPSTREAM pAssistStream = 0, pRecordStream = 0;

			//调试的时候，当前目录在cpp下，而你创建.stg时是在exe目录下，所以这里会失败
			//如果创建默认结构时，没有pStream->Release()，这里也会失败；
			//调试中断了，shift + F5，m_pRootStg->Release没有调，也会失败;
			HRESULT hr1 = m_pRootStg->OpenStream(_T("辅助流"), 0, m_mode, 0, &pAssistStream);
			HRESULT hr2 = m_pRootStg->OpenStream(_T("申请记录流"), 0, m_mode, 0, &pRecordStream);
			if (FAILED(hr1) || FAILED(hr2)) {
				theApp.WriteLog(error, _T("打开辅助流或申请记录流失败！"));
				return;
			}

			stStgApplyLog stLog;

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

			//处置过程

			/*写入stg
			辅助流：记录当前申请id，
			申请记录流：最多记录10000条记录，查找按 nApplyID * 结构体大小
			*/
			stStgAssist st;
			st.nCurApplyID = sp->nApplyID;
			st.Write(pAssistStream);

			stLog.Write(pRecordStream);
			
			pAssistStream->Release(); 
			pRecordStream->Release();
		}//if (m_bOpen) {
	}//else { //写日志

}

//修改申请日志
void CStgOperator::ModifyApplyLog(const std::shared_ptr<stApplyInfo>& sp/*成员名，值*/, bool bResumeOrDo)
{
	
	m_emLogType = Update;
	m_pCurApplyInfo = sp;
	m_pThread->ResumeThread();

}

//上传日志到db（复核、值班长查看。。。）
bool CStgOperator::UploadApplyLog()
{
	return true;
}
