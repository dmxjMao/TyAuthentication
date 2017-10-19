/*********************************************************************
* 版权所有 (C)2010, 上海天跃科技有限公司。
*
* 文件名称：TYServerSDK.h
* 内容摘要：服务器层SDK接口函数声明
* 当前版本：
* 作    者：张小路
* 完成日期：20100505
**********************************************************************/
#ifndef TY_SERVER_SDK_H
#define TY_SERVER_SDK_H

#ifdef TYSERVERSDK_EXPORTS
    #define TY_SERVER_API extern "C" __declspec(dllexport)
#else
    #define TY_SERVER_API extern "C" __declspec(dllimport)
#endif

#ifndef CALL_METHOD
    #define CALL_METHOD __stdcall
#endif

#ifndef TYSERVER_API_18
	#define TYSERVER_API_18
#endif

#include "CommonDefine.h"
#include "TjtyCommon.h"
#include "TjtyNet.h"

/****************************************************************************
*************************常量定义********************************************
****************************************************************************/

/****************************************************************************
*************************数据结构及类型定义**********************************
****************************************************************************/

//接口函数声明
//初始化相关
/**********************************************************************
* 函数名称：TY_Server_InitSDK
* 功能描述：初始化SDK，此函数是使用其他函数的基础和前提条件。
* 输入参数：无。
* 输出参数：无。
* 返 回 值： 0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_InitSDK(void);

/**********************************************************************
* 函数名称：TY_Server_Cleanup
* 功能描述：释放SDK资源，SDK使用完成后，需调用此函数释放资源。
* 输入参数：无。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_Cleanup(void);

/**********************************************************************
* 函数名称：TY_Server_SetExceptCallBack
* 功能描述：注册异常回调函数，该回调函数用来回调各种异常信息的结果。
* 输入参数：pfMsgCallback 异常信息回调函数；
		    dwUser 用户自定义参数。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SetExceptCallBack(
                    ExceptionMsgCallBack pfMsgCallback, DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_SetMsgCallBack
* 功能描述：注册消息回调函数，用来接收中心管理服务器的发送过来的信息。
* 输入参数：pfMsgCallback 消息回调函数；
		    dwUser 用户自定义参数。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SetMsgCallBack(MsgCallBack pfMsgCallback,
                                                       DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_GetLastError
* 功能描述：获取错误码，当调用各函数返回失败后，调用此函数获取失败的原因。
* 输入参数：无。
* 输出参数：无。
* 返 回 值：错误码。
***********************************************************************/
TY_SERVER_API DWORD CALL_METHOD TY_Server_GetLastError(void);

//登录操作相关
/**********************************************************************
* 函数名称：TY_Server_LogInCMS
* 功能描述：登录中心管理服务器，是整个系统中必不可少的操作。
* 输入参数：chCMSIP 中心管理服务器IP；
		    nPort 端口号；
		    lpUserInfo 用户信息（用户名、密码、用户类型）。
			pExpireDate 用户过期时间，没有则不改变
* 输出参数：无。
* 返 回 值：-1表示失败，其它值为登录成功后返回的操作句柄。
***********************************************************************/
#ifdef TYSERVER_API_18
TY_SERVER_API long CALL_METHOD TY_Server_LogInCMS(char* chCMSIP, int nPort,
                                            LPT_CLIENT_USERINFO lpUserInfo, TJTY_TIME* pExpireDate);
#else
TY_SERVER_API long CALL_METHOD TY_Server_LogInCMS(char* chCMSIP, int nPort,
                                            LPT_CLIENT_USERINFO lpUserInfo);
#endif

/**********************************************************************
* 函数名称：TY_Server_LogOutCMS
* 功能描述：退出登录中心管理服务器，退出将无法进行其他的一切操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_LogOutCMS(long lUserID);

/**********************************************************************
* 函数名称：TY_Server_LockUser
* 功能描述：锁定用户函数。通知中心管理服务器锁定相应的用户。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_LockUser(long lUserID);

/**********************************************************************
* 函数名称：TY_Server_UnLockUser
* 功能描述：解除锁定用户函数。通知中心管理服务器解除对相应的用户的锁定。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_UnLockUser(long lUserID);

/**********************************************************************
* 函数名称：TY_Server_GetModuleEvaluateInfo
* 功能描述：获取指定模块的试用期信息
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输入参数：pcModuleType 模块类型名简称，7个英文字母以内，区分大小写
* 输出参数：pInfo [in,out] 模块试用期信息,成功时填入试用信息，否则不改动内容
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetModuleEvaluateInfo(long lUserID, const char* pcModuleName, LPT_MODULE_PERIOD pInfo);

/**********************************************************************
* 函数名称：TY_Server_ReportClientAbility
* 功能描述：上报客户端能力。通知中心管理服务器客户端的一些能力信息，包括接收对讲等。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            lpClientAbility 客户端能力描述结构指针。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ReportClientAbility(long lUserID, 
                                                            LPT_CLIENT_ABILITY lpClientAbility);

/**********************************************************************
* 函数名称：TY_Server_ReportClientAbility
* 功能描述：客户端消息发布，配置客户端使用。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            lpReleaseStru 客户端消息发表于结构指针。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ReleaseInfo(long lUserID, LPT_CLIENT_REL_STRU lpReleaseStru);

/**********************************************************************
* 函数名称：TY_Server_GetUserLogInKey
* 功能描述：获取用户登录中心管理服务器成功返回的LogInKey,用于连接APP使用。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输出参数：chLogInKey 获取到的LogInKey。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetUserLogInKey(long lUserID, char *chLogInKey);

//报警监听相关
/**********************************************************************
* 函数名称：TY_Server_SetAlarmCallBack
* 功能描述：注册报警回调函数，用来接收报警信息。
* 输入参数：pfAlmMsgCallback 报警信息回调函数；
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SetAlarmCallBack(AlmMsgCallBack pfAlmMsgCallback,
                                                         DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_StartAlmListen
* 功能描述：开始监听报警，开始监听前一定要确保登录中心成功。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StartAlmListen(long lUserID);

/**********************************************************************
* 函数名称：TY_Server_StopAlmListen
* 功能描述：停止监听报警，退出将无法收到报警信息。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopAlmListen(long lUserID);

//音视频预览相关
/**********************************************************************
* 函数名称：TY_Server_RequestPlay
* 功能描述：预览申请函数。用来向中心管理服务器进行的预览申请，查看用户是否有权限，
            以及采取何种方式预览（直连/转发）等等。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpViewInfo 视频申请信息（主机IP/ID、通道号、预览方式）。
* 输出参数：nLinkType[out] 连接方式，直连或者转发；
		    lpDEVInfo[out] 设备登录信息结构指针，用来存储当返回为直连方式
            去申请视频时的一些设备连接相关的信息。当反馈为转发时，该参数无意义。
* 返 回 值：-1代表失败，其它值为预览操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_RequestPlay(long lUserID,
                                    LPT_VIEW_APPLYINFO lpViewInfo,
                                    int &nLinkType,
                                    LPT_DEV_LOGIN_INFO lpDEVInfo);

//音视频预览相关-日常巡查，仅转发
/**********************************************************************
* 函数名称：TY_Server_RequestPlayRCXC
* 功能描述：预览申请函数。用来向中心管理服务器进行的预览申请，查看用户是否有权限，
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpViewInfo 视频申请信息（主机IP/ID、通道号、预览方式）。
* 返 回 值：-1代表失败，其它值为预览操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_RequestPlayRCXC(long lUserID,
                                    LPT_VIEW_APPLYINFO_EX lpViewInfo);


/**********************************************************************
* 函数名称：TY_Server_StartPlay
* 功能描述：开始预览函数。
            当预览申请时反馈为采用经过媒体服务器转发的方式进行预览时调用该函数开始预览；
            当为直连设备的方式时，不能调用该函数开始预览，应采用网络库中的开始预览函数。
* 输入参数：lPlayID 申请成功返回的预览句柄；
		    fpDataCallBack 数据回调函数；
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StartPlay(long lPlayID,
                                                  DataCallBack pfDataCallBack,
                                                  DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_StopPlay
* 功能描述：停止预览操作。当调用预览申请函数成功，无论采用转发的方式或者直连的方式，
            并且不管开始预览是否成功，都应该调用此函数来结束此次预览操作。
* 输入参数：lPlayID 申请成功返回的预览句柄；
		    nLinkType 预览方式（直连/转发）。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopPlay(long lPlayID, int nLinkType);
/**********************************************************************
* 函数名称：TY_Server_SendPlayResult
* 功能描述：通知预览结果。当直连方式预览时，将具体的预览结果通知给中心管理服务器。
*           转发方式不用调用该函数。
* 输入参数：lPlayID 申请成功返回的预览句柄；
		    nResult 预览结果（0-用户停止；其余是申请失败的错误码）。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SendPlayResult(long lPlayID, int nResult);

//回放下载相关
/**********************************************************************
* 函数名称：TY_Server_RequestPlayOrDown
* 功能描述：回放下载申请函数。用来向中心管理服务器进行的回放下载申请，查看用户是否有权限，
            回放或者下载的DVR上的文件还是存储设备上的文件。
            以及采取何种方式（直连/转发）回放和下载等等。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDEVIDInfo 设备ID信息。
            nStorageLocation 文件位置（0-DVR，1-存储设备）
* 输出参数：nLinkType 连接方式，直连或者转发；
            lpReplyInfo 反馈信息结构指针，用来存储当返回为直连方式去回放或者
            下载时的一些连接设备的信息、回放权限、下载权限等信息。
            当反馈为转发时，该参数无意义。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_RequestPlayOrDown(
                                        long lUserID,
                                        LPT_DEVID_INFO lpDEVIDInfo,
                                        int nStorageLocation,
                                        int &nLinkType,
                                        LPT_REPLY_PLAYANDDOWN_INFO lpReplyInfo);

//回放下载相关
/**********************************************************************
* 函数名称：TY_Server_RequestPlayOrDown
* 功能描述：回放下载申请函数。用来向中心管理服务器进行的回放下载申请，查看用户是否有权限，
            回放或者下载的DVR上的文件还是存储设备上的文件。
            以及采取何种方式（直连/转发）回放和下载等等。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDEVIDInfo 设备ID信息。
            nStorageLocation 文件位置（0-DVR，1-存储设备）
* 输出参数：nLinkType 连接方式，直连或者转发；
            lpReplyInfo 反馈信息结构指针，用来存储当返回为直连方式去回放或者
            下载时的一些连接设备的信息、回放权限、下载权限等信息。
            当反馈为转发时，该参数无意义。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_RequestPlayOrDownEx(
                                        long lUserID,
                                        LPT_DEVID_INFO lpDEVIDInfo,
                                        int nStorageLocation,
                                        int &nLinkType,
                                        LPT_REPLY_PLAYANDDOWN_INFO_EX lpReplyInfo);

/**********************************************************************
* 函数名称：TY_Server_SearchFileList
* 功能描述：检索符合条件文件列表，文件列表以回调函数的方式给出。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpSearchInfo 检索条件（主机IP/ID、通道号、时间、文件类型、存储位置等）；
            pfFileListCallBack 文件列表回调函数；
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SearchFileList(
                                        long lUserID,
                                        LPT_SEARCHFILE_INFO lpSearchInfo,
                                        FileListCallBack pfFileListCallBack,
                                        DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_StopSearchFile
* 功能描述：停止检索文件列表。当用户主动停止检索或者检索结束时调用该函数，其与开始检索函数是成对使用。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopSearchFile(long lUserID);

/**********************************************************************
* 函数名称：TY_Server_PlayBackByName
* 功能描述：按文件名称方式进行远程网络回放，数据通过回调函数给出，
            由应用程序自己去进行解码操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpPlayBackInfo 回放信息，包括设备信息、通道信息、存储位置等。
		    lpFileInfo 文件信息；
		    pfDataCallBack 数据回调函数；
			lFileSize 回放文件大小
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：-1代表失败，其它值为回放操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_PlayBackByName(
                                        long lUserID,
                                        LPT_PLAYORDOWN_PARA lpPlayBackInfo,
                                        LPT_SEARCHFILE_CMS_RESULT_INFO lpFileInfo,
                                        DataCallBack pfDataCallBack,
										long& lFileSize,
                                        DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_PlayBackByNameOnDVR
* 功能描述：按文件名称方式对DVR上的文件进行远程网络回放，数据通过回调函数给出，
            由应用程序自己去进行解码操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpPlayBackInfo 回放信息，包括设备信息、通道信息、存储位置等。
		    lpFileInfo 文件信息；
		    pfDataCallBack 数据回调函数；
			lFileSize 文件体积(传出)
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：-1代表失败，其它值为回放操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_PlayBackByNameOnDVR(
												long lUserID,
												LPT_PLAYORDOWN_PARA lpPlayBackInfo,
												LPTJTY_NET_FILEINFO lpFileInfo,
												DataCallBack pfDataCallBack,
												long& lFileSize,
												DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_PlayBackOnDVR_RCXC
* 功能描述：按文件名称方式对DVR上的文件进行远程网络回放，数据通过回调函数给出，
            由应用程序自己去进行解码操作。日常巡查使用
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpPlayBackInfo 回放信息，包括设备信息、通道信息、存储位置等。
		    lpFileInfo 文件信息；
			lpTransInfo 日常巡查相关信息
		    pfDataCallBack 数据回调函数；
			lpFileSize 文件体积(传出)
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：-1代表失败，其它值为回放操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_PlayBackOnDVR_RCXC(
                                        long lUserID,
                                        LPT_PLAYORDOWN_PARA lpPlayBackInfo,
                                        LPTJTY_NET_FILEINFO lpFileInfo,
										LPT_MS_TRANS_PLAYBACK_RCXC lpTransInfo,
                                        DataCallBack pfDataCallBack,
										long* lpFileSize,
                                        DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_PlayBackOnDVR_Compress
* 功能描述：按文件名称方式对DVR上的文件进行远程网络回放，使用压缩接口，数据通过回调函数给出，
            由应用程序自己去进行解码操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
			nMode, 回放方式：1-文件2-时间，时间由lpFileInfo里的time字段给出
		    lpPlayBackInfo 回放信息，包括设备信息、通道信息。
		    lpFileInfo 文件信息；
			lpCompressInfo 压缩参数
		    pfDataCallBack 数据回调函数；
			lpFileSize 文件体积(传出)
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：-1代表失败，其它值为回放操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_PlayBackOnDVR_Compress(
                                        long lUserID,
										int nMode,
                                        LPT_PLAYORDOWN_PARA lpPlayBackInfo,
                                        LPTJTY_NET_FILEINFO lpFileInfo,
										LPTJTY_NET_COMPRESS_REMOTEPLAY lpCompressInfo,
                                        DataCallBack pfDataCallBack,
										long* lpFileSize,
                                        DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_PlayBackByTime
* 功能描述：按时间方式进行远程网络回放，数据通过回调函数给出，
            由应用程序自己去进行解码操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpPlayBackInfo 回放信息，包括设备信息、通道信息、存储位置等。
            pStartTime 开始时间；
		    pStopTime 结束时间；
		    pfDataCallBack 数据回调函数；
		    dwUser 用户参数。
* 输出参数：lFileLength 文件长度，当其为-1时代表不能获取到其长度。
* 返 回 值：-1代表失败，其它值为回放操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_PlayBackByTime(
                                        long lUserID,
                                        LPT_PLAYORDOWN_PARA lpPlayBackInfo,
                                        LPT_TIME_INFO pStartTime,
                                        LPT_TIME_INFO pStopTime,
                                        DataCallBack pfDataCallBack,
                                        long* plFileLength,
										DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_StopPlayBack
* 功能描述：停止正在进行的回放操作，释放资源。当回放正常结束时，
            也应调用该函数进行资源释放。
* 输入参数：lPlayBackID 回放操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopPlayBack(long lPlayBackID);


/**********************************************************************
* 函数名称：TY_Server_PlayBackControl
* 功能描述：对正在进行的回放操作进行控制操作，包括改变播放进度、改变播放速度等操作。
* 输入参数：lPlayBackID 回放操作句柄；
		    nPlayCtrlCmd 回放控制命令；
	    	nValue 输入值（如进度值、快放倍数等）。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_PlayBackControl(long lPlayBackID,
                                                        int nPlayCtrlCmd,
                                                        void* pValue);


/**********************************************************************
* 函数名称：TY_Server_PlayBackGetStatus
* 功能描述：获取正在进行的回放的状态信息，包括播放进度。
* 输入参数：lPlayBackID 回放操作句柄；
		    nPlayInfoCmd 回放控制命令；(FILE_PLAYBACK_GETPOS)
	    	pValue 输出值（如进度值、快放倍数等，不同命令有不同的输出值）。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_PlayBackGetStatus(long lPlayBackID,
                                                        int nPlayCtrlCmd,
                                                        void* pValue);

/**********************************************************************
* 函数名称：TY_Server_SendPlayBackResult
* 功能描述：通知回放结果，当采用直连方式回放DVR设备上的文件时调用该函数，通知中心管理服务器记录或者修改回放状态。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpPlayBackInfo 回放信息，包括设备信息、通道信息、存储位置等。
            pStartTime 文件开始时间；
		    pStopTime 文件结束时间；
		    nResult 回放结果（0-失败，1-成功，2-停止）；
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SendPlayBackResult(
                                        long lUserID,
                                        LPT_PLAYORDOWN_PARA lpPlayBackInfo,
                                        LPT_TIME_INFO pStartTime,
                                        LPT_TIME_INFO pStopTime,
                                        int nResult);


/**********************************************************************
* 函数名称：TY_Server_DownLoadByName
* 功能描述：按文件名称方式进行远程下载，数据通过回调函数给出，
            由应用程序自己去进行写文件操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDownLoadInfo 下载信息，包括设备信息、通道信息、存储位置等。
		    lpFileInfo 文件信息；
            nOffset 偏移量大小，用于断点续传；
			pcLocalFileName 保存本地的文件名
		    pfDataCallBack 数据回调函数，如提供，则回调下载
			lFileSize 返回的文件大小
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：-1代表失败，其它值为下载操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_DownLoadByName(
                                        long lUserID,
                                        LPT_PLAYORDOWN_PARA lpDownLoadInfo,
                                        LPT_SEARCHFILE_CMS_RESULT_INFO lpFileInfo,
                                        int nOffset,
										char* pcLocalFileName,
                                        DataCallBack pfDataCallBack,
										long& lFileSize,
                                        DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_DownLoadByNameOnDVR
* 功能描述：按文件名称方式进行远程下载，数据通过回调函数给出，
            由应用程序自己去进行写文件操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDownLoadInfo 下载信息，包括设备信息、通道信息、存储位置等。
		    lpFileInfo 文件信息；
            nOffset 偏移量大小，用于断点续传；
			pcLocalFileName 保存本地的文件名
		    pfDataCallBack 数据回调函数，如提供，则回调下载
			lFileSize 返回的文件大小
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：-1代表失败，其它值为下载操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_DownLoadByNameOnDVR(
                                        long lUserID,
                                        LPT_PLAYORDOWN_PARA lpDownLoadInfo,
                                        LPTJTY_NET_FILEINFO lpFileInfo,
                                        int nOffset,
										char* pcLocalFileName,
                                        DataCallBack pfDataCallBack,
										long& lFileSize,
                                        DWORD dwUser);


/**********************************************************************
* 函数名称：TY_Server_DownLoadByTime
* 功能描述：按时间方式进行远程下载，数据通过回调函数给出，
            由应用程序自己去进行写文件操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDownLoadInfo 下载信息，包括设备信息、通道信息、存储位置等。
            pStartTime 开始时间；
		    pStopTime 结束时间；
            pcFilePath 文件保存路径；
		    pfDataCallBack 数据回调函数；
		    dwUser 用户参数。
* 输出参数：lFileLength 文件长度，当其为-1时代表不能获取到其长度。
* 返 回 值：-1代表失败，其它值为下载操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_DownLoadByTime(
                                        long lUserID,
                                        LPT_PLAYORDOWN_PARA lpDownLoadInfo,
                                        LPT_TIME_INFO pStartTime,
                                        LPT_TIME_INFO pStopTime,
                                        const char* pcFilePath,
                                        DataCallBack pfDataCallBack,
                                        DWORD dwUser,
                                        long &lFileLength);

/**********************************************************************
* 函数名称：TY_Server_StopDownLoad
* 功能描述：停止正在进行的下载操作，释放资源。当下载正常结束时，
            也应调用该函数进行资源释放。
* 输入参数：lDownLoadID 下载操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopDownLoad(long lDownLoadID);

/**********************************************************************
* 函数名称：TY_Server_GetDownloadPosition
* 功能描述：获取指定下载Handle的下载进度，范围0-100
* 输入参数：lDownLoadID 下载操作句柄。
* 输出参数：无。
* 返 回 值：下载进度 0-100。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetDownloadPosition(long lDownLoadID);

/**********************************************************************
* 函数名称：TY_Server_SendDownLoadResult
* 功能描述：通知下载结果，当采用直连方式下载DVR设备上的文件时调用该函数，通知中心管理服务器记录或者修改下载状态。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDownLoadInfo 下载信息，包括设备信息、通道信息、存储位置等。
            pStartTime 文件开始时间；
		    pStopTime 文件结束时间；
		    nResult 下载结果（0-失败，1-成功，2-停止）；
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SendDownLoadResult(
                                        long lUserID,
                                        LPT_PLAYORDOWN_PARA lpDownLoadInfo,
                                        LPT_TIME_INFO pStartTime,
                                        LPT_TIME_INFO pStopTime,
                                        int nResult);

//远程控制相关
/**********************************************************************
* 函数名称：TY_Server_ControlDevice
* 功能描述：运程控制函数，对前端主机进行控制操作，包括布撤防控制、外设控制、远程关机与重启等操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    nCtrlCmd 控制操作命令；
		    lpCtrlInfoList[in] 控制信息链表指针，包括设备编号、端口号等信息，
            不同的控制操作对应不同的结构；
		    nListCount 链表长度。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ControlDevice(long lUserID,
                                                      int nCtrlCmd,
                                                      void *lpCtrlInfoList,
                                                      int nListCount);

/**********************************************************************
* 函数名称：TY_Server_RequestPTZCtrl
* 功能描述：申请云台控制操作。该函数返回成功时，用户可用返回的操作句柄进行一系列的控制操作，
            当不再对该云台进行控制时需要调用停止控制函数。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDEVIDInfo 设备ID描述；
		    nListCount 链表长度。
* 输出参数：无。
* 返 回 值：-1代表失败，其它为返回的云台控制操作句柄。 
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_RequestPTZCtrl(long lUserID,
                                                       LPT_DEVID_INFO lpDEVIDInfo,
                                                       int nChannel);

/**********************************************************************
* 函数名称：TY_Server_ControlPTZ
* 功能描述：对前端设备的云台进行控制，包括方向旋转、光圈、焦距、预置位等控制操作。
* 输入参数：lPTZCtrlID 返回的云台控制操作句柄；
		    lpPTZCtrlInfoEx 云台控制描述信息链表；
		    nListCount 链表长度。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ControlPTZ(long lPTZCtrlID,
                                                   LPT_PTZ_CTRL_STRU_EX lpPTZCtrlInfoEx,
                                                   int nListCount);

/**********************************************************************
* 函数名称：TY_Server_StopPTZCtrl
* 功能描述：结束云台控制操作。
* 输入参数：lPTZCtrlID 返回的云台控制操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopPTZCtrl(long lPTZCtrlID);

//状态获取相关
/**********************************************************************
* 函数名称：TY_Server_GetDeviceState
* 功能描述：根据不同的状态命令，获取前端设备相应的工作状态，
            包括布撤防状态、硬盘状态、通道状态等。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    nStateCMD 状态命令；
		    lpGetDEVStateList 状态获取信息链表；
		    nListCount 链表长度。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetDeviceState(long lUserID,
                                                       int nStateCMD,
                                                       void *lpGetDEVStateList,
                                                       int nListCount);

/**********************************************************************
* 函数名称：TY_Server_GetUserState
* 功能描述：根据不同的状态命令，获取用户相应的工作状态，
            包括预览状态、回放状态、下载状态、在线状态等。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    nStateCMD 状态命令；
		    lpUserInfoList 用户信息链表；
		    nListCount 链表长度。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetUserState(long lUserID,
                                                     int nStateCMD,
                                                     void *lpUserInfoList,
                                                     int nListCount);

/**********************************************************************
* 函数名称：TY_Server_GetServerState
* 功能描述：根据不同的状态命令，获取相应的服务器状态。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    nStateCMD 状态命令；
		    lpServerInfoList 服务器信息链表；
		    nListCount 链表长度。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetServerState(long lUserID,
                                                       int nStateCMD,
                                                       void *lpServerInfoList,
                                                       int nListCount);

/**********************************************************************
* 函数名称：TY_Server_GetOnlineUser
* 功能描述：获取已登录中心管理服务器的用户。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    nClientType 用户类型。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetOnlineUser(long lUserID,
                                                      int nClientType);

/**********************************************************************
* 函数名称：TY_Server_GetDevSoftVersion
* 功能描述：获取指定设备的软件版本信息，该函数采用异步的方式实现，此处只发送命令数据，
            具体获取到的信息通过回调函数给出，包括设备现在运行的软件版本号和最新的软件版本号。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            lpDEVIDList 设备ID信息链表；
		    nListCount 链表长度。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetDevSoftVersion(long lUserID,
                                                      LPT_DEVID_INFO lpDEVIDList,
                                                      int nListCount);

//语音对讲相关
/**********************************************************************
* 函数名称：TY_Server_RequestTalk
* 功能描述：对讲申请函数。当监控中心用户主动选择与前端设备进行语音对讲时，
            调用该函数向中心进行申请。该函数只是进行申请验证，并未建立对讲连接。
            申请成功后，应该程序需要调用网络库来进行语音对讲。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            lpDEVIDInfo 设备ID信息；
		    nChannel 通道号。
* 输出参数：lpDEVInfo 设备登录信息结构指针，用来存储当返回设备连接相关的信息，
            包括设备IP，端口号，用户名和密码等。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_RequestTalk(long lUserID,
                                                    LPT_DEVID_INFO lpDEVIDInfo,
                                                    int nChannel,
                                                    LPT_DEV_LOGIN_INFO lpDEVInfo);

/**********************************************************************
* 函数名称：TY_Server_SendTalkResult
* 功能描述：通知对讲结果函数。将建立对讲连接的实时结果通知给中心管理服务器，
            包括建立对讲成功、建立对讲失败、拒绝对讲、结束对讲等。无论采取何种方式对讲，
            结束对讲时都应通知中心管理服务器。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            lpDEVIDInfo 设备ID信息；
		    nChannel 通道号；
            nResult[in] 对讲结果（建立对讲成功、建立对讲失败、拒绝对讲、结束对讲），见E_TALK_RESULT。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SendTalkResult(long lUserID,
                                                       LPT_DEVID_INFO lpDEVIDInfo,
                                                       int nChannel,
                                                       int nResult);

/**********************************************************************
* 函数名称：TY_Server_StartTalk
* 功能描述：开始远程语音对讲，该接口只是针对天跃工控主机主动采用第三方呼叫的方式时使用。
            内部封装了音频数据采集编码与解码的操作，具体的语音数据通过回调函数给出。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            lpDEVIDInfo 设备ID信息；
		    nChannel 通道号；
            pfTalkDataCallBack 语音数据回调函数；
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：-1表示失败，其它为对讲操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_StartTalk(long lUserID,
                                                   LPT_DEVID_INFO lpDEVIDInfo,
                                                   int nChannel,
                                                   TalkDataCallBack pfTalkDataCallBack,
                                                   DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_StartTalk
* 功能描述：结束远程语音对讲，该函数与开始语音对讲成对使用，也只有在采用
            第三方呼叫的方式进行对讲时使用。
* 输入参数：lTalkID 对讲操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopTalk(long lTalkID);

//客户端之间语音对讲相关
/**********************************************************************
* 函数名称：TY_Server_StartTalkListen
* 功能描述：建立对讲监听。当客户端可以用来与其他的客户端进行语音对讲时调用该函数，
            建立对讲监听，用来接收对讲请求。
* 输入参数：nPort 监听端口号；
            pfTalkDataCallBack 语音数据回调函数；
            dwUser 用户自定义参数。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StartTalkListen(int nPort, 
                                                        TalkDataCallBack pfTalkDataCallBack, 
                                                        DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_ReqClientTalk
* 功能描述：客户端对讲申请。当监控中心用户主动选择与其他客户端进行语音对讲时，调用该函数向中心进行申请。
            该函数只是进行申请验证，并未建立对讲连接。申请成功后，应该程序需要调用开始对讲函数来进行语音对讲。
            该函数同步方式实现。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpUserInfo 用户信息；
* 输出参数：lpClientInfo 客户端连接信息结构，用来存储当返回客户端连接相关的信息。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ReqClientTalk(long lUserID, 
                                                      LPT_USER_NAMEANDTYPE lpUserInfo, 
                                                      LPT_CLIENT_INFO lpClientInfo);

/**********************************************************************
* 函数名称：TY_Server_SendClientTalkResult
* 功能描述：通知客户端对讲结果。当客户端接收到其他客户端的对讲请求时调用该函数，
            来通知对方是接收或者拒绝对讲；当接受对方的对讲请求后，停止对讲时调用该函数结束对讲。
* 输入参数：lnResult 对讲结果（E_TALK_RESULT）。 
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SendClientTalkResult(int nResult);

/**********************************************************************
* 函数名称：TY_Server_StartClientTalk
* 功能描述：开始客户端语音对讲。开始远程客户端语音对讲，当客户端主动发起与另一个客户端进行对讲时调用。
            内部封装了音频数据采集编码与解码的操作，具体的语音数据通过回调函数给出。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpClientInfo 客户端连接相关的信息。
* 输出参数：无。
* 返 回 值：-1表示失败，其它为对讲操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_StartClientTalk(long lUserID, 
                                                        LPT_CLIENT_INFO lpClientInfo);

/**********************************************************************
* 函数名称：TY_Server_StopClientTalk
* 功能描述：停止客户端语音对讲。结束远程客户语音对讲，该函数与开始语音对讲成对使用，
            也只有客户端主动对讲时调用。 
* 输入参数：lTalkID 对讲操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopClientTalk(long lTalkID);

//群呼相关
/**********************************************************************
* 函数名称：TY_Server_RequestMultiTalk
* 功能描述：群呼申请函数。向中心管理服务器发送群呼申请命令，包括将要群呼的设备信息列表。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    nDEVType 设备类型；
		    lpDEVIDList 加入群呼组的设备信息链表；
		    nListCount 设备链表长度。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_RequestMultiTalk(long lUserID,
                                                         int nDEVType,
                                                         LPT_DEVID_INFO lpDEVIDList,
                                                         int nListCount);

/**********************************************************************
* 函数名称：TY_Server_AddDEVToMulti
* 功能描述：向中心管理服务器发送添加群呼设备命令，包括将要增加群呼的设备信息列表。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDEVIDList 将要从群呼组中删除的设备信息链表； 
		    nListCount 设备链表长度。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_AddDEVToMulti(long lUserID,
                                                      int nDEVType,
                                                      LPT_DEVID_INFO lpDEVIDList,
                                                      int nListCount);

/**********************************************************************
* 函数名称：TY_Server_DelDEVFromMulti
* 功能描述：向中心管理服务器发送添加群呼设备命令，包括将要增加群呼的设备信息列表。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDEVIDList 将要从群呼组中删除的设备信息链表；
		    nListCount 设备链表长度。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_DelDEVFromMulti(long lUserID,
                                                        LPT_DEVID_INFO lpDEVIDList,
                                                        int nListCount);

/**********************************************************************
* 函数名称：TY_Server_SendMultiResult
* 功能描述：将群呼的实时结果通知给中心管理服务器，包括群呼成功、群呼失败。
            主要用于对嵌入式设备的群呼操作时使用。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            lpDEVIDInfo 设备ID信息；
		    nResult 群呼结果（群呼成功、群呼失败）。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SendMultiResult(long lUserID,
                                                         LPT_DEVID_INFO lpDEVIDInfo,
                                                         int nResult);

/**********************************************************************
* 函数名称：TY_Server_StartMultiTalk
* 功能描述：开始群呼，当对工控主机申请群呼时调用此函数开始发送语音数据。
            当申请其它嵌入式设备群呼时，应调用网络库中的开始群呼函数，此时该函数无效。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            pfTalkDataCallBack 群呼语音数据回调;
		    dwUser 用户参数。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StartMultiTalk(long lUserID,
                                                       TalkDataCallBack pfTalkDataCallBack,
                                                       DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_StopMultiTalk
* 功能描述：停止群呼操作，无论采用何种方式进行群呼操作，
            都应调用该函数通知中心管理服务器结束群呼操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopMultiTalk(long lUserID);

//校时管理相关
/**********************************************************************
* 函数名称：TY_Server_GetCMSTime
* 功能描述：获取中心管理服务器当前的时间。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetCMSTime(long lUserID);

/**********************************************************************
* 函数名称：TY_Server_ReportSatTimeToCMS
* 功能描述：向中心报告卫星时间。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            pTimeInfo 当前时间信息；
* 输出参数：无。
* 返 回 值：-1 失败，0表示成功
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ReportSatTimeToCMS(long lUserID, struct tm* pTimeInfo);

/**********************************************************************
* 函数名称：TY_Server_GetDeviceTime
* 功能描述：获取相应设备当前的时间。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            lpDEVIDList 设备信息列表；
		    nListCount 设备列表长度。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetDeviceTime(long lUserID,
                                                      LPT_DEVID_INFO lpDEVIDList,
                                                      int nListCount);

/**********************************************************************
* 函数名称：TY_Server_SetDeviceTime
* 功能描述：通知中心管理服务器对前端设备进行校时操作，主要用于手动校时。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            lpDEVIDList 设备信息列表；
		    nListCount 设备列表长度。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SetDeviceTime(long lUserID,
                                                      LPT_DEVID_INFO lpDEVIDList,
                                                      int nListCount);

/**********************************************************************
* 函数名称：TY_Server_ReplySetTime
* 功能描述：校时响应函数。当中心管理服务器向前端设备自动校时时，会通知相应的客户端，
            此时客户端调用该函数响应校时通知。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            nResult 相应结果（0-接受或者1-取消）。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ReplySetTime(long lUserID,
                                                     int nResult);

//消息转发相关
/**********************************************************************
* 函数名称：TY_Server_TransMessage
* 功能描述：消息转发函数。通过中心管理服务器将消息转发给指定的客户端。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            chUserList 接收消息的用户信息列表；
		    nListCount 用户列表长度；
		    chMsgBuf 消息缓冲区；
		    nBufSize 消息长度。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_TransMessage(long lUserID,
                                                     LPT_USER_NAMEANDTYPE lpUserList,
                                                     int nListCount,
                                                     char *chMsgBuf,
                                                     int nBufSize);

//软件升级管理
/**********************************************************************
* 函数名称：TY_Server_GetNewVersion
* 功能描述：获取客户端软件的最新版本。获取对应客户端软件的最新版本信息和能否升级的信息。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            nClientType 客户端类型；
		    dwVersion 现在运行的软件版本号。
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetNewVersion(long lUserID,
                                                      int nClientType,
                                                      DWORD dwVersion);

/**********************************************************************
* 函数名称：TY_Server_StartUpdate
* 功能描述：客户端升级请求。发送升级命令，通知中心管理服务器发送升级包。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄。
* 输出参数：无。
* 返 回 值：-1代表失败,其它为升级操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_StartUpdate(long lUserID);

/**********************************************************************
* 函数名称：TY_Server_StopUpdate
* 功能描述：客户端停止升级请求。通知中心管理服务器停止发送升级包数据。
* 输入参数：lUpdateID 升级操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopUpdate(long lUpdateID);

/**********************************************************************
* 函数名称：TY_Server_ReqDEVUpdate
* 功能描述：当客户端要对设备进行升级时调用该函数，
            向中心管理服务器发送升级申请，查看是否有权限升级，
            通过验证后返回登录设备相关的信息。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpDEVIDInfo 设备ID信息；
		    lpDEVInfo 设备登录信息结构指针，用来存储当返回设备连接相关的信息，
                      包括设备IP，端口号，用户名和密码等。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ReqDEVUpdate(long lUserID,
                                                     LPT_DEVID_INFO lpDEVIDInfo,
                                                     LPT_DEV_LOGIN_INFO lpDEVInfo);

/**********************************************************************
* 函数名称：TY_Server_ReqClientUpdate
* 功能描述：当客户端要对其它客户端进行升级时调用该函数，
            向中心管理服务器发送升级申请，查看是否有权限升级，
            通过验证后返回登录设备相关的信息。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    lpUserInfo 用户信息；
		    lpClientInfo 客户端连接信息结构指针，用来存储当返回客户端连接相关的信息；
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ReqClientUpdate(long lUserID,
                                                        LPT_USER_NAMEANDTYPE lpUserInfo,
                                                        LPT_CLIENT_INFO lpClientInfo);


//其它
/**********************************************************************
* 函数名称：TY_Server_ReqFileUpLoad
* 功能描述：申请文件上传。申请将客户端本地的配置文件上传至相关的存储设备。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            chFileName 上传文件的名称（全路径）；
		    pFileInfo 文件描述；
            lFileLength 返回的文件长度；
* 输出参数：无。
* 返 回 值：-1代表失败,其它为上传文件的操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_ReqFileUpLoad(long lUserID,
                                                       char *chFileName,
                                                       void *pFileInfo,
                                                       long &lFileLength);

/**********************************************************************
* 函数名称：TY_Server_StartFileUpLoad
* 功能描述：开始文件上传。将客户端本地的配置文件上传至相关的存储设备。
* 输入参数：lUpLoadID 文件上传操作句柄；
		    pfPosCallBack 上传进度度回调函数；
	    	dwUser 用户参数。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StartFileUpLoad(long lUpLoadID,
                                                        PosCallBack pfPosCallBack,
                                                        DWORD dwUser);

/**********************************************************************
* 函数名称：TY_Server_StopFileUpLoad
* 功能描述：停止文件上传操作，释放资源。
* 输入参数：lUpLoadID 文件上传操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopFileUpLoad(long lUpLoadID);

/**********************************************************************
* 函数名称：TY_Server_ReqFileDownLoad
* 功能描述：申请附件下载。申请将存储设备上的附件下载到客户端本地。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
            chFileName 文件名称
		    pFileInfo 文件描述；
* 输出参数：pOutFileInfo 服务器反馈的文件描述信息；
            lFileLength 文件长度。
* 返 回 值：-1代表失败,其它为附件下载的操作句柄。
***********************************************************************/
TY_SERVER_API long CALL_METHOD TY_Server_ReqFileDownLoad(long lUserID,
                                                         char *chFileName,
                                                         void *pFileInfo,
                                                         void *pOutFileInfo,
                                                         long &lFileLength);

/**********************************************************************
* 函数名称：TY_Server_StartFileDownLoad
* 功能描述：开始附件下载。将存储设备上的附件下载到客户端本地，数据通过回调函数给出，
            由应用程序自己去进行写文件操作。
* 输入参数：lDownLoadID 附件下载操作句柄；			
		    pfDataCallBack 数据回调函数；
		    dwUser 用户参数；
		    nOffSet 开始下载的位置。
* 输出参数：无
* 返 回 值：-1代表失败,其它为附件下载的操作句柄。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StartFileDownLoad(long lDownLoadID, 
                                                           DataCallBack pfDataCallBack, 
                                                           DWORD dwUser, 
                                                           int nOffSet);

/**********************************************************************
* 函数名称：TY_Server_StopFileDownLoad
* 功能描述：停止附件下载操作，释放资源。
* 输入参数：lDownLoadID 附件下载操作句柄。
* 输出参数：无。
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_StopFileDownLoad(long lDownLoadID);

/**********************************************************************
* 函数名称：TY_Server_GetMediaSessionByPlayID
* 功能描述：通过预览ID获取对应的MediaSession
* 输入参数：nPlayType 播放类型，0预览，1回放（不包含直连方式），2下载
* 输入参数：lPlayID 预览,回放，下载句柄。
* 输出参数：pMSSession MS的Session信息
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetMediaSessionByPlayID(int nPlayType, long lPlayID, T_MS_SESSION_INFO* pMSSession);

/**********************************************************************
* 函数名称：TY_Server_GetCascadeInformation
* 功能描述：获取下级级联平台的各种信息
* 参数：lUserID [in] 用户登录句柄。
			nCMSID [in] 中心级联信息
			nCommand [in] 获取命令类型
			pcParamBuf [in] 发送参数Buffer
			nParamSize [in] 发送参数Buffer大小
			pcResultBuf [out] 接受结果buffer
			pnResultSize [in, out] 接受结果buffer大小，传出时表示实际占用的大小
			pnResultCount [out] 如果结果为数组时表示数组大小
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_GetCascadeInformation(long lUserID, int nCommand, int nCMSID[5],
															  const char* pcParamBuf, int nParamSize,
															  char* pcResultBuf, int* pnResultSize, int* pnResultCount);

/**********************************************************************
* 函数名称：TY_Server_ReportClientStreamInfo
* 功能描述：向中心汇报客户端视频使用情况
* 参数：lUserID [in] 用户登录句柄。
		nClientLocation [in] 客户位置，0监控中心，1网点
		pVideoInfos [in] 视频使用信息数组
		nCount [in] 数组元素个数
* 返 回 值：0-成功,其它失败。
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ReportClientStreamInfo(long lUserID, int nClientLocation, 
															  T_VIDEO_INFO_CLIENT* pVideoInfos, int nCount);

/**********************************************************************
* 函数名称：TY_Server_RequestBandWidthForPlayback
* 功能描述：向中心申请回放或者下载的带宽
* 参数：lUserID [in] 用户登录句柄。
		bIsVod 是否是VOD点播，TRUE表示是
		pVideoInfo [in] 视频信息
		pStartTime[in]，pEndTime[in] 回放下载开始结束时间
* 返 回 值：0-成功,其它表示错误码
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_RequestBandWidthForPlayback(long lUserID, BOOL bIsVod, T_VIDEO_INFO_CLIENT* pVideoInfo, T_TIME_INFO* pStartTime, T_TIME_INFO* pEndTime);

/**********************************************************************
* 函数名称：TY_Server_SendStreammingResult
* 功能描述：向中心发送回放下载的结果
* 参数：lUserID [in] 用户登录句柄。
		bIsVod 是否是VOD点播，TRUE表示是
		pVideoInfo [in] 视频信息
		pStartTime[in]，pEndTime[in] 回放下载开始结束时间
		nResult [in] 回放下载的结果，0-正常停止或结束；其余是回放失败的错误码
* 返 回 值：0-成功,其他表示失败
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_SendStreammingResult(long lUserID, BOOL bIsVod, T_VIDEO_INFO_CLIENT* pVideoInfo, T_TIME_INFO* pStartTime, T_TIME_INFO* pEndTime, int nResult);

//IP对讲相关
/**********************************************************************
* 函数名称：TY_Server_IPTalkControl
* 功能描述：运程控制函数，主要负责IP对讲相关操作。
* 输入参数：lUserID 登录中心管理服务器成功返回的操作句柄；
		    nCtrlCmd 控制操作命令；
		    lpCtrlInfo[in] 控制信息结构体，不同命令对应的结构体不同
			nStructSize[in] 控制信息体大小
* 输出参数：无。
* 返 回 值：-1 失败，其它为此次操作对应的消息序列号
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_IPTalkControl(long lUserID,
                                                      int nCtrlCmd,
                                                      void *lpCtrlInfo, int nStructSize);

//媒体存储文件申请
/**********************************************************************
* 函数名称：TY_Server_Mediafile_Request
* 功能描述：向中心申请相关存储服务器文件，返回存放文件的流媒体信息
* 输入参数：lUserID[in] 登录中心管理服务器成功返回的操作句柄；
		    lpViewInfo[in] 设备信息，通道信息，文件类型信息
		    lpTimeBegin[in] 文件对应开始时间
			lpTimeEnd[in] 文件对应结束时间
			lpMediaInfo[out] 返回的媒体服务器信息
* 输出参数：无。
* 返 回 值：0 成功，其他表示失败
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_Mediafile_Request(long lUserID,
														LPT_VIEW_APPLYINFO lpViewInfo,
														LPT_TIME_INFO lpTimeBegin,
														LPT_TIME_INFO lpTimeEnd,
														LPT_MS_SESSION_INFO lpMediaInfo);

//通知媒体存储DVR录像文件
/**********************************************************************
* 函数名称：TY_Server_RemoteMSStoreFile_Request
* 功能描述：通知媒体存储服务器存储DVR上的录像文件，本消息通过中心转发
* 输入参数：lUserID[in] 登录中心管理服务器成功返回的操作句柄；
		    lpViewInfoEx[in] 设备信息，通道信息(本结构体仅需填写设备信息和通道号)
		    lpFileTimeInfo[in] 文件信息或者时间信息，根据nMode确定填充的内容
			nMode[in] 存储方式，1表示按文件存储，2表示按时间存储
* 输出参数：无。
* 返 回 值：0 成功，其他表示失败
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_RemoteMSStoreFile_Request(long lUserID,
														LPT_VIEW_APPLYINFO_EX lpViewInfoEx,
														LPTJTY_NET_FILEINFO lpFileTimeInfo,
														int nMode);

//跟第三方系统交换消息
/**********************************************************************
* 函数名称：TY_Server_ThirdPart_ExchangeMessage
* 功能描述：与接入zonee平台的第三方系统交换信息，第三方平台作为zonee客户端接入
*          消息反馈通过消息回调函数给出，回调的消息类型见CommonDefine.h内第三方系统交互相关
*		   消息回调buffer头部为T_MSG_RESP_RESULT，如果出错，则后续为char[64]，表示错误消息
* 输入参数：lUserID[in] 登录中心管理服务器成功返回的操作句柄；
		    nMessageType[in] 请求的消息类型，见CommonDefine.h内第三方系统交互相关
		    pReqBody[in] 请求消息的消息体，跟消息类型相关
			nBodySize[in] 请求消息体的大小
* 输出参数：无。
* 返 回 值：-1表示失败，其余表示此消息交互的消息id，此消息id会通过消息回调函数给出
***********************************************************************/
TY_SERVER_API int CALL_METHOD TY_Server_ThirdPart_ExchangeMessage(long lUserID,
														int nMessageType,
														void* pReqBody,
														int nBodySize);
//-----------------------------------------------------------------------
#endif