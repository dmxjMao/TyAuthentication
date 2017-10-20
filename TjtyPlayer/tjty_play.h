// Tjty_Play.h : Tjty_Play DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

//#include "resource.h"		// ������
#include "TjtyCommon.h"

// CTjty_PlayApp
// �йش���ʵ�ֵ���Ϣ������� Tjty_Play.cpp
//

typedef enum _TJTY_FISHEYE_OPERATETYPE
{
	TJTY_FISHEYE_SETPARAM = 0,
	TJTY_FISHEYE_GETPARAM
}TJTY_FISHEYE_OPERATETYPE;

typedef struct _TJTY_FISHEYE_SIZE
{
	int w;
	int h;
}TJTY_FISHEYE_SIZE;

typedef enum _TJTY_FISHEYE_MOUNTMODE
{
	TJTY_FISHEYEMOUNT_MODE_INVALID = 0,
	TJTY_FISHEYEMOUNT_MODE_CEIL = 1,						/*��װ*/
	TJTY_FISHEYEMOUNT_MODE_WALL,							/*��װ*/
	TJTY_FISHEYEMOUNT_MODE_FLOOR,						/*��װ*/
	TJTY_FISHEYEMOUNT_MODE_NUM
}TJTY_FISHEYE_MOUNTMODE;

typedef enum _TJTY_FISHEYE_CALIBRATMODE
{
	TJTY_FISHEYECALIBRATE_MODE_INVALID = 0,
	TJTY_FISHEYECALIBRATE_MODE_OFF = 1,								/*�ر������㷨�⣬�ⲿ�ر�*/
	TJTY_FISHEYECALIBRATE_MODE_ORIGINAL,								/*ԭʼģʽ(������),�����ű���*/
	TJTY_FISHEYECALIBRATE_MODE_PANORAMA,								/*1p*/
	TJTY_FISHEYECALIBRATE_MODE_PANORAMA_PLUS_ONE_EPTZ,				/*1p+1*/
	TJTY_FISHEYECALIBRATE_MODE_DOUBLE_PANORAMA,						/*2p*/
	TJTY_FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_DOUBLE_PANORAMA,		/*1+2p*/
	TJTY_FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_THREE_EPTZ_REGION,		/*1+3*/
	TJTY_FISHEYECALIBRATE_MODE_PANORAMA_PLUS_THREE_EPTZ_REGION,		/*1p+3*/
	TJTY_FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_TWO_EPTZ_REGION,		/*1+2*/	
	TJTY_FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_FOUR_EPTZ_REGION,		/*1+4*/
	TJTY_FISHEYECALIBRATE_MODE_PANORAMA_PLUS_FOUR_EPTZ_REGION,		/*1p+4*/
	TJTY_FISHEYECALIBRATE_MODE_PANORAMA_PLUS_SIX_EPTZ_REGION,		/*1p+6*/
	TJTY_FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_EIGHT_EPTZ_REGION,		/*1+8*/
	TJTY_FISHEYECALIBRATE_MODE_PANORAMA_PLUS_EIGHT_EPTZ_REGION,		/*1p+8*/
	TJTY_FISHEYECALIBRATE_MODE_TWO_EPTZ_REGION_WITH_ORIGINAL,		/*1F+2*/	
	TJTY_FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION_WITH_ORIGINAL,		/*1F+4*/	
	TJTY_FISHEYECALIBRATE_MODE_DOUBLE_PANORAMA_WITH_ORIGINAL,		/*1F+2p*/
	TJTY_FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION_WITH_PANORAMA,		/*1p(F)+4*/
	TJTY_FISHEYECALIBRATE_MODE_TWO_EPTZ_REGION,		                /*2����*/
	TJTY_FISHEYECALIBRATE_MODE_SINGLE,								/*������*/
	TJTY_FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION,						/*4����*/
	TJTY_FISHEYECALIBRATE_MODE_USER_DEFINED,				    		/*�û��Զ���*/
	TJTY_FISHEYECALIBRATE_MODE_PHONE,								/*�ֻ�ģʽ*/
	TJTY_FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_ONE_EPTZ_REGION,		/*1+1*/
	TJTY_FISHEYECALIBRATE_MODE_ONE_EPTZ_REGION,						/*1����*/

	TJTY_FISHEYECALIBRATE_MODE_NUM
}TJTY_FISHEYE_CALIBRATMODE;

typedef struct _TJTY_FISHEYE_REGIONPARAM
{
	int x;
	int y;
	int hAngle;
	int vAngle;
	int available;
	int reserved[3];
}TJTY_FISHEYE_REGIONPARAM;

typedef struct _TJTY_FISHEYE_MODEINITPARAM
{
	TJTY_FISHEYE_REGIONPARAM   regionParam[9];
	int              circularOffset;
	int              panoramaOffset;
	int              useRegionParam;           /*Ϊ1ʱ������Ч��ʹ�ø�ֵ���г�ʼ����û�б�����Ϣʱ����Ϊ0*/
	int              reserved[1];
}TJTY_FISHEYE_MODEINITPARAM;

typedef struct _TJTY_FISHEYE_POINT2D
{
	short x;
	short y;
}TJTY_FISHEYE_POINT2D;

typedef struct _TJTY_FISHEYE_SUBMODE
{
	TJTY_FISHEYE_MOUNTMODE     subMountMode;			    /*��ͼ��װģʽ, ����ͼ����У��ģʽΪ�û��Զ���ģʽʱ, ��ֵ��Ч*/
	TJTY_FISHEYE_CALIBRATMODE  subCalibrateMode;	        /*��ͼ��У��ģʽ, ����ͼ����У��ģʽΪ�û��Զ���ģʽʱ, ��ֵ��Ч*/
	TJTY_FISHEYE_SIZE          imgOutput;                /*��ͼ������ֱ���*/
	TJTY_FISHEYE_POINT2D       upperLeft;                /*��ͼ��ƫ��*/
	int					  reserved[3];				/*�����ֽ�*/
}TJTY_FISHEYE_SUBMODE;

typedef struct _TJTY_FISHEYE_OUTPUTFORMAT
{
	TJTY_FISHEYE_SIZE          mainShowSize;		        /*�ݲ�����, ����ʾ����, 4:3, 16:9��, �㷨�ݴ�����ʺϵ����Ž��������������¾����ﵽ�ñ�����*/
	TJTY_FISHEYE_SIZE          floatMainShowSize;		/*���˫bufferʱʹ�ã�Ŀǰ��ʱ�������ϵĲ����������������ڵ�����ʾ���ڷֱ���, ����Բ�Ŀ�߱���ҪΪ1:1��������װȫ���Ŀ�߱���ҪΪ16:9*/
	TJTY_FISHEYE_SIZE          imgOutput;                /*���ͼ��ֱ���(����ǰ), ͼ����У��ģʽΪ�û��Զ���ģʽʱΪ�ⲿ����, ����ģʽΪ�ڲ�����*/
	TJTY_FISHEYE_SUBMODE*	  subMode;                  /*��ģʽ��Ϣ, ͼ����У��ģʽΪ�û��Զ���ģʽʱΪ�ⲿ����, ����ģʽΪ�ڲ�����*/
	int		              subModeNum;               /*��ģʽ��, ͼ����У��ģʽΪ�û��Զ���ģʽʱΪ�ⲿ����, ����ģʽΪ�ڲ�����*/
	int                   outputSizeRatio;		    /*�ݲ�����, У�����ͼ������ű�,Q8��ʽ,��Χ0-256, 256Ϊ�����������ֱ���*/
	int                   reserved[1];				/*�����ֽ�*/
}TJTY_FISHEYE_OUTPUTFORMAT;

/*ǹ������*/
typedef enum tjty_CAM_TYPE
{
	//ǹ������
	TJTY_IPCTYPE_200WN				= 0,	//
	TJTY_IPCTYPE_130WN				= 1,
	TJTY_IPCTYPE_D1WN				= 2,
	TJTY_IPCTYPE_100WN				= 3,
	TJTY_IPCTYPE_FE					= 4,	//����

	//�������
	TJTY_SPCTYPE_D6501				= 100,	//sony��о65���
	TJTY_HSPCTYPE_D6A2030E			= 101,	//�󻪻�о2030E��6A���
	TJTY_HSPCTYPE_D65A2030E			= 102	//�󻪻�о2030E��65A���
}TJTY_CAM_TYPE;

/*��ͷ����*/
typedef enum tjty_LEN_TYPE
{
	TJTY_LENTYPE_NORM				= 0,	//�޻��侵ͷ
	TJTY_LENTYPE_Lens0361 			= 1,	//3.6����ǹ����ͷ
	TJTY_LENTYPE_Lens2880			= 2,	//130�ȹ��ǹ����ͷ
	TJTY_LENTYPE_Lens0362 			= 3,	//3.6����ǹ����ͷ
	TJTY_LENTYPE_Lens0401 			= 4,	//4.0����ǹ����ͷ

	TJTY_LENTYPE_TEST1				= 100	//�����ò���
}TJTY_LEN_TYPE;

typedef struct _TJTY_MHFPTZ_CONFIGPARAM
{	
	/*�������*/
	int zoom_type;							//��������ģʽ----��������Ӧ�䱶�͸��ݿ�ѡĿ���С�䱶����ģʽ
	int hcam_wax;							//����������Ӧ����Ƕ�x��ˮƽ��
	int hcam_way;							//����������Ӧ����Ƕ�y����ֱ��
	int hcam_wmul;							//�����������ã���׼������
	int cfg_type;							//���÷�ʽ��Ĭ��Ϊ1��ʹ�����ò�����ʽ,1��ʹ�ò������÷�ʽ��0��ʹ���豸�������÷�ʽ

	//���������							         
	//��ͷ����
	int prm_re;								//ͶӰ�뾶
	int prm_mul;							//ͶӰ����
	int prm_dx;								//x����ƫ��
	int prm_dy;								//y����ƫ��
	int prm_cw;								//CMOS��ʵ��ʹ�ÿ�
	int prm_ch;								//CMOS�ߣ�ʵ��ʹ�øߣ�

	//������ʹ�����������ã�cfg_typeΪ0ʱ���øò�������Ч��            //Ĭ��130�ȡ�130��ǹ����200W65���
	TJTY_LEN_TYPE mlen_type;						//�������ͷ����
	TJTY_CAM_TYPE mcam_type;						//���������
	TJTY_CAM_TYPE hcam_type;						//���������

	//�������
	int himg_width;                         //�����ͼ���
	int himg_height;                        //�����ͼ���
	int prm_fax;                            //���ˮƽ�ӳ���

	/*��Ĭ�ϵĲ���*/
	//���������
	int mcam_fc;							//�����Ч����
	int mcam_cw;							//��ͷ�����
	int mcam_ch;							//��ͷ����� 
	int cam_height;                         //�������߶ȣ��ף�������ʱδʹ�ã�
	int prm_ma;								//�������

	//���������
	//�������
	int prm_hw;								//CMOS��
	int prm_hh;								//CMOS��
	int prm_fo;								//��Ч����
	int prm_ca;								//��Ұ����
	int prm_mmul;							//�����
}TJTY_MHFPTZ_CONFIGPARAM;

typedef struct _TJTY_FISHEYE_OPTPARAM
{
	TJTY_FISHEYE_SIZE     mainStreamSize;		    /*��Ӧ������ԭʼ��ߣ�������ֱ�����֮����ʱ����Ϊ�������Ǵ˷ֱ������Ŷ���*/
	int              originX;					/*����ͼ��������Բ��Բ�ĺ�����, ��һ����0-8192����ϵ*/
	int              originY;					/*����ͼ��������Բ��Բ��������, ��һ����0-8192����ϵ*/
	int              radius;					/*����ͼ��������Բ�İ뾶, ��һ����0-8192����ϵ*/ 
	int              lensDirection;		        /*��ת�Ƕ�, Q7��ʽ, ��Χ0-360*128, һ����Ϊ0*/
	TJTY_FISHEYE_MOUNTMODE     mainMountMode;		/*����װģʽ*/
	TJTY_FISHEYE_CALIBRATMODE  mainCalibrateMode;	/*ͼ����У��ģʽ*/
	TJTY_FISHEYE_MODEINITPARAM modeInitParam;        /*�ⲿ����ģʽ��ʼ����������Ϣ��������ģʽ�л��ָ�����һ�ε�״̬,*/
	TJTY_FISHEYE_OUTPUTFORMAT *outputFormat;         /*���ͼ����Ϣ*/
	TJTY_MHFPTZ_CONFIGPARAM   *configParam;          /*�����������ò���*/
	int              enableAutoContrast;       /*�����Զ��Աȶ�, 0�ر�, 1����, �ù��ܻ������㷨��ʱ, ��Ҫ���ܺõĻ����Ž��鿪��*/
	int              alphaHistogram;           /*ֱ��ͼIIRǿ��0-255, Ĭ��128, Խ��Խ�ο���ǰ֡*/
	int              alphaGray;                /*�Ҷ�����ǿ��0-255, Ĭ��245, Խ��Խ�Աȶ���*/
	TJTY_FISHEYE_SIZE     captureSize;		       /*��Ӧ��ǰģʽ�µ�ץͼ�ֱ���*/
	int              mhfptzIndex;               //IN ��������������0,1,2....
	int              reserved[1];				/*�����ֽ�*/
}TJTY_FISHEYE_OPTPARAM;

typedef enum _TJTY_FISHEYE_EPTZCMD
{
	TJTY_FISHEYEEPTZ_CMD_INVALID = 0,	
	TJTY_FISHEYEEPTZ_CMD_ZOOM_IN = 1,						/*�Ŵ�*/
	TJTY_FISHEYEEPTZ_CMD_ZOOM_OUT,							/*��С*/
	TJTY_FISHEYEEPTZ_CMD_UP,								/*�����ƶ�*/
	TJTY_FISHEYEEPTZ_CMD_DOWN,								/*�����ƶ�*/
	TJTY_FISHEYEEPTZ_CMD_LEFT,								/*�����ƶ�*/
	TJTY_FISHEYEEPTZ_CMD_RIGHT,								/*�����ƶ�*/
	TJTY_FISHEYEEPTZ_CMD_ROTATE_CLOCKWISE_AUTO,				/*�Զ�˳ʱ����ת*/
	TJTY_FISHEYEEPTZ_CMD_ROTATE_ANTICLOCKWISE_AUTO,			/*�Զ���ʱ����ת*/
	TJTY_FISHEYEEPTZ_CMD_STOP,								/*ֹͣ*/
	TJTY_FISHEYEEPTZ_CMD_SHOW_REGION,						/*��ѡ�Ŵ�*/
	TJTY_FISHEYEEPTZ_CMD_EXIT_SHOW_REGION,					/*�˳���ѡ�Ŵ�*/
	TJTY_FISHEYEEPTZ_CMD_DEFAULT,						    /*�ָ�Ĭ��*/
	TJTY_FISHEYEEPTZ_CMD_ORIGIN_ROTATE,						/*Բ��ת*/

	TJTY_FISHEYEEPTZ_CMD_SET_CUR_REGION = 0x20,             /*����ָ�����ڵ�λ����Ϣ*/
	TJTY_FISHEYEEPTZ_CMD_GET_CUR_REGION,                    /*��ȡָ�����ڵ�λ����Ϣ*/
	TJTY_FISHEYEEPTZ_CMD_IS_IN_PANORAMA_REGION,             /*������Ƿ��ڵ�ǰȫ������������*/
	TJTY_FISHEYEEPTZ_CMD_TAP_VIEW,							/*��ʾָ��λ��,���㼴��*/
	TJTY_FISHEYEEPTZ_CMD_SET_FOCUS,	 				        /*���ô���λ����Ϣ*/
	TJTY_FISHEYEEPTZ_CMD_GET_FOCUS,							/*��ȡ����λ����Ϣ*/

	TJTY_FISHEYEEPTZ_CMD_PTZ_CALI,							/*���������궨*/
	TJTY_FISHEYEEPTZ_CMD_GET_PTZ_RLT,						/*��ȡ����������λ��Ϣ*/
	TJTY_FISHEYEEPTZ_CMD_NUM
}TJTY_FISHEYE_EPTZCMD;

typedef struct _TJTY_FISHEYE_EPTZPARAM
{
	TJTY_FISHEYE_EPTZCMD   ePtzCmd;			/*��̨������˵����FISHEYE_EPtzCmd����*/
	int          winId;				    /*Ҫ����eptz�Ĵ��ڱ�ţ����Ͻ�winIdΪ0�������ҵ���*/							
	int          arg1;
	int          arg2;
	int          arg3;
	int          arg4;
	int          arg5;
	int          arg6;
	int          reserved0[6];			   /*�����ֽ�*/
	void*        pParam;                   /*��������*/
	void*        pResult;
	void*        pArg;   

	int          reserved1[7];			   /*�����ֽ�*/

}TJTY_FISHEYE_EPTZPARAM;

typedef void (CALLBACK* TJTY_fCBFishEyeInfoFun)( 
	LONG nPort,
	BYTE byCorrectMode,
	WORD wRadius,
	WORD wCircleX,
	WORD wCircleY,
	UINT widthRatio,
	UINT heightRatio,
	BYTE gain,
	BYTE denoiseLevel,
	BYTE installStyle,
	void* pUserData );

//class CTjty_PlayApp : public CWinApp
//{
//public:
//	CTjty_PlayApp();
//
//// ��д
//public:
//	virtual BOOL InitInstance();
//
//	//��������
//public:
//	WORD		m_wHIKRenderMD;	//�����Ƿ���Ⱦ�ƶ���ⷶΧ
//
//public:	
//	void ReadConfigFile();	
//	void WriteConfigFile();
//
//	//��ȡʵ��
//	static CTjty_PlayApp * GetInstance();
//
//	DECLARE_MESSAGE_MAP()
//};
//extern CTjty_PlayApp theApp;

//#if defined( _WINDLL)
#define TJTYSDK_API  extern "C" __declspec(dllexport)
//#else
//#define TJTYSDK_API  extern "C" //__declspec(dllimport)
//#endif
#define CALLMETHOD __stdcall

//����ӿ�
//typedef void (CALLBACK * pDrawTitleFun)(LONG nPort, HDC hDC, time_t time, DWORD dwWidth, DWORD dwHeight, LPVOID lpVoid);
typedef void (CALLBACK * pDrawTitleFun)(LONG nPort, HDC hDC, UINT time, DWORD dwWidth, DWORD dwHeight, LPVOID lpVoid);


//�ַ����ӻص�����
typedef void (CALLBACK *DrawFunCallBack)(LONG nPort, HDC hDC, LONG nUser);

