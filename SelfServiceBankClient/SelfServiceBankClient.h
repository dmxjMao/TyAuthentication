
// SelfServiceBankClient.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "CommonDefine.h"

// CSelfServiceBankClientApp:
// See SelfServiceBankClient.cpp for the implementation of this class
//

/*ZCMsgManager的观察者
*/
class CZCMsgObserver {
public:
	//通知
	virtual void Update(bool bOK, DWORD/*消息类型*/, DWORD/*消息ID*/, PBYTE/*消息内容*/) = 0;
	//异常通知  接口尽可能少，不然子类实现很麻烦
	//virtual void Abnormal() = 0;
};


class CLogDialog;
//struct S_New_UserInfo; //有typedef，造成重定义
//typedef struct S_New_UserInfo S_New_UserInfo;


class CSelfServiceBankClientApp : public CWinApp, public CZCMsgObserver
{
public:
	//using ZCMsgHandler = void(CSelfServiceBankClientApp::*)(PBYTE);
	CSelfServiceBankClientApp();

public:
	virtual BOOL InitInstance();
	//inline const std::shared_ptr<CLogDialog>& GetLogDlg() const { return m_oLogDlg; }
	//写日志
	void _cdecl WriteLog(severity_level level, const TCHAR* szMsg, ...);
	//消息通知
	virtual void Update(bool, DWORD, DWORD, PBYTE);
	//virtual void Abnormal();

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();

private:
	//初始化日志
	bool InitLog();
	
	//初始化ZCMsgManager消息处理函数
	void InitZCMsgHandler();
	//当前用户信息
	void ZCMsgCurrentUserInfo(PBYTE, DWORD);
	//创建或获取用户信息
	std::shared_ptr<stUserInfo>& CreateOrGetUserInfo(const CString& str);
	//用户详细信息
	void ZCMsgUserDetailInfo(PBYTE, DWORD);
	//用户权限信息
	void ZCMsgDisposalInfo(PBYTE, DWORD);
	//管辖人员信息
	void ZCMsgControledPersonInfo(PBYTE, DWORD);
	//管辖人员头像
	void ZCMsgControledHeadPic(PBYTE, DWORD);
	//部门信息
	void ZCMsgDepartmentInfo(PBYTE, DWORD);

	//std::shared_ptr<CLogDialog> m_oLogDlg = 0;//日志对话框

private:
	std::map<DWORD, void(CSelfServiceBankClientApp::*)(PBYTE, DWORD)> m_mapZCMsgHandler;//ZCMsgManager消息处理函数
	std::map<CString, std::shared_ptr<stUserInfo>> m_mapUserInfo;//用户详情信息
	CString m_strCurUserName; //当前用户名
	std::vector<std::shared_ptr<stControledPersonInfo>> m_vecControledPersonInfo;//管辖人员信息
	//std::vector<std::shared_ptr<TAGDOADEPARTMENTINFO_S>>

};

extern CSelfServiceBankClientApp theApp;



//全局类，后期作为theApp成员
struct StgCfg;
class CGobalVariable {
private:
	//GDI+初始化
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;

	CString m_strExePath;//exe路径
	//CString m_strStgCfgPath;//配置文档路径
	//std::vector<StgCfg*> m_vecCfg;//配置
	//HANDLE m_hEventReadStgCfg;//读取配置线程完成事件
	
	//const
	//字体
	//const FontFamily cstFontFamily = _T("微软雅黑");
	//const Gdiplus::Font cstFont = Gdiplus::Font(&cstFontFamily, 12, FontStyleRegular, UnitPixel);
	//const SolidBrush cstSolidBrushText = Color(125, 125, 125);

public:
	CGobalVariable();
	~CGobalVariable();
	bool Init();
	const CString& GetExePath() const { return m_strExePath; }
};
extern CGobalVariable g_GobalVariable; //全局变量

