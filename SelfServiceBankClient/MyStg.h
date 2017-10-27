#pragma once

/*结构化存储

记录日志
流类型：1，申请认证记录 不变流；2，可变流；3，辅助流；

流结构图
			root@(0)
		/			\
	辅助流~		申请记录流~

*/


//流类型
enum StgStreamType {
	StgAssist,//辅助流
	StgApply,//申请记录
	StgStreamTypeBuff
};

//基类：读写
struct StgBase{
	virtual void Read(LPSTREAM) = 0;
	virtual void Write(LPSTREAM) = 0;
};

//处置过程
struct stStgAction : StgBase {
	TCHAR szActType[32];//<操作名称
	char chActDate[32];//<操作时间
	TCHAR chActPerson[32];//<操作人
	
	void Read(LPSTREAM);
	void Write(LPSTREAM);
};

//申请记录索引
struct stStgApplyIndex : StgBase {
	int nApplyID = 0;//申请id
	int nPos = 0;//在流中的其实位置
	int nSize = 0;//记录大小

	void Read(LPSTREAM);
	void Write(LPSTREAM);
};

//流结构：辅助信息
struct stStgAssist : StgBase {
	unsigned long nCurApplyID = 0;//当前申请id

	stStgApplyIndex* pIndex = 0;
	int nIndexCnt = 0;

	void Read(LPSTREAM);
	void Write(LPSTREAM);
};

//流结构：申请日志
struct stStgApplyLog : StgBase{
	//基础信息
	unsigned long nApplyID = -1;//申请id
	TCHAR szDevName[32] = { 0 };//设备名
	TCHAR szAreaName[32] = { 0 };//所在网点名
	TCHAR szPartName[32] = { 0 };//所在部位名
	TCHAR szContactManName[64] = { 0 };//联系人名
	TCHAR szApplyTime[32] = { 0 };//<申请时间
	TCHAR szContactInfo[16] = { 0 };//<联系方式
	TCHAR szPlanName[64] = { 0 };//<预案名称
	UINT8 nMethod = -1;//<处置方式 -1-未处理  0-开门 1-申请授权 2-应急处置  3-申请特批 4-拒绝开门
	UINT8 nProcessType = -1;//<审核状态	1-通过 2-拒绝
	UINT8 nProcessStatus = 1;//<认证状态值 1-未处置 2-处置中 3-待审核 4-已处理 5-已失效
	//int nIsCollection;//<是否收藏 1-收藏 0-不
	UINT8 nPassStatus;//<通行情况	1-同意开门 2-拒绝进入
	//int nIsNormal; //<是否正常输入
	TCHAR szHandleMan[32] = { 0 };//<处置人
	TCHAR szApplyType[32] = { 0 };//<认证模式
	//TCHAR chDoorGUID[64] = { 0 };//<认证GUID

	//处置过程
	//执行预案、申请授权 + 开门/关门/上锁、拒绝开门。。。
	stStgAction* pAction = 0;
	UINT8 nActionNum = 0;
	//

	void Read(LPSTREAM);
	void Write(LPSTREAM);
};

//Stg操作类
struct stApplyInfo;

class CStgOperator {
public:
	//
	struct StreamNode {//stream节点属性
		StgStreamType em;//流类型
		CString name;//流名称
		//StgBase* cfg;//数据

		StreamNode(StgStreamType e, CString nm)
			: em(e), name(nm){}
	};
	
	enum LogType { Write, Update, LogTypeBuff }; //操作类型：写，更新

	//打开stg
	CStgOperator();
	//关闭stg
	~CStgOperator();
	
	//面向客户的接口
	//获取申请id
	unsigned long GetApplyID();
	//读取最近n条申请记录
	bool GetRecentNRecord(const int nCnt, std::vector<stApplyInfo>&);
	//写入申请日志
	void WriteApplyLog(const std::shared_ptr<stApplyInfo>&, bool bResumeOrDo = true);
	//修改申请日志
	void ModifyApplyLog(const std::shared_ptr<stApplyInfo>&/*成员名，值*/, bool bResumeOrDo = true);
	//上传日志到db（复核、值班长查看。。。）
	bool UploadApplyLog();

private:
	//处理继承关系
	//void TransformBase2Derived(StreamNode& node, void*& pv, ULONG& len);
	//创建默认结构
	bool CreateDefaultStg();

	//面向客户的接口
	

public:
	LogType m_emLogType = LogTypeBuff;//操作类型
	std::shared_ptr<stApplyInfo> m_pCurApplyInfo = 0;//当前申请记录
	CWinThread* m_pThread = 0; //CWinThread成员m_autodelete控制

private:
	bool m_bOpen = false;
	LPSTORAGE m_pRootStg = 0;	
	DWORD m_mode = STGM_READWRITE | STGM_SHARE_EXCLUSIVE;
};