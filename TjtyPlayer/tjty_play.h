// Tjty_Play.h : Tjty_Play DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

//#include "resource.h"		// 主符号
#include "TjtyCommon.h"

// CTjty_PlayApp
// 有关此类实现的信息，请参阅 Tjty_Play.cpp
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
	TJTY_FISHEYEMOUNT_MODE_CEIL = 1,						/*顶装*/
	TJTY_FISHEYEMOUNT_MODE_WALL,							/*壁装*/
	TJTY_FISHEYEMOUNT_MODE_FLOOR,						/*地装*/
	TJTY_FISHEYEMOUNT_MODE_NUM
}TJTY_FISHEYE_MOUNTMODE;

typedef enum _TJTY_FISHEYE_CALIBRATMODE
{
	TJTY_FISHEYECALIBRATE_MODE_INVALID = 0,
	TJTY_FISHEYECALIBRATE_MODE_OFF = 1,								/*关闭鱼眼算法库，外部关闭*/
	TJTY_FISHEYECALIBRATE_MODE_ORIGINAL,								/*原始模式(正方形),带缩放比例*/
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
	TJTY_FISHEYECALIBRATE_MODE_TWO_EPTZ_REGION,		                /*2画面*/
	TJTY_FISHEYECALIBRATE_MODE_SINGLE,								/*单画面*/
	TJTY_FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION,						/*4画面*/
	TJTY_FISHEYECALIBRATE_MODE_USER_DEFINED,				    		/*用户自定义*/
	TJTY_FISHEYECALIBRATE_MODE_PHONE,								/*手机模式*/
	TJTY_FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_ONE_EPTZ_REGION,		/*1+1*/
	TJTY_FISHEYECALIBRATE_MODE_ONE_EPTZ_REGION,						/*1画面*/

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
	int              useRegionParam;           /*为1时表明有效，使用该值进行初始化；没有保存信息时请置为0*/
	int              reserved[1];
}TJTY_FISHEYE_MODEINITPARAM;

typedef struct _TJTY_FISHEYE_POINT2D
{
	short x;
	short y;
}TJTY_FISHEYE_POINT2D;

typedef struct _TJTY_FISHEYE_SUBMODE
{
	TJTY_FISHEYE_MOUNTMODE     subMountMode;			    /*子图像安装模式, 仅当图像主校正模式为用户自定义模式时, 该值有效*/
	TJTY_FISHEYE_CALIBRATMODE  subCalibrateMode;	        /*子图像校正模式, 仅当图像主校正模式为用户自定义模式时, 该值有效*/
	TJTY_FISHEYE_SIZE          imgOutput;                /*子图像输出分辨率*/
	TJTY_FISHEYE_POINT2D       upperLeft;                /*子图像偏移*/
	int					  reserved[3];				/*保留字节*/
}TJTY_FISHEYE_SUBMODE;

typedef struct _TJTY_FISHEYE_OUTPUTFORMAT
{
	TJTY_FISHEYE_SIZE          mainShowSize;		        /*暂不启用, 主显示比例, 4:3, 16:9等, 算法据此输出适合的最优结果（不变形情况下尽量达到该比例）*/
	TJTY_FISHEYE_SIZE          floatMainShowSize;		/*输出双buffer时使用，目前暂时还是用老的操作方法，浮动窗口的主显示窗口分辨率, 浮动圆的宽高比需要为1:1，浮动壁装全景的宽高比需要为16:9*/
	TJTY_FISHEYE_SIZE          imgOutput;                /*输出图像分辨率(缩放前), 图像主校正模式为用户自定义模式时为外部输入, 其他模式为内部返回*/
	TJTY_FISHEYE_SUBMODE*	  subMode;                  /*子模式信息, 图像主校正模式为用户自定义模式时为外部输入, 其他模式为内部返回*/
	int		              subModeNum;               /*子模式数, 图像主校正模式为用户自定义模式时为外部输入, 其他模式为内部返回*/
	int                   outputSizeRatio;		    /*暂不启用, 校正输出图像的缩放比,Q8格式,范围0-256, 256为保持最大输出分辨率*/
	int                   reserved[1];				/*保留字节*/
}TJTY_FISHEYE_OUTPUTFORMAT;

/*枪机类型*/
typedef enum tjty_CAM_TYPE
{
	//枪机类型
	TJTY_IPCTYPE_200WN				= 0,	//
	TJTY_IPCTYPE_130WN				= 1,
	TJTY_IPCTYPE_D1WN				= 2,
	TJTY_IPCTYPE_100WN				= 3,
	TJTY_IPCTYPE_FE					= 4,	//鱼眼

	//球机类型
	TJTY_SPCTYPE_D6501				= 100,	//sony机芯65球机
	TJTY_HSPCTYPE_D6A2030E			= 101,	//大华机芯2030E，6A球机
	TJTY_HSPCTYPE_D65A2030E			= 102	//大华机芯2030E，65A球机
}TJTY_CAM_TYPE;

/*镜头类型*/
typedef enum tjty_LEN_TYPE
{
	TJTY_LENTYPE_NORM				= 0,	//无畸变镜头
	TJTY_LENTYPE_Lens0361 			= 1,	//3.6毫米枪机镜头
	TJTY_LENTYPE_Lens2880			= 2,	//130度广角枪机镜头
	TJTY_LENTYPE_Lens0362 			= 3,	//3.6毫米枪机镜头
	TJTY_LENTYPE_Lens0401 			= 4,	//4.0毫米枪机镜头

	TJTY_LENTYPE_TEST1				= 100	//调试用参数
}TJTY_LEN_TYPE;

typedef struct _TJTY_MHFPTZ_CONFIGPARAM
{	
	/*必设参数*/
	int zoom_type;							//倍数控制模式----期望自适应变倍和根据框选目标大小变倍两种模式
	int hcam_wax;							//期望倍数对应球机角度x（水平）
	int hcam_way;							//期望倍数对应球机角度y（垂直）
	int hcam_wmul;							//期望倍数设置（基准倍数）
	int cfg_type;							//配置方式，默认为1：使用配置参数方式,1：使用参数配置方式，0：使用设备类型配置方式

	//主相机参数							         
	//镜头参数
	int prm_re;								//投影半径
	int prm_mul;							//投影倍率
	int prm_dx;								//x方向偏移
	int prm_dy;								//y方向偏移
	int prm_cw;								//CMOS宽（实际使用宽）
	int prm_ch;								//CMOS高（实际使用高）

	//主相机和从相机类型配置（cfg_type为0时设置该参数才有效）            //默认130度、130万枪机和200W65球机
	TJTY_LEN_TYPE mlen_type;						//主相机镜头类型
	TJTY_CAM_TYPE mcam_type;						//主相机类型
	TJTY_CAM_TYPE hcam_type;						//从相机类型

	//球机参数
	int himg_width;                         //从相机图像宽
	int himg_height;                        //从相机图像高
	int prm_fax;                            //球机水平视场角

	/*可默认的参数*/
	//主相机参数
	int mcam_fc;							//相机等效焦距
	int mcam_cw;							//镜头靶面高
	int mcam_ch;							//镜头靶面宽 
	int cam_height;                         //相机架设高度（米），（暂时未使用）
	int prm_ma;								//焦距参数

	//从相机参数
	//球机参数
	int prm_hw;								//CMOS宽
	int prm_hh;								//CMOS高
	int prm_fo;								//等效焦距
	int prm_ca;								//视野参数
	int prm_mmul;							//最大倍率
}TJTY_MHFPTZ_CONFIGPARAM;

typedef struct _TJTY_FISHEYE_OPTPARAM
{
	TJTY_FISHEYE_SIZE     mainStreamSize;		    /*对应主码流原始宽高，当传入分辨率与之不等时表明为辅码流是此分辨率缩放而来*/
	int              originX;					/*输入图像中鱼眼圆的圆心横坐标, 归一化至0-8192坐标系*/
	int              originY;					/*输入图像中鱼眼圆的圆心纵坐标, 归一化至0-8192坐标系*/
	int              radius;					/*输入图像中鱼眼圆的半径, 归一化至0-8192坐标系*/ 
	int              lensDirection;		        /*旋转角度, Q7格式, 范围0-360*128, 一般配为0*/
	TJTY_FISHEYE_MOUNTMODE     mainMountMode;		/*主安装模式*/
	TJTY_FISHEYE_CALIBRATMODE  mainCalibrateMode;	/*图像主校正模式*/
	TJTY_FISHEYE_MODEINITPARAM modeInitParam;        /*外部传入模式初始化各画面信息，适用于模式切换恢复到上一次的状态,*/
	TJTY_FISHEYE_OUTPUTFORMAT *outputFormat;         /*输出图像信息*/
	TJTY_MHFPTZ_CONFIGPARAM   *configParam;          /*鱼球联动配置参数*/
	int              enableAutoContrast;       /*开启自动对比度, 0关闭, 1开启, 该功能会增加算法耗时, 需要性能好的机器才建议开启*/
	int              alphaHistogram;           /*直方图IIR强度0-255, 默认128, 越大越参考当前帧*/
	int              alphaGray;                /*灰度拉伸强度0-255, 默认245, 越大越对比度弱*/
	TJTY_FISHEYE_SIZE     captureSize;		       /*对应当前模式下的抓图分辨率*/
	int              mhfptzIndex;               //IN 鱼球联动球机序号0,1,2....
	int              reserved[1];				/*保留字节*/
}TJTY_FISHEYE_OPTPARAM;

typedef enum _TJTY_FISHEYE_EPTZCMD
{
	TJTY_FISHEYEEPTZ_CMD_INVALID = 0,	
	TJTY_FISHEYEEPTZ_CMD_ZOOM_IN = 1,						/*放大*/
	TJTY_FISHEYEEPTZ_CMD_ZOOM_OUT,							/*缩小*/
	TJTY_FISHEYEEPTZ_CMD_UP,								/*向上移动*/
	TJTY_FISHEYEEPTZ_CMD_DOWN,								/*向下移动*/
	TJTY_FISHEYEEPTZ_CMD_LEFT,								/*向左移动*/
	TJTY_FISHEYEEPTZ_CMD_RIGHT,								/*向右移动*/
	TJTY_FISHEYEEPTZ_CMD_ROTATE_CLOCKWISE_AUTO,				/*自动顺时针旋转*/
	TJTY_FISHEYEEPTZ_CMD_ROTATE_ANTICLOCKWISE_AUTO,			/*自动逆时针旋转*/
	TJTY_FISHEYEEPTZ_CMD_STOP,								/*停止*/
	TJTY_FISHEYEEPTZ_CMD_SHOW_REGION,						/*框选放大*/
	TJTY_FISHEYEEPTZ_CMD_EXIT_SHOW_REGION,					/*退出框选放大*/
	TJTY_FISHEYEEPTZ_CMD_DEFAULT,						    /*恢复默认*/
	TJTY_FISHEYEEPTZ_CMD_ORIGIN_ROTATE,						/*圆旋转*/

	TJTY_FISHEYEEPTZ_CMD_SET_CUR_REGION = 0x20,             /*配置指定窗口的位置信息*/
	TJTY_FISHEYEEPTZ_CMD_GET_CUR_REGION,                    /*获取指定窗口的位置信息*/
	TJTY_FISHEYEEPTZ_CMD_IS_IN_PANORAMA_REGION,             /*输入点是否在当前全景点链区域内*/
	TJTY_FISHEYEEPTZ_CMD_TAP_VIEW,							/*显示指定位置,即点即看*/
	TJTY_FISHEYEEPTZ_CMD_SET_FOCUS,	 				        /*设置窗口位置信息*/
	TJTY_FISHEYEEPTZ_CMD_GET_FOCUS,							/*获取窗口位置信息*/

	TJTY_FISHEYEEPTZ_CMD_PTZ_CALI,							/*鱼球联动标定*/
	TJTY_FISHEYEEPTZ_CMD_GET_PTZ_RLT,						/*获取鱼球联动定位信息*/
	TJTY_FISHEYEEPTZ_CMD_NUM
}TJTY_FISHEYE_EPTZCMD;

typedef struct _TJTY_FISHEYE_EPTZPARAM
{
	TJTY_FISHEYE_EPTZCMD   ePtzCmd;			/*云台操作，说明见FISHEYE_EPtzCmd定义*/
	int          winId;				    /*要进行eptz的窗口编号，左上角winId为0，从左到右递增*/							
	int          arg1;
	int          arg2;
	int          arg3;
	int          arg4;
	int          arg5;
	int          arg6;
	int          reserved0[6];			   /*保留字节*/
	void*        pParam;                   /*鱼球联动*/
	void*        pResult;
	void*        pArg;   

	int          reserved1[7];			   /*保留字节*/

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
//// 重写
//public:
//	virtual BOOL InitInstance();
//
//	//公有数据
//public:
//	WORD		m_wHIKRenderMD;	//海康是否渲染移动侦测范围
//
//public:	
//	void ReadConfigFile();	
//	void WriteConfigFile();
//
//	//获取实例
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

//特殊接口
//typedef void (CALLBACK * pDrawTitleFun)(LONG nPort, HDC hDC, time_t time, DWORD dwWidth, DWORD dwHeight, LPVOID lpVoid);
typedef void (CALLBACK * pDrawTitleFun)(LONG nPort, HDC hDC, UINT time, DWORD dwWidth, DWORD dwHeight, LPVOID lpVoid);


//字符叠加回调函数
typedef void (CALLBACK *DrawFunCallBack)(LONG nPort, HDC hDC, LONG nUser);

