/*********************************************************************
* 版权所有 (C)2010, 上海天跃科技有限公司。
* 
* 文件名称： CommonDefine.h
* 内容摘要： 公共数据定义，包括常量宏定义，数据结构定义等。
* 当前版本： 
* 作    者： 张小路
* 完成日期： 20100426
* 修改记录：1. 20100907  张小路 替换了数据类型定义。
*           2. 20100916  张小路 增加了状态获取时需要的数据结构。
*           3. 20101110  张小路 添加了消息发布的消息枚举和数据结构
**********************************************************************/
#ifndef TY_SERVER_COMMONDEFINE_H
#define TY_SERVER_COMMONDEFINE_H

#include <stdio.h>
#include "TY_Type.h"
#include "ErrorCode.h"

//-------------------------------------------------------------------
//常量宏定义
#define IP_LENGTH           20      //IP地址长度
#define ID_LENGTH           20      //用户编号ID长度
#define NAME_LENGTH         20      //名称长度
#define PASSWORD_LENGTH     20      //密码长度
#define KEY_LENGTH          20      //key的长度
#define SESSIONID_LENGTH    32      //会话ID长度
#define DEV_ID_LENGTH       20      //设备编号ID长度
#define HANDLE_LENGTH       20      //句柄长度
#define MAX_CASCADE         5	    //最大级联数量	
#define FILE_NAME_LENGTH    60      //文件名长度
#define FILE_INFO_LENGTH    20      //文件描述长度
#define SYS_HEADER_LENGTH   256     //系统头长度
#define CLIENT_PSW_LENGTH   128     //客户端登录CMS密码长度
#define FILE_FULL_PATH_LENGTH 255   //文件全路径长度
#define VODSESSIONIDLEN     1

//---------------------------------------------------------------------
//音视频数据类型宏定义
#define SYSHEAD_DATA         0   //系统头信息
#define AUDIO_AND_VIDEO_DATA 1   //音视频混合数据
#define VIDEO_DATA           2   //视频数据
#define AUDIO_DATA           3   //音频数据
#define FILE_DATA            4  //文件数据

//----------------------------------------------------------------------
//回调消息类型宏定义
//对讲相关信息
#define CLIENT_TALK_REQUEST 1000    //客户端对讲请求
#define CLIENT_TALK_REFUSE  1001    //客户端拒绝对讲
#define CLIENT_TALK_STOP    1002    //客户端停止对讲
#define CLIENT_TALK_FAIL    1003    //客户端建立对讲失败 
#define CLIENT_TALK_OK      1004    //客户端建立对讲成功
#define CLIENT_TALK_IN_TALK 1005    //客户端正在进行对讲

//升级相关信息
#define DEV_VERSION_INF0         1100   //设备版本信息
#define CLIENT_NEWVERSION_INFO   1101   //客户端版本信息
#define START_CLIENT_UPGRADE     1102   //客户端开始升级反馈 

//云台控制结果
#define PTZ_CTRL_RESULT          1200   //云台控制操作反馈

//群呼相关
#define REQ_MULTITALK_RESULT     1300   //群呼申请结果
#define ADD_MULTITALK_RESULT     1301   //添加群呼设备结果

//时间管理相关
#define CMS_TIME_INFO            1400   //CMS时间信息
#define DEV_TIME_INFO            1401   //设备时间信息
#define SET_DEV_TIME_BACK        1402   //设置设备时间反馈
#define SET_TIME_NOTICE          1403   //CMS校时通知
#define SETTIME_PLAN_MOD         1404   //校时计划修改消息发布 

//消息转发
#define MSG_TRANS_BY_CMS         1500   //经过中心管理服务器转发的消息 
#define MSG_TRANS_RESP           1501   //消息转发成功与否反馈

//消息通知与发布相关
#define USER_LOGIN_CMS           1600   //用户上线
#define USER_LOGOUT_CMS          1601   //用户下线
#define TALK_REQUST              1602   //呼叫请求
#define TALK_NOTICE              1603   //呼叫通知
#define DEV_MODIFY               1604   //设备属性修改
#define SERVER_LOGIN             1605   //服务器上线
#define SERVER_LOGOUT            1606   //服务器下线
#define SETTIME_ERROR_NOTICE     1607   //计划校时失败通知
#define DEV_SETTIME_FAIL         1608   //计划校时单台设备校时失败
#define TICK_USER_OUT            1609   //用户被踢下线
#define VIEW_TICK_OUT            1610   //预览被高等级用户踢下线
#define DEV_USERNAME_PWD_MOD     1611   //登录设备的用户名或者密码修改
#define DEV_IP_MOD               1612   //设备的IP修改
#define EMERGENCY_PLAN_MOD       1613   //应急预案修改 
#define ADD_NODE                 1614   //添加节点
#define DEL_NODE                 1615   //删除节点
#define MOD_NODE                 1616   //修改节点
#define MOV_NODE                 1617   //移动节点
#define ADD_NODETYPE             1618   //添加节点
#define MOD_NODETYPE             1619   //修改节点
#define DEL_NODETYPE             1620   //删除节点
#define MSSTORE_PlAN_MOD         1621  //录像计划的修改
#define MSSTORE_CLAER_MOD        1622  //清盘策略的修改
#define MSSTORE_SET_MOD          1623  //录像设置修改
#define ALARMCONFIG_MOD_REL      1624  //报警类型策略修改
#define ROUTEREGULATION_MOD_REL  1625  //路由规则修改 


//设备控制相关
#define DEV_REROOT_RESULT        1700   //设备重启结果
#define DEV_SHUTDOWN_RESULT      1701   //关闭设备结果
#define CTRL_ALARMIN_RESULT      1702   //布撤防控制结果
#define CTRL_ALARMOUT_RESULT     1703   //报警输出控制结果
#define CTRL_VIDEOPARA_RESULT    1704   //视频参数调节结果
#define CTRL_AIRCONDTION_RESULT  1705   //空调开关控制结果
#define CTRL_ACPARAM_RESULT      1706   //空调参数调节结果   
#define CTRL_ALARMHOST_RESULT	 1707	//报警主机控制

//设备状态相关
#define DEV_ONLINE_STATE         1800  //设备在线状态
#define DEV_RUN_STATE            1801  //设备运行状态
#define DISK_STATE               1802  //硬盘状态
#define ALMIN_STATE              1803  //报警输入探头状态
#define ALMOUT_STATE             1804  //报警输出状态
#define CHANNEL_STATE            1805  //通道状态
#define ENVIRONMENT_STATE        1806  //环境状态
#define ACCESS_STATE             1807  //门禁状态
#define VIDEO_PARAM              1808  //视频参数
#define ALARMHOST_STATE			 1809  //报警主机状态

#define PATROL_ARM_STATE		 1810  //巡检布撤防状态
#define PATROL_CLOCK_STATE		 1811  //巡检时钟状态
#define PATROL_DISK_STATE		 1812  //巡检硬盘状态
#define PATROL_RECORD_STATE		 1813  //巡检录像状态
#define PATROL_RECORD_DAYS		 1814  //巡检录像天数
#define PATROL_RECORD_INTEGRITY	 1815  //巡检录像完整性
#define PATROL_VIDEO_QUALITY	 1816  //巡检视频质量诊断
#define PATROL_NODE_STATE		 1817  //节点状态

//用户状态相关
#define USER_ONLINE_STATE        1900  //用户在线状态
#define USER_REALPLAY_STATE      1901  //用户预览状态
#define USER_REMOTEPLAY_STATE    1902  //用户回放状态
#define USER_DOWNLOAD_STATE      1903  //用户下载状态
#define USER_TALKBACK_STATE      1904  //用户对讲状态
#define MS_STATE                 1905  //媒体服务器状态
#define AS_STATE                 1906  //报警服务器状态
#define CMS_STATE                1907  //中心管理服务器状态
#define USER_VERSION             1908  //用户所登录客户端的版本信息
#define ONLINE_USER              1909  //在线用户列表   
#define ONLINE_MS                1910  //在线媒体信息
#define ONLINE_AS                1911  //在线报警服务器信息   
#define ONLINE_MS_EX             1912  //在线媒体信息EX
#define ONLINE_AS_EX             1913  //在线报警服务器信息EX
#define ONLINE_USER_EX           1914  //在线用户列表EX

//文件上传于下载，回放操作相关
#define FILE_UPLOAD_END          2000  //文件上传结束
#define FILE_DOWNLOAD_END        2001  //文件下载结束
#define FILE_PLAYBACK_POS		 2002  //操作文件回放位置
#define FILE_PLAYBACK_GETPOS	 2003  //获取文件回放位置
#define FILE_PLAYBACK_SETTIME    2004  //操作文件回放时间
#define FILE_PLAYBACK_GETTIME	 2005  //获取文件回放时间
#define FILE_PLAYBACK_SETSPEED	 2006  //设置回放倍速

//级联相关信息获取
#define CASCADE_INFO_CMS		 2101	//中心信息 (传入参数，传出参数)
#define CASCADE_INFO_USER		 2102	//用户信息 (P_UserInfo, S_UserInfo)
#define CASCADE_INFO_PRIVILEGE	 2103	//权限信息 (Char[64], S_ShowClientPrivilegeInfo)
#define CASCADE_INFO_AREANODE	 2104	//区域信息 (P_AreaInfo, S_AreaNodeInfo)
#define CASCADE_INFO_DEVNODE	 2105	//设备信息 (NULL, S_DevNodeInfo)
#define CASCADE_INFO_FRONTNODE	 2106	//前端节点信息 (NULL, S_FrontendNodeInfo)
#define CASCADE_INFO_FRONTALARM	 2107	//前端设备报警类型 (P_FrontendAlarmInfo, S_FrontendAlarmInfo)
#define CASCADE_INFO_DEVALARM	 2108	//主机报警类型信息 (P_HostAlarmInfo, S_HostAlarmInfo)
#define CASCADE_INFO_ALARMHOST	 2109	//报警主机信息 (P_AlarmPartionInfo, S_AlarmPartionInfo)
#define CASCADE_INFO_DEVTALK	 2110	//主机对讲关联信息 (NULL, S_HostTalkInfo)
#define CASCADE_INFO_CHLTALK	 2111	//通道对讲关联信息 (NULL, S_FrontendTalkInfo)
#define CASCADE_INFO_GISMAP		 2112	//GIS设置信息 (P_GSMAPSHOWInfo, S_GSMAPShowInfo)
#define CASCADE_INFO_PTZ_PRESET	 2113	//云台预置点信息 (NULL, S_ShowPrePointInfo)
#define CASCADE_INFO_PTZ_TRACE	 2114	//云台巡航信息  (NULL, S_ShowCruiseInfo)
#define CASCADE_INFO_PTZ_LOCUS	 2115	//云台轨迹信息 (NULL, S_ShowPrePointInfo)

#define MSG_VIDEO_CLIENT_KICKOUT 2200	//视频用户抢占

//第三方系统交互相关
#define THIRDPART_MESSAGE_SY_SCHEDULE_INFO		3000	//获取指定网点的押运排班信息(守押)[REQ:int,组织机构id][RESP:TSyScheduleList]
#define THIRDPART_MESSAGE_SY_IMAGE				3001	//获取各种类型的图片(守押)[REQ:TSyGetImage][RESP:TSyImageId]
#define THIRDPART_MESSAGE_SY_SERVER_TIME		3002	//获取服务器时间(守押)[REQ：无][RESP:T_TIME_INFO]
#define THIRDPART_MESSAGE_SY_ROUTE_STATUS		3003	//获取指定网点押运路线的状态(守押)[REQ:int,组织结构id][RESP:TSyRouteList]
#define THIRDPART_MESSAGE_SY_TAG_DATA			3004	//获取电子标签卡的详细信息(守押)[REQ:TSyGetTagData][RESP:TSyTagDataList]

//-----------------------------------------------------------------------
//异常消息宏定义
#define USER_EXCHANGE_ERR   1      //用户交互异常
#define ALARM_EXCHANGE_ERR  2      //报警服务器交互异常 
#define REALPLAY_ERR        3      //预览异常
#define PLAYBACK_ERR        4      //回放异常
#define DOWNLOAD_ERR        5      //下载异常
#define FILE_DOWNLOAD_ERR   6      //附件下载异常 
#define FILE_UPLOAD_ERR     7      //附件上传异常
#define CLIENT_TALKCMD_ERR  8      //客户端对讲命令接收异常
#define CLIENT_TALKDATA_ERR 9      //客户端对讲数据接收异常 
#define REALPLAY_RESTORE    10	   //视频恢复，客户端使用		
//------------------------------------------------------------------------
//定义增值模块
#define MODULE_LXJC_SHORT	"LXJC"
#define MODULE_LXJC_NAME	"录像检查模块"

#define MODULE_SJGL_SHORT	"SJGL"
#define MODULE_SJGL_NAME	"事件管理模块"

#define MODULE_PERIOD_FORBIDDEN		(-1)
#define MODULE_PERIOD_UNLIMITED		0
#define MODULE_PERIOD_LIMITED		1

/****************************************************************************
*************************函数原型********************************************
****************************************************************************/

//回调函数原型
//----------------------------------------------------------------------------
//异常消息回调函数
/****************************************************************************
* 函数名称：ExceptionMsgCallBack
* 功能描述：异常消息回调函数，用来回调异常消息。
* 参    数：dwExceptMsg 异常消息类型；
            lHandle 对应的操作句柄；
            dwUser 用户自定义参数。
* 返 回 值： 无。
*****************************************************************************/
typedef void(__stdcall *ExceptionMsgCallBack)(U_LONG_TY dwExceptMsg, LONG_TY lHandle, U_LONG_TY dwUser);

//消息回调函数
/****************************************************************************
* 函数名称：MsgCallBack
* 功能描述：消息回调函数，用来回调各种消息。
* 参    数：lUserID 登录中心管理服务器返回的操作句柄；
		    MsgType 消息类型；
		    chMsgBuf 消息描述缓冲区；
		    dwBufSize 消息缓冲长度；
		    dwUser 用户参数。
* 返 回 值： 无。
*****************************************************************************/
typedef void(__stdcall *MsgCallBack)(LONG_TY lUserID, U_LONG_TY MsgType,
                                    U_CHAR_TY *chMsgBuf, U_LONG_TY dwBufSize, U_INT_TY nMsgID, U_LONG_TY dwUser);

//报警消息回调
/****************************************************************************
* 函数名称：AlmMsgCallBack
* 功能描述：报警消息回调函数，用来回调报警消息。
* 参    数：lUserID 登录中心管理服务器返回的操作句柄；
		    chAlmMsgBuf报警消息缓冲区；
		    dwBufSize 消息缓冲长度；
            nMsgID 消息序列号；
		    dwUser 用户参数。
* 返 回 值： 无。
*****************************************************************************/
typedef void(__stdcall *AlmMsgCallBack)(LONG_TY lUserID, U_CHAR_TY *chAlmMsgBuf,
                              U_LONG_TY dwBufSize, U_LONG_TY dwUser);

//音视频数据回调函数
/****************************************************************************
* 函数名称：DataCallBack
* 功能描述：音视频数据回调函数，用来回调预览、回放、下载时的音视频数据。
* 参    数：lHandle 操作句柄；
		    dwDataType 数据类型；
		    pBuffer 数据缓冲区；
		    dwBufSize 缓冲区大小(1-检索结束，0-检索异常，其它-正常);
		    dwUser 用户参数
* 返 回 值： 无。
*****************************************************************************/
typedef void(__stdcall *DataCallBack)(LONG_TY lHandle, U_LONG_TY dwDataType, U_CHAR_TY *pBuffer,
                            U_LONG_TY dwBufSize, U_LONG_TY dwUser);

//文件列表回调函数
/****************************************************************************
* 函数名称：FileListCallBack
* 功能描述：文件列表回调函数，回调检索文件列表时的文件信息。
* 参    数：llUserID登录中心管理服务器返回的操作句柄；
		    buf 数据缓冲区；
		    dwBufSize 缓冲区大小；
		    dwUser 用户参数。
* 返 回 值： 无。
*****************************************************************************/
typedef void(__stdcall *FileListCallBack)(LONG_TY lUserID, void *buf, U_LONG_TY dwBufSize, U_LONG_TY dwUser);

//对讲语音数据回调函数
/****************************************************************************
* 函数名称：TalkDataCallBack
* 功能描述：对讲语音数据回调函数，用来回调语音对讲时的语音数据。
* 参    数：lTalkID 对讲操作句柄；
		    DataBuffer数据缓冲区；
		    dwBufSize 缓冲区大小；
		    byAudioFlag 数据来源标志(接收到的远程数据或者本地采集到的数据)；
		    dwUser 用户参数。
* 返 回 值： 无。
*****************************************************************************/
typedef void(__stdcall *TalkDataCallBack)(LONG_TY lTalkID, U_CHAR_TY *DataBuffer,
                                U_LONG_TY dwBufSize, U_CHAR_TY byAudioFlag, U_LONG_TY  dwUser);

//进度回调函数
/****************************************************************************
* 函数名称：PosCallBack
* 功能描述：该函数主要用于将文件上传的进度回调给上层应用程序。
* 参    数：lUpLoadID 上传操作句柄；
		    dwUpLoadSize 已经上传的数据大小；
		    dwTotalSize 文件的总大小；
		    dwUser 用户参数。
* 返 回 值： 无。
*****************************************************************************/
typedef void(__stdcall *PosCallBack)(LONG_TY lUpLoadID, U_LONG_TY dwUpLoadSize,
                           U_LONG_TY dwTotalSize,  U_LONG_TY dwUser);
//---------------------------------------------------------------------------

/*****************************************************************************/
/************************命令枚举定义*****************************************/
/*****************************************************************************/
#if 0 
/*******************************************************************************
此部分定义和"porotocol.h"中相同，考虑到客户端需要这部分定义而不需要"porotocol.h",
故将其在此重新定义，客户端使用时将0改为1即可。
*******************************************************************************/

//设备控制操作请求枚举 MSG_REQ_DEV_CTR
typedef enum
{
    MSG_REQ_CTRL_DEV_REBOOT   = 0x00000001,  //设备重启
    MSG_REQ_CTRL_DEV_SHUTDOWN = 0x00000002,  //设备关机
    MSG_REQ_CTRL_ALMIN        = 0x00000004,  //报警探头控制
    MSG_REQ_CTRL_ALMOUT       = 0x00000008,  //报警输出控制
    MSG_REQ_CTRL_VIDEOPARAM   = 0x00000010,  //视频参数控制
    MSG_REQ_CTRL_AIRCONDTION  = 0x00000020,  //空调开关控制
    MSG_REQ_CTRL_ACPARAM      = 0x00000040,  //空调参数调节
	MSG_REQ_CTRL_ALARMHOST    = 0x00000080   //报警主机控制
}E_MSG_REQ_DEV_CTRL;

//设备状态获取请求枚举 MSG_REQ_GET_DEV_STATE
typedef enum
{
    MSG_REQ_DEV_ONLINE_STATE  = 0x00000001,     //设备在线状态
    MSG_REQ_DEV_RUN_STATE     = 0x00000002,     //设备运行状态
    MSG_REQ_DISK_STATE        = 0x00000008,     //硬盘状态
    MSG_REQ_ALMIN_STATE       = 0x00000010,     //报警探头状态
    MSG_REQ_ALMOUT_STATE      = 0x00000020,     //报警输出状态
    MSG_REQ_CHANNEL_STATE     = 0x00000040,     //通道状态
    MSG_REQ_ENVIRONMENT_STATE = 0x00000080,     //环境状态
    MSG_REQ_ACCESS_STATE      = 0x00000100,     //门禁状态
    MSG_REQ_VIDEO_PARAM       = 0x00000200,     //视频参数
    MSG_REQ_ALARMHOST_STATE   = 0x00000400	//报警主机状态
}E_MSG_REQ_GET_DEV_STATE;

//获取用户状态请求枚举 MSG_REQ_GET_USER_STATE
typedef enum
{
    MSG_REQ_USER_ONLINE_STATE     = 0x00000001,	//用户在线状态
    MSG_REQ_USER_REALPLAY_STATE   = 0x00000002,	//用户预览状态
    MSG_REQ_USER_REMOTEPLAY_STATE = 0x00000004, //回放状态
    MSG_REQ_USER_DOWNLOAD_STATE   = 0x00000008,	//下载状态
    MSG_REQ_USER_TALKBACK_STATE   = 0x00000010, //对讲状态
    MSG_REQ_USER_VERSION          = 0x00000100, //用户所登录客户端的版本信息
    MSG_REQ_ONLINE_USER           = 0x00000200,  //获取在线用户列表
    MSG_REQ_ONLINE_USER_EX        = 0x00000400 //获取在线用户信息列表
}E_MSG_REQ_GET_USER_STATE;

//获取服务器信息的子类型 MSG_REQ_GET_SERVER_STATE
typedef enum
{
    MSG_REQ_ONLINE_MS			  = 0x00000001, //获取在线媒体服务器信息
    MSG_REQ_ONLINE_AS			  = 0x00000002, //获取在线报警服务器信息
    MSG_REQ_MS_STATE          	  = 0x00000004, //媒体服务器状态
    MSG_REQ_AS_STATE              = 0x00000008, //报警服务器状态
    MSG_REQ_CMS_STATE             = 0x00000010, //中心管理服务器状态
    MSG_REQ_ONLINE_MS_EX		  = 0x00000020, //获取在线媒体信息
	MSG_REQ_ONLINE_AS_EX		  = 0x00000040 //获取在线报警信息
}E_MSG_REQ_GET_SERVER_STATE;

#endif


//-----------------------------------------------------------------------------
//加密类型
typedef enum
{
    ENCRYPT_TYPE_CLEAR = 0,	//明文
    ENCRYPT_TYPE_TY,        //私有加密
    ENCRYPT_TYPE_MD5 = 10,  //MD5
}E_ENCRYPT_TYPE;

//-----------------------------------------------------------------------------
//认证类型
typedef enum
{
    AUTH_TYPE_DEFAULT = 0,	//默认（使用中心配置的方式认证）
    AUTH_TYPE_ZONEE,        //内部认证（使用原有的平台内部认证方式）
    AUTH_TYPE_LDAP,         //LDAP认证
    AUTH_TYPE_RADIUS,       //RADIUS认证
}E_AUTH_TYPE;

//-----------------------------------------------------------------------------
//码流类型
typedef enum
{
    STREAM_TYPE_DEF = 0,    //缺省值，预设值或标清
    STREAM_TYPE_CIF,        //流畅（CIF）
    STREAM_TYPE_D1,         //标清（D1）
    STREAM_TYPE_720P,       //高清（720p）
    STREAM_TYPE_1080P,      //超清（1080p）
}E_STREAM_TYPE;

//-----------------------------------------------------------------------------
//录像文件类型
typedef enum
{
    REC_FILE_ALL = 0,   //所有录像
    REC_FILE_TIMING,    //定时录像
    REC_FILE_MANUAL,    //手工录像
    REC_FILE_ALARM,     //报警录像
    REC_FILE_MOVE,      //移动侦测 
}E_REC_FILE_TYPE;

//-----------------------------------------------------------------------------
//对讲通知枚举
typedef enum
{
    TALK_OK = 0,  //对讲成功
    TALK_FAIL,    //对讲失败
    TALK_ACCEPT,  //接受对讲
    TALK_REFUSE,  //拒绝对讲
    TALK_STOP,    //停止对讲 
    TALK_WAIT_TIMEOUT,  //等待超时

    //呼入
    TALK_OK_EX,
    TALK_FAIL_EX,
    TALK_STOP_EX,

	TALK_IN_TALK = 100,	//对方正在进行呼叫

}E_TALK_RESULT;

//发布信息枚举（配置客户端使用）
typedef enum
{
    NODETYPE_ADD = 100,   //节点类型添加
    NODETYPE_MOD = 101,   //节点类型修改
    NODETYPE_DEL = 102,   //节点类型删除

    NODE_ADD = 200,   //添加节点
    NODE_MOD = 201,   //修改节点
    NODE_DEL = 202,   //删除节点
    NODE_MOV = 203,   //移动节点

    ALARMCONFIG_MOD = 300,   //报警类型处理策略修改

    RECORDSET_MOD = 400,     //录像设置修改 
    STORAGEPLAN_MOD = 401,   //存储计划修改

    ROUTEREGULATION_MOD = 500,   //路由规则修改
    SETTIMEPLAN_MOD = 600    //校时计划修改	
}E_CLIENT_RELEASE;
/*****************************************************************************/
/************************结构体定义*******************************************/
/*****************************************************************************/
//时间信息结构
typedef struct
{
    U_LONG_TY dwYear;    //年
    U_LONG_TY dwMonth;   //月
    U_LONG_TY dwDay;     //日
    U_LONG_TY dwHour;    //时
    U_LONG_TY dwMinute;  //分
    U_LONG_TY dwSecond;  //秒		
}T_TIME_INFO, *LPT_TIME_INFO;

//时间信息结构扩展
typedef struct
{
	U_LONG_TY dwYear;    //年
	U_LONG_TY dwMonth;   //月
	U_LONG_TY dwDay;     //日
	U_LONG_TY dwHour;    //时
	U_LONG_TY dwMinute;  //分
	U_LONG_TY dwSecond;  //秒
	U_LONG_TY dwMilSecs; //毫秒
}T_TIME_INFO_EX, *LPT_TIME_INFO_EX;

//用户信息结构
typedef struct
{
    CHAR_TY chUserName[NAME_LENGTH]; //用户名
    CHAR_TY chUserPwd[CLIENT_PSW_LENGTH];  //用户密码
    INT_TY  nClientType;  //用户类型
	//INT_TY  nEncryptType; //加密方式  
	char byEncryptType;		//加密方式，见E_ENCRYPT_TYPE
	char byReserved1;		//0
	char byAuthType;		//认证类型，见E_AUTH_TYPE
	char byReserved2;		//0
    U_INT_TY unVersion;  //客户端版本号
}T_CLIENT_USERINFO, *LPT_CLIENT_USERINFO;

//用户名和类型
typedef struct
{
    CHAR_TY chUserName[NAME_LENGTH]; //用户名
    U_LONG_TY ulUserIP;     //IP
    INT_TY nUserType;		//类型
}T_USER_NAMEANDTYPE, *LPT_USER_NAMEANDTYPE;

//在线用户信息
typedef struct
{
	char userName[NAME_LENGTH]; //用户名
	int ip; //IP
	int type; //类型
	int version; //版本
	char reserved[32];
} T_USERINFO_ONLINE;

//用户上下线通知结构
typedef struct
{
    T_USER_NAMEANDTYPE TUserInfo;
    CHAR_TY chLogInKey[KEY_LENGTH];
}T_ANCE_USER, *LPT_ANCE_USER;

//服务器编号
typedef struct
{
    CHAR_TY chServerCode[NAME_LENGTH];
}T_SERVER_CODE, *LPT_SERVER_CODE;

//设备ID信息
typedef struct
{
    LONG_TY lCMSCascadeInfo[MAX_CASCADE];  //中心级联信息
    LONG_TY lDEVID;        		//设备ID
}T_DEVID_INFO, *LPT_DEVID_INFO;

//设备编号信息
typedef struct
{
    CHAR_TY chDEVCode[DEV_ID_LENGTH];
    U_LONG_TY nDEVID;
}T_DEV_CODE, *LPT_DEV_CODE;

//报警服务器信息
typedef struct
{
    U_LONG_TY ulASIP;  //报警服务器IP
    INT_TY nPort;             //端口号 
}T_AS_INFO, *LPT_AS_INFO;

//客户端信息
typedef struct
{
    U_LONG_TY ulIP;		//IP地址
    INT_TY  nPort;			//端口号
}T_CLIENT_INFO, *LPT_CLIENT_INFO;

//申请音视频预览结构
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      //设备ID信息
	union {
		INT_TY  nViewDataType;            //预览方式（音频、视频、音视频、图片等 0开始表示转发预览，0x10开始表示直连预览） 
		struct {
			SHORT_TY nStreamType; //码流类型，见E_STREAM_TYPE，0x10表示直连预览
			SHORT_TY nViewMode; //预览方式，0-普通预览，1-联动预览
		};
	};
    INT_TY  nChannel;                 //通道号
}T_VIEW_APPLYINFO, *LPT_VIEW_APPLYINFO;

//申请音视频预览结构扩展
typedef struct
{
	T_DEVID_INFO devInfo; //设备ID信息
	short stream; //0-默认，1-流畅，2-标清，3-高清，4-超清，16-直连
	short mode; //0-普通预览，1-联动预览
	int channel; //通道号
	int flag; // 0x1-存储（仅非直连时有效）
	int module; // 1-报警处置；2-日常巡查；3-门禁认证
	char guid[64]; // 关联的GUID
	char reserved[16]; // 保留
} T_VIEW_APPLYINFO_EX, *LPT_VIEW_APPLYINFO_EX;

//音视频预览反馈的媒体交互信息
typedef struct
{
    CHAR_TY chSessionID[SESSIONID_LENGTH];  //会话ID
    U_LONG_TY ulMSIP;   //媒体服务器IP
    INT_TY nPort;        //媒体端口号
    INT_TY nTransType;   //转发方式（0-TCP/1-UDP/2-组播）
    U_LONG_TY ulMulticastIP;   //组播地址
    INT_TY nMulticastPort;         //组播端口号
}T_MS_SESSION_INFO, *LPT_MS_SESSION_INFO;

//设备登录信息结构
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;            //设备ID信息,包含级联信息
    CHAR_TY chDEVID[DEV_ID_LENGTH];        //设备编号ID
    CHAR_TY chLoginName[NAME_LENGTH];      //登录用户名
    CHAR_TY chLoginPwd[PASSWORD_LENGTH];   //登录密码
    INT_TY  nDEVType;                      //设备类型 （哪个厂家的设备）
    U_LONG_TY ulDEVIP;              //设备IP
    INT_TY  nPort;                         //设备端口号
}T_DEV_LOGIN_INFO, *LPT_DEV_LOGIN_INFO;


//回放申请反馈信息结构
typedef struct
{
    T_DEV_LOGIN_INFO T_DevLogInInfo;   //登录设备信息
    U_LONG_TY    ulPlayBackLevel;  //回放权限
    U_LONG_TY    ulDownLoadLevel;  //下载权限
}T_REPLY_PLAYANDDOWN_INFO, *LPT_REPLY_PLAYANDDOWN_INFO;

//回放申请反馈信息结构扩展
typedef struct
{
    T_DEV_LOGIN_INFO T_DevLogInInfo;   //登录设备信息
    U_LONG_TY    ulPlayBackLevel[8];  //回放权限
    U_LONG_TY    ulDownLoadLevel[8];  //下载权限
}T_REPLY_PLAYANDDOWN_INFO_EX, *LPT_REPLY_PLAYANDDOWN_INFO_EX;


//检索文件条件信息结构
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      	//设备ID信息
	CHAR_TY chAreaName[64];			//网点名称
    T_TIME_INFO  T_StartTime;       //开始时间
    T_TIME_INFO  T_StopTime;        //结束时间   
    INT_TY  nChannel;               //通道号
    INT_TY  nStorageLoction;		//存储位置（0-DVR，按时间，1-存储设备，2-DVR，按文件转发）
    INT_TY  nFileType;			    //文件类型（1-计划存储，2-联动存储）
	CHAR_TY chAlarmTypeName[20];	//报警联动类型
    CHAR_TY chOtherInfo[20];        //其它条件
}T_SEARCHFILE_INFO, *LPT_SEARCHFILE_INFO;

//中心返回的检索文件单条结果
typedef struct
{
	CHAR_TY chDvrName[64];				//视频文件所属DVR名称
	INT_TY nChannel;					//视频文件通道编号
	CHAR_TY chFileName[16];				//视频文件名
	CHAR_TY chFilePath[32];				//文件的相对路径
	T_TIME_INFO T_VideoStartTime;		//视频文件开始时间
	T_TIME_INFO T_VideoEndTime;			//视频文件结束时间
}T_SEARCHFILE_CMS_RESULT_INFO, *LPT_SEARCHFILE_CMS_RESULT_INFO;

//回放，下载，点播的请求文件信息
typedef struct  
{
	CHAR_TY chFilePath[32];			//存储文件所在服务器的相对路径
	CHAR_TY chFileName[16];			//存储文件名
	CHAR_TY chReserved[12];			//保留字段
}T_PLAYBACKFILE_INFO, *LPT_PLAYBACKFILE_INFO;

//流媒体使用的文件描述
typedef struct
{
	INT_TY nFileType;				//文件类型 1. 视频；2. 音频；3. 图片
	INT_TY nFileFormat;				//文件编码 如果是视频，可以是.264、.DH等等
	LONG_TY lFileSize;				//文件大小，字节数
	LONG_TY lPlayTime;				//文件播放时长(预留)
	CHAR_TY chReserved[8];			//保留
	CHAR_TY chFileHeader[SYS_HEADER_LENGTH];		//文件头，用于初始化播放库
	INT_TY nHeaderSize;				//文件头大小
}T_PLAYBACKFILE_MS_INFO, *LPT_PLAYBACKFILE_MS_INFO;

//流媒体转发回放EX文件描述
typedef struct 
{
	int nErrorCode;
	int nPlayID;
	int nFileType;
	int nDevType;
	int nFileSize;
	char szReserved[8];
	char szFileHeader[260];
}T_PLAYBACKFILE_MS_EXINFO, *LPT_PLAYBACKFILE_MS_EXINFO;

//回放或者下载参数结构
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      	//设备ID信息，回放流媒体服务器上的文件时不需要设置该参数
    INT_TY nChannel;			    //通道信息
    INT_TY nStroageLocation;		//存储位置(0-DVR, 1-存储设备)
	T_MS_SESSION_INFO TMsSession;	//流媒体服务器Session和信息
}T_PLAYORDOWN_PARA, *LPT_PLAYORDOWN_PARA;

//请求流媒体回放点播数据结构
typedef struct  
{
	LONG_TY lFileId;			//请求数据的文件ID
	LONG_TY lStartPos;			//请求数据的开始位置
	INT_TY nReqSize;			//本次请求的数据大小， > 0 表示请求长度， = 0表示请求默认长度 ， < 0表示请求直到文件末尾的长度
	INT_TY nFlag;				//各种标识，保留
	CHAR_TY pcReserved[12];		//保留
}T_PLAYORDOWN_MSVOD_REQDATA, *LPT_PLAYORDOWN_MSVOD_REQDATA;

//流媒体相应点播数据请求的数据结构头
typedef struct
{
	INT_TY nErrorCode;			//错误码，0表示成功，其余失败
	LONG_TY lFileId;			//相应的文件ID
	LONG_TY lStartPos;			//请求的开始位置
	INT_TY nReqSize;			//请求的数据长度
	LONG_TY lPacketStartPos;	//本次发送的开始位置
	INT_TY nPacketSize;			//本次发送的数据长度
	INT_TY nFlag;				//标识位，0表示数据传输完毕，1表示还有剩余数据（相对于一次请求而言）
	CHAR_TY pcReserved[12];		//保留
}T_PLAYORDOWN_MSVOD_RESPDATA, *LPT_PLAYORDOWN_MSVOD_RESPDATA;

//请求流媒体按时间回放传输结构
typedef struct {
	INT_TY nIsBeginSeek;		//是否跳转
	INT_TY nReqDataType;		//请求数据方式
	INT_TY nTime;				//数据时间
	INT_TY nNum;				//请求数据包个数
	T_TIME_INFO_EX tSeekBegin;	//跳转开始时间
	CHAR_TY pcReserved[12];		//保留
} T_PLAYORDOWN_MSTIMEVOD_REQDATA, *LPT_PLAYORDOWN_MSTIMEVOD_REQDATA;

//流媒体按时间回放传输相应结构
typedef struct {
	INT_TY nErrorCode;				//错误码
	T_TIME_INFO_EX tCurrentTime;	//当前时间
	INT_TY nDataLength;				//数据长度
	INT_TY nFlag;					//标识位，0表示数据传输完毕，1表示还有剩余数据（相对于一次请求而言）
	CHAR_TY pcReserved[12];			//保留
} T_PLAYORDOWN_MSTIMEVOD_RESPDATA, *LPT_PLAYORDOWN_MSTIMEVOD_RESPDATA;;

//设备控制相关结构
//报警探头控制结构io
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      //设备ID信息
    INT_TY  nPort;                //端口（第几位为1代表第几个端口，可按位或）
    U_CHAR_TY byCMD;              //操作描述（布撤防、旁路控制，1-布防，2-撤防，3-旁路，4-取消旁路） 
}T_ALMIN_CTRL_STRU, *LPT_ALMIN_CTRL_STRU;

//报警输出控制结构
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;       //设备ID信息
    INT_TY  nPort;                 //端口（第几位为1代表第几个端口，可按位或）
    BOOL_TY bOpen;                 //打开或者关闭（true-打开，false-关闭）
}T_ALMOUT_CTRL_STRU, *LPT_ALMOUT_CTRL_STRU;

//云台控制结构
typedef struct
{
    CHAR_TY  chCtrlID[HANDLE_LENGTH];  //云台控制操作句柄
    T_DEVID_INFO TDEVIDInfo;           //设备ID信息
    INT_TY   nChannel;                 //通道号（单个通道号，不是按位计算的）
    U_LONG_TY dwCtrlCMD;               //云台控制操作命令
    U_CHAR_TY  byParam;                //参数值（不同的命令对应同的值）
    BOOL_TY  bStop;                    //停止表示
}T_PTZ_CTRL_STRU, *LPT_PTZ_CTRL_STRU;

//云台高级控制
typedef struct
{
	CHAR_TY  chCtrlID[HANDLE_LENGTH];//云台控制操作句柄
	T_DEVID_INFO TDEVIDInfo;         //设备ID信息
	INT_TY   nChannel;               //通道号
	DWORD dwCtrlCMD;                 //云台控制操作命令
	DWORD dwParam1;                  //参数值
	DWORD dwParam2;                  //参数值
	DWORD dwParam3;                  //参数值
	DWORD dwParam4;                  //参数值
	DWORD dwParam5;                  //参数值
	DWORD dwParam6;                  //参数值
}T_PTZ_CTRL_STRU_EX, *LPT_PTZ_CTRL_STRU_EX;


//视频参数调节结构
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;			//设备ID信息
    INT_TY  nChannel;                   //通道号（单个通道号，不是按位计算的）
    U_CHAR_TY byBrightness;             //亮度
    U_CHAR_TY byContrast;               //对比度
    U_CHAR_TY bySaturation;             //饱和度
    U_CHAR_TY byHue;                    //色调
}T_VIDEO_PARAM_STRU, *LPT_VIDEO_PARAM_STRU;

//空调控制结构
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;		  //设备ID信息
    INT_TY nAddress;                  //空调地址
    INT_TY nOpenClose;                //1开 0关
    INT_TY nMode;                     //模式 1自动 2除湿 3制冷 4制热
    INT_TY nTemp;                     //温度
}T_ACPARAM_STRU, *LPT_ACPARAM_STRU;


//报警主机控制相关结构
//控制命令
typedef struct
{
    unsigned char code;         //操作码：布撤防、旁路等
    unsigned char subsystem;    //分区号，1-32
    unsigned short zone;        //防区号，1-512，布撤防时无效
} T_ALMHOST_CTRL_CMD, *LPT_ALMHOST_CTRL_CMD;

//控制结构
typedef struct
{
    T_DEVID_INFO device;        //设备ID信息
	unsigned int count;         //控制命令数
	T_ALMHOST_CTRL_CMD cmds[1]; //控制命令列表
} T_ALMHOST_CTRL_STRU, *LPT_ALMHOST_CTRL_STRU;

//控制回复
typedef struct
{
    unsigned char code;         //操作码：布撤防、旁路等
    unsigned char subsystem;    //分区号，1-32
    unsigned short zone;        //防区号，1-512，布撤防时无效
	unsigned int error;         //错误码，0表示成功
} T_AlARMHOST_CTRL;


//设备状态获取结构
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      //设备ID信息
    INT_TY nChannel;              //通道号或者端口号，按位表示，第几位是1就代表第几通道；可组合（获取视频参数时除外）。  
                                  //当获取与通道无关的状态时（比如硬盘、设备在线、设备运行、门禁、环境状态）时，该参数为0即可。  
}T_GET_DEV_STATE, *LPT_GET_DEV_STATE;

//服务器IP、端口、类型信息
typedef struct
{
	U_LONG_TY ulServerIP;  //IP
	U_LONG_TY Port;        //端口号
	INT_TY ServerType;     //服务器类型
}T_SERVER_INFO, *LPT_SERVER_INFO;

//客户端能力结构
typedef struct
{
    BOOL_TY bRecvTalk;      //接收对讲请求
}T_CLIENT_ABILITY, *LPT_CLIENT_ABILITY;


//发布消息结构（配置客户端使用）
typedef struct
{
    int nCMDType;		  //发布的消息类型
    unsigned long ulID;   //对应数据库中的ID（唯一）
    int nLevel;			  //节点等级
    char chCode[50];      //节点编号
    bool bIsExistFile;    //是否带有文件
    char chFileName[255]; //文件名称  
}T_CLIENT_REL_STRU, *LPT_CLIENT_REL_STRU;

//节点类型结构
typedef struct
{
    U_LONG_TY ulTypeID;
    INT_TY nLevel;
}T_NODETYPE_INFO, *LPT_NODETYPE_INFO;

//节点信息结构
typedef struct
{
	CHAR_TY    chNodeCode[20];            //节点的编号（网点、主机、摄像机、探头、外设）
    U_INT_TY   NodeType;                  //节点的类型（见 TJTY_AREANODE_TYPE）
}T_NODEINFO_ADDMODDEL, *LPT_NODEINFO_ADDMODDEL;

//软件使用期限定义
typedef struct {
	char pcReserved1[8];		//预留位(用于存放MN)
	char pcReserved2[16];		//预留位(用于存放机器码)
	char pcSoftType[8];			//模块简称，如 SJGL 代表事件管理模块，用于指示key文件的文件名
	char pcSoftName[64];		//软件名称
	char pcUserName[64];		//客户名称
	unsigned long dwSoftVersion;	//软件版本限制，-1表示禁止使用，0表示无限制，其他数字表示限制使用该数字之前的版本
	long dwIsHaveLimit;				//是否有期限限制, 0表示无限制，1表示有限制
	char pcEvaluateEndDate[16];		//使用到期时间 形如 20130102 ,表示2013年1月2日到期

} T_MODULE_PERIOD, *LPT_MODULE_PERIOD;

//MS按时间回放请求
typedef struct {
	CHAR_TY chSessionID[SESSIONID_LENGTH];  //会话ID
	T_DEVID_INFO tDevInfo;					//设备信息
	T_TIME_INFO tStartTime;					//开始时间
	T_TIME_INFO tEndTime;					//结束时间
	INT_TY	nChannel;						//通道号
	CHAR_TY chOther[20];					//其他条件
} T_MODULE_TIMEVOD_MS_REQ, *LPT_MODULE_TIMEVOD_MS_REQ;

//MS转发回放日常巡查
typedef struct {
	int nMode;					   //2-时间, 其余都是文件方式
	int flag;                      //0-不存储；-存储
	int module;                    //1-报警处置；-日常巡查；-门禁认证
	char guid[64];                 //关联的GUID
	char reserved[16];             //保留
} T_MS_TRANS_PLAYBACK_RCXC, *LPT_MS_TRANS_PLAYBACK_RCXC;

/*****************************************************************************/
/************************结构体定义结束***************************************/
/*****************************************************************************/

//状态结果
//用户预览状态/回放/下载反馈. 
typedef struct
{
    U_CHAR_TY DvrCode[DEV_ID_LENGTH];
    U_LONG_TY ulChannel;
    U_INT_TY  ViewType;       //图片\声音\视频
    U_INT_TY  enTransmitType; //0： 直连 1： 转发 
	T_TIME_INFO   Time;		  //开始时间。
}T_VIEWSTRUCT;

//对讲状态反馈
typedef struct
{
    U_LONG_TY TalkType;					//1:与设备对讲、0:与客户端对讲
	U_CHAR_TY DvrCode[DEV_ID_LENGTH];	//设备编号或者用户名
	U_LONG_TY ulChannel;				//通道号或用户IP地址
	U_LONG_TY UserType;					//客户端类型
}T_TALK_STATE;


//设备状态
//硬盘状态
typedef struct
{
    CHAR_TY     Name[20];		//磁盘的名称 、如C,D,E、 hard1、hard2 等
	U_LONG_TY  ulVolume;		//硬盘容量
    U_LONG_TY  ulFreeSpace;		//硬盘剩余空间 (MB)
    U_LONG_TY  ulHardDiskStatic;//硬盘状态 0－活动；1－休眠；2－不正常等
}T_DISK_STATE;

//报警输入状态
typedef struct
{
	U_LONG_TY ulchannel;	//通道号
	U_CHAR_TY ucbOnAlarm;	//1： 布防,0： 撤防
	U_CHAR_TY ucbPass;		//0: 旁路,1: 没旁路
	U_CHAR_TY ucbOnwork;	//0：非正常工作 1：正常工作 
	U_LONG_TY ucGetOK;		//0:表示成功 其他为错误码
	U_CHAR_TY ucnoneed;     //不需要的
}T_ALARMIN_STATE;

//录像通道状态
typedef struct
{
    U_LONG_TY ulchannel;	//通道号
	U_CHAR_TY ucbinsignal;  //0： 无信号，1： 有信号
	U_CHAR_TY ucbRec;       //0：没录像  1： 在录像
	U_CHAR_TY ucbOnwork;    //0：非正常工作 1：正常工作
	U_LONG_TY ucGetOK;		//0:表示成功 其他为错误码
	U_INT_TY  ulRecDay;		//工控录像天数
	U_CHAR_TY ucnoneed;     //不需要的
}T_CHANNEL_STATE;

//报警主机状态
typedef struct
{
	unsigned int    error;		// 错误码，0表示成功
	unsigned char   subsystem;	// 分区号，1-32
	unsigned char   status;		// 分区状态，0-撤防，1-布防
	unsigned short  count;		// 已旁路的防区数目
	unsigned short  zones[1];	// 已旁路的防区号列表
}T_ALARMHOST_STATE;

//门禁状态
typedef struct
{
	unsigned int	error;			// 错误码，0表示成功
	unsigned int	status;			// 控制器状态：0-关门, 1-开门, 2-常开, 3-常闭
	char			reserved[8];	// 保留字段，0
}T_ACCESS_STATE;

//控制回复
typedef struct
{
	U_LONG_TY ulChannel;  //通道号
    BOOL_TY   ucok;       //控制结果
    U_CHAR_TY CtrlType;   // mask ctrl what.
	INT_32    ErrorNo;    //
}T_AlARMINOUT_CTRL;


//通知MS、AS链接或断开对某台设备的服务的设备结构
typedef struct
{
	U_LONG_TY nEquipmentID;
	CHAR_TY   chEquipmentID[DEV_ID_LENGTH];
    U_INT_TY  LinkAc;//0:让其断开链接，1:让服务器去连接。 


	U_LONG_TY EDvrType;
	U_LONG_TY MainType;
	U_LONG_TY SubType;
	U_LONG_TY IP;//使用整形表示IP
	U_LONG_TY port;
	CHAR_TY   LoginName[NAME_LENGTH];
	CHAR_TY   LoginPassWord[PASSWORD_LENGTH];
}T_DEV_TASK;

//DVR通道预览被踢设备结构
typedef struct
{
    U_LONG_TY nDEVID;
	CHAR_TY chDEVID[DEV_ID_LENGTH]; 
	INT_TY  Channel;             //通道号
}T_DEVR_TICK, *LPT_DEVR_TICK;

//媒体服务器信息
typedef struct
{
	CHAR_TY MSCode[20];  //媒体服务器编号
	U_LONG_TY ulIP;		 //媒体ip
	U_LONG_TY UplandNum; //上传视频数
	U_LONG_TY TransNum;  //转发视频数
}T_MS_ONLINE_INFO;

//报警服务器信息
typedef struct
{
    CHAR_TY ASCode[20];
	U_LONG_TY ulASIP;  //报警服务器IP
    //int nPort;       //端口号 
}T_AS_STATE_INFO, *LPT_AS_STATE_INFO;

//媒体服务器信息扩展
typedef struct
{
	CHAR_TY MSCode[20];  //媒体服务器编号
	U_LONG_TY ulIP;		 //媒体ip
	U_LONG_TY UplandNum; //上传视频数
	U_LONG_TY TransNum;  //转发视频数
	int version;		 //版本
	char reserved[28];
}T_MS_ONLINE_INFO_EX;

//报警服务器信息扩展
typedef struct
{
    CHAR_TY ASCode[20];
	U_LONG_TY ulASIP;  //报警服务器IP
	int version;	   //版本
	char reserved[36];
}T_AS_STATE_INFO_EX, *LPT_AS_STATE_INFO_EX;

//客户端申请点播，回复媒体结构信息
typedef struct
{
    INT_TY VodSessionID[VODSESSIONIDLEN];
	U_LONG_TY ulServerIP; //媒体服务器的IP
	U_LONG_TY Port;		  //端口号
}T_VOD_RSE_SESSION;

//中心客户端与CMS之间通信结构
typedef enum
{
	ADDAPP =0,
	DELAPP,
	CHANGEAPP
}APP_CHANGE_TYPE;

////////////////////////////////////////////////////////////
// 视频信息相关

//视频观看连接方式
typedef enum
{
	VIDEO_CMODE_TRANSMIT,		//转发
	VIDEO_CMODE_DIRECT,			//直连
} E_VIDEO_CONNECT_MODE;

//视频观看类型
typedef enum
{
	VIDEO_TYPE_REALPLAY,		//实时预览
	VIDEO_TYPE_PB_DEV,			//回放设备录像
	VIDEO_TYPE_PB_STORE,		//回放存储录像（点播）
	VIDEO_TYPE_STORE,			//存储
	VIDEO_TYPE_DL_DEV,			//下载设备录像
	VIDEO_TYPE_DL_STORE,		//下载存储录像
} E_VIDEO_TYPE;

//客户端视频信息
typedef struct
{
	char session[SESSIONID_LENGTH];
	T_DEVID_INFO device;
	char channel;
	char mode;		// E_VIDEO_CONNECT_MODE
	char type;  	// E_VIDEO_TYPE
	char stream; 	// E_STREAM_TYPE
	char reserved[4];

} T_VIDEO_INFO_CLIENT;

//媒体视频信息
typedef struct
{
	char session[SESSIONID_LENGTH];
	int device;
	char channel;
	char type;  	// E_VIDEO_TYPE
	char stream; 	// E_STREAM_TYPE
	char reserved[5];

} T_VIDEO_INFO_MS;

//IP对讲 开始对讲,监听(MSG_REQ_IPT_CALL / MSG_REQ_IPT_MONITOR)
typedef struct
{
	U_INT_TY	cmd;		// 呼叫1、接听2、挂断3、拒绝4(监听时，1表示开始监听，0表示停止监听)
	U_INT_TY	fromHost;	// cmd发起方终端ID
	U_INT_TY	fromPanel;	// cmd发起方面板
	U_INT_TY	toHost;		// 目标终端 ID
	U_INT_TY	toPanel;	// 目标面板
	char		reserved[12];	// 保留：0
} T_IPTALK_CALL;

//IP对讲 广播（MSG_REQ_IPT_BROADCAST）
typedef struct
{
	U_INT_TY	cmd;		// 开始广播1、停止广播0
	U_INT_TY	fromHost;	// 广播发起终端ID
	U_INT_TY	fromPanel;	// 备用
	U_INT_TY	targetCount;	// 接收广播终端个数，停止广播时为0
	struct {
	U_INT_TY	targetHost;	// 目标终端ID
	U_INT_TY	targetPanels;	// 目标面板，每一位代表一个面板，0为所有面板
	} targets[1];
} T_IPTALK_BROADCAST;

//IP对讲，文件播放（MSG_REQ_IPT_FILEPLAY）
typedef struct
{
	U_INT_TY	cmd;		// 开始播放1、停止播放
	U_INT_TY	fromHost;	// 终端ID
	U_INT_TY	fromPanel;	// 备用
	U_INT_TY	idx;		// 文件索引
	char		reserved[48];	// 保留：0
} T_IPTALK_FILEPLAY;

//IP对讲 音量控制（MSG_REQ_IPT_SET_VOL）
typedef struct 
{
	U_INT_TY	cmd;		// 备用
	U_INT_TY	host;		// 终端ID
	U_INT_TY	panel;		// 备用
	U_INT_TY	vol;		// 0-100
	char		reserved[16];	// 保留：0
} T_IPTALK_SETVOL;

//IP对讲 拨打电话（MSG_REQ_IPT_PHONE）
typedef struct 
{
	U_INT_TY	cmd;		// 拨打1，挂断0
	U_INT_TY	fromHost;	// 终端ID
	U_INT_TY	fromPanel;	// 面板
	U_INT_TY	toHost;		// 目标终端 ID
	U_INT_TY	toPanel;	// 目标面板
	char		phone[20];	// 电话号码
	char		reserved[24];	// 保留：0
} T_IPTALK_PHONE;

//事件上报
typedef struct
{
	short		type;		// 主机1、探头2、摄像头3，手动4，对讲5等
	short		event;		// 具体事件
	int			host;		// 终端ID
	int			port;		// 终端端口或面板
	int			host2;
	int			port2;
	char		reserved[12];	// 保留：0
} T_NOTIFY_EVENT;

//门禁系统相关事件
typedef struct
{
	short	type;		// 报警1、异常2、门禁3等
	short	event;		// 具体事件
	int		host;		// 门禁点ID
	int		reserved;	// 保留
	int		extra;		//0-没有额外数据，1-门禁数据
} T_NOTIFY_EVENT_ACS;

// T_NOTIFY_EVENT_ACS.extra == 1时需带上的数据
typedef struct
{
	short	year;
	short	month;
	short	day;
	short	hour;
	short	minute;
	short	second;
	char	location[256];	//事件发生的门禁点
	char	user[64];		//持卡人
	char	card[64];		//卡号
	char	department[64];	//持卡人部门
} T_NOTIFY_EVENT_ACS_EXTRA;

//报警主机相关事件
typedef struct
{
	unsigned short	type;		// 报警主机1、接警软件2
	unsigned short	event;		// 具体事件(TJTY_EAC_ALMTYPE)
	unsigned int 	host;		// 主机ID
	unsigned int 	subsystem;	// 分区号
	unsigned int 	zone;		// 防区号
	unsigned int 	extra;		// 0-没有额外数据，1-事件描述( TEventDescribe )
}T_NOTIFY_EVENT_ALARMHOST;

typedef struct
{
	char chEventDescription[100];   //事件描述
}T_NOTIFY_EVENT_ALARMHOST_EXTRA;

//视频设备相关事件
struct TVideoDevAlarm
{
   unsigned int	host;		// 设备ID
   unsigned int	event;		//0:无报警 1:硬盘坏 2:硬盘满 3:上线 4:掉线
   unsigned char 	video[128]; 	//0:无报警 1:视频丢失 2:视频移动 3:视频遮挡 其它值:智能识别报警
   unsigned char 	sensor[128]; 	//0:无报警 1:有报警
};


////////////////////////////////////////////////////////
// 巡检异常事件消息
struct TNotiEventPatrol
{
	short	type;			// EEventPatrolType
	short	event;			// EEventPatrolExcept
	T_TIME_INFO_EX	time;	// 巡检时间
	int		host;			// 设备ID
	int		param;			// 参数，一般指通道号，0表示所有
							// 		视频设备的摄像头号
							// 		报警主机的分区号
							// 		硬盘的分区号
	int		extra;			// 是否有扩展数据，0-没有，1-有
};

// 巡检异常事件类型
enum EEventPatrolType
{
	PATROL_TYPE_ARM_STATE = 1,		// 布撤防状态
	PATROL_TYPE_CLOCK_STATE,		// 时钟状态
	PATROL_TYPE_DISK_STATE,			// 硬盘状态
	PATROL_TYPE_RECORD_STATE,		// 录像状态
	PATROL_TYPE_RECORD_DAYS,		// 录像天数
	PATROL_TYPE_RECORD_INTEGRITY,	// 录像完整性
	PATROL_TYPE_VIDEO_QUALITY,		// 视频质量诊断
	PATROL_TYPE_NODE_STATE,			// 监测节点状态
};

// 时钟状态异常扩展数据
struct TPatrolExceptExtraClockState
{
	int timediff;	// 时间差（秒），负数表示时钟慢了
};

// 磁盘状态异常扩展数据
struct TPatrolExceptExtraDiskState
{
	int total;		// 总容量（MB）
	int used;		// 已使用容量（MB）
};

// 录像天数异常扩展数据
struct TPatrolExceptExtraRecordDays
{
	int days;		// 录像不足天数
};

// 录像完整性异常扩展数据
struct TPatrolExceptExtraRecordIntegrity
{
	int	count;		// 录像缺失时间段的数量
	struct {
	T_TIME_INFO	begin;		// 开始时间
	T_TIME_INFO	end;		// 结束时间
	} sections[1];
};

// 视频质量诊断扩展数据
struct TPatrolExceptExtraVideoQuality
{
	char	pictureID[32];		// 图片存储在文件服务器中的ID
};

// 监测节点状态异常数据
struct TPatrolExceptExtraNodeState
{
	double			usage;			//使用率
	unsigned int	total;			//总量（CPU-无，内存-MB，网络-MB）
	unsigned int	data1;			//保留
	unsigned int	data2;			//保留
	unsigned int	data3;			//保留
	char			reserved[8];	//保留
};

// 平台的磁盘相关事件
struct TEvtPlatDisk
{
	T_TIME_INFO	time;		// 时间
	char		addr[20];	// IP地址
	char		name[20];	// 软件登录名
	int			module;		// 软件类型
	int			event;		// 1-磁盘已满；2-磁盘损坏
	char		reserved[56];	// 保留：0
};


// 视频网关文件通知
struct TEventMediaFile
{
	char guid[64];			// 报警GUID字符串
	char devName[64];		// 设备名称
	char camName[64];		// 摄像头名称
	int devType;			// 设备类型，参见TjtyNet库的定义
	int fileType;			// 文件类型，1-图片，2-视频
	long fileSize;			// 文件大小，字节
	int reserved;			// 保留，0
	T_TIME_INFO begin;		// 开始时间
	T_TIME_INFO end;		// 结束时间，如果是图片置空
	char filePath[200];		// 文件绝对路径
};

// 视频网关文件通知扩展
struct TEventMediaFileEx
{
	char guid[64];			// 报警GUID
	char devName[64];		// 保留，0
	char channelName[64];	// 通道名称
	int devType;			// 保留，0
	int fileType;			// 文件类型，1-图片，2-视频，3-音频
	long fileSize;			// 保留，0
	int flag;				// 标志位，bit1-删除位（0-不删除，1-用完删除）
	T_TIME_INFO begin;		// 开始时间
	T_TIME_INFO end;		// 结束时间
	char filePath[200];		// 文件绝对路径
	char planGuid[64];		// 预案GUID
	char actionGuid[64];	// 动作GUID
	long processId;			// 处警记录ID
	char reserved[64];		// 保留，0
};

// 模块的状态报告
/*
其中的状态码定义如下：
41	服务器掉线
42	超时未收到任何文件
43	服务器即将被认为关闭
44	超时未有任何文件存储请求
*/
struct TEventStateReport
{
	int	state;				// 状态码，0表示正常，其他表示异常
	char moduleName[64];	// 模块名称，如媒体服务器
	char moduleCode[16];	// 模块代号，如MS
	char reserved[428];		// 保留，0
};


//Client向考拉平台报修一个设备故障
struct TDeviceTroubleRepairToKoala
{
	int  msg;				// 消息类型（固定值：100001）
	int  state;				// 维修状态
	char guid[64];			// 故障单号
	char number[40];		// 设备编号
	char devicetype[40];	// 设备类型
	char maintype[40];		// 厂家
	char subtype[40];		// 型号
	char area[40];			// 所属区域
	char maintenance[40];	// 维保商
	char telephone[40];		// 维保电话
	char troubletype[40];	// 故障类型
	char troubles[256];		// 故障现象串
	char describe[256];		// 故障描述
	char reserved1[40];		// 预留1 
	char reserved2[40];		// 预留2
};


//手动报警
//该结构是报警网关向报警服务器转发考拉平台的报警消息。报警服务器向客户端转发按照原有报警传输协议，此处不再定义。
struct TNewAlarmToZONEE
{
	int  msg;				// 消息类型（固定值：201004）
	char guid[64];			// 报警唯一标识
	char number[64];		// 设备编号
	int  type;				// 报警类型值
	int  level;				// 报警等级
	char alarmtype[40];		// 报警类型
	char time[40];			// 报警发生时间
	char locate[64];		// 报警地点
	char describe[256];		// 描述
	char files[256];		// 附件串
	char user[40];			// 报警人
};



//配置客户端转发修改预案，动作，事件消息
struct TAlarmPlan_ModelInfo_Syn
{
    INT_TY  msgid;// 消息ID	223001
    CHAR_TY guid[128];
    INT_TY  nActionType; //1-添加 2-修改 3-删除
    INT_TY  nModelType;  //1-动作 2-事件 3-预案

};

/* 守押系统相关 - 开始 */

//车辆信息
struct TSyCar
{
	char number[20];		// 车牌号
	char idCard[20];		// 证件号
	char cardTagNo[20];		// 电子标签卡号
};

//人员信息
struct TSyPerson
{
	int id;					// ID
	char sid[20];			// 身份证号
	char name[20];			// 姓名
};

//人员种类
enum ESyPersonType
{
	SY_PERSON_TYPE_DRIVER = 1,		// 驾驶员
	SY_PERSON_TYPE_BUSINESS,		// 业务员
	SY_PERSON_TYPE_GUARD,			// 押运员
};

//排班信息
struct TSyScheduleInfo
{
	char time[20];			// 预定到达时间hh:mm
	TSyCar car;				// 车辆
	int personCount;		// 人员数
	struct {
		int personType;		// 人员种类
		TSyPerson person;	// 人员信息
	} persons[10];
};

//排班信息列表
struct TSyScheduleList
{
	int count;
	TSyScheduleInfo info[1];
};

//获取图片参数
struct TSyGetImage
{
	int userId;				// 用户id
	char photoId[20];		// 照片id
	char vehicleNo[20];		// 车牌号
	int imageType;			// 图片类型：1 表示下载人员照片,userId
							//     2 表示下载正常实时人脸识别时的照片，使用userId和photoId
							//     3 表示下载钞车照片，可通过2种方式获取照片，有车牌号优先使用车牌号来获取车的照片
							//         a)使用photoId参数，设置为钞车标签卡号; b)使用vehicleNo车牌号
							//     4 表示下载连续3次人脸验证不通过的人脸照片, 使用photoId参数
};

//图片
struct TSyImageId
{
	char imageId[32];		// 图片存储在文件服务器中的ID
};

//押运状态
struct TSyRouteStatus
{
	int orgId;					//网点id
	char orgName[32];			//网点名称
	int orderNo;				//路线中该网点预订的顺序号
	int passed;					//该网点是否已经走过，0:还未走过 1:已经走过
	int actualOrderNo;			//路线中该网点实际的顺序号
	T_TIME_INFO arriveTime;		//实际到达时间
	int arriveTimeStatus;		//到达时间是否正常 0：正常 1：轻微异常 2：严重异常
};

//押运路线状态
struct TSyRouteList
{
	int count;
	TSyRouteStatus route[1];
};

//获取电子标签卡详细信息参数
struct TSyGetTagData
{
	int orgId;					//组织机构id即网点id
	int getType;				//获取电子标签卡详细信息的方式
								//    1：获取所有电子标签卡信息
								//    2：只获取当前网点相关的电子标签卡信息
								//    3：只获取下面指定的电子标签卡的信息
	int count;					//电子标签卡数量
	struct {
		char tagId[20];			//电子标签卡id
	} tagList[1];				//电子标签卡列表
};

//电子标签卡信息
struct TSyTagData
{
	char name[32];			//名字或编号，车牌号
	int type;				//1：钞箱  2：钞车
	char driver[20];		//type=2时为驾驶员
	char tagId[20];			//电子标签卡id
};

//电子标签卡信息列表
struct TSyTagDataList
{
	int count;
	TSyTagData tagData[1];
};


//守押报警消息相关，TEscortAlarm为报警消息发送到AS
typedef struct tCashbox{
	char	ashboxName[32];	//款箱名
	char	tagNo[32];		//款箱的电子标签卡号
	T_TIME_INFO	time;		//监测到电子标签卡的时间
}TCashbox;

typedef struct tEscortCar{
	char	vehicleNo[32];		//车牌号
	char	tagNo[32];		//车的电子标签卡号
	T_TIME_INFO	time;		//监测到电子标签卡的时间
	int	valid;			//车是否合规 0：合规 1：不合规
}TEscortCar;

typedef struct tEscortPerson{
	int	userId;			//用户ID
	T_TIME_INFO	time;		//实际刷脸时间 yyyy-mm-dd hh:mm:ss
	char	name[32];		//实际刷脸人员名字
	char	type[32];		//人员类型，如“押运员”
	char	typeCode[8];		//人员类型代码 空值:人员类别不清 10:正式员工  40:押运人员  50:保安人员  80:外来人员  其它code后续补充
	char	photoId[32];		//连续3次人脸验证不通过时，该参数才会有值
	char	sid[32];			//身份证号
	int	valid;			//人员是否合规 0：合规 1：不合规
	int	arrivedtimestatus;	//到达时间是否正常 0：正常 1：轻微异常 2：严重异常
}TEscortPerson;

typedef struct tEscortAlarm
{
	int		host;	//平台设备ID
	int		channelNo;
	int		organizationID;		//网点ID
	char	organizationName[32];	//网点名称
	char		deviceNo[32];		//设备号，如果是人则为人脸识别仪的设备号，如果是车和款箱，则为射频读写卡的设备号
	int		dataType;		//0:正常人脸验证  organizationid  deviceno  person有效，但photoid无值
						//1:连续3次人脸验证不通过，organizationid  deviceno  person有效，photoid有值，是系统临时产生的一个id号，用来2接口去获取当时人脸的照片
						//2:人脸识别仪拆机报警, 只有deviceno有效
						//3:人脸识别仪异常报警, 只有deviceno有效
						//4:人脸识别仪删除报警, 只有deviceno有效
						//10:人员变动  userid name sid有效
						//11:车辆变动  vehicleno,tagno, status, oldvehicleno, oldtagno 有效
						//12:款箱变动  tagno, cashboxname, status, oldtagno, oldcashboxname有效
						//20:钞车信息  organizationid  deviceno  car有效
						//30:款箱信息  organizationid  deviceno  cashbox有效

	TEscortPerson	person;			//人员信息
	TEscortCar	car;			//车信息
	TCashbox	cashbox;		//款箱信息

	char		vehicleNo[32];		//车牌号
	char		tagNo[32];		//电子标签卡号(车或款箱)
	char		ashboxName[32];	//款箱名
	int		status;			//车(箱)的状态 0：有效 1：无效 2：已物理删除
	char		oldVehicleNo[32];	//原来的车牌号
	char		oldTagNo[32];		//原来的电子标签卡号(车或款箱)
	char		oldCashboxName[32];	//原来的款箱名
} TEscortAlarm;

/* 守押系统相关 - 结束 */

#endif 