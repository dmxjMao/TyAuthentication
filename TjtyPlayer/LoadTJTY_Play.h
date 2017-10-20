/*********************************************************************
* ��Ȩ���� (C)2010, �Ϻ���Ծ�Ƽ����޹�˾��
*
* �ļ����ƣ�LoadTJTY_Play.h
* ����ժҪ����̬���ý����Tjty_Play�ĸ�����ָ��Ķ��塣
* ��ǰ�汾��
* ��    �ߣ�����ƽ
* ������ڣ�20100727
**********************************************************************/
//---------------------------------------------------------------------------
#ifndef LoadTJTY_PlayH
#define LoadTJTY_PlayH
//---------------------------------------------------------------------------
#include "TJTY_Play.h"
//---------------------------------------------------------------------------

typedef bool (CALLMETHOD *fTJTY_PLAY_InitplayStyle)(int nport,int type);  
typedef bool (CALLMETHOD *fTJTY_PLAY_SetStreamOpenMode)(int nport,DWORD nMODE);  //���ò���ģʽ
typedef bool (CALLMETHOD *fTJTY_PLAY_StartPlay)(int nport,BYTE * pFileHeadBuf,DWORD size,DWORD nBufPoolSize,HWND hWnd,int num);
typedef bool (CALLMETHOD *fTJTY_PLAY_InputData)(int nport,BYTE *Buf,DWORD nSize);
typedef bool (CALLMETHOD *fTJTY_PLAY_PlaySound)(int nport);
typedef bool (CALLMETHOD *fTJTY_PLAY_SetVolume)(int nPort,WORD nVolume);
typedef bool (CALLMETHOD *fTJTY_PLAY_StopPlay)(int nport);
typedef bool (CALLMETHOD *fTJTY_PLAY_StopSound)(int nport);
typedef bool (CALLMETHOD *fTJTY_PLAY_ResetSourceBuffer)(int nport);  //ˢ�»�����
typedef int  (CALLMETHOD *fTJTY_PLAY_GetLastError)(int nport);
typedef bool (CALLMETHOD *fTJTY_PLAY_Capture)(int nport,char * FileFullName);
typedef int  (CALLMETHOD *fTJTY_PLAY_GetSourceBufRemain)(int nPort);
typedef void  (CALLMETHOD *fTJTY_PLAY_DrawTitleFun)(pDrawTitleFun lpDrawTitleFun); //Ϊ��ɫ�Ǽ�ע��ͼ���ϻ�ͼ����
typedef bool (CALLMETHOD *fTJTY_PLAY_RegisterDrawFun)(long nPort,
													  DrawFunCallBack pfDrawFunCallBack,
													  long nUser); //ע��ͼ�����ַ����Ӻ���
typedef bool  (CALLMETHOD *fTJTY_PLAY_LoadDLDll)(char dllPatch[]); //������̬����أ�֮���Էų������������ط��÷�ֹ�ظ���
typedef bool  (CALLMETHOD *fTJTY_PLAY_FreeDLDll)();
typedef bool (CALLMETHOD *fTJTY_PLAY_OpenFile)(int nPort,char FileFullName[],int *error);
typedef bool (CALLMETHOD *fTJTY_PLAY_PlayFile)(int nPort,HWND hWnd);
typedef int  (CALLMETHOD *fTJTY_PLAY_GetToalFileTime)(int nPort);
typedef bool (CALLMETHOD *fTJTY_PLAY_FilePlayPause)(int nPort);
typedef bool (CALLMETHOD *fTJTY_PLAY_FilePlayResume)(int nPort);
typedef bool (CALLMETHOD *fTJTY_PLAY_PlayRefresh)(int nPort);
typedef bool (CALLMETHOD *fTJTY_PLAY_SetPlayPos)(int nPort,float fPostion);
typedef bool (CALLMETHOD *fTJTY_PLAY_ChangePlaySpeed)(int nPort,int nSpeed);
typedef int  (CALLMETHOD *fTJTY_PLAY_GetCurPlayTime)(int nPort);
typedef bool (CALLMETHOD *fTJTY_PLAY_FrameBack)(int nPort);
typedef bool (CALLMETHOD *fTJTY_PLAY_FrameForward)(int nPort);
typedef bool (CALLMETHOD *fTJTY_PLAY_CloseFile)(int nPort);


//---------------------------------------------------------------------------
extern fTJTY_PLAY_InitplayStyle           TJTY_PLAY_InitplayStyle;
extern fTJTY_PLAY_SetStreamOpenMode       TJTY_PLAY_SetStreamOpenMode;
extern fTJTY_PLAY_StartPlay               TJTY_PLAY_StartPlay;
extern fTJTY_PLAY_InputData               TJTY_PLAY_InputData;
extern fTJTY_PLAY_PlaySound               TJTY_PLAY_PlaySound;
extern fTJTY_PLAY_SetVolume               TJTY_PLAY_SetVolume;
extern fTJTY_PLAY_StopPlay                TJTY_PLAY_StopPlay;
extern fTJTY_PLAY_StopSound               TJTY_PLAY_StopSound;
extern fTJTY_PLAY_ResetSourceBuffer       TJTY_PLAY_ResetSourceBuffer;
extern fTJTY_PLAY_GetLastError            TJTY_PLAY_GetLastError;
extern fTJTY_PLAY_Capture                 TJTY_PLAY_Capture;
extern fTJTY_PLAY_GetSourceBufRemain      TJTY_PLAY_GetSourceBufRemain;
extern fTJTY_PLAY_DrawTitleFun            TJTY_PLAY_DrawTitleFun;
extern fTJTY_PLAY_RegisterDrawFun         TJTY_PLAY_RegisterDrawFun;
extern fTJTY_PLAY_LoadDLDll               TJTY_PLAY_LoadDLDll;
extern fTJTY_PLAY_FreeDLDll               TJTY_PLAY_FreeDLDll;
extern fTJTY_PLAY_OpenFile                TJTY_PLAY_OpenFile;
extern fTJTY_PLAY_PlayFile                TJTY_PLAY_PlayFile;
extern fTJTY_PLAY_GetToalFileTime         TJTY_PLAY_GetToalFileTime;
extern fTJTY_PLAY_FilePlayPause           TJTY_PLAY_FilePlayPause;
extern fTJTY_PLAY_FilePlayResume          TJTY_PLAY_FilePlayResume;
extern fTJTY_PLAY_PlayRefresh             TJTY_PLAY_PlayRefresh;
extern fTJTY_PLAY_SetPlayPos              TJTY_PLAY_SetPlayPos;
extern fTJTY_PLAY_ChangePlaySpeed         TJTY_PLAY_ChangePlaySpeed;
extern fTJTY_PLAY_GetCurPlayTime          TJTY_PLAY_GetCurPlayTime;
extern fTJTY_PLAY_FrameBack               TJTY_PLAY_FrameBack;
extern fTJTY_PLAY_FrameForward            TJTY_PLAY_FrameForward;
extern fTJTY_PLAY_CloseFile               TJTY_PLAY_CloseFile;


//---------------------------------------------------------------------------
//���ض�̬��
//���������chDLLPath ��̬������·������������̬���ļ���
//����ֵ��0-�ɹ���С��0ʧ��
int LoadTJTY_Play(const TCHAR* szDLLPath);

//ж�ض�̬��
int FreeTJTY_Play();
//---------------------------------------------------------------------------
#endif
