/**
* @file ZCProtocol.h 
*
* @brief ����ͻ��˸�ģ�齻��Э��궨��
* 
* @version 1.0.0.1
*
* @author gaoxiaoliang@typrotech.com
*/

#ifndef TY_ZCPROTOCOL_H
#define TY_ZCPROTOCOL_H

#include "ZCErrorCode.h"
#include "ConnectAppProtocol.h"


/************************************************************************/
/*                          ��Ϣ�ṹ����                                */
/************************************************************************/
/** @defgroup ZCMsgHeadDefine ��ϢЭ��ͷ���ṹ����      
 * ����ÿ��ͨ����Ϣ��ͷ��������Ϣ��
 * @{
 */
 
/** 
 * @brief ��ϢЭ��ͷ���ṹ����
 *
 * �ýṹ��ÿ��ͨ����Ϣ��ͷ��������Ϣ���ܳ���20�ֽڡ�
 */
typedef struct
{
	WORD   wProtocolVersion;    ///<Э��汾           @note Ŀǰ�汾ֵΪ0
	WORD   wReserved;           ///<����λ             @note ����λ��Ŀǰʹ��ʱ��0����
	WORD   wMsgModuleType;      ///<������Ϣ��ģ������ @see E_ZC_MODULETYPE
	WORD   wREQModuleType;      ///<������Ϣ��ģ������ @see E_ZC_MODULETYPE
	DWORD  dwMsgType;           ///<��Ϣ����           @note ���������ֵ����ο���������Ϣ����ֵ����   
	DWORD  dwMsgId;             ///<��Ϣ����           @note �����߿�ͨ����ֵ������ͬ��Ϣ���͵���Ϣ
	DWORD  dwMsgLength;         ///<��Ϣ����	       @note �������ж���Ϣ�Ƿ���ȷ�Լ�������Ϣ�����
}ZC_MSG_HEAD, *LPZC_MSG_HEAD;
 
/** 
 * @brief ��Ӧ��Ϣͷ���ṹ����
 *
 * �ýṹ��ÿ����������Ϣ��ͷ��������Ϣ���ܳ���8�ֽڡ�
 */
typedef struct
{
	DWORD nOK;        ///<�ɹ���� 0-ʧ�ܣ�����ɹ�
	DWORD nError;     ///<�����룬��nOKΪ�ɹ�ʱ����ֵ������
}ZC_MSG_RESP_RESULT, *LPZC_MSG_RESP_RESULT;
/** @} */

/************************************************************************/
/*                             ģ�鶨��                                 */
/************************************************************************/
/** @defgroup ZCMsgModuleTypeDefine �ͻ��˸�ģ������ֵ����      
 * ����˵���ͻ��˸�ģ���Ӧ��ģ������ֵ��
 * @{
 */
 
/** 
 * @brief �ͻ��˸�ģ������ֵ����
 *
 * �ýṹ������ҵ��ģ�����չ�����¡�
 */
typedef enum
{
    ZC_MODULE_SERVER     = 1000,   ///<(1000)��Ϣ����ģ��
	ZC_MODULE_APP        = 2000,   ///<(2000)APPģ��
	ZC_MODULE_BCBCLIENT  = 3000,   ///<(3000)BCB�ͻ���ģ��
	ZC_MODULE_HANDOVER   = 4000,   ///<(4000)���Ӱ�ģ��
	ZC_MODULE_SCHEDULE   = 4100,   ///<(4100)�Ű�ģ��
	ZC_MODULE_TASK       = 4200,   ///<(4200)����ģ��
	ZC_MODULE_ALARM      = 5000,   ///<(5000)����ģ��
	ZC_MODULE_OPENDOOR   = 5100,   ///<(5100)��������֤ģ��
	ZC_MODULE_SYSDORCTOR = 5200,   ///<(5200)������άģ��
}E_ZC_MODULETYPE;
/** @} */

/************************************************************************/
/*                          ��Ϣ���Ͷ���                                */
/************************************************************************/
/** @defgroup ZCMsgTypeDefine ��ģ����Ϣ����ֵ����      
 * ����˵����ģ����ʹ�õ���Ϣ����ֵ�����Ӧ�Ľṹ��
 * @{
 */
 
/** @defgroup ZCCommonMsgTypeDefine ��ģ�鹲ͬ��Ӧ��Ϣ����ö��      
 * �����ģ�鹲ͬ��Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
    /**
	* @brief (0)ģ��ע��ʧ����Ϣ
	* 
	* @note ������Ϣֵ:\ref ZC_MSG_SERVER_RESP_REGISTER (10000)
	* @note �����ṹ��:NULL
	*/
    ZC_MSG_SERVER_REQ_REGFAILED    = 0,            
	ZC_MSG_SERVER_REQ_NOMODULE,                ///<(1)����ģ�鲻������Ϣ
	
	/**
	* @brief (2)����ģ��Ͽ���Ϣ
	* 
	* ��Ϊ����������Ϣ����ϵͳ��ĳ��ģ��ע��ʱ����Ϣ�����ͨ������Ϣ֪ͨ���ߵ�����ģ�顣��ģ������п����Ƿ��账�����Ϣ��
	* 
	* @note ���ͽṹ��:WORD wModuleType ģ������ֵ
	*/
	ZC_MSG_SERVER_REQ_MODULELOGOUT,           
	
	ZC_MSG_COMMON_ROLEINFO = 100,              ///<(100)ϵͳ��ɫ��Ϣ
	ZC_MSG_COMMON_CHILDROLEINFO,               ///<(101)������ɫ��Ϣ
	ZC_MSG_COMMON_PLANINFO,                    ///<(102)Ԥ������Ϣ
	ZC_MSG_COMMON_USERIMAGEID,                 ///<(103)�û�ͷ����Ϣ
	ZC_MSG_COMMON_EVENTINFO,                   ///<(104)�¼�����Ϣ
	ZC_MSG_COMMON_OPENCAMERA,                  ///<(105)�����ĳ��ͨ����Ƶ����
	
	ZC_MSG_COMMON_CURUSER = 2000,              ///<(2000)��ǰ�û���Ϣ��1��
	ZC_MSG_COMMON_DOWNLOADPIC,                 ///<(2001)ͷ��·��
	ZC_MSG_COMMON_ONLINEUSER,                  ///<(2002)��ǰ�����û���Ϣ
	ZC_MSG_COMMON_CURUSERINFOEX,               ///<(2003)��ǰ�û���Ϣ����
	ZC_MSG_COMMON_ALLUSERINFO,                 ///<(2004)�����û���Ϣ����
	ZC_MSG_COMMON_USERSTATE,                   ///<(2005)�û�״̬��Ϣ����
	ZC_MSG_COMMON_USERALLINFO,                 ///<(2006)�û���ϸ��Ϣ����
	ZC_MSG_COMMON_ALLSUBORDINATEINFO,          ///<(2007)�û�����������Ϣ����
	ZC_MSG_COMMMON_CLASSMONITOR,               ///<(2008)�û�ͬһ����ϼ���ɫ��Ϣ����
	ZC_MSG_COMMON_USERMONITOR,                 ///<(2009)�û��ϼ���ɫ��Ϣ����
	ZC_MSG_COMMON_ALLCLASSSUBORDINATEINFO,     ///<(2010)�û�ͬһ���������������Ϣ����
	ZC_MSG_COMMON_UPLOADATTACHMENT,            ///<(2011)�����ϴ��������

    ZC_MSG_COMMON_GETALARMATTACHMENTFROMMS = 2020,    ///<(2020)�Ӵ洢���������ر���������������  @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_GETALARMATTACHMENTFROMMS (30050)
    ZC_MSG_COMMON_PLAYBACKALARMATTACHMENTFROMMS,      ///<(2021)�Ӵ洢�������طű���������Ƶ��������  @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_PLAYBACKALARMATTACHMENTFROMMS (30051)

	ZC_MSG_COMMON_THIRDPART_EXCHANGEMESSAGE = 2025,      ///<(2025)��������ϵͳ������Ϣ�������  @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_THIRDPART_EXCHANGEMESSAGE (30090)
    ZC_MSG_COMMON_TRANSCOMMONMSGTOKOALA,                 ///<(2026)����������������Ϣ�������  @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_TRANSCOMMONMSGTOKOALA (30091)

	ZC_MSG_COMMON_ALLAREAINFO = 2050,          ///<(2050)����������Ϣ����
	ZC_MSG_COMMON_ALLALARMTYPEINFO,            ///<(2051)���б���������Ϣ����
	ZC_MSG_COMMON_ALLALARMLEVELINFO,           ///<(2052)���б����ȼ���Ϣ����
	ZC_MSG_COMMON_ALLALARMDEALSTATEINFO,       ///<(2053)��������״̬������Ϣ����
	ZC_MSG_COMMON_ALARMDEALTYPE,               ///<(2054)���б����������ͷ���
	ZC_MSG_COMMON_ALARMDECIDETYPE,             ///<(2055)���б������Դ����ͷ���
	ZC_MSG_COMMON_ALLKEYPARTINFO,              ///<(2056)����������Ϣ����
	ZC_MSG_COMMON_ALLDEVICEINFO,               ///<(2057)����������ϸ��Ϣ����
	
	ZC_MSG_COMMON_SETDUTYSTATUS = 2100,        ///<(2100)���������û�״̬���� 
	
	ZC_MSG_COMMON_ADDEVENT = 2200,             ///<(2200)��̬�����������  
	ZC_MSG_COMMON_SENDEMAIL,                   ///<(2201)�����ʼ��������
	ZC_MSG_COMMON_CLOSEALLVIDEO,               ///<(2202)�ر���Ƶ���ڽ������
    ZC_MSG_COMMON_DEVTALKBYID,                 ///<(2203)ͨ���Խ��豸ID���жԽ�����
	ZC_MSG_COMMON_CONTROLACSHOST,              ///<(2204)�Ž��������ƽ������
    ZC_MSG_COMMON_FLASHNODE,              ///<(2205)�ڵ���˸�������

    ZC_MSG_COMMON_REQUESTTRANSMSG_EX = 2299,   ///<(2299)ͨ�����ĸ������ͻ���ת����Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_REQUESTTRANSMSG_EX (30299)
	ZC_MSG_COMMON_REQUESTTRANSMSG = 2300,      ///<(2300)ͨ�����ĸ��������ӵ�ͼ�ͻ���ת����Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_REQUESTTRANSMSG (30300)
	ZC_MSG_COMMON_TRANSMSG,                    ///<(2301)����ִ��ת������ @note ��Ϊ�����ͻ����������͵���Ϣ��������ģ���ݲ��������
    ZC_MSG_COMMON_TRANSDEVICETROUBLEMSGTOKOALA,///<(2302)����ƽ̨�ύ�豸������Ϣ�������  @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_TRANSDEVICETROUBLEMSGTOKOALA (30301)
}E_ZC_MSG_COMMON_REQ;
/** @} */

/** @defgroup ZCServerMsgTypeDefine ��Ϣ����ģ����Ӧ��Ϣ����ö��      
 * ������Ϣ����ģ����Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
	ZC_MSG_SERVER_RESP_REGISTER     = 10000,     ///<(10000)ģ��ע����Ϣ  @note ����ṹ��:NULL @note ������Ϣֵ:\ref ZC_MSG_SERVER_REQ_REGFAILED (0) ����ʧ��ʱ���� 
	ZC_MSG_SERVER_RESP_UNREGISTER,               ///<(10001)ģ�鷴ע����Ϣ 
}E_ZC_MSG_SERVER;
/** @} */

/** @defgroup ZCAppMsgTypeDefine Appģ����Ӧ��Ϣ����ö��      
 * ����Appģ����Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
	ZC_MSG_APP_HA_INFO  = 20000,        ///<(20000)�����û����Ӱ���Ϣ @note ����ṹ��:\ref T_CURUSER_INFO @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_HA_INFO (40000)
	ZC_MSG_APP_HA_WAITUSERLIST,         ///<(20001)������Ӱ���Ա�б� @note ����ṹ��:\ref T_CURUSER_INFO @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_HA_WAITUSERLIST (40001)
	ZC_MSG_APP_HA_A_TASKINFO,           ///<(20002)����ֵ��Ա����ִ����� @note ����ṹ��:\ref T_CURUSER_INFO @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_A_TASKINFO (40002)
	ZC_MSG_APP_HA_M_TASKINFO,           ///<(20003)����ֵ�೤����ִ����� @note ����ṹ��:\ref T_CURUSER_INFO @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_M_TASKINFO (40003)
	ZC_MSG_APP_HA_ALARMINFO,            ///<(20004)����δ��������Ϣ @note ����ṹ��:\ref T_CURUSER_INFO @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_HA_ALARMINFO (40004)
	ZC_MSG_APP_ADD_HAINFO,              ///<(20005)�ύ���Ӱ���Ϣ @note ����ṹ��:\ref P_NEW_ADD_HA_INFO @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_ADD_HAINFO (40005)
	ZC_MSG_APP_SEL_HAINFO,              ///<(20006)��ѯ���Ӱ��¼ @note ����ṹ��:\ref P_NEW_SHOW_HA_INFO @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_SEL_HAINFO (40006)
	ZC_MSG_APP_HA_A_HISTORYINFO,        ///<(20007)����ֵ��Ա���Ӱ���ʷ��ϸ��Ϣ @note ����ṹ��:int nScheduleID �Ű�ID @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_A_HISTORYINFO (40008)
	ZC_MSG_APP_HA_M_HISTORYINFO,        ///<(20008)����ֵ�೤���Ӱ���ʷ��ϸ��Ϣ @note ����ṹ��:int nScheduleID �Ű�ID @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_M_HISTORYINFO (40009)
	ZC_MSG_APP_HA_MODIFYALARMDEALMAN,   ///<(20009)���������޸ı�����������Ϣ @note ����ṹ��:\ref TAG_NEW_ALARMDISPOSAL_BATCHSET_P @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_MODIFYALARMDEALMAN (40010)
	ZC_MSG_APP_HA_CURCLASSUSERINFO,     ///<(20010)�����ȡ��ǰ���������Ա��Ϣ @note ����ṹ��:NULL @note ������Ϣֵ:\ref ZC_MSG_HANDOVER_CURCLASSUSERINFO (40011)
    
	ZC_MSG_APP_DATEGROUPSET = 20100,    ///<(20100)���������������Ϣ������ZC_MSG_SCHEDULE_DATEGROUPSET
	ZC_MSG_APP_DATEGROUPINFO,           ///<(20101)�����ȡ��������Ϣ������ZC_MSG_SCHEDULE_DATEGROUPINFO
	ZC_MSG_APP_CLASSINFOSET,            ///<(20102)������������Ϣ������ZC_MSG_SCHEDULE_CLASSINFOSET
	ZC_MSG_APP_CLASSINFO,               ///<(20103)�����ȡ�����Ϣ������ZC_MSG_SCHEDULE_CLASSINFO
	ZC_MSG_APP_SCHEDULESET,             ///<(20104)���������Ű���Ϣ���ο�ServerConnectApp.h��������ZC_MSG_SCHEDULE_SCHEDULESET
	ZC_MSG_APP_SCHEDULEINFO,            ///<(20105)�����ȡ�Ű���Ϣ���ο�ServerConnectApp.h��������ZC_MSG_SCHEDULE_SCHEDULEINFO
	ZC_MSG_APP_SC_USERINFO,             ///<(20106)������Ű���Ա��Ϣ������ZC_MSG_SCHEDULE_SC_USERINFO
	
	ZC_MSG_APP_TASKINFOSET = 20200,     ///<(20200)�������������Ϣ������ZC_MSG_TASK_TASKINFOSET
	ZC_MSG_APP_FASTTASKINFOSET,         ///<(20201)���������������񣬷���ZC_MSG_TASK_FASTTASKINFOSET
	ZC_MSG_APP_TASKINFO,                ///<(20202)�����ѯ�������������Ϣ(5)������ZC_MSG_TASK_TASKINFO
	ZC_MSG_APP_DETAILEDTASKINFO,        ///<(20203)�����ѯ������ϸ��Ϣ(6)������ZC_MSG_TASK_DETAILEDTASKINFO
	ZC_MSG_APP_TASKSTATESET,            ///<(20204)������������״̬������ZC_MSG_TASK_TASKSTATESET
	ZC_MSG_APP_TASKMODULEINFOSET,       ///<(20205)�����������ģ����Ϣ������ZC_MSG_TASK_TASKMODULEINFOSET
	ZC_MSG_APP_TASKMODULEINFO,          ///<(20206)�����ѯ����ģ����Ϣ������ZC_MSG_TASK_TASKMODULEINFO
	ZC_MSG_APP_DETAILEDTASKMODULEINFO,  ///<(20207)�����ѯ����ģ����ϸ��Ϣ������ZC_MSG_TASK_DETAILEDTASKMODULEINFO
	ZC_MSG_APP_TASKOBJECTINFO,          ///<(20208)�����ȡ���������Ϣ������ZC_MSG_TASK_TASKOBJECTINFO
	ZC_MSG_APP_TASKKEYPARTINFO,         ///<(20209)�����ȡ����λ��Ϣ������ZC_MSG_TASK_TASKKEYPARTINFO
	ZC_MSG_APP_TASKLEVELINFO,           ///<(20210)�����ȡ������Ҫ�̶����ͣ�����ZC_MSG_TASK_TASKLEVELINFO
	ZC_MSG_APP_TASKOPERATIONINFO,       ///<(20211)�����ȡ����������ͣ�����ZC_MSG_TASK_TASKOPERATIONINFO
	ZC_MSG_APP_TASKEXCEPTIONINFO,       ///<(20212)�����ȡ�쳣���ͣ�����ZC_MSG_TASK_TASKEXCEPTIONINFO
	ZC_MSG_APP_DETATASKEXCEPTIONINFO,   ///<(20213)�����ȡ�쳣�������飬����ZC_MSG_TASK_DETATASKEXCEPTIONINFO 
	ZC_MSG_APP_TASKCLASSROLEINFO,       ///<(20214)�����ȡ�����·���ɫ��Ϣ������ZC_MSG_TASK_TASKCLASSROLEINFO
	ZC_MSG_APP_CURONLINEUSERINFO,       ///<(20215)�����ȡ��ǰ�ϰ��û���Ϣ������ZC_MSG_TASK_CURONLINEUSERINFO
	ZC_MSG_APP_TODAYTASKINFO,           ///<(20216)�����ȡ��ǰ�û�����������Ϣ������ZC_MSG_TASK_TODAYTASKINFO
	ZC_MSG_APP_TODAYTASKALLINFO,        ///<(20217)�����ȡĳ����ִ��������Ϣ,����ZC_MSG_TASK_TODAYTASKALLINFO
	ZC_MSG_APP_TODAYTASKOBJECTINFO,     ///<(20218)�����ȡĳ����ִ�����������Ϣ,����ZC_MSG_TASK_TODAYTASKOBJECTINFO
	ZC_MSG_APP_TODAYTASKDOINFO,         ///<(20219)�����ȡĳ���������ִ����Ϣ,����ZC_MSG_TASK_TODAYTASKDOINFO
	ZC_MSG_APP_USERTASKINFO,            ///<(20220)�����ȡĳ�û�����������Ϣ(7)������ZC_MSG_TASK_USERTASKINFO

    /**
	* @brief (20221)������������ִ����Ϣ
	*
	* Ϊ���¼��ݣ�����Ϣ�ɽ������ֲ�����һ�ֲ�����guid��һ�ֺ���guid����Ϣ������������Ϣ���ȵ��ò�ͬ��APP�ӿڡ�
	* 
	* @note ����ṹ��:\ref P_NEW_INSPECT_TASKEXCUTESET ���� P_NEW_INSPECT_TASKEXCUTESET_NEW
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	* @note ������Ϣֵ:\ref ZC_MSG_TASK_TASKEXCUTESET (42021)
	* @note APP���:\ref MSG_REG_NEW_INSPECT_TASKEXCUTESET (1259) ���� MSG_REG_NEW_INSPECT_TASKEXCUTESET_NEW��611��
	*/
	ZC_MSG_APP_TASKEXCUTESET,          

	ZC_MSG_APP_TASK_CURUSERINFO,        ///<(20222)��������ģ������ĵ�ǰ�û���Ϣ������ZC_MSG_TASK_CURUSERINFO
	ZC_MSG_APP_CHECKTASKINFO,           ///<(20223)�����ѯ��ִ��������Ϣ������ZC_MSG_TASK_CHECKTASKINFO	
	ZC_MSG_APP_SHOWTASKCHECKINFO,       ///<(20224)�����ȡ���񸴺������Ϣ������ZC_MSG_TASK_SHOWTASKCHECKINFO
	ZC_MSG_APP_SHOWTASKEPLANINFO,       ///<(20225)�����ȡ���񸴺�Ԥ����Ϣ������ZC_MSG_TASK_SHOWTASKEPLANINFO
	ZC_MSG_APP_ISQUALIFIEDMOD,          ///<(20226)������������ִ���Ƿ�ϸ񣬷���ZC_MSG_TASK_ISQUALIFIEDMOD
	ZC_MSG_APP_TASKCHECKRECORDSET,      ///<(20227)���������������ļ�¼������ZC_MSG_TASK_TASKCHECKRECORDSET
	
	ZC_MSG_APP_SHOWAREAERRORINFO,       ///<(20228)ͳ��ĳ���������쳣������������ZC_MSG_TASK_SHOWAREAERRORINFO
	ZC_MSG_APP_SHOWAREAERRORATEINFO,    ///<(20229)ͳ��������쳣�ʣ�����ZC_MSG_TASK_SHOWAREAERRORATEINFO
	ZC_MSG_APP_SHOWCOVERRATEINFO,       ///<(20230)ͳ��Ѳ�츲���ʣ�����ZC_MSG_TASK_SHOWCOVERRATEINFO
	ZC_MSG_APP_SHOWALARMRECORINFO,      ///<(20231)��ȡ����������Ϣ������ZC_MSG_TASK_SHOWALARMRECORINFO
	ZC_MSG_APP_SHOWAREAERRORNUMINFO,    ///<(20232)ͳ�Ƶ�λʱ���ڵ������쳣����������ZC_MSG_TASK_SHOWAREAERRORNUMINFO
	ZC_MSG_APP_SHOWERRORCHECKRATEINFO,  ///<(20233)ͳ���쳣�ĸ���ϸ��ʣ�����ZC_MSG_TASK_SHOWERRORCHECKRATEINFO
	
	ZC_MSG_APP_STATICS_TASKADDINFO,     ///<(20234)���������ͳ����Ϣ������ZC_MSG_TASK_STATICS_TASKADDINFO
	ZC_MSG_APP_STATICS_EMPLOYANALY,     ///<(20235)Ա������������ͳ����Ϣ������ZC_MSG_TASK_STATICS_EMPLOYANALY
	ZC_MSG_APP_STATICS_EMPLOYMANAGER,   ///<(20236)Ա��������ͳ����Ϣ������ZC_MSG_TASK_STATICS_EMPLOYMANAGER

	/**
	* @brief (20237)�����ѯ��ִ��������Ϣ���Ƿ�����������
	* 
	* @note ����ṹ��:\ref P_NEW_INSPECT_CHECKTASKINFOWITHLOCK
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_CHECKTASKINFOSHOW * N
	* @note ������Ϣֵ:\ref ZC_MSG_TASK_CHECKTASKLOCKINFO 
	* @note APP���:\ref MSG_REG_NEW_INSPECT_CHECKTASKINFOWITHLOCK (294)
	*/
	ZC_MSG_APP_CHECKTASKLOCKINFO,

	/**
	 * @brief (20238)�����ȡĳ���·������ִ����ϢEx
	 * 
	 * @note ����ṹ��:\ref int �·�����ID
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_TODAYTASKALLINFOSHOW_EX * N
	 * @note ������Ϣֵ:\ref ZC_MSG_TASK_TODAYTASKALLINFOSHOW_EX 
	 * @note APP���:\ref MSG_REG_NEW_INSPECT_TODAYTASKALLINFOSHOW (1275)
	 */
	ZC_MSG_APP_TODAYTASKALLINFOSHOW_EX,

	/**
	 * @brief (20239)�����ȡ����ִ�����Ex
	 * 
	 * @note ����ṹ��:\ref int �·�����ID
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_TODAYTASKDOINFOSHOW_EX * N
	 * @note ������Ϣֵ:\ref ZC_MSG_TASK_TODAYTASKDOINFOSHOW_EX
	 * @note APP���:\ref MSG_REG_NEW_INSPECT_TODAYTASKALLINFOSHOW (1275)
	 */
	ZC_MSG_APP_TODAYTASKDOINFOSHOW_EX,

    /**
	 * @brief (20240)������ݳ���ID�Ͳ�λID��ȡ�����Ŀ������Ϣ
	 * 
	 * @note ����ṹ��:\ref P_EXCEPTION_CHECK_ITEM
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_EXCEPTION_CHECK_ITEM * N
	 * @note ������Ϣֵ:\ref ZC_MSG_TASK_AKIDCONFIGUREINFO
	 * @note APP���:\ref MSG_REG_NEW_AKIDCONFIGUREINFO_GET ��320��
	 */
	ZC_MSG_APP_AKIDCONFIGUREINFO,

    /**
	 * @brief (20241)�����ȡ����Ѳ������Ŀ��ʱ�����Ϣ
	 * 
	 * @note ����ṹ��:\ref NULL
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_GetConfigureTimeInfo * N
	 * @note ������Ϣֵ:\ref ZC_MSG_TASK_CONFIGURETIMEINFO
	 * @note APP���:\ref MSG_REG_NEW_CONFIGURETIME_INFO ��311��
	 */
	ZC_MSG_APP_TASK_CONFIGURETIMEINFO,

	/**
	 * @brief (20242)�������ʱ������ƻ�ȡ����Ѳ������Ŀ��ʱ�����Ϣ
	 * 
	 * @note ����ṹ��:\ref P_ConfigureTimeNameInfo
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_GetConfigureTimeOnlyInfo * N
	 * @note ������Ϣֵ:\ref ZC_MSG_TASK_CONFIGURETIMEONLYINFO
	 * @note APP���:\ref MSG_REG_NEW_CONFIGURETIMENAME_GET ��312��
	 */
	ZC_MSG_APP_TASK_CONFIGURETIMEONLYINFO,

	/**
	 * @brief (20243)�����ѯ������Ϣ���������������Ƿ��ע��
	 * 
	 * @note ����ṹ��:\ref P_NEW_INSPECT_CHECKTASKINFOWITHLOCK_NEW
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_CHECKTASKINFOSHOW * N
	 * @note ������Ϣֵ:\ref ZC_MSG_TASK_CHECKTASKINFOWITHLOCK_NEW
	 * @note APP���:\ref MSG_REG_NEW_INSPECT_CHECKTASKINFOWITHLOCK_NEW ��343��
	 */
	ZC_MSG_APP_TASK_CHECKTASKINFOWITHLOCK_NEW,

	/**
	 * @brief (20244)�����ѯѲ�츲����_New
	 *
	 * @note ����ṹ��:\ref P_NEW_INSPECT_COVERRATENEWINFO
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_INSPECT_COVERRATENEWINFO * N
	 *
	 * @note ������Ϣֵ:\ref ZC_MSG_TASK_COVERRATENEWINFO_NEW (42044)
	 * @note APP���:\ref MSG_REG_NEW_INSPECT_COVERRATENEWINFO (347)
	 */
    ZC_MSG_APP_TASK_COVERRATENEWINFO_NEW,

	ZC_MSG_APP_ALARM_QUERYINFO = 20300,    ///<(20300)������ѯ���������ZC_MSG_ALARM_QUERYINFO
	ZC_MSG_APP_ALARM_STATICINFO,           ///<(20301)����ͳ�ƽ��������ZC_MSG_ALARM_STATICINFO
	ZC_MSG_APP_ALARM_TOPINFO,              ///<(20302)�������н��������ZC_MSG_ALARM_TOPINFO
	ZC_MSG_APP_ALARM_DETAILINFO,           ///<(20303)����ͨ������������Ϣ��ȡ������ϸ��Ϣ������ZC_MSG_ALARM_DETAILINFO
	
	ZC_MSG_APP_ALARM_USERGRAPHINFO,        ///<(20304)�����ȡ�û�����ͼ����Ϣ������ZC_MSG_ALARM_USERGRAPHINFO
	ZC_MSG_APP_ALARM_OPUSERGRAPH,          ///<(20305)������ɾ���û�ͼ������ZC_MSG_ALARM_OPUSERGRAPH
	ZC_MSG_APP_ALARM_USERREPORTINFO,       ///<(20306)�����ȡ�û�������Ϣ���鿴����Tabҳʹ�ã�������ZC_MSG_ALARM_USERREPORTINFO
	ZC_MSG_APP_ALARM_MODSTATUSUSERREPORT,  ///<(20307)���������û�����״̬��Ϣ������ZC_MSG_ALARM_MODSTATUSUSERREPORT
	ZC_MSG_APP_ALARM_OPUSERREPORT,         ///<(20308)������ɾ���û����棬����ZC_MSG_ALARM_OPUSERREPORT
	ZC_MSG_APP_ALARM_USERREPORTBOOKINFO,   ///<(20309)�����ȡ�û����涩����Ϣ�����ı���Tabҳʹ�ã�������ZC_MSG_ALARM_USERREPORTBOOKINFO

	/**
	* @brief (20310)������ѯ������Ƿ�����������
	* 
	* @note ����ṹ��:\ref P_NEW_JH_COMPLEXCHECKWITHLOCK
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_JH_COMPLEXCHECK * N
	* @note ������Ϣֵ:\ref ZC_MSG_ALARM_QUERYLOCKINFO ��50010��
	* @note APP���:\ref MSG_REG_NEW_JH_COMPLEXCHECKWITHLOCK (295)
	*/
    ZC_MSG_APP_ALARM_QUERYLOCKINFO,

	/**
	 * @brief (20311)���ݱ���ID�򱨾�GUID��ȡ������ϸ��Ϣ
	 *
	 * 20170602�����ӿڣ���ȫ��ȡ����������Ϣ
	 * 
	 * @note ����ṹ��:\ref P_NEW_DETAILALARMINFO_GET
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_DETAILALARMINFO_GET
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_DETAILALARMINFO_GET ��50011��
	 * @note APP���:\ref MSG_REG_NEW_ALARMDETAILINFO_NEW_SHOW (353)
	 */
    ZC_MSG_APP_ALARM_DETAILALARMINFO_GET,

	/**
  	 * @brief (20312)�������ͻ�ȡ_�����¼�
	 * 
	 * @note ����ṹ��:\ref NULL
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_ALARMACATEGORY_SHOW * N
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_NEW_ALARMACATEGORY_SHOW ��50012��
	 * @note APP���:\ref MSG_REG_NEW_ALARMACATEGORY_SHOW (354)
	 */
    ZC_MSG_APP_ALARM_NEW_ALARMACATEGORY_SHOW,
	
	ZC_MSG_APP_ALARM_DISPOSALINFO = 20320,      ///<(20320)�����ȡ�û���������Ȩ�ޣ�����ZC_MSG_ALARM_DISPOSALINFO
    ZC_MSG_APP_ALARM_LEVELPLOYINFO, 	        ///<(20321)�����ȡ�����ȼ����ò��ԣ�����ZC_MSG_ALARM_LEVELPLOYINFO
	ZC_MSG_APP_ALARM_HISTORYDEALINFO,           ///<(20322)�����ȡ��ʷ�������ͳ�����ݣ�����ZC_MSG_ALARM_HISTORYDEALINFO
	ZC_MSG_APP_ALARM_POSTILINFO,                ///<(20323)�����ȡ������ע��Ϣ������ZC_MSG_ALARM_POSTILINFO
	ZC_MSG_APP_ALARM_OPERATIONINFO,             ///<(20324)�����ȡ����������Ϣ������ZC_MSG_ALARM_OPERATIONINFO
	ZC_MSG_APP_ALARM_NOTDEALINFO,               ///<(20325)�����ȡδ��������Ϣ������ZC_MSG_ALARM_NOTDEALINFO
	
    ZC_MSG_APP_ALARM_DEALSTATUSSET = 20330,     ///<(20330)�������ñ�����Ϣ����״̬������ZC_MSG_ALARM_DEALSTATUSSET
	ZC_MSG_APP_ALARM_PEOPLESET,                 ///<(20331)�������ñ�����Ϣ�����ˣ�����ZC_MSG_ALARM_PEOPLESET
	ZC_MSG_APP_ALARM_DEALSULTSET,               ///<(20332)�����ύ�������ý��������ZC_MSG_ALARM_DEALSULTSET
	ZC_MSG_APP_ALARM_MODALARMPARAM,             ///<(20333)�����޸ı����ؼ�����������ZC_MSG_ALARM_MODALARMPARAM
	ZC_MSG_APP_ALARM_ADDALARMOPERATIONINFO,     ///<(20334)������������������¼������ZC_MSG_ALARM_ADDALARMOPERATION
	ZC_MSG_APP_ALARM_ADDALARMPOSTILINFO,        ///<(20335)��������������ע��Ϣ������ZC_MSG_ALARM_ADDALARMPOSTILINFO
	ZC_MSG_APP_ALARM_ADDDEFERALARMINGO,         ///<(20336)���������Ӻ�������Ϣ������ZC_MSG_ALARM_ADDDEFERALARMINGO
	
	/**
	* @brief (20337)�����ȡĳ������ý��洢�����б���Ϣ
	* 
	* @note ����ṹ��:\ref CLIENTGETMEDIASTORAGEATTACHMENT_P 
	* @note ���ؽṹ��:\ref CLIENTGETMEDIASTORAGEATTACHMENT_S
	* @note ������Ϣֵ:\ref ZC_MSG_ALARM_GETMSATTACHMENT (50088)
	* @note APP���:\ref MSG_REG_CLIENTGETMEDIASTORAGEATTACHMENT (610)
	*/
	ZC_MSG_APP_ALARM_GETMSATTACHMENT,    

	/**
	* @brief (20338)��������\�������������洢�ļ�
	* 
	* @note ����ṹ��:\ref ALARMSTORAGEFILELOCKED_SET_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	* @note ������Ϣֵ:\ref ZC_MSG_ALARM_LOCKMSATTACHMENT (50089)
	* @note APP���:\ref MSG_REG_ALARMSTORAGEFILELOCKED_SET (601)
	*/
	ZC_MSG_APP_ALARM_LOCKMSATTACHMENT,

	/**
	 * @brief (20339)��������_�ֶ�����
	 * 
	 * @note ����ṹ��:\ref P_ALARMDISPOSAL_ALARMCATEGORY_SET_NEW 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_MANUALENTRY(50089)
	 * @note APP���:\ref MSG_REG_ALARMDISPOSAL_ALARMCATEGORY_SET_NEW (616)
	 */
    ZC_MSG_APP_ALARM_MANUALENTRY,

	/**
	 * @brief (20340)��ȡ���Ľ�������������
	 * 
	 * @note ����ṹ��:\ref P_NEW_PARAM_EXCHANGEINFO 
	 * @note ���ؽṹ��:\ref S_NEW_PARAM_EXCHANGEINFO
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_EXCHANGEINFO_NEW(50067)
	 * @note APP���:\ref MSG_REG_NEW_EXCHANGEINFO_NEW (349)
	 */
    ZC_MSG_APP_ALARM_EXCHANGEINFO_NEW,

	/**
	 * @brief (20341)���Ľ������������ݲ���
	 * 
	 * @note ����ṹ��:\ref P_NEW_EXCHANGEINFO_OPERATION 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_EXCHANGEINFO_OPERATION(50068)
	 * @note APP���:\ref MSG_REG_NEW_EXCHANGEINFO_OPERATION (350)
	 */
    ZC_MSG_APP_ALARM_EXCHANGEINFO_OPERATION,

   /**
	 * @brief (20342)����������־����_New
	 * 
	 * @note ����ṹ��:\ref P_NEW_ALARMDISPOSALNEW_SET 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_REG_NEW_ALARMDISPOSALNEW_SET(50069)
	 * @note APP���:\ref MSG_REG_NEW_ALARMDISPOSALNEW_SET (351)
	 */
    ZC_MSG_APP_ALARM_REG_NEW_ALARMDISPOSALNEW_SET,

	/**
	 * @brief (20343)���ݱ���ID�򱨾�GUID��ȡ������¼��Ϣ
	 * 
	 * @note ����ṹ��:\ref P_NEW_ALARMDISPOSALNEW_SHOW 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_ALARMDISPOSALNEW_SHOW * N
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_REG_NEW_ALARMDISPOSALNEW_SHOW(50070)
	 * @note APP���:\ref MSG_REG_NEW_ALARMDISPOSALNEW_SHOW (352)
	 */
    ZC_MSG_APP_ALARM_REG_NEW_ALARMDISPOSALNEW_SHOW,
	
    /**
	 * @brief (20350)�������ÿ�����Ϣд��
	 * 
	 * @note ����ṹ��:\ref ALARMDEALKOALAINFO_INSERT_P 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_DEALKOALAINFO (50200)
	 * @note APP���:\ref MSG_REG_ALARMDEALKOALAINFO_INSERT (703)
	 */
	ZC_MSG_APP_ALARM_DEALKOALAINFO = 20350,

	/**
	 * @brief (20351)��ȡ������_Koala
	 * 
	 * @note ����ṹ��:\ref GETACTIONLIB_KOALA_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETACTIONLIB_KOALA_S * N
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_GETACTIONLIB_KOALA (50201)
	 * @note APP���:\ref MSG_REG_GETACTIONLIB_KOALA (704)
	 */
	ZC_MSG_APP_ALARM_GETACTIONLIB_KOALA,

    /**
	 * @brief (20352)��ȡԤ����_Koala
	 * 
	 * @note ����ṹ��:\ref GETPREPLANLIB_KOALA_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETPREPLANLIB_KOALA_S * N
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_GETPREPLANLIB_KOALA (50202)
	 * @note APP���:\ref MSG_REG_GETPREPLANLIB_KOALA (705)
	 */
	ZC_MSG_APP_ALARM_GETPREPLANLIB_KOALA,

    /**
	 * @brief (20353)��ȡ�¼���_Koala
	 * 
	 * @note ����ṹ��:\ref GETEVENTLIB_KOALA_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETEVENTLIB_KOALA_S * N
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_GETEVENTLIB_KOALA (50203)
	 * @note APP���:\ref MSG_REG_GETEVENTLIB_KOALA (706)
	 */
	ZC_MSG_APP_ALARM_GETEVENTLIB_KOALA,

	/**
	 * @brief (20354)��ȡKoala��������
	 * 
	 * @note ����ṹ��:\ref GETALARMATTACHMENT_KOALA_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETALARMATTACHMENT_KOALA_S * N
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_GETALARMATTACHMENT_KOALA (50204)
	 * @note APP���:\ref MSG_REG_GETALARMATTACHMENT_KOALA (707)
	 */
	ZC_MSG_APP_ALARM_GETALARMATTACHMENT_KOALA,

	/**
	 * @brief (20355)���ñ�������_��������ֵ
	 * 
	 * @note ����ṹ��:\ref P_NEW_ALARMDISPOSALADDCATEGORYID_AC_SET
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_DISPOSALADDCATEGORYID_AC_SET (50205)
	 * @note APP���:\ref MSG_REG_NEW_ALARMDISPOSALADDCATEGORYID_AC_SET (356)
	 */
	ZC_MSG_APP_ALARM_DISPOSALADDCATEGORYID_AC_SET,

    /**
	 * @brief (20356)����������Ϣ���ۺϲ�ѯWITHLOCK_NEW
	 * 
	 * @note ����ṹ��:\ref P_NEW_COMPLEXCHECKWITHLOCK
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_COMPLEXCHECKWITHLOCK * N
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_JH_COMPLEXCHECKWITHLOCK_NEW (50206)
	 * @note APP���:\ref MSG_REG_NEW_JH_COMPLEXCHECKWITHLOCK_NEW (357)
	 */
	ZC_MSG_APP_ALARM_JH_COMPLEXCHECKWITHLOCK_NEW,

	/**
     * @brief (20357)���ݱ���GUID��ȡ��������������״̬
     * 
     * @note ����ṹ��:\ref P_AlarmDeviceStateByGuid
     * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_AlarmDeviceStateByGuid * N
     * @note ������Ϣֵ:\ref ZC_MSG_ALARM_ALARMDEVICESTATEINTO_NEW (50207)
     * @note APP���:\ref MSG_REG_NEW_ALARMDEVICESTATEBYGUID_SHOW (367)
     */
	ZC_MSG_APP_ALARM_ALARMDEVICESTATEINTO_NEW,

	ZC_MSG_APP_OPENDOOR_ADDREQUEST = 20400,     ///<(20400)�������ˢ����֤��¼��403��������ZC_MSG_OPENDOOR_ADDREQUEST
	ZC_MSG_APP_OPENDOOR_ADDDEALPLANINFO,        ///<(20401)�����ύԤ��ִ����Ϣ��404��������ZC_MSG_OPENDOOR_ADDDEALPLANINFO
	ZC_MSG_APP_OPENDOOR_MODIFYDEALTYPE,         ///<(20402)�����޸���֤���÷�ʽ��405��������ZC_MSG_OPENDOOR_MODIFYDEALTYPE
	ZC_MSG_APP_OPENDOOR_MODIFYREQUESTSTATE,     ///<(20403)�����޸���֤����״̬��406��������ZC_MSG_OPENDOOR_MODIFYREQUESTSTATE
	ZC_MSG_APP_OPENDOOR_SUBMITAUDITORDEALINFO,  ///<(20404)�����ύ����������˻�����Ϣ��407��������ZC_MSG_OPENDOOR_SUBMITAUDITORDEALINFO
	ZC_MSG_APP_OPENDOOR_MODIFYISCOLLECTION,     ///<(20405)�����޸���֤��¼�ղ�״̬��408��������ZC_MSG_OPENDOOR_MODIFYISCOLLECTION 

    /**
	* @brief (20406)����������֤�����¼
	*
	* Ϊ���¼��ݣ�����Ϣ�ɽ������ֲ�����һ�ֲ�����guid��һ�ֺ���guid����Ϣ������������Ϣ���ȵ��ò�ͬ��APP�ӿڡ�
	* 
	* @note ����ṹ��:\ref TAGDOA_INFO_P ���� TAGDOA_INFO_P_NEW
	* @note ���ؽṹ��:\ref TAGDOA_INFO_S
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_SUBMITDEALINFO (51156)
	* @note APP���:\ref MSG_REG_NEW_DOOROPENAPPLY_INFO_ADD (409) ���� MSG_REG_NEW_DOOROPENAPPLY_INFO_ADD_NEW��612��
	*/
	ZC_MSG_APP_OPENDOOR_SUBMITDEALINFO,         
	ZC_MSG_APP_OPENDOOR_SETUSERBASEINFO,        ///<(20407)���������û���֤������Ϣ��410��������ZC_MSG_OPENDOOR_SETUSERBASEINFO
	ZC_MSG_APP_OPENDOOR_ADDOPERAINFO,           ///<(20408)����������֤���ö�����Ϣ��411��������ZC_MSG_OPENDOOR_ADDOPERAINFO
	ZC_MSG_APP_OPENDOOR_ADDLOGINFO,             ///<(20409)����������֤ϵͳ��־��Ϣ��412��������ZC_MSG_OPENDOOR_ADDLOGINFO
	ZC_MSG_APP_OPENDOOR_ADDSUGGESTION,          ///<(20410)����������֤���������Ϣ��413��������ZC_MSG_OPENDOOR_ADDSUGGESTION
	ZC_MSG_APP_OPENDOOR_ADDEXCEPTIONINFO,       ///<(20411)����¼���쳣��֤��Ϣ��431��������ZC_MSG_OPENDOOR_ADDEXCEPTIONINFO
	
	ZC_MSG_APP_OPENDOOR_GETUSERBASEINFO,        ///<(20412)�����ȡ�û���֤������Ϣ��416��������ZC_MSG_OPENDOOR_GETUSERBASEINFO
	ZC_MSG_APP_OPENDOOR_GETALLACSHOSTINFO,      ///<(20413)�����ȡ�����Ž�������Ϣ��417��������ZC_MSG_OPENDOOR_GETALLACSHOSTINFO
	ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKINFO,     ///<(20414)�����ȡ�Ž�����������Ϣ��418��������ZC_MSG_OPENDOOR_GETACSHOSTLINKINFO
	ZC_MSG_APP_OPENDOOR_GETACSHOSTLINKTALKINFO, ///<(20415)�����ȡ�Ž����������Խ���Ϣ��419��������ZC_MSG_OPENDOOR_GETACSHOSTLINKTALKINFO
	ZC_MSG_APP_OPENDOOR_GETALLPEPOLEINFO,       ///<(20416)�����ȡ�������Ͻ�ĳ�����Ա��Ϣ��420��������ZC_MSG_OPENDOOR_GETALLPEPOLEINFO
	ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYINFO,    ///<(20417)�����ȡ��֤��ʷ��Ϣ��422��������ZC_MSG_OPENDOOR_GETAPPLYHISTORYINFO
	ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYDETAIL,  ///<(20418)�����ȡ��֤��ʷ��ϸ��Ϣ��423��������ZC_MSG_OPENDOOR_GETAPPLYHISTORYDETAIL
	ZC_MSG_APP_OPENDOOR_GETOPERAINFO,           ///<(20419)�����ȡ��֤�����б���Ϣ��424��������ZC_MSG_OPENDOOR_GETOPERAINFO
	ZC_MSG_APP_OPENDOOR_GETAPPLYPLANINFO,       ///<(20420)�����ȡԤ��ִ����Ϣ��425��������ZC_MSG_OPENDOOR_GETAPPLYPLANINFO
	ZC_MSG_APP_OPENDOOR_GETSUGGESTIONINFO,      ///<(20421)�����ȡ���������Ϣ��426��������ZC_MSG_OPENDOOR_GETSUGGESTIONINFO
	ZC_MSG_APP_OPENDOOR_GETLOGINFO,             ///<(20422)�����ȡϵͳ��־��Ϣ��427��������ZC_MSG_OPENDOOR_GETLOGINFO
	ZC_MSG_APP_OPENDOOR_GETACCESSLOGINFO,       ///<(20423)�����ȡ����ˢ����Ϣ��428��������ZC_MSG_OPENDOOR_GETACCESSLOGINFO
	
	/**
	* @brief (20424)�����ѯˢ����ʷ��Ϣ
	*
	* 2016-04-28����ʹ�ã�֮��ʹ���½ӿ� \ref ZC_MSG_APP_OPENDOOR_APPLY_BYCARDINFO_NEW��20431��
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_GETBYCARDHISTORYINFO
	* @note APP���:\ref MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFO_SHOW (429)
	*/
	ZC_MSG_APP_OPENDOOR_GETBYCARDHISTORYINFO, 
	ZC_MSG_APP_OPENDOOR_STATISTICS,             ///<(20425)����ͳ����֤��Ϣ��430��������ZC_MSG_OPENDOOR_STATISTICS
	ZC_MSG_APP_OPENDOOR_DISPOSALINFO,           ///<(20426)�����ȡ��ǰ�û���֤���Ȩ��(263)������ZC_MSG_OPENDOOR_DISPOSALINFO
	ZC_MSG_APP_OPENDOOR_ACCESSRELATION,         ///<(20427)�����ȡ�Ž��豸���ӹ�����Ϣ(433)������ZC_MSG_OPENDOOR_ACCESSRELATION
	ZC_MSG_APP_OPENDOOR_CTRLLEVELMULINFO,       ///<(20428)�����ȡ�ܿصȼ���Ϣ(402)������ZC_MSG_OPENDOOR_CTRLLEVELMULINFO
	ZC_MSG_APP_OPENDOOR_CTRLLEVELPLAN,          ///<(20429)�����ȡ�ܿز�����Ϣ��434��������ZC_MSG_OPENDOOR_CTRLLEVELPLAN
	ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO,         ///<(20430)�����ȡ������Ϣ��435��������ZC_MSG_OPENDOOR_DEPARTMENTINFO

    /**
	* @brief (20431)�����ѯˢ����ʷ��Ϣ
	*
	* 2016-04-28����ʹ�ã�֮��ʹ���½ӿ� /ref ZC_MSG_APP_OPENDOOR_APPLY_BYCARDINFO_NEW��20431��
	*
	* @note ����ṹ��:\ref TAGDOABYCARDINFO_NEW_P 
	* @note ���ؽṹ��:\ref TAGDOABYCARDINFO_NEW_S
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_APPLY_BYCARDINFO_NEW
	* @note APP���:\ref MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFO_SHOW_NEW (450)
	*/
	ZC_MSG_APP_OPENDOOR_APPLY_BYCARDINFO_NEW,

    /**
	* @brief (20432)�����ȡ�û��Ž�����ͷ������Ϣ
	*
	* @note ����ṹ��:\ref NULL
	* @note ���ؽṹ��:\ref USERDOORCAMERARELATION_CLIENT_GET_S
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_USERDOORCAMERARELATION
	* @note APP���:\ref MSG_REG_NEW_USERDOORCAMERARELATION_CLIENT_GET (451)
	*/
	ZC_MSG_APP_OPENDOOR_USERDOORCAMERARELATION,   

	/**
	* @brief (20433)�����ȡ��֤��ʷ��Ϣ���Ƿ�����������
	*
	* @note ����ṹ��:\ref TAGDOAHISTORYINFOWITHLOCK_P
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref TAGDOAHISTORYINFO_S * N
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_GETAPPLYHISTORYLOCKINFO
	* @note APP���:\ref MSG_REG_NEW_DOOROPENAPPLY_HISTORYINFOWITHLOCK (296)
	*/
	ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYLOCKINFO,  

	/**
	* @brief (20434)����������Ա��Ϣ
	*
	* @note ����ṹ��:\ref STAFFINFOOPERATION_P
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_STAFFINFOOPERATION
	* @note APP���:\ref MSG_REG_NEW_STAFFINFOOPERATION (453)
	*/
	ZC_MSG_APP_OPENDOOR_STAFFINFOOPERATION, 

    /**
	* @brief (20435)�������ò�����Ϣ
	*
	* @note ����ṹ��:\ref DEPARTMENTINFOOPERATION_P
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_DEPARTMENTINFOOPERATION
	* @note APP���:\ref MSG_REG_NEW_DEPARTMENTINFOOPERATION (454)
	*/
	ZC_MSG_APP_OPENDOOR_DEPARTMENTINFOOPERATION, 

    /**
	* @brief (20436)����������Ա״̬
	*
	* @note ����ṹ��:\ref STAFFSTATUS_SET_P
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_STAFFSTATUS_SET
	* @note APP���:\ref MSG_REG_NEW_STAFFSTATUS_SET (455)
	*/
	ZC_MSG_APP_OPENDOOR_STAFFSTATUS_SET, 

    /**
	* @brief (20437)�����ȡ������Ϣ
	*
	* @note ����ṹ��:\ref DEPARTMENTINFO_GET_P
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DEPARTMENTINFO_GET_S * N
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_DEPARTMENTINFO_GET
	* @note APP���:\ref MSG_REG_NEW_DEPARTMENTINFO_GET (456)
	*/
	ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO_GET, 

    /**
	* @brief (20438)�����ȡȨ������Ϣ
	*
	* @note ����ṹ��: NULL
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref AUTHGROUP_GET_S * N
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_AUTHGROUP_GET
	* @note APP���:\ref MSG_REG_NEW_AUTHGROUP_GET (457)
	*/
	ZC_MSG_APP_OPENDOOR_AUTHGROUP_GET, 

    /**
	* @brief (20439)�����ȡ��Ա��Ϣ
	*
	* @note ����ṹ��:\ref STAFFINFO_GET_P
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref STAFFINFO_GET_S * N
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_STAFFINFO_GET
	* @note APP���:\ref MSG_REG_NEW_STAFFINFO_GET (458)
	*/
	ZC_MSG_APP_OPENDOOR_STAFFINFO_GET, 

    /**
	* @brief (20440)�����ȡ��Ա������Ϣ
	*
	* @note ����ṹ��:\ref STAFFOPERATION_GET_P
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref STAFFOPERATION_GET_S * N
	*
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_STAFFOPERATION_GET (51190)
	* @note APP���:\ref MSG_REG_NEW_STAFFOPERATION_GET (459)
	*/
	ZC_MSG_APP_OPENDOOR_STAFFOPERATION_GET, 

	/**
	 * @brief (20441)�����ȡ��ԱȨ����
	 *
	 * @note ����ṹ��:\ref STAFFAUTHINFO_GET_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref STAFFAUTHINFO_GET_S * N
	 *
	 * @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_STAFFAUTHINFO_GET (51191)
	 * @note APP���:\ref MSG_REG_NEW_STAFFAUTHINFO_GET (461)
	 */
	ZC_MSG_APP_OPENDOOR_STAFFAUTHINFO_GET, 

    /**
	 * @brief (20442)���������֤��Ѻ��Ϣ
	 *
	 * @note ����ṹ��:\ref DOOROPENSYRELATION_SET_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 *
	 * @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_DOOROPENSYRELATION_SET (51192)
	 * @note APP���:\ref MSG_REG_NEW_DOOROPENSYRELATION_SET (464)
	 */
	ZC_MSG_APP_OPENDOOR_DOOROPENSYRELATION_SET,

    /**
	 * @brief (20443)�����ȡ�Ž�������Ѻ�豸
	 *
	 * @note ����ṹ��:\ref ACCESSSYRELATION_GET_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref ACCESSSYRELATION_GET_S * N
	 *
	 * @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_ACCESSSYRELATION_GET (51193)
	 * @note APP���:\ref MSG_REG_NEW_ACCESSSYRELATION_GET (465)
	 */
	ZC_MSG_APP_OPENDOOR_ACCESSSYRELATION_GET,

    /**
	 * @brief (20444)�����ȡ��֤��Ѻ������Ϣ
	 *
	 * @note ����ṹ��:\ref DOOROPENSYRELATION_GET_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DOOROPENSYRELATION_GET_S * N
	 *
	 * @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_DOOROPENSYRELATION_GET (51194)
	 * @note APP���:\ref MSG_REG_NEW_DOOROPENSYRELATION_GET (466)
	 */
	ZC_MSG_APP_OPENDOOR_DOOROPENSYRELATION_GET,

	/**
	 * @brief (20445)�����ѯ��֤��ʷ��Ϣ���ɰ���֤���Ͳ�ѯ��
	 *
	 * @note ����ṹ��:\ref QUERYHISTORYINFO_SY_GET_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref QUERYHISTORYINFO_SY_GET_S * N
	 *
	 * @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_QUERYHISTORYINFO_SY_GET (51195)
	 * @note APP���:\ref MSG_REG_NEW_QUERYHISTORYINFO_SY_GET (467)
	 */
	ZC_MSG_APP_OPENDOOR_QUERYHISTORYINFO_SY_GET,

    /**
	* @brief (20500)�����ȡ��ǰ�û�������ά���Ȩ����Ϣ
	* 
	* @note ����ṹ��: NULL 
	* @note ���ؽṹ��:\ref T_SYSDORCTORPOSALINFO
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DISPOSALINFO (52000)
	* @note APP���:\ref MSG_REG_NEW_ALARMDISPOSAL_AUTH_SHOW (1302) \ref P_NEW_ALARMDISPOSAL_AUTH_SHOW \ref S_NEW_ALARMDISPOSAL_AUTH_SHOW
	*/
	ZC_MSG_APP_SYSDORCTOR_DISPOSALINFO = 20500,       
	
	/**
	* @brief (20510)�����ȡƽ̨������Ϣ
	* 
	* ƽ̨������Ϣ��Ϣ���������洦���ýӿڷ���APP��ȡ�������������������ݣ�����1�����Լ����ݡ�
	* 
	* @note ����ṹ��: NULL 
	* @note ���ؽṹ��:\ref CMS_INFO
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_CMSINFO (52010)
	* @note APP���:\ref MSG_REQ_NEW_SHOW_CMSNODE_INFO \ref P_CMSInfo \ref S_CMSInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_CMSINFO = 20510,

	/**
	* @brief (20511)�����ȡƽ̨������Ϣ
	* 
	* �ýӿڷ���ƽ̨����������Ϣ���������û�������ɸѡ��������Ϣ��ѯ��ʱ���δ����������û�ɸѡ��������Ŀǰ��������άģ����ʹ�øýӿڣ����ݲ������洦���ýӿڷ���APP��ȡ�����������ݣ��պ�������Ч�����⣬���Ƕ����Ż�����4�����Լ����ݡ�
	* 
	* @note ����ṹ��: NULL 
	* @note ���ؽṹ��:\ref AREA_NODE_INFO
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_AREAINFO (52011)
	* @note APP���:\ref MSG_REQ_NEW_SHOW_ALLAREANODE_INFO \ref P_AreaInfo \ref S_AreaNodeInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_AREAINFO,   

	/**
	* @brief (20512)�����ȡƽ̨������Ϣ
	* 
	* ����Ŀǰ��������άģ����ʹ�øýӿڣ����ݲ������洦���ýӿڷ���APP��ȡ�����������ݣ��պ�������Ч�����⣬���Ƕ����Ż�����5�����Լ����ݡ�
	* 
	* @note ����ṹ��: NULL 
	* @note ���ؽṹ��:\ref DEV_NODE_INFO
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVINFO (52012)
	* @note APP���:\ref MSG_REQ_NEW_SHOW_DEVNODE_INFO \ref S_DevNodeInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVINFO,

	/**
	* @brief (20513)�����ȡƽ̨̽ͷ��Ϣ
	* 
	* ����Ŀǰ��������άģ����ʹ�øýӿڣ����ݲ������洦���ýӿڷ���APP��ȡ�����������ݣ��պ�������Ч�����⣬���Ƕ����Ż�����5�����Լ����ݡ�
	* 
	* @note ����ṹ��: NULL 
	* @note ���ؽṹ��:\ref CAMERA_NODE_INFO
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_CAMERAINFO (52013)
	* @note APP���:\ref MSG_REQ_NEW_SHOW_FRONTNODE_INFO \ref S_FrontendNodeInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_CAMERAINFO,  

	/**
	* @brief (20514)�����ȡƽ̨������Ϣ(�����ʲ����)
	* 
	* ����Ŀǰ��������άģ����ʹ�øýӿڣ����ݲ������洦���ýӿڷ���APP��ȡ�����������ݣ�
	* 
	* @note ����ṹ��: NULL 
	* @note ���ؽṹ��:\ref DEVICEINFOWITHCAPITAL_GET_S
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVINFO_EX (52014)
	* @note APP���:\ref MSG_REG_NEW_DEVICEINFOWITHCAPITAL_GET ��545��
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVINFO_EX,

	/**
	* @brief (20515)�����ȡƽ̨̽ͷ��Ϣ(�����ʲ����)
	* 
	* ����Ŀǰ��������άģ����ʹ�øýӿڣ����ݲ������洦���ýӿڷ���APP��ȡ�����������ݣ�
	* 
	* @note ����ṹ��: NULL 
	* @note ���ؽṹ��:\ref FRONTENDNODEINFOWITHCAPITAL_GET_S
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_CAMERAINFO_EX (52015)
	* @note APP���:\ref MSG_REG_NEW_FRONTENDNODEINFOWITHCAPITAL_GET ��546��
	*/
	ZC_MSG_APP_SYSDORCTOR_CAMERAINFO_EX,  

    /**
	* @brief (20519)�����ȡ�����豸Ʒ����Ϣ(ֻ�����ʲ���Ϣ�д��ڵ�)
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ�����������ݣ�����2�����Լ����ݡ�
	* 
	* @note ����ṹ��:\ref DEVICEMANUFACTUREINFOINCAPITALGET_S 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DEVICEMANUFACTUREINFOGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MANUFACTUREINFOINCAPITAL (52019)
	* @note APP���:\ref MSG_REG_NEW_DEVICEMANUFACTUREINFOINCAPITAL_GET��544��
	*/
	ZC_MSG_APP_SYSDORCTOR_MANUFACTUREINFOINCAPITAL = 20519,

	/**
	* @brief (20520)�����ȡ�����豸Ʒ����Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ�����������ݣ�����2�����Լ����ݡ�
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DEVICEMANUFACTUREINFOGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MANUFACTURENAME (52020)
	* @note APP���:\ref MSG_REG_NEW_DEVICEMANUFACTUREINFO_GET��509��
	*/
	ZC_MSG_APP_SYSDORCTOR_MANUFACTURENAME = 20520,  
	
	/**
	* @brief (20521)�����ȡ�豸�ͺ���Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ�����������ݣ�����2�����Լ����ݡ�
	* 
	* @note ����ṹ��:\ref DEVICEMODELINFOGET_IN_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DEVICEMODELINFOGET_OUT_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MODELNO (52021)
	* @note APP���:\ref MSG_REG_NEW_DEVICEMODELINFO_GET��510��
	*/
	ZC_MSG_APP_SYSDORCTOR_MODELNO,      

	/**
	* @brief (20522)�����ȡ���й�Ӧ����Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ�����������ݣ�����2�����Լ����ݡ�
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref SUPPLIERINFOGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_SUPPLIERCOMPANY��52022��
	* @note APP���:\ref MSG_REG_NEW_SUPPLIERINFO_GET��511��
	*/
	ZC_MSG_APP_SYSDORCTOR_SUPPLIERCOMPANY, 

	/**
	* @brief (20523)�����ȡ����ά������Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ�����������ݣ�����2�����Լ����ݡ�
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref MAINTENCECOMPANYGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MAINTENCECOMPANY��52023��
	* @note APP���:\ref MSG_REG_NEW_MAINTENCECOMPANY_GET��512��
	*/
	ZC_MSG_APP_SYSDORCTOR_MAINTENCECOMPANY, 

	/**
	* @brief (20524)�����ȡ����ά���̵绰��Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ�����������ݣ�����2�����Լ����ݡ�
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref MAINTENCEINFOPHONE_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MAINTENCEPHONE��52024��
	* @note APP���:\ref MSG_REG_NEW_MAINTENCEINFO_PHONE_GET��518��
	*/
	ZC_MSG_APP_SYSDORCTOR_MAINTENCEPHONE,      
	
	/**
	* @brief (20525)�����ȡ���й�������Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ�����������ݣ�����2�����Լ����ݡ�
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref ENGINEERINGINFOGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_ENGINEERINGNAME��52025��
	* @note APP���:\ref MSG_REG_NEW_ENGINEERINGINFO_GET��513��
	*/
	ZC_MSG_APP_SYSDORCTOR_ENGINEERINGNAME,
	
	/**
	* @brief (20526)�����ȡ���б���������Ϣ
	* 
	* ��Ϣ����ͨ��APPʵʱ��ѯ������ƽ̨�����б���������Ϣ
	* 
	* @note ����ṹ��:\ref NULL 
	*       ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref P_AlarmPartionInfo *N
	*       ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_ALARMHOSTINFO��52026��
	*       APP���:\ref MSG_REQ_NEW_ALARMPARTION��1161��\ref P_AlarmPartionInfo \ref S_AlarmPartionInfo
	*/
	ZC_MSG_APP_SYSDORCTOR_ALARMHOSTINFO,

	/**
	* @brief (20527)�����ȡ���б��������������ƻ���Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref ALARMARMDISARMPLAN_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_ALARMARMDISARMPLAN��52027��
	* @note APP���:\ref MSG_REG_NEW_ALARMARMDISARMPLAN_GET��519��
	*/
    ZC_MSG_APP_SYSDORCTOR_ALARMARMDISARMPLAN,

	/**
	* @brief (20528)�����ȡ��������ʹ��״̬��Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref HOSTUSESTATUSGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_HOSTUSESTATUS��52028��
	* @note APP���:\ref MSG_REG_NEW_HOSTUSESTATUS_GET��522��
	*/
    ZC_MSG_APP_SYSDORCTOR_HOSTUSESTATUS,
	
	/**
	* @brief (20529)�����ȡ����̽ͷʹ��״̬��Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DETECTORUSESTATUSGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DETECTORUSESTATUS��52029��
	* @note APP���:\ref MSG_REG_NEW_DETECTORUSESTATUS_GET��523��
	*/
	ZC_MSG_APP_SYSDORCTOR_DETECTORUSESTATUS,

	/**
	* @brief (20530)�����ѯ�豸�����ʲ���Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref DEVICEBASEINFOGET_IN_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DEVICEBASEINFOGET_OUT_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVCAPITALINFO��52030��
	* @note APP���:\ref MSG_REG_NEW_DEVICEBASEINFO_GET��514��
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVCAPITALINFO = 20530,  
	
	/**
	* @brief (20531)�����޸��豸�����ʲ���Ϣ
	* 
	* ��Ϣ���������Ϣ�������жϣ����ݲ����������ȷ�������ʱֱ�ӵ���APP�ӿڽ��������ύ�������ڲ������ݣ�
	* 
	* @note ����ṹ��:\ref CAPITALINFOOPERATION_P 
	*       ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	*       ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_SETDEVCAPITALINFO��52031��
	*       APP���:\ref MSG_REG_NEW_CAPITALINFO_OPERATION��500��\ref CAPITALINFOOPERATION_P
	*/
	ZC_MSG_APP_SYSDORCTOR_SETDEVCAPITALINFO,  

	/**
	* @brief (20532)����ͳ���豸�����ʲ���Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref CAPITALINFOSTATISTICS_IN_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref CAPITALINFOSTATISTICS_OUT_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_STATDEVCAPITALINFO��52032��
	* @note APP���:\ref MSG_REG_NEW_CAPITALINFO_STATISTICS��520��
	*/
	ZC_MSG_APP_SYSDORCTOR_STATDEVCAPITALINFO,   

    /**
	* @brief (20533)�����ȡͨ��¼��ģ��������Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref OMRECORDDAYSMODULEGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_OMRECORDDAYSMODULE��52033��
	* @note APP���:\ref MSG_REG_NEW_OMRECORDDAYSMODULE_GET��533��
	*/
	ZC_MSG_APP_SYSDORCTOR_OMRECORDDAYSMODULE,

    /**
	* @brief (20534)�����ȡͨ��¼��ģ���Ƿ�������Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DETECTMODULEINFOGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DETECTMODULEINFO��52034��
	* @note APP���:\ref MSG_REG_NEW_DETECTMODULEINFO_GET��538��
	*/
	ZC_MSG_APP_SYSDORCTOR_DETECTMODULEINFO,

    /**
	* @brief (20535)�������¼������ģ��ID��ȡ��������ͷ��Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref SOFTSETCHANNELRECORDDAYSGET_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref SOFTSETCHANNELRECORDDAYSGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_SOFTSETCHANNELRECORDDAYS��52035��
	* @note APP���:\ref MSG_REG_NEW_SOFTSETCHANNELRECORDDAYS_GET��542��
	*/
	ZC_MSG_APP_SYSDORCTOR_SOFTSETCHANNELRECORDDAYS,

    /**
	 * @brief (20536)�����ȡһ����ά��Ϣ
	 * 
	 * ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref NULL 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_GetIOMOperationInfo *N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_IOMOPERATIONINFO��52036��
	 * @note APP���:\ref MSG_REG_NEW_IOMOPERATIONINFO_GET��547��
	 */
	ZC_MSG_APP_SYSDORCTOR_IOMOPERATIONINFO,

	/**
	* @brief (20540)�����ȡ���й���������Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref NULL 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref FAULTNAMEGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_FAULTINFO��52040��
	* @note APP���:\ref MSG_REG_NEW_FAULTNAME_GET��516��
	*/
	ZC_MSG_APP_SYSDORCTOR_FAULTINFO = 20540,       

	/**
	* @brief (20541)�����ѯ���޼�¼��Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref MALFUNCTIONINFOGET_IN_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref MALFUNCTIONINFOGET_OUT_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO��52041��
	* @note APP���:\ref MSG_REG_NEW_MALFUNCTIONINFO_GET��515��
	*/
	ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO,  

	/**
	* @brief (20542)�����ȡά�޼�¼��Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref MAINTENCEINFOIN_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref MAINTENCEINFOGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MAINTENCEINFO��52042��
	* @note APP���:\ref MSG_REG_NEW_MAINTENCEINFO_GET��517��
	*/
	ZC_MSG_APP_SYSDORCTOR_MAINTENCEINFO, 
	
	/**
	* @brief (20543)�����������޼�¼��Ϣ
	* 
	* ��Ϣ���������Ϣ�������жϣ����ݲ����������ȷ�������ʱֱ�ӵ���APP�ӿڽ��������ύ�������ڲ������ݣ�
	* 
	* @note ����ṹ��:\ref MALFUNCTIONINSERT_P 
	*       ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	*       ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_ADDMALFUNCTIONINFO��52043��
	*       APP���:\ref MSG_REG_NEW_MALFUNCTION_INSERT��502��\ref MALFUNCTIONINSERT_P
	*/
	ZC_MSG_APP_SYSDORCTOR_ADDMALFUNCTIONINFO, 

	/**
	* @brief (20544)��������ά�޼�¼��Ϣ
	* 
	* ��Ϣ���������Ϣ�������жϣ����ݲ����������ȷ�������ʱֱ�ӵ���APP�ӿڽ��������ύ�������ڲ������ݣ�
	* 
	* @note ����ṹ��:\ref MAINTENCEINFOINSERT_P 
	*       ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	*       ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_ADDMAINTENCEINFO��52044��
	*       APP���:\ref MSG_REG_NEW_MAINTENCEINFO_INSERT��503��\ref MAINTENCEINFOINSERT_P
	*/
	ZC_MSG_APP_SYSDORCTOR_ADDMAINTENCEINFO,   

	/**
	* @brief (20545)����ͳ�Ʊ��޼�¼��Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref MALFUNCTIONINFOSTATISTICS_IN_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref MALFUNCTIONINFOSTATISTICS_OUT_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_STATMALFUNCTIONINFO��52045��
	* @note APP���:\ref MSG_REG_NEW_MALFUNCTIONINFO_STATISTICS��521��
	*/
	ZC_MSG_APP_SYSDORCTOR_STATMALFUNCTIONINFO,  

	/**
	* @brief (20546)�����豸��������豸������Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref DEVICEBASEINFOBYIDGET_SOFTSET_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DEVICEBASEINFOBYIDGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVICEBASEINFOBYID��52046��
	* @note APP���:\ref MSG_REG_NEW_DEVICEBASEINFOBYID_CLIENT_GET��526��
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOBYID,

    /**
	* @brief (20547)�����豸�ʲ���������豸������Ϣ
	* 
	* ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	* 
	* @note ����ṹ��:\ref DEVICEBASEINFOBYIDGET_CLIENT_P 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DEVICEBASEINFOBYIDGET_S *N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVICEBASEINFOBYCAPITALCODE��52047��
	* @note APP���:\ref MSG_REG_NEW_DEVICEBASEINFOBYID_CLIENT_GET��526��
	*/
	ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOBYCAPITALCODE,

	/**
	 * @brief (20548)��ȡ�豸������Ϣ_NEW
	 * 
	 * ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref DEVICEBASEINFOGET_NEW_IN_P
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DEVICEBASEINFOGET_NEW_OUT_S *N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVICEBASEINFOGET_NEW��52048��
	 * @note APP���:\ref MSG_REG_NEW_DEVICEBASEINFO_GET_NEW��550��
	 */
	ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOGET_NEW,

	/**
	 * @brief (20549)���޼�¼��Ϣ��ѯ_NEW
	 * 
	 * ��Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref MALFUNCTIONINFOGET_NEW_IN_P 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref MALFUNCTIONINFOGET_NEW_OUT_S *N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO_GET_NEW��52049��
	 * @note APP���:\ref MSG_REG_NEW_MALFUNCTIONINFO_GET_NEW��551��
	 */
	ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO_GET_NEW,

    /**
	 * @brief (20550)ͨ�����ģ����ز���
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_CHANNELDETECTMODULEOPERATION_NEW 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_CHANNELDETECTMODULE_OPERATION_NEW ��52083��
	 * @note APP���:\ref MSG_REG_NEW_CHANNELDETECTMODULE_OPERATION_NEW��563��
	 */
    ZC_MSG_APP_SYSDORCTOR_CHANNELDETECTMODULE_OPERATION_NEW,

    /**
	 * @brief (20551)������ά��ȡ¼������ģ��
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref NULL 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_OMRECORDDAYSMODULEGET_NEW * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_OMRECORDDAYSMODULE_GET_NEW ��52084��
	 * @note APP���:\ref MSG_REG_NEW_OMRECORDDAYSMODULE_GET_NEW��564��
	 */
    ZC_MSG_APP_SYSDORCTOR_OMRECORDDAYSMODULE_GET_NEW,

    /**
	 * @brief (20552)���޹����������ȡ
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_MalfuctionInfoGet 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_MalfuctionInfoGet * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MALFUNCTION_NEW_GET ��52085��
	 * @note APP���:\ref MSG_REG_NEW_MALFUNCTION_NEW_GET��565��
	 */
    ZC_MSG_APP_SYSDORCTOR_MALFUNCTION_NEW_GET,

	/**
	 * @brief (20553)������ά���ϴ����¼
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_FaultTreatment 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_FaultTreatment * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_FAULTTREATMENT_GET ��52086��
	 * @note APP���:\ref MSG_REG_NEW_FAULTTREATMENT_GET��566��
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTTREATMENT_GET,

    /**
	 * @brief (20554)������άά�޼�¼
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_MaintenanceRecord 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_MaintenanceRecord * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MAINTENANCERECORD_GET ��52087��
	 * @note APP���:\ref MSG_REG_NEW_MAINTENANCERECORD_GET��567��
	 */
    ZC_MSG_APP_SYSDORCTOR_MAINTENANCERECORD_GET,

    /**
	 * @brief (20555)������ά���������ۼ�¼
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_ReviewAndEvaluation 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_ReviewAndEvaluation * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_REVIEWANDEVALUTION_GET ��52088��
	 * @note APP���:\ref MSG_REG_NEW_REVIEWANDEVALUTION_GET��568��
	 */
    ZC_MSG_APP_SYSDORCTOR_REVIEWANDEVALUTION_GET,

    /**
	 * @brief (20556)������ά���ϼ�¼д��
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_FaultDeviceInfoIns 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_FAULTDEVICEINFO_ADD ��52089��
	 * @note APP���:\ref MSG_REG_NEW_FAULTDEVICEINFO_ADD��569��
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTDEVICEINFO_ADD,

    /**
	 * @brief (20557)������ά���ϴ����¼д��
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_FaultDeviceHandleInfoIns 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_FAULTDEVICEHANDLEINFO_ADD ��52090��
	 * @note APP���:\ref MSG_REG_NEW_FAULTDEVICEHANDLEINFO_ADD��570��
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTDEVICEHANDLEINFO_ADD,

	/**
	 * @brief (20558)������ά���޼�¼д��
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_MalfuctionInfo_Ins 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO_ADD ��52091��
	 * @note APP���:\ref MSG_REG_NEW_MALFUNCTIONINFO_ADD��571��
	 */
    ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO_ADD,

	/**
	 * @brief (20559)������άά�޼�¼д��
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_MaintenanceInfo_Ins 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MAINTENCEINFO_ADD ��52092��
	 * @note APP���:\ref MSG_REG_NEW_MAINTENCEINFO_ADD��572��
	 */
    ZC_MSG_APP_SYSDORCTOR_MAINTENCEINFO_ADD,

    /**
	 * @brief (20560)������ά���˼�¼д��
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_CheckInfo_Ins 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_CHECKINFO_ADD ��52093��
	 * @note APP���:\ref MSG_REG_NEW_CHECKINFO_ADD��573��
	 */
    ZC_MSG_APP_SYSDORCTOR_CHECKINFO_ADD,

	/**
	 * @brief (20561)�豸��ʷ���ϼ���
	 * 
	 * 20170601�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_DeviceFaultGet 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_DeviceHistoryFaultGet
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVICEFAULTINFO_SET ��52094��
	 * @note APP���:\ref MSG_REG_NEW_DEVICEFAULTINFO_SET��574��
	 */
    ZC_MSG_APP_SYSDORCTOR_DEVICEFAULTINFO_SET,

    /**
	 * @brief (20562)��ȡ�����쳣����
	 * 
	 * 20170607�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_FaultExtremelyInfoGet 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_FaultExtremelyInfoGet
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_NEW_FAULTEXTREMELYINFO_GET ��52095��
	 * @note APP���:\ref MSG_REG_NEW_FAULTEXTREMELYINFO_GET��575��
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_FAULTEXTREMELYINFO_GET,

	/**
	 * @brief (20563)IOM���־���������͹��ϼ�¼д��
	 * 
	 * 20170607�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_FaultDeviceInfoAdditionalIns 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_NEWFAULTDEVICEADDITIONAL_ADD ��52096��
	 * @note APP���:\ref MSG_REG_NEWFAULTDEVICEADDITIONAL_ADD��576��
	 */
    ZC_MSG_APP_SYSDORCTOR_NEWFAULTDEVICEADDITIONAL_ADD,

	/**
	 * @brief (20564)������Ϣ����
	 * 
	 * 20170609�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_SupplierMaintenanceOperation 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_NEW_SUPPLIERMAINTENANCE_OPERATION ��52097��
	 * @note APP���:\ref MSG_REG_NEW_SUPPLIERMAINTENANCE_OPERATION��559��
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_SUPPLIERMAINTENANCE_OPERATION,

	/**
	 * @brief (20565)������Ϣ��ȡ
	 * 
	 * 20170609�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_SupplierMaintenanceInfo 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_SupplierMaintenanceInfo * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_NEW_SUPPLIERMAINTENANCEINFO_GET ��52098��
	 * @note APP���:\ref MSG_REG_NEW_SUPPLIERMAINTENANCEINFO_GET��560��
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_SUPPLIERMAINTENANCEINFO_GET,

    /**
	 * @brief (20566)�ʲ���Ϣ����
	 * 
	 * 20170609�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_CapticalInfoNewOperation 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_NEW_CAPTICALINFONEW_OPERATION ��52099��
	 * @note APP���:\ref MSG_REG_NEW_CAPTICALINFONEW_OPERATION��561��
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_CAPTICALINFONEW_OPERATION,

    /**
	 * @brief (20567)�ʲ���Ϣ��ȡ
	 * 
	 * 20170609�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_CapticalInfoNewGet 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_CapticalInfoNewGet * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_NEW_CAPTICALINFO_NEW_GET ��52100��
	 * @note APP���:\ref MSG_REG_NEW_CAPTICALINFO_NEW_GET��562��
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_CAPTICALINFO_NEW_GET,

	/**
	 * @brief (20568)��ȡѲ��ƻ�
	 * 
	 * 20170614�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref NULL 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref DETECTSCHEDULEGET_S * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_NEW_DETECTSCHEDULE_GET ��52101��
	 * @note APP���:\ref MSG_REG_NEW_DETECTSCHEDULE_GET��524��
	 */
    ZC_MSG_APP_SYSDORCTOR_NEW_DETECTSCHEDULE_GET,

	/**
	 * @brief (20569)�ʲ�״̬ͳ��_Additional
	 * 
	 * 20170620�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_CapticalAdditionalInfoGet 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_CapticalAdditionalInfoGet * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_CAPTICALADDITIONALINFO_GET ��52102��
	 * @note APP���:\ref MSG_REG_CAPTICALADDITIONALINFO_GET��579��
	 */
    ZC_MSG_APP_SYSDORCTOR_CAPTICALADDITIONALINFO_GET,

	/**
	 * @brief (20570)�ʲ�״̬ͳ��
	 * 
	 * 20170620�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_CapticalStatisticsInfoGet 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_CapticalStatisticsInfoGet * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_CAPTICALSTATISTICSINFO_GET ��52103��
	 * @note APP���:\ref MSG_REG_CAPTICALSTATISTICSINFO_GET��580��
	 */
    ZC_MSG_APP_SYSDORCTOR_CAPTICALSTATISTICSINFO_GET,

	/**
	 * @brief (20571)����ͳ��
	 * 
	 * 20170620�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_FaultTypeStatisticsInfoGet 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_FaultTypeStatisticsInfoGet * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_FAULTSTATISTICSINFO_GET ��52104��
	 * @note APP���:\ref MSG_REG_FAULTSTATISTICSINFO_GET��581��
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTSTATISTICSINFO_GET,

	/**
	 * @brief (20572)ά������ͳ��
	 * 
	 * 20170620�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_MaintenanceStatisticsInfoGet 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_MaintenanceStatisticsInfoGet * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_MAINTENANCESTATISTICSINFO_GET ��52105��
	 * @note APP���:\ref MSG_REG_MAINTENANCESTATISTICSINFO_GET��582��
	 */
    ZC_MSG_APP_SYSDORCTOR_MAINTENANCESTATISTICSINFO_GET,

	/**
	 * @brief (20573)�����쳣�ʲ�ͳ��
	 * 
	 * 20170719�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_GetCapticalAreaExceptionInfo 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_GetCapticalAreaExceptionInfo * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_CAPTICALAREAEXCEPTIONINFO_GET ��52106��
	 * @note APP���:\ref MSG_REG_GETCAPTICALAREAEXCEPTIONINFO_GET��583��
	 */
    ZC_MSG_APP_SYSDORCTOR_CAPTICALAREAEXCEPTIONINFO_GET,

	/**
	 * @brief (20574)IOM�������޴���
	 * 
	 * 20170725�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_BatchMalfunctionInfo 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_BATCHMALFUNCTIONINFO_SET ��52107��
	 * @note APP���:\ref MSG_REG_BATCHMALFUNCTIONINFO_SET��584��
	 */
    ZC_MSG_APP_SYSDORCTOR_BATCHMALFUNCTIONINFO_SET,

	/**
	 * @brief (20575)�����豸��Ϣ��ȡ����ID
	 * 
	 * 20170815�����ӿڣ���Ϣ���������洦���ýӿڷ���APP��ȡ������������
	 * 
	 * @note ����ṹ��:\ref P_GetFaultIdByDeviceDetailInfo 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_GetFaultIdByDeviceDetailInfo * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_FAULTIDBYDEVICEDETAILINFO_GET ��52108��
	 * @note APP���:\ref MSG_REG_FAULTIDBYDEVICEDETAILINFO_GET��585��
	 */
    ZC_MSG_APP_SYSDORCTOR_FAULTIDBYDEVICEDETAILINFO_GET,

	ZC_MSG_APP_ROLEINFO = 29000,        ///<(29000)����ϵͳ�н�ɫ��Ϣ������ZC_MSG_COMMON_ROLEINFO
	ZC_MSG_APP_CHILDROLEINFO,           ///<(29001)�����ȡĳ��ɫ��������ɫ��Ϣ������ZC_MSG_COMMON_CHILDROLEINFO
	ZC_MSG_APP_PLANINFO,                ///<(29002)����Ԥ������Ϣ������ZC_MSG_COMMON_PLANINFO 
	ZC_MSG_APP_USERIMAGEID,             ///<(29003)�����ȡĳ�û�ͷ����Ϣ��1��������ZC_MSG_COMMON_USERIMAGEID
	ZC_MSG_APP_CURUSERINFOEX,           ///<(29004)�����ȡ��ǰ�û���Ϣ������ZC_MSG_COMMON_CURUSERINFOEX
	ZC_MSG_APP_ALLUSERINFO,             ///<(29005)���������û���Ϣ������ZC_MSG_COMMON_ALLUSERINFO
	ZC_MSG_APP_USERSTATE,               ///<(29006)�����ȡ�û�״̬������ZC_MSG_COMMON_USERSTATE 
	ZC_MSG_APP_USERALLINFO,             ///<(29007)�����ȡĳ�û���ϸ��Ϣ������ZC_MSG_COMMON_USERALLINFO
	ZC_MSG_APP_ALLSUBORDINATEINFO,      ///<(29008)�����ȡ�û�����������Ϣ������ZC_MSG_COMMON_ALLSUBORDINATEINFO
    ZC_MSG_APP_CLASSMONITOR,            ///<(29009)�����ȡ�û�ͬһ����ϼ���ɫ��Ϣ������ZC_MSG_COMMMON_CLASSMONITOR
	ZC_MSG_APP_USERMONITOR,             ///<(29010)�����ȡ�û��ϼ���ɫ��Ϣ������ZC_MSG_COMMON_USERMONITOR
	ZC_MSG_APP_ALLCLASSSUBORDINATEINFO, ///<(29011)�����ȡ�û�ͬһ�������������Ϣ������ZC_MSG_COMMON_ALLCLASSSUBORDINATEINFO
    ZC_MSG_APP_EVENTINFO,               ///<(29012)�����ȡ�¼�����Ϣ������ZC_MSG_COMMON_EVENTINFO	
	
	ZC_MSG_APP_ALLAREAINFO = 29050,     ///<(29050)��������������Ϣ������ZC_MSG_COMMON_ALLAREAINFO
	ZC_MSG_APP_ALLALARMTYPEINFO,        ///<(29051)�������б���������Ϣ������ZC_MSG_COMMON_ALLALARMTYPEINFO 
	ZC_MSG_APP_ALLALARMLEVELINFO,       ///<(29052)�������б����ȼ���Ϣ������ZC_MSG_COMMON_ALLALARMLEVELINFO
	ZC_MSG_APP_ALLALARMDEALSTATEINFO,   ///<(29053)���󱨾�����״̬������Ϣ������ZC_MSG_COMMON_ALLALARMDEALSTATEINFO
	ZC_MSG_APP_ALARMDEALTYPE,           ///<(29054)�������б����������ͣ�����ZC_MSG_COMMON_ALARMDEALTYPE
	ZC_MSG_APP_ALARMDECIDETYPE,         ///<(29055)�������б������Դ����ͣ�����ZC_MSG_COMMON_ALARMDECIDETYPE
	ZC_MSG_APP_ALLKEYPARTINFO,          ///<(29056)�������в�λ��Ϣ������ZC_MSG_COMMON_ALLKEYPARTINFO
    ZC_MSG_APP_ALLDEVICEINFO,           ///<(29057)��������������ϸ��Ϣ������ZC_MSG_COMMON_ALLDEVICEINFO
	            
	ZC_MSG_APP_DUTYSTATUSSET = 29100,     ///<(29100)���������û�״̬������ZC_MSG_COMMON_SETDUTYSTATUS
}E_ZC_MSG_APP;
/** @} */

/** @defgroup ZCBCBMsgTypeDefine BCB�ͻ���ģ����Ӧ��Ϣ����ö��    
 * ����BCB�ͻ���ģ����Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
    ZC_MSG_BCBCLIENT_CURUSER    = 30000,     ///<(30000)����ǰ�û���Ϣ������ZC_MSG_COMMON_CURUSER
	ZC_MSG_BCBCLIENT_NEWUSER,                ///<(30001)���������û���¼��2��������ZC_MSG_HANDOVER_NEWUSER
	ZC_MSG_BCBCLIENT_DOWNLOADPIC,            ///<(30002)��������ͼƬ������ZC_MSG_COMMON_DOWNLOADPIC
	ZC_MSG_BCBCLIENT_ONLINEUSER,             ///<(30003)���������û���Ϣ������ZC_MSG_COMMON_ONLINEUSER
	ZC_MSG_BCBCLIENT_UPLOADATTACHMENT,       ///<(30004)�����ϴ�����������ZC_MSG_COMMON_UPLOADATTACHMENT

    /**
	 * @brief (30005)�����ĳ��ͨ����Ƶ
     *
     * ֧����������
	 *
	 * @note ����ṹ��:\ref char chCameraName[64] * N  ͨ��������
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_COMMON_OPENCAMERA (105)
	 */
    ZC_MSG_BCBCLIENT_OPENCAMREA,

    /**
	* @brief (30050)����Ӵ洢���������ر�����������
	* 
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ���ݲ��趨��ʱʱ��
	*
	* @note ����ṹ��:\ref CLIENTGETMEDIASTORAGEATTACHMENT_S
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + char chFilePath[260]
	* @note ������Ϣֵ:\ref ZC_MSG_COMMON_GETALARMATTACHMENTFROMMS (2020)
	* @note BCB��Ϣ������:CZCMsgDealGetAlarmAttachmentFromMs
	*
	* @note ������˵����
	* @note ������������Ȳ���ȷ������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	*/
	ZC_MSG_BCBCLIENT_GETALARMATTACHMENTFROMMS = 30050,

    /**
	* @brief (30051)����Ӵ洢�������طű���������Ƶ����
	* 
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ���ݲ��趨��ʱʱ��
	*
	* @note ����ṹ��:\ref CLIENTGETMEDIASTORAGEATTACHMENT_S
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	* @note ������Ϣֵ:\ref ZC_MSG_COMMON_PLAYBACKALARMATTACHMENTFROMMS (2021)
	* @note BCB��Ϣ������:CZCMsgDealPlayBackAlarmAttachmentFromMs
	*
	* @note ������˵����
	* @note ������������Ȳ���ȷ������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	*/
	ZC_MSG_BCBCLIENT_PLAYBACKALARMATTACHMENTFROMMS,

	/**
	 * @brief (30090)�����������ϵͳ������Ϣ
	 *
	 * @note ����ṹ��:������Ϣ����ֵ + ��Ϣ���Ͷ�Ӧ�Ľṹ��
	 * @note ������Ϣ����˵�����£�
	 * @note #define THIRDPART_MESSAGE_SY_SCHEDULE_INFO		3000	//��ȡָ�������Ѻ���Ű���Ϣ(��Ѻ)[REQ:int,��֯����id][RESP:TSyScheduleList]
	 * @note #define THIRDPART_MESSAGE_SY_IMAGE				3001	//��ȡ�������͵�ͼƬ(��Ѻ)[REQ:TSyGetImage][RESP:TSyImageId]
	 * @note #define THIRDPART_MESSAGE_SY_SERVER_TIME		3002	//��ȡ������ʱ��(��Ѻ)[REQ����][RESP:T_TIME_INFO]
	 * @note #define THIRDPART_MESSAGE_SY_ROUTE_STATUS		3003	//��ȡָ������Ѻ��·�ߵ�״̬(��Ѻ)[REQ:int,��֯�ṹid][RESP:TSyRouteList]
	 * @note #define THIRDPART_MESSAGE_SY_TAG_DATA			3004	//��ȡ���ӱ�ǩ������ϸ��Ϣ(��Ѻ)[REQ:TSyGetTagData][RESP:TSyTagDataList]
	 * @note ����ṹ��ʾ����
	 * @code
	   //�˴���THIRDPART_MESSAGE_SY_SCHEDULE_INFO(3000)Ϊ��
	   //�����������֯����IDΪ������
	   int nMsgType = THIRDPART_MESSAGE_SY_SCHEDULE_INFO;
	   int nOrganizationId = 1;
       //��ֵ����
	   int nParamLen = sizeof(int) + sizeof(int); //��Ϣ����ֵ+��֯����id
	   BYTE* pRequestParam = new BYTE[nParamLen];
       memcpy((int*)pRequestParam,&nMsgType,sizeof(int));
	   memcpy((int*)&pRequestParam[sizeof(int)], &nOrganizationId, sizeof(int));
	   //����ͨ��������Ͳ���
	   CZCMsgManager::SendMsg(..,..,..,pRequestParam,nParamLen);
       delete[] pRequestParam;
	   pRequestParam = NULL; 
	 * @endcode
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + ������Ϣ����ֵ��int�� + ��Ӧ��Ϣ���͵ķ����ṹ��
	 * @note ������Ϣֵ:\ref ZC_MSG_COMMON_THIRDPART_EXCHANGEMESSAGE (2025)
	 * @note BCB��Ϣ������:CMsgDealThirdPartExchangeMessageUnit
     *
	 * @note ������˵����
	 * @note ��������Ϣ����ֵ���Ӧ�Ľṹ�峤�Ȳ���������\ref BCBC_ERROR_PARAMERROR
	 * @note ��������Ϣ����ֵ����3000-3004֮�䣬����\ref BCBC_ERROR_UNKNOWNMSG
	 * @note �ڷ����ӿڷ���ʧ�ܣ�����\ref BCBC_ERROR_THRIDPARTREQUESTFAILED
	 */
	ZC_MSG_BCBCLIENT_THIRDPART_EXCHANGEMESSAGE = 30090,

    /**
	 * @brief (30091)��������������������Ϣ
	 *
	 * @note ����ṹ��:\ref ƽ̨��������������ĸ��ֽṹ��
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_COMMON_TRANSCOMMONMSGTOKOALA (50105��
	 */
    ZC_MSG_BCBCLIENT_TRANSCOMMONMSGTOKOALA,

	ZC_MSG_BCBCLIENT_STARTTASKCHECK  = 30100,     ///<(30100)����ʼִ������9��������ZC_MSG_TASK_STARTTASKCHECK
	ZC_MSG_BCBCLIENT_STOPTASKCHECK,               ///<(30101)����ִֹͣ�����񣬷���ZC_MSG_TASK_STOPTASKCHECK
	
    ZC_MSG_BCBCLIENT_CAPTUREPIC,             ///<(30102)����ץȡͼƬ������ZC_MSG_TASK_CAPTUREPIC
    ZC_MSG_BCBCLIENT_SHORTMESSAGE,           ///<(30103)�����Ͷ��ţ�10��������ZC_MSG_TASK_SHORTMESSAGE
    ZC_MSG_BCBCLIENT_TELEPHONECALL,          ///<(30104)���󲦴�绰��11��������ZC_MSG_TASK_TELEPHONECALL	
    
	ZC_MSG_BCBCLIENT_TRANSFASTTASK,          ///<(30105)�����·���������12��������ZC_MSG_TASK_TRANSFASTTASK
	ZC_MSG_BCBCLIENT_STARTCHECKPLAYBACK,     ///<(30106)����ʼѲ��طţ�����ZC_MSG_TASK_STARTCHECKPLAYBACK
    ZC_MSG_BCBCLIENT_STOPCHECKPLAYBACK,      ///<(30107)����ֹͣѲ��طţ�����ZC_MSG_TASK_STOPCHECKPLAYBACK
	
	ZC_MSG_BCBCLIENT_ALARMPOSITION = 30200,       ///<(30200)�����������ͼ�㣬����ZC_MSG_ALARM_ALARMPOSITION 
    ZC_MSG_BCBCLIENT_CONCEALALARM,                ///<(30201)��������ĳ����Դ������ZC_MSG_ALARM_CONCEALALARM
   	ZC_MSG_BCBCLIENT_ALARMLINKVIDEO,              ///<(30202)����򿪱���������Ƶ������ZC_MSG_ALARM_ALARMLINKVIDEO
	ZC_MSG_BCBCLIENT_ALARNEARBYVIDEO,             ///<(30203)����ۿ�����������Ƶ������ZC_MSG_ALARM_ALARNEARBYVIDEO
    ZC_MSG_BCBCLIENT_ALARMREPLAY,                 ///<(30204)����ۿ�����¼��طţ�����ZC_MSG_ALARM_ALARMREPLAY 
	ZC_MSG_BCBCLIENT_DEFENCEDEV,                  ///<(30205)���󲼳����豸������ZC_MSG_ALARM_DEFENCEDEV
	ZC_MSG_BCBCLIENT_CONTROLDEV,                  ///<(30206)��������豸��������ơ������ţ�������ZC_MSG_ALARM_CONTROLDEV
	ZC_MSG_BCBCLIENT_DEVTALK,                     ///<(30207)���������Խ�������ZC_MSG_ALARM_DEVTALK
	ZC_MSG_BCBCLIENT_DOWNANDUPLOADVIDEO,          ///<(30208)��������¼���ϴ�������ZC_MSG_ALARM_DOWNANDUPLOADVIDEO
    ZC_MSG_BCBCLIENT_ALARMMAPINFO,                ///<(30209)�����ȡ��������ͼ��Ϣ������ZC_MSG_ALARM_ALARMMAPINFO	
    ZC_MSG_BCBCLIENT_ALARMPOSITION_UNLOCK,        ///<(30210)���������ǰͼ�㣬 ���� ZC_MSG_ALARM_ALARMPOSITION_UNLOCK
    ZC_MSG_BCBCLIENT_ALARMREPLAY_CLOSE,           ///<(30211)����رձ���¼��طţ����õ�������֤,��ZC_MSG_BCBCLIENT_ALARMREPLAY������Ӧ)������ZC_MSG_ALARM_ALARMREPLAY_CLOSE
   
    /**
	* @brief (30212)����򿪵�������֤����������Ƶ
	*
	* @note ����ṹ��:\ref T_OPENDOORLINKVIDEOPRARM
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	* @note ������Ϣֵ:\ref ZC_MSG_OPENDOOR_OPENLINKVIDEO (51104)
	*/
    ZC_MSG_BCBCLIENT_OPENDOORLINKVIDEO,

    /**
	* @brief (30213)����ڵ���˸
	*
	* @note ����ṹ��:\ref T_OPENDOORLINKVIDEOPRARM
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	* @note ������Ϣֵ:\ref ZC_MSG_COMMON_FLASHNODE (51104)
	*/
    ZC_MSG_BCBCLIENT_FLASHNODE,
	
	ZC_MSG_BCBCLIENT_ADDEVENT = 30250,            ///<(30250)������Ӷ�̬��Ϣ��17��������ZC_MSG_COMMON_ADDEVENT                 
    ZC_MSG_BCBCLIENT_SENDEMAIL,                   ///<(30251)�������ʼ�������ZC_MSG_COMMON_SENDEMAIL
	ZC_MSG_BCBCLIENT_CLOSEALLVIDEO,               ///<(30252)����ر�������Ƶ���ڣ�����ZC_MSG_COMMON_CLOSEALLVIDEO
    ZC_MSG_BCBCLIENT_DEVTALKBYID,                 ///<(30253)����ͨ���Խ��豸ID���жԽ�,����ZC_MSG_COMMON_DEVTALKBYID
	ZC_MSG_BCBCLIENT_CONTROLACSHOST,              ///<(30254)��������Ž�������21��������ZC_MSG_COMMON_CONTROLACSHOST

	ZC_MSG_BCBCLIENT_STARTLISTENMANUALCAPTURE = 30280,    ///<(30280)����ʼ�����ֶ�ץͼ��Ϣ������ZC_MSG_OPENDOOR_STARTLISTENMANUALCAPTURE
	ZC_MSG_BCBCLIENT_STOPLISTENMANUALCAPTURE,             ///<(30281)����ֹͣ�����ֶ�ץͼ��Ϣ������ZC_MSG_OPENDOOR_STOPLISTENMANUALCAPTURE
	ZC_MSG_BCBCLIENT_CAPTUREWITHOUTOPEN,                  ///<(30282)������δ����Ƶʱץͼ��20��������ZC_MSG_OPENDOOR_CAPTUREWITHOUTOPEN  

    /**
	 * @brief (30299)����ͨ�����ĸ������ͻ���ת����Ϣ
     *
     * �ýӿڱ�\ref ZC_MSG_BCBCLIENT_REQUESTTRANSMSG (30300)��һ���ͻ������Ͳ���
	 *
	 * @note ����ṹ��:\ref T_TRANS_COMMONHEADINFO_EX + �����Զ�����Ϣ����
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_COMMON_REQUESTTRANSMSG_EX  (2299)
	 */
    ZC_MSG_BCBCLIENT_REQUESTTRANSMSG_EX = 30299,

	ZC_MSG_BCBCLIENT_REQUESTTRANSMSG = 30300, ///<(30300)����ͨ�����ĸ������ͻ���ת����Ϣ��ǰ4���ֽڱ�ʾ���յ�ģ��ţ�������\ref ZC_MSG_COMMON_REQUESTTRANSMSG (2300)

    /**
	* @brief (30301)��������ƽ̨�ύ�豸������Ϣ
	*
	* @note ����ṹ��:\ref TDeviceTroubleRepairToKoala
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	* @note ������Ϣֵ:\ref ZC_MSG_COMMON_TRANSDEVICETROUBLEMSGTOKOALA (2302)
	*/
    ZC_MSG_BCBCLIENT_TRANSDEVICETROUBLEMSGTOKOALA,

	/**
	 * @brief (30310)��������ƽ̨ȷ�Ͼ��顢ָ����Ա������ָ����ԱЭ��
	 *
	 * @note ����ṹ��:\ref TRequestVerifyAlarmToKoala
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_TRANSREQUESTVERIFYALARMTOKOALA (50100) 
	 */
    ZC_MSG_BCBCLIENT_TRANSREQUESTVERIFYALARMTOKOALA = 30310,

    /**
	 * @brief (30311)��������ƽ̨�ϱ�����Ԥ�����л�Ԥ��
	 *
	 * @note ����ṹ��:\ref TDealAlarmInfoToKoala + \ref TDealStep * N
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_TRANSDEALALARMINFOTOKOALA (50101) 
	 */
    ZC_MSG_BCBCLIENT_TRANSDEALALARMINFOTOKOALA,

	/**
	 * @brief (30312)��������ƽ̨��ȡ������Ա��Ϣ
	 *
	 * @note ����ṹ��:\ref TGetOnlineUserToKoala
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_TRANSGETONLINEUSERTOKOALA (50102) 
	 */
    ZC_MSG_BCBCLIENT_TRANSGETONLINEUSERTOKOALA,

	/**
	 * @brief (30313)��������ƽ̨�ϱ��������ý���
	 *
	 * @note ����ṹ��:\ref TDealStepToKoala
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_TRANSDEALSTEPTOKOALA (50103) 
	 */
    ZC_MSG_BCBCLIENT_TRANSDEALSTEPTOKOALA,

    /**
	 * @brief (30314)��������ƽ̨�ϱ����ý�����Ϣ
	 *
	 * @note ����ṹ��:\ref TDealEndToKoala
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_TRANSDEALENDTOKOALA (50104) 
	 */
    ZC_MSG_BCBCLIENT_TRANSDEALENDTOKOALA,

	/**
	 * @brief (30315)��������ƽ̨�����յ����ý�����Ϣ
	 *
	 * @note ����ṹ��:\ref TFeedBackToKoala
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 * @note ������Ϣֵ:\ref ZC_MSG_ALARM_TRANSFEEDBACKTOKOALA (50105�� 
	 */
    ZC_MSG_BCBCLIENT_TRANSFEEDBACKTOKOALA,

    /**
	* @brief (30400)�����ѯ�����������״̬
	* 
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s��������������������豸�������ض���������Ϣ��
	*
	* @note ����ṹ��:\ref T_GET_DEV_STATE * N 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref ONLINESTATE
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DVRONLINESTATE��52060��
	* @note BCB��Ϣ������:CZCMsgDealDEVOnlineStateUnit
	*
	* @note ������˵����
	* @note ���������Ϊ�ջ��ܱ�T_GET_DEV_STATE����������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	* @note �����Ĳ�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_DVRONLINESTATE = 30400, 

    /**
	* @brief (30401)�����ѯ��������״̬
	* 
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s��������������������豸�������ض���������Ϣ��
	*
	* @note ����ṹ��:\ref T_GET_DEV_STATE * N 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + \ref T_ALARMHOST_STATE * N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_ALARMHOSTSTATE��52061��
	* @note BCB��Ϣ������:CZCMsgDealAlarmHostStateUnit
	*
	* @note ������˵����
	* @note ���������Ϊ�ջ��ܱ�T_GET_DEV_STATE����������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	* @note �����Ĳ�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_ALARMHOSTSTATE,   

    /**
	* @brief (30402)�����ѯ�������ʱ��״̬
	* 
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s��
	*
	* @note ����ṹ��:\ref T_DEVID_INFO * N 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETDEVTIME * N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVTIMEINFO��52062��
	* @note BCB��Ϣ������:CZCMsgDealGetDevTimeUnit
	*
	* @note ������˵����
	* @note ���������Ϊ�ջ��ܱ�T_DEVID_INFO����������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	* @note �����Ĳ�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVTIMEINFO, 

    /**
	* @brief (30403)�����ѯ�������ʱ��״̬
	* 
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s��
	*
	* @note ����ṹ��:\ref T_DEVID_INFO * N 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE * N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_SETDEVTIMEINFO��52063��
	* @note BCB��Ϣ������:CZCMsgDealSetDevTimeUnit
	*
	* @note ������˵����
	* @note ���������Ϊ�ջ��ܱ�T_DEVID_INFO����������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	* @note �����Ĳ�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_SETDEVTIMEINFO,  

    /**
	* @brief (30404)�����ѯ�������ͨ��״̬
	* 
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s��������������������豸�������ض���������Ϣ��
	*
	* @note ����ṹ��:\ref T_GET_DEV_STATE * N 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + \ref T_CHANNEL_STATE * N��N���豸ͨ����������Ŀǰ����ȫ��ͨ����
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVCHANNELSTATE��52064��
	* @note BCB��Ϣ������:CZCMsgDealDEVChannelStateUnit
	*
	* @note ������˵����
	* @note ���������Ϊ�ջ��ܱ�T_GET_DEV_STATE����������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	* @note �����Ĳ�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVCHANNELSTATE,  

    /**
	* @brief (30405)�����ѯ�������Ӳ��״̬
	* 
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s��������������������豸�������ض���������Ϣ��
	*
	* @note ����ṹ��:\ref T_GET_DEV_STATE * N 
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + \ref T_DISK_STATE * N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVDISKSTATE��52065��
	* @note BCB��Ϣ������:CZCMsgDealDEVDiskStateUnit
	*
	* @note ������˵����
	* @note ���������Ϊ�ջ��ܱ�T_GET_DEV_STATE����������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	* @note �����Ĳ�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	*/
	ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVDISKSTATE,    

    /**
	* @brief (30406)�����ѯĳͨ����¼��ƻ���¼���ļ�
	* 
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s���ݲ�֧��������ѯ���ҽ�֧��ֱ���豸��ѯ��
	*
	* @note ����ṹ��:\ref T_GET_DEV_CHECKVIDEOINFO
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref T_GET_DEV_STATE [length28] + \ref TYNET_DVR_RECORD [length508]+ \ref  T_DEV_CHECKVIDEOFILEINFO [length32]* N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_DEVCHECKVIDEO��52066��
	* @note BCB��Ϣ������:CZCMsgDealDevCheckVideoUnit
	*
	* @note ������˵����
	* @note ������������Ȳ�����T_GET_DEV_CHECKVIDEOINFO������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	* @note �۲�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	* @note ��¼��ƻ���ѯʧ�ܣ�����\ref T_GET_DEV_CHECKVIDEOINFO
	* @note ��¼���ļ��б��ѯʧ�ܣ�����\ref BCBC_ERROR_SEARCHFILELISTFAILED
	* @note ��¼���ļ��ص�������·�쳣������\ref BCBC_ERROR_SEARCHFILELISTFAILED
	*/
    ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVCHECKVIDEO,

    /**
	* @brief (30407)�����ѯ�Ž�����״̬
	*
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s��������������������豸�������ض���������Ϣ��
	*
	* @note ����ṹ��:\ref T_GET_DEV_STATE * N
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + \ref T_ACCESS_STATE * N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_ACCESSSTATE��52067��
	* @note BCB��Ϣ������:CZCMsgDealAccseeStateUnit
	*
	* @note ������˵����
	* @note ���������Ϊ�ջ��ܱ�T_GET_DEV_STATE����������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	* @note �����Ĳ�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	*/
    ZC_MSG_BCBCLIENT_SYSDORCTOR_ACCESSSTATE,

    /**
	* @brief (30408)�����ѯ��Ƶ�������Ѳ����
	*
	* BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s��������������������豸�������ض���������Ϣ��
	*
	* @note ����ṹ��:\ref T_GET_DEV_STATE * N
	* @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + ( \ref TPatrolResult + \ref TpatrolResultVideoQuality) * N
	* @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_VIDEOQUALITY��52068��
	* @note BCB��Ϣ������:CZCMsgDealVideoQualityUnit
	*
	* @note ������˵����
	* @note ���������Ϊ�ջ��ܱ�T_GET_DEV_STATE����������\ref BCBC_ERROR_PARAMERROR
	* @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	* @note �����Ĳ�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	*/
    ZC_MSG_BCBCLIENT_SYSDORCTOR_VIDEOQUALITY,

	/**
	 * @brief (30409)�����ѯ�ڵ�״̬���������ڵ㣩���
	 *
	 * BCB�ͻ���ͬһʱ�̽��ܴ���һ������Ϣ����ʱʱ��Ϊ20s��������������������豸�������ض���������Ϣ��
	 *
	 * @note ����ṹ��:\ref T_GET_DEV_STATE * N
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETSTATE + ( \ref TPatrolResult + \ref TpatrolResultNodeState) * N
	 * @note ������Ϣֵ:\ref ZC_MSG_SYSDORCTOR_NODESTATE��52069��
	 * @note BCB��Ϣ������:CZCMsgDealNodeStateUnit
	 *
	 * @note ������˵����
 	 * @note ���������Ϊ�ջ��ܱ�T_GET_DEV_STATE����������\ref BCBC_ERROR_PARAMERROR
	 * @note �����ڴ������Ϣ���󣬷���\ref BCBC_ERROR_BUSY
	 * @note �����Ĳ�ѯ���������ʱ������\ref BCBC_ERROR_TIMEOUT
	 */
    ZC_MSG_BCBCLIENT_SYSDORCTOR_NODESTATE,
}E_ZC_MSG_BCBCLIENT;
/** @} */

/** @defgroup ZCHandoverMsgTypeDefine ���Ӱ�ģ����Ӧ��Ϣ����ö��    
 * ���彻�Ӱ�ģ����Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
	ZC_MSG_HANDOVER_HA_INFO = 40000,        ///<(40000)�û����Ӱ���Ϣ @note ������Ϣֵ:\ref ZC_MSG_APP_HA_INFO (20000) @note �����ṹ��:\ref T_USER_HA_INFO
	ZC_MSG_HANDOVER_HA_WAITUSERLIST,        ///<(40001)���Ӱ���Ա��Ϣ @note ������Ϣֵ:\ref ZC_MSG_APP_HA_WAITUSERLIST (20001) @note �����ṹ��:\ref S_NEW_SHOW_HA_WAITUSERLIST
	ZC_MSG_HANDOVER_A_TASKINFO,             ///<(40002)ֵ��Ա����ִ����� @note ������Ϣֵ:\ref ZC_MSG_APP_HA_A_TASKINFO (20002) @note �����ṹ��:\ref S_NEW_SHOW_HA_A_TASKINFO
	ZC_MSG_HANDOVER_M_TASKINFO,             ///<(40003)ֵ�೤����ִ����� @note ������Ϣֵ:\ref ZC_MSG_APP_HA_M_TASKINFO (20003) @note �����ṹ��:\ref S_NEW_SHOW_HA_M_TASKINFO
	ZC_MSG_HANDOVER_HA_ALARMINFO,           ///<(40004)δ��������Ϣ @note ������Ϣֵ:\ref ZC_MSG_APP_HA_ALARMINFO (20004) @note �����ṹ��:\ref S_NEW_SHOW_HA_ALARMINFO
	ZC_MSG_HANDOVER_ADD_HAINFO,             ///<(40005)������Ϣ�ύ��� @note ������Ϣֵ:\ref ZC_MSG_APP_ADD_HAINFO (20005) @note �����ṹ��:NULL
	ZC_MSG_HANDOVER_SEL_HAINFO,             ///<(40006)���Ӱ���ʷ��ѯ��� @note ������Ϣֵ:\ref ZC_MSG_APP_SEL_HAINFO (20006) @note �����ṹ��:\ref S_NEW_SHOW_HA_INFO 
	ZC_MSG_HANDOVER_NEWUSER,                ///<(40007)���û���¼����
	ZC_MSG_HANDOVER_A_HISTORYINFO,          ///<(40008)ֵ��Ա���Ӱ���ʷ��ϸ��Ϣ @note ������Ϣֵ:\ref ZC_MSG_APP_HA_A_HISTORYINFO (20007) @note �����ṹ��:\ref S_NEW_SHOW_HA_A_TASKINFO
	ZC_MSG_HANDOVER_M_HISTORYINFO,          ///<(40009)ֵ�೤���Ӱ���ʷ��ϸ��Ϣ @note ������Ϣֵ:\ref ZC_MSG_APP_HA_M_HISTORYINFO (20008) @note �����ṹ��:\ref S_NEW_SHOW_HA_M_TASKINFO
	ZC_MSG_HANDOVER_MODIFYALARMDEALMAN,     ///<(40010)�����޸ı��������˽������ @note ������Ϣֵ:\ref ZC_MSG_APP_HA_MODIFYALARMDEALMAN (20009) @note �����ṹ��:NULL
	ZC_MSG_HANDOVER_CURCLASSUSERINFO,       ///<(40011)��ǰ��������û���Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_HA_CURCLASSUSERINFO (20010) @note �����ṹ��:\ref T_USER_HA_INFO  
}E_ZC_MSG_HANDOVER;
/** @} */

/** @defgroup ZCScheduleMsgTypeDefine �Ű�ģ����Ӧ��Ϣ����ö��    
 * �����Ű�ģ����Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
    ZC_MSG_SCHEDULE_DATEGROUPSET = 41000,    ///<(41000)����������������
	ZC_MSG_SCHEDULE_DATEGROUPINFO,           ///<(41001)��������Ϣ����
	ZC_MSG_SCHEDULE_CLASSINFOSET,            ///<(41002)������ν������
	ZC_MSG_SCHEDULE_CLASSINFO,               ///<(41003)�����Ϣ����
	ZC_MSG_SCHEDULE_SCHEDULESET,             ///<(41004)�����Ű���Ϣ�������
	ZC_MSG_SCHEDULE_SCHEDULEINFO,            ///<(41005)��ȡ�Ű���Ϣ����
	ZC_MSG_SCHEDULE_SC_USERINFO,             ///<(41006)���Ű���Ա��Ϣ����
}E_ZC_MSG_SCHEDULE;
/** @} */

/** @defgroup ZCTaskMsgTypeDefine Ѳ������ģ����Ӧ��Ϣ����ö��  
 * ����Ѳ������ģ����Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
    ZC_MSG_TASK_TASKINFOSET = 42000,    ///<(42000)��������������
	ZC_MSG_TASK_FASTTASKINFOSET,        ///<(42001)������������������
	ZC_MSG_TASK_TASKINFO,               ///<(42002)��ѯ������Ϣ����
	ZC_MSG_TASK_DETAILEDTASKINFO,       ///<(42003)��ѯ������ϸ��Ϣ����
	ZC_MSG_TASK_TASKSTATESET,           ///<(42004)��������״̬�������
	ZC_MSG_TASK_TASKMODULEINFOSET,      ///<(42005)��������ģ��������
	ZC_MSG_TASK_TASKMODULEINFO,         ///<(42006)��ѯ����ģ����Ϣ����
	ZC_MSG_TASK_DETAILEDTASKMODULEINFO, ///<(42007)��ѯ����ģ����ϸ��Ϣ����
	ZC_MSG_TASK_TASKOBJECTINFO,         ///<(42008)��ȡ���������Ϣ���� 
	ZC_MSG_TASK_TASKKEYPARTINFO,        ///<(42009)��ȡ����λ��Ϣ����
	ZC_MSG_TASK_TASKLEVELINFO,          ///<(42010)��ȡ������Ҫ�̶���Ϣ����
	ZC_MSG_TASK_TASKOPERATIONINFO,      ///<(42011)��ȡ����������ͷ���
	ZC_MSG_TASK_TASKEXCEPTIONINFO,      ///<(42012)��ȡ�쳣���ͷ���
	ZC_MSG_TASK_DETATASKEXCEPTIONINFO,  ///<(42013)��ȡ�쳣�������鷴��
	ZC_MSG_TASK_TASKCLASSROLEINFO,      ///<(42014)��ȡ�����·���ɫ��Ϣ����
	ZC_MSG_TASK_CURONLINEUSERINFO,      ///<(42015)��ȡ��ǰ�ϰ��û���Ϣ����
	ZC_MSG_TASK_TODAYTASKINFO,          ///<(42016)��ȡ��ǰ�û�����������Ϣ����
	ZC_MSG_TASK_TODAYTASKALLINFO,       ///<(42017)��ȡĳ����ִ��������Ϣ����  
    ZC_MSG_TASK_TODAYTASKOBJECTINFO,    ///<(42018)��ȡĳ����ִ�����������Ϣ����
    ZC_MSG_TASK_TODAYTASKDOINFO,        ///<(42019)��ȡĳ���������ִ����Ϣ����
	ZC_MSG_TASK_USERTASKINFO,           ///<(42020)��ȡĳ�û�����������Ϣ����
	ZC_MSG_TASK_TASKEXCUTESET,          ///<(42021)��������ִ����Ϣ������� 
    ZC_MSG_TASK_CURUSERINFO,            ///<(42022)����ģ����صĵ�ǰ�û���Ϣ����(8)	
	ZC_MSG_TASK_CHECKTASKINFO,          ///<(42023)��ѯ������Ϣ����	
	ZC_MSG_TASK_SHOWTASKCHECKINFO,      ///<(42024)��ȡ���񸴺������Ϣ����
	ZC_MSG_TASK_SHOWTASKEPLANINFO,      ///<(42025)��ȡ���񸴺�Ԥ����Ϣ����
	ZC_MSG_TASK_ISQUALIFIEDMOD,         ///<(42026)��������ִ���Ƿ�ϸ���
	ZC_MSG_TASK_TASKCHECKRECORDSET,     ///<(42027)�����������ļ�¼����
	
	ZC_MSG_TASK_SHOWAREAERRORINFO,       ///<(42028)ͳ��ĳ���������쳣����������
	ZC_MSG_TASK_SHOWAREAERRORATEINFO,    ///<(42029)ͳ��������쳣�ʷ���
	ZC_MSG_TASK_SHOWCOVERRATEINFO,       ///<(42030)ͳ��Ѳ�츲���ʷ���
	ZC_MSG_TASK_SHOWALARMRECORINFO,      ///<(42031)��ȡ����������Ϣ����
	ZC_MSG_TASK_SHOWAREAERRORNUMINFO,    ///<(42032)ͳ�Ƶ�λʱ���ڵ������쳣��������
	ZC_MSG_TASK_SHOWERRORCHECKRATEINFO,  ///<(42033)ͳ���쳣�ĸ���ϸ��ʷ���
	
	ZC_MSG_TASK_STATICS_TASKADDINFO,     ///<(42034)���������ͳ����Ϣ����
	ZC_MSG_TASK_STATICS_EMPLOYANALY,     ///<(42035)Ա������������ͳ����Ϣ����
	ZC_MSG_TASK_STATICS_EMPLOYMANAGER,   ///<(42036)Ա��������ͳ����Ϣ����

	ZC_MSG_TASK_CHECKTASKLOCKINFO,       ///<(42037)��ѯ������Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_CHECKTASKLOCKINFO (20237) 	

	ZC_MSG_TASK_TODAYTASKALLINFOSHOW_EX, ///<(42038)��ȡĳ���·������ִ����ϢEx���� @note ������Ϣֵ:\ref ZC_MSG_APP_TODAYTASKALLINFOSHOW_EX (20238)
    ZC_MSG_TASK_TODAYTASKDOINFOSHOW_EX,  ///<(42039)��ȡ����ִ�����Ex���� @note ������Ϣֵ:\ref ZC_MSG_APP_TODAYTASKDOINFOSHOW_EX (20239)
	ZC_MSG_TASK_AKIDCONFIGUREINFO,       ///<(42040)���ݳ���ID�Ͳ�λID��ȡ�����Ŀ������Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_AKIDCONFIGUREINFO (20240)
	ZC_MSG_TASK_CONFIGURETIMEINFO,       ///<(42041)��ȡ����Ѳ������Ŀ��ʱ�����Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_TASK_CONFIGURETIMEINFO (20241)
	ZC_MSG_TASK_CONFIGURETIMEONLYINFO,   ///<(42042)����ʱ������ƻ�ȡ����Ѳ������Ŀ��ʱ�����Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_TASK_CONFIGURETIMEONLYINFO (20242)
	ZC_MSG_TASK_CHECKTASKINFOWITHLOCK_NEW, ///<(42043)�����ѯ������Ϣ���������������Ƿ��ע������ @note ������Ϣֵ:\ref ZC_MSG_APP_TASK_CHECKTASKINFOWITHLOCK_NEW (20243)
    ZC_MSG_TASK_COVERRATENEWINFO_NEW,      ///<(42044)�����ѯѲ�츲����_New���� @note ������Ϣֵ:\ref ZC_MSG_APP_TASK_COVERRATENEWINFO_NEW (20244)

	ZC_MSG_TASK_STARTTASKCHECK = 42100,      ///<(42100)��ʼִ������������
	ZC_MSG_TASK_STOPTASKCHECK,               ///<(42101)ִֹͣ������������
	
	ZC_MSG_TASK_CAPTUREPIC,             ///<(42102)����ץȡͼƬ������12��
    ZC_MSG_TASK_SHORTMESSAGE,           ///<(42103)�����Ͷ��ŷ���
    ZC_MSG_TASK_TELEPHONECALL,          ///<(42104)���󲦴�绰������12��
	ZC_MSG_TASK_TRANSFASTTASK,          ///<(42105)�����·�����������
    ZC_MSG_TASK_STARTCHECKPLAYBACK,     ///<(42106)��ʼѲ��طŽ������
    ZC_MSG_TASK_STOPCHECKPLAYBACK,      ///<(42107)ֹͣѲ��طŽ������
	
	ZC_MSG_TASK_FASTTASKINFO = 42900,   ///<(42900)����ִ�п������񣨴�Ϊ�����ͻ����������͵���Ϣ��������ģ���ݲ����������
}E_ZC_MSG_TASK;
/** @} */

/** @defgroup ZCAlarmMsgTypeDefine ��������ģ����Ӧ��Ϣ����ö��  
 * ���屨������ģ����Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
    ZC_MSG_ALARM_QUERYINFO = 50000,    ///<(50000)������ѯ�������
    ZC_MSG_ALARM_STATICINFO,           ///<(50001)����ͳ�ƽ������
	ZC_MSG_ALARM_TOPINFO,              ///<(50002)�������н������
	ZC_MSG_ALARM_DETAILINFO,           ///<(50003)������ϸ��Ϣ����
		
	ZC_MSG_ALARM_USERGRAPHINFO,        ///<(50004)�û�����ͼ����Ϣ����
	ZC_MSG_ALARM_OPUSERGRAPH,          ///<(50005)��ɾ���û�ͼ����
	ZC_MSG_ALARM_USERREPORTINFO,       ///<(50006)��ȡ�û�������Ϣ����
	ZC_MSG_ALARM_MODSTATUSUSERREPORT,  ///<(50007)�����û�����״̬��Ϣ����
	ZC_MSG_ALARM_OPUSERREPORT,         ///<(50008)��ɾ���û����淴��
	ZC_MSG_ALARM_USERREPORTBOOKINFO,   ///<(50009)��ȡ�û����涩����Ϣ����
	ZC_MSG_ALARM_QUERYLOCKINFO,        ///<(50010)������ѯ�������(�Ƿ���������) @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_QUERYLOCKINFO (20310)
	ZC_MSG_ALARM_DETAILALARMINFO_GET,        ///<(50011)���ݱ���ID�򱨾�GUID��ȡ������ϸ��Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_DETAILALARMINFO_GET (20311)
	ZC_MSG_ALARM_NEW_ALARMACATEGORY_SHOW,    ///<(50012)�������ͻ�ȡ_�����¼�������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_NEW_ALARMACATEGORY_SHOW (20312)

	ZC_MSG_ALARM_ALARMPOSITION = 50040,       ///<(50040)��������ͼ�㷴�� 
    ZC_MSG_ALARM_CONCEALALARM,                ///<(50041)����ĳ����Դ����
   	ZC_MSG_ALARM_ALARMLINKVIDEO,              ///<(50042)�򿪱���������Ƶ����
	ZC_MSG_ALARM_ALARNEARBYVIDEO,             ///<(50043)�򿪱���������Ƶ����
    ZC_MSG_ALARM_ALARMREPLAY,                 ///<(50044)�ۿ�����¼��طŷ��� 
	ZC_MSG_ALARM_DEFENCEDEV,                  ///<(50045)�������豸����
	ZC_MSG_ALARM_CONTROLDEV,                  ///<(50046)�����豸��������ơ������ţ�����
	ZC_MSG_ALARM_DEVTALK,                     ///<(50047)�Խ�����
	ZC_MSG_ALARM_DOWNANDUPLOADVIDEO,          ///<(50048)����¼���ϴ��������
	ZC_MSG_ALARM_ALARMMAPINFO,                ///<(50049)��������ͼ��Ϣ����
    ZC_MSG_ALARM_ALARMPOSITION_UNLOCK,        ///<(50050)������ǰͼ�㷴��
    ZC_MSG_ALARM_ALARMREPLAY_CLOSE,           ///<(50051)�رձ���¼��طŷ���
	
	ZC_MSG_ALARM_DISPOSALINFO = 50060,      ///<(50060)��ȡ�û���������Ȩ�޷���
    ZC_MSG_ALARM_LEVELPLOYINFO, 	        ///<(50061)��ȡ�����ȼ����ò��Է���
	ZC_MSG_ALARM_HISTORYDEALINFO,           ///<(50062)��ȡ��ʷ�������ͳ�����ݷ���
	ZC_MSG_ALARM_POSTILINFO,                ///<(50063)��ȡ������ע��Ϣ����
	ZC_MSG_ALARM_OPERATIONINFO,             ///<(50064)��ȡ����������Ϣ����
	ZC_MSG_ALARM_NOTDEALINFO,               ///<(50065)��ȡδ��������Ϣ����
    ZC_MSG_ALARM_MANUALENTRY,               ///<(50066)�����ֶ�������Ϣ����
    ZC_MSG_ALARM_EXCHANGEINFO_NEW,          ///<(50067)��ȡ���Ľ������������ݷ���
    ZC_MSG_ALARM_EXCHANGEINFO_OPERATION,    ///<(50068)���Ľ������������ݲ�������
	ZC_MSG_ALARM_REG_NEW_ALARMDISPOSALNEW_SET,    ///<(50069)����������־����_New����
	ZC_MSG_ALARM_REG_NEW_ALARMDISPOSALNEW_SHOW,    ///<(50070)���ݱ���ID�򱨾�GUID��ȡ������¼��Ϣ����
	
	ZC_MSG_ALARM_SETDUTYSTATUS = 50080,     ///<(50080)����ֵ��Ա״̬����
    ZC_MSG_ALARM_DEALSTATUSSET,             ///<(50081)���ñ�����Ϣ����״̬����
	ZC_MSG_ALARM_PEOPLESET,                 ///<(50082)���ñ�����Ϣ�����˷���
	ZC_MSG_ALARM_DEALSULTSET,               ///<(50083)�ύ�������ý������
	ZC_MSG_ALARM_MODALARMPARAM,             ///<(50084)�޸ı����ؼ���������
	ZC_MSG_ALARM_ADDALARMOPERATION,         ///<(50085)��������������¼����
	ZC_MSG_ALARM_ADDALARMPOSTILINFO,        ///<(50086)����������ע��Ϣ����
	ZC_MSG_ALARM_ADDDEFERALARMINGO,         ///<(50087)�����Ӻ�������Ϣ����
	ZC_MSG_ALARM_GETMSATTACHMENT,           ///<(50088)��ȡĳ������ý��洢�����б���Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_GETMSATTACHMENT (20337) @note �����ṹ��:\ref CLIENTGETMEDIASTORAGEATTACHMENT_S
    ZC_MSG_ALARM_LOCKMSATTACHMENT,          ///<(50089)����\�������������洢�����ļ�������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_LOCKMSATTACHMENT (20338) @note �����ṹ��:\ref ZC_MSG_RESP_RESULT

	ZC_MSG_ALARM_OPENALARMMANAGER = 50090,  ///<(50090)����򿪱�������
	
	/**
	* @brief (50098)�������ͱ�����Ϣ����չGUID����Ϣ��
	* 
	* ����Ϣ��bcb�ͻ����������͸����ģ�飬Ŀǰ����������Ҳû�����͵�ǰ�����������ڿ��������ɸ�ģ����bcb�ͻ���ע������Ľӿڡ�
	* 
	* @note ��Ϣ�ṹ��:\ref T_TRANSMITALARMINFO_EX
	* @note ����Ϣ��\ref ZC_MSG_ALARM_NEWALARMINFO (50099)���ݷḻ����ģ��������п��ǽ���������Ϣ���ͻ�����������ʱ�������ͣ����������һ�֣�
	* @note ����bcb�ͻ�����Ҫ�����ϵı��������������Ըýӿ����͵�GUIDֵ����Ϊ�գ���ģ��ʹ��ʱ��������жϣ�
	*/
    ZC_MSG_ALARM_NEWALARMINFO_EX  = 50098,  ///<��չ����ת����Ϣ
	
	/**
	* @brief (50099)�������ͱ�����Ϣ
	* 
	* ����Ϣ��bcb�ͻ����������͸����ģ�飬Ŀǰ����������Ҳû�����͵�ǰ�����������ڿ��������ɸ�ģ����bcb�ͻ���ע������Ľӿڡ�������ά�ô��������쳣.
	* 
	* @note ��Ϣ�ṹ��:\ref T_TRANSMITALARMINFO 
	*/
	ZC_MSG_ALARM_NEWALARMINFO     = 50099, 


    /**
	 * @brief (50100)����ƽ̨ȷ�Ͼ��顢ָ����Ա������ָ����ԱЭ���������
	 * 
	 * ����Ϣ����ʾ�ͻ����Ƿ�ɹ�����Ϣת�������ģ������������ͨ��\ref ZC_MSG_ALARM_VERIFYALARMFEEDBACKTOZONEE (50125)����
 	 * 
	 * @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_TRANSREQUESTVERIFYALARMTOKOALA (30310) 
	 * @note ��Ϣ�ṹ��:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSREQUESTVERIFYALARMTOKOALA = 50100,///<(50100)

    /**
	 * @brief (50101)����ƽ̨�ϱ�����Ԥ�����л�Ԥ���������
	 * 
	 * ����Ϣ����ʾ�ͻ����Ƿ�ɹ�����Ϣת�������ģ��������������û�з������
	 * 
	 * @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_TRANSDEALALARMINFOTOKOALA (30311) 
	 * @note ��Ϣ�ṹ��:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSDEALALARMINFOTOKOALA,
	
    /**
	 * @brief (50102)����ƽ̨��ȡ������Ա��Ϣ�������
	 * 
	 * ����Ϣ����ʾ�ͻ����Ƿ�ɹ�����Ϣת�������ģ������������ͨ��\ref ZC_MSG_ALARM_ONLINEUSERTOZONEE (50124)����
	 * 
	 * @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_TRANSGETONLINEUSERTOKOALA (30312) 
	 * @note ��Ϣ�ṹ��:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSGETONLINEUSERTOKOALA,

    /**
	 * @brief (50103)����ƽ̨�ϱ��������ý��Ƚ������
	 * 
	 * ����Ϣ����ʾ�ͻ����Ƿ�ɹ�����Ϣת�������ģ��������������û�з������
	 * 
	 * @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_TRANSDEALSTEPTOKOALA (30313) 
	 * @note ��Ϣ�ṹ��:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSDEALSTEPTOKOALA,

    /**
	 * @brief (50104)����ƽ̨�ϱ����ý�����Ϣ�������
	 * 
	 * ����Ϣ����ʾ�ͻ����Ƿ�ɹ�����Ϣת�������ģ��������������û�з������
	 * 
	 * @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_TRANSDEALENDTOKOALA (30314) 
	 * @note ��Ϣ�ṹ��:\ref ZC_MSG_RESP_RESULT 
	 */
    ZC_MSG_ALARM_TRANSDEALENDTOKOALA,

	/**
	 * @brief (50105)����ƽ̨�����յ����ý�����Ϣ�������
	 *
	 * ����Ϣ����ʾ�ͻ����Ƿ�ɹ�����Ϣת�������ģ��������������û�з������
	 *
	 * @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_TRANSFEEDBACKTOKOALA (30315�� 
	 * @note ���ؽṹ��:\ref ZC_MSG_RESP_RESULT
	 */
    ZC_MSG_ALARM_TRANSFEEDBACKTOKOALA,

    /**
	 * @brief (50120) ������������Э����Ϣ
	 * 
	 * ����Ϣ�ɿ�������������û��������ͣ��ݲ���Ҫ����
	 * 
	 * @note ��Ϣ�ṹ��:\ref TRequestHelpToZONEE 
	 */
	ZC_MSG_ALARM_REQUESTHELPTOZONEE = 50120, 

	/**
	 * @brief (50121) ���������ϱ��������ý�����Ϣ
	 * 
	 * ����Ϣ�ɿ�������������û��������ͣ��ݲ���Ҫ����
	 * 
	 * @note ��Ϣ�ṹ��:\ref TDealStepToZONEE 
	 */
	ZC_MSG_ALARM_DEALSTEPTOZONEE,

	/**
	 * @brief (50122) ���������ϱ��������ý�����Ϣ
	 * 
	 * ����Ϣ�ɿ�������������û��������ͣ��ݲ���Ҫ����
	 * 
	 * @note ��Ϣ�ṹ��:\ref TDealEndToZONEE 
	 */
	ZC_MSG_ALARM_DEALENDTOZONEE, 

	/**
	 * @brief (50123) �����������ͱ������ù����еĸ�����Ϣ
	 * 
	 * �ͻ������ö���ĳ�������Ĵ����ˣ������ͻ���ִ�б�������ʱ������Ϣ�ɿ�������������û��������ͣ��ݲ���Ҫ������
	 * 
	 * @note ��Ϣ�ṹ��:\ref TAlarmFileToZONEE 
	 */
	ZC_MSG_ALARM_ALARMFILETOZONEE,  

    /**
	 * @brief (50124) ����������Ա��Ϣ����
	 * 
	 * ����Ϣ�ɿ�������������û��յ�\ref ZC_MSG_BCBCLIENT_TRANSGETONLINEUSERTOKOALA  (30312)������������ͣ��ݲ���Ҫ����
	 * 
	 * @note ��Ϣ�ṹ��:\ref TOnlineUserToZONEE + \ref TUserInfo * N
	 */
	ZC_MSG_ALARM_ONLINEUSERTOZONEE,

	/**
	 * @brief (50125) ����ȷ�Ͼ��鷴��
	 * 
	 * ����Ϣ�ɿ�������������û��յ�\ref ZC_MSG_BCBCLIENT_TRANSREQUESTVERIFYALARMTOKOALA (30310)������������ͣ��ݲ���Ҫ����
	 * 
	 * @note ��Ϣ�ṹ��:\ref TVerifyAlarmFeedBackToZONEE
	 */
	ZC_MSG_ALARM_VERIFYALARMFEEDBACKTOZONEE,

    /**
	 * @brief (50126) �����ڲ�ָ����Ա�����Ϣ֪ͨ
	 * 
	 * ����Ϣ�ɿ�������������û��������ͣ��ݲ���Ҫ����
	 * 
	 * @note ��Ϣ�ṹ��:\ref TAssignmentNotifyToZONEE
	 */
	ZC_MSG_ALARM_ASSIGNMENTNOTIFYTOZONEE,

    ZC_MSG_ALARM_DEALKOALAINFO = 50200,     ///<(50200)�������ÿ�����Ϣд�������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_DEALKOALAINFO (20350) @note �����ṹ��:\ref ZC_MSG_RESP_RESULT
    ZC_MSG_ALARM_GETACTIONLIB_KOALA,        ///<(50201)��ȡ������_Koala������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_GETACTIONLIB_KOALA (20351) @note �����ṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETACTIONLIB_KOALA_S * N
    ZC_MSG_ALARM_GETPREPLANLIB_KOALA,       ///<(50202)��ȡԤ����_Koala������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_GETPREPLANLIB_KOALA (20352) @note �����ṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETPREPLANLIB_KOALA_S * N
    ZC_MSG_ALARM_GETEVENTLIB_KOALA,         ///<(50203)��ȡ�¼���_Koala������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_GETEVENTLIB_KOALA (20353) @note �����ṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETEVENTLIB_KOALA_S * N
    ZC_MSG_ALARM_GETALARMATTACHMENT_KOALA,  ///<(50204)��ȡKoala��������������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_GETALARMATTACHMENT_KOALA (20354) @note �����ṹ��:\ref ZC_MSG_RESP_RESULT + \ref GETALARMATTACHMENT_KOALA_S * N
    ZC_MSG_ALARM_DISPOSALADDCATEGORYID_AC_SET,  ///<(50205)���ñ�������_��������ֵ������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_DISPOSALADDCATEGORYID_AC_SET (20355) @note �����ṹ��:\ref ZC_MSG_RESP_RESULT
    ZC_MSG_ALARM_JH_COMPLEXCHECKWITHLOCK_NEW,   ///<(50206)����������Ϣ���ۺϲ�ѯWITHLOCK_NEW������� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_JH_COMPLEXCHECKWITHLOCK_NEW (20356) @note �����ṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_NEW_COMPLEXCHECKWITHLOCK * N
    ZC_MSG_ALARM_ALARMDEVICESTATEINTO_NEW,      ///<(50207)���ݱ���GUID��ȡ��������������״̬���� @note ������Ϣֵ:\ref ZC_MSG_APP_ALARM_ALARMDEVICESTATEINTO_NEW (20357) @note �����ṹ��:\ref ZC_MSG_RESP_RESULT + \ref S_AlarmDeviceStateInfo * N
}E_ZC_MSG_ALARM;
/** @} */

/** @defgroup ZCOpenDoorMsgTypeDefine ��������֤ģ����Ӧ��Ϣ����ö��  
 * �����������֤ģ����Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
    ZC_MSG_OPENDOOR_STARTLISTENMANUALCAPTURE = 51100,    ///<(51100)��ʼ�����ֶ�ץͼ��Ϣ����
	ZC_MSG_OPENDOOR_STOPLISTENMANUALCAPTURE,             ///<(51101)ֹͣ�����ֶ�ץͼ��Ϣ����
	ZC_MSG_OPENDOOR_NEW_MANUAL_CAPTURE,                  ///<(51102)�µ��ֶ�ץͼ��Ϣ���������ͣ���ʱ����Ҫ������
	ZC_MSG_OPENDOOR_CAPTUREWITHOUTOPEN,                  ///<(51103)δ����Ƶʱץͼ�������
	ZC_MSG_OPENDOOR_OPENLINKVIDEO,                       ///<(51104)��������Ƶ�������
	
	ZC_MSG_OPENDOOR_ADDREQUEST = 51150,                  ///<(51150)����ˢ����֤��¼����
	ZC_MSG_OPENDOOR_ADDDEALPLANINFO,                     ///<(51151)�ύԤ��ִ����Ϣ�������
	ZC_MSG_OPENDOOR_MODIFYDEALTYPE,                      ///<(51152)�޸���֤���÷�ʽ�������
	ZC_MSG_OPENDOOR_MODIFYREQUESTSTATE,                  ///<(51153)�޸���֤����״̬�������
	ZC_MSG_OPENDOOR_SUBMITAUDITORDEALINFO,               ///<(51154)�ύ����������˻�����Ϣ�������
	ZC_MSG_OPENDOOR_MODIFYISCOLLECTION,                  ///<(51155)�޸���֤��¼�ղ�״̬������� 
	ZC_MSG_OPENDOOR_SUBMITDEALINFO,                      ///<(51156)������֤�����¼�������
	ZC_MSG_OPENDOOR_SETUSERBASEINFO,                     ///<(51157)�����û���֤������Ϣ�������
	ZC_MSG_OPENDOOR_ADDOPERAINFO,                        ///<(51158)������֤���ö�����Ϣ�������
	ZC_MSG_OPENDOOR_ADDLOGINFO,                          ///<(51159)������֤ϵͳ��־��Ϣ�������
	ZC_MSG_OPENDOOR_ADDSUGGESTION,                       ///<(51160)������֤���������Ϣ�������
	ZC_MSG_OPENDOOR_ADDEXCEPTIONINFO,                    ///<(51161)�����쳣��֤��Ϣ�������
	
	ZC_MSG_OPENDOOR_GETUSERBASEINFO,                     ///<(51162)��ȡ�û���֤������Ϣ�������
	ZC_MSG_OPENDOOR_GETALLACSHOSTINFO,                   ///<(51163)��ȡ�����Ž�������Ϣ�������
	ZC_MSG_OPENDOOR_GETACSHOSTLINKINFO,                  ///<(51164)��ȡ�Ž�����������Ϣ�������
	ZC_MSG_OPENDOOR_GETACSHOSTLINKTALKINFO,              ///<(51165)��ȡ�Ž����������Խ���Ϣ�������
	ZC_MSG_OPENDOOR_GETALLPEPOLEINFO,                    ///<(51166)��ȡ�������Ͻ�ĳ�����Ա��Ϣ�������
	ZC_MSG_OPENDOOR_GETAPPLYHISTORYINFO,                 ///<(51167)��ȡ��֤��ʷ��Ϣ�������
	ZC_MSG_OPENDOOR_GETAPPLYHISTORYDETAIL,               ///<(51168)��ȡ��֤��ʷ��ϸ��Ϣ�������
	ZC_MSG_OPENDOOR_GETOPERAINFO,                        ///<(51169)��ȡ��֤�����б���Ϣ�������
	ZC_MSG_OPENDOOR_GETAPPLYPLANINFO,                    ///<(51170)��ȡԤ��ִ����Ϣ�������
	ZC_MSG_OPENDOOR_GETSUGGESTIONINFO,                   ///<(51171)��ȡ���������Ϣ�������
	ZC_MSG_OPENDOOR_GETLOGINFO,                          ///<(51172)��ȡϵͳ��־��Ϣ�������
	ZC_MSG_OPENDOOR_GETACCESSLOGINFO,                    ///<(51173)��ȡ����ˢ����Ϣ�������
	ZC_MSG_OPENDOOR_GETBYCARDHISTORYINFO,                ///<(51174)��ѯˢ����ʷ��Ϣ�������
	ZC_MSG_OPENDOOR_STATISTICS,                          ///<(51175)ͳ����֤��Ϣ�������
	ZC_MSG_OPENDOOR_DISPOSALINFO,                        ///<(51176)��ǰ�û���֤���Ȩ�޽������
	ZC_MSG_OPENDOOR_ACCESSRELATION,                      ///<(51177)��ȡ�Ž��豸���ӹ�����Ϣ�������
	ZC_MSG_OPENDOOR_CTRLLEVELMULINFO,                    ///<(51178)�ܿصȼ���Ϣ�������
	ZC_MSG_OPENDOOR_CTRLLEVELPLAN,                       ///<(51179)�ܿز�����Ϣ�������
	ZC_MSG_OPENDOOR_DEPARTMENTINFO,                      ///<(51180)������Ϣ�������
	ZC_MSG_OPENDOOR_APPLY_BYCARDINFO_NEW,                ///<(51181)��ѯˢ����ʷ��Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_APPLY_BYCARDINFO_NEW (20431)
	ZC_MSG_OPENDOOR_USERDOORCAMERARELATION,              ///<(51182)��ȡ�û��Ž�����ͷ������Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_USERDOORCAMERARELATION (20432)
	ZC_MSG_OPENDOOR_GETAPPLYHISTORYLOCKINFO,             ///<(51183)��ȡ��֤��ʷ��Ϣ���Ƿ��������������� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_GETAPPLYHISTORYLOCKINFO (20433)
	ZC_MSG_OPENDOOR_STAFFINFOOPERATION,                  ///<(51184)������Ա��Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_STAFFINFOOPERATION (20434)
	ZC_MSG_OPENDOOR_DEPARTMENTINFOOPERATION,             ///<(51185)���ò�����Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_DEPARTMENTINFOOPERATION (20435)
	ZC_MSG_OPENDOOR_STAFFSTATUS_SET,                     ///<(51186)������Ա״̬���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_STAFFSTATUS_SET (20436)
	ZC_MSG_OPENDOOR_DEPARTMENTINFO_GET,                  ///<(51187)��ȡ������Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_DEPARTMENTINFO_GET (20437)
	ZC_MSG_OPENDOOR_AUTHGROUP_GET,                       ///<(51188)��ȡȨ������Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_AUTHGROUP_GET (20438)
	ZC_MSG_OPENDOOR_STAFFINFO_GET,                       ///<(51189)��ȡ��Ա��Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_STAFFINFO_GET (20439)
	ZC_MSG_OPENDOOR_STAFFOPERATION_GET,                  ///<(51190)��ȡ��Ա������Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_STAFFOPERATION_GET (20440)
    ZC_MSG_OPENDOOR_STAFFAUTHINFO_GET,                   ///<(51191)��ȡ��ԱȨ������Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_STAFFAUTHINFO_GET (20441)
    ZC_MSG_OPENDOOR_DOOROPENSYRELATION_SET,              ///<(51192)���������֤��Ѻ��Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_DOOROPENSYRELATION_SET (20442)
    ZC_MSG_OPENDOOR_ACCESSSYRELATION_GET,                ///<(51193)��ȡ�Ž�������Ѻ�豸��Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_ACCESSSYRELATION_GET (20443)
    ZC_MSG_OPENDOOR_DOOROPENSYRELATION_GET,              ///<(51194)��ȡ��֤��Ѻ������Ϣ���� @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_DOOROPENSYRELATION_GET (20444)
    ZC_MSG_OPENDOOR_QUERYHISTORYINFO_SY_GET,             ///<(51195)��ѯ��֤��ʷ��Ϣ���ɰ���֤���Ͳ�ѯ������ @note ������Ϣֵ:\ref ZC_MSG_APP_OPENDOOR_QUERYHISTORYINFO_SY_GET (20445)
 
	ZC_MSG_OPENDOOR_OPENDATAMANAGER = 51200,             ///<(51200)����򿪲�ѯ��ͳ�ƹ������
	ZC_MSG_OPENDOOR_OPENBASESET,                         ///<(51201)����򿪻������ý���
	ZC_MSG_OPENDOOR_OPENUSERMANAGER,                     ///<(51202)�������Ա�������
}E_ZC_MSG_OPENDOOR;
/** @} */

/** @defgroup ZCSysDorctorMsgTypeDefine ������άģ����Ӧ��Ϣ����ö��  
 * �����������֤ģ����Ӧ��Ϣ����ֵ
 * @{
 */
typedef enum
{
	ZC_MSG_SYSDORCTOR_DISPOSALINFO = 52000, ///<(52000)������ά��ǰ�û�Ȩ����Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DISPOSALINFO (20500)

    ZC_MSG_SYSDORCTOR_CMSINFO = 52010,    ///<(52010)��������Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_CMSINFO (20510)
	ZC_MSG_SYSDORCTOR_AREAINFO,           ///<(52011)��������Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_AREAINFO (20511)
	ZC_MSG_SYSDORCTOR_DEVINFO,            ///<(52012)��������Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DEVINFO (20512) 
	ZC_MSG_SYSDORCTOR_CAMERAINFO,         ///<(52013)̽ͷ����Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_CAMERAINFO (20513)
    ZC_MSG_SYSDORCTOR_DEVINFO_EX,         ///<(52014)��������Ϣ��ȡ�������(�����ʲ����) @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DEVINFO_EX (20514) 
	ZC_MSG_SYSDORCTOR_CAMERAINFO_EX,      ///<(52015)̽ͷ����Ϣ��ȡ�������(�����ʲ����) @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_CAMERAINFO_EX (20515) 
	
	ZC_MSG_SYSDORCTOR_MANUFACTUREINFOINCAPITAL = 52019, ///<(52019)�����豸Ʒ����Ϣ(ֻ�����ʲ���Ϣ�д��ڵ�)��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MANUFACTUREINFOINCAPITAL (20519)
    ZC_MSG_SYSDORCTOR_MANUFACTURENAME = 52020, ///<(52020)�����豸Ʒ����Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MANUFACTURENAME (20520)    
    ZC_MSG_SYSDORCTOR_MODELNO,                 ///<(52021)�豸�ͺ���Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MODELNO (20521) 
    ZC_MSG_SYSDORCTOR_SUPPLIERCOMPANY,         ///<(52022)���й�Ӧ����Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_SUPPLIERCOMPANY (20522) 
    ZC_MSG_SYSDORCTOR_MAINTENCECOMPANY,        ///<(52023)����ά������Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENCECOMPANY (20523) 
    ZC_MSG_SYSDORCTOR_MAINTENCEPHONE,          ///<(52024)����ά���̵绰��Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENCEPHONE (20524) 
    ZC_MSG_SYSDORCTOR_ENGINEERINGNAME,         ///<(52025)���й�������Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_ENGINEERINGNAME (20525) 
    ZC_MSG_SYSDORCTOR_ALARMHOSTINFO,           ///<(52026)���б���������Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_ALARMHOSTINFO (20526) 
    ZC_MSG_SYSDORCTOR_ALARMARMDISARMPLAN,      ///<(52027)���б��������������ƻ���Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_ALARMARMDISARMPLAN (20527)
    ZC_MSG_SYSDORCTOR_HOSTUSESTATUS,	       ///<(52028)��������ʹ��״̬��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_HOSTUSESTATUS (20528)
    ZC_MSG_SYSDORCTOR_DETECTORUSESTATUS,	   ///<(52029)����̽ͷʹ��״̬��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DETECTORUSESTATUS (20529)

    ZC_MSG_SYSDORCTOR_DEVCAPITALINFO = 52030,  ///<(52030)�豸�����ʲ���Ϣ��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DEVCAPITALINFO (20530) 
    ZC_MSG_SYSDORCTOR_SETDEVCAPITALINFO,       ///<(52031)�豸�����ʲ���Ϣ�޸Ľ������ @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_SETDEVCAPITALINFO (20531)
    ZC_MSG_SYSDORCTOR_STATDEVCAPITALINFO,      ///<(52032)�豸�����ʲ���Ϣͳ�ƽ������ @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_STATDEVCAPITALINFO (20532) 
    ZC_MSG_SYSDORCTOR_OMRECORDDAYSMODULE,      ///<(52033)��ȡͨ��¼��ģ��������Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_OMRECORDDAYSMODULE (20533) 
    ZC_MSG_SYSDORCTOR_DETECTMODULEINFO,        ///<(52034)��ȡͨ��¼��ģ���Ƿ�������Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DETECTMODULEINFO (20534) 
    ZC_MSG_SYSDORCTOR_SOFTSETCHANNELRECORDDAYS,///<(52035)����¼������ģ��ID��ȡ��������ͷ��Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_SOFTSETCHANNELRECORDDAYS (20535) 
    ZC_MSG_SYSDORCTOR_IOMOPERATIONINFO,        ///<(52036)��ȡһ����ά��Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_IOMOPERATIONINFO (20536) 

    ZC_MSG_SYSDORCTOR_FAULTINFO = 52040,           ///<(52040)���й���������Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_FAULTINFO (20540)
    ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO,             ///<(52041)���޼�¼��Ϣ��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO (20541) 
    ZC_MSG_SYSDORCTOR_MAINTENCEINFO,               ///<(52042)ά�޼�¼��Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO (20542)
    ZC_MSG_SYSDORCTOR_ADDMALFUNCTIONINFO,          ///<(52043)�������޼�¼��Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_ADDMALFUNCTIONINFO (20543) 
    ZC_MSG_SYSDORCTOR_ADDMAINTENCEINFO,            ///<(52044)����ά�޼�¼��Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_ADDMAINTENCEINFO (20544) 
    ZC_MSG_SYSDORCTOR_STATMALFUNCTIONINFO,         ///<(52045)���޼�¼��Ϣͳ�ƽ������ @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_STATMALFUNCTIONINFO (20545)
    ZC_MSG_SYSDORCTOR_DEVICEBASEINFOBYID,          ///<(52046)�����豸��������豸������Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOBYID (20546)
    ZC_MSG_SYSDORCTOR_DEVICEBASEINFOBYCAPITALCODE, ///<(52047)�����豸�ʲ���������豸������Ϣ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOBYCAPITALCODE (20547)
    ZC_MSG_SYSDORCTOR_DEVICEBASEINFOGET_NEW,       ///<(52048)��ȡ�豸������Ϣ_NEW������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DEVICEBASEINFOGET_NEW (20548)
    ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO_GET_NEW,     ///<(52049)���޼�¼��Ϣ��ѯ_NEW������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO_GET_NEW (20549)

	ZC_MSG_SYSDORCTOR_DVRONLINESTATE = 52060, ///<(52060)�����������״̬��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DVRONLINESTATE (30400) 
	ZC_MSG_SYSDORCTOR_ALARMHOSTSTATE,         ///<(52061)��������״̬��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_ALARMHOSTSTATE (30401) 
    ZC_MSG_SYSDORCTOR_DEVTIMEINFO,            ///<(52062)�������ʱ��״̬��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVTIMEINFO (30402) 
    ZC_MSG_SYSDORCTOR_SETDEVTIMEINFO,         ///<(52063)�������ʱ��״̬���ý������ @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_SETDEVTIMEINFO (30403) 
    ZC_MSG_SYSDORCTOR_DEVCHANNELSTATE,        ///<(52064)�������ͨ��״̬��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVCHANNELSTATE (30404)
	ZC_MSG_SYSDORCTOR_DEVDISKSTATE,           ///<(52065)�������Ӳ��״̬��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVDISKSTATE (30405)
    ZC_MSG_SYSDORCTOR_DEVCHECKVIDEO,          ///<(52066)�������Ӳ��״̬��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_DEVCHECKVIDEO (30406)
    ZC_MSG_SYSDORCTOR_ACCESSSTATE,            ///<(52067)�Ž�����״̬��ѯ������� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_ACCESSSTATE (30407)
    ZC_MSG_SYSDORCTOR_VIDEOQUALITY,           ///<(52068)��ѯ��Ƶ�������Ѳ�������� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_VIDEOQUALITY (30408)
    ZC_MSG_SYSDORCTOR_NODESTATE,              ///<(52069)��ѯ�ڵ�״̬���������ڵ㣩������� @note ������Ϣֵ:\ref ZC_MSG_BCBCLIENT_SYSDORCTOR_NODESTATE (30409)

    /**
	 * @brief (52080)�����������ά������
	 *
	 * ������άһ���У�����ϢΪ������豸��Ϣ�������
	 *
	 * @note ����ϢΪ����������Ϣ���ݲ���Ҫ����
	 */
    ZC_MSG_SYSDORCTOR_OPENDEVICEMANAGER = 52080, 

	/**
	 * @brief (52081)������ά���ڲ���ʹ��
	 *
	 * ������άһ���У�����ϢΪ�����״̬��ѯ�������
	 *
	 * @note ����ϢΪ����������Ϣ���ݲ���Ҫ����
	 */        
    ZC_MSG_SYSDORCTOR_OPENCHECKSTATEMANAGER, 

	/**
	 * @brief (52082)������ά���ڲ���ʹ��
	 *
	 * ������άһ���У�����ϢΪ����򿪹��Ϲ������
	 *
	 * @note ����ϢΪ����������Ϣ���ݲ���Ҫ����
	 */  
    ZC_MSG_SYSDORCTOR_OPENREPAIRMANAGER, 

	ZC_MSG_SYSDORCTOR_CHANNELDETECTMODULE_OPERATION_NEW,  ///<(52083)ͨ�����ģ����ز���������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_CHANNELDETECTMODULE_OPERATION_NEW (20550)
	ZC_MSG_SYSDORCTOR_OMRECORDDAYSMODULE_GET_NEW,         ///<(52084)������ά��ȡ¼������ģ�������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_OMRECORDDAYSMODULE_GET_NEW (20551)
	ZC_MSG_SYSDORCTOR_MALFUNCTION_NEW_GET,                ///<(52085)���޹����������ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTION_NEW_GET (20552)
	ZC_MSG_SYSDORCTOR_FAULTTREATMENT_GET,                 ///<(52086)������ά���ϴ����¼������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_FAULTTREATMENT_GET (20553)
	ZC_MSG_SYSDORCTOR_MAINTENANCERECORD_GET,              ///<(52087)������άά�޼�¼������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENANCERECORD_GET (20554)
	ZC_MSG_SYSDORCTOR_REVIEWANDEVALUTION_GET,             ///<(52088)������ά���������ۼ�¼������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_REVIEWANDEVALUTION_GET (20555)
	ZC_MSG_SYSDORCTOR_FAULTDEVICEINFO_ADD,                ///<(52089)������ά���ϼ�¼д�������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_FAULTDEVICEINFO_ADD (20556)
	ZC_MSG_SYSDORCTOR_FAULTDEVICEHANDLEINFO_ADD,          ///<(52090)������ά���ϴ����¼д�������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_FAULTDEVICEHANDLEINFO_ADD (20557)
	ZC_MSG_SYSDORCTOR_MALFUNCTIONINFO_ADD,                ///<(52091)���ܱ��޼�¼д�������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MALFUNCTIONINFO_ADD (20558)
	ZC_MSG_SYSDORCTOR_MAINTENCEINFO_ADD,                  ///<(52092)������άά�޼�¼д�������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENCEINFO_ADD (20559)
	ZC_MSG_SYSDORCTOR_CHECKINFO_ADD,                      ///<(52093)������ά���˼�¼д�������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_CHECKINFO_ADD (20560)
	ZC_MSG_SYSDORCTOR_DEVICEFAULTINFO_SET,                ///<(52094)�豸��ʷ���ϼ���������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_DEVICEFAULTINFO_SET (20561)
	ZC_MSG_SYSDORCTOR_NEW_FAULTEXTREMELYINFO_GET,         ///<(52095)��ȡ�����쳣���������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_NEW_FAULTEXTREMELYINFO_GET (20562)
	ZC_MSG_SYSDORCTOR_NEWFAULTDEVICEADDITIONAL_ADD,       ///<(52096)IOM���־���������͹��ϼ�¼д�������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_NEWFAULTDEVICEADDITIONAL_ADD (20563)
	ZC_MSG_SYSDORCTOR_NEW_SUPPLIERMAINTENANCE_OPERATION,  ///<(52097)������Ϣ����������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_NEW_SUPPLIERMAINTENANCE_OPERATION (20564)
	ZC_MSG_SYSDORCTOR_NEW_SUPPLIERMAINTENANCEINFO_GET,    ///<(52098)������Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_NEW_SUPPLIERMAINTENANCEINFO_GET (20565)
	ZC_MSG_SYSDORCTOR_NEW_CAPTICALINFONEW_OPERATION,      ///<(52099)�ʲ���Ϣ����������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_NEW_CAPTICALINFONEW_OPERATION (20566)
	ZC_MSG_SYSDORCTOR_NEW_CAPTICALINFO_NEW_GET,           ///<(52100)�ʲ���Ϣ��ȡ������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_NEW_CAPTICALINFO_NEW_GET (20567)
    ZC_MSG_SYSDORCTOR_NEW_DETECTSCHEDULE_GET,             ///<(52101)��ȡѲ��ƻ�������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_NEW_DETECTSCHEDULE_GET (20568)  
	ZC_MSG_SYSDORCTOR_CAPTICALADDITIONALINFO_GET,         ///<(52102)�ʲ�״̬ͳ��_Additional������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_CAPTICALADDITIONALINFO_GET (20569)  
    ZC_MSG_SYSDORCTOR_CAPTICALSTATISTICSINFO_GET,         ///<(52103)�ʲ�״̬ͳ�ƽ������ @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_CAPTICALSTATISTICSINFO_GET (20570)  
    ZC_MSG_SYSDORCTOR_FAULTSTATISTICSINFO_GET,            ///<(52104)����ͳ�ƽ������ @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_FAULTSTATISTICSINFO_GET (20571)  
    ZC_MSG_SYSDORCTOR_MAINTENANCESTATISTICSINFO_GET,      ///<(52105)ά������ͳ�ƽ������ @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_MAINTENANCESTATISTICSINFO_GET (20572)  
    ZC_MSG_SYSDORCTOR_CAPTICALAREAEXCEPTIONINFO_GET,      ///<(52106)�����쳣�ʲ�ͳ�ƽ������ @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_CAPTICALAREAEXCEPTIONINFO_GET (20573)  
    ZC_MSG_SYSDORCTOR_BATCHMALFUNCTIONINFO_SET,           ///<(52107)IOM�������޴��������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_BATCHMALFUNCTIONINFO_SET (20574)  
    ZC_MSG_SYSDORCTOR_FAULTIDBYDEVICEDETAILINFO_GET,      ///<(52108)�����豸��Ϣ��ȡ����ID������� @note ������Ϣֵ:\ref ZC_MSG_APP_SYSDORCTOR_FAULTIDBYDEVICEDETAILINFO_GET (20575)
}E_ZC_MSG_SYSDORCTOR; 
/** @} */
/** @} */

///���õ�ǰ��λ�ı�������״̬����ö��
typedef enum
{
	ZC_MSG_ALARM_SETUSERSTATUSFREE     = 10,     ///��ǰ�û�δ����������
	ZC_MSG_ALARM_SETUSERSTATUSONELEVEL,          ///���ڴ���1�౨��
	ZC_MSG_ALARM_SETUSERSTATUSTWOLEVEL,          ///���ڴ���2�౨��
	ZC_MSG_ALARM_SETUSERSTATUSTHREELEVEL,        ///���ڴ���3�౨��
	ZC_MSG_ALARM_SETUSERSTATUSFOURLEVEL,         ///���ڴ���4�౨��
	ZC_MSG_ALARM_SETUSERSTATUSFIVELEVEL,         ///���ڴ���5�౨��
	ZC_MSG_ALARM_SETUSRESTATUSDELAYTIME = 21,	 ///�е���ʱ
}E_ZC_MSG_SETUSERSTATUS;

/************************************************************************/
/*                            �ṹ�嶨��                                */
/************************************************************************/
#define NODE_NAME_LEN 64
#define NODE_CODE_LEN 64
#define CENTER_CODE_LEN 128
#define DEVICE_NAME_LEN 128
#define DEVICE_CODE_LEN 64
#define DEVICE_IP_LEN 32
#define DEVICE_MODEL_LEN 128
#define DEVICE_MANUFACTURE_LEN 64
#define DEVICE_SUPPLIER_LEN 64
#define CONTRACT_INFO_LEN 64
#define MAINTENANCE_INFO_LEN 64
#define CAPITAL_CODE_LEN   20

typedef enum
{
	ON_USE = 1,
	ON_REPAIR,
	ON_DISABLE
}E_DEVICE_STATUS;

//��ǰ�û���Ϣ�ṹ��1��
typedef struct
{
    char chUserName[64];           // �û���		
}T_CURUSER_INFO, *LPT_CURUSER_INFO;

typedef struct
{
    int nId;                       // �û�ID
    char chUserName[64];           // �û���	
    int  nLevel;                   // �û�����
    char chRole[128];              // �û���ɫ    	
}T_CURUSER_INFO_EX, *LPT_CURUSER_INFO_EX;

//���û���¼��Ϣ�ṹ��2��
typedef struct
{
    char chUserName[64];           // �û���		
	char chPassWord[64];           // ����
}T_NEWLOGINUSER_INFO, *LPT_NEWLOGINUSER_INFO;

//�û����Ӱ���Ϣ�ṹ��3��
typedef struct
{
    int nScheduleID;               //�Ű�ID  
	char chUserName[64];           //�û�����
    char strRole[64];              //�û���ɫ
    char chPassWord[64];           //�û�����
	char chHandoverTime[32];       //�Ӱ�ʱ��
	char chImage[512];             //�û�ͷ��
	unsigned short nAlarmCount;    //��������
	bool bMonitor;                 //�Ƿ�ӵ�н��Ӱ����Ȩ��  
	bool bHandover;                //�Ƿ�����ɽ��Ӱ�
}T_USER_HA_INFO, *LPT_USER_HA_INFO;

//ϵͳ��ɫ��Ϣ�ṹ��4��
typedef struct
{
    int nRoleId;                //��ɫ��� 
    char strRole[64];           //��ɫ����		
}T_ROLE_INFO, *LPT_ROLE_INFO;

//������ϸ��Ϣ�ṹ��5��
typedef struct
{
	int nTaskID;                   // ����ID
	char chTaskName[64];           // ��������
	char chDescription[512];       // ��������
	int nOperation;                // ����������� 1-�鿴��Ƶ 2-¼��ط�
	char chOperName[32];           // ���������������
	char chEffectiveBeginDate[32]; // ��Ч�ڿ�ʼʱ��
	char chEffectiveEndDate[32];   // ��Ч�ڽ���ʱ��
	int nLoopMethod;               // ѭ������ 1-ÿ�� 2-ÿ�� 3-ÿ��
	char chLoopMemo[512];          // ѭ����ע
	bool bDoTimeRange;             // �Ƿ�涨����ʱ�䷶Χ
	char chStartTime[32];          // ��ʼʱ��
	char chEndTime[32];            // ����ʱ��
	bool bStartInTime;             // �Ƿ�涨׼ʱִ��
	bool bEngInTime;               // �Ƿ�ǿ��Ҫ���ֹʱ��
	bool bWarn;                    // �Ƿ񵽵�����
	int nWarnMinu;                 // ����ǰX��������
	bool bTotalTime;               // �Ƿ�涨����ִ��ʱ��
	int nToTalTime;                // ����ִ��ʱ������λ�����ӣ�
	int nTotalTimes;               // ִ�д���
	bool bRuleTimes;               // �Ƿ�ǿ��ֵ��Ա��ִ�в鿴��Ƶʱ�Ե����ƵԤ��ƵĻ��ΪѲ���Ҫ����
	int nRuleTimes;                // ÿ������ÿ·��Ƶ���ٵ������
	char chInstructions[1024];     // ����ָ��
	bool bTaskLevel;               // �Ƿ�涨������Ҫ�ȼ�
	int nTaskLevel;                // ������Ҫ�ȼ����ȼ���ID��û�й涨��ʱ��Ϊ0
	bool bError;                   // �Ƿ��쳣�ο�
	int nError;                    // �쳣��ID��û��ʱΪ0
	char chErrorLabel[128];        // �����ǩ
	int nClassId;                  // ���ΨһID
	char chClassName[32];          // �������
	char chStatus[32];             // ����״̬��1-δ�·���2-δ��ɣ�3-���·���
	char chType[32];               // �������ͣ�1-�ճ�����2-ͻ������
	char chRoleNames[1024];        // �·����󣨽�ɫ����,����
	char chKeyPartName[128];       // ��λ����
	int nObject;                   // ���ⳡ��Ϊ1�����峡��Ϊ2
	char chPlaceNames[30000];      // ���ⳡ������峡�����ƣ�,����
}T_ALL_TASKINFO, *LPT_ALL_TASKINFO;

//������ϸ��Ϣ�ṹ��6��
typedef struct
{
	int nTaskID;                              // ����ID
	char chTaskName[64];                      // ��������
	char chOperName[32];                      // ������������
	char chClassName[32];                     // �������
	char chRoleNames[1024];                   // �·����󣨽�ɫ����,����
	char chEffectiveBeginDate[32];            // ��Ч�ڿ�ʼʱ��
	char chEffectiveEndDate[32];              // ��Ч�ڽ���ʱ��
	char chStartTime[32];                     // ��ʼʱ��
	char chEndTime[32];                       // ����ʱ��
	bool bWarn;                               // �Ƿ񵽵�����
	char chTI_Status_Int[32];                 // ����״̬��δ�·���δ��ɣ����·���
	char chTI_Type_Int[32];                   // �������ͣ��ճ�����ͻ������
}T_SUB_TASKINFO,*LPT_SUB_TASKINFO;

//��Ϣ��ѯ���ڽṹ��7��
typedef struct
{
	char chBeginDate[32];                     // ��ѯ��ʼ����
	char chEndDate[32];                       // ��ѯ��������    
}T_SEARCHDATE,*LPT_SEARCHDATE;

//����ģ�������Ϣ�ṹ��8��
typedef struct
{
    int  nScheduleID;                         // �Ű�ID
    char chUserName[64];                      // �û�����
	char chRoleName[64];                      // ��ɫ����
    int  nRoleID;                             // ��ɫ���
	int  nClassID;                            // ��α��
    bool bModuleAuthoritys[4];                // ģ��Ȩ��[0-�Ű�,1-������,2-���񸴺�,3-ֵ�೤���Ӱ�]
}T_TASKMCURUSERINFO,*LPT_TASKMCURUSERINFO;

//����ʼִ�нṹ��9��
typedef struct
{
    int nOperation;                // ����������� 1-�鿴��Ƶ 2-¼��ط�
	char chAreaName[64];           // ����ִ���������ƣ����Բ鿴��Ƶʱ��ɸѡ�ڵ���
	char chGuid[64];			   // ����ִ��ΨһGUID
	int nModule;                   // 1-�������ã�2-�ճ�Ѳ�飻3-�Ž���֤
	char chReserved[16];           // ����
}T_DOTASKINFO,*LPT_DOTASKINFO;

//���Ͷ��Žṹ��10��
typedef struct
{
    char chMsg[256];              // ��������
	char chContactMan[64];        // ���������� 
	char chTelephone[32];         // �����˵绰����
}T_SENDSHORTMESSAGEINFO,*LPT_SENDSHORTMESSAGEINFO;

//����绰�ṹ��11��
typedef struct
{
    char chDestName[64];           // Ŀ������
    char chManName[64];            // ����������
    char chTelephone[32];          // �绰����     
}T_TELEPHONECALLINFO,*LPT_TELEPHONECALLINFO;

//�����ṹ��12��
typedef struct
{ 
    char chAttachment[256];       // ��������
}T_ATTACHMENTINFO,*LPT_ATTACHMENTINFO;

//�·���������ṹ��13��
typedef struct
{
    char chReceiveUserName[64];                // ��������û���
	P_NEW_INSPECT_FASTTASKINFOSET sTaskInfo;   // ����������Ϣ
}T_TRANS_FASTTASKINFO,*LPT_TRANS_FASTTASKINFO;

//�������Ȩ�޽ṹ��14��
typedef struct
{
    bool bAssignPosal;      // �Ƿ��б�������Ȩ�� 
	bool bCheckPosal;       // �Ƿ��б�������Ȩ��
	bool bChangePosal;      // �Ƿ��о��顢�ȼ��޸�Ȩ��
	bool bDecidePosal;      // �Ƿ��ж���Ȩ��
}T_ALARMPOSALINFO,*LPT_ALARMPOSALINFO;

//��������֤���Ȩ�޽ṹ
typedef struct
{
	bool bUserInfoSetPosal;  // �Ƿ�����Ա��ɾ��Ȩ�� 
	bool bEnteringPosal;     // �Ƿ�¼��Ȩ��
	bool bDealWithPosal;     // �Ƿ���֤����Ȩ��
	bool bCheckPosal;        // �Ƿ������Ȩ��
	bool bQueryPosal;        // �Ƿ��м�¼��ѯȨ��
}T_OPENDOORPOSALINFO,*LPT_OPENDOORPOSALINFO;

///<������ά���Ȩ�޽ṹ
typedef struct
{
	bool bNormalPosal;   ///< �Ƿ�����ͨʹ��Ȩ�� 
	bool bDevInfoPosal;  ///< �Ƿ����豸��Ϣ����Ȩ��
	bool bReviewPosal;	///< �Ƿ��б��޹�����Ȩ��
}T_SYSDORCTORPOSALINFO,*LPT_SYSDORCTORPOSALINFO;

//����������������ṹ��15��
typedef struct
{
    int nAlarmSourceType;    // ����Դ���ͣ� 0-���� 1-����ͷ��̽ͷ
	char chAlarmSource[64];  // ����Դ����
}T_ALARMLINKOPERATEPRARM,*LPT_ALARMLINKOPERATEPRARM;


typedef struct
{
	int nAlarmSourceType;    ///< ����Դ���ͣ� 0-���� 1-����ͷ��̽ͷ
	char chAlarmSource[64];  ///< ����Դ����
	char chGuid[64];         ///< ��֤����GUID
}T_OPENDOORLINKVIDEOPRARM,*LPT_OPENDOORLINKVIDEOPRARM;

//��������¼��ط���������ṹ��16��
typedef struct
{
    int nAlarmSourceType;    // ����Դ���ͣ� 0-���� 1-����ͷ��̽ͷ
	char chAlarmSource[64];  // ����Դ����
	char chAlarmTime[32];    // ����ʱ�䣨��ʽ2015-01-01 00:00:00��  
}T_ALARMREPLAYPARAM,*LPT_ALARMREPLAYPARAM;

//��Ƶ���ز��ϴ���������ṹ
typedef struct
{
    int nAlarmSourceType;    // ����Դ���ͣ� 0-���� 1-����ͷ��̽ͷ
	char chAlarmSource[64];  // ����Դ����
	TJTY_TIME tBeginTime;    // ��Ƶ������ʼʱ��
	TJTY_TIME tEndTime;      // ��Ƶ���ؽ���ʱ��
}T_ALARMDWONANDUPLOADPARAM,*LPT_ALARMDWONANDUPLOADPARAM;

/*
* @��̬������������ṹ��17��
*
* ��ֵʾ������
* ��A����@ĳ�ˣ���ĳ�˷���̬��Ϣ��   
* {
*    T_ADDEVENTINFO info = {0}; 
*    strcpy_s(info.chContext,1024,"@�����û��� ");    //�û�����Ŀո񲻿�ʡ  
*    //������£��������������ɲ��ø�ֵ     
* }
* ��B����ת��������ĳ��
* {
*    T_ADDEVENTINFO info = {0}; 
*    sprintf_s(info.chContext,1024,"%s����������һ��������Ϣ[���ƣ�%s �������ͣ�%s ����ʱ�䣺%s]",...);  
*    sprintf_s(info.chSource,128,"[�������:%d]%s",...);   
*  }
*/
typedef struct
{
    char chContext[1024];     // ��̬����ʱԤ����������
    char chSource[128];       // ��̬Դ����ҪĳЩ����������ʱ��ֵ��
    char chTime[64];          // ��̬����ʱ�䣨������������ֵʱ�������   	
}T_ADDEVENTINFO,*LPT_ADDEVENTINFO;

///<ת�������ṹ��/Ѳ�������ͽṹ��
typedef struct
{
	unsigned char ucChannel;    ///< ����ͨ���Ż򱨾�����������
	unsigned char ucDevType;    ///< �����豸����(����Դ���ͣ�0-���� 1-����ͷ��̽ͷ)
	unsigned char ucAlarmType;  ///< ��������/Ѳ���쳣�¼�E_EVENTPATROL_EXCEPT
	unsigned char ucReserved;   ///< �����ȼ�
	char chMemo[128];           ///< ������Ϣ/��ע��Ϣ[���������š�����ʱ����Ϣ]	ǰ64�ֽ�����������64�ֽ��Ǹ���
	int	 nDealType;             ///< 9999��Ѳ���쳣�౨���� ����ֵ������ԭ������:0-�����˹�����  1-δ����chDealUser��ʾָ���Ĵ����������� 8-δ���䣨chDealUser��ʾ�������Ϣ��ֵ�೤������
	char chDealUser[64];        ///< ����������/ip��ַ
}T_TRANSMITALARMENTITY,*LPT_TRANSMITALARMENTITY;

///<���屨����չ���ݽṹ��
typedef struct
{
    char guid[64];                              ///< ����Ψһ��ʶ
    int  videoseconds;                          ///< ����¼��������Ϊ0��¼��
    int  picturescount;                         ///< ����ץͼ������Ϊ0��ץͼ��
    int  reserved1;                             ///< ����1	0-����    1-����
    char reserved2[32];                         ///< ����2
}T_TRANSMITALARMENTITY_EX,*lPT_TRANSMITALARMENTITY_EX;

struct T_TRANSMITALARMINFO
{
    char chDevID[20];           ///< �豸ID(�ַ���)
    long nDevNumber;            ///< �豸ID(����)
    char chAlarmSource[128];    ///< ����Դ����
	char chArea[64];            ///< ��������
    char chAlarmDateTime[32];   ///< ��������ʱ��
	char chKeyPart[64];         ///< ������λ
    T_TRANSMITALARMENTITY tAlarmInfo;        ///< ���屨����Ϣ/Ѳ������Ϣ
};

typedef struct
{
    T_TRANSMITALARMINFO      tTransmitAlarmInfo;     ///< ���屨����Ϣ/Ѳ������Ϣ
    T_TRANSMITALARMENTITY_EX tAlarmInfo_Ex;          ///< ���屨����չ��Ϣ
}T_TRANSMITALARMINFO_EX,*LPT_TRANSMITALARMINFO_EX;

//Ѳ���쳣�¼�
typedef enum 
{
	PATROL_EXCEPT_UNSUPPORT = 1,    // ��֧��
	PATROL_EXCEPT_OFFLINE,          // ����
	PATROL_EXCEPT_GET_FAIL,         // ��ȡʧ��

	// ������״̬
	PATROL_EXCEPT_ARM_STATE = 10,   // �����쳣
	PATROL_EXCEPT_DISARM_STATE,		// �����쳣

	// ʱ��״̬
	PATROL_EXCEPT_CLOCK_STATE = 20, // ʱ���쳣

	// Ӳ��״̬
	PATROL_EXCEPT_DISK_STATE = 30,  // �����쳣
	PATROL_EXCEPT_DISK_FULL,        // ��������

	// ¼��״̬
	PATROL_EXCEPT_RECORD_STATE = 40,// ¼���쳣

	// ¼������
	PATROL_EXCEPT_RECORD_DAYS = 50, // ¼����������

	// ¼��������
	PATROL_EXCEPT_RECORD_INTEGRITY = 60,// ¼��ȱʧ

	// ��Ƶ�������
	PATROL_EXCEPT_VQ_LOST = 70,			// ��Ƶ��ʧ
	PATROL_EXCEPT_VQ_FOGGY,				// ͼ��ģ��
	PATROL_EXCEPT_VQ_LUMINANCE,			// �����쳣
	PATROL_EXCEPT_VQ_CHROMINANCE,		// ͼ��ƫɫ
	PATROL_EXCEPT_VQ_SNOWFLAKE,			// ѩ������
	PATROL_EXCEPT_VQ_STRIPE,			// ���Ƹ���
	PATROL_EXCEPT_VQ_SHAKE,				// ���涶��
    PATROL_EXCEPT_KOALA_QUICK_ALARM = 198,	// ����һ������
		
    // ���ڵ�״̬
	PATROL_EXCEPT_NODE_CPU_HIGH = 100,	// CPUʹ���ʹ���
	PATROL_EXCEPT_NODE_MEM_HIGH,		// �ڴ�ʹ���ʹ���
	PATROL_EXCEPT_NODE_NET_HIGH,		// ����ʹ���ʹ���
}E_EVENTPATROL_EXCEPT;

/************************************************
****������Ϣ��
*ʱ��״̬�쳣
*���������������ʾʱ����ˣ�������ʾʱ������
*����ʾ���� ��100��
*����ʾ������-100��

****¼�������쳣
*��������
*���� ��3��

****¼���������쳣
ʾ���� ��<2><2015-12-12 19:36:00 2015-12-12 19:39:00><2015-13-13 19:45:00 2015-13-13 19:47:00>��

<2>��¼��ȱʧʱ��ε�����
<2015-12-12 19:36:00 2015-12-12 19:39:00>����1��ȱʧʱ���
<2015-13-13 19:45:00 2015-13-13 19:47:00>����2��ȱʧʱ���

****�������������쳣
ʾ���� ��<2000><1800>��

2000����������MB��
1800����ʹ��������MB��
*************************************************/

typedef struct
{
    int nAreaId;                      //�ڵ�ID
	char chCode[32];                  //�ڵ����
	char chName[64];                  //�ڵ�����
	char chFatherNo[32];              //��һ������
	char chAddress[128];              //�����ַ
	char chManName[64];               //��ϵ��
	char chContactInfo[64];           //��ϵ��ʽ
	int nAreaTypeID;                  //�ڵ�����ID��1~8,9,10,11,12,13��
	char chNodeTypeName[64];          //�ڵ�������
	int nAreaLevel;                   //�ڵ㼶��1~101,102,103,200,300,400��
	char chCenterNo[128];             //���ı��
	char chFatherCenterNo[128];       //�����ı��	
	int nAreaPosition;                //����		
}T_AREA_INFO, *LPT_AREA_INFO;

//�������沼��ͼ��Ϣ�ṹ��
typedef struct
{
    char chAreaMapPath[256];          //��ͼ��ͼ·��
    int nPosX;                        //�ڵ�X���� ���ڵ�ͼ�ϵ��������*1000��      
    int nPosY;	                      //�ڵ�y���� ���ڵ�ͼ�ϵ��������*1000��
}T_ALARMMAP_INFO,*LPT_ALARMMAP_INFO;

//��Ϣת����Ϣͷ�ṹ��13��
typedef struct
{
    char chReceiveUserName[64];      // ��Ϣ�����û���
    DWORD dwReceiveModuleType;       // ��Ϣ����ģ��ֵ
}T_TRANS_COMMONHEADINFO,*LPT_TRANS_COMMONHEADINFO;

typedef struct
{
    char chReceiveUserName[64];      // ��Ϣ�����û���
    int  nUserType;                  // �û����� ����ǽ-1003 ���ӵ�ͼ-1004 �ֿ�-1005 ����̨-1006
    DWORD dwReceiveModuleType;       // ��Ϣ����ģ��ֵ
}T_TRANS_COMMONHEADINFO_EX,*LPT_TRANS_COMMONHEADINFO_EX;

//��Ϣת����Ϣ��ṹ
typedef struct
{
	unsigned int ucLength;         //��Ϣ�峤��
	unsigned int ucMsgType;        //��Ϣ���
	unsigned int ucOnlineStatus;    //����״̬
	unsigned int ucDealStatus;      //����״̬
	char chDispatcher[64];			//ת���û�
	int nAlarmID;                    //��ر���ID
	T_TRANSMITALARMINFO_EX alarmInfo;   //������Ϣ
}T_TRANS_ALARMMANAGER_INFO,*LPT_TRANS_ALARMMANAGER_INFO;

typedef enum
{
	MT_CHECKONLINE    = 0x01, //��ʱ����
	MT_FEEDBACKONLINE = 0x02, //��ʱ����
	MT_FEEDBACKSTATUS = 0x04, //��ֵ�೤�㱨״̬
	MT_DISTRIBUTE     = 0x08, //ֵ�೤��ֵ��Ա��������
	MT_REVIEWNEEDED   = 0x10, //ֵ��Ա��ֵ�೤���븴��
	MT_REVIEWDONE     = 0x20, //ֵ�೤��ֵ��Ա�����������
}E_TRANS_MESSAGETYPE;

//�ϼ��û���Ϣ
typedef struct
{
    char chMonitorName[64];
	bool bModuleAuthoritys[16];    // ģ��Ȩ��[0-�Ű�,1-������,2-���񸴺�,3-ֵ�೤���Ӱ�,4-�����Ű�Ȩ��,5-��������Ȩ��,6-��������Ȩ��,7-�������顢�ȼ��޸�Ȩ�� 8-��������Ȩ��]
}T_MONITOR_INFO,*LPT_MONITOR_INFO;

//�ϴ�������Ϣ�ṹ
typedef struct
{
    int  nFileType;        //�ļ����� 0-ͼƬ 1-��Ƶ 2-��Ƶ
    char chFilePath[512];  //�ļ�����·��
}T_UPLOADATTACHMENT_INFO,*LPT_UPLOADATTACHMENT_INFO;

typedef struct
{
	char chDeviceName[128];	///<�豸ID
	int nChannelNum;		///<ͨ����
	char chFileName[50];	///<�ļ���
	char chFilePath[250];	///<�ļ�·��
	char chBeginDate[64];	///<��ʼʱ��
	char chEndDate[64];		///<����ʱ��
	int nDateType;			///<�������ͣ�1-��Ƶ ;2-ͼƬ ;3-��Ƶ(�Ͻӿ�ʹ��)
	int nStorageType;		///<�洢���ͣ�1-��Ƶ ;2-ͼƬ ;3-��Ƶ
	int nStorageModule;		///<�洢ģ�飺1-��������;2-�ճ�Ѳ��;3-�Ž���֤
	char chGUID[64];		///<�������ɵ�GUID
}T_CheckInfoTotalData, *LPT_CheckInfoTotalData;

//δ����Ƶץͼʱ����������ṹ��20��
typedef struct
{
    int nDevId;        //����ͨ��ID������ͷ�ı�ţ�
}T_CAPTUREWITHOUTOPEN_INFO,*LPT_CAPTUREWITHOUTOPEN_INFO;

//�Ž�������������ṹ��21��
typedef struct
{
	char chAlarmSource[64];  // ����Դ����
	int nCmd;                // 0-���� 1-���� 2-����   
}T_CONTROLACSHOSTPRARM,*LPT_CONTROLACSHOSTPRARM;

//��ȡ������ϸ��Ϣ
typedef struct
{
	int nType;						// =1:�������ģ�=2:�������ģ�=3:�¼�����
	int nCMSId;						// CMS���ͱ��
	int nCMSFatherId;				// ��CMS�ϼ�CMS���ͱ��
}CMS_INFO,*PCMS_INFO;

//��ȡ����ڵ���ϸ��Ϣ������
typedef struct
{	
	char chCode[NODE_CODE_LEN];             // �ڵ����(���ڹ�����)
	char chName[NODE_NAME_LEN];             // �ڵ�����(������ʾ��)
	char chFatherNo[NODE_CODE_LEN];         // ��һ������(���ڹ�����)
	char chCenterNo[CENTER_CODE_LEN];       // ���ı��
	char chFatherCenterNo[CENTER_CODE_LEN]; // �����ı��
	int nId;								// �ڵ�ID
	int nLevel;								// �ڵ㼶��1~99,100,101,102,200��
}AREA_NODE_INFO,*PAREA_NODE_INFO;

//��ȡ�����豸��Ϣ(DVR����������) 
typedef struct
{
	char chIp[DEVICE_IP_LEN];					// �豸IP��ַ
	char chCode[NODE_CODE_LEN];					// �ڵ����(���ڹ�����)
	char chName[DEVICE_NAME_LEN];				// �豸����(������ʾ��)	
	char chAreaCode[NODE_CODE_LEN];				// �����������
	char chCenterNo[CENTER_CODE_LEN];			// ���ı��
	char chFatherCenterNo[CENTER_CODE_LEN];		// �����ı��
	int nId;									// �ڵ�ID
	int nLevel;									// �ڵ㼶��1~99,100,101,102,200��	
	int nManufacturerType;						// ��������
}DEV_NODE_INFO,*PDEV_NODE_INFO;

//��ȡ������ڵ�
typedef struct
{
	char chCode[NODE_CODE_LEN];					// �ڵ����(���ڹ�����)
	char chName[DEVICE_NAME_LEN];				// �豸����(������ʾ��)
	char chAreaCode[NODE_CODE_LEN];				// �����������
	char chHostCode[NODE_CODE_LEN];				// ������������
	char chCenterNo[CENTER_CODE_LEN];			// ���ı��
	char chFatherCenterNo[CENTER_CODE_LEN];		// �����ı��
	int nId;									// �ڵ�ID
	int nLevel;									// �ڵ㼶��1~99,100,101,102,200��
	int nChannelNo;								// ͨ����
}CAMERA_NODE_INFO,*PCAMERA_NODE_INFO;

//�ղ��ҵ�ͼ��(ͼ������ֵö��)
typedef enum
{
	E_CHART_TYPE_OPENDOOR = 1,			//��������֤�ղ�ͼ������ֵ
	E_CHART_TYPE_ALARM,					//����ģ���ղ�ͼ������ֵ
	E_CHART_TYPE_SYSDOCTOR_DEV_STAT,	//������ά�豸ͳ���ղ�ͼ������ֵ
	E_CHART_TYPE_SYSDOCTOR_MALF_STAT,	//������ά����ͳ���ղ�ͼ������ֵ
}E_CHART_COLLECT_VALUE;
 
// //��ȡ�����豸��Ϣ(DVR����������)  �����ʲ����
// typedef struct
// {
// 	char chIP[20];			///<IP��ַ
// 	char chDeviceCode[32];	///<�豸����
// 	char chDeviceName[128];	///<�豸����
// 	char chUpperCode[32];	///<�����������
// 	int nCenterNo;			///<����ID
// 	int nFatherCenterNo;	///<������ID
// 	int nDeviceId;			///<�豸ID
// 	int nDeviceLevel;		///<�豸�ȼ�
// 	char chCapitalCode[32];	///<�ʲ�����
// 
// }DEVICEINFOWITHCAPITAL_GET_S,*PDEVICEINFOWITHCAPITAL_GET_S;
// //��ȡ������ڵ� �����ʲ����
// typedef struct
// {
// 	char chFrontendCode[32];	///<ǰ���豸����
// 	char chFrontendName[128];	///<ǰ���豸����
// 	char chUpperCode[32];		///<�����������
// 	char chDeviceCode[32];		///<�����豸����
// 	int nCenterNo;				///<����ID
// 	int nFatherCenterNo;		///<������ID
// 	int nDeviceId;				///<�豸ID
// 	int nDeviceLevel;			///<�豸�ȼ�
// 	int nChannelNo;				///<ͨ����
// 	char chCapitalCode[32];		///<�ʲ�����
// 
// }FRONTENDNODEINFOWITHCAPITAL_GET_S,*PFRONTENDNODEINFOWITHCAPITAL_GET_S;

struct TPatrolResult
{
	unsigned int error;			// �����룬0��ʾ�ɹ�
	unsigned int reserved[2];	// ������0
	unsigned int count;			// Ѳ���쳣���������0��ʾһ������
};

// ��Ƶ����Ѳ����
struct TPatrolResultVideoQuality
{
	short channel;				// ��Ƶͨ��
	short event;				// EEventPatrolExcept
	char reserved[4];			// ������0
	char pictureID[32];			// ͼƬ�洢���ļ��������е�ID
};

// �ڵ�״̬����
enum ENodeStateType
{
	NODE_STATE_TYPE_CPU = 1,	//CPU
	NODE_STATE_TYPE_MEMORY,		//�ڴ�
	NODE_STATE_TYPE_NETWORK,	//����
};

// �ڵ�״̬Ѳ����
struct TPatrolResultNodeState
{
	short	type;			//״̬���ͣ��μ�ENodeStateType
	char	flag;			//0-������1-�쳣
	char	param;			//����
	int		total;			//������CPU-�ޣ��ڴ�-MB������-MB��
	double	usage;			//ʹ����
	int		data1;			//����
	int		data2;			//����
	char	reserved[8];	//����
};

//��ȡ����������Ա��Ϣ
typedef struct
{
	int  msg;						// ��Ϣ���ͣ��̶�ֵ��200003��
	char guid[64];					// ����Ψһ��ʶ
	char reserved[32];				// Ԥ��
}TGetOnlineUserToKoala, *LPTGetOnlineUserToKoala;

//������Ա
typedef struct
{
	int  msg;			// ��Ϣ���ͣ��̶�ֵ��201006��
	char guid[64];      // ����Ψһ��ʶ
	int  usercount;		// �û�����������������ȡ�����û�������Ϣ��
}TOnlineUserToZONEE, *LPTOnlineUserToZONEE;

//�����û���Ϣ�������û���Ϣ����
typedef struct
{
	int  busy;			// ״̬��0���У�1��æ��
    long id;            //�û�id
	char name[40];		// �û�����
	char describe[64];	// ����
	char address[64];	// GPS��Ϣ
}TUserInfo, *LPTUserInfo;

//����ȷ�Ͼ��顢ָ����Ա������ָ����ԱЭ��
typedef struct
{
	int	msg;				// ��Ϣ���ͣ��̶�ֵ��200001��
	int operate;			// �������ͣ�0������ȷ�Ͼ��飬1��ָ����Ա������2��ָ����ԱЭ����
	char guid[64];			// Ψһ��ʶ
	char sourcename[40];	// ����Դ����
	char locate[40];		// ����
	char part[40];			// ��λ
	char alarmtype[40];		// ��������
	int  alarmlevel;		// �����ȼ�
	char time[40];			// ����ʱ��
	char address[64];		// GPSλ�ã�Ԥ����
	char describe[256];		// ����
	char files[256];		// ������
	char koalausers[256];	// ������ȷ��������Ա��
}TRequestVerifyAlarmToKoala, *LPTRequestVerifyAlarmToKoala;


//ȷ�Ͼ��鷴��
typedef struct
{
	int	 msg;				// ��Ϣ���ͣ��̶�ֵ��201007��
	int  operate;			// �������ͣ�0��ȷ��������1��ȷ�����������2������������
	int  state;				// 0�����ܣ�1���ܾ�
	char guid[64];			// Ψһ��ʶ
	char time[40];			// ȷ��ʱ��		
	char user[40];			// ������Ա(��һ��ȷ����Ա���ڶ���Э����Ա)
	char describe[256];		// ����
	char files[256];		// ������
	char refusereason[64];	// �ܾ�ԭ��
	char plan[64];			// Ԥ����Ԥ����
}TVerifyAlarmFeedBackToZONEE, *LPTVerifyAlarmFeedBackToZONEE;


//�����ڲ�ָ����Ա�����Ϣ֪ͨ
typedef struct
{
	int	 msg;				// ��Ϣ���ͣ��̶�ֵ��201008��
	char guid[64];			// Ψһ��ʶ
	char time[40];			// ָ��ʱ��		
	char manager[40];		// ָ����
	char executer[128];		// ��ָ����
	char describe[256];		// ����
	char files[256];		// ������
}TAssignmentNotifyToZONEE, *LPTAssignmentNotifyToZONEE;

//����Э��
typedef struct
{
	int	 msg;				// ��Ϣ���ͣ��̶�ֵ��201001�� 
	int	 operate;			// ��������
	char guid[64];			// ����Ψһ��ʶ
	char user[40];			// �û�
	char time[40];			// ����ʱ��
	char describe[256];		// ����
	char files[256];		// ������
	char reserved1[40];		// Ԥ��1
	char reserved2[40];		// Ԥ��2
}TRequestHelpToZONEE, *LPTRequestHelpToZONEE;


//�ϱ�����Ԥ�����л�Ԥ��
typedef struct
{
	int	 msg;			// ��Ϣ���ͣ��̶�ֵ��200002��
	int operate;		// �������ͣ�0���ϱ�Ԥ����1���л�Ԥ����
	int state;			// ��������
	char guid[64];		// Ψһ��ʶ
	char sourcename[40];// ����Դ����
	char alarmtype[40];	// ��������
	int  alarmlevel;	// �����ȼ�
	char planguid[64];	// Ԥ��Ψһ��ʶ
	int	 id;			// Ԥ��id
	char planname[40];	// Ԥ������
	char describe[256];	// ����
	int	 stepscount;	// ���Ӷ�������������������ȡ���Ӷ����������ݣ�
}TDealAlarmInfoToKoala, *LPTDealAlarmInfoToKoala;

//���Ӷ����������������ݣ�
typedef struct
{
	int	order;				// ������ţ���0��ʼ��
	int state;				// ����ִ��״̬��0��ִ���꣬1��������
	char stepguid[64];		// ����Ψһ��ʶ
	int id;					// ����id
	int performer;			// ִ����
	int necessary;			// ����ִ�У�0������ִ�У�1����ѡ��
	char name[40];			// ��������
	char describe[128];		// ��������
	char user[40];			// ������
	char begintime[40];		// ��ʼʱ��
	char endtime[40];		// ����ʱ��
	char files[256];		// ������
}TDealStep, *LPTDealStep;


//���ﴦ�ý����ϱ�
typedef struct
{
	int  msg;				// ��Ϣ���ͣ��̶�ֵ��200004��
	int  state;				// ִ��״̬��0��ִ���꣬1��������
	char guid[64];			// ����Ψһ��ʶ
	char planguid[64];		// Ԥ��Ψһ��ʶ
	int  order;				// ������ţ���0��ʼ��
	char stepguid[64];		// ����Ψһ��ʶ
	int  id;				// ����Id
	char name[40];			// ��������
	char detail[128];		// ��������
	char user[40];			// ������
	char begintime[40];		// ��ʼʱ��
	char endtime[40];		// ����ʱ��
	char describe[256];		// ����
	char files[256];		// ������
}TDealStepToKoala, *LPTDealStepToKoala;


//���ﴦ�ý���
typedef struct
{
	int  msg;				// ��Ϣ���ͣ��̶�ֵ��200005��
	int  state;				// ״̬��0��������
	char guid[64];			// ����Ψһ��ʶ
	char describe[128];		// ��������
	char label[40];			// �������ͣ�ʵ�����󱨵ȣ�
	char user[40];			// ������
	char time[40];			// ��ʼʱ��
	char files[256];		// ������
}TDealEndToKoala, *LPTDealEndToKoala;

//�յ������ϱ����ý�������
typedef struct
{
	int msg;				// ��Ϣ���� (�̶�ֵ��200006)
	int operate;			// (Ϊ0)
	int state;				// ����˴���״̬ (0:δ����, 1:����)
	char guid[64];			// ����Ψһ��ʶ
	char describe[128];		// ����
	char reserved[64];		// Ԥ��
}TFeedBackToKoala, *LPTFeedBackToKoala;

//�������ý����ϱ�
typedef struct
{
	int  msg;				// ��Ϣ���ͣ��̶�ֵ��201002��
	int  state;				// ִ��״̬��0��ִ���꣬1��������
	char guid[64];			// ����Ψһ��ʶ
	char planguid[64];		// Ԥ��Ψһ��ʶ
	int  order;				// �������
	char stepguid[64];		// ����Ψһ��ʶ
	int  id;				// ����id
	char name[40];			// ��������
	char detail[128];		// ��������
	char user[40];			// ������
	char begintime[40];		// ��ʼʱ��
	char endtime[40];		// ����ʱ��
	char describe[256];		// ����
	char files[256];		// ������
}TDealStepToZONEE, *LPTDealStepToZONEE;

//�����ϱ���������
typedef struct
{
	int  msg;			// ��Ϣ���ͣ��̶�ֵ��201005��
	char guid[64];		// ����Ψһ��ʶ
	char user[40];		// �ύ��
	char files[256];	// ������
}TAlarmFileToZONEE, *LPTAlarmFileToZONEE;


//�����ϱ����ý���
typedef struct
{
	int  msg;				// ��Ϣ���ͣ��̶�ֵ��201003��
	int  state;				// ״̬��0��������
	char guid[64];			// ����Ψһ��ʶ
	char describe[128];		// ��������
	char label[40];			// �������ͣ�ʵ�����󱨵ȣ�
	char user[40];			// ������
	char time[40];			// ��ʼʱ��
	char files[256];		// ������
}TDealEndToZONEE, *LPTDealEndToZONEE;

/************* ��������֤���� ***************/
// ��������Ϣת����Ϣ�ṹ��
typedef struct
{
	unsigned int ucMsgType;       //��Ϣ����
	int ucDealStatus;            //����״̬ 1-δ����2-�����С�3-����ˡ�4-�Ѵ���5-��ʧЧ
	int nApplyID;                 //��֤ID
	char chSender[64];            //������

}T_TRANS_OPENDOOR_INFO,*LPT_TRANS_OPENDOOR_INFO;
typedef enum
{
	MT_CURRENTSTATUS      = 0x01,     // ֪ͨ������֤��ǰ״̬
	MT_APPLYAUTHORIZATION = 0x02,     //������Ȩ
	MT_APPLYAPPROVAL      = 0x04,     //��������
	MT_REFUSEOPENDOOR     = 0x08,     //�ܾ�����
	MT_EMERGENCYPLANCALL  = 0x10,     //Ӧ������
}T_TRANS_OPENDOOL_MESSAGETYPE;

#endif