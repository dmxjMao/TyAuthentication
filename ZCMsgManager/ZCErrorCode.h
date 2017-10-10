/**
* @file ZCErrorCode.h
*
* @brief ����ͻ��˸�ģ�齻��������궨��
* 
* @version 1.0.0.1
*
* @author gaoxiaoliang@typrotech.com
*/

#ifndef ZCERRORCODE_H
#define ZCERRORCODE_H

/** @defgroup ZCErrorCodeDefine ��ϢЭ�������ṹ����     
 * ����ͻ��˸�ģ�齻��������궨�� 
 * @{
 */
///��Ϣ����ģ��ɹ��붨��
typedef enum
{
	ZC_SUCCESS                        = 0x0    ///<(0)����
}E_ZC_SUCCESS_CODE;

///��Ϣ����ģ������붨��
typedef enum
{
	SERVER_ERROR_MODULEOFFLINE = 0x1       ///<(1)����ģ�鲻����
}E_SERVER_ERROR_CODE;

///Appģ������붨��
typedef enum
{
	APP_ERROR_LINKERROR = 0x10,         ///<(16)APP�����쳣
	APP_ERROR_NOREQMODULE,              ///<(17)����ģ���쳣
	APP_ERROR_PARAMTOOSMALL,            ///<(18)��������ṹ�����쳣
	APP_ERROR_PARAMISNULL,              ///<(19)�������Ϊ��
	APP_ERROR_GETINFOFAILED,            ///<(20)��APP��ȡ��Ϣʧ��
	APP_ERROR_GETINFONULL,              ///<(21)�����Ϊ��
	APP_ERROR_UNKNOWNMSG,               ///<(22)δ֪��Ϣ
	APP_ERROR_OPERATEFAILED,            ///<(23)��ɾ�Ĳ���ʧ��  
	APP_ERROR_PARAMERROR,               ///<(24)�����������
	APP_ERROR_CURUSERNULL,              ///<(25)��ǰ�û�δ��¼
	APP_ERROR_NOFINDSCHEDULEINFO,       ///<(26)δ�ҵ���ǰ�û����Ű���Ϣ
    APP_ERROR_NOFINDMONITORROLE,        ///<(27)δ�ҵ��ϼ���ɫ
	APP_ERROR_NOFINDMONITORINCLASS,     ///<(28)δ��ͬһ������ҵ��ϼ���ɫ
	APP_ERROR_NOFINDSUBROLE,            ///<(29)δ�ҵ��¼���ɫ
	APP_ERROR_NOFINDSUBROLEINCLASS,     ///<(30)δ��ͬһ������ҵ��¼���ɫ

	APP_ERROR_NUM1 = 0x100,             ///<(256)��ʱ��ģ�������ΰ󶨣��޷�ɾ���������Ƴ����ڰ����Ϣ
}E_APP_ERROR_CODE;

///BCBģ������붨��
typedef enum
{
	BCBC_ERROR_NOUSERINFO = 0x400,       ///<(1024)��ǰ�û�����
	BCBC_ERROR_USERINFOISNULL,           ///<(1025)�����û���ϢΪ�� 
	BCBC_ERROR_DOWNLOADIMGFAILED,        ///<(1026)ͼƬ����ʧ��
	BCBC_ERROR_PARAMERROR,               ///<(1027)�����������
    BCBC_ERROR_BUSY,                     ///<(1028)ϵͳ��æ
    BCBC_ERROR_UNKNOWNMSG,               ///<(1029)δ֪��Ϣ
    BCBC_ERROR_GETINFONULL,              ///<(1030)�����Ϊ��
    BCBC_ERROR_NOFINDAREA,               ///<(1031)δ�ҵ�������Ϣ
    BCBC_ERROR_NOFINDALARMSOURCENODE,    ///<(1032)δ�ҵ�����Դ�ڵ���Ϣ
    BCBC_ERROR_HOSTALARMNOHAVELINKVIDEO, ///<(1033)�����౨��û��������Ƶ����¼��
    BCBC_ERROR_NOEVENTMODULE,            ///<(1034)��̬ģ��δ���û�δ��Ȩ
    BCBC_ERROR_NOFINDNEARBYVIDEO,        ///<(1035)δ�ҵ�������Ƶ
    BCBC_ERROR_NOFINDTALKDEV,            ///<(1036)������δ�ҵ��Խ��豸
    BCBC_ERROR_DOWNLOADFAILED,           ///<(1037)��Ƶ����ʧ��
    BCBC_ERROR_UPLOADFAILED,             ///<(1038)��Ƶ�ϴ�ʧ��
    BCBC_ERROR_CAPTUREPICFAILED,         ///<(1039)ץͼʧ��
    BCBC_ERROR_NOTALKMODULE,             ///<(1040)δ���öԽ�ģ��
    BCBC_ERROR_UPLOADATTACHMENTFAILED,   ///<(1041)�����ϴ�ʧ��
    BCBC_ERROR_NOFINDDEVID,              ///<(1042)δ�ҵ���Ӧ�豸
    BCBC_ERROR_ACSCONTROLMSGSENDFAILED,  ///<(1043)�Ž����������ʧ��
    BCBC_ERROR_TIMEOUT,                  ///<(1044)����ʱ
    BCBC_ERROR_GETRECORDINFOFAILED,      ///<(1045)��ȡͨ��¼��ƻ�ʧ��
    BCBC_ERROR_SEARCHFILELISTFAILED,     ///<(1046)��ȡͨ��¼���ļ��б�ʧ��
    BCBC_ERROR_SEARCHFILENETEXCEPTION,   ///<(1047)��ѯ¼���ļ������쳣
    BCBC_ERROR_NOCHECKMODULE,            ///<(1048)δ���ûط�����ģ��
    BCBC_ERROR_REQUESTFILEFAILED,        ///<(1049)�����ļ�ʧ��
    BCBC_ERROR_NOFINDKOALASERVICE,       ///<(1050)δ�ҵ��������������û�
    BCBC_ERROR_THRIDPARTREQUESTFAILED,   ///<(1051)�����������ϵͳ������Ϣʧ��
}E_BCBC_ERROR_CODE;
/** @} */
#endif