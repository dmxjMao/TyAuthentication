/*********************************************************************
* 版权所有 (C)2010, 上海天跃科技有限公司。
*
* 文件名称：LoadTJTY_Play.cpp
* 内容摘要：动态调用解码库Tjty_Play.dll的实现。
* 当前版本：
* 作    者：张孙平
* 完成日期：20100727
**********************************************************************/


#include "stdafx.h"
#include "LoadTJTY_Play.h"
#include <stdio.h>
//---------------------------------------------------------------------------
fTJTY_PLAY_InitplayStyle           TJTY_PLAY_InitplayStyle=NULL;
fTJTY_PLAY_SetStreamOpenMode       TJTY_PLAY_SetStreamOpenMode=NULL;
fTJTY_PLAY_StartPlay               TJTY_PLAY_StartPlay=NULL;
fTJTY_PLAY_InputData               TJTY_PLAY_InputData=NULL;
fTJTY_PLAY_PlaySound               TJTY_PLAY_PlaySound=NULL;
fTJTY_PLAY_SetVolume               TJTY_PLAY_SetVolume=NULL;
fTJTY_PLAY_StopPlay                TJTY_PLAY_StopPlay=NULL;
fTJTY_PLAY_StopSound               TJTY_PLAY_StopSound=NULL;
fTJTY_PLAY_ResetSourceBuffer       TJTY_PLAY_ResetSourceBuffer=NULL;
fTJTY_PLAY_GetLastError            TJTY_PLAY_GetLastError=NULL;
fTJTY_PLAY_Capture                 TJTY_PLAY_Capture=NULL;
fTJTY_PLAY_GetSourceBufRemain      TJTY_PLAY_GetSourceBufRemain=NULL;
fTJTY_PLAY_DrawTitleFun            TJTY_PLAY_DrawTitleFun=NULL;
fTJTY_PLAY_RegisterDrawFun         TJTY_PLAY_RegisterDrawFun=NULL;
fTJTY_PLAY_LoadDLDll               TJTY_PLAY_LoadDLDll=NULL;
fTJTY_PLAY_FreeDLDll               TJTY_PLAY_FreeDLDll=NULL;
fTJTY_PLAY_OpenFile                TJTY_PLAY_OpenFile=NULL;
fTJTY_PLAY_PlayFile                TJTY_PLAY_PlayFile=NULL;
fTJTY_PLAY_GetToalFileTime         TJTY_PLAY_GetToalFileTime=NULL;
fTJTY_PLAY_FilePlayPause           TJTY_PLAY_FilePlayPause=NULL;
fTJTY_PLAY_FilePlayResume          TJTY_PLAY_FilePlayResume=NULL;
fTJTY_PLAY_PlayRefresh             TJTY_PLAY_PlayRefresh=NULL;
fTJTY_PLAY_SetPlayPos              TJTY_PLAY_SetPlayPos=NULL;
fTJTY_PLAY_ChangePlaySpeed         TJTY_PLAY_ChangePlaySpeed=NULL;
fTJTY_PLAY_GetCurPlayTime          TJTY_PLAY_GetCurPlayTime=NULL;
fTJTY_PLAY_FrameBack               TJTY_PLAY_FrameBack=NULL;
fTJTY_PLAY_FrameForward            TJTY_PLAY_FrameForward=NULL;
fTJTY_PLAY_CloseFile               TJTY_PLAY_CloseFile=NULL;

//------------------------------------------------------------------------
static HINSTANCE g_hTJTY_Play = NULL;
//------------------------------------------------------------------------
//加载动态库
//输入参数：chDLLPath 动态库所在路径，不包括动态库文件名
//返回值：0-成功，-1失败
int LoadTJTY_Play(const TCHAR* szDLLPath)
{
	if (NULL == szDLLPath)
    {
        return -1;
    }

	TCHAR szDllName[MAX_PATH] = _T("Tjty_Play.dll");

	//g_hTJTY_Play = LoadLibraryEx(szDllName, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	g_hTJTY_Play = LoadLibrary(szDllName);
	if (NULL == g_hTJTY_Play)
    {
		return -1;
    }

	TJTY_PLAY_InitplayStyle = (fTJTY_PLAY_InitplayStyle)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_InitplayStyle");
	TJTY_PLAY_SetStreamOpenMode = (fTJTY_PLAY_SetStreamOpenMode)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_SetStreamOpenMode");
	TJTY_PLAY_StartPlay = (fTJTY_PLAY_StartPlay)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_StartPlay");
    TJTY_PLAY_InputData = (fTJTY_PLAY_InputData)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_InputData");
    TJTY_PLAY_PlaySound = (fTJTY_PLAY_PlaySound)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_PlaySound");
    TJTY_PLAY_SetVolume = (fTJTY_PLAY_SetVolume)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_SetVolume");
    TJTY_PLAY_StopPlay = (fTJTY_PLAY_StopPlay)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_StopPlay");
    TJTY_PLAY_StopSound = (fTJTY_PLAY_StopSound)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_StopSound");
	TJTY_PLAY_ResetSourceBuffer = (fTJTY_PLAY_ResetSourceBuffer)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_ResetSourceBuffer");
	TJTY_PLAY_GetLastError = (fTJTY_PLAY_GetLastError)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_GetLastError");
	TJTY_PLAY_Capture = (fTJTY_PLAY_Capture)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_Capture");
	TJTY_PLAY_GetSourceBufRemain = (fTJTY_PLAY_GetSourceBufRemain)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_GetSourceBufRemain");
	TJTY_PLAY_DrawTitleFun = (fTJTY_PLAY_DrawTitleFun)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_DrawTitleFun");
	TJTY_PLAY_RegisterDrawFun = (fTJTY_PLAY_RegisterDrawFun)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_RegisterDrawFun");
	TJTY_PLAY_LoadDLDll = (fTJTY_PLAY_LoadDLDll)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_LoadDLDll");
	TJTY_PLAY_FreeDLDll = (fTJTY_PLAY_FreeDLDll)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_FreeDLDll");
	TJTY_PLAY_OpenFile = (fTJTY_PLAY_OpenFile)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_OpenFile");
	TJTY_PLAY_PlayFile = (fTJTY_PLAY_PlayFile)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_PlayFile");
	TJTY_PLAY_GetToalFileTime = (fTJTY_PLAY_GetToalFileTime)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_GetToalFileTime");
	TJTY_PLAY_FilePlayPause = (fTJTY_PLAY_FilePlayPause)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_FilePlayPause");
	TJTY_PLAY_FilePlayResume = (fTJTY_PLAY_FilePlayResume)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_FilePlayResume");
	TJTY_PLAY_PlayRefresh = (fTJTY_PLAY_PlayRefresh)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_PlayRefresh");
	TJTY_PLAY_SetPlayPos = (fTJTY_PLAY_SetPlayPos)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_SetPlayPos");
	TJTY_PLAY_ChangePlaySpeed = (fTJTY_PLAY_ChangePlaySpeed)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_ChangePlaySpeed");
	TJTY_PLAY_GetCurPlayTime = (fTJTY_PLAY_GetCurPlayTime)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_GetCurPlayTime");
	TJTY_PLAY_FrameBack = (fTJTY_PLAY_FrameBack)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_FrameBack");
	TJTY_PLAY_FrameForward = (fTJTY_PLAY_FrameForward)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_FrameForward");
	TJTY_PLAY_CloseFile = (fTJTY_PLAY_CloseFile)
        GetProcAddress(g_hTJTY_Play, "TJTY_PLAY_CloseFile");
    if (NULL == TJTY_PLAY_InitplayStyle
        || NULL == TJTY_PLAY_SetStreamOpenMode
        || NULL == TJTY_PLAY_StartPlay
        || NULL == TJTY_PLAY_InputData
        || NULL == TJTY_PLAY_PlaySound
        || NULL == TJTY_PLAY_SetVolume
        || NULL == TJTY_PLAY_StopPlay
        || NULL == TJTY_PLAY_StopSound
        || NULL == TJTY_PLAY_ResetSourceBuffer
        || NULL == TJTY_PLAY_GetLastError
        || NULL == TJTY_PLAY_Capture
        || NULL == TJTY_PLAY_GetSourceBufRemain
        || NULL == TJTY_PLAY_DrawTitleFun
        || NULL == TJTY_PLAY_RegisterDrawFun
        || NULL == TJTY_PLAY_LoadDLDll
        || NULL == TJTY_PLAY_FreeDLDll
        || NULL == TJTY_PLAY_OpenFile
        || NULL == TJTY_PLAY_PlayFile
        || NULL == TJTY_PLAY_GetToalFileTime
        || NULL == TJTY_PLAY_FilePlayPause
        || NULL == TJTY_PLAY_FilePlayResume
        || NULL == TJTY_PLAY_PlayRefresh
        || NULL == TJTY_PLAY_SetPlayPos
        || NULL == TJTY_PLAY_ChangePlaySpeed
        || NULL == TJTY_PLAY_GetCurPlayTime
        || NULL == TJTY_PLAY_FrameBack
        || NULL == TJTY_PLAY_FrameForward
        || NULL == TJTY_PLAY_CloseFile)
    {
        FreeLibrary(g_hTJTY_Play);
        g_hTJTY_Play = NULL;

		//LOG(ERROR) << "LoadTJTY_Play failed!";
        return -1;
    }
    return 0;
}

//卸载动态库
int FreeTJTY_Play()
{
    if (NULL != g_hTJTY_Play)
    {
        FreeLibrary(g_hTJTY_Play);
        g_hTJTY_Play = NULL;
    }
    return 0;
}


