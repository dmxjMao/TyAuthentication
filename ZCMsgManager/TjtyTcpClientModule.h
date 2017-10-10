/** \file TjtyTcpClientModule.h 头文件
 */
#ifndef TJTYTCPCLIENTMODULE_H
#define TJTYTCPCLIENTMODULE_H

#include "ZCProtocol.h"

#ifdef TJTY_TCP_CLIENT_MODULE
#define TJTY_TCPCLIENTMODULE_API extern "C" _declspec(dllexport)
#else
#define TJTY_TCPCLIENTMODULE_API extern "C" _declspec(dllimport)
#endif

/** @defgroup StateCallBackTypeDefine 状态回调类型定义      
 * 定义TJTY_TCPCLIENTMODULE_STATE_CALLBACK回调的几种状态类型
 * @{
 */
#define CM_ONCONNECT  1     ///<连接成功
#define CM_ONCLOSE    2     ///<连接停止
#define CM_ONERROR    3     ///<连接异常中断
/** @} */

/** @defgroup MsgCallbak 消息回调函数定义
 * 定义通信组件库中使用到的消息回调函数
 * @{
 */
 
/**
* @brief 消息回调函数
*
* @param zMsgHead        消息头信息 
* @param pMessage        消息体  
* @param pnMessageSize   消息长度
* @param dwUser          用户参数
*/
typedef VOID (_stdcall *TJTY_TCPCLIENTMODULE_MSG_CALLBACK)(ZC_MSG_HEAD zMsgHead, void* pMessage, INT pnMessageSize, DWORD dwUser);
/** @} */

/** @defgroup StateCallbak 状态回调函数定义
 * 定义通信组件库中使用到的状态回调函数
 * @{
 */
 
/**
* @brief 状态回调函数
*
* 主要用于回调处理通信状态
*
* @param dwState         消息类型（详情参看上述define内容）
* @param pMessage        消息体  （具体的消息体结构由消息类型决定）
* @param pnMessageSize   消息长度
* @param dwUser          用户参数
*/
typedef VOID (_stdcall *TJTY_TCPCLIENTMODULE_STATE_CALLBACK)(DWORD dwState, void* pMessage, INT pnMessageSize, DWORD dwUser);
/** @} */

/** @defgroup InitInfoDefine 组件初始化结构定义
 * 定义组件模块初始化结构信息
 * @{
 */

/** \brief 组件初始化结构定义
 *
 * 该结构是组件模块初始化时，各必要参数的集合。
 */
typedef struct
{
	WORD  wProtocolVersion;                               ///<协议版本
	WORD  wLoaclModuleType;                               ///<模块类型
	WORD  wPort;                                          ///<服务端口号 
	TJTY_TCPCLIENTMODULE_MSG_CALLBACK pfCallback;         ///<消息回调函数 参见 \ref MsgCallbak"消息回调函数"定义 
	TJTY_TCPCLIENTMODULE_STATE_CALLBACK pfStateCallBack;  ///<状态回调函数 参见 \ref StateCallbak"状态回调函数"定义   
	DWORD dwUser;                                         ///<用户参数
}TCPCLIENTMODULE_INIT_INFO,*LPTCPCLIENTMODULE_INIT_INFO;
/** @} */

/** @defgroup SendInfoDefine 待发送信息结构定义
 * 定义待发送信息结构信息
 * @{
 */

/** \brief 待发送信息结构定义
 *
 * 该结构是待发送信息各参数的集合。
 */
typedef struct
{
    WORD   wModuleType;         ///<接收模块类型
	WORD   wReservedEx;         ///<预留参数
	DWORD  dwMsgType;           ///<消息类型
	DWORD  dwMsgId;             ///<消息序号
    BYTE*  pBuffer;             ///<消息体
    DWORD  dwLength;            ///<消息体长度
}TCPCLIENTMODULE_SEND_INFO,*LPTCPCLIENTMODULE_SEND_INFO;
/** @} */

/** @defgroup APIInterface 客户端组件模块接口API
 *  @{
 */
/**
* 设置通信组建工作线程数
*
* 该接口在初始化接口前调用生效；
*
* @param nAnalyThreadCount[in] 消息分析处理线程数：模块接收消息较频繁时，建议适当扩大该值，默认值为2；
* @param nSendThreadCount[in]  消息发送线程数：模块转发消息较频繁时，建议适当扩大该值，默认值1；
*
* @return 初始化是否成功 成功true；失败false
*/
TJTY_TCPCLIENTMODULE_API bool _stdcall TJTY_TcpClient_SetThreadCount(int nAnalyThreadCount,int nSendThreadCount);

/**
* 初始化函数
*
* 初始化成功表示通信建立成功；
*
* @param info[in] 初始化参数,参见 \ref InitInfoDefine "组件初始化结构"定义
*
* @return 初始化是否成功 成功true；失败false
*/
TJTY_TCPCLIENTMODULE_API bool _stdcall TJTY_TcpClient_Init(TCPCLIENTMODULE_INIT_INFO info);

/**
* 添加待发送消息函数
* 
* 对于客户端模块主动请求的消息，其消息序号由客户端自定义；对于反馈消息，消息序号使用接收到的序号值。
* 未初始化或网络异常断开，该函数均可能执行失败。
*
* @param info[in] 初始化参数，参见 \ref SendInfoDefine "待发送信息结构"定义
*
* @return 操作是否成功 成功true；失败false
*/
TJTY_TCPCLIENTMODULE_API bool _stdcall TJTY_TcpClient_AddWaitSendMsg(TCPCLIENTMODULE_SEND_INFO info);

/**
* 结束通信函数
* 
* 该接口主要用于与服务端断开通信；成功发送消息后，会有CM_ONCLOSE消息返回；
*
* @return 操作是否成功 成功true；失败false
*/
TJTY_TCPCLIENTMODULE_API bool _stdcall TJTY_TcpClient_UnInit();

/**
* 设置日志记录方式
*
* 组件的初始化与否，不影响该接口的使用。
* 
* @param bWriteAll[in] true-记录所有日志 false-记录部分日志
*/
TJTY_TCPCLIENTMODULE_API void _stdcall TJTY_TcpClient_SetLogWriteType(bool bWriteAll);

/**
* 记录日志
*
* 组件的初始化与否，不影响该接口的使用。
* 
* @param pLog[in]       日志内容
* @param bMustWrite[in] 是否必须记录
*/
TJTY_TCPCLIENTMODULE_API void _stdcall TJTY_TcpClient_WriteLog(const char* pLog,bool bMustWrite);
/** @} */
#endif