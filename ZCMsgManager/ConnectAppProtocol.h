/*********************************************************************
* ��Ȩ���� (C)2010, �Ϻ���Ծ�Ƽ����޹�˾��
*
* �ļ����ƣ�ConnectAPPProtocol.h
* ����ժҪ����APP����������Э��Ķ���
* ��ǰ�汾��V1.8.2.28
* ��   �ߣ�����
* ������ڣ�2016-09-13
***********************************************************************/
#ifndef CONNNECTAPP_PROTOCOL
#define CONNNECTAPP_PROTOCOL
#include "TjtyCommon.h"

///<��Ϣ����������
typedef enum
{
    MSG_REQ_TEST_DUMY = 0,
    MSG_REQ_USER_LOGIN_DUMMY = 1000,                 ///<�û���¼(1000)
    MSG_REQ_USER_LOGOUT_DUMMY,                       ///<�û��˳�(1001)
    MSG_REQ_AREA_INFO,                         ///<��ȡ������Ϣ(1002)
    MSG_REQ_DEV_BASE_INFO,                     ///<�豸������Ϣ(1003)
    MSG_REQ_DEV_AS_INFO,                       ///<AS��Ҫ���豸��Ϣ(1004)
    MSG_REQ_DEV_MS_INFO,                       ///<MS��Ҫ���豸��Ϣ(1005)
    MSG_REQ_USER_INFO,                         ///<�û���Ϣ(1006)
    MSG_REQ_USER_AUTHORITY,                    ///<�û�����Ȩ��(1007)
    MSG_REQ_USER_AUTH_DEV,                     ///<�û�����豸��Ȩ��(1008)
    MSG_REQ_USER_AUTH_CHL,                     ///<�û����ͨ����Ȩ��(1009)
    MSG_REQ_CAMERA_INFO,                       ///<����ͷ��Ϣ(1010)
    MSG_REQ_ALARMIN_INFO,                      ///<̽ͷ��Ϣ(1011)
    MSG_REQ_ALARMOUT_INFO,                     ///<������Ϣ(1012)
    MSG_REQ_AS_INFO,                           ///<AS��Ϣ(1013)
    MSG_REQ_MS_INFO,                           ///<MS��Ϣ(1014)
    MSG_REQ_DEVID_BY_ASNAME,                   ///<���ݱ�����������ȡ��Ӧ���豸(1015)
    MSG_REQ_DEVID_BY_MSNAME,                   ///<����ý���������ȡ��Ӧ���豸(1016)
    MSG_REQ_USER_RECV_ALARM_AUTH,              ///<�û��ľ���Ӿ�Ȩ��(1017)
    MSG_REQ_ALARM_INFO,                        ///<������Ϣ(1018)
    MSG_REQ_ALARM_DEAL_STRATEGY,               ///<������Ϣ�������(1019)
    MSG_REQ_RECORD_FILE_INFO,                  ///<¼���ļ���Ϣ(1020)
    MSG_REQ_STORAGE_PLAN,                      ///<��ȡͨ���Ĵ洢�ƻ�(1021)
    MSG_REQ_BACKUP_PLAN,                       ///<DVR���ݼƻ�(1022)
    MSG_REQ_ADDLOGINFO,                        ///<�����־��Ϣ(1023)
    MSG_REQ_ADDTALKLOG,                        ///<��ӶԽ���Ϣ(1024)
    MSG_REQ_SETTIME_PLAN,                      ///<��ȡУʱ�ƻ�(1025)
    MSG_REQ_USER_DEV_LOGINFO,                  ///<�����û�����ȡ�豸�ĵ�¼��Ϣ(1026)
    MSG_REQ_CMS_INFO,                          ///<��ȡ���Ĺ����������Ϣ(1027)
    MSG_REQ_STOR_STREAM_SET,                   ///<��ȡ��ʽ�洢����(1028)
    MSG_REQ_STOR_FILE_SET,                     ///<��ȡ�ļ�ʽ�洢����(1029)
    MSG_REQ_STOR_REM_SET,                      ///<��ȡ���̻�������(1030)
    MSG_REQ_STOR_PLAN_INFO,                    ///<��ȡ�洢�ƻ���Ϣ(1031)
    MSG_REQ_DEV_STOR_PLAN,                     ///<��ȡ�豸�Ĵ���ƻ�(1032)
    MSG_REQ_VIDEO_FILE_INFO,                   ///<��ȡ¼���ļ���Ϣ(1033)
    MSG_REQ_VIDEO_FILE_DEL,                    ///<ɾ��¼���ļ���־��Ϣ(1034)
    MSG_REQ_DEV_BASE_INFO_EX,                  ///<�豸������Ϣ���豸����(1035)
    MSG_REQ_DEV_AS_INFO_EX,                    ///<AS��Ҫ���豸��Ϣ���豸����(1036)
    MSG_REQ_DEV_MS_INFO_EX,                    ///<MS��Ҫ���豸��Ϣ����ֵ���豸����(1037)
    MSG_REQ_NEW_DEV_INFO,                      ///<��ȡ�豸������Ϣ������������Ϣ��(1038)
    MSG_REQ_NEW_CAMERA_INFO,                   ///<��ȡ����ͷ������Ϣ������������Ϣ)(1039)
    MSG_REQ_NEW_SHOW_ALLAREANODE_INFO,         ///<��ȡ����ڵ���ϸ��Ϣ������(1)+1039
    MSG_REQ_NEW_SHOW_DEVNODE_INFO,             ///<��ȡ���������豸��Ϣ��DVR�������������Ž���(2)+1039
    MSG_REQ_NEW_SHOW_FRONTNODE_INFO,           ///<��ȡ����ǰ���豸��Ϣ������ͷ��̽ͷ�������(3)+1039
    MSG_REQ_NEW_SHOW_USERINFO_All,             ///<��ȡ�û���ϸ��Ϣ(4)+1039
    MSG_REQ_NEW_SHOW_CMSNODE_INFO,             ///<��ȡ���ķ�������ϸ��Ϣ(5)+1039
    MSG_REQ_NEW_SHOW_CHANNELGROUP,             ///<��ȡͨ������Ϣ(6)+1039
    MSG_REQ_NEW_SHOW_HOSTNODE_TALK,            ///<��ȡ�����Խ�������Ϣ(7)+1039
    MSG_REQ_NEW_SHOW_FRONTENDNODE_TALK,        ///<��ȡǰ���豸�Խ�������Ϣ(8)+1039
    MSG_REQ_NEW_SHOW_SCREEN_INFO,              ///<��ȡ����ǽ��ϸ��Ϣ(9)+1039
    MSG_REQ_NEW_SHOW_EMERGENCYGROUP,           ///<��ȡԤ������ϸ��Ϣ(10)+1039
    MSG_REQ_NEW_SHOW_ALARMTYPE,                ///<��ȡ����������ϸ��Ϣ(11)+1039
    MSG_REQ_NEW_SHOW_DEVALARMSOUND,            ///<��ȡ��������������ϸ��Ϣ(12)+1039
    MSG_REQ_NEW_SHOW_ALARMSOUND_INFO,          ///<��ȡǰ���豸����������ϸ��Ϣ(13)+1039
    MSG_REQ_NEW_ALARMFILTER_SET,               ///<������������(14)+1039 (add)
    MSG_REQ_NEW_ADD_NEWEVENT,                  ///<������¼�(15)+1039 (add)
    MSG_REQ_NEW_REPLY_EVENT,                   ///<�ظ��¼�(16)+1039 (add)
    MSG_REQ_NEW_ACCESS_ALLEVTCONTEVENT,        ///<��ȡ�����¼���ϸ��Ϣ(17)+1039
    MSG_REQ_NEW_SHOW_NEWEVENTNUM,              ///<��ȡ���¼�����Ŀ(18)+1039
    MSG_REQ_NEW_MODY_STATEOFUNREADEVENT,       ///<�޸�δ���¼�״̬(19)+1039 (mod)
    MSG_REQ_NEW_QUERY_EVENT,                   ///<ȫ���¼���Ϣģ����ѯ(20)+1039
    MSG_REQ_NEW_SHOW_EVENTNUM,                 ///<��ȡȫ���¼���Ϣģ����ѯ����Ŀ(21)+1039
    MSG_REQ_NEW_GET_ALLLABEL,                  ///<��ȡ���б�ǩ��Ϣ(22)+1039
    MSG_REQ_NEW_M_EVENT_STATISTICS,            ///<�ͻ����¼���ǩͳ��(23)+1039
    MSG_REQ_NEW_M_MODCLIENTUSER,               ///<�ͻ����û������޸�(24)+1039(mod)
    MSG_REQ_NEW_SHOW_ALARMINFO,                ///<������־��Ϣ��ѯ(25)+1039
    MSG_REQ_NEW_STAT_ALARMINFO,                ///<������־ͳ����Ϣ(26)+1039
    MSG_REQ_NEW_SHOW_SYSLOGINFO,               ///<ϵͳ��־��Ϣ��ѯ(27)+1039
    MSG_REQ_NEW_STAT_SYSLOGINFO,               ///<ϵͳ��־ͳ����Ϣ(28)+1039
    MSG_REQ_NEW_M_CRUISE,                      ///<Ѳ����ؽڵ���Ϣ(29)+1039(add��mod��delete)
    MSG_REQ_NEW_M_CRUISE_SET,                  ///<Ѳ������(30)+1039(add)
    MSG_REQ_NEW_SHOW_PREPOINT,                 ///<��ȡԤ�õ���Ϣ(31)+1039
    MSG_REQ_NEW_SHOW_TRACE,                    ///<��ȡѲ����Ϣ(32)+1039
    MSG_REQ_NEW_SHOW_LOCUS,                    ///<��ȡ�켣��Ϣ(33)+1039
    MSG_REQ_NEW_M_GETERROR,                    ///<��ȡƽ̨��������Ϣ(34)+1039
    MSG_REQ_NEW_SHOWOPTYPE,                    ///<��ȡ������־������Ϣ(35)+1039
    MSG_REQ_NEW_SHOWPRIVILEGECMS,              ///<256ͨ�����Ļ�ȡ�豸Ȩ����Ϣ(36)+1039
    MSG_REQ_NEW_SHOWPRIVILEGECLIENT,           ///<256ͨ���ͻ��˻�ȡ�豸Ȩ����Ϣ(37)+1039
    MSG_REQ_NEW_ADD_USERINFO,                  ///<����û���Ϣ(38)+1039(add)
    MSG_REQ_NEW_MOD_USERINFO,                  ///<�޸��û���Ϣ(39)+1039(mod)
    MSG_REQ_NEW_DEL_USERINFO,                  ///<ɾ���û���Ϣ(40)+1039(del)
    MSG_REQ_NEW_SHOW_ROLEINFO,                 ///<��ʾ��ɫ��Ϣ(41)+1039
    MSG_REQ_NEW_ROLEINFO,                      ///<��ɫ��ز�����Ϣ(42)+1039(add��mod��del)
    MSG_REQ_NEW_AREACODEINFO,                  ///<ʡ�����������Ϣ(43)+1039
    MSG_REQ_NEW_SHOW_NODETYPE_INFO,            ///<��ȡ�ڵ�������Ϣ(44)+1039
    MSG_REQ_NEW_MOD_NODETYPE_INFO,             ///<�޸Ľڵ�������Ϣ(45)+1039(mod)
    MSG_REQ_NEW_ABOUTLABEL,                    ///<��ǩ�����Ϣ����(46)+1039(add��mod��del)
    MSG_REQ_NEW_SHOWLABEL,                     ///<��ȡ��ǩ�����Ϣ(47)+1039
    MSG_REQ_NEW_CAMAREA,                       ///<����ͷ���������Ϣ����(48)+1039(add��mod��del)
    MSG_REQ_NEW_SHOWCAMAREA,                   ///<��ȡ����ͷ���������Ϣ(49)+1039
    MSG_REQ_NEW_SHOWLOGINFO,                   ///<��ȡ��־��Ϣ(50)+1039
    MSG_REQ_NEW_SETTIMEPLAN,                   ///<����Уʱ�ƻ���Ϣ(51)+1039
    MSG_REQ_NEW_SHOWTIMEPLAN,                  ///<��ȡУʱ�ƻ���Ϣ(52)+1039
    MSG_REQ_NEW_MOST_SET,                      ///<��������(ͼƬ������)(53)+1039
    MSG_REQ_NEW_PARTION,                       ///<���������Ϣ����(54)+1039(add��mod��del)
    MSG_REQ_NEW_MODPARTAREA,                   ///<�޸ķ�����������(55)+1039(mod)
    MSG_REQ_NEW_SHOWPARTINFO,                  ///<��ʾ���屨�������ķ���-������Ϣ(56)+1039
    MSG_REQ_NEW_SET_ROLEAUTHORITY,             ///<��ɫȨ����Ϣ����(57)+1039
    MSG_REQ_NEW_M_SHOWPRIVILEGE,               ///<��ɫȨ����Ϣ��ѯ(58)+1039
    MSG_REQ_NEW_SCREEN_SET,                    ///<����ǽ��Ϣ����(59)+1039
    MSG_REQ_NEW_SET_M_EMERGENCY,               ///<Ԥ����Ϣ����(60)+1039
    MSG_REQ_NEW_SHOW_USER_AREA,                ///<��ȡ�û�����������Ϣ(61)+1039
    MSG_REQ_NEW_INTO_ROLE,                     ///<�޸��û�������ɫ(62)+1039
    MSG_REQ_NEW_CHANNELGROUP,                  ///<ͨ������Ϣ��ز���(63)+1039(add��mod��del)
    MSG_REQ_NEW_SHOWCHANNELGROUP,              ///<ͨ������ʾ��ز���(64)+1039
    MSG_REQ_NEW_SETCHANNELGROUP,               ///<ͨ����������ز���(65)+1039
    MSG_REQ_NEW_SHOW_SQLMANAGE,                ///<��ʾ���ݿ�ռ������Ϣ(66)+1039
    MSG_REQ_NEW_SET_CLEANTIME,                 ///<���ñ�����־����ʱ��(67)+1039
    MSG_REQ_NEW_GET_SQLINFO,                   ///<��ȡ���ݿⱸ��·����Ϣ(68)+1039
    MSG_REQ_NEW_SAVE_SQLINFO,                  ///<�������ݿⱸ��·��(69)+1039
    MSG_REQ_NEW_M_SQLPOSITION,                 ///<��ȡ�洢������Ϣ(70)+1039
    MSG_REQ_NEW_CONFIGCLIENT_LOGIN,            ///<�ж����ÿͻ��˵�¼�˺���Ϣ(71)+1039
    MSG_REQ_NEW_GET_CONFIG_LOGIN,              ///<��ȡ���ÿͻ��˵�¼�����豸���˺���Ϣ(72)+1039
    MSG_REQ_NEW_SET_SERVERLOGIN,               ///<���÷�������¼��Ϣ(73)+1039
    MSG_REQ_NEW_SHOW_DEVLOGIN_CONDITION,       ///<��ʾ��������¼��Ϣ(74)+1039
    MSG_REQ_NEW_LOGINDEL_SERVER,               ///<��������¼�豸ɾ��(75)+1039
    MSG_REQ_NEW_LOGINCLEAN_SERVER,             ///<��������¼�豸���(76)+1039
    MSG_REQ_NEW_SET_CLIENTLOGIN,               ///<���ÿͻ��˵�¼��Ϣ(77)+1039
    MSG_REQ_NEW_SHOW_CLIENTLOGIN,              ///<��ʾ�ͻ��˵�¼��Ϣ(78)+1039
    MSG_REQ_NEW_LOGINDEL_CLIENT,               ///<�ͻ��˵�¼�豸ɾ��(79)+1039
    MSG_REQ_NEW_LOGINCLEAN_CLIENT,             ///<�ͻ��˵�¼�豸���(80)+1039
    MSG_REQ_NEW_M_COPYLOGIN,                   ///<�����û���¼����(81)+1039
    MSG_REQ_NEW_SET_VIDEOCONFIG,               ///<�洢��������(82)+1039
    MSG_REQ_NEW_SET_STORAGEPLAN,               ///<���ô洢�ƻ�(83)+1039
    MSG_REQ_NEW_SET_FRONTEND_PLAN_WEEK,        ///<����ͨ���洢�ƻ������Ϣ(84)+1039
    MSG_REQ_NEW_SHOW_VIDEOSET_INFO,            ///<��ʾ�洢����������Ϣ(85)+1039
    MSG_REQ_NEW_SHOW_CLEARDISK_INFO,           ///<��ʾ��������(86)+1039
    MSG_REQ_NEW_SHOW_STORAGEVIEW,              ///<��ʾ�洢�ƻ������Ϣ(87)+1039
    MSG_REQ_NEW_DEL_STORAGEPLAN,               ///<ɾ���洢�ƻ�(88)+1039
    MSG_REQ_NEW_CMSNODE_INFO,                  ///<���Ĺ����������ز���(89)+1039(add��mod��del)
    MSG_REQ_NEW_MSNODE_INFO,                   ///<ý���������ز���(90)+1039(add��mod��del)
    MSG_REQ_NEW_SHOW_MSNODE_INFO,              ///<��ʾý���������ϸ��Ϣ(91)+1039
    MSG_REQ_NEW_ADD_MSCONFIG,                  ///<ý���������������(92)+1039
    MSG_REQ_NEW_DEL_MSCONFIG,                  ///<ɾ��ý���������������(93)+1039
    MSG_REQ_NEW_SHOW_MSDEV_INFO,               ///<��ʾý�������������ϸ��Ϣ(94)+1039
    MSG_REQ_NEW_ASNODE_INFO,                   ///<������������ز���(95)+1039(add��mod��del)
    MSG_REQ_NEW_SHOW_ASNODE_INFO,              ///<��ʾ������������ϸ��Ϣ(96)+1039
    MSG_REQ_NEW_ADD_ASCONFIG,                  ///<������������������(97)+1039
    MSG_REQ_NEW_DEL_ASCONFIG,                  ///<ɾ��������������������(98)+1039
    MSG_REQ_NEW_SHOW_ASDEV_INFO,               ///<��ʾ����������������ϸ��Ϣ(99)+1039
    MSG_REQ_NEW_M_GETALRAMID,                  ///<��ȡ��󱨾����(100)+1039
    MSG_REQ_NEW_ALARMTYPE_INFO,                ///<����������ز���(101)+1039
    MSG_REQ_NEW_SHOW_ALARMCONFIG,              ///<��ʾ����������ϸ��Ϣ(102)+1039
    MSG_REQ_NEW_AREANODEINFO,                  ///<����ڵ���Ϣ��ز���(103)+1039(add��mod��del)
    MSG_REQ_NEW_AREANODEMOVE,                  ///<����ڵ��ƶ�(104)+1039
    MSG_REQ_NEW_MAXAREANODE,                   ///<��ȡ�������ڵ�(105)+1039
    MSG_REQ_NEW_DEVNODEINFO,                   ///<�豸�ڵ���Ϣ��ز���(106)+1039(add��mod��del)
    MSG_REQ_NEW_DEVNODEMOVE,                   ///<�豸�ڵ��ƶ�(107)+1039
    MSG_REQ_NEW_FRONTENDNODEINFO,              ///<ǰ�˽ڵ���Ϣ��ز���(108)+1039(add��mod��del)
    MSG_REQ_NEW_FRONTENDNODEMOVE,              ///<ǰ�˽ڵ��ƶ�(109)+1039
    MSG_REQ_NEW_SHOW_MANUFATURE,               ///<��ʾƷ����Ϣ(110)+1039
    MSG_REQ_NEW_SHOW_IP,                       ///<��ʾIP��Ϣ(111)+1039
    MSG_REQ_NEW_SHOWINFOBYDEV,                 ///<�������������ʾ�豸��Ϣ(112)+1039
    MSG_REQ_NEW_SETDEVLOGIN,                   ///<����DEV��¼�û�����(113)+1039
    MSG_REQ_NEW_FRONTENDSOUND,                 ///<����ǰ���豸����ʾ������������(114)+1039
    MSG_REQ_NEW_FRONTENDTALK,                  ///<����ǰ���豸����ʾ�����Խ�ͨ��(115)+1039
    MSG_REQ_NEW_FRONTNODEINFO,                 ///<����ǰ���豸����ʾ��ڵ���ϸ��Ϣ(116)+1039
    MSG_REQ_NEW_AUTOMODNAME,                   ///<Զ��ͨ����ƥ��(117)+1039
    MSG_REQ_NEW_CONFIGCHECK,                   ///<���������(118)+1039
    MSG_REQ_NEW_EXCELCHECK,                    ///<�豸��Ϣ����(119)+1039
    MSG_REQ_NEW_GETPHONEUSER,                  ///<�ֻ���ȡ�û���Ϣ(120)+1039
    MSG_REQ_NEW_MODPHONEUSER,                  ///<�ֻ��޸��û���Ϣ(121)+1039
    MSG_REQ_NEW_ALARMPARTION,                  ///<��ʾ���������ַ�����Ϣ(122)+1039
    MSG_REQ_NEW_ONLYONE,                       ///<��ʾ������Ϣ(123)+1039
    MSG_REQ_NEW_USERIMAGE,                     ///<�ֻ���ȡ�����û�ͷ����Ϣ(124)+1039
    MSG_REQ_NEW_EVENTBYPHONE,                  ///<�ֻ���ȡ�����¼���ϸ��Ϣ(125)+1039
    MSG_REQ_NEW_REPLYBYONE,                    ///<�ֻ���ȡָ���¼������лظ�(126)+1039
    MSG_REQ_NEW_ALLEVENTPHONE,                 ///<�ֻ���ȡ�����¼�(ͨ��ʱ��)(127)+1039
    MSG_REQ_NEW_GSMAPSET,                      ///<GS��γ������(128)+1039
    MSG_REQ_NEW_GSMAPSHOW,                     ///<GS������Ϣ��ȡ(129)+1039
    MSG_REQ_NEW_IMAGEFILESET,                  ///<IMAGE�ļ�����(130)+1039
    MSG_REQ_NEW_MODONEINCIDENT,                ///<�ֻ����¼�״̬�޸�(131)+1039
    MSG_REQ_NEW_M_COPYSERVER,                  ///<���Ʒ�������¼��Ϣ(132)+1039
    MSG_REQ_NEW_GSMAPDET,                      ///<GS�ڵ�ɾ��(133)+1039
    MSG_REQ_NEW_GSMAPSHOWINFO,                 ///<GS������Ϣ��ȡ(134)+1039
    MSG_REQ_NEW_DVRSORTSHOWINFO,               ///<��Ʒ�������ȡ��������(135)+1039
    MSG_REQ_NEW_ALARMDEALINTO,                 ///<�ͻ��˱��������ύ(136)+1039
    MSG_REQ_NEW_NEXTCENTER,                    ///<��ȡ�����¼����ı��(137)+1039
    MSG_REQ_NEW_ALARMPROCESS,                  ///<����������(138)+1039
    MSG_REQ_NEW_ALARMTOP,                      ///<��������(139)+1039
    MSG_REG_NEW_DEVICEBASEINFO,                ///<��������ȡ�豸������Ϣ(+Ʒ������)(140)+1039(CMS)
    MSG_REG_NEW_DEVICEBASERELATEINFO,          ///<��������ȡ�豸������Ϣ(+Ʒ������+����)(141)+1039(CMS)
    MSG_REG_NEW_MS_DEVICEBASEINFO,             ///<��������ȡ�豸������Ϣ(+Ʒ������)(142)+1039(MS)
    MSG_REG_NEW_AS_DEVICEBASEINFO,             ///<��������ȡ�豸������Ϣ(+Ʒ������)(143)+1039(AS)
    MSG_REG_NEW_ALRAMEPLAN,                    ///<����Ԥ������(144)+1039(add��mod��del)
    MSG_REG_NEW_ALRAMEPLANRELATE,              ///<����Ԥ����������(145)+1039(add��del)
    MSG_REG_NEW_SHOWALARMEPLAN,                ///<��ʾ����Ԥ����Ϣ(146)+1039
    MSG_REG_NEW_SHOWALARMEPLANINFO,            ///<��ʾ����Ԥ����ϸ��Ϣ(147)+1039
    MSG_REG_NEW_SHOWALARMEPLANRET,             ///<��ʾ����Ԥ��������Ϣ(148)+1039
    MSG_REG_NEW_NEWTVSCREEN,                   ///<���ӻ�����ǽ����(149)+1039(add��mod��del)
    MSG_REG_NEW_SHOWNEWTVSCREEN,               ///<��ʾ���ӻ�����ǽ��Ϣ(150)+1039
    MSG_REG_NEW_STATICSAREAALARMNUM,           ///<���㱨������ͳ��(151)+1039
    MSG_REG_NEW_SHOWALARMLEVEL,                ///<��ʾ�����ȼ���Ϣ(152)+1039
    MSG_REG_NEW_SHOWALARMLEVELPLOY,            ///<��ʾ�����ȼ�������Ϣ(153)+1039
    MSG_REG_NEW_SETALARMLEVELPLOY,             ///<���ñ����ȼ�������Ϣ(154)+1039
    MSG_REG_NEW_SHOWPOSITIONINFO,              ///<��ȡ��λ��Ϣ(155)+1039
    MSG_REG_NEW_SHOWLOCATIONINFO,              ///<��ȡ������Ϣ(156)+1039
    MSG_REG_NEW_OPACTIONLIB,                   ///<�������������(157)+1039(add��mod��del)
    MSG_REG_NEW_SHOWACTIONLIB,                 ///<��ȡ������(158)+1039
    MSG_REG_NEW_OPEVENTLIB,                    ///<�¼����������(159)+1039(add��mod��del)
    MSG_REG_NEW_SHOWEVENTLIB,                  ///<��ȡ�¼���(160)+1039
    MSG_REG_NEW_OPPLANLIB,                     ///<Ԥ�����������(161)+1039(add��mod��del)
    MSG_REG_NEW_SHOWPLANLIB,                   ///<��ȡԤ����(162)+1039
    MSG_REG_NEW_SHOWALWAYSDEAL,                ///<��ȡ���ô��������Ϣ(163)+1039
    MSG_REG_NEW_SHOWDEALCONSEQUECE,            ///<��ȡ����ʽ��Ϣ(164)+1039
    MSG_REG_NEW_WRITEDEALRESULT,               ///<д�뱨��������(165)+1039
    MSG_REG_NEW_SHOWHISTORYDEAL,               ///<����ĳ����Դ��ȡ��ʷ������Ϣ(166)+1039
    MSG_REG_NEW_COMPLEXSTATICS,                ///<����������Ϣ���ۺ�ͳ��(167)+1039
    MSG_REG_NEW_COMPLEXCHECK,                  ///<����������Ϣ���ۺϲ�ѯ(168)+1039
    MSG_REG_NEW_COMPLEXTOP,                    ///<����������Ϣ���ۺ�����(169)+1039
    MSG_REG_NEW_SHOWPLANINFOBYALARM,           ///<���ݱ�����ϢID��ȡ��ӦԤ����Ϣ(170)+1039
    MSG_REG_NEW_SHOWALARMINFOBYALARM,          ///<���ݱ���������Ϣ��ȡ������ϸ��Ϣ(171)+1039
    MSG_REG_NEW_OPUSERGRAPHINFO,               ///<�û�ͼ���������(172)+1039(add��mod��del)
    MSG_REG_NEW_OPUSERREPORTINFO,              ///<�û������������(173)+1039(add��mod��del)
    MSG_REG_NEW_MODSTATUSUSERREPORT,           ///<�޸��û�����״̬(174)+1039(mod)
    MSG_REG_NEW_SHOWUSERGRAPHINFO,             ///<��ȡ�û�ͼ����Ϣ(175)+1039
    MSG_REG_NEW_SHOWUSERREPORTINFO,            ///<��ȡ�û�������Ϣ(176)+1039
    MSG_REG_NEW_SHOWALARMBACKINFO,             ///<����������ϸ��Ϣ(177)+1039
    MSG_REG_NEW_SHOWUSERREPORTBOOKINFO,        ///<��ȡ�û����涩����Ϣ����(178)+1039
    MSG_REG_NEW_OPAREAPLACEINFO,               ///<������������(179)+1039(add��mod��del)
    MSG_REG_NEW_OPKEYPARTINFO,                 ///<��λ��������(180)+1039(add��mod��del)
    MSG_REG_NEW_OPALARMLEVELINFO,              ///<�����ȼ���������(181)+1039(add��mod��del)
    MSG_REG_NEW_OPTIMEMODEL,                   ///<ʱ��ģ���������(182)+1039(add��mod��del)
    MSG_REG_NEW_SHOWTIMEMODEL,                 ///<ʱ��ģ����Ϣ��ȡ(183)+1039
    MSG_REG_NEW_SETMULALARMLEVEL,              ///<�����ȼ�������������(184)+1039(add��del)
    MSG_REG_NEW_SHOWMULALARMLEVEL,             ///<�����ȼ���������������Ϣ��ȡ(185)+1039
    MSG_REG_NEW_SETSINALARMLEVEL,              ///<�����ȼ�������������(186)+1039(add��del)
    MSG_REG_NEW_SHOWSINALARMLEVEL,             ///<�����ȼ���������������Ϣ��ȡ(187)+1039
    MSG_REG_NEW_DEVICEBASEINFOLEVEL,           ///<������������ȡ�豸������Ϣ(+��������λ)(188)+1039
    MSG_REG_NEW_PLACEKEYPARTMODEL,             ///<��������λ���������͡�ʱ��ģ��(����+ID)(189)+1039
    MSG_REG_NEW_PLACEKEYPARTBYNAME,            ///<�������ƻ�ȡ��������λ(190)
    MSG_REG_NEW_SHOWALARMBYDEVNAME,            ///<�������ƻ�ȡ������������(191)
    MSG_REG_NEW_SHOWUNHANDLEALARMCOUNT,        ///<��ʾδ���ñ�����Ŀ(192)
    MSG_REG_NEW_SET_PLACEKEYPART,              ///<�������ó�������λ(193)
    MSG_REG_NEW_SHOW_AREAPLACESET,             ///<��ȡ��������������Ϣ(194)
    MSG_REG_NEW_SHOW_KEYPARTSET,               ///<��ȡ��λ����������Ϣ(195)
    MSG_REG_NEW_SHOWTODAYCLASSES,              ///<��ȡ�����Ű���Ϣ(196)
    MSG_REG_NEW_SHOW_HA_CURUSER,               ///<��ȡ��ǰ�����û���Ϣ(197)
    MSG_REG_NEW_SHOW_HA_WAITUSERLIST,          ///<��ȡ���Ӱ���Ա��Ϣ(198)
    MSG_REG_NEW_SHOW_HA_A_TASKINFO,            ///<��ȡֵ��Ա����ִ�����(199)
    MSG_REG_NEW_SHOW_HA_M_TASKINFO,            ///<��ȡֵ�೤����ִ�����(200)
    MSG_REG_NEW_SHOW_HA_ALARMINFO,             ///<��ȡ�����δ��������Ϣ(201)
    MSG_REG_NEW_ADD_HA_INFO,                   ///<�ύ������Ϣ(202)
    MSG_REG_NEW_SHOW_HA_INFO,                  ///<��ȡ���Ӱ���ʷ��Ϣ(203)
    MSG_REG_NEW_TASKDISTREBUTE_SET,            ///<�������ݿ�ַ�����(204)
    MSG_REG_NEW_INSPECT_ROLESET,               ///<����Ѳ���ɫ��չ����(205)
    MSG_REG_NEW_INSPECT_ROLESHOW,              ///<����Ѳ���ɫ��չ��Ϣ��ȡ(206)
    MSG_REG_NEW_INSPECT_ABORTLIBSET,           ///<����Ѳ���쳣�����(207)
    MSG_REG_NEW_INSPECT_ABORTLIBSHOW,          ///<����Ѳ���쳣����Ϣ��ȡ(208)
    MSG_REG_NEW_INSPECT_DATEGROUPSET,          ///<����Ѳ�����������(209)
    MSG_REG_NEW_INSPECT_DATEGROUPSHOW,         ///<����Ѳ����������Ϣ��ȡ(210)
    MSG_REG_NEW_INSPECT_CLASSINFOSET,          ///<����Ѳ������Ϣ����(211)
    MSG_REG_NEW_INSPECT_CLASSINFOSHOW,         ///<����Ѳ������Ϣ��ȡ(212)
    MSG_REG_NEW_INSPECT_SCHEDULEINFOSET,       ///<����Ѳ���Ű���Ϣ����(213)
    MSG_REG_NEW_INSPECT_SCHEDULEINFOSHOW,      ///<����Ѳ���Ű���Ϣ��ȡ(214)
    MSG_REG_NEW_INSPECT_CLASSUSERINFOSHOW,     ///<����Ѳ����-�û���Ϣ��ȡ(215)
    MSG_REG_NEW_INSPECT_CLASSMODULESET,        ///<����Ѳ����ģ���������(216)
    MSG_REG_NEW_INSPECT_TASKINFOSET,           ///<����Ѳ��������Ϣ��������(217)
    MSG_REG_NEW_INSPECT_FASTTASKINFOSET,       ///<����Ѳ�����������Ϣ��������(218)
    MSG_REG_NEW_INSPECT_TASKMODULESET,         ///<����Ѳ������ģ���������(219)
    MSG_REG_NEW_INSPECT_TASKEXCUTESET,         ///<����Ѳ������ִ�в���(220)
    MSG_REG_NEW_INSPECT_CHECKRECORDSET,        ///<����Ѳ�����ļ�¼���(221)
    MSG_REG_NEW_INSPECT_TASKSTATUSMOD,         ///<����Ѳ�������·�״̬�޸�(222)
    MSG_REG_NEW_INSPECT_ISQUALIFIEDMOD,        ///<����Ѳ���쳣��ϸ�״̬�޸�(223)
    MSG_REG_NEW_INSPECT_EXCUTEERRORSET,        ///<����Ѳ���쳣�����(224)
    MSG_REG_NEW_INSPECT_CURDUTYPEOPLEINFO,     ///<��ȡ��ǰֵ����Ա��Ϣ(225)
    MSG_REG_NEW_INSPECT_SHOWALLTASKINFO,       ///<��ȡ����������ϸ��Ϣ(226)
    MSG_REG_NEW_INSPECT_TASKOPERATIONINFOSHOW, ///<��ȡ�������������Ϣ(227)
    MSG_REG_NEW_INSPECT_TASKLEVELINFOSHOW,     ///<��ȡ������Ҫ�̶���Ϣ(228)
    MSG_REG_NEW_INSPECT_TASKMODULEINFOSHOW,    ///<��ȡ����ģ����Ϣ(229)
    MSG_REG_NEW_INSPECT_CHANNELKEYPARTINFOSHOW,///<��ȡ����ͨ����λ��Ϣ(230)
    MSG_REG_NEW_INSPECT_ROLEDEVINFOSHOW,       ///<���ݽ�ɫ��ȡ��Ȩ����Ϣ(231)
    MSG_REG_NEW_INSPECT_TASKSENDROLEINFO,      ///<���ݰ�λ�ȡ�����·���ɫ(232)
    MSG_REG_NEW_INSPECT_TASKOBJECTINFO,        ///<��ȡ���������Ϣ(233)
    MSG_REG_NEW_INSPECT_CLASSCONFIRMSETINFO,   ///<�ϡ��°�ǩ������(234)
    MSG_REG_NEW_INSPECT_TODAYTASKINFOSHOW,     ///<��ȡĳ�û��Ľ�������(235)
    MSG_REG_NEW_INSPECT_TODAYTASKALLINFOSHOW,  ///<��ȡĳ���·������ִ����Ϣ(236)
    MSG_REG_NEW_INSPECT_USERTASKINFOSHOW,      ///<��ȡ�û���������(237)
    MSG_REG_NEW_INSPECT_CHECKTASKINFOSHOW,     ///<�����ѯ(238)
    MSG_REG_NEW_INSPECT_SHOWTASKCHECKINFO,     ///<���񸴺���Ϣ(239)
    MSG_REG_NEW_INSPECT_SHOWTASKEPLANINFO,     ///<�������Ԥ����Ϣ(240)
    MSG_REG_NEW_INSPECT_SHOWAREAERRORINFO,     ///<ĳ���������쳣������(241)
    MSG_REG_NEW_INSPECT_SHOWAREAERRORATEINFO,  ///<������쳣��(242)
    MSG_REG_NEW_INSPECT_SHOWCOVERRATEINFO,     ///<Ѳ�츲����(243)
    MSG_REG_NEW_INSPECT_SHOWAREAERRORNUMINFO,  ///<��λʱ���ڵ������쳣����ͳ��(244)
    MSG_REG_NEW_INSPECT_SHOWERRORCHECKRATEINFO,///<�쳣�ĸ���ϸ���(245)
    MSG_REG_NEW_INSPECT_SHOWALARMRECORINFO,    ///<����(246)
    MSG_REG_NEW_SHOW_JH_DEVICEINFO,            ///<�豸���͡�Ʒ�ơ��ͺ���Ϣ��ѯ(247)
    MSG_REG_NEW_CHECK_JH_DEVICEINFO,           ///<�豸������Ϣ��ѯ(248)
    MSG_REG_NEW_STATICS_JH_DEVICEINFO,         ///<�豸������Ϣͳ��(249)
    MSG_REG_NEW_JH_INSERT_ALARMINFO,           ///<������Ϣ����(250)
    MSG_REG_NEW_JH_COMPLEXCHECK,               ///<����������Ϣ���ۺϲ�ѯ(251)
    MSG_REG_NEW_JH_DATABASEINFO,               ///<��ѯ���ݿ������ַ���(252)
    MSG_REG_NEW_INSPECT_STATICS_TASKADDINFO,   ///<���������ͳ����Ϣ(253)
    MSG_REG_NEW_INSPECT_STATICS_EMPLOYANALY,   ///<Ա������������ͳ����Ϣ(254)
    MSG_REG_NEW_INSPECT_STATICS_EMPLOYMANAGER, ///<Ա��������ͳ����Ϣ(255)
    MSG_REG_NEW_IP_POOL_SET,                   ///<�û�IP������(256)
    MSG_REG_NEW_IP_POOL_SHOW,                  ///<�û�IP����Ϣ��ȡ(257)
    MSG_REG_NEW_USEFULPSW_SET,                 ///<������Ч������(258)
    MSG_REG_NEW_USEFULPSW_SHOW,                ///<������Ч����Ϣ��ȡ(259)
    MSG_REG_NEW_USERPSWINFO_SHOW,              ///<��������ȡ�û�������Ϣ(260)[MD5]
    MSG_REG_NEW_ALARMDISPOSAL_USEFULTYPE,      ///<��Ч�������ͻ�ȡ(261)
    MSG_REG_NEW_ALARMDISPOSAL_USEFULPLACEKEY,  ///<��Ч������λ��Ϣ��ȡ(262)
    MSG_REG_NEW_ALARMDISPOSAL_AUTH_SHOW,       ///<�����û�����ȡ��������Ȩ��(263)
    MSG_REG_NEW_ALARMDISPOSAL_PLOY_SHOW,       ///<��ȡ�����ȼ����ò���(264)
    MSG_REG_NEW_ALARMDISPOSAL_DUTYSTATUS_SET,  ///<����ֵ��Ա״̬(265)
    MSG_REG_NEW_ALARMDISPOSAL_STATUS_SET,      ///<���ñ�����Ϣ����״̬(266)
    MSG_REG_NEW_ALARMDISPOSAL_PEOPLE_SET,      ///<���ñ�����Ϣ������(267)
    MSG_REG_NEW_ALARMDISPOSAL_DEALSULT_SET,    ///<�ύ�������ý��(268)
    MSG_REG_NEW_ALARMDISPOSAL_USERSTATUS_SHOW, ///<��ȡ�û�����״̬(269)
    MSG_REG_NEW_ALARMDISPOSAL_ALM_SET,         ///<�����ȼ���������(270)
    MSG_REG_NEW_ALARMDISPOSAL_USERAL_SHOW,     ///<��ȡ�û��ܴ���ı����ȼ�(271)
    MSG_REG_NEW_ALARMDISPOSAL_ACATEGORY_SET,   ///<�������͡����Դ���Ϣ����(272)(add��mod��del)
    MSG_REG_NEW_ALARMDISPOSAL_ACATEGORY_SHOW,  ///<�������͡����Դ���Ϣ��ȡ(273)
    MSG_REG_NEW_ALARMDISPOSAL_MODULEANTH_SHOW, ///<ģ��Ȩ����Ϣ��ȡ(274)
    MSG_REG_NEW_ALARMDISPOSAL_AMA_SHOW,        ///<���ݱ����ȼ���ȡ����Ȩ����Ϣ(275)
    MSG_REG_NEW_ALARMDISPOSAL_ASSINGLE_SET,    ///<�˹���Ԥ��������(276)
    MSG_REG_NEW_ALARMDISPOSAL_ASINFO_SHOW,     ///<ĳ�û�δ������ɵı�����Ϣ(277)
    MSG_REG_NEW_ALARMDISPOSAL_ANEXT_SHOW,      ///<��ȡ�����û�������Ϣ(278)
    MSG_REG_NEW_ALARMDISPOSAL_AM_SHOW,         ///<���ݱ���ID��ȡ������ע��¼��Ϣ(279)
    MSG_REG_NEW_ALARMDISPOSAL_AO_SHOW,         ///<���ݱ���ID��ȡ������¼��Ϣ(280)
    MSG_REG_NEW_ALARMDISPOSAL_CRM_SET,         ///<�������ļ�¼(281)
    MSG_REG_NEW_ALARMDISPOSAL_AC_SET,          ///<��������(282)
    MSG_REG_NEW_ALARMDISPOSAL_ACI_SET,         ///<����������־����(283)
    MSG_REG_NEW_ALARMDISPOSAL_AD_SET,          ///<������ʱ���ô洢(284)
    MSG_REG_NEW_ALARMCHECKED_PERSONS_NUM,      ///<��ȡӵ�б�������Ȩ�޵Ľ�ɫ������(285)
    MSG_REG_NEW_ALARMDISPOSAL_PEOPLE_BATCHSET, ///<�������ñ���������(286)
    MSG_REG_NEW_ALARMCHECKED_IFSETED,          ///<��ȡ�ϼ�����Ȩ���Ƿ�����(287)
    MSG_REQ_NEW_AS_USERINFO_ADD,               ///<�����û���Ϣ(288)
    MSG_REQ_NEW_AS_USERINFO_GET,               ///<��ȡ�����û���Ϣ(289)
	MSG_REQ_NEW_POSITIONINFO_GET_NEW,	       ///<��ȡλ����Ϣ�����ÿͻ����Ҽ�ʹ��(290)
	MSG_REQ_NEW_FILESERVERINFO_GET,	       	   ///<��ȡ�ļ�������������Ϣ(291)
	MSG_REQ_NEW_FILESERVERINFO_SET,	       	   ///<�ļ�������·������(292)
	MSG_REG_NEW_OPACTIONLIB_NEW,               ///<�������������_NEW(293)
	MSG_REG_NEW_INSPECT_CHECKTASKINFOWITHLOCK, ///<�����ѯ_NEW(294)
	MSG_REG_NEW_JH_COMPLEXCHECKWITHLOCK,       ///<����������Ϣ���ۺϲ�ѯWITHLOCK��295��
	MSG_REG_NEW_DOOROPENAPPLY_HISTORYINFOWITHLOCK,    ///<��ѯ��֤��ʷ��Ϣ(296)
	MSG_REG_NEW_LASTALARMDEALSTATUS_GET,   	   ///<���ݱ���Դ��ȡ���һ�������ı�������״̬(297)

	
	
	//������֤
    MSG_REG_NEW_CTRLLEVEL_SHOW = 400,                  ///<��ʾ�ܿصȼ���Ϣ (400)
    MSG_REG_NEW_CTRLLEVEL_MOD,                         ///<�޸Ĺܿصȼ���Ϣ(401)
    MSG_REG_NEW_CTRLLEVELMUL_SHOW,                     ///<������ȡ�ܿصȼ� (402)
    MSG_REG_NEW_DOOROPENAPPLY_BYCARD,                  ///<ˢ���������� (403)
    MSG_REG_NEW_DOOROPENAPPLY_EPLAN_ADD,               ///<���뿪����֤Ԥ����Ϣ(404)
    MSG_REG_NEW_DOOROPENAPPLY_METHOD_MODIFY,           ///<�޸Ĵ��÷�ʽ(405)
    MSG_REG_NEW_DOOROPENAPPLY_PROCESSSTATUS_MODIFY,    ///<�޸���֤״̬ (406)
    MSG_REG_NEW_DOOROPENAPPLY_AUDITOR,                 ///<�����������(407)
    MSG_REG_NEW_DOOROPENAPPLY_ISCOLLECTION,            ///<���������ղ� (408)
    MSG_REG_NEW_DOOROPENAPPLY_INFO_ADD,                ///<����������Ϣ����(409)
    MSG_REG_NEW_DOOROPENAPPLY_USERINFO_SET,            ///<�û���֤��������(410)
    MSG_REG_NEW_DOOROPENAPPLY_ATTACHMENTINFO_ADD,      ///<��֤������־�����(411)
    MSG_REG_NEW_DOOROPENAPPLY_APPLYLOG_ADD,            ///<��֤ϵͳ��־����(412)
    MSG_REG_NEW_DOOROPENAPPLY_MEMO_ADD,                ///<��֤�����������(413)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSLOG_ADD,           ///<ˢ����Ϣ����(414)
    MSG_REG_NEW_DOOROPENAPPLY_CLASSSCHEDULE_ADD,       ///<��β���(415)
    MSG_REG_NEW_DOOROPENAPPLY_PASSWORD_SHOW,           ///<��ȡ�û����������Ϣ(416)
    MSG_REG_NEW_DOOROPENAPPLY_ALLACCESSINFO_SHOW,      ///<��ȡ�����Ž�������Ϣ(417)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSOTHERINFO_SHOW,    ///<��ȡ�Ž�����������Ϣ(418)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSTALKINFO_SHOW,     ///<��ȡ�Ž����������Խ���Ϣ(419)
    MSG_REG_NEW_DOOROPENAPPLY_PEPOLEINFO_SHOW,         ///<��ȡ�������Ͻ�ĳ�����Ա��Ϣ(420)
    MSG_REG_NEW_DOOROPENAPPLY_SHOULDPEPOLE_SHOW,       ///<��ȡӦ����Ա��Ϣ(421)
    MSG_REG_NEW_DOOROPENAPPLY_HISTORYINFO_SHOW,        ///<��ѯ��֤��ʷ��Ϣ(422)
    MSG_REG_NEW_DOOROPENAPPLY_DETAIL_SHOW,             ///<��ѯ��֤��ʷ��ϸ��Ϣ��֤����(423)
    MSG_REG_NEW_DOOROPENAPPLY_ATTACHMENT_SHOW ,        ///<��ѯ��֤�����б�(424)
    MSG_REG_NEW_DOOROPENAPPLY_ACTIONDETAIL_SHOW,       ///<��ѯ��֤Ԥ��������Ϣ(425)
    MSG_REG_NEW_DOOROPENAPPLY_PROCESSMEMO_SHOW,        ///<��ѯ��֤��������б�(426)
    MSG_REG_NEW_DOOROPENAPPLY_ACTLOG_SHOW,             ///<��ѯ��֤ϵͳ��־�б�(427)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSLOG_SHOW,          ///<��ѯ��֤����ˢ����Ϣ�б�(428)
    MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFO_SHOW,         ///<��ѯˢ����ʷ��Ϣ(429)
    MSG_REG_NEW_DOOROPENAPPLY_STATISTICS_SHOW,         ///<��ѯͳ����Ϣ(430)
    MSG_REG_NEW_DOOROPENAPPLY_EXCEPTIONINFO_ADD,       ///<�쳣����Ϣ����(431)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSRELATION_SET,      ///<�Ž��������ƽ�����(432)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSRELATION,          ///<�����Ž���ϵ(433)
    MSG_REG_NEW_CTRLLEVELPLAN_SHOW,                    ///<��ȡ�ܿصȼ�����(434)
    MSG_REG_NEW_DOOROPENAPPLY_DEPARTMENTINFO,          ///<��ȡ������Ϣ(435)
    MSG_REG_NEW_DOOROPENAPPLY_APPLYINFOCOUNT_GET,      ///<��ȡ��֤��ʷ��Ϣ������(436)
    MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFOCOUNT_GET,     ///<��ȡˢ����ʷ��Ϣ������(437)
    MSG_REG_NEW_CTRLLEVELPLAN_PLANPROJECT,             ///<��ȡ����������(438)
    MSG_REG_NEW_CTRLLEVELPLAN_ALLDEVINFO_CL_SHOW,      ///<��ȡ�����豸�Ĺܿصȼ���Ϣ(439)
    MSG_REG_NEW_CTRLLEVELPLAN_PLANCONFIGINFO_GET,      ///<��ȡ�����������������Ϣ(440)
    MSG_REG_NEW_CTRLLEVELPLAN_PLANCONFIGINFO_SET,      ///<���ò����������������Ϣ(441)
    MSG_REG_NEW_ALLIPTALKDEVICEINFO,                   ///<��ȡIP�Խ��豸��Ϣ(442)
    MSG_REG_NEW_IPTALKPANELINFO_GET,                   ///<��ȡIP�Խ��豸�����Ϣ(443)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSIPTALK_SET,        ///<�Ž��Խ���������(444)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSIPTALK_GET,        ///<�Ž��Խ�������ȡ(445)
    MSG_REG_NEW_CTRLLEVELPLAN_CTRLLEVELSET,            ///<�ܿصȼ���������(446)
	MSG_REG_NEW_BSAPPVERSION_SHOW,                     ///<��ȡBSAPP�汾��Ϣ(447)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSMS_SCSGET,         ///<���ÿͻ����Ž����ӹ�ϵ��ȡ��448��
	MSG_REG_NEW_USERDOORCAMERARELATION_GET,       	   ///<��ȡ�û��Ž����������-���ÿͻ��ˣ�449��
	MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFO_SHOW_NEW,     ///<��ѯˢ����ʷ��Ϣ_NEW(450)
	MSG_REG_NEW_USERDOORCAMERARELATION_CLIENT_GET,     ///<��ȡ�û��Ž����������-�ͻ��ˣ�451��
	MSG_REG_NEW_USERDOORCAMERARELATION_SET,     	   ///<�û��Ž�������������ã�452��
	MSG_REG_NEW_STAFFINFOOPERATION,			     	   ///<��Ա��Ϣ��ز�����453��
	MSG_REG_NEW_DEPARTMENTINFOOPERATION,     	  	   ///<������Ϣ��ز�����454��
	MSG_REG_NEW_STAFFSTATUS_SET,     	  			   ///<��Ա״̬���ã�455��
	MSG_REG_NEW_DEPARTMENTINFO_GET,     	  		   ///<��ȡ������Ϣ(456)
	MSG_REG_NEW_AUTHGROUP_GET,     	  			  	   ///<��ȡȨ������Ϣ��457��
	MSG_REG_NEW_STAFFINFO_GET,     	  			   	   ///<��ȡ��Ա��Ϣ��458��
	MSG_REG_NEW_STAFFOPERATION_GET,     	  		   ///<��ȡ��Ա������Ϣ��459��
	MSG_REG_NEW_STAFFSYNCFLAG_SET,     	  		   	   ///<��Աͬ����־���ã�460��
	MSG_REG_NEW_STAFFAUTHINFO_GET,     	  		   	   ///<��ԱȨ�����ȡ��461��
	MSG_REG_NEW_STAFFSYNCINFO_GET,     	  		   	   ///<��ȡͬ����Ա��Ϣ��462��
	MSG_REG_NEW_ACCESSSYRELATION_SET,     	  		   ///<�Ž�������Ѻ���ã�463��
	MSG_REG_NEW_DOOROPENSYRELATION_SET,     	  	   ///<��֤��Ѻ��Ϣ������464��
	MSG_REG_NEW_ACCESSSYRELATION_GET,     	  		   ///<�Ž�������Ѻ�豸��ȡ��465��
	MSG_REG_NEW_DOOROPENSYRELATION_GET,     	  	   ///<��֤��Ѻ��Ϣ������ȡ��466��
	MSG_REG_NEW_QUERYHISTORYINFO_SY_GET,     	  	   ///<��ѯ��֤��ʷ��Ϣ���ɰ���֤���Ͳ�ѯ����467��
	
	
	
	//������ά
	MSG_REG_NEW_CAPITALINFO_OPERATION = 500,           ///<�ʲ���Ϣ��ز��������ӡ��޸ġ������޸�(500)
	MSG_REG_NEW_DETECTSCHEDULE_SET,					   ///<Ѳ��ģ��ƻ�����(501)
	MSG_REG_NEW_MALFUNCTION_INSERT,					   ///<���ϱ�����Ϣ����(502)
	MSG_REG_NEW_MAINTENCEINFO_INSERT,				   ///<����ά�޼�¼(503)
	MSG_REG_NEW_OMSERVER_OPERATION,				       ///<��ά��������ز���(504)
	MSG_REG_NEW_DETECTMODULE_OPERATION,				   ///<Ѳ��ģ����ز���(505)
	MSG_REG_NEW_CHANNELDETECTMODULE_OPERATION,		   ///<ͨ�����ģ����ز���(506)
	MSG_REG_NEW_OMSERVERDIVIDE_SET,		   			   ///<��ά����������(507)
	MSG_REG_NEW_FAULTINFO_OPERATION,		   		   ///<����������ز���(508)
	MSG_REG_NEW_DEVICEMANUFACTUREINFO_GET,		   	   ///<��ȡ�豸Ʒ����Ϣ(509)
	MSG_REG_NEW_DEVICEMODELINFO_GET,		   		   ///<��ȡ�豸�ͺ���Ϣ(510)
	MSG_REG_NEW_SUPPLIERINFO_GET,		   		       ///<��ȡ��Ӧ����Ϣ(511)
	MSG_REG_NEW_MAINTENCECOMPANY_GET,		   		   ///<��ȡά������Ϣ(512)
	MSG_REG_NEW_ENGINEERINGINFO_GET,		   		   ///<��ȡ��������Ϣ(513)
	MSG_REG_NEW_DEVICEBASEINFO_GET,		   		       ///<��ȡ�豸������Ϣ(514)
	MSG_REG_NEW_MALFUNCTIONINFO_GET,		   		   ///<���޼�¼��Ϣ��ѯ(515)
	MSG_REG_NEW_FAULTNAME_GET,		   		           ///<��ȡ��������(516)
	MSG_REG_NEW_MAINTENCEINFO_GET,		   		       ///<ά�޼�¼��Ϣ��ȡ(517)
	MSG_REG_NEW_MAINTENCEINFO_PHONE_GET,		   	   ///<��ȡά������Ϣ�����绰(518)
	MSG_REG_NEW_ALARMARMDISARMPLAN_GET,		   	       ///<���������������ƻ���ȡ(519)
	MSG_REG_NEW_CAPITALINFO_STATISTICS,		   	       ///<�豸������Ϣͳ��(520)
	MSG_REG_NEW_MALFUNCTIONINFO_STATISTICS,		   	   ///<������Ϣͳ��(521)
	MSG_REG_NEW_HOSTUSESTATUS_GET,		   	   		   ///<����ʹ��״̬��ȡ(522)
	MSG_REG_NEW_DETECTORUSESTATUS_GET,		   	   	   ///<̽ͷʹ��״̬��ȡ(523)
	MSG_REG_NEW_DETECTSCHEDULE_GET,		   	   	       ///<��ȡѲ��ƻ�(524)
	MSG_REG_NEW_MODULEINFO_GET,		   	   	           ///<��ȡģ��������Ϣ(525)
	MSG_REG_NEW_DEVICEBASEINFOBYID_CLIENT_GET,		   ///<�����豸��Ż�ȡ�豸������Ϣ���ͻ��ˣ�(526)
	MSG_REG_NEW_DEVICEBASEINFOBYID_SOFTSET_GET,		   ///<�����豸��Ż�ȡ�豸������Ϣ�����ÿͻ��ˣ�(527)
	MSG_REG_NEW_OMDEVICEINFO_GET,		   			   ///<��ȡOM�豸��Ϣ(528)
	MSG_REG_NEW_OMCHANNELINFODIVIDE_GET,		   	   ///<��ȡOMͨ����Ϣ����(529)
	MSG_REG_NEW_OMPARTATIONINFO_GET,		   		   ///<��ʾOM������Ϣ(530)
	MSG_REG_NEW_OMARMDISARMMODULE_GET,		           ///<OM��ȡ������ģ��(531)
	MSG_REG_NEW_OMARMDISARMSCHEDULE_GET,		   	   ///<OM��ȡ�����������ƻ�(532)
	MSG_REG_NEW_OMRECORDDAYSMODULE_GET,		   		   ///<OM��ȡ¼������ģ��(533)
	MSG_REG_NEW_OMCHANNELRECORDDAYS_GET,		   	   ///<OM��ȡ����ͷ¼������(534)
	MSG_REG_NEW_FAULTINFODETAIL_GET,		   	   	   ///<��ȡ������Ϣ����(535)
	MSG_REG_NEW_ASARMDISARMSCHEDULE_GET,		   	   ///<AS��ȡ�����������ƻ�(536)
	MSG_REG_NEW_ALARMARMDISARMPLANBYID_GET,		   	   ///<���������������ƻ���ȡͨ��ID(537)
	MSG_REG_NEW_DETECTMODULEINFO_GET,		   	       ///<���ÿͻ��˻�ȡѲ��ģ����Ϣ(538)
	MSG_REG_NEW_OMSERVERDIVIDEINFO_GET,		   	       ///<��ȡ���ָ�Ѳ����������豸��Ϣ(539)
	MSG_REG_NEW_OMSERVERINFO_GET,		   	      	   ///<��ȡOM��������Ϣ(540)
	MSG_REG_NEW_ALLOMINFO_SOFTSET_GET,		   	       ///<���ÿͻ��˻�ȡ����OM��Ϣ(541)
	MSG_REG_NEW_SOFTSETCHANNELRECORDDAYS_GET,		   ///<����¼������ģ��ID��ȡ��������ͷ(542)
	MSG_REG_NEW_ASDEVICEINFOBYSTATUS_GET,		  	   ///<������������ȡ�豸��Ϣͨ���豸״̬(543)
	MSG_REG_NEW_DEVICEMANUFACTUREINFOINCAPITAL_GET,	   ///<��ȡ�豸Ʒ����Ϣ��ֻ�����ʲ���Ϣ�д��ڵģ�(544)
	MSG_REG_NEW_DEVICEINFOWITHCAPITAL_GET,		  	   ///<��ȡ�豸��Ϣ�����ʲ����� (545)
	MSG_REG_NEW_FRONTENDNODEINFOWITHCAPITAL_GET,	   ///<��ȡ�豸��Ϣ�����ʲ����� (546)
	
	//ý��洢���ƽӿ�
	MSG_REG_ALARMDISPOSAL_ASSINGLE_SET_NEW = 600,      ///<��������_NEW(600)
	MSG_REG_ALARMSTORAGEFILELOCKED_SET,				   ///<���������洢�ļ�����������(601)
	MSG_REG_MEDIASTORAGEFILEINFO_INSERT,			   ///<ý��洢�ļ���Ϣд��(602)
	MSG_REG_ALARMTYPEOPERATION_NEW,			 		   ///<�����������ӡ��޸�_NEW(603)
	MSG_REG_CLEANDISKSTORAGE_SET,			 		   ///<���̲�������(604)
	MSG_REG_CLEANDISKSTORAGE_GET,			 		   ///<���̲������û�ȡ(605)
	MSG_REG_MEDIASTORAGEDELETEDBRECORD,			 	   ///<ý��洢ɾ�����ݿ��¼(606)
	MSG_REG_DELETEFILEINFO_GET,			 	           ///<��ȡҪɾ�����ļ���Ϣ(607)
	MSG_REG_ALARMCONFIG_GET_NEW,			 	       ///<��ȡ��������_NEW(608)
	MSG_REG_ALARMDEALSTRATEGY_GET_NEW,			 	   ///<������������ȡ�������ò�����Ϣ_NEW(609)
	MSG_REG_CLIENTGETMEDIASTORAGEATTACHMENT,		   ///<�ͻ��˻�ȡý��洢�ĸ���(610)
	MSG_REG_NEW_INSPECT_TASKEXCUTESET_NEW,			   ///<����Ѳ������ִ�в���_NEW(611)
	MSG_REG_NEW_DOOROPENAPPLY_INFO_ADD_NEW,            ///<����������Ϣ����_NEW(612)
	MSG_REG_GETFIRSTDAYFILEINFO,			 	   	   ///<��ȡ�����δ�������ļ�(613)
	MSG_REG_DELETEFILEINFOBYDATE,			 	   	   ///<ɾ��ָ������δ�������ļ�(614)
	
	//��������koala�ӿ�
	MSG_REG_ACTIONOPERATION_KOALA = 700,			   ///<��������ز���_Koala(700)
	MSG_REG_PREPLANOPERATION_KOALA,			   		   ///<Ԥ������ز���_Koala(701)
	MSG_REG_EVENTOPERATION_SOFTSET,			   		   ///<�¼�����ز���_NEW,���ÿͻ���ʹ��(702)
	MSG_REG_ALARMDEALKOALAINFO_INSERT,			   	   ///<�������ÿ�����Ϣд��(703)
	MSG_REG_GETACTIONLIB_KOALA,			   	   		   ///<��ȡ������_Koala(704)
	MSG_REG_GETPREPLANLIB_KOALA,			   	   	   ///<��ȡԤ����_Koala(705)
	MSG_REG_GETEVENTLIB_KOALA,			   	   	       ///<��ȡ�¼���_Koala(706)
	MSG_REG_GETALARMATTACHMENT_KOALA,			   	   ///<��ȡKoala��������(707)
	
	

    MSG_REG_NEW_FAULTINFOS = 3000,             ///<������Ϣ
    MSG_REG_NEW_ALLDISKINFO,                   ///<�����豸Ӳ����Ϣ
    MSG_REG_NEW_SETSIGNLEDISKNUM,              ///<����һ̨�豸ʵ��Ӳ����
    MSG_REG_NEW_SETMULTIDISKNUM,               ///<���ö�̨�豸ʵ��Ӳ����
    MSG_REQ_NEW_DEVNODEINFOEX,                 ///<�ͻ������ýڵ�Ĳ���

}E_MSG_REQ_SUBTYPE;

///<��־��¼�Ĳ������Ͷ���
typedef enum
{
    LOG_REALPLAY,	    ///<Ԥ��
    LOG_TALK_DEV,	    ///<�豸�Խ�
    LOG_TALK_USER,	    ///<�û��Խ�
    LOG_PLAYBACK,	    ///<�ط�
    LOG_DEV_CTRL,           ///<�豸����
    LOG_ALARMIN_CTRL,       ///<�����������
    LOG_ALARMOUT_CTRL,      ///<�����������
    LOG_CAMERA_CTRL,        ///<����ͷ����
    LOG_DEV_STATE,          ///<�豸����״̬
    LOG_USER_STATE,         ///<�û�����״̬
    LOG_GET_CMS_TIME,       ///<�鿴����ʱ��
    LOG_TALK_IP,            ///<IP�Խ�
}E_LOGTYPE;

///<--------------------���ݽṹ����-------------------------------------
typedef struct
{
	char Name[20];		///<��������
	char AreaCode[20];	///<�������
	long  AreaID;        ///<����ID
	char FatherCode[20]; ///<���ڵ�ı��
	int  MaxviewNum;     ///<����ϴ�ͨ����
	int  AreaType;       ///<���㼶��
}T_AREAINFO, *LPT_AREAINFO;

///<ͨ����Ϣ�ṹ
typedef struct
{
    unsigned long  lDvrID;
    unsigned long  lChannelNO;
}T_CHANNEL_INFO, *LPT_CHANNEL_INFO;

///<�豸������Ϣ�ṹ
typedef struct
{
    char  chNumber[20];   ///<�豸�ַ������
    char  chIp[20];       ///<�豸IP
    char  chUserName[20]; ///<�û���
    char  chPassWord[20]; ///<����
    long  lNumber;        ///<�豸���ͱ��
    long  lCenterID;      ///<��������ID
    int   nPort;          ///<�˿ں�
    int   nChannelNum;    ///<ͨ����
    int   nDevType;       ///<�豸����
    int   nType;          ///<����
    int   nSubType;       ///<�ͺ�
    int   nNeedLink;      ///<�Ƿ���Ҫ����
    char  Area[20];       ///<��������
}T_DEV_BASE_INFO, *LPT_DEV_BASE_INFO;

///<�豸������Ϣ�ṹ����
typedef struct
{
    char  chDvrName[40];  ///<�豸����
    char  chNumber[20];   ///<�豸�ַ������
    char  chIp[20];       ///<�豸IP
    char  chUserName[20]; ///<�û���
    char  chPassWord[20]; ///<����
    long  lNumber;        ///<�豸���ͱ��
    long  lCenterID;      ///<��������ID
    int   nPort;          ///<�˿ں�
    int   nChannelNum;    ///<ͨ����
    int   nDevType;       ///<�豸����
    int   nType;          ///<����
    int   nSubType;       ///<�ͺ�
    int   nNeedLink;      ///<�Ƿ���Ҫ����
    char  Area[20];       ///<��������
}T_DEV_BASE_INFO_EX, *LPT_DEV_BASE_INFO_EX;

///<�豸������Ϣ������������Ϣ��
typedef struct
{
    char  chDvrName[40];  ///<�豸����
    char  chNumber[20];   ///<�豸�ַ������
    char  chIp[20];       ///<�豸IP
    char  chUserName[20]; ///<�û���
    char  chPassWord[20]; ///<����
    long  lNumber;        ///<�豸���ͱ��
    long  lCenterID;      ///<��������ID
    int   nPort;          ///<�˿ں�
    int   nChannelNum;    ///<ͨ������  
    int   nDevType;       ///<�豸����
    int   nType;          ///<����
    int   nSubType;       ///<�ͺ�
    int   nNeedLink;      ///<�Ƿ���Ҫ����
    char  Area[20];       ///<��������
    int linkNum;                  ///<��������
    T_CHANNEL_INFO ARRDevinfo[32];///<����ͨ����
}T_DEV_BASE_INFO_EX_NEW, *LPT_DEV_BASE_INFO_EX_NEW;


///<AS��Ҫ���豸��Ϣ�ṹ
typedef struct
{
    T_DEV_BASE_INFO TBaseInfo;   ///<������Ϣ
    int arraySensorInfo[256][2];  ///<̽ͷ�����Ϣ��[*][0]-�Ƿ�Խ�������-1�����������ͣ�>0����δ�裨=0����[*][1]-�Խ�ͨ��(>0)
    int arrayManualSensorInfo[256]; ///<�ֶ��������ͣ�>0��
}T_AS_DEV_INFO, *LPT_AS_DEV_INFO;

///<AS��Ҫ���豸��Ϣ�ṹ����ֵ���豸����
typedef struct
{
    T_DEV_BASE_INFO_EX TBaseInfoEx;   ///<������Ϣ
    int arraySensorInfo[256][2];  ///<̽ͷ�����Ϣ��[*][0]-�Ƿ�Խ�������-1�����������ͣ�>0����δ�裨=0����[*][1]-�Խ�ͨ��(>0)
    int arrayManualSensorInfo[256]; ///<�ֶ��������ͣ�>0��
}T_AS_DEV_INFO_EX, *LPT_AS_DEV_INFO_EX;

///<MS��Ҫ���豸��Ϣ�ṹ
typedef struct
{
    T_DEV_BASE_INFO TBaseInfo;

    char szVodPwd[20]; ///<������Ҫ �ط��û�����
    char szVodName[20];
    bool bLongLink; ///<�Ƿ񱣳ֳ�����
}T_MS_DEV_INFO, *LPT_MS_DEV_INFO;

///<MS��Ҫ���豸��Ϣ�ṹ����ֵ���豸����
typedef struct
{
    T_DEV_BASE_INFO_EX TBaseInfoEx;

    char szVodPwd[20]; ///<������Ҫ �ط��û�����
    char szVodName[20];
    bool bLongLink; ///<�Ƿ񱣳ֳ�����
}T_MS_DEV_INFO_EX, *LPT_MS_DEV_INFO_EX;

///<�û�������Ϣ
typedef struct
{
    char chUsername[20];
    char chPassword[20];

    ///<��Щ�û���Ҫ�ڹ̶��������ϵ�¼����ҪMac��ַ��IP
    char chMACAddr[20];  ///<����MAC��ַ ��
    char chIP[20];      ///<�̶�������IP��
    int  nPrity;        ///<�ȼ�
    char Question[50];
	char Answer[50];
    TJTY_TIME TValiadStartTime;   ///<��Ч�ڿ�ʼʱ��
    TJTY_TIME TValiadEndTime;     ///<��Ч�ڽ���ʱ��
}T_USER_INFO, *LPT_USER_INFO;

///<�û�����Ȩ�޽ṹ
typedef struct
{
    bool UserMrg;///<�û�����
	bool DevMrg; ///<�豸����
	bool Real_TimeVideoView; ///<ʵʱԤ��
	bool Talk; ///<�Խ�
	bool GroupTalk;///<Ⱥ��
	bool DevCtrl; ///<�豸����
	bool StateLookUp; ///<״̬��ѯ
	bool Polling;///<Ѳ��
	bool DevMsgLookUp;  ///<dvr ��־��ѯ
	bool m_AssetsMag;   ///<�ʲ�����Ȩ��
	bool m_EventMag;    ///<�¼�����
	bool m_SystemConfig;  ///<ϵͳ����
	bool RecvAlarm;    ///<�Ӿ�
	bool PlayBack;      ///<�ط�
    bool bIsVIP;        ///<VIP�û�
}T_USER_TOTAL_AUTH, *LPT_USER_TOTAL_AUTH;

///<�û����嵽ͨ����Ȩ�޽ṹ
typedef struct
{
    unsigned int RealTimeView; ///<ʵʱԤ��Ȩ��
	unsigned int PlayBack;     ///<�ط�Ȩ��
	unsigned int Download;     ///<����Ȩ��
	unsigned int VideoConfig;  ///<��Ƶ��������Ȩ��
	unsigned int HolderCtrl;   ///<��̨����Ȩ��
}T_USER_AUTH_CHL, *LPT_USER_AUTH_CHL;

///<�û����豸������Ȩ��
typedef struct
{
    long lDEVID;     ///<�豸ID��
	bool AlarmOutCtrl;///<���������Ȩ��
	bool DevAct;      ///<���ػ�����Ȩ��
	bool AlarmInCtrl; ///<���������Ȩ��
	bool DevUpgrade;  ///<���豸����Ȩ��
	bool DevTime;     ///<���豸УʱȨ��
	bool DevLogLookUp;///<���豸��־�鿴Ȩ��
	bool DevConfig;   ///< ���豸����Ȩ��
	bool TalkDevc;    ///<�Խ�Ȩ��
	bool RecvAlarmDev;///<���ձ���Ȩ��
	T_USER_AUTH_CHL ChannelPower;  ///<ͨ��Ȩ��
}T_USER_AUTH_DEV, *LPT_USER_AUTH_DEV;

///<�û��Ӿ�Ȩ�޽ṹ
typedef struct
{
    long lDEVID;    ///<�豸ID
    int  nRecvAlarmLevel;  ///<����ĽӾ��ȼ�
}T_USER_AUTH_ALARM, *LPT_USER_AUTH_ALARM;
/*
typedef struct
{
    char chUsername[20];
    char chPassword[20];
    int  nPrity;        ///<�ȼ�
    T_USER_AUTH_ALARM Dev_AUTHInfo[2000];  ///<�豸����Ӧ�ĽӾ��ȼ���Ϣ
    bool IsSystem;
}T_USER_DEV_ALARMAUTH, *LPT_USER_DEV_ALARMAUTH;   */

///<����ͷ��Ϣ�ṹ
typedef struct
{
    char Name[20];   ///<����ͷ����
    char CameraCode[20];	///<����ͷ����
    unsigned long  lDVRID;   ///<�豸���
    int  nChannelNO;           ///<ͨ����
    int  NetModel;      ///<����ģ�� 0�������� 1�� ������
    int  AreaPri;       ///<����ȼ���
    int linkNum;
    T_CHANNEL_INFO ARRDevinfo[5];///<����ͨ����  Ŀǰ��Ʒ����Ϊ4������5��Ԥ����
}T_CAMERA_INFO, *LPT_CAMERA_INFO;

///<����ͷ��Ϣ�ṹ����������Ϣ��
typedef struct
{
    char Name[64];                ///<����ͷ����
    char CameraCode[32];	  ///<����ͷ����
    unsigned long  lDVRID;        ///<�豸���
    int  nChannelNO;              ///<ͨ����
    int  NetModel;                ///<����ģ�� 0-CIF; 1-D1; 2-720P; 3-1080P
    int  AreaPri;                 ///<����ȼ�
    int linkNum;                  ///<��������
    T_CHANNEL_INFO ARRDevinfo[32];///<����ͨ����
}T_CAMERA_INFO_NEW, *LPT_CAMERA_INFO_NEW;

///<̽ͷ��Ϣ�ṹ
typedef struct
{
    char Name[20];
    char AlarmCode[20];
    int  nChannelNO;           ///<ͨ����
    unsigned long  lDVRID;     ///<�豸���
    ///<�������ͣ��������͡� ����AlarnIn ��ʾΪ�ӱ������ͣ�AlarmOut��ʾ������������(�Ž����Ƶ�)
    int  AlarmType;
    int  AreaPri;       ///<����ȼ���
    int linkNum;
    T_CHANNEL_INFO ARRDevinfo[32];///<����ͨ����
}T_SENSOR_INFO, *LPT_SENSOR_INFO;

///<ý���������Ϣ�ṹ
typedef struct
{
    char MSCode[20];   ///<��ý����
    char PassWorld[20];
    unsigned long IP;
    int  DataPort;    ///<ý������ݶ˿ڡ�
	unsigned long MSAbility;///<ý�������������
}T_MS_INFO_STRU, *LPT_MS_INFO_STRU;

///<������������Ϣ�ṹ
typedef struct
{
    char ASCode[20];   ///<�������������
    char PassWorld[20];
    unsigned long IP;
}T_AS_INFO_STRU, LPT_AS_INFO_STRU;

///<������Ϣ����
typedef struct
{
    int nFiltrateFlag;  ///<0�������ˣ�1�����ˣ�2��������
    int nInterval;      ///<���˼������λΪ��
    unsigned char ucIsSaveText;///<�Ƿ�洢�������֣�1:�洢��0:���洢
    unsigned char ucIsSaveVideo;///<�Ƿ�������Ƶ�洢��1:������0:������
    int nSaveTime;               ///<�洢ʱ����S��
}T_ALARM_DEALINFO, *LPT_ALARM_DEALINFO;

typedef struct
{
    TJTY_TIME StartTime;
    TJTY_TIME EndTime;
}T_ALARM_TIMESEGMENT, *LPT_ALARM_TIMESEGMENT;

///<�����������
typedef struct
{
    int nAlarmType;  ///<��������
    T_ALARM_TIMESEGMENT TimeSegment[6];
    T_ALARM_DEALINFO T_AlarmDeal[6];
}T_ALARM_DEAL_STRATEGY, *LPT_ALARM_DEAL_STRATEGY;

///<����������Ϣ�ṹ
typedef struct
{
    unsigned char ucChannel;///<ͨ����
    unsigned char ucSourceType;///<����Դ���ͣ�̽ͷ��������������ȣ�
    unsigned char ucAlarmType;///<�������ͣ���Ƶ��ʧ���ƶ������⡢Ļ���ȣ�
    unsigned char ucReserved;///<����λ
}SIGNALALARM;

///<����������Ϣ�ṹ(JH - NEW)
typedef struct
{
    unsigned char ucChannel;     ///<ͨ����
    unsigned char ucSourceType;  ///<����Դ���ͣ�̽ͷ��������������ȣ�
    unsigned char ucAlarmType;   ///<�������ͣ���Ƶ��ʧ���ƶ������⡢Ļ���ȣ�
    unsigned char ucReserved;    ///<�����ȼ�
    char chMemo[128];            ///<��ע��Ϣ[���������š�����ʱ����Ϣ]
}SIGNALALARM_NEW;

///<������Ϣ�ṹ
typedef struct
{
    char      chNumber[20];
    char      chIp[20];
    long      lNumber;
    int       nAlarmCount;
    TJTY_TIME   tTime;
}T_ALARMInfo;

///<��־��¼ģ��
typedef struct
{
	unsigned long DeviceID;
	unsigned int udChannel;
	char chOpDesip[256];///<��������
	char UserName[20];  ///<�����û���
	TJTY_TIME OpTime;///<���鷢��ʱ��
	unsigned int Optype;///<�������� ��LOGTYPE
	bool OpenOrClose;   ///<������Ƶ�ʱ������˵���Ǵ򿪻��ǹرա�
}T_DEVSQL_LOGINFO, *LPT_DEVSQL_LOGINFO;

///<�û��Խ���־��¼
typedef struct
{
	char UserName[20];	///<�������û���
	char Ip[20];
	char chOpDesip[256];///<��������
	char AskUserName[20];  ///<�����û��������û�����
	TJTY_TIME  OpTime;///<���鷢��ʱ��
	unsigned int Optype;///<�������ͼ�LOGTYPE
}T_USERTALK_LOGINFO, *LPT_USERTALK_LOGINFO;

///<��־���Ͷ���
/*
typedef enum           .
{
	REALTIME_VIEW,	///<ʵʱ��ƵԤ��
	TALKWITHDEV,	///<���豸�Խ�
	TALKWITHUSER,	///<��ͻ��Խ�
	PLAYBACK,		///<�ط�����
	DEVCTRLLOG,     ///<�豸���ƣ��������ػ���Уʱ�Ȳ���
	ALARMINCTRL,    ///<̽ͷ���ƣ���ʱ DevSqllog udChannel ��ʾ����̽ͷ���飬��λ���㡣
	ALARMOUTCTRL,	///<������� ��ʱDevSqllog udChannel ��ʾ��������š���Ҫ������������ж�����ӵ���ʲô��
	DEVCAMERACTL    ///<����ͷ����
}LOGTYPE;
*/

///<Уʱ�ƻ�
typedef struct
{
    unsigned int nPlanID;
    TJTY_TIME TExecTime;     ///<Уʱ��ʼִ��ʱ���
    TJTY_TIME TLastSetTime;  ///<�ϴ�ִ��ʱ��
    int       nSetTimeCycle; ///<Уʱ���� 1-8Сʱ��2-16Сʱ��3-24Сʱ��
                             ///<4-һ�ܣ�7*24Сʱ����5-һ�£�30*24Сʱ��
}T_SETTIME_PLAN, *LPT_SETTIME_PLAN;

///<��¼�豸�û�����������Ϣ
typedef struct
{
    char chUserName[20];    ///<��¼�豸�û���
    char chPassWord[20];    ///<��¼�豸����
    unsigned long ulDEVID;  ///<�豸ID
}T_DEV_LOGINFO, *LPT_DEV_LOGINFO;

///<���Ĺ����������Ϣ�ṹ
typedef struct
{
    char chCMSMemo[200];   ///<��ע������
    char chCMSName[50];
    char chUserName[20];   ///<��¼�¼����ĵ��û���
    char chPassWord[20];   ///<��¼�¼����ĵ�����
    unsigned long ulCMSIP;
    long lCenterID;         ///<������ı��
    long lFatherCenterID;   ///<��������ı��
    int nPort;              ///<��ʱ�̶�Ϊ4000
    int nType;              ///<1-������CMS��2-��������CMS��3-�¼���CMS�� 4-�¼�����CMS
}T_CMS_INFO_STRU, *LPT_CMS_INFO_STRU;
/**************************************************************************/
///<��ȡʱ����Ҫ�Ĳ����ṹ

///<��ȡ�豸�б���Ϣʱ��Ҫ�Ĳ����ṹ
///<MSG_REQ_AREA_INFO,  MSG_REQ_DEV_BASE_INFO,  MSG_REQ_DEV_AS_INFO,
typedef struct
{
	unsigned int DevType;    ///<�豸���ͣ��ɰ�λ��
	char ServerCode[20];     ///<����������
}T_GDEVPARAM;

///<��ȡ�����豸��Ϣʱ����Ҫ�Ĳ����ṹ
typedef struct
{
    unsigned int unDEVID;   ///<�豸ID
	char ServerCode[20];    ///<����������
}T_GSDEV_PARA;

///<��ȡָ���û���ָ���豸��Ȩ��
typedef struct
{
    char chUserName[20];
    unsigned int unDEVID;   ///<�豸ID
}T_GSDEV_AUTH_PARA;

///<��ȡָ���û���¼ָ���豸�ĵ�¼��Ϣ
typedef struct
{
    char chUserName[20];    ///<�û���
    unsigned int unDEVID;   ///<�豸ID
}T_USERNAME_DEVID;


///<������������MS�ϵĵ㲥�ļ�

typedef struct
{
    long lDevId;            ///<�豸ID
    char chAreaName[64];    ///<��������
    TJTY_TIME TStartTime;   ///<��ʼʱ��
    TJTY_TIME TStopTime;    ///<����ʱ��
    int nChannel;           ///<ͨ����
	int nFileType;			///<�ļ����ͣ�1-�ƻ��洢��2-�����洢;3-���д洢;4-�¼ƻ��洢��5-�������洢��
    char chAlarmTypeName[20];   ///<������������
    char chOtherInfo[20];       ///<��������
}T_MSVOD_SEARCH_PARA;



///< ��DCOMͨ�ŷ�ʽת��ΪTCPͨ�ŷ�ʽ( Modify by mgy )

///< ִ����ɾ�Ĳ���������Ϣ�ṹ��(common-out)
typedef struct
{
    char chReturn[256];        ///< ִ����ɾ�ķ���ֵ(Ĭ��"1"Ϊִ�гɹ�����֮Ϊ�쳣�ִ�)
}S_CommonRet;


///< ��ȡ����ڵ���ϸ��Ϣ������ (1-int)
typedef struct
{
    int nNodeId;         ///<�ڵ�����ID
    char chSerial[32];   ///<�ڵ����
    char chName[64];     ///<�ڵ�����
    int bCondition;      ///<��ѯ����
    char chUserName[64]; ///<�û�������ȡ��������ʱ���룩
}P_AreaInfo;
/******************************
P_AreaInfo.bCondition:

0�������������������
1�����������ŷ����ض������µ����нڵ㣨���㡢������ǰ���豸��
2�����������ŷ����ض�����Ĳ���ͼ��·��������
3�����������������ϸ��Ϣ����������������
4�������������Ʒ����ض�����Ĳ���ͼ��·�������ƣ����и�����ı��
5�����������ŷ����ض��������ϸ��Ϣ
6�����������������ϸ��Ϣ
7�������������Ʒ����ض��������ϸ��Ϣ
8�����������ŷ����ض��������ϸ��Ϣ
9�������û������ع�������
100��������������ID���رȸ�����IDС���������֣����߲㼶�����㣩
101: ������������ı��+�������ͣ�
******************************/
///< ��ȡ����ڵ���ϸ��Ϣ������ (1-out)
typedef struct
{
    int nAreaId;                      ///<�ڵ�ID
    char chCode[32];                  ///<�ڵ����
    char chName[64];                  ///<�ڵ�����
    char chFatherNo[32];              ///<��һ������
    char chAddress[128];              ///<�����ַ
    char chManName[64];               ///<��ϵ��
    char chContactInfo[64];           ///<��ϵ��ʽ
    int nAreaTypeID;                  ///<�ڵ�����ID��1~8,9,10,11,12,13��
    char chNodeTypeName[64];          ///<�ڵ�������
    int nAreaLevel;                   ///<�ڵ㼶��1~101,102,103,200,300,400��
    int  nXPos;                       ///<�ڵ�ͼ�ϵ�X���꣨ǧ���ƣ�
    int  nYPos;                       ///<�ڵ�ͼ�ϵ�Y���꣨ǧ���ƣ�
    int  nSize;                       ///<ͼ���С
    int  nWay;                        ///<ͼ�귽��
    int nNetWidthLimit;               ///<�������
    int nUpLoadMaxChlNum;             ///<����ϴ�ͨ����
    int nImageID;                     ///<ͼƬID
    int nAutoSwitch;                  ///<�����Ƿ��Զ��л�
    char chImageName[64];             ///<ͼ������
    char chImagePath[256];            ///<ͼ���ļ�·��
    char chMapName[64];               ///<��ͼ�ļ�����
    char chMapPath[256];              ///<��ͼ�ļ�·��
    int  nMapSize;                    ///<��ͼ��С���ֽڣ�
    char SwitchNetWidth[64];          ///<�ٽ����
    int SwitchUploadLimit;            ///<�ٽ�ͨ����
    char chCenterNo[128];             ///<���ı��
    char chFatherCenterNo[128];       ///<�����ı��
    char chUserName[64];              ///<�û�������ȡ����ʱ���أ�
    char chMemo[512];                 ///<��ע
    int nAreaPosition;                ///<����
}S_AreaNodeInfo;

///< ��ȡ�����豸��Ϣ(DVR�������������Ž�) (2-out)
typedef struct
{
    int nID;                    ///< �豸ID
    char chDevCode[64];         ///< �豸����
    char chDevName[128];        ///< �豸����
    char chDevIp[32];           ///< �豸IP��ַ
    char chAreaCode[64];        ///< �����������
    int nDeviceType;            ///< �豸����(9��11��14)
    int nPort;                  ///< �˿ں�
    int nHostSpeak;             ///< �����Խ�
    int nAlarmFilter;           ///< �������˱�־
    char chAlarmFilterDate[64]; ///< ��������ʱ��
    int nCanSpreak;             ///< �ܷ�Խ�
    int nAutoIp;                ///< �Զ�IP
    int nProportionX;           ///< ǧ����X����
    int nProportionY;           ///< ǧ����Y����
    int nImageSize;             ///< ͼ���С
    int nImageDirection;        ///< ͼ�귽��
    int nAlarmLevel;            ///< ��������ȼ�
    int nDevTypeID;             ///< �豸����ID��Ʒ��ID��
    char chDevModelNo[128];     ///< �豸�ͺ�
    int nIsConnected;           ///< �Ƿ���Ҫ����
    char chIpSpeak[128];        ///< IP�Խ�
    char chDevManufacture[64];  ///< Ʒ������
    int nDevManufatureID;       ///< Ʒ�Ʊ��
    char chCenterNo[128];       ///< ���ı��
    char chFatherCenterNo[128]; ///< �����ı��
    int nDevTypeCode;           ///< �豸���ͱ�ţ�2*n��
    int nKeyPart;               ///< ��λ
}S_DevNodeInfo;

///< ��ȡ�����豸��Ϣ(DVR�������������Ž�) (2-out)  new
typedef struct
{
    int nID;                    ///< �豸ID
    char chDevCode[64];         ///< �豸����
    char chDevName[128];        ///< �豸����
    char chDevIp[32];           ///< �豸IP��ַ
    char chAreaCode[64];        ///< �����������
    int nDeviceType;            ///< �豸����(9��11��14)
    int nPort;                  ///< �˿ں�
    int nHostSpeak;             ///< �����Խ�
    int nAlarmFilter;           ///< �������˱�־
    char chAlarmFilterDate[64]; ///< ��������ʱ��
    int nCanSpreak;             ///< �ܷ�Խ�
    int nAutoIp;                ///< �Զ�IP
    int nProportionX;           ///< ǧ����X����
    int nProportionY;           ///< ǧ����Y����
    int nImageSize;             ///< ͼ���С
    int nImageDirection;        ///< ͼ�귽��
    int nAlarmLevel;            ///< ��������ȼ�
    int nDevTypeID;             ///< �豸����ID��Ʒ��ID��
    char chDevModelNo[128];     ///< �豸�ͺ�
    int nIsConnected;           ///< �Ƿ���Ҫ����
    char chIpSpeak[128];        ///< IP�Խ�
    char chDevManufacture[64];  ///< Ʒ������
    int nDevManufatureID;       ///< Ʒ�Ʊ��
    char chCenterNo[128];       ///< ���ı��
    char chFatherCenterNo[128]; ///< �����ı��
    int nDevTypeCode;           ///< �豸���ͱ�ţ�2*n��
    int nKeyPart;               ///< ��λ
    char chSetDate[32];         ///< �豸���ʱ��
}S_DevNodeInfo_New;

///< ��ȡǰ���豸��Ϣ(����ͷ��̽ͷ�����)(3-out)
typedef struct
{
    int nID;                    ///< �豸ID
    char chFrontendCode[64];    ///< �豸����
    char chFrontendName[128];   ///< �豸����
    int nChannelNo;             ///< ͨ����
    int nDeviceType;            ///< �豸����(10��12��13)
    int nDeviceUseage;          ///< �豸������λ��ʶ(2,1,4)
    char chAreaCode[64];        ///< �����������
    char chHostCode[64];        ///< ������������
    int nProportionX;           ///< ǧ����X����
    int nProportionY;           ///< ǧ����Y����
    int nImageSize;             ///< ͼ���С
    int nImageDirection;        ///< ͼ�귽��
    int nHolder;                ///< ��̨���Ʊ�־
    int nSpeak;                 ///< �Խ�������־
    int nAlarmFilter;           ///< �������˱�־
    char chAlarmFilterDate[64]; ///< ��������ʱ��
    int nAlarmLevel;            ///< ��������ȼ�
    int nChannelRelated;        ///< ����ͨ����־
    int nNetModel;              ///< ����ģʽ
    char chAreaName[256];       ///< ������������
    char chDeviceName[256];     ///< ������������
    char chNetModel[64];        ///< ����������ϸ��Ϣ
    int nCameraAreaID;          ///< ����ͷ�������ID
    char chCenterNo[128];       ///< ���ı��
    char chFatherCenterNo[128]; ///< �����ı��
    int nKeyPart;               ///< ��λ
}S_FrontendNodeInfo;

///< ��ȡ�û���ϸ��Ϣ(4-int)
/******************************
P_UserInfo.nCondition:

0�����������û���ϸ��Ϣ
1�������û�����Ȩ�޷����û���Ȩ����Ϣ
2�������û�����ȡ�û�����ϸ��Ϣ
3: ��ȡ���е��û�
4: �����û�ID��ȡ�û�����ϸ��Ϣ
5: ��ȡδ��������ǽ�û���
6: ��ȡ����ǽ(ģʽ��Ӧ)��Ϣ
10: ���������û���Ϣ(����ͷ��) ע�����ΪS_New_UserInfo
******************************/
typedef struct
{
    int nCondition;             ///< ��ѯ����
    char chUserName[64];        ///< �û���
	char chPrivilege[128];      ///<Ȩ������(Ŀǰ��ֵĬ�Ϲ̶�Ϊ��ƵԤ��)
}P_UserInfo;

///< ��ȡ�û���ϸ��Ϣ(4-out)
typedef struct
{
    int nID;                    ///< �û�ID
    char chUserCode[32];        ///< ����
    char chUserName[64];        ///< �û���
    char chPassword[64];        ///< ����
    int  nLevel;                ///< �û�����
    char chRole[128];           ///< �û���ɫ
    int  nLock;                 ///< �������Ƿ����ù������㣩
    char chStartTime[32];       ///< �û���Ч��ʼʱ��
    char chEndTime[32];         ///< �û���Ч����ʱ��
    char chPhone[64];           ///< �绰
    char chEmail[64];           ///< Email
    char chAbout[500];          ///< �û����
    /***************************��ȡ�û�Ȩ��************************/
    char chPrivilege[128];      ///< Ȩ������
    char chPrivilegeDetail[128];///< ��ϸȨ����Ϣ
    int nHostID;               ///< ��Ӧ������ID
    int nChannels;             ///< ��Ӧ����ȫ��ͨ����ƴ�ӵ�ͨ������ɵ�����ֵ��
}S_UserInfo;

///< ��ȡ�û���ϸ��Ϣ(4-out)(��ͷ��)
typedef struct
{
    int nID;                    ///< �û�ID
    char chUserCode[32];        ///< ����
    char chUserName[64];        ///< �û���
    char chPassword[64];        ///< ����
    int  nLevel;                ///< �û�����
    char chRole[128];           ///< �û���ɫ
    int  nLock;                 ///< �������Ƿ����ù������㣩
    char chStartTime[32];       ///< �û���Ч��ʼʱ��
    char chEndTime[32];         ///< �û���Ч����ʱ��
    char chPhone[64];           ///< �绰
    char chEmail[64];           ///< Email
    char chAbout[500];          ///< �û����
    char chImage[512];          ///< �û�ͷ��
}S_New_UserInfo;

///< ��ȡ�û���ϸ��Ϣ(4-out)[��������/����]
typedef struct
{
    int nID;                    ///< �û�ID
    char chUserCode[32];        ///< ����
    char chUserName[64];        ///< �û���
    char chPassword[64];        ///< ����
    int  nLevel;                ///< �û�����
    char chRole[128];           ///< �û���ɫ
    int  nLock;                 ///< �������Ƿ����ù������㣩
    char chStartTime[32];       ///< �û���Ч��ʼʱ��
    char chEndTime[32];         ///< �û���Ч����ʱ��
    char chPhone[64];           ///< �绰
    char chEmail[64];           ///< Email
    char chAbout[500];          ///< �û����
    bool bUseful;               ///< ����/����
    char chLevels[64];          ///< �����ȼ�ֵ��$
}S_UserInfo_Useful;

///< ��ȡ���ķ�������ϸ��Ϣ(5-int)
/******************************
P_CMSInfo.nCondition:

0�������������ķ�������ϸ��Ϣ
1�����ر������ķ�������ϸ��Ϣ
3�������¼����ķ�������ϸ��Ϣ
******************************/
typedef struct
{
    int nCondition;             ///< ��ѯ����
}P_CMSInfo;

///< ��ȡ���ķ�������ϸ��Ϣ(5-out)
typedef struct
{
    int nID;                    ///< ����ID
    char chCmsCode[64];         ///< ���ı���
    char chCmsName[64];         ///< ��������
    char chIP[64];              ///< ����IP(��)
    char chViceIP[64];          ///< ����IP(��)
    int  nType;                 ///< �������ͣ�1-�������ģ�3-�¼����ģ�
    char chCenterNo[32];        ///< ���ı��
    char chFatherCenterNo[32];  ///< �����ı��
    char chUserName[64];        ///< ��¼���ĵ��û���
    char chPassword[64];        ///< ��¼���ĵ�����
}S_CMSInfo;

///< ��ȡͨ������ϸ��Ϣ(6-int)
/******************************
P_ChannelInfo.nCondition:

0����������ͨ���������
1������ͨ�������Ʒ��ظ�ͨ�����µ�����ͨ����Ϣ
******************************/
typedef struct
{
    int nCondition;             ///< ��ѯ����
    char chGroupName[128];      ///< ͨ��������(nCondition =1ʱ������)
}P_ChannelInfo;

///< ��ȡͨ������ϸ��Ϣ(6-out)
typedef struct
{
    char chChannelGroup[128];   ///< ͨ��������
    char chName[128];           ///< ͨ����
    int nChannelNo;             ///< ͨ����
    char chHostCode[64];        ///< �������
    int  nSequence;             ///< ͨ������˳��
}S_ChannelInfo;

///< ��ȡ�����Խ�������Ϣ(7-out)
typedef struct
{
    int nDeviceID;             ///< �豸ID
    int nLinkNum;              ///< ��������
    int nCameraID[32];         ///< ��������ͷID����
}S_HostTalkInfo;

///< ��ȡǰ���豸�Խ�������Ϣ(8-out)
typedef struct
{
    int nFrontendID;           ///< ǰ���豸ID
    int nLinkNum;              ///< ��������
    int nCameraID[32];         ///< ��������ͷID����
}S_FrontendTalkInfo;

///< ��ȡ����ǽ��ϸ��Ϣ(9-int)
/******************************
P_ScreenInfo.nCondition:

0���������е���ǽ��ϸ��Ϣ
1�������û��������ض��û��ĵ���ǽ��ϸ��Ϣ
******************************/
typedef struct
{
    int nCondition;             ///< ��ѯ����
    char chUserName[128];       ///< �û���(nCondition =1ʱ������)
}P_ScreenInfo;

///< ��ȡ����ǽ��ϸ��Ϣ(9-out)
typedef struct
{
    char chUserName[128];     ///< �û���
    char chWeek[32];          ///< ����
    int nTimeConsequence;     ///< ʱ���
    char chStartTime[64];     ///< ��ʼʱ��
    char chEndTime[64];       ///< ����ʱ��
    int  nDevide;             ///< ����ָ���
    int nSwitchTime;          ///< �л����
    int nDeviceID;            ///< ����ID
    char chDeviceName[128];   ///< ������
    char chChannelName[128];  ///< ͨ����
    int nChannelNo;           ///< ͨ����
    int nShowScreen;          ///< ��ʾ��ʽ
}S_ScreenInfo;

///< ��ȡԤ������ϸ��Ϣ(10-int)
/******************************
P_EmergencyInfo.nCondition:

0����������Ԥ����
1����������Ԥ����ϸ��Ϣ
2�������û��������ض��û���Ԥ����ϸ��Ϣ
******************************/
typedef struct
{
    int nCondition;             ///< ��ѯ����
    char chUserName[128];       ///< �û���(nCondition =2ʱ������)
}P_EmergencyInfo;

///< ��ȡԤ������ϸ��Ϣ(10-out)
typedef struct
{
    int nEmergencyID;             ///< Ԥ����ID
    char chEmergencyGroup[128];   ///< Ԥ��������
    int nE_Devide;                ///< ����ָ���
    int nE_SwitchTime;            ///< �л����
    int nUserID;                  ///< �û�ID
    char chUserName[128];         ///< �û���
    int nDeviceID;                ///< ����ID
    char chHostCode[64];          ///< �������
    char chDeviceName[128];       ///< ������
    char chChannelName[128];      ///< ͨ����
    int nChannelNo;               ///< ͨ����
    int nSequence;                ///< ͨ������˳��
    int nDevide;                  ///< �û���ʾ����ָ���
    int nSwitch;                  ///< �û���ʾ�л����
    int nShowScreen;              ///< ��ʾ��ʽ
}S_EmergencyInfo;

///< ��ȡ����������ϸ��Ϣ(11-out)
typedef struct
{
    int nAlarmTypeID;             ///< ��������ID
    char chAlarmTypeName[128];    ///< ������������
    char chAlarmTypeSound[128];   ///< �������Ͷ�Ӧ��������
}S_AlarmTypeInfo;

///< ��ȡ��������������ϸ��Ϣ(12-int)
/******************************
P_HostAlarmInfo.nCondition:

0������������Ӧ����������ϸ��Ϣ
1�����������������ض�������Ӧ����������ϸ��Ϣ
******************************/
typedef struct
{
    int nCondition;             ///< ��ѯ����
    char chDeviceName[128];     ///< ��������(nCondition =1ʱ������)
}P_HostAlarmInfo;

///< ��ȡ��������������ϸ��Ϣ(12-out)
typedef struct
{
    int nDeviceID;              ///< �豸ID
    char chDeviceCode[64];      ///< ��������
    char chDeviceName[128];     ///< ��������
    char chIP[64];              ///< ����IP
    int nPort;                  ///< �˿�
    char chAreaCode[64];        ///< �����������
    int nDeviceType;            ///< �豸���ͣ�9��15��
    int nAlarmLevel;            ///< �������򼶱�
    int nDeviceTypeID;          ///< �豸����ID
    char chModelName[128];      ///< �ͺ�
    int nAlarmTypeID;           ///< ��������ID
    char chAlarmTypeName[128];  ///< ������������
    char chAlarmTypeSound[128]; ///< �������Ͷ�Ӧ��������
}S_HostAlarmInfo;

///< ��ȡǰ���豸����������ϸ��Ϣ(13-int)
/******************************
P_FrontendAlarmInfo.nCondition:

0������ǰ���豸��Ӧ����������ϸ��Ϣ
1������ǰ���豸�������ض�ǰ���豸��Ӧ����������ϸ��Ϣ
******************************/
typedef struct
{
    int nCondition;             ///< ��ѯ����
    char chFrontendName[128];   ///< ǰ���豸����(nCondition =1ʱ������)
}P_FrontendAlarmInfo;

///< ��ȡǰ���豸����������ϸ��Ϣ(13-out)
typedef struct
{
    int nFrontendID;              ///< ǰ���豸ID
    char chDeviceCode[64];        ///< ǰ���豸����
    char chDeviceName[128];       ///< ǰ���豸����
    int nChannelNo;               ///< ͨ����
    int nDeviceType;              ///< �豸���ͣ�10��12��
    char chAreaCode[64];          ///< �����������
    char chHostCode[64];          ///< �����������
    int nAlarmLevel;              ///< �������򼶱�
    int nNetModel;                ///< �������ͣ�1��2��3��4��
    int nAlarmTypeID;             ///< ��������ID
    char chAlarmTypeName[128];    ///< ������������
    char chAlarmTypeSound[128];   ///< �������Ͷ�Ӧ��������
}S_FrontendAlarmInfo;

///< ������������(14-int)
typedef struct
{
    int nCondition;            ///< ��ѯ����(0-���������־���룬1-������������)
    char chCode[64];           ///< ����
    char chName[128];          ///< �û���(nCondition =0ʱ������)
    int nNodeType;             ///< �ڵ����ͣ�9��10��12��
    char chFilterTime[64];     ///< ����ִ����ֹʱ��
}P_AlarmFilterSetInfo;

///< ������¼�(15-int)
typedef struct
{
    char  chUserName[64];            ///<�û���
    char  chEventDescribe[128];      ///<�¼�Դ
    char  chHappenTime[64];          ///<�¼�����ʱ��
    char  chSubmitTime[64];          ///<�¼��ύʱ��
    char  chContent[1024];           ///<�¼�����
    int   nProperty;                 ///<�¼����ԣ��Ƿ���˽���¼�
    char chLabelName[128];           ///<�¼���ǩ��
}P_AddEventInfo;

///< �ظ��¼�(16-int)
typedef struct
{
    char  chUserName[64];            ///<�û���
    int   nID;                       ///<�¼�ID
    char  chReplyContent[3000];      ///<�ظ�����
    char  chReplyTime[64];           ///<�¼��ظ�ʱ��
    int   nEventState;               ///<�¼�״̬  0 �ظ� 1 ���´� 2 �ر�
}P_ReplyEventInfo;

///< ��ȡ�����¼���ϸ��Ϣ(17-int)
typedef struct
{
    char chUserName[64];          ///<�û���
    int nPage;                    ///<ҳ��(��nҳ)
    int nShowEventNumInPage;      ///<ÿҳ��ʾ�������¼�
    int nClosed;                  ///<�Ƿ��ѹر�(0:�� 1:�ر� 2:ȫ��)
    int nState;                   ///<����(0:ȫ���¼� 1:�Լ����� 2:���������)
}P_EventInfo;

///< ��ȡ�����¼���ϸ��Ϣ(17-out)
typedef struct
{
    int nID;                      ///< �¼�ID
    char chLabelName[64];         ///< ��ǩ��
    char chSubmitMan[64];         ///< �¼�������
    char chEventDescribe[128];    ///< �¼�Դ
    char chHappenTime[64];        ///< �¼�����ʱ��
    char chSubmitTime[64];        ///< �¼��ύʱ��
    char chContent[1024];         ///< �¼�����
    int nState;                   ///< �¼�״̬(0:�� 1:�ر� 2:ȫ��)
    char chReplyMan[64];          ///< �ظ���
    char chReplyTime[64];         ///< �ظ�ʱ��
    char chReplyContent[3000];    ///< �ظ�����
    char chUserName[64];          ///< �û���
    int nProperty;                ///< �û��Ƿ�Ϊ������
    int nAssociate;               ///< �Ƿ��лظ�
    int nHaveRead;                ///< �Ƿ��Ѷ�
}S_EventInfo;

///< ��ȡ���¼�����Ŀ(18-int)
typedef struct
{
    char chUserName[64];          ///<�û���
}P_NewEventInfo;

///< ��ȡ�����¼���ϸ��Ϣ(18-out)
typedef struct
{
    int nTotal;                  ///<�û��ܿ������������¼���Ŀ
    int nOwnerNum;               ///<���û���������¼���Ŀ
    int nRelatedNum;             ///<���û���ص����¼���Ŀ
}S_NewEventInfo;

///< �޸�δ���¼�״̬(19-int)
typedef struct
{
    char chUserName[64];          ///<�û���
    int nState;                   ///<����(0:ȫ���¼� 1:�Լ����� 2:���������)
}P_ModEventStateInfo;

///< ȫ���¼���Ϣģ����ѯ�Լ���ѯ��Ŀͳ��(20��21-int)
typedef struct
{
    char chUserName[64];          ///<�û���
    int nState;                   ///<״̬(0:ȫ���¼� 1:�Լ����� 2:�������)
    int nClosed;                  ///<�Ƿ��ѹر�(0:�� 1:�ر� 2:ȫ��)
    int nPage;                    ///<ҳ��
    int nShowEventNumInPage;      ///<ÿҳ��ʾ�������¼�
    char chCondition[512];        ///<ģ����ѯ����
    char chStartTime[32];         ///<��ʼʱ��
    char chEndTime[32];           ///<����ʱ��
    char chLabelName[128];        ///<�¼���ǩ��
}P_QueryEventInfo;

///< ȫ���¼���Ϣģ����ѯ(20-out)
typedef struct
{
    int nID;                      ///< �¼�ID
    char chLabelName[64];         ///< ��ǩ��
    char chSubmitMan[64];         ///< �¼�������
    char chEventDescribe[128];    ///< �¼�Դ
    char chHappenTime[64];        ///< �¼�����ʱ��
    char chSubmitTime[64];        ///< �¼��ύʱ��
    char chContent[1024];         ///< �¼�����
    int nState;                   ///< �¼�״̬(0:�� 1:�ر� 2:ȫ��)
    char chReplyMan[64];          ///< �ظ���
    char chReplyTime[64];         ///< �ظ�ʱ��
    char chReplyContent[3000];    ///< �ظ�����
    char chUserName[64];          ///< �û���
    int nProperty;                ///< �û��Ƿ�Ϊ������
    int nAssociate;               ///< �Ƿ��лظ�
    int nHaveRead;                ///< �Ƿ��Ѷ�
    int nSort;                    ///< ��¼���
}S_QueryEventAllInfo;

///< ��ȡȫ���¼���Ϣģ����ѯ����Ŀ(21-out)
typedef struct
{
    int nTotal;                  ///<�¼���Ŀ
}S_QueryEventNumInfo;

///< ��ȡ���б�ǩ��Ϣ(22-out)
typedef struct
{
    int nID;                        ///< ��ǩID
    char chLabelName[128];          ///< ��ǩ��
    char chContent[1024];           ///< ��ǩ����
}S_LabelInfo;

///< �ͻ����¼���ǩͳ��(23-int)
typedef struct
{
    int nType;                ///< ͳ������ 1-ͳ���¼���ǩ��2-ͳ���¼������û���3-����ͳ�ƣ�4-����ͳ�ƣ�
    char chUserName[64];      ///< �û���
    char chLabelName[128];    ///< ��ǩ��
    char chBeginTime[32];     ///< ��ʼʱ��
    char chEndTime[32];       ///< ����ʱ��
}P_LabelStaticsInfo;

///< �ͻ����¼���ǩͳ��(23-out)
typedef struct
{
    char chContent[128];      ///< ���ݣ���ǩ�����û������ջ���ʱ�䣩
    int nCount;               ///< ��Ŀ
}S_LabelStaticsInfo;

///< �ͻ����û������޸�(24-int)
typedef struct
{
    char chUser[64];       ///< �û���
    char chOldPsw[64];     ///< ԭ����
    char chNewPsw[64];     ///< ������
}P_ModUserPswInfo;

///< ������־��Ϣ(25��26-int)
typedef struct
{
    int nCondition;            ///< ������1:������ͳ�ƣ�2:����������ͳ�ƣ�3:����ͳ�ƣ�4: ���·�ͳ�ƣ�
    char chAlarmTypeName[64];  ///< ������������
    char chHostSource[64];     ///< ����
    char chCameraSource[64];   ///< ����ͷ
    char chAlarmArea[64];      ///< �����ص�
    int nPage;                 ///< ҳ��
    int nCount_Page;           ///< ÿҳ��ʾ��¼����
    char chAlarmBeginTime[32]; ///< ������־��ʼʱ��
    char chAlarmEndTime[32];   ///< ������־����ʱ��
}P_AlarmLogInfo;

///< ������־��Ϣ��ѯ(25-out)
typedef struct
{
    char chAlarmTypeName[64];  ///< ������������
    char chAlarmSource[64];    ///< ����Դ
    char chAlarmArea[64];      ///< �����ص�
    int nSumCount;             ///< �ܼ�¼����
    int nSumPage;              ///< ��ҳ��
    char chBeginTime[32];      ///< ������־��ʼʱ�䣨2012-01-01 00:00:00��
    char chBeginDay[32];       ///< ������־��ʼ���ڣ�2012-01-01��
    char chBeginMonth[32];     ///< ������־��ʼ�·ݣ�2012-01��
    int nAlarmTypeID;                           ///< ������ϢID
    int nProcessState;                          ///< ����״̬��1-����0-δ����
    char chProcessUser_VarC[64];                ///< ������
    char chProcessDate_Date[32];                ///< ��������
    int nProcessMethod_Int;                     ///< ����ʽ��1-����2-ת����3-����
    char chProcessSuggestion_VarC[256];         ///< �������
    char chProcessMemo_VarC[512];               ///< ��ע
}S_AlarmLogQueryInfo;

///< ������־��Ϣͳ��(26-out)
typedef struct
{
    char chContent[128];      ///< ���ݣ��������������ص������ջ���ʱ�䣩
    int nCount;               ///< ��Ŀ
}S_AlarmLogStaticsInfo;

///< ϵͳ��־��Ϣ(27��28-int)
typedef struct
{
    int  nCondition;          ///< ������(1:���û�ͳ��;2:����������ͳ��;3:����ͳ��;4: ���·�ͳ��)
    char chUserName[64];      ///< �û���
    char chSysLogType[128];   ///< ��������
    int  nPage;               ///< ҳ��
    int nCount_Page;          ///< ÿҳ��ʾ��¼����
    char chBeginTime[32];     ///< ϵͳ��־��ʼʱ��
    char chEndTime[32];       ///< ϵͳ��־����ʱ��
}P_SysLogInfo;

///< ϵͳ��־��Ϣ��ѯ(27-out)
typedef struct
{
    char chUserName[64];      ///< �û���
    char chSysLogType[128];   ///< ��������
    char chActDetail[512];    ///< ����������Ϣ
    char chActTime[32];       ///< ϵͳ��־����ʱ�� ��2012-01-01 00:00:00��
    char chActDate[32];       ///< ϵͳ��־�������� ��2012-01-01��
    char chActMonth[32];      ///< ϵͳ��־�����·ݣ�2012-01��
    int nSumCount;            ///< �ܼ�¼����
    int nSumPage;             ///< ��ҳ��
}S_SysLogQueryInfo;

///< ϵͳ��־��Ϣͳ��(28-out)
typedef struct
{
    char chContent[128];      ///< ���ݣ��û�������־���������ջ���ʱ�䣩
    int nCount;               ///< ��Ŀ
}S_SysLogStaticsInfo;

///< Ѳ����ؽڵ���Ϣ(29-int)
typedef struct
{
    int nID;                  ///< ��� 1-Ԥ�õ���� ��2-Ѳ����� ��3-�켣���
    int nType;                ///< ���� 1-��� ��2-�޸� ��3-ɾ��
    int nNo;                  ///< ���
    char chName[64];          ///< ����
    char chFrontendName[64];  ///< ǰ���豸��
}P_CruiseInfo;

///< Ѳ������(30-int)
typedef struct
{
    char chFrontendName[64];   ///< ǰ���豸��
    char chCruiseName[64];     ///< Ѳ������
    int nNo;                   ///< Ѳ�����
    char chPointName[2000];    ///< Ԥ�õ����ִ�
    char chPointNo[500];       ///< Ԥ�õ��Ŵ�
    char chPointTime[500];     ///< Ԥ�õ�ͣ��ʱ�䴮
    char chPointSpeed[500];    ///< ����Ԥ�õ��ٶȴ�
}P_CruiseSetInfo;

///< ��ȡԤ�õ���Ϣ(31-out)
typedef struct
{
    char chFrontendCode[64];   ///< ǰ���豸���
    char chPointName[64];      ///< Ԥ�õ�����
    int nNo;                   ///< Ԥ�õ����
}S_ShowPrePointInfo;

///< ��ȡѲ����Ϣ(32-out)
typedef struct
{
    char chFrontendCode[64];   ///< ǰ���豸���
    char chCruiseName[64];     ///< Ѳ������
    int nNo;                   ///< Ѳ�����
    int nConsequeceNo;         ///< Ѳ��Ԥ�õ�˳��
    int nPointTime;            ///< Ԥ�õ�ͣ��ʱ��
    int nPointSpeed;           ///< ����Ԥ�õ��ٶ�
    char chPointName[64];      ///< Ԥ�õ�����
    int nPointNo;              ///< Ԥ�õ���
}S_ShowCruiseInfo;

///< ��ȡ�켣��Ϣ(33-out)
typedef struct
{
    char chFrontendCode[64];   ///< ǰ���豸���
    char chLocusName[64];      ///< �켣����
    int nNo;                   ///< �켣���
}S_ShowLocusInfo;

///< ��ȡƽ̨��������Ϣ(34-out)
typedef struct
{
    int nID;                   ///< ��������
    char chContent[256];       ///< ������������Ϣ
}S_ShowErrorCodeInfo;

///< ��ȡ������־������Ϣ(35-out)
typedef struct
{
    char chLogType[64];       ///< ������־������Ϣ
}S_ShowSysLogTypeInfo;

///< 256ͨ�����Ļ�ȡ�豸Ȩ����Ϣ(36-out) : ����char chUserName[64]
typedef struct
{
    long lDEVID;                   ///<�豸ID��
    bool AlarmOutCtrl;             ///<���������Ȩ��
    bool DevAct;                   ///<���ػ�����Ȩ��
    bool AlarmInCtrl;              ///<���������Ȩ��
    bool DevUpgrade;               ///<���豸����Ȩ��
    bool DevTime;                  ///<���豸УʱȨ��
    bool DevLogLookUp;             ///<���豸��־�鿴Ȩ��
    bool DevConfig;                ///<���豸����Ȩ��
    bool TalkDevc;                 ///<�Խ�Ȩ��
    bool RecvAlarmDev;             ///<���ձ���Ȩ��
    unsigned int RealTimeView[8];  ///<ʵʱԤ��Ȩ��: ��Ӧ����256ͨ����8��������
    unsigned int PlayBack[8];      ///<�ط�Ȩ��: ��Ӧ����256ͨ����8��������
    unsigned int Download[8];      ///<����Ȩ��: ��Ӧ����256ͨ����8��������
}S_ShowCmsPrivilegeInfo;

///< 256ͨ���ͻ��˻�ȡ�豸Ȩ����Ϣ(37-out) : ����char chUserName[64]
typedef struct
{
    char chUserName[64];          ///< �û���
    char chRole[128];             ///< �û���ɫ
    char chPrivilege[128];        ///< Ȩ������
    char chPrivilegeDetail[128];  ///< ��ϸȨ����Ϣ
    int nHostID;                  ///< ��Ӧ������ID
    unsigned int nChannels[8];    ///< ��Ӧ����256ͨ����8��������
}S_ShowClientPrivilegeInfo;

///< ��ӡ��޸ġ�ɾ���û���Ϣ(38��39��40-int)
typedef struct
{
    int  UserId;                 ///< �û�ID(�޸ġ�ɾ��ʱ����)
    char cUserName[64];          ///< �û���
    char cPsw[64];               ///< ����
    int  cUserLevel;             ///< �û�����
    char cFindPswQuestion[64];   ///< �û��绰
    char cFindPswAnswer[64];     ///< �û�Email
    bool IsLock;                 ///< �Ƿ��������
    char cRoleName[64];          ///< ������ɫ
    char iEmployeeId[64];        ///< Ա��ID
    char CreateTime_Date[64];    ///< ��Ч��ʼʱ��
    char Validity_Date[64];      ///< ��Ч��ֹʱ��
    char Memo[1024];             ///< �û����
    char Memo_ID[30000];         ///< ����ѡ������
    char chAreaName[30000];      ///< ����������Ϣ(ѡ������+������)
    bool bUseful;                ///< �û�����/����״̬
    char chLevels[64];           ///< �����ȼ�ֵ��$
}P_ShowAboutUserInfo;

///< ��ʾ��ɫ��Ϣ(41-out)
typedef struct
{
    int nID;                    ///< ��ɫID
    char chRoleName[64];        ///< ��ɫ��
    char Memo[1024];            ///< ��ɫ��ע
    char CreateTime[64];        ///< ��ɫ����ʱ��
}S_ShowRoleInfo;

///< ��ɫ��ز�����Ϣ(42-int)
typedef struct
{
    int nCondition;             ///< ������1-add,2-mod,3-del
    int nID;                    ///< ��ɫID(mod��delʱ����)
    char chRoleName[64];        ///< ��ɫ��
    char Memo[1024];            ///< ��ɫ��ע
}P_ShowAboutRoleInfo;

///< ʡ�����������Ϣ(43-int)
/******************************
P_ShowAreaCodeInfo.nCondition:

0����������������ϸ��Ϣ
1������ʡ�ݻ�ȡ������ϸ��Ϣ
2�����ݳ��л�ȡ������ϸ��Ϣ
3�����ݱ����ȡ������ϸ��Ϣ
4: ��������ʡ������
******************************/
typedef struct
{
    int nCondition;             ///< ����
    char chName[64];            ///< ���ƣ�ʡ�ݻ���У�
    char chCode[64];            ///< ����
}P_ShowAreaCodeInfo;

///< ʡ�����������Ϣ(43-out)
typedef struct
{
    char chProvice[64];        ///< ʡ��
    char chCity[64];           ///< ����
    char chCode[64];           ///< ��Ӧ����
}S_ShowAreaCodeInfo;

///< ��ȡ�ڵ�������Ϣ(44-out)
typedef struct
{
    int nID;                   ///< �ڵ����ͱ��
    char chName[64];           ///< �ڵ�������
    char chImage[64];          ///< �ڵ�ͼ������
    int nLevel;                ///< �ڵ�ȼ�
}S_ShowNodeTypeInfo;

///< �޸Ľڵ�������Ϣ(45-int)
typedef struct
{
    int nID;                   ///< �ڵ����ͱ��
    char chName[64];           ///< �ڵ�������(�޸ĺ�)
}P_ShowModNodeTypeInfo;

///< ��ǩ�����Ϣ����(46-int)
typedef struct
{
    int nCondition;          ///< ������1-add,2-mod,3-del
    int nID;                 ///< ��ǩID
    char chName[128];        ///< ��ǩ��
    int nLocked;             ///< �Ƿ�������Ĭ��Ϊ0������Ϊ1
    char chNotes[512];       ///< ��ǩ��ע��Ĭ��Ϊ""
    int nProperty;           ///< �����ֶΣ�Ĭ��Ϊ0
}P_ShowLabelInfo;

///< ��ȡ��ǩ�����Ϣ(47-out)
typedef struct
{
    int nID;                 ///< ��ǩID
    char chName[128];        ///< ��ǩ��
    int nLocked;             ///< �Ƿ�������Ĭ��Ϊ0������Ϊ1��˽�ܣ�
    char chNotes[512];       ///< ��ǩ��ע
    int nProperty;           ///< �����ֶ�
}S_ShowLabelInfo;

///< ����ͷ���������Ϣ����(48-int)
typedef struct
{
    int nCondition;          ///< ������1-add,2-mod,3-del
    int nID;                 ///< ����ID
    char chName[128];        ///< ������
    char chNotes[512];       ///< ����ע��Ĭ��Ϊ""
    int nProperty;           ///< �����ֶΣ�Ĭ��Ϊ0
}P_CameraAreaInfo;

///< ��ȡ����ͷ���������Ϣ(49-out)
typedef struct
{
    int nID;                 ///< ����ID
    char chName[128];        ///< ������
    char chNotes[512];       ///< ��ע
}S_ShowCameraAreaInfo;

///< ��ȡ��־��Ϣ(50-int)
typedef struct
{
    char strOperType[40];   ///< �������
    char strOpp[40];        ///< ����ʵ��
    char strStartTime[50];  ///< ��ѯ��ʼʱ�䣨�������ڣ�
    char strEndTime[50];    ///< ��ѯ����ʱ�䣨�������ڣ�
    int nStart;             ///< ��ʼ��¼��
    int nEnd;               ///< ������¼��
}P_OpLogCheckInfo;

///< ��ȡ��־��Ϣ(50-out)
typedef struct
{
    char strOperType[64];      ///< �������
    char strOpp[64];           ///< ����ʵ��
    char strOPPName[64];       ///< ����������
    char strDateTime[32];      ///< ����ʱ��
}S_ShowOpLogCheckInfo;

///< ����Уʱ�ƻ���Ϣ(51-int)
typedef struct
{
    char  chTimingBeginDate[32];    ///<��ʼ����
    char  chTimingPeriod[32];       ///<����
    char  chCheckTIme[32];          ///<Уʱʱ��
}P_SetTimePlanInfo;

///< ��ȡУʱ�ƻ���Ϣ(52-out)
typedef struct
{
    char  chTimingBeginDate[32];    ///<��ʼ����
    char  chTimingPeriod[32];       ///<����
    char  chCheckTIme[32];          ///<Уʱʱ��
}S_ShowTimePlanInfo;

///< �������ã�ͼƬ��������(53-int)
typedef struct
{
    int nType;                     ///< �������� 0-ͼƬ��1-����
    char chAreaName[64];           ///< ������
    char chDeviceName[30000];      ///< �豸��
    char chFrontendName[30000];    ///< ����ͷ��
    int nSize;                     ///< ͼƬ��С 1-С��2-�У�3-��
    int nNetMode;                  ///< ���� 1-cf,2-D1,3-720P,4-1080P
}P_SetMostInfo;

///< ��������������-��������Ϣ�ṹ��(54��55��56-int)
typedef struct
{
    int nCondition;         ///< ������1-add,2-mod,3-del(������Ϣ)
    int nID;                ///< �������(����Ψһ��ʶ���޸ĵ�ʱ����Ҫ����)
    int nPartNo;            ///< ������
    char chPartName[100];   ///< ��������
    char chDvrName[100];    ///< ����������������
    char chPartArea[8000];  ///< �������������з������ִ�
    int nAreaID;            ///< �������(����Ψһ��ʶ)
    int nAreaNo;            ///< ������
    char chAreaName[100];   ///< ��������
}P_PartitionAreaInfo;

///< ��ʾ���屨�������ķ���-������Ϣ(56-out)
typedef struct
{
    int ID;             ///< ������
    char chName[100];   ///< ������
    int nPartID;        ///< ����Ψһ��ʶID
    char chDvrName[100];///< ������������
    char chArea[100];   ///< �������֣�̽ͷ����
    int nDet;           ///< ͨ����
    int nArea;          ///< ������
}S_ShowPartAreaInfo;

///< ��ɫȨ����Ϣ����(57-int)
typedef struct
{
    char chLenth[208300];  ///< Ȩ���ַ���(��ɫ|Ȩ��|�豸|ͨ��|���)
}P_SetRolePriviligeInfo;

///< ��ɫȨ����Ϣ��ѯ(58-int)
typedef struct
{
    int nID;                 ///< 0-����������1-��ѡ����������
    char strRole[64];        ///< ��ɫ��
    char chAreaName[30000];  ///< ���򴮣�nID == 1��
}P_ShowRolePriviligeInfo;

///< ��ɫȨ����Ϣ��ѯ(58-out)
typedef struct
{
    char chDvrName[64];     ///< �豸��
    bool bSpeak;            ///< �Խ�Ȩ��
    bool bAlarm;            ///< �Ӿ�Ȩ��
    bool bControl;          ///< ����Ȩ��
    bool bConfig;           ///< ����Ȩ��
    char chRealplay[257];   ///< Ԥ��Ȩ��
    char chPlayback[257];   ///< �ط�Ȩ��
    char chLoad[257];       ///< ����Ȩ��
}S_ShowRolePriviligeInfo;

///< ����ǽ��Ϣ����(59-int)
typedef struct
{
    int nTVID;                      ///<����ǽID
    int nDecodeType;                ///<��������  1 ��� 2 ˫�� �� 3˫�� �� ��4Ӳ��
    int nPriorityType;              ///<������ 1 ������ 2
    char chGroupName[128];          ///<�������� �������飬�����飬������
    char chDateNames[128];          ///<ʱ���� ���ڻ�����
    char chUserName[64];            ///<�û���
    int  nTimeSequence;             ///<ʱ��κ�
    char chBeginTime[32];           ///<��ʼʱ��
    char chEndTime[32];             ///<����ʱ��
    int nSwitchTime;                ///<�л����ʱ��
    int nScreenDevide;              ///<����ָ���
    char chMonitorSet[128];         ///<������ (��������\�������ָ���\�������\�л����)
    char chChannelNames[100000];    ///<ͨ����
}P_ShowSetScreeenInfo;

///< Ԥ����Ϣ����(60-int)
typedef struct
{
    int nID;                          ///<Ԥ����ı��
    char chGroupName[128];            ///<Ԥ������
    char chUserName[64];              ///<�û���
    int nSwitchTime;                  ///<�л����ʱ��
    int nScreenDevide;                ///<����ָ���
    char chMonitorSet[128];           ///<������ (��������\�������ָ���\�������\�л����)
    char chChannelNames[100000];      ///<ͨ����
}P_ShowSetEmergencyInfo;

///< ��ȡ�û�����������Ϣ(61-out)
typedef struct
{
    char chUserName[64];    ///<�û���
    char chAreaName[64];    ///<��������
    char chAreaCode[64];    ///<������
}S_ShowUserAreaInfo;

///< �޸��û�������ɫ(62-int)
typedef struct
{
    char strUser[8000];     ///< �û���
    char strRole[64];       ///< ��ɫ��
}P_ShowModUserRoleInfo;

///< ͨ������Ϣ��ز���(63-int)
typedef struct
{
    int nCondition;         ///< ������1-add,2-mod,3-del
    char chGroupName[100];  ///< ͨ������
    char chOldName[100];    ///< ԭͨ������(modʱ����)
}P_ChannelGroupInfo;

///< ͨ������ʾ��ز���(64-int)
typedef struct
{
    int nCondition;            ///< ������1-��ʾ����ͨ���飬2-��ʾͨ�����µ�ͨ��,3-ȫ��ͨ������Ϣ
    char chGroupName[100];     ///< ͨ������(2-����)
}P_ShowChannelGroupInfo;

///< ͨ������ʾ��ز���(64-out)
typedef struct
{
    char chGroupName[100];     ///< ͨ������
    char chFrontendName[100];  ///< ͨ������
    char chDvrCode[64];        ///< �������
    int nChannelNo;            ///< ͨ����
    int nSequence;             ///< ���
}S_ShowChannelGroupInfo;

///< ͨ����������ز���(65-int)
typedef struct
{
    int nCondition;              ///< ������1-���ã�2-�Ƴ�
    char chFrontendNames[30000]; ///< ͨ��������
    char chGroupName[100];       ///< ����
    char chOrder[30000];         ///< ����˳��
}P_SetChannelGroupInfo;

///< ��ʾ���ݿ�ռ������Ϣ(66-out)
typedef struct
{
    char chType[64];            ///< ��־����
    char chCurrentSize[32];     ///< ��ǰ��С(MB)
    char chDaySize[32];         ///< ÿ��ռ�ÿռ�(MB)
    char chEmpty[32];           ///< �洢���̿��ÿռ�(MB)
    char chEmptyDays[32];       ///< ʵ�ʻ��ɴ洢����
    char chCleanDay[32];        ///< ���һ����������
    char chSaveMonth[32];       ///< ���㱣����Ϣ��
}S_ShowSqlManageInfo;

///< ���ñ�����־����ʱ��(67-int)
typedef struct
{
    int nMonth;                 ///< ʱ�䳤��
}P_SetCleanTimeInfo;

///< ��ȡ���ݿⱸ��·����Ϣ(68-out)
typedef struct
{
    char chPath[256];          ///< ·��λ��
}S_GetSqlSaveInfo;

///< �������ݿⱸ��·��(69-int)
typedef struct
{
    char strFilePath[256];     ///< ·��λ��
}P_SetSqlSaveInfo;

///< ��ȡ�洢������Ϣ(70-out)
typedef struct
{
    char chDisk[16];           ///< �̷�
    char chFreeSize[32];       ///< ʣ��ռ�(MB)
}S_ShowDiskInfo;

///< �ж����ÿͻ��˵�¼�˺���Ϣ(71-int)
typedef struct
{
    char chUser[64];         ///< �û���
    char chPassword[64];     ///< ����
}P_GetConfigClientInfo;

///< ��ȡ���ÿͻ��˵�¼�����豸���˺���Ϣ(72-int)
typedef struct
{
    char chDevCode[128];    ///< �豸���
}P_GetConfigClientLoginInfo;

///< ��ȡ���ÿͻ��˵�¼�����豸���˺���Ϣ(72-out)
typedef struct
{
    int nManufatureType;     ///< Ʒ������
    int nPort;               ///< �˿�
    char chUser[64];         ///< �û���
    char chPassword[64];     ///< ����
    char chIP[64];           ///< IP��ַ
    char chModeType[128];    ///< Ʒ��������
}S_GetConfigClientLoginInfo;

///< ���÷�������¼��Ϣ(73-int)
typedef struct
{
    char chServerName[64];   ///< ��������
    char chDevName[30000];   ///< �豸��
    char chUserName[64];     ///< �û���
    char chPassWord[64];     ///< ����
}P_SetServerLoginInfo;

///< ��ʾ��������¼��Ϣ(74-int)
typedef struct
{
    char chServerName[128];    ///< ��������
    int nPageNum;              ///< ҳ��
}P_GetServerLoginInfo;

///< ��ʾ��������¼��Ϣ(74-out)
typedef struct
{
    char chServerName[64];    ///< ��������
    char chDevName[64];       ///< �豸��
    char chUser[64];          ///< �û�
    char chPassword[64];      ///< ����
    char chIP[64];            ///< IP��ַ
    char chManufature[128];   ///< Ʒ��
    int nTotalPageNum;        ///< ҳ��
}S_GetServerLoginInfo;

///< ��������¼�豸ɾ�������(75��76-int)
typedef struct
{
    char chServerOrClient[128];     ///< ��������
    int ServerType;                 ///< ���������ͣ�1-���ģ�2-������3-ý��
    char chDeviceName[128];         ///< �豸��(ɾ��ʱ����)
}P_DelServerLoginInfo;

///< ���ÿͻ��˵�¼��Ϣ(77-int)
typedef struct
{
    char chUserName[64];              ///<client
    char chDevName[30000];            ///<�豸��
    char chConnDVRUserName[64];       ///<�û���
    char chConnDVRPassWord[64];       ///<����
}P_SetClientLoginInfo;

///< ��ʾ�ͻ��˵�¼��Ϣ(78-int)
typedef struct
{
    char chUserName[128];    ///< �û���
    int nPageNum;            ///< ҳ��
}P_GetClientLoginInfo;

///< ��ʾ�ͻ��˵�¼��Ϣ(78-out)
typedef struct
{
    char chUserName[128];     ///< �û���
    int nDevID;               ///< �豸ID
    char chDevName[64];       ///< �豸��
    char chUser[64];          ///< �û�
    char chPassword[64];      ///< ����
    char chIP[64];            ///< IP��ַ
    char chManufature[128];   ///< Ʒ��
    int nTotalPageNum;        ///< ҳ��
}S_GetClientLoginInfo;

///< �ͻ��˵�¼�豸ɾ�������(79��80-int)
typedef struct
{
    char chServerOrClient[128];///< �ͻ�����
    char chDeviceName[128];    ///< �豸��
}P_DelClientLoginInfo;

///< �����û���¼����(81-int)
typedef struct
{
    char chUser[40];           ///< �����û���
    char chCopyUser[3000];     ///< ��Ҫ���Ƶ�n���û�
}P_CopyClientLoginInfo;

///< �洢��������(82-int)
typedef struct
{
    int  nStoreType;               ///<�洢��ʽ
    char chDataType[64];           ///<��������
    char chStoreDays[100];         ///<��������
    char chPackageIntervals[100];  ///<���
    char chRedundancyTimes[100];   ///<����ʱ��
    char chMediaTypes[100];        ///<���ݸ�ʽ
    char chBeginTimes[100];        ///<��ʼʱ��
    char chEndTime[100];           ///<����ʱ��
    int  nCapacityThreshold;       ///<�洢ʣ��������ֵ
    int  nDelDays;                 ///<ɾ������
    bool bReserveMarkedData;       ///<������ǩ����
}P_SetVideoInfo;

///< ���ô洢�ƻ�(83-int)
typedef struct
{
    char chPlanName[64];           ///<�ƻ���
    char chBeginTime[64];          ///<��ʼʱ��
    char chEndTime[64];            ///<����ʱ��
    int  nStorageType ;            ///<¼������  1Ϊ��Ƶ 2ΪͼƬ 3Ϊ��Ƶ
    int  nConfigSequence;          ///<ʱ���
}P_SetStorageInfo;

///< ����ͨ���洢�ƻ������Ϣ(84-int)
typedef struct
{
    char chPlanName[64];           ///<�ƻ���
    char chFrontendNames[500000];  ///<��Ӧ¼���ͨ��������
    char chDateNames[128];         ///<��Ӧ¼��ĵ�����������
}P_SetChannelPlanInfo;

///< ��ʾ�洢����������Ϣ(85-out)
typedef struct
{
    int  nStoreType;               ///<�洢��ʽ
    int  nDataType;                ///<��������
    int  nStoreDays;               ///<��������
    int  nPackageIntervals;        ///<���ʱ��
    int  nRedundancyTimes;         ///<����ʱ��
    char chMediaTypes[32];         ///<���ݸ�ʽ
    char chBeginTimes[32];         ///<��ʼʱ��
    char chEndTime[32];            ///<����ʱ��
}S_GetVideoInfo;

///< ��ʾ��������(86-out)
typedef struct
{
    int nLeave;          ///< ʣ������
    int nDel;            ///< ɾ������
    bool bLabel;         ///< �Ƿ�����ǩ
}S_GetCleanDiskInfo;

///< ��ʾ�洢�ƻ������Ϣ(87-int)
/*
P_GetStorageInfo.nCondition:
0����ȡ�����豸�ļƻ�������Ϣ
1����ȡ�ƻ���ϸ��Ϣ
2���������ں������ȡ��Ӧ�ļƻ�������Ϣ
3����������\����\����ͷ��ȡ��Ӧ�ļƻ�������Ϣ
4����������ͷ���ͼƻ���ȡ��Ӧ������
5: ��������ͷ���鿴�ƻ���Ϣ[��������]
*/
typedef struct
{
    int  nCondition;               ///<������(0,1,2,3,4)
    char chPlanName[64];           ///<�ƻ���(4)
    char chFrontendName[128];      ///<ͨ����(4)
    char chAreaName[30000];        ///<ǰ���豸��Ӧ����(2,3)
    int nWeek;                     ///<����ֵ��0 ~ 6(2)
}P_GetStorageInfo;

///< ��ʾ�洢�ƻ������Ϣ(87-out)
typedef struct
{
    int nID;                     ///<�ƻ�ID(1)
    int nSequence;               ///<ʱ���(1)
    char chBegin[64];            ///<��ʼʱ��(1)
    char chEnd[64];              ///<����ʱ��(1)
    char chStorage[64];          ///<�洢��ʽ(1)
    char chPlanName[64];         ///<�ƻ���(0,1,2,3)
    char chDevName[64];          ///<�豸��(0,2,3)
    char chIP[64];               ///<IP��ַ(0,2,3)
    char chFrontendName[128];    ///<ͨ����(0,2,3)
    int nChannelNo;              ///<ͨ����(0,2,3)
    int nWeek;                   ///<����ֵ��0 ~ 6(4)
}S_GetStorageInfo;

///< ɾ���洢�ƻ�(88-int)
typedef struct
{
    char chFrontendNames[500000];  ///<��Ӧ¼���ͨ��������
}P_DelStorageInfo;

///< ���Ĺ����������ز���(89-int)(add��mod��del)
typedef struct
{
    int  nCondition;            ///<����:1-add,2-mod,3-del
    char chCode[64];            ///<����
    char chName[64];            ///<����
    char chIP[64];              ///<��IP��ַ
    char chBackUpIP[64];        ///<��IP��ַ
    int  nCenterType;           ///<CMS���ͣ����������¼���ʶ��
    char chServerNo[64];        ///<���ı��
    char chUserName[64];        ///<�û�����
    char chPassWord[64];        ///<����
    char chMemo[512];           ///<��ע(�޸�ʱΪԭ������)
}P_CMSNodeInfo;

///< ý���������ز���(90-int)(add��mod��del)
typedef struct
{
    int  nCondition;            ///<����:1-add,2-mod,3-del
    char chCode[64];            ///<����(�޸�ʱΪԭý����)
    char chName[64];            ///<����
    char chIP[64];              ///<IP��ַ
    int  nMSType;               ///<MS���ͣ���ת�������桢�㲥��
    char chPassWord[64];        ///<����
    char chMemo[512];           ///<��ע
}P_MSNodeInfo;

///< ��ʾý���������ϸ��Ϣ(91-out)
typedef struct
{
    int  nID;                   ///<ID���
    char chCode[64];            ///<����
    char chName[64];            ///<����
    char chIP[64];              ///<IP��ַ
    int  nMSType;               ///<MS����
    char chPassWord[64];        ///<����
    char chMemo[512];           ///<��ע
}S_GetMSNodeInfo;

///< ý��������������á�ɾ������ʾ(92��93��94-int)
typedef struct
{
    int  nCondition;            ///<����:1-���Ƿ�ʽ,2-׷�ӷ�ʽ(92)
    char chMSName[64];          ///<ý������(92��93��94)
    char chDevName[30000];      ///<������(92��93)
}P_MSConfigSetInfo;

///< ��ʾý�������������ϸ��Ϣ(94-out)
typedef struct
{
    char chDevName[64];         ///<��������
}S_GetMSConfigInfo;

///< ������������ز���(95-int)(add��mod��del)
typedef struct
{
    int  nCondition;            ///<����:1-add,2-mod,3-del
    char chCode[64];            ///<����(�޸�ʱΪԭ������)
    char chName[64];            ///<����
    char chIP[64];              ///<IP��ַ
    char chPassWord[64];        ///<����
    char chMemo[512];           ///<��ע
}P_ASNodeInfo;

///< ��ʾ������������ϸ��Ϣ(96-out)
typedef struct
{
    int  nID;                   ///<ID���
    char chCode[64];            ///<����
    char chName[64];            ///<����
    char chIP[64];              ///<IP��ַ
    char chPassWord[64];        ///<����
    char chMemo[512];           ///<��ע
}S_GetASNodeInfo;

///< �����������������á�ɾ������ʾ(97��98��99-int)
typedef struct
{
    int  nCondition;            ///<����:1-���Ƿ�ʽ,2-׷�ӷ�ʽ(97)
    char chASName[64];          ///<��������(97��98��99)
    char chDevName[30000];      ///<������(97��98)
}P_ASConfigSetInfo;

///< ��ʾ����������������ϸ��Ϣ(99-out)
typedef struct
{
    char chDevName[64];         ///<��������
}S_GetASConfigInfo;

///< ��ȡ��󱨾����(100-out)
typedef struct
{
    int nMaxID;               ///<���������
}S_GetAlarmMaxIDInfo;

///< ����������ز���(101-int)(add��mod��del)
typedef struct
{
    int  nCondition;                ///< ����:1-add,2-mod,3-del
    int nID;                        ///< ���
    int nAC;                        ///< AC���
    char strTypeName[64];           ///< ������
    char strTimeStart[64];          ///< ��ʼʱ��
    char strTimeEnd[64];            ///< ����ʱ��
    char strSound[256];             ///< ��������
    int  ConfigSequence;            ///< ����ʱ���ID
    int  nPriority;                 ///< �������ȼ�
    int  bFliter;                   ///< �Ƿ����
    int  nFliterTimeInterval;       ///< ����ʱ����
    int  bWord;                     ///< �Ƿ��������
    int  bVideoStore;               ///< �Ƿ������洢
    int  nVideoStoreTime;           ///< ��Ƶ�洢ʱ��
    int  bAlarmInfoStore;           ///< ������Ϣ�Ƿ�洢
}P_AlramTypeInfo;

///< ��ʾ����������ϸ��Ϣ(102��608-in)
/*
P_GetAlarmConfigInfo.nCondition:
0: ���б���������Ϣ
1������AC�����ʾ�ض�����������Ϣ
2: ���ݱ���ID��ʱ�����ʾ�ض�����������Ϣ
*/
typedef struct
{
    int nCondition;                 ///< �������
    int nID;                        ///< �������
    int ConfigSequence;             ///< ʱ���
    int nAC;                        ///< AC���
}P_GetAlarmConfigInfo;

///< ��ʾ����������ϸ��Ϣ(102-out)
typedef struct
{
    int nID;                        ///< �������
    int nAC;                        ///< AC���
    char strTypeName[64];           ///< ������
    int  ConfigSequence;            ///< ʱ���
    char strTime[64];               ///< ��ʼʱ��
    bool  bWord;                    ///< �Ƿ��������
    bool  bVideoStore;              ///< �Ƿ������洢
    int  nVideoStoreTime;           ///< ��Ƶ�洢ʱ��
    bool  bFliter;                  ///< �Ƿ����
    int  nFliterTimeInterval;       ///< ����ʱ����
    bool  bAlarmDeal;               ///< �����Ƿ���
}S_GetAlarmConfigInfo;

///< ����ڵ���Ϣ��ز���(103-int)(add��mod��del)
typedef struct
{
    int  nCondition;                ///<����:1-add,2-mod,3-del
    char chSerial[64];              ///<����
    char chName[64];                ///<����
    char chAddress[256];            ///<�����ַ
    char chManName[256];            ///<��ϵ��
    char chContactInfo[256];        ///<��ϵ��ʽ
    char chFatherNo[64];            ///<��һ������
    char chNodeName[64];            ///<�ڵ�������
    int  nXPos;                     ///<�ڵ�ͼ�ϵ�X���� TODO
    int  nYPos;                     ///<�ڵ�ͼ�ϵ�Y���� TODO
    int  nSize;                     ///<ͼ���С1-��ͼ�꣬-Сͼ��
    int  nWay;                      ///<ͼ�귽��1-���ϡ�-���¡�-����-���ҡ�-���ϡ�-���¡�-���ϡ�-����
    char chMapName[64];             ///<��ͼ�ļ�����
    char chMapPath[256];            ///<��ͼ�ļ�·��
    int  nMapSize;                  ///<��ͼ��С���ֽڣ�
    int nNetWidthLimit;             ///<�������
    int nUpLoadMaxChlNum;           ///<����ϴ�ͨ����
    bool bAutoSwitch;               ///<�����Ƿ��Զ��л�
    char chMemo[512];               ///<��ע��Ϣ(2)
    int nCenterNo;                  ///<���ı��
    int nAreaPosition;              ///<����
}P_AreaNodeOpInfo;

///< ����ڵ��ƶ�(104-int)
typedef struct
{
    char chNodeCode[64];          ///<���
    int nXPos;                    ///<X����
    int nYPos;                    ///<Y����
}P_AreaNodeMoveInfo;

///< �豸�ڵ���Ϣ��ز���(106-int)(add��mod��del)
typedef struct
{
    int  nCondition;                     ///<����:1-add,2-mod,3-del
    char chCode[64];                     ///<����
    char chName[64];                     ///<����
    char chIP[64];                       ///<IP��ַ
    char chManufacturer[128];            ///<����
    char chModel[128];                   ///<�ͺ�
    int  nPort;                          ///<�˿ں�
    char chFatherNodeName[64];           ///<���ڵ�����
    int  nNodeType;                      ///<�ڵ�������
    int  nXPos;                          ///<X����
    int  nYPos;                          ///<Y����
    int  nImageSize;                     ///<ͼ���С
    int  nImageWay;                      ///<ͼ�귽��
    int  bCanTalk;                       ///<�Ƿ�Խ�
    int  bCanHostTalk;                   ///<�Ƿ������Խ�
    int  bIsConnected;                   ///<�Ƿ����ӷ�����
    int  nTalkType;                      ///< 0Ϊͨ���Խ�   1Ϊ�����Խ�
    char chIPTalkID[64];                 ///< IP�Խ�����ID��0Ϊδʹ��
    int  nAlarmAreaLevel;                ///<���򱨾��ȼ�
    int  bAutoIP;                        ///<�Ƿ�̬IP
    char chAlarmTypeNames[2000];         ///<������������
    char chAlarmSoundNames[10000];       ///<��������
    char chAlarmSoundPath[256];          ///<����������Ӧ·��
    char chRelatedChannelNames[30000];   ///<����ͨ����
    char chRelatedDeviceNames[30000];    ///<����ͨ����Ӧ���豸
    int nKeyPart;                        ///<��λ
    char chSetDate[32];                  ///<�豸���ʱ��
}P_DevNodeOpInfo;

///< �豸�ڵ��ƶ�(107-int)
typedef struct
{
    char chNodeCode[64];          ///<���
    int nXPos;                    ///<X����
    int nYPos;                    ///<Y����
}P_DevNodeMoveInfo;

///< ǰ�˽ڵ���Ϣ��ز���(108-int)(add��mod��del)
typedef struct
{
    int  nCondition;                   ///<����:1-add,2-mod,3-del
    char chCode[64];                   ///<����
    char chName[64];                   ///<����
    int  nChannelNO;                   ///<ͨ����
    int  nNodeType;                    ///<�ڵ����ͣ�����ͷ��̽ͷ����������ȣ�
    int  nDEVStyle;                    ///<�豸���ͣ��ڹҡ�ǹ��������ȣ�
    char chAreaName[64];               ///<������������
    char chAreaCode[64];               ///<��Ӧ������
    char chUpperName[64];              ///<�����ϼ��豸����
    char chUpperCode[64];              ///<��Ӧ�������  
    int  nXPos;                        ///<X����
    int  nYPos;                        ///<Y����
    int  nImageSize;                   ///<ͼ���С
    int  nImageWay;                    ///<ͼ�귽��
    bool bHavePTZ;                     ///<�Ƿ�����̨
    int  nAlarmAreaLevel;              ///<���򱨾��ȼ�
    int  nSreamNetModel;               ///<��Ƶ����ģʽ����/��������
    bool bChannelRelated;              ///<�Ƿ�����ͨ��
    bool bIsTalkTrigger;               ///<�Ƿ�Խ�����
    int  nCapitalId;                   ///<�ʲ�ID
    char chMemo[512];                  ///<��ע��Ϣ
    char chAlarmTypeNames[2000];       ///<������������
    char chAlarmSoundNames[2000];      ///<��������
    char chAlarmSoundPath[256];        ///<����������Ӧ·��
    char chRelatedChannelNames[30000]; ///<����ͨ����
    char chRelatedDeviceNames[30000];  ///<����ͨ����Ӧ���豸
    int nKeyPart;                      ///<��λ
}P_FrontendNodeOpInfo;

///< ǰ�˽ڵ��ƶ�(109-int)
typedef struct
{
    char chNodeCode[64];          ///<���
    int nXPos;                    ///<X����
    int nYPos;                    ///<Y����
}P_FrontendNodeMoveInfo;

///< ��ʾƷ����Ϣ(110-int)
/*
P_GetManufatureInfo.nCondition:
0: ��ʾ����Ʒ������
1: ��ʾdvrƷ������
2: ��ʾ��������Ʒ������
3: ��ʾ�Ž�Ʒ������
4: ��ʾIP�Խ��豸Ʒ������
5: ��ʾ����IP�Խ��豸
6: ����Ʒ����ʾ�����豸
7: ��ʾָ����Ʒ������
*/
typedef struct
{
    int  nCondition;             ///<����
    char chManufature[128];      ///<Ʒ����(6)
}P_GetManufatureInfo;

///< ��ʾƷ����Ϣ(110-out)
typedef struct
{
    char chName[64];            ///<����
    int nID;                    ///<���ͺ�
}S_GetManufatureInfo;

///< ��ʾIP��Ϣ(111-int)
/*
P_GetIPInfo.nCondition:
0: ��ʾ����IP
1: ��������ʾIP�����ͱ��
*/
typedef struct
{
    int  nCondition;             ///<����
    char chName[128];            ///<������(1)
}P_GetIPInfo;

///< ��ʾIP��Ϣ(111-out)
typedef struct
{
    char chIP[64];              ///<����
    int nID;                    ///<���ͺ�
}S_GetIPInfo;

///< �������������ʾ�豸��Ϣ(112-int)
/*
P_GetInfoByDvrInfo.nCondition:
0: �����豸���ƺ�����(10,12,13)��ȡ�Ѵ��ڵ�ͨ����
1: �����豸������ʾ�������ͨ����
2: �����豸������ʾ���µ�ͨ����ͨ����
3: �����豸������ʾ��Խ�����ͨ����Ϣ
4: ��ȡ�����豸
5: ��ȡӵ��ǰ���豸�������豸
6: ������������ʾ���㼰���²�������豸��Ϣ
7: �����豸������ʾ�����
8: �����豸������ʾ������
9: �����豸����ʾ���õı�����������
10: ��ʾ�����豸�������ͨ����
*/
typedef struct
{
    int  nCondition;             ///<����
    char chName[128];            ///<�豸��
    char chCode[128];            ///<�豸�����������
    int nNodeType;               ///<ǰ������
}P_GetInfoByDvrInfo;

///< �������������ʾ�豸��Ϣ(112-out)
typedef struct
{
    char chName[128];            ///<�豸��
    char chCode[128];            ///<�豸����
    char chFrontendName[128];    ///<ǰ���豸��
    int nChannelNo;              ///<ͨ����
    char chTypeName[128];        ///<����������
    char chSoundName[128];       ///<��������
    char chDefaultName[128];     ///<Ĭ������
}S_GetInfoByDvrInfo;

///<����DEV��¼�û�����(113-int)
typedef struct
{
    char chName[128];            ///<�豸��
    char chUser[128];            ///<�û���
    char chPassword[128];        ///<����
}P_SetLoginDvrInfo;

///<ǰ���豸��ز���(114��115��116-int)
typedef struct
{
    char chName[128];            ///<ǰ���豸��
}P_FrontendInfo;

///< ����ǰ���豸����ʾ������������(114-out)
typedef struct
{
    char chFrontendName[128];    ///<ǰ���豸��
    char chTypeName[128];        ///<����������
    char chSoundName[128];       ///<��������
    char chDefaultName[128];     ///<Ĭ������
}S_GetSoundByFrontendInfo;

///< ����ǰ���豸����ʾ�����Խ�ͨ��(115-out)
typedef struct
{
    char chName[128];            ///<�豸��
    char chCode[128];            ///<�豸����
    char chFrontendName[128];    ///<ǰ���豸��
    int nChannelNo;              ///<ͨ����
    int nSequence;               ///<���
}S_GetTalkByFrontendInfo;

///< �������ƻ�ȡǰ���豸��Ϣ(����ͷ��̽ͷ�����)(116-out)
typedef struct
{
    int nID;                    ///< �豸ID
    char chFrontendCode[64];    ///< �豸����
    char chFrontendName[128];   ///< �豸����
    int nChannelNo;             ///< ͨ����
    int nDeviceType;            ///< �豸����(10��12��13)
    int nDeviceUseage;          ///< �豸������λ��ʶ(2,1,4)
    char chAreaCode[64];        ///< �����������
    char chHostCode[64];        ///< ������������
    int nProportionX;           ///< ǧ����X����
    int nProportionY;           ///< ǧ����Y����
    int nImageSize;             ///< ͼ���С
    int nImageDirection;        ///< ͼ�귽��
    int nHolder;                ///< ��̨���Ʊ�־
    int nSpeak;                 ///< �Խ�������־
    int nAlarmFilter;           ///< �������˱�־
    char chAlarmFilterDate[64]; ///< ��������ʱ��
    int nAlarmLevel;            ///< ��������ȼ�
    int nChannelRelated;        ///< ����ͨ����־
    int nNetModel;              ///< ����ģʽ
    char chAreaName[256];       ///< ������������
    char chDeviceName[256];     ///< ������������
    char chNetModel[64];        ///< ����������ϸ��Ϣ
    int nCameraAreaID;          ///< ����ͷ�������ID
    char chCenterNo[128];       ///< ���ı��
    char chFatherCenterNo[128]; ///< �����ı��
    char chMemoType[32];        ///< ǰ������
    int nKeyPart;               ///< ��λ
}S_OnlyFrontendNodeInfo;

///<Զ��ͨ����ƥ��(117-int)
typedef struct
{
    char chCode[128];            ///<�豸����
    char chFrontendName[128];    ///<ǰ���豸��
    int nChannelNo;              ///<ͨ����
    int nNodeType;               ///<����
}P_AutoModNameInfo;

///<���������(118-int)
/*
P_ConfigCheckInfo.nCondition
0: ��������
1: ����δ���
2: ý��δ���
3: ����δ���
4: ý��δ����
5: ����δ����
6: ���ĵ�¼����
7: ý���¼����
8: ������¼����
9: ̽ͷδ��������
10: δ����û�
11: δ���ÿͻ��˵�¼
12: δ������Ƶͨ����
13: δ���ô洢
*/
typedef struct
{
    int nCondition;   ///<����
}P_ConfigCheckInfo;

///<���������(118-out)
typedef struct
{
    int nNum;                  ///<��Ŀ
    char chMemo[128];          ///<��ע
    char chDevName[128];       ///<�豸��
    char chManufature[128];    ///<�豸����
    char chFrontendName[128];  ///<ǰ���豸����̽ͷ��
    char chUser[64];           ///<�û���
}S_ConfigCheckInfo;

///<�豸��Ϣ����(119-int)
/*
P_ExcelCheckInfo.nCondition
1: ������Ϣ��
2: ������Ϣ��
3: ��������������
4: ǰ���豸��Ϣ��
5: ǰ���豸��������;
6: ����ͷ������Ϣ��
7: ̽ͷ������Ϣ;
8: ǰ���豸����ƥ��
*/
typedef struct
{
    int nCondition;      ///<��������
    char chCon[512];     ///<ƥ������
    int nCount;          ///<��ȡ����(Ĭ��0�������ȡȫ��)
}P_ExcelCheckInfo;

///<�豸��Ϣ����(119-out)(1)
typedef struct
{
    int nID;                   ///<���
    char chArea[64];           ///<������
    char chFatherArea[64];     ///<�ϼ�������
    char chAddress[128];       ///<��ַ
    char chContactor[128];     ///<��ϵ��
    char chTel[64];            ///<��ϵ��ʽ
    int nWidth;                ///<�������
    int nLoad;                 ///<�ϴ�·��
    char chImage[64];          ///<����ͼ����
}S_ExcelCheckInfo_1;

///<�豸��Ϣ����(119-out)(2)
typedef struct
{
    int nID;                   ///<���
    char chHost[64];           ///<��������
    char chIP[64];             ///<IP��ַ
    char chArea[64];           ///<��������
    char chDevType[64];        ///<�豸����
    char chManufature[128];    ///<��������
    char chModel[128];         ///<�ͺ�
    int nPort;                 ///<�˿�
    char chSpeak[16];          ///<�ܷ�Խ�
    char chSpeakMemo[64];      ///<�Խ���ʽ
    char chLevel[16];          ///<�����ȼ�
    char chFrontend[128];      ///<����ͨ����
    int nSequence;             ///<�������
}S_ExcelCheckInfo_2;

///<�豸��Ϣ����(119-out)(3)
typedef struct
{
    int nID;                   ///<���
    char chHost[64];           ///<��������
    char chType[64];           ///<��������
    char chSound[64];          ///<��������
}S_ExcelCheckInfo_3;

///<�豸��Ϣ����(119-out)(4��8)
typedef struct
{
    int nID;                   ///<���
    char chName[128];          ///<ǰ���豸����
    int nChannelNo;            ///<ͨ����
    char chDevType[64];        ///<�豸����
    char chSubType[128];       ///<�豸������
    char chHost[64];           ///<����DVR
    char chArea[64];           ///<��������
    char chLevel[16];          ///<�����������ȼ�
    char chFrontend[128];      ///<����ͨ����
    int nSequence;             ///<�������
}S_ExcelCheckInfo_4;

///<�豸��Ϣ����(119-out)(5)
typedef struct
{
    int nID;                   ///<���
    char chName[128];          ///<ǰ���豸����
    char chType[64];           ///<��������
    char chSound[64];          ///<��������
}S_ExcelCheckInfo_5;

///<�豸��Ϣ����(119-out)(6��7)
typedef struct
{
    char chFrontend[128];       ///<ǰ���豸����
    char chDevName[128];        ///<�豸��
    char chRelateFrontend[128]; ///<����ͨ����
    char chRelateDevName[128];  ///<����ͨ����������
}S_ExcelCheckInfo_6;

///<�ֻ��û���Ϣ(120��121-int,120-out)
typedef struct
{
    char chUserName[64];       ///<�û���
    char chPhone[128];         ///<�绰
    char chEmail[128];         ///<����
    char chAbout[512];         ///<�û����
    char chImage[128];         ///<�û�ͷ��
}PhoneUserInfo;

///<��ʾ���������ַ�����Ϣ(122-int)
/*
* 0����ȡ���б��������ķַ�����Ϣ
* 1�������豸����ȡ���������ķַ�����Ϣ
* 2�������豸ID��ȡ���������ķַ�����Ϣ
*/
typedef struct
{
    int nPartID;             ///< ������
    int nDefenseNum;         ///< ������
    int DefenseNo[256];      ///< �������б�
	char chPartitionName[128]; ///<��������
}PartionInformation;
typedef struct
{
    int nCondition;       ///< ����
    char chDevName[128];  ///< �豸��
    int nDevID;           ///< �豸ID
}P_AlarmPartionInfo;

///<��ʾ���������ַ�����Ϣ(122-out)
typedef struct
{
    int nDevID;                   ///<�豸ID
    char chDevName[128];          ///<�豸��
    int nPartNum;                 ///<������Ŀ
    PartionInformation Part[33];  ///<������ϸ��Ϣ
}S_AlarmPartionInfo;

///<��ʾ������Ϣ(123-int)
/*
* 0�����ݱ����ȡ�����豸��Ϣ
* 1���������ƻ�ȡ�����豸��Ϣ
*/
typedef struct
{
    int nCondition;          ///< ����
    char chCode[64];         ///< ���
    char chName[128];        ///< ����
}P_OnlyOneInfo;

///<�ֻ���ȡ�����û�ͷ����Ϣ(124-out)
typedef struct
{
    char chUserName[64];    ///<�û���
    int nUserNum;           ///<�û�����
    char chImage[128];      ///<ͷ������
}S_UserImageInfo;

///<�ֻ���ȡ�����¼���ϸ��Ϣ(125-int)
typedef struct
{
    char chUserName[64];          ///<�û���
    int nPage;                    ///<ҳ��(��nҳ)
    int nShowEventNumInPage;      ///<ÿҳ��ʾ�������¼�
    int nClosed;                  ///<�Ƿ��ѹر�(0:�� 1:�ر� 2:ȫ��)
    int nState;                   ///<����(0:ȫ���¼� 1:�Լ����� 2:���������)
}P_EventByPhoneInfo;

///<�ֻ���ȡ�����¼���ϸ��Ϣ(125-out)
typedef struct
{
    int nEventNum;                ///< �¼�����
    int nID;                      ///< �¼�ID
    char chLabelName[64];         ///< ��ǩ��
    char chSubmitMan[64];         ///< �¼�������
    char chEventDescribe[128];    ///< �¼�Դ
    char chHappenTime[64];        ///< �¼�����ʱ��
    char chSubmitTime[64];        ///< �¼��ύʱ��
    char chContent[1024];         ///< �¼�����
    int nState;                   ///< �¼�״̬(0:�� 1:�ر� 2:ȫ��)
    int nReplyNum;                ///< �ظ�����
    int nProperty;                ///< �û��Ƿ�Ϊ������
    int nHaveRead;                ///< �Ƿ��Ѷ�
}S_EventByPhoneInfo;

///<�ֻ���ȡָ���¼������лظ�(126-int)
typedef struct
{
    int nID;                      ///< �¼�ID
}P_ReplyByOneInfo;

///<�ֻ���ȡָ���¼������лظ�(126-out)
typedef struct
{
    int nReplyNum;                ///< �ظ�����
    char chReplyMan[64];          ///< �ظ���
    char chReplyTime[64];         ///< �ظ�ʱ��
    char chReplyContent[512];     ///< �ظ�����
    char chTimeDescription[32];   ///< ʱ������
}S_ReplyByOneInfo;

///<�ֻ���ȡ�����¼�(ͨ��ʱ��)(127-int)
typedef struct
{
    char chUserName[64];          ///<�û���
    char chLastTime[32];          ///<���һ����¼ʱ��
    int nShowEventNumInPage;      ///<ÿҳ��ʾ�������¼�
    int nClosed;                  ///<�Ƿ��ѹر�(0:�� 1:�ر� 2:ȫ��)
    int nState;                   ///<����(0:ȫ���¼� 1:�Լ����� 2:���������)
}P_AllEventPhoneInfo;

///<�ֻ���ȡ�����¼�(ͨ��ʱ��)(127-out)
typedef struct
{
    int nEventNum;                ///< �¼�����
    int nID;                      ///< �¼�ID
    char chLabelName[64];         ///< ��ǩ��
    char chSubmitMan[64];         ///< �¼�������
    char chEventDescribe[128];    ///< �¼�Դ
    char chHappenTime[64];        ///< �¼�����ʱ��
    char chSubmitTime[64];        ///< �¼��ύʱ��
    char chContent[1024];         ///< �¼�����
    int nState;                   ///< �¼�״̬(0:�� 1:�ر� 2:ȫ��)
    int nReplyNum;                ///< �ظ�����
    int nProperty;                ///< �û��Ƿ�Ϊ������
    int nHaveRead;                ///< �Ƿ��Ѷ�
    char chLastTime[32];          ///< ���һ����¼ʱ��
    char chTimeDescription[32];   ///< ʱ������
}S_AllEventPhoneInfo;

///<GS��γ������(128-int)
typedef struct
{
    int nAreaID;                  ///<����ID
    char chXGS[25];               ///<GS γ��
    char chYGS[25];               ///<GS ����
}P_GSMAPInfo;

///<GS������Ϣ��ȡ(129,134-int)
typedef struct
{
    int nCondition;               ///<����[0-�����ã�1-ȫ��]
}P_GSMAPSHOWInfo;

///<GS������Ϣ��ȡ(129-out)
typedef struct
{
    int nAreaID;                  ///<����ID
    char chName[128];             ///<��������
    char chXGS[25];               ///<GS γ��
    char chYGS[25];               ///<GS ����
    char chContactor[64];         ///<��ϵ��
    char chPhone[64];             ///<��ϵ�绰
}S_GSMAPInfo;

///<IMAGE�ļ�����(130-int)
typedef struct
{
    char chName[64];             ///<�ļ���
    char chPath[128];            ///<�ļ�·��
    float fSize;                 ///<�ļ���С
}P_ImageFileInfo;

///<�ֻ����¼�״̬�޸�(131-int)
typedef struct
{
    char chUserName[64];          ///<�û���
    int nID;                      ///<�¼�ID
}P_OnlyOneIncidentInfo;

///< ����������(132-int)
typedef struct
{
    int nServerID;            ///< ������ID;
    int nServerType;          ///< ���������ͣ�1-���ģ�2-������3-ý��
    char chServerID[1000];    ///< ���Ƶķ�����ID��
    char chServerName[1000];  ///< ���Ƶķ�������
}P_CopyServerLoginInfo;

///< GS�ڵ�ɾ��(133-int)
typedef struct
{
    int nID;            ///< ����ڵ�ID;
}P_GSDeleteInfo;

///<GS������Ϣ��ȡ(134-out)
typedef struct
{
    int nAreaID;                  ///<����ID
    char chName[128];             ///<��������
    char chXGS[25];               ///<GS γ��
    char chYGS[25];               ///<GS ����
    char chMemo[512];             ///<��ע
}S_GSMAPShowInfo;

///<��Ʒ�������ȡ��������(135-out)
typedef struct
{
    char chManufature[64];       ///<Ʒ��
    char chName[64];             ///<������
}S_DvrSortShowInfo;

///< �ͻ��˱��������ύ(136-int)
typedef struct
{
    char chName[60];            ///<��������
    int  nChannelNo;            ///<ͨ����
    char chAlarmType[30];       ///<������������
    char chAlarmTime[30];       ///<����ʱ��
    char chMan[60];             ///<������
    int nConseque;              ///<����ʽ
    char chOpinion[256];        ///<�������
    char chMemo[512];           ///<��ע
}P_AlarmDealIntoInfo;

///< ��ȡ�����¼����ı��(137-out)
typedef struct
{
    int  nCenterNo;             ///<���
    char chName[64];            ///<����
    char chIP[64];              ///<IP��ַ
}S_NextCenterNoInfo;

///< �ͻ�������������(138-int)
typedef struct
{
    char chAlarmID[30000];      ///<������ϢID������1$2$3$4$����$Ϊ�ָ�������$����
    char chMan[60];             ///<������
    int nConseque;              ///<����ʽ
    char chOpinion[256];        ///<�������
    char chMemo[512];           ///<��ע
}P_AlarmProcessSetInfo;

///< ��������(139-int)
typedef struct
{
    int nTypeID;               ///<��������
    int nDays;                 ///<����
}P_AlarmTopInfo;

///< ��������(139-out)
typedef struct
{
    char chName[64];          ///<����
    int nCount;               ///<����
}S_AlarmTopInfo;

///< ��������ȡ�豸������Ϣ(+Ʒ������)(140-out)(CMS)
typedef struct
{
    char  chDvrName[40];  ///<�豸����
    char  chNumber[20];   ///<�豸�ַ������
    char  chIp[20];       ///<�豸IP
    char  chUserName[20]; ///<�û���
    char  chPassWord[20]; ///<����
    long  lNumber;        ///<�豸���ͱ��
    long  lCenterID;      ///<��������ID
    int   nPort;          ///<�˿ں�
    int   nChannelNum;    ///<ͨ����
    int   nDevType;       ///<�豸����
    int   nType;          ///<����
    int   nSubType;       ///<�ͺ�
    int   nNeedLink;      ///<�Ƿ���Ҫ����
    char  Area[20];       ///<��������
    char chDvrManufature[20];  ///<�豸Ʒ������
    char chReserved[64];       ///<Ԥ��
}S_DevBaseInfo,*LPS_DevBaseInfo;

///< ��������ȡ�豸������Ϣ(+Ʒ������+����)(141-out)(CMS)
typedef struct
{
    char  chDvrName[40];  ///<�豸����
    char  chNumber[20];   ///<�豸�ַ������
    char  chIp[20];       ///<�豸IP
    char  chUserName[20]; ///<�û���
    char  chPassWord[20]; ///<����
    long  lNumber;        ///<�豸���ͱ��
    long  lCenterID;      ///<��������ID
    int   nPort;          ///<�˿ں�
    int   nChannelNum;    ///<ͨ������  
    int   nDevType;       ///<�豸����
    int   nType;          ///<����
    int   nSubType;       ///<�ͺ�
    int   nNeedLink;      ///<�Ƿ���Ҫ����
    char  Area[20];       ///<��������
    int linkNum;                  ///<��������
    T_CHANNEL_INFO ARRDevinfo[32];///<����ͨ����
    char chDvrManufature[20];     ///<�豸Ʒ������
    char chReserved[64];          ///<Ԥ��
}S_DevBaseRelateInfo,*LPS_DevBaseRelateInfo;

///< MS��������ȡ�豸������Ϣ(+Ʒ������)(142-out)(MS)
typedef struct
{
    S_DevBaseInfo TBaseInfoEx;    ///<������Ϣ
    char szVodPwd[20];            ///<������Ҫ �ط��û�����
    char szVodName[20];
    bool bLongLink;               ///<�Ƿ񱣳ֳ�����
}S_MSBASEINFO,*LPS_MSBASEINFO;

///< AS��������ȡ�豸������Ϣ(+Ʒ������)(143-out)(AS)
typedef struct
{
    S_DevBaseInfo TBaseInfoEx;      ///<������Ϣ
    int arraySensorInfo[256][2];    ///<̽ͷ�����Ϣ��[*][0]-�Ƿ�Խ�������-1�����������ͣ�>0����δ�裨=0����[*][1]-�Խ�ͨ��(>0)
    int arrayManualSensorInfo[256]; ///<�ֶ��������ͣ�>0��
}S_ASBASEINFO,*LPS_ASBASEINFO;

///< ����Ԥ������(144-int)(add��mod��del)
typedef struct
{
    int nCondition;            ///< ������1-add;2-mod;3-del
    int nEPlanID;              ///< Ԥ��ID
    char chName[64];           ///< ����
    int nLevel;                ///< �����ȼ�
    char chMan[32];            ///< ��
    char chDateTime[32];       ///< ʱ��
    char chStepText[8000];     ///< Ԥ����ϸ���裬ƴ���ַ�������$Ϊ�ָ���
}P_AlarmEPlan;

///< ����Ԥ����������(145-int)(add��del)
typedef struct
{
    int nCondition;            ///< ������1-add;2-del
    int nEPlanID;              ///< Ԥ��ID
    int nAlarmID;              ///< ��������ID
}P_AlarmEPlanRelate;

///< ��ʾ����Ԥ����Ϣ(146-out)
typedef struct
{
    int nEPlanID;              ///< Ԥ��ID
    char chName[64];           ///< ����
    int nLevel;                ///< �����ȼ�
    char chMan[32];            ///< ��
    char chDateTime[32];       ///< ʱ��
}S_ShowAlarmEPlan;

///< ��ʾ����Ԥ����ϸ��Ϣ(147-int)
typedef struct
{
    int nCondition;            ///< ������0-ȫ��;1-�ض�ID
    int nEPlanID;              ///< Ԥ��ID (nCondition=1ʱ)
}P_ShowAlarmEPlanInfo;

///< ��ʾ����Ԥ����ϸ��Ϣ(147-out)
typedef struct
{
    int nEPlanID;              ///< Ԥ��ID
    char chName[64];           ///< ����
    int nLevel;                ///< �����ȼ�
    char chMan[32];            ///< ��
    char chDateTime[32];       ///< ʱ��
    char chStep[512];          ///< Ԥ������
}S_ShowAlarmEPlanInfo;

///< ��ʾ����Ԥ��������Ϣ(148-out)
typedef struct
{
    int nEPlanID;              ///< Ԥ��ID
    char chEName[64];          ///< Ԥ������
    int nAlarmID;              ///< ��������ID
    char chAlarmName[64];      ///< ����������
}S_ShowAlarmEPlanRet;

///< ���ӻ�����ǽ����(149-int)(add��mod��del)
typedef struct
{
    int nCondition;            ///< ������1-���;2-�޸�;3-ɾ��;4-���õ���ǽ����
    int nTvID;
    char chName[64];
    int nPartNum;
    int nStartX;
    int nStartY;
    int nGridX;
    int nGridY;
    char chUser[64];
}P_NewTVScreenInfo;

///< ��ʾ���ӻ�����ǽ��Ϣ(150-out)
typedef struct
{
    int nTvID;
    char chName[64];
    int nPartNum;
    int nStartX;
    int nStartY;
    int nGridX;
    int nGridY;
    char chUser[64];
}S_NewTVScreenInfo;

///<���㱨������ͳ��(151-int)
/*  P_NewStaticsAreaAlarmNum.nCondition��
**  1: �������㵥λʱ���ڱ�������
**  2: ĳ�����ڵ�λʱ���ڵ�һ��������
**  3: ĳ������20����λʱ�䳤�ȱ�������
*/
typedef struct
{
    int nCondition;    ///< ����
    char chName[64];   ///< ��������
    int nSubTime;      ///< ʱ����
    int nUnit;         ///< n����λʱ����
}P_NewStaticsAreaAlarmNum;

///<���㱨������ͳ��(151-out)
typedef struct
{
    char chName[64];   ///< ������ / ����������
    int nNum;          ///< ͳ������
    int nUnitMinute;   ///< ʱ������
}S_NewStaticsAreaAlarmNum;

///<��ʾ�����ȼ���Ϣ(152-out)
typedef struct
{
    int nLevelValue;               ///< ���
    char chLevelName[64];          ///< ����
    char chLevelColor[512];        ///< �����ȼ���ɫ  R#G#B
}S_NEW_SHOWALARMLEVEL;

///<��ʾ�����ȼ�������Ϣ(153-int)
typedef struct
{
    int nCondition;            ///< 0-ȫ����1-���ݱ����ȼ�ֵ��2-���ݱ����ȼ���
    int nAlarmValue;           ///< �����ȼ�ֵ
    char chLevelName[64];      ///< �����ȼ�
}P_NEW_SHOWALARMLEVELPLOY;

///<��ʾ�����ȼ�������Ϣ(153-out)
typedef struct
{
    int nAlarmID;               ///< �����ȼ�ΨһID;
    int nAlarmValue;            ///< �����ȼ�ֵ
    char chLevelName[64];       ///< �����ȼ�
    bool bRelated;              ///< �˹���Ԥ
    int nPlanID;                ///< Ԥ��ID
    char chPlanName[64];        ///< Ԥ����
    bool bRecive;               ///< �Ӿ���ʱ��־
    int nReciveTime;            ///< �Ӿ���ʱʱ��
    int nReciveType;            ///< �Ӿ���ʱʱ�����ͣ�0-�룬1-��
    char chReciveReport[1024];  ///< �Ӿ��ϱ���
    bool bFinish;               ///< ���ó�ʱ��־
    int nFinishTime;            ///< ���ó�ʱʱ��
    int nFinishType;            ///< ���ó�ʱʱ�����ͣ�0-�룬1-��
    char chFinishReport[1024];  ///< �����ϱ���
    int nPlanDeal;              ///< Ԥ������(0-������,1-����)
}S_NEW_SHOWALARMLEVELPLOY;

///<���ñ����ȼ�������Ϣ(154-int)
typedef struct
{
    int nAlarmValue;            ///< �����ȼ�ֵ
    bool bRelated;              ///< �˹���Ԥ
    int nPlanID;                ///< Ԥ��ID
    bool bRecive;               ///< �Ӿ���ʱ��־
    int nReciveTime;            ///< �Ӿ���ʱʱ��
    int nReciveType;            ///< �Ӿ���ʱʱ�����ͣ�0-�룬1-��
    char chReciveReport[1024];  ///< �Ӿ��ϱ���
    bool bFinish;               ///< ���ó�ʱ��־
    int nFinishTime;            ///< ���ó�ʱʱ��
    int nFinishType;            ///< ���ó�ʱʱ�����ͣ�0-�룬1-��
    char chFinishReport[1024];  ///< �����ϱ���
    int nPlanDeal;              ///< Ԥ������(0-������,1-����)
}P_NEW_SETALARMLEVELPLOY;

///<��ȡ��λ��Ϣ(155-out)
typedef struct
{
    int nLevelValue;  ///< ���
    char chName[64];  ///< ����
}S_NEW_SHOWPOSITIONINFO;

///<��ȡ������Ϣ(156-out)
typedef struct
{
	int nPlaceID;     ///<����ID
    int nLevelValue;  ///< ���
    char chName[64];  ///< ����
}S_NEW_SHOWLOCATIONINFO;

///<�������������(157-int)(add��mod��del)
typedef struct
{
    int nCondition;    ///< ����: 1-add,2-mod,3-del
    int nActionID;     ///< ����ID;
    char chName[64];   ///< ��������
}P_NEW_OPACTIONLIB;

///<��ȡ������(158-int)
typedef struct
{
    int nCondition;         ///<  0-ȫ����1-��ȡ������С��ţ�2-��ȡ�̶���������
}P_NEW_SHOWACTIONLIB;

///<��ȡ������(158-out)
typedef struct
{
    int nID;           ///< Ψһ���
    int nActionID;     ///< �������
    char chName[64];   ///< ��������
	int nProperty;		///< ��ʶ��0-����ִ�У�1-�̶����ͣ�2-����ִ�У���2016-07-14����)
	char chProperty[128];  ///< ���ԣ�Ŀǰ��д�绰����(2016-07-14����)����������ִ�л���ִ��
}S_NEW_SHOWACTIONLIB;

///<�¼����������(159-int)(add��mod��del)
typedef struct
{
    int nCondition;         ///< ����: 1-add,2-mod,3-del
    int nEventID;           ///< �¼�ID
    char chName[64];        ///< �¼�����
    int nAlarmValue;        ///< �����ȼ�ֵ
    char chActionID[1024];  ///< ����ID��
    char chMustBeDos[1024]; ///< �����Ƿ�ɼ���ִ��
}P_NEW_OPEVENTLIB;

///<��ȡ�¼���(160-int)
typedef struct
{
    int nCondition;         ///<  0-ȫ����1-�����¼�ID��2-�����¼���, 3- ������������
    int nEventID;           ///< �¼�ID
    char chEventName[64];   ///< �¼�����
}P_NEW_SHOWEVENTLIB;

///<��ȡ�¼���(160-out)
typedef struct
{
    int nEventID;           ///< �¼�ID
    char chEventName[64];   ///< �¼�����
    int nAlarmValue;        ///< �����ȼ�ֵ
    char chAlarmLevel[64];  ///< �����ȼ���
    int nAI_Id;             ///< ����Ψһ���
    int nActionID;          ///< �������
    char chActionName[64];  ///< ��������
    int nSequence;          ///< �����������
    bool bMustDo;           ///< �Ƿ����ִ��
	char chProperty[128];	///< ���ԣ�Ŀǰ��ŵ绰����
}S_NEW_SHOWEVENTLIB;

///<Ԥ�����������(161-int)(add��mod��del)
typedef struct
{
    int nCondition;         ///< ����: 1-add,2-mod,3-del
    int nPlanID;            ///< Ԥ��ID
    char chName[64];        ///< Ԥ������
    char chMan[64];         ///< ������
    char chActionID[1024];  ///< ����ID��
    char chMustBeDos[1024]; ///< �����Ƿ�ɼ���ִ��
}P_NEW_OPPLANLIB;

///<��ȡԤ����(162-int)
typedef struct
{
    int nCondition;         ///<  0-ȫ����1-����Ԥ��ID��2-����Ԥ����, 3- ������������
    int nPlanID;            ///< Ԥ��ID
    char chPlanName[64];    ///< Ԥ������
}P_NEW_SHOWPLANLIB;

///<��ȡԤ����(162-out)
typedef struct
{
    int nPlanID;            ///< Ԥ��ID
    char chPlanName[64];    ///< Ԥ������
    char chMan[64];         ///< ������
    int nAI_Id;             ///< ����Ψһ���
    int nActionID;          ///< �������
    char chActionName[64];  ///< ��������
    int nSequence;          ///< �����������
    bool bMustDo;           ///< �Ƿ����ִ��
	char chProperty[128];   ///< ���ԣ�Ŀǰ��绰����(2016-05-11�޸�)
}S_NEW_SHOWPLANLIB;

///<��ȡ���ô��������Ϣ(163-out)
typedef struct
{
    int nID;                ///< ID
    char chSuggestion[128]; ///< ���
    int nType;              ///< ����
    int nProperty;
    char chProperty[128];
}S_NEW_SHOWALWAYSDEAL;

///<��ȡ����ʽ��Ϣ(164-out)
typedef struct
{
    int nTypeID;          ///< ���
    char chTypeName[64];  ///< ������ (ʵ�����󱨡����쳣)
}S_NEW_SHOWDEALCONSEQUECE;

///<д�뱨��������(165-int)
typedef struct
{
    int nAlarmID;                  ///< ������ϢID
    char chAlarmSource[128];       ///< ����Դ
    int nSourceType;               ///< ����Դ���� 0-������1-����ͷ
    char chAlarmType[128];         ///< ��������
    char chAlarmDateTime[32];      ///< ��������ʱ��(yyyy-mm-dd hh:mm::ss)
    int nAlarmLevel;               ///< ��������
    char chKeyPart[128];           ///< �ؼ���λ
    int nProcessType;              ///< ����ʽ(1-ʵ����2-�󱨣�3-���쳣)
    char chMemo[512];              ///< ��ע
    int nEPlanType;                ///< Ԥ������(1-��ͨԤ����2-�¼�)
    char chPlanName[128];          ///< Ԥ����
    char chHandleMan[128];         ///< ������
    char chAttachment[1024];       ///< ��������
    bool bDoFinish;                ///< �Ƿ������
    char chActionNos[1000];        ///< Ԥ������ID��
    char chActionNames[2048];      ///< Ԥ���������ִ�
    char chDoBeginTimes[2048];     ///< Ԥ�����迪ʼʱ�䴮
    char chDoEndTimes[2048];       ///< Ԥ���������ʱ�䴮
    char chAttachments[8000];      ///< Ԥ�����踽����
    char chDoSuccesses[800];       ///< Ԥ�����账�����ƴ���ַ���
    char chDoMans[2048];           ///< Ԥ�����账���˴�
    char chDoMemos[8000];          ///< Ԥ�����账��������
}P_NEW_WRITEDEALRESULT;

///<����ĳ����Դ��ȡ��ʷ������Ϣ(166-int)
typedef struct
{
    char chAlarmSource[128];       ///< ����Դ
    char chAlarmType[128];         ///< ��������
    int nAnalysisType;		   ///< ͳ������: 1-����������-��Ӧ������ID
}P_NEW_SHOWHISTORYDEAL;

///<����ĳ����Դ��ȡ��ʷ������Ϣ(166-out)
typedef struct
{
    int nLine;                     ///< ��ͼ���
    double nPoint[7];              ///< ��ͼ����
    char chMemo[256];              ///< ����(2,3,4)
}S_NEW_SHOWHISTORYDEAL;

///<����������Ϣ���ۺ�ͳ��(167-int)
typedef struct
{
    int nCondition;                ///< ����(ʱ��(1-Сʱ��2-�ա�3-��)��4-�ص㣬5-�������ͣ�6-�����ȼ���7-����״̬��8-�����ˣ�9-����ʽ)
    int nCategoryType;             ///< 4-�������ص�ͳ�� 5-����������ͳ�� 6-�������ȼ�ͳ�� 7-������״̬ͳ�� 8-��������ͳ�� 9-����������ͳ��
    bool bDatePoint;               ///< �������⴦����
    int nDateStart;                ///< ���տ�ʼ�� (0~23)
    int nDateEnd;                  ///< ���ս����� (0~23)
    bool bMonthPoint;              ///< �������⴦����
    int nMonth;                    ///< ��������ֵ 0-ȫ����1-�����գ�2-��ĩ
    char chBeginTime[32];          ///< ��ʼʱ��
    char chEndTime[32];            ///< ����ʱ��
    char chAreaNames[2048];        ///< �ص��Ŵ�
    char chAlarmTypes[1024];       ///< �������ʹ�
    char chAlarmlevels[32];        ///< �����ȼ���
    char chHandleMans[1024];       ///< �����˴�
    char chProcessTypes[32];       ///< ����ʽ����1-ʵ��,2-��,3-���쳣
    char chProcessStates[32];      ///< ����״̬����0-δ����1-�����У�2-�Ѵ���
}P_NEW_COMPLEXSTATICS;

///<����������Ϣ���ۺ�ͳ��(167-out)
typedef struct
{
    char chDateTime[32];           ///< ʱ��
    char chContent[128];           ///< ���ݣ��ص㡢�������͡������ȼ��������ˡ�����ʽ������״̬��
    int nCount;                    ///< ��Ŀ
}S_NEW_COMPLEXSTATICS;

///<����������Ϣ���ۺϲ�ѯ(168-int)
typedef struct
{
    int nPage;                     ///< ҳ��
    int nCount_Page;               ///< ÿҳ��ʾ��¼����
    char chBeginTime[32];          ///< ��ʼʱ��
    char chEndTime[32];            ///< ����ʱ��
    char chAreaNames[2048];        ///< �ص��Ŵ�
    char chAlarmTypes[1024];       ///< �������ʹ�
    char chAlarmlevels[32];        ///< �����ȼ���
    char chHandleMan[32];          ///< ������
    int nProcessType;              ///< ����ʽ��1-ʵ��,2-��,3-���쳣
    int nProcessStates;            ///< ����״̬��1-δ����2-�����У�3-�Ѵ���
}P_NEW_COMPLEXCHECK;

typedef struct
{
    int nUnHandleCount;            ///< δ��������
}S_NEW_COMPLEXCHECKUNHANDLE;

///<����������Ϣ���ۺϲ�ѯ(168-out)
typedef struct
{
    char chAlarmTypeName[64];      ///< ������������
    char chAlarmSource[64];        ///< ����Դ
    int nAlarmSourceType;          ///< ����Դ���ͣ�0-������1-����ͷ
    char chAlarmArea[64];          ///< �����ص�
    int nSumCount;                 ///< �ܼ�¼����
    int nSumPage;                  ///< ��ҳ��
    char chBeginTime[32];          ///< ������־��ʼʱ�䣨2012-01-01 00:00:00��
    char chBeginDay[32];           ///< ������־��ʼ���ڣ�2012-01-01��
    char chBeginMonth[32];         ///< ������־��ʼ�·ݣ�2012-01��
    int nAlarmTypeID;              ///< ������ϢID
    int nProcessState;             ///< ����״̬��0-δ����1-�����У�2-�Ѵ���
    char chProcessUser_VarC[64];   ///< ������
    char chProcessDate_Date[32];   ///< ��������
    int nProcessMethod_Int;        ///< ����ʽ��1-ʵ��,2-��,3-���쳣
    char chProcessMemo_VarC[512];  ///< ��ע
    int nAlarmLevel;               ///< �����ȼ�
    char chPalnName[64];           ///< ��ӦԤ��
    char chProcessBeginTime[32];   ///< ����ʼʱ��
    char chProcessEndTime[32];     ///< �������ʱ��
}S_NEW_COMPLEXCHECK;

///<����������Ϣ���ۺ�����(169-int)
/*  ������4- nAreaID ����
*         7- nAlarmSourceType �ش�
*����������- nAreaID �ش�
*/
typedef struct
{
    int nCondition;                ///< ����(ʱ��(1-Сʱ��2-�ա�3-��)��4-�ص㣬5-�������ͣ�6-�����ˣ�7-����Դ
    char chDimensions[3072];       ///< ά�ȴ�
    char chBeginTime[32];          ///< ��ʼʱ��
    char chEndTime[32];            ///< ����ʱ��
    char chAlarmSource[64];        ///< ����Դ
    int nAlarmSourceType;          ///< ����Դ���ͣ�0-������1-����ͷ
    int nAreaID;                   ///< �ص�
    char chAlarmType[64];          ///< ��������
    char chHandleMan[64];          ///< ������
    int nAlarmlevel;               ///< �����ȼ�
    int nProcessType;              ///< ����ʽ��1-ʵ��,2-��,3-���쳣
    int nProcessState;             ///< ����״̬��0-δ����1-�����У�2-�Ѵ���
}P_NEW_COMPLEXTOP;

///<����������Ϣ���ۺ�����(169-out)
typedef struct
{
    char chContent[128];           ///< ���ݣ�ʱ�䡢�ص㡢�������͡�����Դ�������ˣ�
    int nCount;                    ///< ��Ŀ
}S_NEW_COMPLEXTOP;

///<���ݱ�����ϢID��ȡ��ӦԤ����Ϣ(170-int)
typedef struct
{
    int nAlramID;                  ///< ������ϢID
}P_NEW_SHOWPLANINFOBYALARM;

///<���ݱ�����ϢID��ȡ��ӦԤ����Ϣ(170-out)
typedef struct
{
    int nActionID;                 ///< �������
    char chActionName[64];         ///< ��������
    int nSequence;                 ///< �����������
    bool bDeal;                    ///< �Ƿ���ִ��
    char chAttach[128];            ///< Ԥ������
    char chBegin[32];              ///< ��ʼʱ��
    char chEnd[32];                ///< ����ʱ��
    char chMan[64];                ///< ������
    char chMemo[1024];             ///< ��������
}S_PLANSTEP;

typedef struct
{
    char chPlanName[64];           ///< Ԥ������
    int nPlanType;                 ///< Ԥ������ 1-��ͨԤ����2-�¼�
    char chAttachment[128];        ///< Ԥ������
    int nStepNums;                 ///< Ԥ��������Ŀ
    S_PLANSTEP T_StepInfo[100];    ///< Ԥ��������ϸ��Ϣ
}S_NEW_SHOWPLANINFOBYALARM;

///<���ݱ���������Ϣ��ȡ������ϸ��Ϣ(171-int)
typedef struct
{
    int nCondition;                ///< 1-���ݱ�����ϢID ��2-���ݱ���Դ��ʱ�䡢���ͣ�3-����GUID��ȡ��
    int nAlarmID;                  ///< ������ϢID
    char chAlarmSource[128];        ///< ����Դ��condition=3ʱ����GUID
    char chAlarmDateTime[32];      ///< ��������ʱ��
    char chAlarmType[32];          ///< ��������
}P_NEW_SHOWALARMINFOBYALARM;

///<���ݱ���������Ϣ��ȡ������ϸ��Ϣ(171-out)
typedef struct
{
    int nAlarmID;                  ///< ������ϢID
    char chAreaName[64];           ///< �ص�
    char chAlarmSource[64];        ///< ����Դ
    int nAlarmSourceType;          ///< ����Դ���ͣ�0-������1-����ͷ
    char chAlarmType[32];          ///< ��������
    char chAlarmDateTime[32];      ///< ��������ʱ��
    int nAlarmLevel;               ///< �����ȼ�
    bool bProcessState;            ///< �Ƿ������
    char chProcessUser_VarC[64];   ///< ������
    char chProcessDate_Date[32];   ///< ��������
    int nProcessMethod_Int;        ///< ����ʽ��1-ʵ��,2-��,3-���쳣
    char chProcessMemo_VarC[512];  ///< ��ע
    char chPlanName[64];           ///< ��ӦԤ��
    int nPlanType;                 ///< Ԥ������ 1-��ͨԤ����2-�¼�
    char chAttachment[128];        ///< Ԥ������
    int nStepNums;                 ///< Ԥ��������Ŀ
    S_PLANSTEP T_StepInfo[100];    ///< Ԥ��������ϸ��Ϣ
    char chNo[20];                 ///< ��ˮ��
    char chAlarmStatusType[128];         ///< ��������
    char chCheckStatus[128];       ///< ���Դ�
    char chIsQualified[64];        ///< ���˽��
    char chCheckMan[64];           ///< ������
    char chCheckDate[20];          ///< ����ʱ��
	int nProperty;				   ///< ��״̬��0-������1-������
	char chGUID[128];			   ///< ����GUID
	char chKeyPart[64];			   ///< ��λ
    int nProcessStatus;			   ///< ����״̬

}S_NEW_SHOWALARMINFOBYALARM;

///<�û�ͼ���������(172-int)(add��mod��del)
typedef struct
{
    int nCondition;                ///< ����: 1-add,2-mod,3-del
    int nGraphID;                  ///< ͼ����
    char chUserName[64];           ///< �û���
    char chGraphName[128];         ///< ͼ����
    char chCondition_VarC[2048];   ///< ͼ������
    int  nProperty;                ///<ͼ������
}P_NEW_OPUSERGRAPHINFO;

///<�û������������(173-int)(add��mod��del)
typedef struct
{
    int nCondition;                ///< ����: 1-add,2-mod,3-del
    int nReportID;                 ///< ������
    char chUserName[64];           ///< �û���
    int nReportType;               ///< ��������(1-�ձ���2-�ܱ���3-�±���4-������5-���걨��6-�걨)
    char chReportName[128];        ///< ������
    char chCondition_VarC[2048];   ///< ѡ���ͼ��
    int nPutDate_Int;              ///< ����ʱ��
    bool bEnable;                  ///< �Ƿ�����
    int  nProperty;                ///<ͼ������
}P_NEW_OPUSERREPORTINFO;

///<�޸��û�����״̬(174-int)(mod)
typedef struct
{
    int nReportID;                 ///< ������
}P_NEW_MODSTATUSUSERREPORT;

///<��ȡ�û�ͼ����Ϣ(175-int)
typedef struct
{
    char chUserName[64];           ///< �û���
    int nProperty;                 ///< ͼ������ 0-ȫ��
}P_NEW_SHOWUSERGRAPHINFO;

///<��ȡ�û�ͼ����Ϣ(175-out)
typedef struct
{
    int nGraphID;                  ///< ͼ����
    char chGraphName[128];         ///< ͼ����
    char chCondition_VarC[2048];   ///< ͼ������
    int nProperty;                 ///< ͼ������
}S_NEW_SHOWUSERGRAPHINFO;

///<��ȡ�û�������Ϣ(176-int)
typedef struct
{
    char chUserName[64];           ///< �û���
    int nReportType;               ///< ��������(1-�ձ���2-�ܱ���3-�±���4-������5-���걨��6-�걨)(0-ȫ��)
    char chReportDate[32];         ///< ��������
    int nStatus;                   ///< �Ƿ��Ѷ�(0-δ����1-�Ѷ�)(2-ȫ��)
    int nProperty;                 ///< ͼ������(0-ȫ��)
}P_NEW_SHOWUSERREPORTINFO;

///<��ȡ�û�������Ϣ(176-out)
typedef struct
{
    int nReportID;                 ///< ������
    int nReportType;               ///< ��������(1-�ձ���2-�ܱ���3-�±���4-������5-���걨��6-�걨)
    char chReportName[128];        ///< ������
    char chCondition_VarC[2048];   ///< ѡ���ͼ��
    char chReportDate[32];         ///< ��������
    int nStatus;                   ///< �Ƿ��Ѷ�(0-δ����1-�Ѷ�)
    int nProperty;                 ///< ͼ������(0-ȫ��)
}S_NEW_SHOWUSERREPORTINFO;

///<����������ϸ��Ϣ(177-int)
typedef struct
{
    int nAlarmID;                  ///< ��������ID
    char chAreaName[64];           ///< ����������������
    char chDeviceName[64];         ///< �����豸����
    char chChannelName[64];        ///< ����ͨ�����ƣ����Ϊͨ���������ʹ��룬�������Ϊ�գ�
    char chBeginTime[32];          ///< ������ʼʱ��
    char chEndTime[32];            ///< ��������ʱ��
    char chUserName[64];           ///< �û���
}P_NEW_SHOWALARMBACKINFO;

///<����������ϸ��Ϣ(177-out)
typedef struct
{
    int nID;                      ///< ID
    char chUserName[64];          ///< �û���
    char chAreaName[64];          ///< ������
    char chDeviceName[64];        ///< �豸��
    char chChannelName[64];       ///< ͨ����
    int nActType;                 ///< ��������
    int nSequece;                 ///< ���
    char chActionName[64];        ///< ������
    char chBeginTime[32];         ///< ��ʼʱ��
    char chEndTime[32];           ///< ����ʱ��
    char chAttachment[128];       ///< ������
    int nDoSuccess;               ///< ����״̬��0-δ����1-�����У�2-�Ѵ���
    char chMemo[1024];            ///< ��������
}S_NEW_SHOWALARMBACKINFO;

///<��ȡ�û����涩����Ϣ����(178-int)
typedef struct
{
    char chUserName[64];         ///< �û���
    int nProperty;                 ///< ͼ������(0-ȫ��)
}P_NEW_SHOWUSERREPORTBOOKINFO;

///<��ȡ�û����涩����Ϣ����(178-out)
typedef struct
{
    int nReportID;                 ///< ������
    int nReportType;               ///< ��������(1-�ձ���2-�ܱ���3-�±���4-������5-���걨��6-�걨)
    char chReportName[128];        ///< ������
    char chCondition_VarC[2048];   ///< ѡ���ͼ��
    char chReportDate[32];         ///< ��������
    int nPutDate_Int;              ///< ����ʱ��
    bool bEnable;                  ///< �Ƿ�����
    int nProperty;                 ///< ͼ������(0-ȫ��)
}S_NEW_SHOWUSERREPORTBOOKINFO;

///<������������(179-int)(add��mod��del)
typedef struct
{
    int nCondition;                ///< ����: 1-add,2-mod,3-del
    int nPlaceType;                ///< ��������ֵ
    char chPlaceName[64];          ///< ������
}P_NEW_OPAREAPLACEINFO;

///<��λ��������(180-int)(add��mod��del)
typedef struct
{
    int nCondition;                ///< ����: 1-add,2-mod,3-del
    int nKeyPartValue;             ///< ��λ����ֵ
    char chKeyPartName[64];        ///< ��λ��
}P_NEW_OPKEYPARTINFO;

///<�����ȼ���������(181-int)(add��mod��del)
typedef struct
{
    int nCondition;                ///< ����: 1-add,2-mod,3-del
    int nLevelValue;               ///< ��������ֵ
    char chLevelName[64];          ///< ����������
    char chLevelColor[512];        ///< �����ȼ���ɫ
}P_NEW_OPALARMLEVELINFO;

///<ʱ��ģ���������(182-int)(add��mod��del)
typedef struct
{
    int nCondition;                ///< ����: 1-add,2-mod,3-del
    int nID;                       ///< ģ��ID
    char chName[128];              ///< ģ������
    char chDescrip[1024];          ///< ����
    char chMon[512];               ///< ����һ
    char chTue[512];               ///< ���ڶ�
    char chWed[512];               ///< ������
    char chThu[512];               ///< ������
    char chFri[512];               ///< ������
    char chSat[512];               ///< ������
    char chSun[512];               ///< ������
}P_NEW_OPTIMEMODEL;

///<ʱ��ģ����Ϣ��ȡ(183-int)
typedef struct
{
    int nCondition;                ///< ����: 0-ȫ��,1-����ID,2-ȡȫ��ģ��(����ʱ���)
    int nID;                       ///< ģ��ID
}P_NEW_SHOWTIMEMODEL;

///<ʱ��ģ����Ϣ��ȡ(183-out)

typedef struct
{
    char chStart[10];              ///< ��ʼʱ��
    char chEnd[10];                ///< ����ʱ��
}S_TIMECONSEQUECE;

typedef struct
{
    int nCount;                    ///< ʱ�������
    S_TIMECONSEQUECE S_Info[10];   ///< ʱ���
}S_TIMEWEEKDAY;

typedef struct
{
    int nID;                       ///< ģ��ID
    char chName[128];              ///< ģ������
    char chDescrip[1024];          ///< ����
    int nModelType;                ///< ģ������0-�ճ�ģ�壬1-�ڼ���ģ��
    char chStartDate[12];          ///< ��ʼ����(�ڼ���ģ��)
    char chEndDate[12];            ///< ��������(�ڼ���ģ��)
    S_TIMEWEEKDAY S_Day[7];        ///< ����һ~������ (�ڼ���ģ����� 0)
}S_NEW_SHOWTIMEMODEL;

///<�����ȼ�������������(184-int)(add��del)
typedef struct
{
    int nCondition;                ///< ����: 1-add,2-mod,3-del,4-���
    char chLcIDs[80000];            ///< ID��(ɾ��ʱ����)
    char chPlaces[80000];           ///< ����ID��
    char chKeyParts[80000];         ///< ��λID��
    char chTypes[80000];            ///< ��������ID��
    int nModelID;                  ///< ģ��ID
    int nLevelID;                  ///< �����ȼ�ID
}P_NEW_SETMULALARMLEVEL;

///<�����ȼ���������������Ϣ��ȡ(185-int)
typedef struct
{
    int nCondition;                ///< ����: 0-ȫ��,1-���ݵȼ�,2-���ݳ�������λ�����͡�ʱ��ģ��ID
    int nLevelID;                  ///< �����ȼ�ֵ
    char chPlace[64];              ///< ��������
    char chKeyPart[64];            ///< �ؼ���λ����
    char chAlarmType[64];          ///< ������������
    int nModelID;                  ///< ʱ��ģ��ID
}P_NEW_SHOWMULALARMLEVEL;

///<�����ȼ���������������Ϣ��ȡ(185-out)
typedef struct
{
    int nAlarmLevelId_Int;        ///< ��������ID
    int nAlarmLevel_Int;          ///< ��������ֵ
    char chAlarmLevelName[32];    ///< ����������
    int nPlaceId_Int;             ///< ����ID
    int nPlaceType_Int;           ///< ��������ֵ
    char chPlaceName[64];         ///< ��������
    int nKeyPartId_Int;           ///< ��λID
    int nKeyPart_Int;             ///< ��λֵ
    char chKeyPartName[64];       ///< ��λ����
    int nAlarmTypeId_Int;         ///< ��������ID
    char chAlarmTypeName[64];     ///< ����������
    int nTimeModuleId_Int;        ///< ʱ��ģ��ID
    char chModuleName_VarC[128];  ///< ʱ��ģ������
    int nLC_ID;                   ///< ��¼���
}S_NEW_SHOWMULALARMLEVEL;

///<�����ȼ�������������(186-int)(add��del)
typedef struct
{
    int nCondition;                ///< ����: 1-add,2-mod,3-del
    int nDevID;                    ///< �豸ID
    int nDevType;                  ///< �豸����1-������2-ǰ���豸(����ͷ��̽ͷ)
    int nAlarmTypeID;              ///< ��������ID;
    int nModelID;                  ///< ģ��ID
    int nLevelID;                  ///< �����ȼ�ID
}P_NEW_SETSINALARMLEVEL;

///<�����ȼ���������������Ϣ��ȡ(187-int)
typedef struct
{
    int nCondition;                ///< ����: 0-ȫ����1-�����豸ID+�豸����
    int nDevID;                    ///< �豸ID
    int nDevType;                  ///< �豸����1-������2-ǰ���豸(����ͷ��̽ͷ)
}P_NEW_SHOWSINALARMLEVEL;

///<�����ȼ���������������Ϣ��ȡ(187-out)
typedef struct
{
    int nDevID;                    ///< �豸ID
    int nDevType;                  ///< �豸����1-������2-ǰ���豸(����ͷ��̽ͷ)
    int nAlarmTypeId_Int;          ///< ��������ID
    char chAlarmTypeName[64];      ///< ����������
    int nTimeModuleId_Int;         ///< ʱ��ģ��ID
    char chModuleName_VarC[128];   ///< ʱ��ģ������
    int nAlarmLevelId_Int;         ///< ��������ID
    int nAlarmLevel_Int;           ///< ��������ֵ
    char chAlarmLevelName[32];     ///< ����������
    int nLC_ID;                    ///< ��¼���
    char chDevName[128];           ///< ����[nCondition=2ʱ��Ч]
    int nTerminalID;               ///< ����ID
    int nChannelNo;                ///< ͨ����
}S_NEW_SHOWSINALARMLEVEL;

///< ������������ȡ�豸��ϸ��Ϣ+��������λ(188-out)
typedef struct
{
    S_DevBaseInfo TBaseInfoEx;      ///<������Ϣ
    int nPlaceType;                 ///<����ID
    int nKeyPart;                   ///<��λID
    int nBaseLevel;                 ///<Ĭ�ϵȼ�
    int ArrayFrontend[128][5];      ///<̽ͷ�ṹ����:   0-����,1-��λ,2-Ĭ�ϵȼ�,3-(-1,������>0 ��������),4- ����ͨ����
    int ArrayCamera[128][3];        ///<����ͷ�ṹ����: 0-����,1-��λ,2-Ĭ�ϵȼ�
}S_DevBaseInfo_AS,*LPS_DevBaseInfo_AS;

///< ��������λ���������͡�ʱ��ģ��(����+ID)(189-int)
typedef struct
{
    int nCondition;                ///< ����: 0-������1-��λ��2-�������ͣ�3-ʱ��ģ��
}P_NEW_PLACEKEYPARTMODEL;

///< ��������λ���������͡�ʱ��ģ��(����+ID)(189-out)
typedef struct
{
    int nID;                       ///< ID
    char chName[128];              ///< ����
}S_NEW_PLACEKEYPARTMODEL;

///< �������ƻ�ȡ�����ȼ���Ϣ(190-int)
typedef struct
{
    int nDevType;                  ///< �豸����1-������2-ǰ���豸(����ͷ��̽ͷ)
    char chName[128];              ///< ����
}P_NEW_PLACEKEYPARTBYNAME;

///< �������ƻ�ȡ�����ȼ���Ϣ(190-out)
typedef struct
{
    char chName[128];              ///< ����
    char chAlarmTypeName[64];      ///< ����������
    char chModuleName_VarC[128];   ///< ʱ��ģ������
    char chAlarmLevelName[32];     ///< ����������
}S_NEW_PLACEKEYPARTBYNAME;

///< �������ƻ�ȡ������������(191-int)
typedef struct
{
    int nCondition;                ///< Ĭ��0,1-����̽ͷ����
    int nDevType;                  ///< �豸����1-������2-ǰ���豸(����ͷ��̽ͷ)
    char chName[128];              ///< ����
}P_NEW_SHOWALARMBYDEVNAME;

///< �������ƻ�ȡ������������(191-out)
typedef struct
{
    char chName[128];              ///< ����
    int nAlarmTypeID;              ///< ��������ID
    char chAlarmTypeName[64];      ///< ����������
}S_NEW_SHOWALARMBYDEVNAME;

///< �������ó�������λ
typedef struct
{
    int nCondition;                ///< 1-���ó�����2-���ò�λ
    int nTypeValue;                ///< ����or��λ����ֵ
    char chIDs[1000000];           ///< ID��or��Ŵ�
}P_NEW_SET_PLACEKEYPART;

///< ��ȡ��������������Ϣ
typedef struct
{
    int nCondition;                ///< 0-ȫ����1-��ȡ�����ã�2-��ȡδ���ã�3-���������ţ�4-���������ó�������ֵ��
    char chCode[64];               ///< ������
    char chTypeValues[128];        ///< ��������ֵ��
}P_NEW_SHOW_AREAPLACESET;

///< ��ȡ��������������Ϣ
typedef struct
{
    unsigned int nAreaID;         ///< ����ID
    char chCode[64];              ///< ������
    char chAreaName[128];         ///< ��������
    char chUpperAreaName[128];    ///< �ϼ�����
    char chUpperCode[64];         ///< �ϼ�������
    int nNodeType;                ///< �ڵ�����ֵ
    int nAreaType;                ///< ��������ֵ
    char chAreaTypeName[128];     ///< ��������
}S_NEW_SHOW_AREAPLACESET;

///< ��ȡ��λ����������Ϣ
typedef struct
{
    int nCondition;                ///< 0-ȫ����1-��ȡ�����ã�2-��ȡδ���ã�3-�����豸��ţ�4-���������ó�������ֵ������λ����ֵ��
    char chCode[64];               ///< �豸���
    char chTypeValues[128];        ///< ��������ֵ��
    char chKeyPartValues[128];     ///< ��λ����ֵ��
}P_NEW_SHOW_KEYPARTSET;

///< ��ȡ��λ����������Ϣ
typedef struct
{
    char chName[128];             ///< �豸����
    char chCode[64];              ///< �豸���
    char chUpperAreaName[128];    ///< �ϼ�����
    char chUpperCode[64];         ///< �ϼ�������
    int nNodeType;                ///< �ڵ�����ֵ
    int nAreaType;                ///< ��������ֵ
    char chAreaTypeName[128];     ///< ��������
    int nKeyPart;                 ///< ��λ����ֵ
    char chKeyPart[128];          ///< ��λ����
}S_NEW_SHOW_KEYPARTSET;

///< ��ȡ�����Ű���Ϣ(196-out)
typedef struct
{
    int  nScheduleID;                   ///< �Ű���
    int  nClassID;                      ///< ��α��
    char chClassName[32];               ///< �������
    char chUserName[64];                ///< ֵ��Ա����
    char chRole[64];                    ///< ֵ��Ա��ɫ
    char chBeginTime[32];               ///< �����ʼʱ��
    char chEndTime[32];                 ///< ��ν���ʱ��
    char chDate[32];                    ///< �������
}S_NEW_SHOWTODAYCLASSESINFO;

///< ��ȡ��ǰ�����û���Ϣ(197��199��200-in)
typedef struct
{
    int nCondition;                     ///< ����[200: 1-ֵ�೤���Ӱ�,2-ֵ�೤��ѯ��ʷ]
    int  nScheduleID;                   ///< �Ű�ID����Ρ���������ɫ����ά�ȵ�ID��
}P_NEW_SHOW_HA_CURUSER;

///< ��ȡ��ǰ�����û���Ϣ(197-out)
typedef struct
{
    char strRole[64];              ///< �û���ɫ
    char chPassWord[64];           ///< �û�����
    char chHeirTime[32];           ///< �Ӱ�ʱ��
    char chImage[512];             ///< �û�ͷ��
    unsigned short nAlarmCount;    ///< ��������
    bool bMonitor;                 ///< �Ƿ�ӵ�н��Ӱ����Ȩ��
    bool bDoShift;                 ///< �Ƿ��ѽ���
}S_NEW_SHOW_HA_CURUSER;

///< ��ȡ���Ӱ���Ա��Ϣ(198-in)
typedef struct
{
    char chRole[64];              ///< ��ɫ����
    char chDate[32];              ///< ��һ���������
    int  nClassID;                ///< ��һ����α��
}P_NEW_SHOW_HA_WAITUSERLIST;

///< ��ȡ���Ӱ���Ա��Ϣ(198-out)
typedef struct
{
    int  nScheduleID;             ///< �Ű�ID
    char chUserName[64];          ///< ֵ��Ա����
    char chRole[64];              ///< ��ɫ����
    char chPassWord[64];          ///< �û�����
    char chImage[512];            ///< �û�ͷ��
}S_NEW_SHOW_HA_WAITUSERLIST;

///< ��ȡֵ��Ա����ִ�����(199-out)
typedef struct
{
    char chTaskName[64];          ///< ��������
    int nTaskType;                ///< ��������[1-�ճ�����2-ͻ������]
    int nTaskCount;               ///< ������ִ�д���
    int nDoCount;                 ///< ������ɴ���
}S_NEW_SHOW_HA_A_TASKINFO;

///< ��ȡֵ�೤����ִ�����(200-out)
typedef struct
{
    int  nScheduleID;              ///< �����Ű�ID
    char chUserName[64];           ///< ��������
    char chRole[64];               ///< ������ɫ
    float fPTask;                  ///< ���������
    bool bHandover;                ///< �Ƿ��ѽ���
    char chMemo[600];              ///< ��ע
    char chLeaderMemo[600];        ///< ֵ�೤��ע[nCondition =2]
}S_NEW_SHOW_HA_M_TASKINFO;

///< ��ȡ�����δ��������Ϣ(201-in)
typedef struct
{
    char chBeginTime[32];           ///< ��ʼʱ��
    char chEndTime[32];             ///< ����ʱ��
}P_NEW_SHOW_HA_ALARMINFO;

///< ��ȡ�����δ��������Ϣ(201-out)
typedef struct
{
    char chAlarmSource[64];        ///< ����Դ
    char chAlarmType[32];          ///< ��������
    char chAlarmDateTime[32];      ///< ��������ʱ��
    int nAlarmLevel;               ///< �����ȼ�
}S_NEW_SHOW_HA_ALARMINFO;

///< �ύ������Ϣ��202-in�� ������ʱ������������ݿ��¼��
typedef struct
{
    int nUserSchID;                ///< �������Ű�ID
    int nHeirSchID;                ///< �Ӱ����Ű�ID
    float fPTask;                  ///< ���������
    int  nDelAlarmCount;           ///< ������������
    char chMemo[600];              ///< ��ע
    char chIDList[300];            ///< �����Ű�ID�� ����[1$2$3$]
}P_NEW_ADD_HA_INFO;

///< ��ȡ���Ӱ���ʷ��Ϣ��203-in��
typedef struct
{
    int  nCondition;                ///< ������1-���Ű�ID��ȡ 2-������ɸѡ
    int  nScheduleID;              ///< �Ű�ID
    char chUserName[64];           ///< ����������
    char chRole[64];               ///< �����˽�ɫ
    char chHeirBeginTime[32];      ///< �Ӱ���ʼʱ��  ����4�����������գ�������ʱ����  ������Ĭ��1��
    char chHeirEndTime[32];        ///< �Ӱ����ʱ��
    char chHandoverBeginTime[32];  ///< ������ʼʱ��
    char chHandoverEndTime[32];    ///< �������ʱ��
    float fPBeginTask;             ///< �������������
    float fPENdTask;               ///< �������������
    int nAlarmCountBegin;          ///< ����������������
    int nAlarmCountEnd;            ///< ����������������
}P_NEW_SHOW_HA_INFO;

///< ��ȡ���Ӱ���ʷ��Ϣ��203-out��
typedef struct
{
    int  nScheduleID;              ///< �Ű�ID
    char chUserName[64];           ///< ����������
    char chHeirName[64];           ///< �Ӱ�������
    char chRole[64];               ///< �����˽�ɫ
    char chHeirRole[64];           ///< �Ӱ��˽�ɫ
    char chImage[512];             ///< ������ͷ��
    char chHeirImage[512];         ///< �Ӱ���ͷ��
    char chHeirTime[32];           ///< �Ӱ�ʱ��
    char chHandoverTime[32];       ///< ����ʱ��
    float fPTask;                  ///< ���������
    int nDelAlarmCount;            ///< ������������
    char chMemo[600];              ///< ��ע  
    bool bMonitor;                 ///< �Ƿ���ֵ�೤ 	
}S_NEW_SHOW_HA_INFO;

///< �������ݿ�ַ�����(204-in)
typedef struct
{
    int nScheduleID;               ///< ���ΨһID
}P_NEW_TASKDISTREBUTE_SET;

///< ����Ѳ���ɫ��չ����(205-in)
typedef struct
{
    int nCondition;                ///< ������1-add,2-mod,3-del,
    int nRoleID;                   ///< ��ɫID
    char chRole[64];               ///< ��ɫ����
    int nUppRoleID;                ///< �ϼ���ɫID
    char chMemo[512];              ///< ��ɫ��ע
    bool bParticipate;             ///< �Ƿ�����Ű�
    char chModuleAuthoritys[1024]; ///< ģ��Ȩ�޴�[01��]
}P_NEW_INSPECT_ROLESET;

///< ����Ѳ���ɫ��չ��Ϣ��ȡ(206-in)
typedef struct
{
    int nCondition;                ///< ������1-���н�ɫ,2-���ݽ�ɫID,3-���ݽ�ɫ����
    int nRoleID;                   ///< ��ɫID
    char chRole[64];               ///< ��ɫ����
}P_NEW_INSPECT_ROLESHOW;

///< ����Ѳ���ɫ��չ��Ϣ��ȡ(206-out)
typedef struct
{
    int nRoleID;                   ///< ��ɫID
    char chRole[64];               ///< ��ɫ����
    int nUppRoleID;                ///< �ϼ���ɫID
    char chUppRole[64];            ///< �ϼ���ɫ����
    char chMemo[512];              ///< ��ɫ��ע
    bool bParticipate;             ///< �Ƿ�����Ű�
    bool bModuleAuthoritys[16];    ///< ģ��Ȩ��[0-�Ű�,1-������,2-���񸴺�,3-ֵ�೤���Ӱ�]
                                   ///<[4-�����Ű�Ȩ��,5-ֵ�೤���Ӱ�Ȩ��,6-���񸴺�Ȩ��,7-�������Ȩ�� 8-����ȼ��޸�Ȩ�� 9 - ����Ȩ��]
}S_NEW_INSPECT_ROLESHOW;

///< ����Ѳ���쳣�����(207-in)
typedef struct
{
    int nCondition;                ///< ������[�쳣���ͣ�1-add,2-mod,3-del���쳣�4-add,5-mod,6-del]
    int nTypeID;                   ///< ΨһID
    char chType[128];              ///< ����
    int nUppTypeID;                ///< ��������ID
}P_NEW_INSPECT_ABORTLIBSET;

///< ����Ѳ���쳣����Ϣ��ȡ(208-in)
typedef struct
{
    int nCondition;               ///< ������1-�����쳣����,2-�����쳣��
}P_NEW_INSPECT_ABORTLIBSHOW;

///< ����Ѳ���쳣����Ϣ��ȡ(208-out)
typedef struct
{
    int nTypeID;                   ///< ΨһID
    char chType[128];              ///< ����
    int nUppTypeID;                ///< ��������ID[nCondition=2]
}S_NEW_INSPECT_ABORTLIBSHOW;

///< ����Ѳ�����������(209-int)
typedef struct
{
    int nCondition;                ///< ������1-add,2-mod,3-del
    int nDateID;                   ///< ������ΨһID
    char chName[64];               ///< ����������
    bool bWeek[7];                 ///< ���ڼ��Ƿ��ϰ�[����һ-0 ~ ������-6]
    char chModDates[128];          ///< �޸����ڴ�����1$2$(2-mod)
}P_NEW_INSPECT_DATEGROUPSET;

///< ����Ѳ����������Ϣ��ȡ(210-out)
typedef struct
{
    int nDateID;                   ///< ������ΨһID
    char chName[64];               ///< ����������
    bool bWeek[7];                 ///< ���ڼ��Ƿ��ϰ�[����һ-0 ~ ������-6]
}S_NEW_INSPECT_DATEGROUPSHOW;

///< ����Ѳ������Ϣ����(211-int)
typedef struct
{
    int nCondition;                ///< ������1-add,2-mod,3-del
    int nClassID;                  ///< ���ΨһID
    char chName[64];               ///< �������
    int nDateID;                   ///< ������ΨһID
    char chStartTime[32];          ///< ��ο�ʼʱ��
    char chEndTime[32];            ///< ��ν���ʱ��
    bool bCrossDate;               ///< �Ƿ����
    char chRoleIds[1024];          ///< ��ؽ�ɫID��(�磺1$2$)
}P_NEW_INSPECT_CLASSINFOSET;

///< ����Ѳ������Ϣ��ȡ(212-out)
typedef struct
{
    int nClassID;                  ///< ���ΨһID
    char chName[64];               ///< �������
    int nDateID;                   ///< ������ΨһID
    char chStartTime[32];          ///< ��ο�ʼʱ��
    char chEndTime[32];            ///< ��ν���ʱ��
    bool bCrossDate;               ///< �Ƿ����
    char chRoleIds[1024];          ///< ��ؽ�ɫID��(�磺1$2$)
}S_NEW_INSPECT_CLASSINFOSHOW;

///< ����Ѳ���Ű���Ϣ����(213-int)
typedef struct
{
    int nCondition;                ///< ������1-add,2-mod,3-del,4-set
    int nScheduleID;               ///< �Ű�ID
    char chName[64];               ///< �������
    char chDateTime[32];           ///< �Ű�����
    char chUserName[1024];         ///< �û��� [nCondition =4ʱ����ʽ��1$2$]
    char chRoleName[64];           ///< ��ɫ��
    char chChangeMan[64];          ///< �޸����û���
    char chChangeMemo[512];        ///< �޸ı�ע
}P_NEW_INSPECT_SCHEDULEINFOSET;

///< ����Ѳ���Ű���Ϣ��ȡ(214-int)
typedef struct
{
    int nCondition;                ///< ������0-ȫ����1-�������ڻ�ȡ�����ڵ������Ϣ
    char chStartDate[32];          ///< ��ʼ����
    char chEndDate[32];            ///< ��������
}P_NEW_INSPECT_SCHEDULEINFOSHOW;

///< ����Ѳ���Ű���Ϣ��ȡ(214-out)
typedef struct
{
    int nScheduleID;               ///< �Ű�ID
    int nClassID;                  ///< ���ΨһID
    char chName[64];               ///< �������
    int nUserID;                   ///< �û�ID
    int nRoleID;                   ///< ��ɫID
    char chUserName[64];           ///< �û���
    char chRoleName[64];           ///< ��ɫ��
    char chDateTime[32];           ///< �Ű�����
    char chWeekDayName[32];        ///< ���ڼ�
}S_NEW_INSPECT_SCHEDULEINFOSHOW;

///< ����Ѳ����-�û���Ϣ��ȡ(215-int)
typedef struct
{
    int nCondition;                ///< ������0-ȫ����1-���ݰ�����ͽ�ɫ��
    char chClassName[64];          ///< �����
    char chRoleName[64];           ///< ��ɫ��
}P_NEW_INSPECT_CLASSUSERINFOSHOW;

///< ����Ѳ����-�û���Ϣ��ȡ(215-out)
typedef struct
{
    int nClassID;                  ///< ���ΨһID
    char chName[64];               ///< �������
    bool bWeek[7];                 ///< ���ڼ��Ƿ��ϰ�[����һ-0 ~ ������-6]
    int nUserID;                   ///< �û�ID
    int nRoleID;                   ///< ��ɫID
    char chUserName[64];           ///< �û���
    char chRoleName[64];           ///< ��ɫ��
    char chStartTime[32];          ///< ��ο�ʼʱ��
    char chEndTime[32];            ///< ��ν���ʱ��
    bool bCrossDate;               ///< �Ƿ����
    bool bParticipate;             ///< �Ƿ�����Ű�
}S_NEW_INSPECT_CLASSUSERINFOSHOW;

///< ����Ѳ����ģ���������(216-int)
typedef struct
{
    int nCondition;                ///< ������1-add,2-mod,3-del
    int nModuleID;                 ///< ���ģ��ΨһID
    char chName[64];               ///< ���ģ������
    char chStartTime[32];          ///< ���ģ�忪ʼʱ��
    char chEndTime[32];            ///< ���ģ�����ʱ��
    bool bCrossDate;               ///< �Ƿ����
    char chRoleIds[1024];          ///< ��ؽ�ɫID��(�磺1$2$)
}P_NEW_INSPECT_CLASSMODULESET;

///< ����Ѳ��������Ϣ��������(217-int)
typedef struct
{
    int nCondition;                ///< ������1-add,2-mod
    int nTaskID;                   ///< ����ΨһID
    char chName[64];               ///< ��������
    char chDescription[512];       ///< ��������
    int nOperation;                ///< �����������
    char chEffectiveBeginDate[32]; ///< ��Ч�ڿ�ʼʱ��
    char chEffectiveEndDate[32];   ///< ��Ч�ڽ���ʱ��
    int nLoopMethod;               ///< ѭ������
    char chLoopMemo[512];          ///< ѭ����ע
    bool bDoTimeRange;             ///< �Ƿ�涨����ʱ�䷶Χ
    char chStartTime[32];          ///< ��ʼʱ��
    char chEndTime[32];            ///< ����ʱ��
    bool bStartInTime;             ///< �Ƿ�涨׼ʱִ��
    bool bEngInTime;               ///< �Ƿ�ǿ��Ҫ���ֹʱ��
    bool bWarn;                    ///< �Ƿ񵽵�����
    int nWarnMinu;                 ///< ����ǰX��������
    bool bTotalTime;               ///< �Ƿ�涨����ִ��ʱ��
    int nToTalTime;                ///< ����ִ��ʱ��
    int nTotalTimes;               ///< ִ�д���
    bool bRuleTimes;               ///< �Ƿ�ǿ��ֵ��Ա��ִ�в鿴��Ƶʱ�Ե����ƵԤ��ƵĻ��ΪѲ���Ҫ����
    int nRuleTimes;                ///< ÿ������ÿ·��Ƶ���ٵ������
    char chInstructions[1024];     ///< ����ָ��
    bool bTaskLevel;               ///< �Ƿ�涨������Ҫ�ȼ�
    int nTaskLevel;                ///< ������Ҫ�ȼ����ȼ���ID��û�й涨��ʱ��Ϊ0
    bool bError;                   ///< �Ƿ��쳣�ο�
    int nError;                    ///< �쳣��ID��û��ʱΪ0
    char chErrorLabel[128];        ///< �����ǩ
    int nClassId;                  ///< ���ΨһID
    int nStatus;                   ///< ����״̬��1-δ�·���2-δ��ɣ�3-���·���
    int nType;                     ///< �������ͣ�1-�ճ�����2-ͻ������
    char chRoleNames[1024];        ///< �·����󣨽�ɫ����$����
    char chKeyPartName[128];       ///< ��λ����
    int nObject;                   ///< ���ⳡ��Ϊ1�����峡��Ϊ2
    char chPlaceNames[30000];      ///< ���ⳡ������峡�����ƣ�$����
    char chDates[8000];            ///< ����$��
}P_NEW_INSPECT_TASKINFOSET;

///< ����Ѳ�����������Ϣ��������(218-int)
typedef struct
{
    char chName[64];               ///< ��������
    char chDescription[512];       ///< ��������
    bool bDoTimeRange;             ///< �Ƿ�涨����ʱ�䷶Χ
    char chStartTime[32];          ///< ����ʼʱ��
    char chEndTime[32];            ///< �������ʱ��
    bool bStartInTime;             ///< �Ƿ�׼ʱ��ʼִ��
    bool bEngInTime;               ///< �Ƿ�Ҫ���ֹʱ��
    bool bTotalTime;               ///< �Ƿ�涨����ִ��ʱ��
    int nToTalTime;                ///< ����ʱ������λ�����ӣ�
    char chUserName[64];           ///< �û���
    int nScheduleID;               ///< �Ű�ID
}P_NEW_INSPECT_FASTTASKINFOSET;

///< ����Ѳ������ģ���������(219-int)
typedef struct
{
    int nCondition;                   ///< ������1-add,2-mod,3-del
    int nMoudleID;                    ///< ģ��ID
    char chName[64];                  ///< ģ����������
    char chDescription[512];          ///< ��������
    int nOperation;                   ///< ��������
    int nLoopMethod;                  ///< ѭ����ʽ
    char chLoopMemo[512];             ///< ѭ����ʽ��ע
    bool bDoTimeRange;                ///< �Ƿ�涨����ʱ�䷶Χ
    char chStartTime[32];             ///< ��ʼִ��ʱ��
    char chEndTime[32];               ///< ����ִ��ʱ��
    bool bStartInTime;                ///< �Ƿ�涨׼��ִ��
    bool bEngInTime;                  ///< �Ƿ�ǿ��Ҫ���ֹʱ��
    bool bWarn;                       ///< �Ƿ����õ�������
    int nWarnMinu;                    ///< ����ǰX��������
    bool bTotalTime;                  ///< �Ƿ�涨����ִ��ʱ��
    int nToTalTime;                   ///< ִ��ʱ��
    int nTotalTimes;                  ///< ִ�д���
    bool bRuleTimes;                  ///< �Ƿ�ǿ��ֵ��Ա��ִ�в鿴��Ƶʱ�Ե����ƵԤ����Ļ��ΪѲ���Ҫ����
    int nRuleTimes;                   ///< ÿ������ÿ·��Ƶ���ٵ������
    char chInstructions[1024];        ///< ����ָ��
    bool bTaskLevel;                  ///< �Ƿ�涨��Ҫ�ȼ�
    int nTaskLevel;                   ///< �ȼ���ID
    bool bError;                      ///< �Ƿ�����쳣�ο�
    int nError;                       ///< �쳣��ID��û���쳣ʱ��0
    char chErrorLabel[128];           ///< �����ǩ
    char chUserName[64];              ///< ģ������û���
}P_NEW_INSPECT_TASKMODULESET;        

///< ����Ѳ������ִ�в���(220-int)
typedef struct
{
    int nTaskDistributeId;                ///< �����·�ID
    char chAreaName[64];                  ///< ������������
    int nDoError;                         ///< �쳣����ֵ
    bool bDoCarry;                        ///< �Ƿ�Ϊ��ע����Ѳ��
    char chBeginTime[32];                 ///< ��ʼѲ��ʱ��
    char chError[512];                    ///< �쳣$��
    char chOperate[512];                  ///< ����$��
    char chAnnex[2048];                   ///< ����
    char EPlanName[128];                  ///< Ԥ������
    bool bIsQualified;                    ///< �Ƿ�ϸ�
    char chReadRecord[8000];              ///< ���ļ�¼
    char chMemo[512];                     ///< ��ע
    char chActionNos[8000];               ///< ��������$��
    char chActionNames[8000];             ///< ����������$��
    char chHandleMans[8000];              ///< ������$��
    char chDoBeginTimes[8000];            ///< ��ʼ����ʱ��$��
    char chDoEndTimes[8000];              ///< ��������ʱ��$��
    char chAttachments[8000];             ///< ����$��
    char chDoSuccesses[8000];             ///< �Ƿ�ִ�гɹ�$��
    char chMemos_VarC[8000];              ///< ��ע$��
	char chTerminalIds[4000];			   ///<�ն�ID����$�ָ�
    char chChannelNos[2000];			   ///<ͨ��ID����$�ָ�
    char chBeginTimes[8000];			   ///<��ʼʱ�䣬��$�ָ�
    char chEndTimes[8000];				   ///<����ʱ�䣬��$�ָ�
}P_NEW_INSPECT_TASKEXCUTESET;

///< ����Ѳ�����ļ�¼���(221-int)
typedef struct
{
    int nTaskID;                  ///< ����Ѳ��ID
    char chTaskCheckTime[32];     ///< ��������ʱ��
    char chTaskCheckContent[512]; ///< ������������
    char chTaskCheckUser[64];     ///< �����������û���
}P_NEW_INSPECT_CHECKRECORDSET;       

///< ����Ѳ�������·�״̬�޸�(222-int)
typedef struct
{
    int nTaskID;                  ///< ����ID
    int nStatusType;              ///< ����״̬����
    char chRevokeUser[64];        ///< ���������û���
    char chTaskMemo[512];         ///< ��������ע
}P_NEW_INSPECT_TASKSTATUSMOD;

///< ����Ѳ���쳣��ϸ�״̬�޸�(223-int)
typedef struct
{
    int nTaskID;                  ///< ����Ѳ��ID
    bool bIsQualified;            ///< �Ƿ�ϸ�
}P_NEW_INSPECT_ISQUALIFIEDMOD;

///< ����Ѳ���쳣�����(224-int)
typedef struct
{
    int nTaskID;                  ///< ����ִ��ID
    bool bDoError;                ///< �Ƿ����쳣
    char chErrorNames[256];       ///< �쳣����$��
    char chOperate[128];          ///< ��������
    char chAnnex[2048];           ///< ����
    bool bIsSelfDefinite;         ///< �Ƿ��Զ���
    char chErrorTypeDefinite[256];///< �Զ����쳣����
    char chErrorOperateDefinite[512]; ///< �Զ��崦��ʽ
    bool bIsQualified;            ///< �Ƿ�ϸ�
    char chMemo[512];             ///< ��ע
}P_NEW_INSPECT_EXCUTEERRORSET;

///< ��ȡ��ǰֵ����Ա��Ϣ(225-out)
typedef struct
{
    int nUserID;                   ///< �û�ID
    char chName[64];               ///< �û���
    int nScheduleID;               ///< �Ű�ID
}S_NEW_INSPECT_CURDUTYPEOPLEINFO;

///< ��ȡ����������ϸ��Ϣ(226-int)
typedef struct
{
    int nCondition;                ///< ������0-ȫ����1-��������ID��2-�Զ���
    int nTaskID;                   ///< ����ID[nCondition = 1]
    int nStatus;                   ///< ����״̬��1-δ�·���2-���·�[nCondition = 2]
    char chTask[64];               ///< ��������[nCondition = 2]
    char chOppTask[32];            ///< �������[nCondition = 2]
    char chClass[32];              ///< �������[nCondition = 2]
    char chRole[32];               ///< ��ɫ����[nCondition = 2]
    char chOppObject[64];          ///< �������[nCondition = 2]
}P_NEW_INSPECT_SHOWALLTASKINFO;

///< ��ȡ����������ϸ��Ϣ(226-out) [nCondition = 0]
typedef struct
{
    int nTI_Id_Int;                           ///< ����ID
    char chTI_Name_VarC[64];                  ///< ��������
    char chOI_Name_VarC[32];                  ///< ������������
    char chCI_Name_VarC[32];                  ///< �������
    char chRI_RoleName_VarC[32];              ///< ��ɫ����
    char chTI_EffectiveBeginDate_Date[32];    ///< ��Ч�ڿ�ʼʱ��
    char chTI_EffectiveEndDate_Date[32];      ///< ��Ч�ڽ���ʱ��
    char chTI_StartTime_VarC[32];             ///< ��ʼʱ��
    char chTI_EndTime_VarC[32];               ///< ����ʱ��
    bool bTI_Warn_Bit;                        ///< �Ƿ񵽵�����
    char chTI_Status_Int[32];                 ///< ����״̬��δ�·���δ��ɣ����·���
    char chTI_Type_Int[32];                   ///< �������ͣ��ճ�����ͻ������
    char chOppObject[64];                     ///< ��������
}S_NEW_INSPECT_SHOWALLTASKINFO_ALL;

///< ��ȡ����������ϸ��Ϣ(226-out) [nCondition = 1]
typedef struct
{
    int nTI_Id_Int;                           ///< ����ID
    char chTI_Description_VarC[512];          ///< ��������
    int nTI_Operation_Int;                    ///< �����������
    int nTI_LoopMethod_Int;                   ///< ѭ������
    char chTI_LoopMemo_VarC[512];             ///< ѭ����ע
    bool bTI_DoTimeRange_Bit;                 ///< �Ƿ�涨����ʱ�䷶Χ
    bool bTI_StartInTime_Bit;                 ///< �Ƿ�涨׼ʱִ��
    bool bTI_EngInTime_Bit;                   ///< �Ƿ�ǿ��Ҫ���ֹʱ��
    int nTI_WarnMinu_Int;                     ///< ����ǰX��������
    bool bTI_TotalTime_Bit;                   ///< �Ƿ�涨����ִ��ʱ��
    int nTI_ToTalTime_Int;                    ///< ����ִ��ʱ��
    int nTI_TotalTimes_Int;                   ///< ִ�д���
    bool bTI_RuleTimes_Bit;                   ///< �Ƿ�ǿ��ֵ��Ա��ִ�в鿴��Ƶʱ�Ե����ƵԤ��ƵĻ��ΪѲ���Ҫ����
    int nTI_RuleTimes_Int;                    ///< ÿ������ÿ·��Ƶ���ٵ������
    char chTI_Instructions_VarC[1024];        ///< ����ָ��
    bool bTI_TaskLevel_Bit;                   ///< �Ƿ�涨������Ҫ�ȼ�
    int nTI_TaskLevel_Int;                    ///< ������Ҫ�ȼ����ȼ���ID��û�й涨��ʱ��Ϊ0
    bool bTI_Error_Bit;                       ///< �Ƿ��쳣�ο�
    int nTI_Error_Int;                        ///< �쳣��ID��û��ʱΪ0
    char chTI_ErrorLabel_VarC[128];           ///< �����ǩ
    int nTI_ClassId_Int;                      ///< ���ID
    char chTI_Name_VarC[64];                  ///< ��������
    int nOI_Id_Int;                           ///< ��������
    char chOI_Name_VarC[32];                  ///< ������������
    int nTOR_Object_Int;                      ///< ���ⳡ��Ϊ1�����峡��Ϊ2
    int nTOR_PlaceId_Int;                     ///< ����ID
    int nTOR_KeyPartId_Int;                   ///< ��λID
    char chCI_Name_VarC[32];                  ///< �������
    bool bCI_IsCrossDate_Bit;                 ///< �Ƿ����
    char chCI_StartTime_VarC[32];             ///< ��ο�ʼʱ��
    char chCI_EndTime_VarC[32];               ///< ��ν���ʱ��
    bool bWeek[7];                            ///< ���ڼ��Ƿ��ϰ�[����һ-0 ~ ������-6]
    int nRI_Id_Int;                           ///< ��ɫID
    char chRI_RoleName_VarC[32];              ///< ��ɫ����
    char chTI_EffectiveBeginDate_Date[32];    ///< ��Ч�ڿ�ʼʱ��
    char chTI_EffectiveEndDate_Date[32];      ///< ��Ч�ڽ���ʱ��
    char chTI_StartTime_VarC[32];             ///< ��ʼʱ��
    char chTI_EndTime_VarC[32];               ///< ����ʱ��
    bool bTI_Warn_Bit;                        ///< �Ƿ񵽵�����
    char chTI_Status_Int[32];                 ///< ����״̬��δ�·���δ��ɣ����·���
    char chTI_Type_Int[32];                   ///< �������ͣ��ճ�����ͻ������
    char chOppObject[64];                     ///< ��������[����]
    char chKeyPart[128];                      ///< �ؼ���λ
}S_NEW_INSPECT_SHOWALLTASKINFO;

///< ��ȡ�������������Ϣ(227-out)
typedef struct
{
    int nOperationId;           ///< ��������ID
    int nType;                  ///< 1-�鿴��Ƶ 2-�ط���Ƶ
    char chName[32];            ///< ������������
    char chMemo[128];           ///< ��ע
}S_NEW_INSPECT_TASKOPERATIONINFOSHOW;

///< ��ȡ������Ҫ�̶���Ϣ(228-out)
typedef struct
{
    int nTaskLevelId;           ///< �ȼ�ID
    int nType;                  ///< �ȼ����� 1-��ͨ 2-��Ҫ
    char chName[32];            ///< �ȼ�����
}S_NEW_INSPECT_TASKLEVELINFOSHOW;

///< ��ȡ����ģ����Ϣ(229-int)
typedef struct
{
    int nCondition;                ///< ������0-ȫ����1-��������ģ��ID
    int nTaskModuleID;             ///< ����ģ��ID
}P_NEW_INSPECT_TASKMODULEINFOSHOW;

///< ��ȡ����ģ����Ϣ(229-out)[nCondition == 0]
typedef struct
{
    int nTaskModuleID;             ///< ����ģ��ΨһID
    char chName[64];               ///< ����ģ������
    char chUserName[64];           ///< ģ������û���
    char chAddTime[32];            ///< ģ�����ʱ��
}S_NEW_INSPECT_TASKMODULEINFOSHOW_ALL;

///< ��ȡ����ģ����Ϣ(229-out)[nCondition == 1]
typedef struct
{
    int nTaskModuleID;             ///< ����ģ��ΨһID
    char chName[64];               ///< ����ģ������
    char chDescription[512];       ///< ��������
    int nOperation;                ///< ����������� 1-�鿴��Ƶ 2-¼��ط�
    int nLoopMethod;               ///< ѭ������ 1-ÿ�� 2-ÿ�� 3-ÿ��
    char chLoopMemo[512];          ///< ѭ������ע
    char chStartTime[32];          ///< ��ʼִ��ʱ��
    char chEndTime[32];            ///< ����ִ��ʱ��
    bool bDoTimeRange;             ///< �Ƿ�涨����ʱ�䷶Χ
    bool bStartInTime;             ///< �Ƿ�涨׼ʱִ��
    bool bEngInTime;               ///< �Ƿ�ǿ��Ҫ���ֹʱ��
    bool bWarn;                    ///< �Ƿ񵽵�����
    int nWarnMinu;                 ///< ����ǰX��������
    int nToTalTime;                ///< ����ִ��ʱ������λ�����ӣ�
    int nTotalTimes;               ///< ִ�д���
    bool bTotalTime;               ///< �Ƿ�涨����ִ��ʱ��
    bool bRuleTimes;               ///< �Ƿ�ǿ��ֵ��Ա��ִ�в鿴��Ƶʱ�Ե����ƵԤ��ƵĻ��ΪѲ���Ҫ����
    bool bTaskLevel;               ///< �Ƿ�涨������Ҫ�ȼ�
    bool bError;                   ///< �Ƿ��쳣�ο�
    int nRuleTimes;                ///< ÿ������ÿ·��Ƶ���ٵ������
    int nTaskLevel;                ///< ������Ҫ�ȼ����ȼ���ID��û�й涨��ʱ��Ϊ0
    char chTaskLevelName[32];      ///< ������Ҫ�ȼ�����
    int nError;                    ///< �쳣��ID��û��ʱΪ0
    char chErrorName[64];          ///< �쳣��������
    char chInstructions[1024];     ///< ����ָ��
    char chErrorLabel[128];        ///< �����ǩ
    char chUserName[64];           ///< ģ������û���
    char chAddTime[32];            ///< ģ�����ʱ��
}S_NEW_INSPECT_TASKMODULEINFOSHOW;

///< ��ȡ����ͨ����λ��Ϣ(230-out)
typedef struct
{ 
    unsigned int nDevId;          ///< �豸ID
    int nChannelId;               ///< ͨ��ID
    int nChannelNo;               ///< ͨ����
    char chKeyPartName[128];      ///< ��λ����
}S_NEW_INSPECT_CHANNELKEYPARTINFOSHOW;

///< ���ݽ�ɫ��ȡ��Ȩ����Ϣ(231-int)
typedef struct
{
    int nRoleID;                    ///< ��ɫID
    int nTypeInt;                   ///< Ȩ������[1-��ƵԤ����2-��Ƶ�ط�]
}P_NEW_INSPECT_ROLEDEVINFOSHOW;

///< ���ݽ�ɫ��ȡ��Ȩ����Ϣ(231-out)
typedef struct
{
    unsigned int nDevId;           ///< �豸ID
    unsigned int Purview[8];       ///< Ȩ��ֵ
}S_NEW_INSPECT_ROLEDEVINFOSHOW;

///< ���ݰ�λ�ȡ�����·���ɫ(232-int)
typedef struct
{
    char chClassName[32];         ///< �������
}P_NEW_INSPECT_TASKSENDROLEINFO;

///< ���ݰ�λ�ȡ�����·���ɫ(232-out)
typedef struct
{
    int nRoleId;                  ///< ��ɫID
    char chRoleName[64];          ///< ��ɫ����
}S_NEW_INSPECT_TASKSENDROLEINFO;

///< ��ȡ���������Ϣ(233-int)
typedef struct
{
    int nCondition;                ///< ������1-��ȡȫ��,2-����ĳ�����ɫ��ȡ,3-���ݽ�ɫ����ȡ
    int nOperation;                ///< ����������� 1-�鿴��Ƶ 2-¼��ط�
    char chRoleList[640];          ///< ����Ϊ2ʱ������ֵ��ɫ���ƣ���ɫ1����Ϊ3ʱ���ò�����ֵΪ��ɫ���ƴ�����ɫ1$��ɫ2$��
}P_NEW_INSPECT_TASKOBJECTINFO;

///< ��ȡ���������Ϣ(233-out)
typedef struct
{
    int nObjectId;                 ///< ���ⳡ��ID
    int nObjectType;               ///< ���ⳡ������
    char chObjectName[64];         ///< ���ⳡ������
    int nPlaceId;                  ///< ���峡��ID ����ѯ����Ϊ��ɫ��ʱ���������ȡ�����峡��
    char chPlaceName[64];          ///< ���峡������
}S_NEW_INSPECT_TASKOBJECTINFO;

///< �ϡ��°�ǩ������(234-int)
typedef struct
{
    int nCondition;                ///< ������1-�ϰ࣬2-�°�
    int nScheduleID;               ///< �Ű�ID
}P_NEW_INSPECT_CLASSCONFIRMSETINFO;

///< ��ȡĳ�û��Ľ�������(235-int)
typedef struct
{
    int nScheduleId;              ///< �Ű�ID
    int nTaskType;                ///< ��������[0-Ĭ��ȫ����1-��ͨ��2-����]
}P_NEW_INSPECT_TODAYTASKINFOSHOW;

///< ��ȡĳ�û��Ľ�������(235-out)
typedef struct
{
    int nTaskId;                  ///< ����ID
    char chTaskName[64];          ///< ��������
    int nTaskLevel;               ///< ������Ҫ�ȼ�
    float fPTask;                 ///< ���������
    char chStartTime[32];         ///< ��ʼִ��ʱ��
    char chEndTime[32];           ///< ����ִ��ʱ��
    bool bStartInTime;            ///< �Ƿ�涨׼ʱִ��
    bool bEngInTime;              ///< �Ƿ�ǿ��Ҫ���ֹʱ��
    bool bWarn;                   ///< �Ƿ񵽵�����
    int nWarnMinu;                ///< ����ǰX��������
    int nTaskNextID;              ///< �����·�ID
}S_NEW_INSPECT_TODAYTASKINFOSHOW;

///< ��ȡĳ���·������ִ����Ϣ(236-int)
typedef struct
{
    int nCondition;               ///< 0-��ȡĳ���·������ִ����Ϣ 1-��ȡ���������Ϣ 2-��ȡ����ִ�����
    int nTaskId;                  ///< �·�����ID
    int nScheduleID;              ///< �Ű�ID[nCondition = 2]
}P_NEW_INSPECT_TODAYTASKALLINFOSHOW;

///< ��ȡĳ���·������ִ����Ϣ(236-out)[nCondition = 0]
typedef struct
{
    char chTaskName[64];          ///< ��������
    char chInstructions[1024];    ///< ����ָ��
    bool bTotalTime;              ///< �Ƿ�涨����ִ��ʱ��
    bool bRuleTimes;              ///< �Ƿ�ǿ��ֵ��Ա��ִ�в鿴��Ƶʱ�Ե����ƵԤ��ƵĻ��ΪѲ���Ҫ����
    int nToTalTime;               ///< ����ִ��ʱ������λ�����ӣ�
    int nRuleTimes;               ///< ÿ������ÿ·��Ƶ���ٵ������
    char chErrorNameList[1024];   ///< �쳣��
}S_NEW_INSPECT_TODAYTASKALLINFOSHOW;

///< ��ȡĳ���·������ִ����Ϣ(236-out)[nCondition = 1]
typedef struct
{
    int nObjectId;                ///< �������
    char chObjectName[64];        ///< ��������
    int nKeyPartID;               ///< ��λID
    int nObject_Int;              ///< ��������
}S_NEW_INSPECT_TODAYTASKOBJECTINFOSHOW;

///< ��ȡĳ���·������ִ����Ϣ(236-out)[nCondition = 2]
typedef struct
{
    char chAreaName[64];          ///< ��������
    char chSubmitTime[32];        ///< �����ύʱ��
    bool bError;                  ///< �Ƿ��쳣
}S_NEW_INSPECT_TODAYTASKDOINFOSHOW;

///< ��ȡ�û���������(237-int)
typedef struct
{
    char chUserName[64];          ///< �û�����
    char chBeginTime[32];         ///< ��ѯ��ʼ����
    char chEndTime[32];           ///< ��ѯ��������
}P_NEW_INSPECT_USERTASKINFOSHOW;

///< ��ȡ�û���������(237-out)
typedef struct
{
    int nTaskId;                  ///< ������
    char chTaskName[64];          ///< ��������
    char chDateTime[32];          ///< ��������
}S_NEW_INSPECT_USERTASKINFOSHOW;

///< �����ѯ(238-in)
typedef struct
{
    char chUserName[64];          ///< �û�����
    char chTaskName[64];          ///< ��������
    char chRoleName[64];          ///< ��ɫ����
    int  nError;                  ///< �쳣����ֵ 0-���쳣��1-ִ��ʱ����̣�2-ִ�в�׼ʱ��3-Ѳ�����쳣
    int  nClassId;                ///< ���ID
    char chBeginDate[32];         ///< ��ѯ��ʼ����
    char chEndDate[32];           ///< ��ѯ��������(����ʱ����ò�Ҫ���ڵ�ǰ���ڣ�֮����������޽����)238
}P_NEW_INSPECT_CHECKTASKINFOSHOW;

///< �����ѯ(238,294-out)
typedef struct
{
    int nTaskId;                  ///< ������
    char chTaskName[64];          ///< ��������
    char chRoleName[64];          ///< ��ɫ��
    char chUserName[64];          ///< �û�����
    char chTaskLevel[32];         ///< ����ȼ�
    int nErrorType;               ///< �쳣���ͱ�ţ�0-���쳣��1-ִ��ʱ����̣�2-ִ�в�׼ʱ��3-Ѳ�����쳣��
	int nProperty;                ///< ����״̬��0-������1-������
}S_NEW_INSPECT_CHECKTASKINFOSHOW;

///< ���񸴺���Ϣ(239-int)
typedef struct
{
    int nTaskId;                ///< ����ִ��ID
}P_NEW_INSPECT_SHOWTASKCHECKINFO;


///<��ȡ����ִ�й���ͨ������Ϣ��239-out��
typedef struct _TaskExecute_Relate_Show
{
	char chTerminalIds[4000];			   ///<�ն�ID����$�ָ�
	char chChannelNos[2000];			   ///<ͨ��ID����$�ָ�
	char chBeginTimes[8000];			   ///<��ʼʱ�䣬��$�ָ�
	char chEndTimes[8000];				   ///<����ʱ�䣬��$�ָ�
}TaskExecuteRelate_S;

///< ���񸴺���Ϣ(239-out)
typedef struct
{
    int nTaskId;                ///< ����ִ��ID
    int nDoError;               ///< �����쳣
    int nProperty;              ///< �Ƿ�������
    char chBeginTime[32];       ///< ��ʼִ��ʱ��
    char chEndTime[32];         ///< ����ִ��ʱ��
    char chAreaName[64];        ///< ��������
    char chAddress[128];        ///< �����ַ
    char chContactMan[256];     ///< ��ϵ��
    char chContactInfo[256];    ///< ��ϵ����ϵ��ʽ
    char chErrors[512];         ///< �쳣��$��
    char chUserName[32];        ///< ����ִ�����û�����
    char chRoleName[32];        ///< ����ִ���˽�ɫ����
    char chFindPSWQ[64];        ///< ����ִ������ϵ��ʽ
    char chHeadPortrait[512];   ///< ͷ��
    char chOperates[512];       ///< ����$��
    char chMemo[512];           ///< ��ע
    char chAnnex[2048];         ///< ����
    char chReadRecord[8000];    ///< ���ļ�¼
    char chEPlanName[128];      ///< Ԥ������
    bool bDoCarry;              ///< �Ƿ񱻹�ע
    bool bIsQualified;          ///< �Ƿ�ϸ�
	TaskExecuteRelate_S T_TaskRelate;    ///<���������Ϣ
	int nLockProperty;		    ///< ��״̬��0-������1-������
	
}S_NEW_INSPECT_SHOWTASKCHECKINFO;

///< �������Ԥ����Ϣ(240-int)
typedef struct
{
    int nTaskId;                  ///< ������
}P_NEW_INSPECT_SHOWTASKEPLANINFO;

///< �������Ԥ����Ϣ(240-out)
typedef struct
{
    int nTaskId;                  ///< ������
    int nActionNo;                ///< �������
    int nSequece;                 ///< ���
    char chActionName[64];        ///< ������
    char chBeginTime[32];         ///< ��ʼʱ��
    char chEndTime[32];           ///< ����ʱ��
    char chHandleMan[64];         ///< ������
    char chAttachment[1024];      ///< ����
    char chMemo[512];             ///< ��ע
    bool bDoSuccess;              ///< �Ƿ�ɹ�
}S_NEW_INSPECT_SHOWTASKEPLANINFO;

///< ĳ���������쳣������(241-int)
typedef struct
{
    int nCondition;               ///< 0-ȫ�� 1-����ID 2-��������
    int nAreaId;                  ///< ����ID
    char chAreaName[64];          ///< ��������
}P_NEW_INSPECT_SHOWAREAERRORINFO;

///< ĳ���������쳣������(241-out)
typedef struct
{
    int nAreaId;                  ///< ����ID
    int nErrorNum;                ///< �쳣��������
    char chAreaName[64];          ///< ��������
    char chErrorName[64];         ///< �쳣����
}S_NEW_INSPECT_SHOWAREAERRORINFO;

///< ������쳣��(242-int)
typedef struct
{
    int nCondition;               ///< 0-ȫ�� 1-����ID 2-��������
    int nAreaId;                  ///< ����ID
    char chAreaName[64];          ///< ��������
}P_NEW_INSPECT_SHOWAREAERRORATEINFO;

///< ������쳣��(242-out)
typedef struct
{
    int nAreaId;                  ///< ����ID
    int nErrorNum;                ///< �쳣��������
    int nTotalNum;                ///< Ѳ���ܴ���
    char chAreaName[64];          ///< ��������
    float fErrorRate;             ///< �쳣��
}S_NEW_INSPECT_SHOWAREAERRORATEINFO;

///< Ѳ�츲����(243-int)
typedef struct
{
    int nDay;                     ///< N��
}P_NEW_INSPECT_SHOWCOVERRATEINFO;

///< Ѳ�츲����(243-out)
typedef struct
{
    int nTaskId;                  ///< ������
    float fCoverRate;             ///< ������
}S_NEW_INSPECT_SHOWCOVERRATEINFO;

///< ��λʱ���ڵ������쳣����ͳ��(244-int)
///< nCondition:
///< 1--TOP ����
///< 2--���㵥λʱ���ڲ������쳣�����,ÿ����������
///< 3--ĳһ�����ʱ��ηֲ�
typedef struct
{
    int nCondition;               ///< ����
    char chBeginTime[32];         ///< ��ʼʱ�� [3:ʱ���]
    char chEndTime[32];           ///< ����ʱ�� [3:ʱ���]
    char chAreaName[64];          ///< ��������[2,3]
    int nDay;                     ///< N��[3]
}P_NEW_INSPECT_SHOWAREAERRORNUMINFO;

///< ��λʱ���ڵ������쳣����ͳ��(244-out)
typedef struct
{
    int nAreaId;                  ///< ����ID
    int nErrorNum;                ///< �쳣��������
    char chAreaName[64];          ///< ��������
    char chErrorName[64];         ///< �쳣����[2,3]
    char chBeginTime[32];         ///< ��ʼʱ��[3]
}S_NEW_INSPECT_SHOWAREAERRORNUMINFO;

///< �쳣�ĸ���ϸ���(245-out)
typedef struct
{
    char chUserName[64];          ///< �û���
    int nExcuteNum;               ///< �ϸ����
    int nTotalNum;                ///< ִ���ܴ���
    float fRate;                  ///< �ϸ���
}S_NEW_INSPECT_SHOWERRORCHECKRATEINFO;

///< ����(246-int)
typedef struct
{
    int nScheduleID;               ///< �Ű�ID
}P_NEW_INSPECT_SHOWALARMRECORINFO;

///< ����(246-out)
typedef struct
{
    char chSuggestion[1024];      ///< ����
}S_NEW_INSPECT_SHOWALARMRECORINFO;

///< �豸���͡�Ʒ�ơ��ͺ���Ϣ��ѯ(247-int)
typedef struct
{
    int nCondition;               ///< ����
    char chType[32];              ///< ����
    char chManufa[32];            ///< Ʒ��
}P_NEW_SHOW_JH_DEVICEINFO;

///< �豸���͡�Ʒ�ơ��ͺ���Ϣ��ѯ(247-out)
typedef struct
{
    char chName[128];              ///< ����
}S_NEW_SHOW_JH_DEVICEINFO;

///< �豸������Ϣ��ѯ(248-int)
typedef struct
{
    int nCondition;               ///< ����
    char chStart[32];             ///< ��ʼʱ��
    char chEnd[32];               ///< ����ʱ��
    char chType[32];              ///< ����
    char chManufa[32];            ///< Ʒ��
    char chModelNo[128];          ///< �ͺ�
    int nStart;                   ///< ��ʼ����
    int nEnd;                     ///< ��������
}P_NEW_CHECK_JH_DEVICEINFO;

///< �豸������Ϣ��ѯ(248-out)
typedef struct
{
    char chCode[64];              ///< ���
    char chName[64];              ///< ����
    char chManufa[32];            ///< Ʒ��
    char chModelNo[128];          ///< �ͺ�
    char chIP[32];                ///< IP��ַ
    char chTime[32];              ///< �������
    int nCount;                   ///< ������[nCondition =1]
}S_NEW_CHECK_JH_DEVICEINFO;

///< �豸������Ϣͳ��(249-int)
typedef struct
{
    int nCondition;               ///< ����
    char chStart[32];             ///< ��ʼʱ��
    char chEnd[32];               ///< ����ʱ��
}P_NEW_STATICS_JH_DEVICEINFO;

///< �豸������Ϣͳ��(249-out)
typedef struct
{
    char chName[128];              ///< ����
    int nCount;                    ///< ����
}S_NEW_STATICS_JH_DEVICEINFO;

///<����������Ϣ���ۺϲ�ѯ(251-in)
typedef struct
{
    int nPage;                     ///< ҳ��
    int nCount_Page;               ///< ÿҳ��ʾ��¼����
    char chBeginTime[32];          ///< ��ʼʱ��
    char chEndTime[32];            ///< ����ʱ��
    char chAreaNames[2048];        ///< �ص��Ŵ�
    char chAlarmTypes[1024];       ///< �������ʹ�
    char chAlarmlevels[32];        ///< �����ȼ���
    char chHandleMan[32];          ///< ������
    char chProcessType[32];        ///< ��������
    int nProcessStates;            ///< ����״̬
}P_NEW_JH_COMPLEXCHECK;

///<����������Ϣ���ۺϲ�ѯ(251,295-out)
typedef struct
{
    char chAlarmTypeName[64];      ///< ������������
    char chAlarmSource[64];        ///< ����Դ
    int nAlarmSourceType;          ///< ����Դ���ͣ�0-������1-����ͷ
    char chAlarmArea[64];          ///< �����ص�
    int nSumCount;                 ///< �ܼ�¼����
    int nSumPage;                  ///< ��ҳ��
    char chBeginTime[32];          ///< ������־��ʼʱ�䣨2012-01-01 00:00:00��
    char chBeginDay[32];           ///< ������־��ʼ���ڣ�2012-01-01��
    char chBeginMonth[32];         ///< ������־��ʼ�·ݣ�2012-01��
    int nAlarmTypeID;              ///< ������ϢID
    int nProcessState;             ///< ����״̬
    char chProcessUser_VarC[64];   ///< ������
    char chProcessDate_Date[32];   ///< ��������
    char chProcessType[32];        ///< ��������
    char chProcessMemo_VarC[512];  ///< ��ע
    int nAlarmLevel;               ///< �����ȼ�
    char chPalnName[64];           ///< ��ӦԤ��
    char chProcessBeginTime[32];   ///< ����ʼʱ��
    char chProcessEndTime[32];     ///< �������ʱ��
    char chMemo[128];              ///< ��ע��Ϣ[���������š�����ʱ����Ϣ]
    char chKeyPart[128];           ///< ��λ��Ϣ
	int nProperty;                 ///< ����״̬��0-������1-������
	char chGUID[128];			   ///< ����GUID
}S_NEW_JH_COMPLEXCHECK;

///< ��ѯ���ݿ������ַ���(252-out)
typedef struct
{
    char chIp[20];         ///< IP��ַ
    char chUser[32];       ///< �û���
    char chPassword[32];   ///< ����
    char chDatabase[32];   ///< ���ݿ���
    int nPort;             ///< ���Ӷ˿�
}S_NEW_JH_DATABASEINFO;

///< ���������ͳ����Ϣ(253-int)
/** nCondition:
*   1: ������������������
*   2: ������ʱ��������ÿ����������
*   3: ѡ��ĳһ��ɫ����ʾ�ý�ɫ����������������
*   4: ѡ��ĳһ��κ���ʾ�ð������������������
*   5: ĳһ����������Ҫ�ȼ�����
*   6: ĳһ��������������ͻ���
*   7: ĳһ������������ʱ�θ���
*   8: ĳһ����������Ҫ�ȼ�����
*   9: ĳһ��������������ͻ���
**/
typedef struct
{
    int nCondition;        ///< ����
    char chName[64];       ///< ����ֵ
    char chStart[32];      ///< ��ʼʱ��
    char chEnd[32];        ///< ����ʱ��
}P_NEW_INSPECT_STATICS_TASKADDINFO;

///< ���������ͳ����Ϣ(253-out)
typedef struct
{
    char chName[64];       ///< ����ֵ
    union
    {
        int nNum;          ///< ����
        char chTime[10];   ///< ʱ��(nCondition == 7)
    }Data;
}S_NEW_INSPECT_STATICS_TASKADDINFO;

///< Ա������������ͳ����Ϣ(254-int)
typedef struct
{
    char chName[64];       ///< �û���
}P_NEW_INSPECT_STATICS_EMPLOYANALY;

///< Ա������������ͳ����Ϣ(254-out)
typedef struct
{
    float fTaskExecuteRate;       ///< ���������
    float fQualifiedRate;         ///< Ѳ���쳣�ϸ���
    float fStandardRate;          ///< Ѳ��淶��
    float fEPlanRate;             ///< Ԥ����������
    float fHighLevelAlarmRate;    ///< �ߵȼ�������������
}S_NEW_INSPECT_STATICS_EMPLOYANALY;

///< Ա��������ͳ����Ϣ(255-int)
/** nCondition:
*   1: ִ������ȼ�
*   2: ����Ѳ���쳣���ϸ�ʱ��ηֲ�����
*   3: �������ȼ�
**/
typedef struct
{
    int nCondition;        ///< ����
    char chName[64];       ///< ����ֵ
}P_NEW_INSPECT_STATICS_EMPLOYMANAGER;

///< Ա��������ͳ����Ϣ(255-out)
typedef struct
{
    int nLevelOrTimes;     ///< �ȼ�ֵor����
    union
    {
        int nNum;          ///< ����
        float fExRate;     ///< �쳣��(nCondition == 2)
    }Data;
}S_NEW_INSPECT_STATICS_EMPLOYMANAGER;

///< �û�IP������(256-int)
typedef struct
{
    char chAllow[4096];    ///< ��Ч��Χ
    char chBan[4096];      ///< ��Ч��Χ
}P_NEW_IP_POOL_SET;

///< �û�IP����Ϣ��ȡ(257-out)
typedef struct
{
    char chStart[20];      ///< ��ʼIP
    char chEnd[20];        ///< ����IP
    bool bAllow;           ///< ��Ч/��Ч��Χ
}S_NEW_IP_POOL_SHOW;

///< ������Ч��(258-int,259-out)
typedef struct
{
    int nID;              ///< ID����
    int nDays;            ///< ������Ч��(����Ϊ��λ)
}S_NEW_USEFULPSW_INFO;

///< ��������ȡ�û�������Ϣ(260)[MD5-int]
typedef struct
{
    int nCondition;       ///< 0-Ĭ��ȫ����1-�ض��û�
    char chName[64];      ///< �ض��û���
}P_NEW_USERPSWINFO_SHOW;

///< ��������ȡ�û�������Ϣ(260)[MD5-out)
typedef struct
{
    char chUsername[64];          ///< �û���
    char chPassword[64];          ///< �û�����
    int  nPrity;                  ///< �û��ȼ�
    TJTY_TIME TValiadStartTime;   ///< ��Ч�ڿ�ʼʱ��
    TJTY_TIME TValiadEndTime;     ///< ��Ч�ڽ���ʱ��
    TJTY_TIME TValiadPswStart;    ///< �û����뿪��ʱ��
    bool bUseful;                 ///< �û�����/����״̬
}S_NEW_USERPSWINFO_SHOW;

///< ��Ч�������ͻ�ȡ(261-out)
typedef struct
{
    int nAlarmTypeID;             ///< ��������ID
    char chAlarmType[64];         ///< ������������
}S_NEW_ALARMDISPOSAL_USEFULTYPE;

///< ��Ч������λ��Ϣ��ȡ(262-out)
typedef struct
{
    int nPlaceID;                 ///< ����ID
    char chPlace[64];             ///< ��������
    int nKeyPartID;               ///< ��λID
    char chKeyPart[64];           ///< ��λ����
}S_NEW_ALARMDISPOSAL_USEFULPLACEKEY;

///< �����û�����ȡ��������Ȩ��(263-int)
/* ģ���ʶ
* 1 - �Ű�ģ��
* 2 - �ճ�Ѳ��ģ��
* 3 - ��������ģ��
* 4 - ��������֤ģ��
* 5 - ������άģ��
*/
typedef struct
{
    char chName[64];      ///< �ض��û���
    char chModule[32];    ///< ģ�鴮����1,2,3
}P_NEW_ALARMDISPOSAL_AUTH_SHOW;

///< �����û�����ȡ��������Ȩ��(263-out)
/* Ȩ�ޱ��
* 1 - �Ű�Ȩ�� [�Ű�ģ��]
* 2 - ������Ȩ�� [�Ű�ģ��]
* 3 - ���񸴺�Ȩ�� [�ճ�Ѳ��ģ��]
* 4 - ֵ�೤���Ӱ�Ȩ�� [�ճ�Ѳ��ģ��]
* 5 - �����Ű�Ȩ�� [�Ű�ģ��]
* 6 - ���񸴺�Ȩ�� [��������ģ��]
* 7 - �������Ȩ�� [��������ģ��]
* 8 - ���顢�ȼ��޸�Ȩ�� [��������ģ��]
* 9 - ����Ȩ�� [��������ģ��]
* 10 - ��Ա��ɾ�� [��������֤ģ��]
* 11 - ¼����� [��������֤ģ��]
* 12 - ��֤���� [��������֤ģ��]
* 13 - ���Ȩ�� [��������֤ģ��]
* 14 - ��¼��ѯ [��������֤ģ��]
* 15 - ��ͨʹ��Ȩ�� [������άģ��]
* 16 - �豸��Ϣ����Ȩ�� [������άģ��]
*/
typedef struct
{
    bool bModuleAuth[128];          ///< ����Ȩ��
}S_NEW_ALARMDISPOSAL_AUTH_SHOW;

///< ��ȡ�����ȼ����ò���(264-out)
/* �����Ȩ������ֵ
* 1 - ����ر�
* 2 - ȫ������
* 3 - �˹���Ԥ
* 4 - �ӳٴ���
* 5 - ��ʱ����
* 6 - ���õȴ�
* 7 - �����չ���ַ�
* 8 - Ԥ������
* 9 - ����ִ��

* 10 - �ϼ�����
*/
typedef struct
{
    int nALId;             ///< ��������ID
    int nAlarmLevel;       ///< ��������ֵ
    char chAlarmLevel[64]; ///< ����������
    int nAMId;             ///< Ȩ��ID
    int nMethodId;         ///< Ȩ��ֵ
    char chMethodName[32]; ///< Ȩ����
    int nRelatedUserId;    ///< �û�ID
    char chUserName[64];   ///< �û���
    int nEPlanId;          ///< Ԥ��ID
    char chPlanName[64];   ///< Ԥ����
    int nConfigTime;       ///< ����ʱ��ֵ
}S_NEW_ALARMDISPOSAL_PLOY_SHOW;

///< ����ֵ��Ա״̬(265-int)
/*  �û�״̬
* 1 - ����
* 2 - ����������
* 3 - Ѳ����
* 4 - ����
*/
typedef struct
{
    int nUserID;         ///< �û�ID
    char chName[64];     ///< �û���
    int nStatus;         ///< �û�״̬
}P_NEW_ALARMDISPOSAL_DUTYSTATUS_SET;

///< ���ñ�����Ϣ����״̬(266-int)
/* ����״̬
* 1 - δ����
* 2 - ������
* 3 - �ӳٴ���
* 4 - ��ͣ����
* 5 - ������
* 6 - �Ѵ���
* 7 - �Ѷ���
*/
typedef struct
{
    int nAlarmInfoId;              ///< ������ϢID
    char chAlarmSource[128];       ///< ����Դ
    int nSourceType;               ///< ����Դ���� 1-������2-����ͷ
    char chAlarmType[128];         ///< ��������
    char chAlarmDateTime[32];      ///< ��������ʱ��(yyyy-mm-dd hh:mm::ss)
    int nStatus;                   ///< ����״̬
}P_NEW_ALARMDISPOSAL_STATUS_SET;

///< ���ñ�����Ϣ������(267-int)
typedef struct
{
    int nCondition;                ///< ����1-add,2-mod(�ñ����Ƿ��Ѵ��ù�)
    int nAlarmInfoId;              ///< ������ϢID
    char chAlarmSource[128];       ///< ����Դ
    int nSourceType;               ///< ����Դ���� 1-������2-����ͷ
    char chAlarmType[128];         ///< ��������
    char chAlarmDateTime[32];      ///< ��������ʱ��(yyyy-mm-dd hh:mm::ss)
    char chHandleMan[64];          ///< ������
    char chActPerson[64];          ///< ԭ������
}P_NEW_ALARMDISPOSAL_PEOPLE_SET;

///< �ύ�������ý��(268-int)
typedef struct
{
    int nAlarmID;                  ///< ������ϢID
    char chAlarmGUID[64];          ///< ������ˮ��
    char chAlarmSource[128];       ///< ����Դ
    int nSourceType;               ///< ����Դ���� 0-������1-����ͷ
    char chAlarmType[128];         ///< ��������
    char chAlarmDateTime[32];      ///< ��������ʱ��(yyyy-mm-dd hh:mm::ss)
    int nAlarmLevel;               ///< ��������
    char chKeyPart[128];           ///< �ؼ���λ
    int nProcessType;              ///< ����ʽ
    char chMemo[512];              ///< ��ע
    int nEPlanType;                ///< Ԥ������(1-��ͨԤ����2-�¼�)
    char chPlanName[128];          ///< Ԥ����
    char chHandleMan[128];         ///< ������
    char chAttachment[1024];       ///< ��������
    bool bDoFinish;                ///< �Ƿ������
    char chActionNos[1000];        ///< Ԥ������ID��
    char chActionNames[2048];      ///< Ԥ���������ִ�
    char chDoBeginTimes[2048];     ///< Ԥ�����迪ʼʱ�䴮
    char chDoEndTimes[2048];       ///< Ԥ���������ʱ�䴮
    char chAttachments[8000];      ///< Ԥ�����踽����
    char chDoSuccesses[800];       ///< Ԥ�����账�����ƴ���ַ���
    char chDoMans[2048];           ///< Ԥ�����账���˴�
    char chDoMemos[8000];          ///< Ԥ�����账��������
    char chMustBeDones[8000];      ///< Ԥ�������Ƿ����ִ�д�
    char chAlarmCategory[32];      ///< ��������
    char chCheckStatus[32];        ///< ���Դ�
}P_NEW_ALARMDISPOSAL_DEALSULT_SET;

///< ��ȡ�û�����״̬(269-int)
/* nCondition:
* 0 - ��ȡ�����û�״̬
* 1 - ��ȡ���п����û�
* 2 - �����û�������ȡ�û�״̬
*/
typedef struct
{
    int nCondition;                ///< ����
    char chUsers[3072];            ///< �û�������: 'use1','user2'
}P_NEW_ALARMDISPOSAL_USERSTATUS_SHOW;

///< ��ȡ�û�����״̬(269-out)
typedef struct
{
    char chName[64];              ///< �û�
    int nStatus;                  ///< �û�״̬
}S_NEW_ALARMDISPOSAL_USERSTATUS_SHOW;

///< �����ȼ���������(270-int)
typedef struct
{
    int nLevelVaule;             ///< ������������ֵ
    char chMethodIds[1024];      ///< Ȩ������ֵ��$
    char chUserIds[1024];        ///< �û�ID��$
    char chConfigTimes[1024];    ///< ����ʱ�䴮$
    char chEPlanIds[1024];       ///< Ԥ��ID��$
}P_NEW_ALARMDISPOSAL_ALM_SET;

///< ��ȡ�û��ܴ���ı����ȼ�(271-int)
/* nCondition:
* 0 - ȫ��
* 1 - �ض��û�
*/
typedef struct
{
    int nCondition;              ///< ����
    char chName[64];             ///< �ض��û���
}P_NEW_ALARMDISPOSAL_USERAL_SHOW;

///< ��ȡ�û��ܴ���ı����ȼ�(271-out)
typedef struct
{
    char chName[64];             ///< �ض��û���
    char chLevels[64];           ///< ������������ֵ��$
}S_NEW_ALARMDISPOSAL_USERAL_SHOW;

///< �������͡����Դ���Ϣ����(272-int)(add��mod��del)
typedef struct
{
    int nCondition;              ///< ����: 1,2,3-���飬4,5,6-���Դ�
    int nTypeID;                 ///< ΨһID
    char chName[32];             ///< ����
    int nTypeValue;              ///< ����ֵ
}P_NEW_ALARMDISPOSAL_ACATEGORY_SET;

///< �������͡����Դ���Ϣ��ȡ(273-int)
typedef struct
{
    int nCondition;              ///< ����: 1-���飬2-���Դ�
}P_NEW_ALARMDISPOSAL_ACATEGORY_SHOW;

///< �������͡����Դ���Ϣ��ȡ(273-out)
typedef struct
{
    int nTypeID;                 ///< ΨһID
    char chName[32];             ///< ����
    int nTypeValue;              ///< ����ֵ
}S_NEW_ALARMDISPOSAL_ACATEGORY_SHOW;

///< ģ��Ȩ����Ϣ��ȡ(274-int)
typedef struct
{
    int nCondition;             ///< ����: 0-���У�1-���ݾ����ģ�顢Ȩ�ޣ�2-�����ȼ�Ȩ�޿���Ϣ
    char chModules[64];         ///< ģ��: 1,2,3
    char chAuths[128];          ///< Ȩ�ޣ�1,2,3,4
}P_NEW_ALARMDISPOSAL_MODULEANTH_SHOW;

///< ģ��Ȩ����Ϣ��ȡ(274-out)
typedef struct
{
    char chAuth[32];            ///< Ȩ����
    int nAuthValue;             ///< Ȩ��ֵ
    char chModule[32];          ///< ����ģ��
}S_NEW_ALARMDISPOSAL_MODULEANTH_SHOW;

///< ���ݱ����ȼ���ȡ����Ȩ����Ϣ(275-int)
typedef struct
{
    int nCondition;             ///< ����: 0-���ݵȼ�ID��1-���ݵȼ�ֵ��2-���ݵȼ�����
    int nID;                    ///< �ȼ�ID
    int nLevel;                 ///< �ȼ�ֵ
    char chName[64];            ///< �ȼ���
}P_NEW_ALARMDISPOSAL_AMA_SHOW;

///< ���ݱ����ȼ���ȡ����Ȩ����Ϣ(275-out)
typedef struct
{
    bool bAuths[32];           ///< Ȩ����Ϣ
    int nTimeOut;              ///< ��ʱʱ��
    int nUserID;               ///< �û�ID
    char chUserName[64];       ///< �ϱ���
    int nPlanID;               ///< Ԥ��ID
    char chPlanName[64];       ///< Ԥ����
    int nReverseTime;          ///< ����ʱ
    int nDelayTime;            ///< ¼����ʱ
}S_NEW_ALARMDISPOSAL_AMA_SHOW;

///< �˹���Ԥ��������(276-int)
typedef struct
{
    int nDeviceID;             ///< �豸ID
    int nChannelNo;            ///< ͨ����
    int nAID;                  ///< ��������ID
    int nLevel;                ///< �����ȼ�ֵ
    int nStstus;               ///< ����״̬
    char chMemo[128];          ///< ��ע
    char chName[64];           ///< ������
    TJTY_TIME tTime;           ///< ����ʱ��
}P_NEW_ALARMDISPOSAL_ASSINGLE_SET;

///< ��������(277��278��279��280-int)
typedef struct
{
    int nAlramID;             ///< ������ϢID
    char chName[64];          ///< ����
}P_NEW_ALARMDISPOSAL_ASMO_SHOW;

///< ĳ�û�δ������ɵı�����Ϣ(277-out)
typedef struct
{
    int nAlramID;             ///< ������ϢID
    char chAlramDate[32];     ///< ��������ʱ��
    char chAlramSource[64];   ///< ����Դ
    char chAlramType[64];     ///< ��������
    int nAlarmLevel;          ///< �����ȼ�
    char chAlramArea[64];     ///< ��������
    char chName[64];          ///< ������
    int nStstus;              ///< ����״̬
    char chDateTime[32];      ///< ����ʱ��
    char chKeyPart[128];      ///< ��λ��Ϣ
	char chGUID[128];	      ///< ����GUID
}S_NEW_ALARMDISPOSAL_ASINFO_SHOW;

///< ��ȡ�����û�������Ϣ(278-out)
typedef struct
{
    int nUserID;              ///< �û�ID
    char chName[64];          ///< ����
}S_NEW_ALARMDISPOSAL_ANEXT_SHOW;

///< ���ݱ���ID��ȡ������ע��¼��Ϣ(279-out)
typedef struct
{
    char chName[64];          ///< �û�����
    char chDateTime[32];      ///< ��עʱ��
    char chMemo[128];         ///< ��ע��Ϣ
}S_NEW_ALARMDISPOSAL_AM_SHOW;

///< ���ݱ���ID��ȡ������¼��Ϣ(280-out)
typedef struct
{
    char chName[64];          ///< �����û�
    char chOpType[64];        ///< ��������
    char chMemo[128];         ///< ��¼��Ϣ
    char chDateTime[32];      ///< ����ʱ��
}S_NEW_ALARMDISPOSAL_AO_SHOW;

///< ������ļ�¼(281-int)
typedef struct
{
    int nAlramID;             ///< ����ID
    char chName[64];          ///< �û�
    char chMemo[512];         ///< ��ע
    char chDate[32];          ///< ʱ��
}P_NEW_ALARMDISPOSAL_CRM_SET;

///< ��������(282-int)
typedef struct
{
    int nAlramID;               ///< ����ID
    char chAlarmLevel[64];      ///< �����ȼ�
    char chAlarmCategory[32];   ///< ��������
    char chCheckStatus[32];     ///< ����״̬
    char chIsQualified[64];     ///< ���Դ�
    char chCheckMan[64];        ///< ������
    char chCheckDate[32];       ///< ����ʱ��
}P_NEW_ALARMDISPOSAL_AC_SET;

///< ����������־����(283-int)
typedef struct
{
    int nAlarmId;              ///< ����ID
    char chActType[64];        ///< ��������
    char chActMemo[1024];      ///< ������ע
    char chActPerson[64];      ///< ������
    char chActDate[32];        ///< ����ʱ��
}P_NEW_ALARMDISPOSAL_ACI_SET;

///< ������ʱ���ô洢(284-int)
typedef struct
{
    int nAlramID;             ///< ����ID
    char chAlramSource[64];   ///< ����Դ
    char chAlramType[64];     ///< ��������
    char chAlramArea[64];     ///< ��������
    int nStstus;              ///< ����״̬
    char chDateTime[32];      ///< ����ʱ��
    char chName[64];          ///< ������
}P_NEW_ALARMDISPOSAL_AD_SET;

typedef struct
{
    char chOldName[128];  ///<ԭ����������
    char chNewName[128];  ///<�´���������
    char chProperty[128]; ///<���޸ĵ�״ֵ̬ ��$ƴ����$����

}TAG_NEW_ALARMDISPOSAL_BATCHSET_P, *PTAG_NEW_ALARMDISPOSAL_BATCHSET_P;

///<���������û���Ϣ��288-out��
typedef struct
{
    char chUserName[64];     ///<�û���
    char chHeadImage[64];    ///<ͷ��
    char chWorkNum[16];      ///<����
    char chId[64];           ///<���֤��
    char charDepartmentName[20];           ///<����
    int  nUserType;                        ///<�û�����
    char chBeginDate[32];                  ///<��Ա��Ч�ڿ�ʼʱ��
    char chEndDate[32];                    ///<��Ա��Ч�ڽ���ʱ��
    char chCardNum[16];                    ///<����
    char chCardBeginDate[32];              ///<����Ч�ڿ�ʼʱ��
    char chCardEndDate[32];                ///<����Ч�ڽ���ʱ�� 
}TAGASUSERADD_P, *PTAGASUSERADD_P;

///<��ȡ�û���Ϣ��289-out��
typedef struct
{
    char chUserName[64];                   ///<�û���
    char chHeadImage[64];                  ///<ͷ��
    char chWorkNum[16];                    ///<����
    char chId[64];                         ///<���֤��
    char charDepartmentName[20];           ///<����
    int  nUserType;                        ///<�û�����
    char chBeginDate[32];                  ///<����Ч�ڿ�ʼʱ��
    char chEndDate[32];                    ///<����Ч�ڽ���ʱ��
    char chCardNum[16];                    ///<����
}TAGASUSERGET_S, *PTAGASUSERGET_S;

///<��ʾ�ܿصȼ���Ϣ(400-out)
typedef struct
{
    int nLevelId;          ///< �ȼ�ID
    int nLevelValue;       ///< �ȼ�ֵ
    char chLevelName[64];  ///< �ȼ�����
}S_NEW_SHOWCTRLLEVEL;

///<�ܿصȼ��޸ģ�401-in��
typedef struct
{
    int nCondition;           ///< ����: 1-add,2-mod,3-del
    int nValue;               ///< �ܿؼ���ֵ
    char chName[128];         ///< �ܿؼ�����
}P_NEW_OPCTRLLEVELINFO;

///<�ܿصȼ����֣�402-out��
typedef struct
{
    char chLevelName[128];     ///<�ȼ�����
    char chPlaceName[64];      ///<��������
    char chKeyPartName[128];   ///<��λ����
    char chDeviceName[64];     ///<�豸����
}S_NEW_CTRLLEVELINFO;

///<ˢ������(403)
typedef struct
{
    int nApplyId;                    ///<��������ID
    char chDeviceName[64];           ///<�Ž�����
    char chAccessDate[32];           ///<ˢ��ʱ��
}TAGOPENDOOR_P, *PTAGOPENDOOR_P;

///<������֤Ԥ����Ϣ (404)
typedef struct
{
    int nId;                        ///<��������ID
    char chActionNos[8000];         ///<�������
    char chActionNames[8000];       ///<��������
    char chHandleMans[8000];        ///<������
    char chDoBeginTimes[8000];      ///< ��ʼ����ʱ��
    char chDoEndTimes[8000];        ///< ��������ʱ��
    char chAttachments[8000];       ///< ����
    char chDoSuccesses[8000];       ///< �Ƿ�ִ�гɹ�
    char chMustBeDones[8000];       ///< �Ƿ����ִ��
    char chMemos[8000];             ///< �������ݵ���Ϣ
}TAGOPENDOORPLANINFO_P, *PTAGOPENDOORPLANINFO_P;

///<���÷�ʽ (405)
typedef struct
{
    int nId;                           ///<��������ID
    int nMethod;                       ///<���÷�ʽֵ -1-δ����  0-����1-������Ȩ 2-Ӧ������  3-�������� 4-�ܾ�����
}TAGDOOROPENAPPLY_METHOD_P, *PTAGDOOROPENAPPLY_METHOD_P;

///<��֤״̬ (406)
typedef struct
{
    int nId;                ///<��������ID
    int nProcessStatus;       ///< ��֤״ֵ̬ 1-δ����2-������ 3-�����4-�Ѵ���5-��ʧЧ
    char chHandleDate[20];             ///<����ʱ��
}TAGDOA_PROCESSSTATUS_P, *PTAGDOA_PROCESSSTATUS_P;

///<����������� (407)
typedef struct
{
    int nId;                             ///<��������ID
    int nProcessType;                    ///<���״̬	1-ͨ�� 2-�ܾ�
    int nProcessStatus;                  ///<��֤״ֵ̬ 1-δ�� 2-������ 3-����� 4-�Ѵ��� 5-��ʧЧ
    int nPassStatus;                     ///< ͨ�����	1-ͬ�⿪�� 2-�ܾ�����
    char chAuditor[128];                 ///<���������
    char chAuditDate[20];                  ///<���ʱ��
}TAGDOA_AUDITOR_P, *PTAGDOA_AUDITOR_P;

///<���������ղ�(408)
typedef struct
{
    int nId;                            ///<��������ID
    int nIsCollection;                  ///<�Ƿ��ղ� 1-�ղ� 0-��
}TAGDOA_ISCOLLECTION_P, *PTAGDOA_ISCOLLECTION_P;

///<����������Ϣ(409-in)
typedef struct
{
    char chDeviceName[64];              ///<�豸����
    char chAreaName[64];                ///<������������
    char chKeyPart[128];                ///<��λ����
    char chContactPerson[128];          ///<��ϵ������
    char chHappenDate[32];              ///<����ʱ��
    char chContactInfo[16];             ///<��ϵ��ʽ
    int nMethod;                        ///<���÷�ʽ
    char chPlanName[128];               ///<Ԥ������
    int nProcessType;                   ///<���״̬	1-ͨ�� 2-�ܾ�
    int nProcessStatus;                 ///<��֤״ֵ̬ 1-δ�� 2-������ 3-����� 4-�Ѵ��� 5-��ʧЧ
    int nIsCollection;                  ///<�Ƿ��ղ� 1-�ղ� 0-��
    int nPassStatus;                    ///<ͨ�����	1-ͬ�⿪�� 2-�ܾ�����
    int nIsNormal;                      ///<�Ƿ���������
    char chHandleMan[128];              ///<������
    char chApplyType[512];              ///<��֤ģʽ
}TAGDOA_INFO_P, *PTAGDOA_INFO_P;

///<����������Ϣ���أ�409,612-out��
 typedef struct
{
    char chReturn[256];        ///< ִ����ɾ�ķ���ֵ(Ĭ��"1"Ϊִ�гɹ�����֮Ϊ�쳣�ִ�) ʵ���������������ʱ�����guid���൱��һ��userdata
    int  nId;
}TAGDOA_INFO_S;

///<�û���֤(410)
typedef struct
{
    char chUserName[64];                 ///<�û���
    char chPassword[256];                ///<����
    int nDoShow;                         ///<�������Ƿ���ʾ 1-��ʾ 0-��
}TAGDOA_USERINFO_P, *PTAGDOA_USERINFO_P;

///<��֤������־��(411)
typedef struct
{
    int nId;                            ///<��������ID
    int nActType;                       ///<��������ֵ
    char chActName[64];                 ///<��������
    char chAttachment[1024];            ///<����
}TAGDOA_ATTACHMENT_P, *PTAGDOA_ATTACHMENT_P;

///<��֤ϵͳ��־ (412)
typedef struct
{
    int nId;                            ///<��������ID
    char chActType[64];                 ///<��������
    char chActDate[32];                 ///<����ʱ��
    char chActPerson[64];               ///<������
}TAGDOA_APPLYACTLOG_P, *PTAGDOA_APPLYACTLOG_P;

///<��֤�������(413)
typedef struct
{
    int nId;                              ///<��������ID
    char chContent[256];                 ///<�������
    char chProcessDate[32];              ///<����ʱ��
    char chProcessMan[64];               ///<������
}TAGDOA_PROCESSMEMO_P, *PTAGDOA_PROCESSMEMO_P;

///<ˢ����Ϣ(414)
typedef struct
{
    int nStatus;                         ///<ˢ��״̬ 	1-�Ϸ�2-���Ϸ�3-��Ч��
    int nId;                             ///<�豸ID
    char chCardNum[16];                  ///<����
    char chPersonId[32];                 ///<���֤��
    char chAccessDate[32];               ///<ˢ��ʱ��
}TAGDOA_LOG_P, *PTAGDOA_LOG_P;

///<���(415)
typedef struct
{
    char chDeviceName[64];            ///<�豸����
    char chDate[10];                 ///<�Ű�����
    char chBeginDate[32];            ///<��ʼʱ��
    char chEndDate[32];              ///<����ʱ��
    char chIds[1000];                ///<�Ű���ԱID�� $ƴ��
}TAGDOA_CLASSSCHEDULE_P, *PTAGDOA_CLASSSCHEDULE_P;

///<(416-in)
typedef struct
{
    char chUserName[64];            ///<�û�����
}TAGDOAPPASSWORD_P;

///<(416-0ut)
typedef struct
{
    int nUserId;                     ///<�û�ID
    char chUserName[64];             ///<�û�����
    char chPassword[256];            ///<����
    bool bDoShow;                    ///<�Ƿ���ʾ������
}TAGDOAPPASSWORD_S;

///<(420-0ut)
typedef struct  
{
    char chUserName[64];             ///<�û�����
    char chHeadImage[64];            ///<ͷ��
    char chId[64];                   ///<���֤
    char chWorkNum[16];              ///<����
    int  nDepartmentId;              ///<���ű��
    int  nUserType;                  ///<״̬\���� 1-�ڲ� 2-�ⲿ  
	char chCardNum[64];				///<����
    char chDepartmentName[64];		///<��������
    char chUserType[32];			///<�û�����
    char chBeginTime[20];			///<���ÿ�ʼʱ��
    char chEndTime[20];				///<���ý���ʱ��
    char chSex[10];					///<�Ա�
    int nStatus;					///<��Ա״̬
    int nId;						///<��ԱID
	
}TAGDOAPERSONINFO_S;

///<(417-0ut)
typedef struct
{
    int nID;                    ///< �豸ID
    char chDevCode[64];         ///< �豸����
    char chDevName[128];        ///< �豸����
    char chDevIp[32];           ///< �豸IP��ַ
    char chAreaCode[64];        ///< �����������
    int nDeviceType;            ///< �豸����(9��11��14)
    int nDevTypeID;             ///< �豸����ID��Ʒ��ID��
    char chDevModelNo[128];     ///< �豸�ͺ�
    char chDevManufacture[64];  ///< Ʒ������
    int nDevManufatureID;       ///< Ʒ�Ʊ��
    char chCenterNo[128];       ///< ���ı��
    char chFatherCenterNo[128]; ///< �����ı��
    int nDevTypeCode;           ///< �豸���ͱ�ţ�2*n��
    int nKeyPart;               ///< ��λ
    BOOL bCanSpreak;            ///<�ܷ�Խ�  ����������֤���������ж��Ƿ�����Ȩ�豸��
    BOOL bIsConnect;            ///<�Ƿ���Ҫ���� ����������֤���������ж��Ƿ�����֤�豸��
}TAGDOAACCESSINFO_S;   
 
///<��ѯ��֤��ʷ��Ϣ(422-in)
typedef struct
{
    char chBeginDate[32];            ///<��֤����ʱ��  ��ʼ
    char chEndDate[32];              ///<��֤ʱ�����
    char chAreaName[64];             ///<��������
    int  nPassStatus;                ///<ͨ��״̬0-ȫ�� 1-ͬ�⿪�� 2-�ܾ�����
    int  nProcessStatus;             ///<����״̬0-ȫ�� 1-δ���� 2-������ 3-�����
    int  nIsCollection;              ///<�Ƿ��ղ� 0-ȫ�� 1-�ղ� 2-δ�ղ�
    int  nIsNomal;                   ///<¼�뷽ʽ 0-ȫ�� 1-����¼�� 2-������¼��
    int  nMethod;                    ///<����ģʽ 0-ȫ��
    int  nProcessType;               ///<���״̬ 0-ȫ�� 1-ͨ��(�ϸ�) 2-�ܾ�(���ϸ�)
    int  nPages;                     ///<ҳ��
    int  nRecords;                   ///<ÿҳ��ʾ��¼��
}TAGDOAHISTORYINFO_P;

///<��ѯ��֤��ʷ��Ϣ(422,296-out)
typedef struct
{
    int  nId;                        ///<��֤Id
    char chAreaName[64];             ///<��������
    char chDeviceName[64];           ///<�Ž�����
    char chHappenDate[32];           ///<��֤����ʱ��
    int  nMethod;                    ///<����ʽ
    int  nProcessStatus;             ///<����״̬ 1-δ���� 2-������ 3-�����
    int  nProcessType;               ///<���״̬ 1-ͨ��(�ϸ�) 2-�ܾ�(���ϸ�)
    int  nPassStatus;                ///<ͨ��״̬1-ͬ�⿪�� 2-�ܾ�����
    char chHandleMan[128];           ///<������
    char chHandleDate[20];           ///<����ʱ��
    char chAuditor[128];             ///<�����
    char chAuditDate[20];            ///<���ʱ��
    bool bIsCollection;              ///<�Ƿ��ղ�
    bool bIsNormal;                  ///<�Ƿ�����¼��
    char chApplyType[128];           ///<��֤ģʽ
	int nProperty;                 ///< ����״̬��0-������1-������
    int  nSumPage;                   ///<��ҳ��
}TAGDOAHISTORYINFO_S;

///<��ѯ��֤��ʷ��ϸ��Ϣ-��֤����(423-out)
typedef struct
{
    int  nId;                            ///<��֤Id
    char chDeviceName[64];               ///<�Ž�����
    char chHappenDate[32];               ///<��֤����ʱ��
    char chAreaName[64];                 ///<��������
    char chKeyPart[128];                 ///<��λ����
    char chContactPerson[128];           ///<��ϵ������
    char chContactInfo[16];              ///<��ϵ��ʽ
    char chHandleMan[128];               ///<������
    char chRoleName[64];
    char chPSWQ[50];                     ///<�ֻ�
    char chPSWA[50];                     ///<����
    char chHandleDate[20];               ///<����ʱ��
    char chAuditor[128];                 ///<�����
    char chAuditDate[20];                ///<���ʱ��
    char chPlanName[64];
    bool bIsCollection;                  ///<�Ƿ��ղ�
    bool bIsNormal;                      ///<�Ƿ�����¼��
    char chApplyType[128];               ///< ��֤ģʽ
    int  nMethod;                        ///<����ʽ
    int  nProcessStatus;                ///<��֤״̬
    int  nProcessType_Int;              ///<���״̬
    int  nPassStatus_Int;               ///<ͨ�����
	int nProperty;				        ///< ��״̬��0-������1-������
}TAGDOAAPPLYDETAIL_S;

 ///<��ѯ��֤��ʷ��ϸ��Ϣ-�����б�(424-out)
typedef struct
{
    int nApplyId;                       ///<����ID
    int nActType;                       ///<��������ֵ
    char chActName[64];                 ///<������������
    char chAttachment[1024];            ///<����
}TAGDOAATTACHMENT_S;

///<��ѯ��֤��ʷ��ϸ��Ϣ-Ԥ��������Ϣ(425-in)
typedef struct
{
    int nApplyId;                       ///<����ID
    int nActionNo;                      ///<�������
    int nSequence;                      ///<����˳��
    char chActName[128];                ///<������������
    char chHandleMan[128];              ///<������
    char chDoBeginTime[32];
    char chDoEndTime[32];
    char chAttachment[1024];            ///<����
    bool bDoSuccess;                    ///<�Ƿ�ִ�гɹ� 0-���ɹ�1-�ɹ�
    bool bMustBeDone;                   ///<�Ƿ����ִ�� 1-�� 0-��
    char chMemo[512];                   ///<��ע����������
    int  nProporty;                     ///<���α����ֶ�
    char chProporty[128];               ///<�ַ��ͱ����ֶ�
    char chLastModify_Date[32];         ///<����޸�ʱ��
}TAGDOAACTIONDETAIL_S;

///<��ѯ��֤��ʷ��ϸ��Ϣ-��֤��������б�(426-out)
typedef struct
{
    int nApplyId;                       ///<����ID
    char chContent[256];                ///<�������
    char chProcessDate[32];             ///<����ʱ��
    char chProcessMan[64];              ///<������
}TAGDOAPROCESSMEMO_S;

///<��ѯ��֤��ʷ��ϸ��Ϣ-��֤��������б�(427-out)
typedef struct
{
    int nApplyId;                       ///<����ID
    char chActType[64];                 ///<��������
    char chActDate[32];                 ///<����ʱ��
    char chActPerson[64];               ///<ִ����
}TAGDOAACTLOG_S;

///<��ѯ��֤��ʷ��ϸ��Ϣ-��֤����ˢ����Ϣ�б�(428-in)
typedef struct
{
    int nId;                        ///<����ID
}TAGDOADOORACCESSLOG_P;

///<��ѯ��֤��ʷ��ϸ��Ϣ-��֤����ˢ����Ϣ�б�(428-out)
typedef struct
{
    int nApplyId;                        ///<����ID
    char chDeviceName[64];               ///<�Ž�����
    char chAreaName[64];                 ///<��������
    char chKeyPart[128];                 ///<��λ����
    char chCardNum[16];                  ///<����
    char chName[128];                    ///<����
    char chId[64];
    int  nUserType;                      ///<
    int  nStatus;                        ///<Ȩ��״̬ 1-�ϸ� 2-���ϸ� 
    char chType[64];                     ///<����
    char chWorkNum[16];                  ///<����
    char chDepartment[32];               ///<����
    char chAccessDate[32];               ///<ˢ��ʱ��
    ///<char chPersonId[32];               ///<���֤��
    char chMemo[512];                    ///<¼��ԭ��
}TAGDOADOORACCESSLOG_S;

 ///<��ѯˢ����ʷ��Ϣ(429-in)
 typedef struct
 {
     char chBeginTime[32];       ///<��ʼʱ��
     char chEndTime[32];         ///<����ʱ��
     char chAreaName[64];        ///<��������
     char chCompanyName[64];     ///<��λ����
     int  nStatus;               ///<Ȩ��״̬0-ȫ�� 1-�ϸ� 2-���ϸ� 3-��Ч
     char chWorkNum[16];         ///<����
     char chPersonId[32];        ///<���֤��
     int  nPages;                ///<ҳ��
     int  nRecords;              ///<ÿҳ��ʾ��¼��
     char chName[32];            ///<ˢ��������
 }TAGDOABYCARDINFO_P;

 ///<��ѯˢ����ʷ��Ϣ(429-out)
 typedef struct
 {
     char chName[32];                     ///<ˢ��������
     int  nUserType;                      ///<
     int  nStatus;                        ///<Ȩ��״̬ 1-�ϸ� 2-���ϸ�
     char chType[64];                     ///<����
     char chPersonId[32];                 ///<���֤��
     char chWorkNum[16];                  ///<����
     char chDepartment[32];               ///<��λ
     char chKeyPart[128];                 ///<��λ����
     char chAccessDate[32];               ///<ˢ��ʱ��
     char chAreaName[64];                 ///<��������
     char chMemo[512];                    ///<¼��ԭ��
     int  nSumPage;                       ///<��ҳ��
     int  nApplyId;                       ///<��֤ID
 }TAGDOABYCARDINFO_S;

///<��ѯͳ����Ϣ(430-in)
 typedef struct
 {
     int  nStatisticsType;              ///<ͳ������
     char chBeginTime[32];              ///<��ʼʱ��
     char chEndTime[32];                ///<����ʱ��
     char chAreaName[80000];            ///<��������  ��ѡ�ڵ�һ�������������� ��$ƴ��
     char chDepartment[64];             ///<��λ����
     char chPassStatus[8000];           ///<ͨ��״̬     ͨ��״ֵ̬$��
     char chProcessStatus[8000];        ///<����״̬     ����״ֵ̬$��
     char chHandleMan[8000];            ///<������       ��������$��
     int  nGraphType;                   ///<ͼ������ 1-����ͼ/��״ͼ 2-��״ͼ
 }TAGDOASTATISTICS_P;

 ///<��ѯͳ����Ϣ(430-out)
 typedef struct
 {
     char chStatisticsTime[32];       ///< ʱ��
     char chStatisticsItem[128];      ///<ͳ����
     int  nNum;                       ///<����
 }TAGDOASTATISTICS_S;

 ///<�쳣������Ϣ����(431-in)
 typedef struct
 {
     char chDeviceName[64];     ///<�豸����
     char chAreaName[64];       ///<��������
     char chKeyPart[128];       ///<�ؼ���λ����
     char chCardNum[16];        ///<����
     char chName[128];          ///<����
     char chId[64];             ///<���֤��
     int  nUserType;            ///< ����
     char chType[64];           ///<����
     int nStatus;               ///<Ȩ��
     char chWorkNum[16];        ///<����
     char chDepartment[32];     ///<����
     char chAccessDate[32];     ///<ˢ��ʱ��
     char chMemo[512];          ///<¼��ԭ��
 }TAGDOAEXCEPINFO_P;

 ///<(432-out)
 typedef struct
{
    char chReturn[256];        ///< ִ����ɾ�ķ���ֵ(Ĭ��"1"Ϊִ�гɹ�����֮Ϊ�쳣�ִ�)
    int  nId;
}TAGDOAEXCEPINFO_S;

///<�Ž��豸���ӹ�����432-in��
 typedef struct
{
    char chDeviceCode[64];      ///< ���Ž����
    char chDeviceName[50];      ///< ���Ž�����
}TAGDOACCESSRELATIONSET_S;

///<�Ž��豸���ӹ�����433-out��
 typedef struct
{
    int nMasterAccessId;      ///< ���Ž�ID
	char chMasterName[50];	  ///< ���Ž�����
    int nSlaveAccessId;       ///< ���Ž�ID
	char chSlaveName[50];	  ///< ���Ž�����
}TAGDOACCESSRELATION_S;

///<��ȡ�ܿصȼ�����(434-out)
typedef struct
{
    int nLevelId;            ///<�ܿصȼ�id
    int nLevelType;          ///<�ܿصȼ�����ֵ
    char chLevelName[128];   ///<�ܿصȼ�����
    int nPlanId;             ///<�ܿز���id
    int nPlanType;           ///<�ܿز�������ֵ
    char chPlanName[64];     ///<�ܿز�����������
    int  nMethodId;          ///<�ܿز��Բ���ֵ
    char chMethodName[64];   ///<�ܿز��Բ�������
    int nSetItem1;            ///<������������1
    int nSetItem2;            ///<������������2
    int nSetItem3;            ///<������������3
    char chSetItem4[128];     ///<���������ַ���1
    char chSetItem5[128];     ///<���������ַ���2
}TAGCTRLEVELPLAN_S;

///<��ȡ������Ϣ��435-out��
typedef struct
{
   int nId;                           ///<����ID
   char chDepartMentName[20];         ///<��������
}TAGDOADEPARTMENTINFO_S;

///<����������(438-out)
typedef struct
{
    int  nTypeId;             ///< ��������ID
    char chTypeName[64];      ///< ������������
    int  nMethodId;           ///< ����ID
    char chMethodName[64];    ///< ��������
}TAGDOAPLANPROJECT_S;

///<��ѯ�ܿز�����Ϣ(439-int)
typedef struct
{
    int nCondition;                ///< ����: 0-ȫ��,1-���ݵȼ�,2-���ݳ�������λ
    char chLevelName[32];          ///< �ܿؼ�����
    char chPlace[64];              ///< ��������
    char chKeyPart[64];            ///< �ؼ���λ����
}P_NEW_SHOWMULCTRLLEVEL;

///<�ܿز�����Ϣ-�豸�Ĺܿصȼ�������Ϣ(439-out)
typedef struct
{
    int  nCtrlLevelNum;           ///< �ܿؼ�������
    char chLevelName[32];         ///< �ܿؼ�����
    char chPlaceName[64];         ///< ��������
    char chKeyPartName[64];       ///< ��λ����
    char chDeviceName[64];        ///< �豸����
    int  nLC_ID;                  ///< ��¼���
}S_NEW_SHOWMULCTRLLEVEL;

///<��ȡ����������������Ϣ(440-In)
typedef struct
{
    int  nId;                 ///<�ܿصȼ�ID
}TAGDOAPLANPROJECTCONFIG_P;

///<��ȡ����������������Ϣ(440-out)
typedef struct
{
    int  nCtrlLevelId;        ///<�ܿصȼ�ID
    int  nLevel;              ///<�ܿصȼ�����ֵ
    char chLevelName[128];    ///<�ܿصȼ�����
    int  nControlStrategyId;  ///<�ܿز���ID
    int  nTypeId;             ///<��������ID
    char chTypeName[64];      ///<������������
    int  nMethodId;           ///<����ID
    char chMethodName[64];    ///<��������
    int  nSetItem1;           ///<����1
    int  nSetItem2;           ///<����2
    int  nSetItem3;           ///<����3
    char chSetItem4[128];     ///<����4
    char chSetItem5[128];     ///<����5
}TAGDOAPLANPROJECTCONFIG_S;

///<���ò���������������Ϣ(441-in)
typedef struct
{
    int  nCtrlLevelId;                ///<�ܿصȼ�ID
    char chControlStrategyId[100];    ///<����ID�� ��$ƴ��
    char chSetItem1[1000];            ///<����1
    char chSetItem2[1000];            ///<����2
    char chSetItem3[1000];            ///<����3
    char chSetItem4[2000];            ///<����4  Ԥ������
}TAGDOAPLANPROJECT_P;

///<��ȡIP�Խ��豸��Ϣ(442-out)
typedef struct
{
    int nId;
    char chDeviceName[128];
    char chDeviceCode[128];
}TAGDOAIPTALKINFO_S;

///<��ȡIP�Խ��豸��Ϣ(443-in)
typedef struct
{
    char chDeviceCode[128];
}TAGDOAIPTALKPANELINFO_P;

///<��ȡIP�Խ��豸��Ϣ(443-out)
typedef struct
{
    int nId;
    char chFrontendName[128];
}TAGDOAIPTALKPANELINFO_S;

///<�Ž��Խ���������(444-in)
typedef struct
{
    char chDeviceCode[64];
    char chFrontendName[50];
}TAGDOAIPTALKACCESS_P;

///<�Ž��Խ�������ȡ��445-in��
typedef struct
{
    int nDevId; ///<�Ž�ID
}TAGDOAIPTALKACCESSGET_P;

///<�Ž��Խ�������ȡ��445-out��
typedef struct
{
    char chDeviceName[20];
    char chFrontendName[50];
}TAGDOAIPTALKACCESSGET_S;

///<�ܿصȼ��������ã�446-in��
typedef struct
{
    int  nContion;                     ///<������1-��� 2-ɾ��
    char chLevelName[128];             ///<�ܿصȼ�����
    char chPlaceNames[1000];           ///<�������ƴ�
    char chKeyPartNames[1000];         ///<��λ���ƴ�
}TAGDOACTRLLEVELSET_P;

///<��ȡBSAPP�汾��Ϣ��447-out��
typedef struct
{
    int nField1;      	///<�汾�ֶ�1
	int nField2;		///<�汾�ֶ�2
	int nField3;		///<�汾�ֶ�3
	int nField4;		///<�汾�ֶ�4
}BSAPPVERSIONGET_S;

///<���ÿͻ����Ž����ӹ�ϵ��ȡ��448-in��
typedef struct
{
    int nMasterId;                  ///<���Ž��ɣ�
}TAGDOQASSESSMSSCS_P;

///<���ÿͻ����Ž����ӹ�ϵ��ȡ��448-out��
typedef struct
{
    char chDeviceName[50];         ///<���Ž�����
}TAGDOQASSESSMSSCS_S;

///<��ȡλ����Ϣ�����ÿͻ����Ҽ�ʹ�ã�290-out��
typedef struct
{
    int nKeyPartID;				//��λID
	int nKeyPartValue;			//��λֵ
	char chKeyPartName[50];		//��λ����
}POSITIONINFOGET_S_NEW;


///<�ʲ���Ϣ��ز��������ӡ��޸ġ������޸ģ�500-in��
typedef struct
{
	int nCondition;					///<����		 @note   1-���ӣ�2-�޸ģ�3-�����޸�
	char chDeviceCode[64];			///<�豸����   @note   ԭ����豸ʱ���ɵı��룬condition=2,3ʱ����
	int nDeviceType;				///<�豸���� 	 @note   1-����;2-�����,condition=2,3ʱ����
	char chCapitalCode[8000];		///<�ʲ����   @note  ���ͻ��˴��룩,�����޸�ʱ��$����,һ�����ɴ���100����Ϣ
	char chSN[64];					///<SN��     @note   �����ã��ɿգ�
	char chManufactureName[128];	///<Ʒ��		 @note   �豸��Ʒ����Ϣ
	char chModelNo[128];			///<�ͺ�		 @note   �豸�ľ����ͺ�
	char chSupplierName[128];		///<��Ӧ��	 @note   �豸�Ĺ�Ӧ��
	char chSTName[128];				///<������	 @note   ʩ����λ
	char chMaintenceName[128];		///<ά����	 @note   �豸��ά����˾
	int nMaintenceMonth;			///<ά������	 @note   ά����ʱ��������Ϊ��λ
	char chMaintenceTele[32];		///<ά���绰   @note   ά����˾��ϵ�˵绰
	char chStorageDate[20];			///<���ʱ��   @note   �豸���ʱ�䣬ֻ��������
	int nStatus;					///<�ʲ�״̬   @note   1-����ʹ�ã�2-ά���У�3-����  (�����޸�ʱ����)
 
}CAPITALINFOOPERATION_P;

	
///<Ѳ��ģ��ƻ����ã�501-in��
typedef struct
{
	int nModelType;				///<ģ�����ͺ�  @note   �ͻ������ж��壬��Ӧ����  ����������״̬��ʱ��״̬��Ӳ��״̬��ͨ��״̬
	char chBeginTime[10];		///<��ʼʱ��    @note   ���������� ���磺12:13:59
	char chEndTime[10];			///<����ʱ��	  @note   ����������
	int nCycle;					///<����ֵ     @note   ����1-100��
	int nCycleType;				///<��������    @note   1-ʱ��2-��
	char chSchedule[128];	    ///<��������    @note   ÿ�죬ÿ��
	int nCheckDays;				///<���ֵ	  @note   ¼�������Լ��ʹ�ã�ֵ��Χ1-365
	bool bIsEnable;			    ///<�Ƿ�����    @note   �Ƿ���Ч
 
}DETECTSCHEDULESET_P;


///<���ϱ�����Ϣ���루502-in��
typedef struct
{
	char chMalfunctionCode[64];   	///<���ϵ���    
	char chCapitalCode[64];			///<�ʲ����    @note  �豸���ʲ���Ϣ���
	char chDeviceType[64];			///<�豸����    @note  �豸�����ͣ��������������
	char chManufactureName[128];	///<Ʒ��		  @note   �豸��Ʒ��
	char chModelNo[128];			///<�ͺ�		  @note   �豸�ľ����ͺ�
	char chFirstLevel[64];			///<����       @note   �豸����������
	char chSecondLevel[256];		///<֧��       @note   �豸������֧�У�������к�����֮���ж������$ƴ��
	char chThirdLevel[128];			///<����       @note   �豸����������
	char chMaintenceName[128];		///<ά����     @note    �豸��ά����λ
	char chMaintenceTele[32];		///<ά���绰    @note   �豸ά����λ����ϵ�绰
	char chFaultType[128];			///<��������    @note   �豸�Ĺ������ͣ�������ߣ�Ӳ���𻵵�
	char chFaultNames[1024];		///<��������    @note   ����������Ƶ�źŵ�
	char chDescribe[512];			///<����       @note   �Թ�������ľ�������
	int nStatus;					///<����״̬    @note   1-���޸���2-ά���У�3-���ϣ�
	char chHandleDate[20];			///<����ʱ��    @note   ��¼���޵�ʱ��
	char chHandleMan[64];			///<������      @note   ��¼���޵���
 
}MALFUNCTIONINSERT_P;


///<����ά�޼�¼��503-in��
typedef struct
{
	int nMalfunctionId;			///<���޵�ID    @note  ���ϼ�¼ID
	char chMaintenceDate[20];		///<ά��ʱ��     @note  ʵ��ά��ʱ��
	char chMemo[512];				///<��ע        
	int nStatus;				///<ά��״̬     @note  1-���޸���2-ά���У�3-���ϣ�
	char chRecordMan[64];			///<��¼��      @note   ��Ӽ�¼����
 
}MAINTENCEINFOINSERT_P;


///<��ά��������ز���������ɾ���ģ�504-in��
typedef struct
{
	int nCondition;			    ///<��������         @note  1-���룻2-�޸ģ�3-ɾ����
	char chOMServerCode[30];	///<��ά���������    @note  ��ά�������ı��
	char chName[64];			///<����������	   @note   ��ά����������
	char chPassword[64];		///<����            @note   ��¼��ά������������
	char chIP[32];				///<IP��ַ          @note   ��ά������ip��ַ
	char chMemo[512];			///<��ע  
	char chUserName[64];		///<Conficlient
}OMSERVEROPERATION_P;


///<Ѳ��ģ�����ã����룬�޸ģ�505-in��
typedef struct
{
	int nCondition;				///<����			@note   1-���룻2-�޸ģ�3-ɾ��
	int nModuleId;				///<ģ��ID		@note   Ѳ��ģ��ID�����ݿ����ɣ�ɾ��ʱʹ��
	char chModuleName[128];		///<ģ������		@note   Ѳ��ģ�������
	char chWeekdays[128];		///<����ƴ���ַ�������$�ָ�		@note  ����ƴ���ַ�������$�ָ�磺����һ$���ڶ�
	bool bIsEnable;			    ///<�Ƿ�����
	char chCreateMan[64];		///<������
	char chCreateDate[20];		///<��������
	char chTypes[8000];			///<ʱ��������ַ�����1-������2-����		@note  ʱ��������ַ�����1-������2-����  �磺1$2$
	char chSequences[8000];		///<ʱ���˳��		@note  ʱ��ΰ�˳��ƴ�ӵ��ַ���  �磺00:00:00-23:59:59$
	char chBeginTimes[8000];	///<��ʼʱ�䴮����$ƴ��   @note  ��ʼʱ�䴮����$ƴ��
	char chEndTimes[8000];		///<����ʱ�䴮����$ƴ��   @note  ����ʱ�䴮����$ƴ��
	char chTerminalIds[8000];	///<����ID������$ƴ��    @note  ����ID������$ƴ��
	char chPartitionses[8000];	///<����������$ƴ�ӣ�Ŀǰ��Ϊ��    @note  ����������$ƴ�ӣ�Ŀǰ��Ϊ��
	char chUserName[128];		///<Configclient
}DETECTMODULEOPERATION_P;


///<ͨ�����ģ����ز���:��ӣ��޸ģ�506-in��
typedef struct
{
	int nCondition;				///<����               @note  1-��ӣ�2-�޸ģ�3-ɾ��
	int nModuleId;				///<ͨ��Ѳ��ģ��ID		  @note  ͨ��Ѳ��ģ��ID,���ݿ����ɣ�ɾ��ʱʹ��
	char chModuleName[128];		///<ͨ��Ѳ��ģ������     @note   ͨ��Ѳ��ģ������
	int nDays;					///<Ӧ�洢������		  @note  ҪѲ���ͨ������Ҫ�洢������
	char chCreateMan[64];		///<������
	char chCreateDate[20];		///<��������
	char chFrontendIds[8000];	///<ͨ��ID������$ƴ��    @note  ҪѲ���ͨ��ID������$ƴ��
	char chUserName[128];
}CHANNELDETECTMODULEOPERATION_P;


///<��ά���������֣�507-in��
typedef struct
{
	int nCondition;					///<������1-����������ã�2-׷��
	char chOMServerName[64];		///<��ά����������    @note  ��ά����������
	char chDeviceNames[8000];		///<�豸���ƴ�����$ƴ��   @note  �豸���ƴ�����$ƴ��,ÿ�β������ܳ���100̨
	char chUserName[128];
}OMSERVERDIVIDESET_P;


///<����������ز�����508-in��
typedef struct
{
	int nCondition;				///<����           @note  1-���ӣ�2-�޸ģ�3-ɾ��;
	int nFaultInfoId;			///<��������ID	  @note  ��������ID,���ݿ����ɣ�ɾ��ʱʹ��
	char chFaultName[128];		///<������������	  @note  ������������
	int nFaultType;				///<��������ֵ      @note  ��������ֵ 
	char chSetMan[128];			///<������         @note  ��������������
	char chSetDate[20];			///<����ʱ��       @note  ������������ʱ��
	bool bIsEnable;				///<�Ƿ�����
	char chUserName[128];
}FAULTINFOOPERATION_P;

///<��ȡ�豸Ʒ����Ϣ��ֻ�����ʲ���Ϣ�д��ڵģ�(544-in)
typedef struct
{
	int nCondition;				///<������    @note  nCondition=3,��ȡ�ʲ���Ϣ�д��ڵ��豸�ͺ�
}DEVICEMANUFACTUREINFOINCAPITALGET_S;
	
///<��ȡ�豸Ʒ����Ϣ(509-out��544-out)
typedef struct
{
	char chManufactureName[128];  ///<Ʒ������    @note  �豸Ʒ������
}DEVICEMANUFACTUREINFOGET_S;

///<��ȡ�ͺ���Ϣ(510-in)
typedef struct
{
	int nCondition;					///<����   @note 0-��ѯ���У�1-����Ʒ�Ʋ�ѯ��3-��ȡ�ʲ���Ϣ�д��ڵ�
	char chManufactureName[128];    ///<Ʒ������    @note  �豸Ʒ������
}DEVICEMODELINFOGET_IN_P;

///<��ȡ�ͺ���Ϣ(510-out)
typedef struct
{
	char chModelName[128];  ///<�ͺ�����   @note  �豸�ͺ�����
}DEVICEMODELINFOGET_OUT_S;

///<��ȡ��Ӧ����Ϣ(511-out)
typedef struct
{
	char chSupplierName[128];  ///<��Ӧ������   @note  �豸��Ӧ������
}SUPPLIERINFOGET_S;

///<��ȡά������Ϣ(512-out)
typedef struct
{
	char chMaintenceCompany[128];  ///<ά��������   @note  �豸��Ӧ������
}MAINTENCECOMPANYGET_S;

///<��ȡ��������Ϣ(513-out)
typedef struct
{
	char chEngineeringInfo[128];  ///<����������   @note  �豸��װ��λ����
}ENGINEERINGINFOGET_S;


///<��ȡ��ȡ�豸������Ϣ(514-in)
typedef struct
{
	char chDeviceType[100];			///<�豸����
	char chManufactureName[128];	///<Ʒ��
	char chModelNo[128];			///<�ͺ�
	char chSupplierName[128];		///<��Ӧ��
	char chMaintenceName[128];		///<ά����
	char chSTName[128];				///<������
	char chStorageDateBegin[20];	///<��⿪ʼʱ��
	char chStorageDateEnd[20];		///<������ʱ��
	char chAreaName[64];			///<��������
	char chMaintenceTele[32];		///<ά���绰
	char chStatus[100];				///<ʹ��״̬
	int nPage;						///<��ǰҳ��
	int nNumberPerPage;				///<ÿҳ����	
}DEVICEBASEINFOGET_IN_P;

///</<��ȡ��ȡ�豸������Ϣ(514-out)
typedef struct
{
	char chCapitalCode[64];			///<�ʲ����
	char chDeviceCode[64];			///<�豸����
	char chDeviceType[100];			///<�豸����
	char chAreaName[64];			///<��������
	char chManufactureName[128];	///<Ʒ��
	char chModelNo[128];			///<�ͺ�
	char chStorageDate[20];			///<���ʱ��
	char chSupplierName[128];		///<��Ӧ��
	char chSTName[128];				///<������
	char chMaintenceName[128];		///<ά����
	int nMaintenceMonth;			///<ά������
	char chMaintenceTele[32];		///<ά���绰
	char chStatus[100];				///<ʹ��״̬
	int nTotalNum;					///<������	
}DEVICEBASEINFOGET_OUT_S;


///<���޼�¼��Ϣ��ѯ(515-in)
typedef struct
{
	char chDeviceType[64];			///<�豸����
	char chManufactureName[128];	///<Ʒ��
	char chModelNo[128];			///<�ͺ�
	char chThirdLevel[128];			///<��������
	char chStatus[128];				///<ά��״̬
	char chHandleDateBegin[20];		///<���޿�ʼʱ��
	char chhandleDateEnd[20];		///<���޽���ʱ��
	int nPage;						///<��ǰҳ��
	int nNumberPerPage;				///<ÿҳ����
}MALFUNCTIONINFOGET_IN_P;

///</</<���޼�¼��Ϣ��ѯ(515-out)
typedef struct
{
	int nId;						///<���޵�ID
	char chMalfunctionCode[64];		///<���޵���
	char chCapitalCode[64];			///<�ʲ�����
	char chDeviceType[64];			///<�豸����
	char chManufactureName[128];	///<Ʒ��
	char chModelNo[128];			///<�ͺ�
	char chThirdLevel[128];			///<��������
	char chHandleDate[20];			///<����ʱ��
	char chHandleMan[32];			///<������
	char chFaultNames[1024];		///<����������$�ָ�
	char chDescribe[128];			///<��������
	char chStatus[128];				///<ά��״̬
	int nTotalNum;					///<������
}MALFUNCTIONINFOGET_OUT_S;

///<��ȡ��������(516-out)
typedef struct
{
	char chFaultName[128];  ///<��������
}FAULTNAMEGET_S;

///<ά�޼�¼��Ϣ��ȡ(517-in)
typedef struct
{
	int nId;					///<���޵�ID
}MAINTENCEINFOIN_P;

///<ά�޼�¼��Ϣ��ȡ(517-out)
typedef struct
{
	int nId;					///<���޵�ID
	char chMaintenceDate[128];	///<ά��ʱ��
	char chMemo[256];			///<��ע
	char chMaintStatus[128];	///<ά��״̬
	char chRecordMan[64];		///<��¼��
}MAINTENCEINFOGET_S;

///<��ȡά������Ϣ�����绰(518-out)
typedef struct
{
	char chMaintencePhone[32];		///<ά���̵绰
}MAINTENCEINFOPHONE_S;

///<���������������ƻ���ȡ(519-out)
typedef struct
{
	int nModelId;			///<ģ��ID	
	char chModelName[128];	///<ģ������
	char chWeekdays[128];	///<�������ڴ� ���ÿͻ�������ƴ�Ӳ��
	bool bIsEnable;			///<�Ƿ�����
	int nType;				///<ʱ������ 1-���� 2-����
	int nSequence;			///<ʱ���˳��
	char chBeginTime[20];	///<��ʼʱ��
	char chEndTime[20];		///<����ʱ��
	int nAlarmId;			///<��������ID
	char chDeviceName[64];	///<������������
	char chPartitions[128];	///<����������ʱ���ã�
}ALARMARMDISARMPLAN_S;

///<�豸������Ϣͳ��(520-in)
typedef struct
{
	int nStatisticsType;			///<1-�豸���� 2-�豸�ͺ� 3-�豸Ʒ�� 4-���� 5-��Ӧ�� 6-�豸״̬ 7-������ 8-ά����
	int nGraphType;					///<1-��ͼ 2-��ͼ ��״ͼ���β���Ŀǰ�ͻ��˲��ã�appĬ��ֵ��2,���߲����þͿ�����
	char chDeviceTypes[1000];		///<�豸�������ƴ� $ƴ��
	char chModelNos[8000];			///<�豸�ͺ����� $ƴ��
	char chManufactureNames[8000];	///<Ʒ������ $ƴ��
	char chAreaNames[8000];			///<�������ƴ� $ƴ��
	char chSupplierNames[8000];		///<��Ӧ�����ƴ� $ƴ��
	char chStatuses[1000];			///<�豸״̬���ƴ� $ƴ��
	char chSTNames[8000];			///<���������ƴ� $ƴ��
	char chMaintenceNames[8000];	///<ά�������ƴ� $ƴ��
	char chStorageDateBegin[20];	///<���ʱ�俪ʼ
	char chStorageDateEnd[20];		///<���ʱ�����
}CAPITALINFOSTATISTICS_IN_P;

///<�豸������Ϣͳ��(520-out)
typedef struct
{
	char chStatisticsType[128];	///<ͳ����
	int nTotal;					///<����
}CAPITALINFOSTATISTICS_OUT_S;

///<������Ϣͳ��(521-in)
typedef struct
{
	int nStatisticsType;			///<1-�豸���� 2-�豸Ʒ	�� 3-�豸�ͺ� 4-���� 5-�豸״̬
	int nGraphType;					///<1-��ͼ 2-��ͼ ��״ͼ
	char chDeviceTypes[1000];			///<�豸�������ƴ� $ƴ��
	char chManufactureNames[8000];		///<Ʒ�����ƴ� $ƴ��
	char chModelNos[8000];				///<�ͺ����ƴ� $ƴ��
	char chThirdLevels[8000];			///<�������ƴ� $ƴ��
	char chStatuses[1000];				///<״̬���ƴ� $ƴ�� �ͻ�����ʱ���� ���롯�����߲���ֵ
	char chHandleMans[1000];			///<���������ƴ� $ƴ��
	char chHandleDateBegin[20];		///<����ʱ�俪ʼ
	char chHandleDateEnd[20];		///<����ʱ�����
}MALFUNCTIONINFOSTATISTICS_IN_P;

///<������Ϣͳ��(521-out)
typedef struct
{
	char chStatisticsType[128];	///<ͳ����
	char chStatisticsDate[20];	///<ʱ��	GraphTypeΪ1ʱ����
	int nTotal;					///<����
}MALFUNCTIONINFOSTATISTICS_OUT_S;

///<����ʹ��״̬��ȡ(522-out)
typedef struct
{
	int nDeviceId;					///<�豸���
	int nStatus;					///<ʹ��״̬   @note  1-����ʹ�ã�2-ά���У�3-����
}HOSTUSESTATUSGET_S;

///<̽ͷʹ��״̬��ȡ(523-out)
typedef struct
{
	int nDeviceId;					///<�豸���
	int nStatus;					///<ʹ��״̬   @note  1-����ʹ�ã�2-ά���У�3-����
}DETECTORUSESTATUSGET_S;

///<��ȡѲ��ƻ�(524-out)
typedef struct
{
	int nType;				///<Ѳ��ƻ����� 1-����״̬ 2-ʱ��״̬  3-Ӳ��״̬ 4-ͨ��״̬ 5-¼��������
	char chBeginTime[20];	///<��ʼʱ��
	char chEndTime[20];		///<����ʱ��
	int nCycle;				///<ˢ��ʱ��
	int nCycleType;			///<ˢ��ʱ�䵥λ
	bool bWeekDays[7];		///<ִ�й���
	int nCheckDays;			///<�����
	bool bIsEnable;		    ///<�Ƿ�����
}DETECTSCHEDULEGET_S;

///<��ȡģ��������Ϣ(525-out)
typedef struct
{
	char chModuleName[64];		///<ģ������
	char chModuleType[64];		///<ģ������
	char chCreateMan[64];		///<������
	char chCreateDate[20];		///<����ʱ��
}MODULEINFOGET_S;

///<�����豸��Ż�ȡ�豸������Ϣ_�ͻ���(526-in)
typedef struct
{
	char chCapitalCode[64];		///<�ʲ�����
}DEVICEBASEINFOBYIDGET_CLIENT_P;

///<�����豸��Ż�ȡ�豸������Ϣ_���ÿͻ���(527-in)
typedef struct
{
	int nDeviceType;		    ///<�豸������   @note  �������ݿ��
	int nDeviceId;				///<�豸ID
	
}DEVICEBASEINFOBYIDGET_SOFTSET_P;

///<�����豸��Ż�ȡ�豸������Ϣ(526,527-out)
typedef struct
{
	int nDeviceId;					///<�豸ID
	int nDeviceType;				///<�豸����
	char chCapitalCode[64];			///<�ʲ����
	char chNodeName[32];			///<�豸��������
	char chManufactureName[128];	///<Ʒ��
	char chModelNo[128];			///<�ͺ�
	char chSupplierName[128];		///<��Ӧ��
	char chStorageDate[20];			///<���ʱ��
	char chSTName[128];				///<������
	char chMaintenceName[128];		///<ά����
	int nMaintenceMonth;			///<ά������
	char chMaintenceTele[32];		///<ά���绰
	char chStatus[100];				///<ʹ��״̬
}DEVICEBASEINFOBYIDGET_S;


///<OM����������(528,532,534-in)
typedef struct
{
	char chOMName[32];   ///<OM����������
	
}OMSERVERNAME_P;

///<��ȡOM�豸��Ϣ(528-out)
typedef struct
{
	int nDeviceId;				///<�豸ID
	char chDeviceName[40];		///<�豸����
	char chDeviceCode[20];		///<�豸����
	char chIP[20];				///<IP��ַ
	char chUpperNode[20];		///<�ϼ��ڵ����
	int nPortNo;				///<�˿ں�
	int nDeviceType;			///<�豸����
	char chManufactureName[32];	///<�豸��������
	int nManufactureCode;		///<�豸���ұ��
	char chModelNo[32];			///<�豸�ͺ�
	char chUserName[20];		///<��¼�û���
	char chPassword[35];		///<��¼����
	bool bIsConnected;			///<�Ƿ���Ҫ����
	
}OMDEVICEINFOGET_S;


///<��ȡOMͨ����Ϣ����(529-in)
typedef struct
{
	int nCondition;		 ///<��������0��Ԥ����
	char chOMName[32];   ///<OM����������
	
}OMCHANNELINFODIVIDEGET_P;

///<��ȡOMͨ����Ϣ����(529-out)
typedef struct
{
	int nChannelId;				///<ͨ��ID
	char chChannelName[32];		///<ͨ������
	int nChannelNo;				///<ͨ����
	int nChannelType;			///<ͨ������
	int nDeviceId;				///<�����豸ID
	
}OMCHANNELINFODIVIDEGET_S;


///<��ʾOM������Ϣ(530-in)
typedef struct
{
	int nCondition;		 ///<��������0��Ԥ����
	char chOMName[32];   ///<OM����������
	
}OMPARTATIONINFOGET_P;

///<��ʾOM������Ϣ(530-out)
typedef struct
{
    int nDevID;                 	    ///<�豸ID
    char chDevName[32];          		///<�豸��
	int nPartNum;                 		///<������Ŀ
	PartionInformation Part[33];		///<������ϸ��Ϣ 
	
}OMPARTATIONINFOGET_S;

typedef struct
{
	char chBeginTime[20];	///<��ʼʱ��
	char chEndTime[20];		///<����ʱ��
	
}TimeModule;

///<OM��ȡ������ģ��(531-out)
typedef struct
{
	int nModelId;				///<ģ��ID
	char chModelName[32];		///<ģ������
	bool bWeekDays[7];			///<����
	int nArmTimeCount;			///<����ʱ�������
	int nDisArmTimeCount;		///<����ʱ�������
	TimeModule arrArm[6];		///<����ʱ���
	TimeModule arrDisArm[6];	///<����ʱ���
	
}OMARMDISARMMODULEGET_S;

///<OM��ȡ�����������ƻ�(532-out)
typedef struct
{
	int nDeviceId;	///<�豸ID
	int nModuleId;	///<ģ��ID
	
}OMARMDISARMSCHEDULEGET_S;

///<OM��ȡ¼������ģ��(533-out)
typedef struct
{
	int nModuleId;			///<ģ��ID
	char chModuleName[32];	///<ģ������
	int nRecordDays;		///<¼������
	
}OMRECORDDAYSMODULEGET_S;

///<OM��ȡ¼������ģ��(534-out)
typedef struct
{
	int nChannelId;	///<ͨ��ID
	int nModuleId;	///<ģ��ID
	
}OMCHANNELRECORDDAYSGET_S;


///<��ȡ������Ϣ����(535-out)
typedef struct
{
	int nId;				///<��������ID
	char chFaultName[128];	///<������������
	char chSetDate[20];		///<¼������
	char chSetMan[32];		///<¼����
	bool bIsEnable;		///<�Ƿ�����
	int nFaultType;			///<��������
	
}FAULTINFODETAILGET_S;

///<AS��ȡ�����������ƻ�(536-in)
typedef struct
{
	char chASName[32];   ///<AS����������
	
}ASARMDISARMSCHEDULEGET_P;

///<AS��ȡ�����������ƻ�(536-out)
typedef struct
{
	int nDeviceId;	///<�豸ID
	int nModuleId;	///<ģ��ID
	
}ASARMDISARMSCHEDULEGET_S;


///<���������������ƻ���ȡͨ��ID(537-out)
typedef struct
{
	int nModuleId;	///<ģ��ID
	
}ALARMARMDISARMPLANBYID_P;

///<���������������ƻ���ȡͨ��ID(537-out)
typedef struct
{
	int nModelId;			///<ģ��ID	
	char chModelName[128];	///<ģ������
	char chWeekdays[128];	///<�������ڴ� ���ÿͻ�������ƴ�Ӳ��
	bool bIsEnable;			///<�Ƿ�����
	char chType[1024];		///<ʱ������ 1-���� 2-����:��$ƴ��
	char chSequence[1024];	///<ʱ���˳��:��$ƴ��
	char chBeginTime[8000];	///<��ʼʱ��:��$ƴ��
	char chEndTime[8000];	///<����ʱ��:��$ƴ��
	char chAlarmId[8000];	///<��������ID:��$ƴ��
	char chDeviceName[8000];	///<������������:��$ƴ��
	char chPartitions[8000];	///<����������ʱ���ã�:��$ƴ��
	
}ALARMARMDISARMPLANBYID_S;

///<���ÿͻ��˻�ȡѲ��ģ����Ϣ(538-out)
typedef struct
{
	int nModuleId;			///<ģ��ID
	char chMuduleName[32];	///<ģ������
	bool bIsEnable;			///<�Ƿ�����
	char chCreateMan[32];	///<������
	char chCreateDate[20];	///<��������
	
}DETECTMODULEINFOGET_S;


///<��ȡ���ָ�Ѳ����������豸��Ϣ(539-in)
typedef struct
{
	char chOMName[32];   ///<OM����������
	
}OMSERVERDIVIDEINFOGET_P;

///<��ȡ���ָ�Ѳ����������豸��Ϣ(539-out)
typedef struct
{
	int nDeviceId;			///<�豸ID
	char chDeviceName[64];	///<�豸����
	
}OMSERVERDIVIDEINFOGET_S;

///<��ȡOM��������Ϣ(540-in)
typedef struct
{
	char chOMName[32];   ///<OM����������
	
}OMSERVERINFOGET_P;

///<��ȡOM��������Ϣ(540-out)
typedef struct
{
	char chOMName[32];		///<OM����������
	char chPassword[64];	///<��¼����
	char chIP[20];			///<IP��ַ
	
}OMSERVERINFOGET_S;

///<���ÿͻ��˻�ȡ����OM��Ϣ(541-out)
typedef struct
{
	int nOMId;					///<OM������ID
	char chOMServerCode[32];	///<OM���������
	char chOMServerName[32];	///<OM����������
	char chOMPassword[64];		///<OM����������
	char chOMIPAddr[20];		///<OM������IP��ַ
	char chOMMemo[128];			///<OM��������ע
	
}ALLOMINFOSOFTSETGET_S;

///<����¼������ģ��ID��ȡ��������ͷ(542-in)
typedef struct
{
	int nModuleId;   ///<¼������ģ��ID
	
}SOFTSETCHANNELRECORDDAYSGET_P;


///<����¼������ģ��ID��ȡ��������ͷ(542-out)
typedef struct
{
	int nChannelId;	///<ͨ��ID
	int nModuleId;	///<ģ��ID
	
}SOFTSETCHANNELRECORDDAYSGET_S;


///<������������ȡ�豸��Ϣͨ���豸״̬(543-in)
typedef struct
{
	int nCondition;   ///<1-��ѯ������2-��ѯ����ͷ
	int nStatus;	  ///<0-ȫ��״̬��1-����ʹ�ã�2-ά���У�3-����
	
}ASDEVICEINFOBYSTATUSGET_P;


///<������������ȡ�豸��Ϣͨ���豸״̬(543-out)
typedef struct
{
	int nTerminalId;	///<�ն�ID	nCondition=2ʱ��ֵ
	int nDeviceID;		///<�豸ID  nCondition��1-����ID��2-����ͷID
	int nChannelNo;		///<ͨ����	nCondition=2ʱ��ֵ
	int nStatus;		///<ʹ��״̬
	
}ASDEVICEINFOBYSTATUSGET_S;


///< ��������_NEW(600-in)
typedef struct
{
    int nDeviceID;             ///< �豸ID
    int nChannelNo;            ///< ͨ����
    int nAID;                  ///< ��������ID
    int nLevel;                ///< �����ȼ�ֵ
    int nStstus;               ///< ����״̬
    char chMemo[128];          ///< ��ע
    char chName[64];           ///< ������
    TJTY_TIME tTime;           ///< ����ʱ��
	char chGUID[128];		   ///< ��������������ΨһID
}P_ALARMDISPOSAL_ASSINGLE_SET_NEW;

///< ���������洢�ļ�����������(601-in)
typedef struct
{
    char chGUIDs[8000];		  ///<Ҫ������������ID,1-�������ã�2-����Ѳ�飻3-������֤��
									///<����ID$��ӦIDֵ$�����磺1$100$101$
	bool bIsLocked;			  ///<�Ƿ�������1-������0-����
		
}ALARMSTORAGEFILELOCKED_SET_P;

///< ý��洢�ļ���Ϣд��(602-in)
typedef struct
{
	char chFileCode[10];	// �ļ�����
	long nDevID;            // �豸ID
	int nChannel;           // ͨ����
	char chFileName[50];    // ¼���ļ���
	char chFilePath[250];   // ¼���ļ�·��
	char chBeginTime[64];	// ��ʼʱ��
	char chEndTime[64];  	// ����ʱ��
	char chLastRead[20];    // ����ȡʱ��
	int nReadTimes;			// ��ȡ����
	int nDateType;			// ��������
	int nAlarmType;      	// ��������
	int nAlarmLevel;        // ��������
	bool bIsLocked;		    // �Ƿ�����
	char chMemo[500];		// ��ע
	int nStorageType;		// �洢����:1-��Ƶ ;2-ͼƬ ;3-��Ƶ
	int nStorageModule;		// �洢ģ��:1-��������;2-�ճ�Ѳ��;3-�Ž���֤
	char chGUID[128];	    // GUID
		
}MEDIASTORAGEFILEINFO_INSERT_P;


///< �����������ӡ��޸�_NEW(603-in)(add��mod)
typedef struct
{
    int  nCondition;                ///< ����:1-add,2-mod
    int nID;                        ///< ���
    int nAC;                        ///< AC���
    char strTypeName[64];           ///< ������
    char strTimeStart[64];          ///< ��ʼʱ��
    char strTimeEnd[64];            ///< ����ʱ��
    char strSound[256];             ///< ��������
    int  ConfigSequence;            ///< ����ʱ���ID
    int  nPriority;                 ///< �������ȼ�
    int  bFliter;                   ///< �Ƿ����
    int  nFliterTimeInterval;       ///< ����ʱ����
    int  bWord;                     ///< �Ƿ��������
    int  bVideoStore;               ///< �Ƿ������洢
    int  nVideoStoreTime;           ///< ��Ƶ�洢ʱ��
    int  bAlarmInfoStore;           ///< ������Ϣ�Ƿ�洢
	bool bDoCapture;				///< �Ƿ�ץͼ
	int nCaptureCount;				///< ץͼ����
	
}ALARMTYPEOPERATION_NEW_P;

///< ���̲�������(604��606��607-IN)
typedef struct
{
	int nModuleType;			//ģ�����ͣ�1-�������ã�2-�ճ�Ѳ�飻3-�Ž���֤
	int nStorageType;			//�洢���ͣ�1-��Ƶ��2-ͼƬ��3-��Ƶ
	int nStorageDays;			//�洢����
	bool bIsEnable;	            //�Ƿ�����
	
}CLEANDISKSTORAGE_SET_P;

///< ���̲������û�ȡ(605-out)
typedef struct
{
	int nModuleType;			//ģ�����ͣ�1-�������ã�2-�ճ�Ѳ�飻3-�Ž���֤
	int nStorageType;			//�洢���ͣ�1-��Ƶ��2-ͼƬ��3-��Ƶ
	int nStorageDays;			//�洢����
	bool bIsEnable;	            //�Ƿ�����
	char chModuleDesc[16];		//ģ����������
	char chStorageTypeDesc[8];	//�洢��������
	
}CLEANDISKSTORAGE_GET_S;


///< ��ȡҪɾ�����ļ���Ϣ(607-out)
typedef struct
{
	char chFileName[50];		//�ļ�����
	char chFilePath[250];		//�ļ�·��
	
}DELETEFILEINFO_GET_S;


///< ��ȡ��������_NEW(608-out)
typedef struct
{
    int nID;                        ///< �������
    int nAC;                        ///< AC���
    char strTypeName[64];           ///< ������
    int  ConfigSequence;            ///< ʱ���
    char strTime[64];               ///< ��ʼʱ��
    bool  bWord;                    ///< �Ƿ��������
    bool  bVideoStore;              ///< �Ƿ������洢
    int  nVideoStoreTime;           ///< ��Ƶ�洢ʱ��
    bool  bFliter;                  ///< �Ƿ����
    int  nFliterTimeInterval;       ///< ����ʱ����
    bool  bAlarmDeal;               ///< �����Ƿ���
	bool bDoCapture;				///< �Ƿ�ץͼ
	int nCaptureCount;				///< ץͼ����
	
}ALARMCONFIG_GET_NEW_S;


///<������Ϣ����
typedef struct
{
    int nFiltrateFlag;  			///<0�������ˣ�1�����ˣ�2��������
    int nInterval;      			///<���˼������λΪ��
    unsigned char ucIsSaveText;		///<�Ƿ�洢�������֣�1:�洢��0:���洢
    unsigned char ucIsSaveVideo;	///<�Ƿ�������Ƶ�洢��1:������0:������
    int nSaveTime;               	///<�洢ʱ����S��
	bool bDoCapture;		        ///<�Ƿ�����ץͼ
    int nCaptureCount;              ///<ץͼ����
}T_ALARM_DEALINFO_NEW;


///<������������ȡ�������ò�����Ϣ_NEW(609)
typedef struct
{
    int nAlarmType;  						///<��������
	char chAlarmTypeName[128];      		///<����������
    T_ALARM_TIMESEGMENT TimeSegment[6];		///<ʱ���
    T_ALARM_DEALINFO_NEW T_AlarmDeal[6]; 	///<������������
}ALARMDEALSTRATEGY_GET_NEW;

///<�ͻ��˻�ȡý��洢�ĸ���(610-in)
typedef struct
{
    int nCondition;      ///< 1-����GUID��ѯ�������ù���������2-����AlarmId��ѯ�������ù���������3-��������ִ��ID��ѯ�ճ�Ѳ�����������4-������֤ID��ѯ������֤����������
	char chGUID[64];	 ///< GUID
	int nAlarmId;		 ///< ����ID
	
}CLIENTGETMEDIASTORAGEATTACHMENT_P;

///<�ͻ��˻�ȡý��洢�ĸ���(610-out)
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
	
}CLIENTGETMEDIASTORAGEATTACHMENT_S;

///< ����Ѳ������ִ�в���_NEW(611-in)
typedef struct
{
    int nTaskDistributeId;                ///< �����·�ID
    char chAreaName[64];                  ///< ������������
    int nDoError;                         ///< �쳣����ֵ
    bool bDoCarry;                        ///< �Ƿ�Ϊ��ע����Ѳ��
    char chBeginTime[32];                 ///< ��ʼѲ��ʱ��
    char chError[512];                    ///< �쳣$��
    char chOperate[512];                  ///< ����$��
    char chAnnex[2048];                   ///< ����
    char EPlanName[128];                  ///< Ԥ������
    bool bIsQualified;                    ///< �Ƿ�ϸ�
    char chReadRecord[8000];              ///< ���ļ�¼
    char chMemo[512];                     ///< ��ע
    char chActionNos[8000];               ///< ��������$��
    char chActionNames[8000];             ///< ����������$��
    char chHandleMans[8000];              ///< ������$��
    char chDoBeginTimes[8000];            ///< ��ʼ����ʱ��$��
    char chDoEndTimes[8000];              ///< ��������ʱ��$��
    char chAttachments[8000];             ///< ����$��
    char chDoSuccesses[8000];             ///< �Ƿ�ִ�гɹ�$��
    char chMemos_VarC[8000];              ///< ��ע$��
	char chTerminalIds[4000];			   ///<�ն�ID����$�ָ�
    char chChannelNos[2000];			   ///<ͨ��ID����$�ָ�
    char chBeginTimes[8000];			   ///<��ʼʱ�䣬��$�ָ�
    char chEndTimes[8000];				   ///<����ʱ�䣬��$�ָ�
	char chTaskGUID[128];				   ///<����GUID(�ͻ�������)
}P_NEW_INSPECT_TASKEXCUTESET_NEW;

///<����������Ϣ����_NEW(612-in)
typedef struct
{
    char chDeviceName[64];              ///<�豸����
    char chAreaName[64];                ///<������������
    char chKeyPart[128];                ///<��λ����
    char chContactPerson[128];          ///<��ϵ������
    char chHappenDate[32];              ///<����ʱ��
    char chContactInfo[16];             ///<��ϵ��ʽ
    int nMethod;                        ///<���÷�ʽ
    char chPlanName[128];               ///<Ԥ������
    int nProcessType;                   ///<���״̬	1-ͨ�� 2-�ܾ�
    int nProcessStatus;                 ///<��֤״ֵ̬ 1-δ�� 2-������ 3-����� 4-�Ѵ��� 5-��ʧЧ
    int nIsCollection;                  ///<�Ƿ��ղ� 1-�ղ� 0-��
    int nPassStatus;                    ///<ͨ�����	1-ͬ�⿪�� 2-�ܾ�����
    int nIsNormal;                      ///<�Ƿ���������
    char chHandleMan[128];              ///<������
    char chApplyType[512];              ///<��֤ģʽ
	char chDoorGUID[128];				///<��֤GUID(�ͻ�������)
}TAGDOA_INFO_P_NEW;

///<��ȡ�û��Ž����������-���ÿͻ���(449-in)
typedef struct
{
	char chDeviceCode[64];		///<�Ž��豸����
	
}USERDOORCAMERARELATION_GET_P;

///<��ȡ�û��Ž����������-���ÿͻ���(449-out)
typedef struct
{
	char chDoorCode[64];		///<�Ž��豸����
	char chUserName[128];		///<�������û�����
	char chCameraName[128];		///<���������������
	bool bIsEnable;				///<�Ƿ�����
	
}USERDOORCAMERARELATION_GET_S;


 ///<��ѯˢ����ʷ��Ϣ_NEW(450-in)
 typedef struct
 {
     char chBeginTime[32];       ///<��ʼʱ��
     char chEndTime[32];         ///<����ʱ��
     char chAreaName[64];        ///<��������
     char chCompanyName[64];     ///<��λ����
     int  nStatus;               ///<Ȩ��״̬0-ȫ�� 1-�ϸ� 2-���ϸ� 3-��Ч
     char chWorkNum[16];         ///<����
     char chPersonId[32];        ///<���֤��
     int  nPages;                ///<ҳ��
     int  nRecords;              ///<ÿҳ��ʾ��¼��
     char chName[32];            ///<ˢ��������
	 char chContrlLevel[32];	 ///<�ܿصȼ�
 }TAGDOABYCARDINFO_NEW_P;

 ///<��ѯˢ����ʷ��Ϣ_NEW(450-out)
 typedef struct
 {
     char chName[32];                     ///<ˢ��������
     int  nUserType;                      ///<
     int  nStatus;                        ///<Ȩ��״̬ 1-�ϸ� 2-���ϸ�
     char chType[64];                     ///<����
     char chPersonId[32];                 ///<���֤��
     char chWorkNum[16];                  ///<����
     char chDepartment[32];               ///<��λ
     char chKeyPart[128];                 ///<��λ����
     char chAccessDate[32];               ///<ˢ��ʱ��
     char chAreaName[64];                 ///<��������
     char chMemo[512];                    ///<¼��ԭ��
     int  nSumPage;                       ///<��ҳ��
     int  nApplyId;                       ///<��֤ID
	 char chContrlLevel[32];	 		  ///<�ܿصȼ�
 }TAGDOABYCARDINFO_NEW_S;

///<��ȡ�û��Ž����������-�ͻ���(451-out)
typedef struct
{
	int nDoorId;			///<�Ž��豸ID
	char chUserName[128];	///<�������û�����
	int nDeviceId;			///<����������ͷ�����豸ID
	int nChannelNo;			///<����������ͷͨ����
	int nCenterNo;			///<���ı��
	
}USERDOORCAMERARELATION_CLIENT_GET_S;

 ///<�û��Ž��������������(452-in)
 typedef struct
 {
	char chDoorCode[64];		///<�Ž��豸����
	char chUserName[128];		///<�������û�����
	char chCameraName[128];		///<���������������
	bool bIsEnable;				///<�Ƿ�����
	
 }USERDOORCAMERARELATION_SET_P;


///<��ȡ�豸��Ϣ�����ʲ�����(545-out)
typedef struct
{
	char chIP[20];			///<IP��ַ
	char chDeviceCode[32];	///<�豸����
	char chDeviceName[128];	///<�豸����
	char chUpperCode[32];	///<�ϼ�����
	int nCenterNo;			///<����ID
	int nFatherCenterNo;	///<������ID
	int nDeviceId;			///<�豸ID
	int nDeviceLevel;		///<�豸�ȼ�
	char chCapitalCode[32];	///<�ʲ�����
	
}DEVICEINFOWITHCAPITAL_GET_S;

///<��ȡ�豸��Ϣ�����ʲ�����(546-out)
typedef struct
{
	char chFrontendCode[32];	///<ǰ���豸����
	char chFrontendName[128];	///<ǰ���豸����
	char chUpperCode[32];		///<�ϼ�����
	char chDeviceCode[32];		///<�����豸����
	int nCenterNo;				///<����ID
	int nFatherCenterNo;		///<������ID
	int nDeviceId;				///<�豸ID
	int nDeviceLevel;			///<�豸�ȼ�
	int nChannelNo;				///<ͨ����
	char chCapitalCode[32];		///<�ʲ�����
	
}FRONTENDNODEINFOWITHCAPITAL_GET_S;
 

///<��ȡ�ļ�������������Ϣ(291-out,292-in)
typedef struct
{
	int nFileType;				//�ļ����ͣ�1-�ļ�������
	char chFilePath[256];		//�ļ�������URL·��
	char chFileName[128];		//����	
	
}FILESERVERINFO_GET_SP;
 
///<�������������_NEW(293-in)
typedef struct
{
    int nCondition;    ///< ����: 1-add,2-mod,3-del
    int nActionID;     ///< ����ID;
	int nActionNo;	   ///< �������;
	int nProperty;	   ///< ��ʶ��0-����ִ�У�1-�̶����ͣ�2-����ִ�У�
    char chName[64];   ///< ��������
	char chProperty[128];	///< ���ԣ�Ŀǰ���绰���룬��������ִ�л���ִ��
}P_NEW_OPACTIONLIB_NEW;
 
 
///< �����ѯ_NEW(294-in)
typedef struct
{
    char chUserName[64];          ///< �û�����
    char chTaskName[64];          ///< ��������
    char chRoleName[64];          ///< ��ɫ����
    int  nError;                  ///< �쳣����ֵ 0-���쳣��1-ִ��ʱ����̣�2-ִ�в�׼ʱ��3-Ѳ�����쳣
    int  nClassId;                ///< ���ID
    char chBeginDate[32];         ///< ��ѯ��ʼ����
    char chEndDate[32];           ///< ��ѯ��������(����ʱ����ò�Ҫ���ڵ�ǰ���ڣ�֮����������޽����)
	int nProperty;                ///< ����״̬��-1-ȫ����0-������1-������
}P_NEW_INSPECT_CHECKTASKINFOWITHLOCK; 

///<����������Ϣ���ۺϲ�ѯwithlock(295-in)
typedef struct
{
    int nPage;                     ///< ҳ��
    int nCount_Page;               ///< ÿҳ��ʾ��¼����
    char chBeginTime[32];          ///< ��ʼʱ��
    char chEndTime[32];            ///< ����ʱ��
    char chAreaNames[2048];        ///< �ص��Ŵ�
    char chAlarmTypes[1024];       ///< �������ʹ�
    char chAlarmlevels[32];        ///< �����ȼ���
    char chHandleMan[32];          ///< ������
    char chProcessType[32];        ///< ��������
    int nProcessStates;            ///< ����״̬
	int nProperty;                ///< ����״̬��-1-ȫ����0-������1-������
}P_NEW_JH_COMPLEXCHECKWITHLOCK;
 
///<��ѯ��֤��ʷ��Ϣwithlock(296-in)
typedef struct
{
    char chBeginDate[32];            ///<��֤����ʱ��  ��ʼ
    char chEndDate[32];              ///<��֤ʱ�����
    char chAreaName[64];             ///<��������
    int  nPassStatus;                ///<ͨ��״̬0-ȫ�� 1-ͬ�⿪�� 2-�ܾ�����
    int  nProcessStatus;             ///<����״̬0-ȫ�� 1-δ���� 2-������ 3-�����
    int  nIsCollection;              ///<�Ƿ��ղ� 0-ȫ�� 1-�ղ� 2-δ�ղ�
    int  nIsNomal;                   ///<¼�뷽ʽ 0-ȫ�� 1-����¼�� 2-������¼��
    int  nMethod;                    ///<����ģʽ 0-ȫ��
    int  nProcessType;               ///<���״̬ 0-ȫ�� 1-ͨ��(�ϸ�) 2-�ܾ�(���ϸ�)
    int  nPages;                     ///<ҳ��
    int  nRecords;                   ///<ÿҳ��ʾ��¼��
	int nProperty;                ///< ����״̬��-1-ȫ����0-������1-������
}TAGDOAHISTORYINFOWITHLOCK_P; 
 

///<��Ա��Ϣ��ز���(453-in)
typedef struct
{
	int nCondition;				///<������1-������2-�޸ģ�3-ɾ����4-����
	int nStaffId;				///<��Ա���
	char chUserName[64];		///<����
	char chSex[10];				///<�Ա�
	char chPhone[32];			///<��ϵ�绰
	char chHeadImage[64];		///<ͷ��
	char chWorkNum[16];			///<����
	char chIdentityCard[64];	///<���֤��
	char chDepartmentName[20];	///<����
	int nUserType;				///<�û����ͣ�1-�ڲ���2-�ⲿ��3-��ʱ
	char chBeginTime[20];		///<��Ա��Ч�ڿ�ʼʱ��
	char chEndTime[20];			///<��Ա��Ч�ڽ���ʱ��
	char chCardNum[16];			///<����
	char chAuthGroup[1000];		///<Ȩ����,��$�ָ������Ϣ������id$Ȩ��������$�������ݿ���Աid$��
	int nUserStatus;			///<�û�״̬��0-������1-ע��
	char chAttachment[128];		///<������Ϣ
	int nLogoutReason;			///<ע��ԭ��0-������1-��ְ��2-���룻3-���ݣ�4-������5-����
	char chLogoutDesc[256];		///<ע������
	int nCheckStatus;			///<���״̬��1-����ˣ�2-����ˣ�3-���δͨ��
	char chCheckNumber[64];		///<��˱��
	char chLoginUser[32];		///<��¼���û�
}STAFFINFOOPERATION_P; 
 

///<������Ϣ��ز���(454-in)
typedef struct
{
	int nCondition;				///<������1-������2-�޸ģ�3-ɾ��
	int nDepartmentId;			///<����ID
	char chDepartmentName[32];	///<��������
	char chMemo[128];			///<��ע��Ϣ	
	char chLoginUser[32];		///<�����û� 	
}DEPARTMENTINFOOPERATION_P; 


///<��Ա״̬����(455-in)
typedef struct
{
	int nStaffId;			///<��Ա���
	int nStatus;			///<��Ա״̬��0-������1-ע����
	int nLogoutReason;		///<ע��ԭ��0-������1-��ְ��2-���룻3-���ݣ�4-������5-����
	char chLoginUser[32];	///<�����û� 	 	
}STAFFSTATUS_SET_P;
 
///<��ȡ������Ϣ(456-in)
typedef struct
{
	int nCondition;			///<������0-��ȡ���У�1-���ݲ�������ģ����ѯ
	char chDepartment[32];	///<�������� 	
}DEPARTMENTINFO_GET_P;

///<��ȡ������Ϣ(456-out)
typedef struct
{
	int nDepartmentId;			///<����ID
	char chDepartmentName[32];	///<��������
	char chMemo[128];			///<��ע��Ϣ		
}DEPARTMENTINFO_GET_S;

///<��ȡȨ������Ϣ(457-out)
typedef struct
{
	char chAuthGroup[32];	///<Ȩ����	
}AUTHGROUP_GET_S;
 
///<��ȡ��Ա��Ϣ(458-in)
typedef struct
{
	char chDepName[32];			///<��������
	char chAuthGroup[32];		///<Ȩ����
	char chStaffType[16];		///<�û����ͣ��ڲ����ⲿ��
	char chStaffStatus[16];		///<�û�״̬����������ְ�������
	char chQuery[32];			///<��ѯ���������������֤��ģ������
	int nPage;					///<��ǰҳ��
	int nPageNum;				///<ÿҳ��ʾ������	
}STAFFINFO_GET_P;

///<��ȡ��Ա��Ϣ(458-out)
typedef struct
{
	int nStaffId;				///<��Ա���
	char chUserName[64];			///<����
	char chSex[10];				///<�Ա�
	char chPhone[32];			///<��ϵ�绰
	char chHeadImage[64];		///<ͷ��
	char chWorkNum[16];			///<����
	char chIdentityCard[32];		///<���֤��
	char chDepartmentName[32];	///<����
	char chUserType[16];			///<�û����ͣ�1-�ڲ���2-�ⲿ��3-��ʱ
	char chBeginTime[20];		///<��Ա��Ч�ڿ�ʼʱ��
	char chEndTime[20];			///<��Ա��Ч�ڽ���ʱ��
	char chCardNum[16];			///<����
	char chAuthGroup[20];		///<Ȩ����,��$�ָ�
	int nUserStatus;			///<�û�״̬��0-������1-ע��
	char chAttachment[128];		///<������Ϣ
	char chLogoutReason[10];		///<ע��ԭ��0-������1-��ְ��2-���룻3-���ݣ�4-������5-����
	char chLogoutDesc[256];		///<ע������
	char chCheckStatus[10];		///<���״̬��0-����ˣ�1-����ˣ�2-���δͨ��
	char chCheckNumber[64];		///<��˱��
	int nTotalNum;				///<�ܼ�¼��
	int nPageNum;				///<ÿҳ����	
}STAFFINFO_GET_S;
 

///<��ȡ��Ա������Ϣ(459-in)
typedef struct
{
	char chUserName[64];		///<�������û�
	int nOperateObject;			///<��������1-��Ա��2-����
	int nOperateType;			///<�������ͣ�1-������2-�޸ġ�3-ɾ��
	char chContent[64];			///<��������
	char chBeginTime[20];		///<������ʼʱ��
	char chEndTime[20];			///<��������ʱ��
	int nPage;					///<��ǰҳ��
	int nPageNum;				///<ÿҳ����	
}STAFFOPERATION_GET_P;

///<��ȡ��Ա������Ϣ(459-out)
typedef struct
{
	int nId;					///<������־ID
	char chUserName[64];		///<�������û�
	char chOperateObject[16];	///<����������Ա������
	char chOperateType[16];		///<�������ͣ��������޸ġ�ɾ��
	char chMemo[64];			///<��������
	char chOperateTime[20];		///<����ʱ��
	int nTotalNum;				///<�ܼ�¼��
	int nPageNum;				///<ÿҳ����	
}STAFFOPERATION_GET_S;
 
 
///< ��ȡ�����δ�������ļ�(613-in)
typedef struct
{
	char chServerName[64];		///<����������
	
}GETFIRSTDAYFILEINFO_GET_P;
 
 
///< ��ȡ�����δ�������ļ�(613-out)
typedef struct
{
	char chFileName[50];		///<�ļ�����
	char chFilePath[250];		///<�ļ�·��
	char chDelDate[12];			///<Ҫɾ��������
	
}GETFIRSTDAYFILEINFO_GET_S;

///< ɾ��ָ������δ�������ļ�(614-in)
typedef struct
{
	char chDelDate[12];			///<Ҫɾ��������
	char chServerName[64];		///<����������
	
}DELETEFILEINFOBYDATE_P;


///< ��������ز���_Koala(700-in)
typedef struct
{
	int nCondition;			///<������1-��ӣ�2-�޸ģ�3-ɾ��
	int nActionID;			///<����ID:�����޸�ɾ��ʹ��
	char chActionName[64];	///<��������
	int nProperty;			///<��ʶ��0-����ִ�У�1-�̶�����
	char chProperty[64];	///<���ԣ�Ŀǰ���绰����
	int nActionNo;			///<�������
	char chMemo[256];		///<��ע����Ϊ��
	char chGUID[128];		///<����Ψһ��ʶ
	
}ACTIONOPERATION_KOALA_P;

///< Ԥ������ز���_Koala(701-in)
typedef struct
{
    int nCondition;            ///< ����: 1-koala����,2-koala�޸�,3-koalaɾ����4-SoftSet���ӣ�5-SoftSet�޸�
    int nPlanID;               ///< Ԥ��ID
    char chName[64];           ///< Ԥ������
    char chMan[64];            ///< ������
    char chActionID[2000];     ///< ����ID������$�ָ�(koala����GUID�������ÿͻ��˴���ID��)
    char chMustBeDos[128]; 	   ///< �����Ƿ����ִ�У���$�ָ0-���Ǳ��룻1-����
	char chExecuteType[128];   ///<	����ִ�����ͣ���$�ָ0-����ִ�У�2-����ִ��
    char chGUID[128]; 		   ///< Ԥ��Ψһ��ʶ
	
}PREPLANOPERATION_KOALA_P;


///< �¼�����ز���_NEW,���ÿͻ���ʹ��(702-in)
typedef struct
{
    int nCondition;            ///< ����: 1-add;2-modify
    int nEventID;              ///< �¼�ID
    char chName[64];           ///< �¼�����
    int nAlarmValue;           ///< �����ȼ�ֵ
    char chActionID[128]; 	   ///< ����ID��,��$�ָ�
    char chMustBeDos[128];     ///< �����Ƿ����ִ�У���$�ָ0-���Ǳ��룻1-����
	char chExecuteType[128];   ///<	����ִ�����ͣ���$�ָ0-����ִ�У�2-����ִ��
    char chGUID[128];     	   ///< �¼�Ψһ��ʶ
	
}EVENTOPERATION_SOFTSET_P;

///< �������ÿ�����Ϣд��(703-in)
typedef struct
{
	int nActionType;		///<�������ͣ�1-����Э��;2-�����ϱ�;3-���ý���;4-�ֶ�����;5-��������;6-ȷ�Ͼ��鷴��;7-ָ����Ա
	char chZoneeUser[64];	///<ָ���ߣ������û�
	char chKoalaUser[256];	///<ָ�ɵĿ�����Ա���ϴ��������û�,�����������Ϊ7ʱ����$�ָ��һ��Ϊ��������
	int nOperationType;		///<�������ͣ���Ӧ������������
	char chDescribe[256];	///<�������붯�����Ͷ�Ӧ
	char chTime[20];		///<�붯�����Ͷ�Ӧ���磺1-����Э��ʱ�䣻7-ָ��ʱ���
	int nAssignStatus;		///<ָ�ɷ���״̬��0-���ܣ�1-�ܾ�
	char chBeginTime[20];	///<��ʼʱ��
	char chEndTime[20];		///<����ʱ��
	char chAttachMent[1024];///<������
	char chRefuseReason[256];///<�ܾ�ԭ��
	char chEPlanName[128];	///<Ԥ��GUID,��������=2��ʱ����
	int nProperty;			///<����
	char chProperty[256];	///<����,��������=2��ʱ���붯����GUID
	char chGUID[64];		///<����GUID
	
}ALARMDEALKOALAINFO_INSERT_P;

///< ��ȡ������_Koala(704-in)
typedef struct
{
	int nCondition;			///<������0-ȫ����1-����GUID��ȡ
	char chGUID[128];		///<����GUID
	
}GETACTIONLIB_KOALA_P;

///< ��ȡ������_Koala(704-out)
typedef struct
{
    int nID;           ///< Ψһ���
    int nActionID;     ///< �������
    char chName[64];    ///< ��������
    char chProperty[64]; ///< ���ԣ�Ŀǰ��д�绰���룬��������ִ�л���ִ��
    int nProperty;		///<��ʶ��0-����ִ�У�2-����ִ�У�
    char chMemo[256];	///<��ע
    char chGUID[128];	///<����Ψһ��ʶ
	
}GETACTIONLIB_KOALA_S;

///< ��ȡԤ����_Koala(705-in)
typedef struct
{
	int nCondition;			///<������0-ȫ����1-����Ԥ��ID��2-����Ԥ����, 3- ��������������4-����GUID��ȡ
	int nPlanID;			///<Ԥ��ID
	char chPlanName[128];		///<Ԥ�����ƣ�condition=4ʱ��GUID
	
}GETPREPLANLIB_KOALA_P;

typedef struct
{
    int nID;           ///< Ψһ���
    int nActionID;     ///< �������
    char chName[64];    ///< ��������
    char chProperty[64];  ///< ���ԣ�Ŀǰ��д�绰���룬��������ִ�л���ִ��
    int nProperty;		///<��ʶ��0-����ִ�У�2-����ִ�У�
    char chMemo[256];		///<��ע
    char chGUID[128];		///<����Ψһ��ʶ
    int nSequence;		///<ִ��˳��
    int nMustDo;		///<�Ƿ����ִ�У�0-��������1-����ִ��
	
}ACTIONINFO_KOALA;


///< ��ȡԤ����_Koala(705-out)
typedef struct
{
    int nPlanID;              ///< Ԥ��ID
    char chPlanName[64];       ///< Ԥ������
    char chMan[64];            ///< ������
    char chGUID[128];		 ///< Ԥ��Ψһ��ʶ
	int nActionNum;			///< ��������������
	ACTIONINFO_KOALA actions[20];///<Ԥ�������Ķ���
	
}GETPREPLANLIB_KOALA_S;

///< ��ȡ�¼���_Koala(706-in)
typedef struct
{
	int nCondition;			///<������0-ȫ����1-�����¼�ID��2-�����¼�����3- ��������������4-����GUID��ȡ
	int nEventID;			///<�¼�ID
	char chEventName[128];		///<�¼����ƣ�condition=4ʱ��GUID
	
}GETEVENTLIB_KOALA_P;

///< ��ȡ�¼���_Koala(706-out)
typedef struct
{
    int nEventID;           ///< �¼�ID
    char chEventName[64];    ///< �¼�����
    int nAlarmValue;        ///< �����ȼ�ֵ
    char chAlarmLevel[64];   ///< �����ȼ���
    char chGUID[128];		///< �¼�Ψһ��ʶ
	int nActionNum;			///< ��������������
	ACTIONINFO_KOALA actions[20];///<Ԥ�������Ķ���
	
}GETEVENTLIB_KOALA_S;

///< ��ȡKoala��������(707-in)
typedef struct
{
	int nCondition;			///<������0-ȫ����1-���ݶ�Ӧ���ͻ�ȡ��Ӧ�ĸ�����2-��ȡ���ù����еĸ�����3-��ȡ�����ϱ���Ϣ
	int nType;			    ///<�������ͣ�1-����Э��;2-�����ϱ�;3-���ý���;4-�ֶ�����;5-��������;6-ȷ�Ͼ��鷴��;7-ָ����Ա
	char chGUID[128];		///<����GUID���ش���
	
}GETALARMATTACHMENT_KOALA_P;

///< ��ȡKoala��������(707-out)
typedef struct
{
	char chKoalaUser[64];	///<ָ�ɵĿ�����Ա���ϴ��������û�,�����������Ϊ7ʱ����$�ָ��һ��Ϊ��������
	int nIsMasterUser;		///<�Ƿ��������ˣ�0-���ǣ�1-��
	char chDescribe[256];	///<�������붯�����Ͷ�Ӧ
	char chTime[20];		///<�붯�����Ͷ�Ӧ���磺1-����Э��ʱ�䣻7-ָ��ʱ���
	char chBeginTime[20];	///<��ʼʱ��
	char chEndTime[20];		///<����ʱ��
	char chAttachMent[2000];///<������
	char chRefuseReason[256];///<�ܾ�ԭ��condition=3ʱ���˴�Ϊ������GUID
	int nEPlanName;			///<Ԥ��ID
	
}GETALARMATTACHMENT_KOALA_S;


///< ��Աͬ����־����(460-in)
typedef struct
{
	char chIds[1000];  ///<��¼ID������$�ָ�
	int nSyncDay;	///<Ҫͬ������
	int nStatus;	///<ͬ��״̬��1-��ͬ��
	
}STAFFSYNCFLAG_SET_P;



///< ��ԱȨ�����ȡ(461-in)
typedef struct
{
	int nStaffId;   ///<��ԱID
	
}STAFFAUTHINFO_GET_P;

///< ��ԱȨ�����ȡ(461-out)
typedef struct
{
	int nAuthId;					///<Ȩ����id
	char chAuthName[64];			///<Ȩ��������
	char chManufacturerName[64];	///<��������
	int nIsHas;						///<�����и�Ȩ��
	
}STAFFAUTHINFO_GET_S;


///< ��ȡͬ����Ա��Ϣ(462-in)
typedef struct
{
	int nSyncDay;  		 ///<Ҫͬ��������
	
}STAFFSYNCINFO_GET_P;

///< ��ȡͬ����Ա��Ϣ(462-out)
typedef struct
{
	int nRecordId;				///<��¼ID
	int nOperateType;			///<�������ͣ�1-��ӣ�2-�޸ģ�3-ɾ����4-ע����5-�ָ�ע��
	int nManufactureId;			///<���Ҷ�Ӧ����ԱID
	int nManufactureCode;		///<���ұ��
	char chAuthGroupName[64];	///<Ȩ��������
	char chUserName[64];		///<��Ա����
	char chWordNum[64];			///<����
	char chIdentity[64];		///<���֤
	char chDepName[64];			///<��������
	char chSex[10];				///<�Ա�
	char chBeginTime[20];		///<�����ڿ�ʼʱ��
	char chEndTime[20];			///<��Ч�ڽ���ʱ��
	
}STAFFSYNCINFO_GET_S;


///< �Ž�������Ѻ����(463-in)
typedef struct
{
	char chDeviceCode[64];		///<�豸����
	char chDeviceNames[256];	///<�������豸���ƣ���$�ָ�
	char chRelationTypes[64];	///<�������ͣ���$�ָ0-Ѻ����֤�豸��1-Ѻ��·��̽ͷ
	char chDeviceTypes[256];	///<�豸���ͣ���$�ָ0-̽ͷ��1-����ʶ���豸��2-��Աʶ���豸
	char chIsEnables[64];		///<�Ƿ����ã���$�ָ0-���ã�1-����
	
}ACCESSSYRELATION_SET_P;

///< ��֤��Ѻ��Ϣ����(464-in)
typedef struct
{
	int nOpenDoorId;				///<��֤ID
	char chAreaName[128];			///<��������
	char chLineName[128];			///<Ѻ����·����
	int nLineStatus;				///<·����֤״̬��0-������1-�쳣��-1-׷����Ϣ
	char chLineAreaNodes[8000];		///<Ѻ����·�����б���$�ָ�
	char chLineAreaNodeStatus[1024];///<Ѻ����·����״̬����$�ָ������һһ��Ӧ��0-����(��ɫ)��1-��΢�쳣(��ɫ)��2-�����쳣(��ɫ)
	char chPlanTime[20];			///<Ԥ�Ƶ���ʱ��
	char chRealTime[20];			///<ʵ�ʵ���ʱ��
	char chPlanCarImage[128];		///<Ԥ�Ƶ��ﳵ��ͼƬ
	char chRealCarImage[128];		///<ʵ�ʵ��ﳵ��ͼƬ
	char chPlanCarNum[128];			///<Ԥ�Ƶ��ﳵ�ƺ�
	char chRealCarNum[128];			///<ʵ�ʵ��ﳵ�ƺ�
	char chPlanCarDriver[128];		///<Ԥ�Ƶ����ʻԱ
	char chRealCarDriver[128];		///<ʵ�ʵ����ʻԱ
	char chPlanStaffImage[256];		///<Ԥ�Ƶ�����Ա��Ƭ,��$�ָ�
	char chRealStaffImage[256];		///<ʵ�ʵ�����Ա��Ƭ,��$�ָ�
	char chPlanStaffName[256];		///<Ԥ�Ƶ�����Ա����,��$�ָ�
	char chRealStaffName[256];		///<ʵ�ʵ�����Ա����,��$�ָ�
	char chPlanStaffNum[256];		///<Ԥ�Ƶ�����Ա���֤,��$�ָ�
	char chRealStaffNum[256];		///<ʵ�ʵ�����Ա���֤,��$�ָ�
	char chPlanDepartment[256];		///<Ԥ�Ƶ�����Ա����,��$�ָ�
	char chRealDepartment[256];		///<ʵ�ʵ�����Ա����,��$�ָ�
	char chRealStaffStatus[256];	///<��Ա����״̬��,��$�ָ0-������1-�쳣
	char chRFIDNum[1024];			///<������,��$�ָ�
	char chRFIDTime[1024];			///<���䵽��ʱ��,��$�ָ�
	int nProperty;					///<����
	char chProperty[256];			///<����
	
}DOOROPENSYRELATION_SET_P;

///< �Ž�������Ѻ�豸��ȡ(465-in)
typedef struct
{
	int nCondition;			///<������0-ȫ����1-�����豸id��ȡ��2-�����豸�����ȡ
	int nDeviceId;			///<�豸ID
	char chDeviceCode[64];	///<�豸����
	
}ACCESSSYRELATION_GET_P;

///< �Ž�������Ѻ�豸��ȡ(465-out)
typedef struct
{
	int nDoorId;					///<�Ž��豸ID
	char chMasterDeviceCode[64];	///<�Ž��豸����
	char chMasterDeviceName[64];	///<�Ž��豸����
	int nDeviceId;					///<�����豸��ID
	char chRelationDeviceCode[64];	///<�����豸�ı���
	char chRelationDeviceName[64];	///<�����豸������
	int nRelationType;				///<�������ͣ�0-Ѻ����֤�豸��1-Ѻ��·��̽ͷ
	int nDeviceType;				///<�豸���ͣ�0-̽ͷ��1-����ʶ���豸��2-��Աʶ���豸
	int nIsEnable;					///<�Ƿ����ã�0-���ã�1-����
	
}ACCESSSYRELATION_GET_S;

///< ��֤��Ѻ��Ϣ������ȡ(466-in)
typedef struct
{
	int nCondition;			///<������1-������֤id��ȡ��
	int nDoorOpenId;		///<��֤id
	
}DOOROPENSYRELATION_GET_P;

///< ��֤��Ѻ��Ϣ������ȡ(466-out)
typedef struct
{
	int nOpenDoorId;				///<��֤ID
	char chAreaName[128];			///<��������
	char chLineName[128];			///<Ѻ����·����
	int nLineStatus;				///<·����֤״̬��0-������1-�쳣
	char chLineAreaNodes[8000];		///<Ѻ����·�����б���$�ָ�
	char chLineAreaNodeStatus[1024];///<Ѻ����·����״̬����$�ָ������һһ��Ӧ��0-����(��ɫ)��1-��΢�쳣(��ɫ)��2-�����쳣(��ɫ)
	char chPlanTime[20];			///<Ԥ�Ƶ���ʱ��
	char chRealTime[20];			///<ʵ�ʵ���ʱ��
	char chPlanCarImage[128];		///<Ԥ�Ƶ��ﳵ��ͼƬ
	char chRealCarImage[128];		///<ʵ�ʵ��ﳵ��ͼƬ
	char chPlanCarNum[128];			///<Ԥ�Ƶ��ﳵ�ƺ�
	char chRealCarNum[128];			///<ʵ�ʵ��ﳵ�ƺ�
	char chPlanCarDriver[128];		///<Ԥ�Ƶ����ʻԱ
	char chRealCarDriver[128];		///<ʵ�ʵ����ʻԱ
	char chPlanStaffImage[256];		///<Ԥ�Ƶ�����Ա��Ƭ,��$�ָ�
	char chRealStaffImage[256];		///<ʵ�ʵ�����Ա��Ƭ,��$�ָ�
	char chPlanStaffName[256];		///<Ԥ�Ƶ�����Ա����,��$�ָ�
	char chRealStaffName[256];		///<ʵ�ʵ�����Ա����,��$�ָ�
	char chPlanStaffNum[256];		///<Ԥ�Ƶ�����Ա���֤,��$�ָ�
	char chRealStaffNum[256];		///<ʵ�ʵ�����Ա���֤,��$�ָ�
	char chPlanDepartment[256];		///<Ԥ�Ƶ�����Ա����,��$�ָ�
	char chRealDepartment[256];		///<ʵ�ʵ�����Ա����,��$�ָ�
	char chRealStaffStatus[256];	///<��Ա����״̬��,��$�ָ0-������1-�쳣
	char chRFIDNum[1024];			///<������,��$�ָ�
	char chRFIDTime[1024];			///<���䵽��ʱ��,��$�ָ�
	int nProperty;					///<����
	char chProperty[256];			///<����
	
}DOOROPENSYRELATION_GET_S;


///<��ѯ��֤��ʷ��Ϣ_SY(467-in)
typedef struct
{
    char chBeginDate[32];            ///<��֤����ʱ��  ��ʼ
    char chEndDate[32];              ///<��֤ʱ�����
    char chAreaName[64];             ///<��������
    int  nPassStatus;                ///<ͨ��״̬0-ȫ�� 1-ͬ�⿪�� 2-�ܾ�����
    int  nProcessStatus;             ///<����״̬0-ȫ�� 1-δ���� 2-������ 3-�����
    int  nIsCollection;              ///<�Ƿ��ղ� 0-ȫ�� 1-�ղ� 2-δ�ղ�
    int  nIsNomal;                   ///<¼�뷽ʽ 0-ȫ�� 1-����¼�� 2-������¼��
    int  nMethod;                    ///<����ģʽ 0-ȫ��
    int  nProcessType;               ///<���״̬ 0-ȫ�� 1-ͨ��(�ϸ�) 2-�ܾ�(���ϸ�)
    int  nPages;                     ///<ҳ��
    int  nRecords;                   ///<ÿҳ��ʾ��¼��
	int nProperty;                   ///< ����״̬��-1-ȫ����0-������1-������
	int  nAuthType;					 ///< ��֤���ͣ�-1-ȫ����0-ԭ������֤��1-��Ѻ��֤
}QUERYHISTORYINFO_SY_GET_P; 

///<��ѯ��֤��ʷ��Ϣ_SY(467-out)
typedef struct
{
    int  nId;                        ///<��֤Id
    char chAreaName[64];             ///<��������
    char chDeviceName[64];           ///<�Ž�����
    char chHappenDate[32];           ///<��֤����ʱ��
    int  nMethod;                    ///<����ʽ
    int  nProcessStatus;             ///<����״̬ 1-δ���� 2-������ 3-�����
    int  nProcessType;               ///<���״̬ 1-ͨ��(�ϸ�) 2-�ܾ�(���ϸ�)
    int  nPassStatus;                ///<ͨ��״̬1-ͬ�⿪�� 2-�ܾ�����
    char chHandleMan[128];           ///<������
    char chHandleDate[20];           ///<����ʱ��
    char chAuditor[128];             ///<�����
    char chAuditDate[20];            ///<���ʱ��
    bool bIsCollection;              ///<�Ƿ��ղ�
    bool bIsNormal;                  ///<�Ƿ�����¼��
    char chApplyType[128];           ///<��֤ģʽ
	int nProperty;                   ///< ����״̬��0-������1-������
	int  nAuthType;				     ///< ��֤���ͣ�0-ԭ������֤��1-��Ѻ��֤
    int  nSumPage;                   ///<��ҳ��
}QUERYHISTORYINFO_SY_GET_S;


///<���ݱ���Դ��ȡ���һ�������ı�������״̬(297-in)
typedef struct
{
    int nCondition;            	///<������0-��ȡ���һ�������ı�������״̬
    char chAlarmSource[64];     ///<����Դ
	char chParam[64];           ///<����������
}LASTALARMDEALSTATUS_GET_P; 

///<���ݱ���Դ��ȡ���һ�������ı�������״̬(297-out)
typedef struct
{
    int nDealStatus;			///<����״̬��0-�ǽ���״̬��2-δ����3-�����У�4-�ӳٴ���5-��ͣ����

}LASTALARMDEALSTATUS_GET_S;














/**************************************************************************/

///<------------------------------------------------------------------------------
#endif