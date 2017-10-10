/** \file TjtyTcpClientModule.h ͷ�ļ�
 */
#ifndef TJTYTCPCLIENTMODULE_H
#define TJTYTCPCLIENTMODULE_H

#include "ZCProtocol.h"

#ifdef TJTY_TCP_CLIENT_MODULE
#define TJTY_TCPCLIENTMODULE_API extern "C" _declspec(dllexport)
#else
#define TJTY_TCPCLIENTMODULE_API extern "C" _declspec(dllimport)
#endif

/** @defgroup StateCallBackTypeDefine ״̬�ص����Ͷ���      
 * ����TJTY_TCPCLIENTMODULE_STATE_CALLBACK�ص��ļ���״̬����
 * @{
 */
#define CM_ONCONNECT  1     ///<���ӳɹ�
#define CM_ONCLOSE    2     ///<����ֹͣ
#define CM_ONERROR    3     ///<�����쳣�ж�
/** @} */

/** @defgroup MsgCallbak ��Ϣ�ص���������
 * ����ͨ���������ʹ�õ�����Ϣ�ص�����
 * @{
 */
 
/**
* @brief ��Ϣ�ص�����
*
* @param zMsgHead        ��Ϣͷ��Ϣ 
* @param pMessage        ��Ϣ��  
* @param pnMessageSize   ��Ϣ����
* @param dwUser          �û�����
*/
typedef VOID (_stdcall *TJTY_TCPCLIENTMODULE_MSG_CALLBACK)(ZC_MSG_HEAD zMsgHead, void* pMessage, INT pnMessageSize, DWORD dwUser);
/** @} */

/** @defgroup StateCallbak ״̬�ص���������
 * ����ͨ���������ʹ�õ���״̬�ص�����
 * @{
 */
 
/**
* @brief ״̬�ص�����
*
* ��Ҫ���ڻص�����ͨ��״̬
*
* @param dwState         ��Ϣ���ͣ�����ο�����define���ݣ�
* @param pMessage        ��Ϣ��  ���������Ϣ��ṹ����Ϣ���;�����
* @param pnMessageSize   ��Ϣ����
* @param dwUser          �û�����
*/
typedef VOID (_stdcall *TJTY_TCPCLIENTMODULE_STATE_CALLBACK)(DWORD dwState, void* pMessage, INT pnMessageSize, DWORD dwUser);
/** @} */

/** @defgroup InitInfoDefine �����ʼ���ṹ����
 * �������ģ���ʼ���ṹ��Ϣ
 * @{
 */

/** \brief �����ʼ���ṹ����
 *
 * �ýṹ�����ģ���ʼ��ʱ������Ҫ�����ļ��ϡ�
 */
typedef struct
{
	WORD  wProtocolVersion;                               ///<Э��汾
	WORD  wLoaclModuleType;                               ///<ģ������
	WORD  wPort;                                          ///<����˿ں� 
	TJTY_TCPCLIENTMODULE_MSG_CALLBACK pfCallback;         ///<��Ϣ�ص����� �μ� \ref MsgCallbak"��Ϣ�ص�����"���� 
	TJTY_TCPCLIENTMODULE_STATE_CALLBACK pfStateCallBack;  ///<״̬�ص����� �μ� \ref StateCallbak"״̬�ص�����"����   
	DWORD dwUser;                                         ///<�û�����
}TCPCLIENTMODULE_INIT_INFO,*LPTCPCLIENTMODULE_INIT_INFO;
/** @} */

/** @defgroup SendInfoDefine ��������Ϣ�ṹ����
 * �����������Ϣ�ṹ��Ϣ
 * @{
 */

/** \brief ��������Ϣ�ṹ����
 *
 * �ýṹ�Ǵ�������Ϣ�������ļ��ϡ�
 */
typedef struct
{
    WORD   wModuleType;         ///<����ģ������
	WORD   wReservedEx;         ///<Ԥ������
	DWORD  dwMsgType;           ///<��Ϣ����
	DWORD  dwMsgId;             ///<��Ϣ���
    BYTE*  pBuffer;             ///<��Ϣ��
    DWORD  dwLength;            ///<��Ϣ�峤��
}TCPCLIENTMODULE_SEND_INFO,*LPTCPCLIENTMODULE_SEND_INFO;
/** @} */

/** @defgroup APIInterface �ͻ������ģ��ӿ�API
 *  @{
 */
/**
* ����ͨ���齨�����߳���
*
* �ýӿ��ڳ�ʼ���ӿ�ǰ������Ч��
*
* @param nAnalyThreadCount[in] ��Ϣ���������߳�����ģ�������Ϣ��Ƶ��ʱ�������ʵ������ֵ��Ĭ��ֵΪ2��
* @param nSendThreadCount[in]  ��Ϣ�����߳�����ģ��ת����Ϣ��Ƶ��ʱ�������ʵ������ֵ��Ĭ��ֵ1��
*
* @return ��ʼ���Ƿ�ɹ� �ɹ�true��ʧ��false
*/
TJTY_TCPCLIENTMODULE_API bool _stdcall TJTY_TcpClient_SetThreadCount(int nAnalyThreadCount,int nSendThreadCount);

/**
* ��ʼ������
*
* ��ʼ���ɹ���ʾͨ�Ž����ɹ���
*
* @param info[in] ��ʼ������,�μ� \ref InitInfoDefine "�����ʼ���ṹ"����
*
* @return ��ʼ���Ƿ�ɹ� �ɹ�true��ʧ��false
*/
TJTY_TCPCLIENTMODULE_API bool _stdcall TJTY_TcpClient_Init(TCPCLIENTMODULE_INIT_INFO info);

/**
* ��Ӵ�������Ϣ����
* 
* ���ڿͻ���ģ�������������Ϣ������Ϣ����ɿͻ����Զ��壻���ڷ�����Ϣ����Ϣ���ʹ�ý��յ������ֵ��
* δ��ʼ���������쳣�Ͽ����ú���������ִ��ʧ�ܡ�
*
* @param info[in] ��ʼ���������μ� \ref SendInfoDefine "��������Ϣ�ṹ"����
*
* @return �����Ƿ�ɹ� �ɹ�true��ʧ��false
*/
TJTY_TCPCLIENTMODULE_API bool _stdcall TJTY_TcpClient_AddWaitSendMsg(TCPCLIENTMODULE_SEND_INFO info);

/**
* ����ͨ�ź���
* 
* �ýӿ���Ҫ���������˶Ͽ�ͨ�ţ��ɹ�������Ϣ�󣬻���CM_ONCLOSE��Ϣ���أ�
*
* @return �����Ƿ�ɹ� �ɹ�true��ʧ��false
*/
TJTY_TCPCLIENTMODULE_API bool _stdcall TJTY_TcpClient_UnInit();

/**
* ������־��¼��ʽ
*
* ����ĳ�ʼ����񣬲�Ӱ��ýӿڵ�ʹ�á�
* 
* @param bWriteAll[in] true-��¼������־ false-��¼������־
*/
TJTY_TCPCLIENTMODULE_API void _stdcall TJTY_TcpClient_SetLogWriteType(bool bWriteAll);

/**
* ��¼��־
*
* ����ĳ�ʼ����񣬲�Ӱ��ýӿڵ�ʹ�á�
* 
* @param pLog[in]       ��־����
* @param bMustWrite[in] �Ƿ�����¼
*/
TJTY_TCPCLIENTMODULE_API void _stdcall TJTY_TcpClient_WriteLog(const char* pLog,bool bMustWrite);
/** @} */
#endif