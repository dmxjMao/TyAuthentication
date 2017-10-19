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
/*************************常量的宏定义****************************************/
//----------------------------------------------------------------------------
#define TJTY_NET_MAXDISKNUM                    16   //硬盘最大个数
//----------------------------------------------------------------------------
#define TJTY_NET_SYSHEAD                       0    //系统头数据
#define TJTY_NET_STREAMDATA                    1    //音视频混合流数据
#define TJTY_NET_VIDEODATA                     2    //视频流数据
#define TJTY_NET_AUDIODATA                     3    //音频流数据
#define TJTY_NET_NAME_LEN                      40  //名字长度
#define TJTY_NET_PASSWD_LEN                    20  //密码长度
#define TJTY_NET_SERIALNO_LEN                  50 //序列号长度
#define TJTY_NET_VERSION_LEN                   40 //版本号长度
#define TJTY_NET_DVRTYPE_LEN                   20 //DVR 类型长度
#define TJTY_NET_DVRSUBTYPE_LEN                20 //DVR 子类型长度
#define TJTY_NET_MAX_ETHERNET	               2  //设备可配以太网络
#define TJTY_NET_MACADDR_LEN                   20 //mac地址长度
#define TJTY_NET_IPADDR_LEN                    20 //IP 地址长度
#define TJTY_NET_PATHNAME_LEN	               128 //路径长度
#define TJTY_NET_MAX_ALARMOUT                  8   //报警输出最大个数
#define TJTY_NET_MAX_ALARMIN                   16  //报警输入最大个数
#define TJTY_NET_MAX_DAYS                      7   //最大天数
#define TJTY_NET_MAX_TIMESEGMENT               4   //最大时间段数
#define TJTY_NET_MAX_CHANNUM                   64  //最大通道数
#define TJTY_NET_MAX_EXCEPTIONNUM              16  //设备最大异常处理数
#define TJTY_NET_MAX_DISKNUM	               16  //设备最大硬盘数
#define TJTY_NET_MAX_CRUPIONT                  32  //云台巡航路径最大条数
//#define TJTY_NET_MAX_DAYS  7
//#define TJTY_NET_MAX_TIMESEGMENT  8
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*****************************************************************************/

//-----------------------------------------------------------------------------
/*************************回调函数原型定义************************************/
//-----------------------------------------------------------------------------
/*-----------------------------------------------------------------------------
	数据回调函数定义
	lRealHandle:操作句柄;
	dwDataType:数据类型(0--头文件数据流, 1--视频流数据流);
	pBuffer:数据存储缓冲头指针;
	dwBufSize:缓冲数据大小;
	dwUser:用户数据
-----------------------------------------------------------------------------*/
typedef void (__stdcall *TJTY_NET_DataCallBack)( long lPlayHandle,
                                                DWORD dwDataType,
                                                const BYTE *pBuffer,
                                                DWORD dwBufSize,
                                                DWORD dwUser);
//图敏回放数据控制回调函数
//该函数只有在远程回放图敏主机的录像时有效。SDK有数据到达时调用一次此回调函数，
//当此回调函数返回TRUE时，SDK会送数据给应用程序，
//当函数返回FALSE时，SDK会暂停送数据给应用程序，
//程序可根据该本地通道中的数据是否足够来返回是否要SDK送数据给应用程序。
//若没有注册此回调函数，则SDK会不停地送数据给应用程序，会导致远程回放时快进。
typedef bool (__stdcall *TJTY_NET_RemoteRecDataCallBack_TM)(long lPlayID, DWORD dwUser);
//----------------------------------------------------------------------------
//报警消息回调
typedef void(__stdcall *TJTY_NET_ALARM_MSG_CALLBACK )(long lUserID, void *buf,
                                                      DWORD length, DWORD dwUser);

//----------------------------------------------------------------------------
//文件列表回调函数
typedef void(__stdcall *TJTY_NET_FileList_CALLBACK )(long lUserID, void *buf,
                                                     DWORD length, DWORD dwUser);
//----------------------------------------------------------------------------
//语音对讲回调函数
typedef void(__stdcall *TJTY_NET_VoiceData_CALLBACK)(long lTalkID,
                                                     BYTE  *pRecvDataBuffer,
                                                     DWORD  dwBufSize,
                                                     BYTE   byAudioFlag,
                                                     DWORD  dwUser);
//----------------------------------------------------------------------------
//日志列表回调函数
typedef void(__stdcall *TJTY_NET_LogInfo_CALLBACK)(long lUserID, void *buf,
                                                    DWORD length, DWORD dwUser);
//----------------------------------------------------------------------------
//异常回调函数
typedef void(__stdcall *TJTY_NET_ExceptionMsg_CALLBACK)(long lCommand,  //异常信息类型
                                                        long lUserID,   //用户ID
                                                        long lHandle,   //对应的操作句柄
                                                        DWORD dwUser);
//搜索设备回调函数
typedef void(__stdcall *TJTY_NET_SearchDevice_CALLBACK)(void *buf);
//----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
/*************************数据结构定义****************************************/
//-----------------------------------------------------------------------------
//获取参数命令枚举类型
typedef enum
{
    TJTY_NET_GET_DEVICECFG = 100,    //获取设备基本信息
    TJTY_NET_GET_NETCFG,             //获取网络参数
    TJTY_NET_GET_PICCFG,             // 获取图象参数
    TJTY_NET_GET_VILOST,             // 获取视频丢失参数
    TJTY_NET_GET_MOTION,             //获取移动侦测报警参数
    TJTY_NET_GET_HIDEALARM,         //获取视频遮挡参数
    TJTY_NET_GET_RECORDCFG,         //获取录像设置参数
    TJTY_NET_GET_ALARMINCFG,        //获取报警输入参数
    TJTY_NET_GET_ALARMOUTCFG,       //获取报警输出参数
    TJTY_NET_GET_EXCEPTIONCFG,      //获取异常告警信息参数
    TJTY_NET_GET_SYYTEMTIME         //获取DVR系统时间
}TJTY_NET_GETCFG;
//-----------------------------------------------------------------------------
//设置参数命令枚举类型
typedef enum{
    TJTY_NET_SET_DEVICECFG = 200,    //设置设备基本信息
    TJTY_NET_SET_NETCFG,             //设置网络参数
    TJTY_NET_SET_PICCFG,             //设置图象参数
    TJTY_NET_SET_VILOST,             //设置获取视频丢失参数
    TJTY_NET_SET_MOTION,             //设置移动侦测报警参数
    TJTY_NET_SET_HIDEALARM,         //设置视频遮挡参数
    TJTY_NET_SET_RECORDCFG,         //设置录像设置参数
    TJTY_NET_SET_ALARMINCFG,        //设置报警输入参数
    TJTY_NET_SET_ALARMOUTCFG,       //设置报警输出参数
    TJTY_NET_SET_EXCEPTIONCFG,      //设置异常告警信息参数
    TJTY_NET_SET_SYYTEMTIME         //设置DVR系统时间
}TJTY_NET_SETCFG;
//-----------------------------------------------------------------------------
//云台控制命令枚举
typedef enum{
    TJTY_NET_LIGHT_PWRON = 400,   // 接通灯光电源
    TJTY_NET_WIPER_PWRON,         //接通雨刷开关
    TJTY_NET_FAN_PWRON,           //接通风扇开关
    TJTY_NET_HEATER_PWRON,        //接通加热器开关
    TJTY_NET_AUX_PWRON,           //接通辅助设备开关
    TJTY_NET_ZOOM_IN,             //焦距以变大(倍率变大)
    TJTY_NET_ZOOM_OUT,            //焦距变小(倍率变小)
    TJTY_NET_FOCUS_IN,            //焦点前调
    TJTY_NET_FOCUS_OUT,           //焦点后调
    TJTY_NET_IRIS_ENLARGE,        //光圈扩大
    TJTY_NET_IRIS_SHRINK,         //光圈缩小
    TJTY_NET_TILT_UP,             //云台向上
    TJTY_NET_TILT_DOWN,           //云台向下
    TJTY_NET_PAN_LEFT,            //云台左转
    TJTY_NET_PAN_RIGHT,           // 云台右转
    TJTY_NET_UP_LEFT,             //云台左上
    TJTY_NET_UP_RIGHT,            //云台右上
    TJTY_NET_DOWN_LEFT,           //云台左下
    TJTY_NET_DOWN_RIGHT,          //云台右下
    TJTY_NET_PAN_AUTO             //左右自动扫描
}TJTY_NET_PTZCTRL_CMD;
//-----------------------------------------------------------------------------
//预置位操作命令枚举类型
typedef enum{
    TYJTY_NET_SET_PRESET = 300,  //设置预置点
    TYJTY_NET_CLE_PRESET,        //清除预置点
    TYJTY_NET_GOTO_PRESET       //转到预置点
}TJTY_NET_PTZPRESET_CMD;
//-----------------------------------------------------------------------------
//巡航控制命令枚举类型
typedef enum{
    TJTY_NET_FILL_PRE_SEQ = 310, //将预置点加入巡航序列
    //TJTY_NET_SET_SEQ_DWELL,     //设置巡航点停顿时间
    //TJTY_NET_SET_SEQ_SPEED,     //设置巡航速度
    TJTY_NET_CLE_PRE_SEQ,       //将预置点从巡航序列中删除
    TJTY_NET_CLE_SEQ,           //清除巡航路线
    TJTY_NET_RUN_SEQ,           // 开始巡航
    TJTY_NET_STOP_SEQ           // 停止巡航
}TJTY_NET_PTZCRU_CMD;
//-----------------------------------------------------------------------------
//云台轨迹操作命令枚举类型
typedef enum{
    TJTY_NET_STA_MEM_CRUISE = 320,  //开始记录轨迹
    TJTY_NET_STOP_MEM_CRUISE,       //停止记录轨迹
    TJTY_NET_RUN_CRUISE,             //开始运行轨迹
    TJTY_NET_STOP_CRUISE             //停止轨迹
}TJTY_NET_PTZTRACK_CMD;
//----------------------------------------------------------------------------
//智能报警类型定义
typedef enum{
    TJTY_NET_DETECT_EVENT_NOWARN = 0x0000,          //没有报警
    TJTY_NET_DETECT_EVENT_VIDEO_ERROR = 0x001E,	         	//30， 视频信号异常
    TJTY_NET_DETECT_EVENT_PTZ_TARGETLOSS,			//31, PTZ跟踪目标丢失
    TJTY_NET_DETECT_EVENT_OBJ_REMOVED,				//32, 物品被盗
    TJTY_NET_DETECT_EVENT_OBJ_LEAVE,				//33, 物品遗留
    TJTY_NET_DETECT_EVENT_PARKING,				//34, 停车
    TJTY_NET_DETECT_EVENT_PERIMETER,				//35, 警戒区
    TJTY_NET_DETECT_EVENT_ABNORMALVEL,				//36, 非正常速度（移动）
    TJTY_NET_DETECT_EVENT_CONVERSE,				//37，逆行
    TJTY_NET_DETECT_EVENT_TRIPWIRE,				//38, 警戒线
    TJTY_NET_DETECT_EVENT_LOITER,				//39, 闲逛
    TJTY_NET_DETECT_EVENT_SLIPUP,				//40, 滑倒
    TJTY_NET_DETECT_EVENT_SOLDIER,				//41, 哨兵异常
    TJTY_NET_DETECT_EVENT_FIGHT,				//42, 打架
    TJTY_NET_DETECT_EVENT_MUTITRIPWIRE,				//43, 多警戒线
    TJTY_NET_DETECT_EVENT_MLOITER,				//44, 多人闲逛
    TJTY_NET_DETECT_EVENT_FIRE,					//45, 火情
    TJTY_NET_DETECT_EVENT_MOKE,					//46, 烟雾
    TJTY_NET_DETECT_EVENT_DENSITY,				//47, 群体事件（拥挤）
    TJTY_NET_DETECT_EVENT_CLUSTER,				//48, 群体事件（聚集）
    TJTY_NET_DETECT_EVENT_CRDFIGHT,				//49, 群体事件（打架）
    TJTY_NET_DETECT_EVENT_EVACUATE,				//50, 群体事件（疏散）
    TJTY_NET_DETECT_EVENT_CLUTTER,				//51，群体事件（杂乱）
    TJTY_NET_DETECT_EVENT_QUEUE,				//52, 群体事件（排队）
    TJTY_NET_DETECT_EVENT_FACEDISGUISE,				//53, 人脸伪装
    TJTY_NET_DETECT_EVENT_STOLEN_VIDEO,				//54, 偷窥
    TJTY_NET_DETECT_EVENT_OVERHEIGHT,				//55, 超高检测
    TJTY_NET_DETECT_EVENT_ATMOBJLEFT,				//56, ATM加装异物检测
    TJTY_NET_DETECT_EVENT_COUNT,				//57, 人群计数
    TJTY_NET_DETECT_EVENT_HIGH_DENSITY,				//58, 区域人员密度
    TJTY_NET_DETECT_EVENT_CUTFLOW,				//59, 人群切面流量计数
    TJTY_NET_DETECT_EVENT_LINESWAY,				//60, 输电线晃动检测
    TJTY_NET_DETECT_EVENT_RADIAN,				//61, 弧垂异常检测
    TJTY_NET_DETECT_EVENT_APPENDOBJ,				//62, 飘挂物检测
    TJTY_NET_DETECT_EVENT_LINEDISCHANGE,			//63, 输电线间距变化检测
    TJTY_NET_DETECT_EVENT_COVERICE,				//64, 覆冰检测
    TJTY_NET_DETECT_EVENT_TRAVERSE_PLANE,		        //65, 穿越警戒面
    TJTY_NET_DETECT_EVENT_ENTER_AREA,				//66, 进入区域
    TJTY_NET_DETECT_EVENT_LEAVE_AREA,				//67, 离开区域
    TJTY_NET_DETECT_EVENT_INSTRUSION,				//68, 周界入侵
    TJTY_NET_DETECT_EVENT_LEFT_TAKE,				//69, 丢包捡包
    TJTY_NET_DETECT_EVENT_RUN,					//70, 奔跑
    TJTY_NET_DETECT_EVENT_VIOLENT_MOTION,		        //71，剧烈运行
    TJTY_NET_DETECT_EVENT_REACH_HIGHT,				//72, 攀高
    TJTY_NET_DETECT_EVENT_GETUP,				//73， 起身
    TJTY_NET_DETECT_EVENT_TARRY,				//74, 人员滞留
    TJTY_NET_DETECT_EVENT_STICKUP,				//75，贴纸条
    TJTY_NET_DETECT_EVENT_INSTALL_SCANNER,			//76, 安装读卡器
    TJTY_NET_DETECT_EVENT_HUMAN_ENTER,                          //77, 人靠近ATM
    TJTY_NET_DETECT_EVENT_OVER_TIME,                            //78, 操作超时

    TJTY_NET_DETECT_ATM_DETECTAREA,                            //79，检测区域不明物报警
    TJTY_NET_DETECT_ATM_KEYBOARDAREA,	                       //80，键盘区域不明物报警
    TJTY_NET_DETECT_ATM_CARDREGION,	                       //81，插卡口区域不明物报警
    TJTY_NET_DETECT_ATM_SHIELD,		                       //82，键盘罩区域不明物报警
    TJTY_NET_DETECT_ATM_PANEL_CAMERA_BLOCK,                    //83, 面板摄像头被堵
    TJTY_NET_DETECT_ATM_FACE_CAMERA_BLOCK,                     //84, 人脸摄像头被堵
    TJTY_NET_DETECT_ATM_GPI,                                   //85, 开关报警

    TJTY_NET_DETECT_SSB_TRAILING_WITHDRAWALS ,	               //86, 大厅尾随取款报警
    TJTY_NET_DETECT_SSB_PEOPEL_HOVER,			       //87, 大厅人员徘徊
    TJTY_NET_DETECT_SSB_PEOPEL_FELL,			       //88, 大厅人员倒地
    TJTY_NET_DETECT_SSB_REMNANTS,			       //89, 大厅遗留物报警
    TJTY_NET_DETECT_SSB_PEOPELS_GATHER,			       //90, 大厅多人聚集报警
    TJTY_NET_DETECT_SSB_FORBIDDEN_ACCESS,                      //91, 大厅禁止进入
    TJTY_NET_DETECT_SSB_FIGHTING,                              //92, 大厅打架事件
    TJTY_NET_DETECT_SSB_CAMERA_NO_SIGNAL,		       //93, 大厅摄像头无信号报警
    TJTY_NET_DETECT_SSB_CAMERA_ABNORMAL,		       //94, 大厅摄像头异常报警
    TJTY_NET_DETECT_SSB_SPORTS_INVADE,			       //95, 加钞间运动入侵报警
    TJTY_NET_DETECT_SSB_ROOM_CAMERA_NO_SIGNAL,		       //96, 加钞间摄像头无信号报警
    TJTY_NET_DETECT_SSB_ALARM_GPI,			       //97, 开关输入报警(外部报警)

    TJTY_NET_DETECT_EVENT_DUMMY = 0xFFFFFFFF        //将ENUM扩充到4字节，以摒除二进制差异
} TJTY_NET_DETECT_EVENT_ALARM;
//-----------------------------------------------------------------------------
//实时预览网络参数结构
typedef struct		
{
	int		        nLinkMode;	        //连接方式0：TCP方式,1：UDP方式,
                                                        //2：多播方式,3 - RTP方式，
                                                        //4-音视频分开(TCP)
	int		        nCodeType;	       //码流类型(0:主码流,1:子码流，2：标清(D1)
                                                        //3：高清(720P)，4：高清(1080P))
	char			*pchMultiCastIP;       //多播组地址
	HWND					hWnd;		       //播放窗口句柄
    TJTY_NET_DataCallBack   pfRealPlayCallBack;    //预览数据回调
    DWORD                   dwUser;                //用户参数
	int						nChannelNO;		    //预览通道(从1开始)
}TJTY_NET_PLAY_PARA,*LPTJTY_NET_PLAY_PARA;
//----------------------------------------------------------------------------
//文件信息结构
typedef struct
{
    DWORD       FileID;         //文件ID
    char        chName[128];    //文件名
    int		nDisk;           //所在盘符
    DWORD       dwStartcluster;   //起始簇号（大华特有）、智诺
    //BYTE        bHint;		  // 文件定位索引(智诺）
    //BYTE        byNetMultID;	  // (智诺）播放项ID. 网络库上层使用,不是查询所得! 是用户回放的时候用来区分同一个通道的不同项而使用, 是一个输入值!
				  // 由于支持该功能的设备最多支持一个通道16项, 所以传入的值会被内部做取余处理, 范围为[0,15]

    int			nChannel;        //通道号
    int			video_type;    //-1；默认；0:普通录像；1：定时；2：手工；3，报警：4，移动侦测， 5 智能报警
    TJTY_TIME           StartTime;      //开始时间
    TJTY_TIME           EndTime;        //结束时间
    DWORD	    dwFileLength;      //文件大小（Byte）
    BYTE	    partition_no;   //分区号    (智诺用作bHint）
    BYTE	    segment_no;     //段号      (智诺用作byNetMultID）

}TJTY_NET_FILEINFO, *LPTJTY_NET_FILEINFO;
//---------------------------------------------------------------------------
#define MAX_MULTIPLAYBACK_CHANNEL_NUM  64               // 最大多通道预览回放通道数
//文件信息结构
typedef struct
{
	int							nChannels[MAX_MULTIPLAYBACK_CHANNEL_NUM];		// (IN)预览通道号
	int							nChannelNum;									// (IN)预览通道数 
	int							nRemoteType;									//	(IN)回放类型
	int							nFPS;											// (IN)帧率,1~25
	int							nBitRate;										// (IN)码流值,192~1024
	int							nResolution;									//	(IN)分辨率("D1", "HD1", "BCIF", "CIF", "QCIF", "VGA", "QVGA", "SVCD", "QQVGA", "SVGA", "XVGA", "WXGA", 
																						//"SXGA", "WSXGA", "UXGA", "WUXGA", "LFT", "720", "1080", "1_3M", 
																						//"2M","5M","3M","5_0M","1_2M", "1408_1024", "8M", "2560_1920", "960H", "960_720"
																						//,"NHD" , "QNHD", "QQNHD")
	HWND						hWnd;											// (IN)视频播放窗口句柄
	TJTY_NET_DataCallBack		pfRemotePlayCallBack;							// (IN)回放数据回调
	DWORD						dwUser;											// (IN)用户数据	
	bool						bDefault;										// (IN)false不支持该功能直接返回false，true不支持该功能会切换成常态回放。
	bool						bSupport;										// (OUT)返回该厂家是否支持false 不支持， true支持
}TJTY_NET_COMPRESS_REMOTEPLAY, *LPTJTY_NET_COMPRESS_REMOTEPLAY;
//----------------------------------------------------------------------------

//报警信息结构
typedef struct
{
    char hostip[20];     //主机IP
    BYTE videoalarm[64];  //每个字节按位表示，从低到高，第一位为1表示视频丢失，    ///64  //24
                          // 第二位为1表示视频移动，第三位为1表示视频遮挡；
                          //其中videoalarm[0]第五位为1表示硬盘出错，第六位为1表示硬盘满。
                          //第七位为1表示网络错误，第八位为1表示非法访问
    BYTE sensoralarm[16]; //探头报警, 每个字节为1表示该探头有报警；为0表示该探头无报警。
    TJTY_NET_DETECT_EVENT_ALARM detectalarm[32];		//智能检测报警，数组每个元素代表一个通道，如果通道发生报警，参见ENUM类型，值为0时代表无报警
}TJTY_NET_ALARMINFO,  *LPTJTY_NET_ALARMINFO;
//---------------------------------------------------------------------------
//JPEG图像信息结构体(目前只有wPicQuality有作用)
typedef struct
{
    WORD  wPicSize; //抓图尺寸：0=CIF；1=QCIF；2=4CIF；
    WORD  wPicQuality;  //图片质量系数 ：0－最好；1－较好； 2－一般
}TJTY_NET_JPEGPARA, *LPTJTY_NET_JPEGPARA;
//----------------------------------------------------------------------------
//设备基本信息结构
typedef struct
{
    BYTE byChanNum;         //通道个数
    BYTE byStartChan;       //起始通道号
    BYTE byAlarmInPortNum;  //报警输入个数
    BYTE byAlarmOutPortNum; //报警输出个数
    BYTE byDiskNum;         //硬盘个数
    int  nHandleArr[64];    //通道类型句柄数组
    char* pcReserved;       //预留结构
}TJTY_NET_DEVICEINFO, *LPTJTY_NET_DEVICEINFO;
//---------------------------------------------------------------------------
//版本信息结构
typedef struct
{
    char  sSoftwareVersion[TJTY_NET_VERSION_LEN];  //软件版本号
    char  sSoftwareBuildDate[TJTY_NET_VERSION_LEN];  //软件生成日期

    char  sDSPSoftwareVersion[TJTY_NET_VERSION_LEN];  //DSP软件版本
    char  sDSPSoftwareBuildDate[TJTY_NET_VERSION_LEN]; //DSP软件生成日期

    char  sPanelVersion[TJTY_NET_VERSION_LEN];    //前面板版本号
    char  sHardwareVersion[TJTY_NET_VERSION_LEN];   //硬件版本号
}TJTY_NET_VERSIONINFO;
//---------------------------------------------------------------------------
//设备信息结构，只有前三项可以修改
//TJTY_NET_GET_DEVICECFG   获取设备信息命令
//TJTY_NET_SET_DEVICECFG   设置设备基本命令
typedef struct
{
    char  sDVRName[TJTY_NET_NAME_LEN];   //DVR 名称
    DWORD  dwDVRID;    //DVR ID 用于遥控器

    DWORD  dwRecycleRecord;   //是否循环录像（1-是，0-否）

    char  sDVRType[TJTY_NET_DVRSUBTYPE_LEN];       //DVR 子类型

    char  sSerialNumber[TJTY_NET_SERIALNO_LEN];   //序列号
    TJTY_NET_VERSIONINFO lpVersionInfo;

    BYTE  byAlarmInPortNum;  //报警输入个数
    BYTE  byAlarmOutPortNum;  //报警输出个数
    BYTE  byRS232Num;   //232串口个数
    BYTE  byRS485Num;   //485串口个数
    BYTE  byNetworkPortNum;  //网口个数
    BYTE  byDiskCtrlNum;    //硬盘控制器个数
    BYTE  byDiskNum;       //硬盘个数
    BYTE  byChanNum;  //通道个数
    BYTE  byStartChan;   //起始通道号
    BYTE  byAudioNum;   //音频口个数
    BYTE  byIPChanNum;  //最大数字通道数
}TJTY_NET_DEVICECFG, *LPTJTY_NET_DEVICECFG;
//---------------------------------------------------------------------------
//以太网结构
typedef struct
{
    char  chDVRIP[TJTY_NET_IPADDR_LEN];     //
    char  chGatewayIP[TJTY_NET_IPADDR_LEN];   //IP 地址
    char  chDVRIPMask[TJTY_NET_IPADDR_LEN];   //子网掩码网关

    DWORD  dwNetInterface;   //网络接口：1－10MBase-T；2－10MBase-T全双工；3－100MBase-TX；4－100M全双工；
                            //5－10M/100M/1000M自适应；6- 1000M全双工；

    WORD  wDVRPort;          //端口号

    char  chMACAddr[TJTY_NET_MACADDR_LEN];  //网卡物理地址

}TJTY_NET_ETHERNET;
//-----------------------------------------------------------------------------
//PPPoE 结构
typedef struct
{
    DWORD  dwPPPoE;        //是否启用（1-启用，0-不启用）
    char  chPPPoEUser[TJTY_NET_NAME_LEN];      //PPPoE 用户名
    char  chPPPoEPassword[TJTY_NET_PASSWD_LEN];  //密码
    char  chPPPoEIP[TJTY_NET_IPADDR_LEN];  // PPPoE  IP 地址
}TJTY_NET_PPPOECFG, *LPTJTY_NET_PPPOECFG;
//-----------------------------------------------------------------------------
//网络参数结构
// TJTY_NET_GET_NETCFG  获取网络参数命令
// TJTY_NET_SET_NETCFG  设置网络参数命令
typedef struct
{
    TJTY_NET_ETHERNET struEtherNet[TJTY_NET_MAX_ETHERNET];   // 以太网口参数

    char  chManageHostIP[TJTY_NET_IPADDR_LEN];     //管理主机IP
    WORD  wManageHostPort;   //管理主机端口号

    char  chIPServerIP[TJTY_NET_IPADDR_LEN];   //IP解析服务器IP

    char  chMultiCastIP[TJTY_NET_IPADDR_LEN];   //多播组地址

    char  chNFSIP[TJTY_NET_IPADDR_LEN];   //NAS 服务器IP
    char  sNFSDirectory[TJTY_NET_PATHNAME_LEN];    //NAS 存储目录

    WORD  wHttpPort;       //HTTP 端口号

    TJTY_NET_PPPOECFG struPPPOE;   //PPPoE 结构
}TJTY_NET_NETCFG,*LPTJTY_NET_NETCFG;
//-----------------------------------------------------------------------------
//码流参数结构
typedef struct
{
    BYTE  byStreamType;    //码流类型：0－视频流；1－复合流
    BYTE  byResolution;    //分辨率：0－DCIF； 1－CIF，2－QCIF,；
                            // 3－4CIF；4－2CIF; 5--其它

    BYTE  byBitrateType;   //码率类型：0－变码率；1－定码率
    BYTE  byPicQuality;   //图象质量：0－最好；1－次好；
                       // 2－较好；3－一般；4－较差；5－差

    DWORD  dwVideoBitrate; //码率： 0－保留； 1－16K(保留)； 2－32K；3－48k；
                       //4－64K；5－80K；6－96K；7－128K；8－160k；9－192K；
                       //10－224K；11－256K；12－320K；13－384K；14－448K；
                       //15－512K；16－640K；17－768K；18－896K；19－1024K；
                       //20－1280K；21－1536K；22－1792K；23－2048K

    DWORD  dwVideoFrameRate; // 帧率：0－全部；1－1/16；2－1/8；3－1/4；4－1/2；
                         //5－1；6－2；7－4；8－6；9－8；10－10；11－12；12－16；13－20
}TJTY_NET_COMPRESSION_INFO,*LPTJTY_NET_COMPRESSION_INFO;

//----------------------------------------------------------------------------
typedef struct
{
    BYTE  byBrightness;         //亮度，取值范围0～255
    BYTE  byContrast;          //对比度，取值范围0～255
    BYTE  bySaturation;       //饱和度，取值范围0～255
    BYTE  byHue;             //色调，取值范围为0～255
}TJTY_NET_VIDEOEFFECT, *LPTJTY_NET_VIDEOEFFECT;
//----------------------------------------------------------------------------
//图像参数结构
//TJTY_NET_GET_PICCFG     获取图象参数命令
//TJTY_NET_SET_PICCFG     设置图象参数命令
typedef struct
{
    char  sChanName[TJTY_NET_NAME_LEN];  //通道名称

    DWORD  dwVideoFormat;       //视频制式：1－NTSC； 2－PAL

    BYTE  byBrightness;         //亮度，取值范围0～255
    BYTE  byContrast;          //对比度，取值范围0～255
    BYTE  bySaturation;       //饱和度，取值范围0～255
    BYTE  byHue;             //色调，取值范围为0～255

    TJTY_NET_COMPRESSION_INFO  struMainStreamPara;  //主码流参数

    TJTY_NET_COMPRESSION_INFO  struSubStreamPara;    //子码流参数

    DWORD  dwShowChanName;   //是否显示通道名（0－不显示；1－显示，预览区域大小704*576）
    WORD  wShowNameTopLeftX; // 通道名称显示位置左上角的x坐标
    WORD  wShowNameTopLeftY;  //通道名称显示位置右上角的x坐标

    DWORD  dwEnableHide;  //是否启动区域遮蔽（以色块盖住图像中需隐藏部分）：0－否，1－是
    WORD  wHideAreaTopLeftX;  //遮蔽区域的x坐标
    WORD  wHideAreaTopLeftY;   //遮蔽区域的y坐标
    WORD  wHideAreaWidth;   //遮蔽区域的宽度
    WORD  wHideAreaHeight;  //遮蔽区域的高度

    DWORD  dwShowOsd;    //预览的图象上是否显示OSD：0－不显示；1－显示
    WORD  wOSDTopLeftX;  //OSD左上角的x坐标
    WORD  wOSDTopLeftY;  //OSD左上角的y坐标

    BYTE  byDispWeek;   //是否显示星期
}TJTY_NET_PICCFG, *LPTJTY_NET_PICCFG;
//-----------------------------------------------------------------------------
//#define TJTY_NET_GET_VILOST    103  // 获取视频丢失参数
//#define TJTY_NET_SET_VILOST    203  // 设置视频丢失参数

//布防时间结构
typedef struct
{
    BYTE  byStartHour;   //开始时间 小时
    BYTE  byStartMin;    //开始时间 分钟
    BYTE  byStopHour;    //结束时间 小时
    BYTE  byStopMin;    //结束时间 分钟
}TJTY_NET_SCHEDTIME, *LPTJTY_NET_SCHEDTIME;
//-----------------------------------------------------------------------------
//告警信息处理结构
typedef struct
{
    DWORD  dwHandleType;     //处理方式，多种处理方式的"或"值：
                         // 0x00－不处理；0x01－监视器上警告；0x02－声音警告；
                         //0x04－上传中心；0x08－触发报警输出；

    BYTE  byRelAlarmOut[TJTY_NET_MAX_ALARMOUT];    //报警触发的输出通道，
                                                    //数组元素值为1表示触发该路报警输出
}TJTY_NET_HANDLEEXCEPTION;
//---------------------------------------------------------------------------
//视频丢失处理结构
//TJTY_NET_GET_VILOST    获取视频丢失参数命令
//TJTY_NET_SET_VILOST    设置视频丢失参数命令
typedef struct
{
    BYTE  byEnableHandleVILost;     //是否处理（1-处理，0-不处理）

    TJTY_NET_HANDLEEXCEPTION  strVILostHandleType;  //处理方式

    TJTY_NET_SCHEDTIME  struAlarmTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];  //布防时间
}TJTY_NET_VILOST, *LPTJTY_NET_VILOST;
//-----------------------------------------------------------------------------
//移动侦测报警结构
//TJTY_NET_GET_MOTION      获取移动侦测报警参数参数
//TJTY_NET_SET_MOTION      设置移动侦测报警参数参数

typedef struct
{
    BYTE  byMotionSenstive;  //移动侦测灵敏度：0-5数值越高越灵敏，0xff关闭
    BYTE  byEnableHandleMotion;  //是否处理（1-处理，0-不处理）

    TJTY_NET_HANDLEEXCEPTION  strMotionHandleType;  //处理方式

    TJTY_NET_SCHEDTIME  struAlarmTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];  //布防时间

    BYTE  byRelRecordChan[TJTY_NET_MAX_CHANNUM];  //报警触发的录象通道,数组元素值为1表示触发该通道报警
}TJTY_NET_MOTION, *LPTJTY_NET_MOTION;
//----------------------------------------------------------------------------
//视频遮挡报警结构
//TJTY_NET_GET_HIDEALARM  获取视频遮挡报警参数参数
//TJTY_NET_SET_HIDEALARM  设置视频遮挡报警参数参数

typedef struct
{
    DWORD  dwEnableHideAlarm;  //是否启动遮挡报警：0－否；1－低灵敏度；2－中灵敏度；3－高灵敏度

    TJTY_NET_HANDLEEXCEPTION  strAreaHandleType;  //处理方式

    TJTY_NET_SCHEDTIME  struAlarmTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];  //布防时间
}TJTY_NET_HIDEALARM, *LPTJTY_NET_HIDEALARM;
//-----------------------------------------------------------------------------
//全天录像结构
typedef struct
{
    WORD  wAllDayRecord;   //是否全天录像

    BYTE  byRecordType;  //0－定时录像；1－移动侦测录像；2－报警录像；3－移动侦测或者报警录像；
                     //4－移动侦测录像和报警录像；5－命令触发录像；6－手动录像
}TJTY_NET_RECORDDAY;
//-----------------------------------------------------------------------------
//时间段录像结构
typedef struct
{
    TJTY_NET_SCHEDTIME  struRecordTime;   //时间段

    BYTE  byRecordType;  //0－定时录像；1－移动侦测录像；2－报警录像；3－移动侦测或者报警录像；
                     //4－移动侦测录像和报警录像；5－命令触发录像；6－手动录像

}TJTY_NET_RECORDSCHED,*LPTJTY_NET_RECORDSCHED;
//-----------------------------------------------------------------------------
//录像参数结构
//TJTY_NET_GET_RECORDCFG     获取录像设置参数命令
//TJTY_NET_SET_RECORDCFG     设置录像设置参数命令
typedef struct
{
    DWORD  dwRecord;   //是否录像 ：0－否；1－是

    TJTY_NET_RECORDDAY  struRecAllDay[TJTY_NET_MAX_DAYS];    //全天录像布防
    TJTY_NET_RECORDSCHED  struRecordSched[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT]; //录像布防

    DWORD  dwRecordTime;  //录像延时
    DWORD  dwPreRecordTime;  //预录时间

}TJTY_NET_RECORD,*LPTJTY_NET_RECORD;
//---------------------------------------------------------------------------


//报警输入参数结构
//TJTY_NET_GET_ALARMINCFG    获取报警输入参数命令
//TJTY_NET_SET_ALARMINCFG    设置报警输入参数命令

typedef struct
{
    char  sAlarmInName[TJTY_NET_NAME_LEN];   //报警输入名称

    BYTE  byAlarmType;   //报警器类型：0－常开；1－常闭
    BYTE  byAlarmInHandle;   //是否处理

    TJTY_NET_HANDLEEXCEPTION  struAlarmHandleType;  //处理方式

    TJTY_NET_SCHEDTIME  struAlarmTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];  //布防时间

    BYTE  byRelRecordChan[TJTY_NET_MAX_CHANNUM];  //报警触发的录象通道,
                                              //数组元素值为1表示触发该通道报警

    BYTE  byEnablePreset[TJTY_NET_MAX_CHANNUM];  //是否调用预置点，
                                             //数组元素值为1表示该通道调用了预置点
    BYTE  byPresetNo[TJTY_NET_MAX_CHANNUM];    //调用的云台预置点序号，
    BYTE  byEnableCruise[TJTY_NET_MAX_CHANNUM];  //该通道是否调用巡航，值为1表示调用了巡航
    BYTE  byCruiseNo[TJTY_NET_MAX_CHANNUM];  //调用的云台的巡航路线序号
    BYTE  byEnablePtzTrack[TJTY_NET_MAX_CHANNUM];  //该通道是否调用轨迹，值为1表示调用了轨迹
    BYTE  byPTZTrack[TJTY_NET_MAX_CHANNUM]; //调用的云台的轨迹序号
}TJTY_NET_ALARMINCFG,*LPTJTY_NET_ALARMINCFG;
//-----------------------------------------------------------------------------
//报警输出参数结构
//TJTY_NET_GET_ALARMOUTCFG       获取报警输出参数命令
//TJTY_NET_SET_ALARMOUTCFG       设置报警输出参数命令

typedef struct{

    char  sAlarmOutName[TJTY_NET_NAME_LEN];   //报警输出口名称
    DWORD  dwAlarmOutDelay;   //输出信号状态延时时间

    TJTY_NET_SCHEDTIME struAlarmOutTime[TJTY_NET_MAX_DAYS][TJTY_NET_MAX_TIMESEGMENT];
    //报警输出激活时间段
}TJTY_NET_ALARMOUTCFG, *LPTJTY_NET_ALARMOUTCFG;
//-----------------------------------------------------------------------------
//异常告警信息参数结构
//TJTY_NET_GET_EXCEPTIONCFG    获取异常告警信息参数命令
//TJTY_NET_SET_EXCEPTIONCFG    设置异常告警信息参数命令

typedef struct
{

    TJTY_NET_HANDLEEXCEPTION struExceptionHandleType[TJTY_NET_MAX_EXCEPTIONNUM];
    //异常信息处理方式  0－硬盘满；1－硬盘出错；2－网线断；3－IP 地址冲突；
    //4－非法访问；5－输入/输出视频制式不匹配，

}TJTY_NET_EXCEPTION, *LPTJTY_NET_EXCEPTION;
//-----------------------------------------------------------------------------
//时间设置相关
//TJTY_NET_GET_SYYTEMTIME     获取DVR系统时间命令
//TJTY_NET_SET_SYYTEMTIME     设置DVR系统时间命令（校时）
//时间结构详见 TJTY_TIME；
//-----------------------------------------------------------------------------
//硬盘状态结构
typedef struct
{
    DWORD  dwVolume;   //硬盘容量 (MB)
    DWORD  dwFreeSpace;  //硬盘剩余空间 (MB)
    DWORD  dwHardDiskStatic;  //硬盘状态 0－活动；1－休眠；2－不正常等
}TJTY_NET_DISKSTATE,*LPTJTY_NET_DISKSTATE;
//---------------------------------------------------------------------------
//通道状态结构
typedef struct
{
    BYTE  byRecordStatic;      // 录像状态：0－不录像；1－录像
    BYTE  bySignalStatic;      // 信号状态：0－正常；1－信号丢失
    BYTE  byHardwareStatic;    // 硬件状态：0－正常；1－异常，例如DSP死掉
    int   iRecordDays ;        // 录像天数
}TJTY_NET_CHANNELSTATE,*LPTJTY_NET_CHANNELSTATE;
//-----------------------------------------------------------------------------
//设备状态结构
typedef struct
{                                        
    DWORD  dwDeviceStatic;            //设备的状态：0－正常，1－CPU占用率太高，超过85%；
										//2－硬件错误，例如串口死掉

    TJTY_NET_DISKSTATE struHardDiskStatic[TJTY_NET_MAX_DISKNUM];  //硬盘状态

    TJTY_NET_CHANNELSTATE struChanStatic[TJTY_NET_MAX_CHANNUM];  //通道参数

}TJTY_NET_WORKSTATE,*LPTJTY_NET_WORKSTATE;
//----------------------------------------------------------------------------
//日志信息结构
typedef struct
{
    TJTY_TIME strLogTime;   //记录日志时间

    char chLogType[20];  //日志类型
    char chLogInfo[80];  //日志内容
    //DWORD  dwMajorType;  //主类型
    //DWORD  dwMinorType;  //子类型

    char  sPanelUser[TJTY_NET_NAME_LEN];  //前端操作用户
    char  sNetUser[TJTY_NET_NAME_LEN];  //网络操作用户

    DWORD  dwChannel;   //通道号
    DWORD  dwDiskNumber; //磁盘号
    
    DWORD  dwAlarmInPort;  //报警输入端口
    DWORD  dwAlarmOutPort; //报警输出端口

}TJTY_NET_LOG, *LPTJTY_NET_LOG;
//-----------------------------------------------------------------------------
//区域结构
typedef struct
{
    int  xTop;    //方框起始点的x坐标
    int  yTop;  //方框起始点的y坐标
    int  xBottom; //方框结束点的x坐标
    int  yBottom; //方框结束点的y坐标
}TJTY_NET_RECT, *LPTJTY_NET_RECT;
//----------------------------------------------------------------------------
//巡航点信息结构
typedef struct
{
    BYTE byPresetNum;   //预置点序号
    BYTE bynDwell;     //停留时间
    BYTE bynSpeed;     //速度
    BYTE byReserve;     //保留
}TJTY_NET_CRUISE_POINT, *LPTJTY_NET_CRUISE_POINT;
//---------------------------------------------------------------------------
//巡航路径信息结构
typedef struct{

    TJTY_NET_CRUISE_POINT struCruisePoint[TJTY_NET_MAX_CRUPIONT];

}TJTY_NET_CRUISE_RET, *LPTJTY_NET_CRUISE_RET;

//搜索设备结果信息
typedef struct Device_SEARCH_RESULT
{
    char pcIpAddr[128];				//设备IP地址
    int  nPort;					//设备服务端口
    char pcXAddr[128];				//设备服务地址
    char pcEPAddr[128];				//设备EndPoint参照
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
  BYTE                   byRecordType;   /* 录象类型 0:定时录像，1:移动侦测，2:报警录像，3:动测|报警，4:动测&报警 5:命令触发, 6: 智能录像,10-PIR报警，11-无线报警，12-呼救报警，13-PIR|无线报警|呼救报警 ,15 无设定*/
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
/*************************函数接口*******************************************/
//----------------------------------------------------------------------------
//初始化相关
TJTY_NET_API bool __stdcall TJTY_NET_Init(DWORD dwDVRType, int &nError);

//设置异常回调函数
TJTY_NET_API bool __stdcall TJTY_NET_SetExceptionCallBack
                            (TJTY_NET_ExceptionMsg_CALLBACK pfExceptionCallBack,
                            DWORD dwUser, int &nError);

TJTY_NET_API bool __stdcall TJTY_NET_CleanUp();

//设置报警回调
TJTY_NET_API bool __stdcall TJTY_NET_SetAlarmMessCallBack(TJTY_NET_ALARM_MSG_CALLBACK pfAlarmMessCallBack,
                                                         int &nError);

//设置回调数据控制回调函数(图敏专用)
TJTY_NET_API bool __stdcall TJTY_NET_SetRemoteRecDataCallBack_TM(
                            TJTY_NET_RemoteRecDataCallBack_TM fpRemoteRecDataCallBack_TM);

//登录DVR相关
TJTY_NET_API bool __stdcall TJTY_NET_LogInDVR(TJTY_DVRTYPE  nDVRType,
                                             char          *pchDvrIP,
                                             UINT          unPort,
                                             char          *pchName,
                                             char          *pchPass,
                                             LPTJTY_NET_DEVICEINFO lpDeviceInfo,
                                             long          &lUserID);

TJTY_NET_API bool __stdcall TJTY_NET_QuitDVR(long lUserID);

//预览相关
TJTY_NET_API bool __stdcall TJTY_NET_RealPlay(long lUserID, LPTJTY_NET_PLAY_PARA lpRealPlayInfo, long &lPlayID);

TJTY_NET_API bool __stdcall TJTY_NET_StopRealPlay(long lPlayID);

//保存捕获到的数据到指定的文件中
//函数功能：保存预览数据到指定的文件
//输入参数：lPlayID[in] 预览句柄
//          chFileName[in] 文件名
//          nError[out] 错误码
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall TJTY_NET_SaveRealData(long lPlayID, char *chFileName, int &nError);

//停止保存捕获到的数据
//函数功能：保存预览数据到指定的文件
//输入参数：lPlayID[in] 正在保存数据的预览句柄
//返回值：true 成功，false 失败
TJTY_NET_API bool __stdcall TJTY_NET_StopSaveRealData(long lPlayID);

//抓图（BMP格式）
//函数功能：对正在预览的图像抓图
//输入参数：lPlayID[in] 预览句柄
//          chPicFileName[in] 保存图片的文件名
//          nError[out] 错误码
//返回值：true 成功，false 失败；
//说明: 当用户采用数据回调方式预览时，该函数无效。
TJTY_NET_API bool __stdcall TJTY_NET_CapturePicture(long lPlayID, char *chPicFileName, int &nError);

//抓JPEG图,保存成文件
//函数功能：抓JPEG图,保存成文件(不需要打开通道预览)
//输入参数：lUserID[in] 登录DVR返回的句柄
//          nChannel[in] 通道号
//          lpJPEGPara[in] JPEG图像信息结构
//          chPicFileName[in] 保存图片的名称
//          nError[out] 错误码
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall TJTY_NET_CaptureJPEGPicture(long lUserID,
                                                        int nChannel,
                                                        LPTJTY_NET_JPEGPARA lpJPEGPara,
                                                        char *chPicFileName,
                                                        int &nError);

//抓JPEG图,保存到内存
//函数功能：抓JPEG图,保存到内存(不需要打开通道预览)
//输入参数：lUserID[in] 登录DVR返回的句柄
//          nChannel[in] 通道号
//          lpJPEGPara[in] JPEG图像信息结构
//          chPicBuf[in] 保存图片的缓冲区
//          dwPicSize[in] 缓冲区大小
//          lpSizeReturned[out] 实际返回的数据大小
//          nError[out] 错误码
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall	TJTY_NET_CaptureJPEGPicToMemory(long lUserID,
                                                        int nChannel,
                                                        LPTJTY_NET_JPEGPARA lpJPEGPara,
                                                        char *chPicBuf,
                                                        DWORD  dwPicSize,
                                                        LPDWORD  lpSizeReturned,
                                                        int &nError);

//获取视频参数
//函数功能：获取视频图像参数，包括色度、亮度、饱和度、对比度
//输入参数：lUserID[in] 登录DVR返回的句柄
//          nChannel[in] 通道号
//          lpstruVideoEffect[out] 图像参数结构
//          nError[out] 错误码
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall TJTY_NET_GetVideoEffect(long lUserID,
                                                    int nChannel,
                                                    LPTJTY_NET_VIDEOEFFECT lpstruVideoEffect,
                                                    int &nError);

//设置视频参数
//函数功能：设置视频图像参数，包括色度、亮度、饱和度、对比度
//输入参数：lUserID[in] 登录DVR返回的句柄
//          nChannel[in] 通道号
//          lpstruVideoEffect[in] 图像参数结构
//          nError[out] 错误码
//返回值：true 成功，false 失败；
//说明：该函数将改变前端主机对应通道的视频参数设置。
TJTY_NET_API bool __stdcall TJTY_NET_SetVideoEffect(long lUserID,
                                                    int nChannel,
                                                    LPTJTY_NET_VIDEOEFFECT lpstruVideoEffect,
                                                    int &nError);

//生成一个关键帧
//函数功能：请求DVR生成一个关键帧
//输入参数：lUserID[in] 登录DVR返回的句柄
//          nChannel[in] 通道号
//          nType[in] 码流类型0-主码流，1-子码流
TJTY_NET_API bool __stdcall TJTY_NET_MakeKeyFrame(long lUserID, int nChannel, int nType);

//检索文件列表
TJTY_NET_API bool __stdcall TJTY_NET_SearchFileList(long                lUserID,
                                                   int                   nChannelNO,
                                                   TJTY_TIME             StartTime,
                                                   TJTY_TIME             EndTime,
                                                   int                   nFileType,
                                                   char                  *chCardID,
                                                   TJTY_NET_FileList_CALLBACK  pfFileListCallBack,
                                                   DWORD                 dwUser,
	                                                int                   &nError);
//停止检索
TJTY_NET_API bool __stdcall TJTY_NET_StopSearchFile(long lUserID);

//停止某一路通道检索
//输入参数：lUserID[in] 登录DVR返回的句柄
//          nChannel[in] 通道号
TJTY_NET_API bool __stdcall TJTY_NET_StopSearchFileByChannel(long lUserID, int  nChannelNO);


//锁定文件
//函数功能：锁定指定的录像文件，锁定后该文件将不会自动删除或者覆盖
//输入参数：lUserID[in] 登录DVR返回的句柄
//          pFileInfo[in] 文件信息
//          nError[out] 错误码
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall TJTY_NET_LockFileByName(long lUserID,
                                                    LPTJTY_NET_FILEINFO pFileInfo,
                                                    int &nError);

//解锁文件
//函数功能：解锁指定的录像文件
//输入参数：lUserID[in] 登录DVR返回的句柄
//          pFileInfo[in] 文件信息
//          nError[out] 错误码
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall TJTY_NET_UnLockFileByName(long lUserID,
                                                      LPTJTY_NET_FILEINFO pFileInfo,
                                                      int &nError);

//回放相关
//按文件信息回放
TJTY_NET_API bool __stdcall TJTY_NET_RemotePlayByName(long                      lUserID,
                                                     LPTJTY_NET_FILEINFO       pFileInfo,
                                                     HWND	                     hWnd,			    //播放窗口句柄
                                                     TJTY_NET_DataCallBack     pfRemotePlayCallBack,
                                                     DWORD                     dwUser,
                                                     DWORD                     &dwFileLength,
                                                     long                      &lPlayID);

//按时间回放
TJTY_NET_API bool __stdcall TJTY_NET_RemotePlayByTime(long                      lUserID,
                                                     int                       nChannel,
                                                     TJTY_TIME                 StartTime,
                                                     TJTY_TIME                 EndTime,
                                                     HWND	               hWnd,
                                                     TJTY_NET_DataCallBack     pfRemotePlayCallBack,
                                                     DWORD                     dwUser,
                                                     DWORD                     &dwFileLength,
                                                     long                      &lPlayID);
//二次压缩按文件回放
TJTY_NET_API bool __stdcall TJTY_NET_CompressRemotePlayByName(long                      lUserID,
															LPTJTY_NET_FILEINFO       pFileInfo,
															LPTJTY_NET_COMPRESS_REMOTEPLAY	pModeParam,
															DWORD                     &dwFileLength,
															long                      &lPlayID);
//二次压缩按时间回放
TJTY_NET_API bool __stdcall TJTY_NET_CompressRemotePlayByTime(long                      lUserID,
													  TJTY_TIME                 StartTime,
													  TJTY_TIME                 EndTime,
													LPTJTY_NET_COMPRESS_REMOTEPLAY	pModeParam,	
													DWORD                     &dwFileLength,
													  long                      &lPlayID);

//停止回放
TJTY_NET_API bool __stdcall TJTY_NET_StopRemotePlay(long lRemotePlayID);

//设置回放进度
TJTY_NET_API bool __stdcall TJTY_NET_SetRemotePlayPos(long lRemotePlayID, int nPos);

//获取回放进度
TJTY_NET_API bool __stdcall TJTY_NET_GetRemotePlayPos(long lRemotePlayID, int &nPos);

//下载相关
//按文件信息下载
TJTY_NET_API bool __stdcall TJTY_NET_DownLoadByName(long                      lUserID,
                                                   LPTJTY_NET_FILEINFO       pFileInfo,
                                                   char*                     chSaveFileName,
                                                   TJTY_NET_DataCallBack     pfDownLoadCallBack,
                                                   DWORD                     dwUser,
                                                   DWORD                     &dwFileLength,
                                                   long                      &lDownID);

//按时间下载
TJTY_NET_API bool __stdcall TJTY_NET_DownLoadByTime(long                      lUserID,
                                                   int                       nChannel,
                                                   TJTY_TIME                 StartTime,
                                                   TJTY_TIME                 EndTime,
                                                   char*                     chSaveFileName,
                                                   TJTY_NET_DataCallBack     pfDownLoadCallBack,
                                                   DWORD                     dwUser,
                                                   DWORD                     &dwFileLength,
                                                   long                      &lDownID);
//停止下载
TJTY_NET_API bool __stdcall TJTY_NET_StopDownLoad(long lDownLoadID);

//获取下载进度
TJTY_NET_API bool __stdcall TJTY_NET_GetDownLoadPos(long lDownLoadID, int &nPos);

//保存所回放的录像数据
//函数功能：保存回放数据到指定的文件
//输入参数：lRemotePlayID[in] 回放句柄
//          chFileName[in] 文件名
//          nError[out] 错误码
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall TJTY_NET_SaveRemotePlayData(long lRemotePlayID,
                                                        char *chFileName,
                                                        int &nError);

//停止保存回放的录像数据
//函数功能：停止保存回放数据到文件
//输入参数：lRemotePlayID[in] 正在保存数据的回放句柄
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall TJTY_NET_StopSaveRemoteData(long lRemotePlayID);

//对讲相关
TJTY_NET_API bool __stdcall TJTY_NET_StartTalk(long lUserID, int nLinkChannel,
                                               TJTY_NET_VoiceData_CALLBACK pfVioceCallBack,
                                               DWORD dwUser,
                                               long &lTalkID);

TJTY_NET_API bool __stdcall TJTY_NET_StopTalk(long lTalkID);

//设置声音音量
TJTY_NET_API bool __stdcall TJTY_SetVoiceVolume(long lTalkID, int nVolume);

//启动语音转发
//函数功能：启动语音转发
//参数：lUserID[in] 登录DVR返回的句柄
//      nLinkChannel[in]  对讲通道
//      pfVioceCallBack[in] 语音回调函数
//      dwUser[in] 用户参数
//      lTalkID[out] 返回的语音转发操作句柄
TJTY_NET_API bool __stdcall TJTY_NET_StartVoiceCom_MR(long lUserID, int nLinkChannel,
                                                      TJTY_NET_VoiceData_CALLBACK pfVioceCallBack,
                                                      DWORD dwUser,
                                                      long &lTalkID);

//语音转发
//函数功能：语音转发
//参数：lTalkID[in] 语音转发操作句柄
//      pSendBuf[in]  转发的数据缓冲
//      dwBufSize[in] 语缓冲区大小
TJTY_NET_API bool __stdcall TJTY_NET_VoiceComSendData(long lTalkID, char *pSendBuf, DWORD dwBufSize);

//停止语音转发
TJTY_NET_API bool __stdcall TJTY_NET_StopVoiceCom(long lTalkID);

//群呼相关
TJTY_NET_API bool __stdcall TJTY_NET_StartMultiTalk(long *lpUserID, int nDVRNumber, int nDVRType, int &nError);

TJTY_NET_API bool __stdcall TJTY_NET_StopMultiTalk();

TJTY_NET_API bool __stdcall TJTY_NET_AddDVRToMulti(long lUserID,
                                                   int nDVRType,
                                                   int &nError);

TJTY_NET_API bool __stdcall TJTY_NET_DelDVRFromMulti(long lUserID);

//报警相关
TJTY_NET_API bool __stdcall TJTY_NET_StartListen(long lUserID, DWORD dwUser);

TJTY_NET_API bool __stdcall TJTY_NET_StopListen(long lUserID);

//-----------------------------------------------------------------------------
//设备参数获取与设置部分
//-----------------------------------------------------------------------------
//整体获取和设置参数
//函数功能：整体获取与设置DVR参数，该函数提供一个设置界面，所有操作均在内部封装
//参数：lUserID[in]    登录DVR返回的ID;
//      nError[out]    错误码
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall TJTY_NET_GetAndSetConfig(long lUserID, int &nError);
//-----------------------------------------------------------------------------
//获取设备参数函数
//函数功能：获取DVR参数
//参数：lUserID[in]    登录DVR返回的ID;
//      dwCommond[in]  命令参数，见TJTY_NET_GETCFG；
//      lChannel[in]   通道号
//      lpOutBuf[out]   用于存储参数信息的结构指针
//      dwBufSize[in]  lpOutBuf缓冲区的长度
//      nError[out]    错误码
//返回值：true 成功，false 失败；

TJTY_NET_API bool __stdcall TJTY_NET_GetDVRConfig(long lUserID,
                                                 DWORD   dwCommond,
                                                 long    lChannel,
                                                 LPVOID  lpOutBuf,
                                                 DWORD   dwBufSize,
                                                 int     &nError);

//-----------------------------------------------------------------------------
//设置设备参数函数
//函数功能：设置DVR参数
//参数：lUserID[in]    登录DVR返回的ID;
//      dwCommond[in]  命令参数，见TJTY_NET_SETCFG；
//      lChannel[in]   通道号
//      lpInBuf[in]    存储参数信息的结构指针
//      dwBufSize[in]  lpInBuf缓冲区的长度
//      nError[out]    错误码
//返回值：true 成功，false 失败；

TJTY_NET_API bool __stdcall TJTY_NET_SetDVRConfig(long lUserID,
                                                  DWORD   dwCommond,
                                                  long    lChannel,
                                                  LPVOID  lpInBuf,
                                                  DWORD   dwBufSize,
                                                  int     &nError);

//----------------------------------------------------------------------------
//恢复出厂默认设置
//函数功能：恢复DVR出厂默认设置
//参数：lUserID[in]    登录DVR返回的ID;
//      nError[out]    错误码
//返回值：true 成功，false 失败；
TJTY_NET_API bool __stdcall TJTY_NET_RestoreConfig(long lUserID, int &nError);
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//获取设备状态函数
//函数功能：获取设备状态
//参数：lUserID[in]    登录DVR返回的ID;
//      lpWorkStateBuf[out] 存储设备状态信息的结构指针
//      nError[out]    错误码
//返回值：true 成功，false 失败；

TJTY_NET_API bool __stdcall TJTY_NET_GetDVRWorkState(long lUserID,
                                                     LPTJTY_NET_WORKSTATE lpWorkStateBuf,
                                                     int &nError);
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//获取报警输入布防状态函数
//函数功能：获取报警输入布防状态
//参数：lUserID[in]    登录DVR返回的ID;
//      nAlarmInNO[in] 报警输入端口号
//      nAlarmInState[out]  布防状态（1-布防， 0-撤防）
//      nError[out]    错误码
//返回值：true 成功，false 失败；

TJTY_NET_API bool __stdcall TJTY_NET_GetDVRAlarmInState(long lUserID,
                                                        int   nAlarmInNO,
                                                        int   &nAlarmInState,
                                                        int   &nError);
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//报警输入布撤防控制函数
//函数功能：布撤防
//参数：lUserID[in]    登录DVR返回的ID;
//      nAlarmInNO[in] 报警输入端口号
//      bAlarm[in]   布撤防命令（true-布防， false-撤防）
//      nError[out]    错误码
//返回值：true 成功，false 失败；

TJTY_NET_API bool __stdcall TJTY_NET_SetDVRAlarmInState(long lUserID,
                                                        int   nAlarmInNO,
                                                        bool  bAlarmIn,
                                                        int   &nError);
//-----------------------------------------------------------------------------
//外设控制函数
//函数功能：控制外部设备
//参数：lUserID[in]    登录DVR返回的ID;
//      nAlarmOutNO[in] 报警输出端口号
//      bAlarm[in]   控制命令（true-打开， false-关闭）
//      nError[out]    错误码
//返回值：true 成功，false 失败；

TJTY_NET_API bool __stdcall TJTY_NET_ControlDVRAlarmOut(long lUserID,
                                                        int  nAlarmOutNO,
                                                        bool bAlarmOut,
                                                        int  &nError);
//----------------------------------------------------------------------------
/*****************************设备管理部分************************************/
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//远程关机控制
//函数功能：远程关机控制
//参数：lUserID[in]    登录DVR返回的ID;
//      nError[out]    错误码
//返回值：true 成功，false 失败；

TJTY_NET_API bool __stdcall TJTY_NET_ShutDownDVR(long lUserID, int &nError);
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//远程重启主机控制
//函数功能：重启远程关机
//参数：lUserID[in]    登录DVR返回的ID;
//      nError[out]    错误码
//返回值：true 成功，false 失败；

TJTY_NET_API bool __stdcall TJTY_NET_RebootDVR(long lUserID, int &nError);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//日志查询函数
//函数功能：日志查询函数
//参数：lUserID[in]    登录DVR返回的ID;
//      dwLogType[in]   日志类型（0－全部；1－报警；2-异常；3－操作）
//      lpStartTime[in] 开始时间
//      lpStopTime[in]  结束时间
//      lpLogInfoCallBack[in] 日志回调函数
//      dwUser[in]      用户自定义参数
//      nError[out]    错误码
//返回值：true-成功；false-失败；

TJTY_NET_API bool __stdcall TJTY_NET_FindDVRLog(long lUserID,
                                                DWORD  dwLogType,
                                                LPTJTY_TIME lpStartTime,
                                                LPTJTY_TIME lpStopTime,
                                                TJTY_NET_LogInfo_CALLBACK lpLogInfoCallBack,
                                                DWORD dwUser,
                                                int &nError);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//停止查找日志
//函数功能：停止查找日志，释放资源
//参数：lUserID[in]  登录DVR返回的ID;
//返回值：true-成功，false-失败。

TJTY_NET_API bool __stdcall TJTY_NET_FindClosetLog(long lUserID);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//函数功能：控制云台操作
//参数：lUserID[in]  登录DVR返回的ID;
//      nChannel[in] 通道号
//      dwPZTCommond[in] 操作命令, 见TJTY_NET_PTZCTRL_CMD；
//      bStop[in]  动作开始或者停止（true-停止，false-开始）；
//      nError[out] 错误码
//返回值：true-成功，false-失败。

TJTY_NET_API bool __stdcall TJTY_NET_PTZControl(long  lUserID,
                                                int   nChannel,
                                                DWORD dwPZTCommond,
                                                bool  bStop,
                                                DWORD dwSpeed,
                                                int &nError);
//-----------------------------------------------------------------------------
//云台图象区域控制
//函数功能：控制云台图象区域选择放大或缩小
//参数：lUserID[in]  登录DVR返回的ID;
//      nChannel[in] 通道号
//      pRectInfo[in] 区域信息结构
//      nError[out] 错误码
//返回值：true-成功，false-失败。

TJTY_NET_API bool __stdcall TJTY_NET_PZTSelZoomIn(long lUserID,
                                                  int nChannel,
                                                  LPTJTY_NET_RECT pRectInfo,
                                                  int &nError);
//-----------------------------------------------------------------------------
//函数功能：云台预置位点的设置、清除与转至预置位点
//参数：lUserID[in]  登录DVR返回的ID;
//      nChannel[in] 通道号
//      dwPTZPresetCmd[in] 操作命令，见TJTY_NET_PTZPRESET_CMD。
//      nPresetIndex[in] 预置点的序号 
//      nError[out] 错误码
//返回值：true-成功，false-失败。

TJTY_NET_API bool __stdcall TJTY_NET_PTZPreset(long lUserID, int nChannel,
                                                DWORD  dwPTZPresetCmd,
                                                int nPresetIndex,
                                                int &nError);
//----------------------------------------------------------------------------
//函数功能：巡航路径的修改、设置、执行等操作。
//参数：lUserID[in]  登录DVR返回的ID;
//      nChannel[in] 通道号
//      dwPTZCruiseCmd[in] 巡航操作命令，见TJTY_NET_PTZCRU_CMD;
//      nCruiseIndex[in] 巡航路径的序号
//      nCruisePoint[in] 巡航点序号
//      nPreSetNO[in]  预置位号
//      dwStopTime[in]  停留位号
//      dwSpeed[in]  速度
//      nError[out] 错误码
//返回值：true-成功，false-失败。

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
//函数功能：获取云台一条巡航路径的详细信息
//参数：lUserID[in]  登录DVR返回的ID;
//      nChannel[in] 通道号
//      dwPTZCruiseCmd[in] 巡航操作命令，见上面宏定义
//      nCruiseIndex[in] 巡航路径的序号
//      nCruisePoint[out] 巡航路径信息结构，用于存储获得的巡航路径信息
//      nError[out] 错误码
//返回值：true-成功，false-失败。

TJTY_NET_API bool __stdcall TJTY_NET_GetPTZCruise(long lUserID,
                                                  int nChannel,
                                                  int nCruiseIndex,
                                                  LPTJTY_NET_CRUISE_RET  lpCruiseRet,
                                                  int &nError);
//-----------------------------------------------------------------------------
//函数功能：控制云台轨迹操作
//参数：lUserID[in]  登录DVR返回的ID;
//      nChannel[in] 通道号
//      dwPTZTrackCmd[in] 轨迹操作命令，见TJTY_NET_PTZTRACK_CMD;
//      nError[out] 错误码
//返回值：true-成功，false-失败。

TJTY_NET_API bool __stdcall TJTY_NET_PTZTrack(long lUserID,
                                              int nChannel,
                                              DWORD dwPTZTrackCmd,
                                              int nIDTrack,
                                              int &nError);
//-----------------------------------------------------------------------------
//函数功能：获取通道名
//参数：lUserID[in]  登录DVR返回的ID;
//      pcChanNames[out] 通道名数组
//      nChanNums[out] 实际的通道数目;
//      nError[out] 错误码
//返回值：true-成功，false-失败。

TJTY_NET_API bool __stdcall TJTY_NET_GetAllChannelName(long lUserID,
                                                       char pcChanNames[TJTY_NET_MAX_CHANNUM][TJTY_NET_PATHNAME_LEN],
                                                       int &nChanNums,
                                                       int &nError);
//-----------------------------------------------------------------------------
//函数功能：获取录像信息
//参数：lUserID[in]  登录DVR返回的ID;
//      nChannel[in] 通道号
//      dwCmd 信息命令
//      TYNET_DVR_RECORD[out] 录像信息结构;
//      nError[out] 错误码
//返回值：true-成功，false-失败。
TJTY_NET_API bool  __stdcall TJTY_NET_GetDVRRecordInfo( long lUserID,
                                                        int nChannel,
                                                        DWORD dwCmd,
                                                        TYNET_DVR_RECORD &struRecCfg,
                                                        int &nError) ;
//函数功能：搜索网络中的设备，获取设备列表
//参数：dwDVRType  设备类型
//      pSearchDevice_CALLBACK  搜索设备回调函数
//      nError   错误码
//返回值：true-成功，false-失败。
TJTY_NET_API bool  __stdcall TJTY_NET_GetDeviceList( DWORD dwDVRType,
                                                     TJTY_NET_SearchDevice_CALLBACK   pSearchDevice_CALLBACK,
                                                     int &nError) ;

//设置回放速度（宇视）
TJTY_NET_API bool _stdcall  TJTY_NET_SetPlaySpeed(long lRemotePlayID,int nSpeed);

//获取已播放时间（宇视）
TJTY_NET_API bool _stdcall  TJTY_NET_GetPlayedTime(long lRemotePlayID, DWORD &PlayedTime);

//回放暂停（宇视）
TJTY_NET_API bool _stdcall  TJTY_NET_RemotePlayPause(long lRemotePlayID, int &nError);

//回放恢复（宇视）
TJTY_NET_API bool _stdcall  TJTY_NET_RemotePlayResume(long lRemotePlayID, int &nError);

//单帧回放（宇视）
TJTY_NET_API bool _stdcall  TJTY_NET_RemotePlayOneByOne(long lRemotePlayID, int &nError);



#endif