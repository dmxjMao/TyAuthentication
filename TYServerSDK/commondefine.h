/*********************************************************************
* ��Ȩ���� (C)2010, �Ϻ���Ծ�Ƽ����޹�˾��
* 
* �ļ����ƣ� CommonDefine.h
* ����ժҪ�� �������ݶ��壬���������궨�壬���ݽṹ����ȡ�
* ��ǰ�汾�� 
* ��    �ߣ� ��С·
* ������ڣ� 20100426
* �޸ļ�¼��1. 20100907  ��С· �滻���������Ͷ��塣
*           2. 20100916  ��С· ������״̬��ȡʱ��Ҫ�����ݽṹ��
*           3. 20101110  ��С· �������Ϣ��������Ϣö�ٺ����ݽṹ
**********************************************************************/
#ifndef TY_SERVER_COMMONDEFINE_H
#define TY_SERVER_COMMONDEFINE_H

#include <stdio.h>
#include "TY_Type.h"
#include "ErrorCode.h"

//-------------------------------------------------------------------
//�����궨��
#define IP_LENGTH           20      //IP��ַ����
#define ID_LENGTH           20      //�û����ID����
#define NAME_LENGTH         20      //���Ƴ���
#define PASSWORD_LENGTH     20      //���볤��
#define KEY_LENGTH          20      //key�ĳ���
#define SESSIONID_LENGTH    32      //�ỰID����
#define DEV_ID_LENGTH       20      //�豸���ID����
#define HANDLE_LENGTH       20      //�������
#define MAX_CASCADE         5	    //���������	
#define FILE_NAME_LENGTH    60      //�ļ�������
#define FILE_INFO_LENGTH    20      //�ļ���������
#define SYS_HEADER_LENGTH   256     //ϵͳͷ����
#define CLIENT_PSW_LENGTH   128     //�ͻ��˵�¼CMS���볤��
#define FILE_FULL_PATH_LENGTH 255   //�ļ�ȫ·������
#define VODSESSIONIDLEN     1

//---------------------------------------------------------------------
//����Ƶ�������ͺ궨��
#define SYSHEAD_DATA         0   //ϵͳͷ��Ϣ
#define AUDIO_AND_VIDEO_DATA 1   //����Ƶ�������
#define VIDEO_DATA           2   //��Ƶ����
#define AUDIO_DATA           3   //��Ƶ����
#define FILE_DATA            4  //�ļ�����

//----------------------------------------------------------------------
//�ص���Ϣ���ͺ궨��
//�Խ������Ϣ
#define CLIENT_TALK_REQUEST 1000    //�ͻ��˶Խ�����
#define CLIENT_TALK_REFUSE  1001    //�ͻ��˾ܾ��Խ�
#define CLIENT_TALK_STOP    1002    //�ͻ���ֹͣ�Խ�
#define CLIENT_TALK_FAIL    1003    //�ͻ��˽����Խ�ʧ�� 
#define CLIENT_TALK_OK      1004    //�ͻ��˽����Խ��ɹ�
#define CLIENT_TALK_IN_TALK 1005    //�ͻ������ڽ��жԽ�

//���������Ϣ
#define DEV_VERSION_INF0         1100   //�豸�汾��Ϣ
#define CLIENT_NEWVERSION_INFO   1101   //�ͻ��˰汾��Ϣ
#define START_CLIENT_UPGRADE     1102   //�ͻ��˿�ʼ�������� 

//��̨���ƽ��
#define PTZ_CTRL_RESULT          1200   //��̨���Ʋ�������

//Ⱥ�����
#define REQ_MULTITALK_RESULT     1300   //Ⱥ��������
#define ADD_MULTITALK_RESULT     1301   //���Ⱥ���豸���

//ʱ��������
#define CMS_TIME_INFO            1400   //CMSʱ����Ϣ
#define DEV_TIME_INFO            1401   //�豸ʱ����Ϣ
#define SET_DEV_TIME_BACK        1402   //�����豸ʱ�䷴��
#define SET_TIME_NOTICE          1403   //CMSУʱ֪ͨ
#define SETTIME_PLAN_MOD         1404   //Уʱ�ƻ��޸���Ϣ���� 

//��Ϣת��
#define MSG_TRANS_BY_CMS         1500   //�������Ĺ��������ת������Ϣ 
#define MSG_TRANS_RESP           1501   //��Ϣת���ɹ������

//��Ϣ֪ͨ�뷢�����
#define USER_LOGIN_CMS           1600   //�û�����
#define USER_LOGOUT_CMS          1601   //�û�����
#define TALK_REQUST              1602   //��������
#define TALK_NOTICE              1603   //����֪ͨ
#define DEV_MODIFY               1604   //�豸�����޸�
#define SERVER_LOGIN             1605   //����������
#define SERVER_LOGOUT            1606   //����������
#define SETTIME_ERROR_NOTICE     1607   //�ƻ�Уʱʧ��֪ͨ
#define DEV_SETTIME_FAIL         1608   //�ƻ�Уʱ��̨�豸Уʱʧ��
#define TICK_USER_OUT            1609   //�û���������
#define VIEW_TICK_OUT            1610   //Ԥ�����ߵȼ��û�������
#define DEV_USERNAME_PWD_MOD     1611   //��¼�豸���û������������޸�
#define DEV_IP_MOD               1612   //�豸��IP�޸�
#define EMERGENCY_PLAN_MOD       1613   //Ӧ��Ԥ���޸� 
#define ADD_NODE                 1614   //��ӽڵ�
#define DEL_NODE                 1615   //ɾ���ڵ�
#define MOD_NODE                 1616   //�޸Ľڵ�
#define MOV_NODE                 1617   //�ƶ��ڵ�
#define ADD_NODETYPE             1618   //��ӽڵ�
#define MOD_NODETYPE             1619   //�޸Ľڵ�
#define DEL_NODETYPE             1620   //ɾ���ڵ�
#define MSSTORE_PlAN_MOD         1621  //¼��ƻ����޸�
#define MSSTORE_CLAER_MOD        1622  //���̲��Ե��޸�
#define MSSTORE_SET_MOD          1623  //¼�������޸�
#define ALARMCONFIG_MOD_REL      1624  //�������Ͳ����޸�
#define ROUTEREGULATION_MOD_REL  1625  //·�ɹ����޸� 


//�豸�������
#define DEV_REROOT_RESULT        1700   //�豸�������
#define DEV_SHUTDOWN_RESULT      1701   //�ر��豸���
#define CTRL_ALARMIN_RESULT      1702   //���������ƽ��
#define CTRL_ALARMOUT_RESULT     1703   //����������ƽ��
#define CTRL_VIDEOPARA_RESULT    1704   //��Ƶ�������ڽ��
#define CTRL_AIRCONDTION_RESULT  1705   //�յ����ؿ��ƽ��
#define CTRL_ACPARAM_RESULT      1706   //�յ��������ڽ��   
#define CTRL_ALARMHOST_RESULT	 1707	//������������

//�豸״̬���
#define DEV_ONLINE_STATE         1800  //�豸����״̬
#define DEV_RUN_STATE            1801  //�豸����״̬
#define DISK_STATE               1802  //Ӳ��״̬
#define ALMIN_STATE              1803  //��������̽ͷ״̬
#define ALMOUT_STATE             1804  //�������״̬
#define CHANNEL_STATE            1805  //ͨ��״̬
#define ENVIRONMENT_STATE        1806  //����״̬
#define ACCESS_STATE             1807  //�Ž�״̬
#define VIDEO_PARAM              1808  //��Ƶ����
#define ALARMHOST_STATE			 1809  //��������״̬

#define PATROL_ARM_STATE		 1810  //Ѳ�첼����״̬
#define PATROL_CLOCK_STATE		 1811  //Ѳ��ʱ��״̬
#define PATROL_DISK_STATE		 1812  //Ѳ��Ӳ��״̬
#define PATROL_RECORD_STATE		 1813  //Ѳ��¼��״̬
#define PATROL_RECORD_DAYS		 1814  //Ѳ��¼������
#define PATROL_RECORD_INTEGRITY	 1815  //Ѳ��¼��������
#define PATROL_VIDEO_QUALITY	 1816  //Ѳ����Ƶ�������
#define PATROL_NODE_STATE		 1817  //�ڵ�״̬

//�û�״̬���
#define USER_ONLINE_STATE        1900  //�û�����״̬
#define USER_REALPLAY_STATE      1901  //�û�Ԥ��״̬
#define USER_REMOTEPLAY_STATE    1902  //�û��ط�״̬
#define USER_DOWNLOAD_STATE      1903  //�û�����״̬
#define USER_TALKBACK_STATE      1904  //�û��Խ�״̬
#define MS_STATE                 1905  //ý�������״̬
#define AS_STATE                 1906  //����������״̬
#define CMS_STATE                1907  //���Ĺ��������״̬
#define USER_VERSION             1908  //�û�����¼�ͻ��˵İ汾��Ϣ
#define ONLINE_USER              1909  //�����û��б�   
#define ONLINE_MS                1910  //����ý����Ϣ
#define ONLINE_AS                1911  //���߱�����������Ϣ   
#define ONLINE_MS_EX             1912  //����ý����ϢEX
#define ONLINE_AS_EX             1913  //���߱�����������ϢEX
#define ONLINE_USER_EX           1914  //�����û��б�EX

//�ļ��ϴ������أ��طŲ������
#define FILE_UPLOAD_END          2000  //�ļ��ϴ�����
#define FILE_DOWNLOAD_END        2001  //�ļ����ؽ���
#define FILE_PLAYBACK_POS		 2002  //�����ļ��ط�λ��
#define FILE_PLAYBACK_GETPOS	 2003  //��ȡ�ļ��ط�λ��
#define FILE_PLAYBACK_SETTIME    2004  //�����ļ��ط�ʱ��
#define FILE_PLAYBACK_GETTIME	 2005  //��ȡ�ļ��ط�ʱ��
#define FILE_PLAYBACK_SETSPEED	 2006  //���ûطű���

//���������Ϣ��ȡ
#define CASCADE_INFO_CMS		 2101	//������Ϣ (�����������������)
#define CASCADE_INFO_USER		 2102	//�û���Ϣ (P_UserInfo, S_UserInfo)
#define CASCADE_INFO_PRIVILEGE	 2103	//Ȩ����Ϣ (Char[64], S_ShowClientPrivilegeInfo)
#define CASCADE_INFO_AREANODE	 2104	//������Ϣ (P_AreaInfo, S_AreaNodeInfo)
#define CASCADE_INFO_DEVNODE	 2105	//�豸��Ϣ (NULL, S_DevNodeInfo)
#define CASCADE_INFO_FRONTNODE	 2106	//ǰ�˽ڵ���Ϣ (NULL, S_FrontendNodeInfo)
#define CASCADE_INFO_FRONTALARM	 2107	//ǰ���豸�������� (P_FrontendAlarmInfo, S_FrontendAlarmInfo)
#define CASCADE_INFO_DEVALARM	 2108	//��������������Ϣ (P_HostAlarmInfo, S_HostAlarmInfo)
#define CASCADE_INFO_ALARMHOST	 2109	//����������Ϣ (P_AlarmPartionInfo, S_AlarmPartionInfo)
#define CASCADE_INFO_DEVTALK	 2110	//�����Խ�������Ϣ (NULL, S_HostTalkInfo)
#define CASCADE_INFO_CHLTALK	 2111	//ͨ���Խ�������Ϣ (NULL, S_FrontendTalkInfo)
#define CASCADE_INFO_GISMAP		 2112	//GIS������Ϣ (P_GSMAPSHOWInfo, S_GSMAPShowInfo)
#define CASCADE_INFO_PTZ_PRESET	 2113	//��̨Ԥ�õ���Ϣ (NULL, S_ShowPrePointInfo)
#define CASCADE_INFO_PTZ_TRACE	 2114	//��̨Ѳ����Ϣ  (NULL, S_ShowCruiseInfo)
#define CASCADE_INFO_PTZ_LOCUS	 2115	//��̨�켣��Ϣ (NULL, S_ShowPrePointInfo)

#define MSG_VIDEO_CLIENT_KICKOUT 2200	//��Ƶ�û���ռ

//������ϵͳ�������
#define THIRDPART_MESSAGE_SY_SCHEDULE_INFO		3000	//��ȡָ�������Ѻ���Ű���Ϣ(��Ѻ)[REQ:int,��֯����id][RESP:TSyScheduleList]
#define THIRDPART_MESSAGE_SY_IMAGE				3001	//��ȡ�������͵�ͼƬ(��Ѻ)[REQ:TSyGetImage][RESP:TSyImageId]
#define THIRDPART_MESSAGE_SY_SERVER_TIME		3002	//��ȡ������ʱ��(��Ѻ)[REQ����][RESP:T_TIME_INFO]
#define THIRDPART_MESSAGE_SY_ROUTE_STATUS		3003	//��ȡָ������Ѻ��·�ߵ�״̬(��Ѻ)[REQ:int,��֯�ṹid][RESP:TSyRouteList]
#define THIRDPART_MESSAGE_SY_TAG_DATA			3004	//��ȡ���ӱ�ǩ������ϸ��Ϣ(��Ѻ)[REQ:TSyGetTagData][RESP:TSyTagDataList]

//-----------------------------------------------------------------------
//�쳣��Ϣ�궨��
#define USER_EXCHANGE_ERR   1      //�û������쳣
#define ALARM_EXCHANGE_ERR  2      //���������������쳣 
#define REALPLAY_ERR        3      //Ԥ���쳣
#define PLAYBACK_ERR        4      //�ط��쳣
#define DOWNLOAD_ERR        5      //�����쳣
#define FILE_DOWNLOAD_ERR   6      //���������쳣 
#define FILE_UPLOAD_ERR     7      //�����ϴ��쳣
#define CLIENT_TALKCMD_ERR  8      //�ͻ��˶Խ���������쳣
#define CLIENT_TALKDATA_ERR 9      //�ͻ��˶Խ����ݽ����쳣 
#define REALPLAY_RESTORE    10	   //��Ƶ�ָ����ͻ���ʹ��		
//------------------------------------------------------------------------
//������ֵģ��
#define MODULE_LXJC_SHORT	"LXJC"
#define MODULE_LXJC_NAME	"¼����ģ��"

#define MODULE_SJGL_SHORT	"SJGL"
#define MODULE_SJGL_NAME	"�¼�����ģ��"

#define MODULE_PERIOD_FORBIDDEN		(-1)
#define MODULE_PERIOD_UNLIMITED		0
#define MODULE_PERIOD_LIMITED		1

/****************************************************************************
*************************����ԭ��********************************************
****************************************************************************/

//�ص�����ԭ��
//----------------------------------------------------------------------------
//�쳣��Ϣ�ص�����
/****************************************************************************
* �������ƣ�ExceptionMsgCallBack
* �����������쳣��Ϣ�ص������������ص��쳣��Ϣ��
* ��    ����dwExceptMsg �쳣��Ϣ���ͣ�
            lHandle ��Ӧ�Ĳ��������
            dwUser �û��Զ��������
* �� �� ֵ�� �ޡ�
*****************************************************************************/
typedef void(__stdcall *ExceptionMsgCallBack)(U_LONG_TY dwExceptMsg, LONG_TY lHandle, U_LONG_TY dwUser);

//��Ϣ�ص�����
/****************************************************************************
* �������ƣ�MsgCallBack
* ������������Ϣ�ص������������ص�������Ϣ��
* ��    ����lUserID ��¼���Ĺ�����������صĲ��������
		    MsgType ��Ϣ���ͣ�
		    chMsgBuf ��Ϣ������������
		    dwBufSize ��Ϣ���峤�ȣ�
		    dwUser �û�������
* �� �� ֵ�� �ޡ�
*****************************************************************************/
typedef void(__stdcall *MsgCallBack)(LONG_TY lUserID, U_LONG_TY MsgType,
                                    U_CHAR_TY *chMsgBuf, U_LONG_TY dwBufSize, U_INT_TY nMsgID, U_LONG_TY dwUser);

//������Ϣ�ص�
/****************************************************************************
* �������ƣ�AlmMsgCallBack
* ����������������Ϣ�ص������������ص�������Ϣ��
* ��    ����lUserID ��¼���Ĺ�����������صĲ��������
		    chAlmMsgBuf������Ϣ��������
		    dwBufSize ��Ϣ���峤�ȣ�
            nMsgID ��Ϣ���кţ�
		    dwUser �û�������
* �� �� ֵ�� �ޡ�
*****************************************************************************/
typedef void(__stdcall *AlmMsgCallBack)(LONG_TY lUserID, U_CHAR_TY *chAlmMsgBuf,
                              U_LONG_TY dwBufSize, U_LONG_TY dwUser);

//����Ƶ���ݻص�����
/****************************************************************************
* �������ƣ�DataCallBack
* ��������������Ƶ���ݻص������������ص�Ԥ�����طš�����ʱ������Ƶ���ݡ�
* ��    ����lHandle ���������
		    dwDataType �������ͣ�
		    pBuffer ���ݻ�������
		    dwBufSize ��������С(1-����������0-�����쳣������-����);
		    dwUser �û�����
* �� �� ֵ�� �ޡ�
*****************************************************************************/
typedef void(__stdcall *DataCallBack)(LONG_TY lHandle, U_LONG_TY dwDataType, U_CHAR_TY *pBuffer,
                            U_LONG_TY dwBufSize, U_LONG_TY dwUser);

//�ļ��б�ص�����
/****************************************************************************
* �������ƣ�FileListCallBack
* �����������ļ��б�ص��������ص������ļ��б�ʱ���ļ���Ϣ��
* ��    ����llUserID��¼���Ĺ�����������صĲ��������
		    buf ���ݻ�������
		    dwBufSize ��������С��
		    dwUser �û�������
* �� �� ֵ�� �ޡ�
*****************************************************************************/
typedef void(__stdcall *FileListCallBack)(LONG_TY lUserID, void *buf, U_LONG_TY dwBufSize, U_LONG_TY dwUser);

//�Խ��������ݻص�����
/****************************************************************************
* �������ƣ�TalkDataCallBack
* �����������Խ��������ݻص������������ص������Խ�ʱ���������ݡ�
* ��    ����lTalkID �Խ����������
		    DataBuffer���ݻ�������
		    dwBufSize ��������С��
		    byAudioFlag ������Դ��־(���յ���Զ�����ݻ��߱��زɼ���������)��
		    dwUser �û�������
* �� �� ֵ�� �ޡ�
*****************************************************************************/
typedef void(__stdcall *TalkDataCallBack)(LONG_TY lTalkID, U_CHAR_TY *DataBuffer,
                                U_LONG_TY dwBufSize, U_CHAR_TY byAudioFlag, U_LONG_TY  dwUser);

//���Ȼص�����
/****************************************************************************
* �������ƣ�PosCallBack
* �����������ú�����Ҫ���ڽ��ļ��ϴ��Ľ��Ȼص����ϲ�Ӧ�ó���
* ��    ����lUpLoadID �ϴ����������
		    dwUpLoadSize �Ѿ��ϴ������ݴ�С��
		    dwTotalSize �ļ����ܴ�С��
		    dwUser �û�������
* �� �� ֵ�� �ޡ�
*****************************************************************************/
typedef void(__stdcall *PosCallBack)(LONG_TY lUpLoadID, U_LONG_TY dwUpLoadSize,
                           U_LONG_TY dwTotalSize,  U_LONG_TY dwUser);
//---------------------------------------------------------------------------

/*****************************************************************************/
/************************����ö�ٶ���*****************************************/
/*****************************************************************************/
#if 0 
/*******************************************************************************
�˲��ֶ����"porotocol.h"����ͬ�����ǵ��ͻ�����Ҫ�ⲿ�ֶ��������Ҫ"porotocol.h",
�ʽ����ڴ����¶��壬�ͻ���ʹ��ʱ��0��Ϊ1���ɡ�
*******************************************************************************/

//�豸���Ʋ�������ö�� MSG_REQ_DEV_CTR
typedef enum
{
    MSG_REQ_CTRL_DEV_REBOOT   = 0x00000001,  //�豸����
    MSG_REQ_CTRL_DEV_SHUTDOWN = 0x00000002,  //�豸�ػ�
    MSG_REQ_CTRL_ALMIN        = 0x00000004,  //����̽ͷ����
    MSG_REQ_CTRL_ALMOUT       = 0x00000008,  //�����������
    MSG_REQ_CTRL_VIDEOPARAM   = 0x00000010,  //��Ƶ��������
    MSG_REQ_CTRL_AIRCONDTION  = 0x00000020,  //�յ����ؿ���
    MSG_REQ_CTRL_ACPARAM      = 0x00000040,  //�յ���������
	MSG_REQ_CTRL_ALARMHOST    = 0x00000080   //������������
}E_MSG_REQ_DEV_CTRL;

//�豸״̬��ȡ����ö�� MSG_REQ_GET_DEV_STATE
typedef enum
{
    MSG_REQ_DEV_ONLINE_STATE  = 0x00000001,     //�豸����״̬
    MSG_REQ_DEV_RUN_STATE     = 0x00000002,     //�豸����״̬
    MSG_REQ_DISK_STATE        = 0x00000008,     //Ӳ��״̬
    MSG_REQ_ALMIN_STATE       = 0x00000010,     //����̽ͷ״̬
    MSG_REQ_ALMOUT_STATE      = 0x00000020,     //�������״̬
    MSG_REQ_CHANNEL_STATE     = 0x00000040,     //ͨ��״̬
    MSG_REQ_ENVIRONMENT_STATE = 0x00000080,     //����״̬
    MSG_REQ_ACCESS_STATE      = 0x00000100,     //�Ž�״̬
    MSG_REQ_VIDEO_PARAM       = 0x00000200,     //��Ƶ����
    MSG_REQ_ALARMHOST_STATE   = 0x00000400	//��������״̬
}E_MSG_REQ_GET_DEV_STATE;

//��ȡ�û�״̬����ö�� MSG_REQ_GET_USER_STATE
typedef enum
{
    MSG_REQ_USER_ONLINE_STATE     = 0x00000001,	//�û�����״̬
    MSG_REQ_USER_REALPLAY_STATE   = 0x00000002,	//�û�Ԥ��״̬
    MSG_REQ_USER_REMOTEPLAY_STATE = 0x00000004, //�ط�״̬
    MSG_REQ_USER_DOWNLOAD_STATE   = 0x00000008,	//����״̬
    MSG_REQ_USER_TALKBACK_STATE   = 0x00000010, //�Խ�״̬
    MSG_REQ_USER_VERSION          = 0x00000100, //�û�����¼�ͻ��˵İ汾��Ϣ
    MSG_REQ_ONLINE_USER           = 0x00000200,  //��ȡ�����û��б�
    MSG_REQ_ONLINE_USER_EX        = 0x00000400 //��ȡ�����û���Ϣ�б�
}E_MSG_REQ_GET_USER_STATE;

//��ȡ��������Ϣ�������� MSG_REQ_GET_SERVER_STATE
typedef enum
{
    MSG_REQ_ONLINE_MS			  = 0x00000001, //��ȡ����ý���������Ϣ
    MSG_REQ_ONLINE_AS			  = 0x00000002, //��ȡ���߱�����������Ϣ
    MSG_REQ_MS_STATE          	  = 0x00000004, //ý�������״̬
    MSG_REQ_AS_STATE              = 0x00000008, //����������״̬
    MSG_REQ_CMS_STATE             = 0x00000010, //���Ĺ��������״̬
    MSG_REQ_ONLINE_MS_EX		  = 0x00000020, //��ȡ����ý����Ϣ
	MSG_REQ_ONLINE_AS_EX		  = 0x00000040 //��ȡ���߱�����Ϣ
}E_MSG_REQ_GET_SERVER_STATE;

#endif


//-----------------------------------------------------------------------------
//��������
typedef enum
{
    ENCRYPT_TYPE_CLEAR = 0,	//����
    ENCRYPT_TYPE_TY,        //˽�м���
    ENCRYPT_TYPE_MD5 = 10,  //MD5
}E_ENCRYPT_TYPE;

//-----------------------------------------------------------------------------
//��֤����
typedef enum
{
    AUTH_TYPE_DEFAULT = 0,	//Ĭ�ϣ�ʹ���������õķ�ʽ��֤��
    AUTH_TYPE_ZONEE,        //�ڲ���֤��ʹ��ԭ�е�ƽ̨�ڲ���֤��ʽ��
    AUTH_TYPE_LDAP,         //LDAP��֤
    AUTH_TYPE_RADIUS,       //RADIUS��֤
}E_AUTH_TYPE;

//-----------------------------------------------------------------------------
//��������
typedef enum
{
    STREAM_TYPE_DEF = 0,    //ȱʡֵ��Ԥ��ֵ�����
    STREAM_TYPE_CIF,        //������CIF��
    STREAM_TYPE_D1,         //���壨D1��
    STREAM_TYPE_720P,       //���壨720p��
    STREAM_TYPE_1080P,      //���壨1080p��
}E_STREAM_TYPE;

//-----------------------------------------------------------------------------
//¼���ļ�����
typedef enum
{
    REC_FILE_ALL = 0,   //����¼��
    REC_FILE_TIMING,    //��ʱ¼��
    REC_FILE_MANUAL,    //�ֹ�¼��
    REC_FILE_ALARM,     //����¼��
    REC_FILE_MOVE,      //�ƶ���� 
}E_REC_FILE_TYPE;

//-----------------------------------------------------------------------------
//�Խ�֪ͨö��
typedef enum
{
    TALK_OK = 0,  //�Խ��ɹ�
    TALK_FAIL,    //�Խ�ʧ��
    TALK_ACCEPT,  //���ܶԽ�
    TALK_REFUSE,  //�ܾ��Խ�
    TALK_STOP,    //ֹͣ�Խ� 
    TALK_WAIT_TIMEOUT,  //�ȴ���ʱ

    //����
    TALK_OK_EX,
    TALK_FAIL_EX,
    TALK_STOP_EX,

	TALK_IN_TALK = 100,	//�Է����ڽ��к���

}E_TALK_RESULT;

//������Ϣö�٣����ÿͻ���ʹ�ã�
typedef enum
{
    NODETYPE_ADD = 100,   //�ڵ��������
    NODETYPE_MOD = 101,   //�ڵ������޸�
    NODETYPE_DEL = 102,   //�ڵ�����ɾ��

    NODE_ADD = 200,   //��ӽڵ�
    NODE_MOD = 201,   //�޸Ľڵ�
    NODE_DEL = 202,   //ɾ���ڵ�
    NODE_MOV = 203,   //�ƶ��ڵ�

    ALARMCONFIG_MOD = 300,   //�������ʹ�������޸�

    RECORDSET_MOD = 400,     //¼�������޸� 
    STORAGEPLAN_MOD = 401,   //�洢�ƻ��޸�

    ROUTEREGULATION_MOD = 500,   //·�ɹ����޸�
    SETTIMEPLAN_MOD = 600    //Уʱ�ƻ��޸�	
}E_CLIENT_RELEASE;
/*****************************************************************************/
/************************�ṹ�嶨��*******************************************/
/*****************************************************************************/
//ʱ����Ϣ�ṹ
typedef struct
{
    U_LONG_TY dwYear;    //��
    U_LONG_TY dwMonth;   //��
    U_LONG_TY dwDay;     //��
    U_LONG_TY dwHour;    //ʱ
    U_LONG_TY dwMinute;  //��
    U_LONG_TY dwSecond;  //��		
}T_TIME_INFO, *LPT_TIME_INFO;

//ʱ����Ϣ�ṹ��չ
typedef struct
{
	U_LONG_TY dwYear;    //��
	U_LONG_TY dwMonth;   //��
	U_LONG_TY dwDay;     //��
	U_LONG_TY dwHour;    //ʱ
	U_LONG_TY dwMinute;  //��
	U_LONG_TY dwSecond;  //��
	U_LONG_TY dwMilSecs; //����
}T_TIME_INFO_EX, *LPT_TIME_INFO_EX;

//�û���Ϣ�ṹ
typedef struct
{
    CHAR_TY chUserName[NAME_LENGTH]; //�û���
    CHAR_TY chUserPwd[CLIENT_PSW_LENGTH];  //�û�����
    INT_TY  nClientType;  //�û�����
	//INT_TY  nEncryptType; //���ܷ�ʽ  
	char byEncryptType;		//���ܷ�ʽ����E_ENCRYPT_TYPE
	char byReserved1;		//0
	char byAuthType;		//��֤���ͣ���E_AUTH_TYPE
	char byReserved2;		//0
    U_INT_TY unVersion;  //�ͻ��˰汾��
}T_CLIENT_USERINFO, *LPT_CLIENT_USERINFO;

//�û���������
typedef struct
{
    CHAR_TY chUserName[NAME_LENGTH]; //�û���
    U_LONG_TY ulUserIP;     //IP
    INT_TY nUserType;		//����
}T_USER_NAMEANDTYPE, *LPT_USER_NAMEANDTYPE;

//�����û���Ϣ
typedef struct
{
	char userName[NAME_LENGTH]; //�û���
	int ip; //IP
	int type; //����
	int version; //�汾
	char reserved[32];
} T_USERINFO_ONLINE;

//�û�������֪ͨ�ṹ
typedef struct
{
    T_USER_NAMEANDTYPE TUserInfo;
    CHAR_TY chLogInKey[KEY_LENGTH];
}T_ANCE_USER, *LPT_ANCE_USER;

//���������
typedef struct
{
    CHAR_TY chServerCode[NAME_LENGTH];
}T_SERVER_CODE, *LPT_SERVER_CODE;

//�豸ID��Ϣ
typedef struct
{
    LONG_TY lCMSCascadeInfo[MAX_CASCADE];  //���ļ�����Ϣ
    LONG_TY lDEVID;        		//�豸ID
}T_DEVID_INFO, *LPT_DEVID_INFO;

//�豸�����Ϣ
typedef struct
{
    CHAR_TY chDEVCode[DEV_ID_LENGTH];
    U_LONG_TY nDEVID;
}T_DEV_CODE, *LPT_DEV_CODE;

//������������Ϣ
typedef struct
{
    U_LONG_TY ulASIP;  //����������IP
    INT_TY nPort;             //�˿ں� 
}T_AS_INFO, *LPT_AS_INFO;

//�ͻ�����Ϣ
typedef struct
{
    U_LONG_TY ulIP;		//IP��ַ
    INT_TY  nPort;			//�˿ں�
}T_CLIENT_INFO, *LPT_CLIENT_INFO;

//��������ƵԤ���ṹ
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      //�豸ID��Ϣ
	union {
		INT_TY  nViewDataType;            //Ԥ����ʽ����Ƶ����Ƶ������Ƶ��ͼƬ�� 0��ʼ��ʾת��Ԥ����0x10��ʼ��ʾֱ��Ԥ���� 
		struct {
			SHORT_TY nStreamType; //�������ͣ���E_STREAM_TYPE��0x10��ʾֱ��Ԥ��
			SHORT_TY nViewMode; //Ԥ����ʽ��0-��ͨԤ����1-����Ԥ��
		};
	};
    INT_TY  nChannel;                 //ͨ����
}T_VIEW_APPLYINFO, *LPT_VIEW_APPLYINFO;

//��������ƵԤ���ṹ��չ
typedef struct
{
	T_DEVID_INFO devInfo; //�豸ID��Ϣ
	short stream; //0-Ĭ�ϣ�1-������2-���壬3-���壬4-���壬16-ֱ��
	short mode; //0-��ͨԤ����1-����Ԥ��
	int channel; //ͨ����
	int flag; // 0x1-�洢������ֱ��ʱ��Ч��
	int module; // 1-�������ã�2-�ճ�Ѳ�飻3-�Ž���֤
	char guid[64]; // ������GUID
	char reserved[16]; // ����
} T_VIEW_APPLYINFO_EX, *LPT_VIEW_APPLYINFO_EX;

//����ƵԤ��������ý�彻����Ϣ
typedef struct
{
    CHAR_TY chSessionID[SESSIONID_LENGTH];  //�ỰID
    U_LONG_TY ulMSIP;   //ý�������IP
    INT_TY nPort;        //ý��˿ں�
    INT_TY nTransType;   //ת����ʽ��0-TCP/1-UDP/2-�鲥��
    U_LONG_TY ulMulticastIP;   //�鲥��ַ
    INT_TY nMulticastPort;         //�鲥�˿ں�
}T_MS_SESSION_INFO, *LPT_MS_SESSION_INFO;

//�豸��¼��Ϣ�ṹ
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;            //�豸ID��Ϣ,����������Ϣ
    CHAR_TY chDEVID[DEV_ID_LENGTH];        //�豸���ID
    CHAR_TY chLoginName[NAME_LENGTH];      //��¼�û���
    CHAR_TY chLoginPwd[PASSWORD_LENGTH];   //��¼����
    INT_TY  nDEVType;                      //�豸���� ���ĸ����ҵ��豸��
    U_LONG_TY ulDEVIP;              //�豸IP
    INT_TY  nPort;                         //�豸�˿ں�
}T_DEV_LOGIN_INFO, *LPT_DEV_LOGIN_INFO;


//�ط����뷴����Ϣ�ṹ
typedef struct
{
    T_DEV_LOGIN_INFO T_DevLogInInfo;   //��¼�豸��Ϣ
    U_LONG_TY    ulPlayBackLevel;  //�ط�Ȩ��
    U_LONG_TY    ulDownLoadLevel;  //����Ȩ��
}T_REPLY_PLAYANDDOWN_INFO, *LPT_REPLY_PLAYANDDOWN_INFO;

//�ط����뷴����Ϣ�ṹ��չ
typedef struct
{
    T_DEV_LOGIN_INFO T_DevLogInInfo;   //��¼�豸��Ϣ
    U_LONG_TY    ulPlayBackLevel[8];  //�ط�Ȩ��
    U_LONG_TY    ulDownLoadLevel[8];  //����Ȩ��
}T_REPLY_PLAYANDDOWN_INFO_EX, *LPT_REPLY_PLAYANDDOWN_INFO_EX;


//�����ļ�������Ϣ�ṹ
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      	//�豸ID��Ϣ
	CHAR_TY chAreaName[64];			//��������
    T_TIME_INFO  T_StartTime;       //��ʼʱ��
    T_TIME_INFO  T_StopTime;        //����ʱ��   
    INT_TY  nChannel;               //ͨ����
    INT_TY  nStorageLoction;		//�洢λ�ã�0-DVR����ʱ�䣬1-�洢�豸��2-DVR�����ļ�ת����
    INT_TY  nFileType;			    //�ļ����ͣ�1-�ƻ��洢��2-�����洢��
	CHAR_TY chAlarmTypeName[20];	//������������
    CHAR_TY chOtherInfo[20];        //��������
}T_SEARCHFILE_INFO, *LPT_SEARCHFILE_INFO;

//���ķ��صļ����ļ��������
typedef struct
{
	CHAR_TY chDvrName[64];				//��Ƶ�ļ�����DVR����
	INT_TY nChannel;					//��Ƶ�ļ�ͨ�����
	CHAR_TY chFileName[16];				//��Ƶ�ļ���
	CHAR_TY chFilePath[32];				//�ļ������·��
	T_TIME_INFO T_VideoStartTime;		//��Ƶ�ļ���ʼʱ��
	T_TIME_INFO T_VideoEndTime;			//��Ƶ�ļ�����ʱ��
}T_SEARCHFILE_CMS_RESULT_INFO, *LPT_SEARCHFILE_CMS_RESULT_INFO;

//�طţ����أ��㲥�������ļ���Ϣ
typedef struct  
{
	CHAR_TY chFilePath[32];			//�洢�ļ����ڷ����������·��
	CHAR_TY chFileName[16];			//�洢�ļ���
	CHAR_TY chReserved[12];			//�����ֶ�
}T_PLAYBACKFILE_INFO, *LPT_PLAYBACKFILE_INFO;

//��ý��ʹ�õ��ļ�����
typedef struct
{
	INT_TY nFileType;				//�ļ����� 1. ��Ƶ��2. ��Ƶ��3. ͼƬ
	INT_TY nFileFormat;				//�ļ����� �������Ƶ��������.264��.DH�ȵ�
	LONG_TY lFileSize;				//�ļ���С���ֽ���
	LONG_TY lPlayTime;				//�ļ�����ʱ��(Ԥ��)
	CHAR_TY chReserved[8];			//����
	CHAR_TY chFileHeader[SYS_HEADER_LENGTH];		//�ļ�ͷ�����ڳ�ʼ�����ſ�
	INT_TY nHeaderSize;				//�ļ�ͷ��С
}T_PLAYBACKFILE_MS_INFO, *LPT_PLAYBACKFILE_MS_INFO;

//��ý��ת���ط�EX�ļ�����
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

//�طŻ������ز����ṹ
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      	//�豸ID��Ϣ���ط���ý��������ϵ��ļ�ʱ����Ҫ���øò���
    INT_TY nChannel;			    //ͨ����Ϣ
    INT_TY nStroageLocation;		//�洢λ��(0-DVR, 1-�洢�豸)
	T_MS_SESSION_INFO TMsSession;	//��ý�������Session����Ϣ
}T_PLAYORDOWN_PARA, *LPT_PLAYORDOWN_PARA;

//������ý��طŵ㲥���ݽṹ
typedef struct  
{
	LONG_TY lFileId;			//�������ݵ��ļ�ID
	LONG_TY lStartPos;			//�������ݵĿ�ʼλ��
	INT_TY nReqSize;			//������������ݴ�С�� > 0 ��ʾ���󳤶ȣ� = 0��ʾ����Ĭ�ϳ��� �� < 0��ʾ����ֱ���ļ�ĩβ�ĳ���
	INT_TY nFlag;				//���ֱ�ʶ������
	CHAR_TY pcReserved[12];		//����
}T_PLAYORDOWN_MSVOD_REQDATA, *LPT_PLAYORDOWN_MSVOD_REQDATA;

//��ý����Ӧ�㲥������������ݽṹͷ
typedef struct
{
	INT_TY nErrorCode;			//�����룬0��ʾ�ɹ�������ʧ��
	LONG_TY lFileId;			//��Ӧ���ļ�ID
	LONG_TY lStartPos;			//����Ŀ�ʼλ��
	INT_TY nReqSize;			//��������ݳ���
	LONG_TY lPacketStartPos;	//���η��͵Ŀ�ʼλ��
	INT_TY nPacketSize;			//���η��͵����ݳ���
	INT_TY nFlag;				//��ʶλ��0��ʾ���ݴ�����ϣ�1��ʾ����ʣ�����ݣ������һ��������ԣ�
	CHAR_TY pcReserved[12];		//����
}T_PLAYORDOWN_MSVOD_RESPDATA, *LPT_PLAYORDOWN_MSVOD_RESPDATA;

//������ý�尴ʱ��طŴ���ṹ
typedef struct {
	INT_TY nIsBeginSeek;		//�Ƿ���ת
	INT_TY nReqDataType;		//�������ݷ�ʽ
	INT_TY nTime;				//����ʱ��
	INT_TY nNum;				//�������ݰ�����
	T_TIME_INFO_EX tSeekBegin;	//��ת��ʼʱ��
	CHAR_TY pcReserved[12];		//����
} T_PLAYORDOWN_MSTIMEVOD_REQDATA, *LPT_PLAYORDOWN_MSTIMEVOD_REQDATA;

//��ý�尴ʱ��طŴ�����Ӧ�ṹ
typedef struct {
	INT_TY nErrorCode;				//������
	T_TIME_INFO_EX tCurrentTime;	//��ǰʱ��
	INT_TY nDataLength;				//���ݳ���
	INT_TY nFlag;					//��ʶλ��0��ʾ���ݴ�����ϣ�1��ʾ����ʣ�����ݣ������һ��������ԣ�
	CHAR_TY pcReserved[12];			//����
} T_PLAYORDOWN_MSTIMEVOD_RESPDATA, *LPT_PLAYORDOWN_MSTIMEVOD_RESPDATA;;

//�豸������ؽṹ
//����̽ͷ���ƽṹio
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      //�豸ID��Ϣ
    INT_TY  nPort;                //�˿ڣ��ڼ�λΪ1����ڼ����˿ڣ��ɰ�λ��
    U_CHAR_TY byCMD;              //��������������������·���ƣ�1-������2-������3-��·��4-ȡ����·�� 
}T_ALMIN_CTRL_STRU, *LPT_ALMIN_CTRL_STRU;

//����������ƽṹ
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;       //�豸ID��Ϣ
    INT_TY  nPort;                 //�˿ڣ��ڼ�λΪ1����ڼ����˿ڣ��ɰ�λ��
    BOOL_TY bOpen;                 //�򿪻��߹رգ�true-�򿪣�false-�رգ�
}T_ALMOUT_CTRL_STRU, *LPT_ALMOUT_CTRL_STRU;

//��̨���ƽṹ
typedef struct
{
    CHAR_TY  chCtrlID[HANDLE_LENGTH];  //��̨���Ʋ������
    T_DEVID_INFO TDEVIDInfo;           //�豸ID��Ϣ
    INT_TY   nChannel;                 //ͨ���ţ�����ͨ���ţ����ǰ�λ����ģ�
    U_LONG_TY dwCtrlCMD;               //��̨���Ʋ�������
    U_CHAR_TY  byParam;                //����ֵ����ͬ�������Ӧͬ��ֵ��
    BOOL_TY  bStop;                    //ֹͣ��ʾ
}T_PTZ_CTRL_STRU, *LPT_PTZ_CTRL_STRU;

//��̨�߼�����
typedef struct
{
	CHAR_TY  chCtrlID[HANDLE_LENGTH];//��̨���Ʋ������
	T_DEVID_INFO TDEVIDInfo;         //�豸ID��Ϣ
	INT_TY   nChannel;               //ͨ����
	DWORD dwCtrlCMD;                 //��̨���Ʋ�������
	DWORD dwParam1;                  //����ֵ
	DWORD dwParam2;                  //����ֵ
	DWORD dwParam3;                  //����ֵ
	DWORD dwParam4;                  //����ֵ
	DWORD dwParam5;                  //����ֵ
	DWORD dwParam6;                  //����ֵ
}T_PTZ_CTRL_STRU_EX, *LPT_PTZ_CTRL_STRU_EX;


//��Ƶ�������ڽṹ
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;			//�豸ID��Ϣ
    INT_TY  nChannel;                   //ͨ���ţ�����ͨ���ţ����ǰ�λ����ģ�
    U_CHAR_TY byBrightness;             //����
    U_CHAR_TY byContrast;               //�Աȶ�
    U_CHAR_TY bySaturation;             //���Ͷ�
    U_CHAR_TY byHue;                    //ɫ��
}T_VIDEO_PARAM_STRU, *LPT_VIDEO_PARAM_STRU;

//�յ����ƽṹ
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;		  //�豸ID��Ϣ
    INT_TY nAddress;                  //�յ���ַ
    INT_TY nOpenClose;                //1�� 0��
    INT_TY nMode;                     //ģʽ 1�Զ� 2��ʪ 3���� 4����
    INT_TY nTemp;                     //�¶�
}T_ACPARAM_STRU, *LPT_ACPARAM_STRU;


//��������������ؽṹ
//��������
typedef struct
{
    unsigned char code;         //�����룺����������·��
    unsigned char subsystem;    //�����ţ�1-32
    unsigned short zone;        //�����ţ�1-512��������ʱ��Ч
} T_ALMHOST_CTRL_CMD, *LPT_ALMHOST_CTRL_CMD;

//���ƽṹ
typedef struct
{
    T_DEVID_INFO device;        //�豸ID��Ϣ
	unsigned int count;         //����������
	T_ALMHOST_CTRL_CMD cmds[1]; //���������б�
} T_ALMHOST_CTRL_STRU, *LPT_ALMHOST_CTRL_STRU;

//���ƻظ�
typedef struct
{
    unsigned char code;         //�����룺����������·��
    unsigned char subsystem;    //�����ţ�1-32
    unsigned short zone;        //�����ţ�1-512��������ʱ��Ч
	unsigned int error;         //�����룬0��ʾ�ɹ�
} T_AlARMHOST_CTRL;


//�豸״̬��ȡ�ṹ
typedef struct
{
    T_DEVID_INFO TDEVIDInfo;      //�豸ID��Ϣ
    INT_TY nChannel;              //ͨ���Ż��߶˿ںţ���λ��ʾ���ڼ�λ��1�ʹ���ڼ�ͨ��������ϣ���ȡ��Ƶ����ʱ���⣩��  
                                  //����ȡ��ͨ���޹ص�״̬ʱ������Ӳ�̡��豸���ߡ��豸���С��Ž�������״̬��ʱ���ò���Ϊ0���ɡ�  
}T_GET_DEV_STATE, *LPT_GET_DEV_STATE;

//������IP���˿ڡ�������Ϣ
typedef struct
{
	U_LONG_TY ulServerIP;  //IP
	U_LONG_TY Port;        //�˿ں�
	INT_TY ServerType;     //����������
}T_SERVER_INFO, *LPT_SERVER_INFO;

//�ͻ��������ṹ
typedef struct
{
    BOOL_TY bRecvTalk;      //���նԽ�����
}T_CLIENT_ABILITY, *LPT_CLIENT_ABILITY;


//������Ϣ�ṹ�����ÿͻ���ʹ�ã�
typedef struct
{
    int nCMDType;		  //��������Ϣ����
    unsigned long ulID;   //��Ӧ���ݿ��е�ID��Ψһ��
    int nLevel;			  //�ڵ�ȼ�
    char chCode[50];      //�ڵ���
    bool bIsExistFile;    //�Ƿ�����ļ�
    char chFileName[255]; //�ļ�����  
}T_CLIENT_REL_STRU, *LPT_CLIENT_REL_STRU;

//�ڵ����ͽṹ
typedef struct
{
    U_LONG_TY ulTypeID;
    INT_TY nLevel;
}T_NODETYPE_INFO, *LPT_NODETYPE_INFO;

//�ڵ���Ϣ�ṹ
typedef struct
{
	CHAR_TY    chNodeCode[20];            //�ڵ�ı�ţ����㡢�������������̽ͷ�����裩
    U_INT_TY   NodeType;                  //�ڵ�����ͣ��� TJTY_AREANODE_TYPE��
}T_NODEINFO_ADDMODDEL, *LPT_NODEINFO_ADDMODDEL;

//���ʹ�����޶���
typedef struct {
	char pcReserved1[8];		//Ԥ��λ(���ڴ��MN)
	char pcReserved2[16];		//Ԥ��λ(���ڴ�Ż�����)
	char pcSoftType[8];			//ģ���ƣ��� SJGL �����¼�����ģ�飬����ָʾkey�ļ����ļ���
	char pcSoftName[64];		//�������
	char pcUserName[64];		//�ͻ�����
	unsigned long dwSoftVersion;	//����汾���ƣ�-1��ʾ��ֹʹ�ã�0��ʾ�����ƣ��������ֱ�ʾ����ʹ�ø�����֮ǰ�İ汾
	long dwIsHaveLimit;				//�Ƿ�����������, 0��ʾ�����ƣ�1��ʾ������
	char pcEvaluateEndDate[16];		//ʹ�õ���ʱ�� ���� 20130102 ,��ʾ2013��1��2�յ���

} T_MODULE_PERIOD, *LPT_MODULE_PERIOD;

//MS��ʱ��ط�����
typedef struct {
	CHAR_TY chSessionID[SESSIONID_LENGTH];  //�ỰID
	T_DEVID_INFO tDevInfo;					//�豸��Ϣ
	T_TIME_INFO tStartTime;					//��ʼʱ��
	T_TIME_INFO tEndTime;					//����ʱ��
	INT_TY	nChannel;						//ͨ����
	CHAR_TY chOther[20];					//��������
} T_MODULE_TIMEVOD_MS_REQ, *LPT_MODULE_TIMEVOD_MS_REQ;

//MSת���ط��ճ�Ѳ��
typedef struct {
	int nMode;					   //2-ʱ��, ���඼���ļ���ʽ
	int flag;                      //0-���洢��-�洢
	int module;                    //1-�������ã�-�ճ�Ѳ�飻-�Ž���֤
	char guid[64];                 //������GUID
	char reserved[16];             //����
} T_MS_TRANS_PLAYBACK_RCXC, *LPT_MS_TRANS_PLAYBACK_RCXC;

/*****************************************************************************/
/************************�ṹ�嶨�����***************************************/
/*****************************************************************************/

//״̬���
//�û�Ԥ��״̬/�ط�/���ط���. 
typedef struct
{
    U_CHAR_TY DvrCode[DEV_ID_LENGTH];
    U_LONG_TY ulChannel;
    U_INT_TY  ViewType;       //ͼƬ\����\��Ƶ
    U_INT_TY  enTransmitType; //0�� ֱ�� 1�� ת�� 
	T_TIME_INFO   Time;		  //��ʼʱ�䡣
}T_VIEWSTRUCT;

//�Խ�״̬����
typedef struct
{
    U_LONG_TY TalkType;					//1:���豸�Խ���0:��ͻ��˶Խ�
	U_CHAR_TY DvrCode[DEV_ID_LENGTH];	//�豸��Ż����û���
	U_LONG_TY ulChannel;				//ͨ���Ż��û�IP��ַ
	U_LONG_TY UserType;					//�ͻ�������
}T_TALK_STATE;


//�豸״̬
//Ӳ��״̬
typedef struct
{
    CHAR_TY     Name[20];		//���̵����� ����C,D,E�� hard1��hard2 ��
	U_LONG_TY  ulVolume;		//Ӳ������
    U_LONG_TY  ulFreeSpace;		//Ӳ��ʣ��ռ� (MB)
    U_LONG_TY  ulHardDiskStatic;//Ӳ��״̬ 0�����1�����ߣ�2����������
}T_DISK_STATE;

//��������״̬
typedef struct
{
	U_LONG_TY ulchannel;	//ͨ����
	U_CHAR_TY ucbOnAlarm;	//1�� ����,0�� ����
	U_CHAR_TY ucbPass;		//0: ��·,1: û��·
	U_CHAR_TY ucbOnwork;	//0������������ 1���������� 
	U_LONG_TY ucGetOK;		//0:��ʾ�ɹ� ����Ϊ������
	U_CHAR_TY ucnoneed;     //����Ҫ��
}T_ALARMIN_STATE;

//¼��ͨ��״̬
typedef struct
{
    U_LONG_TY ulchannel;	//ͨ����
	U_CHAR_TY ucbinsignal;  //0�� ���źţ�1�� ���ź�
	U_CHAR_TY ucbRec;       //0��û¼��  1�� ��¼��
	U_CHAR_TY ucbOnwork;    //0������������ 1����������
	U_LONG_TY ucGetOK;		//0:��ʾ�ɹ� ����Ϊ������
	U_INT_TY  ulRecDay;		//����¼������
	U_CHAR_TY ucnoneed;     //����Ҫ��
}T_CHANNEL_STATE;

//��������״̬
typedef struct
{
	unsigned int    error;		// �����룬0��ʾ�ɹ�
	unsigned char   subsystem;	// �����ţ�1-32
	unsigned char   status;		// ����״̬��0-������1-����
	unsigned short  count;		// ����·�ķ�����Ŀ
	unsigned short  zones[1];	// ����·�ķ������б�
}T_ALARMHOST_STATE;

//�Ž�״̬
typedef struct
{
	unsigned int	error;			// �����룬0��ʾ�ɹ�
	unsigned int	status;			// ������״̬��0-����, 1-����, 2-����, 3-����
	char			reserved[8];	// �����ֶΣ�0
}T_ACCESS_STATE;

//���ƻظ�
typedef struct
{
	U_LONG_TY ulChannel;  //ͨ����
    BOOL_TY   ucok;       //���ƽ��
    U_CHAR_TY CtrlType;   // mask ctrl what.
	INT_32    ErrorNo;    //
}T_AlARMINOUT_CTRL;


//֪ͨMS��AS���ӻ�Ͽ���ĳ̨�豸�ķ�����豸�ṹ
typedef struct
{
	U_LONG_TY nEquipmentID;
	CHAR_TY   chEquipmentID[DEV_ID_LENGTH];
    U_INT_TY  LinkAc;//0:����Ͽ����ӣ�1:�÷�����ȥ���ӡ� 


	U_LONG_TY EDvrType;
	U_LONG_TY MainType;
	U_LONG_TY SubType;
	U_LONG_TY IP;//ʹ�����α�ʾIP
	U_LONG_TY port;
	CHAR_TY   LoginName[NAME_LENGTH];
	CHAR_TY   LoginPassWord[PASSWORD_LENGTH];
}T_DEV_TASK;

//DVRͨ��Ԥ�������豸�ṹ
typedef struct
{
    U_LONG_TY nDEVID;
	CHAR_TY chDEVID[DEV_ID_LENGTH]; 
	INT_TY  Channel;             //ͨ����
}T_DEVR_TICK, *LPT_DEVR_TICK;

//ý���������Ϣ
typedef struct
{
	CHAR_TY MSCode[20];  //ý����������
	U_LONG_TY ulIP;		 //ý��ip
	U_LONG_TY UplandNum; //�ϴ���Ƶ��
	U_LONG_TY TransNum;  //ת����Ƶ��
}T_MS_ONLINE_INFO;

//������������Ϣ
typedef struct
{
    CHAR_TY ASCode[20];
	U_LONG_TY ulASIP;  //����������IP
    //int nPort;       //�˿ں� 
}T_AS_STATE_INFO, *LPT_AS_STATE_INFO;

//ý���������Ϣ��չ
typedef struct
{
	CHAR_TY MSCode[20];  //ý����������
	U_LONG_TY ulIP;		 //ý��ip
	U_LONG_TY UplandNum; //�ϴ���Ƶ��
	U_LONG_TY TransNum;  //ת����Ƶ��
	int version;		 //�汾
	char reserved[28];
}T_MS_ONLINE_INFO_EX;

//������������Ϣ��չ
typedef struct
{
    CHAR_TY ASCode[20];
	U_LONG_TY ulASIP;  //����������IP
	int version;	   //�汾
	char reserved[36];
}T_AS_STATE_INFO_EX, *LPT_AS_STATE_INFO_EX;

//�ͻ�������㲥���ظ�ý��ṹ��Ϣ
typedef struct
{
    INT_TY VodSessionID[VODSESSIONIDLEN];
	U_LONG_TY ulServerIP; //ý���������IP
	U_LONG_TY Port;		  //�˿ں�
}T_VOD_RSE_SESSION;

//���Ŀͻ�����CMS֮��ͨ�Žṹ
typedef enum
{
	ADDAPP =0,
	DELAPP,
	CHANGEAPP
}APP_CHANGE_TYPE;

////////////////////////////////////////////////////////////
// ��Ƶ��Ϣ���

//��Ƶ�ۿ����ӷ�ʽ
typedef enum
{
	VIDEO_CMODE_TRANSMIT,		//ת��
	VIDEO_CMODE_DIRECT,			//ֱ��
} E_VIDEO_CONNECT_MODE;

//��Ƶ�ۿ�����
typedef enum
{
	VIDEO_TYPE_REALPLAY,		//ʵʱԤ��
	VIDEO_TYPE_PB_DEV,			//�ط��豸¼��
	VIDEO_TYPE_PB_STORE,		//�طŴ洢¼�񣨵㲥��
	VIDEO_TYPE_STORE,			//�洢
	VIDEO_TYPE_DL_DEV,			//�����豸¼��
	VIDEO_TYPE_DL_STORE,		//���ش洢¼��
} E_VIDEO_TYPE;

//�ͻ�����Ƶ��Ϣ
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

//ý����Ƶ��Ϣ
typedef struct
{
	char session[SESSIONID_LENGTH];
	int device;
	char channel;
	char type;  	// E_VIDEO_TYPE
	char stream; 	// E_STREAM_TYPE
	char reserved[5];

} T_VIDEO_INFO_MS;

//IP�Խ� ��ʼ�Խ�,����(MSG_REQ_IPT_CALL / MSG_REQ_IPT_MONITOR)
typedef struct
{
	U_INT_TY	cmd;		// ����1������2���Ҷ�3���ܾ�4(����ʱ��1��ʾ��ʼ������0��ʾֹͣ����)
	U_INT_TY	fromHost;	// cmd�����ն�ID
	U_INT_TY	fromPanel;	// cmd�������
	U_INT_TY	toHost;		// Ŀ���ն� ID
	U_INT_TY	toPanel;	// Ŀ�����
	char		reserved[12];	// ������0
} T_IPTALK_CALL;

//IP�Խ� �㲥��MSG_REQ_IPT_BROADCAST��
typedef struct
{
	U_INT_TY	cmd;		// ��ʼ�㲥1��ֹͣ�㲥0
	U_INT_TY	fromHost;	// �㲥�����ն�ID
	U_INT_TY	fromPanel;	// ����
	U_INT_TY	targetCount;	// ���չ㲥�ն˸�����ֹͣ�㲥ʱΪ0
	struct {
	U_INT_TY	targetHost;	// Ŀ���ն�ID
	U_INT_TY	targetPanels;	// Ŀ����壬ÿһλ����һ����壬0Ϊ�������
	} targets[1];
} T_IPTALK_BROADCAST;

//IP�Խ����ļ����ţ�MSG_REQ_IPT_FILEPLAY��
typedef struct
{
	U_INT_TY	cmd;		// ��ʼ����1��ֹͣ����
	U_INT_TY	fromHost;	// �ն�ID
	U_INT_TY	fromPanel;	// ����
	U_INT_TY	idx;		// �ļ�����
	char		reserved[48];	// ������0
} T_IPTALK_FILEPLAY;

//IP�Խ� �������ƣ�MSG_REQ_IPT_SET_VOL��
typedef struct 
{
	U_INT_TY	cmd;		// ����
	U_INT_TY	host;		// �ն�ID
	U_INT_TY	panel;		// ����
	U_INT_TY	vol;		// 0-100
	char		reserved[16];	// ������0
} T_IPTALK_SETVOL;

//IP�Խ� ����绰��MSG_REQ_IPT_PHONE��
typedef struct 
{
	U_INT_TY	cmd;		// ����1���Ҷ�0
	U_INT_TY	fromHost;	// �ն�ID
	U_INT_TY	fromPanel;	// ���
	U_INT_TY	toHost;		// Ŀ���ն� ID
	U_INT_TY	toPanel;	// Ŀ�����
	char		phone[20];	// �绰����
	char		reserved[24];	// ������0
} T_IPTALK_PHONE;

//�¼��ϱ�
typedef struct
{
	short		type;		// ����1��̽ͷ2������ͷ3���ֶ�4���Խ�5��
	short		event;		// �����¼�
	int			host;		// �ն�ID
	int			port;		// �ն˶˿ڻ����
	int			host2;
	int			port2;
	char		reserved[12];	// ������0
} T_NOTIFY_EVENT;

//�Ž�ϵͳ����¼�
typedef struct
{
	short	type;		// ����1���쳣2���Ž�3��
	short	event;		// �����¼�
	int		host;		// �Ž���ID
	int		reserved;	// ����
	int		extra;		//0-û�ж������ݣ�1-�Ž�����
} T_NOTIFY_EVENT_ACS;

// T_NOTIFY_EVENT_ACS.extra == 1ʱ����ϵ�����
typedef struct
{
	short	year;
	short	month;
	short	day;
	short	hour;
	short	minute;
	short	second;
	char	location[256];	//�¼��������Ž���
	char	user[64];		//�ֿ���
	char	card[64];		//����
	char	department[64];	//�ֿ��˲���
} T_NOTIFY_EVENT_ACS_EXTRA;

//������������¼�
typedef struct
{
	unsigned short	type;		// ��������1���Ӿ����2
	unsigned short	event;		// �����¼�(TJTY_EAC_ALMTYPE)
	unsigned int 	host;		// ����ID
	unsigned int 	subsystem;	// ������
	unsigned int 	zone;		// ������
	unsigned int 	extra;		// 0-û�ж������ݣ�1-�¼�����( TEventDescribe )
}T_NOTIFY_EVENT_ALARMHOST;

typedef struct
{
	char chEventDescription[100];   //�¼�����
}T_NOTIFY_EVENT_ALARMHOST_EXTRA;

//��Ƶ�豸����¼�
struct TVideoDevAlarm
{
   unsigned int	host;		// �豸ID
   unsigned int	event;		//0:�ޱ��� 1:Ӳ�̻� 2:Ӳ���� 3:���� 4:����
   unsigned char 	video[128]; 	//0:�ޱ��� 1:��Ƶ��ʧ 2:��Ƶ�ƶ� 3:��Ƶ�ڵ� ����ֵ:����ʶ�𱨾�
   unsigned char 	sensor[128]; 	//0:�ޱ��� 1:�б���
};


////////////////////////////////////////////////////////
// Ѳ���쳣�¼���Ϣ
struct TNotiEventPatrol
{
	short	type;			// EEventPatrolType
	short	event;			// EEventPatrolExcept
	T_TIME_INFO_EX	time;	// Ѳ��ʱ��
	int		host;			// �豸ID
	int		param;			// ������һ��ָͨ���ţ�0��ʾ����
							// 		��Ƶ�豸������ͷ��
							// 		���������ķ�����
							// 		Ӳ�̵ķ�����
	int		extra;			// �Ƿ�����չ���ݣ�0-û�У�1-��
};

// Ѳ���쳣�¼�����
enum EEventPatrolType
{
	PATROL_TYPE_ARM_STATE = 1,		// ������״̬
	PATROL_TYPE_CLOCK_STATE,		// ʱ��״̬
	PATROL_TYPE_DISK_STATE,			// Ӳ��״̬
	PATROL_TYPE_RECORD_STATE,		// ¼��״̬
	PATROL_TYPE_RECORD_DAYS,		// ¼������
	PATROL_TYPE_RECORD_INTEGRITY,	// ¼��������
	PATROL_TYPE_VIDEO_QUALITY,		// ��Ƶ�������
	PATROL_TYPE_NODE_STATE,			// ���ڵ�״̬
};

// ʱ��״̬�쳣��չ����
struct TPatrolExceptExtraClockState
{
	int timediff;	// ʱ���룩��������ʾʱ������
};

// ����״̬�쳣��չ����
struct TPatrolExceptExtraDiskState
{
	int total;		// ��������MB��
	int used;		// ��ʹ��������MB��
};

// ¼�������쳣��չ����
struct TPatrolExceptExtraRecordDays
{
	int days;		// ¼��������
};

// ¼���������쳣��չ����
struct TPatrolExceptExtraRecordIntegrity
{
	int	count;		// ¼��ȱʧʱ��ε�����
	struct {
	T_TIME_INFO	begin;		// ��ʼʱ��
	T_TIME_INFO	end;		// ����ʱ��
	} sections[1];
};

// ��Ƶ���������չ����
struct TPatrolExceptExtraVideoQuality
{
	char	pictureID[32];		// ͼƬ�洢���ļ��������е�ID
};

// ���ڵ�״̬�쳣����
struct TPatrolExceptExtraNodeState
{
	double			usage;			//ʹ����
	unsigned int	total;			//������CPU-�ޣ��ڴ�-MB������-MB��
	unsigned int	data1;			//����
	unsigned int	data2;			//����
	unsigned int	data3;			//����
	char			reserved[8];	//����
};

// ƽ̨�Ĵ�������¼�
struct TEvtPlatDisk
{
	T_TIME_INFO	time;		// ʱ��
	char		addr[20];	// IP��ַ
	char		name[20];	// �����¼��
	int			module;		// �������
	int			event;		// 1-����������2-������
	char		reserved[56];	// ������0
};


// ��Ƶ�����ļ�֪ͨ
struct TEventMediaFile
{
	char guid[64];			// ����GUID�ַ���
	char devName[64];		// �豸����
	char camName[64];		// ����ͷ����
	int devType;			// �豸���ͣ��μ�TjtyNet��Ķ���
	int fileType;			// �ļ����ͣ�1-ͼƬ��2-��Ƶ
	long fileSize;			// �ļ���С���ֽ�
	int reserved;			// ������0
	T_TIME_INFO begin;		// ��ʼʱ��
	T_TIME_INFO end;		// ����ʱ�䣬�����ͼƬ�ÿ�
	char filePath[200];		// �ļ�����·��
};

// ��Ƶ�����ļ�֪ͨ��չ
struct TEventMediaFileEx
{
	char guid[64];			// ����GUID
	char devName[64];		// ������0
	char channelName[64];	// ͨ������
	int devType;			// ������0
	int fileType;			// �ļ����ͣ�1-ͼƬ��2-��Ƶ��3-��Ƶ
	long fileSize;			// ������0
	int flag;				// ��־λ��bit1-ɾ��λ��0-��ɾ����1-����ɾ����
	T_TIME_INFO begin;		// ��ʼʱ��
	T_TIME_INFO end;		// ����ʱ��
	char filePath[200];		// �ļ�����·��
	char planGuid[64];		// Ԥ��GUID
	char actionGuid[64];	// ����GUID
	long processId;			// ������¼ID
	char reserved[64];		// ������0
};

// ģ���״̬����
/*
���е�״̬�붨�����£�
41	����������
42	��ʱδ�յ��κ��ļ�
43	��������������Ϊ�ر�
44	��ʱδ���κ��ļ��洢����
*/
struct TEventStateReport
{
	int	state;				// ״̬�룬0��ʾ������������ʾ�쳣
	char moduleName[64];	// ģ�����ƣ���ý�������
	char moduleCode[16];	// ģ����ţ���MS
	char reserved[428];		// ������0
};


//Client����ƽ̨����һ���豸����
struct TDeviceTroubleRepairToKoala
{
	int  msg;				// ��Ϣ���ͣ��̶�ֵ��100001��
	int  state;				// ά��״̬
	char guid[64];			// ���ϵ���
	char number[40];		// �豸���
	char devicetype[40];	// �豸����
	char maintype[40];		// ����
	char subtype[40];		// �ͺ�
	char area[40];			// ��������
	char maintenance[40];	// ά����
	char telephone[40];		// ά���绰
	char troubletype[40];	// ��������
	char troubles[256];		// ��������
	char describe[256];		// ��������
	char reserved1[40];		// Ԥ��1 
	char reserved2[40];		// Ԥ��2
};


//�ֶ�����
//�ýṹ�Ǳ��������򱨾�������ת������ƽ̨�ı�����Ϣ��������������ͻ���ת������ԭ�б�������Э�飬�˴����ٶ��塣
struct TNewAlarmToZONEE
{
	int  msg;				// ��Ϣ���ͣ��̶�ֵ��201004��
	char guid[64];			// ����Ψһ��ʶ
	char number[64];		// �豸���
	int  type;				// ��������ֵ
	int  level;				// �����ȼ�
	char alarmtype[40];		// ��������
	char time[40];			// ��������ʱ��
	char locate[64];		// �����ص�
	char describe[256];		// ����
	char files[256];		// ������
	char user[40];			// ������
};



//���ÿͻ���ת���޸�Ԥ�����������¼���Ϣ
struct TAlarmPlan_ModelInfo_Syn
{
    INT_TY  msgid;// ��ϢID	223001
    CHAR_TY guid[128];
    INT_TY  nActionType; //1-��� 2-�޸� 3-ɾ��
    INT_TY  nModelType;  //1-���� 2-�¼� 3-Ԥ��

};

/* ��Ѻϵͳ��� - ��ʼ */

//������Ϣ
struct TSyCar
{
	char number[20];		// ���ƺ�
	char idCard[20];		// ֤����
	char cardTagNo[20];		// ���ӱ�ǩ����
};

//��Ա��Ϣ
struct TSyPerson
{
	int id;					// ID
	char sid[20];			// ���֤��
	char name[20];			// ����
};

//��Ա����
enum ESyPersonType
{
	SY_PERSON_TYPE_DRIVER = 1,		// ��ʻԱ
	SY_PERSON_TYPE_BUSINESS,		// ҵ��Ա
	SY_PERSON_TYPE_GUARD,			// Ѻ��Ա
};

//�Ű���Ϣ
struct TSyScheduleInfo
{
	char time[20];			// Ԥ������ʱ��hh:mm
	TSyCar car;				// ����
	int personCount;		// ��Ա��
	struct {
		int personType;		// ��Ա����
		TSyPerson person;	// ��Ա��Ϣ
	} persons[10];
};

//�Ű���Ϣ�б�
struct TSyScheduleList
{
	int count;
	TSyScheduleInfo info[1];
};

//��ȡͼƬ����
struct TSyGetImage
{
	int userId;				// �û�id
	char photoId[20];		// ��Ƭid
	char vehicleNo[20];		// ���ƺ�
	int imageType;			// ͼƬ���ͣ�1 ��ʾ������Ա��Ƭ,userId
							//     2 ��ʾ��������ʵʱ����ʶ��ʱ����Ƭ��ʹ��userId��photoId
							//     3 ��ʾ���س�����Ƭ����ͨ��2�ַ�ʽ��ȡ��Ƭ���г��ƺ�����ʹ�ó��ƺ�����ȡ������Ƭ
							//         a)ʹ��photoId����������Ϊ������ǩ����; b)ʹ��vehicleNo���ƺ�
							//     4 ��ʾ��������3��������֤��ͨ����������Ƭ, ʹ��photoId����
};

//ͼƬ
struct TSyImageId
{
	char imageId[32];		// ͼƬ�洢���ļ��������е�ID
};

//Ѻ��״̬
struct TSyRouteStatus
{
	int orgId;					//����id
	char orgName[32];			//��������
	int orderNo;				//·���и�����Ԥ����˳���
	int passed;					//�������Ƿ��Ѿ��߹���0:��δ�߹� 1:�Ѿ��߹�
	int actualOrderNo;			//·���и�����ʵ�ʵ�˳���
	T_TIME_INFO arriveTime;		//ʵ�ʵ���ʱ��
	int arriveTimeStatus;		//����ʱ���Ƿ����� 0������ 1����΢�쳣 2�������쳣
};

//Ѻ��·��״̬
struct TSyRouteList
{
	int count;
	TSyRouteStatus route[1];
};

//��ȡ���ӱ�ǩ����ϸ��Ϣ����
struct TSyGetTagData
{
	int orgId;					//��֯����id������id
	int getType;				//��ȡ���ӱ�ǩ����ϸ��Ϣ�ķ�ʽ
								//    1����ȡ���е��ӱ�ǩ����Ϣ
								//    2��ֻ��ȡ��ǰ������صĵ��ӱ�ǩ����Ϣ
								//    3��ֻ��ȡ����ָ���ĵ��ӱ�ǩ������Ϣ
	int count;					//���ӱ�ǩ������
	struct {
		char tagId[20];			//���ӱ�ǩ��id
	} tagList[1];				//���ӱ�ǩ���б�
};

//���ӱ�ǩ����Ϣ
struct TSyTagData
{
	char name[32];			//���ֻ��ţ����ƺ�
	int type;				//1������  2������
	char driver[20];		//type=2ʱΪ��ʻԱ
	char tagId[20];			//���ӱ�ǩ��id
};

//���ӱ�ǩ����Ϣ�б�
struct TSyTagDataList
{
	int count;
	TSyTagData tagData[1];
};


//��Ѻ������Ϣ��أ�TEscortAlarmΪ������Ϣ���͵�AS
typedef struct tCashbox{
	char	ashboxName[32];	//������
	char	tagNo[32];		//����ĵ��ӱ�ǩ����
	T_TIME_INFO	time;		//��⵽���ӱ�ǩ����ʱ��
}TCashbox;

typedef struct tEscortCar{
	char	vehicleNo[32];		//���ƺ�
	char	tagNo[32];		//���ĵ��ӱ�ǩ����
	T_TIME_INFO	time;		//��⵽���ӱ�ǩ����ʱ��
	int	valid;			//���Ƿ�Ϲ� 0���Ϲ� 1�����Ϲ�
}TEscortCar;

typedef struct tEscortPerson{
	int	userId;			//�û�ID
	T_TIME_INFO	time;		//ʵ��ˢ��ʱ�� yyyy-mm-dd hh:mm:ss
	char	name[32];		//ʵ��ˢ����Ա����
	char	type[32];		//��Ա���ͣ��硰Ѻ��Ա��
	char	typeCode[8];		//��Ա���ʹ��� ��ֵ:��Ա����� 10:��ʽԱ��  40:Ѻ����Ա  50:������Ա  80:������Ա  ����code��������
	char	photoId[32];		//����3��������֤��ͨ��ʱ���ò����Ż���ֵ
	char	sid[32];			//���֤��
	int	valid;			//��Ա�Ƿ�Ϲ� 0���Ϲ� 1�����Ϲ�
	int	arrivedtimestatus;	//����ʱ���Ƿ����� 0������ 1����΢�쳣 2�������쳣
}TEscortPerson;

typedef struct tEscortAlarm
{
	int		host;	//ƽ̨�豸ID
	int		channelNo;
	int		organizationID;		//����ID
	char	organizationName[32];	//��������
	char		deviceNo[32];		//�豸�ţ����������Ϊ����ʶ���ǵ��豸�ţ�����ǳ��Ϳ��䣬��Ϊ��Ƶ��д�����豸��
	int		dataType;		//0:����������֤  organizationid  deviceno  person��Ч����photoid��ֵ
						//1:����3��������֤��ͨ����organizationid  deviceno  person��Ч��photoid��ֵ����ϵͳ��ʱ������һ��id�ţ�����2�ӿ�ȥ��ȡ��ʱ��������Ƭ
						//2:����ʶ���ǲ������, ֻ��deviceno��Ч
						//3:����ʶ�����쳣����, ֻ��deviceno��Ч
						//4:����ʶ����ɾ������, ֻ��deviceno��Ч
						//10:��Ա�䶯  userid name sid��Ч
						//11:�����䶯  vehicleno,tagno, status, oldvehicleno, oldtagno ��Ч
						//12:����䶯  tagno, cashboxname, status, oldtagno, oldcashboxname��Ч
						//20:������Ϣ  organizationid  deviceno  car��Ч
						//30:������Ϣ  organizationid  deviceno  cashbox��Ч

	TEscortPerson	person;			//��Ա��Ϣ
	TEscortCar	car;			//����Ϣ
	TCashbox	cashbox;		//������Ϣ

	char		vehicleNo[32];		//���ƺ�
	char		tagNo[32];		//���ӱ�ǩ����(�������)
	char		ashboxName[32];	//������
	int		status;			//��(��)��״̬ 0����Ч 1����Ч 2��������ɾ��
	char		oldVehicleNo[32];	//ԭ���ĳ��ƺ�
	char		oldTagNo[32];		//ԭ���ĵ��ӱ�ǩ����(�������)
	char		oldCashboxName[32];	//ԭ���Ŀ�����
} TEscortAlarm;

/* ��Ѻϵͳ��� - ���� */

#endif 