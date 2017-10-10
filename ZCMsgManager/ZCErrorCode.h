/**
* @file ZCErrorCode.h
*
* @brief 众绎客户端各模块交互错误码宏定义
* 
* @version 1.0.0.1
*
* @author gaoxiaoliang@typrotech.com
*/

#ifndef ZCERRORCODE_H
#define ZCERRORCODE_H

/** @defgroup ZCErrorCodeDefine 消息协议错误码结构定义     
 * 众绎客户端各模块交互错误码宏定义 
 * @{
 */
///消息服务模块成功码定义
typedef enum
{
	ZC_SUCCESS                        = 0x0    ///<(0)正常
}E_ZC_SUCCESS_CODE;

///消息服务模块错误码定义
typedef enum
{
	SERVER_ERROR_MODULEOFFLINE = 0x1       ///<(1)请求模块不在线
}E_SERVER_ERROR_CODE;

///App模块错误码定义
typedef enum
{
	APP_ERROR_LINKERROR = 0x10,         ///<(16)APP连接异常
	APP_ERROR_NOREQMODULE,              ///<(17)请求模块异常
	APP_ERROR_PARAMTOOSMALL,            ///<(18)请求参数结构长度异常
	APP_ERROR_PARAMISNULL,              ///<(19)请求参数为空
	APP_ERROR_GETINFOFAILED,            ///<(20)从APP获取信息失败
	APP_ERROR_GETINFONULL,              ///<(21)结果集为空
	APP_ERROR_UNKNOWNMSG,               ///<(22)未知消息
	APP_ERROR_OPERATEFAILED,            ///<(23)增删改操作失败  
	APP_ERROR_PARAMERROR,               ///<(24)请求参数错误
	APP_ERROR_CURUSERNULL,              ///<(25)当前用户未登录
	APP_ERROR_NOFINDSCHEDULEINFO,       ///<(26)未找到当前用户的排班信息
    APP_ERROR_NOFINDMONITORROLE,        ///<(27)未找到上级角色
	APP_ERROR_NOFINDMONITORINCLASS,     ///<(28)未在同一班次中找到上级角色
	APP_ERROR_NOFINDSUBROLE,            ///<(29)未找到下级角色
	APP_ERROR_NOFINDSUBROLEINCLASS,     ///<(30)未在同一班次中找到下级角色

	APP_ERROR_NUM1 = 0x100,             ///<(256)该时间模板已与班次绑定，无法删除，请先移除所在班次信息
}E_APP_ERROR_CODE;

///BCB模块错误码定义
typedef enum
{
	BCBC_ERROR_NOUSERINFO = 0x400,       ///<(1024)当前用户离线
	BCBC_ERROR_USERINFOISNULL,           ///<(1025)请求用户信息为空 
	BCBC_ERROR_DOWNLOADIMGFAILED,        ///<(1026)图片下载失败
	BCBC_ERROR_PARAMERROR,               ///<(1027)请求参数错误
    BCBC_ERROR_BUSY,                     ///<(1028)系统繁忙
    BCBC_ERROR_UNKNOWNMSG,               ///<(1029)未知消息
    BCBC_ERROR_GETINFONULL,              ///<(1030)结果集为空
    BCBC_ERROR_NOFINDAREA,               ///<(1031)未找到区域信息
    BCBC_ERROR_NOFINDALARMSOURCENODE,    ///<(1032)未找到报警源节点信息
    BCBC_ERROR_HOSTALARMNOHAVELINKVIDEO, ///<(1033)主机类报警没有联动视频（或录像）
    BCBC_ERROR_NOEVENTMODULE,            ///<(1034)动态模块未启用或未授权
    BCBC_ERROR_NOFINDNEARBYVIDEO,        ///<(1035)未找到附近视频
    BCBC_ERROR_NOFINDTALKDEV,            ///<(1036)该区域未找到对讲设备
    BCBC_ERROR_DOWNLOADFAILED,           ///<(1037)视频下载失败
    BCBC_ERROR_UPLOADFAILED,             ///<(1038)视频上传失败
    BCBC_ERROR_CAPTUREPICFAILED,         ///<(1039)抓图失败
    BCBC_ERROR_NOTALKMODULE,             ///<(1040)未启用对讲模块
    BCBC_ERROR_UPLOADATTACHMENTFAILED,   ///<(1041)附件上传失败
    BCBC_ERROR_NOFINDDEVID,              ///<(1042)未找到对应设备
    BCBC_ERROR_ACSCONTROLMSGSENDFAILED,  ///<(1043)门禁控制命令发送失败
    BCBC_ERROR_TIMEOUT,                  ///<(1044)请求超时
    BCBC_ERROR_GETRECORDINFOFAILED,      ///<(1045)获取通道录像计划失败
    BCBC_ERROR_SEARCHFILELISTFAILED,     ///<(1046)获取通道录像文件列表失败
    BCBC_ERROR_SEARCHFILENETEXCEPTION,   ///<(1047)查询录像文件网络异常
    BCBC_ERROR_NOCHECKMODULE,            ///<(1048)未启用回放下载模块
    BCBC_ERROR_REQUESTFILEFAILED,        ///<(1049)请求文件失败
    BCBC_ERROR_NOFINDKOALASERVICE,       ///<(1050)未找到考拉报警网关用户
    BCBC_ERROR_THRIDPARTREQUESTFAILED,   ///<(1051)请求跟第三方系统交换消息失败
}E_BCBC_ERROR_CODE;
/** @} */
#endif