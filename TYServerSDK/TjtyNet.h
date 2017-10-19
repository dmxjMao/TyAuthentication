#ifndef TjtyNetH
#define TjtyNetH
//-----------------------------------------------------------------------------
#ifdef TJTY_NET
#define TJTY_NET_API extern "C" __declspec(dllexport)
#else
#define TJTY_NET_API extern "C" __declspec(dllimport)
#endif
//-----------------------------------------------------------------------------
#include "TjtyCommon.h"
#include "ErrorCode.h"
//-----------------------------------------------------------------------------
/*************************�����ĺ궨��****************************************/
//----------------------------------------------------------------------------
#define TJTY_NET_MAXDISKNUM                    16   //Ӳ��������
//----------------------------------------------------------------------------
#define TJTY_NET_SYSHEAD                       0    //ϵͳͷ����
#define TJTY_NET_STREAMDATA                    1    //����Ƶ���������
#define TJTY_NET_VIDEODATA                     2    //��Ƶ������
#define TJTY_NET_AUDIODATA                     3    //��Ƶ������
#define TJTY_NET_NAME_LEN                      40  //���ֳ���
#define TJTY_NET_PASSWD_LEN                    20  //���볤��
#define TJTY_NET_SERIALNO_LEN                  50 //���кų���
#define TJTY_NET_VERSION_LEN                   40 //�汾�ų���
#define TJTY_NET_DVRTYPE_LEN                   20 //DVR ���ͳ���
#define TJTY_NET_DVRSUBTYPE_LEN                20 //DVR �����ͳ���
#define TJTY_NET_MAX_ETHERNET	               2  //�豸������̫����
#define TJTY_NET_MACADDR_LEN                   20 //mac��ַ����
#define TJTY_NET_IPADDR_LEN                    20 //IP ��ַ����
#define TJTY_NET_PATHNAME_LEN	               128 //·������
#define TJTY_NET_MAX_ALARMOUT                  8   //�������������
#define TJTY_NET_MAX_ALARMIN                   16  //��������������
#define TJTY_NET_MAX_DAYS                      7   //�������
#define TJTY_NET_MAX_TIMESEGMENT               4   //���ʱ�����
#define TJTY_NET_MAX_CHANNUM                   64  //���ͨ����
#define TJTY_NET_MAX_EXCEPTIONNUM              16  //�豸����쳣������
#define TJTY_NET_MAX_DISKNUM	               16  //�豸���Ӳ����
#define TJTY_NET_MAX_CRUPIONT                  32  //��̨Ѳ��·���������
//#define TJTY_NET_MAX_DAYS  7
//#define TJTY_NET_MAX_TIMESEGMENT  8
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*****************************************************************************/

//-----------------------------------------------------------------------------
/*************************�ص�����ԭ�Ͷ���************************************/
//-----------------------------------------------------------------------------
/*-----------------------------------------------------------------------------
	���ݻص���������
	lRealHandle:�������;
	dwDataType:��������(0--ͷ�ļ�������, 1--��Ƶ��������);
	pBuffer:���ݴ洢����ͷָ��;
	dwBufSize:�������ݴ�С;
	dwUser:�û�����
-----------------------------------------------------------------------------*/
typedef void (__stdcall *TJTY_NET_DataCallBack)( long lPlayHandle,
                                                DWORD dwDataType,
                                                const BYTE *pBuffer,
                                                DWORD dwBufSize,
                                                DWORD dwUser);
//ͼ���ط����ݿ��ƻص�����
//�ú���ֻ����Զ�̻ط�ͼ��������¼��ʱ��Ч��SDK�����ݵ���ʱ����һ�δ˻ص�������
//���˻ص���������TRUEʱ��SDK�������ݸ�Ӧ�ó���
//����������FALSEʱ��SDK����ͣ�����ݸ�Ӧ�ó���
//����ɸ��ݸñ���ͨ���е������Ƿ��㹻�������Ƿ�ҪSDK�����ݸ�Ӧ�ó���
//��û��ע��˻ص���������SDK�᲻ͣ�������ݸ�Ӧ�ó��򣬻ᵼ��Զ�̻ط�ʱ�����
typedef bool (__stdcall *TJTY_NET_RemoteRecDataCallBack_TM)(long lPlayID, DWORD dwUser);
//----------------------------------------------------------------------------
//������Ϣ�ص�
typedef void(__stdcall *TJTY_NET_ALARM_MSG_CALLBACK )(long lUserID, void *buf,
                                                      DWORD length, DWORD dwUser);

//----------------------------------------------------------------------------
//�ļ��б�ص�����
typedef void(__stdcall *TJTY_NET_FileList_CALLBACK )(long lUserID, void *buf,
                                                     DWORD length, DWORD dwUser);
//----------------------------------------------------------------------------
//�����Խ��ص�����
typedef void(__stdcall *TJTY_NET_VoiceData_CALLBACK)(long lTalkID,
                                                     BYTE  *pRecvDataBuffer,
                                                     DWORD  dwBufSize,
                                                     BYTE   byAudioFlag,
                                                     DWORD  dwUser);
//----------------------------------------------------------------------------
//��־�б�ص�����
typedef void(__stdcall *TJTY_NET_LogInfo_CALLBACK)(long lUserID, void *buf,
                                                    DWORD length, DWORD dwUser);
//----------------------------------------------------------------------------
//�쳣�ص�����
typedef void(__stdcall *TJTY_NET_ExceptionMsg_CALLBACK)(long lCommand,  //�쳣��Ϣ����
                                                        long lUserID,   //�û�ID
                                                        long lHandle,   //��Ӧ�Ĳ������
                                                        DWORD dwUser);
//�����豸�ص�����
typedef void(__stdcall *TJTY_NET_SearchDevice_CALLBACK)(void *buf);
//----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
/*************************���ݽṹ����****************************************/
//-----------------------------------------------------------------------------
//��ȡ��������ö������
typedef enum
{
    TJTY_NET_GET_DEVICECFG = 100,    //��ȡ�豸������Ϣ
    TJTY_NET_GET_NETCFG,             //��ȡ�������
    TJTY_NET_GET_PICCFG,             // ��ȡͼ�����
    TJTY_NET_GET_VILOST,             // ��ȡ��Ƶ��ʧ����
    TJTY_NET_GET_MOTION,             //��ȡ�ƶ���ⱨ������
    TJTY_NET_GET_HIDEALARM,         //��ȡ��Ƶ�ڵ�����
    TJTY_NET_GET_RECORDCFG,         //��ȡ¼�����ò���
    TJTY_NET_GET_ALARMINCFG,        //��ȡ�����������
    TJTY_NET_GET_ALARMOUTCFG,       //��ȡ�����������
    TJTY_NET_GET_EXCEPTIONCFG,      //��ȡ�쳣�澯��Ϣ����
    TJTY_NET_GET_SYYTEMTIME         //��ȡDVRϵͳʱ��
}TJTY_NET_GETCFG;
//-----------------------------------------------------------------------------
//���ò�������ö������
typedef enum{
    TJTY_NET_SET_DEVICECFG = 200,    //�����豸������Ϣ
    TJTY_NET_SET_NETCFG,             //�����������
    TJTY_NET_SET_PICCFG,             //����ͼ�����
    TJTY_NET_SET_VILOST,             //���û�ȡ��Ƶ��ʧ����
    TJTY_NET_SET_MOTION,             //�����ƶ���ⱨ������
    TJTY_NET_SET_HIDEALARM,         //������Ƶ�ڵ�����
    TJTY_NET_SET_RECORDCFG,         //����¼�����ò���
    TJTY_NET_SET_ALARMINCFG,        //���ñ����������
    TJTY_NET_SET_ALARMOUTCFG,       //���ñ����������
    TJTY_NET_SET_EXCEPTIONCFG,      //�����쳣�澯��Ϣ����
    TJTY_NET_SET_SYYTEMTIME         //����DVRϵͳʱ��
}TJTY_NET_SETCFG;
//-----------------------------------------------------------------------------
//��̨��������ö��
typedef enum{
    TJTY_NET_LIGHT_PWRON = 400,   // ��ͨ�ƹ��Դ
    TJTY_NET_WIPER_PWRON,         //��ͨ��ˢ����
    TJTY_NET_FAN_PWRON,           //��ͨ���ȿ���
    TJTY_NET_HEATER_PWRON,        //��ͨ����������
    TJTY_NET_AUX_PWRON,           //��ͨ�����豸����
    TJTY_NET_ZOOM_IN,             //�����Ա��(���ʱ��)
    TJTY_NET_ZOOM_OUT,            //�����С(���ʱ�С)
    TJTY_NET_FOCUS_IN,            //����ǰ��
    TJTY_NET_FOCUS_OUT,           //������
    TJTY_NET_IRIS_ENLARGE,        //��Ȧ����
    TJTY_NET_IRIS_SHRINK,         //��Ȧ��С
    TJTY_NET_TILT_UP,             //��̨����
    TJTY_NET_TILT_DOWN,           //��̨����
    TJTY_NET_PAN_LEFT,            //��̨��ת
    TJTY_NET_PAN_RIGHT,           // ��̨��ת
    TJTY_NET_UP_LEFT,             //��̨����
    TJTY_NET_UP_RIGHT,            //��̨����
    TJTY_NET_DOWN_LEFT,           //��̨����
    TJTY_NET_DOWN_RIGHT,          //��̨����
    TJTY_NET_PAN_AUTO             //�����Զ�ɨ��
}TJTY_NET_PTZCTRL_CMD;
//-----------------------------------------------------------------------------
//Ԥ��λ��������ö������
typedef enum{
    TYJTY_NET_SET_PRESET = 300,  //����Ԥ�õ�
    TYJTY_NET_CLE_PRESET,        //���Ԥ�õ�
    TYJTY_NET_GOTO_PRESET       //ת��Ԥ�õ�
}TJTY_NET_PTZPRESET_CMD;
//-----------------------------------------------------------------------------
//Ѳ����������ö������
typedef enum{
    TJTY_NET_FILL_PRE_SEQ = 310, //��Ԥ�õ����Ѳ������
    //TJTY_NET_SET_SEQ_DWELL,     //����Ѳ����ͣ��ʱ��
    //TJTY_NET_SET_SEQ_SPEED,     //����Ѳ���ٶ�
    TJTY_NET_CLE_PRE_SEQ,       //��Ԥ�õ��Ѳ��������ɾ��
    TJTY_NET_CLE_SEQ,           //���Ѳ��·��
    TJTY_NET_RUN_SEQ,           // ��ʼѲ��
    TJTY_NET_STOP_SEQ           // ֹͣѲ��
}TJTY_NET_PTZCRU_CMD;
//-----------------------------------------------------------------------------
//��̨�켣��������ö������
typedef enum{
    TJTY_NET_STA_MEM_CRUISE = 320,  //��ʼ��¼�켣
    TJTY_NET_STOP_MEM_CRUISE,       //ֹͣ��¼�켣
    TJTY_NET_RUN_CRUISE,             //��ʼ���й켣
    TJTY_NET_STOP_CRUISE             //ֹͣ�켣
}TJTY_NET_PTZTRACK_CMD;
//----------------------------------------------------------------------------
//���ܱ������Ͷ���
typedef enum{
    TJTY_NET_DETECT_EVENT_NOWARN = 0x0000,          //û�б���
    TJTY_NET_DETECT_EVENT_VIDEO_ERROR = 0x001E,	         	//30�� ��Ƶ�ź��쳣
    TJTY_NET_DETECT_EVENT_PTZ_TARGETLOSS,			//31, PTZ����Ŀ�궪ʧ
    TJTY_NET_DETECT_EVENT_OBJ_REMOVED,				//32, ��Ʒ����
    TJTY_NET_DETECT_EVENT_OBJ_LEAVE,				//33, ��Ʒ����
    TJTY_NET_DETECT_EVENT_PARKING,				//34, ͣ��
    TJTY_NET_DETECT_EVENT_PERIMETER,				//35, ������
    TJTY_NET_DETECT_EVENT_ABNORMALVEL,				//36, �������ٶȣ��ƶ���
    TJTY_NET_DETECT_EVENT_CONVERSE,				//37������
    TJTY_NET_DETECT_EVENT_TRIPWIRE,				//38, ������
    TJTY_NET_DETECT_EVENT_LOITER,				//39, �й�
    TJTY_NET_DETECT_EVENT_SLIPUP,				//40, ����
    TJTY_NET_DETECT_EVENT_SOLDIER,				//41, �ڱ��쳣
    TJTY_NET_DETECT_EVENT_FIGHT,				//42, ���
    TJTY_NET_DETECT_EVENT_MUTITRIPWIRE,				//43, �ྯ����
    TJTY_NET_DETECT_EVENT_MLOITER,				//44, �����й�
    TJTY_NET_DETECT_EVENT_FIRE,					//45, ����
    TJTY_NET_DETECT_EVENT_MOKE,					//46, ����
    TJTY_NET_DETECT_EVENT_DENSITY,				//47, Ⱥ���¼���ӵ����
    TJTY_NET_DETECT_EVENT_CLUSTER,				//48, Ⱥ���¼����ۼ���
    TJTY_NET_DETECT_EVENT_CRDFIGHT,				//49, Ⱥ���¼�����ܣ�
    TJTY_NET_DETECT_EVENT_EVACUATE,				//50, Ⱥ���¼�����ɢ��
    TJTY_NET_DETECT_EVENT_CLUTTER,				//51��Ⱥ���¼������ң�
    TJTY_NET_DETECT_EVENT_QUEUE,				//52, Ⱥ���¼����Ŷӣ�
    TJTY_NET_DETECT_EVENT_FACEDISGUISE,				//53, ����αװ
    TJTY_NET_DETECT_EVENT_STOLEN_VIDEO,				//54, ͵��
    TJTY_NET_DETECT_EVENT_OVERHEIGHT,				//55, ���߼��
    TJTY_NET_DETECT_EVENT_ATMOBJLEFT,				//56, ATM��װ������
    TJTY_NET_DETECT_EVENT_COUNT,				//57, ��Ⱥ����
    TJTY_NET_DETECT_EVENT_HIGH_DENSITY,				//58, ������Ա�ܶ�
    TJTY_NET_DETECT_EVENT_CUTFLOW,				//59, ��Ⱥ������������
    TJTY_NET_DETECT_EVENT_LINESWAY,				//60, ����߻ζ����
    TJTY_NET_DETECT_EVENT_RADIAN,				//61, �����쳣���
    TJTY_NET_DETECT_EVENT_APPENDOBJ,				//62, Ʈ������
    TJTY_NET_DETECT_EVENT_LINEDISCHANGE,			//63, ����߼��仯���
    TJTY_NET_DETECT_EVENT_COVERICE,				//64, �������
    TJTY_NET_DETECT_EVENT_TRAVERSE_PLANE,		        //65, ��Խ������
    TJTY_NET_DETECT_EVENT_ENTER_AREA,				//66, ��������
    TJTY_NET_DETECT_EVENT_LEAVE_AREA,				//67, �뿪����
    TJTY_NET_DETECT_EVENT_INSTRUSION,				//68, �ܽ�����
    TJTY_NET_DETECT_EVENT_LEFT_TAKE,				//69, �������
    TJTY_NET_DETECT_EVENT_RUN,					//70, ����
    TJTY_NET_DETECT_EVENT_VIOLENT_MOTION,		        //71����������
    TJTY_NET_DETECT_EVENT_REACH_HIGHT,				//72, �ʸ�
    TJTY_NET_DETECT_EVENT_GETUP,				//73�� ����
    TJTY_NET_DETECT_EVENT_TARRY,				//74, ��Ա����
    TJTY_NET_DETECT_EVENT_STICKUP,				//75����ֽ��
    TJTY_NET_DETECT_EVENT_INSTALL_SCANNER,			//76, ��װ������
    TJTY_NET_DETECT_EVENT_HUMAN_ENTER,                          //77, �˿���ATM
    TJTY_NET_DETECT_EVENT_OVER_TIME,                            //78, ������ʱ

    TJTY_NET_DETECT_ATM_DETECTAREA,                            //79������������ﱨ��
    TJTY_NET_DETECT_ATM_KEYBOARDAREA,	                       //80�������������ﱨ��
    TJTY_NET_DETECT_ATM_CARDREGION,	                       //81���忨���������ﱨ��
    TJTY_NET_DETECT_ATM_SHIELD,		                       //82���������������ﱨ��
    TJTY_NET_DETECT_ATM_PANEL_CAMERA_BLOCK,                    //83, �������ͷ����
    TJTY_NET_DETECT_ATM_FACE_CAMERA_BLOCK,                     //84, ��������ͷ����
    TJTY_NET_DETECT_ATM_GPI,                                   //85, ���ر���

    TJTY_NET_DETECT_SSB_TRAILING_WITHDRAWALS ,	               //86, ����β��ȡ���
    TJTY_NET_DETECT_SSB_PEOPEL_HOVER,			       //87, ������Ա�ǻ�
    TJTY_NET_DETECT_SSB_PEOPEL_FELL,			       //88, ������Ա����
    TJTY_NET_DETECT_SSB_REMNANTS,			       //89, ���������ﱨ��
    TJTY_NET_DETECT_SSB_PEOPELS_GATHER,			       //90, �������˾ۼ�����
    TJTY_NET_DETECT_SSB_FORBIDDEN_ACCESS,                      //91, ������ֹ����
    TJTY_NET_DETECT_SSB_FIGHTING,                              //92, ��������¼�
    TJTY_NET_DETECT_SSB_CAMERA_NO_SIGNAL,		       //93, ��������ͷ���źű���
    TJTY_NET_DETECT_SSB_CAMERA_ABNORMAL,		       //94, ��������ͷ�쳣����
    TJTY_NET_DETECT_SSB_SPORTS_INVADE,			       //95, �ӳ����˶����ֱ���
    TJTY_NET_DETECT_SSB_ROOM_CAMERA_NO_SIGNAL,		       //96, �ӳ�������ͷ���źű���
    TJTY_NET_DETECT_SSB_ALARM_GPI,			       //97, �������뱨��(�ⲿ����)

    TJTY_NET_DETECT_EVENT_DUMMY = 0xFFFFFFFF        //��ENUM���䵽4�ֽڣ�����������Ʋ���
} TJTY_NET_DETECT_EVENT_ALARM;
//-----------------------------------------------------------------------------
//ʵʱԤ����������ṹ
typedef struct		
{
	int		        nLinkMode;	        //���ӷ�ʽ0��TCP��ʽ,1��UDP��ʽ,
                                                        //2���ಥ��ʽ,3 - RTP��ʽ��
                                                        //4-����Ƶ�ֿ�(TCP)
	int		        nCodeType;	       //��������(0:������,1:��������2������(D1)
                                                        //3������(720P)��4������(1080P))
	char			*pchMultiCastIP;       //�ಥ���ַ
	HWND					hWnd;		       //���Ŵ��ھ��
    TJTY_NET_DataCallBack   pfRealPlayCallBack;    //Ԥ�����ݻص�
    DWORD                   dwUser;                //�û�����
	int						nChannelNO;		    //Ԥ��ͨ��(��1��ʼ)
}TJTY_NET_PLAY_PARA,*LPTJTY_NET_PLAY_PARA;
//----------------------------------------------------------------------------
//�ļ���Ϣ�ṹ
typedef struct
{
    DWORD       FileID;         //�ļ�ID
    char        chName[128];    //�ļ���
    int		nDisk;           //�����̷�
    DWORD       dwStartcluster;   //��ʼ�غţ������У�����ŵ
    //BYTE        bHint;		  // �ļ���λ����(��ŵ��
    //BYTE        byNetMultID;	  // (��ŵ��������ID. ������ϲ�ʹ��,���ǲ�ѯ����! ���û��طŵ�ʱ����������ͬһ��ͨ���Ĳ�ͬ���ʹ��, ��һ������ֵ!
				  // ����֧�ָù��ܵ��豸���֧��һ��ͨ��16��, ���Դ����ֵ�ᱻ�ڲ���ȡ�ദ��, ��ΧΪ[0,15]

    int			nChannel;        //ͨ����
    int			video_type;    //-1��Ĭ�ϣ�0:��ͨ¼��1����ʱ��2���ֹ���3��������4���ƶ���⣬ 5 ���ܱ���
    TJTY_TIME           StartTime;      //��ʼʱ��
    TJTY_TIME           EndTime;        //����ʱ��
    DWORD	    dwFileLength;      //�ļ���С��Byte��
    BYTE	    partition_no;   //������    (��ŵ����bHint��
    BYTE	    segment_no;     //�κ�      (��ŵ����byNetMultID��

}TJTY_NET_FILEINFO, *LPTJTY_NET_FILEINFO;
//---------------------------------------------------------------------------
#define MAX_MULTIPLAYBACK_CHANNEL_NUM  64               // ����ͨ��Ԥ���ط�ͨ����
//�ļ���Ϣ�ṹ
typedef struct
{
	int							nChannels[MAX_MULTIPLAYBACK_CHANNEL_NUM];		// (IN)Ԥ��ͨ����
	int							nChannelNum;									// (IN)Ԥ��ͨ���� 
	int							nRemoteType;									//	(IN)�ط�����
	int							nFPS;											// (IN)֡��,1~25
	int							nBitRate;										// (IN)����ֵ,192~1024
	int							nResolution;									//	(IN)�ֱ���("D1", "HD1", "BCIF", "CIF", "QCIF", "VGA", "QVGA", "SVCD", "QQVGA", "SVGA", "XVGA", "WXGA", 
																						//"SXGA", "WSXGA", "UXGA", "WUXGA", "LFT", "720", "1080", "1_3M", 
																						//"2M","5M","3M","5_0M","1_2M", "1408_1024", "8M", "2560_1920", "960H", "960_720"
																						//,"NHD" , "QNHD", "QQNHD")
	HWND						hWnd;											// (IN)��Ƶ���Ŵ��ھ��
	TJTY_NET_DataCallBack		pfRemotePlayCallBack;							// (IN)�ط����ݻص�
	DWORD						dwUser;											// (IN)�û�����	
	bool						bDefault;										// (IN)false��֧�ָù���ֱ�ӷ���false��true��֧�ָù��ܻ��л��ɳ�̬�طš�
	bool						bSupport;										// (OUT)���ظó����Ƿ�֧��false ��֧�֣� true֧��
}TJTY_NET_COMPRESS_REMOTEPLAY, *LPTJTY_NET_COMPRESS_REMOTEPLAY;
//----------------------------------------------------------------------------

//������Ϣ�ṹ
typedef struct
{
    char hostip[20];     //����IP
    BYTE videoalarm[64];  //ÿ���ֽڰ�λ��ʾ���ӵ͵��ߣ���һλΪ1��ʾ��Ƶ��ʧ��    ///64  //24
                          // �ڶ�λΪ1��ʾ��Ƶ�ƶ�������λΪ1��ʾ��Ƶ�ڵ���
                          //����videoalarm[0]����λΪ1��ʾӲ�̳�������λΪ1��ʾӲ������
                          //����λΪ1��ʾ������󣬵ڰ�λΪ1��ʾ�Ƿ�����
    BYTE sensoralarm[16]; //̽ͷ����, ÿ���ֽ�Ϊ1��ʾ��̽ͷ�б�����Ϊ0��ʾ��̽ͷ�ޱ�����
    TJTY_NET_DETECT_EVENT_ALARM detectalarm[32];		//���ܼ�ⱨ��������ÿ��Ԫ�ش���һ��ͨ�������ͨ�������������μ�ENUM���ͣ�ֵΪ0ʱ�����ޱ���
}TJTY_NET_ALARMINFO,  *LPTJTY_NET_ALARMINFO;
//---------------------------------------------------------------------------
//JPEGͼ����Ϣ�ṹ��(Ŀǰֻ��wPicQuality������)
typedef struct
{
    WORD  wPicSize; //ץͼ�ߴ磺0=CIF��1=QCIF��2=4CIF��
    WORD  wPicQuality;  //ͼƬ����ϵ�� ��0����ã�1���Ϻã� 2��һ��
}TJTY_NET_JPEGPARA, *LPTJTY_NET_JPEGPARA;
//----------------------------------------------------------------------------
//�豸������Ϣ�ṹ
typedef struct
{
    BYTE byChanNum;         //ͨ������
    BYTE byStartChan;       //��ʼͨ����
    BYTE byAlarmInPortNum;  //�����������
    BYTE byAlarmOutPortNum; //�����������
    BYTE byDiskNum;         //Ӳ�̸���
    int  nHandleArr[64];    //ͨ�����;������
    char* pcReserved;       //Ԥ���ṹ
}TJTY_NET_DEVICEINFO, *LPTJTY_NET_DEVICEINFO;
//---------------------------------------------------------------------------
//�汾��Ϣ�ṹ
typedef struct
{
    char  sSoftwareVersion[TJTY_NET_VERSION_LEN];  //����汾��
    char  sSoftwareBuildDate[TJTY_NET_VERSION_LEN];  //�����������

    char  sDSPSoftwareVersion[TJTY_NET_VERSION_LEN];  //DSP����汾
    char  sDSPSoftwareBuildDate[TJTY_NET_VERSION_LEN]; //DSP�����������

    char  sPanelVersion[TJTY_NET_VERSION_LEN];    //ǰ���汾��
    char  sHardwareVersion[TJTY_NET_VERSION_LEN];   //Ӳ���汾��
}TJTY_NET_VERSIONINFO;
//---------------------------------------------------------------------------
//�豸��Ϣ�ṹ��ֻ��ǰ��������޸�
//TJTY_NET_GET_DEVICECFG   ��ȡ�豸��Ϣ����
//TJTY_NET_SET_DEVICECFG   �����豸��������
typedef struct
{
    char  sDVRName[TJTY_NET_NAME_LEN];   //DVR ����
    DWORD  dwDVRID;    //DVR ID ����ң����

    DWORD  dwRecycleRecord;   //�Ƿ�ѭ��¼��1-�ǣ�0-��

    char  sDVRType[TJTY_NET_DVRSUBTYPE_LEN];       //DVR ������

    char  sSerialNumber[TJTY_NET_SERIALNO_LEN];   //���к�
    TJTY_NET_VERSIONINFO lpVersionInfo;

    BYTE  byAlarmInPortNum;  //�����������
    BYTE  byAlarmOutPortNum;  //�����������
    BYTE  byRS232Num;   //232���ڸ���
    BYTE  byRS485Num;   //485���ڸ���
    BYTE  byNetworkPortNum;  //���ڸ���
    BYTE  byDiskCtrlNum;    //Ӳ�̿���������
    BYTE  byDiskNum;       //Ӳ�̸���
    BYTE  byChanNum;  //ͨ������
    BYTE  byStartChan;   //��ʼͨ����
    BYTE  byAudioNum;   //��Ƶ�ڸ���
    BYTE  byIPChanNum;  //�������ͨ����
}TJTY_NET_DEVICECFG, *LPTJTY_NET_DEVICECFG;
//---------------------------------------------------------------------------
//��̫���ṹ
typedef struct
{
    char  chDVRIP[TJTY_NET_IPADDR_LEN];     //
    char  chGatewayIP[TJTY_NET_IPADDR_LEN];   //IP ��ַ
    char  chDVRIPMask[TJTY_NET_IPADDR_LEN];   //������������

    DWORD  dwNetInterface;   //����ӿڣ�1��10MBase-T��2��10MBase-Tȫ˫����3��100MBase-TX��4��100Mȫ˫����
                            //5��10M/100M/1000M����Ӧ��6- 1000Mȫ˫����

    WORD  wDVRPort;          //�˿ں�

    char  chMACAddr[TJTY_NET_MACADDR_LEN];  //���������ַ

}TJTY_NET_ETHERNET;
//-----------------------------------------------------------------------------
//PPPoE �ṹ
typedef struct
{
    DWORD  dwPPPoE;        //�Ƿ����ã�1-���ã�0-�����ã�
    char  chPPPoEUser[TJTY_NET_NAME_LEN];      //PPPoE �û���
    char  chPPPoEPassword[TJTY_NET_PASSWD_LEN];  //����
    char  chPPPoEIP[TJTY_NET_IPADDR_LEN];  // PPPoE  IP ��ַ
}TJTY_NET_PPPOECFG, *LPTJTY_NET_PPPOECFG;
//-----------------------------------------------------------------------------
//��������ṹ
// TJTY_NET_GET_NETCFG  ��ȡ�����������
// TJTY_NET_SET_NETCFG  ���������������
typedef struct
{
    TJTY_NET_ETHERNET struEtherNet[TJTY_NET_MAX_ETHERNET];   // ��̫���ڲ���

    char  chManageHostIP[TJTY_NET_IPADDR_LEN];     //��������IP
    WORD  wManageHostPort;   //���������˿ں�

    char  chIPServerIP[TJTY_NET_IPADDR_LEN];   //IP����������IP

    char  chMultiCastIP[TJTY_NET_IPADDR_LEN];   //�ಥ���ַ

    char  chNFSIP[TJTY_NET_IPADDR_LEN];   //NAS ������IP
    char  sNFSDirectory[TJTY_NET_PATHNAME_LEN];    //NAS �洢Ŀ¼

    WORD  wHttpPort;       //HTTP �˿ں�

    TJTY_NET_PPPOECFG struPPPOE;   //PPPoE �ṹ
}TJTY_NET_NETCFG,*LPTJTY_NET_NETCFG;
//-----------------------------------------------------------------------------
//���������ṹ
typedef struct
{
    BYTE  byStreamType;    //�������ͣ�0����Ƶ����1��������
    BYTE  byResolution;    //�ֱ��ʣ�0��DCIF�� 1��CIF��2��QCIF,��
                            // 3��4CIF��4��2CIF; 5--����

    BYTE  byBitrateType;   //�������ͣ�0�������ʣ�1��������
    BYTE  byPicQuality;   //ͼ��������0����ã�1���κã�
                       // 2���Ϻã�3��һ�㣻4���ϲ5����

    DWORD  dwVideoBitrate; //���ʣ� 0�������� 1��16K(����)�� 2��32K��3��48k��
                       //4��64K��5��80K��6��96K��7��128K��8��160k��9��192K��
                       //10��224K��11��256K��12��320K��13��384K��14��448K��
                       //15��512K��16��640K��17��768K��18��896K��19��1024K��
                       //20��1280K��21��1536K��22��1792K��23��2048K

    DWORD  dwVideoFrameRate; // ֡�ʣ�0��ȫ����1��1/16��2��1/8��3��1/4��4��1/2��
                         //5��1��6��2��7��4��8��6��9��8��10��10��11��12��12��16��13��20
}TJTY_NET_COMPRESSION_INFO,*LPTJTY_NET_COMPRESSION_INFO;

//----------------------------------------------------------------------------
typedef struct
{
    BYTE  byBrightness;         //���ȣ�ȡֵ��Χ0��255
    BYTE  byContrast;          //�Աȶȣ�ȡֵ��Χ0��255
    BYTE  bySaturation;       //���Ͷȣ�ȡֵ��Χ0��255
    BYTE  byHue;             //ɫ����ȡֵ��ΧΪ0��255
}TJTY_NET_VIDEOEFFECT, *LPTJTY_NET_VIDEOEFFECT;
//----------------------------------------------------------------------------
//ͼ������ṹ
//TJTY_NET_GET_PICCFG     ��ȡͼ���������
//TJTY_NET_SET_PICCFG     ����ͼ���������
typedef struct
{
    char  sChanName[TJTY_NET_NAME_LEN];  //ͨ������

    DWORD  dwVideoFormat;       //��Ƶ��ʽ��1��NTSC�� 2��PAL

    BYTE  byBrightness;         //���ȣ�ȡֵ��Χ0��255
    BYTE  byContrast;          //�Աȶȣ�ȡֵ��Χ0��255
    BYTE  bySaturation;       //���Ͷȣ�ȡֵ��Χ0��255
    BYTE  byHue;             //ɫ����ȡֵ��ΧΪ0��255

    TJTY_NET_COMPRESSION_INFO  struMainStreamPara;  //����������

    TJTY_NET_COMPRESSION_INFO  struSubStreamPara;    //����������

    DWORD  dwShowChanName;   //�Ƿ���ʾͨ������0������ʾ��1����ʾ��Ԥ�������С704*576��
    WORD  wShowNameTopLeftX; // ͨ��������ʾλ�����Ͻǵ�x����
    WORD  wShowNameTopLeftY;  //ͨ��������ʾλ�����Ͻǵ�x����

    DWORD  dwEnableHide;  //�Ƿ����������ڱΣ���ɫ���סͼ���������ز��֣���0����1����
    WORD  wHideAreaTopLeftX;  //�ڱ������x����
    WORD  wHideAreaTopLeftY;   //�ڱ������y����
    WORD  wHideAreaWidth;   //�ڱ�����Ŀ��
    WORD  wHideAreaHeight;  //�ڱ�����ĸ߶�

    DWORD  dwShowOsd;    //Ԥ����ͼ�����Ƿ���ʾOSD��0������ʾ��1����ʾ
    WORD  wOSDTopLeftX;  //OSD���Ͻǵ�x����
    WORD  wOSDTopLeftY;  //OSD���Ͻǵ�y����

    BYTE  byDispWeek;   //�Ƿ���ʾ����
}TJTY_NET_PICCFG, *LPTJTY_NET_PICCFG;
//-----------------------------------------------------------------------------
//#define TJTY_NET_GET_VILOST    103  // ��ȡ��Ƶ��ʧ����
//#define TJTY_NET_SET_VILOST    203  // ������Ƶ��ʧ����

//����ʱ��ṹ
typedef struct
{
    BYTE  byStartHour;   //��ʼʱ�� Сʱ
    BYTE  byStartMin;    //��ʼʱ�� ����
    BYTE  byStopHour;    //����ʱ�� Сʱ
    BYTE  byStopMin;    //����ʱ�� ����
}TJTY_NET_SCHEDTIME, *LPTJTY_NET_SCHEDTIME;
//-----------------------------------------------------------------------------
//�澯��Ϣ����ṹ
typedef struct
{
    DWORD  dwHandleType;     //����ʽ�����ִ���ʽ��"��"ֵ��
                         // 0x00��������0x01���������Ͼ��棻0x02���������棻
                         //0x04���ϴ����ģ�0x08���������������

    BYTE  byRelAlarmOut[TJTY_NET_MAX_ALARMOUT];    //�������������ͨ����
                                                    //����Ԫ��ֵΪ1��ʾ������·�������
}TJTY_NET_HANDLEEXCEPTION;
//---------------------------------------------------------------------------
//��Ƶ��ʧ����ṹ
//TJTY_NET_GET_VILOST    ��ȡ��Ƶ��ʧ��������
//TJTY_NET_SET_VILOST    ������Ƶ��ʧ��������
typedef struct
{
    BYTE  byEnableHandleVILost;     //�Ƿ���1-����0-������

    TJTY_NET_HANDLEEXCEPTION  strVILostHandleType;  //����ʽ

    TJTY_NET_SCHEDTIME  struAlarmTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];  //����ʱ��
}TJTY_NET_VILOST, *LPTJTY_NET_VILOST;
//-----------------------------------------------------------------------------
//�ƶ���ⱨ���ṹ
//TJTY_NET_GET_MOTION      ��ȡ�ƶ���ⱨ����������
//TJTY_NET_SET_MOTION      �����ƶ���ⱨ����������

typedef struct
{
    BYTE  byMotionSenstive;  //�ƶ���������ȣ�0-5��ֵԽ��Խ������0xff�ر�
    BYTE  byEnableHandleMotion;  //�Ƿ���1-����0-������

    TJTY_NET_HANDLEEXCEPTION  strMotionHandleType;  //����ʽ

    TJTY_NET_SCHEDTIME  struAlarmTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];  //����ʱ��

    BYTE  byRelRecordChan[TJTY_NET_MAX_CHANNUM];  //����������¼��ͨ��,����Ԫ��ֵΪ1��ʾ������ͨ������
}TJTY_NET_MOTION, *LPTJTY_NET_MOTION;
//----------------------------------------------------------------------------
//��Ƶ�ڵ������ṹ
//TJTY_NET_GET_HIDEALARM  ��ȡ��Ƶ�ڵ�������������
//TJTY_NET_SET_HIDEALARM  ������Ƶ�ڵ�������������

typedef struct
{
    DWORD  dwEnableHideAlarm;  //�Ƿ������ڵ�������0����1���������ȣ�2���������ȣ�3����������

    TJTY_NET_HANDLEEXCEPTION  strAreaHandleType;  //����ʽ

    TJTY_NET_SCHEDTIME  struAlarmTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];  //����ʱ��
}TJTY_NET_HIDEALARM, *LPTJTY_NET_HIDEALARM;
//-----------------------------------------------------------------------------
//ȫ��¼��ṹ
typedef struct
{
    WORD  wAllDayRecord;   //�Ƿ�ȫ��¼��

    BYTE  byRecordType;  //0����ʱ¼��1���ƶ����¼��2������¼��3���ƶ������߱���¼��
                     //4���ƶ����¼��ͱ���¼��5�������¼��6���ֶ�¼��
}TJTY_NET_RECORDDAY;
//-----------------------------------------------------------------------------
//ʱ���¼��ṹ
typedef struct
{
    TJTY_NET_SCHEDTIME  struRecordTime;   //ʱ���

    BYTE  byRecordType;  //0����ʱ¼��1���ƶ����¼��2������¼��3���ƶ������߱���¼��
                     //4���ƶ����¼��ͱ���¼��5�������¼��6���ֶ�¼��

}TJTY_NET_RECORDSCHED,*LPTJTY_NET_RECORDSCHED;
//-----------------------------------------------------------------------------
//¼������ṹ
//TJTY_NET_GET_RECORDCFG     ��ȡ¼�����ò�������
//TJTY_NET_SET_RECORDCFG     ����¼�����ò�������
typedef struct
{
    DWORD  dwRecord;   //�Ƿ�¼�� ��0����1����

    TJTY_NET_RECORDDAY  struRecAllDay[TJTY_NET_MAX_DAYS];    //ȫ��¼�񲼷�
    TJTY_NET_RECORDSCHED  struRecordSched[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT]; //¼�񲼷�

    DWORD  dwRecordTime;  //¼����ʱ
    DWORD  dwPreRecordTime;  //Ԥ¼ʱ��

}TJTY_NET_RECORD,*LPTJTY_NET_RECORD;
//---------------------------------------------------------------------------


//������������ṹ
//TJTY_NET_GET_ALARMINCFG    ��ȡ���������������
//TJTY_NET_SET_ALARMINCFG    ���ñ��������������

typedef struct
{
    char  sAlarmInName[TJTY_NET_NAME_LEN];   //������������

    BYTE  byAlarmType;   //���������ͣ�0��������1������
    BYTE  byAlarmInHandle;   //�Ƿ���

    TJTY_NET_HANDLEEXCEPTION  struAlarmHandleType;  //����ʽ

    TJTY_NET_SCHEDTIME  struAlarmTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];  //����ʱ��

    BYTE  byRelRecordChan[TJTY_NET_MAX_CHANNUM];  //����������¼��ͨ��,
                                              //����Ԫ��ֵΪ1��ʾ������ͨ������

    BYTE  byEnablePreset[TJTY_NET_MAX_CHANNUM];  //�Ƿ����Ԥ�õ㣬
                                             //����Ԫ��ֵΪ1��ʾ��ͨ��������Ԥ�õ�
    BYTE  byPresetNo[TJTY_NET_MAX_CHANNUM];    //���õ���̨Ԥ�õ���ţ�
    BYTE  byEnableCruise[TJTY_NET_MAX_CHANNUM];  //��ͨ���Ƿ����Ѳ����ֵΪ1��ʾ������Ѳ��
    BYTE  byCruiseNo[TJTY_NET_MAX_CHANNUM];  //���õ���̨��Ѳ��·�����
    BYTE  byEnablePtzTrack[TJTY_NET_MAX_CHANNUM];  //��ͨ���Ƿ���ù켣��ֵΪ1��ʾ�����˹켣
    BYTE  byPTZTrack[TJTY_NET_MAX_CHANNUM]; //���õ���̨�Ĺ켣���
}TJTY_NET_ALARMINCFG,*LPTJTY_NET_ALARMINCFG;
//-----------------------------------------------------------------------------
//������������ṹ
//TJTY_NET_GET_ALARMOUTCFG       ��ȡ���������������
//TJTY_NET_SET_ALARMOUTCFG       ���ñ��������������

typedef struct{

    char  sAlarmOutName[TJTY_NET_NAME_LEN];   //�������������
    DWORD  dwAlarmOutDelay;   //����ź�״̬��ʱʱ��

    TJTY_NET_SCHEDTIME struAlarmOutTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];
    //�����������ʱ���
}TJTY_NET_ALARMOUTCFG, *LPTJTY_NET_ALARMOUTCFG;
//-----------------------------------------------------------------------------
//�쳣�澯��Ϣ�����ṹ
//TJTY_NET_GET_EXCEPTIONCFG    ��ȡ�쳣�澯��Ϣ��������
//TJTY_NET_SET_EXCEPTIONCFG    �����쳣�澯��Ϣ��������

typedef struct
{

    TJTY_NET_HANDLEEXCEPTION struExceptionHandleType[TJTY_NET_MAX_EXCEPTIONNUM];
    //�쳣��Ϣ����ʽ  0��Ӳ������1��Ӳ�̳���2�����߶ϣ�3��IP ��ַ��ͻ��
    //4���Ƿ����ʣ�5������/�����Ƶ��ʽ��ƥ�䣬

}TJTY_NET_EXCEPTION, *LPTJTY_NET_EXCEPTION;
//-----------------------------------------------------------------------------
//ʱ���������
//TJTY_NET_GET_SYYTEMTIME     ��ȡDVRϵͳʱ������
//TJTY_NET_SET_SYYTEMTIME     ����DVRϵͳʱ�����Уʱ��
//ʱ��ṹ��� TJTY_TIME��
//-----------------------------------------------------------------------------
//Ӳ��״̬�ṹ
typedef struct
{
    DWORD  dwVolume;   //Ӳ������ (MB)
    DWORD  dwFreeSpace;  //Ӳ��ʣ��ռ� (MB)
    DWORD  dwHardDiskStatic;  //Ӳ��״̬ 0�����1�����ߣ�2����������
}TJTY_NET_DISKSTATE,*LPTJTY_NET_DISKSTATE;
//---------------------------------------------------------------------------
//ͨ��״̬�ṹ
typedef struct
{
    BYTE  byRecordStatic;      // ¼��״̬��0����¼��1��¼��
    BYTE  bySignalStatic;      // �ź�״̬��0��������1���źŶ�ʧ
    BYTE  byHardwareStatic;    // Ӳ��״̬��0��������1���쳣������DSP����
    int   iRecordDays ;        // ¼������
}TJTY_NET_CHANNELSTATE,*LPTJTY_NET_CHANNELSTATE;
//-----------------------------------------------------------------------------
//�豸״̬�ṹ
typedef struct
{                                        
    DWORD  dwDeviceStatic;            //�豸��״̬��0��������1��CPUռ����̫�ߣ�����85%��
										//2��Ӳ���������紮������

    TJTY_NET_DISKSTATE struHardDiskStatic[TJTY_NET_MAX_DISKNUM];  //Ӳ��״̬

    TJTY_NET_CHANNELSTATE struChanStatic[TJTY_NET_MAX_CHANNUM];  //ͨ������

}TJTY_NET_WORKSTATE,*LPTJTY_NET_WORKSTATE;
//----------------------------------------------------------------------------
//��־��Ϣ�ṹ
typedef struct
{
    TJTY_TIME strLogTime;   //��¼��־ʱ��

    char chLogType[20];  //��־����
    char chLogInfo[80];  //��־����
    //DWORD  dwMajorType;  //������
    //DWORD  dwMinorType;  //������

    char  sPanelUser[TJTY_NET_NAME_LEN];  //ǰ�˲����û�
    char  sNetUser[TJTY_NET_NAME_LEN];  //��������û�

    DWORD  dwChannel;   //ͨ����
    DWORD  dwDiskNumber; //���̺�
    
    DWORD  dwAlarmInPort;  //��������˿�
    DWORD  dwAlarmOutPort; //��������˿�

}TJTY_NET_LOG, *LPTJTY_NET_LOG;
//-----------------------------------------------------------------------------
//����ṹ
typedef struct
{
    int  xTop;    //������ʼ���x����
    int  yTop;  //������ʼ���y����
    int  xBottom; //����������x����
    int  yBottom; //����������y����
}TJTY_NET_RECT, *LPTJTY_NET_RECT;
//----------------------------------------------------------------------------
//Ѳ������Ϣ�ṹ
typedef struct
{
    BYTE byPresetNum;   //Ԥ�õ����
    BYTE bynDwell;     //ͣ��ʱ��
    BYTE bynSpeed;     //�ٶ�
    BYTE byReserve;     //����
}TJTY_NET_CRUISE_POINT, *LPTJTY_NET_CRUISE_POINT;
//---------------------------------------------------------------------------
//Ѳ��·����Ϣ�ṹ
typedef struct{

    TJTY_NET_CRUISE_POINT struCruisePoint[TJTY_NET_MAX_CRUPIONT];

}TJTY_NET_CRUISE_RET, *LPTJTY_NET_CRUISE_RET;

//�����豸�����Ϣ
typedef struct Device_SEARCH_RESULT
{
    char pcIpAddr[128];				//�豸IP��ַ
    int  nPort;					//�豸����˿�
    char pcXAddr[128];				//�豸�����ַ
    char pcEPAddr[128];				//�豸EndPoint����
    TJTY_DVRTYPE  type ;
}DEVICE_SEARCH_RESULT;
//------------------------------------------------------------
typedef struct
{
  BYTE    byStartHour;
  BYTE    byStartMin;
  BYTE    byStopHour;
  BYTE    byStopMin;
}TYNET_DVR_SCHEDTIME, *LPTYNET_DVR_SCHEDTIME;

typedef struct
{
  WORD    wAllDayRecord;
  BYTE    byRecordType;
  char    reservedData;
}TYNET_DVR_RECORDDAY, *LPTYNET_DVR_RECORDDAY;

typedef struct
{
  TYNET_DVR_SCHEDTIME    struRecordTime;
  BYTE                   byRecordType;   /* ¼������ 0:��ʱ¼��1:�ƶ���⣬2:����¼��3:����|������4:����&���� 5:�����, 6: ����¼��,10-PIR������11-���߱�����12-���ȱ�����13-PIR|���߱���|���ȱ��� ,15 ���趨*/
  char                   reservedData[3];
}TYNET_DVR_RECORDSCHED, *LPTYNET_DVR_RECORDSCHED;

typedef struct
{
    DWORD                   dwSize;
    DWORD                   dwRecord;
    TYNET_DVR_RECORDDAY     struRecAllDay[TJTY_NET_MAX_DAYS];
    TYNET_DVR_RECORDSCHED   struRecordSched[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT*2];
    DWORD                   dwRecordTime;
    DWORD                   dwPreRecordTime;
    DWORD                   dwRecorderDuration;
    BYTE                    byRedundancyRec;
    BYTE                    byAudioRec;
    BYTE                    byReserve[10];
}TYNET_DVR_RECORD, *LPTYNET_DVR_RECORD;

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*************************�����ӿ�*******************************************/
//----------------------------------------------------------------------------
//��ʼ�����
TJTY_NET_API bool __stdcall TJTY_NET_Init(DWORD dwDVRType, int &nError);

//�����쳣�ص�����
TJTY_NET_API bool __stdcall TJTY_NET_SetExceptionCallBack
                            (TJTY_NET_ExceptionMsg_CALLBACK pfExceptionCallBack,
                            DWORD dwUser, int &nError);

TJTY_NET_API bool __stdcall TJTY_NET_CleanUp();

//���ñ����ص�
TJTY_NET_API bool __stdcall TJTY_NET_SetAlarmMessCallBack(TJTY_NET_ALARM_MSG_CALLBACK pfAlarmMessCallBack,
                                                         int &nError);

//���ûص����ݿ��ƻص�����(ͼ��ר��)
TJTY_NET_API bool __stdcall TJTY_NET_SetRemoteRecDataCallBack_TM(
                            TJTY_NET_RemoteRecDataCallBack_TM fpRemoteRecDataCallBack_TM);

//��¼DVR���
TJTY_NET_API bool __stdcall TJTY_NET_LogInDVR(TJTY_DVRTYPE  nDVRType,
                                             char          *pchDvrIP,
                                             UINT          unPort,
                                             char          *pchName,
                                             char          *pchPass,
                                             LPTJTY_NET_DEVICEINFO lpDeviceInfo,
                                             long          &lUserID);

TJTY_NET_API bool __stdcall TJTY_NET_QuitDVR(long lUserID);

//Ԥ�����
TJTY_NET_API bool __stdcall TJTY_NET_RealPlay(long lUserID, LPTJTY_NET_PLAY_PARA lpRealPlayInfo, long &lPlayID);

TJTY_NET_API bool __stdcall TJTY_NET_StopRealPlay(long lPlayID);

//���沶�񵽵����ݵ�ָ�����ļ���
//�������ܣ�����Ԥ�����ݵ�ָ�����ļ�
//���������lPlayID[in] Ԥ�����
//          chFileName[in] �ļ���
//          nError[out] ������
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall TJTY_NET_SaveRealData(long lPlayID, char *chFileName, int &nError);

//ֹͣ���沶�񵽵�����
//�������ܣ�����Ԥ�����ݵ�ָ�����ļ�
//���������lPlayID[in] ���ڱ������ݵ�Ԥ�����
//����ֵ��true �ɹ���false ʧ��
TJTY_NET_API bool __stdcall TJTY_NET_StopSaveRealData(long lPlayID);

//ץͼ��BMP��ʽ��
//�������ܣ�������Ԥ����ͼ��ץͼ
//���������lPlayID[in] Ԥ�����
//          chPicFileName[in] ����ͼƬ���ļ���
//          nError[out] ������
//����ֵ��true �ɹ���false ʧ�ܣ�
//˵��: ���û��������ݻص���ʽԤ��ʱ���ú�����Ч��
TJTY_NET_API bool __stdcall TJTY_NET_CapturePicture(long lPlayID, char *chPicFileName, int &nError);

//ץJPEGͼ,������ļ�
//�������ܣ�ץJPEGͼ,������ļ�(����Ҫ��ͨ��Ԥ��)
//���������lUserID[in] ��¼DVR���صľ��
//          nChannel[in] ͨ����
//          lpJPEGPara[in] JPEGͼ����Ϣ�ṹ
//          chPicFileName[in] ����ͼƬ������
//          nError[out] ������
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall TJTY_NET_CaptureJPEGPicture(long lUserID,
                                                        int nChannel,
                                                        LPTJTY_NET_JPEGPARA lpJPEGPara,
                                                        char *chPicFileName,
                                                        int &nError);

//ץJPEGͼ,���浽�ڴ�
//�������ܣ�ץJPEGͼ,���浽�ڴ�(����Ҫ��ͨ��Ԥ��)
//���������lUserID[in] ��¼DVR���صľ��
//          nChannel[in] ͨ����
//          lpJPEGPara[in] JPEGͼ����Ϣ�ṹ
//          chPicBuf[in] ����ͼƬ�Ļ�����
//          dwPicSize[in] ��������С
//          lpSizeReturned[out] ʵ�ʷ��ص����ݴ�С
//          nError[out] ������
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall	TJTY_NET_CaptureJPEGPicToMemory(long lUserID,
                                                        int nChannel,
                                                        LPTJTY_NET_JPEGPARA lpJPEGPara,
                                                        char *chPicBuf,
                                                        DWORD  dwPicSize,
                                                        LPDWORD  lpSizeReturned,
                                                        int &nError);

//��ȡ��Ƶ����
//�������ܣ���ȡ��Ƶͼ�����������ɫ�ȡ����ȡ����Ͷȡ��Աȶ�
//���������lUserID[in] ��¼DVR���صľ��
//          nChannel[in] ͨ����
//          lpstruVideoEffect[out] ͼ������ṹ
//          nError[out] ������
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall TJTY_NET_GetVideoEffect(long lUserID,
                                                    int nChannel,
                                                    LPTJTY_NET_VIDEOEFFECT lpstruVideoEffect,
                                                    int &nError);

//������Ƶ����
//�������ܣ�������Ƶͼ�����������ɫ�ȡ����ȡ����Ͷȡ��Աȶ�
//���������lUserID[in] ��¼DVR���صľ��
//          nChannel[in] ͨ����
//          lpstruVideoEffect[in] ͼ������ṹ
//          nError[out] ������
//����ֵ��true �ɹ���false ʧ�ܣ�
//˵�����ú������ı�ǰ��������Ӧͨ������Ƶ�������á�
TJTY_NET_API bool __stdcall TJTY_NET_SetVideoEffect(long lUserID,
                                                    int nChannel,
                                                    LPTJTY_NET_VIDEOEFFECT lpstruVideoEffect,
                                                    int &nError);

//����һ���ؼ�֡
//�������ܣ�����DVR����һ���ؼ�֡
//���������lUserID[in] ��¼DVR���صľ��
//          nChannel[in] ͨ����
//          nType[in] ��������0-��������1-������
TJTY_NET_API bool __stdcall TJTY_NET_MakeKeyFrame(long lUserID, int nChannel, int nType);

//�����ļ��б�
TJTY_NET_API bool __stdcall TJTY_NET_SearchFileList(long                lUserID,
                                                   int                   nChannelNO,
                                                   TJTY_TIME             StartTime,
                                                   TJTY_TIME             EndTime,
                                                   int                   nFileType,
                                                   char                  *chCardID,
                                                   TJTY_NET_FileList_CALLBACK  pfFileListCallBack,
                                                   DWORD                 dwUser,
	                                                int                   &nError);
//ֹͣ����
TJTY_NET_API bool __stdcall TJTY_NET_StopSearchFile(long lUserID);

//ֹͣĳһ·ͨ������
//���������lUserID[in] ��¼DVR���صľ��
//          nChannel[in] ͨ����
TJTY_NET_API bool __stdcall TJTY_NET_StopSearchFileByChannel(long lUserID, int  nChannelNO);


//�����ļ�
//�������ܣ�����ָ����¼���ļ�����������ļ��������Զ�ɾ�����߸���
//���������lUserID[in] ��¼DVR���صľ��
//          pFileInfo[in] �ļ���Ϣ
//          nError[out] ������
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall TJTY_NET_LockFileByName(long lUserID,
                                                    LPTJTY_NET_FILEINFO pFileInfo,
                                                    int &nError);

//�����ļ�
//�������ܣ�����ָ����¼���ļ�
//���������lUserID[in] ��¼DVR���صľ��
//          pFileInfo[in] �ļ���Ϣ
//          nError[out] ������
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall TJTY_NET_UnLockFileByName(long lUserID,
                                                      LPTJTY_NET_FILEINFO pFileInfo,
                                                      int &nError);

//�ط����
//���ļ���Ϣ�ط�
TJTY_NET_API bool __stdcall TJTY_NET_RemotePlayByName(long                      lUserID,
                                                     LPTJTY_NET_FILEINFO       pFileInfo,
                                                     HWND	                     hWnd,			    //���Ŵ��ھ��
                                                     TJTY_NET_DataCallBack     pfRemotePlayCallBack,
                                                     DWORD                     dwUser,
                                                     DWORD                     &dwFileLength,
                                                     long                      &lPlayID);

//��ʱ��ط�
TJTY_NET_API bool __stdcall TJTY_NET_RemotePlayByTime(long                      lUserID,
                                                     int                       nChannel,
                                                     TJTY_TIME                 StartTime,
                                                     TJTY_TIME                 EndTime,
                                                     HWND	               hWnd,
                                                     TJTY_NET_DataCallBack     pfRemotePlayCallBack,
                                                     DWORD                     dwUser,
                                                     DWORD                     &dwFileLength,
                                                     long                      &lPlayID);
//����ѹ�����ļ��ط�
TJTY_NET_API bool __stdcall TJTY_NET_CompressRemotePlayByName(long                      lUserID,
															LPTJTY_NET_FILEINFO       pFileInfo,
															LPTJTY_NET_COMPRESS_REMOTEPLAY	pModeParam,
															DWORD                     &dwFileLength,
															long                      &lPlayID);
//����ѹ����ʱ��ط�
TJTY_NET_API bool __stdcall TJTY_NET_CompressRemotePlayByTime(long                      lUserID,
													  TJTY_TIME                 StartTime,
													  TJTY_TIME                 EndTime,
													LPTJTY_NET_COMPRESS_REMOTEPLAY	pModeParam,	
													DWORD                     &dwFileLength,
													  long                      &lPlayID);

//ֹͣ�ط�
TJTY_NET_API bool __stdcall TJTY_NET_StopRemotePlay(long lRemotePlayID);

//���ûطŽ���
TJTY_NET_API bool __stdcall TJTY_NET_SetRemotePlayPos(long lRemotePlayID, int nPos);

//��ȡ�طŽ���
TJTY_NET_API bool __stdcall TJTY_NET_GetRemotePlayPos(long lRemotePlayID, int &nPos);

//�������
//���ļ���Ϣ����
TJTY_NET_API bool __stdcall TJTY_NET_DownLoadByName(long                      lUserID,
                                                   LPTJTY_NET_FILEINFO       pFileInfo,
                                                   char*                     chSaveFileName,
                                                   TJTY_NET_DataCallBack     pfDownLoadCallBack,
                                                   DWORD                     dwUser,
                                                   DWORD                     &dwFileLength,
                                                   long                      &lDownID);

//��ʱ������
TJTY_NET_API bool __stdcall TJTY_NET_DownLoadByTime(long                      lUserID,
                                                   int                       nChannel,
                                                   TJTY_TIME                 StartTime,
                                                   TJTY_TIME                 EndTime,
                                                   char*                     chSaveFileName,
                                                   TJTY_NET_DataCallBack     pfDownLoadCallBack,
                                                   DWORD                     dwUser,
                                                   DWORD                     &dwFileLength,
                                                   long                      &lDownID);
//ֹͣ����
TJTY_NET_API bool __stdcall TJTY_NET_StopDownLoad(long lDownLoadID);

//��ȡ���ؽ���
TJTY_NET_API bool __stdcall TJTY_NET_GetDownLoadPos(long lDownLoadID, int &nPos);

//�������طŵ�¼������
//�������ܣ�����ط����ݵ�ָ�����ļ�
//���������lRemotePlayID[in] �طž��
//          chFileName[in] �ļ���
//          nError[out] ������
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall TJTY_NET_SaveRemotePlayData(long lRemotePlayID,
                                                        char *chFileName,
                                                        int &nError);

//ֹͣ����طŵ�¼������
//�������ܣ�ֹͣ����ط����ݵ��ļ�
//���������lRemotePlayID[in] ���ڱ������ݵĻطž��
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall TJTY_NET_StopSaveRemoteData(long lRemotePlayID);

//�Խ����
TJTY_NET_API bool __stdcall TJTY_NET_StartTalk(long lUserID, int nLinkChannel,
                                               TJTY_NET_VoiceData_CALLBACK pfVioceCallBack,
                                               DWORD dwUser,
                                               long &lTalkID);

TJTY_NET_API bool __stdcall TJTY_NET_StopTalk(long lTalkID);

//������������
TJTY_NET_API bool __stdcall TJTY_SetVoiceVolume(long lTalkID, int nVolume);

//��������ת��
//�������ܣ���������ת��
//������lUserID[in] ��¼DVR���صľ��
//      nLinkChannel[in]  �Խ�ͨ��
//      pfVioceCallBack[in] �����ص�����
//      dwUser[in] �û�����
//      lTalkID[out] ���ص�����ת���������
TJTY_NET_API bool __stdcall TJTY_NET_StartVoiceCom_MR(long lUserID, int nLinkChannel,
                                                      TJTY_NET_VoiceData_CALLBACK pfVioceCallBack,
                                                      DWORD dwUser,
                                                      long &lTalkID);

//����ת��
//�������ܣ�����ת��
//������lTalkID[in] ����ת���������
//      pSendBuf[in]  ת�������ݻ���
//      dwBufSize[in] �ﻺ������С
TJTY_NET_API bool __stdcall TJTY_NET_VoiceComSendData(long lTalkID, char *pSendBuf, DWORD dwBufSize);

//ֹͣ����ת��
TJTY_NET_API bool __stdcall TJTY_NET_StopVoiceCom(long lTalkID);

//Ⱥ�����
TJTY_NET_API bool __stdcall TJTY_NET_StartMultiTalk(long *lpUserID, int nDVRNumber, int nDVRType, int &nError);

TJTY_NET_API bool __stdcall TJTY_NET_StopMultiTalk();

TJTY_NET_API bool __stdcall TJTY_NET_AddDVRToMulti(long lUserID,
                                                   int nDVRType,
                                                   int &nError);

TJTY_NET_API bool __stdcall TJTY_NET_DelDVRFromMulti(long lUserID);

//�������
TJTY_NET_API bool __stdcall TJTY_NET_StartListen(long lUserID, DWORD dwUser);

TJTY_NET_API bool __stdcall TJTY_NET_StopListen(long lUserID);

//-----------------------------------------------------------------------------
//�豸������ȡ�����ò���
//-----------------------------------------------------------------------------
//�����ȡ�����ò���
//�������ܣ������ȡ������DVR�������ú����ṩһ�����ý��棬���в��������ڲ���װ
//������lUserID[in]    ��¼DVR���ص�ID;
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall TJTY_NET_GetAndSetConfig(long lUserID, int &nError);
//-----------------------------------------------------------------------------
//��ȡ�豸��������
//�������ܣ���ȡDVR����
//������lUserID[in]    ��¼DVR���ص�ID;
//      dwCommond[in]  �����������TJTY_NET_GETCFG��
//      lChannel[in]   ͨ����
//      lpOutBuf[out]   ���ڴ洢������Ϣ�Ľṹָ��
//      dwBufSize[in]  lpOutBuf�������ĳ���
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�

TJTY_NET_API bool __stdcall TJTY_NET_GetDVRConfig(long lUserID,
                                                 DWORD   dwCommond,
                                                 long    lChannel,
                                                 LPVOID  lpOutBuf,
                                                 DWORD   dwBufSize,
                                                 int     &nError);

//-----------------------------------------------------------------------------
//�����豸��������
//�������ܣ�����DVR����
//������lUserID[in]    ��¼DVR���ص�ID;
//      dwCommond[in]  �����������TJTY_NET_SETCFG��
//      lChannel[in]   ͨ����
//      lpInBuf[in]    �洢������Ϣ�Ľṹָ��
//      dwBufSize[in]  lpInBuf�������ĳ���
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�

TJTY_NET_API bool __stdcall TJTY_NET_SetDVRConfig(long lUserID,
                                                  DWORD   dwCommond,
                                                  long    lChannel,
                                                  LPVOID  lpInBuf,
                                                  DWORD   dwBufSize,
                                                  int     &nError);

//----------------------------------------------------------------------------
//�ָ�����Ĭ������
//�������ܣ��ָ�DVR����Ĭ������
//������lUserID[in]    ��¼DVR���ص�ID;
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�
TJTY_NET_API bool __stdcall TJTY_NET_RestoreConfig(long lUserID, int &nError);
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//��ȡ�豸״̬����
//�������ܣ���ȡ�豸״̬
//������lUserID[in]    ��¼DVR���ص�ID;
//      lpWorkStateBuf[out] �洢�豸״̬��Ϣ�Ľṹָ��
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�

TJTY_NET_API bool __stdcall TJTY_NET_GetDVRWorkState(long lUserID,
                                                     LPTJTY_NET_WORKSTATE lpWorkStateBuf,
                                                     int &nError);
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//��ȡ�������벼��״̬����
//�������ܣ���ȡ�������벼��״̬
//������lUserID[in]    ��¼DVR���ص�ID;
//      nAlarmInNO[in] ��������˿ں�
//      nAlarmInState[out]  ����״̬��1-������ 0-������
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�

TJTY_NET_API bool __stdcall TJTY_NET_GetDVRAlarmInState(long lUserID,
                                                        int   nAlarmInNO,
                                                        int   &nAlarmInState,
                                                        int   &nError);
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//�������벼�������ƺ���
//�������ܣ�������
//������lUserID[in]    ��¼DVR���ص�ID;
//      nAlarmInNO[in] ��������˿ں�
//      bAlarm[in]   ���������true-������ false-������
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�

TJTY_NET_API bool __stdcall TJTY_NET_SetDVRAlarmInState(long lUserID,
                                                        int   nAlarmInNO,
                                                        bool  bAlarmIn,
                                                        int   &nError);
//-----------------------------------------------------------------------------
//������ƺ���
//�������ܣ������ⲿ�豸
//������lUserID[in]    ��¼DVR���ص�ID;
//      nAlarmOutNO[in] ��������˿ں�
//      bAlarm[in]   �������true-�򿪣� false-�رգ�
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�

TJTY_NET_API bool __stdcall TJTY_NET_ControlDVRAlarmOut(long lUserID,
                                                        int  nAlarmOutNO,
                                                        bool bAlarmOut,
                                                        int  &nError);
//----------------------------------------------------------------------------
/*****************************�豸������************************************/
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//Զ�̹ػ�����
//�������ܣ�Զ�̹ػ�����
//������lUserID[in]    ��¼DVR���ص�ID;
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�

TJTY_NET_API bool __stdcall TJTY_NET_ShutDownDVR(long lUserID, int &nError);
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//Զ��������������
//�������ܣ�����Զ�̹ػ�
//������lUserID[in]    ��¼DVR���ص�ID;
//      nError[out]    ������
//����ֵ��true �ɹ���false ʧ�ܣ�

TJTY_NET_API bool __stdcall TJTY_NET_RebootDVR(long lUserID, int &nError);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//��־��ѯ����
//�������ܣ���־��ѯ����
//������lUserID[in]    ��¼DVR���ص�ID;
//      dwLogType[in]   ��־���ͣ�0��ȫ����1��������2-�쳣��3��������
//      lpStartTime[in] ��ʼʱ��
//      lpStopTime[in]  ����ʱ��
//      lpLogInfoCallBack[in] ��־�ص�����
//      dwUser[in]      �û��Զ������
//      nError[out]    ������
//����ֵ��true-�ɹ���false-ʧ�ܣ�

TJTY_NET_API bool __stdcall TJTY_NET_FindDVRLog(long lUserID,
                                                DWORD  dwLogType,
                                                LPTJTY_TIME lpStartTime,
                                                LPTJTY_TIME lpStopTime,
                                                TJTY_NET_LogInfo_CALLBACK lpLogInfoCallBack,
                                                DWORD dwUser,
                                                int &nError);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//ֹͣ������־
//�������ܣ�ֹͣ������־���ͷ���Դ
//������lUserID[in]  ��¼DVR���ص�ID;
//����ֵ��true-�ɹ���false-ʧ�ܡ�

TJTY_NET_API bool __stdcall TJTY_NET_FindClosetLog(long lUserID);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//�������ܣ�������̨����
//������lUserID[in]  ��¼DVR���ص�ID;
//      nChannel[in] ͨ����
//      dwPZTCommond[in] ��������, ��TJTY_NET_PTZCTRL_CMD��
//      bStop[in]  ������ʼ����ֹͣ��true-ֹͣ��false-��ʼ����
//      nError[out] ������
//����ֵ��true-�ɹ���false-ʧ�ܡ�

TJTY_NET_API bool __stdcall TJTY_NET_PTZControl(long  lUserID,
                                                int   nChannel,
                                                DWORD dwPZTCommond,
                                                bool  bStop,
                                                DWORD dwSpeed,
                                                int &nError);
//-----------------------------------------------------------------------------
//��̨ͼ���������
//�������ܣ�������̨ͼ������ѡ��Ŵ����С
//������lUserID[in]  ��¼DVR���ص�ID;
//      nChannel[in] ͨ����
//      pRectInfo[in] ������Ϣ�ṹ
//      nError[out] ������
//����ֵ��true-�ɹ���false-ʧ�ܡ�

TJTY_NET_API bool __stdcall TJTY_NET_PZTSelZoomIn(long lUserID,
                                                  int nChannel,
                                                  LPTJTY_NET_RECT pRectInfo,
                                                  int &nError);
//-----------------------------------------------------------------------------
//�������ܣ���̨Ԥ��λ������á������ת��Ԥ��λ��
//������lUserID[in]  ��¼DVR���ص�ID;
//      nChannel[in] ͨ����
//      dwPTZPresetCmd[in] ���������TJTY_NET_PTZPRESET_CMD��
//      nPresetIndex[in] Ԥ�õ����� 
//      nError[out] ������
//����ֵ��true-�ɹ���false-ʧ�ܡ�

TJTY_NET_API bool __stdcall TJTY_NET_PTZPreset(long lUserID, int nChannel,
                                                DWORD  dwPTZPresetCmd,
                                                int nPresetIndex,
                                                int &nError);
//----------------------------------------------------------------------------
//�������ܣ�Ѳ��·�����޸ġ����á�ִ�еȲ�����
//������lUserID[in]  ��¼DVR���ص�ID;
//      nChannel[in] ͨ����
//      dwPTZCruiseCmd[in] Ѳ�����������TJTY_NET_PTZCRU_CMD;
//      nCruiseIndex[in] Ѳ��·�������
//      nCruisePoint[in] Ѳ�������
//      nPreSetNO[in]  Ԥ��λ��
//      dwStopTime[in]  ͣ��λ��
//      dwSpeed[in]  �ٶ�
//      nError[out] ������
//����ֵ��true-�ɹ���false-ʧ�ܡ�

TJTY_NET_API bool __stdcall TJTY_NET_PTZCruise(long lUserID,
                                               int nChannel,
                                               DWORD  dwPTZCruiseCmd,
                                               int nCruiseIndex,
                                               int nCruisePoint,
                                               int nPreSetNO,
                                               DWORD dwStopTime,
                                               DWORD dwSpeed,
                                               int &nError);

//-----------------------------------------------------------------------------
//�������ܣ���ȡ��̨һ��Ѳ��·������ϸ��Ϣ
//������lUserID[in]  ��¼DVR���ص�ID;
//      nChannel[in] ͨ����
//      dwPTZCruiseCmd[in] Ѳ���������������궨��
//      nCruiseIndex[in] Ѳ��·�������
//      nCruisePoint[out] Ѳ��·����Ϣ�ṹ�����ڴ洢��õ�Ѳ��·����Ϣ
//      nError[out] ������
//����ֵ��true-�ɹ���false-ʧ�ܡ�

TJTY_NET_API bool __stdcall TJTY_NET_GetPTZCruise(long lUserID,
                                                  int nChannel,
                                                  int nCruiseIndex,
                                                  LPTJTY_NET_CRUISE_RET  lpCruiseRet,
                                                  int &nError);
//-----------------------------------------------------------------------------
//�������ܣ�������̨�켣����
//������lUserID[in]  ��¼DVR���ص�ID;
//      nChannel[in] ͨ����
//      dwPTZTrackCmd[in] �켣���������TJTY_NET_PTZTRACK_CMD;
//      nError[out] ������
//����ֵ��true-�ɹ���false-ʧ�ܡ�

TJTY_NET_API bool __stdcall TJTY_NET_PTZTrack(long lUserID,
                                              int nChannel,
                                              DWORD dwPTZTrackCmd,
                                              int nIDTrack,
                                              int &nError);
//-----------------------------------------------------------------------------
//�������ܣ���ȡͨ����
//������lUserID[in]  ��¼DVR���ص�ID;
//      pcChanNames[out] ͨ��������
//      nChanNums[out] ʵ�ʵ�ͨ����Ŀ;
//      nError[out] ������
//����ֵ��true-�ɹ���false-ʧ�ܡ�

TJTY_NET_API bool __stdcall TJTY_NET_GetAllChannelName(long lUserID,
                                                       char pcChanNames[TJTY_NET_MAX_CHANNUM][TJTY_NET_PATHNAME_LEN],
                                                       int &nChanNums,
                                                       int &nError);
//-----------------------------------------------------------------------------
//�������ܣ���ȡ¼����Ϣ
//������lUserID[in]  ��¼DVR���ص�ID;
//      nChannel[in] ͨ����
//      dwCmd ��Ϣ����
//      TYNET_DVR_RECORD[out] ¼����Ϣ�ṹ;
//      nError[out] ������
//����ֵ��true-�ɹ���false-ʧ�ܡ�
TJTY_NET_API bool  __stdcall TJTY_NET_GetDVRRecordInfo( long lUserID,
                                                        int nChannel,
                                                        DWORD dwCmd,
                                                        TYNET_DVR_RECORD &struRecCfg,
                                                        int &nError) ;
//�������ܣ����������е��豸����ȡ�豸�б�
//������dwDVRType  �豸����
//      pSearchDevice_CALLBACK  �����豸�ص�����
//      nError   ������
//����ֵ��true-�ɹ���false-ʧ�ܡ�
TJTY_NET_API bool  __stdcall TJTY_NET_GetDeviceList( DWORD dwDVRType,
                                                     TJTY_NET_SearchDevice_CALLBACK   pSearchDevice_CALLBACK,
                                                     int &nError) ;

//���ûط��ٶȣ����ӣ�
TJTY_NET_API bool _stdcall  TJTY_NET_SetPlaySpeed(long lRemotePlayID,int nSpeed);

//��ȡ�Ѳ���ʱ�䣨���ӣ�
TJTY_NET_API bool _stdcall  TJTY_NET_GetPlayedTime(long lRemotePlayID, DWORD &PlayedTime);

//�ط���ͣ�����ӣ�
TJTY_NET_API bool _stdcall  TJTY_NET_RemotePlayPause(long lRemotePlayID, int &nError);

//�طŻָ������ӣ�
TJTY_NET_API bool _stdcall  TJTY_NET_RemotePlayResume(long lRemotePlayID, int &nError);

//��֡�طţ����ӣ�
TJTY_NET_API bool _stdcall  TJTY_NET_RemotePlayOneByOne(long lRemotePlayID, int &nError);



#endif