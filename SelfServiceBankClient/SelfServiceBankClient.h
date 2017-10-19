
// SelfServiceBankClient.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "ConnectAppProtocol.h" //结构体

// CSelfServiceBankClientApp:
// See SelfServiceBankClient.cpp for the implementation of this class
//

/*ZCMsgManager的观察者
*/
class CZCMsgObserver {
public:
	//通知
	virtual void Update(bool bOK, DWORD/*消息类型*/, DWORD/*消息ID*/, PBYTE/*消息内容*/, INT nMsgLen) = 0;
	//异常通知  接口尽可能少，不然子类实现很麻烦
	//virtual void Abnormal() = 0;
};


class CLogDialog;
//struct S_New_UserInfo; //有typedef，造成重定义
//typedef struct S_New_UserInfo S_New_UserInfo;
struct stUserInfo;
struct stCtrlPersonInfo;
struct stCtrlPlanInfo;
struct stACSHostInfo;
struct stEmergPlan;
struct stNode;
enum emNodeType;
class CGobalVariable;

class CSelfServiceBankClientApp : public CWinApp, public CZCMsgObserver
{
public:
	//using ZCMsgHandler = void(CSelfServiceBankClientApp::*)(PBYTE);
	CSelfServiceBankClientApp();
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//inline const std::shared_ptr<CLogDialog>& GetLogDlg() const { return m_oLogDlg; }
	//写日志
	void _cdecl WriteLog(severity_level level, const TCHAR* szMsg, ...);
	//消息通知
	virtual void Update(bool, DWORD, DWORD, PBYTE, INT);

	DECLARE_MESSAGE_MAP()
	
public:
	//使用vector是为了减少内存；使用map是1）消息机制整合相关信息较麻烦
	CString m_strCurUserName; //当前用户名
	std::map<CString, std::shared_ptr<stUserInfo>> m_mapUserInfo;//用户详情信息
	std::vector<std::shared_ptr<stCtrlPersonInfo>> m_vecCtrlPersonInfo;//管辖人员信息
	//std::vector<std::shared_ptr<TAGDOADEPARTMENTINFO_S>> m_vecDepartmentInfo;//部门信息
	std::map<UINT8, std::shared_ptr<stCtrlPlanInfo>> m_mapCtrlPlan;//策略信息<管控等级,策略结构>，由于消息来得恶心，为了方便起见使用了map，并且没有设置过就不发
	//std::vector<std::shared_ptr<stACSHostInfo>> m_vecACSHostInfo;//门禁主机信息，要整合管控等级，消息谁先到又不确定
	std::map<CString, std::shared_ptr<stACSHostInfo>> m_mapACSHostInfo;//门禁主机信息，主机名字不重复
	std::vector<std::shared_ptr<stEmergPlan>> m_vecEMPlanInfo;//预案信息
	std::map<emNodeType, std::vector<std::shared_ptr<stNode>>> m_mapNodeInfo;//节点信息
	std::shared_ptr<CGobalVariable> m_oGobal;//全局变量

private:
	//初始化日志
	bool InitLog();	
	//初始化ZCMsgManager消息处理函数
	void InitZCMsgHandler();
	//当前用户信息
	void ZCMsgCurrentUserInfo(PBYTE, DWORD, INT);
	//创建或获取用户信息
	std::shared_ptr<stUserInfo>& CreateOrGetUserInfo(const CString& str);
	//用户详细信息
	void ZCMsgUserDetailInfo(PBYTE, DWORD, INT);
	//用户权限信息
	void ZCMsgDisposalInfo(PBYTE, DWORD, INT);
	//区域信息
	void ZCMsgAreaInfo(PBYTE, DWORD, INT);
	//主机信息
	void ZCMsgDevHostInfo(PBYTE, DWORD, INT);
	//前端设备信息
	void ZCMsgDeviceInfo(PBYTE, DWORD, INT);
	//管辖人员信息
	void ZCMsgCtrlPersonInfo(PBYTE, DWORD, INT);
	//管辖人员头像
	void ZCMsgCtrlHeadPic(PBYTE, DWORD, INT);
	//部门信息
	void ZCMsgDepartmentInfo(PBYTE, DWORD, INT);
	//门禁主从关系
	void ZCMsgEntranceRelation(PBYTE, DWORD, INT);
	//所有门禁主机信息
	void ZCMsgACSHostInfo(PBYTE, DWORD, INT);
	//管控等级信息
	void ZCMsgCtrlLevelInfo(PBYTE, DWORD, INT);
	//管控策略信息
	void ZCMsgCtrlPlanInfo(PBYTE, DWORD, INT);
	//部位信息
	void ZCMsgKeypartInfo(PBYTE, DWORD, INT);
	//门禁主机关联摄像头设备
	void ZCMsgACSHostLinkCameraInfo(PBYTE, DWORD, INT);
	//门禁主机关联对讲设备
	void ZCMsgACSHostLinkTalkInfo(PBYTE, DWORD, INT);
	//赋值关联设备
	//shared_ptr<stACSHostInfo>& ZCMsgHelper_SetACSHostRelDeviceInfo(const int nDevID);
	//所有处置人信息
	void ZCMsgHandlerInfo(PBYTE, DWORD, INT);
	//用户门禁摄像头关联信息
	void ZCMsgDoorRelationInfo(PBYTE, DWORD, INT);
	//所有预案信息
	void ZCMsgEMPlanInfo(PBYTE, DWORD, INT);
	//std::shared_ptr<CLogDialog> m_oLogDlg = 0;//日志对话框


	//服务库回调
	static void __stdcall ServerExcepCallBack(unsigned long dwExceptMsg, long lHandle, unsigned long dwUser);
	static void __stdcall MsgCallBackFunc(long lUserID, DWORD MsgType, BYTE *chMsgBuf, DWORD dwBufSize,
		unsigned int nMsgID, DWORD dwUser);

private:
	std::map<DWORD, void(CSelfServiceBankClientApp::*)(PBYTE, DWORD, INT)> m_mapZCMsgHandler;//ZCMsgManager消息处理函数

};

extern CSelfServiceBankClientApp theApp;



//全局变量
class CGobalVariable {
private:
	//GDI+初始化
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;
	CString strExePath;//exe路径
	
	//boost::log::sources::wseverity_logger< severity_level > m_slog;//级别日志器
	//CString m_strStgCfgPath;//配置文档路径
	//std::vector<StgCfg*> m_vecCfg;//配置
	//HANDLE m_hEventReadStgCfg;//读取配置线程完成事件
	
public:
	long nCMSHander = -1;//登录中心管理服务器成功返回的操作句柄
	/*UI部分，后期作为配置项
	*/
	const Color cstClrTitle = Color(54, 132, 215);//标题颜色
	const int cstnTitleHeight = 30;//标题高度

	//默认字体  不成功，因为GDI+还没有初始化
	//std::shared_ptr<FontFamily> cstFontFamily;
	//std::shared_ptr<Gdiplus::Font> cstFont = 0; //字体大小，构造私有
	//Gdiplus::Font* cstFont = 0;//字体大小

	//std::shared_ptr<SolidBrush> cstSolidBrushText = 0;//文本颜色
	//SolidBrush* cstSolidBrushText = 0;  Clone返回的是Brush*
	//static FontFamily cstFontFamily = (_T("微软雅黑"));

public:
	CGobalVariable();
	~CGobalVariable();
	bool Init();
	inline const CString& GetExePath() const { return strExePath; }
	//inline const long GetCMSHander() const { return nCMSHander; }
	//inline decltype(m_slog)& GetLog() { return m_slog; }
};




/*UI配置类
*/
class CUICfg {
public:
	//设置ui属性
	void SetUICfg(std::string s);

private:
	//匹配到ui属性
	virtual bool OnMatchUICfg(const boost::smatch& what) = 0;
	//是否有ui属性
	bool HasUICfg(const std::string& str);

protected:
	//构造函数初始化
	std::vector<std::string> m_vecUICfg;//ui配置
	boost::regex m_uiregex;//ui正则
};


