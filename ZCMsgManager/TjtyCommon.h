/*********************************************************************
* ��Ȩ���� (C)2010, �Ϻ���Ծ�Ƽ����޹�˾��
* 
* �ļ����ƣ�TjtyCommon.h
* ����ժҪ��ϵͳ�������ݶ��塣
*        
* ��ǰ�汾�� 
* ��    �ߣ� ��С·
* ������ڣ� 20100819
**********************************************************************/
//-----------------------------------------------------------------------------
#ifndef TjtyCommonH
#define TjtyCommonH
//-----------------------------------------------------------------------------
#include "TY_Type.h"
//-----------------------------------------------------------------------------
//�ڵ�����
typedef enum
{
    TJTY_AREANODE_HEADOFFICE = 1,    //����
	TJTY_AREANODE_BRANCHBANK_PROVINCE,  //ʡ����
    TJTY_AREANODE_BRANCHBANK_CITY,      //�з���
    TJTY_AREANODE_SUB_BRANCHBANK,       //֧��
	TJTY_AREANODE_BUSI_OUTLET,          //����
    TJTY_AREANODE_FLOOR                 //¥��
}TJTY_AREANODE_TYPE;

//�豸���Ͷ���
typedef enum
{
    DEV_TYPC = 0,   //��Ծ����DVR
    DEV_EDVR,       //Ƕ��ʽDVR
    DEV_ALARMHOST,  //��������
    DEV_EAC,        //���ذ�������
}TJTY_DEVTYPE;

//�豸����
typedef enum
{
	TJTY_DEV_DVR             = 1,  //DVR 
	TJTY_DEV_NVR             = 2,  //NVR   
	TJTY_DEV_ALARMHOST       = 4,  //��������
	TJTY_DEV_DOA             = 8,  //�Ž�
	TJTY_DEV_ENVIRONMENT     = 16, //�����ɼ���
	TJTY_DEV_IP_CAMERA       = 32, //IPC
    TJTY_DEV_DVS             = 64, //DVS
    TJTY_DEV_MTA             = 128  //���ذ��Ӿ�����
}TJTY_DEVICE_TYPE;
//-----------------------------------------------------------------------------
//�������
typedef enum
{
    TJTY_SOFT_CMS = 1000,//���ķ�����
    TJTY_SOFT_MS,        //ý�������
    TJTY_SOFT_AS,        //����������
    TJTY_SOFT_DEC,       //����ǽ
    TJTY_SOFT_EMAP,      //���ӵ�ͼ
    TJTY_SOFT_ARIC,      //�ֿ�
    TJTY_SOFT_CONSOLE,   //����̨
    TJTY_SOFT_APP,       //APP
	TJTY_SOFT_MONITOR
}TJTY_SOFTWARE_TYPE;
//-----------------------------------------------------------------------------
//DVR���Ͷ���
typedef enum
{
	TJTY_DVR_PC = 0,       //��Ծ����
	TJTY_DVR_HIK,          //����
	TJTY_DVR_DH,           //��
	TJTY_DVR_TM,           //ͼ��
	TJTY_DVR_DL,           //����
	TJTY_DVR_HB6000,       //����6000
	TJTY_DVR_HB8000,       //����8000
	TJTY_DVR_BSR,          //��ɫ֮��
	TJTY_DVR_TYEDVR,       //��ԾǶ��ʽ
	TJTY_DVR_SMTK,         //�ǰ���
	TJTY_DVR_HTC,          //��ͨDVR
	TJTY_IPC_SONY,         //����IPC
	TJTY_DVR_HIKPC,        //��������
	TJTY_DVR_BSR7,         //��ɫ֮��7

    TJTY_DVR_NULL = 0xFFFFFFFF  //δ֪����
}TJTY_DVRTYPE;

//-----------------------------------------------------------------------------
//�����ʼ������
#define INIT_ALL_TYPE           (0)                     //ȫ��
#define INIT_TJTY_DVR_PC        (1<<TJTY_DVR_PC)        //����
#define INIT_TJTY_DVR_HIK       (1<<TJTY_DVR_HIK)       //����
#define INIT_TJTY_DVR_DH        (1<<TJTY_DVR_DH)        //��
#define INIT_TJTY_DVR_TM        (1<<TJTY_DVR_TM)        //ͼ��
#define INIT_TJTY_DVR_DL        (1<<TJTY_DVR_DL)        //����
#define INIT_TJTY_DVR_HB6000    (1<<TJTY_DVR_HB6000)    //����6000
#define INIT_TJTY_DVR_HB8000    (1<<TJTY_DVR_HB8000)    //����8000
#define INIT_TJTY_DVR_BSR       (1<<TJTY_DVR_BSR)       //����
#define INIT_TJTY_DVR_TYEDVR    (1<<TJTY_DVR_TYEDVR)    //��ԾDVR
#define INIT_TJTY_DVR_SMTK      (1<<TJTY_DVR_SMTK)      //�ǰ���
#define INIT_TJTY_DVR_HTC       (1<<TJTY_DVR_HTC)       //��ͨDVR
#define INIT_TJTY_IPC_SONY      (1<<TJTY_IPC_SONY)      //����IPC
#define INIT_TJTY_DVR_BSR7      (1<<TJTY_DVR_BSR7)      //����7

#define INIT_TJTY_DVR_ALLEXCEPT_HTC	(0xFFFFFFFF & ~INIT_TJTY_DVR_HTC)

//-----------------------------------------------------------------------------
//ǰ���豸����
typedef enum
{
    TJTY_FRONT_ALARM_IN    = 1,        //̽ͷ���������룩
    TJTY_FRONT_CAMERA      = 2,        //����ͷ
    TJTY_FRONT_ALARM_OUT   = 4,        //���裨���������
    TJTY_FRONT_ALARM_HAND  = 8         //�ֶ�����
}TJTY_FRONT_DEV_TYPE;
//-----------------------------------------------------------------------------
//ʱ��ṹ
typedef struct
{
    U_LONG_TY dwYear;		//��
	U_LONG_TY dwMonth;		//��
	U_LONG_TY dwDay;		//��
	U_LONG_TY dwHour;		//ʱ
	U_LONG_TY dwMinute;		//��
	U_LONG_TY dwSecond;		//��
}TJTY_TIME, *LPTJTY_TIME;
//----------------------------------------------------------------------------
//��־���ͺ궨��
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
 