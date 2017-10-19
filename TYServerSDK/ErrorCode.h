/***********************************************************************
 * Copyright (C) 2010, Tianyue Co. Ltd.
 * 
 * File Name:   ErrorCode.h
 * Description: Defines all the error codes in the system
 * Version:     V0.01
 * Author:      High Ceremony
 * Date:        2010-12-02
 ***********************************************************************/

#ifndef ERRORCODE_H
#define ERRORCODE_H


typedef enum
{
	TY_SUCCESS                        = 0x0 //正常
}SUCCESS_CODE;
//-----------------------------------------------------------------------------
/**************************************************
 **           Error code from device'sdk               **
 **************************************************/
typedef enum
{
	TY_NET_NO_INIT_ERROR                  =0x1,	  //未初始化SDK或者初始化失败
	TY_NET_TCP_ERROR                      ,   //网络交互异常
	TY_NET_BACK_ERROR                     ,   //错误的反馈
	TY_NET_UNKNOWN_ERROR                  ,   //未知错误
	TY_NET_NOSUPPORT_ERROR                ,   //不支持此功能
	//登录有关的错误信息
	TY_NET_NAMEORPWD_ERROR                ,   //登录用户名或密码错误
	TY_NET_NAME_FORBID_ERROR              ,   //登录用户名被禁用
	TY_NET_NAME_BUSY_ERROR                ,   //登录用户名正在使用
	//-----------------------------------------------------------------------------
	//操作有关的错误信息
	TY_NET_NOLOGIN_ERROR                  ,  //没有登录
	TY_NET_NOLEVEL_ERROR                  ,  //没有权限
	TY_NET_PARA_ERROR_ERROR               ,  //参数错误
	TY_NET_NOFILE_FIND_ERROR              ,  //没有检索到文件
	TY_NET_NOSUFFICIENTMEMORY_ERROR       ,  //内存不足
	TY_NET_ISFINDING_ERROR                ,  //正在检索
	TY_NET_ISMULTITALK_ERROR              ,  //正在群呼
	TY_NET_ISGETTING_ERROR                ,  //正在获取中（主要用于图敏的参数获取）
	TY_NET_NOTREALPLAY_ERROR              ,  //没有预览
	TY_NET_NOTREMOTEPLAY_ERROR            ,  //没有在回放
	TY_NET_NOTTALK_ERROR                  ,  //不在对讲中
    TY_NET_OPEN_MIC_ERROR                 ,  //打开音频失败
	//-----------------------------------------------------------------------------
	//异常信息常量
	TY_NET_EXCEPTION_EXCHANGE_ERROR       , //用户交互异常
	TY_NET_EXCEPTION_PREVIEW_ERROR        , //网络预览异常
	TY_NET_EXCEPTION_PLAYBACK_ERROR       , //网络回放异常
	TY_NET_EXCEPTION_ALARM_ERROR          , //报警异常
	TY_NET_EXCEPTION_AUDIOEXCHANGE          //语音对讲异常
}DEVICE_NET_ERROR_CODE;

//-----------------------------------------------------------------------------
/**************************************************
 **           播放库错误码	               **
 **************************************************/
typedef enum
{
	TJTY_PLAY_NOERR 	 					 =0x0,		//没有错误
	TJTY_PLAY_NO_INIT_ERROR                  =0x100,	  	//未初始化SDK或者初始化失败
	TJTY_PLAY_NOTSUPPORT,									//不支持此功能
	TJTY_PLAY_INIT_ERROR,									//初始化失败
	TJTY_PLAY_INVALID_PARAM,								//错误的参数
	TJTY_PLAY_BUFFER_FULL,									//缓冲区已满，无法输入流
	TJTY_PLAY_NOENOUGH_MEMORY,								//内存不足
	TJTY_PLAY_PORT_USED,									//该窗口号已经被使用
	TJTY_PLAY_INVALID_PORT,									//无效的窗口号
	TJTY_PLAY_DECODE_ERROR,									//解码失败
	TJTY_PLAY_RENDER_FAILED,								//渲染失败
	TJTY_PLAY_OP_FAILED,									//播放，停止，暂停等操作失败
	TJTY_PLAY_WRONG_BUFTYPE,								//错误的缓冲类型
	TJTY_PLAY_CALLORDER_WRONG,								//错误的调用顺序

	TJTY_PLAY_UNKNOWNERR					   =0x1FF,		//未知错误
			
}DEVICE_PLAY_ERROR_CODE;


/**************************************************
 **           Error code that CMS may give              **
 **************************************************/
typedef enum
{
	//User login Error
	TY_NAME_ERROR			= 0x400	,		//the user'name is wrony
	TY_PASS_ERROR					,
	TY_NAMEINUSE_ERROR				,		//the user was already  login.
	TY_VALIDPERIOD_ERROR			,		//the use is out of period
	TY_REACH_USERNUM_LIMIT          ,
	TY_NO_RESULT					,		//can't find any results
	TY_APP_OFFLINE					,		//app offline
	TY_CMS_INITIALIZING				,		//cms initializing
	TY_VERSION_TOO_LOW				,
	TY_VERSION_TOO_HIGH				,
	TY_MODULE_FORBIDDEN				,
	TY_LDAP_ERROR					,
	TY_LDAP_SERVER_DOWN				,
	TY_LDAP_VERSION_ERROR			,
	TY_LDAP_BIND_FAIL				,
	TY_RADIUS_ERROR					,
	TY_RADIUS_SERVER_DOWN			,
	TY_USER_FORBIDDEN				,
	TY_USER_IP_LIMIT				,
	TY_USER_PASS_OVERDUE			,
	
	TY_NOPOWER_ERROR		= 0x480,		//nopower
	TY_NOTISHDEV_ERROR				,		//no this device
	TY_NOTHISCHL_ERROR				,		//no this channel
	TY_BANDWIDTHLIMIT_ERROR			,		//the channl num that get video from the area has reah to the limit.
	TY_CUTLINE_ERROR				,		//the device cut line
	TY_NOMS_ERROR					,		//con't get a ms is in use.
	TY_PARA_ERROR					,		//the parameter is error.
	TY_GETTHEMAXTRASLIMIT_ERROR     ,       //
	TY_SEARCHFILE_LINK_ERROR		,		//
	TY_SEARCHFILE_LINK_TIMEOUT		,		//
	TY_SEARCHFILE_USER_BUSY			,		//
	TY_SEARCHFILE_USER_FAIL			,		//
	TY_SEARCHFILE_USER_NOAUTH		,		//
	TY_SEARCHFILE_EXCEPT			,		//
	TY_SEARCHFILE_TIMEOUT			,		//
	TY_PTZCONTROL_INUSE				,		//
	TY_VIEW_TIMEOUT					,		//

	TY_NOTHISFILE_ERROR	   = 0x500	,		//no this config file.(when use want to download some config file,or get video file form sql)         

	TY_LIMIT_NUM_USER      = 0x540  ,       //reach the maximal user number
	TY_LIMIT_NUM_DEVICE             ,       //reach the maximal device number
	TY_LIMIT_NUM_CAMERA             ,       //reach the maximal camera number

    //look use info
	TY_NOVIEW_ERROR		   = 0x00000580	,	//user don't moniter any real-time video
	TY_NOTHISUSER_ERROR					,	//no this use.(when one use want to get an other use'info)
	TY_NOTALK_ERROR						,	//not in talk。
	
	TY_INTALK_ERROR		   = 0x00000600	,	//the user or device already in talking.
	
	TY_OTHERERROR							//The error we con't describe it.

}CMS_ERRORCODE;
	
#define ERRP  1000


/**************************************************
 **            The Error Code of MS              **
 **************************************************/
typedef enum
{
    // General Error, begin with 0x800
    TY_MS_ERROR = 0x800             , // mark as the beginning, not used
    TY_MS_OTHER_ERROR,

    // Transmit Module, begin with 0x900
    TY_TRANS_ERROR = 0x900          , // mark as the beginning, not used
    TY_TRANS_SESS_EXIST_ERROR       , // session already exist
    TY_TRANS_DEV_NOTEXIST_ERROR     , // dev not exist
    TY_TRANS_DEV_OFFLINE_ERROR      , // dev not online
    TY_TRANS_CHL_NOTEXIST_ERROR     , // channel not exist
    TY_TRANS_REQ_FAIL_ERROR         , // request video failed
    TY_TRANS_SYSHEAD_ERROR          , // get syshead failed
	TY_TRANS_PB_LINK_ERROR			,		//
	TY_TRANS_PB_LINK_TIMEOUT		,		//
	TY_TRANS_PB_USER_BUSY			,		//
	TY_TRANS_PB_USER_FAIL			,		//
	TY_TRANS_PB_USER_NOAUTH			,		//
	TY_TRANS_PB_FILE_NOTEXIST		,		//
	TY_TRANS_PB_FILE_ERROR			,		//
	TY_TRANS_PB_NOT_SUPPORT			,		//
	TY_TRANS_PB_EXCEPT				,		//
	TY_TRANS_PB_HEAD_TIMEOUT		, // 
	TY_TRANS_PB_DATA_TIMEOUT		, // 
	TY_TRANS_PB_POS_ERROR			, // playback set position failed
    TY_TRANS_OTHER_ERROR,

    // Storage Module, begin with 0xA00
    TY_STOR_ERROR = 0xA00           , // mark as the beginning, not used
    TY_STOR_OTHER_ERROR,

    // VOD Module, begin with 0xB00
    TY_VOD_ERROR = 0xB00            , // mark as the beginning, not used
    TY_VOD_NOT_SUPPORT_ERROR        , // vod not supported by this ms
    TY_VOD_SESS_EXIST_ERROR         , // session already exist
    TY_VOD_SESS_NOT_EXIST_ERROR     , // session not exist
    TY_VOD_FILE_WRONG_ERROR         , // file not exist or file format error
    TY_VOD_FILE_IO_FAIL_ERROR       , // file io error
    TY_VOD_FILE_ID_ERROR            , // file id not legal
    TY_VOD_PARAM_ERROR              , // vod request parameter error. e.g., file position eror
    TY_VOD_OTHER_ERROR,

    TY_MS_ERROR_END = 0xBFF           // mark as the end, not used
} MS_ERRORCODE;

/**************************************************
 **           Error code from the AS              **
 **************************************************/
typedef enum
{
	TY_ILLEGAL					= 0xC00
}AS_ERRORCODE;


/**************************************************
 **           Error code from the server SDK              **
 **************************************************/
typedef enum
{
	TY_SERVER_MEMROY_ERROR			=	0x1000,       //分配内存错误
	TY_SERVER_PARA_ERROR			,       //参数错误
	TY_SERVER_SDK_HAD_INIT_ERROR	,       //重复初始化SDK
	TY_SERVER_SDK_NO_INIT_ERROR		,       //未初始化SDK
	TY_SERVER_INIT_NET_ERROR		,       //初始化网络错误
	TY_SERVER_SOCK_CONNECT_ERROR	,		//连接套接字错误
	TY_SERVER_SOCKET_INVALID_ERROR  ,		//套接字无效
	TY_SERVER_NET_BLOCK_ERROR		,       //网络阻塞
	TY_SERVER_TIME_OUT_ERROR		,       //超时
	TY_SERVER_SEND_DATA_FAIL_ERROR	,		//发送数据失败
	TY_SERVER_RECV_DATA_FAIL_ERROR	,		//接收数据失败
	TY_SERVER_BACK_ERROR_ERROR      ,		//反馈错误  
	TY_SERVER_THREADPOOL_FULL_ERROR ,		//线程池已满（达到最大值）
	TY_SERVER_HAD_LOGIN_ERROR       ,		//重复登录中心管理服务器  
	TY_SERVER_NO_LOGIN_ERROR        ,		//未登录中心管理服务器 
	TY_SERVER_CREATE_EVENT_ERROR	,		//创建事件错误
	TY_SERVER_WAIT_EVENT_ERROR		,		//等待事件失败
	TY_SERVER_CALLBACK_NULL_ERROR   ,		//未设置回调函数
	TY_SERVER_HAD_LINKED_ERROR      ,		//重复连接 
	TY_SERVER_NOT_TRANS_LINK_ERROR  ,		//不是转发连接方式
	TY_SERVER_IS_SEARCHING_ERROR    ,		//正在检索文件
	TY_SERVER_INVALID_HANDLE_ERROR  ,		//无效的句柄
	TY_SERVER_NO_SUPPORT_ERROR      ,		//不支持该功能
	TY_SERVER_NOENOUGHPRI_ERROR     ,		//权限不足 
	TY_SERVER_IS_TALKING_ERROR      ,		//正在对讲或者群呼
	TY_SERVER_OPEN_MIC_ERROR		,		//打开音频采集失败
	TY_SERVER_OPEN_FILE_FAIL_ERROR	,		//打开文件失败
	TY_SERVER_SOCKET_BIND_ERROR		,		//绑定套接字失败
	TY_SERVER_OPENMIC_ERROR      			//打开音频采集失败
}SERVER_SDK_ERRORCODE;
/**************************************************
** the error From Appserver
**************************************************/
typedef enum
{   
	TY_APP_SDK_HAD_CONNECTED_ERROR      = 0x1400,		//已经连接   
	TY_APP_SDK_MEMROY_ERROR_ERROR       ,				//分配内存错误
	TY_APP_SDK_SOCK_CONNECT_ERROR		,				//连接套接字失败
	TY_APP_SDK_SEND_ERROR				,				//发送数据失败 
	TY_APP_SDK_RECV_ERROR				,				//接收数据失败  
	TY_APP_SDK_BACK_ERROR				,				//反馈失败
	TY_APP_SDK_CREATETHREAD_ERROR		,				//创建线程失败
	TY_APP_SDK_PARA_ERROR				,				//参数错误 
	TY_APP_SDK_NO_CONNECT_ERROR         ,				//尚未连接APP服务器   
	TY_APP_SDK_CREATE_EVENT_ERROR		,				//创建事件失败
	TY_APP_SDK_WAIT_EVENT_ERROR			,				//等待事件错误 
	TY_APP_SDK_BACK_MSG_ERROR			,				//反馈错误 
	TY_APP_SDK_QUERY_NO_RESULT_ERROR    ,				//未查询到相应的结果
	TY_APP_SDK_QUERY_NOT_SUPPORT_ERROR  ,				//不支持该查询功能
	TY_APP_SDK_QUERY_EXCEPTION_ERROR    ,				//APP服务器检索异常
	TY_APP_SDK_LINK_SQLSERVER_FAIL_ERROR ,				//APP服务器连接数据库失败
	TY_APP_SDK_UNKNOW_ERROR_ERROR        ,				//未知错误
	TY_APP_SDK_LOGINKEY_ERROR			 ,				//LogInKey验证失败

	//use in client
	TY_RPCOUTWORK_ERROR					,				//RPC 服务器不可用。
	TY_COMMOND_ERROR					,               //命令错误。
	TY_IPMULI_ERROR						,				//添加设备时ip地址重复。
	TY_NAMEMULTI_ERROR					,               //名称重复。
	TY_CHANLEMULTI_ERROR				,				//通道已经存在。
	TY_NOTHISMODEL_ERROR				,				//无此此型号。
	
}APP_ERRORCODE;	

#endif
