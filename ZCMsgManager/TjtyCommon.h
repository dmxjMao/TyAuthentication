/*********************************************************************
* 版权所有 (C)2010, 上海天跃科技有限公司。
* 
* 文件名称：TjtyCommon.h
* 内容摘要：系统共用数据定义。
*        
* 当前版本： 
* 作    者： 张小路
* 完成日期： 20100819
**********************************************************************/
//-----------------------------------------------------------------------------
#ifndef TjtyCommonH
#define TjtyCommonH
//-----------------------------------------------------------------------------
#include "TY_Type.h"
//-----------------------------------------------------------------------------
//节点类型
typedef enum
{
    TJTY_AREANODE_HEADOFFICE = 1,    //总行
	TJTY_AREANODE_BRANCHBANK_PROVINCE,  //省分行
    TJTY_AREANODE_BRANCHBANK_CITY,      //市分行
    TJTY_AREANODE_SUB_BRANCHBANK,       //支行
	TJTY_AREANODE_BUSI_OUTLET,          //网点
    TJTY_AREANODE_FLOOR                 //楼层
}TJTY_AREANODE_TYPE;

//设备类型定义
typedef enum
{
    DEV_TYPC = 0,   //天跃工控DVR
    DEV_EDVR,       //嵌入式DVR
    DEV_ALARMHOST,  //报警主机
    DEV_EAC,        //迈特安服务器
}TJTY_DEVTYPE;

//设备类型
typedef enum
{
	TJTY_DEV_DVR             = 1,  //DVR 
	TJTY_DEV_NVR             = 2,  //NVR   
	TJTY_DEV_ALARMHOST       = 4,  //报警主机
	TJTY_DEV_DOA             = 8,  //门禁
	TJTY_DEV_ENVIRONMENT     = 16, //环境采集器
	TJTY_DEV_IP_CAMERA       = 32, //IPC
    TJTY_DEV_DVS             = 64, //DVS
    TJTY_DEV_MTA             = 128  //迈特安接警中心
}TJTY_DEVICE_TYPE;
//-----------------------------------------------------------------------------
//软件类型
typedef enum
{
    TJTY_SOFT_CMS = 1000,//中心服务器
    TJTY_SOFT_MS,        //媒体服务器
    TJTY_SOFT_AS,        //报警服务器
    TJTY_SOFT_DEC,       //电视墙
    TJTY_SOFT_EMAP,      //电子地图
    TJTY_SOFT_ARIC,      //分控
    TJTY_SOFT_CONSOLE,   //控制台
    TJTY_SOFT_APP,       //APP
	TJTY_SOFT_MONITOR
}TJTY_SOFTWARE_TYPE;
//-----------------------------------------------------------------------------
//DVR类型定义
typedef enum
{
	TJTY_DVR_PC = 0,       //天跃工控
	TJTY_DVR_HIK,          //海康
	TJTY_DVR_DH,           //大华
	TJTY_DVR_TM,           //图敏
	TJTY_DVR_DL,           //大立
	TJTY_DVR_HB6000,       //汉邦6000
	TJTY_DVR_HB8000,       //汉邦8000
	TJTY_DVR_BSR,          //蓝色之星
	TJTY_DVR_TYEDVR,       //天跃嵌入式
	TJTY_DVR_SMTK,         //智安邦
	TJTY_DVR_HTC,          //恒通DVR
	TJTY_IPC_SONY,         //索尼IPC
	TJTY_DVR_HIKPC,        //海康工控
	TJTY_DVR_BSR7,         //蓝色之星7

    TJTY_DVR_NULL = 0xFFFFFFFF  //未知类型
}TJTY_DVRTYPE;

//-----------------------------------------------------------------------------
//定义初始化类型
#define INIT_ALL_TYPE           (0)                     //全部
#define INIT_TJTY_DVR_PC        (1<<TJTY_DVR_PC)        //工控
#define INIT_TJTY_DVR_HIK       (1<<TJTY_DVR_HIK)       //海康
#define INIT_TJTY_DVR_DH        (1<<TJTY_DVR_DH)        //大华
#define INIT_TJTY_DVR_TM        (1<<TJTY_DVR_TM)        //图敏
#define INIT_TJTY_DVR_DL        (1<<TJTY_DVR_DL)        //大立
#define INIT_TJTY_DVR_HB6000    (1<<TJTY_DVR_HB6000)    //汉邦6000
#define INIT_TJTY_DVR_HB8000    (1<<TJTY_DVR_HB8000)    //汉邦8000
#define INIT_TJTY_DVR_BSR       (1<<TJTY_DVR_BSR)       //蓝星
#define INIT_TJTY_DVR_TYEDVR    (1<<TJTY_DVR_TYEDVR)    //天跃DVR
#define INIT_TJTY_DVR_SMTK      (1<<TJTY_DVR_SMTK)      //智安邦
#define INIT_TJTY_DVR_HTC       (1<<TJTY_DVR_HTC)       //恒通DVR
#define INIT_TJTY_IPC_SONY      (1<<TJTY_IPC_SONY)      //索尼IPC
#define INIT_TJTY_DVR_BSR7      (1<<TJTY_DVR_BSR7)      //蓝星7

#define INIT_TJTY_DVR_ALLEXCEPT_HTC	(0xFFFFFFFF & ~INIT_TJTY_DVR_HTC)

//-----------------------------------------------------------------------------
//前端设备类型
typedef enum
{
    TJTY_FRONT_ALARM_IN    = 1,        //探头（报警输入）
    TJTY_FRONT_CAMERA      = 2,        //摄像头
    TJTY_FRONT_ALARM_OUT   = 4,        //外设（报警输出）
    TJTY_FRONT_ALARM_HAND  = 8         //手动报警
}TJTY_FRONT_DEV_TYPE;
//-----------------------------------------------------------------------------
//时间结构
typedef struct
{
    U_LONG_TY dwYear;		//年
	U_LONG_TY dwMonth;		//月
	U_LONG_TY dwDay;		//日
	U_LONG_TY dwHour;		//时
	U_LONG_TY dwMinute;		//分
	U_LONG_TY dwSecond;		//秒
}TJTY_TIME, *LPTJTY_TIME;
//----------------------------------------------------------------------------
//日志类型宏定义
typedef enum
{
	REALTIME_VIEW,	
	TALKWITHDEV,	
	TALKWITHUSER,	
	PLAYBACK,		
	DEVCTRLLOG,    
	ALARMINCTRL,   
	ALARMOUTCTRL,	
	DEVCAMERACTL   
}LOGTYPE;
//-----------------------------------------------------------------------------
#endif
 