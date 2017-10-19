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
	TY_SUCCESS                        = 0x0 //����
}SUCCESS_CODE;
//-----------------------------------------------------------------------------
/**************************************************
 **           Error code from device'sdk               **
 **************************************************/
typedef enum
{
	TY_NET_NO_INIT_ERROR                  =0x1,	  //δ��ʼ��SDK���߳�ʼ��ʧ��
	TY_NET_TCP_ERROR                      ,   //���罻���쳣
	TY_NET_BACK_ERROR                     ,   //����ķ���
	TY_NET_UNKNOWN_ERROR                  ,   //δ֪����
	TY_NET_NOSUPPORT_ERROR                ,   //��֧�ִ˹���
	//��¼�йصĴ�����Ϣ
	TY_NET_NAMEORPWD_ERROR                ,   //��¼�û������������
	TY_NET_NAME_FORBID_ERROR              ,   //��¼�û���������
	TY_NET_NAME_BUSY_ERROR                ,   //��¼�û�������ʹ��
	//-----------------------------------------------------------------------------
	//�����йصĴ�����Ϣ
	TY_NET_NOLOGIN_ERROR                  ,  //û�е�¼
	TY_NET_NOLEVEL_ERROR                  ,  //û��Ȩ��
	TY_NET_PARA_ERROR_ERROR               ,  //��������
	TY_NET_NOFILE_FIND_ERROR              ,  //û�м������ļ�
	TY_NET_NOSUFFICIENTMEMORY_ERROR       ,  //�ڴ治��
	TY_NET_ISFINDING_ERROR                ,  //���ڼ���
	TY_NET_ISMULTITALK_ERROR              ,  //����Ⱥ��
	TY_NET_ISGETTING_ERROR                ,  //���ڻ�ȡ�У���Ҫ����ͼ���Ĳ�����ȡ��
	TY_NET_NOTREALPLAY_ERROR              ,  //û��Ԥ��
	TY_NET_NOTREMOTEPLAY_ERROR            ,  //û���ڻط�
	TY_NET_NOTTALK_ERROR                  ,  //���ڶԽ���
    TY_NET_OPEN_MIC_ERROR                 ,  //����Ƶʧ��
	//-----------------------------------------------------------------------------
	//�쳣��Ϣ����
	TY_NET_EXCEPTION_EXCHANGE_ERROR       , //�û������쳣
	TY_NET_EXCEPTION_PREVIEW_ERROR        , //����Ԥ���쳣
	TY_NET_EXCEPTION_PLAYBACK_ERROR       , //����ط��쳣
	TY_NET_EXCEPTION_ALARM_ERROR          , //�����쳣
	TY_NET_EXCEPTION_AUDIOEXCHANGE          //�����Խ��쳣
}DEVICE_NET_ERROR_CODE;

//-----------------------------------------------------------------------------
/**************************************************
 **           ���ſ������	               **
 **************************************************/
typedef enum
{
	TJTY_PLAY_NOERR 	 					 =0x0,		//û�д���
	TJTY_PLAY_NO_INIT_ERROR                  =0x100,	  	//δ��ʼ��SDK���߳�ʼ��ʧ��
	TJTY_PLAY_NOTSUPPORT,									//��֧�ִ˹���
	TJTY_PLAY_INIT_ERROR,									//��ʼ��ʧ��
	TJTY_PLAY_INVALID_PARAM,								//����Ĳ���
	TJTY_PLAY_BUFFER_FULL,									//�������������޷�������
	TJTY_PLAY_NOENOUGH_MEMORY,								//�ڴ治��
	TJTY_PLAY_PORT_USED,									//�ô��ں��Ѿ���ʹ��
	TJTY_PLAY_INVALID_PORT,									//��Ч�Ĵ��ں�
	TJTY_PLAY_DECODE_ERROR,									//����ʧ��
	TJTY_PLAY_RENDER_FAILED,								//��Ⱦʧ��
	TJTY_PLAY_OP_FAILED,									//���ţ�ֹͣ����ͣ�Ȳ���ʧ��
	TJTY_PLAY_WRONG_BUFTYPE,								//����Ļ�������
	TJTY_PLAY_CALLORDER_WRONG,								//����ĵ���˳��

	TJTY_PLAY_UNKNOWNERR					   =0x1FF,		//δ֪����
			
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
	TY_NOTALK_ERROR						,	//not in talk��
	
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
	TY_SERVER_MEMROY_ERROR			=	0x1000,       //�����ڴ����
	TY_SERVER_PARA_ERROR			,       //��������
	TY_SERVER_SDK_HAD_INIT_ERROR	,       //�ظ���ʼ��SDK
	TY_SERVER_SDK_NO_INIT_ERROR		,       //δ��ʼ��SDK
	TY_SERVER_INIT_NET_ERROR		,       //��ʼ���������
	TY_SERVER_SOCK_CONNECT_ERROR	,		//�����׽��ִ���
	TY_SERVER_SOCKET_INVALID_ERROR  ,		//�׽�����Ч
	TY_SERVER_NET_BLOCK_ERROR		,       //��������
	TY_SERVER_TIME_OUT_ERROR		,       //��ʱ
	TY_SERVER_SEND_DATA_FAIL_ERROR	,		//��������ʧ��
	TY_SERVER_RECV_DATA_FAIL_ERROR	,		//��������ʧ��
	TY_SERVER_BACK_ERROR_ERROR      ,		//��������  
	TY_SERVER_THREADPOOL_FULL_ERROR ,		//�̳߳��������ﵽ���ֵ��
	TY_SERVER_HAD_LOGIN_ERROR       ,		//�ظ���¼���Ĺ��������  
	TY_SERVER_NO_LOGIN_ERROR        ,		//δ��¼���Ĺ�������� 
	TY_SERVER_CREATE_EVENT_ERROR	,		//�����¼�����
	TY_SERVER_WAIT_EVENT_ERROR		,		//�ȴ��¼�ʧ��
	TY_SERVER_CALLBACK_NULL_ERROR   ,		//δ���ûص�����
	TY_SERVER_HAD_LINKED_ERROR      ,		//�ظ����� 
	TY_SERVER_NOT_TRANS_LINK_ERROR  ,		//����ת�����ӷ�ʽ
	TY_SERVER_IS_SEARCHING_ERROR    ,		//���ڼ����ļ�
	TY_SERVER_INVALID_HANDLE_ERROR  ,		//��Ч�ľ��
	TY_SERVER_NO_SUPPORT_ERROR      ,		//��֧�ָù���
	TY_SERVER_NOENOUGHPRI_ERROR     ,		//Ȩ�޲��� 
	TY_SERVER_IS_TALKING_ERROR      ,		//���ڶԽ�����Ⱥ��
	TY_SERVER_OPEN_MIC_ERROR		,		//����Ƶ�ɼ�ʧ��
	TY_SERVER_OPEN_FILE_FAIL_ERROR	,		//���ļ�ʧ��
	TY_SERVER_SOCKET_BIND_ERROR		,		//���׽���ʧ��
	TY_SERVER_OPENMIC_ERROR      			//����Ƶ�ɼ�ʧ��
}SERVER_SDK_ERRORCODE;
/**************************************************
** the error From Appserver
**************************************************/
typedef enum
{   
	TY_APP_SDK_HAD_CONNECTED_ERROR      = 0x1400,		//�Ѿ�����   
	TY_APP_SDK_MEMROY_ERROR_ERROR       ,				//�����ڴ����
	TY_APP_SDK_SOCK_CONNECT_ERROR		,				//�����׽���ʧ��
	TY_APP_SDK_SEND_ERROR				,				//��������ʧ�� 
	TY_APP_SDK_RECV_ERROR				,				//��������ʧ��  
	TY_APP_SDK_BACK_ERROR				,				//����ʧ��
	TY_APP_SDK_CREATETHREAD_ERROR		,				//�����߳�ʧ��
	TY_APP_SDK_PARA_ERROR				,				//�������� 
	TY_APP_SDK_NO_CONNECT_ERROR         ,				//��δ����APP������   
	TY_APP_SDK_CREATE_EVENT_ERROR		,				//�����¼�ʧ��
	TY_APP_SDK_WAIT_EVENT_ERROR			,				//�ȴ��¼����� 
	TY_APP_SDK_BACK_MSG_ERROR			,				//�������� 
	TY_APP_SDK_QUERY_NO_RESULT_ERROR    ,				//δ��ѯ����Ӧ�Ľ��
	TY_APP_SDK_QUERY_NOT_SUPPORT_ERROR  ,				//��֧�ָò�ѯ����
	TY_APP_SDK_QUERY_EXCEPTION_ERROR    ,				//APP�����������쳣
	TY_APP_SDK_LINK_SQLSERVER_FAIL_ERROR ,				//APP�������������ݿ�ʧ��
	TY_APP_SDK_UNKNOW_ERROR_ERROR        ,				//δ֪����
	TY_APP_SDK_LOGINKEY_ERROR			 ,				//LogInKey��֤ʧ��

	//use in client
	TY_RPCOUTWORK_ERROR					,				//RPC �����������á�
	TY_COMMOND_ERROR					,               //�������
	TY_IPMULI_ERROR						,				//����豸ʱip��ַ�ظ���
	TY_NAMEMULTI_ERROR					,               //�����ظ���
	TY_CHANLEMULTI_ERROR				,				//ͨ���Ѿ����ڡ�
	TY_NOTHISMODEL_ERROR				,				//�޴˴��ͺš�
	
}APP_ERRORCODE;	

#endif
