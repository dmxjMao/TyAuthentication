#include "stdafx.h"
//#include <objbase.h >
#include "ZCMsgManager.h"
#include "SelfServiceBankClient.h"

#pragma comment(lib,"..\\ZCMsgManager\\TjtyTcpClientModule.lib")
CZCMsgManager* CZCMsgManager::m_pZcInst = NULL;

//
//extern CSearchStatisticsDlg  *g_SearchStatisticsDlg;
//extern CTyOpenDoorDlg  *g_cOpenDoorDlg;
//extern COpenDoorGeneralListDlg * g_cOpenDoorGeneralListDlg;
//extern COpenDoorApplyDlg* g_cOpenDoorApplyDlg ;
//extern CRemoteAuthenticationPopUpDLg* g_cRemotePopUpDlg;
//CRITICAL_SECTION g_csPreCaptureVector;  //保证std::map<DWORD, vector<CString > > m_mapPreCapture同步
//#define CTRLEVELNAMELENGTH   128
//#define GUIDLENGTH                         64
//
///*typedef std::map<DWORD, vector<CString> > STRNG2VECTOR;*/
//typedef std::map<DWORD, vector<CString > > STRING2VECTOR;
//消息回调函数
void _stdcall pfCallback(ZC_MSG_HEAD zMsgHead, void* pMessage, INT pnMessageSize, DWORD dwUser)
{
	//switch(zMsgHead.dwMsgType)
	//{
	//case ZC_MSG_SERVER_REQ_NOMODULE:      //请求模块不存在消息
	//	{
	//		if(pMessage)
	//		{
	//			WORD* pWord = (WORD*)pMessage;
	//			if(*pWord == ZC_MODULE_BCBCLIENT)
	//			{

	//			}
	//		}
	//		break;
	//	}
	//case ZC_MSG_SERVER_REQ_MODULELOGOUT:    //关联模块断开消息
	//	{
	//		if(pMessage)
	//		{
	//			WORD* pWord = (WORD*)pMessage;
	//			if(*pWord == ZC_MODULE_BCBCLIENT)
	//			{

	//			}
	//		}
	//		break;
	//	}    
	//case ZC_MSG_COMMON_CURUSERINFOEX:  //当前用户信息
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if(pResult->nOK != 0)
	//		{	
	//			T_CURUSER_INFO_EX* pInfo = (T_CURUSER_INFO_EX*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)]);
	//			CZCMsgManager::Instance()->AddCurrentUserInfo(pInfo);
	//			TAGDOAPPASSWORD_P info={0};
	//			strcpy(info.chUserName,pInfo->chUserName);
	//			CZCMsgManager::Instance()->RequestUserPassWord(info);
	//			CZCMsgManager::Instance()->m_bError[EROCURRENTUSER]=false;
	//			CZCMsgManager::Instance()->RequestUserDetail(CZCMsgManager::Instance()->m_CurrentUserInfo.chUserName, -1);
	//		}
	//		else
	//		{
	//			CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//			CZCMsgManager::Instance()->m_bError[EROCURRENTUSER]=true;
	//			CZCMsgManager::Instance()->m_iErrorCode[EROCURRENTUSER]=pResult->nError;
	//		}

	//		if (NULL != g_cOpenDoorDlg)
	//		{
	//			g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 1, 0);
	//		}

	//		break;
	//	}
	//case ZC_MSG_OPENDOOR_DISPOSALINFO:
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if(pResult->nOK != 0)
	//		{	
	//			T_OPENDOORPOSALINFO* pInfo = (T_OPENDOORPOSALINFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)]);
	//			memcpy(&CZCMsgManager::Instance()->m_tOpenDoorDisposalInfo, pInfo, sizeof(T_OPENDOORPOSALINFO));
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("第三方认证获取权限成功.\n"
	//				"人员增删改权限： %d\n录入权限： %d\n认证处置权限：%d\n审核权限：%d\n记录查询权限：%d",
	//				pInfo->bUserInfoSetPosal, pInfo->bQueryPosal, pInfo->bDealWithPosal,
	//				pInfo->bCheckPosal, pInfo->bQueryPosal);
	//		}
	//		else
	//		{
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord(
	//				"第三方认证获取权限失败 错误码：%d\n", pResult->nError);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_COMMON_ALLAREAINFO:  //区域信息
	//	{
	//		
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if(pResult->nOK != 0)
	//		{	
	//			int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(T_AREA_INFO);
	//			for(int i=0;i<iCount;i++)
	//			{
	//				T_AREA_INFO* pInfo = (T_AREA_INFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(T_AREA_INFO)]);
	//				if(i != 0)
	//				{
	//					CZCMsgManager::Instance()->AddAreaInfo(*pInfo,false);
	//				}
	//				else
	//				{
	//					CZCMsgManager::Instance()->AddAreaInfo(*pInfo,true);
	//				}
	//			}
	//			CZCMsgManager::Instance()->m_bError[EROAREA]=false;
	//		}
	//		else
	//		{
	//			CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//			CZCMsgManager::Instance()->m_bError[EROAREA]=true;
	//			CZCMsgManager::Instance()->m_iErrorCode[EROAREA]=pResult->nError;
	//		}
	//		if (NULL != g_cOpenDoorDlg)
	//		{
	//			g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 2, 0);
	//		}
	//		break;
	//	}
	//	
	//	case ZC_MSG_OPENDOOR_GETAPPLYHISTORYINFO:  //认证查询
	//	{
	//		
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if(pResult->nOK != 0)
	//		{	
	//			int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOAHISTORYINFO_S);
	//			for(int i=0;i<iCount;i++)
	//			{
	//				TAGDOAHISTORYINFO_S* pInfo = (TAGDOAHISTORYINFO_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOAHISTORYINFO_S)]);
	//				if(i != 0)
	//				{
	//					CZCMsgManager::Instance()->AddCertificationSearchInfo(*pInfo,false);
	//				}
	//				else
	//				{
	//					CZCMsgManager::Instance()->AddCertificationSearchInfo(*pInfo,true);
	//				}
	//			}
	//			CZCMsgManager::Instance()->m_bError[EROCERTIFICATION]=false;
	//		}
	//		else
	//		{
	//			CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//			CZCMsgManager::Instance()->m_bError[EROCERTIFICATION]=true;
	//			CZCMsgManager::Instance()->m_iErrorCode[EROCERTIFICATION]=pResult->nError;
	//		}
	//		if(g_SearchStatisticsDlg!=NULL)
	//		{
	//			g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMCERTIFICATIONSEARCH,NULL);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_OPENDOOR_GETBYCARDHISTORYINFO:  //人员查询（刷卡信息）
	//	{
	//		
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if(pResult->nOK != 0)
	//		{	
	//			int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOABYCARDINFO_S);
	//			for(int i=0;i<iCount;i++)
	//			{
	//				TAGDOABYCARDINFO_S* pInfo = (TAGDOABYCARDINFO_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOABYCARDINFO_S)]);
	//				if(i != 0)
	//				{
	//					//CZCMsgManager::Instance()->AddStaffSearchInfo(*pInfo,false);
	//				}
	//				else
	//				{
	//					//CZCMsgManager::Instance()->AddStaffSearchInfo(*pInfo,true);
	//				}
	//			}
	//			CZCMsgManager::Instance()->m_bError[EROSTAFFSEARCH] = false;
	//		}
	//		else
	//		{
	//			CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//			CZCMsgManager::Instance()->m_bError[EROSTAFFSEARCH] = true;
	//			CZCMsgManager::Instance()->m_iErrorCode[EROSTAFFSEARCH] = pResult->nError;
	//		}
	//		if(g_SearchStatisticsDlg!=NULL)
	//		{
	//			g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMSTAFFSEARCH,NULL);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_OPENDOOR_APPLY_BYCARDINFO_NEW:  //人员查询（刷卡信息new）
	//		{

	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize - sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOABYCARDINFO_NEW_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOABYCARDINFO_NEW_S* pInfo = (TAGDOABYCARDINFO_NEW_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT) + i*sizeof(TAGDOABYCARDINFO_NEW_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddStaffSearchInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddStaffSearchInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROSTAFFSEARCH] = false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROSTAFFSEARCH] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROSTAFFSEARCH] = pResult->nError;
	//			}
	//			if(g_SearchStatisticsDlg!=NULL)
	//			{
	//				g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMSTAFFSEARCH,NULL);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_STATISTICS:  //统计信息
	//	{
	//		
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		CZCMsgManager::Instance()->m_dGroup=zMsgHead.dwMsgId;
	//		if(pResult->nOK != 0)
	//		{	
	//			int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOASTATISTICS_S);
	//			for(int i=0;i<iCount;i++)
	//			{
	//				TAGDOASTATISTICS_S* pInfo = (TAGDOASTATISTICS_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOASTATISTICS_S)]);
	//				if(i != 0)
	//				{
	//					CZCMsgManager::Instance()->AddStatisticInfo(*pInfo,false);
	//				}
	//				else
	//				{
	//					CZCMsgManager::Instance()->AddStatisticInfo(*pInfo,true);
	//				}
	//			}
	//			CZCMsgManager::Instance()->m_bError[EROSTATISTIC]=false;
	//		}
	//		else
	//		{
	//			CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//			CZCMsgManager::Instance()->m_bError[EROSTATISTIC]=true;
	//			CZCMsgManager::Instance()->m_iErrorCode[EROSTATISTIC]=pResult->nError;
	//		}
	//		if(g_SearchStatisticsDlg!=NULL)
	//		{
	//			g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMCERTIFICATIONSTATISTIC,NULL);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_OPENDOOR_GETALLACSHOSTINFO:  //所有门禁主机信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOAACCESSINFO_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOAACCESSINFO_S* pInfo = (TAGDOAACCESSINFO_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOAACCESSINFO_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddACSHostInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddACSHostInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROACSHOSTINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROACSHOSTINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROACSHOSTINFO]=pResult->nError;
	//			}
	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 6, 0);
	//			}

	//			break;
	//		}
	//	case ZC_MSG_ALARM_ALARMPOSITION:  //进入图层
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROINTOALARMLAYER]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROINTOALARMLAYER]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROINTOALARMLAYER]=pResult->nError;
	//			}

	//			if (NULL != g_cOpenDoorApplyDlg)
	//			{
	//				g_cOpenDoorApplyDlg->PostMessage(WM_NEED_FEEDBACKLINKACTION, 1, 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_ALARM_ALARMLINKVIDEO:  //观看视屏
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROWATCHVIDEO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROWATCHVIDEO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROWATCHVIDEO]=pResult->nError;
	//			}

	//			switch(zMsgHead.dwMsgId)
	//			{
	//			case IDD_REMOTE_AUTHENTICATION_POPUP_DIALOG:
	//				if (NULL != g_cRemotePopUpDlg)
	//				{
	//					g_cRemotePopUpDlg->PostMessage(WN_NEED_ACTIONFEEDBACK, 13, 0);
	//				}
	//				break;

	//			case IDD_OPEN_DOOR_APPLY_DIALOG:
	//				if (NULL != g_cOpenDoorApplyDlg)
	//				{
	//					g_cOpenDoorApplyDlg->PostMessage(WM_NEED_FEEDBACKLINKACTION, 2, 0);
	//				}
	//				break;

	//			}


	//			break;
	//		}
	//	case ZC_MSG_ALARM_ALARMREPLAY:  //回放录像
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROREPLAYVIDEO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROREPLAYVIDEO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROREPLAYVIDEO]=pResult->nError;
	//			}

	//			switch(zMsgHead.dwMsgId)
	//			{
	//			case IDD_REMOTE_AUTHENTICATION_POPUP_DIALOG:
	//				if (NULL != g_cRemotePopUpDlg)
	//				{
	//					g_cRemotePopUpDlg->PostMessage(WN_NEED_ACTIONFEEDBACK, 12, 0);
	//				}
	//				break;

	//			case IDD_OPEN_DOOR_APPLY_DIALOG:
	//				if (NULL != g_cOpenDoorApplyDlg)
	//				{
	//					g_cOpenDoorApplyDlg->PostMessage(WM_NEED_FEEDBACKLINKACTION, 3, 0);
	//				}
	//				break;

	//			}
	//			break;

	//		}
	//	case ZC_MSG_TASK_TELEPHONECALL:  //打电话
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[ERODIALLING]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[ERODIALLING]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[ERODIALLING]=pResult->nError;
	//			}


	//			switch(zMsgHead.dwMsgId)
	//			{
	//			case IDD_REMOTE_AUTHENTICATION_POPUP_DIALOG:
	//				if (NULL != g_cRemotePopUpDlg)
	//				{
	//					g_cRemotePopUpDlg->PostMessage(WN_NEED_ACTIONFEEDBACK, 19, 0);
	//				}
	//				break;

	//			case IDD_OPEN_DOOR_APPLY_DIALOG:
	//				if (NULL != g_cOpenDoorApplyDlg)
	//				{
	//					g_cOpenDoorApplyDlg->PostMessage(WM_NEED_FEEDBACKLINKACTION, 4, 0);
	//				}
	//				break;

	//			}


	//			break;
	//		}
	//	case ZC_MSG_COMMON_DEVTALKBYID: //对讲
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				T_ATTACHMENTINFO* pInfo = (T_ATTACHMENTINFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)]);
	//				CZCMsgManager::Instance()->AddAttachmentInfo(pInfo);
	//				CZCMsgManager::Instance()->m_bError[EROIPTALK]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROIPTALK]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROIPTALK]=pResult->nError;
	//			}
	//			switch(zMsgHead.dwMsgId)
	//			{
	//			case IDD_REMOTE_AUTHENTICATION_POPUP_DIALOG:
	//				if (NULL != g_cRemotePopUpDlg)
	//				{
	//					g_cRemotePopUpDlg->PostMessage(WN_NEED_ACTIONFEEDBACK, 18, 0);
	//				}
	//				break;

	//			case IDD_OPEN_DOOR_APPLY_DIALOG:
	//				if (NULL != g_cOpenDoorApplyDlg)
	//				{
	//					g_cOpenDoorApplyDlg->PostMessage(WM_COMMAND, WN_GET_IPTALKINFO, NULL);
	//				}
	//				break;
	//			}
	//			break;

	//		}
	//	case ZC_MSG_COMMON_CONTROLACSHOST:  //开门
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROOPENDOOR]=false;
	//				//AfxMessageBox(_T("ZC_MSG_COMMON_CONTROLACSHOST success"));
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROOPENDOOR]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROOPENDOOR]=pResult->nError;
	//									//AfxMessageBox(_T("ZC_MSG_COMMON_CONTROLACSHOST fail"));

	//			}
	//			switch(zMsgHead.dwMsgId)
	//			{
	//			case IDD_REMOTE_AUTHENTICATION_POPUP_DIALOG:
	//				if (NULL != g_cRemotePopUpDlg)
	//				{
	//					g_cRemotePopUpDlg->SendMessage(WN_NEED_ACTIONFEEDBACK, 17, 0);
	//				}
	//				break;

	//			case IDD_OPEN_DOOR_APPLY_DIALOG:
	//				if (NULL != g_cOpenDoorApplyDlg)
	//				{
	//					g_cOpenDoorApplyDlg->SendMessage(WM_NEED_FEEDBACKLINKACTION, 6, 0);
	//				}
	//				break;

	//			}

	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_STARTLISTENMANUALCAPTURE:  //请求开始手动抓图事件
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROMANULCAPTUREINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROMANULCAPTUREINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROMANULCAPTUREINFO]=pResult->nError;
	//			}
	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_NEW_MANUAL_CAPTURE:  //自动推送抓图消息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;

	//			char* pInfo = (char*)(&pBuf);
	//			CZCMsgManager::Instance()->AddManualCapture(pInfo);
	//			if (NULL != g_cOpenDoorApplyDlg)
	//			{
	//				g_cOpenDoorApplyDlg->PostMessage(WN_NEED_MANUALCAPTURE, 0 , 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_STOPLISTENMANUALCAPTURE:  //请求关闭手动抓图事件
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROCLOSEMANULCAPTUREINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROCLOSEMANULCAPTUREINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROCLOSEMANULCAPTUREINFO]=pResult->nError;
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_ADDREQUEST:
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROLINKSWIPCARDRECORD]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROLINKSWIPCARDRECORD] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROLINKSWIPCARDRECORD] = pResult->nError;
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_DOOROPENSYRELATION_SET:
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROLINKESCORTCARDRECORD] = false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROLINKESCORTCARDRECORD] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROLINKESCORTCARDRECORD] = pResult->nError;
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_ADDSUGGESTION:  //新增处置意见
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROADDSUGGESTION]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROADDSUGGESTION]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROADDSUGGESTION]=pResult->nError;
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_ADDLOGINFO:  //新增系统日志信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROADDLOGINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROADDLOGINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROADDLOGINFO]=pResult->nError;
	//			}
	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_ADDOPERAINFO:  //新增认证处置操作
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROADDOPERAINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROADDOPERAINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROADDOPERAINFO]=pResult->nError;
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_GETOPERAINFO:  //获取认证操作详细信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOAATTACHMENT_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOAATTACHMENT_S* pInfo = (TAGDOAATTACHMENT_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOAATTACHMENT_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddOperationInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddOperationInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETOPERAINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETOPERAINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETOPERAINFO]=pResult->nError;
	//			}
	//			if (g_cOpenDoorApplyDlg != NULL)
	//			{
	//				g_cOpenDoorApplyDlg->PostMessage(WM_COMMAND, WM_GET_TASTINFO, 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_GETAPPLYPLANINFO:  //获取预案执行信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOAACTIONDETAIL_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOAACTIONDETAIL_S* pInfo = (TAGDOAACTIONDETAIL_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOAACTIONDETAIL_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddActionDetail(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddActionDetail(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETAPPLYPLAN]=false;

	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->m_vOperaInfo.clear();
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETAPPLYPLAN]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETAPPLYPLAN]=pResult->nError;
	//			}
	//			if (g_cOpenDoorApplyDlg != NULL)
	//			{
	//				g_cOpenDoorApplyDlg->PostMessage(WM_COMMAND, WM_GET_EMERGENCYINFO, 0);
	//			}

	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_GETSUGGESTIONINFO:  //获取认证处理意见信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOAPROCESSMEMO_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOAPROCESSMEMO_S* pInfo = (TAGDOAPROCESSMEMO_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOAPROCESSMEMO_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddSuggestionInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddSuggestionInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETSUGGESTIONINFO]=false;

	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETSUGGESTIONINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETSUGGESTIONINFO]=pResult->nError;
	//				TAGDOAPROCESSMEMO_S* pInfo = new TAGDOAPROCESSMEMO_S;
	//				memset(pInfo, 0, sizeof(TAGDOAPROCESSMEMO_S));

	//				CZCMsgManager::Instance()->AddSuggestionInfo(*pInfo,true);
	//				delete pInfo;
	//			}
	//			if (g_cOpenDoorApplyDlg != NULL)
	//			{
	//				g_cOpenDoorApplyDlg->PostMessage(WM_COMMAND, WM_GET_HANDLEINFO, 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_GETLOGINFO:  //获取认证系统日志信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOAACTLOG_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOAACTLOG_S* pInfo = (TAGDOAACTLOG_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOAACTLOG_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddSystemLog(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddSystemLog(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETLOGINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETLOGINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETLOGINFO]=pResult->nError;
	//				TAGDOAACTLOG_S* pInfo = new TAGDOAACTLOG_S;
	//				memset(pInfo, 0, sizeof(TAGDOAACTLOG_S));
	//				CZCMsgManager::Instance()->AddSystemLog(*pInfo, true);
	//				delete pInfo;
	//			}
	//			if (g_cOpenDoorApplyDlg != NULL)
	//			{
	//				g_cOpenDoorApplyDlg->PostMessage(WM_COMMAND, WM_GET_SYSTEMLOG, 0);
	//			}

	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_GETACCESSLOGINFO:  //获取认证关联刷卡信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOADOORACCESSLOG_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOADOORACCESSLOG_S* pInfo = (TAGDOADOORACCESSLOG_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOADOORACCESSLOG_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddDoorAccessLog(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddDoorAccessLog(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETACCESSLOGINFO] = false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("获取认证关联刷卡信息失败, 错误码:%d", pResult->nError);
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETACCESSLOGINFO] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETACCESSLOGINFO] = pResult->nError;
	//			}
	//			if (NULL != g_cOpenDoorApplyDlg)
	//			{
	//				g_cOpenDoorApplyDlg->PostMessage(WM_COMMAND, WN_GET_DOORACCESSLOGINFO, 0);
	//			}
	//			break;
	//		}

	//	case ZC_MSG_OPENDOOR_SUBMITAUDITORDEALINFO:  //提交审核数据
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROSUBMITAUDITORDEALINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROSUBMITAUDITORDEALINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROSUBMITAUDITORDEALINFO]=pResult->nError;
	//			}
	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_ADDDEALPLANINFO:  //提交预案执行数据
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROADDDEALPLANINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROADDDEALPLANINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROADDDEALPLANINFO]=pResult->nError;
	//			}
	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_MODIFYDEALTYPE:  //请求修改认证处置方式
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROMODIFYDEALTYPE]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROMODIFYDEALTYPE]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROMODIFYDEALTYPE]=pResult->nError;
	//			}
	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_SUBMITDEALINFO://新增认证申请记录
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				TAGDOA_INFO_S* pInfo = (TAGDOA_INFO_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)]);
	//				if (0 == pInfo->nId)
	//				{
	//					CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("class = CZCMsgManager MsgId = ZC_MSG_OPENDOOR_SUBMITDEALINFO detail = 认证ID为0!\n");
	//					break;				
	//				}
	//				//CZCMsgManager::Instance()->AddNewOpenDoorApply(pInfo);	
	//				CZCMsgManager::Instance()->m_bError[EROSUBMITDEALINFO] = false;
	//				TAGDOA_INFO_S* pBuf = new TAGDOA_INFO_S;
	//				memset(pBuf, 0, sizeof(TAGDOA_INFO_S));
	//				memcpy(pBuf, pInfo, sizeof(TAGDOA_INFO_S));
	//				if ((g_cOpenDoorDlg != NULL)&&(2 == zMsgHead.dwMsgId))
	//				{	
	//					g_cOpenDoorDlg->PostMessage(WN_NEED_NEWAPPLYFEEDBACK, NULL,  (LPARAM)pBuf);
	//				}	
	//				if ((g_cOpenDoorApplyDlg != NULL)&&(1 == zMsgHead.dwMsgId))
	//				{
	//					g_cOpenDoorApplyDlg->PostMessage(WN_GET_NEWAPPLY, NULL, (LPARAM)pBuf);
	//				}	
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROSUBMITDEALINFO] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROSUBMITDEALINFO] = pResult->nError;
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("class = CZCMsgManager MsgId = ZC_MSG_OPENDOOR_SUBMITDEALINFO detail = 生成认证ID失败!\n");
	//				if ((g_cOpenDoorApplyDlg != NULL)&&(1 == zMsgHead.dwMsgId))
	//				{
	//					g_cOpenDoorApplyDlg->PostMessage(WN_GET_NEWAPPLY, NULL, NULL);
	//				}	
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_GETUSERBASEINFO:  ////请求获取用户信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				TAGDOAPPASSWORD_S* pInfo = (TAGDOAPPASSWORD_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)]);
	//				CZCMsgManager::Instance()->AddUserPassWord(pInfo);
	//				CZCMsgManager::Instance()->m_bError[EROGETUSERBASEINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETUSERBASEINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETUSERBASEINFO]=pResult->nError;
	//			}
	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_MODIFYREQUESTSTATE:  //请求修改认证处置状态 
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROMODIFYREQUESTSTATE]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROMODIFYREQUESTSTATE]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROMODIFYREQUESTSTATE]=pResult->nError;
	//			}
	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_GETALLPEPOLEINFO://请求获取所有需管辖人员信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOAPERSONINFO_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOAPERSONINFO_S* pInfo = (TAGDOAPERSONINFO_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOAPERSONINFO_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddAllPersonInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddAllPersonInfo(*pInfo,true);
	//					}
	//					//获取所有人员的照片信息
	//					IsBadReadPtr(pInfo->chHeadImage,sizeof(int)) == TRUE?CZCMsgManager::Instance()->RequrstDownLoadPic("",i)\
	//						:CZCMsgManager::Instance()->RequrstDownLoadPic(pInfo->chHeadImage,i);
	//					
	//					
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETALLPEPOLEINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETALLPEPOLEINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETALLPEPOLEINFO]=pResult->nError;
	//			}

	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 3, 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_COMMON_REQUESTTRANSMSG:  //请求转发消息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROTRANSMSG]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROTRANSMSG]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROTRANSMSG]=pResult->nError;
	//			}

	//			break;
	//		}
	//	case ZC_MSG_COMMON_TRANSMSG:  //客户端转发消息反馈
	//		{
	//			T_TRANS_OPENDOOR_INFO *tFeedBackMsg =(T_TRANS_OPENDOOR_INFO *)pMessage;
	//			break;
	//		}
	//		
	//	case ZC_MSG_ALARM_USERGRAPHINFO://获取收藏的图表信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(S_NEW_SHOWUSERGRAPHINFO);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					S_NEW_SHOWUSERGRAPHINFO* pInfo = (S_NEW_SHOWUSERGRAPHINFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(S_NEW_SHOWUSERGRAPHINFO)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddCollectChartInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddCollectChartInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROCOLLECTCHART]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROCOLLECTCHART]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROCOLLECTCHART]=pResult->nError;
	//			}
	//			if(g_SearchStatisticsDlg!=NULL)
	//			{
	//				g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMCOLLECTCHART,NULL);
	//			}
	//			break;
	//		}
	//		/*
	//	* 实时报警结构体有所扩展(修改时间：2016年3月17日13:35:16)
	//	* 原报警结构体:T_TRANSMITALARMINFO，扩展后结构体为：T_TRANSMITALARMINFO_EX
	//	* 原反馈消息类型：ZC_MSG_ALARM_NEWALARMINFO，修改后消息类型：ZC_MSG_ALARM_NEWALARMINFO_EX 
	//	*/
	//	//case ZC_MSG_ALARM_NEWALARMINFO:  //推送刷卡认证信息
	//	case ZC_MSG_ALARM_NEWALARMINFO_EX: 
	//		{

	//			int i = sizeof(T_TRANSMITALARMINFO_EX);
	//			if(pnMessageSize != sizeof(T_TRANSMITALARMINFO_EX))
	//			{
	//				char chLogInfo[140];
	//				sprintf(chLogInfo, "recv:%s", "结构体长度有误！");
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord(chLogInfo);
	//				break;
	//			}
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("收到刷卡信息 %s",
	//				((T_TRANSMITALARMINFO_EX*)pMessage)->tTransmitAlarmInfo.tAlarmInfo.chMemo);

	//			OPENDOORAPPLYCONFIG* pCtrLevelInfo = CZCMsgManager::Instance()->GetOpenDoorApplyConfig(((T_TRANSMITALARMINFO_EX*)pMessage)->tTransmitAlarmInfo.nDevNumber);	
	//			if (NULL == pCtrLevelInfo)
	//			{
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("class=CZCMsgManager MsgID=ZC_MSG_ALARM_NEWALARMINFO detail=获取管控等级失败\n");
	//				free(pCtrLevelInfo);
	//				pCtrLevelInfo = NULL;
	//				return;
	//			}
	//			if (pCtrLevelInfo->nApplyMethod == 2  /*1-远程 2-本地*/)
	//			{
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("class=CZCMsgManager MsgID=ZC_MSG_ALARM_NEWALARMINFO detail= 区域管控等级三级\n");
	//				free(pCtrLevelInfo);
	//				pCtrLevelInfo = NULL;

	//				S_RECV_CARDLOGINFO* pCardInfo = CZCMsgManager::Instance()->GetCardPersonInfo((T_TRANSMITALARMINFO_EX*)pMessage);
	//				T_TRANS_COMMONHEADINFO tCommonHeadInfo = {0};
	//				char* pTmp = NULL;	
	//				USERDOORCAMERARELATION_CLIENT_GET_S* pUserDoorRelation = CZCMsgManager::Instance()->GetUserDoorRelation(((T_TRANSMITALARMINFO_EX*)pMessage)->tTransmitAlarmInfo.nDevNumber);
	//				if (pUserDoorRelation == NULL)
	//				{
	//					CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Location COpenDoorApplyDlg::OnBnClickedButtonCloseWindow Error:%s", "无法查到金库设备关联用户信息");
	//					return;
	//				}
	//				_snprintf(tCommonHeadInfo.chReceiveUserName, sizeof(tCommonHeadInfo.chReceiveUserName), "%s", pUserDoorRelation->chUserName);
	//				tCommonHeadInfo.dwReceiveModuleType = ZC_MODULE_OPENDOOR;
	//				CZCMsgManager::Instance()->RequestTransMSG( tCommonHeadInfo,pCardInfo, MSG_CARDLOGINFO );
	//				return;
	//			}

	//			T_TRANSMITALARMINFO_EX* pInfo = new T_TRANSMITALARMINFO_EX;
	//			memcpy(pInfo,pMessage,sizeof(T_TRANSMITALARMINFO_EX));

	//			char chLogInfo[140];
	//			sprintf(chLogInfo, "recv:%s", pInfo->tTransmitAlarmInfo.tAlarmInfo.chMemo);
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord(chLogInfo);

	//			if (::IsWindow(g_cOpenDoorDlg->GetSafeHwnd()))
	//			{					
	//				g_cOpenDoorDlg->PostMessage(WN_NEED_SWIP_ALARM, NULL, (LPARAM)pInfo);
	//			}
	//			break;

	//		}
	//	case ZC_MSG_ALARM_OPUSERGRAPH:  //增删改我的图表
	//	{
	//		
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if(pResult->nOK != 0)
	//		{	
	//			
	//			CZCMsgManager::Instance()->m_bError[EROCHANGECOLLECTCHART]=false;
	//		}
	//		else
	//		{
	//			CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//			CZCMsgManager::Instance()->m_bError[EROCHANGECOLLECTCHART]=true;
	//			CZCMsgManager::Instance()->m_iErrorCode[EROCHANGECOLLECTCHART]=pResult->nError;
	//		}
	//		if(g_SearchStatisticsDlg!=NULL)
	//		{
	//			g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMCHANGCHART,NULL);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_ALARM_USERREPORTBOOKINFO://获取用户订阅信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(S_NEW_SHOWUSERREPORTBOOKINFO);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					S_NEW_SHOWUSERREPORTBOOKINFO* pInfo = (S_NEW_SHOWUSERREPORTBOOKINFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(S_NEW_SHOWUSERREPORTBOOKINFO)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddSubscribeInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddSubscribeInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROSUBSCRIBE]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROSUBSCRIBE]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROSUBSCRIBE]=pResult->nError;
	//			}
	//			if(g_SearchStatisticsDlg!=NULL)
	//			{
	//				g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMSUBSCRIBE,NULL);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_ALARM_OPUSERREPORT:  //增、删、改订阅信息
	//	{
	//		
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if(pResult->nOK != 0)
	//		{	
	//			
	//			CZCMsgManager::Instance()->m_bError[EROCHANGESUBSCRIBE]=false;
	//		}
	//		else
	//		{
	//			CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//			CZCMsgManager::Instance()->m_bError[EROCHANGESUBSCRIBE]=true;
	//			CZCMsgManager::Instance()->m_iErrorCode[EROCHANGESUBSCRIBE]=pResult->nError;
	//		}
	//		if(g_SearchStatisticsDlg!=NULL)
	//		{
	//			g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMCHANGESUBSCRIBE,NULL);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_ALARM_USERREPORTINFO://获取报告信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(S_NEW_SHOWUSERREPORTINFO);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					S_NEW_SHOWUSERREPORTINFO* pInfo = (S_NEW_SHOWUSERREPORTINFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(S_NEW_SHOWUSERREPORTINFO)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddReportInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddReportInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROREPORT]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROREPORT]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROREPORT]=pResult->nError;
	//			}
	//			if(g_SearchStatisticsDlg!=NULL)
	//			{
	//				g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMGETREPORT,NULL);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_ALARM_MODSTATUSUSERREPORT:  //修改报告状态信息
	//	{
	//		
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if(pResult->nOK != 0)
	//		{	
	//			
	//			CZCMsgManager::Instance()->m_bError[EROCHANGEREPORTSTATUS]=false;
	//		}
	//		else
	//		{
	//			CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//			CZCMsgManager::Instance()->m_bError[EROCHANGEREPORTSTATUS]=true;
	//			CZCMsgManager::Instance()->m_iErrorCode[EROCHANGEREPORTSTATUS]=pResult->nError;
	//		}
	//		if(g_SearchStatisticsDlg!=NULL)
	//		{
	//			g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMCHANGEREPORTSTATUS,NULL);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_OPENDOOR_ACCESSRELATION: //获取门禁主从关系信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOACCESSRELATION_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOACCESSRELATION_S* pInfo = (TAGDOACCESSRELATION_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOACCESSRELATION_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddAccessRelation(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddAccessRelation(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROACCESSRELATION]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROACCESSRELATION]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROACCESSRELATION]=pResult->nError;
	//			}
	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 5, 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_CTRLLEVELMULINFO: ////请求获取管控等级信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(S_NEW_CTRLLEVELINFO);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					S_NEW_CTRLLEVELINFO* pInfo = (S_NEW_CTRLLEVELINFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(S_NEW_CTRLLEVELINFO)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddCtrlLevelInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddCtrlLevelInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROCTRLLEVELMULINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROCTRLLEVELMULINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROCTRLLEVELMULINFO]=pResult->nError;
	//			}
	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 7, 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_CTRLLEVELPLAN:  //请求获取管控策略信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGCTRLEVELPLAN_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGCTRLEVELPLAN_S* pInfo = (TAGCTRLEVELPLAN_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGCTRLEVELPLAN_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddCtrlLevelPlan(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddCtrlLevelPlan(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROCTRLLEVELPLAN]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROCTRLLEVELPLAN]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROCTRLLEVELPLAN]=pResult->nError;
	//			}
	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 8, 0);
	//			}

	//			break;

	//		}
	//		//申请详细信息请求反馈
	//	case ZC_MSG_OPENDOOR_GETAPPLYHISTORYDETAIL:
	//		{
	//			BYTE *pBuf = (BYTE *)pMessage;
	//			ZC_MSG_RESP_RESULT * pResult = (ZC_MSG_RESP_RESULT *)pBuf;
	//			if (pResult->nOK != 0)
	//			{
	//				TAGDOAAPPLYDETAIL_S * pInfo = (TAGDOAAPPLYDETAIL_S *)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)]);
	//				CZCMsgManager::Instance()->SetApplyDetailInfo(*pInfo);
	//				CZCMsgManager::Instance()->m_bError[EROAPPLYDETAILINFO] = false;

	//				if (-1 == zMsgHead.dwMsgId)//新认证
	//				{
	//					TAGDOAAPPLYDETAIL_S* pBuf = new TAGDOAAPPLYDETAIL_S;
	//					memset(pBuf, 0, sizeof(TAGDOAAPPLYDETAIL_S));
	//					memcpy(pBuf, pInfo, sizeof(TAGDOAAPPLYDETAIL_S));
	//					if (g_cOpenDoorGeneralListDlg)
	//					{
	//						g_cOpenDoorGeneralListDlg->PostMessage(WM_GET_APPLYDETAILINFO, 0, (LPARAM)pBuf);
	//					}
	//				}
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROAPPLYDETAILINFO] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROAPPLYDETAILINFO] = pResult->nError;
	//				if (-1 == zMsgHead.dwMsgId)//新认证
	//				{
	//					CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_GETAPPLYHISTORYDETAIL Detail = 错误码%d\n", pResult->nError);
	//				}
	//			}
	//			
	//			if (1 == zMsgHead.dwMsgId)
	//			{
	//				if (g_SearchStatisticsDlg!=NULL)
	//				{
	//					g_SearchStatisticsDlg->PostMessage(WM_COMMAND, WMCENTIFICATIONDETAILINFO, 0);
	//				}
	//			}
	//			else if(2 == zMsgHead.dwMsgId)
	//			{
	//				if (g_SearchStatisticsDlg!=NULL)
	//				{
	//					g_SearchStatisticsDlg->PostMessage(WM_COMMAND, WMSTAFFCERTIFICATIONINFO, 0);
	//				}
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_MODIFYISCOLLECTION:   //请求修改收藏状态
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	

	//				CZCMsgManager::Instance()->m_bError[EROISCOLLECTIONS]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROISCOLLECTIONS]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROISCOLLECTIONS]=pResult->nError;
	//			}
	//			break;
	//		}

	//	case ZC_MSG_OPENDOOR_DEPARTMENTINFO:  //部门信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOADEPARTMENTINFO_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOADEPARTMENTINFO_S* pInfo = (TAGDOADEPARTMENTINFO_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOADEPARTMENTINFO_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddDepartmentInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddDepartmentInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[ERODEPARTMENT]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[ERODEPARTMENT]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[ERODEPARTMENT]=pResult->nError;
	//			}
	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 4, 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_COMMON_PLANINFO:  //获取预案库
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(S_NEW_SHOWPLANLIB);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					S_NEW_SHOWPLANLIB* pInfo = (S_NEW_SHOWPLANLIB*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(S_NEW_SHOWPLANLIB)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddPlanLib(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddPlanLib(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETPLANINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETPLANINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETPLANINFO]=pResult->nError;
	//			}
	//			if (g_cRemotePopUpDlg != NULL)
	//			{
	//				g_cRemotePopUpDlg->PostMessage(WM_COMMAND, WN_GET_EMERGENCYPLAN, NULL);
	//			}

	//			break;
	//		}
	//	case ZC_MSG_COMMON_DOWNLOADPIC:    //获取照片路径
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if(pResult->nOK != 0)
	//		{
	//			memcpy(CZCMsgManager::Instance()->m_cImage, &pBuf[sizeof(ZC_MSG_RESP_RESULT)], 512);
	//			CZCMsgManager::Instance()->m_bError[EROPHOTO] = false;
	//			if (1000 == zMsgHead.dwMsgId)
	//			{
	//				if (g_cOpenDoorApplyDlg != NULL)
	//				{
	//					char* strImage = new char[512];
	//					memset(strImage, 0, 512);
	//					memcpy(strImage, (CZCMsgManager::Instance()->m_cImage), 512);
	//					g_cOpenDoorApplyDlg->PostMessage(WM_GET_IPTALKADRESS, 0, (LPARAM)strImage);
	//				}
	//			}
	//			else if (1001 == zMsgHead.dwMsgId)
	//			{
	//				if (g_cOpenDoorApplyDlg != NULL)
	//				{
	//					char* strImage = new char[512];
	//					memset(strImage, 0, 512);
	//					memcpy(strImage, (CZCMsgManager::Instance()->m_cImage), 512);

	//					g_cOpenDoorApplyDlg->SendMessage(WM_GET_MANUALCAPTUREADDREE, 0, (LPARAM)strImage);

	//				}
	//			}
	//			else if (1002 == zMsgHead.dwMsgId)
	//			{
	//				if (g_cOpenDoorApplyDlg != NULL)
	//				{
	//					//g_cOpenDoorApplyDlg->PostMessage(WM_GET_MANUALCAPTUREADDREE, 0, (LPARAM)(CZCMsgManager::Instance()->m_cImage));
	//				}
	//			}
	//			else if (1004 == zMsgHead.dwMsgId)
	//			{
	//				if (NULL != g_cRemotePopUpDlg)
	//				{
	//					char* strImage = new char[512];
	//					memset(strImage, 0, 512);
	//					memcpy(strImage,(CZCMsgManager::Instance()->m_cImage),512);

	//					g_cRemotePopUpDlg->PostMessage(WM_COMMAND, WN_GET_CAPTUREATTACHMENT, 0);
	//				}
	//			}
	//			else if(WM_REQ_HEADIMG_ID == zMsgHead.dwMsgId)
	//			{
	//				char * pImg = new char[512];
	//				memset(pImg, 0, 512);
	//				strcpy(pImg, CZCMsgManager::Instance()->m_cImage);
	//				PostMessage(CZCMsgManager::Instance()->hAddStaffInfoUI, WM_GET_INIT_HEADIMG_ADDDLG, 0, (LPARAM)pImg);

	//			}
	//			else if(WM_REQ_ATTACHIMG_ID == zMsgHead.dwMsgId)
	//			{
	//				char * pImg = new char[512];
	//				memset(pImg, 0, 512);
	//				strcpy(pImg, CZCMsgManager::Instance()->m_cImage);
	//				PostMessage(CZCMsgManager::Instance()->hAddStaffInfoUI, WM_GET_INIT_ATTACHIMG_ADDDLG, 0, (LPARAM)pImg);

	//			}
	//			else
	//			{
	//				if (CZCMsgManager::Instance()->m_vPersonPhoto[zMsgHead.dwMsgId] == NULL)
	//				{
	//					char* strPhoto = new char[512];
	//					memcpy(strPhoto, CZCMsgManager::Instance()->m_cImage, 512);
	//					CZCMsgManager::Instance()->m_vPersonPhoto[zMsgHead.dwMsgId] = strPhoto;
	//				}
	//				else
	//				{
	//					memcpy(CZCMsgManager::Instance()->m_vPersonPhoto[zMsgHead.dwMsgId], CZCMsgManager::Instance()->m_cImage, 512);
	//				}
	//			}
	//		}
	//		else
	//		{
	//			if (CZCMsgManager::Instance()->m_vPersonPhoto[zMsgHead.dwMsgId] == NULL)
	//			{
	//				char* strPhoto = new char[512];
	//				memset(strPhoto, 0, 512);
	//				CZCMsgManager::Instance()->m_vPersonPhoto[zMsgHead.dwMsgId] = strPhoto;
	//			}
	//			else
	//			{
	//				memset(CZCMsgManager::Instance()->m_vPersonPhoto[zMsgHead.dwMsgId], 0, 512);
	//			}		

	//			CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//			CZCMsgManager::Instance()->m_bError[EROPHOTO] = true;
	//			CZCMsgManager::Instance()->m_iErrorCode[EROPHOTO] = pResult->nError;
	//		}
	//		break;			
	//	}
	//	case ZC_MSG_COMMON_ALLKEYPARTINFO: //获取所有部位信息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(S_NEW_SHOWPOSITIONINFO);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					S_NEW_SHOWPOSITIONINFO* pInfo = (S_NEW_SHOWPOSITIONINFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(S_NEW_SHOWPOSITIONINFO)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddPartInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddPartInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETALLPARTINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETALLPARTINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETALLPARTINFO]=pResult->nError;
	//			}
	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 9, 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_COMMON_UPLOADATTACHMENT:  //上传附件
	//		{
	//			BYTE *pBuf = (BYTE *)pMessage;
	//			ZC_MSG_RESP_RESULT * pResult = (ZC_MSG_RESP_RESULT *)pBuf;
	//			if (pResult->nOK != 0)
	//			{
	//				char* pInfo = (char *)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)]);
	//				CZCMsgManager::Instance()->AddAttachmentId(pInfo);
	//				CZCMsgManager::Instance()->m_bError[EROUPLOADATTACTMENT] = false;
	//				if (zMsgHead.dwMsgId == UINT_UPLOAD_ATTACTMENT)
	//				{
	//					PostMessage(CZCMsgManager::Instance()->hAddStaffInfoUI, UINT_UPLAOD_ATTACTMENT_SUCCESS, 0, (LPARAM)&CZCMsgManager::Instance()->m_chAttachment);
	//				}
	//				else if (zMsgHead.dwMsgId == UINT_UPLOAD_HEADPIC)
	//				{
	//					PostMessage(CZCMsgManager::Instance()->hAddStaffInfoUI, UINT_UPLAOD_HEADPIC_SUCCESS, 0, (LPARAM)&CZCMsgManager::Instance()->m_chAttachment);
	//				}
	//			}
	//			else
	//			{
	//				if (zMsgHead.dwMsgId == UINT_UPLOAD_ATTACTMENT)
	//				{
	//					PostMessage(CZCMsgManager::Instance()->hAddStaffInfoUI, UINT_UPLAOD_ATTACTMENT_FAIL, 0, NULL);
	//				}
	//				else if (zMsgHead.dwMsgId == UINT_UPLOAD_HEADPIC)
	//				{
	//					PostMessage(CZCMsgManager::Instance()->hAddStaffInfoUI, UINT_UPLAOD_HEADPIC_FAIL, 0, NULL);
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROUPLOADATTACTMENT] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROUPLOADATTACTMENT] = pResult->nError;
	//			}
	//			if (1 == zMsgHead.dwMsgId)
	//			{
	//				if (NULL != g_cOpenDoorApplyDlg)
	//				{
	//					g_cOpenDoorApplyDlg->SendMessage(WM_COMMAND, WM_GET_MANUALCAPTURE, 0);
	//				}						
	//			}
	//			else if (2 == zMsgHead.dwMsgId)
	//			{
	//				if (NULL != g_cOpenDoorApplyDlg)
	//				{
	//					g_cOpenDoorApplyDlg->PostMessage(WM_COMMAND, WM_GET_IPTALK, 0);
	//				}
	//			}
	//			else if (3 == zMsgHead.dwMsgId)
	//			{
	//				if (NULL != g_cOpenDoorDlg)
	//				{
	//					g_cOpenDoorDlg->PostMessage(WM_COMMAND, WN_GET_PRECAPTUREID, 0);
	//				}
	//			}
	//			else if (1004 == zMsgHead.dwMsgId)
	//			{
	//				if (NULL != g_cRemotePopUpDlg)
	//				{
	//					g_cRemotePopUpDlg->PostMessage(WM_COMMAND, WN_GET_CAPTUREATTACHMENT, 0);
	//				}
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_CAPTUREWITHOUTOPEN:  //预抓图
	//		{
	//			BYTE *pBuf = (BYTE *)pMessage;
	//			ZC_MSG_RESP_RESULT * pResult = (ZC_MSG_RESP_RESULT *)pBuf;
	//			if (pResult->nOK != 0)
	//			{
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/256;
	//				for(int i=0;i<iCount;i++)
	//				{
	//					char* pInfo = (char*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*256]);
	//					bool bRet = CZCMsgManager::Instance()->AddPreCapture(zMsgHead.dwMsgId, pInfo, false);
	//					if (bRet && NULL != g_cOpenDoorApplyDlg)
	//					{
	//						g_cOpenDoorApplyDlg->SendMessage(WM_GET_PRECAPTURE, 0, 0);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETALLPARTINFO]=false;

	//			}
	//			else{
	//				CZCMsgManager::Instance()->m_bError[EROUPLOADATTACTMENT] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROUPLOADATTACTMENT] = pResult->nError;
	//			}
	//			
	//			break;
	//		}
	//	case ZC_MSG_TASK_SHORTMESSAGE:  //响应发短信
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROSENDSHORTMSG]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROSENDSHORTMSG]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROSENDSHORTMSG]=pResult->nError;
	//			}
	//			if (NULL != g_cRemotePopUpDlg)
	//			{
	//				g_cRemotePopUpDlg->PostMessage(WN_NEED_ACTIONFEEDBACK,14, 0);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_COMMON_SENDEMAIL:	//响应发邮件
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROSENDEMAIL]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROSENDEMAIL]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROSENDEMAIL]=pResult->nError;
	//			}
	//			if (NULL != g_cRemotePopUpDlg)
	//			{
	//				g_cRemotePopUpDlg->PostMessage(WN_NEED_ACTIONFEEDBACK,15, 0);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_ALARM_DEFENCEDEV:	//响应布撤防设备
	//		{
	//			BYTE *pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT *)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				CZCMsgManager::Instance()->m_bError[EROIFSETDEFENSE]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROIFSETDEFENSE]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROIFSETDEFENSE]=pResult->nError;
	//			}
	//			if (NULL != g_cRemotePopUpDlg)
	//			{
	//				g_cRemotePopUpDlg->PostMessage(WN_NEED_ACTIONFEEDBACK,16, 0);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_OPENBASESET:  //基础设置窗口打开
	//		{
	//			if(g_cOpenDoorDlg!=NULL)
	//			{
	//				//g_cOpenDoorDlg->PostMessage(WM_COMMAND,WMBASICSETING,NULL);
	//			}
	//			break;
	//		}
	//		
	//	case ZC_MSG_OPENDOOR_OPENDATAMANAGER:  //打开查询与统计管理界面
	//		{
	//			if(g_cOpenDoorDlg!=NULL)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_COMMAND,WMSEARCHSTATISTIC,NULL);
	//			}
	//			break;
	//		}
	//		//new add 2016年7月7日09:20:12
	//	case ZC_MSG_OPENDOOR_OPENUSERMANAGER:  //打开人员管理界面
	//		{
	//			if(g_cOpenDoorDlg!=NULL)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_COMMAND,WM_REQ_OPEN_STAFF_MANAGERDLG, NULL);
	//			}
	//			break;
	//		}

	//	case ZC_MSG_OPENDOOR_SETUSERBASEINFO:	//设置基本信息
	//		{
	//			BYTE *pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT *)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				TAGDOAPPASSWORD_P info={0};
	//				strcpy(info.chUserName,CZCMsgManager::Instance()->m_CurrentUserInfo.chUserName);
	//				CZCMsgManager::Instance()->RequestUserPassWord(info);
	//				CZCMsgManager::Instance()->m_bError[EROBASICSETTING]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROBASICSETTING]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROBASICSETTING]=pResult->nError;
	//			}
	//			if (g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_SET_OPENDOORICONSHOW, (WPARAM)(CZCMsgManager::Instance()->m_iShow), NULL);
	//			}

	//			break;
	//		}

	//	case ZC_MSG_TASK_CAPTUREPIC:  //响应抓图，给出附件
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				T_ATTACHMENTINFO* pInfo = (T_ATTACHMENTINFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)]);
	//				CZCMsgManager::Instance()->AddCaptureAttachment(*pInfo,false);
	//				CZCMsgManager::Instance()->m_bError[EROCAPTURE]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROCAPTURE]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROCAPTURE]=pResult->nError;
	//			}
	//			if (NULL != g_cRemotePopUpDlg)
	//			{
	//				g_cRemotePopUpDlg->PostMessage(WN_NEED_ACTIONFEEDBACK,11, 0);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_GETACSHOSTLINKINFO: //获门禁主机关联摄像头设备
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(S_FrontendTalkInfo);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					S_FrontendTalkInfo* pInfo = (S_FrontendTalkInfo*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(S_FrontendTalkInfo)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddFrontendTalkInfo(*pInfo,false);//attention:这里会比较错乱。由于历史原因，返回结构体名字用错（但结构体的结构正好符合），所以函数名也是错误的（按照错误的结构体名命名）
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddFrontendTalkInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROGETACSHOSTLINKINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETACSHOSTLINKINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETACSHOSTLINKINFO]=pResult->nError;
	//			}

	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 10, 0);
	//			}
	//			break;

	//		}
	//	case ZC_MSG_OPENDOOR_ADDEXCEPTIONINFO:
	//		{
	//			BYTE *pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT *)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				TAGDOAEXCEPINFO_S info={0};
	//				CZCMsgManager::Instance()->m_bError[EROEXCEPTINPUT]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROEXCEPTINPUT]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROEXCEPTINPUT]=pResult->nError;
	//			}

	//			if (TRUE == CZCMsgManager::Instance()->m_bIsAbnormalId)
	//			{
	//				if (NULL != g_cOpenDoorApplyDlg)
	//				{
	//					//g_cOpenDoorApplyDlg->PostMessage(WM_COMMAND, WN_GET_NEWAPPLY, NULL);
	//					CZCMsgManager::Instance()->m_bIsAbnormalId = FALSE;
	//				}
	//			}

	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_GETACSHOSTLINKTALKINFO:
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(S_HostTalkInfo);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					S_HostTalkInfo* pInfo = (S_HostTalkInfo*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(S_HostTalkInfo)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddHostTalkInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddHostTalkInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROHOSTTALKINFO]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROHOSTTALKINFO]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROHOSTTALKINFO]=pResult->nError;
	//			}

	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 11, 0);
	//			}
	//			break;

	//		}
	//	case ZC_MSG_COMMON_ALLUSERINFO:  //请求获取所有处理人姓名信息
	//		{

	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				CString csTemp;
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/64;
	//				for(int i=0;i<iCount;i++)
	//				{
	//					char* pInfo = (char*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*64]);
	//					CZCMsgManager::Instance()->RequestUserDetail(pInfo, i);
	//					CharToCString(pInfo,csTemp,64);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddAllDealerInfo(csTemp,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddAllDealerInfo(csTemp,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROALLUSER]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROALLUSER]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROALLUSER]=pResult->nError;
	//			}
	//			break;
	//		}
	//	case ZC_MSG_COMMON_USERALLINFO:
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			S_New_UserInfo* pTmp = (S_New_UserInfo*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)]);
	//			int nRet = pResult->nOK;
	//			if (0 != nRet)
	//			{
	//				if(-1 == zMsgHead.dwMsgId)
	//				{
	//					memset(CZCMsgManager::Instance()->m_pUserDetail, 0, sizeof(CZCMsgManager::Instance()->m_pUserDetail));
	//					memcpy(CZCMsgManager::Instance()->m_pUserDetail, &pBuf[sizeof(ZC_MSG_RESP_RESULT)], sizeof(S_New_UserInfo));
	//				}
	//				else
	//				{
	//					S_New_UserInfo* tUserInfo = new S_New_UserInfo;
	//					memset(tUserInfo, 0, sizeof(S_New_UserInfo));
	//					memcpy(tUserInfo, &pBuf[sizeof(ZC_MSG_RESP_RESULT)], sizeof(S_New_UserInfo));
	//					CZCMsgManager::Instance()->AddUserInfoToMap(tUserInfo, zMsgHead.dwMsgId);
	//				}	
	//			}
	//			else
	//			{
	//				//todo 暂不处理用户详细信息获取失败的情况	
	//			}

	//		}
	//		break;
	//	case ZC_MSG_ALARM_ALARMREPLAY_CLOSE:
	//		{
	//			BYTE *pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT *)pBuf;
	//			int nRet = pResult->nOK;
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_OPENLINKVIDEO:  //新方式联动视频反馈
	//		{
	//			BYTE *pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT *)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//			}
	//			else 
	//			{
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_OPENLINKVIDEO Detail = 错误码%d\n", pResult->nError);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_ALARM_GETMSATTACHMENT:  //获取视频附件列表反馈
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				bool bRet = CZCMsgManager::Instance()->RequestPlayAttachmentList(&pBuf[sizeof(ZC_MSG_RESP_RESULT)], pnMessageSize - sizeof(ZC_MSG_RESP_RESULT));
	//			}
	//			else 
	//			{
	//				 CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_ALARM_GETMSATTACHMENT Detail = 错误码%d", pResult->nError);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_TASK_STARTCHECKPLAYBACK:  //请求回放下载反馈
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//			}
	//			else 
	//			{
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_TASK_STARTCHECKPLAYBACK Detail = 错误码%s", pResult->nError);
	//			}

	//			break;
	//		}
	//	case ZC_MSG_TASK_STOPCHECKPLAYBACK:    //请求关闭回放下载
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{									
	//			}
	//			else 
	//			{
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_TASK_STOPCHECKPLAYBACK Detail = 错误码%s", pResult->nError);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_USERDOORCAMERARELATION:
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if (pResult->nOK != 0)
	//			{
	//				int nCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(USERDOORCAMERARELATION_CLIENT_GET_S);
	//				for (int i = 0; i < nCount; i++)
	//				{
	//					USERDOORCAMERARELATION_CLIENT_GET_S*  pRelationInfo = (USERDOORCAMERARELATION_CLIENT_GET_S*)(&(pBuf[sizeof(ZC_MSG_RESP_RESULT) + sizeof(USERDOORCAMERARELATION_CLIENT_GET_S)*i]));
	//					 CZCMsgManager::Instance()->AddUserDoorCameraRelationInfo(pRelationInfo);
	//				}
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_USERDOORCAMERARELATION Detail = 错误码%d", pResult->nError);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_ACCESSSYRELATION_GET: //获取门禁关联守押设备
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(ACCESSSYRELATION_GET_S);
	//				for(int i = 0; i < iCount; i++)
	//				{
	//					ACCESSSYRELATION_GET_S* pInfo = (ACCESSSYRELATION_GET_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT) + i*sizeof(ACCESSSYRELATION_GET_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddEscortAccessRelation(*pInfo, false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddEscortAccessRelation(*pInfo, true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROESCORTACCESSRELATION] = false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROESCORTACCESSRELATION] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROESCORTACCESSRELATION] = pResult->nError;
	//			}
	//			if (NULL != g_cOpenDoorDlg)
	//			{
	//				g_cOpenDoorDlg->PostMessage(WM_NEED_BASICDATAFEEDBACK, 12, 0);
	//			}

	//			break;

	//		}
	//	case ZC_MSG_ALARM_LOCKMSATTACHMENT:
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if (pResult->nOK != 0)
	//			{
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_ALARM_LOCKMSATTACHMENT Detail = 锁定解锁联动文件失败 错误码%d\n", pResult->nError);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_GETAPPLYHISTORYLOCKINFO:     //带锁定状态的认证历史记录反馈
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{	
	//				int iCount = (pnMessageSize-sizeof(ZC_MSG_RESP_RESULT))/sizeof(TAGDOAHISTORYINFO_S);
	//				for(int i=0;i<iCount;i++)
	//				{
	//					TAGDOAHISTORYINFO_S* pInfo = (TAGDOAHISTORYINFO_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT)+i*sizeof(TAGDOAHISTORYINFO_S)]);
	//					if(i != 0)
	//					{
	//						CZCMsgManager::Instance()->AddCertificationSearchInfo(*pInfo,false);
	//					}
	//					else
	//					{
	//						CZCMsgManager::Instance()->AddCertificationSearchInfo(*pInfo,true);
	//					}
	//				}
	//				CZCMsgManager::Instance()->m_bError[EROCERTIFICATION]=false;
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROCERTIFICATION]=true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROCERTIFICATION]=pResult->nError;
	//			}
	//			if(g_SearchStatisticsDlg!=NULL)
	//			{
	//				g_SearchStatisticsDlg->PostMessage(WM_COMMAND,WMCERTIFICATIONSEARCH,NULL);
	//			}
	//			break;
	//		}
	//	case ZC_MSG_OPENDOOR_STAFFINFOOPERATION:  //请求设置人员信息
	//	{			
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if (pResult->nOK != 0)
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, UNIT_SET_STAFFINFO_SUCCESS, zMsgHead.dwMsgId, NULL);
	//		}
	//		else
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, UNIT_SET_STAFFINFO_FAIL, zMsgHead.dwMsgId, NULL);
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_STAFFINFOOPERATION Detail = 设置人员失败 错误码%d", pResult->nError);
	//		}
	//			break;
	//	}
	//	case ZC_MSG_OPENDOOR_DEPARTMENTINFOOPERATION:  //请求设置部门信息
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if (pResult->nOK != 0)
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, UNIT_SET_DEPARTMENINFO_SUCCESS, zMsgHead.dwMsgId, NULL);
	//		}
	//		else
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, UNIT_SET_DEPARTMENINFO_FAIL, zMsgHead.dwMsgId, NULL);
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_DEPARTMENTINFOOPERATION Detail = 设置部门失败 错误码%d", pResult->nError);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_OPENDOOR_STAFFSTATUS_SET:  //请求设置人员状态信息
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if (pResult->nOK != 0)
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, UNIT_SET_STAFFSTATEINFO_SUCCESS, 0, NULL);
	//		}
	//		else
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, UNIT_SET_STAFFSTATEINFO_FAIL, 0, NULL);
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_STAFFSTATUS_SET Detail = 设置人员状态失败 错误码%d\n", pResult->nError);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_OPENDOOR_DEPARTMENTINFO_GET:  //请求获取部门信息
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if (pResult->nOK != 0)
	//		{
	//			int iCount = (pnMessageSize - sizeof(ZC_MSG_RESP_RESULT)) / sizeof(DEPARTMENTINFO_GET_S);
	//			DEPARTMENTINFO_GET_S* pInfo = new DEPARTMENTINFO_GET_S;
	//			for (int i = 0; pInfo && i<iCount; i++)
	//			{
	//				memset(pInfo, 0, sizeof(DEPARTMENTINFO_GET_S));
	//				memcpy(pInfo, (DEPARTMENTINFO_GET_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT) + i*sizeof(DEPARTMENTINFO_GET_S)]), sizeof(DEPARTMENTINFO_GET_S));
	//				if (i != 0)
	//				{
	//					CZCMsgManager::Instance()->AddStaffDepartment(pInfo, false);
	//				}
	//				else
	//				{
	//					CZCMsgManager::Instance()->AddStaffDepartment(pInfo, true);
	//				}
	//			}
	//			if(pInfo)
	//			{
	//				delete pInfo;
	//				pInfo = NULL;
	//			}

	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, WM_COMMAND, UNIT_GET_DEPARTMENINFO_SUCCESS, NULL);
	//		}
	//		else
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, WM_COMMAND, UNIT_GET_DEPARTMENINFO_FAIL, NULL);

	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_DEPARTMENTINFO_GET Detail = 获取部门信息失败 错误码%d\n", pResult->nError);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_OPENDOOR_AUTHGROUP_GET:  //请求获取权限组
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if (pResult->nOK != 0)
	//		{
	//			int iCount = (pnMessageSize - sizeof(ZC_MSG_RESP_RESULT)) / sizeof(AUTHGROUP_GET_S);
	//			AUTHGROUP_GET_S* pInfo = new AUTHGROUP_GET_S;
	//			for (int i = 0; pInfo && i<iCount; i++)
	//			{
	//				memset(pInfo, 0, sizeof(AUTHGROUP_GET_S));
	//				memcpy(pInfo, (AUTHGROUP_GET_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT) + i*sizeof(AUTHGROUP_GET_S)]), sizeof(AUTHGROUP_GET_S));
	//				if (i != 0)
	//				{
	//					CZCMsgManager::Instance()->AddAuthgroup(pInfo, false);
	//				}
	//				else
	//				{
	//					CZCMsgManager::Instance()->AddAuthgroup(pInfo, true);
	//				}
	//			}
	//			if(pInfo)
	//			{
	//				delete pInfo;
	//				pInfo = NULL;
	//			}
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, WM_COMMAND, UNIT_GET_AUTHGROUPINFO_SUCCESS, NULL);
	//		}
	//		else
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, WM_COMMAND, UNIT_GET_AUTHGROUPINFO_FAIL, NULL);
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_AUTHGROUP_GET Detail = 获取权限组信息失败 错误码%d\n", pResult->nError);
	//		}
	//		break;		
	//	}
	//	case ZC_MSG_OPENDOOR_STAFFINFO_GET:  //请求获取人员信息
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if (pResult->nOK != 0)
	//		{
	//			int iCount = (pnMessageSize - sizeof(ZC_MSG_RESP_RESULT)) / sizeof(STAFFINFO_GET_S);
	//			if(zMsgHead.dwMsgId == USER_MSG_SERIAL_ID_DELETE_DEPARTMENT)
	//			{
	//				// 检查该部门是否可以删除
	//				BOOL bCanDelDepart = TRUE;
	//				if(iCount > 0)
	//				{
	//					bCanDelDepart = FALSE;
	//				}
	//				PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, WM_MSG_DEPARTMENT_CAN_DELETE,
	//					bCanDelDepart, NULL);
	//				break;
	//			}
	//			STAFFINFO_GET_S* pInfo = new STAFFINFO_GET_S;
	//			for (int i = 0; pInfo && i<iCount; i++)
	//			{
	//				memset(pInfo, 0, sizeof(STAFFINFO_GET_S));
	//				memcpy(pInfo, (STAFFINFO_GET_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT) + i*sizeof(STAFFINFO_GET_S)]), sizeof(STAFFINFO_GET_S));
	//				if (i != 0)
	//				{
	//					CZCMsgManager::Instance()->AddStaffinfo(pInfo, false);
	//				}
	//				else
	//				{
	//					CZCMsgManager::Instance()->AddStaffinfo(pInfo, true);
	//				}
	//			}
	//			if(pInfo)
	//			{
	//				delete pInfo;
	//				pInfo = NULL;
	//			}
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, WM_COMMAND, UNIT_GET_STAFFINFO_SUCCESS, NULL);
	//		}
	//		else
	//		{
	//			if(zMsgHead.dwMsgId == USER_MSG_SERIAL_ID_DELETE_DEPARTMENT)
	//			{
	//				// 检查该部门是否可以删除
	//				PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, WM_MSG_DEPARTMENT_CAN_DELETE, TRUE, NULL);
	//				break;
	//			}
	//			PostMessage(CZCMsgManager::Instance()->hStaffManagerUI, WM_COMMAND, UNIT_GET_STAFFINFO_FAIL, NULL);
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_STAFFINFO_GET Detail = 获取人员信息失败 错误码%d\n", pResult->nError);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_OPENDOOR_STAFFOPERATION_GET:  //请求获取人员操作信息
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if (pResult->nOK != 0)
	//		{
	//			int iCount = (pnMessageSize - sizeof(ZC_MSG_RESP_RESULT)) / sizeof(STAFFOPERATION_GET_S);
	//			STAFFOPERATION_GET_S* pInfo = new STAFFOPERATION_GET_S;
	//			for (int i = 0; pInfo && i<iCount; i++)
	//			{
	//				memset(pInfo, 0, sizeof(STAFFOPERATION_GET_S));
	//				memcpy(pInfo, (STAFFOPERATION_GET_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT) + i*sizeof(STAFFOPERATION_GET_S)]), sizeof(STAFFOPERATION_GET_S));
	//				if (i != 0)
	//				{

	//					CZCMsgManager::Instance()->AddStaffOperationinfo(pInfo, false);
	//				}
	//				else
	//				{
	//					CZCMsgManager::Instance()->AddStaffOperationinfo(pInfo, true);
	//				}
	//			}
	//			if(pInfo)
	//			{
	//				delete pInfo;
	//				pInfo = NULL;
	//			}
	//			PostMessage(CZCMsgManager::Instance()->hOperationInfoUI, WM_COMMAND, UNIT_GET_STAFFOPERATION_SUCCESS, NULL);
	//		}
	//		else
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hOperationInfoUI, WM_COMMAND, UNIT_SET_STAFFOPERATION_FAIL, NULL);
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_STAFFOPERATION_GET Detail = 获取人员操作信息失败 错误码%d\n", pResult->nError);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_OPENDOOR_STAFFAUTHINFO_GET:
	//	{
	//		BYTE* pBuf = (BYTE*)pMessage;
	//		ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//		if (pResult->nOK != 0)
	//		{
	//			int iCount = (pnMessageSize - sizeof(ZC_MSG_RESP_RESULT)) / sizeof(STAFFAUTHINFO_GET_S);
	//			for (int i = 0; i<iCount; i++)
	//			{
	//				STAFFAUTHINFO_GET_S tInfo;
	//				memset(&tInfo, 0, sizeof(STAFFAUTHINFO_GET_S));
	//				memcpy(&tInfo, (STAFFAUTHINFO_GET_S*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT) + i*sizeof(STAFFAUTHINFO_GET_S)]), sizeof(STAFFAUTHINFO_GET_S));
	//				if (i != 0)
	//				{
	//					CZCMsgManager::Instance()->AddStaffAuthgroup(tInfo, false);
	//				}
	//				else
	//				{
	//					CZCMsgManager::Instance()->AddStaffAuthgroup(tInfo, true);
	//				}
	//			}
	//			PostMessage(CZCMsgManager::Instance()->hAddStaffInfoUI, UNIT_GET_STAFFAUTHGROUPINFO_SUCCESS, TRUE, NULL);
	//		}
	//		else
	//		{
	//			PostMessage(CZCMsgManager::Instance()->hAddStaffInfoUI, UNIT_GET_STAFFAUTHGROUPINFO_FAIL, FALSE, NULL);
	//			CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function = pfCallback  MsgID = ZC_MSG_OPENDOOR_AUTHGROUP_GET Detail = 获取权限组信息失败 错误码:%d\n", pResult->nError);
	//		}
	//		break;
	//	}
	//	case ZC_MSG_SYSDORCTOR_DEVINFO:  //请求获取所有主机节点信息 不含资产编号
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				int iCount = (pnMessageSize - sizeof(ZC_MSG_RESP_RESULT)) / sizeof(DEV_NODE_INFO);

	//				for(int i=0; i<iCount; i++)
	//				{
	//					DEV_NODE_INFO* pInfo = (DEV_NODE_INFO*)(&pBuf[sizeof(ZC_MSG_RESP_RESULT) + i * sizeof(DEV_NODE_INFO)]);		
	//					THostNode* pHostNode = new THostNode(pInfo);			
	//					bool bRet = CGlobalManager::Instance()->m_pNodeService->pFirstCenterNode->AddNewHostNodeInfo(pHostNode);
	//					if(!bRet)
	//					{
	//						delete pHostNode;
	//						pHostNode = NULL;
	//					}
	//				}
	//			}
	//			else
	//			{
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("<<NORMAL>>%s", "GethostInfo结果集为空");
	//			}
	//			CGlobalManager::Instance()->m_pNodeService->bGetDevInfoOk = true;
	//			break;

	//		}
	//	case ZC_MSG_COMMON_THIRDPART_EXCHANGEMESSAGE:	//请求跟第三方系统交换消息
	//		{
	//			BYTE* pBuf = (BYTE*)pMessage;
	//			ZC_MSG_RESP_RESULT* pResult = (ZC_MSG_RESP_RESULT*)pBuf;
	//			if(pResult->nOK != 0)
	//			{
	//				int nMsgType;
	//				memcpy(&nMsgType, &pBuf[sizeof(ZC_MSG_RESP_RESULT)], sizeof(int));
	//				if (nMsgType = THIRDPART_MESSAGE_SY_SCHEDULE_INFO)
	//				{
	//					struct TSyScheduleList* pInfo = new struct TSyScheduleList;
	//					memcpy(pInfo, 0, sizeof(TSyScheduleList));
	//					memcpy(pInfo, &pBuf[sizeof(ZC_MSG_RESP_RESULT) + sizeof(int)], sizeof(TSyScheduleList));
	//					if (::IsWindow(g_cOpenDoorDlg->GetSafeHwnd()))
	//					{					
	//						g_cOpenDoorDlg->PostMessage(WM_GET_ESCORT_PLAN, NULL, (LPARAM)pInfo);
	//					}
	//				}
	//				else if (nMsgType = THIRDPART_MESSAGE_SY_IMAGE)
	//				{
	//					struct TSyImageId* pInfo = new struct TSyImageId;
	//					memcpy(pInfo, 0, sizeof(TSyImageId));
	//					memcpy(pInfo, &pBuf[sizeof(ZC_MSG_RESP_RESULT) + sizeof(int)], sizeof(TSyImageId));
	//					if (::IsWindow(g_cOpenDoorDlg->GetSafeHwnd()))
	//					{					
	//						g_cOpenDoorDlg->PostMessage(WM_GET_ESCORT_IMAGE, zMsgHead.dwMsgId, (LPARAM)pInfo);
	//					}
	//				}
	//				else if (nMsgType = THIRDPART_MESSAGE_SY_ROUTE_STATUS)
	//				{
	//					struct TSyRouteList* pInfo = new struct TSyRouteList;
	//					memcpy(pInfo, 0, sizeof(TSyRouteList));
	//					memcpy(pInfo, &pBuf[sizeof(ZC_MSG_RESP_RESULT) + sizeof(int)], sizeof(TSyRouteList));
	//					if (::IsWindow(g_cOpenDoorDlg->GetSafeHwnd()))
	//					{					
	//						g_cOpenDoorDlg->PostMessage(WM_GET_ESCORT_ROUTE, NULL, (LPARAM)pInfo);
	//					}
	//				}
	//			}
	//			else
	//			{		
	//				CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("获取押运web端信息失败");
	//				CZCMsgManager::Instance()->SetLastError(pResult->nError);
	//				CZCMsgManager::Instance()->m_bError[EROGETESCORTINFOFROMWEB] = true;
	//				CZCMsgManager::Instance()->m_iErrorCode[EROGETESCORTINFOFROMWEB] = pResult->nError;
	//			}
	//			break;
	//		}
	//	default:
	//	{
	//		break;
	//	}
	//}

}

void _stdcall pfStateCallback(DWORD dwState, void* pMessage, INT pnMessageSize, DWORD dwUser)
{
	CZCMsgManager* pZCMsgManager = (CZCMsgManager*)dwUser;
	if(pZCMsgManager == NULL)
	{
		return;
	}
	switch(dwState)
	{
	case CM_ONCONNECT:
		{
			pZCMsgManager->SetInitState(true);
			break;
		}
	default:
		break; 
	}
}

CZCMsgManager::CZCMsgManager(void): m_bInit(false)
{
	/*for(int i=0;i<MESSAGENUM;++i)
	{
		m_bError[i]=true;
		m_iErrorCode[i]=0;
	}
	m_iShow=0;
	memcpy(m_CurrentUserInfo.chUserName,"\0",64);
	InitializeCriticalSection(&g_csPreCaptureVector);
	CString strDebugName = _T("第三方认证");
	char* tmp =NULL;
	CStringToChar(strDebugName, &tmp);
	m_cDebugLog =new CDebugLogService(tmp);
	free(tmp);
	tmp = NULL;
	
	memset(&m_cImage, 0, 512);
	try
	{
		m_pUserDetail = new S_New_UserInfo;
	}
	catch (std::bad_alloc)
	{
		CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("<<ERROR>>class = CZCMsgManager: func = CZCMsgManager(void) detail = 分配内存失败");
	}
	memset(m_pUserDetail, 0 , sizeof(S_New_UserInfo));
	memset(&m_tOpenDoorDisposalInfo, 0, sizeof(m_tOpenDoorDisposalInfo));

	m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	m_dwMsgID = 0;*/
}

CZCMsgManager::~CZCMsgManager(void)
{
	/*DeleteCriticalSection(&g_csPreCaptureVector);
	std::map<int,char*>::iterator mapPhotoIter = CZCMsgManager::Instance()->m_vPersonPhoto.begin();
	for (; mapPhotoIter != CZCMsgManager::Instance()->m_vPersonPhoto.end(); mapPhotoIter++)
	{
		delete(mapPhotoIter->second);
		mapPhotoIter->second = NULL;
	}	
	CZCMsgManager::Instance()->m_vPersonPhoto.clear();
	delete m_pUserDetail;
	if (NULL != m_cDebugLog)
	{
		delete m_cDebugLog;
		m_cDebugLog = NULL;
	}

	CZCMsgManager::Instance()->m_vecStaffDepartment.clear();

	CZCMsgManager::Instance()->m_vecfAuthGroup.clear();

	CZCMsgManager::Instance()->m_vecStaffinfo.clear();

	CZCMsgManager::Instance()->m_vecStaffOperationinfo.clear();

	CloseHandle(m_hEvent);*/
}

bool CZCMsgManager::Init(DWORD dwUser)
{
	//TCHAR szPath[512];
	//GetModuleFileName(NULL, szPath, 512);
	//for (int i=wcslen(szPath)-1; i>=0; --i)
	//{   
	//	if (szPath[i] == '\\')
	//	{
	//		szPath[i] = '\0';
	//		break;   
	//	}
	//}
	
	auto str = g_GobalVariable.GetExePath();


	//wcscat(szPath,_T("\\system\\config.ini\0"));
	//FILE *fp=NULL;
	//CString cstrTemp(szPath);
	//char *pTempPath=NULL;
	//CStringToChar(cstrTemp,&pTempPath);
	//if(NULL==pTempPath)
	//{
	//	return false;
	//}
	//fp=fopen(pTempPath,"r");
	//int iPort=0,iFlag=0;
	//if(fp)
	//{
	//	iPort=GetPrivateProfileInt(_T("Config"),_T("Port"),5555,szPath);
	//	iFlag=GetPrivateProfileInt(_T("Config"),_T("Flag"),0,szPath);
	//	fclose(fp);
	//	free(pTempPath);
	//	pTempPath=NULL;
	//}
	//else
	//{
	//	MessageBox(NULL,_T("配置文件打开失败！"),_T("提示"),MB_OK);
	//	free(pTempPath);
	//	pTempPath=NULL;
	//	return false;
	//}

	//TJTY_TcpClient_SetThreadCount(1,1);

	//TCPCLIENTMODULE_INIT_INFO info = {0};
	//info.dwUser = (DWORD)this;;
	//info.pfCallback = pfCallback;
	//info.pfStateCallBack = pfStateCallback;
	//info.wLoaclModuleType = ZC_MODULE_OPENDOOR;
	//info.wPort = iPort;
	//info.wProtocolVersion = 0;
	//TJTY_TcpClient_Init(info);
	////m_bInit = true;
	//if(1==iFlag)
	//{
	//	TJTY_TcpClient_SetLogWriteType(true);
	//}

	//if(WaitForSingleObject(m_hEvent, 2000) != WAIT_OBJECT_0) //不死等，以防初始化函数连续调用时，状态回掉无反馈
	//{
	//	return false;
	//}

	//return m_bInit;

	return 0;
}

void CZCMsgManager::SetInitState(bool bInit)
{
	m_bInit = bInit;
	SetEvent(m_hEvent);
}

bool CZCMsgManager::AddSendMsg(WORD wModlueType,DWORD dwMsgId,DWORD dwMsgType,BYTE* pBuf,DWORD nBufSize)
{
	if(!m_bInit)
	{
		MessageBox(NULL,_T("消息服务连接失败！"),_T("提示"),MB_OK);
		return false;
	}

	TCPCLIENTMODULE_SEND_INFO info = {0};

	info.wReservedEx = 0;
	info.wModuleType = wModlueType; 
	info.dwMsgId = dwMsgId;
	info.dwMsgType = dwMsgType;
	info.dwLength = nBufSize;
	info.pBuffer = pBuf;

	return TJTY_TcpClient_AddWaitSendMsg(info);
}

bool CZCMsgManager::UnInit()
{
	m_bInit = false; 
	return TJTY_TcpClient_UnInit();
}

void CZCMsgManager::SetLastError(DWORD nError)
{
	//m_LastError = nError;
}

DWORD CZCMsgManager::GetValidMsgID()
{
	/*m_dwMsgID++;
	if(m_dwMsgID > ZC_MSG_SERIAL_ID_MAX_VALUE)
	{
		m_dwMsgID = 0;
	}
	return m_dwMsgID;*/
	return 0;
}
//
//bool CZCMsgManager::RequestCurrentUserInfo()   //请求当前用户信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//	return AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_CURUSERINFOEX,NULL,0);
//}
//
//bool CZCMsgManager::RequestOpenDoorDisposalInfo()		// 请求第三方处理权限
//{
//	DWORD dwMsgID = GetValidMsgID();
//	return AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_OPENDOOR_DISPOSALINFO, NULL,0);
//}
//
//void CZCMsgManager::AddCurrentUserInfo(T_CURUSER_INFO_EX *info)
//{
//	strcpy(m_CurrentUserInfo.chRole,info->chRole);
//	strcpy(m_CurrentUserInfo.chUserName,info->chUserName);
//	m_CurrentUserInfo.nId=info->nId;
//	m_CurrentUserInfo.nLevel=info->nLevel;
//}
//
//bool CZCMsgManager::RequestAreaInfo()   //请求区域信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//	return AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_ALLAREAINFO,NULL,0);
//}
//
//void CZCMsgManager::AddAreaInfo(T_AREA_INFO &info, bool bClear)
//{
//	if(bClear)
//	{
//		m_AreaInfo.clear();
//	}
//	m_AreaInfo.push_back(info);
//}
//
//bool  CZCMsgManager:: RequestCertificationSearchInfo(TAGDOAHISTORYINFO_P info)   //请求认证查询
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOAHISTORYINFO_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOAHISTORYINFO_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYINFO,pBuf,sizeof(TAGDOAHISTORYINFO_P));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddCertificationSearchInfo(TAGDOAHISTORYINFO_S &info, bool bClear)
//{
//	if(bClear)
//	{
//		m_CertificationSearchInfo.clear();
//	}
//	m_CertificationSearchInfo.push_back(info);
//}
//
//bool  CZCMsgManager:: RequestStaffSearchInfo(TAGDOABYCARDINFO_P info)   //请求人员查询（刷卡信息）
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOABYCARDINFO_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOABYCARDINFO_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_OPENDOOR_GETBYCARDHISTORYINFO,pBuf,sizeof(TAGDOABYCARDINFO_P));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddStaffSearchInfo(TAGDOABYCARDINFO_NEW_S &info, bool bClear)
//{
//	if(bClear)
//	{
//		m_StaffSearchInfo.clear();
//	}
//	m_StaffSearchInfo.push_back(info);
//}
//
//bool  CZCMsgManager:: RequestStatisticInfo(TAGDOASTATISTICS_P info)   //请求统计信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOASTATISTICS_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOASTATISTICS_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_OPENDOOR_STATISTICS,pBuf,sizeof(TAGDOASTATISTICS_P));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool  CZCMsgManager:: RequestStatisticInfo(TAGDOASTATISTICS_P info,DWORD dwMsgID)   //请求统计信息
//{
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOASTATISTICS_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOASTATISTICS_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_OPENDOOR_STATISTICS,pBuf,sizeof(TAGDOASTATISTICS_P));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddStatisticInfo(TAGDOASTATISTICS_S &info, bool bClear)
//{
//	if(bClear)
//	{
//		m_StatisticInfo.clear();
//	}
//	m_StatisticInfo.push_back(info);
//}
//
//void CZCMsgManager::AddACSHostInfo(TAGDOAACCESSINFO_S &stHostInfo, bool bClear)  //获取所有报警主机信息
//{
//	if (bClear)
//	{
//		m_vAllACSHostInfo.clear();
//	}
//
//	m_vAllACSHostInfo.push_back(stHostInfo);
//
//}
//
//bool CZCMsgManager::RequestACSHostInfo()  
//{
//	DWORD dwMsgID = GetValidMsgID();
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_OPENDOOR_GETALLACSHOSTINFO,NULL,0);
//
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestIntoLayer(char* chAreaName)  //请求进入图层
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(char)*64];
//
//	if (chAreaName)
//	{
//		memcpy((char *)pBuf,chAreaName, sizeof(char)*64);
//	}
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT,dwMsgID, ZC_MSG_BCBCLIENT_ALARMPOSITION, pBuf, 64);
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestWatchVideo(T_ALARMLINKOPERATEPRARM info, DWORD dwMsgID)  //观看视频
//{
//
//	BYTE* pBuf = new BYTE[sizeof(T_ALARMLINKOPERATEPRARM)];
//
//	memcpy(pBuf,&info,sizeof(T_ALARMLINKOPERATEPRARM));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_ALARMLINKVIDEO, pBuf, sizeof(T_ALARMLINKOPERATEPRARM));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestReplayVideo(T_ALARMREPLAYPARAM info, DWORD dwMsgID)  //回放录像
//{
//
//	BYTE* pBuf = new BYTE[sizeof(T_ALARMREPLAYPARAM)];
//
//	memcpy(pBuf,&info,sizeof(T_ALARMREPLAYPARAM));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_ALARMREPLAY, pBuf, sizeof(T_ALARMREPLAYPARAM));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestDialling(T_TELEPHONECALLINFO info, DWORD dwMsgID)  //打电话
//{
//
//	BYTE* pBuf = new BYTE[sizeof(T_TELEPHONECALLINFO)];
//
//	memcpy(pBuf,&info,sizeof(T_TELEPHONECALLINFO));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_TELEPHONECALL, pBuf, sizeof(T_TELEPHONECALLINFO));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//void CZCMsgManager::AddAttachmentInfo(T_ATTACHMENTINFO *info)
//{
//	
//	strcpy(m_stAttachmentInfo.chAttachment, info->chAttachment);
//
//}
//
//bool CZCMsgManager::RequestIPTalk(int nDeviceID, DWORD dwMsgID)  //对讲
//{
//
//	BYTE* pBuf = new BYTE[sizeof(int)];
//
//	memcpy(pBuf,&nDeviceID,sizeof(int));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_DEVTALKBYID, pBuf, sizeof(nDeviceID));
//	delete []pBuf;
//	pBuf = NULL;
//
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestOpenDoor(T_CONTROLACSHOSTPRARM info, DWORD dwMsgID)  //请求开门
//{
//
//	BYTE* pBuf = new BYTE[sizeof(T_CONTROLACSHOSTPRARM)];
//
//	memcpy(pBuf,&info,sizeof(T_CONTROLACSHOSTPRARM));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_CONTROLACSHOST, pBuf, sizeof(T_CONTROLACSHOSTPRARM));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestManulCaptureInfo()  //请求开始抓图事件
//{
//	DWORD dwMsgID = GetValidMsgID();
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_STARTLISTENMANUALCAPTURE, NULL, 0);
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestCloseManulCaptureInfo()  //请求结束监听手动抓图
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_STOPLISTENMANUALCAPTURE, NULL, 0);
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestLinkSwipCardRecord(TAGOPENDOOR_P info)  //请求关联刷卡认证记录
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGOPENDOOR_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGOPENDOOR_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_ADDREQUEST, pBuf, sizeof(TAGOPENDOOR_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestLinkEscortCardRecord(DOOROPENSYRELATION_SET_P info)  //请求关联押运认证记录
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(DOOROPENSYRELATION_SET_P)];
//
//	memcpy(pBuf,&info,sizeof(DOOROPENSYRELATION_SET_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_DOOROPENSYRELATION_SET, pBuf, sizeof(DOOROPENSYRELATION_SET_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestEscortPlanInfo(int nOrgId)  //请求获取指定网点的押运排班信息(守押)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	int nMsgType = THIRDPART_MESSAGE_SY_SCHEDULE_INFO;
//	int nOrganizationId = nOrgId;
//
//	int nBufLen = sizeof(int) + sizeof(int); 
//	BYTE* pBuf = new BYTE[nBufLen];
//	memcpy((int*)pBuf, &nMsgType, sizeof(int));
//	memcpy((int*)&pBuf[sizeof(int)], &nOrganizationId, sizeof(int));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_THIRDPART_EXCHANGEMESSAGE, pBuf, nBufLen);
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestEscortPhotoInfo(struct TSyGetImage info)  //请求获取各种类型的图片(守押)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	int nMsgType = THIRDPART_MESSAGE_SY_IMAGE;
//
//	int nBufLen = sizeof(int) + sizeof(TSyGetImage); 
//	BYTE* pBuf = new BYTE[nBufLen];
//	memcpy((int*)pBuf, &nMsgType, sizeof(int));
//	memcpy((int*)&pBuf[sizeof(int)], &info, sizeof(TSyGetImage));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_THIRDPART_EXCHANGEMESSAGE, pBuf, nBufLen);
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestEscortRouteInfo(int nOrgId)  //请求获取指定网点押运路线的状态(守押)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	int nMsgType = THIRDPART_MESSAGE_SY_ROUTE_STATUS;
//	int nOrganizationId = nOrgId;
//
//	int nBufLen = sizeof(int) + sizeof(int); 
//	BYTE* pBuf = new BYTE[nBufLen];
//	memcpy((int*)pBuf, &nMsgType, sizeof(int));
//	memcpy((int*)&pBuf[sizeof(int)], &nOrganizationId, sizeof(int));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_THIRDPART_EXCHANGEMESSAGE, pBuf, nBufLen);
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestEscortRFIDInfo(struct TSyGetTagData info)  //请求电子标签卡的详细信息(守押)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	int nMsgType = THIRDPART_MESSAGE_SY_TAG_DATA;
//
//	int nBufLen = sizeof(int) + sizeof(TSyGetTagData); 
//	BYTE* pBuf = new BYTE[nBufLen];
//	memcpy((int*)pBuf, &nMsgType, sizeof(int));
//	memcpy((int*)&pBuf[sizeof(int)], &info, sizeof(TSyGetTagData));
//
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_THIRDPART_EXCHANGEMESSAGE, pBuf, nBufLen);
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestAddSuggestion(TAGDOA_PROCESSMEMO_P info)  //新增处置意见
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOA_PROCESSMEMO_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOA_PROCESSMEMO_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_ADDSUGGESTION, pBuf, sizeof(TAGDOA_PROCESSMEMO_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestAddLogInfo(TAGDOA_APPLYACTLOG_P info)  //新增认证系统日志
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOA_APPLYACTLOG_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOA_APPLYACTLOG_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_ADDLOGINFO, pBuf, sizeof(TAGDOA_APPLYACTLOG_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestAddOperaInfo(TAGDOA_ATTACHMENT_P info)  //新增认证处置操作信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOA_ATTACHMENT_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOA_ATTACHMENT_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_ADDOPERAINFO, pBuf, sizeof(TAGDOA_ATTACHMENT_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddOperationInfo(TAGDOAATTACHMENT_S &info, bool bClear)  //请求获取认证操作详细信息
//{
//	if(bClear)
//	{
//		m_vOperaInfo.clear();
//	}
//	m_vOperaInfo.push_back(info);
//}
//
//bool CZCMsgManager::RequestOperationInfo(int nId)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(int)];
//
//	memcpy(pBuf,&nId,sizeof(int));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETOPERAINFO, pBuf, sizeof(int));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//void CZCMsgManager::AddActionDetail(TAGDOAACTIONDETAIL_S &info, bool bClear) //获取预案执行信息
//{
//	if(bClear)
//	{
//		m_vActionDetail.clear();
//	}
//	m_vActionDetail.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestActionDetail(int nId)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(int)];
//
//	memcpy(pBuf,&nId,sizeof(int));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETAPPLYPLANINFO, pBuf, sizeof(int));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddSuggestionInfo(TAGDOAPROCESSMEMO_S &info, bool bClear) //获取认证处理意见信息
//{
//	if(bClear)
//	{
//		m_vSuggestionInfo.clear();
//	}
//	m_vSuggestionInfo.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestSuggestionInfo(int nId)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(int)];
//
//	memcpy(pBuf,&nId,sizeof(int));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETSUGGESTIONINFO, pBuf, sizeof(int));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddSystemLog(TAGDOAACTLOG_S &info, bool bClear)  //获取认证系统日志信息
//{
//	if(bClear)
//	{
//		m_vSystemLog.clear();
//	}
//	m_vSystemLog.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestSystemLog(int nId)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(int)];
//
//	memcpy(pBuf,&nId,sizeof(int));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETLOGINFO, pBuf, sizeof(int));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//void CZCMsgManager::AddDoorAccessLog(TAGDOADOORACCESSLOG_S &info, bool bClear)  //获取认证刷卡信息
//{
//	if(bClear)
//	{
//		m_vDoorAccessLog.clear();
//	}
//	m_vDoorAccessLog.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestDoorAccessLog(int nId)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(int)];
//
//	memcpy(pBuf,&nId,sizeof(int));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETACCESSLOGINFO, pBuf, sizeof(int));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestSubmitAuditorDealInfo(TAGDOA_AUDITOR_P info)  //提交审核数据
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOA_AUDITOR_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOA_AUDITOR_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_SUBMITAUDITORDEALINFO, pBuf, sizeof(TAGDOA_AUDITOR_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestAddDealPlanInfo(TAGOPENDOORPLANINFO_P info)  //提交预案执行数据
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGOPENDOORPLANINFO_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGOPENDOORPLANINFO_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_ADDDEALPLANINFO, pBuf, sizeof(TAGOPENDOORPLANINFO_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestModifyDealType(TAGDOOROPENAPPLY_METHOD_P info)  //修改认证处置方式：值-1-未处理 0-开门-申请授权2-应急处置 3-申请特批4-拒绝开门
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOOROPENAPPLY_METHOD_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOOROPENAPPLY_METHOD_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_MODIFYDEALTYPE, pBuf, sizeof(TAGDOOROPENAPPLY_METHOD_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddNewOpenDoorApply(TAGDOA_INFO_S* info)
//{
//	m_tNewOpenDoorApply.nId = info->nId;
//	strncpy(m_tNewOpenDoorApply.chReturn, info->chReturn, 256);
//}
//
//bool CZCMsgManager::RequestSubmitDealInfo(TAGDOA_INFO_P info, DWORD dwMsgID)  //新增认证申请记录
//{
//// 	m_dwMsgID++;
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOA_INFO_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOA_INFO_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_SUBMITDEALINFO, pBuf, sizeof(TAGDOA_INFO_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//void CZCMsgManager::AddUserPassWord(TAGDOAPPASSWORD_S *info)  //请求获取用户信息
//{
//	strcpy(m_stPassWord.chUserName,info->chUserName);
//	strcpy(m_stPassWord.chPassword,info->chPassword);
//	m_stPassWord.bDoShow=info->bDoShow;
//	m_stPassWord.nUserId=info->nUserId;
//
//}
//
//bool CZCMsgManager::RequestUserPassWord(TAGDOAPPASSWORD_P info)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOAPPASSWORD_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOAPPASSWORD_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETUSERBASEINFO, pBuf, sizeof(TAGDOAPPASSWORD_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestModifyRequestState(TAGDOA_PROCESSSTATUS_P info)  //请求修改认证处置状态 认证状态值 1-未处置2-处置中 3-待审核4-已处理5-已失效
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOA_PROCESSSTATUS_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOA_PROCESSSTATUS_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_MODIFYREQUESTSTATE, pBuf, sizeof(TAGDOA_PROCESSSTATUS_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//void CZCMsgManager::AddAllPersonInfo(TAGDOAPERSONINFO_S &info, bool bClear)  //请求获取所有需管辖人员信息
//{
//	if(bClear)
//	{
//		m_vAllPersonInfo.clear();
//	}
//	m_vAllPersonInfo.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestAllPersonInfo()
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETALLPEPOLEINFO, NULL, 0);
//
//	return bRet;
//
//}
//
//void CZCMsgManager::AddManualCapture(char* chPath)
//{
//	memset(m_chManualCapturePath, 0, 512);
//	strncpy(m_chManualCapturePath, chPath, 512);
//
//}
//
//bool CZCMsgManager::RequestTransMSG(T_TRANS_COMMONHEADINFO info, T_TRANS_OPENDOOR_INFO msgInfo)  //请求转发消息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(T_TRANS_COMMONHEADINFO)+sizeof(T_TRANS_OPENDOOR_INFO)];
//
//	memcpy(pBuf, &info, sizeof(T_TRANS_COMMONHEADINFO));
//	memcpy(&pBuf[sizeof(T_TRANS_COMMONHEADINFO)],&msgInfo,sizeof(T_TRANS_OPENDOOR_INFO));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_REQUESTTRANSMSG, pBuf, sizeof(T_TRANS_COMMONHEADINFO)+sizeof(T_TRANS_OPENDOOR_INFO));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestTransMSG( T_TRANS_COMMONHEADINFO info, void* msgInfo, int nMessageType )
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	switch (nMessageType)
//	{
//	case MSG_CARDLOGINFO:
//		{
//			int nBufferLenght = sizeof(S_COM_MSGHEAD) + sizeof(S_RECV_CARDLOGINFO);
//			BYTE* pBuf = new BYTE[sizeof(T_TRANS_COMMONHEADINFO) + nBufferLenght];
//
//			memcpy(pBuf, &info, sizeof(T_TRANS_COMMONHEADINFO));
//
//			S_COM_MSGHEAD* sMsgHead = (S_COM_MSGHEAD*)&pBuf[sizeof(T_TRANS_COMMONHEADINFO)];
//// 			sMsgHead->nMsgLen = nBufferLenght + sizeof(T_TRANS_COMMONHEADINFO);
//			sMsgHead->nMsgType = MSG_CARDLOGINFO;
//			sMsgHead->nLoginType = 1004;
//			_snprintf(sMsgHead->chUserName, sizeof(sMsgHead->chUserName), "%s", "");
//			memcpy(&pBuf[sizeof(T_TRANS_COMMONHEADINFO) + sizeof(S_COM_MSGHEAD)], msgInfo, sizeof(S_RECV_CARDLOGINFO));
//			bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_REQUESTTRANSMSG, pBuf, nBufferLenght + sizeof(T_TRANS_COMMONHEADINFO));
//			delete []pBuf;
//		}
//		break;
//	case MSG_CLOSEAGENTDOOR:
//		{
//			int nBufferLenght = sizeof(S_COM_MSGHEAD) + sizeof(S_REQ_CLOSEAGENTINFO);
//			BYTE* pBuf = new BYTE[sizeof(T_TRANS_COMMONHEADINFO) + nBufferLenght];
//
//			memcpy(pBuf, &info, sizeof(T_TRANS_COMMONHEADINFO));
//
//			S_COM_MSGHEAD* sMsgHead = (S_COM_MSGHEAD*)&pBuf[sizeof(T_TRANS_COMMONHEADINFO)];
//			sMsgHead->nMsgType = MSG_CLOSEAGENTDOOR;
//			sMsgHead->nLoginType = 1004;
//			_snprintf(sMsgHead->chUserName, sizeof(sMsgHead->chUserName), "%s", "");
//			memcpy(&pBuf[sizeof(T_TRANS_COMMONHEADINFO) + sizeof(S_COM_MSGHEAD)], msgInfo, sizeof(S_REQ_CLOSEAGENTINFO));
//
//			bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_REQUESTTRANSMSG, pBuf, nBufferLenght + sizeof(T_TRANS_COMMONHEADINFO));
//			delete []pBuf;
//
//		}
//		break;
//	case MSG_MANIPULATEINFO:
//		{
//			int nBufferLenght = sizeof(S_COM_MSGHEAD) + sizeof(S_RECV_MANIPULATEINFO);
//			int nTotal = sizeof(T_TRANS_COMMONHEADINFO) + nBufferLenght;
//			BYTE* pBuf = new BYTE[sizeof(T_TRANS_COMMONHEADINFO) + nBufferLenght];
//
//			memcpy(pBuf, &info, sizeof(T_TRANS_COMMONHEADINFO));
//
//			S_COM_MSGHEAD* sMsgHead = (S_COM_MSGHEAD*)&pBuf[sizeof(T_TRANS_COMMONHEADINFO)];
//			sMsgHead->nMsgType = MSG_MANIPULATEINFO;
//			sMsgHead->nLoginType = 1004;
//			_snprintf(sMsgHead->chUserName, sizeof(sMsgHead->chUserName), "%s", "");
//			memcpy(&pBuf[sizeof(T_TRANS_COMMONHEADINFO) + sizeof(S_COM_MSGHEAD)], msgInfo, sizeof(S_RECV_MANIPULATEINFO));
//
//			bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_REQUESTTRANSMSG, pBuf, nBufferLenght + sizeof(T_TRANS_COMMONHEADINFO));
//			delete []pBuf;
//		}
//		break;
//	case MSG_WORKLOCATINFO:
//		{
//			int nBufferLenght = sizeof(S_COM_MSGHEAD) + sizeof(S_RECV_WORKLOCATVIDEOINFO);
//			BYTE* pBuf = new BYTE[sizeof(T_TRANS_COMMONHEADINFO) + nBufferLenght];
//
//			memcpy(pBuf, &info, sizeof(T_TRANS_COMMONHEADINFO));
//
//			S_COM_MSGHEAD* sMsgHead = (S_COM_MSGHEAD*)&pBuf[sizeof(T_TRANS_COMMONHEADINFO)];
//			sMsgHead->nMsgType = MSG_WORKLOCATINFO;
//			sMsgHead->nLoginType = 1004;
//			_snprintf(sMsgHead->chUserName, sizeof(sMsgHead->chUserName), "%s", "");
//			memcpy(&pBuf[sizeof(T_TRANS_COMMONHEADINFO) + sizeof(S_COM_MSGHEAD)], msgInfo, sizeof(S_RECV_WORKLOCATVIDEOINFO));
//
//			bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_REQUESTTRANSMSG, pBuf, nBufferLenght + sizeof(T_TRANS_COMMONHEADINFO));
//			delete []pBuf;
//		}
//		break;
//
//	}
//	return true;
//}
//
//bool CZCMsgManager::RequestAccessRelation()  //请求获取门禁主从关系信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_ACCESSRELATION, NULL, 0);
//
//	return bRet;
//}
//
//bool CZCMsgManager::CheckIsMasterEntranceGuard(long nDeviceId)
//{
//	map<long, long>::iterator iterDevice;
//
//	iterDevice = CZCMsgManager::Instance()->m_mapAccessRelation.begin();
//	for (; iterDevice != CZCMsgManager::Instance()->m_mapAccessRelation.end(); iterDevice++)
//	{
//		if ((iterDevice->second == nDeviceId))
//		{
//			break;
//		}
//	}
//	if (iterDevice == CZCMsgManager::Instance()->m_mapAccessRelation.end())
//	{
//		return false;
//	}	
//
//	return true;
//}
//
//void CZCMsgManager::AddAccessRelation(TAGDOACCESSRELATION_S &info, bool bIsClear)
//{
//	if (bIsClear)
//	{
//		m_mapAccessRelation.clear();
//	}
//	m_mapAccessRelation.insert(pair<int,int>( info.nSlaveAccessId, info.nMasterAccessId));
//	
//	
//}
//
//void CZCMsgManager::AddEscortAccessRelation(ACCESSSYRELATION_GET_S &info, bool bIsClear)
//{
//	if (bIsClear)
//	{
//		m_mapEscortAccessRelation.clear();
//	}
//	m_mapEscortAccessRelation.insert(pair<int,int>( info.nDeviceId, info.nDoorId));
//
//
//}
//
//void CZCMsgManager::AddCtrlLevelInfo(S_NEW_CTRLLEVELINFO &info, bool bClear)  //请求获取管控等级信息
//{
//	if (bClear)
//	{
//		m_vCtrlLevelInfo.clear();
//	}
//
//	m_vCtrlLevelInfo.push_back(info);
//}
//
//bool CZCMsgManager::RequestCtrlLevelInfo()
//{
//
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_CTRLLEVELMULINFO, NULL, 0);
//	return bRet;
//}
//
//bool  CZCMsgManager:: RequestCollectChartInfo(P_NEW_SHOWUSERGRAPHINFO info)   //请求获取收藏的图表信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(P_NEW_SHOWUSERGRAPHINFO)];
//
//	memcpy(pBuf,&info,sizeof(P_NEW_SHOWUSERGRAPHINFO));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_ALARM_USERGRAPHINFO,pBuf,sizeof(P_NEW_SHOWUSERGRAPHINFO));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddCollectChartInfo(S_NEW_SHOWUSERGRAPHINFO &info, bool bClear)
//{
//	if(bClear)
//	{
//		m_CollectChartInfo.clear();
//	}
//	m_CollectChartInfo.push_back(info);
//}
//
//bool  CZCMsgManager:: RequestChangeCollectChartInfo(P_NEW_OPUSERGRAPHINFO info)   //增删改收藏的图表信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(P_NEW_OPUSERGRAPHINFO)];
//
//	memcpy(pBuf,&info,sizeof(P_NEW_OPUSERGRAPHINFO));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_ALARM_OPUSERGRAPH,pBuf,sizeof(P_NEW_OPUSERGRAPHINFO));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool  CZCMsgManager:: RequestSubscribeInfo(P_NEW_SHOWUSERREPORTBOOKINFO info)  //请求获取用户订阅信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(P_NEW_SHOWUSERREPORTBOOKINFO)];
//
//	memcpy(pBuf,&info,sizeof(P_NEW_SHOWUSERREPORTBOOKINFO));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_ALARM_USERREPORTBOOKINFO,pBuf,sizeof(P_NEW_SHOWUSERREPORTBOOKINFO));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddSubscribeInfo(S_NEW_SHOWUSERREPORTBOOKINFO &info, bool bClear)
//{
//	if(bClear)
//	{
//		m_SubscribeInfo.clear();
//	}
//	m_SubscribeInfo.push_back(info);
//}
//
//bool  CZCMsgManager:: RequestChangeSubscribeInfo(P_NEW_OPUSERREPORTINFO info)   //请求增、删、改订阅信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(P_NEW_OPUSERREPORTINFO)];
//
//	memcpy(pBuf,&info,sizeof(P_NEW_OPUSERREPORTINFO));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_ALARM_OPUSERREPORT,pBuf,sizeof(P_NEW_OPUSERREPORTINFO));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool  CZCMsgManager:: RequestReportInfo(P_NEW_SHOWUSERREPORTINFO info)  //请求获取报告信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(P_NEW_SHOWUSERREPORTINFO)];
//
//	memcpy(pBuf,&info,sizeof(P_NEW_SHOWUSERREPORTINFO));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_ALARM_USERREPORTINFO,pBuf,sizeof(P_NEW_SHOWUSERREPORTINFO));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddReportInfo(S_NEW_SHOWUSERREPORTINFO &info, bool bClear)
//{
//	if(bClear)
//	{
//		m_ReportInfo.clear();
//	}
//	m_ReportInfo.push_back(info);
//}
//
//bool  CZCMsgManager:: RequestChangeReportStatusInfo(P_NEW_MODSTATUSUSERREPORT info)  //修改报告状态信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(P_NEW_MODSTATUSUSERREPORT)];
//
//	memcpy(pBuf,&info,sizeof(P_NEW_MODSTATUSUSERREPORT));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_ALARM_MODSTATUSUSERREPORT,pBuf,sizeof(P_NEW_MODSTATUSUSERREPORT));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddCtrlLevelPlan(TAGCTRLEVELPLAN_S &info, bool bClear)   //请求获取管控策略信息
//{
//	if (bClear)
//	{
//		m_vCtrlLevelPlan.clear();
//	}
//
//	m_vCtrlLevelPlan.push_back(info);
//}
//
//bool CZCMsgManager::RequestCtrlLevelPlan()
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_CTRLLEVELPLAN, NULL, 0);
//
//	return bRet;
//}
//
////根据申请认证ID获取申请详细信息
//bool CZCMsgManager::RequestAppyDetailInfo(int nId/*申请认证ID*/, int nMsgId) 
//{
//	m_dwMsgID = nMsgId;
//
//	BYTE* pBuf = new BYTE[sizeof(int)];
//
//	memcpy(pBuf,&nId, sizeof(int));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, m_dwMsgID, ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYDETAIL, pBuf, sizeof(int));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::SetApplyDetailInfo(TAGDOAAPPLYDETAIL_S tagApplyDetails)
//{
//	m_tagApplyDetails = tagApplyDetails;
//}
//
//bool CZCMsgManager::RequestDepartmentInfo() //获取部门信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO, NULL, 0);
//
//	return bRet;
//}
//
//void CZCMsgManager::AddDepartmentInfo(TAGDOADEPARTMENTINFO_S &info, bool bClear)   //
//{
//	if (bClear)
//	{
//		m_DepartmentInfo.clear();
//	}
//
//	m_DepartmentInfo.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestIsCollection(TAGDOA_ISCOLLECTION_P info)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(TAGDOA_ISCOLLECTION_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOA_ISCOLLECTION_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_OPENDOOR_MODIFYISCOLLECTION,pBuf,sizeof(TAGDOA_ISCOLLECTION_P));
//
//	delete [] pBuf;
//	pBuf = NULL;
//	return bRet;
//
//
//}
//
//void CZCMsgManager::AddPlanLib(S_NEW_SHOWPLANLIB &info, bool bIsClear)   //获取预案库
//{
//	if (bIsClear)
//	{
//		m_vGetPlanLib.clear();
//	}
//	m_vGetPlanLib.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestPlanLib(P_NEW_SHOWPLANLIB info)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(P_NEW_SHOWPLANLIB)];
//
//	memcpy(pBuf, &info, sizeof(P_NEW_SHOWPLANLIB));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_PLANINFO, pBuf, sizeof(P_NEW_SHOWPLANLIB));
//
//	delete []pBuf;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequrstDownLoadPic(char* chImage,DWORD m_dwMsgID)
//{
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, m_dwMsgID, ZC_MSG_BCBCLIENT_DOWNLOADPIC, (BYTE*)chImage, 512);
//	return bRet;
//}
//
//bool CZCMsgManager::RequestDownAttachment(char* chImage,DWORD m_dwMsgID)
//{
//	BYTE* pBuf = new BYTE[512];
//
//	memcpy((char*)pBuf,chImage,512);
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, m_dwMsgID, ZC_MSG_BCBCLIENT_DOWNLOADPIC, pBuf, 512);
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//void CZCMsgManager::AddPartInfo(S_NEW_SHOWPOSITIONINFO &info, bool bIsClear)  //获取所有部位信息
//{
//	if (bIsClear)
//	{
//		m_vPartInfo.clear();
//	}
//	m_vPartInfo.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestPartInfo()
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_ALLKEYPARTINFO, NULL, 0);
//
//	return bRet;
//
//}
//
//void CZCMsgManager::AddAttachmentId(char* strId)  //上传附件
//{
//	strncpy(m_chAttachment, strId, sizeof(m_chAttachment));
//}
//
//bool CZCMsgManager::RequestAttachmentId(T_UPLOADATTACHMENT_INFO& info, DWORD dMsgFrom)
//{
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dMsgFrom, ZC_MSG_BCBCLIENT_UPLOADATTACHMENT, (BYTE*)&info, sizeof(T_UPLOADATTACHMENT_INFO));
//
//	return bRet;
//
//}
//
//bool CZCMsgManager::AddPreCapture(DWORD dwDeviceID, char* strPreCapture, bool bIsClear)
//{
//	if(strPreCapture == NULL || strcmp(strPreCapture,"") == 0)
//	{
//		return false;
//	}
//	EnterCriticalSection(&g_csPreCaptureVector);
//
//	CString chPicturePath;
//	chPicturePath = strPreCapture;
//	m_mapPreCapture[dwDeviceID].push_back(chPicturePath);
//
//	LeaveCriticalSection(&g_csPreCaptureVector);
//
//	return true;
//}
//
//bool CZCMsgManager::RequestPreCapture(T_CAPTUREWITHOUTOPEN_INFO info, DWORD dwDeviceId)
//{
//
//	BYTE* pBuf = new BYTE[sizeof(T_CAPTUREWITHOUTOPEN_INFO)];
//
//	memcpy(pBuf, &info, sizeof(T_CAPTUREWITHOUTOPEN_INFO));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwDeviceId, ZC_MSG_BCBCLIENT_CAPTUREWITHOUTOPEN, pBuf, sizeof(T_CAPTUREWITHOUTOPEN_INFO));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//void CZCMsgManager::AddFrontendTalkInfo(S_FrontendTalkInfo &info, bool bIsClear)    //获取前段摄像头设备
//{
//	if (bIsClear)
//	{
//		m_vFrontendTalkInfo.clear();
//	}
//	m_vFrontendTalkInfo.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestFrontendTalkInfo()
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKINFO, NULL, 0);
//
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestIssueShortMessage(T_SENDSHORTMESSAGEINFO info)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(T_SENDSHORTMESSAGEINFO)];
//
//	memcpy(pBuf,&info,sizeof(T_SENDSHORTMESSAGEINFO));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT,dwMsgID,ZC_MSG_BCBCLIENT_SHORTMESSAGE,pBuf,sizeof(T_SENDSHORTMESSAGEINFO));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestSendEmail(char * pcEmailMsg)	
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(char)*512];
//
//	if (pcEmailMsg)
//	{
//		memcpy((char *)pBuf,pcEmailMsg, sizeof(char)*512);
//	}
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT,dwMsgID, ZC_MSG_BCBCLIENT_SENDEMAIL, pBuf, 512);
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;	
//}
//
//bool CZCMsgManager::RequestSetUnSetDefenseDevice(T_ALARMLINKOPERATEPRARM info)	
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(T_ALARMLINKOPERATEPRARM)];
//
//	memcpy(pBuf,&info,sizeof(T_ALARMLINKOPERATEPRARM));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_DEFENCEDEV, pBuf,sizeof(T_ALARMLINKOPERATEPRARM));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
////请求抓图
//bool CZCMsgManager::RequestCapture()
//{
//	DWORD dwMsgID = GetValidMsgID();
//	return AddSendMsg(ZC_MODULE_BCBCLIENT,dwMsgID,ZC_MSG_BCBCLIENT_CAPTUREPIC,NULL,0);
//}
//
//void CZCMsgManager::AddCaptureAttachment(T_ATTACHMENTINFO &info, bool bClear)
//{
//	strcpy(m_CaptureAttachment.chAttachment, info.chAttachment);
//}
//
//bool CZCMsgManager::SetBasicSettingInfo(TAGDOA_USERINFO_P info)   //设置基本信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[sizeof(TAGDOA_USERINFO_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOA_USERINFO_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_APP_OPENDOOR_SETUSERBASEINFO, pBuf,sizeof(TAGDOA_USERINFO_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestExceptionInfo(TAGDOAEXCEPINFO_P info)
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[sizeof(TAGDOAEXCEPINFO_P)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOAEXCEPINFO_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_ADDEXCEPTIONINFO, pBuf,sizeof(TAGDOAEXCEPINFO_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddHostTalkInfo(S_HostTalkInfo &info, bool bIsClear) //请求获取主机对讲
//{
//	if (bIsClear)
//	{
//		m_vHostTalkInfo.clear();
//	}
//	m_vHostTalkInfo.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestHostTalkInfo()
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKTALKINFO, NULL, 0);
//
//	return bRet;
//
//}
//
//bool  CZCMsgManager::RequestAllDealerInfo()   //请求获取所有处理人姓名信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//	return AddSendMsg(ZC_MODULE_APP,dwMsgID,ZC_MSG_APP_ALLUSERINFO,NULL,0);
//}
//
//void CZCMsgManager::AddAllDealerInfo(CString info, bool bClear)
//{
//	if(bClear)
//	{
//		m_AllDealerInfo.clear();
//	} 
//	m_AllDealerInfo.push_back(info);
//
//}
//
//bool CZCMsgManager::RequestCloseVideo()
//{
//	DWORD dwMsgID = GetValidMsgID();
//	return  AddSendMsg(ZC_MODULE_BCBCLIENT,dwMsgID,ZC_MSG_BCBCLIENT_CLOSEALLVIDEO,NULL,0);
//}
//
//bool CZCMsgManager::RequestUserDetail(char chUserName[64], int nIndex)
//{
//	BYTE* pBuf = new BYTE[64];
//	memcpy(pBuf, chUserName, 64);
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, nIndex, ZC_MSG_APP_USERALLINFO, pBuf, 64);
//	delete []pBuf;
//	return bRet;
//}
//
//TAGDOAACCESSINFO_S* CZCMsgManager::GetAccessHostInfo( int nDeviceID )
//{
//	TAGDOAACCESSINFO_S* pAccessInfo = NULL;
//	
//	std::vector<TAGDOAACCESSINFO_S>::iterator iterAccessHost = m_vAllACSHostInfo.begin();	
//	for (;iterAccessHost != m_vAllACSHostInfo.end(); iterAccessHost++)
//	{
//		if (iterAccessHost->nID == nDeviceID)
//		{
//			try
//			{
//				pAccessInfo = new TAGDOAACCESSINFO_S;
//			}
//			catch (std::bad_alloc)
//			{
//				return pAccessInfo;
//			}
//			memcpy(pAccessInfo, &(*iterAccessHost), sizeof(TAGDOAACCESSINFO_S));
//			return pAccessInfo;
//		}
//	}
//	return pAccessInfo;
//}
//
//S_NEW_CTRLLEVELINFO* CZCMsgManager::GetCTRLevelInfo( char* chDeviceName )
//{
//	S_NEW_CTRLLEVELINFO* pCtrlLevelInfo = NULL;
//
//	std::vector<S_NEW_CTRLLEVELINFO>::iterator iterCtrLevelInfo = m_vCtrlLevelInfo.begin();	
//	for (;iterCtrLevelInfo != m_vCtrlLevelInfo.end(); iterCtrLevelInfo++)
//	{
//		if (0 == strcmp(iterCtrLevelInfo->chDeviceName, chDeviceName))
//		{
//			try
//			{
//				pCtrlLevelInfo = new S_NEW_CTRLLEVELINFO;
//			}
//			catch (std::bad_alloc)
//			{
//				return pCtrlLevelInfo;
//			}
//			memcpy(pCtrlLevelInfo, &(*iterCtrLevelInfo), sizeof(S_NEW_CTRLLEVELINFO));
//			return pCtrlLevelInfo;
//		}
//	}
//	return pCtrlLevelInfo;
//}
//
//OPENDOORAPPLYCONFIG* CZCMsgManager::GetOpenDoorApplyConfig(int nDevNumber)
//{
//	TAGDOAACCESSINFO_S* pAccessHost = GetAccessHostInfo(nDevNumber);
//	if (pAccessHost == NULL)
//	{
//		return NULL;
//	}
//	S_NEW_CTRLLEVELINFO* pCTRLevel = GetCTRLevelInfo(pAccessHost->chDevName);
//
//	OPENDOORAPPLYCONFIG*  pOpenDoorApplyConfig= NULL;
//	pOpenDoorApplyConfig = new OPENDOORAPPLYCONFIG;
//	memset(pOpenDoorApplyConfig, 0, sizeof(OPENDOORAPPLYCONFIG));
//
//	if (pCTRLevel == NULL)
//	{
//		if (pOpenDoorApplyConfig != NULL)
//		{
//			delete pOpenDoorApplyConfig;
//		}
//		return NULL;
//	}
//
//	std::vector<TAGCTRLEVELPLAN_S>::iterator iterCTRLevelPlan = m_vCtrlLevelPlan.begin();
//	char* chLevelName = NULL;
//	chLevelName = new char[CTRLEVELNAMELENGTH];
//	_snprintf(chLevelName, CTRLEVELNAMELENGTH*sizeof(char), "%s", pCTRLevel->chLevelName);
//
//	while (iterCTRLevelPlan != m_vCtrlLevelPlan.end())
//	{
//		// 		iterCTRLevelPlan = find_if(m_vecpCtrLevelPlan.begin(), m_vecpCtrLevelPlan.end(), std::bind2nd(CTRLevelPlanInfoFind(), chLevelName));
//		
//		if (strcmp(chLevelName, iterCTRLevelPlan->chLevelName) != 0)
//		{
//			iterCTRLevelPlan++;
//			continue;
//		}
//		switch((*iterCTRLevelPlan).nMethodId)
//		{
//		case UNIT_APPLY_STRATEGY_LIFE:
//			pOpenDoorApplyConfig->nLifeLength = (*iterCTRLevelPlan).nSetItem1;
//			break;
//		case UNIT_APPLY_STRATEGY_METHOD:
//			pOpenDoorApplyConfig->nApplyMethod = (*iterCTRLevelPlan).nSetItem1;
//			break;
//		case UNIT_APPLY_STRATEGY_BY_FIRSTWAY:
//			pOpenDoorApplyConfig->nApplyFirstWay = (*iterCTRLevelPlan).nSetItem1;
//			pOpenDoorApplyConfig->nFirstWayCount = (*iterCTRLevelPlan).nSetItem2;
//			break;
//		case UNIT_APPLY_STRATEGY_BY_SECONDWAY:
//			pOpenDoorApplyConfig->nApplySecondWay = (*iterCTRLevelPlan).nSetItem1;
//			pOpenDoorApplyConfig->nSecondWayCount = (*iterCTRLevelPlan).nSetItem2;
//			break;
//		case UNIT_APPLY_STRATEGY_RECORD:
//			pOpenDoorApplyConfig->nRecordMethod = (*iterCTRLevelPlan).nSetItem1;
//			pOpenDoorApplyConfig->nRecordLengthFirst = (*iterCTRLevelPlan).nSetItem2;
//			pOpenDoorApplyConfig->nRecordLengthSecond = (*iterCTRLevelPlan).nSetItem3;
//			break;
//		case UNIT_APPLY_STRATEGY_CAPTURE:
//			pOpenDoorApplyConfig->nPreCaptureMethod = (*iterCTRLevelPlan).nSetItem1;
//			pOpenDoorApplyConfig->nPreCaptureInternal = (*iterCTRLevelPlan).nSetItem2;
//			pOpenDoorApplyConfig->nPreCaptureLength = (*iterCTRLevelPlan).nSetItem3;
//			break;
//		case UNIT_APPLY_STRATEGY_PLANID:
//			pOpenDoorApplyConfig->nTreatmentID = (*iterCTRLevelPlan).nSetItem1;
//			memcpy(pOpenDoorApplyConfig->chTreatmentName, (*iterCTRLevelPlan).chSetItem4,sizeof(pOpenDoorApplyConfig->chTreatmentName));
//			break;
//		case UNIT_APPLY_STRATEGY_STEPBYSTEP:
//			pOpenDoorApplyConfig->nPerformStepByStep = (*iterCTRLevelPlan).nSetItem1;
//			break;
//		case UNIT_APPLY_STRATEGY_OPENDOOR_AUTHORIZATION:
//			pOpenDoorApplyConfig->nOpenDoorAuthorization = (*iterCTRLevelPlan).nSetItem1;
//			break;
//		case UNIT_APPLY_STRATEGY_SUPERIOR_AUTHORIZATION:
//			pOpenDoorApplyConfig->nSuperiorAuthorization = (*iterCTRLevelPlan).nSetItem1;
//			break;
//		case UNIT_APPLY_STRATEGY_ARRANGEMENT_CHECK:
//			pOpenDoorApplyConfig->nArrangementCheck = (*iterCTRLevelPlan).nSetItem1;
//			break;
//		case UNIT_APPLY_STRATEGY_ALLOW_APPROVAL:
//			pOpenDoorApplyConfig->nAllowApproval = (*iterCTRLevelPlan).nSetItem1;
//			break;
//		case UNIT_APPLY_STATEGY_FIRSTCARD_AUTHORIZATION:
//			pOpenDoorApplyConfig->nFirstCardAuthorization = (*iterCTRLevelPlan).nSetItem1;
//			break;
//		default:
//			break;
//		}
//		iterCTRLevelPlan++;
//	}
//	delete chLevelName;
//	chLevelName = NULL;
//	return pOpenDoorApplyConfig;
//}
//
//bool CZCMsgManager::RequestCloseReplay()
//{
//	DWORD dwMsgID = GetValidMsgID();
//	return AddSendMsg(ZC_MODULE_BCBCLIENT,dwMsgID,ZC_MSG_BCBCLIENT_ALARMREPLAY_CLOSE,NULL,0);
//
//}
//
//bool CZCMsgManager::RequestSubmitDealInfo( TAGDOA_INFO_P_NEW info, DWORD dwMsgID )
//{
//	BYTE* pBuf = new BYTE[sizeof(TAGDOA_INFO_P_NEW)];
//
//	memcpy(pBuf,&info,sizeof(TAGDOA_INFO_P_NEW));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_SUBMITDEALINFO, pBuf, sizeof(TAGDOA_INFO_P_NEW));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//char* CZCMsgManager::GenerateGUID()
//{
//	char* guidBuf = NULL;
//	guidBuf = new (std::nothrow)char[GUIDLENGTH]; 
//	if (NULL == guidBuf)
//	{
//		return guidBuf;
//	}
//	memset(guidBuf,0,GUIDLENGTH);
//	GUID guid;
//	CoInitialize(NULL);
//	if(S_OK == CoCreateGuid(&guid))
//	{
//		_snprintf(guidBuf, GUIDLENGTH,
//			"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
//			guid.Data1,	guid.Data2,	guid.Data3,
//			guid.Data4[0], guid.Data4[1],
//			guid.Data4[2], guid.Data4[3],
//			guid.Data4[4], guid.Data4[5],
//			guid.Data4[6], guid.Data4[7]);
//	}
//	CoUninitialize();
//	return guidBuf;
//}
//
//bool CZCMsgManager::RequestLinkAlarmVideo(T_OPENDOORLINKVIDEOPRARM info,  DWORD dwMsgID)
//{
//	BYTE* pBuf = new BYTE[sizeof(T_OPENDOORLINKVIDEOPRARM)];
//
//	memcpy(pBuf,&info,sizeof(T_OPENDOORLINKVIDEOPRARM));
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_OPENDOORLINKVIDEO, pBuf, sizeof(T_OPENDOORLINKVIDEOPRARM));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::IsGUID( std::string str )
//{
//// 	Match m = Regex.Match(str, @"^[0-9a-f]{8}(-[0-9a-f]{4}){3}-[0-9a-f]{12}$", RegexOptions.IgnoreCase);
//// 	if (m.Success)
//// 	{
//// 		//可以转换 
//// 		//Guid guid = new Guid(str);
//// 		return true;
//// 	}
//// 	else
//// 	{
//// 		//不可转换 
//// 		return false;
//// 	}
//	return true;
//}
//
//bool CZCMsgManager::RequestVideoAttachmentList( CLIENTGETMEDIASTORAGEATTACHMENT_P info )
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[sizeof(CLIENTGETMEDIASTORAGEATTACHMENT_P)];
//
//	memcpy(pBuf,&info,sizeof(CLIENTGETMEDIASTORAGEATTACHMENT_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_ALARM_GETMSATTACHMENT , pBuf, sizeof(CLIENTGETMEDIASTORAGEATTACHMENT_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestPlayAttachmentList(void* pInfo, int nLength)
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[nLength];
//
//	memcpy(pBuf,pInfo,nLength);
//
//	bool bRet = AddSendMsg(ZC_MODULE_BCBCLIENT, dwMsgID, ZC_MSG_BCBCLIENT_STARTCHECKPLAYBACK , pBuf, nLength);
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestClosePlayAttachmentList()
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	return  AddSendMsg(ZC_MODULE_BCBCLIENT,dwMsgID,ZC_MSG_BCBCLIENT_STOPCHECKPLAYBACK,NULL,0);
//
//}
//
//bool CZCMsgManager::RequestStaffSearchInfo( TAGDOABYCARDINFO_NEW_P info )
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[sizeof(TAGDOABYCARDINFO_NEW_P)];
//	memcpy(pBuf, &(info), sizeof(TAGDOABYCARDINFO_NEW_P));
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_APPLY_BYCARDINFO_NEW, pBuf, sizeof(TAGDOABYCARDINFO_NEW_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestUserDoorCameraRelation()
//{
//	DWORD dwMsgID = GetValidMsgID();
//	return AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_USERDOORCAMERARELATION, NULL, 0);
//}
//
//bool CZCMsgManager::RequestEscortAccessRelation()   //请求获取门禁押运设备关联信息
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[sizeof(ACCESSSYRELATION_GET_P)];
//	memset(pBuf, 0, sizeof(ACCESSSYRELATION_GET_P));
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_ACCESSSYRELATION_GET, pBuf, sizeof(ACCESSSYRELATION_GET_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddUserDoorCameraRelationInfo( USERDOORCAMERARELATION_CLIENT_GET_S* pInfo )
//{
//	USERDOORCAMERARELATION_CLIENT_GET_S* pUserDoorRelationInfo = new USERDOORCAMERARELATION_CLIENT_GET_S;
//	memcpy(pUserDoorRelationInfo, pInfo, sizeof(USERDOORCAMERARELATION_CLIENT_GET_S));
//
//	m_mapUserDoorCameraRelationInfo[pInfo->nDoorId] = pUserDoorRelationInfo;
//
//}
//
//USERDOORCAMERARELATION_CLIENT_GET_S* CZCMsgManager::GetUserDoorRelation( int nDeviceId )
//{
//	std::map<int, USERDOORCAMERARELATION_CLIENT_GET_S*>::iterator iter = m_mapUserDoorCameraRelationInfo.begin();
//	iter = m_mapUserDoorCameraRelationInfo.find(nDeviceId);
//	if (iter != m_mapUserDoorCameraRelationInfo.end())
//	{
//		return iter->second;
//	}
//	return NULL;
//}
//
//bool CZCMsgManager::RequestLockOrUnlockAttachment( ALARMSTORAGEFILELOCKED_SET_P info )
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[sizeof(ALARMSTORAGEFILELOCKED_SET_P)];
//	memcpy(pBuf, &(info), sizeof(ALARMSTORAGEFILELOCKED_SET_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_ALARM_LOCKMSATTACHMENT, pBuf, sizeof(ALARMSTORAGEFILELOCKED_SET_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestLockOrUnlockStateHistory( TAGDOAHISTORYINFOWITHLOCK_P info )
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[sizeof(TAGDOAHISTORYINFOWITHLOCK_P)];
//	memcpy(pBuf, &(info), sizeof(TAGDOAHISTORYINFOWITHLOCK_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYLOCKINFO, pBuf, sizeof(TAGDOAHISTORYINFOWITHLOCK_P));
//
//	delete []pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//S_RECV_CARDLOGINFO* CZCMsgManager::GetCardPersonInfo( T_TRANSMITALARMINFO_EX* pAlarmInfo )
//{
//	CString csMemo;
//	char strImgId[64] = {0};
//	S_RECV_CARDLOGINFO* pCardInfo = new S_RECV_CARDLOGINFO;
//	memset(pCardInfo, 0, sizeof(S_RECV_CARDLOGINFO));
//
//	csMemo = pAlarmInfo->tTransmitAlarmInfo.tAlarmInfo.chMemo;
//
//	if (csMemo.IsEmpty())
//	{
//		_snprintf(strImgId, sizeof(strImgId), "%s","");
//	}
//	int iFirst = csMemo.Find(_T('|'));
//	int iSecond = csMemo.Find(_T('|'), iFirst+1);
//	CString strIdentity = csMemo.Mid(iSecond+1);
//	CString strCardType = csMemo.Left(iFirst);
//	CString csCardNum = csMemo.Mid(iFirst+1, iSecond-iFirst-1);
//
//	int iPersonLength = 0;
//	CString strID;
//
//	switch(_ttoi(strCardType))
//	{
//	case 0: //非法
//		pCardInfo->nCardType = 3;	//卡的类别：即1-合法卡、2-无权限卡、3-非法卡，具体待定
//		pCardInfo->nInfoType = 2;
//		break;
//	case 1: //合法
//		pCardInfo->nCardType = 1;	//卡的类别：即1-合法卡、2-无权限卡、3-非法卡，具体待定
//		break;
//	case 2: //无权限
//		pCardInfo->nCardType = 2;	//卡的类别：即1-合法卡、2-无权限卡、3-非法卡，具体待定
//		break;
//	default:
//		break;
//	}
//
//
//	iPersonLength = CZCMsgManager::Instance()->m_vAllPersonInfo.size();
//	for (int i=0; i<iPersonLength; i++)
//	{
//		strID = CZCMsgManager::Instance()->m_vAllPersonInfo[i].chId;
//		if (strID == strIdentity)
//		{
//			pCardInfo->nAuthority = 1;		//刷卡人权限 1-合规 2-不合规
//			pCardInfo->nInfoType = 1;	   //信息类型：1-指纹信息，2-刷卡信息
//			_snprintf(pCardInfo->chUserName, sizeof(pCardInfo->chUserName), "%s",CZCMsgManager::Instance()->m_vAllPersonInfo[i].chUserName);		//刷卡人姓名
//			_snprintf(pCardInfo->chStaffType, sizeof(pCardInfo->chStaffType), "%s",CZCMsgManager::Instance()->m_vAllPersonInfo[i].nUserType ==1? "内部":"外部" );	//分类
//			_snprintf(pCardInfo->chStaffId, sizeof(pCardInfo->chStaffId), "%s",CZCMsgManager::Instance()->m_vAllPersonInfo[i].chWorkNum);
//			_snprintf(pCardInfo->chHeadImg, sizeof(pCardInfo->chHeadImg), "%s",CZCMsgManager::Instance()->m_vAllPersonInfo[i].chHeadImage);
//			_snprintf(pCardInfo->chCardLogTime, sizeof(pCardInfo->chCardLogTime), "%s",pAlarmInfo->tTransmitAlarmInfo.chAlarmDateTime);
//
//			//卡号
//			char * pCardNum = NULL;
//			CStringToChar(csCardNum, &pCardNum);
//			if (NULL != pCardNum)
//			{
//				_snprintf(pCardInfo->chCardNum, sizeof(pCardInfo->chCardNum), "%s", pCardNum);
//				free(pCardNum);
//				pCardNum = NULL;
//			}
//
//			std::vector<TAGDOADEPARTMENTINFO_S>::iterator iter = CZCMsgManager::Instance()->m_DepartmentInfo.begin();
//			for (; iter != CZCMsgManager::Instance()->m_DepartmentInfo.end();iter++)
//			{
//				if (iter->nId = CZCMsgManager::Instance()->m_vAllPersonInfo[i].nDepartmentId)
//				{
//					_snprintf(pCardInfo->chComplany, sizeof(pCardInfo->chComplany), "%s",iter->chDepartMentName);
//				}
//			}
//		
//		break;
//		}
//	}
//	return pCardInfo;
//}
//
//void CZCMsgManager::AddUserInfoToMap(S_New_UserInfo* tUserInfo, int nIndex)
//{
//	CZCMsgManager::Instance()->m_AllDearerDetails[CZCMsgManager::Instance()->m_AllDealerInfo[nIndex]] = tUserInfo;
//}
//
//bool CZCMsgManager::RequestSetStaffInfo(STAFFINFOOPERATION_P info, DWORD dwMsgId)
//{
//	BYTE* pBuf = new BYTE[sizeof(STAFFINFOOPERATION_P)];
//	memcpy(pBuf, &(info), sizeof(STAFFINFOOPERATION_P));
//	CZCMsgManager::Instance()->m_cDebugLog->MessageRecord("Function =CZCMsgManager::RequestSetStaffInfo Detail = 错误码%s", info.chUserName);
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgId, ZC_MSG_APP_OPENDOOR_STAFFINFOOPERATION, pBuf, sizeof(STAFFINFOOPERATION_P));
//
//	delete[]pBuf;
//	pBuf = NULL;
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestDepartmentOperation(DEPARTMENTINFOOPERATION_P info, DWORD dwMsgId)
//{
////	m_dwMsgID++;
//	BYTE* pBuf = new BYTE[sizeof(DEPARTMENTINFOOPERATION_P)];
//	memcpy(pBuf, &(info), sizeof(DEPARTMENTINFOOPERATION_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgId, ZC_MSG_APP_OPENDOOR_DEPARTMENTINFOOPERATION, pBuf, sizeof(DEPARTMENTINFOOPERATION_P));
//
//	delete[]pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestStaffStateOperation(STAFFSTATUS_SET_P info)
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[sizeof(STAFFSTATUS_SET_P)];
//	memcpy(pBuf, &(info), sizeof(STAFFSTATUS_SET_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_STAFFSTATUS_SET, pBuf, sizeof(STAFFSTATUS_SET_P));
//
//	delete[]pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestDepartmentInfo(DEPARTMENTINFO_GET_P &info)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO_GET, (BYTE*)&info, sizeof(DEPARTMENTINFO_GET_P));
//	return bRet;
//}
//
//bool CZCMsgManager::RequestAuthgroupInfo()
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_AUTHGROUP_GET, NULL, 0);
//
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestStaffAuthgroupInfo(STAFFAUTHINFO_GET_P &info)
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	BYTE* pBuf = new BYTE[sizeof(STAFFAUTHINFO_GET_P)];
//	memcpy(pBuf, &(info), sizeof(STAFFAUTHINFO_GET_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_STAFFAUTHINFO_GET, pBuf, sizeof(STAFFAUTHINFO_GET_P));
//
//	delete[]pBuf;
//	pBuf = NULL;
//
//	return bRet;
//
//}
//
//bool CZCMsgManager::RequestStaffInfoOperation(STAFFINFO_GET_P info, DWORD dwMsgID)
//{
//	if(dwMsgID == 0)
//	{
//		dwMsgID = GetValidMsgID();
//	}
//	BYTE* pBuf = new BYTE[sizeof(STAFFINFO_GET_P)];
//	memcpy(pBuf, &(info), sizeof(STAFFINFO_GET_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_STAFFINFO_GET, pBuf, sizeof(STAFFINFO_GET_P));
//
//	delete[]pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//bool CZCMsgManager::RequestOperationInfo(STAFFOPERATION_GET_P info)
//{
//	DWORD dwMsgID = GetValidMsgID();
//	BYTE* pBuf = new BYTE[sizeof(STAFFOPERATION_GET_P)];
//	memcpy(pBuf, &(info), sizeof(STAFFOPERATION_GET_P));
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_OPENDOOR_STAFFOPERATION_GET, pBuf, sizeof(STAFFOPERATION_GET_P));
//
//	delete[]pBuf;
//	pBuf = NULL;
//	return bRet;
//}
//
//void CZCMsgManager::AddStaffDepartment(DEPARTMENTINFO_GET_S *info, bool bClear)
//{
//	if (bClear)
//	{
//		m_vecStaffDepartment.clear();
//	}
//	m_vecStaffDepartment.push_back(*info);
//}
//
//void CZCMsgManager::AddAuthgroup(AUTHGROUP_GET_S *info, bool bClear)
//{
//	if (bClear)
//	{
//		m_vecfAuthGroup.clear();
//	}
//	m_vecfAuthGroup.push_back(*info);
//}
//
//void CZCMsgManager::AddStaffAuthgroup(STAFFAUTHINFO_GET_S info, bool bClear)
//{
//	if (bClear)
//	{
//		m_vecStaffAuthgroup.clear();
//	}
//	m_vecStaffAuthgroup.push_back(info);
//}
//
//void CZCMsgManager::AddStaffinfo(STAFFINFO_GET_S *info, bool bClear)
//{
//	if (bClear)
//	{
//		m_vecStaffinfo.clear();
//	}
//	m_vecStaffinfo.push_back(*info);
//
//}
//
//void CZCMsgManager::AddStaffOperationinfo(STAFFOPERATION_GET_S *info, bool bClear)
//{
//	if (bClear)
//	{
//		m_vecStaffOperationinfo.clear();
//	}
//	m_vecStaffOperationinfo.push_back(*info);
//}
//
//void CZCMsgManager::SetStaffManagerUIHandle(HWND hUI)
//{
//	CZCMsgManager::Instance()->hStaffManagerUI = hUI;
//}
//
//void CZCMsgManager::SetAddStaffInfoUIHandle(HWND hUI)
//{
//	CZCMsgManager::Instance()->hAddStaffInfoUI = hUI;
//}
//
//void CZCMsgManager::SetOperationInfoUIHandle(HWND hUI)
//{
//	CZCMsgManager::Instance()->hOperationInfoUI = hUI;
//
//}
//
//bool CZCMsgManager::RequstLocalDeviceNodeInfo()
//{
//	DWORD dwMsgID = GetValidMsgID();
//
//	bool bRet = AddSendMsg(ZC_MODULE_APP, dwMsgID, ZC_MSG_APP_SYSDORCTOR_DEVINFO, NULL, 0);
//	return bRet;
//}
//
////得到刷卡人身份证号码
//CString CZCMsgManager::OnGetSwipPersonIDNumber(CString csMemo)					
//{
//	if (csMemo.IsEmpty())
//	{
//		return _T("");
//	}
//	int iFirst = csMemo.Find(_T('|'));
//	int iSecond = csMemo.Find(_T('|'), iFirst+1);
//	CString strIdentity = csMemo.Mid(iSecond+1);
//
//	return strIdentity;
//}
//
////得到刷卡人卡号
//CString CZCMsgManager::OnGetSwipPersonCardNumber(CString csMemo)					
//{
//	if (csMemo.IsEmpty())
//	{
//		return _T("");
//	}
//	int iFirst = csMemo.Find(_T('|'));
//	int iSecond = csMemo.Find(_T('|'), iFirst+1);
//	CString strCardNo = csMemo.Mid(iFirst+1, iSecond-1-iFirst);
//
//	return strCardNo;
//}
//
////得到刷卡人对应的头像
//CString CZCMsgManager::OnGetSwipCardPersonImgId(CString csIdNumber)
//{
//	//拿身份证号获取相应的头像ID 
//	int iPersonLength = 0;
//	CString strImgId;
//	CString strID;
//
//	iPersonLength = CZCMsgManager::Instance()->m_vAllPersonInfo.size();
//	for (int i=0; i<iPersonLength; i++)
//	{
//		strID = CZCMsgManager::Instance()->m_vAllPersonInfo[i].chId;
//		if (strID == csIdNumber)
//		{
//			strImgId = CZCMsgManager::Instance()->m_vAllPersonInfo[i].chHeadImage;
//			return strImgId;
//		}
//	}
//	return strImgId;
//}
