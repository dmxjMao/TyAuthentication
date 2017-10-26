/**
* @file ZCProtocol.h 
*
* @brief 众绎客户端各模块交互协议宏定义
* 
* @version 1.0.0.1
*
* @author gaoxiaoliang@typrotech.com
*/

#ifndef TY_ZCPROTOCOL_H
#define TY_ZCPROTOCOL_H

#include "ZCErrorCode.h"
#include "ConnectAppProtocol.h"


/************************************************************************/
/*                          消息结构定义                                */
/************************************************************************/
/** @defgroup ZCMsgHeadDefine 消息协议头部结构定义      
 * 定义每个通信消息的头部必有信息。
 * @{
 */
 
/** 
 * @brief 消息协议头部结构定义
 *
 * 该结构是每个通信消息的头部必有信息，总长度20字节。
 */
typedef struct
{
	WORD   wProtocolVersion;    ///<协议版本           @note 目前版本值为0
	WORD   wReserved;           ///<保留位             @note 保留位，目前使用时赋0即可
	WORD   wMsgModuleType;      ///<接收消息的模块类型 @see E_ZC_MODULETYPE
	WORD   wREQModuleType;      ///<请求消息的模块类型 @see E_ZC_MODULETYPE
	DWORD  dwMsgType;           ///<消息类型           @note 具体的类型值，请参考各请求消息类型值定义   
	DWORD  dwMsgId;             ///<消息序列           @note 编码者可通过该值区分相同消息类型的消息
	DWORD  dwMsgLength;         ///<消息长度	       @note 可用以判断消息是否正确以及计算消息体个数
}ZC_MSG_HEAD, *LPZC_MSG_HEAD;
 
/** 
 * @brief 响应消息头部结构定义
 *
 * 该结构是每个请求反馈消息的头部必有信息，总长度8字节。
 */
typedef struct
{
	DWORD nOK;        ///<成功与否 0-失败，其余成功
	DWORD nError;     ///<错误码，当nOK为成功时，该值无意义
}ZC_MSG_RESP_RESULT, *LPZC_MSG_RESP_RESULT;
/** @} */

/************************************************************************/
/*                             模块定义                                 */
/************************************************************************/
/** @defgroup ZCMsgModuleTypeDefine 客户端各模块类型值定义      
 * 定义说明客户端各模块对应的模块类型值。
 * @{
 */
 
/** 
 * @brief 客户端各模块类型值定义
 *
 * 该结构将根据业务模块的扩展而更新。
 */
typedef enum
{
    ZC_MODULE_SERVER     = 1000,   ///<(1000)消息服务模块
	ZC_MODULE_APP        = 2000,   ///<(2000)APP模块
	ZC_MODULE_BCBCLIENT  = 3000,   ///<(3000)BCB客户端模块
	ZC_MODULE_HANDOVER   = 4000,   ///<(4000)交接班模块
	ZC_MODULE_SCHEDULE   = 4100,   ///<(4100)排班模块
	ZC_MODULE_TASK       = 4200,   ///<(4200)任务模块
	ZC_MODULE_ALARM      = 5000,   ///<(5000)报警模块
	ZC_MODULE_OPENDOOR   = 5100,   ///<(5100)第三方认证模块
	ZC_MODULE_SYSDORCTOR = 5200,   ///<(5200)智能运维模块
}E_ZC_MODULETYPE;
/** @} */

/************************************************************************/
/*                          消息类型定义                                */
/************************************************************************/
/** @defgroup ZCMsgTypeDefine 各模块消息类型值定义      
 * 定义说明各模块中使用的消息类型值及其对应的结构体
 * @{
 */
 
/** @defgroup ZCCommonMsgTypeDefine 多模块共同响应消息类型枚举      
 * 定义多模块共同响应消息类型值
 * @{
 */
typedef enum
{
    /**
	* @brief (0)模块注册失败消息
	* 
	* @note 请求消息值:\ref ZC_MSG_SERVER_RESP_REGISTER (10000)
	* @note 反馈结构体:NULL
	*/
    ZC_MSG_SERVER_REQ_REGFAILED    = 0,            
	ZC_MSG_SERVER_REQ_NOMODULE,                ///<(1)请求模块不存在消息
	
	/**
	* @brief (2)关联模块断开消息
	* 
	* 此为主动推送消息，当系统中某个模块注销时，消息服务会通过此消息通知在线的所有模块。各模块可自行考虑是否需处理该消息。
	* 
	* @note 推送结构体:WORD wModuleType 模块类型值
	*/
	ZC_MSG_SERVER_REQ_MODULELOGOUT,           
	
	ZC_MSG_COMMON_ROLEINFO = 100,              ///<(100)系统角色信息
	ZC_MSG_COMMON_CHILDROLEINFO,               ///<(101)下属角色信息
	ZC_MSG_COMMON_PLANINFO,                    ///<(102)预案库信息
	ZC_MSG_COMMON_USERIMAGEID,                 ///<(103)用户头像信息
	ZC_MSG_COMMON_EVENTINFO,                   ///<(104)事件库信息
	ZC_MSG_COMMON_OPENCAMERA,                  ///<(105)请求打开某个通道视频反馈
	
	ZC_MSG_COMMON_CURUSER = 2000,              ///<(2000)当前用户信息（1）
	ZC_MSG_COMMON_DOWNLOADPIC,                 ///<(2001)头像路径
	ZC_MSG_COMMON_ONLINEUSER,                  ///<(2002)当前在线用户信息
	ZC_MSG_COMMON_CURUSERINFOEX,               ///<(2003)当前用户信息反馈
	ZC_MSG_COMMON_ALLUSERINFO,                 ///<(2004)所有用户信息反馈
	ZC_MSG_COMMON_USERSTATE,                   ///<(2005)用户状态信息反馈
	ZC_MSG_COMMON_USERALLINFO,                 ///<(2006)用户详细信息反馈
	ZC_MSG_COMMON_ALLSUBORDINATEINFO,          ///<(2007)用户所有下属信息反馈
	ZC_MSG_COMMMON_CLASSMONITOR,               ///<(2008)用户同一班次上级角色信息反馈
	ZC_MSG_COMMON_USERMONITOR,                 ///<(2009)用户上级角色信息反馈
	ZC_MSG_COMMON_ALLCLASSSUBORDINATEINFO,     ///<(2010)用户同一个班次所有下属信息反馈
	ZC_MSG_COMMON_UPLOADATTACHMENT,            ///<(2011)附件上传结果反馈

    ZC_MSG_COMMON_GETALARMATTACHMENTFROMMS = 2020,    ///<(2020)从存储服务器下载报警联动附件反馈  @note 请求消息值:\ref ZC_MSG_BCBCLIENT_GETALARMATTACHMENTFROMMS (30050)
    ZC_MSG_COMMON_PLAYBACKALARMATTACHMENTFROMMS,      ///<(2021)从存储服务器回放报警联动视频附件反馈  @note 请求消息值:\ref ZC_MSG_BCBCLIENT_PLAYBACKALARMATTACHMENTFROMMS (30051)

	ZC_MSG_COMMON_THIRDPART_EXCHANGEMESSAGE = 2025,      ///<(2025)跟第三方系统交换信息结果反馈  @note 请求消息值:\ref ZC_MSG_BCBCLIENT_THIRDPART_EXCHANGEMESSAGE (30090)
    ZC_MSG_COMMON_TRANSCOMMONMSGTOKOALA,                 ///<(2026)向考拉报警代理发送消息结果反馈  @note 请求消息值:\ref ZC_MSG_BCBCLIENT_TRANSCOMMONMSGTOKOALA (30091)

	ZC_MSG_COMMON_ALLAREAINFO = 2050,          ///<(2050)所有区域信息反馈
	ZC_MSG_COMMON_ALLALARMTYPEINFO,            ///<(2051)所有报警类型信息反馈
	ZC_MSG_COMMON_ALLALARMLEVELINFO,           ///<(2052)所有报警等级信息反馈
	ZC_MSG_COMMON_ALLALARMDEALSTATEINFO,       ///<(2053)报警处理状态种类信息反馈
	ZC_MSG_COMMON_ALARMDEALTYPE,               ///<(2054)所有报警处置类型反馈
	ZC_MSG_COMMON_ALARMDECIDETYPE,             ///<(2055)所有报警定性戳类型反馈
	ZC_MSG_COMMON_ALLKEYPARTINFO,              ///<(2056)所有区域信息反馈
	ZC_MSG_COMMON_ALLDEVICEINFO,               ///<(2057)所有主机详细信息反馈
	
	ZC_MSG_COMMON_SETDUTYSTATUS = 2100,        ///<(2100)请求设置用户状态反馈 
	
	ZC_MSG_COMMON_ADDEVENT = 2200,             ///<(2200)动态发布结果反馈  
	ZC_MSG_COMMON_SENDEMAIL,                   ///<(2201)发送邮件结果反馈
	ZC_MSG_COMMON_CLOSEALLVIDEO,               ///<(2202)关闭视频窗口结果反馈
    ZC_MSG_COMMON_DEVTALKBYID,                 ///<(2203)通过对讲设备ID进行对讲反馈
	ZC_MSG_COMMON_CONTROLACSHOST,              ///<(2204)门禁主机控制结果反馈
    ZC_MSG_COMMON_FLASHNODE,              ///<(2205)节点闪烁结果反馈

    ZC_MSG_COMMON_REQUESTTRANSMSG_EX = 2299,   ///<(2299)通过中心给其他客户端转发消息反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_REQUESTTRANSMSG_EX (30299)
	ZC_MSG_COMMON_REQUESTTRANSMSG = 2300,      ///<(2300)通过中心给其他电子地图客户端转发消息反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_REQUESTTRANSMSG (30300)
	ZC_MSG_COMMON_TRANSMSG,                    ///<(2301)请求执行转发任务 @note 此为其他客户端主动推送的消息请求，任务模块暂不反馈结果
    ZC_MSG_COMMON_TRANSDEVICETROUBLEMSGTOKOALA,///<(2302)向考拉平台提交设备报修信息结果反馈  @note 请求消息值:\ref ZC_MSG_BCBCLIENT_TRANSDEVICETROUBLEMSGTOKOALA (30301)
}E_ZC_MSG_COMMON_REQ;
/** @} */

/** @defgroup ZCServerMsgTypeDefine 消息服务模块响应消息类型枚举      
 * 定义消息服务模块响应消息类型值
 * @{
 */
typedef enum
{
	ZC_MSG_SERVER_RESP_REGISTER     = 10000,     ///<(10000)模块注册消息  @note 请求结构体:NULL @note 反馈消息值:\ref ZC_MSG_SERVER_REQ_REGFAILED (0) 仅在失败时反馈 
	ZC_MSG_SERVER_RESP_UNREGISTER,               ///<(10001)模块反注册消息 
}E_ZC_MSG_SERVER;
/** @} */

/** @defgroup ZCAppMsgTypeDefine App模块响应消息类型枚举      
 * 定义App模块响应消息类型值
 * @{
 */
typedef enum
{
	ZC_MSG_APP_HA_INFO  = 20000,        ///<(20000)请求用户交接班信息 @note 请求结构体:\ref T_CURUSER_INFO @note 反馈消息值:\ref ZC_MSG_HANDOVER_HA_INFO (40000)
	ZC_MSG_APP_HA_WAITUSERLIST,         ///<(20001)请求待接班人员列表 @note 请求结构体:\ref T_CURUSER_INFO @note 反馈消息值:\ref ZC_MSG_HANDOVER_HA_WAITUSERLIST (40001)
	ZC_MSG_APP_HA_A_TASKINFO,           ///<(20002)请求值班员任务执行情况 @note 请求结构体:\ref T_CURUSER_INFO @note 反馈消息值:\ref ZC_MSG_HANDOVER_A_TASKINFO (40002)
	ZC_MSG_APP_HA_M_TASKINFO,           ///<(20003)请求值班长任务执行情况 @note 请求结构体:\ref T_CURUSER_INFO @note 反馈消息值:\ref ZC_MSG_HANDOVER_M_TASKINFO (40003)
	ZC_MSG_APP_HA_ALARMINFO,            ///<(20004)请求未处理报警信息 @note 请求结构体:\ref T_CURUSER_INFO @note 反馈消息值:\ref ZC_MSG_HANDOVER_HA_ALARMINFO (40004)
	ZC_MSG_APP_ADD_HAINFO,              ///<(20005)提交交接班信息 @note 请求结构体:\ref P_NEW_ADD_HA_INFO @note 反馈消息值:\ref ZC_MSG_HANDOVER_ADD_HAINFO (40005)
	ZC_MSG_APP_SEL_HAINFO,              ///<(20006)查询交接班记录 @note 请求结构体:\ref P_NEW_SHOW_HA_INFO @note 反馈消息值:\ref ZC_MSG_HANDOVER_SEL_HAINFO (40006)
	ZC_MSG_APP_HA_A_HISTORYINFO,        ///<(20007)请求值班员交接班历史详细信息 @note 请求结构体:int nScheduleID 排班ID @note 反馈消息值:\ref ZC_MSG_HANDOVER_A_HISTORYINFO (40008)
	ZC_MSG_APP_HA_M_HISTORYINFO,        ///<(20008)请求值班长交接班历史详细信息 @note 请求结构体:int nScheduleID 排班ID @note 反馈消息值:\ref ZC_MSG_HANDOVER_M_HISTORYINFO (40009)
	ZC_MSG_APP_HA_MODIFYALARMDEALMAN,   ///<(20009)请求批量修改报警处置人信息 @note 请求结构体:\ref TAG_NEW_ALARMDISPOSAL_BATCHSET_P @note 反馈消息值:\ref ZC_MSG_HANDOVER_MODIFYALARMDEALMAN (40010)
	ZC_MSG_APP_HA_CURCLASSUSERINFO,     ///<(20010)请求获取当前班次所有人员信息 @note 请求结构体:NULL @note 反馈消息值:\ref ZC_MSG_HANDOVER_CURCLASSUSERINFO (40011)
    
	ZC_MSG_APP_DATEGROUPSET = 20100,    ///<(20100)请求操作日期组信息，反馈ZC_MSG_SCHEDULE_DATEGROUPSET
	ZC_MSG_APP_DATEGROUPINFO,           ///<(20101)请求获取日期组信息，反馈ZC_MSG_SCHEDULE_DATEGROUPINFO
	ZC_MSG_APP_CLASSINFOSET,            ///<(20102)请求操作班次信息，反馈ZC_MSG_SCHEDULE_CLASSINFOSET
	ZC_MSG_APP_CLASSINFO,               ///<(20103)请求获取班次信息，反馈ZC_MSG_SCHEDULE_CLASSINFO
	ZC_MSG_APP_SCHEDULESET,             ///<(20104)请求设置排班信息（参考ServerConnectApp.h），反馈ZC_MSG_SCHEDULE_SCHEDULESET
	ZC_MSG_APP_SCHEDULEINFO,            ///<(20105)请求获取排班信息（参考ServerConnectApp.h），反馈ZC_MSG_SCHEDULE_SCHEDULEINFO
	ZC_MSG_APP_SC_USERINFO,             ///<(20106)请求待排班人员信息，反馈ZC_MSG_SCHEDULE_SC_USERINFO
	
	ZC_MSG_APP_TASKINFOSET = 20200,     ///<(20200)请求操作任务信息，反馈ZC_MSG_TASK_TASKINFOSET
	ZC_MSG_APP_FASTTASKINFOSET,         ///<(20201)请求新增快速任务，反馈ZC_MSG_TASK_FASTTASKINFOSET
	ZC_MSG_APP_TASKINFO,                ///<(20202)请求查询任务库中任务信息(5)，反馈ZC_MSG_TASK_TASKINFO
	ZC_MSG_APP_DETAILEDTASKINFO,        ///<(20203)请求查询任务详细信息(6)，反馈ZC_MSG_TASK_DETAILEDTASKINFO
	ZC_MSG_APP_TASKSTATESET,            ///<(20204)请求设置任务状态，反馈ZC_MSG_TASK_TASKSTATESET
	ZC_MSG_APP_TASKMODULEINFOSET,       ///<(20205)请求操作任务模板信息，反馈ZC_MSG_TASK_TASKMODULEINFOSET
	ZC_MSG_APP_TASKMODULEINFO,          ///<(20206)请求查询任务模板信息，反馈ZC_MSG_TASK_TASKMODULEINFO
	ZC_MSG_APP_DETAILEDTASKMODULEINFO,  ///<(20207)请求查询任务模板详细信息，反馈ZC_MSG_TASK_DETAILEDTASKMODULEINFO
	ZC_MSG_APP_TASKOBJECTINFO,          ///<(20208)请求获取任务对象信息，反馈ZC_MSG_TASK_TASKOBJECTINFO
	ZC_MSG_APP_TASKKEYPARTINFO,         ///<(20209)请求获取任务部位信息，反馈ZC_MSG_TASK_TASKKEYPARTINFO
	ZC_MSG_APP_TASKLEVELINFO,           ///<(20210)请求获取任务重要程度类型，反馈ZC_MSG_TASK_TASKLEVELINFO
	ZC_MSG_APP_TASKOPERATIONINFO,       ///<(20211)请求获取任务操作类型，反馈ZC_MSG_TASK_TASKOPERATIONINFO
	ZC_MSG_APP_TASKEXCEPTIONINFO,       ///<(20212)请求获取异常类型，反馈ZC_MSG_TASK_TASKEXCEPTIONINFO
	ZC_MSG_APP_DETATASKEXCEPTIONINFO,   ///<(20213)请求获取异常类型详情，反馈ZC_MSG_TASK_DETATASKEXCEPTIONINFO 
	ZC_MSG_APP_TASKCLASSROLEINFO,       ///<(20214)请求获取任务下发角色信息，反馈ZC_MSG_TASK_TASKCLASSROLEINFO
	ZC_MSG_APP_CURONLINEUSERINFO,       ///<(20215)请求获取当前上班用户信息，反馈ZC_MSG_TASK_CURONLINEUSERINFO
	ZC_MSG_APP_TODAYTASKINFO,           ///<(20216)请求获取当前用户今日任务信息，反馈ZC_MSG_TASK_TODAYTASKINFO
	ZC_MSG_APP_TODAYTASKALLINFO,        ///<(20217)请求获取某条待执行任务信息,反馈ZC_MSG_TASK_TODAYTASKALLINFO
	ZC_MSG_APP_TODAYTASKOBJECTINFO,     ///<(20218)请求获取某条待执行任务对象信息,反馈ZC_MSG_TASK_TODAYTASKOBJECTINFO
	ZC_MSG_APP_TODAYTASKDOINFO,         ///<(20219)请求获取某条任务的已执行信息,反馈ZC_MSG_TASK_TODAYTASKDOINFO
	ZC_MSG_APP_USERTASKINFO,            ///<(20220)请求获取某用户多日任务信息(7)，反馈ZC_MSG_TASK_USERTASKINFO

    /**
	* @brief (20221)请求新增任务执行信息
	*
	* 为向下兼容，该消息可接受两种参数，一种不含有guid，一种含有guid。消息处理函数根据消息长度调用不同的APP接口。
	* 
	* @note 请求结构体:\ref P_NEW_INSPECT_TASKEXCUTESET 或者 P_NEW_INSPECT_TASKEXCUTESET_NEW
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	* @note 反馈消息值:\ref ZC_MSG_TASK_TASKEXCUTESET (42021)
	* @note APP相关:\ref MSG_REG_NEW_INSPECT_TASKEXCUTESET (1259) 或者 MSG_REG_NEW_INSPECT_TASKEXCUTESET_NEW（611）
	*/
	ZC_MSG_APP_TASKEXCUTESET,          

	ZC_MSG_APP_TASK_CURUSERINFO,        ///<(20222)请求任务模块所需的当前用户信息，反馈ZC_MSG_TASK_CURUSERINFO
	ZC_MSG_APP_CHECKTASKINFO,           ///<(20223)请求查询已执行任务信息，反馈ZC_MSG_TASK_CHECKTASKINFO	
	ZC_MSG_APP_SHOWTASKCHECKINFO,       ///<(20224)请求获取任务复核相关信息，反馈ZC_MSG_TASK_SHOWTASKCHECKINFO
	ZC_MSG_APP_SHOWTASKEPLANINFO,       ///<(20225)请求获取任务复核预案信息，反馈ZC_MSG_TASK_SHOWTASKEPLANINFO
	ZC_MSG_APP_ISQUALIFIEDMOD,          ///<(20226)请求设置任务执行是否合格，反馈ZC_MSG_TASK_ISQUALIFIEDMOD
	ZC_MSG_APP_TASKCHECKRECORDSET,      ///<(20227)请求新增任务批阅记录，反馈ZC_MSG_TASK_TASKCHECKRECORDSET
	
	ZC_MSG_APP_SHOWAREAERRORINFO,       ///<(20228)统计某具体网点异常项发生情况，反馈ZC_MSG_TASK_SHOWAREAERRORINFO
	ZC_MSG_APP_SHOWAREAERRORATEINFO,    ///<(20229)统计网点的异常率，反馈ZC_MSG_TASK_SHOWAREAERRORATEINFO
	ZC_MSG_APP_SHOWCOVERRATEINFO,       ///<(20230)统计巡检覆盖率，反馈ZC_MSG_TASK_SHOWCOVERRATEINFO
	ZC_MSG_APP_SHOWALARMRECORINFO,      ///<(20231)获取风险提醒信息，反馈ZC_MSG_TASK_SHOWALARMRECORINFO
	ZC_MSG_APP_SHOWAREAERRORNUMINFO,    ///<(20232)统计单位时间内的网点异常数量，反馈ZC_MSG_TASK_SHOWAREAERRORNUMINFO
	ZC_MSG_APP_SHOWERRORCHECKRATEINFO,  ///<(20233)统计异常的复查合格率，反馈ZC_MSG_TASK_SHOWERRORCHECKRATEINFO
	
	ZC_MSG_APP_STATICS_TASKADDINFO,     ///<(20234)任务添加类统计信息，反馈ZC_MSG_TASK_STATICS_TASKADDINFO
	ZC_MSG_APP_STATICS_EMPLOYANALY,     ///<(20235)员工的能力分析统计信息，反馈ZC_MSG_TASK_STATICS_EMPLOYANALY
	ZC_MSG_APP_STATICS_EMPLOYMANAGER,   ///<(20236)员工管理类统计信息，反馈ZC_MSG_TASK_STATICS_EMPLOYMANAGER

	/**
	* @brief (20237)请求查询已执行任务信息（是否锁定附件）
	* 
	* @note 请求结构体:\ref P_NEW_INSPECT_CHECKTASKINFOWITHLOCK
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_CHECKTASKINFOSHOW * N
	* @note 反馈消息值:\ref ZC_MSG_TASK_CHECKTASKLOCKINFO 
	* @note APP相关:\ref MSG_REG_NEW_INSPECT_CHECKTASKINFOWITHLOCK (294)
	*/
	ZC_MSG_APP_CHECKTASKLOCKINFO,

	/**
	 * @brief (20238)请求获取某条下发任务的执行信息Ex
	 * 
	 * @note 请求结构体:\ref int 下发任务ID
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_TODAYTASKALLINFOSHOW_EX * N
	 * @note 反馈消息值:\ref ZC_MSG_TASK_TODAYTASKALLINFOSHOW_EX 
	 * @note APP相关:\ref MSG_REG_NEW_INSPECT_TODAYTASKALLINFOSHOW (1275)
	 */
	ZC_MSG_APP_TODAYTASKALLINFOSHOW_EX,

	/**
	 * @brief (20239)请求获取任务执行情况Ex
	 * 
	 * @note 请求结构体:\ref int 下发任务ID
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_TODAYTASKDOINFOSHOW_EX * N
	 * @note 反馈消息值:\ref ZC_MSG_TASK_TODAYTASKDOINFOSHOW_EX
	 * @note APP相关:\ref MSG_REG_NEW_INSPECT_TODAYTASKALLINFOSHOW (1275)
	 */
	ZC_MSG_APP_TODAYTASKDOINFOSHOW_EX,

    /**
	 * @brief (20240)请求根据场所ID和部位ID获取检查项目所有信息
	 * 
	 * @note 请求结构体:\ref P_EXCEPTION_CHECK_ITEM
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_EXCEPTION_CHECK_ITEM * N
	 * @note 反馈消息值:\ref ZC_MSG_TASK_AKIDCONFIGUREINFO
	 * @note APP相关:\ref MSG_REG_NEW_AKIDCONFIGUREINFO_GET （320）
	 */
	ZC_MSG_APP_AKIDCONFIGUREINFO,

    /**
	 * @brief (20241)请求获取主动巡查检查项目的时间段信息
	 * 
	 * @note 请求结构体:\ref NULL
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_GetConfigureTimeInfo * N
	 * @note 反馈消息值:\ref ZC_MSG_TASK_CONFIGURETIMEINFO
	 * @note APP相关:\ref MSG_REG_NEW_CONFIGURETIME_INFO （311）
	 */
	ZC_MSG_APP_TASK_CONFIGURETIMEINFO,

	/**
	 * @brief (20242)请求根据时间段名称获取主动巡查检查项目的时间段信息
	 * 
	 * @note 请求结构体:\ref P_ConfigureTimeNameInfo
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_GetConfigureTimeOnlyInfo * N
	 * @note 反馈消息值:\ref ZC_MSG_TASK_CONFIGURETIMEONLYINFO
	 * @note APP相关:\ref MSG_REG_NEW_CONFIGURETIMENAME_GET （312）
	 */
	ZC_MSG_APP_TASK_CONFIGURETIMEONLYINFO,

	/**
	 * @brief (20243)请求查询任务信息（检索条件包含是否关注）
	 * 
	 * @note 请求结构体:\ref P_NEW_INSPECT_CHECKTASKINFOWITHLOCK_NEW
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_CHECKTASKINFOSHOW * N
	 * @note 反馈消息值:\ref ZC_MSG_TASK_CHECKTASKINFOWITHLOCK_NEW
	 * @note APP相关:\ref MSG_REG_NEW_INSPECT_CHECKTASKINFOWITHLOCK_NEW （343）
	 */
	ZC_MSG_APP_TASK_CHECKTASKINFOWITHLOCK_NEW,

	/**
	 * @brief (20244)请求查询巡检覆盖率_New
	 *
	 * @note 请求结构体:\ref P_NEW_INSPECT_COVERRATENEWINFO
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_COVERRATENEWINFO * N
	 *
	 * @note 反馈消息值:\ref ZC_MSG_TASK_COVERRATENEWINFO_NEW (42044)
	 * @note APP相关:\ref MSG_REG_NEW_INSPECT_COVERRATENEWINFO (347)
	 */
    ZC_MSG_APP_TASK_COVERRATENEWINFO_NEW,

	ZC_MSG_APP_ALARM_QUERYINFO = 20300,    ///<(20300)报警查询结果，反馈ZC_MSG_ALARM_QUERYINFO
	ZC_MSG_APP_ALARM_STATICINFO,           ///<(20301)报警统计结果，反馈ZC_MSG_ALARM_STATICINFO
	ZC_MSG_APP_ALARM_TOPINFO,              ///<(20302)报警排行结果，反馈ZC_MSG_ALARM_TOPINFO
	ZC_MSG_APP_ALARM_DETAILINFO,           ///<(20303)请求通过报警部分信息获取报警详细信息，反馈ZC_MSG_ALARM_DETAILINFO
	
	ZC_MSG_APP_ALARM_USERGRAPHINFO,        ///<(20304)请求获取用户报警图表信息，反馈ZC_MSG_ALARM_USERGRAPHINFO
	ZC_MSG_APP_ALARM_OPUSERGRAPH,          ///<(20305)请求增删改用户图表，反馈ZC_MSG_ALARM_OPUSERGRAPH
	ZC_MSG_APP_ALARM_USERREPORTINFO,       ///<(20306)请求获取用户报告信息（查看报告Tab页使用），反馈ZC_MSG_ALARM_USERREPORTINFO
	ZC_MSG_APP_ALARM_MODSTATUSUSERREPORT,  ///<(20307)请求设置用户报告状态信息，反馈ZC_MSG_ALARM_MODSTATUSUSERREPORT
	ZC_MSG_APP_ALARM_OPUSERREPORT,         ///<(20308)请求增删改用户报告，反馈ZC_MSG_ALARM_OPUSERREPORT
	ZC_MSG_APP_ALARM_USERREPORTBOOKINFO,   ///<(20309)请求获取用户报告订阅信息（订阅报告Tab页使用），反馈ZC_MSG_ALARM_USERREPORTBOOKINFO

	/**
	* @brief (20310)报警查询结果（是否锁定附件）
	* 
	* @note 请求结构体:\ref P_NEW_JH_COMPLEXCHECKWITHLOCK
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_JH_COMPLEXCHECK * N
	* @note 反馈消息值:\ref ZC_MSG_ALARM_QUERYLOCKINFO （50010）
	* @note APP相关:\ref MSG_REG_NEW_JH_COMPLEXCHECKWITHLOCK (295)
	*/
    ZC_MSG_APP_ALARM_QUERYLOCKINFO,

	/**
	 * @brief (20311)根据报警ID或报警GUID获取报警详细信息
	 *
	 * 20170602新增接口，补全获取报警所有信息
	 * 
	 * @note 请求结构体:\ref P_NEW_DETAILALARMINFO_GET
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_DETAILALARMINFO_GET
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_DETAILALARMINFO_GET （50011）
	 * @note APP相关:\ref MSG_REG_NEW_ALARMDETAILINFO_NEW_SHOW (353)
	 */
    ZC_MSG_APP_ALARM_DETAILALARMINFO_GET,

	/**
  	 * @brief (20312)警情类型获取_分上下级
	 * 
	 * @note 请求结构体:\ref NULL
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_ALARMACATEGORY_SHOW * N
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_NEW_ALARMACATEGORY_SHOW （50012）
	 * @note APP相关:\ref MSG_REG_NEW_ALARMACATEGORY_SHOW (354)
	 */
    ZC_MSG_APP_ALARM_NEW_ALARMACATEGORY_SHOW,
	
	ZC_MSG_APP_ALARM_DISPOSALINFO = 20320,      ///<(20320)请求获取用户报警处置权限，反馈ZC_MSG_ALARM_DISPOSALINFO
    ZC_MSG_APP_ALARM_LEVELPLOYINFO, 	        ///<(20321)请求获取报警等级处置策略，反馈ZC_MSG_ALARM_LEVELPLOYINFO
	ZC_MSG_APP_ALARM_HISTORYDEALINFO,           ///<(20322)请求获取历史处理情况统计数据，反馈ZC_MSG_ALARM_HISTORYDEALINFO
	ZC_MSG_APP_ALARM_POSTILINFO,                ///<(20323)请求获取报警批注信息，反馈ZC_MSG_ALARM_POSTILINFO
	ZC_MSG_APP_ALARM_OPERATIONINFO,             ///<(20324)请求获取报警操作信息，反馈ZC_MSG_ALARM_OPERATIONINFO
	ZC_MSG_APP_ALARM_NOTDEALINFO,               ///<(20325)请求获取未处理报警信息，反馈ZC_MSG_ALARM_NOTDEALINFO
	
    ZC_MSG_APP_ALARM_DEALSTATUSSET = 20330,     ///<(20330)请求设置报警信息处置状态，反馈ZC_MSG_ALARM_DEALSTATUSSET
	ZC_MSG_APP_ALARM_PEOPLESET,                 ///<(20331)请求设置报警信息处置人，反馈ZC_MSG_ALARM_PEOPLESET
	ZC_MSG_APP_ALARM_DEALSULTSET,               ///<(20332)请求提交报警处置结果，反馈ZC_MSG_ALARM_DEALSULTSET
	ZC_MSG_APP_ALARM_MODALARMPARAM,             ///<(20333)请求修改报警关键参数，反馈ZC_MSG_ALARM_MODALARMPARAM
	ZC_MSG_APP_ALARM_ADDALARMOPERATIONINFO,     ///<(20334)请求新增报警操作记录，反馈ZC_MSG_ALARM_ADDALARMOPERATION
	ZC_MSG_APP_ALARM_ADDALARMPOSTILINFO,        ///<(20335)请求新增报警批注信息，反馈ZC_MSG_ALARM_ADDALARMPOSTILINFO
	ZC_MSG_APP_ALARM_ADDDEFERALARMINGO,         ///<(20336)请求新增延后处理报警信息，反馈ZC_MSG_ALARM_ADDDEFERALARMINGO
	
	/**
	* @brief (20337)请求获取某条报警媒体存储附件列表信息
	* 
	* @note 请求结构体:\ref CLIENTGETMEDIASTORAGEATTACHMENT_P 
	* @note 返回结构体:\ref CLIENTGETMEDIASTORAGEATTACHMENT_S
	* @note 反馈消息值:\ref ZC_MSG_ALARM_GETMSATTACHMENT (50088)
	* @note APP相关:\ref MSG_REG_CLIENTGETMEDIASTORAGEATTACHMENT (610)
	*/
	ZC_MSG_APP_ALARM_GETMSATTACHMENT,    

	/**
	* @brief (20338)请求锁定\解锁报警联动存储文件
	* 
	* @note 请求结构体:\ref ALARMSTORAGEFILELOCKED_SET_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	* @note 反馈消息值:\ref ZC_MSG_ALARM_LOCKMSATTACHMENT (50089)
	* @note APP相关:\ref MSG_REG_ALARMSTORAGEFILELOCKED_SET (601)
	*/
	ZC_MSG_APP_ALARM_LOCKMSATTACHMENT,

	/**
	 * @brief (20339)报警插入_手动报警
	 * 
	 * @note 请求结构体:\ref P_ALARMDISPOSAL_ALARMCATEGORY_SET_NEW 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_MANUALENTRY(50089)
	 * @note APP相关:\ref MSG_REG_ALARMDISPOSAL_ALARMCATEGORY_SET_NEW (616)
	 */
    ZC_MSG_APP_ALARM_MANUALENTRY,

	/**
	 * @brief (20340)获取第四交流屏交流内容
	 * 
	 * @note 请求结构体:\ref P_NEW_PARAM_EXCHANGEINFO 
	 * @note 返回结构体:\ref S_NEW_PARAM_EXCHANGEINFO
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_EXCHANGEINFO_NEW(50067)
	 * @note APP相关:\ref MSG_REG_NEW_EXCHANGEINFO_NEW (349)
	 */
    ZC_MSG_APP_ALARM_EXCHANGEINFO_NEW,

	/**
	 * @brief (20341)第四交流屏交流内容操作
	 * 
	 * @note 请求结构体:\ref P_NEW_EXCHANGEINFO_OPERATION 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_EXCHANGEINFO_OPERATION(50068)
	 * @note APP相关:\ref MSG_REG_NEW_EXCHANGEINFO_OPERATION (350)
	 */
    ZC_MSG_APP_ALARM_EXCHANGEINFO_OPERATION,

   /**
	 * @brief (20342)报警复核日志插入_New
	 * 
	 * @note 请求结构体:\ref P_NEW_ALARMDISPOSALNEW_SET 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_REG_NEW_ALARMDISPOSALNEW_SET(50069)
	 * @note APP相关:\ref MSG_REG_NEW_ALARMDISPOSALNEW_SET (351)
	 */
    ZC_MSG_APP_ALARM_REG_NEW_ALARMDISPOSALNEW_SET,

	/**
	 * @brief (20343)根据报警ID或报警GUID获取操作记录信息
	 * 
	 * @note 请求结构体:\ref P_NEW_ALARMDISPOSALNEW_SHOW 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_ALARMDISPOSALNEW_SHOW * N
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_REG_NEW_ALARMDISPOSALNEW_SHOW(50070)
	 * @note APP相关:\ref MSG_REG_NEW_ALARMDISPOSALNEW_SHOW (352)
	 */
    ZC_MSG_APP_ALARM_REG_NEW_ALARMDISPOSALNEW_SHOW,
	
    /**
	 * @brief (20350)报警处置考拉信息写入
	 * 
	 * @note 请求结构体:\ref ALARMDEALKOALAINFO_INSERT_P 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_DEALKOALAINFO (50200)
	 * @note APP相关:\ref MSG_REG_ALARMDEALKOALAINFO_INSERT (703)
	 */
	ZC_MSG_APP_ALARM_DEALKOALAINFO = 20350,

	/**
	 * @brief (20351)获取动作库_Koala
	 * 
	 * @note 请求结构体:\ref GETACTIONLIB_KOALA_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETACTIONLIB_KOALA_S * N
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_GETACTIONLIB_KOALA (50201)
	 * @note APP相关:\ref MSG_REG_GETACTIONLIB_KOALA (704)
	 */
	ZC_MSG_APP_ALARM_GETACTIONLIB_KOALA,

    /**
	 * @brief (20352)获取预案库_Koala
	 * 
	 * @note 请求结构体:\ref GETPREPLANLIB_KOALA_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETPREPLANLIB_KOALA_S * N
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_GETPREPLANLIB_KOALA (50202)
	 * @note APP相关:\ref MSG_REG_GETPREPLANLIB_KOALA (705)
	 */
	ZC_MSG_APP_ALARM_GETPREPLANLIB_KOALA,

    /**
	 * @brief (20353)获取事件库_Koala
	 * 
	 * @note 请求结构体:\ref GETEVENTLIB_KOALA_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETEVENTLIB_KOALA_S * N
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_GETEVENTLIB_KOALA (50203)
	 * @note APP相关:\ref MSG_REG_GETEVENTLIB_KOALA (706)
	 */
	ZC_MSG_APP_ALARM_GETEVENTLIB_KOALA,

	/**
	 * @brief (20354)获取Koala报警附件
	 * 
	 * @note 请求结构体:\ref GETALARMATTACHMENT_KOALA_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETALARMATTACHMENT_KOALA_S * N
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_GETALARMATTACHMENT_KOALA (50204)
	 * @note APP相关:\ref MSG_REG_GETALARMATTACHMENT_KOALA (707)
	 */
	ZC_MSG_APP_ALARM_GETALARMATTACHMENT_KOALA,

	/**
	 * @brief (20355)设置报警复核_警情类型值
	 * 
	 * @note 请求结构体:\ref P_NEW_ALARMDISPOSALADDCATEGORYID_AC_SET
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_DISPOSALADDCATEGORYID_AC_SET (50205)
	 * @note APP相关:\ref MSG_REG_NEW_ALARMDISPOSALADDCATEGORYID_AC_SET (356)
	 */
	ZC_MSG_APP_ALARM_DISPOSALADDCATEGORYID_AC_SET,

    /**
	 * @brief (20356)报警处理信息的综合查询WITHLOCK_NEW
	 * 
	 * @note 请求结构体:\ref P_NEW_COMPLEXCHECKWITHLOCK
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_COMPLEXCHECKWITHLOCK * N
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_JH_COMPLEXCHECKWITHLOCK_NEW (50206)
	 * @note APP相关:\ref MSG_REG_NEW_JH_COMPLEXCHECKWITHLOCK_NEW (357)
	 */
	ZC_MSG_APP_ALARM_JH_COMPLEXCHECKWITHLOCK_NEW,

	/**
     * @brief (20357)根据报警GUID获取报警主机布撤防状态
     * 
     * @note 请求结构体:\ref P_AlarmDeviceStateByGuid
     * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_AlarmDeviceStateByGuid * N
     * @note 反馈消息值:\ref ZC_MSG_ALARM_ALARMDEVICESTATEINTO_NEW (50207)
     * @note APP相关:\ref MSG_REG_NEW_ALARMDEVICESTATEBYGUID_SHOW (367)
     */
	ZC_MSG_APP_ALARM_ALARMDEVICESTATEINTO_NEW,

	ZC_MSG_APP_OPENDOOR_ADDREQUEST = 20400,     ///<(20400)请求关联刷卡认证记录（403），反馈ZC_MSG_OPENDOOR_ADDREQUEST
	ZC_MSG_APP_OPENDOOR_ADDDEALPLANINFO,        ///<(20401)请求提交预案执行信息（404），反馈ZC_MSG_OPENDOOR_ADDDEALPLANINFO
	ZC_MSG_APP_OPENDOOR_MODIFYDEALTYPE,         ///<(20402)请求修改认证处置方式（405），反馈ZC_MSG_OPENDOOR_MODIFYDEALTYPE
	ZC_MSG_APP_OPENDOOR_MODIFYREQUESTSTATE,     ///<(20403)请求修改认证处置状态（406），反馈ZC_MSG_OPENDOOR_MODIFYREQUESTSTATE
	ZC_MSG_APP_OPENDOOR_SUBMITAUDITORDEALINFO,  ///<(20404)请求提交开门申请审核基础信息（407），反馈ZC_MSG_OPENDOOR_SUBMITAUDITORDEALINFO
	ZC_MSG_APP_OPENDOOR_MODIFYISCOLLECTION,     ///<(20405)请求修改认证记录收藏状态（408），反馈ZC_MSG_OPENDOOR_MODIFYISCOLLECTION 

    /**
	* @brief (20406)请求新增认证申请记录
	*
	* 为向下兼容，该消息可接受两种参数，一种不含有guid，一种含有guid。消息处理函数根据消息长度调用不同的APP接口。
	* 
	* @note 请求结构体:\ref TAGDOA_INFO_P 或者 TAGDOA_INFO_P_NEW
	* @note 返回结构体:\ref TAGDOA_INFO_S
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_SUBMITDEALINFO (51156)
	* @note APP相关:\ref MSG_REG_NEW_DOOROPENAPPLY_INFO_ADD (409) 或者 MSG_REG_NEW_DOOROPENAPPLY_INFO_ADD_NEW（612）
	*/
	ZC_MSG_APP_OPENDOOR_SUBMITDEALINFO,         
	ZC_MSG_APP_OPENDOOR_SETUSERBASEINFO,        ///<(20407)请求设置用户认证基础信息（410），反馈ZC_MSG_OPENDOOR_SETUSERBASEINFO
	ZC_MSG_APP_OPENDOOR_ADDOPERAINFO,           ///<(20408)请求新增认证处置动作信息（411），反馈ZC_MSG_OPENDOOR_ADDOPERAINFO
	ZC_MSG_APP_OPENDOOR_ADDLOGINFO,             ///<(20409)请求新增认证系统日志信息（412），反馈ZC_MSG_OPENDOOR_ADDLOGINFO
	ZC_MSG_APP_OPENDOOR_ADDSUGGESTION,          ///<(20410)请求新增认证处理意见信息（413），反馈ZC_MSG_OPENDOOR_ADDSUGGESTION
	ZC_MSG_APP_OPENDOOR_ADDEXCEPTIONINFO,       ///<(20411)请求录入异常认证信息（431），反馈ZC_MSG_OPENDOOR_ADDEXCEPTIONINFO
	
	ZC_MSG_APP_OPENDOOR_GETUSERBASEINFO,        ///<(20412)请求获取用户认证基础信息（416），反馈ZC_MSG_OPENDOOR_GETUSERBASEINFO
	ZC_MSG_APP_OPENDOOR_GETALLACSHOSTINFO,      ///<(20413)请求获取所有门禁主机信息（417），反馈ZC_MSG_OPENDOOR_GETALLACSHOSTINFO
	ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKINFO,     ///<(20414)请求获取门禁主机关联信息（418），反馈ZC_MSG_OPENDOOR_GETACSHOSTLINKINFO
	ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKTALKINFO, ///<(20415)请求获取门禁主机关联对讲信息（419），反馈ZC_MSG_OPENDOOR_GETACSHOSTLINKTALKINFO
	ZC_MSG_APP_OPENDOOR_GETALLPEPOLEINFO,       ///<(20416)请求获取所有需管辖的出入人员信息（420），反馈ZC_MSG_OPENDOOR_GETALLPEPOLEINFO
	ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYINFO,    ///<(20417)请求获取认证历史信息（422），反馈ZC_MSG_OPENDOOR_GETAPPLYHISTORYINFO
	ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYDETAIL,  ///<(20418)请求获取认证历史详细信息（423），反馈ZC_MSG_OPENDOOR_GETAPPLYHISTORYDETAIL
	ZC_MSG_APP_OPENDOOR_GETOPERAINFO,           ///<(20419)请求获取认证操作列表信息（424），反馈ZC_MSG_OPENDOOR_GETOPERAINFO
	ZC_MSG_APP_OPENDOOR_GETAPPLYPLANINFO,       ///<(20420)请求获取预案执行信息（425），反馈ZC_MSG_OPENDOOR_GETAPPLYPLANINFO
	ZC_MSG_APP_OPENDOOR_GETSUGGESTIONINFO,      ///<(20421)请求获取处理意见信息（426），反馈ZC_MSG_OPENDOOR_GETSUGGESTIONINFO
	ZC_MSG_APP_OPENDOOR_GETLOGINFO,             ///<(20422)请求获取系统日志信息（427），反馈ZC_MSG_OPENDOOR_GETLOGINFO
	ZC_MSG_APP_OPENDOOR_GETACCESSLOGINFO,       ///<(20423)请求获取关联刷卡信息（428），反馈ZC_MSG_OPENDOOR_GETACCESSLOGINFO
	
	/**
	* @brief (20424)请求查询刷卡历史信息
	*
	* 2016-04-28后不再使用，之后使用新接口 \ref ZC_MSG_APP_OPENDOOR_APPLY_BYCARDINFO_NEW（20431）
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_GETBYCARDHISTORYINFO
	* @note APP相关:\ref MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFO_SHOW (429)
	*/
	ZC_MSG_APP_OPENDOOR_GETBYCARDHISTORYINFO, 
	ZC_MSG_APP_OPENDOOR_STATISTICS,             ///<(20425)请求统计认证信息（430），反馈ZC_MSG_OPENDOOR_STATISTICS
	ZC_MSG_APP_OPENDOOR_DISPOSALINFO,           ///<(20426)请求获取当前用户认证相关权限(263)，反馈ZC_MSG_OPENDOOR_DISPOSALINFO
	ZC_MSG_APP_OPENDOOR_ACCESSRELATION,         ///<(20427)请求获取门禁设备主从关联信息(433)，反馈ZC_MSG_OPENDOOR_ACCESSRELATION
	ZC_MSG_APP_OPENDOOR_CTRLLEVELMULINFO,       ///<(20428)请求获取管控等级信息(402)，反馈ZC_MSG_OPENDOOR_CTRLLEVELMULINFO
	ZC_MSG_APP_OPENDOOR_CTRLLEVELPLAN,          ///<(20429)请求获取管控策略信息（434），反馈ZC_MSG_OPENDOOR_CTRLLEVELPLAN
	ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO,         ///<(20430)请求获取部门信息（435），反馈ZC_MSG_OPENDOOR_DEPARTMENTINFO

    /**
	* @brief (20431)请求查询刷卡历史信息
	*
	* 2016-04-28后不再使用，之后使用新接口 /ref ZC_MSG_APP_OPENDOOR_APPLY_BYCARDINFO_NEW（20431）
	*
	* @note 请求结构体:\ref TAGDOABYCARDINFO_NEW_P 
	* @note 返回结构体:\ref TAGDOABYCARDINFO_NEW_S
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_APPLY_BYCARDINFO_NEW
	* @note APP相关:\ref MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFO_SHOW_NEW (450)
	*/
	ZC_MSG_APP_OPENDOOR_APPLY_BYCARDINFO_NEW,

    /**
	* @brief (20432)请求获取用户门禁摄像头关联信息
	*
	* @note 请求结构体:\ref NULL
	* @note 返回结构体:\ref USERDOORCAMERARELATION_CLIENT_GET_S
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_USERDOORCAMERARELATION
	* @note APP相关:\ref MSG_REG_NEW_USERDOORCAMERARELATION_CLIENT_GET (451)
	*/
	ZC_MSG_APP_OPENDOOR_USERDOORCAMERARELATION,   

	/**
	* @brief (20433)请求获取认证历史信息（是否锁定附件）
	*
	* @note 请求结构体:\ref TAGDOAHISTORYINFOWITHLOCK_P
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref TAGDOAHISTORYINFO_S * N
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_GETAPPLYHISTORYLOCKINFO
	* @note APP相关:\ref MSG_REG_NEW_DOOROPENAPPLY_HISTORYINFOWITHLOCK (296)
	*/
	ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYLOCKINFO,  

	/**
	* @brief (20434)请求设置人员信息
	*
	* @note 请求结构体:\ref STAFFINFOOPERATION_P
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_STAFFINFOOPERATION
	* @note APP相关:\ref MSG_REG_NEW_STAFFINFOOPERATION (453)
	*/
	ZC_MSG_APP_OPENDOOR_STAFFINFOOPERATION, 

    /**
	* @brief (20435)请求设置部门信息
	*
	* @note 请求结构体:\ref DEPARTMENTINFOOPERATION_P
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_DEPARTMENTINFOOPERATION
	* @note APP相关:\ref MSG_REG_NEW_DEPARTMENTINFOOPERATION (454)
	*/
	ZC_MSG_APP_OPENDOOR_DEPARTMENTINFOOPERATION, 

    /**
	* @brief (20436)请求设置人员状态
	*
	* @note 请求结构体:\ref STAFFSTATUS_SET_P
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_STAFFSTATUS_SET
	* @note APP相关:\ref MSG_REG_NEW_STAFFSTATUS_SET (455)
	*/
	ZC_MSG_APP_OPENDOOR_STAFFSTATUS_SET, 

    /**
	* @brief (20437)请求获取部门信息
	*
	* @note 请求结构体:\ref DEPARTMENTINFO_GET_P
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DEPARTMENTINFO_GET_S * N
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_DEPARTMENTINFO_GET
	* @note APP相关:\ref MSG_REG_NEW_DEPARTMENTINFO_GET (456)
	*/
	ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO_GET, 

    /**
	* @brief (20438)请求获取权限组信息
	*
	* @note 请求结构体: NULL
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref AUTHGROUP_GET_S * N
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_AUTHGROUP_GET
	* @note APP相关:\ref MSG_REG_NEW_AUTHGROUP_GET (457)
	*/
	ZC_MSG_APP_OPENDOOR_AUTHGROUP_GET, 

    /**
	* @brief (20439)请求获取人员信息
	*
	* @note 请求结构体:\ref STAFFINFO_GET_P
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref STAFFINFO_GET_S * N
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_STAFFINFO_GET
	* @note APP相关:\ref MSG_REG_NEW_STAFFINFO_GET (458)
	*/
	ZC_MSG_APP_OPENDOOR_STAFFINFO_GET, 

    /**
	* @brief (20440)请求获取人员操作信息
	*
	* @note 请求结构体:\ref STAFFOPERATION_GET_P
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref STAFFOPERATION_GET_S * N
	*
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_STAFFOPERATION_GET (51190)
	* @note APP相关:\ref MSG_REG_NEW_STAFFOPERATION_GET (459)
	*/
	ZC_MSG_APP_OPENDOOR_STAFFOPERATION_GET, 

	/**
	 * @brief (20441)请求获取人员权限组
	 *
	 * @note 请求结构体:\ref STAFFAUTHINFO_GET_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref STAFFAUTHINFO_GET_S * N
	 *
	 * @note 反馈消息值:\ref ZC_MSG_OPENDOOR_STAFFAUTHINFO_GET (51191)
	 * @note APP相关:\ref MSG_REG_NEW_STAFFAUTHINFO_GET (461)
	 */
	ZC_MSG_APP_OPENDOOR_STAFFAUTHINFO_GET, 

    /**
	 * @brief (20442)请求关联认证守押信息
	 *
	 * @note 请求结构体:\ref DOOROPENSYRELATION_SET_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 *
	 * @note 反馈消息值:\ref ZC_MSG_OPENDOOR_DOOROPENSYRELATION_SET (51192)
	 * @note APP相关:\ref MSG_REG_NEW_DOOROPENSYRELATION_SET (464)
	 */
	ZC_MSG_APP_OPENDOOR_DOOROPENSYRELATION_SET,

    /**
	 * @brief (20443)请求获取门禁关联守押设备
	 *
	 * @note 请求结构体:\ref ACCESSSYRELATION_GET_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref ACCESSSYRELATION_GET_S * N
	 *
	 * @note 反馈消息值:\ref ZC_MSG_OPENDOOR_ACCESSSYRELATION_GET (51193)
	 * @note APP相关:\ref MSG_REG_NEW_ACCESSSYRELATION_GET (465)
	 */
	ZC_MSG_APP_OPENDOOR_ACCESSSYRELATION_GET,

    /**
	 * @brief (20444)请求获取认证守押关联信息
	 *
	 * @note 请求结构体:\ref DOOROPENSYRELATION_GET_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DOOROPENSYRELATION_GET_S * N
	 *
	 * @note 反馈消息值:\ref ZC_MSG_OPENDOOR_DOOROPENSYRELATION_GET (51194)
	 * @note APP相关:\ref MSG_REG_NEW_DOOROPENSYRELATION_GET (466)
	 */
	ZC_MSG_APP_OPENDOOR_DOOROPENSYRELATION_GET,

	/**
	 * @brief (20445)请求查询认证历史信息（可按认证类型查询）
	 *
	 * @note 请求结构体:\ref QUERYHISTORYINFO_SY_GET_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref QUERYHISTORYINFO_SY_GET_S * N
	 *
	 * @note 反馈消息值:\ref ZC_MSG_OPENDOOR_QUERYHISTORYINFO_SY_GET (51195)
	 * @note APP相关:\ref MSG_REG_NEW_QUERYHISTORYINFO_SY_GET (467)
	 */
	ZC_MSG_APP_OPENDOOR_QUERYHISTORYINFO_SY_GET,

    /**
	* @brief (20500)请求获取当前用户智能运维相关权限信息
	* 
	* @note 请求结构体: NULL 
	* @note 返回结构体:\ref T_SYSDORCTORPOSALINFO
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DISPOSALINFO (52000)
	* @note APP相关:\ref MSG_REG_NEW_ALARMDISPOSAL_AUTH_SHOW (1302) \ref P_NEW_ALARMDISPOSAL_AUTH_SHOW \ref S_NEW_ALARMDISPOSAL_AUTH_SHOW
	*/
	ZC_MSG_APP_SYSDORCTOR_DISPOSALINFO = 20500,       
	
	/**
	* @brief (20510)请求获取平台中心信息
	* 
	* 平台中心信息消息服务不做缓存处理，该接口返回APP获取到的所有中心最新数据；【有1条测试假数据】
	* 
	* @note 请求结构体: NULL 
	* @note 返回结构体:\ref CMS_INFO
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_CMSINFO (52010)
	* @note APP相关:\ref MSG_REQ_NEW_SHOW_CMSNODE_INFO \ref P_CMSInfo \ref S_CMSInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_CMSINFO = 20510,

	/**
	* @brief (20511)请求获取平台区域信息
	* 
	* 该接口返回平台所有区域信息，不根据用户名进行筛选（报修信息查询的时候就未考虑需根据用户筛选）。由于目前仅智能运维模块需使用该接口，故暂不做缓存处理，该接口返回APP获取到的最新数据；日后若存在效率问题，则考虑对其优化【有4条测试假数据】
	* 
	* @note 请求结构体: NULL 
	* @note 返回结构体:\ref AREA_NODE_INFO
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_AREAINFO (52011)
	* @note APP相关:\ref MSG_REQ_NEW_SHOW_ALLAREANODE_INFO \ref P_AreaInfo \ref S_AreaNodeInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_AREAINFO,   

	/**
	* @brief (20512)请求获取平台主机信息
	* 
	* 由于目前仅智能运维模块需使用该接口，故暂不做缓存处理，该接口返回APP获取到的最新数据；日后若存在效率问题，则考虑对其优化【有5条测试假数据】
	* 
	* @note 请求结构体: NULL 
	* @note 返回结构体:\ref DEV_NODE_INFO
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVINFO (52012)
	* @note APP相关:\ref MSG_REQ_NEW_SHOW_DEVNODE_INFO \ref S_DevNodeInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVINFO,

	/**
	* @brief (20513)请求获取平台探头信息
	* 
	* 由于目前仅智能运维模块需使用该接口，故暂不做缓存处理，该接口返回APP获取到的最新数据；日后若存在效率问题，则考虑对其优化【有5条测试假数据】
	* 
	* @note 请求结构体: NULL 
	* @note 返回结构体:\ref CAMERA_NODE_INFO
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_CAMERAINFO (52013)
	* @note APP相关:\ref MSG_REQ_NEW_SHOW_FRONTNODE_INFO \ref S_FrontendNodeInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_CAMERAINFO,  

	/**
	* @brief (20514)请求获取平台主机信息(包含资产编号)
	* 
	* 由于目前仅智能运维模块需使用该接口，故暂不做缓存处理，该接口返回APP获取到的最新数据；
	* 
	* @note 请求结构体: NULL 
	* @note 返回结构体:\ref DEVICEINFOWITHCAPITAL_GET_S
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVINFO_EX (52014)
	* @note APP相关:\ref MSG_REG_NEW_DEVICEINFOWITHCAPITAL_GET （545）
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVINFO_EX,

	/**
	* @brief (20515)请求获取平台探头信息(包含资产编号)
	* 
	* 由于目前仅智能运维模块需使用该接口，故暂不做缓存处理，该接口返回APP获取到的最新数据；
	* 
	* @note 请求结构体: NULL 
	* @note 返回结构体:\ref FRONTENDNODEINFOWITHCAPITAL_GET_S
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_CAMERAINFO_EX (52015)
	* @note APP相关:\ref MSG_REG_NEW_FRONTENDNODEINFOWITHCAPITAL_GET （546）
	*/
	ZC_MSG_APP_SYSDORCTOR_CAMERAINFO_EX,  

    /**
	* @brief (20519)请求获取所有设备品牌信息(只包含资产信息中存在的)
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据；【有2条测试假数据】
	* 
	* @note 请求结构体:\ref DEVICEMANUFACTUREINFOINCAPITALGET_S 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DEVICEMANUFACTUREINFOGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MANUFACTUREINFOINCAPITAL (52019)
	* @note APP相关:\ref MSG_REG_NEW_DEVICEMANUFACTUREINFOINCAPITAL_GET（544）
	*/
	ZC_MSG_APP_SYSDORCTOR_MANUFACTUREINFOINCAPITAL = 20519,

	/**
	* @brief (20520)请求获取所有设备品牌信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据；【有2条测试假数据】
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DEVICEMANUFACTUREINFOGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MANUFACTURENAME (52020)
	* @note APP相关:\ref MSG_REG_NEW_DEVICEMANUFACTUREINFO_GET（509）
	*/
	ZC_MSG_APP_SYSDORCTOR_MANUFACTURENAME = 20520,  
	
	/**
	* @brief (20521)请求获取设备型号信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据；【有2条测试假数据】
	* 
	* @note 请求结构体:\ref DEVICEMODELINFOGET_IN_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DEVICEMODELINFOGET_OUT_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MODELNO (52021)
	* @note APP相关:\ref MSG_REG_NEW_DEVICEMODELINFO_GET（510）
	*/
	ZC_MSG_APP_SYSDORCTOR_MODELNO,      

	/**
	* @brief (20522)请求获取所有供应商信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据；【有2条测试假数据】
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref SUPPLIERINFOGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_SUPPLIERCOMPANY（52022）
	* @note APP相关:\ref MSG_REG_NEW_SUPPLIERINFO_GET（511）
	*/
	ZC_MSG_APP_SYSDORCTOR_SUPPLIERCOMPANY, 

	/**
	* @brief (20523)请求获取所有维保商信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据；【有2条测试假数据】
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref MAINTENCECOMPANYGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MAINTENCECOMPANY（52023）
	* @note APP相关:\ref MSG_REG_NEW_MAINTENCECOMPANY_GET（512）
	*/
	ZC_MSG_APP_SYSDORCTOR_MAINTENCECOMPANY, 

	/**
	* @brief (20524)请求获取所有维保商电话信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据；【有2条测试假数据】
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref MAINTENCEINFOPHONE_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MAINTENCEPHONE（52024）
	* @note APP相关:\ref MSG_REG_NEW_MAINTENCEINFO_PHONE_GET（518）
	*/
	ZC_MSG_APP_SYSDORCTOR_MAINTENCEPHONE,      
	
	/**
	* @brief (20525)请求获取所有工程商信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据；【有2条测试假数据】
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref ENGINEERINGINFOGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_ENGINEERINGNAME（52025）
	* @note APP相关:\ref MSG_REG_NEW_ENGINEERINGINFO_GET（513）
	*/
	ZC_MSG_APP_SYSDORCTOR_ENGINEERINGNAME,
	
	/**
	* @brief (20526)请求获取所有报警主机信息
	* 
	* 消息服务通过APP实时查询并返回平台中所有报警主机信息
	* 
	* @note 请求结构体:\ref NULL 
	*       返回结构体:\ref ZC_MSG_RESP_RESULT + \ref P_AlarmPartionInfo *N
	*       反馈消息值:\ref ZC_MSG_SYSDORCTOR_ALARMHOSTINFO（52026）
	*       APP相关:\ref MSG_REQ_NEW_ALARMPARTION（1161）\ref P_AlarmPartionInfo \ref S_AlarmPartionInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_ALARMHOSTINFO,

	/**
	* @brief (20527)请求获取所有报警主机布撤防计划信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref ALARMARMDISARMPLAN_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_ALARMARMDISARMPLAN（52027）
	* @note APP相关:\ref MSG_REG_NEW_ALARMARMDISARMPLAN_GET（519）
	*/
    ZC_MSG_APP_SYSDORCTOR_ALARMARMDISARMPLAN,

	/**
	* @brief (20528)请求获取所有主机使用状态信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref HOSTUSESTATUSGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_HOSTUSESTATUS（52028）
	* @note APP相关:\ref MSG_REG_NEW_HOSTUSESTATUS_GET（522）
	*/
    ZC_MSG_APP_SYSDORCTOR_HOSTUSESTATUS,
	
	/**
	* @brief (20529)请求获取所有探头使用状态信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DETECTORUSESTATUSGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DETECTORUSESTATUS（52029）
	* @note APP相关:\ref MSG_REG_NEW_DETECTORUSESTATUS_GET（523）
	*/
	ZC_MSG_APP_SYSDORCTOR_DETECTORUSESTATUS,

	/**
	* @brief (20530)请求查询设备基本资产信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref DEVICEBASEINFOGET_IN_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DEVICEBASEINFOGET_OUT_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVCAPITALINFO（52030）
	* @note APP相关:\ref MSG_REG_NEW_DEVICEBASEINFO_GET（514）
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVCAPITALINFO = 20530,  
	
	/**
	* @brief (20531)请求修改设备基本资产信息
	* 
	* 消息服务仅对消息长度做判断，内容不做处理，长度符合条件时直接调用APP接口进行数据提交（不存在测试数据）
	* 
	* @note 请求结构体:\ref CAPITALINFOOPERATION_P 
	*       返回结构体:\ref ZC_MSG_RESP_RESULT
	*       反馈消息值:\ref ZC_MSG_SYSDORCTOR_SETDEVCAPITALINFO（52031）
	*       APP相关:\ref MSG_REG_NEW_CAPITALINFO_OPERATION（500）\ref CAPITALINFOOPERATION_P
	*/
	ZC_MSG_APP_SYSDORCTOR_SETDEVCAPITALINFO,  

	/**
	* @brief (20532)请求统计设备基本资产信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref CAPITALINFOSTATISTICS_IN_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref CAPITALINFOSTATISTICS_OUT_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_STATDEVCAPITALINFO（52032）
	* @note APP相关:\ref MSG_REG_NEW_CAPITALINFO_STATISTICS（520）
	*/
	ZC_MSG_APP_SYSDORCTOR_STATDEVCAPITALINFO,   

    /**
	* @brief (20533)请求获取通道录像模板天数信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref OMRECORDDAYSMODULEGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_OMRECORDDAYSMODULE（52033）
	* @note APP相关:\ref MSG_REG_NEW_OMRECORDDAYSMODULE_GET（533）
	*/
	ZC_MSG_APP_SYSDORCTOR_OMRECORDDAYSMODULE,

    /**
	* @brief (20534)请求获取通道录像模板是否启用信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DETECTMODULEINFOGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DETECTMODULEINFO（52034）
	* @note APP相关:\ref MSG_REG_NEW_DETECTMODULEINFO_GET（538）
	*/
	ZC_MSG_APP_SYSDORCTOR_DETECTMODULEINFO,

    /**
	* @brief (20535)请求根据录像天数模板ID获取关联摄像头信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref SOFTSETCHANNELRECORDDAYSGET_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref SOFTSETCHANNELRECORDDAYSGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_SOFTSETCHANNELRECORDDAYS（52035）
	* @note APP相关:\ref MSG_REG_NEW_SOFTSETCHANNELRECORDDAYS_GET（542）
	*/
	ZC_MSG_APP_SYSDORCTOR_SOFTSETCHANNELRECORDDAYS,

    /**
	 * @brief (20536)请求获取一键运维信息
	 * 
	 * 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref NULL 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_GetIOMOperationInfo *N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_IOMOPERATIONINFO（52036）
	 * @note APP相关:\ref MSG_REG_NEW_IOMOPERATIONINFO_GET（547）
	 */
	ZC_MSG_APP_SYSDORCTOR_IOMOPERATIONINFO,

	/**
	* @brief (20540)请求获取所有故障现象信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref NULL 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref FAULTNAMEGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_FAULTINFO（52040）
	* @note APP相关:\ref MSG_REG_NEW_FAULTNAME_GET（516）
	*/
	ZC_MSG_APP_SYSDORCTOR_FAULTINFO = 20540,       

	/**
	* @brief (20541)请求查询报修记录信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref MALFUNCTIONINFOGET_IN_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref MALFUNCTIONINFOGET_OUT_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO（52041）
	* @note APP相关:\ref MSG_REG_NEW_MALFUNCTIONINFO_GET（515）
	*/
	ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO,  

	/**
	* @brief (20542)请求获取维修记录信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref MAINTENCEINFOIN_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref MAINTENCEINFOGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MAINTENCEINFO（52042）
	* @note APP相关:\ref MSG_REG_NEW_MAINTENCEINFO_GET（517）
	*/
	ZC_MSG_APP_SYSDORCTOR_MAINTENCEINFO, 
	
	/**
	* @brief (20543)请求新增报修记录信息
	* 
	* 消息服务仅对消息长度做判断，内容不做处理，长度符合条件时直接调用APP接口进行数据提交（不存在测试数据）
	* 
	* @note 请求结构体:\ref MALFUNCTIONINSERT_P 
	*       返回结构体:\ref ZC_MSG_RESP_RESULT
	*       反馈消息值:\ref ZC_MSG_SYSDORCTOR_ADDMALFUNCTIONINFO（52043）
	*       APP相关:\ref MSG_REG_NEW_MALFUNCTION_INSERT（502）\ref MALFUNCTIONINSERT_P
	*/
	ZC_MSG_APP_SYSDORCTOR_ADDMALFUNCTIONINFO, 

	/**
	* @brief (20544)请求新增维修记录信息
	* 
	* 消息服务仅对消息长度做判断，内容不做处理，长度符合条件时直接调用APP接口进行数据提交（不存在测试数据）
	* 
	* @note 请求结构体:\ref MAINTENCEINFOINSERT_P 
	*       返回结构体:\ref ZC_MSG_RESP_RESULT
	*       反馈消息值:\ref ZC_MSG_SYSDORCTOR_ADDMAINTENCEINFO（52044）
	*       APP相关:\ref MSG_REG_NEW_MAINTENCEINFO_INSERT（503）\ref MAINTENCEINFOINSERT_P
	*/
	ZC_MSG_APP_SYSDORCTOR_ADDMAINTENCEINFO,   

	/**
	* @brief (20545)请求统计报修记录信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref MALFUNCTIONINFOSTATISTICS_IN_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref MALFUNCTIONINFOSTATISTICS_OUT_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_STATMALFUNCTIONINFO（52045）
	* @note APP相关:\ref MSG_REG_NEW_MALFUNCTIONINFO_STATISTICS（521）
	*/
	ZC_MSG_APP_SYSDORCTOR_STATMALFUNCTIONINFO,  

	/**
	* @brief (20546)根据设备编号请求设备基本信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref DEVICEBASEINFOBYIDGET_SOFTSET_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DEVICEBASEINFOBYIDGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVICEBASEINFOBYID（52046）
	* @note APP相关:\ref MSG_REG_NEW_DEVICEBASEINFOBYID_CLIENT_GET（526）
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOBYID,

    /**
	* @brief (20547)根据设备资产编号请求设备基本信息
	* 
	* 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	* 
	* @note 请求结构体:\ref DEVICEBASEINFOBYIDGET_CLIENT_P 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DEVICEBASEINFOBYIDGET_S *N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVICEBASEINFOBYCAPITALCODE（52047）
	* @note APP相关:\ref MSG_REG_NEW_DEVICEBASEINFOBYID_CLIENT_GET（526）
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOBYCAPITALCODE,

	/**
	 * @brief (20548)获取设备基础信息_NEW
	 * 
	 * 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref DEVICEBASEINFOGET_NEW_IN_P
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DEVICEBASEINFOGET_NEW_OUT_S *N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVICEBASEINFOGET_NEW（52048）
	 * @note APP相关:\ref MSG_REG_NEW_DEVICEBASEINFO_GET_NEW（550）
	 */
	ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOGET_NEW,

	/**
	 * @brief (20549)报修记录信息查询_NEW
	 * 
	 * 消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref MALFUNCTIONINFOGET_NEW_IN_P 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref MALFUNCTIONINFOGET_NEW_OUT_S *N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO_GET_NEW（52049）
	 * @note APP相关:\ref MSG_REG_NEW_MALFUNCTIONINFO_GET_NEW（551）
	 */
	ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO_GET_NEW,

    /**
	 * @brief (20550)通道检查模板相关操作
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_CHANNELDETECTMODULEOPERATION_NEW 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_CHANNELDETECTMODULE_OPERATION_NEW （52083）
	 * @note APP相关:\ref MSG_REG_NEW_CHANNELDETECTMODULE_OPERATION_NEW（563）
	 */
    ZC_MSG_APP_SYSDORCTOR_CHANNELDETECTMODULE_OPERATION_NEW,

    /**
	 * @brief (20551)智能运维获取录像天数模板
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref NULL 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_OMRECORDDAYSMODULEGET_NEW * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_OMRECORDDAYSMODULE_GET_NEW （52084）
	 * @note APP相关:\ref MSG_REG_NEW_OMRECORDDAYSMODULE_GET_NEW（564）
	 */
    ZC_MSG_APP_SYSDORCTOR_OMRECORDDAYSMODULE_GET_NEW,

    /**
	 * @brief (20552)报修管理数据项获取
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_MalfuctionInfoGet 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_MalfuctionInfoGet * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MALFUNCTION_NEW_GET （52085）
	 * @note APP相关:\ref MSG_REG_NEW_MALFUNCTION_NEW_GET（565）
	 */
    ZC_MSG_APP_SYSDORCTOR_MALFUNCTION_NEW_GET,

	/**
	 * @brief (20553)智能运维故障处理记录
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_FaultTreatment 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_FaultTreatment * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_FAULTTREATMENT_GET （52086）
	 * @note APP相关:\ref MSG_REG_NEW_FAULTTREATMENT_GET（566）
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTTREATMENT_GET,

    /**
	 * @brief (20554)智能运维维修记录
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_MaintenanceRecord 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_MaintenanceRecord * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MAINTENANCERECORD_GET （52087）
	 * @note APP相关:\ref MSG_REG_NEW_MAINTENANCERECORD_GET（567）
	 */
    ZC_MSG_APP_SYSDORCTOR_MAINTENANCERECORD_GET,

    /**
	 * @brief (20555)智能运维复核与评价记录
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_ReviewAndEvaluation 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_ReviewAndEvaluation * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_REVIEWANDEVALUTION_GET （52088）
	 * @note APP相关:\ref MSG_REG_NEW_REVIEWANDEVALUTION_GET（568）
	 */
    ZC_MSG_APP_SYSDORCTOR_REVIEWANDEVALUTION_GET,

    /**
	 * @brief (20556)智能运维故障记录写入
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_FaultDeviceInfoIns 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_FAULTDEVICEINFO_ADD （52089）
	 * @note APP相关:\ref MSG_REG_NEW_FAULTDEVICEINFO_ADD（569）
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTDEVICEINFO_ADD,

    /**
	 * @brief (20557)智能运维故障处理记录写入
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_FaultDeviceHandleInfoIns 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_FAULTDEVICEHANDLEINFO_ADD （52090）
	 * @note APP相关:\ref MSG_REG_NEW_FAULTDEVICEHANDLEINFO_ADD（570）
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTDEVICEHANDLEINFO_ADD,

	/**
	 * @brief (20558)智能运维报修记录写入
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_MalfuctionInfo_Ins 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO_ADD （52091）
	 * @note APP相关:\ref MSG_REG_NEW_MALFUNCTIONINFO_ADD（571）
	 */
    ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO_ADD,

	/**
	 * @brief (20559)智能运维维修记录写入
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_MaintenanceInfo_Ins 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MAINTENCEINFO_ADD （52092）
	 * @note APP相关:\ref MSG_REG_NEW_MAINTENCEINFO_ADD（572）
	 */
    ZC_MSG_APP_SYSDORCTOR_MAINTENCEINFO_ADD,

    /**
	 * @brief (20560)智能运维复核记录写入
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_CheckInfo_Ins 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_CHECKINFO_ADD （52093）
	 * @note APP相关:\ref MSG_REG_NEW_CHECKINFO_ADD（573）
	 */
    ZC_MSG_APP_SYSDORCTOR_CHECKINFO_ADD,

	/**
	 * @brief (20561)设备历史故障检索
	 * 
	 * 20170601新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_DeviceFaultGet 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_DeviceHistoryFaultGet
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVICEFAULTINFO_SET （52094）
	 * @note APP相关:\ref MSG_REG_NEW_DEVICEFAULTINFO_SET（574）
	 */
    ZC_MSG_APP_SYSDORCTOR_DEVICEFAULTINFO_SET,

    /**
	 * @brief (20562)获取故障异常详情
	 * 
	 * 20170607新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_FaultExtremelyInfoGet 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_FaultExtremelyInfoGet
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_NEW_FAULTEXTREMELYINFO_GET （52095）
	 * @note APP相关:\ref MSG_REG_NEW_FAULTEXTREMELYINFO_GET（575）
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_FAULTEXTREMELYINFO_GET,

	/**
	 * @brief (20563)IOM区分具体故障类型故障记录写入
	 * 
	 * 20170607新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_FaultDeviceInfoAdditionalIns 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_NEWFAULTDEVICEADDITIONAL_ADD （52096）
	 * @note APP相关:\ref MSG_REG_NEWFAULTDEVICEADDITIONAL_ADD（576）
	 */
    ZC_MSG_APP_SYSDORCTOR_NEWFAULTDEVICEADDITIONAL_ADD,

	/**
	 * @brief (20564)厂商信息操作
	 * 
	 * 20170609新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_SupplierMaintenanceOperation 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_NEW_SUPPLIERMAINTENANCE_OPERATION （52097）
	 * @note APP相关:\ref MSG_REG_NEW_SUPPLIERMAINTENANCE_OPERATION（559）
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_SUPPLIERMAINTENANCE_OPERATION,

	/**
	 * @brief (20565)厂商信息获取
	 * 
	 * 20170609新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_SupplierMaintenanceInfo 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_SupplierMaintenanceInfo * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_NEW_SUPPLIERMAINTENANCEINFO_GET （52098）
	 * @note APP相关:\ref MSG_REG_NEW_SUPPLIERMAINTENANCEINFO_GET（560）
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_SUPPLIERMAINTENANCEINFO_GET,

    /**
	 * @brief (20566)资产信息操作
	 * 
	 * 20170609新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_CapticalInfoNewOperation 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_NEW_CAPTICALINFONEW_OPERATION （52099）
	 * @note APP相关:\ref MSG_REG_NEW_CAPTICALINFONEW_OPERATION（561）
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_CAPTICALINFONEW_OPERATION,

    /**
	 * @brief (20567)资产信息获取
	 * 
	 * 20170609新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_CapticalInfoNewGet 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_CapticalInfoNewGet * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_NEW_CAPTICALINFO_NEW_GET （52100）
	 * @note APP相关:\ref MSG_REG_NEW_CAPTICALINFO_NEW_GET（562）
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_CAPTICALINFO_NEW_GET,

	/**
	 * @brief (20568)获取巡检计划
	 * 
	 * 20170614新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref NULL 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref DETECTSCHEDULEGET_S * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_NEW_DETECTSCHEDULE_GET （52101）
	 * @note APP相关:\ref MSG_REG_NEW_DETECTSCHEDULE_GET（524）
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_DETECTSCHEDULE_GET,

	/**
	 * @brief (20569)资产状态统计_Additional
	 * 
	 * 20170620新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_CapticalAdditionalInfoGet 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_CapticalAdditionalInfoGet * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_CAPTICALADDITIONALINFO_GET （52102）
	 * @note APP相关:\ref MSG_REG_CAPTICALADDITIONALINFO_GET（579）
	 */
    ZC_MSG_APP_SYSDORCTOR_CAPTICALADDITIONALINFO_GET,

	/**
	 * @brief (20570)资产状态统计
	 * 
	 * 20170620新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_CapticalStatisticsInfoGet 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_CapticalStatisticsInfoGet * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_CAPTICALSTATISTICSINFO_GET （52103）
	 * @note APP相关:\ref MSG_REG_CAPTICALSTATISTICSINFO_GET（580）
	 */
    ZC_MSG_APP_SYSDORCTOR_CAPTICALSTATISTICSINFO_GET,

	/**
	 * @brief (20571)故障统计
	 * 
	 * 20170620新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_FaultTypeStatisticsInfoGet 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_FaultTypeStatisticsInfoGet * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_FAULTSTATISTICSINFO_GET （52104）
	 * @note APP相关:\ref MSG_REG_FAULTSTATISTICSINFO_GET（581）
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTSTATISTICSINFO_GET,

	/**
	 * @brief (20572)维保服务统计
	 * 
	 * 20170620新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_MaintenanceStatisticsInfoGet 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_MaintenanceStatisticsInfoGet * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_MAINTENANCESTATISTICSINFO_GET （52105）
	 * @note APP相关:\ref MSG_REG_MAINTENANCESTATISTICSINFO_GET（582）
	 */
    ZC_MSG_APP_SYSDORCTOR_MAINTENANCESTATISTICSINFO_GET,

	/**
	 * @brief (20573)网点异常资产统计
	 * 
	 * 20170719新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_GetCapticalAreaExceptionInfo 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_GetCapticalAreaExceptionInfo * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_CAPTICALAREAEXCEPTIONINFO_GET （52106）
	 * @note APP相关:\ref MSG_REG_GETCAPTICALAREAEXCEPTIONINFO_GET（583）
	 */
    ZC_MSG_APP_SYSDORCTOR_CAPTICALAREAEXCEPTIONINFO_GET,

	/**
	 * @brief (20574)IOM批量报修处理
	 * 
	 * 20170725新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_BatchMalfunctionInfo 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_BATCHMALFUNCTIONINFO_SET （52107）
	 * @note APP相关:\ref MSG_REG_BATCHMALFUNCTIONINFO_SET（584）
	 */
    ZC_MSG_APP_SYSDORCTOR_BATCHMALFUNCTIONINFO_SET,

	/**
	 * @brief (20575)根据设备信息获取故障ID
	 * 
	 * 20170815新增接口，消息服务不做缓存处理，该接口返回APP获取到的最新数据
	 * 
	 * @note 请求结构体:\ref P_GetFaultIdByDeviceDetailInfo 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref S_GetFaultIdByDeviceDetailInfo * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_FAULTIDBYDEVICEDETAILINFO_GET （52108）
	 * @note APP相关:\ref MSG_REG_FAULTIDBYDEVICEDETAILINFO_GET（585）
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTIDBYDEVICEDETAILINFO_GET,

	ZC_MSG_APP_ROLEINFO = 29000,        ///<(29000)请求系统中角色信息，反馈ZC_MSG_COMMON_ROLEINFO
	ZC_MSG_APP_CHILDROLEINFO,           ///<(29001)请求获取某角色的下属角色信息，反馈ZC_MSG_COMMON_CHILDROLEINFO
	ZC_MSG_APP_PLANINFO,                ///<(29002)请求预案库信息，反馈ZC_MSG_COMMON_PLANINFO 
	ZC_MSG_APP_USERIMAGEID,             ///<(29003)请求获取某用户头像信息（1），反馈ZC_MSG_COMMON_USERIMAGEID
	ZC_MSG_APP_CURUSERINFOEX,           ///<(29004)请求获取当前用户信息，反馈ZC_MSG_COMMON_CURUSERINFOEX
	ZC_MSG_APP_ALLUSERINFO,             ///<(29005)请求所有用户信息，反馈ZC_MSG_COMMON_ALLUSERINFO
	ZC_MSG_APP_USERSTATE,               ///<(29006)请求获取用户状态，反馈ZC_MSG_COMMON_USERSTATE 
	ZC_MSG_APP_USERALLINFO,             ///<(29007)请求获取某用户详细信息，反馈ZC_MSG_COMMON_USERALLINFO
	ZC_MSG_APP_ALLSUBORDINATEINFO,      ///<(29008)请求获取用户所有下属信息，反馈ZC_MSG_COMMON_ALLSUBORDINATEINFO
    ZC_MSG_APP_CLASSMONITOR,            ///<(29009)请求获取用户同一班次上级角色信息，反馈ZC_MSG_COMMMON_CLASSMONITOR
	ZC_MSG_APP_USERMONITOR,             ///<(29010)请求获取用户上级角色信息，反馈ZC_MSG_COMMON_USERMONITOR
	ZC_MSG_APP_ALLCLASSSUBORDINATEINFO, ///<(29011)请求获取用户同一班次所有下属信息，反馈ZC_MSG_COMMON_ALLCLASSSUBORDINATEINFO
    ZC_MSG_APP_EVENTINFO,               ///<(29012)请求获取事件库信息，反馈ZC_MSG_COMMON_EVENTINFO	
	
	ZC_MSG_APP_ALLAREAINFO = 29050,     ///<(29050)请求所有区域信息，反馈ZC_MSG_COMMON_ALLAREAINFO
	ZC_MSG_APP_ALLALARMTYPEINFO,        ///<(29051)请求所有报警类型信息，反馈ZC_MSG_COMMON_ALLALARMTYPEINFO 
	ZC_MSG_APP_ALLALARMLEVELINFO,       ///<(29052)请求所有报警等级信息，反馈ZC_MSG_COMMON_ALLALARMLEVELINFO
	ZC_MSG_APP_ALLALARMDEALSTATEINFO,   ///<(29053)请求报警处理状态种类信息，反馈ZC_MSG_COMMON_ALLALARMDEALSTATEINFO
	ZC_MSG_APP_ALARMDEALTYPE,           ///<(29054)请求所有报警处置类型，反馈ZC_MSG_COMMON_ALARMDEALTYPE
	ZC_MSG_APP_ALARMDECIDETYPE,         ///<(29055)请求所有报警定性戳类型，反馈ZC_MSG_COMMON_ALARMDECIDETYPE
	ZC_MSG_APP_ALLKEYPARTINFO,          ///<(29056)请求所有部位信息，反馈ZC_MSG_COMMON_ALLKEYPARTINFO
    ZC_MSG_APP_ALLDEVICEINFO,           ///<(29057)请求所有主机详细信息，反馈ZC_MSG_COMMON_ALLDEVICEINFO
	            
	ZC_MSG_APP_DUTYSTATUSSET = 29100,     ///<(29100)请求设置用户状态，反馈ZC_MSG_COMMON_SETDUTYSTATUS
}E_ZC_MSG_APP;
/** @} */

/** @defgroup ZCBCBMsgTypeDefine BCB客户端模块响应消息类型枚举    
 * 定义BCB客户端模块响应消息类型值
 * @{
 */
typedef enum
{
    ZC_MSG_BCBCLIENT_CURUSER    = 30000,     ///<(30000)请求当前用户信息，反馈ZC_MSG_COMMON_CURUSER
	ZC_MSG_BCBCLIENT_NEWUSER,                ///<(30001)请求以新用户登录（2），反馈ZC_MSG_HANDOVER_NEWUSER
	ZC_MSG_BCBCLIENT_DOWNLOADPIC,            ///<(30002)请求下载图片，反馈ZC_MSG_COMMON_DOWNLOADPIC
	ZC_MSG_BCBCLIENT_ONLINEUSER,             ///<(30003)请求在线用户信息，反馈ZC_MSG_COMMON_ONLINEUSER
	ZC_MSG_BCBCLIENT_UPLOADATTACHMENT,       ///<(30004)请求上传附件，反馈ZC_MSG_COMMON_UPLOADATTACHMENT

    /**
	 * @brief (30005)请求打开某个通道视频
     *
     * 支持批量操作
	 *
	 * @note 请求结构体:\ref char chCameraName[64] * N  通道名称组
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_COMMON_OPENCAMERA (105)
	 */
    ZC_MSG_BCBCLIENT_OPENCAMREA,

    /**
	* @brief (30050)请求从存储服务器下载报警联动附件
	* 
	* BCB客户端同一时刻仅能处理一条该消息，暂不设定超时时间
	*
	* @note 请求结构体:\ref CLIENTGETMEDIASTORAGEATTACHMENT_S
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + char chFilePath[260]
	* @note 反馈消息值:\ref ZC_MSG_COMMON_GETALARMATTACHMENTFROMMS (2020)
	* @note BCB消息处理类:CZCMsgDealGetAlarmAttachmentFromMs
	*
	* @note 错误码说明：
	* @note ①请求参数长度不正确，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	*/
	ZC_MSG_BCBCLIENT_GETALARMATTACHMENTFROMMS = 30050,

    /**
	* @brief (30051)请求从存储服务器回放报警联动视频附件
	* 
	* BCB客户端同一时刻仅能处理一条该消息，暂不设定超时时间
	*
	* @note 请求结构体:\ref CLIENTGETMEDIASTORAGEATTACHMENT_S
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	* @note 反馈消息值:\ref ZC_MSG_COMMON_PLAYBACKALARMATTACHMENTFROMMS (2021)
	* @note BCB消息处理类:CZCMsgDealPlayBackAlarmAttachmentFromMs
	*
	* @note 错误码说明：
	* @note ①请求参数长度不正确，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	*/
	ZC_MSG_BCBCLIENT_PLAYBACKALARMATTACHMENTFROMMS,

	/**
	 * @brief (30090)请求跟第三方系统交换消息
	 *
	 * @note 请求结构体:请求消息类型值 + 消息类型对应的结构体
	 * @note 请求消息类型说明如下：
	 * @note #define THIRDPART_MESSAGE_SY_SCHEDULE_INFO		3000	//获取指定网点的押运排班信息(守押)[REQ:int,组织机构id][RESP:TSyScheduleList]
	 * @note #define THIRDPART_MESSAGE_SY_IMAGE				3001	//获取各种类型的图片(守押)[REQ:TSyGetImage][RESP:TSyImageId]
	 * @note #define THIRDPART_MESSAGE_SY_SERVER_TIME		3002	//获取服务器时间(守押)[REQ：无][RESP:T_TIME_INFO]
	 * @note #define THIRDPART_MESSAGE_SY_ROUTE_STATUS		3003	//获取指定网点押运路线的状态(守押)[REQ:int,组织结构id][RESP:TSyRouteList]
	 * @note #define THIRDPART_MESSAGE_SY_TAG_DATA			3004	//获取电子标签卡的详细信息(守押)[REQ:TSyGetTagData][RESP:TSyTagDataList]
	 * @note 请求结构体示例：
	 * @code
	   //此处以THIRDPART_MESSAGE_SY_SCHEDULE_INFO(3000)为例
	   //请求参数，组织机构ID为假数据
	   int nMsgType = THIRDPART_MESSAGE_SY_SCHEDULE_INFO;
	   int nOrganizationId = 1;
       //赋值参数
	   int nParamLen = sizeof(int) + sizeof(int); //消息类型值+组织机构id
	   BYTE* pRequestParam = new BYTE[nParamLen];
       memcpy((int*)pRequestParam,&nMsgType,sizeof(int));
	   memcpy((int*)&pRequestParam[sizeof(int)], &nOrganizationId, sizeof(int));
	   //调用通信组件发送参数
	   CZCMsgManager::SendMsg(..,..,..,pRequestParam,nParamLen);
       delete[] pRequestParam;
	   pRequestParam = NULL; 
	 * @endcode
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + 请求消息类型值（int） + 对应消息类型的反馈结构体
	 * @note 反馈消息值:\ref ZC_MSG_COMMON_THIRDPART_EXCHANGEMESSAGE (2025)
	 * @note BCB消息处理类:CMsgDealThirdPartExchangeMessageUnit
     *
	 * @note 错误码说明：
	 * @note ①请求消息类型值与对应的结构体长度不符，返回\ref BCBC_ERROR_PARAMERROR
	 * @note ②请求消息类型值不在3000-3004之间，返回\ref BCBC_ERROR_UNKNOWNMSG
	 * @note ②服务库接口返回失败，返回\ref BCBC_ERROR_THRIDPARTREQUESTFAILED
	 */
	ZC_MSG_BCBCLIENT_THIRDPART_EXCHANGEMESSAGE = 30090,

    /**
	 * @brief (30091)请求向考拉报警代理发送消息
	 *
	 * @note 请求结构体:\ref 平台考拉报警代理定义的各种结构体
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_COMMON_TRANSCOMMONMSGTOKOALA (50105）
	 */
    ZC_MSG_BCBCLIENT_TRANSCOMMONMSGTOKOALA,

	ZC_MSG_BCBCLIENT_STARTTASKCHECK  = 30100,     ///<(30100)请求开始执行任务（9），反馈ZC_MSG_TASK_STARTTASKCHECK
	ZC_MSG_BCBCLIENT_STOPTASKCHECK,               ///<(30101)请求停止执行任务，反馈ZC_MSG_TASK_STOPTASKCHECK
	
    ZC_MSG_BCBCLIENT_CAPTUREPIC,             ///<(30102)请求抓取图片，反馈ZC_MSG_TASK_CAPTUREPIC
    ZC_MSG_BCBCLIENT_SHORTMESSAGE,           ///<(30103)请求发送短信（10），反馈ZC_MSG_TASK_SHORTMESSAGE
    ZC_MSG_BCBCLIENT_TELEPHONECALL,          ///<(30104)请求拨打电话（11），反馈ZC_MSG_TASK_TELEPHONECALL	
    
	ZC_MSG_BCBCLIENT_TRANSFASTTASK,          ///<(30105)请求下发快速任务（12），反馈ZC_MSG_TASK_TRANSFASTTASK
	ZC_MSG_BCBCLIENT_STARTCHECKPLAYBACK,     ///<(30106)请求开始巡检回放，反馈ZC_MSG_TASK_STARTCHECKPLAYBACK
    ZC_MSG_BCBCLIENT_STOPCHECKPLAYBACK,      ///<(30107)请求停止巡检回放，反馈ZC_MSG_TASK_STOPCHECKPLAYBACK
	
	ZC_MSG_BCBCLIENT_ALARMPOSITION = 30200,       ///<(30200)请求进入所属图层，反馈ZC_MSG_ALARM_ALARMPOSITION 
    ZC_MSG_BCBCLIENT_CONCEALALARM,                ///<(30201)请求屏蔽某报警源，反馈ZC_MSG_ALARM_CONCEALALARM
   	ZC_MSG_BCBCLIENT_ALARMLINKVIDEO,              ///<(30202)请求打开报警关联视频，反馈ZC_MSG_ALARM_ALARMLINKVIDEO
	ZC_MSG_BCBCLIENT_ALARNEARBYVIDEO,             ///<(30203)请求观看报警附近视频，反馈ZC_MSG_ALARM_ALARNEARBYVIDEO
    ZC_MSG_BCBCLIENT_ALARMREPLAY,                 ///<(30204)请求观看报警录像回放，反馈ZC_MSG_ALARM_ALARMREPLAY 
	ZC_MSG_BCBCLIENT_DEFENCEDEV,                  ///<(30205)请求布撤防设备，反馈ZC_MSG_ALARM_DEFENCEDEV
	ZC_MSG_BCBCLIENT_CONTROLDEV,                  ///<(30206)请求控制设备（外设控制、开关门），反馈ZC_MSG_ALARM_CONTROLDEV
	ZC_MSG_BCBCLIENT_DEVTALK,                     ///<(30207)请求联动对讲，反馈ZC_MSG_ALARM_DEVTALK
	ZC_MSG_BCBCLIENT_DOWNANDUPLOADVIDEO,          ///<(30208)请求下载录像并上传，反馈ZC_MSG_ALARM_DOWNANDUPLOADVIDEO
    ZC_MSG_BCBCLIENT_ALARMMAPINFO,                ///<(30209)请求获取报警布防图信息，反馈ZC_MSG_ALARM_ALARMMAPINFO	
    ZC_MSG_BCBCLIENT_ALARMPOSITION_UNLOCK,        ///<(30210)请求解锁当前图层， 反馈 ZC_MSG_ALARM_ALARMPOSITION_UNLOCK
    ZC_MSG_BCBCLIENT_ALARMREPLAY_CLOSE,           ///<(30211)请求关闭报警录像回放（适用第三方认证,与ZC_MSG_BCBCLIENT_ALARMREPLAY动作对应)，反馈ZC_MSG_ALARM_ALARMREPLAY_CLOSE
   
    /**
	* @brief (30212)请求打开第三方认证处置联动视频
	*
	* @note 请求结构体:\ref T_OPENDOORLINKVIDEOPRARM
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	* @note 反馈消息值:\ref ZC_MSG_OPENDOOR_OPENLINKVIDEO (51104)
	*/
    ZC_MSG_BCBCLIENT_OPENDOORLINKVIDEO,

    /**
	* @brief (30213)请求节点闪烁
	*
	* @note 请求结构体:\ref T_OPENDOORLINKVIDEOPRARM
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	* @note 反馈消息值:\ref ZC_MSG_COMMON_FLASHNODE (51104)
	*/
    ZC_MSG_BCBCLIENT_FLASHNODE,
	
	ZC_MSG_BCBCLIENT_ADDEVENT = 30250,            ///<(30250)请求添加动态信息（17），反馈ZC_MSG_COMMON_ADDEVENT                 
    ZC_MSG_BCBCLIENT_SENDEMAIL,                   ///<(30251)请求发送邮件，反馈ZC_MSG_COMMON_SENDEMAIL
	ZC_MSG_BCBCLIENT_CLOSEALLVIDEO,               ///<(30252)请求关闭所有视频窗口，反馈ZC_MSG_COMMON_CLOSEALLVIDEO
    ZC_MSG_BCBCLIENT_DEVTALKBYID,                 ///<(30253)请求通过对讲设备ID进行对讲,反馈ZC_MSG_COMMON_DEVTALKBYID
	ZC_MSG_BCBCLIENT_CONTROLACSHOST,              ///<(30254)请求控制门禁主机（21），反馈ZC_MSG_COMMON_CONTROLACSHOST

	ZC_MSG_BCBCLIENT_STARTLISTENMANUALCAPTURE = 30280,    ///<(30280)请求开始监听手动抓图消息，反馈ZC_MSG_OPENDOOR_STARTLISTENMANUALCAPTURE
	ZC_MSG_BCBCLIENT_STOPLISTENMANUALCAPTURE,             ///<(30281)请求停止监听手动抓图消息，反馈ZC_MSG_OPENDOOR_STOPLISTENMANUALCAPTURE
	ZC_MSG_BCBCLIENT_CAPTUREWITHOUTOPEN,                  ///<(30282)请求在未打开视频时抓图（20），反馈ZC_MSG_OPENDOOR_CAPTUREWITHOUTOPEN  

    /**
	 * @brief (30299)请求通过中心给其他客户端转发消息
     *
     * 该接口比\ref ZC_MSG_BCBCLIENT_REQUESTTRANSMSG (30300)多一个客户端类型参数
	 *
	 * @note 请求结构体:\ref T_TRANS_COMMONHEADINFO_EX + 其他自定义消息内容
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_COMMON_REQUESTTRANSMSG_EX  (2299)
	 */
    ZC_MSG_BCBCLIENT_REQUESTTRANSMSG_EX = 30299,

	ZC_MSG_BCBCLIENT_REQUESTTRANSMSG = 30300, ///<(30300)请求通过中心给其他客户端转发消息（前4个字节表示接收的模块号），反馈\ref ZC_MSG_COMMON_REQUESTTRANSMSG (2300)

    /**
	* @brief (30301)请求向考拉平台提交设备报修信息
	*
	* @note 请求结构体:\ref TDeviceTroubleRepairToKoala
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	* @note 反馈消息值:\ref ZC_MSG_COMMON_TRANSDEVICETROUBLEMSGTOKOALA (2302)
	*/
    ZC_MSG_BCBCLIENT_TRANSDEVICETROUBLEMSGTOKOALA,

	/**
	 * @brief (30310)请求向考拉平台确认警情、指派人员处警、指派人员协助
	 *
	 * @note 请求结构体:\ref TRequestVerifyAlarmToKoala
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_TRANSREQUESTVERIFYALARMTOKOALA (50100) 
	 */
    ZC_MSG_BCBCLIENT_TRANSREQUESTVERIFYALARMTOKOALA = 30310,

    /**
	 * @brief (30311)请求向考拉平台上报报警预案、切换预案
	 *
	 * @note 请求结构体:\ref TDealAlarmInfoToKoala + \ref TDealStep * N
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_TRANSDEALALARMINFOTOKOALA (50101) 
	 */
    ZC_MSG_BCBCLIENT_TRANSDEALALARMINFOTOKOALA,

	/**
	 * @brief (30312)请求向考拉平台获取在线人员信息
	 *
	 * @note 请求结构体:\ref TGetOnlineUserToKoala
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_TRANSGETONLINEUSERTOKOALA (50102) 
	 */
    ZC_MSG_BCBCLIENT_TRANSGETONLINEUSERTOKOALA,

	/**
	 * @brief (30313)请求向考拉平台上报报警处置进度
	 *
	 * @note 请求结构体:\ref TDealStepToKoala
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_TRANSDEALSTEPTOKOALA (50103) 
	 */
    ZC_MSG_BCBCLIENT_TRANSDEALSTEPTOKOALA,

    /**
	 * @brief (30314)请求向考拉平台上报处置结束信息
	 *
	 * @note 请求结构体:\ref TDealEndToKoala
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_TRANSDEALENDTOKOALA (50104) 
	 */
    ZC_MSG_BCBCLIENT_TRANSDEALENDTOKOALA,

	/**
	 * @brief (30315)请求向考拉平台反馈收到处置结束消息
	 *
	 * @note 请求结构体:\ref TFeedBackToKoala
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 * @note 反馈消息值:\ref ZC_MSG_ALARM_TRANSFEEDBACKTOKOALA (50105） 
	 */
    ZC_MSG_BCBCLIENT_TRANSFEEDBACKTOKOALA,

    /**
	* @brief (30400)请求查询监控主机在线状态
	* 
	* BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；若是批量处理，则根据设备数，返回多条反馈信息；
	*
	* @note 请求结构体:\ref T_GET_DEV_STATE * N 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref ONLINESTATE
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DVRONLINESTATE（52060）
	* @note BCB消息处理类:CZCMsgDealDEVOnlineStateUnit
	*
	* @note 错误码说明：
	* @note ①请求参数为空或不能被T_GET_DEV_STATE整除，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	* @note ③中心查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_DVRONLINESTATE = 30400, 

    /**
	* @brief (30401)请求查询报警主机状态
	* 
	* BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；若是批量处理，则根据设备数，返回多条反馈信息；
	*
	* @note 请求结构体:\ref T_GET_DEV_STATE * N 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + \ref T_ALARMHOST_STATE * N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_ALARMHOSTSTATE（52061）
	* @note BCB消息处理类:CZCMsgDealAlarmHostStateUnit
	*
	* @note 错误码说明：
	* @note ①请求参数为空或不能被T_GET_DEV_STATE整除，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	* @note ③中心查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_ALARMHOSTSTATE,   

    /**
	* @brief (30402)请求查询监控主机时钟状态
	* 
	* BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；
	*
	* @note 请求结构体:\ref T_DEVID_INFO * N 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETDEVTIME * N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVTIMEINFO（52062）
	* @note BCB消息处理类:CZCMsgDealGetDevTimeUnit
	*
	* @note 错误码说明：
	* @note ①请求参数为空或不能被T_DEVID_INFO整除，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	* @note ③中心查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVTIMEINFO, 

    /**
	* @brief (30403)请求查询监控主机时钟状态
	* 
	* BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；
	*
	* @note 请求结构体:\ref T_DEVID_INFO * N 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE * N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_SETDEVTIMEINFO（52063）
	* @note BCB消息处理类:CZCMsgDealSetDevTimeUnit
	*
	* @note 错误码说明：
	* @note ①请求参数为空或不能被T_DEVID_INFO整除，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	* @note ③中心查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_SETDEVTIMEINFO,  

    /**
	* @brief (30404)请求查询监控主机通道状态
	* 
	* BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；若是批量处理，则根据设备数，返回多条反馈信息；
	*
	* @note 请求结构体:\ref T_GET_DEV_STATE * N 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + \ref T_CHANNEL_STATE * N（N由设备通道数决定，目前返回全部通道）
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVCHANNELSTATE（52064）
	* @note BCB消息处理类:CZCMsgDealDEVChannelStateUnit
	*
	* @note 错误码说明：
	* @note ①请求参数为空或不能被T_GET_DEV_STATE整除，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	* @note ③中心查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVCHANNELSTATE,  

    /**
	* @brief (30405)请求查询监控主机硬盘状态
	* 
	* BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；若是批量处理，则根据设备数，返回多条反馈信息；
	*
	* @note 请求结构体:\ref T_GET_DEV_STATE * N 
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + \ref T_DISK_STATE * N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVDISKSTATE（52065）
	* @note BCB消息处理类:CZCMsgDealDEVDiskStateUnit
	*
	* @note 错误码说明：
	* @note ①请求参数为空或不能被T_GET_DEV_STATE整除，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	* @note ③中心查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVDISKSTATE,    

    /**
	* @brief (30406)请求查询某通道的录像计划与录像文件
	* 
	* BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；暂不支持批量查询，且仅支持直连设备查询；
	*
	* @note 请求结构体:\ref T_GET_DEV_CHECKVIDEOINFO
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref T_GET_DEV_STATE [length28] + \ref TYNET_DVR_RECORD [length508]+ \ref  T_DEV_CHECKVIDEOFILEINFO [length32]* N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_DEVCHECKVIDEO（52066）
	* @note BCB消息处理类:CZCMsgDealDevCheckVideoUnit
	*
	* @note 错误码说明：
	* @note ①请求参数长度不等于T_GET_DEV_CHECKVIDEOINFO，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	* @note ③查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	* @note ④录像计划查询失败，返回\ref T_GET_DEV_CHECKVIDEOINFO
	* @note ⑤录像文件列表查询失败，返回\ref BCBC_ERROR_SEARCHFILELISTFAILED
	* @note ⑥录像文件回掉函数网路异常，返回\ref BCBC_ERROR_SEARCHFILELISTFAILED
	*/
    ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVCHECKVIDEO,

    /**
	* @brief (30407)请求查询门禁主机状态
	*
	* BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；若是批量处理，则根据设备数，返回多条反馈信息；
	*
	* @note 请求结构体:\ref T_GET_DEV_STATE * N
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + \ref T_ACCESS_STATE * N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_ACCESSSTATE（52067）
	* @note BCB消息处理类:CZCMsgDealAccseeStateUnit
	*
	* @note 错误码说明：
	* @note ①请求参数为空或不能被T_GET_DEV_STATE整除，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	* @note ③中心查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	*/
    ZC_MSG_BCBCLIENT_SYSDORCTOR_ACCESSSTATE,

    /**
	* @brief (30408)请求查询视频质量诊断巡检结果
	*
	* BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；若是批量处理，则根据设备数，返回多条反馈信息；
	*
	* @note 请求结构体:\ref T_GET_DEV_STATE * N
	* @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + ( \ref TPatrolResult + \ref TpatrolResultVideoQuality) * N
	* @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_VIDEOQUALITY（52068）
	* @note BCB消息处理类:CZCMsgDealVideoQualityUnit
	*
	* @note 错误码说明：
	* @note ①请求参数为空或不能被T_GET_DEV_STATE整除，返回\ref BCBC_ERROR_PARAMERROR
	* @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	* @note ③中心查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	*/
    ZC_MSG_BCBCLIENT_SYSDORCTOR_VIDEOQUALITY,

	/**
	 * @brief (30409)请求查询节点状态（服务器节点）结果
	 *
	 * BCB客户端同一时刻仅能处理一条该消息，超时时间为20s；若是批量处理，则根据设备数，返回多条反馈信息；
	 *
	 * @note 请求结构体:\ref T_GET_DEV_STATE * N
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + ( \ref TPatrolResult + \ref TpatrolResultNodeState) * N
	 * @note 反馈消息值:\ref ZC_MSG_SYSDORCTOR_NODESTATE（52069）
	 * @note BCB消息处理类:CZCMsgDealNodeStateUnit
	 *
	 * @note 错误码说明：
 	 * @note ①请求参数为空或不能被T_GET_DEV_STATE整除，返回\ref BCBC_ERROR_PARAMERROR
	 * @note ②正在处理该消息请求，返回\ref BCBC_ERROR_BUSY
	 * @note ③中心查询结果反馈超时，返回\ref BCBC_ERROR_TIMEOUT
	 */
    ZC_MSG_BCBCLIENT_SYSDORCTOR_NODESTATE,
}E_ZC_MSG_BCBCLIENT;
/** @} */

/** @defgroup ZCHandoverMsgTypeDefine 交接班模块响应消息类型枚举    
 * 定义交接班模块响应消息类型值
 * @{
 */
typedef enum
{
	ZC_MSG_HANDOVER_HA_INFO = 40000,        ///<(40000)用户交接班信息 @note 请求消息值:\ref ZC_MSG_APP_HA_INFO (20000) @note 反馈结构体:\ref T_USER_HA_INFO
	ZC_MSG_HANDOVER_HA_WAITUSERLIST,        ///<(40001)待接班人员信息 @note 请求消息值:\ref ZC_MSG_APP_HA_WAITUSERLIST (20001) @note 反馈结构体:\ref S_NEW_SHOW_HA_WAITUSERLIST
	ZC_MSG_HANDOVER_A_TASKINFO,             ///<(40002)值班员任务执行情况 @note 请求消息值:\ref ZC_MSG_APP_HA_A_TASKINFO (20002) @note 反馈结构体:\ref S_NEW_SHOW_HA_A_TASKINFO
	ZC_MSG_HANDOVER_M_TASKINFO,             ///<(40003)值班长任务执行情况 @note 请求消息值:\ref ZC_MSG_APP_HA_M_TASKINFO (20003) @note 反馈结构体:\ref S_NEW_SHOW_HA_M_TASKINFO
	ZC_MSG_HANDOVER_HA_ALARMINFO,           ///<(40004)未处理报警信息 @note 请求消息值:\ref ZC_MSG_APP_HA_ALARMINFO (20004) @note 反馈结构体:\ref S_NEW_SHOW_HA_ALARMINFO
	ZC_MSG_HANDOVER_ADD_HAINFO,             ///<(40005)交班信息提交结果 @note 请求消息值:\ref ZC_MSG_APP_ADD_HAINFO (20005) @note 反馈结构体:NULL
	ZC_MSG_HANDOVER_SEL_HAINFO,             ///<(40006)交接班历史查询结果 @note 请求消息值:\ref ZC_MSG_APP_SEL_HAINFO (20006) @note 反馈结构体:\ref S_NEW_SHOW_HA_INFO 
	ZC_MSG_HANDOVER_NEWUSER,                ///<(40007)新用户登录反馈
	ZC_MSG_HANDOVER_A_HISTORYINFO,          ///<(40008)值班员交接班历史详细信息 @note 请求消息值:\ref ZC_MSG_APP_HA_A_HISTORYINFO (20007) @note 反馈结构体:\ref S_NEW_SHOW_HA_A_TASKINFO
	ZC_MSG_HANDOVER_M_HISTORYINFO,          ///<(40009)值班长交接班历史详细信息 @note 请求消息值:\ref ZC_MSG_APP_HA_M_HISTORYINFO (20008) @note 反馈结构体:\ref S_NEW_SHOW_HA_M_TASKINFO
	ZC_MSG_HANDOVER_MODIFYALARMDEALMAN,     ///<(40010)批量修改报警处置人结果反馈 @note 请求消息值:\ref ZC_MSG_APP_HA_MODIFYALARMDEALMAN (20009) @note 反馈结构体:NULL
	ZC_MSG_HANDOVER_CURCLASSUSERINFO,       ///<(40011)当前班次所有用户信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_HA_CURCLASSUSERINFO (20010) @note 反馈结构体:\ref T_USER_HA_INFO  
}E_ZC_MSG_HANDOVER;
/** @} */

/** @defgroup ZCScheduleMsgTypeDefine 排班模块响应消息类型枚举    
 * 定义排班模块响应消息类型值
 * @{
 */
typedef enum
{
    ZC_MSG_SCHEDULE_DATEGROUPSET = 41000,    ///<(41000)操作日期组结果反馈
	ZC_MSG_SCHEDULE_DATEGROUPINFO,           ///<(41001)日期组信息反馈
	ZC_MSG_SCHEDULE_CLASSINFOSET,            ///<(41002)操作班次结果反馈
	ZC_MSG_SCHEDULE_CLASSINFO,               ///<(41003)班次信息反馈
	ZC_MSG_SCHEDULE_SCHEDULESET,             ///<(41004)设置排班信息结果反馈
	ZC_MSG_SCHEDULE_SCHEDULEINFO,            ///<(41005)获取排班信息反馈
	ZC_MSG_SCHEDULE_SC_USERINFO,             ///<(41006)待排班人员信息反馈
}E_ZC_MSG_SCHEDULE;
/** @} */

/** @defgroup ZCTaskMsgTypeDefine 巡检任务模块响应消息类型枚举  
 * 定义巡检任务模块响应消息类型值
 * @{
 */
typedef enum
{
    ZC_MSG_TASK_TASKINFOSET = 42000,    ///<(42000)操作任务结果反馈
	ZC_MSG_TASK_FASTTASKINFOSET,        ///<(42001)新增快速任务结果反馈
	ZC_MSG_TASK_TASKINFO,               ///<(42002)查询任务信息反馈
	ZC_MSG_TASK_DETAILEDTASKINFO,       ///<(42003)查询任务详细信息反馈
	ZC_MSG_TASK_TASKSTATESET,           ///<(42004)设置任务状态结果反馈
	ZC_MSG_TASK_TASKMODULEINFOSET,      ///<(42005)操作任务模板结果反馈
	ZC_MSG_TASK_TASKMODULEINFO,         ///<(42006)查询任务模板信息反馈
	ZC_MSG_TASK_DETAILEDTASKMODULEINFO, ///<(42007)查询任务模板详细信息反馈
	ZC_MSG_TASK_TASKOBJECTINFO,         ///<(42008)获取任务对象信息反馈 
	ZC_MSG_TASK_TASKKEYPARTINFO,        ///<(42009)获取任务部位信息反馈
	ZC_MSG_TASK_TASKLEVELINFO,          ///<(42010)获取任务重要程度信息反馈
	ZC_MSG_TASK_TASKOPERATIONINFO,      ///<(42011)获取任务操作类型反馈
	ZC_MSG_TASK_TASKEXCEPTIONINFO,      ///<(42012)获取异常类型反馈
	ZC_MSG_TASK_DETATASKEXCEPTIONINFO,  ///<(42013)获取异常类型详情反馈
	ZC_MSG_TASK_TASKCLASSROLEINFO,      ///<(42014)获取任务下发角色信息反馈
	ZC_MSG_TASK_CURONLINEUSERINFO,      ///<(42015)获取当前上班用户信息反馈
	ZC_MSG_TASK_TODAYTASKINFO,          ///<(42016)获取当前用户今日任务信息反馈
	ZC_MSG_TASK_TODAYTASKALLINFO,       ///<(42017)获取某条待执行任务信息反馈  
    ZC_MSG_TASK_TODAYTASKOBJECTINFO,    ///<(42018)获取某条待执行任务对象信息反馈
    ZC_MSG_TASK_TODAYTASKDOINFO,        ///<(42019)获取某条任务的已执行信息反馈
	ZC_MSG_TASK_USERTASKINFO,           ///<(42020)获取某用户多日任务信息反馈
	ZC_MSG_TASK_TASKEXCUTESET,          ///<(42021)新增任务执行信息结果反馈 
    ZC_MSG_TASK_CURUSERINFO,            ///<(42022)任务模块相关的当前用户信息反馈(8)	
	ZC_MSG_TASK_CHECKTASKINFO,          ///<(42023)查询任务信息反馈	
	ZC_MSG_TASK_SHOWTASKCHECKINFO,      ///<(42024)获取任务复核相关信息反馈
	ZC_MSG_TASK_SHOWTASKEPLANINFO,      ///<(42025)获取任务复核预案信息反馈
	ZC_MSG_TASK_ISQUALIFIEDMOD,         ///<(42026)设置任务执行是否合格反馈
	ZC_MSG_TASK_TASKCHECKRECORDSET,     ///<(42027)新增任务批阅记录反馈
	
	ZC_MSG_TASK_SHOWAREAERRORINFO,       ///<(42028)统计某具体网点异常项发生情况反馈
	ZC_MSG_TASK_SHOWAREAERRORATEINFO,    ///<(42029)统计网点的异常率反馈
	ZC_MSG_TASK_SHOWCOVERRATEINFO,       ///<(42030)统计巡检覆盖率反馈
	ZC_MSG_TASK_SHOWALARMRECORINFO,      ///<(42031)获取风险提醒信息反馈
	ZC_MSG_TASK_SHOWAREAERRORNUMINFO,    ///<(42032)统计单位时间内的网点异常数量反馈
	ZC_MSG_TASK_SHOWERRORCHECKRATEINFO,  ///<(42033)统计异常的复查合格率反馈
	
	ZC_MSG_TASK_STATICS_TASKADDINFO,     ///<(42034)任务添加类统计信息反馈
	ZC_MSG_TASK_STATICS_EMPLOYANALY,     ///<(42035)员工的能力分析统计信息反馈
	ZC_MSG_TASK_STATICS_EMPLOYMANAGER,   ///<(42036)员工管理类统计信息反馈

	ZC_MSG_TASK_CHECKTASKLOCKINFO,       ///<(42037)查询任务信息反馈 @note 请求消息值:\ref ZC_MSG_APP_CHECKTASKLOCKINFO (20237) 	

	ZC_MSG_TASK_TODAYTASKALLINFOSHOW_EX, ///<(42038)获取某条下发任务的执行信息Ex反馈 @note 请求消息值:\ref ZC_MSG_APP_TODAYTASKALLINFOSHOW_EX (20238)
    ZC_MSG_TASK_TODAYTASKDOINFOSHOW_EX,  ///<(42039)获取任务执行情况Ex反馈 @note 请求消息值:\ref ZC_MSG_APP_TODAYTASKDOINFOSHOW_EX (20239)
	ZC_MSG_TASK_AKIDCONFIGUREINFO,       ///<(42040)根据场所ID和部位ID获取检查项目所有信息反馈 @note 请求消息值:\ref ZC_MSG_APP_AKIDCONFIGUREINFO (20240)
	ZC_MSG_TASK_CONFIGURETIMEINFO,       ///<(42041)获取主动巡查检查项目的时间段信息反馈 @note 请求消息值:\ref ZC_MSG_APP_TASK_CONFIGURETIMEINFO (20241)
	ZC_MSG_TASK_CONFIGURETIMEONLYINFO,   ///<(42042)根据时间段名称获取主动巡查检查项目的时间段信息反馈 @note 请求消息值:\ref ZC_MSG_APP_TASK_CONFIGURETIMEONLYINFO (20242)
	ZC_MSG_TASK_CHECKTASKINFOWITHLOCK_NEW, ///<(42043)请求查询任务信息（检索条件包含是否关注）反馈 @note 请求消息值:\ref ZC_MSG_APP_TASK_CHECKTASKINFOWITHLOCK_NEW (20243)
    ZC_MSG_TASK_COVERRATENEWINFO_NEW,      ///<(42044)请求查询巡检覆盖率_New反馈 @note 请求消息值:\ref ZC_MSG_APP_TASK_COVERRATENEWINFO_NEW (20244)

	ZC_MSG_TASK_STARTTASKCHECK = 42100,      ///<(42100)开始执行任务结果反馈
	ZC_MSG_TASK_STOPTASKCHECK,               ///<(42101)停止执行任务结果反馈
	
	ZC_MSG_TASK_CAPTUREPIC,             ///<(42102)请求抓取图片反馈（12）
    ZC_MSG_TASK_SHORTMESSAGE,           ///<(42103)请求发送短信反馈
    ZC_MSG_TASK_TELEPHONECALL,          ///<(42104)请求拨打电话反馈（12）
	ZC_MSG_TASK_TRANSFASTTASK,          ///<(42105)请求下发快速任务反馈
    ZC_MSG_TASK_STARTCHECKPLAYBACK,     ///<(42106)开始巡检回放结果反馈
    ZC_MSG_TASK_STOPCHECKPLAYBACK,      ///<(42107)停止巡检回放结果反馈
	
	ZC_MSG_TASK_FASTTASKINFO = 42900,   ///<(42900)请求执行快速任务（此为其他客户端主动推送的消息请求，任务模块暂不反馈结果）
}E_ZC_MSG_TASK;
/** @} */

/** @defgroup ZCAlarmMsgTypeDefine 报警处置模块响应消息类型枚举  
 * 定义报警处置模块响应消息类型值
 * @{
 */
typedef enum
{
    ZC_MSG_ALARM_QUERYINFO = 50000,    ///<(50000)报警查询结果反馈
    ZC_MSG_ALARM_STATICINFO,           ///<(50001)报警统计结果反馈
	ZC_MSG_ALARM_TOPINFO,              ///<(50002)报警排行结果反馈
	ZC_MSG_ALARM_DETAILINFO,           ///<(50003)报警详细信息反馈
		
	ZC_MSG_ALARM_USERGRAPHINFO,        ///<(50004)用户报警图表信息反馈
	ZC_MSG_ALARM_OPUSERGRAPH,          ///<(50005)增删改用户图表反馈
	ZC_MSG_ALARM_USERREPORTINFO,       ///<(50006)获取用户报告信息反馈
	ZC_MSG_ALARM_MODSTATUSUSERREPORT,  ///<(50007)设置用户报告状态信息反馈
	ZC_MSG_ALARM_OPUSERREPORT,         ///<(50008)增删改用户报告反馈
	ZC_MSG_ALARM_USERREPORTBOOKINFO,   ///<(50009)获取用户报告订阅信息反馈
	ZC_MSG_ALARM_QUERYLOCKINFO,        ///<(50010)报警查询结果反馈(是否锁定附件) @note 请求消息值:\ref ZC_MSG_APP_ALARM_QUERYLOCKINFO (20310)
	ZC_MSG_ALARM_DETAILALARMINFO_GET,        ///<(50011)根据报警ID或报警GUID获取报警详细信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_DETAILALARMINFO_GET (20311)
	ZC_MSG_ALARM_NEW_ALARMACATEGORY_SHOW,    ///<(50012)警情类型获取_分上下级结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_NEW_ALARMACATEGORY_SHOW (20312)

	ZC_MSG_ALARM_ALARMPOSITION = 50040,       ///<(50040)进入所属图层反馈 
    ZC_MSG_ALARM_CONCEALALARM,                ///<(50041)屏蔽某报警源反馈
   	ZC_MSG_ALARM_ALARMLINKVIDEO,              ///<(50042)打开报警关联视频反馈
	ZC_MSG_ALARM_ALARNEARBYVIDEO,             ///<(50043)打开报警附近视频反馈
    ZC_MSG_ALARM_ALARMREPLAY,                 ///<(50044)观看报警录像回放反馈 
	ZC_MSG_ALARM_DEFENCEDEV,                  ///<(50045)布撤防设备反馈
	ZC_MSG_ALARM_CONTROLDEV,                  ///<(50046)控制设备（外设控制、开关门）反馈
	ZC_MSG_ALARM_DEVTALK,                     ///<(50047)对讲反馈
	ZC_MSG_ALARM_DOWNANDUPLOADVIDEO,          ///<(50048)下载录像并上传结果反馈
	ZC_MSG_ALARM_ALARMMAPINFO,                ///<(50049)报警布防图信息反馈
    ZC_MSG_ALARM_ALARMPOSITION_UNLOCK,        ///<(50050)解锁当前图层反馈
    ZC_MSG_ALARM_ALARMREPLAY_CLOSE,           ///<(50051)关闭报警录像回放反馈
	
	ZC_MSG_ALARM_DISPOSALINFO = 50060,      ///<(50060)获取用户报警处置权限反馈
    ZC_MSG_ALARM_LEVELPLOYINFO, 	        ///<(50061)获取报警等级处置策略反馈
	ZC_MSG_ALARM_HISTORYDEALINFO,           ///<(50062)获取历史处理情况统计数据反馈
	ZC_MSG_ALARM_POSTILINFO,                ///<(50063)获取报警批注信息反馈
	ZC_MSG_ALARM_OPERATIONINFO,             ///<(50064)获取报警操作信息反馈
	ZC_MSG_ALARM_NOTDEALINFO,               ///<(50065)获取未处理报警信息反馈
    ZC_MSG_ALARM_MANUALENTRY,               ///<(50066)插入手动报警信息反馈
    ZC_MSG_ALARM_EXCHANGEINFO_NEW,          ///<(50067)获取第四交流屏交流内容反馈
    ZC_MSG_ALARM_EXCHANGEINFO_OPERATION,    ///<(50068)第四交流屏交流内容操作反馈
	ZC_MSG_ALARM_REG_NEW_ALARMDISPOSALNEW_SET,    ///<(50069)报警复核日志插入_New反馈
	ZC_MSG_ALARM_REG_NEW_ALARMDISPOSALNEW_SHOW,    ///<(50070)根据报警ID或报警GUID获取操作记录信息反馈
	
	ZC_MSG_ALARM_SETDUTYSTATUS = 50080,     ///<(50080)设置值班员状态反馈
    ZC_MSG_ALARM_DEALSTATUSSET,             ///<(50081)设置报警信息处置状态反馈
	ZC_MSG_ALARM_PEOPLESET,                 ///<(50082)设置报警信息处置人反馈
	ZC_MSG_ALARM_DEALSULTSET,               ///<(50083)提交报警处置结果反馈
	ZC_MSG_ALARM_MODALARMPARAM,             ///<(50084)修改报警关键参数反馈
	ZC_MSG_ALARM_ADDALARMOPERATION,         ///<(50085)新增报警操作记录反馈
	ZC_MSG_ALARM_ADDALARMPOSTILINFO,        ///<(50086)新增报警批注信息反馈
	ZC_MSG_ALARM_ADDDEFERALARMINGO,         ///<(50087)新增延后处理报警信息反馈
	ZC_MSG_ALARM_GETMSATTACHMENT,           ///<(50088)获取某条报警媒体存储附件列表信息反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_GETMSATTACHMENT (20337) @note 反馈结构体:\ref CLIENTGETMEDIASTORAGEATTACHMENT_S
    ZC_MSG_ALARM_LOCKMSATTACHMENT,          ///<(50089)锁定\解锁报警联动存储附件文件结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_LOCKMSATTACHMENT (20338) @note 反馈结构体:\ref ZC_MSG_RESP_RESULT

	ZC_MSG_ALARM_OPENALARMMANAGER = 50090,  ///<(50090)请求打开报警管理
	
	/**
	* @brief (50098)主动推送报警信息（扩展GUID等信息）
	* 
	* 该消息由bcb客户端主动推送给相关模块，目前不做反馈，也没有推送的前置条件。后期考虑增加由各模块向bcb客户端注册监听的接口。
	* 
	* @note 消息结构体:\ref T_TRANSMITALARMINFO_EX
	* @note 该消息比\ref ZC_MSG_ALARM_NEWALARMINFO (50099)内容丰富，各模块可以自行考虑接收哪种消息，客户端主动推送时均会推送，建议仅处理一种；
	* @note 由于bcb客户端需要兼容老的报警服务器，所以该接口推送的GUID值可能为空，各模块使用时请做相关判断；
	*/
    ZC_MSG_ALARM_NEWALARMINFO_EX  = 50098,  ///<扩展报警转发信息
	
	/**
	* @brief (50099)主动推送报警信息
	* 
	* 该消息由bcb客户端主动推送给相关模块，目前不做反馈，也没有推送的前置条件。后期考虑增加由各模块向bcb客户端注册监听的接口。智能运维用此来推送异常.
	* 
	* @note 消息结构体:\ref T_TRANSMITALARMINFO 
	*/
	ZC_MSG_ALARM_NEWALARMINFO     = 50099, 


    /**
	 * @brief (50100)向考拉平台确认警情、指派人员处警、指派人员协助结果反馈
	 * 
	 * 该消息仅表示客户端是否成功将消息转发给中心，考拉反馈结果通过\ref ZC_MSG_ALARM_VERIFYALARMFEEDBACKTOZONEE (50125)返回
 	 * 
	 * @note 请求消息值:\ref ZC_MSG_BCBCLIENT_TRANSREQUESTVERIFYALARMTOKOALA (30310) 
	 * @note 消息结构体:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSREQUESTVERIFYALARMTOKOALA = 50100,///<(50100)

    /**
	 * @brief (50101)向考拉平台上报报警预案、切换预案结果反馈
	 * 
	 * 该消息仅表示客户端是否成功将消息转发给中心，考拉代理服务器没有反馈结果
	 * 
	 * @note 请求消息值:\ref ZC_MSG_BCBCLIENT_TRANSDEALALARMINFOTOKOALA (30311) 
	 * @note 消息结构体:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSDEALALARMINFOTOKOALA,
	
    /**
	 * @brief (50102)向考拉平台获取在线人员信息结果反馈
	 * 
	 * 该消息仅表示客户端是否成功将消息转发给中心，考拉反馈结果通过\ref ZC_MSG_ALARM_ONLINEUSERTOZONEE (50124)返回
	 * 
	 * @note 请求消息值:\ref ZC_MSG_BCBCLIENT_TRANSGETONLINEUSERTOKOALA (30312) 
	 * @note 消息结构体:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSGETONLINEUSERTOKOALA,

    /**
	 * @brief (50103)向考拉平台上报报警处置进度结果反馈
	 * 
	 * 该消息仅表示客户端是否成功将消息转发给中心，考拉代理服务器没有反馈结果
	 * 
	 * @note 请求消息值:\ref ZC_MSG_BCBCLIENT_TRANSDEALSTEPTOKOALA (30313) 
	 * @note 消息结构体:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSDEALSTEPTOKOALA,

    /**
	 * @brief (50104)向考拉平台上报处置结束信息结果反馈
	 * 
	 * 该消息仅表示客户端是否成功将消息转发给中心，考拉代理服务器没有反馈结果
	 * 
	 * @note 请求消息值:\ref ZC_MSG_BCBCLIENT_TRANSDEALENDTOKOALA (30314) 
	 * @note 消息结构体:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSDEALENDTOKOALA,

	/**
	 * @brief (50105)向考拉平台反馈收到处置结束消息结果反馈
	 *
	 * 该消息仅表示客户端是否成功将消息转发给中心，考拉代理服务器没有反馈结果
	 *
	 * @note 请求消息值:\ref ZC_MSG_BCBCLIENT_TRANSFEEDBACKTOKOALA (30315） 
	 * @note 返回结构体:\ref ZC_MSG_RESP_RESULT
	 */
    ZC_MSG_ALARM_TRANSFEEDBACKTOKOALA,

    /**
	 * @brief (50120) 考拉主动请求协助信息
	 * 
	 * 该消息由考拉代理服务器用户主动推送，暂不需要反馈
	 * 
	 * @note 消息结构体:\ref TRequestHelpToZONEE 
	 */
	ZC_MSG_ALARM_REQUESTHELPTOZONEE = 50120, 

	/**
	 * @brief (50121) 考拉主动上报报警处置进度信息
	 * 
	 * 该消息由考拉代理服务器用户主动推送，暂不需要反馈
	 * 
	 * @note 消息结构体:\ref TDealStepToZONEE 
	 */
	ZC_MSG_ALARM_DEALSTEPTOZONEE,

	/**
	 * @brief (50122) 考拉主动上报报警处置结束信息
	 * 
	 * 该消息由考拉代理服务器用户主动推送，暂不需要反馈
	 * 
	 * @note 消息结构体:\ref TDealEndToZONEE 
	 */
	ZC_MSG_ALARM_DEALENDTOZONEE, 

	/**
	 * @brief (50123) 考拉主动推送报警处置过程中的附件信息
	 * 
	 * 客户端设置对于某条报警的处置人，考拉客户端执行报警处置时，该消息由考拉代理服务器用户主动推送，暂不需要反馈；
	 * 
	 * @note 消息结构体:\ref TAlarmFileToZONEE 
	 */
	ZC_MSG_ALARM_ALARMFILETOZONEE,  

    /**
	 * @brief (50124) 考拉在线人员信息反馈
	 * 
	 * 该消息由考拉代理服务器用户收到\ref ZC_MSG_BCBCLIENT_TRANSGETONLINEUSERTOKOALA  (30312)请求后主动推送，暂不需要反馈
	 * 
	 * @note 消息结构体:\ref TOnlineUserToZONEE + \ref TUserInfo * N
	 */
	ZC_MSG_ALARM_ONLINEUSERTOZONEE,

	/**
	 * @brief (50125) 考拉确认警情反馈
	 * 
	 * 该消息由考拉代理服务器用户收到\ref ZC_MSG_BCBCLIENT_TRANSREQUESTVERIFYALARMTOKOALA (30310)请求后主动推送，暂不需要反馈
	 * 
	 * @note 消息结构体:\ref TVerifyAlarmFeedBackToZONEE
	 */
	ZC_MSG_ALARM_VERIFYALARMFEEDBACKTOZONEE,

    /**
	 * @brief (50126) 考拉内部指派人员后的信息通知
	 * 
	 * 该消息由考拉代理服务器用户主动推送，暂不需要反馈
	 * 
	 * @note 消息结构体:\ref TAssignmentNotifyToZONEE
	 */
	ZC_MSG_ALARM_ASSIGNMENTNOTIFYTOZONEE,

    ZC_MSG_ALARM_DEALKOALAINFO = 50200,     ///<(50200)报警处置考拉信息写入结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_DEALKOALAINFO (20350) @note 反馈结构体:\ref ZC_MSG_RESP_RESULT
    ZC_MSG_ALARM_GETACTIONLIB_KOALA,        ///<(50201)获取动作库_Koala结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_GETACTIONLIB_KOALA (20351) @note 反馈结构体:\ref ZC_MSG_RESP_RESULT + \ref GETACTIONLIB_KOALA_S * N
    ZC_MSG_ALARM_GETPREPLANLIB_KOALA,       ///<(50202)获取预案库_Koala结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_GETPREPLANLIB_KOALA (20352) @note 反馈结构体:\ref ZC_MSG_RESP_RESULT + \ref GETPREPLANLIB_KOALA_S * N
    ZC_MSG_ALARM_GETEVENTLIB_KOALA,         ///<(50203)获取事件库_Koala结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_GETEVENTLIB_KOALA (20353) @note 反馈结构体:\ref ZC_MSG_RESP_RESULT + \ref GETEVENTLIB_KOALA_S * N
    ZC_MSG_ALARM_GETALARMATTACHMENT_KOALA,  ///<(50204)获取Koala报警附件结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_GETALARMATTACHMENT_KOALA (20354) @note 反馈结构体:\ref ZC_MSG_RESP_RESULT + \ref GETALARMATTACHMENT_KOALA_S * N
    ZC_MSG_ALARM_DISPOSALADDCATEGORYID_AC_SET,  ///<(50205)设置报警复核_警情类型值结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_DISPOSALADDCATEGORYID_AC_SET (20355) @note 反馈结构体:\ref ZC_MSG_RESP_RESULT
    ZC_MSG_ALARM_JH_COMPLEXCHECKWITHLOCK_NEW,   ///<(50206)报警处理信息的综合查询WITHLOCK_NEW结果反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_JH_COMPLEXCHECKWITHLOCK_NEW (20356) @note 反馈结构体:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_COMPLEXCHECKWITHLOCK * N
    ZC_MSG_ALARM_ALARMDEVICESTATEINTO_NEW,      ///<(50207)根据报警GUID获取报警主机布撤防状态反馈 @note 请求消息值:\ref ZC_MSG_APP_ALARM_ALARMDEVICESTATEINTO_NEW (20357) @note 反馈结构体:\ref ZC_MSG_RESP_RESULT + \ref S_AlarmDeviceStateInfo * N
}E_ZC_MSG_ALARM;
/** @} */

/** @defgroup ZCOpenDoorMsgTypeDefine 第三方认证模块响应消息类型枚举  
 * 定义第三方认证模块响应消息类型值
 * @{
 */
typedef enum
{
    ZC_MSG_OPENDOOR_STARTLISTENMANUALCAPTURE = 51100,    ///<(51100)开始监听手动抓图消息反馈
	ZC_MSG_OPENDOOR_STOPLISTENMANUALCAPTURE,             ///<(51101)停止监听手动抓图消息反馈
	ZC_MSG_OPENDOOR_NEW_MANUAL_CAPTURE,                  ///<(51102)新的手动抓图消息（主动推送，暂时不需要反馈）
	ZC_MSG_OPENDOOR_CAPTUREWITHOUTOPEN,                  ///<(51103)未打开视频时抓图结果反馈
	ZC_MSG_OPENDOOR_OPENLINKVIDEO,                       ///<(51104)打开联动视频结果反馈
	
	ZC_MSG_OPENDOOR_ADDREQUEST = 51150,                  ///<(51150)关联刷卡认证记录反馈
	ZC_MSG_OPENDOOR_ADDDEALPLANINFO,                     ///<(51151)提交预案执行信息结果反馈
	ZC_MSG_OPENDOOR_MODIFYDEALTYPE,                      ///<(51152)修改认证处置方式结果反馈
	ZC_MSG_OPENDOOR_MODIFYREQUESTSTATE,                  ///<(51153)修改认证处置状态结果反馈
	ZC_MSG_OPENDOOR_SUBMITAUDITORDEALINFO,               ///<(51154)提交开门申请审核基础信息结果反馈
	ZC_MSG_OPENDOOR_MODIFYISCOLLECTION,                  ///<(51155)修改认证记录收藏状态结果反馈 
	ZC_MSG_OPENDOOR_SUBMITDEALINFO,                      ///<(51156)新增认证申请记录结果反馈
	ZC_MSG_OPENDOOR_SETUSERBASEINFO,                     ///<(51157)设置用户认证基础信息结果反馈
	ZC_MSG_OPENDOOR_ADDOPERAINFO,                        ///<(51158)新增认证处置动作信息结果反馈
	ZC_MSG_OPENDOOR_ADDLOGINFO,                          ///<(51159)新增认证系统日志信息结果反馈
	ZC_MSG_OPENDOOR_ADDSUGGESTION,                       ///<(51160)新增认证处理意见信息结果反馈
	ZC_MSG_OPENDOOR_ADDEXCEPTIONINFO,                    ///<(51161)新增异常认证信息结果反馈
	
	ZC_MSG_OPENDOOR_GETUSERBASEINFO,                     ///<(51162)获取用户认证基础信息结果反馈
	ZC_MSG_OPENDOOR_GETALLACSHOSTINFO,                   ///<(51163)获取所有门禁主机信息结果反馈
	ZC_MSG_OPENDOOR_GETACSHOSTLINKINFO,                  ///<(51164)获取门禁主机关联信息结果反馈
	ZC_MSG_OPENDOOR_GETACSHOSTLINKTALKINFO,              ///<(51165)获取门禁主机关联对讲信息结果反馈
	ZC_MSG_OPENDOOR_GETALLPEPOLEINFO,                    ///<(51166)获取所有需管辖的出入人员信息结果反馈
	ZC_MSG_OPENDOOR_GETAPPLYHISTORYINFO,                 ///<(51167)获取认证历史信息结果反馈
	ZC_MSG_OPENDOOR_GETAPPLYHISTORYDETAIL,               ///<(51168)获取认证历史详细信息结果反馈
	ZC_MSG_OPENDOOR_GETOPERAINFO,                        ///<(51169)获取认证操作列表信息结果反馈
	ZC_MSG_OPENDOOR_GETAPPLYPLANINFO,                    ///<(51170)获取预案执行信息结果反馈
	ZC_MSG_OPENDOOR_GETSUGGESTIONINFO,                   ///<(51171)获取处理意见信息结果反馈
	ZC_MSG_OPENDOOR_GETLOGINFO,                          ///<(51172)获取系统日志信息结果反馈
	ZC_MSG_OPENDOOR_GETACCESSLOGINFO,                    ///<(51173)获取关联刷卡信息结果反馈
	ZC_MSG_OPENDOOR_GETBYCARDHISTORYINFO,                ///<(51174)查询刷卡历史信息结果反馈
	ZC_MSG_OPENDOOR_STATISTICS,                          ///<(51175)统计认证信息结果反馈
	ZC_MSG_OPENDOOR_DISPOSALINFO,                        ///<(51176)当前用户认证相关权限结果反馈
	ZC_MSG_OPENDOOR_ACCESSRELATION,                      ///<(51177)获取门禁设备主从关联信息结果反馈
	ZC_MSG_OPENDOOR_CTRLLEVELMULINFO,                    ///<(51178)管控等级信息结果反馈
	ZC_MSG_OPENDOOR_CTRLLEVELPLAN,                       ///<(51179)管控策略信息结果反馈
	ZC_MSG_OPENDOOR_DEPARTMENTINFO,                      ///<(51180)部门信息结果反馈
	ZC_MSG_OPENDOOR_APPLY_BYCARDINFO_NEW,                ///<(51181)查询刷卡历史信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_APPLY_BYCARDINFO_NEW (20431)
	ZC_MSG_OPENDOOR_USERDOORCAMERARELATION,              ///<(51182)获取用户门禁摄像头关联信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_USERDOORCAMERARELATION (20432)
	ZC_MSG_OPENDOOR_GETAPPLYHISTORYLOCKINFO,             ///<(51183)获取认证历史信息（是否锁定附件）反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYLOCKINFO (20433)
	ZC_MSG_OPENDOOR_STAFFINFOOPERATION,                  ///<(51184)设置人员信息反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_STAFFINFOOPERATION (20434)
	ZC_MSG_OPENDOOR_DEPARTMENTINFOOPERATION,             ///<(51185)设置部门信息反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_DEPARTMENTINFOOPERATION (20435)
	ZC_MSG_OPENDOOR_STAFFSTATUS_SET,                     ///<(51186)设置人员状态反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_STAFFSTATUS_SET (20436)
	ZC_MSG_OPENDOOR_DEPARTMENTINFO_GET,                  ///<(51187)获取部门信息反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO_GET (20437)
	ZC_MSG_OPENDOOR_AUTHGROUP_GET,                       ///<(51188)获取权限组信息反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_AUTHGROUP_GET (20438)
	ZC_MSG_OPENDOOR_STAFFINFO_GET,                       ///<(51189)获取人员信息反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_STAFFINFO_GET (20439)
	ZC_MSG_OPENDOOR_STAFFOPERATION_GET,                  ///<(51190)获取人员操作信息反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_STAFFOPERATION_GET (20440)
    ZC_MSG_OPENDOOR_STAFFAUTHINFO_GET,                   ///<(51191)获取人员权限组信息反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_STAFFAUTHINFO_GET (20441)
    ZC_MSG_OPENDOOR_DOOROPENSYRELATION_SET,              ///<(51192)请求关联认证守押信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_DOOROPENSYRELATION_SET (20442)
    ZC_MSG_OPENDOOR_ACCESSSYRELATION_GET,                ///<(51193)获取门禁关联守押设备信息反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_ACCESSSYRELATION_GET (20443)
    ZC_MSG_OPENDOOR_DOOROPENSYRELATION_GET,              ///<(51194)获取认证守押关联信息反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_DOOROPENSYRELATION_GET (20444)
    ZC_MSG_OPENDOOR_QUERYHISTORYINFO_SY_GET,             ///<(51195)查询认证历史信息（可按认证类型查询）反馈 @note 请求消息值:\ref ZC_MSG_APP_OPENDOOR_QUERYHISTORYINFO_SY_GET (20445)
 
	ZC_MSG_OPENDOOR_OPENDATAMANAGER = 51200,             ///<(51200)请求打开查询与统计管理界面
	ZC_MSG_OPENDOOR_OPENBASESET,                         ///<(51201)请求打开基本设置界面
	ZC_MSG_OPENDOOR_OPENUSERMANAGER,                     ///<(51202)请求打开人员管理界面
}E_ZC_MSG_OPENDOOR;
/** @} */

/** @defgroup ZCSysDorctorMsgTypeDefine 智能运维模块响应消息类型枚举  
 * 定义第三方认证模块响应消息类型值
 * @{
 */
typedef enum
{
	ZC_MSG_SYSDORCTOR_DISPOSALINFO = 52000, ///<(52000)智能运维当前用户权限信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DISPOSALINFO (20500)

    ZC_MSG_SYSDORCTOR_CMSINFO = 52010,    ///<(52010)中心类信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_CMSINFO (20510)
	ZC_MSG_SYSDORCTOR_AREAINFO,           ///<(52011)区域类信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_AREAINFO (20511)
	ZC_MSG_SYSDORCTOR_DEVINFO,            ///<(52012)主机类信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DEVINFO (20512) 
	ZC_MSG_SYSDORCTOR_CAMERAINFO,         ///<(52013)探头类信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_CAMERAINFO (20513)
    ZC_MSG_SYSDORCTOR_DEVINFO_EX,         ///<(52014)主机类信息获取结果反馈(包含资产编号) @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DEVINFO_EX (20514) 
	ZC_MSG_SYSDORCTOR_CAMERAINFO_EX,      ///<(52015)探头类信息获取结果反馈(包含资产编号) @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_CAMERAINFO_EX (20515) 
	
	ZC_MSG_SYSDORCTOR_MANUFACTUREINFOINCAPITAL = 52019, ///<(52019)所有设备品牌信息(只包含资产信息中存在的)获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MANUFACTUREINFOINCAPITAL (20519)
    ZC_MSG_SYSDORCTOR_MANUFACTURENAME = 52020, ///<(52020)所有设备品牌信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MANUFACTURENAME (20520)    
    ZC_MSG_SYSDORCTOR_MODELNO,                 ///<(52021)设备型号信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MODELNO (20521) 
    ZC_MSG_SYSDORCTOR_SUPPLIERCOMPANY,         ///<(52022)所有供应商信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_SUPPLIERCOMPANY (20522) 
    ZC_MSG_SYSDORCTOR_MAINTENCECOMPANY,        ///<(52023)所有维保商信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENCECOMPANY (20523) 
    ZC_MSG_SYSDORCTOR_MAINTENCEPHONE,          ///<(52024)所有维保商电话信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENCEPHONE (20524) 
    ZC_MSG_SYSDORCTOR_ENGINEERINGNAME,         ///<(52025)所有工程商信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_ENGINEERINGNAME (20525) 
    ZC_MSG_SYSDORCTOR_ALARMHOSTINFO,           ///<(52026)所有报警主机信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_ALARMHOSTINFO (20526) 
    ZC_MSG_SYSDORCTOR_ALARMARMDISARMPLAN,      ///<(52027)所有报警主机布撤防计划信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_ALARMARMDISARMPLAN (20527)
    ZC_MSG_SYSDORCTOR_HOSTUSESTATUS,	       ///<(52028)所有主机使用状态查询结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_HOSTUSESTATUS (20528)
    ZC_MSG_SYSDORCTOR_DETECTORUSESTATUS,	   ///<(52029)所有探头使用状态查询结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DETECTORUSESTATUS (20529)

    ZC_MSG_SYSDORCTOR_DEVCAPITALINFO = 52030,  ///<(52030)设备基本资产信息查询结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DEVCAPITALINFO (20530) 
    ZC_MSG_SYSDORCTOR_SETDEVCAPITALINFO,       ///<(52031)设备基本资产信息修改结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_SETDEVCAPITALINFO (20531)
    ZC_MSG_SYSDORCTOR_STATDEVCAPITALINFO,      ///<(52032)设备基本资产信息统计结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_STATDEVCAPITALINFO (20532) 
    ZC_MSG_SYSDORCTOR_OMRECORDDAYSMODULE,      ///<(52033)获取通道录像模板天数信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_OMRECORDDAYSMODULE (20533) 
    ZC_MSG_SYSDORCTOR_DETECTMODULEINFO,        ///<(52034)获取通道录像模板是否启用信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DETECTMODULEINFO (20534) 
    ZC_MSG_SYSDORCTOR_SOFTSETCHANNELRECORDDAYS,///<(52035)根据录像天数模板ID获取关联摄像头信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_SOFTSETCHANNELRECORDDAYS (20535) 
    ZC_MSG_SYSDORCTOR_IOMOPERATIONINFO,        ///<(52036)获取一键运维信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_IOMOPERATIONINFO (20536) 

    ZC_MSG_SYSDORCTOR_FAULTINFO = 52040,           ///<(52040)所有故障现象信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_FAULTINFO (20540)
    ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO,             ///<(52041)报修记录信息查询结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO (20541) 
    ZC_MSG_SYSDORCTOR_MAINTENCEINFO,               ///<(52042)维修记录信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO (20542)
    ZC_MSG_SYSDORCTOR_ADDMALFUNCTIONINFO,          ///<(52043)新增报修记录信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_ADDMALFUNCTIONINFO (20543) 
    ZC_MSG_SYSDORCTOR_ADDMAINTENCEINFO,            ///<(52044)新增维修记录信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_ADDMAINTENCEINFO (20544) 
    ZC_MSG_SYSDORCTOR_STATMALFUNCTIONINFO,         ///<(52045)报修记录信息统计结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_STATMALFUNCTIONINFO (20545)
    ZC_MSG_SYSDORCTOR_DEVICEBASEINFOBYID,          ///<(52046)根据设备编号请求设备基本信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOBYID (20546)
    ZC_MSG_SYSDORCTOR_DEVICEBASEINFOBYCAPITALCODE, ///<(52047)根据设备资产编号请求设备基本信息结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOBYCAPITALCODE (20547)
    ZC_MSG_SYSDORCTOR_DEVICEBASEINFOGET_NEW,       ///<(52048)获取设备基础信息_NEW结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOGET_NEW (20548)
    ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO_GET_NEW,     ///<(52049)报修记录信息查询_NEW结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO_GET_NEW (20549)

	ZC_MSG_SYSDORCTOR_DVRONLINESTATE = 52060, ///<(52060)监控主机在线状态查询结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DVRONLINESTATE (30400) 
	ZC_MSG_SYSDORCTOR_ALARMHOSTSTATE,         ///<(52061)报警主机状态查询结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_ALARMHOSTSTATE (30401) 
    ZC_MSG_SYSDORCTOR_DEVTIMEINFO,            ///<(52062)监控主机时钟状态查询结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVTIMEINFO (30402) 
    ZC_MSG_SYSDORCTOR_SETDEVTIMEINFO,         ///<(52063)监控主机时钟状态设置结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_SETDEVTIMEINFO (30403) 
    ZC_MSG_SYSDORCTOR_DEVCHANNELSTATE,        ///<(52064)监控主机通道状态查询结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVCHANNELSTATE (30404)
	ZC_MSG_SYSDORCTOR_DEVDISKSTATE,           ///<(52065)监控主机硬盘状态查询结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVDISKSTATE (30405)
    ZC_MSG_SYSDORCTOR_DEVCHECKVIDEO,          ///<(52066)监控主机硬盘状态查询结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVCHECKVIDEO (30406)
    ZC_MSG_SYSDORCTOR_ACCESSSTATE,            ///<(52067)门禁主机状态查询结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_ACCESSSTATE (30407)
    ZC_MSG_SYSDORCTOR_VIDEOQUALITY,           ///<(52068)查询视频质量诊断巡检结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_VIDEOQUALITY (30408)
    ZC_MSG_SYSDORCTOR_NODESTATE,              ///<(52069)查询节点状态（服务器节点）结果反馈 @note 请求消息值:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_NODESTATE (30409)

    /**
	 * @brief (52080)请求打开智能运维主界面
	 *
	 * 智能运维一期中，该消息为请求打开设备信息管理界面
	 *
	 * @note 该消息为主动推送消息，暂不需要反馈
	 */
    ZC_MSG_SYSDORCTOR_OPENDEVICEMANAGER = 52080, 

	/**
	 * @brief (52081)智能运维二期不再使用
	 *
	 * 智能运维一期中，该消息为请求打开状态查询管理界面
	 *
	 * @note 该消息为主动推送消息，暂不需要反馈
	 */        
    ZC_MSG_SYSDORCTOR_OPENCHECKSTATEMANAGER, 

	/**
	 * @brief (52082)智能运维二期不再使用
	 *
	 * 智能运维一期中，该消息为请求打开故障管理界面
	 *
	 * @note 该消息为主动推送消息，暂不需要反馈
	 */  
    ZC_MSG_SYSDORCTOR_OPENREPAIRMANAGER, 

	ZC_MSG_SYSDORCTOR_CHANNELDETECTMODULE_OPERATION_NEW,  ///<(52083)通道检查模板相关操作结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_CHANNELDETECTMODULE_OPERATION_NEW (20550)
	ZC_MSG_SYSDORCTOR_OMRECORDDAYSMODULE_GET_NEW,         ///<(52084)智能运维获取录像天数模板结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_OMRECORDDAYSMODULE_GET_NEW (20551)
	ZC_MSG_SYSDORCTOR_MALFUNCTION_NEW_GET,                ///<(52085)报修管理数据项获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTION_NEW_GET (20552)
	ZC_MSG_SYSDORCTOR_FAULTTREATMENT_GET,                 ///<(52086)智能运维故障处理记录结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_FAULTTREATMENT_GET (20553)
	ZC_MSG_SYSDORCTOR_MAINTENANCERECORD_GET,              ///<(52087)智能运维维修记录结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENANCERECORD_GET (20554)
	ZC_MSG_SYSDORCTOR_REVIEWANDEVALUTION_GET,             ///<(52088)智能运维复核与评价记录结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_REVIEWANDEVALUTION_GET (20555)
	ZC_MSG_SYSDORCTOR_FAULTDEVICEINFO_ADD,                ///<(52089)智能运维故障记录写入结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_FAULTDEVICEINFO_ADD (20556)
	ZC_MSG_SYSDORCTOR_FAULTDEVICEHANDLEINFO_ADD,          ///<(52090)智能运维故障处理记录写入结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_FAULTDEVICEHANDLEINFO_ADD (20557)
	ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO_ADD,                ///<(52091)智能报修记录写入结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO_ADD (20558)
	ZC_MSG_SYSDORCTOR_MAINTENCEINFO_ADD,                  ///<(52092)智能运维维修记录写入结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENCEINFO_ADD (20559)
	ZC_MSG_SYSDORCTOR_CHECKINFO_ADD,                      ///<(52093)智能运维复核记录写入结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_CHECKINFO_ADD (20560)
	ZC_MSG_SYSDORCTOR_DEVICEFAULTINFO_SET,                ///<(52094)设备历史故障检索结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_DEVICEFAULTINFO_SET (20561)
	ZC_MSG_SYSDORCTOR_NEW_FAULTEXTREMELYINFO_GET,         ///<(52095)获取故障异常详情结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_NEW_FAULTEXTREMELYINFO_GET (20562)
	ZC_MSG_SYSDORCTOR_NEWFAULTDEVICEADDITIONAL_ADD,       ///<(52096)IOM区分具体故障类型故障记录写入结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_NEWFAULTDEVICEADDITIONAL_ADD (20563)
	ZC_MSG_SYSDORCTOR_NEW_SUPPLIERMAINTENANCE_OPERATION,  ///<(52097)厂商信息操作结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_NEW_SUPPLIERMAINTENANCE_OPERATION (20564)
	ZC_MSG_SYSDORCTOR_NEW_SUPPLIERMAINTENANCEINFO_GET,    ///<(52098)厂商信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_NEW_SUPPLIERMAINTENANCEINFO_GET (20565)
	ZC_MSG_SYSDORCTOR_NEW_CAPTICALINFONEW_OPERATION,      ///<(52099)资产信息操作结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_NEW_CAPTICALINFONEW_OPERATION (20566)
	ZC_MSG_SYSDORCTOR_NEW_CAPTICALINFO_NEW_GET,           ///<(52100)资产信息获取结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_NEW_CAPTICALINFO_NEW_GET (20567)
    ZC_MSG_SYSDORCTOR_NEW_DETECTSCHEDULE_GET,             ///<(52101)获取巡检计划结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_NEW_DETECTSCHEDULE_GET (20568)  
	ZC_MSG_SYSDORCTOR_CAPTICALADDITIONALINFO_GET,         ///<(52102)资产状态统计_Additional结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_CAPTICALADDITIONALINFO_GET (20569)  
    ZC_MSG_SYSDORCTOR_CAPTICALSTATISTICSINFO_GET,         ///<(52103)资产状态统计结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_CAPTICALSTATISTICSINFO_GET (20570)  
    ZC_MSG_SYSDORCTOR_FAULTSTATISTICSINFO_GET,            ///<(52104)故障统计结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_FAULTSTATISTICSINFO_GET (20571)  
    ZC_MSG_SYSDORCTOR_MAINTENANCESTATISTICSINFO_GET,      ///<(52105)维保服务统计结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENANCESTATISTICSINFO_GET (20572)  
    ZC_MSG_SYSDORCTOR_CAPTICALAREAEXCEPTIONINFO_GET,      ///<(52106)网点异常资产统计结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_CAPTICALAREAEXCEPTIONINFO_GET (20573)  
    ZC_MSG_SYSDORCTOR_BATCHMALFUNCTIONINFO_SET,           ///<(52107)IOM批量报修处理结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_BATCHMALFUNCTIONINFO_SET (20574)  
    ZC_MSG_SYSDORCTOR_FAULTIDBYDEVICEDETAILINFO_GET,      ///<(52108)根据设备信息获取故障ID结果反馈 @note 请求消息值:\ref ZC_MSG_APP_SYSDORCTOR_FAULTIDBYDEVICEDETAILINFO_GET (20575)
}E_ZC_MSG_SYSDORCTOR; 
/** @} */
/** @} */

///设置当前工位的报警处置状态类型枚举
typedef enum
{
	ZC_MSG_ALARM_SETUSERSTATUSFREE     = 10,     ///当前用户未处理报警空闲
	ZC_MSG_ALARM_SETUSERSTATUSONELEVEL,          ///正在处置1类报警
	ZC_MSG_ALARM_SETUSERSTATUSTWOLEVEL,          ///正在处置2类报警
	ZC_MSG_ALARM_SETUSERSTATUSTHREELEVEL,        ///正在处置3类报警
	ZC_MSG_ALARM_SETUSERSTATUSFOURLEVEL,         ///正在处置4类报警
	ZC_MSG_ALARM_SETUSERSTATUSFIVELEVEL,         ///正在处置5类报警
	ZC_MSG_ALARM_SETUSRESTATUSDELAYTIME = 21,	 ///有倒计时
}E_ZC_MSG_SETUSERSTATUS;

/************************************************************************/
/*                            结构体定义                                */
/************************************************************************/
#define NODE_NAME_LEN 64
#define NODE_CODE_LEN 64
#define CENTER_CODE_LEN 128
#define DEVICE_NAME_LEN 128
#define DEVICE_CODE_LEN 64
#define DEVICE_IP_LEN 32
#define DEVICE_MODEL_LEN 128
#define DEVICE_MANUFACTURE_LEN 64
#define DEVICE_SUPPLIER_LEN 64
#define CONTRACT_INFO_LEN 64
#define MAINTENANCE_INFO_LEN 64
#define CAPITAL_CODE_LEN   20

typedef enum
{
	ON_USE = 1,
	ON_REPAIR,
	ON_DISABLE
}E_DEVICE_STATUS;

//当前用户信息结构（1）
typedef struct
{
    char chUserName[64];           // 用户名		
}T_CURUSER_INFO, *LPT_CURUSER_INFO;

typedef struct
{
    int nId;                       // 用户ID
    char chUserName[64];           // 用户名	
    int  nLevel;                   // 用户级别
    char chRole[128];              // 用户角色    	
}T_CURUSER_INFO_EX, *LPT_CURUSER_INFO_EX;

//新用户登录信息结构（2）
typedef struct
{
    char chUserName[64];           // 用户名		
	char chPassWord[64];           // 密码
}T_NEWLOGINUSER_INFO, *LPT_NEWLOGINUSER_INFO;

//用户交接班信息结构（3）
typedef struct
{
    int nScheduleID;               //排班ID  
	char chUserName[64];           //用户名称
    char strRole[64];              //用户角色
    char chPassWord[64];           //用户密码
	char chHandoverTime[32];       //接班时间
	char chImage[512];             //用户头像
	unsigned short nAlarmCount;    //处理报警数
	bool bMonitor;                 //是否拥有交接班审查权限  
	bool bHandover;                //是否已完成交接班
}T_USER_HA_INFO, *LPT_USER_HA_INFO;

//系统角色信息结构（4）
typedef struct
{
    int nRoleId;                //角色编号 
    char strRole[64];           //角色名称		
}T_ROLE_INFO, *LPT_ROLE_INFO;

//任务详细信息结构（5）
typedef struct
{
	int nTaskID;                   // 任务ID
	char chTaskName[64];           // 任务名称
	char chDescription[512];       // 任务描述
	int nOperation;                // 任务操作类型 1-查看视频 2-录像回放
	char chOperName[32];           // 任务操作类型名称
	char chEffectiveBeginDate[32]; // 有效期开始时间
	char chEffectiveEndDate[32];   // 有效期结束时间
	int nLoopMethod;               // 循环规则 1-每天 2-每周 3-每月
	char chLoopMemo[512];          // 循环备注
	bool bDoTimeRange;             // 是否规定任务时间范围
	char chStartTime[32];          // 开始时间
	char chEndTime[32];            // 结束时间
	bool bStartInTime;             // 是否规定准时执行
	bool bEngInTime;               // 是否强制要求截止时间
	bool bWarn;                    // 是否到点提醒
	int nWarnMinu;                 // 到点前X分钟提醒
	bool bTotalTime;               // 是否规定任务执行时长
	int nToTalTime;                // 任务执行时长（单位：分钟）
	int nTotalTimes;               // 执行次数
	bool bRuleTimes;               // 是否强制值班员在执行查看视频时以点击视频预览频幕作为巡检必要动作
	int nRuleTimes;                // 每次任务每路视频至少点击次数
	char chInstructions[1024];     // 任务指导
	bool bTaskLevel;               // 是否规定任务重要等级
	int nTaskLevel;                // 任务重要等级（等级表ID）没有规定的时候为0
	bool bError;                   // 是否异常参考
	int nError;                    // 异常表ID，没有时为0
	char chErrorLabel[128];        // 任务标签
	int nClassId;                  // 班次唯一ID
	char chClassName[32];          // 班次名称
	char chStatus[32];             // 任务状态（1-未下发，2-未完成，3-已下发）
	char chType[32];               // 任务类型（1-日常任务，2-突发任务）
	char chRoleNames[1024];        // 下发对象（角色名称,串）
	char chKeyPartName[128];       // 部位名称
	int nObject;                   // 虚拟场所为1，具体场所为2
	char chPlaceNames[30000];      // 虚拟场所或具体场所名称（,串）
}T_ALL_TASKINFO, *LPT_ALL_TASKINFO;

//任务详细信息结构（6）
typedef struct
{
	int nTaskID;                              // 任务ID
	char chTaskName[64];                      // 任务名称
	char chOperName[32];                      // 操作类型名称
	char chClassName[32];                     // 班次名称
	char chRoleNames[1024];                   // 下发对象（角色名称,串）
	char chEffectiveBeginDate[32];            // 有效期开始时间
	char chEffectiveEndDate[32];              // 有效期结束时间
	char chStartTime[32];                     // 开始时间
	char chEndTime[32];                       // 结束时间
	bool bWarn;                               // 是否到点提醒
	char chTI_Status_Int[32];                 // 任务状态（未下发，未完成，已下发）
	char chTI_Type_Int[32];                   // 任务类型（日常任务，突发任务）
}T_SUB_TASKINFO,*LPT_SUB_TASKINFO;

//信息查询日期结构（7）
typedef struct
{
	char chBeginDate[32];                     // 查询起始日期
	char chEndDate[32];                       // 查询结束日期    
}T_SEARCHDATE,*LPT_SEARCHDATE;

//任务模块相关信息结构（8）
typedef struct
{
    int  nScheduleID;                         // 排班ID
    char chUserName[64];                      // 用户名称
	char chRoleName[64];                      // 角色名称
    int  nRoleID;                             // 角色编号
	int  nClassID;                            // 班次编号
    bool bModuleAuthoritys[4];                // 模块权限[0-排班,1-任务安排,2-任务复核,3-值班长交接班]
}T_TASKMCURUSERINFO,*LPT_TASKMCURUSERINFO;

//任务开始执行结构（9）
typedef struct
{
    int nOperation;                // 任务操作类型 1-查看视频 2-录像回放
	char chAreaName[64];           // 任务执行区域名称，用以查看视频时，筛选节点树
	char chGuid[64];			   // 任务执行唯一GUID
	int nModule;                   // 1-报警处置；2-日常巡查；3-门禁认证
	char chReserved[16];           // 保留
}T_DOTASKINFO,*LPT_DOTASKINFO;

//发送短信结构（10）
typedef struct
{
    char chMsg[256];              // 短信内容
	char chContactMan[64];        // 接收人姓名 
	char chTelephone[32];         // 接收人电话号码
}T_SENDSHORTMESSAGEINFO,*LPT_SENDSHORTMESSAGEINFO;

//拨打电话结构（11）
typedef struct
{
    char chDestName[64];           // 目标名称
    char chManName[64];            // 负责人名称
    char chTelephone[32];          // 电话号码     
}T_TELEPHONECALLINFO,*LPT_TELEPHONECALLINFO;

//附件结构（12）
typedef struct
{ 
    char chAttachment[256];       // 报警附件
}T_ATTACHMENTINFO,*LPT_ATTACHMENTINFO;

//下发快速任务结构（13）
typedef struct
{
    char chReceiveUserName[64];                // 任务接收用户名
	P_NEW_INSPECT_FASTTASKINFOSET sTaskInfo;   // 快速任务信息
}T_TRANS_FASTTASKINFO,*LPT_TRANS_FASTTASKINFO;

//报警相关权限结构（14）
typedef struct
{
    bool bAssignPosal;      // 是否有报警分派权限 
	bool bCheckPosal;       // 是否有报警复核权限
	bool bChangePosal;      // 是否有警情、等级修改权限
	bool bDecidePosal;      // 是否有定性权限
}T_ALARMPOSALINFO,*LPT_ALARMPOSALINFO;

//第三方认证相关权限结构
typedef struct
{
	bool bUserInfoSetPosal;  // 是否有人员增删改权限 
	bool bEnteringPosal;     // 是否录入权限
	bool bDealWithPosal;     // 是否认证处置权限
	bool bCheckPosal;        // 是否有审核权限
	bool bQueryPosal;        // 是否有记录查询权限
}T_OPENDOORPOSALINFO,*LPT_OPENDOORPOSALINFO;

///<智能运维相关权限结构
typedef struct
{
	bool bNormalPosal;   ///< 是否有普通使用权限 
	bool bDevInfoPosal;  ///< 是否有设备信息管理权限
	bool bReviewPosal;	///< 是否有报修管理复核权限
}T_SYSDORCTORPOSALINFO,*LPT_SYSDORCTORPOSALINFO;

//报警联动请求参数结构（15）
typedef struct
{
    int nAlarmSourceType;    // 报警源类型： 0-主机 1-摄像头、探头
	char chAlarmSource[64];  // 报警源名称
}T_ALARMLINKOPERATEPRARM,*LPT_ALARMLINKOPERATEPRARM;


typedef struct
{
	int nAlarmSourceType;    ///< 报警源类型： 0-主机 1-摄像头、探头
	char chAlarmSource[64];  ///< 报警源名称
	char chGuid[64];         ///< 认证关联GUID
}T_OPENDOORLINKVIDEOPRARM,*LPT_OPENDOORLINKVIDEOPRARM;

//报警联动录像回放请求参数结构（16）
typedef struct
{
    int nAlarmSourceType;    // 报警源类型： 0-主机 1-摄像头、探头
	char chAlarmSource[64];  // 报警源名称
	char chAlarmTime[32];    // 报警时间（格式2015-01-01 00:00:00）  
}T_ALARMREPLAYPARAM,*LPT_ALARMREPLAYPARAM;

//视频下载并上传请求参数结构
typedef struct
{
    int nAlarmSourceType;    // 报警源类型： 0-主机 1-摄像头、探头
	char chAlarmSource[64];  // 报警源名称
	TJTY_TIME tBeginTime;    // 视频下载起始时间
	TJTY_TIME tEndTime;      // 视频下载结束时间
}T_ALARMDWONANDUPLOADPARAM,*LPT_ALARMDWONANDUPLOADPARAM;

/*
* @动态发布请求参数结构（17）
*
* 赋值示例如下
* 【A】：@某人（给某人发动态消息）   
* {
*    T_ADDEVENTINFO info = {0}; 
*    strcpy_s(info.chContext,1024,"@具体用户名 ");    //用户名后的空格不可省  
*    //此情况下，另外两个参数可不用赋值     
* }
* 【B】：转发报警给某人
* {
*    T_ADDEVENTINFO info = {0}; 
*    sprintf_s(info.chContext,1024,"%s给您发送了一条报警信息[名称：%s 报警类型：%s 发生时间：%s]",...);  
*    sprintf_s(info.chSource,128,"[报警编号:%d]%s",...);   
*  }
*/
typedef struct
{
    char chContext[1024];     // 动态新增时预设文字内容
    char chSource[128];       // 动态源（需要某些联动动作的时候赋值）
    char chTime[64];          // 动态发生时间（给联动动作赋值时间参数）   	
}T_ADDEVENTINFO,*LPT_ADDEVENTINFO;

///<转发报警结构体/巡检结果推送结构体
typedef struct
{
	unsigned char ucChannel;    ///< 报警通道号或报警主机分区号
	unsigned char ucDevType;    ///< 报警设备类型(报警源类型：0-主机 1-摄像头、探头)
	unsigned char ucAlarmType;  ///< 报警类型/巡检异常事件E_EVENTPATROL_EXCEPT
	unsigned char ucReserved;   ///< 报警等级
	char chMemo[128];           ///< 附加信息/备注信息[人名、部门、出入时间信息]	前64字节是描述，后64字节是附件
	int	 nDealType;             ///< 9999：巡检异常类报警； 其它值：沿用原来定义:0-不需人工处理  1-未处理（chDealUser表示指定的处理人姓名） 8-未分配（chDealUser表示分配该信息的值班长姓名）
	char chDealUser[64];        ///< 处理人姓名/ip地址
}T_TRANSMITALARMENTITY,*LPT_TRANSMITALARMENTITY;

///<具体报警扩展内容结构体
typedef struct
{
    char guid[64];                              ///< 报警唯一标识
    int  videoseconds;                          ///< 联动录像秒数（为0不录像）
    int  picturescount;                         ///< 联动抓图张数（为0不抓图）
    int  reserved1;                             ///< 保留1	0-众绎    1-考拉
    char reserved2[32];                         ///< 保留2
}T_TRANSMITALARMENTITY_EX,*lPT_TRANSMITALARMENTITY_EX;

struct T_TRANSMITALARMINFO
{
    char chDevID[20];           ///< 设备ID(字符串)
    long nDevNumber;            ///< 设备ID(整形)
    char chAlarmSource[128];    ///< 报警源名称
	char chArea[64];            ///< 所属区域
    char chAlarmDateTime[32];   ///< 报警发生时间
	char chKeyPart[64];         ///< 所属部位
    T_TRANSMITALARMENTITY tAlarmInfo;        ///< 具体报警信息/巡检结果信息
};

typedef struct
{
    T_TRANSMITALARMINFO      tTransmitAlarmInfo;     ///< 具体报警信息/巡检结果信息
    T_TRANSMITALARMENTITY_EX tAlarmInfo_Ex;          ///< 具体报警扩展信息
}T_TRANSMITALARMINFO_EX,*LPT_TRANSMITALARMINFO_EX;

//巡检异常事件
typedef enum 
{
	PATROL_EXCEPT_UNSUPPORT = 1,    // 不支持
	PATROL_EXCEPT_OFFLINE,          // 掉线
	PATROL_EXCEPT_GET_FAIL,         // 获取失败

	// 布撤防状态
	PATROL_EXCEPT_ARM_STATE = 10,   // 布防异常
	PATROL_EXCEPT_DISARM_STATE,		// 撤防异常

	// 时钟状态
	PATROL_EXCEPT_CLOCK_STATE = 20, // 时间异常

	// 硬盘状态
	PATROL_EXCEPT_DISK_STATE = 30,  // 磁盘异常
	PATROL_EXCEPT_DISK_FULL,        // 磁盘已满

	// 录像状态
	PATROL_EXCEPT_RECORD_STATE = 40,// 录像异常

	// 录像天数
	PATROL_EXCEPT_RECORD_DAYS = 50, // 录像天数不足

	// 录像完整性
	PATROL_EXCEPT_RECORD_INTEGRITY = 60,// 录像缺失

	// 视频质量诊断
	PATROL_EXCEPT_VQ_LOST = 70,			// 视频丢失
	PATROL_EXCEPT_VQ_FOGGY,				// 图像模糊
	PATROL_EXCEPT_VQ_LUMINANCE,			// 亮度异常
	PATROL_EXCEPT_VQ_CHROMINANCE,		// 图像偏色
	PATROL_EXCEPT_VQ_SNOWFLAKE,			// 雪花干扰
	PATROL_EXCEPT_VQ_STRIPE,			// 条纹干扰
	PATROL_EXCEPT_VQ_SHAKE,				// 画面抖动
    PATROL_EXCEPT_KOALA_QUICK_ALARM = 198,	// 考拉一键报警
		
    // 监测节点状态
	PATROL_EXCEPT_NODE_CPU_HIGH = 100,	// CPU使用率过高
	PATROL_EXCEPT_NODE_MEM_HIGH,		// 内存使用率过高
	PATROL_EXCEPT_NODE_NET_HIGH,		// 网络使用率过高
}E_EVENTPATROL_EXCEPT;

/************************************************
****附加信息：
*时钟状态异常
*相差秒数，正数表示时间快了，负数表示时间慢了
*正数示例： “100”
*负数示例：“-100”

****录像天数异常
*不足天数
*例： “3”

****录像完整性异常
示例： “<2><2015-12-12 19:36:00 2015-12-12 19:39:00><2015-13-13 19:45:00 2015-13-13 19:47:00>”

<2>：录像缺失时间段的数量
<2015-12-12 19:36:00 2015-12-12 19:39:00>：第1个缺失时间段
<2015-13-13 19:45:00 2015-13-13 19:47:00>：第2个缺失时间段

****磁盘容量不足异常
示例： “<2000><1800>”

2000：总容量（MB）
1800：已使用容量（MB）
*************************************************/

typedef struct
{
    int nAreaId;                      //节点ID
	char chCode[32];                  //节点编码
	char chName[64];                  //节点名称
	char chFatherNo[32];              //上一级编码
	char chAddress[128];              //网点地址
	char chManName[64];               //联系人
	char chContactInfo[64];           //联系方式
	int nAreaTypeID;                  //节点类型ID（1~8,9,10,11,12,13）
	char chNodeTypeName[64];          //节点类型名
	int nAreaLevel;                   //节点级别（1~101,102,103,200,300,400）
	char chCenterNo[128];             //中心编号
	char chFatherCenterNo[128];       //父中心编号	
	int nAreaPosition;                //场所		
}T_AREA_INFO, *LPT_AREA_INFO;

//报警报告布防图信息结构体
typedef struct
{
    char chAreaMapPath[256];          //地图底图路径
    int nPosX;                        //节点X坐标 （在地图上的坐标比例*1000）      
    int nPosY;	                      //节点y坐标 （在地图上的坐标比例*1000）
}T_ALARMMAP_INFO,*LPT_ALARMMAP_INFO;

//消息转发消息头结构（13）
typedef struct
{
    char chReceiveUserName[64];      // 消息接收用户名
    DWORD dwReceiveModuleType;       // 消息接收模块值
}T_TRANS_COMMONHEADINFO,*LPT_TRANS_COMMONHEADINFO;

typedef struct
{
    char chReceiveUserName[64];      // 消息接收用户名
    int  nUserType;                  // 用户类型 电视墙-1003 电子地图-1004 分控-1005 控制台-1006
    DWORD dwReceiveModuleType;       // 消息接收模块值
}T_TRANS_COMMONHEADINFO_EX,*LPT_TRANS_COMMONHEADINFO_EX;

//消息转发消息体结构
typedef struct
{
	unsigned int ucLength;         //消息体长度
	unsigned int ucMsgType;        //消息类别
	unsigned int ucOnlineStatus;    //在线状态
	unsigned int ucDealStatus;      //处置状态
	char chDispatcher[64];			//转发用户
	int nAlarmID;                    //相关报警ID
	T_TRANSMITALARMINFO_EX alarmInfo;   //报警信息
}T_TRANS_ALARMMANAGER_INFO,*LPT_TRANS_ALARMMANAGER_INFO;

typedef enum
{
	MT_CHECKONLINE    = 0x01, //暂时不用
	MT_FEEDBACKONLINE = 0x02, //暂时不用
	MT_FEEDBACKSTATUS = 0x04, //向值班长汇报状态
	MT_DISTRIBUTE     = 0x08, //值班长向值班员分配任务
	MT_REVIEWNEEDED   = 0x10, //值班员向值班长申请复核
	MT_REVIEWDONE     = 0x20, //值班长向值班员反馈复核完毕
}E_TRANS_MESSAGETYPE;

//上级用户信息
typedef struct
{
    char chMonitorName[64];
	bool bModuleAuthoritys[16];    // 模块权限[0-排班,1-任务安排,2-任务复核,3-值班长交接班,4-参与排班权限,5-报警复核权限,6-报警分配权限,7-报警警情、等级修改权限 8-报警定性权限]
}T_MONITOR_INFO,*LPT_MONITOR_INFO;

//上传附件信息结构
typedef struct
{
    int  nFileType;        //文件类型 0-图片 1-音频 2-视频
    char chFilePath[512];  //文件本地路径
}T_UPLOADATTACHMENT_INFO,*LPT_UPLOADATTACHMENT_INFO;

typedef struct
{
	char chDeviceName[128];	///<设备ID
	int nChannelNum;		///<通道号
	char chFileName[50];	///<文件名
	char chFilePath[250];	///<文件路径
	char chBeginDate[64];	///<开始时间
	char chEndDate[64];		///<结束时间
	int nDateType;			///<数据类型：1-视频 ;2-图片 ;3-音频(老接口使用)
	int nStorageType;		///<存储类型：1-视频 ;2-图片 ;3-音频
	int nStorageModule;		///<存储模块：1-报警处置;2-日常巡查;3-门禁认证
	char chGUID[64];		///<报警生成的GUID
}T_CheckInfoTotalData, *LPT_CheckInfoTotalData;

//未打开视频抓图时，请求参数结构（20）
typedef struct
{
    int nDevId;        //关联通道ID（摄像头的编号）
}T_CAPTUREWITHOUTOPEN_INFO,*LPT_CAPTUREWITHOUTOPEN_INFO;

//门禁控制请求参数结构（21）
typedef struct
{
	char chAlarmSource[64];  // 报警源名称
	int nCmd;                // 0-锁定 1-解锁 2-开门   
}T_CONTROLACSHOSTPRARM,*LPT_CONTROLACSHOSTPRARM;

//获取中心详细信息
typedef struct
{
	int nType;						// =1:本级中心；=2:备份中心；=3:下级中心
	int nCMSId;						// CMS整型编号
	int nCMSFatherId;				// 该CMS上级CMS整型编号
}CMS_INFO,*PCMS_INFO;

//获取区域节点详细信息（区域）
typedef struct
{	
	char chCode[NODE_CODE_LEN];             // 节点编码(用于构造树)
	char chName[NODE_NAME_LEN];             // 节点名称(用于显示树)
	char chFatherNo[NODE_CODE_LEN];         // 上一级编码(用于构造树)
	char chCenterNo[CENTER_CODE_LEN];       // 中心编号
	char chFatherCenterNo[CENTER_CODE_LEN]; // 父中心编号
	int nId;								// 节点ID
	int nLevel;								// 节点级别（1~99,100,101,102,200）
}AREA_NODE_INFO,*PAREA_NODE_INFO;

//获取主机设备信息(DVR、报警主机) 
typedef struct
{
	char chIp[DEVICE_IP_LEN];					// 设备IP地址
	char chCode[NODE_CODE_LEN];					// 节点编码(用于构造树)
	char chName[DEVICE_NAME_LEN];				// 设备名称(用于显示树)	
	char chAreaCode[NODE_CODE_LEN];				// 所在区域编码
	char chCenterNo[CENTER_CODE_LEN];			// 中心编号
	char chFatherCenterNo[CENTER_CODE_LEN];		// 父中心编号
	int nId;									// 节点ID
	int nLevel;									// 节点级别（1~99,100,101,102,200）	
	int nManufacturerType;						// 厂商类型
}DEV_NODE_INFO,*PDEV_NODE_INFO;

//获取摄像机节点
typedef struct
{
	char chCode[NODE_CODE_LEN];					// 节点编码(用于构造树)
	char chName[DEVICE_NAME_LEN];				// 设备名称(用于显示树)
	char chAreaCode[NODE_CODE_LEN];				// 所在区域编码
	char chHostCode[NODE_CODE_LEN];				// 所属主机编码
	char chCenterNo[CENTER_CODE_LEN];			// 中心编号
	char chFatherCenterNo[CENTER_CODE_LEN];		// 父中心编号
	int nId;									// 节点ID
	int nLevel;									// 节点级别（1~99,100,101,102,200）
	int nChannelNo;								// 通道号
}CAMERA_NODE_INFO,*PCAMERA_NODE_INFO;

//收藏我的图表(图表类型值枚举)
typedef enum
{
	E_CHART_TYPE_OPENDOOR = 1,			//第三方认证收藏图表类型值
	E_CHART_TYPE_ALARM,					//报警模块收藏图表类型值
	E_CHART_TYPE_SYSDOCTOR_DEV_STAT,	//智能运维设备统计收藏图表类型值
	E_CHART_TYPE_SYSDOCTOR_MALF_STAT,	//智能运维故障统计收藏图表类型值
}E_CHART_COLLECT_VALUE;
 
// //获取主机设备信息(DVR、报警主机)  包含资产编号
// typedef struct
// {
// 	char chIP[20];			///<IP地址
// 	char chDeviceCode[32];	///<设备编码
// 	char chDeviceName[128];	///<设备名称
// 	char chUpperCode[32];	///<所在区域编码
// 	int nCenterNo;			///<中心ID
// 	int nFatherCenterNo;	///<父中心ID
// 	int nDeviceId;			///<设备ID
// 	int nDeviceLevel;		///<设备等级
// 	char chCapitalCode[32];	///<资产编码
// 
// }DEVICEINFOWITHCAPITAL_GET_S,*PDEVICEINFOWITHCAPITAL_GET_S;
// //获取摄像机节点 包含资产编号
// typedef struct
// {
// 	char chFrontendCode[32];	///<前端设备编码
// 	char chFrontendName[128];	///<前端设备名称
// 	char chUpperCode[32];		///<所在区域编码
// 	char chDeviceCode[32];		///<所属设备编码
// 	int nCenterNo;				///<中心ID
// 	int nFatherCenterNo;		///<父中心ID
// 	int nDeviceId;				///<设备ID
// 	int nDeviceLevel;			///<设备等级
// 	int nChannelNo;				///<通道号
// 	char chCapitalCode[32];		///<资产编码
// 
// }FRONTENDNODEINFOWITHCAPITAL_GET_S,*PFRONTENDNODEINFOWITHCAPITAL_GET_S;

struct TPatrolResult
{
	unsigned int error;			// 错误码，0表示成功
	unsigned int reserved[2];	// 保留，0
	unsigned int count;			// 巡检异常结果条数，0表示一切正常
};

// 视频质量巡检结果
struct TPatrolResultVideoQuality
{
	short channel;				// 视频通道
	short event;				// EEventPatrolExcept
	char reserved[4];			// 保留，0
	char pictureID[32];			// 图片存储在文件服务器中的ID
};

// 节点状态类型
enum ENodeStateType
{
	NODE_STATE_TYPE_CPU = 1,	//CPU
	NODE_STATE_TYPE_MEMORY,		//内存
	NODE_STATE_TYPE_NETWORK,	//网络
};

// 节点状态巡检结果
struct TPatrolResultNodeState
{
	short	type;			//状态类型，参见ENodeStateType
	char	flag;			//0-正常，1-异常
	char	param;			//保留
	int		total;			//总量（CPU-无，内存-MB，网络-MB）
	double	usage;			//使用率
	int		data1;			//保留
	int		data2;			//保留
	char	reserved[8];	//保留
};

//获取考拉在线人员信息
typedef struct
{
	int  msg;						// 消息类型（固定值：200003）
	char guid[64];					// 报警唯一标识
	char reserved[32];				// 预留
}TGetOnlineUserToKoala, *LPTGetOnlineUserToKoala;

//在线人员
typedef struct
{
	int  msg;			// 消息类型（固定值：201006）
	char guid[64];      // 报警唯一标识
	int  usercount;		// 用户数量（根据数量获取附加用户具体信息）
}TOnlineUserToZONEE, *LPTOnlineUserToZONEE;

//附加用户信息，单个用户信息内容
typedef struct
{
	int  busy;			// 状态（0：闲，1：忙）
    long id;            //用户id
	char name[40];		// 用户名称
	char describe[64];	// 描述
	char address[64];	// GPS信息
}TUserInfo, *LPTUserInfo;

//请求确认警情、指派人员处警、指派人员协助
typedef struct
{
	int	msg;				// 消息类型（固定值：200001）
	int operate;			// 操作类型（0：请求确认警情，1：指派人员处警，2：指派人员协助）
	char guid[64];			// 唯一标识
	char sourcename[40];	// 报警源名称
	char locate[40];		// 场所
	char part[40];			// 部位
	char alarmtype[40];		// 报警类型
	int  alarmlevel;		// 报警等级
	char time[40];			// 报警时间
	char address[64];		// GPS位置（预留）
	char describe[256];		// 描述
	char files[256];		// 附件串
	char koalausers[256];	// 考拉端确警处理人员串
}TRequestVerifyAlarmToKoala, *LPTRequestVerifyAlarmToKoala;


//确认警情反馈
typedef struct
{
	int	 msg;				// 消息类型（固定值：201007）
	int  operate;			// 操作类型（0：确警反馈，1：确警结果反馈，2：处警反馈）
	int  state;				// 0：接受，1：拒绝
	char guid[64];			// 唯一标识
	char time[40];			// 确警时间		
	char user[40];			// 保安人员(第一个确警人员，第二个协助人员)
	char describe[256];		// 描述
	char files[256];		// 附件串
	char refusereason[64];	// 拒绝原因
	char plan[64];			// 预案（预留）
}TVerifyAlarmFeedBackToZONEE, *LPTVerifyAlarmFeedBackToZONEE;


//考拉内部指派人员后的信息通知
typedef struct
{
	int	 msg;				// 消息类型（固定值：201008）
	char guid[64];			// 唯一标识
	char time[40];			// 指派时间		
	char manager[40];		// 指派者
	char executer[128];		// 被指派者
	char describe[256];		// 描述
	char files[256];		// 附件串
}TAssignmentNotifyToZONEE, *LPTAssignmentNotifyToZONEE;

//请求协助
typedef struct
{
	int	 msg;				// 消息类型（固定值：201001） 
	int	 operate;			// 操作类型
	char guid[64];			// 报警唯一标识
	char user[40];			// 用户
	char time[40];			// 发生时间
	char describe[256];		// 描述
	char files[256];		// 附件串
	char reserved1[40];		// 预留1
	char reserved2[40];		// 预留2
}TRequestHelpToZONEE, *LPTRequestHelpToZONEE;


//上报报警预案、切换预案
typedef struct
{
	int	 msg;			// 消息类型（固定值：200002）
	int operate;		// 操作类型（0：上报预案，1：切换预案）
	int state;			// 警情类型
	char guid[64];		// 唯一标识
	char sourcename[40];// 报警源名称
	char alarmtype[40];	// 报警类型
	int  alarmlevel;	// 报警等级
	char planguid[64];	// 预案唯一标识
	int	 id;			// 预案id
	char planname[40];	// 预案名称
	char describe[256];	// 描述
	int	 stepscount;	// 附加动作数量（根据数量获取附加动作具体内容）
}TDealAlarmInfoToKoala, *LPTDealAlarmInfoToKoala;

//附加动作，单个动作内容：
typedef struct
{
	int	order;				// 动作序号（从0开始）
	int state;				// 动作执行状态（0：执行完，1：跳过）
	char stepguid[64];		// 动作唯一标识
	int id;					// 动作id
	int performer;			// 执行者
	int necessary;			// 必须执行（0：必须执行，1：可选）
	char name[40];			// 动作名称
	char describe[128];		// 动作描述
	char user[40];			// 处理人
	char begintime[40];		// 开始时间
	char endtime[40];		// 结束时间
	char files[256];		// 附件串
}TDealStep, *LPTDealStep;


//众绎处置进度上报
typedef struct
{
	int  msg;				// 消息类型（固定值：200004）
	int  state;				// 执行状态（0：执行完，1：跳过）
	char guid[64];			// 报警唯一标识
	char planguid[64];		// 预案唯一标识
	int  order;				// 动作序号（从0开始）
	char stepguid[64];		// 动作唯一标识
	int  id;				// 动作Id
	char name[40];			// 动作名称
	char detail[128];		// 动作描述
	char user[40];			// 处理人
	char begintime[40];		// 开始时间
	char endtime[40];		// 结束时间
	char describe[256];		// 描述
	char files[256];		// 附件串
}TDealStepToKoala, *LPTDealStepToKoala;


//众绎处置结束
typedef struct
{
	int  msg;				// 消息类型（固定值：200005）
	int  state;				// 状态（0：结束）
	char guid[64];			// 报警唯一标识
	char describe[128];		// 动作描述
	char label[40];			// 警情类型（实警、误报等）
	char user[40];			// 处理人
	char time[40];			// 开始时间
	char files[256];		// 附件串
}TDealEndToKoala, *LPTDealEndToKoala;

//收到考拉上报处置结束后反馈
typedef struct
{
	int msg;				// 消息类型 (固定值：200006)
	int operate;			// (为0)
	int state;				// 众绎端处置状态 (0:未结束, 1:结束)
	char guid[64];			// 报警唯一标识
	char describe[128];		// 描述
	char reserved[64];		// 预留
}TFeedBackToKoala, *LPTFeedBackToKoala;

//考拉处置进度上报
typedef struct
{
	int  msg;				// 消息类型（固定值：201002）
	int  state;				// 执行状态（0：执行完，1：跳过）
	char guid[64];			// 报警唯一标识
	char planguid[64];		// 预案唯一标识
	int  order;				// 动作序号
	char stepguid[64];		// 动作唯一标识
	int  id;				// 动作id
	char name[40];			// 动作名称
	char detail[128];		// 动作描述
	char user[40];			// 处理人
	char begintime[40];		// 开始时间
	char endtime[40];		// 结束时间
	char describe[256];		// 描述
	char files[256];		// 附件串
}TDealStepToZONEE, *LPTDealStepToZONEE;

//考拉上报报警附件
typedef struct
{
	int  msg;			// 消息类型（固定值：201005）
	char guid[64];		// 报警唯一标识
	char user[40];		// 提交人
	char files[256];	// 附件串
}TAlarmFileToZONEE, *LPTAlarmFileToZONEE;


//考拉上报处置结束
typedef struct
{
	int  msg;				// 消息类型（固定值：201003）
	int  state;				// 状态（0：结束）
	char guid[64];			// 报警唯一标识
	char describe[128];		// 动作描述
	char label[40];			// 警情类型（实警、误报等）
	char user[40];			// 处理人
	char time[40];			// 开始时间
	char files[256];		// 附件串
}TDealEndToZONEE, *LPTDealEndToZONEE;

/************* 第三方认证特有 ***************/
// 第三方消息转发消息结构体
typedef struct
{
	unsigned int ucMsgType;       //消息类型
	int ucDealStatus;            //处理状态 1-未处理、2-处理中、3-待审核、4-已处理、5-已失效
	int nApplyID;                 //认证ID
	char chSender[64];            //发送者

}T_TRANS_OPENDOOR_INFO,*LPT_TRANS_OPENDOOR_INFO;
typedef enum
{
	MT_CURRENTSTATUS      = 0x01,     // 通知更改认证当前状态
	MT_APPLYAUTHORIZATION = 0x02,     //申请授权
	MT_APPLYAPPROVAL      = 0x04,     //申请特批
	MT_REFUSEOPENDOOR     = 0x08,     //拒绝开门
	MT_EMERGENCYPLANCALL  = 0x10,     //应急处置
}T_TRANS_OPENDOOL_MESSAGETYPE;

#endif