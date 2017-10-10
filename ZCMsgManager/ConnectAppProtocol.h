/*********************************************************************
* 版权所有 (C)2010, 上海天跃科技有限公司。
*
* 文件名称：ConnectAPPProtocol.h
* 内容摘要：与APP服务器交互协议的定义
* 当前版本：V1.8.2.28
* 作   者：刘彬
* 完成日期：2016-09-13
***********************************************************************/
#ifndef CONNNECTAPP_PROTOCOL
#define CONNNECTAPP_PROTOCOL
#include "TjtyCommon.h"

///<消息请求子类型
typedef enum
{
    MSG_REQ_TEST_DUMY = 0,
    MSG_REQ_USER_LOGIN_DUMMY = 1000,                 ///<用户登录(1000)
    MSG_REQ_USER_LOGOUT_DUMMY,                       ///<用户退出(1001)
    MSG_REQ_AREA_INFO,                         ///<获取网点信息(1002)
    MSG_REQ_DEV_BASE_INFO,                     ///<设备基本信息(1003)
    MSG_REQ_DEV_AS_INFO,                       ///<AS需要的设备信息(1004)
    MSG_REQ_DEV_MS_INFO,                       ///<MS需要的设备信息(1005)
    MSG_REQ_USER_INFO,                         ///<用户信息(1006)
    MSG_REQ_USER_AUTHORITY,                    ///<用户整体权限(1007)
    MSG_REQ_USER_AUTH_DEV,                     ///<用户针对设备的权限(1008)
    MSG_REQ_USER_AUTH_CHL,                     ///<用户针对通道的权限(1009)
    MSG_REQ_CAMERA_INFO,                       ///<摄像头信息(1010)
    MSG_REQ_ALARMIN_INFO,                      ///<探头信息(1011)
    MSG_REQ_ALARMOUT_INFO,                     ///<外设信息(1012)
    MSG_REQ_AS_INFO,                           ///<AS信息(1013)
    MSG_REQ_MS_INFO,                           ///<MS信息(1014)
    MSG_REQ_DEVID_BY_ASNAME,                   ///<根据报警服务器获取相应的设备(1015)
    MSG_REQ_DEVID_BY_MSNAME,                   ///<根据媒体服务器获取相应的设备(1016)
    MSG_REQ_USER_RECV_ALARM_AUTH,              ///<用户的具体接警权限(1017)
    MSG_REQ_ALARM_INFO,                        ///<报警信息(1018)
    MSG_REQ_ALARM_DEAL_STRATEGY,               ///<报警信息处理策略(1019)
    MSG_REQ_RECORD_FILE_INFO,                  ///<录像文件信息(1020)
    MSG_REQ_STORAGE_PLAN,                      ///<获取通道的存储计划(1021)
    MSG_REQ_BACKUP_PLAN,                       ///<DVR备份计划(1022)
    MSG_REQ_ADDLOGINFO,                        ///<添加日志信息(1023)
    MSG_REQ_ADDTALKLOG,                        ///<添加对讲信息(1024)
    MSG_REQ_SETTIME_PLAN,                      ///<获取校时计划(1025)
    MSG_REQ_USER_DEV_LOGINFO,                  ///<根据用户名获取设备的登录信息(1026)
    MSG_REQ_CMS_INFO,                          ///<获取中心管理服务器信息(1027)
    MSG_REQ_STOR_STREAM_SET,                   ///<获取流式存储设置(1028)
    MSG_REQ_STOR_FILE_SET,                     ///<获取文件式存储设置(1029)
    MSG_REQ_STOR_REM_SET,                      ///<获取清盘机制设置(1030)
    MSG_REQ_STOR_PLAN_INFO,                    ///<获取存储计划信息(1031)
    MSG_REQ_DEV_STOR_PLAN,                     ///<获取设备的储存计划(1032)
    MSG_REQ_VIDEO_FILE_INFO,                   ///<获取录像文件信息(1033)
    MSG_REQ_VIDEO_FILE_DEL,                    ///<删除录像文件日志信息(1034)
    MSG_REQ_DEV_BASE_INFO_EX,                  ///<设备基本信息带设备名称(1035)
    MSG_REQ_DEV_AS_INFO_EX,                    ///<AS需要的设备信息带设备名称(1036)
    MSG_REQ_DEV_MS_INFO_EX,                    ///<MS需要的设备信息返回值带设备名称(1037)
    MSG_REQ_NEW_DEV_INFO,                      ///<获取设备基本信息（附带联动信息）(1038)
    MSG_REQ_NEW_CAMERA_INFO,                   ///<获取摄像头基本信息（附带联动信息)(1039)
    MSG_REQ_NEW_SHOW_ALLAREANODE_INFO,         ///<获取区域节点详细信息（区域）(1)+1039
    MSG_REQ_NEW_SHOW_DEVNODE_INFO,             ///<获取所有主机设备信息（DVR、报警主机、门禁）(2)+1039
    MSG_REQ_NEW_SHOW_FRONTNODE_INFO,           ///<获取所有前端设备信息（摄像头、探头、输出）(3)+1039
    MSG_REQ_NEW_SHOW_USERINFO_All,             ///<获取用户详细信息(4)+1039
    MSG_REQ_NEW_SHOW_CMSNODE_INFO,             ///<获取中心服务器详细信息(5)+1039
    MSG_REQ_NEW_SHOW_CHANNELGROUP,             ///<获取通道组信息(6)+1039
    MSG_REQ_NEW_SHOW_HOSTNODE_TALK,            ///<获取主机对讲关联信息(7)+1039
    MSG_REQ_NEW_SHOW_FRONTENDNODE_TALK,        ///<获取前端设备对讲关联信息(8)+1039
    MSG_REQ_NEW_SHOW_SCREEN_INFO,              ///<获取电视墙详细信息(9)+1039
    MSG_REQ_NEW_SHOW_EMERGENCYGROUP,           ///<获取预案组详细信息(10)+1039
    MSG_REQ_NEW_SHOW_ALARMTYPE,                ///<获取报警类型详细信息(11)+1039
    MSG_REQ_NEW_SHOW_DEVALARMSOUND,            ///<获取主机报警类型详细信息(12)+1039
    MSG_REQ_NEW_SHOW_ALARMSOUND_INFO,          ///<获取前端设备报警类型详细信息(13)+1039
    MSG_REQ_NEW_ALARMFILTER_SET,               ///<报警过滤设置(14)+1039 (add)
    MSG_REQ_NEW_ADD_NEWEVENT,                  ///<添加新事件(15)+1039 (add)
    MSG_REQ_NEW_REPLY_EVENT,                   ///<回复事件(16)+1039 (add)
    MSG_REQ_NEW_ACCESS_ALLEVTCONTEVENT,        ///<获取所有事件详细信息(17)+1039
    MSG_REQ_NEW_SHOW_NEWEVENTNUM,              ///<获取新事件的数目(18)+1039
    MSG_REQ_NEW_MODY_STATEOFUNREADEVENT,       ///<修改未读事件状态(19)+1039 (mod)
    MSG_REQ_NEW_QUERY_EVENT,                   ///<全部事件信息模糊查询(20)+1039
    MSG_REQ_NEW_SHOW_EVENTNUM,                 ///<获取全部事件信息模糊查询集数目(21)+1039
    MSG_REQ_NEW_GET_ALLLABEL,                  ///<获取所有标签信息(22)+1039
    MSG_REQ_NEW_M_EVENT_STATISTICS,            ///<客户端事件标签统计(23)+1039
    MSG_REQ_NEW_M_MODCLIENTUSER,               ///<客户端用户密码修改(24)+1039(mod)
    MSG_REQ_NEW_SHOW_ALARMINFO,                ///<报警日志信息查询(25)+1039
    MSG_REQ_NEW_STAT_ALARMINFO,                ///<报警日志统计信息(26)+1039
    MSG_REQ_NEW_SHOW_SYSLOGINFO,               ///<系统日志信息查询(27)+1039
    MSG_REQ_NEW_STAT_SYSLOGINFO,               ///<系统日志统计信息(28)+1039
    MSG_REQ_NEW_M_CRUISE,                      ///<巡航相关节点信息(29)+1039(add、mod、delete)
    MSG_REQ_NEW_M_CRUISE_SET,                  ///<巡航设置(30)+1039(add)
    MSG_REQ_NEW_SHOW_PREPOINT,                 ///<获取预置点信息(31)+1039
    MSG_REQ_NEW_SHOW_TRACE,                    ///<获取巡航信息(32)+1039
    MSG_REQ_NEW_SHOW_LOCUS,                    ///<获取轨迹信息(33)+1039
    MSG_REQ_NEW_M_GETERROR,                    ///<获取平台错误码信息(34)+1039
    MSG_REQ_NEW_SHOWOPTYPE,                    ///<获取操作日志类型信息(35)+1039
    MSG_REQ_NEW_SHOWPRIVILEGECMS,              ///<256通道中心获取设备权限信息(36)+1039
    MSG_REQ_NEW_SHOWPRIVILEGECLIENT,           ///<256通道客户端获取设备权限信息(37)+1039
    MSG_REQ_NEW_ADD_USERINFO,                  ///<添加用户信息(38)+1039(add)
    MSG_REQ_NEW_MOD_USERINFO,                  ///<修改用户信息(39)+1039(mod)
    MSG_REQ_NEW_DEL_USERINFO,                  ///<删除用户信息(40)+1039(del)
    MSG_REQ_NEW_SHOW_ROLEINFO,                 ///<显示角色信息(41)+1039
    MSG_REQ_NEW_ROLEINFO,                      ///<角色相关操作信息(42)+1039(add、mod、del)
    MSG_REQ_NEW_AREACODEINFO,                  ///<省份区域编码信息(43)+1039
    MSG_REQ_NEW_SHOW_NODETYPE_INFO,            ///<获取节点类型信息(44)+1039
    MSG_REQ_NEW_MOD_NODETYPE_INFO,             ///<修改节点类型信息(45)+1039(mod)
    MSG_REQ_NEW_ABOUTLABEL,                    ///<标签相关信息操作(46)+1039(add、mod、del)
    MSG_REQ_NEW_SHOWLABEL,                     ///<获取标签相关信息(47)+1039
    MSG_REQ_NEW_CAMAREA,                       ///<摄像头区域相关信息操作(48)+1039(add、mod、del)
    MSG_REQ_NEW_SHOWCAMAREA,                   ///<获取摄像头区域相关信息(49)+1039
    MSG_REQ_NEW_SHOWLOGINFO,                   ///<获取日志信息(50)+1039
    MSG_REQ_NEW_SETTIMEPLAN,                   ///<设置校时计划信息(51)+1039
    MSG_REQ_NEW_SHOWTIMEPLAN,                  ///<获取校时计划信息(52)+1039
    MSG_REQ_NEW_MOST_SET,                      ///<批量设置(图片、码流)(53)+1039
    MSG_REQ_NEW_PARTION,                       ///<分区相关信息操作(54)+1039(add、mod、del)
    MSG_REQ_NEW_MODPARTAREA,                   ///<修改防区所属分区(55)+1039(mod)
    MSG_REQ_NEW_SHOWPARTINFO,                  ///<显示具体报警主机的分区-防区信息(56)+1039
    MSG_REQ_NEW_SET_ROLEAUTHORITY,             ///<角色权限信息设置(57)+1039
    MSG_REQ_NEW_M_SHOWPRIVILEGE,               ///<角色权限信息查询(58)+1039
    MSG_REQ_NEW_SCREEN_SET,                    ///<电视墙信息设置(59)+1039
    MSG_REQ_NEW_SET_M_EMERGENCY,               ///<预案信息设置(60)+1039
    MSG_REQ_NEW_SHOW_USER_AREA,                ///<获取用户过滤网点信息(61)+1039
    MSG_REQ_NEW_INTO_ROLE,                     ///<修改用户所属角色(62)+1039
    MSG_REQ_NEW_CHANNELGROUP,                  ///<通道组信息相关操作(63)+1039(add、mod、del)
    MSG_REQ_NEW_SHOWCHANNELGROUP,              ///<通道组显示相关操作(64)+1039
    MSG_REQ_NEW_SETCHANNELGROUP,               ///<通道组设置相关操作(65)+1039
    MSG_REQ_NEW_SHOW_SQLMANAGE,                ///<显示数据库空间管理信息(66)+1039
    MSG_REQ_NEW_SET_CLEANTIME,                 ///<设置报警日志清理时间(67)+1039
    MSG_REQ_NEW_GET_SQLINFO,                   ///<获取数据库备份路径信息(68)+1039
    MSG_REQ_NEW_SAVE_SQLINFO,                  ///<设置数据库备份路径(69)+1039
    MSG_REQ_NEW_M_SQLPOSITION,                 ///<获取存储磁盘信息(70)+1039
    MSG_REQ_NEW_CONFIGCLIENT_LOGIN,            ///<判断配置客户端登录账号信息(71)+1039
    MSG_REQ_NEW_GET_CONFIG_LOGIN,              ///<获取配置客户端登录具体设备的账号信息(72)+1039
    MSG_REQ_NEW_SET_SERVERLOGIN,               ///<设置服务器登录信息(73)+1039
    MSG_REQ_NEW_SHOW_DEVLOGIN_CONDITION,       ///<显示服务器登录信息(74)+1039
    MSG_REQ_NEW_LOGINDEL_SERVER,               ///<服务器登录设备删除(75)+1039
    MSG_REQ_NEW_LOGINCLEAN_SERVER,             ///<服务器登录设备清空(76)+1039
    MSG_REQ_NEW_SET_CLIENTLOGIN,               ///<设置客户端登录信息(77)+1039
    MSG_REQ_NEW_SHOW_CLIENTLOGIN,              ///<显示客户端登录信息(78)+1039
    MSG_REQ_NEW_LOGINDEL_CLIENT,               ///<客户端登录设备删除(79)+1039
    MSG_REQ_NEW_LOGINCLEAN_CLIENT,             ///<客户端登录设备清空(80)+1039
    MSG_REQ_NEW_M_COPYLOGIN,                   ///<复制用户登录密码(81)+1039
    MSG_REQ_NEW_SET_VIDEOCONFIG,               ///<存储配置设置(82)+1039
    MSG_REQ_NEW_SET_STORAGEPLAN,               ///<设置存储计划(83)+1039
    MSG_REQ_NEW_SET_FRONTEND_PLAN_WEEK,        ///<设置通道存储计划相关信息(84)+1039
    MSG_REQ_NEW_SHOW_VIDEOSET_INFO,            ///<显示存储配置设置信息(85)+1039
    MSG_REQ_NEW_SHOW_CLEARDISK_INFO,           ///<显示清盘设置(86)+1039
    MSG_REQ_NEW_SHOW_STORAGEVIEW,              ///<显示存储计划相关信息(87)+1039
    MSG_REQ_NEW_DEL_STORAGEPLAN,               ///<删除存储计划(88)+1039
    MSG_REQ_NEW_CMSNODE_INFO,                  ///<中心管理服务器相关操作(89)+1039(add、mod、del)
    MSG_REQ_NEW_MSNODE_INFO,                   ///<媒体服务器相关操作(90)+1039(add、mod、del)
    MSG_REQ_NEW_SHOW_MSNODE_INFO,              ///<显示媒体服务器详细信息(91)+1039
    MSG_REQ_NEW_ADD_MSCONFIG,                  ///<媒体服务器划分设置(92)+1039
    MSG_REQ_NEW_DEL_MSCONFIG,                  ///<删除媒体服务器划分设置(93)+1039
    MSG_REQ_NEW_SHOW_MSDEV_INFO,               ///<显示媒体服务器划分详细信息(94)+1039
    MSG_REQ_NEW_ASNODE_INFO,                   ///<报警服务器相关操作(95)+1039(add、mod、del)
    MSG_REQ_NEW_SHOW_ASNODE_INFO,              ///<显示报警服务器详细信息(96)+1039
    MSG_REQ_NEW_ADD_ASCONFIG,                  ///<报警服务器划分设置(97)+1039
    MSG_REQ_NEW_DEL_ASCONFIG,                  ///<删除报警服务器划分设置(98)+1039
    MSG_REQ_NEW_SHOW_ASDEV_INFO,               ///<显示报警服务器划分详细信息(99)+1039
    MSG_REQ_NEW_M_GETALRAMID,                  ///<获取最大报警编号(100)+1039
    MSG_REQ_NEW_ALARMTYPE_INFO,                ///<报警类型相关操作(101)+1039
    MSG_REQ_NEW_SHOW_ALARMCONFIG,              ///<显示报警配置详细信息(102)+1039
    MSG_REQ_NEW_AREANODEINFO,                  ///<区域节点信息相关操作(103)+1039(add、mod、del)
    MSG_REQ_NEW_AREANODEMOVE,                  ///<区域节点移动(104)+1039
    MSG_REQ_NEW_MAXAREANODE,                   ///<获取最大区域节点(105)+1039
    MSG_REQ_NEW_DEVNODEINFO,                   ///<设备节点信息相关操作(106)+1039(add、mod、del)
    MSG_REQ_NEW_DEVNODEMOVE,                   ///<设备节点移动(107)+1039
    MSG_REQ_NEW_FRONTENDNODEINFO,              ///<前端节点信息相关操作(108)+1039(add、mod、del)
    MSG_REQ_NEW_FRONTENDNODEMOVE,              ///<前端节点移动(109)+1039
    MSG_REQ_NEW_SHOW_MANUFATURE,               ///<显示品牌信息(110)+1039
    MSG_REQ_NEW_SHOW_IP,                       ///<显示IP信息(111)+1039
    MSG_REQ_NEW_SHOWINFOBYDEV,                 ///<根据相关条件显示设备信息(112)+1039
    MSG_REQ_NEW_SETDEVLOGIN,                   ///<设置DEV登录用户密码(113)+1039
    MSG_REQ_NEW_FRONTENDSOUND,                 ///<根据前端设备名显示报警类型声音(114)+1039
    MSG_REQ_NEW_FRONTENDTALK,                  ///<根据前端设备名显示联动对讲通道(115)+1039
    MSG_REQ_NEW_FRONTNODEINFO,                 ///<根据前端设备名显示其节点详细信息(116)+1039
    MSG_REQ_NEW_AUTOMODNAME,                   ///<远程通道名匹配(117)+1039
    MSG_REQ_NEW_CONFIGCHECK,                   ///<配置体检项(118)+1039
    MSG_REQ_NEW_EXCELCHECK,                    ///<设备信息总览(119)+1039
    MSG_REQ_NEW_GETPHONEUSER,                  ///<手机获取用户信息(120)+1039
    MSG_REQ_NEW_MODPHONEUSER,                  ///<手机修改用户信息(121)+1039
    MSG_REQ_NEW_ALARMPARTION,                  ///<显示报警主机分防区信息(122)+1039
    MSG_REQ_NEW_ONLYONE,                       ///<显示单个信息(123)+1039
    MSG_REQ_NEW_USERIMAGE,                     ///<手机获取所有用户头像信息(124)+1039
    MSG_REQ_NEW_EVENTBYPHONE,                  ///<手机获取所有事件详细信息(125)+1039
    MSG_REQ_NEW_REPLYBYONE,                    ///<手机获取指定事件的所有回复(126)+1039
    MSG_REQ_NEW_ALLEVENTPHONE,                 ///<手机获取所有事件(通过时间)(127)+1039
    MSG_REQ_NEW_GSMAPSET,                      ///<GS经纬度设置(128)+1039
    MSG_REQ_NEW_GSMAPSHOW,                     ///<GS设置信息获取(129)+1039
    MSG_REQ_NEW_IMAGEFILESET,                  ///<IMAGE文件设置(130)+1039
    MSG_REQ_NEW_MODONEINCIDENT,                ///<手机单事件状态修改(131)+1039
    MSG_REQ_NEW_M_COPYSERVER,                  ///<复制服务器登录信息(132)+1039
    MSG_REQ_NEW_GSMAPDET,                      ///<GS节点删除(133)+1039
    MSG_REQ_NEW_GSMAPSHOWINFO,                 ///<GS区域信息获取(134)+1039
    MSG_REQ_NEW_DVRSORTSHOWINFO,               ///<按品牌排序获取所有主机(135)+1039
    MSG_REQ_NEW_ALARMDEALINTO,                 ///<客户端报警处理提交(136)+1039
    MSG_REQ_NEW_NEXTCENTER,                    ///<获取所有下级中心编号(137)+1039
    MSG_REQ_NEW_ALARMPROCESS,                  ///<批量处理报警(138)+1039
    MSG_REQ_NEW_ALARMTOP,                      ///<报警排行(139)+1039
    MSG_REG_NEW_DEVICEBASEINFO,                ///<服务器获取设备基本信息(+品牌名称)(140)+1039(CMS)
    MSG_REG_NEW_DEVICEBASERELATEINFO,          ///<服务器获取设备基本信息(+品牌名称+联动)(141)+1039(CMS)
    MSG_REG_NEW_MS_DEVICEBASEINFO,             ///<服务器获取设备基本信息(+品牌名称)(142)+1039(MS)
    MSG_REG_NEW_AS_DEVICEBASEINFO,             ///<服务器获取设备基本信息(+品牌名称)(143)+1039(AS)
    MSG_REG_NEW_ALRAMEPLAN,                    ///<报警预案操作(144)+1039(add、mod、del)
    MSG_REG_NEW_ALRAMEPLANRELATE,              ///<报警预案关联操作(145)+1039(add、del)
    MSG_REG_NEW_SHOWALARMEPLAN,                ///<显示报警预案信息(146)+1039
    MSG_REG_NEW_SHOWALARMEPLANINFO,            ///<显示报警预案详细信息(147)+1039
    MSG_REG_NEW_SHOWALARMEPLANRET,             ///<显示报警预案关联信息(148)+1039
    MSG_REG_NEW_NEWTVSCREEN,                   ///<可视化电视墙操作(149)+1039(add、mod、del)
    MSG_REG_NEW_SHOWNEWTVSCREEN,               ///<显示可视化电视墙信息(150)+1039
    MSG_REG_NEW_STATICSAREAALARMNUM,           ///<网点报警数量统计(151)+1039
    MSG_REG_NEW_SHOWALARMLEVEL,                ///<显示报警等级信息(152)+1039
    MSG_REG_NEW_SHOWALARMLEVELPLOY,            ///<显示报警等级策略信息(153)+1039
    MSG_REG_NEW_SETALARMLEVELPLOY,             ///<设置报警等级策略信息(154)+1039
    MSG_REG_NEW_SHOWPOSITIONINFO,              ///<获取部位信息(155)+1039
    MSG_REG_NEW_SHOWLOCATIONINFO,              ///<获取场所信息(156)+1039
    MSG_REG_NEW_OPACTIONLIB,                   ///<动作库基本操作(157)+1039(add、mod、del)
    MSG_REG_NEW_SHOWACTIONLIB,                 ///<获取动作库(158)+1039
    MSG_REG_NEW_OPEVENTLIB,                    ///<事件库基本操作(159)+1039(add、mod、del)
    MSG_REG_NEW_SHOWEVENTLIB,                  ///<获取事件库(160)+1039
    MSG_REG_NEW_OPPLANLIB,                     ///<预案库基本操作(161)+1039(add、mod、del)
    MSG_REG_NEW_SHOWPLANLIB,                   ///<获取预案库(162)+1039
    MSG_REG_NEW_SHOWALWAYSDEAL,                ///<获取常用处理语句信息(163)+1039
    MSG_REG_NEW_SHOWDEALCONSEQUECE,            ///<获取处理方式信息(164)+1039
    MSG_REG_NEW_WRITEDEALRESULT,               ///<写入报警处理结果(165)+1039
    MSG_REG_NEW_SHOWHISTORYDEAL,               ///<根据某报警源获取历史处理信息(166)+1039
    MSG_REG_NEW_COMPLEXSTATICS,                ///<报警处理信息的综合统计(167)+1039
    MSG_REG_NEW_COMPLEXCHECK,                  ///<报警处理信息的综合查询(168)+1039
    MSG_REG_NEW_COMPLEXTOP,                    ///<报警处理信息的综合排行(169)+1039
    MSG_REG_NEW_SHOWPLANINFOBYALARM,           ///<根据报警信息ID获取对应预案信息(170)+1039
    MSG_REG_NEW_SHOWALARMINFOBYALARM,          ///<根据报警部分信息获取报警详细信息(171)+1039
    MSG_REG_NEW_OPUSERGRAPHINFO,               ///<用户图表基本操作(172)+1039(add、mod、del)
    MSG_REG_NEW_OPUSERREPORTINFO,              ///<用户报告基本操作(173)+1039(add、mod、del)
    MSG_REG_NEW_MODSTATUSUSERREPORT,           ///<修改用户报告状态(174)+1039(mod)
    MSG_REG_NEW_SHOWUSERGRAPHINFO,             ///<获取用户图表信息(175)+1039
    MSG_REG_NEW_SHOWUSERREPORTINFO,            ///<获取用户报告信息(176)+1039
    MSG_REG_NEW_SHOWALARMBACKINFO,             ///<报警回溯详细信息(177)+1039
    MSG_REG_NEW_SHOWUSERREPORTBOOKINFO,        ///<获取用户报告订阅信息数据(178)+1039
    MSG_REG_NEW_OPAREAPLACEINFO,               ///<场所基本操作(179)+1039(add、mod、del)
    MSG_REG_NEW_OPKEYPARTINFO,                 ///<部位基本操作(180)+1039(add、mod、del)
    MSG_REG_NEW_OPALARMLEVELINFO,              ///<报警等级基本操作(181)+1039(add、mod、del)
    MSG_REG_NEW_OPTIMEMODEL,                   ///<时间模板基本操作(182)+1039(add、mod、del)
    MSG_REG_NEW_SHOWTIMEMODEL,                 ///<时间模板信息获取(183)+1039
    MSG_REG_NEW_SETMULALARMLEVEL,              ///<报警等级划分批量设置(184)+1039(add、del)
    MSG_REG_NEW_SHOWMULALARMLEVEL,             ///<报警等级划分批量设置信息获取(185)+1039
    MSG_REG_NEW_SETSINALARMLEVEL,              ///<报警等级划分特殊设置(186)+1039(add、del)
    MSG_REG_NEW_SHOWSINALARMLEVEL,             ///<报警等级划分特殊设置信息获取(187)+1039
    MSG_REG_NEW_DEVICEBASEINFOLEVEL,           ///<报警服务器获取设备基本信息(+场所、部位)(188)+1039
    MSG_REG_NEW_PLACEKEYPARTMODEL,             ///<场所、部位、报警类型、时间模板(名称+ID)(189)+1039
    MSG_REG_NEW_PLACEKEYPARTBYNAME,            ///<根据名称获取场所、部位(190)
    MSG_REG_NEW_SHOWALARMBYDEVNAME,            ///<根据名称获取关联报警类型(191)
    MSG_REG_NEW_SHOWUNHANDLEALARMCOUNT,        ///<显示未处置报警数目(192)
    MSG_REG_NEW_SET_PLACEKEYPART,              ///<批量设置场所、部位(193)
    MSG_REG_NEW_SHOW_AREAPLACESET,             ///<获取场所批量设置信息(194)
    MSG_REG_NEW_SHOW_KEYPARTSET,               ///<获取部位批量设置信息(195)
    MSG_REG_NEW_SHOWTODAYCLASSES,              ///<获取今日排班信息(196)
    MSG_REG_NEW_SHOW_HA_CURUSER,               ///<获取当前交班用户信息(197)
    MSG_REG_NEW_SHOW_HA_WAITUSERLIST,          ///<获取待接班人员信息(198)
    MSG_REG_NEW_SHOW_HA_A_TASKINFO,            ///<获取值班员任务执行情况(199)
    MSG_REG_NEW_SHOW_HA_M_TASKINFO,            ///<获取值班长任务执行情况(200)
    MSG_REG_NEW_SHOW_HA_ALARMINFO,             ///<获取班次内未处理报警信息(201)
    MSG_REG_NEW_ADD_HA_INFO,                   ///<提交交班信息(202)
    MSG_REG_NEW_SHOW_HA_INFO,                  ///<获取交接班历史信息(203)
    MSG_REG_NEW_TASKDISTREBUTE_SET,            ///<触发数据库分发任务(204)
    MSG_REG_NEW_INSPECT_ROLESET,               ///<主动巡查角色扩展操作(205)
    MSG_REG_NEW_INSPECT_ROLESHOW,              ///<主动巡查角色扩展信息获取(206)
    MSG_REG_NEW_INSPECT_ABORTLIBSET,           ///<主动巡查异常库操作(207)
    MSG_REG_NEW_INSPECT_ABORTLIBSHOW,          ///<主动巡查异常库信息获取(208)
    MSG_REG_NEW_INSPECT_DATEGROUPSET,          ///<主动巡查日期组操作(209)
    MSG_REG_NEW_INSPECT_DATEGROUPSHOW,         ///<主动巡查日期组信息获取(210)
    MSG_REG_NEW_INSPECT_CLASSINFOSET,          ///<主动巡查班次信息操作(211)
    MSG_REG_NEW_INSPECT_CLASSINFOSHOW,         ///<主动巡查班次信息获取(212)
    MSG_REG_NEW_INSPECT_SCHEDULEINFOSET,       ///<主动巡查排班信息操作(213)
    MSG_REG_NEW_INSPECT_SCHEDULEINFOSHOW,      ///<主动巡查排班信息获取(214)
    MSG_REG_NEW_INSPECT_CLASSUSERINFOSHOW,     ///<主动巡查班次-用户信息获取(215)
    MSG_REG_NEW_INSPECT_CLASSMODULESET,        ///<主动巡查班次模板基本操作(216)
    MSG_REG_NEW_INSPECT_TASKINFOSET,           ///<主动巡查任务信息基本操作(217)
    MSG_REG_NEW_INSPECT_FASTTASKINFOSET,       ///<主动巡查快速任务信息基本操作(218)
    MSG_REG_NEW_INSPECT_TASKMODULESET,         ///<主动巡查任务模板基本操作(219)
    MSG_REG_NEW_INSPECT_TASKEXCUTESET,         ///<主动巡查任务执行插入(220)
    MSG_REG_NEW_INSPECT_CHECKRECORDSET,        ///<主动巡查批阅记录添加(221)
    MSG_REG_NEW_INSPECT_TASKSTATUSMOD,         ///<主动巡查任务下发状态修改(222)
    MSG_REG_NEW_INSPECT_ISQUALIFIEDMOD,        ///<主动巡查异常表合格状态修改(223)
    MSG_REG_NEW_INSPECT_EXCUTEERRORSET,        ///<主动巡查异常表插入(224)
    MSG_REG_NEW_INSPECT_CURDUTYPEOPLEINFO,     ///<获取当前值班人员信息(225)
    MSG_REG_NEW_INSPECT_SHOWALLTASKINFO,       ///<获取所有任务详细信息(226)
    MSG_REG_NEW_INSPECT_TASKOPERATIONINFOSHOW, ///<获取任务操作类型信息(227)
    MSG_REG_NEW_INSPECT_TASKLEVELINFOSHOW,     ///<获取任务重要程度信息(228)
    MSG_REG_NEW_INSPECT_TASKMODULEINFOSHOW,    ///<获取任务模板信息(229)
    MSG_REG_NEW_INSPECT_CHANNELKEYPARTINFOSHOW,///<获取所有通道部位信息(230)
    MSG_REG_NEW_INSPECT_ROLEDEVINFOSHOW,       ///<根据角色获取其权限信息(231)
    MSG_REG_NEW_INSPECT_TASKSENDROLEINFO,      ///<根据班次获取任务下发角色(232)
    MSG_REG_NEW_INSPECT_TASKOBJECTINFO,        ///<获取任务对象信息(233)
    MSG_REG_NEW_INSPECT_CLASSCONFIRMSETINFO,   ///<上、下班签到设置(234)
    MSG_REG_NEW_INSPECT_TODAYTASKINFOSHOW,     ///<获取某用户的今日任务(235)
    MSG_REG_NEW_INSPECT_TODAYTASKALLINFOSHOW,  ///<获取某条下发任务的执行信息(236)
    MSG_REG_NEW_INSPECT_USERTASKINFOSHOW,      ///<获取用户多日任务(237)
    MSG_REG_NEW_INSPECT_CHECKTASKINFOSHOW,     ///<任务查询(238)
    MSG_REG_NEW_INSPECT_SHOWTASKCHECKINFO,     ///<任务复核信息(239)
    MSG_REG_NEW_INSPECT_SHOWTASKEPLANINFO,     ///<任务相关预案信息(240)
    MSG_REG_NEW_INSPECT_SHOWAREAERRORINFO,     ///<某具体网点异常项发生情况(241)
    MSG_REG_NEW_INSPECT_SHOWAREAERRORATEINFO,  ///<网点的异常率(242)
    MSG_REG_NEW_INSPECT_SHOWCOVERRATEINFO,     ///<巡检覆盖率(243)
    MSG_REG_NEW_INSPECT_SHOWAREAERRORNUMINFO,  ///<单位时间内的网点异常数量统计(244)
    MSG_REG_NEW_INSPECT_SHOWERRORCHECKRATEINFO,///<异常的复查合格率(245)
    MSG_REG_NEW_INSPECT_SHOWALARMRECORINFO,    ///<提醒(246)
    MSG_REG_NEW_SHOW_JH_DEVICEINFO,            ///<设备类型、品牌、型号信息查询(247)
    MSG_REG_NEW_CHECK_JH_DEVICEINFO,           ///<设备管理信息查询(248)
    MSG_REG_NEW_STATICS_JH_DEVICEINFO,         ///<设备管理信息统计(249)
    MSG_REG_NEW_JH_INSERT_ALARMINFO,           ///<报警信息插入(250)
    MSG_REG_NEW_JH_COMPLEXCHECK,               ///<报警处理信息的综合查询(251)
    MSG_REG_NEW_JH_DATABASEINFO,               ///<查询数据库配置字符串(252)
    MSG_REG_NEW_INSPECT_STATICS_TASKADDINFO,   ///<任务添加类统计信息(253)
    MSG_REG_NEW_INSPECT_STATICS_EMPLOYANALY,   ///<员工的能力分析统计信息(254)
    MSG_REG_NEW_INSPECT_STATICS_EMPLOYMANAGER, ///<员工管理类统计信息(255)
    MSG_REG_NEW_IP_POOL_SET,                   ///<用户IP池设置(256)
    MSG_REG_NEW_IP_POOL_SHOW,                  ///<用户IP池信息获取(257)
    MSG_REG_NEW_USEFULPSW_SET,                 ///<密码有效期设置(258)
    MSG_REG_NEW_USEFULPSW_SHOW,                ///<密码有效期信息获取(259)
    MSG_REG_NEW_USERPSWINFO_SHOW,              ///<服务器获取用户密码信息(260)[MD5]
    MSG_REG_NEW_ALARMDISPOSAL_USEFULTYPE,      ///<有效报警类型获取(261)
    MSG_REG_NEW_ALARMDISPOSAL_USEFULPLACEKEY,  ///<有效场所部位信息获取(262)
    MSG_REG_NEW_ALARMDISPOSAL_AUTH_SHOW,       ///<根据用户名获取报警处置权限(263)
    MSG_REG_NEW_ALARMDISPOSAL_PLOY_SHOW,       ///<获取报警等级处置策略(264)
    MSG_REG_NEW_ALARMDISPOSAL_DUTYSTATUS_SET,  ///<设置值班员状态(265)
    MSG_REG_NEW_ALARMDISPOSAL_STATUS_SET,      ///<设置报警信息处置状态(266)
    MSG_REG_NEW_ALARMDISPOSAL_PEOPLE_SET,      ///<设置报警信息处置人(267)
    MSG_REG_NEW_ALARMDISPOSAL_DEALSULT_SET,    ///<提交报警处置结果(268)
    MSG_REG_NEW_ALARMDISPOSAL_USERSTATUS_SHOW, ///<获取用户空闲状态(269)
    MSG_REG_NEW_ALARMDISPOSAL_ALM_SET,         ///<报警等级策略设置(270)
    MSG_REG_NEW_ALARMDISPOSAL_USERAL_SHOW,     ///<获取用户能处理的报警等级(271)
    MSG_REG_NEW_ALARMDISPOSAL_ACATEGORY_SET,   ///<警情类型、定性戳信息设置(272)(add、mod、del)
    MSG_REG_NEW_ALARMDISPOSAL_ACATEGORY_SHOW,  ///<警情类型、定性戳信息获取(273)
    MSG_REG_NEW_ALARMDISPOSAL_MODULEANTH_SHOW, ///<模块权限信息获取(274)
    MSG_REG_NEW_ALARMDISPOSAL_AMA_SHOW,        ///<根据报警等级获取报警权限信息(275)
    MSG_REG_NEW_ALARMDISPOSAL_ASSINGLE_SET,    ///<人工干预报警插入(276)
    MSG_REG_NEW_ALARMDISPOSAL_ASINFO_SHOW,     ///<某用户未处理完成的报警信息(277)
    MSG_REG_NEW_ALARMDISPOSAL_ANEXT_SHOW,      ///<获取所有用户下属信息(278)
    MSG_REG_NEW_ALARMDISPOSAL_AM_SHOW,         ///<根据报警ID获取报警批注记录信息(279)
    MSG_REG_NEW_ALARMDISPOSAL_AO_SHOW,         ///<根据报警ID获取操作记录信息(280)
    MSG_REG_NEW_ALARMDISPOSAL_CRM_SET,         ///<增加批阅记录(281)
    MSG_REG_NEW_ALARMDISPOSAL_AC_SET,          ///<报警复核(282)
    MSG_REG_NEW_ALARMDISPOSAL_ACI_SET,         ///<报警复核日志插入(283)
    MSG_REG_NEW_ALARMDISPOSAL_AD_SET,          ///<报警延时处置存储(284)
    MSG_REG_NEW_ALARMCHECKED_PERSONS_NUM,      ///<获取拥有报警复核权限的角色的数量(285)
    MSG_REG_NEW_ALARMDISPOSAL_PEOPLE_BATCHSET, ///<批量设置报警处置人(286)
    MSG_REG_NEW_ALARMCHECKED_IFSETED,          ///<获取上级复核权限是否被设置(287)
    MSG_REQ_NEW_AS_USERINFO_ADD,               ///<增加用户信息(288)
    MSG_REQ_NEW_AS_USERINFO_GET,               ///<获取所有用户信息(289)
	MSG_REQ_NEW_POSITIONINFO_GET_NEW,	       ///<获取位置信息，配置客户端右键使用(290)
	MSG_REQ_NEW_FILESERVERINFO_GET,	       	   ///<获取文件服务器配置信息(291)
	MSG_REQ_NEW_FILESERVERINFO_SET,	       	   ///<文件服务器路径设置(292)
	MSG_REG_NEW_OPACTIONLIB_NEW,               ///<动作库基本操作_NEW(293)
	MSG_REG_NEW_INSPECT_CHECKTASKINFOWITHLOCK, ///<任务查询_NEW(294)
	MSG_REG_NEW_JH_COMPLEXCHECKWITHLOCK,       ///<报警处理信息的综合查询WITHLOCK（295）
	MSG_REG_NEW_DOOROPENAPPLY_HISTORYINFOWITHLOCK,    ///<查询认证历史信息(296)
	MSG_REG_NEW_LASTALARMDEALSTATUS_GET,   	   ///<根据报警源获取最近一条报警的报警处置状态(297)

	
	
	//三方认证
    MSG_REG_NEW_CTRLLEVEL_SHOW = 400,                  ///<显示管控等级信息 (400)
    MSG_REG_NEW_CTRLLEVEL_MOD,                         ///<修改管控等级信息(401)
    MSG_REG_NEW_CTRLLEVELMUL_SHOW,                     ///<批量获取管控等级 (402)
    MSG_REG_NEW_DOOROPENAPPLY_BYCARD,                  ///<刷卡开门请求 (403)
    MSG_REG_NEW_DOOROPENAPPLY_EPLAN_ADD,               ///<插入开门认证预案信息(404)
    MSG_REG_NEW_DOOROPENAPPLY_METHOD_MODIFY,           ///<修改处置方式(405)
    MSG_REG_NEW_DOOROPENAPPLY_PROCESSSTATUS_MODIFY,    ///<修改认证状态 (406)
    MSG_REG_NEW_DOOROPENAPPLY_AUDITOR,                 ///<开门申请审核(407)
    MSG_REG_NEW_DOOROPENAPPLY_ISCOLLECTION,            ///<开门申请收藏 (408)
    MSG_REG_NEW_DOOROPENAPPLY_INFO_ADD,                ///<开门申请信息插入(409)
    MSG_REG_NEW_DOOROPENAPPLY_USERINFO_SET,            ///<用户认证基本设置(410)
    MSG_REG_NEW_DOOROPENAPPLY_ATTACHMENTINFO_ADD,      ///<认证动作日志表插入(411)
    MSG_REG_NEW_DOOROPENAPPLY_APPLYLOG_ADD,            ///<认证系统日志插入(412)
    MSG_REG_NEW_DOOROPENAPPLY_MEMO_ADD,                ///<认证处理意见插入(413)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSLOG_ADD,           ///<刷卡信息插入(414)
    MSG_REG_NEW_DOOROPENAPPLY_CLASSSCHEDULE_ADD,       ///<班次插入(415)
    MSG_REG_NEW_DOOROPENAPPLY_PASSWORD_SHOW,           ///<获取用户审核密码信息(416)
    MSG_REG_NEW_DOOROPENAPPLY_ALLACCESSINFO_SHOW,      ///<获取所有门禁主机信息(417)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSOTHERINFO_SHOW,    ///<获取门禁主机关联信息(418)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSTALKINFO_SHOW,     ///<获取门禁主机关联对讲信息(419)
    MSG_REG_NEW_DOOROPENAPPLY_PEPOLEINFO_SHOW,         ///<获取所有需管辖的出入人员信息(420)
    MSG_REG_NEW_DOOROPENAPPLY_SHOULDPEPOLE_SHOW,       ///<获取应到人员信息(421)
    MSG_REG_NEW_DOOROPENAPPLY_HISTORYINFO_SHOW,        ///<查询认证历史信息(422)
    MSG_REG_NEW_DOOROPENAPPLY_DETAIL_SHOW,             ///<查询认证历史详细信息认证详情(423)
    MSG_REG_NEW_DOOROPENAPPLY_ATTACHMENT_SHOW ,        ///<查询认证操作列表(424)
    MSG_REG_NEW_DOOROPENAPPLY_ACTIONDETAIL_SHOW,       ///<查询认证预案步骤信息(425)
    MSG_REG_NEW_DOOROPENAPPLY_PROCESSMEMO_SHOW,        ///<查询认证处理意见列表(426)
    MSG_REG_NEW_DOOROPENAPPLY_ACTLOG_SHOW,             ///<查询认证系统日志列表(427)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSLOG_SHOW,          ///<查询认证关联刷卡信息列表(428)
    MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFO_SHOW,         ///<查询刷卡历史信息(429)
    MSG_REG_NEW_DOOROPENAPPLY_STATISTICS_SHOW,         ///<查询统计信息(430)
    MSG_REG_NEW_DOOROPENAPPLY_EXCEPTIONINFO_ADD,       ///<异常卡信息插入(431)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSRELATION_SET,      ///<门禁主机名称进关联(432)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSRELATION,          ///<关联门禁关系(433)
    MSG_REG_NEW_CTRLLEVELPLAN_SHOW,                    ///<获取管控等级策略(434)
    MSG_REG_NEW_DOOROPENAPPLY_DEPARTMENTINFO,          ///<获取部门信息(435)
    MSG_REG_NEW_DOOROPENAPPLY_APPLYINFOCOUNT_GET,      ///<获取认证历史信息总条数(436)
    MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFOCOUNT_GET,     ///<获取刷卡历史信息总条数(437)
    MSG_REG_NEW_CTRLLEVELPLAN_PLANPROJECT,             ///<获取策略设置项(438)
    MSG_REG_NEW_CTRLLEVELPLAN_ALLDEVINFO_CL_SHOW,      ///<获取所有设备的管控等级信息(439)
    MSG_REG_NEW_CTRLLEVELPLAN_PLANCONFIGINFO_GET,      ///<获取策略设置项的配置信息(440)
    MSG_REG_NEW_CTRLLEVELPLAN_PLANCONFIGINFO_SET,      ///<设置策略设置项的配置信息(441)
    MSG_REG_NEW_ALLIPTALKDEVICEINFO,                   ///<获取IP对讲设备信息(442)
    MSG_REG_NEW_IPTALKPANELINFO_GET,                   ///<获取IP对讲设备面板信息(443)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSIPTALK_SET,        ///<门禁对讲联动设置(444)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSIPTALK_GET,        ///<门禁对讲联动获取(445)
    MSG_REG_NEW_CTRLLEVELPLAN_CTRLLEVELSET,            ///<管控等级划分设置(446)
	MSG_REG_NEW_BSAPPVERSION_SHOW,                     ///<获取BSAPP版本信息(447)
    MSG_REG_NEW_DOOROPENAPPLY_ACCESSMS_SCSGET,         ///<配置客户端门禁主从关系获取（448）
	MSG_REG_NEW_USERDOORCAMERARELATION_GET,       	   ///<获取用户门禁摄像机关联-配置客户端（449）
	MSG_REG_NEW_DOOROPENAPPLY_BYCARDINFO_SHOW_NEW,     ///<查询刷卡历史信息_NEW(450)
	MSG_REG_NEW_USERDOORCAMERARELATION_CLIENT_GET,     ///<获取用户门禁摄像机关联-客户端（451）
	MSG_REG_NEW_USERDOORCAMERARELATION_SET,     	   ///<用户门禁摄像机关联设置（452）
	MSG_REG_NEW_STAFFINFOOPERATION,			     	   ///<人员信息相关操作（453）
	MSG_REG_NEW_DEPARTMENTINFOOPERATION,     	  	   ///<部门信息相关操作（454）
	MSG_REG_NEW_STAFFSTATUS_SET,     	  			   ///<人员状态设置（455）
	MSG_REG_NEW_DEPARTMENTINFO_GET,     	  		   ///<获取部门信息(456)
	MSG_REG_NEW_AUTHGROUP_GET,     	  			  	   ///<获取权限组信息（457）
	MSG_REG_NEW_STAFFINFO_GET,     	  			   	   ///<获取人员信息（458）
	MSG_REG_NEW_STAFFOPERATION_GET,     	  		   ///<获取人员操作信息（459）
	MSG_REG_NEW_STAFFSYNCFLAG_SET,     	  		   	   ///<人员同步标志设置（460）
	MSG_REG_NEW_STAFFAUTHINFO_GET,     	  		   	   ///<人员权限组获取（461）
	MSG_REG_NEW_STAFFSYNCINFO_GET,     	  		   	   ///<获取同步人员信息（462）
	MSG_REG_NEW_ACCESSSYRELATION_SET,     	  		   ///<门禁关联守押设置（463）
	MSG_REG_NEW_DOOROPENSYRELATION_SET,     	  	   ///<认证守押信息关联（464）
	MSG_REG_NEW_ACCESSSYRELATION_GET,     	  		   ///<门禁关联守押设备获取（465）
	MSG_REG_NEW_DOOROPENSYRELATION_GET,     	  	   ///<认证守押信息关联获取（466）
	MSG_REG_NEW_QUERYHISTORYINFO_SY_GET,     	  	   ///<查询认证历史信息（可按认证类型查询）（467）
	
	
	
	//智能运维
	MSG_REG_NEW_CAPITALINFO_OPERATION = 500,           ///<资产信息相关操作：增加、修改、批量修改(500)
	MSG_REG_NEW_DETECTSCHEDULE_SET,					   ///<巡检模板计划设置(501)
	MSG_REG_NEW_MALFUNCTION_INSERT,					   ///<故障报修信息插入(502)
	MSG_REG_NEW_MAINTENCEINFO_INSERT,				   ///<增加维修记录(503)
	MSG_REG_NEW_OMSERVER_OPERATION,				       ///<运维服务器相关操作(504)
	MSG_REG_NEW_DETECTMODULE_OPERATION,				   ///<巡检模板相关操作(505)
	MSG_REG_NEW_CHANNELDETECTMODULE_OPERATION,		   ///<通道检查模板相关操作(506)
	MSG_REG_NEW_OMSERVERDIVIDE_SET,		   			   ///<运维服务器划分(507)
	MSG_REG_NEW_FAULTINFO_OPERATION,		   		   ///<故障现象相关操作(508)
	MSG_REG_NEW_DEVICEMANUFACTUREINFO_GET,		   	   ///<获取设备品牌信息(509)
	MSG_REG_NEW_DEVICEMODELINFO_GET,		   		   ///<获取设备型号信息(510)
	MSG_REG_NEW_SUPPLIERINFO_GET,		   		       ///<获取供应商信息(511)
	MSG_REG_NEW_MAINTENCECOMPANY_GET,		   		   ///<获取维保商信息(512)
	MSG_REG_NEW_ENGINEERINGINFO_GET,		   		   ///<获取工程商信息(513)
	MSG_REG_NEW_DEVICEBASEINFO_GET,		   		       ///<获取设备基础信息(514)
	MSG_REG_NEW_MALFUNCTIONINFO_GET,		   		   ///<报修记录信息查询(515)
	MSG_REG_NEW_FAULTNAME_GET,		   		           ///<获取故障现象(516)
	MSG_REG_NEW_MAINTENCEINFO_GET,		   		       ///<维修记录信息获取(517)
	MSG_REG_NEW_MAINTENCEINFO_PHONE_GET,		   	   ///<获取维保商信息包含电话(518)
	MSG_REG_NEW_ALARMARMDISARMPLAN_GET,		   	       ///<报警主机布撤防计划获取(519)
	MSG_REG_NEW_CAPITALINFO_STATISTICS,		   	       ///<设备基本信息统计(520)
	MSG_REG_NEW_MALFUNCTIONINFO_STATISTICS,		   	   ///<故障信息统计(521)
	MSG_REG_NEW_HOSTUSESTATUS_GET,		   	   		   ///<主机使用状态获取(522)
	MSG_REG_NEW_DETECTORUSESTATUS_GET,		   	   	   ///<探头使用状态获取(523)
	MSG_REG_NEW_DETECTSCHEDULE_GET,		   	   	       ///<获取巡检计划(524)
	MSG_REG_NEW_MODULEINFO_GET,		   	   	           ///<获取模板总览信息(525)
	MSG_REG_NEW_DEVICEBASEINFOBYID_CLIENT_GET,		   ///<根据设备编号获取设备基本信息（客户端）(526)
	MSG_REG_NEW_DEVICEBASEINFOBYID_SOFTSET_GET,		   ///<根据设备编号获取设备基本信息（配置客户端）(527)
	MSG_REG_NEW_OMDEVICEINFO_GET,		   			   ///<获取OM设备信息(528)
	MSG_REG_NEW_OMCHANNELINFODIVIDE_GET,		   	   ///<获取OM通道信息划分(529)
	MSG_REG_NEW_OMPARTATIONINFO_GET,		   		   ///<显示OM分区信息(530)
	MSG_REG_NEW_OMARMDISARMMODULE_GET,		           ///<OM获取布撤防模板(531)
	MSG_REG_NEW_OMARMDISARMSCHEDULE_GET,		   	   ///<OM获取分区布撤防计划(532)
	MSG_REG_NEW_OMRECORDDAYSMODULE_GET,		   		   ///<OM获取录像天数模板(533)
	MSG_REG_NEW_OMCHANNELRECORDDAYS_GET,		   	   ///<OM获取摄像头录像天数(534)
	MSG_REG_NEW_FAULTINFODETAIL_GET,		   	   	   ///<获取故障信息详情(535)
	MSG_REG_NEW_ASARMDISARMSCHEDULE_GET,		   	   ///<AS获取分区布撤防计划(536)
	MSG_REG_NEW_ALARMARMDISARMPLANBYID_GET,		   	   ///<报警主机布撤防计划获取通过ID(537)
	MSG_REG_NEW_DETECTMODULEINFO_GET,		   	       ///<配置客户端获取巡检模板信息(538)
	MSG_REG_NEW_OMSERVERDIVIDEINFO_GET,		   	       ///<获取划分给巡检服务器的设备信息(539)
	MSG_REG_NEW_OMSERVERINFO_GET,		   	      	   ///<获取OM服务器信息(540)
	MSG_REG_NEW_ALLOMINFO_SOFTSET_GET,		   	       ///<配置客户端获取所有OM信息(541)
	MSG_REG_NEW_SOFTSETCHANNELRECORDDAYS_GET,		   ///<根据录像天数模板ID获取关联摄像头(542)
	MSG_REG_NEW_ASDEVICEINFOBYSTATUS_GET,		  	   ///<报警服务器获取设备信息通过设备状态(543)
	MSG_REG_NEW_DEVICEMANUFACTUREINFOINCAPITAL_GET,	   ///<获取设备品牌信息（只包含资产信息中存在的）(544)
	MSG_REG_NEW_DEVICEINFOWITHCAPITAL_GET,		  	   ///<获取设备信息包含资产编码 (545)
	MSG_REG_NEW_FRONTENDNODEINFOWITHCAPITAL_GET,	   ///<获取设备信息包含资产编码 (546)
	
	//媒体存储完善接口
	MSG_REG_ALARMDISPOSAL_ASSINGLE_SET_NEW = 600,      ///<报警插入_NEW(600)
	MSG_REG_ALARMSTORAGEFILELOCKED_SET,				   ///<报警联动存储文件锁定、解锁(601)
	MSG_REG_MEDIASTORAGEFILEINFO_INSERT,			   ///<媒体存储文件信息写入(602)
	MSG_REG_ALARMTYPEOPERATION_NEW,			 		   ///<报警类型增加、修改_NEW(603)
	MSG_REG_CLEANDISKSTORAGE_SET,			 		   ///<清盘策略设置(604)
	MSG_REG_CLEANDISKSTORAGE_GET,			 		   ///<清盘策略设置获取(605)
	MSG_REG_MEDIASTORAGEDELETEDBRECORD,			 	   ///<媒体存储删除数据库记录(606)
	MSG_REG_DELETEFILEINFO_GET,			 	           ///<获取要删除的文件信息(607)
	MSG_REG_ALARMCONFIG_GET_NEW,			 	       ///<获取报警配置_NEW(608)
	MSG_REG_ALARMDEALSTRATEGY_GET_NEW,			 	   ///<报警服务器获取报警处置策略信息_NEW(609)
	MSG_REG_CLIENTGETMEDIASTORAGEATTACHMENT,		   ///<客户端获取媒体存储的附件(610)
	MSG_REG_NEW_INSPECT_TASKEXCUTESET_NEW,			   ///<主动巡查任务执行插入_NEW(611)
	MSG_REG_NEW_DOOROPENAPPLY_INFO_ADD_NEW,            ///<开门申请信息插入_NEW(612)
	MSG_REG_GETFIRSTDAYFILEINFO,			 	   	   ///<获取最早的未锁定的文件(613)
	MSG_REG_DELETEFILEINFOBYDATE,			 	   	   ///<删除指定日期未锁定的文件(614)
	
	//报警处置koala接口
	MSG_REG_ACTIONOPERATION_KOALA = 700,			   ///<动作库相关操作_Koala(700)
	MSG_REG_PREPLANOPERATION_KOALA,			   		   ///<预案库相关操作_Koala(701)
	MSG_REG_EVENTOPERATION_SOFTSET,			   		   ///<事件库相关操作_NEW,配置客户端使用(702)
	MSG_REG_ALARMDEALKOALAINFO_INSERT,			   	   ///<报警处置考拉信息写入(703)
	MSG_REG_GETACTIONLIB_KOALA,			   	   		   ///<获取动作库_Koala(704)
	MSG_REG_GETPREPLANLIB_KOALA,			   	   	   ///<获取预案库_Koala(705)
	MSG_REG_GETEVENTLIB_KOALA,			   	   	       ///<获取事件库_Koala(706)
	MSG_REG_GETALARMATTACHMENT_KOALA,			   	   ///<获取Koala报警附件(707)
	
	

    MSG_REG_NEW_FAULTINFOS = 3000,             ///<故障信息
    MSG_REG_NEW_ALLDISKINFO,                   ///<所有设备硬盘信息
    MSG_REG_NEW_SETSIGNLEDISKNUM,              ///<设置一台设备实际硬盘数
    MSG_REG_NEW_SETMULTIDISKNUM,               ///<设置多台设备实际硬盘数
    MSG_REQ_NEW_DEVNODEINFOEX,                 ///<客户端设置节点的操作

}E_MSG_REQ_SUBTYPE;

///<日志记录的操作类型定义
typedef enum
{
    LOG_REALPLAY,	    ///<预览
    LOG_TALK_DEV,	    ///<设备对讲
    LOG_TALK_USER,	    ///<用户对讲
    LOG_PLAYBACK,	    ///<回放
    LOG_DEV_CTRL,           ///<设备控制
    LOG_ALARMIN_CTRL,       ///<报警输入控制
    LOG_ALARMOUT_CTRL,      ///<报警输出控制
    LOG_CAMERA_CTRL,        ///<摄像头控制
    LOG_DEV_STATE,          ///<设备在线状态
    LOG_USER_STATE,         ///<用户在线状态
    LOG_GET_CMS_TIME,       ///<查看中心时间
    LOG_TALK_IP,            ///<IP对讲
}E_LOGTYPE;

///<--------------------数据结构定义-------------------------------------
typedef struct
{
	char Name[20];		///<区域名称
	char AreaCode[20];	///<区域编码
	long  AreaID;        ///<整形ID
	char FatherCode[20]; ///<父节点的编号
	int  MaxviewNum;     ///<最大上传通道数
	int  AreaType;       ///<网点级别
}T_AREAINFO, *LPT_AREAINFO;

///<通道信息结构
typedef struct
{
    unsigned long  lDvrID;
    unsigned long  lChannelNO;
}T_CHANNEL_INFO, *LPT_CHANNEL_INFO;

///<设备基本信息结构
typedef struct
{
    char  chNumber[20];   ///<设备字符串编号
    char  chIp[20];       ///<设备IP
    char  chUserName[20]; ///<用户名
    char  chPassWord[20]; ///<密码
    long  lNumber;        ///<设备整型编号
    long  lCenterID;      ///<所属中心ID
    int   nPort;          ///<端口号
    int   nChannelNum;    ///<通道号
    int   nDevType;       ///<设备类型
    int   nType;          ///<厂家
    int   nSubType;       ///<型号
    int   nNeedLink;      ///<是否需要连接
    char  Area[20];       ///<所属网点
}T_DEV_BASE_INFO, *LPT_DEV_BASE_INFO;

///<设备基本信息结构附加
typedef struct
{
    char  chDvrName[40];  ///<设备名称
    char  chNumber[20];   ///<设备字符串编号
    char  chIp[20];       ///<设备IP
    char  chUserName[20]; ///<用户名
    char  chPassWord[20]; ///<密码
    long  lNumber;        ///<设备整型编号
    long  lCenterID;      ///<所属中心ID
    int   nPort;          ///<端口号
    int   nChannelNum;    ///<通道号
    int   nDevType;       ///<设备类型
    int   nType;          ///<厂家
    int   nSubType;       ///<型号
    int   nNeedLink;      ///<是否需要连接
    char  Area[20];       ///<所属网点
}T_DEV_BASE_INFO_EX, *LPT_DEV_BASE_INFO_EX;

///<设备基本信息（附带联动信息）
typedef struct
{
    char  chDvrName[40];  ///<设备名称
    char  chNumber[20];   ///<设备字符串编号
    char  chIp[20];       ///<设备IP
    char  chUserName[20]; ///<用户名
    char  chPassWord[20]; ///<密码
    long  lNumber;        ///<设备整型编号
    long  lCenterID;      ///<所属中心ID
    int   nPort;          ///<端口号
    int   nChannelNum;    ///<通道数量  
    int   nDevType;       ///<设备类型
    int   nType;          ///<厂家
    int   nSubType;       ///<型号
    int   nNeedLink;      ///<是否需要连接
    char  Area[20];       ///<所属网点
    int linkNum;                  ///<联动数量
    T_CHANNEL_INFO ARRDevinfo[32];///<联动通道组
}T_DEV_BASE_INFO_EX_NEW, *LPT_DEV_BASE_INFO_EX_NEW;


///<AS需要的设备信息结构
typedef struct
{
    T_DEV_BASE_INFO TBaseInfo;   ///<基本信息
    int arraySensorInfo[256][2];  ///<探头相关信息。[*][0]-是否对讲触发（-1）、报警类型（>0）、未设（=0）；[*][1]-对讲通道(>0)
    int arrayManualSensorInfo[256]; ///<手动报警类型（>0）
}T_AS_DEV_INFO, *LPT_AS_DEV_INFO;

///<AS需要的设备信息结构返回值带设备名称
typedef struct
{
    T_DEV_BASE_INFO_EX TBaseInfoEx;   ///<基本信息
    int arraySensorInfo[256][2];  ///<探头相关信息。[*][0]-是否对讲触发（-1）、报警类型（>0）、未设（=0）；[*][1]-对讲通道(>0)
    int arrayManualSensorInfo[256]; ///<手动报警类型（>0）
}T_AS_DEV_INFO_EX, *LPT_AS_DEV_INFO_EX;

///<MS需要的设备信息结构
typedef struct
{
    T_DEV_BASE_INFO TBaseInfo;

    char szVodPwd[20]; ///<工控需要 回放用户密码
    char szVodName[20];
    bool bLongLink; ///<是否保持长连接
}T_MS_DEV_INFO, *LPT_MS_DEV_INFO;

///<MS需要的设备信息结构返回值带设备名称
typedef struct
{
    T_DEV_BASE_INFO_EX TBaseInfoEx;

    char szVodPwd[20]; ///<工控需要 回放用户密码
    char szVodName[20];
    bool bLongLink; ///<是否保持长连接
}T_MS_DEV_INFO_EX, *LPT_MS_DEV_INFO_EX;

///<用户基本信息
typedef struct
{
    char chUsername[20];
    char chPassword[20];

    ///<有些用户需要在固定的主机上登录，需要Mac地址及IP
    char chMACAddr[20];  ///<主机MAC地址 。
    char chIP[20];      ///<固定主机的IP。
    int  nPrity;        ///<等级
    char Question[50];
	char Answer[50];
    TJTY_TIME TValiadStartTime;   ///<有效期开始时间
    TJTY_TIME TValiadEndTime;     ///<有效期结束时间
}T_USER_INFO, *LPT_USER_INFO;

///<用户整体权限结构
typedef struct
{
    bool UserMrg;///<用户管理
	bool DevMrg; ///<设备管理
	bool Real_TimeVideoView; ///<实时预览
	bool Talk; ///<对讲
	bool GroupTalk;///<群呼
	bool DevCtrl; ///<设备控制
	bool StateLookUp; ///<状态查询
	bool Polling;///<巡检
	bool DevMsgLookUp;  ///<dvr 日志查询
	bool m_AssetsMag;   ///<资产操作权限
	bool m_EventMag;    ///<事件操作
	bool m_SystemConfig;  ///<系统管理
	bool RecvAlarm;    ///<接警
	bool PlayBack;      ///<回放
    bool bIsVIP;        ///<VIP用户
}T_USER_TOTAL_AUTH, *LPT_USER_TOTAL_AUTH;

///<用户具体到通道的权限结构
typedef struct
{
    unsigned int RealTimeView; ///<实时预览权限
	unsigned int PlayBack;     ///<回放权限
	unsigned int Download;     ///<下载权限
	unsigned int VideoConfig;  ///<视频参数调节权限
	unsigned int HolderCtrl;   ///<云台控制权限
}T_USER_AUTH_CHL, *LPT_USER_AUTH_CHL;

///<用户对设备的整体权限
typedef struct
{
    long lDEVID;     ///<设备ID号
	bool AlarmOutCtrl;///<报警输出口权限
	bool DevAct;      ///<开关机控制权限
	bool AlarmInCtrl; ///<报警输入口权限
	bool DevUpgrade;  ///<对设备升级权限
	bool DevTime;     ///<对设备校时权限
	bool DevLogLookUp;///<对设备日志查看权限
	bool DevConfig;   ///< 对设备配置权限
	bool TalkDevc;    ///<对讲权限
	bool RecvAlarmDev;///<接收报警权限
	T_USER_AUTH_CHL ChannelPower;  ///<通道权限
}T_USER_AUTH_DEV, *LPT_USER_AUTH_DEV;

///<用户接警权限结构
typedef struct
{
    long lDEVID;    ///<设备ID
    int  nRecvAlarmLevel;  ///<具体的接警等级
}T_USER_AUTH_ALARM, *LPT_USER_AUTH_ALARM;
/*
typedef struct
{
    char chUsername[20];
    char chPassword[20];
    int  nPrity;        ///<等级
    T_USER_AUTH_ALARM Dev_AUTHInfo[2000];  ///<设备及对应的接警等级信息
    bool IsSystem;
}T_USER_DEV_ALARMAUTH, *LPT_USER_DEV_ALARMAUTH;   */

///<摄像头信息结构
typedef struct
{
    char Name[20];   ///<摄像头名称
    char CameraCode[20];	///<摄像头编码
    unsigned long  lDVRID;   ///<设备编号
    int  nChannelNO;           ///<通道号
    int  NetModel;      ///<网传模型 0：子码流 1： 主码流
    int  AreaPri;       ///<区域等级。
    int linkNum;
    T_CHANNEL_INFO ARRDevinfo[5];///<联动通道组  目前产品定义为4个，用5个预留。
}T_CAMERA_INFO, *LPT_CAMERA_INFO;

///<摄像头信息结构（带联动信息）
typedef struct
{
    char Name[64];                ///<摄像头名称
    char CameraCode[32];	  ///<摄像头编码
    unsigned long  lDVRID;        ///<设备编号
    int  nChannelNO;              ///<通道号
    int  NetModel;                ///<网传模型 0-CIF; 1-D1; 2-720P; 3-1080P
    int  AreaPri;                 ///<区域等级
    int linkNum;                  ///<联动数量
    T_CHANNEL_INFO ARRDevinfo[32];///<联动通道组
}T_CAMERA_INFO_NEW, *LPT_CAMERA_INFO_NEW;

///<探头信息结构
typedef struct
{
    char Name[20];
    char AlarmCode[20];
    int  nChannelNO;           ///<通道号
    unsigned long  lDVRID;     ///<设备编号
    ///<报警类型，外设类型。 对于AlarnIn 表示为接报警类型，AlarmOut表示所接外设类型(门禁、灯等)
    int  AlarmType;
    int  AreaPri;       ///<区域等级。
    int linkNum;
    T_CHANNEL_INFO ARRDevinfo[32];///<联动通道组
}T_SENSOR_INFO, *LPT_SENSOR_INFO;

///<媒体服务器信息结构
typedef struct
{
    char MSCode[20];   ///<流媒体编号
    char PassWorld[20];
    unsigned long IP;
    int  DataPort;    ///<媒体的数据端口。
	unsigned long MSAbility;///<媒体服务器的能力
}T_MS_INFO_STRU, *LPT_MS_INFO_STRU;

///<报警服务器信息结构
typedef struct
{
    char ASCode[20];   ///<报警服务器编号
    char PassWorld[20];
    unsigned long IP;
}T_AS_INFO_STRU, LPT_AS_INFO_STRU;

///<报警消息处理
typedef struct
{
    int nFiltrateFlag;  ///<0：不过滤；1：过滤；2：不处理
    int nInterval;      ///<过滤间隔，单位为秒
    unsigned char ucIsSaveText;///<是否存储报警文字，1:存储；0:不存储
    unsigned char ucIsSaveVideo;///<是否联动视频存储，1:联动；0:不联动
    int nSaveTime;               ///<存储时长（S）
}T_ALARM_DEALINFO, *LPT_ALARM_DEALINFO;

typedef struct
{
    TJTY_TIME StartTime;
    TJTY_TIME EndTime;
}T_ALARM_TIMESEGMENT, *LPT_ALARM_TIMESEGMENT;

///<报警处理策略
typedef struct
{
    int nAlarmType;  ///<报警类型
    T_ALARM_TIMESEGMENT TimeSegment[6];
    T_ALARM_DEALINFO T_AlarmDeal[6];
}T_ALARM_DEAL_STRATEGY, *LPT_ALARM_DEAL_STRATEGY;

///<单条报警消息结构
typedef struct
{
    unsigned char ucChannel;///<通道号
    unsigned char ucSourceType;///<报警源类型（探头、摄像机、主机等）
    unsigned char ucAlarmType;///<报警类型（视频丢失、移动、红外、幕帘等）
    unsigned char ucReserved;///<保留位
}SIGNALALARM;

///<单条报警消息结构(JH - NEW)
typedef struct
{
    unsigned char ucChannel;     ///<通道号
    unsigned char ucSourceType;  ///<报警源类型（探头、摄像机、主机等）
    unsigned char ucAlarmType;   ///<报警类型（视频丢失、移动、红外、幕帘等）
    unsigned char ucReserved;    ///<报警等级
    char chMemo[128];            ///<备注信息[人名、部门、出入时间信息]
}SIGNALALARM_NEW;

///<报警消息结构
typedef struct
{
    char      chNumber[20];
    char      chIp[20];
    long      lNumber;
    int       nAlarmCount;
    TJTY_TIME   tTime;
}T_ALARMInfo;

///<日志记录模块
typedef struct
{
	unsigned long DeviceID;
	unsigned int udChannel;
	char chOpDesip[256];///<操作描述
	char UserName[20];  ///<操作用户名
	TJTY_TIME OpTime;///<事情发生时间
	unsigned int Optype;///<操作类型 见LOGTYPE
	bool OpenOrClose;   ///<外设控制的时候用于说明是打开还是关闭。
}T_DEVSQL_LOGINFO, *LPT_DEVSQL_LOGINFO;

///<用户对讲日志记录
typedef struct
{
	char UserName[20];	///<被呼叫用户名
	char Ip[20];
	char chOpDesip[256];///<操作描述
	char AskUserName[20];  ///<操作用户名呼叫用户名。
	TJTY_TIME  OpTime;///<事情发生时间
	unsigned int Optype;///<操作类型见LOGTYPE
}T_USERTALK_LOGINFO, *LPT_USERTALK_LOGINFO;

///<日志类型定义
/*
typedef enum           .
{
	REALTIME_VIEW,	///<实时视频预览
	TALKWITHDEV,	///<与设备对讲
	TALKWITHUSER,	///<与客户对讲
	PLAYBACK,		///<回放下载
	DEVCTRLLOG,     ///<设备控制，包括开关机、校时等操作
	ALARMINCTRL,    ///<探头控制，此时 DevSqllog udChannel 表示的是探头号组，安位计算。
	ALARMOUTCTRL,	///<外设控制 此时DevSqllog udChannel 表示的是外设号。需要根据这个号来判断外设接的是什么。
	DEVCAMERACTL    ///<摄像头控制
}LOGTYPE;
*/

///<校时计划
typedef struct
{
    unsigned int nPlanID;
    TJTY_TIME TExecTime;     ///<校时开始执行时间点
    TJTY_TIME TLastSetTime;  ///<上次执行时间
    int       nSetTimeCycle; ///<校时周期 1-8小时，2-16小时，3-24小时，
                             ///<4-一周（7*24小时），5-一月（30*24小时）
}T_SETTIME_PLAN, *LPT_SETTIME_PLAN;

///<登录设备用户名和密码信息
typedef struct
{
    char chUserName[20];    ///<登录设备用户名
    char chPassWord[20];    ///<登录设备密码
    unsigned long ulDEVID;  ///<设备ID
}T_DEV_LOGINFO, *LPT_DEV_LOGINFO;

///<中心管理服务器信息结构
typedef struct
{
    char chCMSMemo[200];   ///<备注、描述
    char chCMSName[50];
    char chUserName[20];   ///<登录下级中心的用户名
    char chPassWord[20];   ///<登录下级中心的密码
    unsigned long ulCMSIP;
    long lCenterID;         ///<监控中心编号
    long lFatherCenterID;   ///<父监控中心编号
    int nPort;              ///<暂时固定为4000
    int nType;              ///<1-本级主CMS，2-本级备份CMS，3-下级主CMS， 4-下级备份CMS
}T_CMS_INFO_STRU, *LPT_CMS_INFO_STRU;
/**************************************************************************/
///<获取时所需要的参数结构

///<获取设备列表信息时需要的参数结构
///<MSG_REQ_AREA_INFO,  MSG_REQ_DEV_BASE_INFO,  MSG_REQ_DEV_AS_INFO,
typedef struct
{
	unsigned int DevType;    ///<设备类型，可按位或
	char ServerCode[20];     ///<服务器名称
}T_GDEVPARAM;

///<获取单个设备信息时所需要的参数结构
typedef struct
{
    unsigned int unDEVID;   ///<设备ID
	char ServerCode[20];    ///<服务器名称
}T_GSDEV_PARA;

///<获取指定用户对指定设备的权限
typedef struct
{
    char chUserName[20];
    unsigned int unDEVID;   ///<设备ID
}T_GSDEV_AUTH_PARA;

///<获取指定用户登录指定设备的登录信息
typedef struct
{
    char chUserName[20];    ///<用户名
    unsigned int unDEVID;   ///<设备ID
}T_USERNAME_DEVID;


///<根据条件检索MS上的点播文件

typedef struct
{
    long lDevId;            ///<设备ID
    char chAreaName[64];    ///<网点名称
    TJTY_TIME TStartTime;   ///<开始时间
    TJTY_TIME TStopTime;    ///<结束时间
    int nChannel;           ///<通道号
	int nFileType;			///<文件类型（1-计划存储，2-联动存储;3-集中存储;4-新计划存储；5-新联动存储）
    char chAlarmTypeName[20];   ///<报警联动类型
    char chOtherInfo[20];       ///<其他条件
}T_MSVOD_SEARCH_PARA;



///< 将DCOM通信方式转化为TCP通信方式( Modify by mgy )

///< 执行增删改操作返回信息结构体(common-out)
typedef struct
{
    char chReturn[256];        ///< 执行增删改返回值(默认"1"为执行成功，反之为异常字串)
}S_CommonRet;


///< 获取区域节点详细信息（区域） (1-int)
typedef struct
{
    int nNodeId;         ///<节点类型ID
    char chSerial[32];   ///<节点编码
    char chName[64];     ///<节点名称
    int bCondition;      ///<查询条件
    char chUserName[64]; ///<用户名（获取过滤网点时传入）
}P_AreaInfo;
/******************************
P_AreaInfo.bCondition:

0：返回所有网点的名称
1；根据网点编号返回特定网点下的所有节点（网点、主机及前端设备）
2：根据网点编号返回特定网点的布防图的路径及名称
3：返回所有网点的详细信息（按网点类型排序）
4：根据网点名称返回特定网点的布防图的路径及名称，还有该网点的编号
5：根据网点编号返回特定网点的详细信息
6：返回所有网点的详细信息
7：根据网点名称返回特定网点的详细信息
8：根据网点编号返回特定网点的详细信息
9：根据用户名返回过滤网点
100：根据网点类型ID返回比该类型ID小的网点名字（更高层级的网点）
101: 返回所有网点的编号+场所类型；
******************************/
///< 获取区域节点详细信息（区域） (1-out)
typedef struct
{
    int nAreaId;                      ///<节点ID
    char chCode[32];                  ///<节点编码
    char chName[64];                  ///<节点名称
    char chFatherNo[32];              ///<上一级编码
    char chAddress[128];              ///<网点地址
    char chManName[64];               ///<联系人
    char chContactInfo[64];           ///<联系方式
    int nAreaTypeID;                  ///<节点类型ID（1~8,9,10,11,12,13）
    char chNodeTypeName[64];          ///<节点类型名
    int nAreaLevel;                   ///<节点级别（1~101,102,103,200,300,400）
    int  nXPos;                       ///<在地图上的X坐标（千分制）
    int  nYPos;                       ///<在地图上的Y坐标（千分制）
    int  nSize;                       ///<图标大小
    int  nWay;                        ///<图标方向
    int nNetWidthLimit;               ///<网点带宽
    int nUpLoadMaxChlNum;             ///<最大上传通道数
    int nImageID;                     ///<图片ID
    int nAutoSwitch;                  ///<码流是否自动切换
    char chImageName[64];             ///<图标名称
    char chImagePath[256];            ///<图标文件路径
    char chMapName[64];               ///<地图文件名称
    char chMapPath[256];              ///<地图文件路径
    int  nMapSize;                    ///<地图大小（字节）
    char SwitchNetWidth[64];          ///<临界带宽
    int SwitchUploadLimit;            ///<临界通道数
    char chCenterNo[128];             ///<中心编号
    char chFatherCenterNo[128];       ///<父中心编号
    char chUserName[64];              ///<用户名（获取过滤时返回）
    char chMemo[512];                 ///<备注
    int nAreaPosition;                ///<场所
}S_AreaNodeInfo;

///< 获取主机设备信息(DVR、报警主机、门禁) (2-out)
typedef struct
{
    int nID;                    ///< 设备ID
    char chDevCode[64];         ///< 设备编码
    char chDevName[128];        ///< 设备名称
    char chDevIp[32];           ///< 设备IP地址
    char chAreaCode[64];        ///< 所在区域编码
    int nDeviceType;            ///< 设备类型(9、11、14)
    int nPort;                  ///< 端口号
    int nHostSpeak;             ///< 主机对讲
    int nAlarmFilter;           ///< 报警过滤标志
    char chAlarmFilterDate[64]; ///< 报警过滤时间
    int nCanSpreak;             ///< 能否对讲
    int nAutoIp;                ///< 自动IP
    int nProportionX;           ///< 千分制X坐标
    int nProportionY;           ///< 千分制Y坐标
    int nImageSize;             ///< 图标大小
    int nImageDirection;        ///< 图标方向
    int nAlarmLevel;            ///< 报警区域等级
    int nDevTypeID;             ///< 设备类型ID（品牌ID）
    char chDevModelNo[128];     ///< 设备型号
    int nIsConnected;           ///< 是否需要连接
    char chIpSpeak[128];        ///< IP对讲
    char chDevManufacture[64];  ///< 品牌名称
    int nDevManufatureID;       ///< 品牌编号
    char chCenterNo[128];       ///< 中心编号
    char chFatherCenterNo[128]; ///< 父中心编号
    int nDevTypeCode;           ///< 设备类型编号（2*n）
    int nKeyPart;               ///< 部位
}S_DevNodeInfo;

///< 获取主机设备信息(DVR、报警主机、门禁) (2-out)  new
typedef struct
{
    int nID;                    ///< 设备ID
    char chDevCode[64];         ///< 设备编码
    char chDevName[128];        ///< 设备名称
    char chDevIp[32];           ///< 设备IP地址
    char chAreaCode[64];        ///< 所在区域编码
    int nDeviceType;            ///< 设备类型(9、11、14)
    int nPort;                  ///< 端口号
    int nHostSpeak;             ///< 主机对讲
    int nAlarmFilter;           ///< 报警过滤标志
    char chAlarmFilterDate[64]; ///< 报警过滤时间
    int nCanSpreak;             ///< 能否对讲
    int nAutoIp;                ///< 自动IP
    int nProportionX;           ///< 千分制X坐标
    int nProportionY;           ///< 千分制Y坐标
    int nImageSize;             ///< 图标大小
    int nImageDirection;        ///< 图标方向
    int nAlarmLevel;            ///< 报警区域等级
    int nDevTypeID;             ///< 设备类型ID（品牌ID）
    char chDevModelNo[128];     ///< 设备型号
    int nIsConnected;           ///< 是否需要连接
    char chIpSpeak[128];        ///< IP对讲
    char chDevManufacture[64];  ///< 品牌名称
    int nDevManufatureID;       ///< 品牌编号
    char chCenterNo[128];       ///< 中心编号
    char chFatherCenterNo[128]; ///< 父中心编号
    int nDevTypeCode;           ///< 设备类型编号（2*n）
    int nKeyPart;               ///< 部位
    char chSetDate[32];         ///< 设备添加时间
}S_DevNodeInfo_New;

///< 获取前端设备信息(摄像头、探头、输出)(3-out)
typedef struct
{
    int nID;                    ///< 设备ID
    char chFrontendCode[64];    ///< 设备编码
    char chFrontendName[128];   ///< 设备名称
    int nChannelNo;             ///< 通道号
    int nDeviceType;            ///< 设备类型(10、12、13)
    int nDeviceUseage;          ///< 设备类型移位标识(2,1,4)
    char chAreaCode[64];        ///< 所在区域编码
    char chHostCode[64];        ///< 所属主机编码
    int nProportionX;           ///< 千分制X坐标
    int nProportionY;           ///< 千分制Y坐标
    int nImageSize;             ///< 图标大小
    int nImageDirection;        ///< 图标方向
    int nHolder;                ///< 云台控制标志
    int nSpeak;                 ///< 对讲触发标志
    int nAlarmFilter;           ///< 报警过滤标志
    char chAlarmFilterDate[64]; ///< 报警过滤时间
    int nAlarmLevel;            ///< 报警区域等级
    int nChannelRelated;        ///< 联动通道标志
    int nNetModel;              ///< 网传模式
    char chAreaName[256];       ///< 所在区域名称
    char chDeviceName[256];     ///< 所属主机名称
    char chNetModel[64];        ///< 码流类型详细信息
    int nCameraAreaID;          ///< 摄像头区域类别ID
    char chCenterNo[128];       ///< 中心编号
    char chFatherCenterNo[128]; ///< 父中心编号
    int nKeyPart;               ///< 部位
}S_FrontendNodeInfo;

///< 获取用户详细信息(4-int)
/******************************
P_UserInfo.nCondition:

0：返回所有用户详细信息
1：根据用户名和权限返回用户的权限信息
2：根据用户名获取用户的详细信息
3: 获取所有的用户
4: 根据用户ID获取用户的详细信息
5: 获取未关联电视墙用户名
6: 获取电视墙(模式对应)信息
10: 返回所有用户信息(包含头像) 注：输出为S_New_UserInfo
******************************/
typedef struct
{
    int nCondition;             ///< 查询条件
    char chUserName[64];        ///< 用户名
	char chPrivilege[128];      ///<权限名称(目前此值默认固定为视频预览)
}P_UserInfo;

///< 获取用户详细信息(4-out)
typedef struct
{
    int nID;                    ///< 用户ID
    char chUserCode[32];        ///< 工号
    char chUserName[64];        ///< 用户名
    char chPassword[64];        ///< 密码
    int  nLevel;                ///< 用户级别
    char chRole[128];           ///< 用户角色
    int  nLock;                 ///< 锁定（是否设置过滤网点）
    char chStartTime[32];       ///< 用户有效开始时间
    char chEndTime[32];         ///< 用户有效结束时间
    char chPhone[64];           ///< 电话
    char chEmail[64];           ///< Email
    char chAbout[500];          ///< 用户简介
    /***************************获取用户权限************************/
    char chPrivilege[128];      ///< 权限名称
    char chPrivilegeDetail[128];///< 详细权限信息
    int nHostID;               ///< 对应的主机ID
    int nChannels;             ///< 对应主机全部通道（拼接的通道号组成的整形值）
}S_UserInfo;

///< 获取用户详细信息(4-out)(带头像)
typedef struct
{
    int nID;                    ///< 用户ID
    char chUserCode[32];        ///< 工号
    char chUserName[64];        ///< 用户名
    char chPassword[64];        ///< 密码
    int  nLevel;                ///< 用户级别
    char chRole[128];           ///< 用户角色
    int  nLock;                 ///< 锁定（是否设置过滤网点）
    char chStartTime[32];       ///< 用户有效开始时间
    char chEndTime[32];         ///< 用户有效结束时间
    char chPhone[64];           ///< 电话
    char chEmail[64];           ///< Email
    char chAbout[500];          ///< 用户简介
    char chImage[512];          ///< 用户头像
}S_New_UserInfo;

///< 获取用户详细信息(4-out)[附加启用/禁用]
typedef struct
{
    int nID;                    ///< 用户ID
    char chUserCode[32];        ///< 工号
    char chUserName[64];        ///< 用户名
    char chPassword[64];        ///< 密码
    int  nLevel;                ///< 用户级别
    char chRole[128];           ///< 用户角色
    int  nLock;                 ///< 锁定（是否设置过滤网点）
    char chStartTime[32];       ///< 用户有效开始时间
    char chEndTime[32];         ///< 用户有效结束时间
    char chPhone[64];           ///< 电话
    char chEmail[64];           ///< Email
    char chAbout[500];          ///< 用户简介
    bool bUseful;               ///< 启用/禁用
    char chLevels[64];          ///< 报警等级值串$
}S_UserInfo_Useful;

///< 获取中心服务器详细信息(5-int)
/******************************
P_CMSInfo.nCondition:

0：返回所有中心服务器详细信息
1；返回本级中心服务器详细信息
3：返回下级中心服务器详细信息
******************************/
typedef struct
{
    int nCondition;             ///< 查询条件
}P_CMSInfo;

///< 获取中心服务器详细信息(5-out)
typedef struct
{
    int nID;                    ///< 中心ID
    char chCmsCode[64];         ///< 中心编码
    char chCmsName[64];         ///< 中心名称
    char chIP[64];              ///< 中心IP(主)
    char chViceIP[64];          ///< 中心IP(副)
    int  nType;                 ///< 中心类型（1-本级中心；3-下级中心）
    char chCenterNo[32];        ///< 中心编号
    char chFatherCenterNo[32];  ///< 父中心编号
    char chUserName[64];        ///< 登录中心的用户名
    char chPassword[64];        ///< 登录中心的密码
}S_CMSInfo;

///< 获取通道组详细信息(6-int)
/******************************
P_ChannelInfo.nCondition:

0：返回所有通道组的名称
1；根据通道组名称返回该通道组下的所有通道信息
******************************/
typedef struct
{
    int nCondition;             ///< 查询条件
    char chGroupName[128];      ///< 通道组名称(nCondition =1时，传入)
}P_ChannelInfo;

///< 获取通道组详细信息(6-out)
typedef struct
{
    char chChannelGroup[128];   ///< 通道组名称
    char chName[128];           ///< 通道名
    int nChannelNo;             ///< 通道号
    char chHostCode[64];        ///< 主机编号
    int  nSequence;             ///< 通道序列顺序
}S_ChannelInfo;

///< 获取主机对讲关联信息(7-out)
typedef struct
{
    int nDeviceID;             ///< 设备ID
    int nLinkNum;              ///< 关联数量
    int nCameraID[32];         ///< 关联摄像头ID数组
}S_HostTalkInfo;

///< 获取前端设备对讲关联信息(8-out)
typedef struct
{
    int nFrontendID;           ///< 前端设备ID
    int nLinkNum;              ///< 关联数量
    int nCameraID[32];         ///< 关联摄像头ID数组
}S_FrontendTalkInfo;

///< 获取电视墙详细信息(9-int)
/******************************
P_ScreenInfo.nCondition:

0：返回所有电视墙详细信息
1；根据用户名返回特定用户的电视墙详细信息
******************************/
typedef struct
{
    int nCondition;             ///< 查询条件
    char chUserName[128];       ///< 用户名(nCondition =1时，传入)
}P_ScreenInfo;

///< 获取电视墙详细信息(9-out)
typedef struct
{
    char chUserName[128];     ///< 用户名
    char chWeek[32];          ///< 星期
    int nTimeConsequence;     ///< 时间段
    char chStartTime[64];     ///< 开始时间
    char chEndTime[64];       ///< 结束时间
    int  nDevide;             ///< 画面分割数
    int nSwitchTime;          ///< 切换间隔
    int nDeviceID;            ///< 主机ID
    char chDeviceName[128];   ///< 主机名
    char chChannelName[128];  ///< 通道名
    int nChannelNo;           ///< 通道号
    int nShowScreen;          ///< 显示方式
}S_ScreenInfo;

///< 获取预案组详细信息(10-int)
/******************************
P_EmergencyInfo.nCondition:

0：返回所有预案组
1；返回所有预案详细信息
2：根据用户名返回特定用户的预案详细信息
******************************/
typedef struct
{
    int nCondition;             ///< 查询条件
    char chUserName[128];       ///< 用户名(nCondition =2时，传入)
}P_EmergencyInfo;

///< 获取预案组详细信息(10-out)
typedef struct
{
    int nEmergencyID;             ///< 预案组ID
    char chEmergencyGroup[128];   ///< 预案组名称
    int nE_Devide;                ///< 画面分割数
    int nE_SwitchTime;            ///< 切换间隔
    int nUserID;                  ///< 用户ID
    char chUserName[128];         ///< 用户名
    int nDeviceID;                ///< 主机ID
    char chHostCode[64];          ///< 主机编号
    char chDeviceName[128];       ///< 主机名
    char chChannelName[128];      ///< 通道名
    int nChannelNo;               ///< 通道号
    int nSequence;                ///< 通道序列顺序
    int nDevide;                  ///< 用户显示画面分割数
    int nSwitch;                  ///< 用户显示切换间隔
    int nShowScreen;              ///< 显示方式
}S_EmergencyInfo;

///< 获取报警类型详细信息(11-out)
typedef struct
{
    int nAlarmTypeID;             ///< 报警类型ID
    char chAlarmTypeName[128];    ///< 报警类型名称
    char chAlarmTypeSound[128];   ///< 报警类型对应声音名称
}S_AlarmTypeInfo;

///< 获取主机报警类型详细信息(12-int)
/******************************
P_HostAlarmInfo.nCondition:

0：返回主机对应报警类型详细信息
1：根据主机名返回特定主机对应报警类型详细信息
******************************/
typedef struct
{
    int nCondition;             ///< 查询条件
    char chDeviceName[128];     ///< 主机名称(nCondition =1时，传入)
}P_HostAlarmInfo;

///< 获取主机报警类型详细信息(12-out)
typedef struct
{
    int nDeviceID;              ///< 设备ID
    char chDeviceCode[64];      ///< 主机编码
    char chDeviceName[128];     ///< 主机名称
    char chIP[64];              ///< 主机IP
    int nPort;                  ///< 端口
    char chAreaCode[64];        ///< 所在区域编码
    int nDeviceType;            ///< 设备类型（9、15）
    int nAlarmLevel;            ///< 报警区域级别
    int nDeviceTypeID;          ///< 设备类型ID
    char chModelName[128];      ///< 型号
    int nAlarmTypeID;           ///< 报警类型ID
    char chAlarmTypeName[128];  ///< 报警类型名称
    char chAlarmTypeSound[128]; ///< 报警类型对应声音名称
}S_HostAlarmInfo;

///< 获取前端设备报警类型详细信息(13-int)
/******************************
P_FrontendAlarmInfo.nCondition:

0：返回前端设备对应报警类型详细信息
1：根据前端设备名返回特定前端设备对应报警类型详细信息
******************************/
typedef struct
{
    int nCondition;             ///< 查询条件
    char chFrontendName[128];   ///< 前端设备名称(nCondition =1时，传入)
}P_FrontendAlarmInfo;

///< 获取前端设备报警类型详细信息(13-out)
typedef struct
{
    int nFrontendID;              ///< 前端设备ID
    char chDeviceCode[64];        ///< 前端设备编码
    char chDeviceName[128];       ///< 前端设备名称
    int nChannelNo;               ///< 通道号
    int nDeviceType;              ///< 设备类型（10、12）
    char chAreaCode[64];          ///< 所在区域编码
    char chHostCode[64];          ///< 所在区域编码
    int nAlarmLevel;              ///< 报警区域级别
    int nNetModel;                ///< 码流类型（1、2、3、4）
    int nAlarmTypeID;             ///< 报警类型ID
    char chAlarmTypeName[128];    ///< 报警类型名称
    char chAlarmTypeSound[128];   ///< 报警类型对应声音名称
}S_FrontendAlarmInfo;

///< 报警过滤设置(14-int)
typedef struct
{
    int nCondition;            ///< 查询条件(0-清除报警日志插入，1-其它类型设置)
    char chCode[64];           ///< 编码
    char chName[128];          ///< 用户名(nCondition =0时，传入)
    int nNodeType;             ///< 节点类型（9、10、12）
    char chFilterTime[64];     ///< 过滤执行终止时间
}P_AlarmFilterSetInfo;

///< 添加新事件(15-int)
typedef struct
{
    char  chUserName[64];            ///<用户名
    char  chEventDescribe[128];      ///<事件源
    char  chHappenTime[64];          ///<事件发生时间
    char  chSubmitTime[64];          ///<事件提交时间
    char  chContent[1024];           ///<事件内容
    int   nProperty;                 ///<事件属性，是否是私密事件
    char chLabelName[128];           ///<事件标签名
}P_AddEventInfo;

///< 回复事件(16-int)
typedef struct
{
    char  chUserName[64];            ///<用户名
    int   nID;                       ///<事件ID
    char  chReplyContent[3000];      ///<回复内容
    char  chReplyTime[64];           ///<事件回复时间
    int   nEventState;               ///<事件状态  0 回复 1 重新打开 2 关闭
}P_ReplyEventInfo;

///< 获取所有事件详细信息(17-int)
typedef struct
{
    char chUserName[64];          ///<用户名
    int nPage;                    ///<页数(第n页)
    int nShowEventNumInPage;      ///<每页显示多少条事件
    int nClosed;                  ///<是否已关闭(0:打开 1:关闭 2:全部)
    int nState;                   ///<条件(0:全部事件 1:自己发起 2:与自身相关)
}P_EventInfo;

///< 获取所有事件详细信息(17-out)
typedef struct
{
    int nID;                      ///< 事件ID
    char chLabelName[64];         ///< 标签名
    char chSubmitMan[64];         ///< 事件发起人
    char chEventDescribe[128];    ///< 事件源
    char chHappenTime[64];        ///< 事件发生时间
    char chSubmitTime[64];        ///< 事件提交时间
    char chContent[1024];         ///< 事件内容
    int nState;                   ///< 事件状态(0:打开 1:关闭 2:全部)
    char chReplyMan[64];          ///< 回复人
    char chReplyTime[64];         ///< 回复时间
    char chReplyContent[3000];    ///< 回复内容
    char chUserName[64];          ///< 用户名
    int nProperty;                ///< 用户是否为发起人
    int nAssociate;               ///< 是否有回复
    int nHaveRead;                ///< 是否已读
}S_EventInfo;

///< 获取新事件的数目(18-int)
typedef struct
{
    char chUserName[64];          ///<用户名
}P_NewEventInfo;

///< 获取所有事件详细信息(18-out)
typedef struct
{
    int nTotal;                  ///<用户能看到的所有新事件数目
    int nOwnerNum;               ///<与用户发起的新事件数目
    int nRelatedNum;             ///<与用户相关的新事件数目
}S_NewEventInfo;

///< 修改未读事件状态(19-int)
typedef struct
{
    char chUserName[64];          ///<用户名
    int nState;                   ///<条件(0:全部事件 1:自己发起 2:与自身相关)
}P_ModEventStateInfo;

///< 全部事件信息模糊查询以及查询数目统计(20、21-int)
typedef struct
{
    char chUserName[64];          ///<用户名
    int nState;                   ///<状态(0:全部事件 1:自己发起 2:自身相关)
    int nClosed;                  ///<是否已关闭(0:打开 1:关闭 2:全部)
    int nPage;                    ///<页数
    int nShowEventNumInPage;      ///<每页显示多少条事件
    char chCondition[512];        ///<模糊查询条件
    char chStartTime[32];         ///<开始时间
    char chEndTime[32];           ///<结束时间
    char chLabelName[128];        ///<事件标签名
}P_QueryEventInfo;

///< 全部事件信息模糊查询(20-out)
typedef struct
{
    int nID;                      ///< 事件ID
    char chLabelName[64];         ///< 标签名
    char chSubmitMan[64];         ///< 事件发起人
    char chEventDescribe[128];    ///< 事件源
    char chHappenTime[64];        ///< 事件发生时间
    char chSubmitTime[64];        ///< 事件提交时间
    char chContent[1024];         ///< 事件内容
    int nState;                   ///< 事件状态(0:打开 1:关闭 2:全部)
    char chReplyMan[64];          ///< 回复人
    char chReplyTime[64];         ///< 回复时间
    char chReplyContent[3000];    ///< 回复内容
    char chUserName[64];          ///< 用户名
    int nProperty;                ///< 用户是否为发起人
    int nAssociate;               ///< 是否有回复
    int nHaveRead;                ///< 是否已读
    int nSort;                    ///< 记录序号
}S_QueryEventAllInfo;

///< 获取全部事件信息模糊查询集数目(21-out)
typedef struct
{
    int nTotal;                  ///<事件数目
}S_QueryEventNumInfo;

///< 获取所有标签信息(22-out)
typedef struct
{
    int nID;                        ///< 标签ID
    char chLabelName[128];          ///< 标签名
    char chContent[1024];           ///< 标签内容
}S_LabelInfo;

///< 客户端事件标签统计(23-int)
typedef struct
{
    int nType;                ///< 统计类型 1-统计事件标签；2-统计事件发起用户；3-按日统计；4-按月统计；
    char chUserName[64];      ///< 用户名
    char chLabelName[128];    ///< 标签名
    char chBeginTime[32];     ///< 开始时间
    char chEndTime[32];       ///< 结束时间
}P_LabelStaticsInfo;

///< 客户端事件标签统计(23-out)
typedef struct
{
    char chContent[128];      ///< 内容（标签名、用户名、日或月时间）
    int nCount;               ///< 数目
}S_LabelStaticsInfo;

///< 客户端用户密码修改(24-int)
typedef struct
{
    char chUser[64];       ///< 用户名
    char chOldPsw[64];     ///< 原密码
    char chNewPsw[64];     ///< 新密码
}P_ModUserPswInfo;

///< 报警日志信息(25、26-int)
typedef struct
{
    int nCondition;            ///< 条件（1:按网点统计；2:按报警类型统计；3:按日统计；4: 按月份统计）
    char chAlarmTypeName[64];  ///< 报警类型名称
    char chHostSource[64];     ///< 主机
    char chCameraSource[64];   ///< 摄像头
    char chAlarmArea[64];      ///< 报警地点
    int nPage;                 ///< 页数
    int nCount_Page;           ///< 每页显示记录条数
    char chAlarmBeginTime[32]; ///< 报警日志开始时间
    char chAlarmEndTime[32];   ///< 报警日志结束时间
}P_AlarmLogInfo;

///< 报警日志信息查询(25-out)
typedef struct
{
    char chAlarmTypeName[64];  ///< 报警类型名称
    char chAlarmSource[64];    ///< 报警源
    char chAlarmArea[64];      ///< 报警地点
    int nSumCount;             ///< 总记录条数
    int nSumPage;              ///< 总页数
    char chBeginTime[32];      ///< 报警日志开始时间（2012-01-01 00:00:00）
    char chBeginDay[32];       ///< 报警日志开始日期（2012-01-01）
    char chBeginMonth[32];     ///< 报警日志开始月份（2012-01）
    int nAlarmTypeID;                           ///< 报警信息ID
    int nProcessState;                          ///< 处理状态：1-处理；0-未处理
    char chProcessUser_VarC[64];                ///< 处理人
    char chProcessDate_Date[32];                ///< 处理日期
    int nProcessMethod_Int;                     ///< 处理方式：1-处理，2-转发；3-忽略
    char chProcessSuggestion_VarC[256];         ///< 处理意见
    char chProcessMemo_VarC[512];               ///< 备注
}S_AlarmLogQueryInfo;

///< 报警日志信息统计(26-out)
typedef struct
{
    char chContent[128];      ///< 内容（报警类型名、地点名、日或月时间）
    int nCount;               ///< 数目
}S_AlarmLogStaticsInfo;

///< 系统日志信息(27、28-int)
typedef struct
{
    int  nCondition;          ///< 条件号(1:按用户统计;2:按操作类型统计;3:按日统计;4: 按月份统计)
    char chUserName[64];      ///< 用户名
    char chSysLogType[128];   ///< 操作类型
    int  nPage;               ///< 页数
    int nCount_Page;          ///< 每页显示记录条数
    char chBeginTime[32];     ///< 系统日志开始时间
    char chEndTime[32];       ///< 系统日志结束时间
}P_SysLogInfo;

///< 系统日志信息查询(27-out)
typedef struct
{
    char chUserName[64];      ///< 用户名
    char chSysLogType[128];   ///< 操作类型
    char chActDetail[512];    ///< 操作具体信息
    char chActTime[32];       ///< 系统日志生成时间 （2012-01-01 00:00:00）
    char chActDate[32];       ///< 系统日志生成日期 （2012-01-01）
    char chActMonth[32];      ///< 系统日志生成月份（2012-01）
    int nSumCount;            ///< 总记录条数
    int nSumPage;             ///< 总页数
}S_SysLogQueryInfo;

///< 系统日志信息统计(28-out)
typedef struct
{
    char chContent[128];      ///< 内容（用户名、日志类型名、日或月时间）
    int nCount;               ///< 数目
}S_SysLogStaticsInfo;

///< 巡航相关节点信息(29-int)
typedef struct
{
    int nID;                  ///< 类别 1-预置点相关 ；2-巡航相关 ；3-轨迹相关
    int nType;                ///< 类型 1-添加 ；2-修改 ；3-删除
    int nNo;                  ///< 序号
    char chName[64];          ///< 名称
    char chFrontendName[64];  ///< 前端设备名
}P_CruiseInfo;

///< 巡航设置(30-int)
typedef struct
{
    char chFrontendName[64];   ///< 前端设备名
    char chCruiseName[64];     ///< 巡航名称
    int nNo;                   ///< 巡航编号
    char chPointName[2000];    ///< 预置点名字串
    char chPointNo[500];       ///< 预置点编号串
    char chPointTime[500];     ///< 预置点停留时间串
    char chPointSpeed[500];    ///< 到达预置点速度串
}P_CruiseSetInfo;

///< 获取预置点信息(31-out)
typedef struct
{
    char chFrontendCode[64];   ///< 前端设备编号
    char chPointName[64];      ///< 预置点名称
    int nNo;                   ///< 预置点序号
}S_ShowPrePointInfo;

///< 获取巡航信息(32-out)
typedef struct
{
    char chFrontendCode[64];   ///< 前端设备编号
    char chCruiseName[64];     ///< 巡航名称
    int nNo;                   ///< 巡航编号
    int nConsequeceNo;         ///< 巡航预置点顺序
    int nPointTime;            ///< 预置点停留时间
    int nPointSpeed;           ///< 到达预置点速度
    char chPointName[64];      ///< 预置点名字
    int nPointNo;              ///< 预置点编号
}S_ShowCruiseInfo;

///< 获取轨迹信息(33-out)
typedef struct
{
    char chFrontendCode[64];   ///< 前端设备编号
    char chLocusName[64];      ///< 轨迹名称
    int nNo;                   ///< 轨迹编号
}S_ShowLocusInfo;

///< 获取平台错误码信息(34-out)
typedef struct
{
    int nID;                   ///< 错误码编号
    char chContent[256];       ///< 错误码内容信息
}S_ShowErrorCodeInfo;

///< 获取操作日志类型信息(35-out)
typedef struct
{
    char chLogType[64];       ///< 操作日志类型信息
}S_ShowSysLogTypeInfo;

///< 256通道中心获取设备权限信息(36-out) : 传入char chUserName[64]
typedef struct
{
    long lDEVID;                   ///<设备ID号
    bool AlarmOutCtrl;             ///<报警输出口权限
    bool DevAct;                   ///<开关机控制权限
    bool AlarmInCtrl;              ///<报警输入口权限
    bool DevUpgrade;               ///<对设备升级权限
    bool DevTime;                  ///<对设备校时权限
    bool DevLogLookUp;             ///<对设备日志查看权限
    bool DevConfig;                ///<对设备配置权限
    bool TalkDevc;                 ///<对讲权限
    bool RecvAlarmDev;             ///<接收报警权限
    unsigned int RealTimeView[8];  ///<实时预览权限: 对应主机256通道（8个整数）
    unsigned int PlayBack[8];      ///<回放权限: 对应主机256通道（8个整数）
    unsigned int Download[8];      ///<下载权限: 对应主机256通道（8个整数）
}S_ShowCmsPrivilegeInfo;

///< 256通道客户端获取设备权限信息(37-out) : 传入char chUserName[64]
typedef struct
{
    char chUserName[64];          ///< 用户名
    char chRole[128];             ///< 用户角色
    char chPrivilege[128];        ///< 权限名称
    char chPrivilegeDetail[128];  ///< 详细权限信息
    int nHostID;                  ///< 对应的主机ID
    unsigned int nChannels[8];    ///< 对应主机256通道（8个整数）
}S_ShowClientPrivilegeInfo;

///< 添加、修改、删除用户信息(38、39、40-int)
typedef struct
{
    int  UserId;                 ///< 用户ID(修改、删除时传入)
    char cUserName[64];          ///< 用户名
    char cPsw[64];               ///< 密码
    int  cUserLevel;             ///< 用户级别
    char cFindPswQuestion[64];   ///< 用户电话
    char cFindPswAnswer[64];     ///< 用户Email
    bool IsLock;                 ///< 是否过滤网点
    char cRoleName[64];          ///< 所属角色
    char iEmployeeId[64];        ///< 员工ID
    char CreateTime_Date[64];    ///< 有效起始时间
    char Validity_Date[64];      ///< 有效终止时间
    char Memo[1024];             ///< 用户简介
    char Memo_ID[30000];         ///< 过滤选择区域
    char chAreaName[30000];      ///< 过滤网点信息(选择区域+父区域)
    bool bUseful;                ///< 用户启用/禁用状态
    char chLevels[64];           ///< 报警等级值串$
}P_ShowAboutUserInfo;

///< 显示角色信息(41-out)
typedef struct
{
    int nID;                    ///< 角色ID
    char chRoleName[64];        ///< 角色名
    char Memo[1024];            ///< 角色备注
    char CreateTime[64];        ///< 角色创建时间
}S_ShowRoleInfo;

///< 角色相关操作信息(42-int)
typedef struct
{
    int nCondition;             ///< 条件：1-add,2-mod,3-del
    int nID;                    ///< 角色ID(mod、del时传入)
    char chRoleName[64];        ///< 角色名
    char Memo[1024];            ///< 角色备注
}P_ShowAboutRoleInfo;

///< 省份区域编码信息(43-int)
/******************************
P_ShowAreaCodeInfo.nCondition:

0：返回所有区域详细信息
1：根据省份获取区域详细信息
2：根据城市获取区域详细信息
3：根据编码获取区域详细信息
4: 返回所有省份名称
******************************/
typedef struct
{
    int nCondition;             ///< 条件
    char chName[64];            ///< 名称（省份或城市）
    char chCode[64];            ///< 编码
}P_ShowAreaCodeInfo;

///< 省份区域编码信息(43-out)
typedef struct
{
    char chProvice[64];        ///< 省份
    char chCity[64];           ///< 城市
    char chCode[64];           ///< 对应编码
}S_ShowAreaCodeInfo;

///< 获取节点类型信息(44-out)
typedef struct
{
    int nID;                   ///< 节点类型编号
    char chName[64];           ///< 节点类型名
    char chImage[64];          ///< 节点图标名字
    int nLevel;                ///< 节点等级
}S_ShowNodeTypeInfo;

///< 修改节点类型信息(45-int)
typedef struct
{
    int nID;                   ///< 节点类型编号
    char chName[64];           ///< 节点类型名(修改后)
}P_ShowModNodeTypeInfo;

///< 标签相关信息操作(46-int)
typedef struct
{
    int nCondition;          ///< 条件：1-add,2-mod,3-del
    int nID;                 ///< 标签ID
    char chName[128];        ///< 标签名
    int nLocked;             ///< 是否锁定，默认为0，锁定为1
    char chNotes[512];       ///< 标签备注，默认为""
    int nProperty;           ///< 备用字段，默认为0
}P_ShowLabelInfo;

///< 获取标签相关信息(47-out)
typedef struct
{
    int nID;                 ///< 标签ID
    char chName[128];        ///< 标签名
    int nLocked;             ///< 是否锁定，默认为0，锁定为1（私密）
    char chNotes[512];       ///< 标签备注
    int nProperty;           ///< 备用字段
}S_ShowLabelInfo;

///< 摄像头区域相关信息操作(48-int)
typedef struct
{
    int nCondition;          ///< 条件：1-add,2-mod,3-del
    int nID;                 ///< 区域ID
    char chName[128];        ///< 区域名
    char chNotes[512];       ///< 区域备注，默认为""
    int nProperty;           ///< 备用字段，默认为0
}P_CameraAreaInfo;

///< 获取摄像头区域相关信息(49-out)
typedef struct
{
    int nID;                 ///< 区域ID
    char chName[128];        ///< 区域名
    char chNotes[512];       ///< 备注
}S_ShowCameraAreaInfo;

///< 获取日志信息(50-int)
typedef struct
{
    char strOperType[40];   ///< 操作类别
    char strOpp[40];        ///< 操作实体
    char strStartTime[50];  ///< 查询开始时间（包括日期）
    char strEndTime[50];    ///< 查询结束时间（包括日期）
    int nStart;             ///< 开始记录行
    int nEnd;               ///< 结束记录行
}P_OpLogCheckInfo;

///< 获取日志信息(50-out)
typedef struct
{
    char strOperType[64];      ///< 操作类别
    char strOpp[64];           ///< 操作实体
    char strOPPName[64];       ///< 操作对象名
    char strDateTime[32];      ///< 操作时间
}S_ShowOpLogCheckInfo;

///< 设置校时计划信息(51-int)
typedef struct
{
    char  chTimingBeginDate[32];    ///<开始日期
    char  chTimingPeriod[32];       ///<周期
    char  chCheckTIme[32];          ///<校时时间
}P_SetTimePlanInfo;

///< 获取校时计划信息(52-out)
typedef struct
{
    char  chTimingBeginDate[32];    ///<开始日期
    char  chTimingPeriod[32];       ///<周期
    char  chCheckTIme[32];          ///<校时时间
}S_ShowTimePlanInfo;

///< 批量设置（图片、码流）(53-int)
typedef struct
{
    int nType;                     ///< 批量类型 0-图片，1-码流
    char chAreaName[64];           ///< 网点名
    char chDeviceName[30000];      ///< 设备名
    char chFrontendName[30000];    ///< 摄像头名
    int nSize;                     ///< 图片大小 1-小，2-中，3-大
    int nNetMode;                  ///< 码流 1-cf,2-D1,3-720P,4-1080P
}P_SetMostInfo;

///< 报警主机（分区-防区）信息结构体(54、55、56-int)
typedef struct
{
    int nCondition;         ///< 条件：1-add,2-mod,3-del(分区信息)
    int nID;                ///< 分区编号(表中唯一标识，修改的时候需要传入)
    int nPartNo;            ///< 分区号
    char chPartName[100];   ///< 分区名字
    char chDvrName[100];    ///< 分区所属主机名字
    char chPartArea[8000];  ///< 分区包含的所有防区名字串
    int nAreaID;            ///< 防区编号(表中唯一标识)
    int nAreaNo;            ///< 防区号
    char chAreaName[100];   ///< 防区名字
}P_PartitionAreaInfo;

///< 显示具体报警主机的分区-防区信息(56-out)
typedef struct
{
    int ID;             ///< 分区号
    char chName[100];   ///< 分区名
    int nPartID;        ///< 分区唯一标识ID
    char chDvrName[100];///< 报警主机名字
    char chArea[100];   ///< 防区名字（探头名）
    int nDet;           ///< 通道号
    int nArea;          ///< 防区号
}S_ShowPartAreaInfo;

///< 角色权限信息设置(57-int)
typedef struct
{
    char chLenth[208300];  ///< 权限字符串(角色|权限|设备|通道|标记)
}P_SetRolePriviligeInfo;

///< 角色权限信息查询(58-int)
typedef struct
{
    int nID;                 ///< 0-所有主机，1-所选区域内主机
    char strRole[64];        ///< 角色名
    char chAreaName[30000];  ///< 区域串（nID == 1）
}P_ShowRolePriviligeInfo;

///< 角色权限信息查询(58-out)
typedef struct
{
    char chDvrName[64];     ///< 设备名
    bool bSpeak;            ///< 对讲权限
    bool bAlarm;            ///< 接警权限
    bool bControl;          ///< 控制权限
    bool bConfig;           ///< 配置权限
    char chRealplay[257];   ///< 预览权限
    char chPlayback[257];   ///< 回放权限
    char chLoad[257];       ///< 下载权限
}S_ShowRolePriviligeInfo;

///< 电视墙信息设置(59-int)
typedef struct
{
    int nTVID;                      ///<电视墙ID
    int nDecodeType;                ///<解码类型  1 软解 2 双显 主 3双显 副 ，4硬解
    int nPriorityType;              ///<行优先 1 列优先 2
    char chGroupName[128];          ///<日期组名 工作日组，假日组，特殊组
    char chDateNames[128];          ///<时间名 星期或日期
    char chUserName[64];            ///<用户名
    int  nTimeSequence;             ///<时间段号
    char chBeginTime[32];           ///<开始时间
    char chEndTime[32];             ///<结束时间
    int nSwitchTime;                ///<切换间隔时间
    int nScreenDevide;              ///<画面分割数
    char chMonitorSet[128];         ///<监视器 (监视器号\监视器分割数\序列输出\切换间隔)
    char chChannelNames[100000];    ///<通道串
}P_ShowSetScreeenInfo;

///< 预案信息设置(60-int)
typedef struct
{
    int nID;                          ///<预案组的编号
    char chGroupName[128];            ///<预案组名
    char chUserName[64];              ///<用户名
    int nSwitchTime;                  ///<切换间隔时间
    int nScreenDevide;                ///<画面分割数
    char chMonitorSet[128];           ///<监视器 (监视器号\监视器分割数\序列输出\切换间隔)
    char chChannelNames[100000];      ///<通道串
}P_ShowSetEmergencyInfo;

///< 获取用户过滤网点信息(61-out)
typedef struct
{
    char chUserName[64];    ///<用户名
    char chAreaName[64];    ///<网点名称
    char chAreaCode[64];    ///<网点编号
}S_ShowUserAreaInfo;

///< 修改用户所属角色(62-int)
typedef struct
{
    char strUser[8000];     ///< 用户名
    char strRole[64];       ///< 角色名
}P_ShowModUserRoleInfo;

///< 通道组信息相关操作(63-int)
typedef struct
{
    int nCondition;         ///< 条件：1-add,2-mod,3-del
    char chGroupName[100];  ///< 通道组名
    char chOldName[100];    ///< 原通道组名(mod时传入)
}P_ChannelGroupInfo;

///< 通道组显示相关操作(64-int)
typedef struct
{
    int nCondition;            ///< 条件：1-显示所有通道组，2-显示通道组下的通道,3-全部通道组信息
    char chGroupName[100];     ///< 通道组名(2-传入)
}P_ShowChannelGroupInfo;

///< 通道组显示相关操作(64-out)
typedef struct
{
    char chGroupName[100];     ///< 通道组名
    char chFrontendName[100];  ///< 通道名字
    char chDvrCode[64];        ///< 主机编号
    int nChannelNo;            ///< 通道号
    int nSequence;             ///< 序号
}S_ShowChannelGroupInfo;

///< 通道组设置相关操作(65-int)
typedef struct
{
    int nCondition;              ///< 条件：1-设置，2-移出
    char chFrontendNames[30000]; ///< 通道名集合
    char chGroupName[100];       ///< 组名
    char chOrder[30000];         ///< 排列顺序
}P_SetChannelGroupInfo;

///< 显示数据库空间管理信息(66-out)
typedef struct
{
    char chType[64];            ///< 日志类型
    char chCurrentSize[32];     ///< 当前大小(MB)
    char chDaySize[32];         ///< 每日占用空间(MB)
    char chEmpty[32];           ///< 存储磁盘可用空间(MB)
    char chEmptyDays[32];       ///< 实际还可存储天数
    char chCleanDay[32];        ///< 最后一次清理日期
    char chSaveMonth[32];       ///< 不足保存信息量
}S_ShowSqlManageInfo;

///< 设置报警日志清理时间(67-int)
typedef struct
{
    int nMonth;                 ///< 时间长度
}P_SetCleanTimeInfo;

///< 获取数据库备份路径信息(68-out)
typedef struct
{
    char chPath[256];          ///< 路径位置
}S_GetSqlSaveInfo;

///< 设置数据库备份路径(69-int)
typedef struct
{
    char strFilePath[256];     ///< 路径位置
}P_SetSqlSaveInfo;

///< 获取存储磁盘信息(70-out)
typedef struct
{
    char chDisk[16];           ///< 盘符
    char chFreeSize[32];       ///< 剩余空间(MB)
}S_ShowDiskInfo;

///< 判断配置客户端登录账号信息(71-int)
typedef struct
{
    char chUser[64];         ///< 用户名
    char chPassword[64];     ///< 密码
}P_GetConfigClientInfo;

///< 获取配置客户端登录具体设备的账号信息(72-int)
typedef struct
{
    char chDevCode[128];    ///< 设备编号
}P_GetConfigClientLoginInfo;

///< 获取配置客户端登录具体设备的账号信息(72-out)
typedef struct
{
    int nManufatureType;     ///< 品牌类型
    int nPort;               ///< 端口
    char chUser[64];         ///< 用户名
    char chPassword[64];     ///< 密码
    char chIP[64];           ///< IP地址
    char chModeType[128];    ///< 品牌子类型
}S_GetConfigClientLoginInfo;

///< 设置服务器登录信息(73-int)
typedef struct
{
    char chServerName[64];   ///< 服务器名
    char chDevName[30000];   ///< 设备名
    char chUserName[64];     ///< 用户名
    char chPassWord[64];     ///< 密码
}P_SetServerLoginInfo;

///< 显示服务器登录信息(74-int)
typedef struct
{
    char chServerName[128];    ///< 服务器名
    int nPageNum;              ///< 页数
}P_GetServerLoginInfo;

///< 显示服务器登录信息(74-out)
typedef struct
{
    char chServerName[64];    ///< 服务器名
    char chDevName[64];       ///< 设备名
    char chUser[64];          ///< 用户
    char chPassword[64];      ///< 密码
    char chIP[64];            ///< IP地址
    char chManufature[128];   ///< 品牌
    int nTotalPageNum;        ///< 页数
}S_GetServerLoginInfo;

///< 服务器登录设备删除、清空(75、76-int)
typedef struct
{
    char chServerOrClient[128];     ///< 服务器名
    int ServerType;                 ///< 服务器类型：1-中心，2-报警，3-媒体
    char chDeviceName[128];         ///< 设备名(删除时传入)
}P_DelServerLoginInfo;

///< 设置客户端登录信息(77-int)
typedef struct
{
    char chUserName[64];              ///<client
    char chDevName[30000];            ///<设备名
    char chConnDVRUserName[64];       ///<用户名
    char chConnDVRPassWord[64];       ///<密码
}P_SetClientLoginInfo;

///< 显示客户端登录信息(78-int)
typedef struct
{
    char chUserName[128];    ///< 用户名
    int nPageNum;            ///< 页数
}P_GetClientLoginInfo;

///< 显示客户端登录信息(78-out)
typedef struct
{
    char chUserName[128];     ///< 用户名
    int nDevID;               ///< 设备ID
    char chDevName[64];       ///< 设备名
    char chUser[64];          ///< 用户
    char chPassword[64];      ///< 密码
    char chIP[64];            ///< IP地址
    char chManufature[128];   ///< 品牌
    int nTotalPageNum;        ///< 页数
}S_GetClientLoginInfo;

///< 客户端登录设备删除、清空(79、80-int)
typedef struct
{
    char chServerOrClient[128];///< 客户端名
    char chDeviceName[128];    ///< 设备名
}P_DelClientLoginInfo;

///< 复制用户登录密码(81-int)
typedef struct
{
    char chUser[40];           ///< 复制用户名
    char chCopyUser[3000];     ///< 需要复制的n个用户
}P_CopyClientLoginInfo;

///< 存储配置设置(82-int)
typedef struct
{
    int  nStoreType;               ///<存储方式
    char chDataType[64];           ///<数据类型
    char chStoreDays[100];         ///<保存天数
    char chPackageIntervals[100];  ///<间隔
    char chRedundancyTimes[100];   ///<冗余时间
    char chMediaTypes[100];        ///<数据格式
    char chBeginTimes[100];        ///<开始时间
    char chEndTime[100];           ///<结束时间
    int  nCapacityThreshold;       ///<存储剩余容量阈值
    int  nDelDays;                 ///<删除天数
    bool bReserveMarkedData;       ///<保留标签数据
}P_SetVideoInfo;

///< 设置存储计划(83-int)
typedef struct
{
    char chPlanName[64];           ///<计划名
    char chBeginTime[64];          ///<开始时间
    char chEndTime[64];            ///<结束时间
    int  nStorageType ;            ///<录像类型  1为视频 2为图片 3为音频
    int  nConfigSequence;          ///<时间段
}P_SetStorageInfo;

///< 设置通道存储计划相关信息(84-int)
typedef struct
{
    char chPlanName[64];           ///<计划名
    char chFrontendNames[500000];  ///<对应录像的通道名集合
    char chDateNames[128];         ///<对应录像的单个或多个星期
}P_SetChannelPlanInfo;

///< 显示存储配置设置信息(85-out)
typedef struct
{
    int  nStoreType;               ///<存储方式
    int  nDataType;                ///<数据类型
    int  nStoreDays;               ///<保存天数
    int  nPackageIntervals;        ///<打包时间
    int  nRedundancyTimes;         ///<冗余时间
    char chMediaTypes[32];         ///<数据格式
    char chBeginTimes[32];         ///<开始时间
    char chEndTime[32];            ///<结束时间
}S_GetVideoInfo;

///< 显示清盘设置(86-out)
typedef struct
{
    int nLeave;          ///< 剩余容量
    int nDel;            ///< 删除容量
    bool bLabel;         ///< 是否保留标签
}S_GetCleanDiskInfo;

///< 显示存储计划相关信息(87-int)
/*
P_GetStorageInfo.nCondition:
0：获取所有设备的计划设置信息
1：获取计划详细信息
2：根据星期和网点获取相应的计划设置信息
3：根据网点\主机\摄像头获取相应的计划设置信息
4：根据摄像头名和计划获取对应的星期
5: 根据摄像头名查看计划信息[包括星期]
*/
typedef struct
{
    int  nCondition;               ///<条件号(0,1,2,3,4)
    char chPlanName[64];           ///<计划名(4)
    char chFrontendName[128];      ///<通道名(4)
    char chAreaName[30000];        ///<前端设备对应网点(2,3)
    int nWeek;                     ///<星期值：0 ~ 6(2)
}P_GetStorageInfo;

///< 显示存储计划相关信息(87-out)
typedef struct
{
    int nID;                     ///<计划ID(1)
    int nSequence;               ///<时间段(1)
    char chBegin[64];            ///<开始时间(1)
    char chEnd[64];              ///<结束时间(1)
    char chStorage[64];          ///<存储方式(1)
    char chPlanName[64];         ///<计划名(0,1,2,3)
    char chDevName[64];          ///<设备名(0,2,3)
    char chIP[64];               ///<IP地址(0,2,3)
    char chFrontendName[128];    ///<通道名(0,2,3)
    int nChannelNo;              ///<通道号(0,2,3)
    int nWeek;                   ///<星期值：0 ~ 6(4)
}S_GetStorageInfo;

///< 删除存储计划(88-int)
typedef struct
{
    char chFrontendNames[500000];  ///<对应录像的通道名集合
}P_DelStorageInfo;

///< 中心管理服务器相关操作(89-int)(add、mod、del)
typedef struct
{
    int  nCondition;            ///<条件:1-add,2-mod,3-del
    char chCode[64];            ///<编码
    char chName[64];            ///<名称
    char chIP[64];              ///<主IP地址
    char chBackUpIP[64];        ///<副IP地址
    int  nCenterType;           ///<CMS类型，（本级、下级标识）
    char chServerNo[64];        ///<中心编号
    char chUserName[64];        ///<用户名称
    char chPassWord[64];        ///<密码
    char chMemo[512];           ///<备注(修改时为原中心名)
}P_CMSNodeInfo;

///< 媒体服务器相关操作(90-int)(add、mod、del)
typedef struct
{
    int  nCondition;            ///<条件:1-add,2-mod,3-del
    char chCode[64];            ///<编码(修改时为原媒体名)
    char chName[64];            ///<名称
    char chIP[64];              ///<IP地址
    int  nMSType;               ///<MS类型，（转发、储存、点播）
    char chPassWord[64];        ///<密码
    char chMemo[512];           ///<备注
}P_MSNodeInfo;

///< 显示媒体服务器详细信息(91-out)
typedef struct
{
    int  nID;                   ///<ID编号
    char chCode[64];            ///<编码
    char chName[64];            ///<名称
    char chIP[64];              ///<IP地址
    int  nMSType;               ///<MS类型
    char chPassWord[64];        ///<密码
    char chMemo[512];           ///<备注
}S_GetMSNodeInfo;

///< 媒体服务器划分设置、删除、显示(92、93、94-int)
typedef struct
{
    int  nCondition;            ///<条件:1-覆盖方式,2-追加方式(92)
    char chMSName[64];          ///<媒体名称(92、93、94)
    char chDevName[30000];      ///<主机串(92、93)
}P_MSConfigSetInfo;

///< 显示媒体服务器划分详细信息(94-out)
typedef struct
{
    char chDevName[64];         ///<主机名称
}S_GetMSConfigInfo;

///< 报警服务器相关操作(95-int)(add、mod、del)
typedef struct
{
    int  nCondition;            ///<条件:1-add,2-mod,3-del
    char chCode[64];            ///<编码(修改时为原报警名)
    char chName[64];            ///<名称
    char chIP[64];              ///<IP地址
    char chPassWord[64];        ///<密码
    char chMemo[512];           ///<备注
}P_ASNodeInfo;

///< 显示报警服务器详细信息(96-out)
typedef struct
{
    int  nID;                   ///<ID编号
    char chCode[64];            ///<编码
    char chName[64];            ///<名称
    char chIP[64];              ///<IP地址
    char chPassWord[64];        ///<密码
    char chMemo[512];           ///<备注
}S_GetASNodeInfo;

///< 报警服务器划分设置、删除、显示(97、98、99-int)
typedef struct
{
    int  nCondition;            ///<条件:1-覆盖方式,2-追加方式(97)
    char chASName[64];          ///<报警名称(97、98、99)
    char chDevName[30000];      ///<主机串(97、98)
}P_ASConfigSetInfo;

///< 显示报警服务器划分详细信息(99-out)
typedef struct
{
    char chDevName[64];         ///<主机名称
}S_GetASConfigInfo;

///< 获取最大报警编号(100-out)
typedef struct
{
    int nMaxID;               ///<报警最大编号
}S_GetAlarmMaxIDInfo;

///< 报警类型相关操作(101-int)(add、mod、del)
typedef struct
{
    int  nCondition;                ///< 条件:1-add,2-mod,3-del
    int nID;                        ///< 编号
    int nAC;                        ///< AC编号
    char strTypeName[64];           ///< 类型名
    char strTimeStart[64];          ///< 开始时间
    char strTimeEnd[64];            ///< 结束时间
    char strSound[256];             ///< 报警声音
    int  ConfigSequence;            ///< 报警时间段ID
    int  nPriority;                 ///< 报警优先级
    int  bFliter;                   ///< 是否过滤
    int  nFliterTimeInterval;       ///< 过滤时间间隔
    int  bWord;                     ///< 是否过滤文字
    int  bVideoStore;               ///< 是否联动存储
    int  nVideoStoreTime;           ///< 视频存储时间
    int  bAlarmInfoStore;           ///< 报警信息是否存储
}P_AlramTypeInfo;

///< 显示报警配置详细信息(102、608-in)
/*
P_GetAlarmConfigInfo.nCondition:
0: 所有报警类型信息
1：根据AC编号显示特定报警类型信息
2: 根据报警ID和时间段显示特定报警类型信息
*/
typedef struct
{
    int nCondition;                 ///< 报警编号
    int nID;                        ///< 报警编号
    int ConfigSequence;             ///< 时间段
    int nAC;                        ///< AC编号
}P_GetAlarmConfigInfo;

///< 显示报警配置详细信息(102-out)
typedef struct
{
    int nID;                        ///< 报警编号
    int nAC;                        ///< AC编号
    char strTypeName[64];           ///< 类型名
    int  ConfigSequence;            ///< 时间段
    char strTime[64];               ///< 起始时间
    bool  bWord;                    ///< 是否过滤文字
    bool  bVideoStore;              ///< 是否联动存储
    int  nVideoStoreTime;           ///< 视频存储时间
    bool  bFliter;                  ///< 是否过滤
    int  nFliterTimeInterval;       ///< 过滤时间间隔
    bool  bAlarmDeal;               ///< 报警是否处理
}S_GetAlarmConfigInfo;

///< 区域节点信息相关操作(103-int)(add、mod、del)
typedef struct
{
    int  nCondition;                ///<条件:1-add,2-mod,3-del
    char chSerial[64];              ///<编码
    char chName[64];                ///<名称
    char chAddress[256];            ///<网点地址
    char chManName[256];            ///<联系人
    char chContactInfo[256];        ///<联系方式
    char chFatherNo[64];            ///<上一级编码
    char chNodeName[64];            ///<节点类型名
    int  nXPos;                     ///<在地图上的X坐标 TODO
    int  nYPos;                     ///<在地图上的Y坐标 TODO
    int  nSize;                     ///<图标大小1-大图标，-小图标
    int  nWay;                      ///<图标方向1-正上、-正下、-正左、-正右、-右上、-右下、-左上、-左下
    char chMapName[64];             ///<地图文件名称
    char chMapPath[256];            ///<地图文件路径
    int  nMapSize;                  ///<地图大小（字节）
    int nNetWidthLimit;             ///<网点带宽
    int nUpLoadMaxChlNum;           ///<最大上传通道数
    bool bAutoSwitch;               ///<码流是否自动切换
    char chMemo[512];               ///<备注信息(2)
    int nCenterNo;                  ///<中心编号
    int nAreaPosition;              ///<场所
}P_AreaNodeOpInfo;

///< 区域节点移动(104-int)
typedef struct
{
    char chNodeCode[64];          ///<编号
    int nXPos;                    ///<X坐标
    int nYPos;                    ///<Y坐标
}P_AreaNodeMoveInfo;

///< 设备节点信息相关操作(106-int)(add、mod、del)
typedef struct
{
    int  nCondition;                     ///<条件:1-add,2-mod,3-del
    char chCode[64];                     ///<编码
    char chName[64];                     ///<名称
    char chIP[64];                       ///<IP地址
    char chManufacturer[128];            ///<厂商
    char chModel[128];                   ///<型号
    int  nPort;                          ///<端口号
    char chFatherNodeName[64];           ///<父节点名称
    int  nNodeType;                      ///<节点类型名
    int  nXPos;                          ///<X坐标
    int  nYPos;                          ///<Y坐标
    int  nImageSize;                     ///<图标大小
    int  nImageWay;                      ///<图标方向
    int  bCanTalk;                       ///<是否对讲
    int  bCanHostTalk;                   ///<是否主机对讲
    int  bIsConnected;                   ///<是否连接服务器
    int  nTalkType;                      ///< 0为通道对讲   1为主机对讲
    char chIPTalkID[64];                 ///< IP对讲关联ID，0为未使用
    int  nAlarmAreaLevel;                ///<区域报警等级
    int  bAutoIP;                        ///<是否动态IP
    char chAlarmTypeNames[2000];         ///<报警类型数组
    char chAlarmSoundNames[10000];       ///<关联声音
    char chAlarmSoundPath[256];          ///<关联声音对应路径
    char chRelatedChannelNames[30000];   ///<关联通道组
    char chRelatedDeviceNames[30000];    ///<关联通道对应的设备
    int nKeyPart;                        ///<部位
    char chSetDate[32];                  ///<设备添加时间
}P_DevNodeOpInfo;

///< 设备节点移动(107-int)
typedef struct
{
    char chNodeCode[64];          ///<编号
    int nXPos;                    ///<X坐标
    int nYPos;                    ///<Y坐标
}P_DevNodeMoveInfo;

///< 前端节点信息相关操作(108-int)(add、mod、del)
typedef struct
{
    int  nCondition;                   ///<条件:1-add,2-mod,3-del
    char chCode[64];                   ///<编码
    char chName[64];                   ///<名称
    int  nChannelNO;                   ///<通道号
    int  nNodeType;                    ///<节点类型（摄像头、探头、报警输出等）
    int  nDEVStyle;                    ///<设备类型（壁挂、枪机、球机等）
    char chAreaName[64];               ///<所属区域名称
    char chAreaCode[64];               ///<对应区域编号
    char chUpperName[64];              ///<所属上级设备名称
    char chUpperCode[64];              ///<对应主机编号  
    int  nXPos;                        ///<X坐标
    int  nYPos;                        ///<Y坐标
    int  nImageSize;                   ///<图标大小
    int  nImageWay;                    ///<图标方向
    bool bHavePTZ;                     ///<是否有云台
    int  nAlarmAreaLevel;              ///<区域报警等级
    int  nSreamNetModel;               ///<视频网传模式（主/子码流）
    bool bChannelRelated;              ///<是否联动通道
    bool bIsTalkTrigger;               ///<是否对讲触发
    int  nCapitalId;                   ///<资产ID
    char chMemo[512];                  ///<备注信息
    char chAlarmTypeNames[2000];       ///<报警类型数组
    char chAlarmSoundNames[2000];      ///<关联声音
    char chAlarmSoundPath[256];        ///<关联声音对应路径
    char chRelatedChannelNames[30000]; ///<关联通道组
    char chRelatedDeviceNames[30000];  ///<关联通道对应的设备
    int nKeyPart;                      ///<部位
}P_FrontendNodeOpInfo;

///< 前端节点移动(109-int)
typedef struct
{
    char chNodeCode[64];          ///<编号
    int nXPos;                    ///<X坐标
    int nYPos;                    ///<Y坐标
}P_FrontendNodeMoveInfo;

///< 显示品牌信息(110-int)
/*
P_GetManufatureInfo.nCondition:
0: 显示所有品牌类型
1: 显示dvr品牌类型
2: 显示报警主机品牌类型
3: 显示门禁品牌类型
4: 显示IP对讲设备品牌类型
5: 显示所有IP对讲设备
6: 根据品牌显示所有设备
7: 显示指纹仪品牌类型
*/
typedef struct
{
    int  nCondition;             ///<条件
    char chManufature[128];      ///<品牌名(6)
}P_GetManufatureInfo;

///< 显示品牌信息(110-out)
typedef struct
{
    char chName[64];            ///<名称
    int nID;                    ///<类型号
}S_GetManufatureInfo;

///< 显示IP信息(111-int)
/*
P_GetIPInfo.nCondition:
0: 显示所有IP
1: 主机名显示IP和类型编号
*/
typedef struct
{
    int  nCondition;             ///<条件
    char chName[128];            ///<主机名(1)
}P_GetIPInfo;

///< 显示IP信息(111-out)
typedef struct
{
    char chIP[64];              ///<名称
    int nID;                    ///<类型号
}S_GetIPInfo;

///< 根据相关条件显示设备信息(112-int)
/*
P_GetInfoByDvrInfo.nCondition:
0: 根据设备名称和类型(10,12,13)获取已存在的通道号
1: 根据设备名称显示其下最大通道号
2: 根据设备名称显示其下的通道及通道号
3: 根据设备名称显示其对讲联动通道信息
4: 获取所有设备
5: 获取拥有前端设备的所有设备
6: 根据区域编号显示本层及上下层的所有设备信息
7: 根据设备名称显示其编码
8: 根据设备编码显示其名称
9: 根据设备名显示设置的报警类型声音
10: 显示所有设备及其最大通道号
*/
typedef struct
{
    int  nCondition;             ///<条件
    char chName[128];            ///<设备名
    char chCode[128];            ///<设备编码或区域编号
    int nNodeType;               ///<前端类型
}P_GetInfoByDvrInfo;

///< 根据相关条件显示设备信息(112-out)
typedef struct
{
    char chName[128];            ///<设备名
    char chCode[128];            ///<设备编码
    char chFrontendName[128];    ///<前端设备名
    int nChannelNo;              ///<通道号
    char chTypeName[128];        ///<报警类型名
    char chSoundName[128];       ///<报警声音
    char chDefaultName[128];     ///<默认声音
}S_GetInfoByDvrInfo;

///<设置DEV登录用户密码(113-int)
typedef struct
{
    char chName[128];            ///<设备名
    char chUser[128];            ///<用户名
    char chPassword[128];        ///<密码
}P_SetLoginDvrInfo;

///<前端设备相关操作(114、115、116-int)
typedef struct
{
    char chName[128];            ///<前端设备名
}P_FrontendInfo;

///< 根据前端设备名显示报警类型声音(114-out)
typedef struct
{
    char chFrontendName[128];    ///<前端设备名
    char chTypeName[128];        ///<报警类型名
    char chSoundName[128];       ///<报警声音
    char chDefaultName[128];     ///<默认声音
}S_GetSoundByFrontendInfo;

///< 根据前端设备名显示联动对讲通道(115-out)
typedef struct
{
    char chName[128];            ///<设备名
    char chCode[128];            ///<设备编码
    char chFrontendName[128];    ///<前端设备名
    int nChannelNo;              ///<通道号
    int nSequence;               ///<序号
}S_GetTalkByFrontendInfo;

///< 根据名称获取前端设备信息(摄像头、探头、输出)(116-out)
typedef struct
{
    int nID;                    ///< 设备ID
    char chFrontendCode[64];    ///< 设备编码
    char chFrontendName[128];   ///< 设备名称
    int nChannelNo;             ///< 通道号
    int nDeviceType;            ///< 设备类型(10、12、13)
    int nDeviceUseage;          ///< 设备类型移位标识(2,1,4)
    char chAreaCode[64];        ///< 所在区域编码
    char chHostCode[64];        ///< 所属主机编码
    int nProportionX;           ///< 千分制X坐标
    int nProportionY;           ///< 千分制Y坐标
    int nImageSize;             ///< 图标大小
    int nImageDirection;        ///< 图标方向
    int nHolder;                ///< 云台控制标志
    int nSpeak;                 ///< 对讲触发标志
    int nAlarmFilter;           ///< 报警过滤标志
    char chAlarmFilterDate[64]; ///< 报警过滤时间
    int nAlarmLevel;            ///< 报警区域等级
    int nChannelRelated;        ///< 联动通道标志
    int nNetModel;              ///< 网传模式
    char chAreaName[256];       ///< 所在区域名称
    char chDeviceName[256];     ///< 所属主机名称
    char chNetModel[64];        ///< 码流类型详细信息
    int nCameraAreaID;          ///< 摄像头区域类别ID
    char chCenterNo[128];       ///< 中心编号
    char chFatherCenterNo[128]; ///< 父中心编号
    char chMemoType[32];        ///< 前端类型
    int nKeyPart;               ///< 部位
}S_OnlyFrontendNodeInfo;

///<远程通道名匹配(117-int)
typedef struct
{
    char chCode[128];            ///<设备编码
    char chFrontendName[128];    ///<前端设备名
    int nChannelNo;              ///<通道号
    int nNodeType;               ///<类型
}P_AutoModNameInfo;

///<配置体检项(118-int)
/*
P_ConfigCheckInfo.nCondition
0: 配置总览
1: 中心未添加
2: 媒体未添加
3: 报警未添加
4: 媒体未划分
5: 报警未划分
6: 中心登录设置
7: 媒体登录设置
8: 报警登录设置
9: 探头未设置联动
10: 未添加用户
11: 未设置客户端登录
12: 未设置视频通道组
13: 未设置存储
*/
typedef struct
{
    int nCondition;   ///<条件
}P_ConfigCheckInfo;

///<配置体检项(118-out)
typedef struct
{
    int nNum;                  ///<数目
    char chMemo[128];          ///<备注
    char chDevName[128];       ///<设备名
    char chManufature[128];    ///<设备厂家
    char chFrontendName[128];  ///<前端设备名（探头）
    char chUser[64];           ///<用户名
}S_ConfigCheckInfo;

///<设备信息总览(119-int)
/*
P_ExcelCheckInfo.nCondition
1: 网点信息；
2: 主机信息；
3: 主机报警声音；
4: 前端设备信息；
5: 前端设备报警声音;
6: 摄像头联动信息；
7: 探头联动信息;
8: 前端设备反向匹配
*/
typedef struct
{
    int nCondition;      ///<条件类型
    char chCon[512];     ///<匹配条件
    int nCount;          ///<获取条数(默认0，代表获取全部)
}P_ExcelCheckInfo;

///<设备信息总览(119-out)(1)
typedef struct
{
    int nID;                   ///<编号
    char chArea[64];           ///<网点名
    char chFatherArea[64];     ///<上级网点名
    char chAddress[128];       ///<地址
    char chContactor[128];     ///<联系人
    char chTel[64];            ///<联系方式
    int nWidth;                ///<网点带宽
    int nLoad;                 ///<上传路数
    char chImage[64];          ///<布防图名称
}S_ExcelCheckInfo_1;

///<设备信息总览(119-out)(2)
typedef struct
{
    int nID;                   ///<编号
    char chHost[64];           ///<主机名称
    char chIP[64];             ///<IP地址
    char chArea[64];           ///<所属网点
    char chDevType[64];        ///<设备类型
    char chManufature[128];    ///<生产厂家
    char chModel[128];         ///<型号
    int nPort;                 ///<端口
    char chSpeak[16];          ///<能否对讲
    char chSpeakMemo[64];      ///<对讲方式
    char chLevel[16];          ///<报警等级
    char chFrontend[128];      ///<联动通道名
    int nSequence;             ///<联动序号
}S_ExcelCheckInfo_2;

///<设备信息总览(119-out)(3)
typedef struct
{
    int nID;                   ///<编号
    char chHost[64];           ///<主机名称
    char chType[64];           ///<报警类型
    char chSound[64];          ///<报警声音
}S_ExcelCheckInfo_3;

///<设备信息总览(119-out)(4、8)
typedef struct
{
    int nID;                   ///<编号
    char chName[128];          ///<前端设备名称
    int nChannelNo;            ///<通道号
    char chDevType[64];        ///<设备类型
    char chSubType[128];       ///<设备子类型
    char chHost[64];           ///<所属DVR
    char chArea[64];           ///<所属区域
    char chLevel[16];          ///<报警区域优先级
    char chFrontend[128];      ///<联动通道名
    int nSequence;             ///<联动序号
}S_ExcelCheckInfo_4;

///<设备信息总览(119-out)(5)
typedef struct
{
    int nID;                   ///<编号
    char chName[128];          ///<前端设备名称
    char chType[64];           ///<报警类型
    char chSound[64];          ///<报警声音
}S_ExcelCheckInfo_5;

///<设备信息总览(119-out)(6、7)
typedef struct
{
    char chFrontend[128];       ///<前端设备名称
    char chDevName[128];        ///<设备名
    char chRelateFrontend[128]; ///<联动通道名
    char chRelateDevName[128];  ///<联动通道所属主机
}S_ExcelCheckInfo_6;

///<手机用户信息(120、121-int,120-out)
typedef struct
{
    char chUserName[64];       ///<用户名
    char chPhone[128];         ///<电话
    char chEmail[128];         ///<邮箱
    char chAbout[512];         ///<用户简介
    char chImage[128];         ///<用户头像
}PhoneUserInfo;

///<显示报警主机分防区信息(122-int)
/*
* 0：获取所有报警主机的分防区信息
* 1：根据设备名获取报警主机的分防区信息
* 2：根据设备ID获取报警主机的分防区信息
*/
typedef struct
{
    int nPartID;             ///< 分区号
    int nDefenseNum;         ///< 防区数
    int DefenseNo[256];      ///< 防区号列表
	char chPartitionName[128]; ///<分区名称
}PartionInformation;
typedef struct
{
    int nCondition;       ///< 条件
    char chDevName[128];  ///< 设备名
    int nDevID;           ///< 设备ID
}P_AlarmPartionInfo;

///<显示报警主机分防区信息(122-out)
typedef struct
{
    int nDevID;                   ///<设备ID
    char chDevName[128];          ///<设备名
    int nPartNum;                 ///<分区数目
    PartionInformation Part[33];  ///<分区详细信息
}S_AlarmPartionInfo;

///<显示单个信息(123-int)
/*
* 0：根据编码获取单个设备信息
* 1：根据名称获取单个设备信息
*/
typedef struct
{
    int nCondition;          ///< 条件
    char chCode[64];         ///< 编号
    char chName[128];        ///< 名称
}P_OnlyOneInfo;

///<手机获取所有用户头像信息(124-out)
typedef struct
{
    char chUserName[64];    ///<用户名
    int nUserNum;           ///<用户数量
    char chImage[128];      ///<头像名称
}S_UserImageInfo;

///<手机获取所有事件详细信息(125-int)
typedef struct
{
    char chUserName[64];          ///<用户名
    int nPage;                    ///<页数(第n页)
    int nShowEventNumInPage;      ///<每页显示多少条事件
    int nClosed;                  ///<是否已关闭(0:打开 1:关闭 2:全部)
    int nState;                   ///<条件(0:全部事件 1:自己发起 2:与自身相关)
}P_EventByPhoneInfo;

///<手机获取所有事件详细信息(125-out)
typedef struct
{
    int nEventNum;                ///< 事件数量
    int nID;                      ///< 事件ID
    char chLabelName[64];         ///< 标签名
    char chSubmitMan[64];         ///< 事件发起人
    char chEventDescribe[128];    ///< 事件源
    char chHappenTime[64];        ///< 事件发生时间
    char chSubmitTime[64];        ///< 事件提交时间
    char chContent[1024];         ///< 事件内容
    int nState;                   ///< 事件状态(0:打开 1:关闭 2:全部)
    int nReplyNum;                ///< 回复数量
    int nProperty;                ///< 用户是否为发起人
    int nHaveRead;                ///< 是否已读
}S_EventByPhoneInfo;

///<手机获取指定事件的所有回复(126-int)
typedef struct
{
    int nID;                      ///< 事件ID
}P_ReplyByOneInfo;

///<手机获取指定事件的所有回复(126-out)
typedef struct
{
    int nReplyNum;                ///< 回复数量
    char chReplyMan[64];          ///< 回复人
    char chReplyTime[64];         ///< 回复时间
    char chReplyContent[512];     ///< 回复内容
    char chTimeDescription[32];   ///< 时间描述
}S_ReplyByOneInfo;

///<手机获取所有事件(通过时间)(127-int)
typedef struct
{
    char chUserName[64];          ///<用户名
    char chLastTime[32];          ///<最后一条记录时间
    int nShowEventNumInPage;      ///<每页显示多少条事件
    int nClosed;                  ///<是否已关闭(0:打开 1:关闭 2:全部)
    int nState;                   ///<条件(0:全部事件 1:自己发起 2:与自身相关)
}P_AllEventPhoneInfo;

///<手机获取所有事件(通过时间)(127-out)
typedef struct
{
    int nEventNum;                ///< 事件数量
    int nID;                      ///< 事件ID
    char chLabelName[64];         ///< 标签名
    char chSubmitMan[64];         ///< 事件发起人
    char chEventDescribe[128];    ///< 事件源
    char chHappenTime[64];        ///< 事件发生时间
    char chSubmitTime[64];        ///< 事件提交时间
    char chContent[1024];         ///< 事件内容
    int nState;                   ///< 事件状态(0:打开 1:关闭 2:全部)
    int nReplyNum;                ///< 回复数量
    int nProperty;                ///< 用户是否为发起人
    int nHaveRead;                ///< 是否已读
    char chLastTime[32];          ///< 最后一条记录时间
    char chTimeDescription[32];   ///< 时间描述
}S_AllEventPhoneInfo;

///<GS经纬度设置(128-int)
typedef struct
{
    int nAreaID;                  ///<区域ID
    char chXGS[25];               ///<GS 纬度
    char chYGS[25];               ///<GS 经度
}P_GSMAPInfo;

///<GS设置信息获取(129,134-int)
typedef struct
{
    int nCondition;               ///<条件[0-已设置，1-全部]
}P_GSMAPSHOWInfo;

///<GS设置信息获取(129-out)
typedef struct
{
    int nAreaID;                  ///<区域ID
    char chName[128];             ///<区域名称
    char chXGS[25];               ///<GS 纬度
    char chYGS[25];               ///<GS 经度
    char chContactor[64];         ///<联系人
    char chPhone[64];             ///<联系电话
}S_GSMAPInfo;

///<IMAGE文件设置(130-int)
typedef struct
{
    char chName[64];             ///<文件名
    char chPath[128];            ///<文件路径
    float fSize;                 ///<文件大小
}P_ImageFileInfo;

///<手机单事件状态修改(131-int)
typedef struct
{
    char chUserName[64];          ///<用户名
    int nID;                      ///<事件ID
}P_OnlyOneIncidentInfo;

///< 服务器复制(132-int)
typedef struct
{
    int nServerID;            ///< 服务器ID;
    int nServerType;          ///< 服务器类型：1-中心；2-报警；3-媒体
    char chServerID[1000];    ///< 复制的服务器ID串
    char chServerName[1000];  ///< 复制的服务器串
}P_CopyServerLoginInfo;

///< GS节点删除(133-int)
typedef struct
{
    int nID;            ///< 区域节点ID;
}P_GSDeleteInfo;

///<GS区域信息获取(134-out)
typedef struct
{
    int nAreaID;                  ///<区域ID
    char chName[128];             ///<区域名称
    char chXGS[25];               ///<GS 纬度
    char chYGS[25];               ///<GS 经度
    char chMemo[512];             ///<备注
}S_GSMAPShowInfo;

///<按品牌排序获取所有主机(135-out)
typedef struct
{
    char chManufature[64];       ///<品牌
    char chName[64];             ///<主机名
}S_DvrSortShowInfo;

///< 客户端报警处理提交(136-int)
typedef struct
{
    char chName[60];            ///<主机名称
    int  nChannelNo;            ///<通道号
    char chAlarmType[30];       ///<报警类型名称
    char chAlarmTime[30];       ///<报警时间
    char chMan[60];             ///<处理人
    int nConseque;              ///<处理方式
    char chOpinion[256];        ///<处理意见
    char chMemo[512];           ///<备注
}P_AlarmDealIntoInfo;

///< 获取所有下级中心编号(137-out)
typedef struct
{
    int  nCenterNo;             ///<编号
    char chName[64];            ///<名称
    char chIP[64];              ///<IP地址
}S_NextCenterNoInfo;

///< 客户端批量处理报警(138-int)
typedef struct
{
    char chAlarmID[30000];      ///<报警信息ID串：如1$2$3$4$，以$为分隔符，以$结束
    char chMan[60];             ///<处理人
    int nConseque;              ///<处理方式
    char chOpinion[256];        ///<处理意见
    char chMemo[512];           ///<备注
}P_AlarmProcessSetInfo;

///< 报警排行(139-int)
typedef struct
{
    int nTypeID;               ///<处理类型
    int nDays;                 ///<天数
}P_AlarmTopInfo;

///< 报警排行(139-out)
typedef struct
{
    char chName[64];          ///<名称
    int nCount;               ///<数量
}S_AlarmTopInfo;

///< 服务器获取设备基本信息(+品牌名称)(140-out)(CMS)
typedef struct
{
    char  chDvrName[40];  ///<设备名称
    char  chNumber[20];   ///<设备字符串编号
    char  chIp[20];       ///<设备IP
    char  chUserName[20]; ///<用户名
    char  chPassWord[20]; ///<密码
    long  lNumber;        ///<设备整型编号
    long  lCenterID;      ///<所属中心ID
    int   nPort;          ///<端口号
    int   nChannelNum;    ///<通道号
    int   nDevType;       ///<设备类型
    int   nType;          ///<厂家
    int   nSubType;       ///<型号
    int   nNeedLink;      ///<是否需要连接
    char  Area[20];       ///<所属网点
    char chDvrManufature[20];  ///<设备品牌名称
    char chReserved[64];       ///<预留
}S_DevBaseInfo,*LPS_DevBaseInfo;

///< 服务器获取设备基本信息(+品牌名称+联动)(141-out)(CMS)
typedef struct
{
    char  chDvrName[40];  ///<设备名称
    char  chNumber[20];   ///<设备字符串编号
    char  chIp[20];       ///<设备IP
    char  chUserName[20]; ///<用户名
    char  chPassWord[20]; ///<密码
    long  lNumber;        ///<设备整型编号
    long  lCenterID;      ///<所属中心ID
    int   nPort;          ///<端口号
    int   nChannelNum;    ///<通道数量  
    int   nDevType;       ///<设备类型
    int   nType;          ///<厂家
    int   nSubType;       ///<型号
    int   nNeedLink;      ///<是否需要连接
    char  Area[20];       ///<所属网点
    int linkNum;                  ///<联动数量
    T_CHANNEL_INFO ARRDevinfo[32];///<联动通道组
    char chDvrManufature[20];     ///<设备品牌名称
    char chReserved[64];          ///<预留
}S_DevBaseRelateInfo,*LPS_DevBaseRelateInfo;

///< MS服务器获取设备基本信息(+品牌名称)(142-out)(MS)
typedef struct
{
    S_DevBaseInfo TBaseInfoEx;    ///<基本信息
    char szVodPwd[20];            ///<工控需要 回放用户密码
    char szVodName[20];
    bool bLongLink;               ///<是否保持长连接
}S_MSBASEINFO,*LPS_MSBASEINFO;

///< AS服务器获取设备基本信息(+品牌名称)(143-out)(AS)
typedef struct
{
    S_DevBaseInfo TBaseInfoEx;      ///<基本信息
    int arraySensorInfo[256][2];    ///<探头相关信息。[*][0]-是否对讲触发（-1）、报警类型（>0）、未设（=0）；[*][1]-对讲通道(>0)
    int arrayManualSensorInfo[256]; ///<手动报警类型（>0）
}S_ASBASEINFO,*LPS_ASBASEINFO;

///< 报警预案操作(144-int)(add、mod、del)
typedef struct
{
    int nCondition;            ///< 条件：1-add;2-mod;3-del
    int nEPlanID;              ///< 预案ID
    char chName[64];           ///< 名称
    int nLevel;                ///< 报警等级
    char chMan[32];            ///< 人
    char chDateTime[32];       ///< 时间
    char chStepText[8000];     ///< 预案详细步骤，拼接字符串，以$为分隔符
}P_AlarmEPlan;

///< 报警预案关联操作(145-int)(add、del)
typedef struct
{
    int nCondition;            ///< 条件：1-add;2-del
    int nEPlanID;              ///< 预案ID
    int nAlarmID;              ///< 报警类型ID
}P_AlarmEPlanRelate;

///< 显示报警预案信息(146-out)
typedef struct
{
    int nEPlanID;              ///< 预案ID
    char chName[64];           ///< 名称
    int nLevel;                ///< 报警等级
    char chMan[32];            ///< 人
    char chDateTime[32];       ///< 时间
}S_ShowAlarmEPlan;

///< 显示报警预案详细信息(147-int)
typedef struct
{
    int nCondition;            ///< 条件：0-全部;1-特定ID
    int nEPlanID;              ///< 预案ID (nCondition=1时)
}P_ShowAlarmEPlanInfo;

///< 显示报警预案详细信息(147-out)
typedef struct
{
    int nEPlanID;              ///< 预案ID
    char chName[64];           ///< 名称
    int nLevel;                ///< 报警等级
    char chMan[32];            ///< 人
    char chDateTime[32];       ///< 时间
    char chStep[512];          ///< 预案步骤
}S_ShowAlarmEPlanInfo;

///< 显示报警预案关联信息(148-out)
typedef struct
{
    int nEPlanID;              ///< 预案ID
    char chEName[64];          ///< 预案名称
    int nAlarmID;              ///< 报警类型ID
    char chAlarmName[64];      ///< 报警类型名
}S_ShowAlarmEPlanRet;

///< 可视化电视墙操作(149-int)(add、mod、del)
typedef struct
{
    int nCondition;            ///< 条件：1-添加;2-修改;3-删除;4-设置电视墙名称
    int nTvID;
    char chName[64];
    int nPartNum;
    int nStartX;
    int nStartY;
    int nGridX;
    int nGridY;
    char chUser[64];
}P_NewTVScreenInfo;

///< 显示可视化电视墙信息(150-out)
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

///<网点报警数量统计(151-int)
/*  P_NewStaticsAreaAlarmNum.nCondition：
**  1: 所有网点单位时间内报警数量
**  2: 某网点内单位时间内单一报警数量
**  3: 某网点内20个单位时间长度报警数量
*/
typedef struct
{
    int nCondition;    ///< 条件
    char chName[64];   ///< 网点名称
    int nSubTime;      ///< 时间间隔
    int nUnit;         ///< n个单位时间间隔
}P_NewStaticsAreaAlarmNum;

///<网点报警数量统计(151-out)
typedef struct
{
    char chName[64];   ///< 网点名 / 报警类型名
    int nNum;          ///< 统计数量
    int nUnitMinute;   ///< 时间间隔数
}S_NewStaticsAreaAlarmNum;

///<显示报警等级信息(152-out)
typedef struct
{
    int nLevelValue;               ///< 序号
    char chLevelName[64];          ///< 名称
    char chLevelColor[512];        ///< 报警等级颜色  R#G#B
}S_NEW_SHOWALARMLEVEL;

///<显示报警等级策略信息(153-int)
typedef struct
{
    int nCondition;            ///< 0-全部，1-根据报警等级值，2-根据报警等级名
    int nAlarmValue;           ///< 报警等级值
    char chLevelName[64];      ///< 报警等级
}P_NEW_SHOWALARMLEVELPLOY;

///<显示报警等级策略信息(153-out)
typedef struct
{
    int nAlarmID;               ///< 报警等级唯一ID;
    int nAlarmValue;            ///< 报警等级值
    char chLevelName[64];       ///< 报警等级
    bool bRelated;              ///< 人工干预
    int nPlanID;                ///< 预案ID
    char chPlanName[64];        ///< 预案名
    bool bRecive;               ///< 接警超时标志
    int nReciveTime;            ///< 接警超时时间
    int nReciveType;            ///< 接警超时时间类型，0-秒，1-分
    char chReciveReport[1024];  ///< 接警上报人
    bool bFinish;               ///< 处置超时标志
    int nFinishTime;            ///< 处置超时时间
    int nFinishType;            ///< 处置超时时间类型，0-秒，1-分
    char chFinishReport[1024];  ///< 处置上报人
    int nPlanDeal;              ///< 预案处置(0-不处置,1-处置)
}S_NEW_SHOWALARMLEVELPLOY;

///<设置报警等级策略信息(154-int)
typedef struct
{
    int nAlarmValue;            ///< 报警等级值
    bool bRelated;              ///< 人工干预
    int nPlanID;                ///< 预案ID
    bool bRecive;               ///< 接警超时标志
    int nReciveTime;            ///< 接警超时时间
    int nReciveType;            ///< 接警超时时间类型，0-秒，1-分
    char chReciveReport[1024];  ///< 接警上报人
    bool bFinish;               ///< 处置超时标志
    int nFinishTime;            ///< 处置超时时间
    int nFinishType;            ///< 处置超时时间类型，0-秒，1-分
    char chFinishReport[1024];  ///< 处置上报人
    int nPlanDeal;              ///< 预案处置(0-不处置,1-处置)
}P_NEW_SETALARMLEVELPLOY;

///<获取部位信息(155-out)
typedef struct
{
    int nLevelValue;  ///< 序号
    char chName[64];  ///< 名称
}S_NEW_SHOWPOSITIONINFO;

///<获取场所信息(156-out)
typedef struct
{
	int nPlaceID;     ///<场所ID
    int nLevelValue;  ///< 序号
    char chName[64];  ///< 名称
}S_NEW_SHOWLOCATIONINFO;

///<动作库基本操作(157-int)(add、mod、del)
typedef struct
{
    int nCondition;    ///< 条件: 1-add,2-mod,3-del
    int nActionID;     ///< 动作ID;
    char chName[64];   ///< 动作名称
}P_NEW_OPACTIONLIB;

///<获取动作库(158-int)
typedef struct
{
    int nCondition;         ///<  0-全部，1-获取可用最小编号，2-获取固定动作类型
}P_NEW_SHOWACTIONLIB;

///<获取动作库(158-out)
typedef struct
{
    int nID;           ///< 唯一编号
    int nActionID;     ///< 动作编号
    char chName[64];   ///< 动作名称
	int nProperty;		///< 标识：0-众译执行；1-固定类型；2-考拉执行；（2016-07-14增加)
	char chProperty[128];  ///< 属性，目前填写电话号码(2016-07-14增加)，增加众译执行或考拉执行
}S_NEW_SHOWACTIONLIB;

///<事件库基本操作(159-int)(add、mod、del)
typedef struct
{
    int nCondition;         ///< 条件: 1-add,2-mod,3-del
    int nEventID;           ///< 事件ID
    char chName[64];        ///< 事件名称
    int nAlarmValue;        ///< 报警等级值
    char chActionID[1024];  ///< 动作ID串
    char chMustBeDos[1024]; ///< 动作是否可继续执行
}P_NEW_OPEVENTLIB;

///<获取事件库(160-int)
typedef struct
{
    int nCondition;         ///<  0-全部，1-根据事件ID，2-根据事件名, 3- 不带联动动作
    int nEventID;           ///< 事件ID
    char chEventName[64];   ///< 事件名称
}P_NEW_SHOWEVENTLIB;

///<获取事件库(160-out)
typedef struct
{
    int nEventID;           ///< 事件ID
    char chEventName[64];   ///< 事件名称
    int nAlarmValue;        ///< 报警等级值
    char chAlarmLevel[64];  ///< 报警等级名
    int nAI_Id;             ///< 动作唯一编号
    int nActionID;          ///< 动作编号
    char chActionName[64];  ///< 动作名称
    int nSequence;          ///< 联动动作序号
    bool bMustDo;           ///< 是否必须执行
	char chProperty[128];	///< 属性，目前存放电话号码
}S_NEW_SHOWEVENTLIB;

///<预案库基本操作(161-int)(add、mod、del)
typedef struct
{
    int nCondition;         ///< 条件: 1-add,2-mod,3-del
    int nPlanID;            ///< 预案ID
    char chName[64];        ///< 预案名称
    char chMan[64];         ///< 创建人
    char chActionID[1024];  ///< 动作ID串
    char chMustBeDos[1024]; ///< 动作是否可继续执行
}P_NEW_OPPLANLIB;

///<获取预案库(162-int)
typedef struct
{
    int nCondition;         ///<  0-全部，1-根据预案ID，2-根据预案名, 3- 不带联动动作
    int nPlanID;            ///< 预案ID
    char chPlanName[64];    ///< 预案名称
}P_NEW_SHOWPLANLIB;

///<获取预案库(162-out)
typedef struct
{
    int nPlanID;            ///< 预案ID
    char chPlanName[64];    ///< 预案名称
    char chMan[64];         ///< 创建人
    int nAI_Id;             ///< 动作唯一编号
    int nActionID;          ///< 动作编号
    char chActionName[64];  ///< 动作名称
    int nSequence;          ///< 联动动作序号
    bool bMustDo;           ///< 是否必须执行
	char chProperty[128];   ///< 属性，目前存电话号码(2016-05-11修改)
}S_NEW_SHOWPLANLIB;

///<获取常用处理语句信息(163-out)
typedef struct
{
    int nID;                ///< ID
    char chSuggestion[128]; ///< 意见
    int nType;              ///< 类型
    int nProperty;
    char chProperty[128];
}S_NEW_SHOWALWAYSDEAL;

///<获取处理方式信息(164-out)
typedef struct
{
    int nTypeID;          ///< 编号
    char chTypeName[64];  ///< 类型名 (实警、误报、无异常)
}S_NEW_SHOWDEALCONSEQUECE;

///<写入报警处理结果(165-int)
typedef struct
{
    int nAlarmID;                  ///< 报警信息ID
    char chAlarmSource[128];       ///< 报警源
    int nSourceType;               ///< 报警源类型 0-主机，1-摄像头
    char chAlarmType[128];         ///< 报警类型
    char chAlarmDateTime[32];      ///< 报警发生时间(yyyy-mm-dd hh:mm::ss)
    int nAlarmLevel;               ///< 报警级别
    char chKeyPart[128];           ///< 关键部位
    int nProcessType;              ///< 处理方式(1-实警，2-误报，3-无异常)
    char chMemo[512];              ///< 备注
    int nEPlanType;                ///< 预案类型(1-普通预案，2-事件)
    char chPlanName[128];          ///< 预案名
    char chHandleMan[128];         ///< 处理人
    char chAttachment[1024];       ///< 报警附件
    bool bDoFinish;                ///< 是否处理完成
    char chActionNos[1000];        ///< 预案步骤ID串
    char chActionNames[2048];      ///< 预案步骤名字串
    char chDoBeginTimes[2048];     ///< 预案步骤开始时间串
    char chDoEndTimes[2048];       ///< 预案步骤结束时间串
    char chAttachments[8000];      ///< 预案步骤附件串
    char chDoSuccesses[800];       ///< 预案步骤处理完成拼接字符串
    char chDoMans[2048];           ///< 预案步骤处理人串
    char chDoMemos[8000];          ///< 预案步骤处理描述串
}P_NEW_WRITEDEALRESULT;

///<根据某报警源获取历史处理信息(166-int)
typedef struct
{
    char chAlarmSource[128];       ///< 报警源
    char chAlarmType[128];         ///< 报警类型
    int nAnalysisType;		   ///< 统计类型: 1-出警后；其他-对应的类型ID
}P_NEW_SHOWHISTORYDEAL;

///<根据某报警源获取历史处理信息(166-out)
typedef struct
{
    int nLine;                     ///< 线图序号
    double nPoint[7];              ///< 线图描绘点
    char chMemo[256];              ///< 描述(2,3,4)
}S_NEW_SHOWHISTORYDEAL;

///<报警处理信息的综合统计(167-int)
typedef struct
{
    int nCondition;                ///< 条件(时间(1-小时、2-日、3-月)，4-地点，5-报警类型，6-报警等级，7-处理状态，8-处理人，9-处理方式)
    int nCategoryType;             ///< 4-按报警地点统计 5-按报警类型统计 6-按报警等级统计 7-按处理状态统计 8-按处理人统计 9-按处警类型统计
    bool bDatePoint;               ///< 按日特殊处理标记
    int nDateStart;                ///< 按日开始点 (0~23)
    int nDateEnd;                  ///< 按日结束点 (0~23)
    bool bMonthPoint;              ///< 按月特殊处理标记
    int nMonth;                    ///< 按月特殊值 0-全部，1-工作日，2-周末
    char chBeginTime[32];          ///< 开始时间
    char chEndTime[32];            ///< 结束时间
    char chAreaNames[2048];        ///< 地点编号串
    char chAlarmTypes[1024];       ///< 报警类型串
    char chAlarmlevels[32];        ///< 报警等级串
    char chHandleMans[1024];       ///< 处理人串
    char chProcessTypes[32];       ///< 处理方式串，1-实警,2-误报,3-无异常
    char chProcessStates[32];      ///< 处理状态串，0-未处理，1-处理中，2-已处理
}P_NEW_COMPLEXSTATICS;

///<报警处理信息的综合统计(167-out)
typedef struct
{
    char chDateTime[32];           ///< 时间
    char chContent[128];           ///< 内容（地点、报警类型、报警等级、处理人、处理方式、处理状态）
    int nCount;                    ///< 数目
}S_NEW_COMPLEXSTATICS;

///<报警处理信息的综合查询(168-int)
typedef struct
{
    int nPage;                     ///< 页数
    int nCount_Page;               ///< 每页显示记录条数
    char chBeginTime[32];          ///< 开始时间
    char chEndTime[32];            ///< 结束时间
    char chAreaNames[2048];        ///< 地点编号串
    char chAlarmTypes[1024];       ///< 报警类型串
    char chAlarmlevels[32];        ///< 报警等级串
    char chHandleMan[32];          ///< 处理人
    int nProcessType;              ///< 处理方式，1-实警,2-误报,3-无异常
    int nProcessStates;            ///< 处理状态，1-未处理，2-处理中，3-已处理
}P_NEW_COMPLEXCHECK;

typedef struct
{
    int nUnHandleCount;            ///< 未处理条数
}S_NEW_COMPLEXCHECKUNHANDLE;

///<报警处理信息的综合查询(168-out)
typedef struct
{
    char chAlarmTypeName[64];      ///< 报警类型名称
    char chAlarmSource[64];        ///< 报警源
    int nAlarmSourceType;          ///< 报警源类型：0-主机，1-摄像头
    char chAlarmArea[64];          ///< 报警地点
    int nSumCount;                 ///< 总记录条数
    int nSumPage;                  ///< 总页数
    char chBeginTime[32];          ///< 报警日志开始时间（2012-01-01 00:00:00）
    char chBeginDay[32];           ///< 报警日志开始日期（2012-01-01）
    char chBeginMonth[32];         ///< 报警日志开始月份（2012-01）
    int nAlarmTypeID;              ///< 报警信息ID
    int nProcessState;             ///< 处理状态：0-未处理，1-处理中，2-已处理
    char chProcessUser_VarC[64];   ///< 处理人
    char chProcessDate_Date[32];   ///< 处理日期
    int nProcessMethod_Int;        ///< 处理方式：1-实警,2-误报,3-无异常
    char chProcessMemo_VarC[512];  ///< 备注
    int nAlarmLevel;               ///< 报警等级
    char chPalnName[64];           ///< 对应预案
    char chProcessBeginTime[32];   ///< 处理开始时间
    char chProcessEndTime[32];     ///< 处理结束时间
}S_NEW_COMPLEXCHECK;

///<报警处理信息的综合排行(169-int)
/*  条件：4- nAreaID 不传
*         7- nAlarmSourceType 必传
*其它条件：- nAreaID 必传
*/
typedef struct
{
    int nCondition;                ///< 条件(时间(1-小时、2-日、3-月)，4-地点，5-报警类型，6-处理人，7-报警源
    char chDimensions[3072];       ///< 维度串
    char chBeginTime[32];          ///< 开始时间
    char chEndTime[32];            ///< 结束时间
    char chAlarmSource[64];        ///< 报警源
    int nAlarmSourceType;          ///< 报警源类型：0-主机，1-摄像头
    int nAreaID;                   ///< 地点
    char chAlarmType[64];          ///< 报警类型
    char chHandleMan[64];          ///< 处理人
    int nAlarmlevel;               ///< 报警等级
    int nProcessType;              ///< 处理方式，1-实警,2-误报,3-无异常
    int nProcessState;             ///< 处理状态，0-未处理，1-处理中，2-已处理
}P_NEW_COMPLEXTOP;

///<报警处理信息的综合排行(169-out)
typedef struct
{
    char chContent[128];           ///< 内容（时间、地点、报警类型、报警源、处理人）
    int nCount;                    ///< 数目
}S_NEW_COMPLEXTOP;

///<根据报警信息ID获取对应预案信息(170-int)
typedef struct
{
    int nAlramID;                  ///< 报警信息ID
}P_NEW_SHOWPLANINFOBYALARM;

///<根据报警信息ID获取对应预案信息(170-out)
typedef struct
{
    int nActionID;                 ///< 动作编号
    char chActionName[64];         ///< 动作名称
    int nSequence;                 ///< 联动动作序号
    bool bDeal;                    ///< 是否已执行
    char chAttach[128];            ///< 预案附件
    char chBegin[32];              ///< 开始时间
    char chEnd[32];                ///< 结束时间
    char chMan[64];                ///< 处理人
    char chMemo[1024];             ///< 处理描述
}S_PLANSTEP;

typedef struct
{
    char chPlanName[64];           ///< 预案名称
    int nPlanType;                 ///< 预案类型 1-普通预案，2-事件
    char chAttachment[128];        ///< 预案附件
    int nStepNums;                 ///< 预案步骤数目
    S_PLANSTEP T_StepInfo[100];    ///< 预案步骤详细信息
}S_NEW_SHOWPLANINFOBYALARM;

///<根据报警部分信息获取报警详细信息(171-int)
typedef struct
{
    int nCondition;                ///< 1-根据报警信息ID ；2-根据报警源、时间、类型；3-根据GUID获取；
    int nAlarmID;                  ///< 报警信息ID
    char chAlarmSource[128];        ///< 报警源，condition=3时传入GUID
    char chAlarmDateTime[32];      ///< 报警发生时间
    char chAlarmType[32];          ///< 报警类型
}P_NEW_SHOWALARMINFOBYALARM;

///<根据报警部分信息获取报警详细信息(171-out)
typedef struct
{
    int nAlarmID;                  ///< 报警信息ID
    char chAreaName[64];           ///< 地点
    char chAlarmSource[64];        ///< 报警源
    int nAlarmSourceType;          ///< 报警源类型：0-主机，1-摄像头
    char chAlarmType[32];          ///< 报警类型
    char chAlarmDateTime[32];      ///< 报警发生时间
    int nAlarmLevel;               ///< 报警等级
    bool bProcessState;            ///< 是否处理完成
    char chProcessUser_VarC[64];   ///< 处理人
    char chProcessDate_Date[32];   ///< 处理日期
    int nProcessMethod_Int;        ///< 处理方式：1-实警,2-误报,3-无异常
    char chProcessMemo_VarC[512];  ///< 备注
    char chPlanName[64];           ///< 对应预案
    int nPlanType;                 ///< 预案类型 1-普通预案，2-事件
    char chAttachment[128];        ///< 预案附件
    int nStepNums;                 ///< 预案步骤数目
    S_PLANSTEP T_StepInfo[100];    ///< 预案步骤详细信息
    char chNo[20];                 ///< 流水号
    char chAlarmStatusType[128];         ///< 警情类型
    char chCheckStatus[128];       ///< 定性戳
    char chIsQualified[64];        ///< 复核结果
    char chCheckMan[64];           ///< 复核人
    char chCheckDate[20];          ///< 复核时间
	int nProperty;				   ///< 锁状态：0-解锁；1-锁定；
	char chGUID[128];			   ///< 报警GUID
	char chKeyPart[64];			   ///< 部位
    int nProcessStatus;			   ///< 处置状态

}S_NEW_SHOWALARMINFOBYALARM;

///<用户图表基本操作(172-int)(add、mod、del)
typedef struct
{
    int nCondition;                ///< 条件: 1-add,2-mod,3-del
    int nGraphID;                  ///< 图表编号
    char chUserName[64];           ///< 用户名
    char chGraphName[128];         ///< 图表名
    char chCondition_VarC[2048];   ///< 图表条件
    int  nProperty;                ///<图表类型
}P_NEW_OPUSERGRAPHINFO;

///<用户报告基本操作(173-int)(add、mod、del)
typedef struct
{
    int nCondition;                ///< 条件: 1-add,2-mod,3-del
    int nReportID;                 ///< 报告编号
    char chUserName[64];           ///< 用户名
    int nReportType;               ///< 报告类型(1-日报、2-周报、3-月报、4-季报、5-半年报、6-年报)
    char chReportName[128];        ///< 报告名
    char chCondition_VarC[2048];   ///< 选择的图表串
    int nPutDate_Int;              ///< 推送时间
    bool bEnable;                  ///< 是否启用
    int  nProperty;                ///<图表类型
}P_NEW_OPUSERREPORTINFO;

///<修改用户报告状态(174-int)(mod)
typedef struct
{
    int nReportID;                 ///< 报告编号
}P_NEW_MODSTATUSUSERREPORT;

///<获取用户图表信息(175-int)
typedef struct
{
    char chUserName[64];           ///< 用户名
    int nProperty;                 ///< 图表类型 0-全部
}P_NEW_SHOWUSERGRAPHINFO;

///<获取用户图表信息(175-out)
typedef struct
{
    int nGraphID;                  ///< 图表编号
    char chGraphName[128];         ///< 图表名
    char chCondition_VarC[2048];   ///< 图表条件
    int nProperty;                 ///< 图表类型
}S_NEW_SHOWUSERGRAPHINFO;

///<获取用户报告信息(176-int)
typedef struct
{
    char chUserName[64];           ///< 用户名
    int nReportType;               ///< 报告类型(1-日报、2-周报、3-月报、4-季报、5-半年报、6-年报)(0-全部)
    char chReportDate[32];         ///< 报告日期
    int nStatus;                   ///< 是否已读(0-未读，1-已读)(2-全部)
    int nProperty;                 ///< 图表类型(0-全部)
}P_NEW_SHOWUSERREPORTINFO;

///<获取用户报告信息(176-out)
typedef struct
{
    int nReportID;                 ///< 报告编号
    int nReportType;               ///< 报告类型(1-日报、2-周报、3-月报、4-季报、5-半年报、6-年报)
    char chReportName[128];        ///< 报告名
    char chCondition_VarC[2048];   ///< 选择的图表串
    char chReportDate[32];         ///< 报告日期
    int nStatus;                   ///< 是否已读(0-未读，1-已读)
    int nProperty;                 ///< 图表类型(0-全部)
}S_NEW_SHOWUSERREPORTINFO;

///<报警回溯详细信息(177-int)
typedef struct
{
    int nAlarmID;                  ///< 报警处置ID
    char chAreaName[64];           ///< 报警发生场所名称
    char chDeviceName[64];         ///< 报警设备名称
    char chChannelName[64];        ///< 报警通道名称（如果为通道报警类型传入，否则可以为空）
    char chBeginTime[32];          ///< 检索开始时间
    char chEndTime[32];            ///< 检索结束时间
    char chUserName[64];           ///< 用户名
}P_NEW_SHOWALARMBACKINFO;

///<报警回溯详细信息(177-out)
typedef struct
{
    int nID;                      ///< ID
    char chUserName[64];          ///< 用户名
    char chAreaName[64];          ///< 区域名
    char chDeviceName[64];        ///< 设备名
    char chChannelName[64];       ///< 通道名
    int nActType;                 ///< 操作类型
    int nSequece;                 ///< 序号
    char chActionName[64];        ///< 动作名
    char chBeginTime[32];         ///< 开始时间
    char chEndTime[32];           ///< 结束时间
    char chAttachment[128];       ///< 附件名
    int nDoSuccess;               ///< 处理状态，0-未处理，1-处理中，2-已处理
    char chMemo[1024];            ///< 处理描述
}S_NEW_SHOWALARMBACKINFO;

///<获取用户报告订阅信息数据(178-int)
typedef struct
{
    char chUserName[64];         ///< 用户名
    int nProperty;                 ///< 图表类型(0-全部)
}P_NEW_SHOWUSERREPORTBOOKINFO;

///<获取用户报告订阅信息数据(178-out)
typedef struct
{
    int nReportID;                 ///< 报告编号
    int nReportType;               ///< 报告类型(1-日报、2-周报、3-月报、4-季报、5-半年报、6-年报)
    char chReportName[128];        ///< 报告名
    char chCondition_VarC[2048];   ///< 选择的图表串
    char chReportDate[32];         ///< 订阅日期
    int nPutDate_Int;              ///< 推送时间
    bool bEnable;                  ///< 是否启用
    int nProperty;                 ///< 图表类型(0-全部)
}S_NEW_SHOWUSERREPORTBOOKINFO;

///<场所基本操作(179-int)(add、mod、del)
typedef struct
{
    int nCondition;                ///< 条件: 1-add,2-mod,3-del
    int nPlaceType;                ///< 场所类型值
    char chPlaceName[64];          ///< 场所名
}P_NEW_OPAREAPLACEINFO;

///<部位基本操作(180-int)(add、mod、del)
typedef struct
{
    int nCondition;                ///< 条件: 1-add,2-mod,3-del
    int nKeyPartValue;             ///< 部位类型值
    char chKeyPartName[64];        ///< 部位名
}P_NEW_OPKEYPARTINFO;

///<报警等级基本操作(181-int)(add、mod、del)
typedef struct
{
    int nCondition;                ///< 条件: 1-add,2-mod,3-del
    int nLevelValue;               ///< 报警级别值
    char chLevelName[64];          ///< 报警级别名
    char chLevelColor[512];        ///< 报警等级颜色
}P_NEW_OPALARMLEVELINFO;

///<时间模板基本操作(182-int)(add、mod、del)
typedef struct
{
    int nCondition;                ///< 条件: 1-add,2-mod,3-del
    int nID;                       ///< 模板ID
    char chName[128];              ///< 模板名称
    char chDescrip[1024];          ///< 描述
    char chMon[512];               ///< 星期一
    char chTue[512];               ///< 星期二
    char chWed[512];               ///< 星期三
    char chThu[512];               ///< 星期四
    char chFri[512];               ///< 星期五
    char chSat[512];               ///< 星期六
    char chSun[512];               ///< 星期日
}P_NEW_OPTIMEMODEL;

///<时间模板信息获取(183-int)
typedef struct
{
    int nCondition;                ///< 条件: 0-全部,1-根据ID,2-取全部模板(不带时间段)
    int nID;                       ///< 模板ID
}P_NEW_SHOWTIMEMODEL;

///<时间模板信息获取(183-out)

typedef struct
{
    char chStart[10];              ///< 开始时间
    char chEnd[10];                ///< 结束时间
}S_TIMECONSEQUECE;

typedef struct
{
    int nCount;                    ///< 时间段数量
    S_TIMECONSEQUECE S_Info[10];   ///< 时间段
}S_TIMEWEEKDAY;

typedef struct
{
    int nID;                       ///< 模板ID
    char chName[128];              ///< 模板名称
    char chDescrip[1024];          ///< 描述
    int nModelType;                ///< 模板类型0-日常模板，1-节假日模板
    char chStartDate[12];          ///< 开始日期(节假日模板)
    char chEndDate[12];            ///< 结束日期(节假日模板)
    S_TIMEWEEKDAY S_Day[7];        ///< 星期一~星期天 (节假日模板采用 0)
}S_NEW_SHOWTIMEMODEL;

///<报警等级划分批量设置(184-int)(add、del)
typedef struct
{
    int nCondition;                ///< 条件: 1-add,2-mod,3-del,4-清空
    char chLcIDs[80000];            ///< ID串(删除时传入)
    char chPlaces[80000];           ///< 场所ID串
    char chKeyParts[80000];         ///< 部位ID串
    char chTypes[80000];            ///< 报警类型ID串
    int nModelID;                  ///< 模板ID
    int nLevelID;                  ///< 报警等级ID
}P_NEW_SETMULALARMLEVEL;

///<报警等级划分批量设置信息获取(185-int)
typedef struct
{
    int nCondition;                ///< 条件: 0-全部,1-根据等级,2-根据场所、部位、类型、时间模板ID
    int nLevelID;                  ///< 报警等级值
    char chPlace[64];              ///< 场所名称
    char chKeyPart[64];            ///< 关键部位名称
    char chAlarmType[64];          ///< 报警类型名称
    int nModelID;                  ///< 时间模板ID
}P_NEW_SHOWMULALARMLEVEL;

///<报警等级划分批量设置信息获取(185-out)
typedef struct
{
    int nAlarmLevelId_Int;        ///< 报警级别ID
    int nAlarmLevel_Int;          ///< 报警级别值
    char chAlarmLevelName[32];    ///< 报警级别名
    int nPlaceId_Int;             ///< 场所ID
    int nPlaceType_Int;           ///< 场所类型值
    char chPlaceName[64];         ///< 场所名称
    int nKeyPartId_Int;           ///< 部位ID
    int nKeyPart_Int;             ///< 部位值
    char chKeyPartName[64];       ///< 部位名称
    int nAlarmTypeId_Int;         ///< 报警类型ID
    char chAlarmTypeName[64];     ///< 报警类型名
    int nTimeModuleId_Int;        ///< 时间模板ID
    char chModuleName_VarC[128];  ///< 时间模板名称
    int nLC_ID;                   ///< 记录编号
}S_NEW_SHOWMULALARMLEVEL;

///<报警等级划分特殊设置(186-int)(add、del)
typedef struct
{
    int nCondition;                ///< 条件: 1-add,2-mod,3-del
    int nDevID;                    ///< 设备ID
    int nDevType;                  ///< 设备类型1-主机，2-前端设备(摄像头、探头)
    int nAlarmTypeID;              ///< 报警类型ID;
    int nModelID;                  ///< 模板ID
    int nLevelID;                  ///< 报警等级ID
}P_NEW_SETSINALARMLEVEL;

///<报警等级划分特殊设置信息获取(187-int)
typedef struct
{
    int nCondition;                ///< 条件: 0-全部，1-根据设备ID+设备类型
    int nDevID;                    ///< 设备ID
    int nDevType;                  ///< 设备类型1-主机，2-前端设备(摄像头、探头)
}P_NEW_SHOWSINALARMLEVEL;

///<报警等级划分特殊设置信息获取(187-out)
typedef struct
{
    int nDevID;                    ///< 设备ID
    int nDevType;                  ///< 设备类型1-主机，2-前端设备(摄像头、探头)
    int nAlarmTypeId_Int;          ///< 报警类型ID
    char chAlarmTypeName[64];      ///< 报警类型名
    int nTimeModuleId_Int;         ///< 时间模板ID
    char chModuleName_VarC[128];   ///< 时间模板名称
    int nAlarmLevelId_Int;         ///< 报警级别ID
    int nAlarmLevel_Int;           ///< 报警级别值
    char chAlarmLevelName[32];     ///< 报警级别名
    int nLC_ID;                    ///< 记录编号
    char chDevName[128];           ///< 名称[nCondition=2时有效]
    int nTerminalID;               ///< 主机ID
    int nChannelNo;                ///< 通道号
}S_NEW_SHOWSINALARMLEVEL;

///< 报警服务器获取设备详细信息+场所、部位(188-out)
typedef struct
{
    S_DevBaseInfo TBaseInfoEx;      ///<基本信息
    int nPlaceType;                 ///<场所ID
    int nKeyPart;                   ///<部位ID
    int nBaseLevel;                 ///<默认等级
    int ArrayFrontend[128][5];      ///<探头结构数组:   0-场所,1-部位,2-默认等级,3-(-1,联动，>0 报警类型),4- 联动通道号
    int ArrayCamera[128][3];        ///<摄像头结构数组: 0-场所,1-部位,2-默认等级
}S_DevBaseInfo_AS,*LPS_DevBaseInfo_AS;

///< 场所、部位、报警类型、时间模板(名称+ID)(189-int)
typedef struct
{
    int nCondition;                ///< 条件: 0-场所，1-部位，2-报警类型，3-时间模板
}P_NEW_PLACEKEYPARTMODEL;

///< 场所、部位、报警类型、时间模板(名称+ID)(189-out)
typedef struct
{
    int nID;                       ///< ID
    char chName[128];              ///< 名称
}S_NEW_PLACEKEYPARTMODEL;

///< 根据名称获取报警等级信息(190-int)
typedef struct
{
    int nDevType;                  ///< 设备类型1-主机，2-前端设备(摄像头、探头)
    char chName[128];              ///< 名称
}P_NEW_PLACEKEYPARTBYNAME;

///< 根据名称获取报警等级信息(190-out)
typedef struct
{
    char chName[128];              ///< 名称
    char chAlarmTypeName[64];      ///< 报警类型名
    char chModuleName_VarC[128];   ///< 时间模板名称
    char chAlarmLevelName[32];     ///< 报警级别名
}S_NEW_PLACEKEYPARTBYNAME;

///< 根据名称获取关联报警类型(191-int)
typedef struct
{
    int nCondition;                ///< 默认0,1-所有探头类型
    int nDevType;                  ///< 设备类型1-主机，2-前端设备(摄像头、探头)
    char chName[128];              ///< 名称
}P_NEW_SHOWALARMBYDEVNAME;

///< 根据名称获取关联报警类型(191-out)
typedef struct
{
    char chName[128];              ///< 名称
    int nAlarmTypeID;              ///< 报警类型ID
    char chAlarmTypeName[64];      ///< 报警类型名
}S_NEW_SHOWALARMBYDEVNAME;

///< 批量设置场所、部位
typedef struct
{
    int nCondition;                ///< 1-设置场所，2-设置部位
    int nTypeValue;                ///< 场所or部位类型值
    char chIDs[1000000];           ///< ID串or编号串
}P_NEW_SET_PLACEKEYPART;

///< 获取场所批量设置信息
typedef struct
{
    int nCondition;                ///< 0-全部，1-获取已设置，2-获取未设置，3-根据网点编号，4-根据已设置场所类型值串
    char chCode[64];               ///< 网点编号
    char chTypeValues[128];        ///< 场所类型值串
}P_NEW_SHOW_AREAPLACESET;

///< 获取场所批量设置信息
typedef struct
{
    unsigned int nAreaID;         ///< 网点ID
    char chCode[64];              ///< 网点编号
    char chAreaName[128];         ///< 网点名称
    char chUpperAreaName[128];    ///< 上级网点
    char chUpperCode[64];         ///< 上级网点编号
    int nNodeType;                ///< 节点类型值
    int nAreaType;                ///< 场所类型值
    char chAreaTypeName[128];     ///< 场所名称
}S_NEW_SHOW_AREAPLACESET;

///< 获取部位批量设置信息
typedef struct
{
    int nCondition;                ///< 0-全部，1-获取已设置，2-获取未设置，3-根据设备编号，4-根据已设置场所类型值串、部位类型值串
    char chCode[64];               ///< 设备编号
    char chTypeValues[128];        ///< 场所类型值串
    char chKeyPartValues[128];     ///< 部位类型值串
}P_NEW_SHOW_KEYPARTSET;

///< 获取部位批量设置信息
typedef struct
{
    char chName[128];             ///< 设备名称
    char chCode[64];              ///< 设备编号
    char chUpperAreaName[128];    ///< 上级网点
    char chUpperCode[64];         ///< 上级网点编号
    int nNodeType;                ///< 节点类型值
    int nAreaType;                ///< 场所类型值
    char chAreaTypeName[128];     ///< 场所名称
    int nKeyPart;                 ///< 部位类型值
    char chKeyPart[128];          ///< 部位名称
}S_NEW_SHOW_KEYPARTSET;

///< 获取今日排班信息(196-out)
typedef struct
{
    int  nScheduleID;                   ///< 排班编号
    int  nClassID;                      ///< 班次编号
    char chClassName[32];               ///< 班次名称
    char chUserName[64];                ///< 值班员姓名
    char chRole[64];                    ///< 值班员角色
    char chBeginTime[32];               ///< 班次起始时间
    char chEndTime[32];                 ///< 班次结束时间
    char chDate[32];                    ///< 班次日期
}S_NEW_SHOWTODAYCLASSESINFO;

///< 获取当前交班用户信息(197、199、200-in)
typedef struct
{
    int nCondition;                     ///< 条件[200: 1-值班长交接班,2-值班长查询历史]
    int  nScheduleID;                   ///< 排班ID（班次、人名、角色三个维度的ID）
}P_NEW_SHOW_HA_CURUSER;

///< 获取当前交班用户信息(197-out)
typedef struct
{
    char strRole[64];              ///< 用户角色
    char chPassWord[64];           ///< 用户密码
    char chHeirTime[32];           ///< 接班时间
    char chImage[512];             ///< 用户头像
    unsigned short nAlarmCount;    ///< 处理报警数
    bool bMonitor;                 ///< 是否拥有交接班审查权限
    bool bDoShift;                 ///< 是否已交班
}S_NEW_SHOW_HA_CURUSER;

///< 获取待接班人员信息(198-in)
typedef struct
{
    char chRole[64];              ///< 角色名称
    char chDate[32];              ///< 下一个班次日期
    int  nClassID;                ///< 下一个班次编号
}P_NEW_SHOW_HA_WAITUSERLIST;

///< 获取待接班人员信息(198-out)
typedef struct
{
    int  nScheduleID;             ///< 排班ID
    char chUserName[64];          ///< 值班员姓名
    char chRole[64];              ///< 角色名称
    char chPassWord[64];          ///< 用户密码
    char chImage[512];            ///< 用户头像
}S_NEW_SHOW_HA_WAITUSERLIST;

///< 获取值班员任务执行情况(199-out)
typedef struct
{
    char chTaskName[64];          ///< 任务名称
    int nTaskType;                ///< 任务类型[1-日常任务，2-突发任务]
    int nTaskCount;               ///< 任务需执行次数
    int nDoCount;                 ///< 任务完成次数
}S_NEW_SHOW_HA_A_TASKINFO;

///< 获取值班长任务执行情况(200-out)
typedef struct
{
    int  nScheduleID;              ///< 下属排班ID
    char chUserName[64];           ///< 下属姓名
    char chRole[64];               ///< 下属角色
    float fPTask;                  ///< 任务完成率
    bool bHandover;                ///< 是否已交班
    char chMemo[600];              ///< 备注
    char chLeaderMemo[600];        ///< 值班长备注[nCondition =2]
}S_NEW_SHOW_HA_M_TASKINFO;

///< 获取班次内未处理报警信息(201-in)
typedef struct
{
    char chBeginTime[32];           ///< 开始时间
    char chEndTime[32];             ///< 结束时间
}P_NEW_SHOW_HA_ALARMINFO;

///< 获取班次内未处理报警信息(201-out)
typedef struct
{
    char chAlarmSource[64];        ///< 报警源
    char chAlarmType[32];          ///< 报警类型
    char chAlarmDateTime[32];      ///< 报警发生时间
    int nAlarmLevel;               ///< 报警等级
}S_NEW_SHOW_HA_ALARMINFO;

///< 提交交班信息（202-in） 【交班时间和日期由数据库记录】
typedef struct
{
    int nUserSchID;                ///< 交班人排班ID
    int nHeirSchID;                ///< 接班人排班ID
    float fPTask;                  ///< 任务完成率
    int  nDelAlarmCount;           ///< 报警处理条数
    char chMemo[600];              ///< 备注
    char chIDList[300];            ///< 下属排班ID串 例如[1$2$3$]
}P_NEW_ADD_HA_INFO;

///< 获取交接班历史信息（203-in）
typedef struct
{
    int  nCondition;                ///< 条件：1-以排班ID获取 2-以条件筛选
    int  nScheduleID;              ///< 排班ID
    char chUserName[64];           ///< 交班人姓名
    char chRole[64];               ///< 交班人角色
    char chHeirBeginTime[32];      ///< 接班起始时间  以下4个仅到年月日，不包含时分秒  尽可能默认1周
    char chHeirEndTime[32];        ///< 接班结束时间
    char chHandoverBeginTime[32];  ///< 交班起始时间
    char chHandoverEndTime[32];    ///< 交班结束时间
    float fPBeginTask;             ///< 任务完成率上限
    float fPENdTask;               ///< 任务完成率下限
    int nAlarmCountBegin;          ///< 报警处理条数上限
    int nAlarmCountEnd;            ///< 报警处理条数下限
}P_NEW_SHOW_HA_INFO;

///< 获取交接班历史信息（203-out）
typedef struct
{
    int  nScheduleID;              ///< 排班ID
    char chUserName[64];           ///< 交班人姓名
    char chHeirName[64];           ///< 接班人姓名
    char chRole[64];               ///< 交班人角色
    char chHeirRole[64];           ///< 接班人角色
    char chImage[512];             ///< 交班人头像
    char chHeirImage[512];         ///< 接班人头像
    char chHeirTime[32];           ///< 接班时间
    char chHandoverTime[32];       ///< 交班时间
    float fPTask;                  ///< 任务完成率
    int nDelAlarmCount;            ///< 报警处理条数
    char chMemo[600];              ///< 备注  
    bool bMonitor;                 ///< 是否是值班长 	
}S_NEW_SHOW_HA_INFO;

///< 触发数据库分发任务(204-in)
typedef struct
{
    int nScheduleID;               ///< 班次唯一ID
}P_NEW_TASKDISTREBUTE_SET;

///< 主动巡查角色扩展操作(205-in)
typedef struct
{
    int nCondition;                ///< 条件：1-add,2-mod,3-del,
    int nRoleID;                   ///< 角色ID
    char chRole[64];               ///< 角色名称
    int nUppRoleID;                ///< 上级角色ID
    char chMemo[512];              ///< 角色备注
    bool bParticipate;             ///< 是否参与排班
    char chModuleAuthoritys[1024]; ///< 模块权限串[01串]
}P_NEW_INSPECT_ROLESET;

///< 主动巡查角色扩展信息获取(206-in)
typedef struct
{
    int nCondition;                ///< 条件：1-所有角色,2-根据角色ID,3-根据角色名称
    int nRoleID;                   ///< 角色ID
    char chRole[64];               ///< 角色名称
}P_NEW_INSPECT_ROLESHOW;

///< 主动巡查角色扩展信息获取(206-out)
typedef struct
{
    int nRoleID;                   ///< 角色ID
    char chRole[64];               ///< 角色名称
    int nUppRoleID;                ///< 上级角色ID
    char chUppRole[64];            ///< 上级角色名称
    char chMemo[512];              ///< 角色备注
    bool bParticipate;             ///< 是否参与排班
    bool bModuleAuthoritys[16];    ///< 模块权限[0-排班,1-任务安排,2-任务复核,3-值班长交接班]
                                   ///<[4-参与排班权限,5-值班长交接班权限,6-任务复核权限,7-任务分配权限 8-警情等级修改权限 9 - 定性权限]
}S_NEW_INSPECT_ROLESHOW;

///< 主动巡查异常库操作(207-in)
typedef struct
{
    int nCondition;                ///< 条件：[异常类型：1-add,2-mod,3-del；异常项：4-add,5-mod,6-del]
    int nTypeID;                   ///< 唯一ID
    char chType[128];              ///< 名称
    int nUppTypeID;                ///< 所属类型ID
}P_NEW_INSPECT_ABORTLIBSET;

///< 主动巡查异常库信息获取(208-in)
typedef struct
{
    int nCondition;               ///< 条件：1-所有异常类型,2-所有异常项
}P_NEW_INSPECT_ABORTLIBSHOW;

///< 主动巡查异常库信息获取(208-out)
typedef struct
{
    int nTypeID;                   ///< 唯一ID
    char chType[128];              ///< 名称
    int nUppTypeID;                ///< 所属类型ID[nCondition=2]
}S_NEW_INSPECT_ABORTLIBSHOW;

///< 主动巡查日期组操作(209-int)
typedef struct
{
    int nCondition;                ///< 条件：1-add,2-mod,3-del
    int nDateID;                   ///< 日期组唯一ID
    char chName[64];               ///< 日期组名称
    bool bWeek[7];                 ///< 星期几是否上班[星期一-0 ~ 星期天-6]
    char chModDates[128];          ///< 修改日期串，如1$2$(2-mod)
}P_NEW_INSPECT_DATEGROUPSET;

///< 主动巡查日期组信息获取(210-out)
typedef struct
{
    int nDateID;                   ///< 日期组唯一ID
    char chName[64];               ///< 日期组名称
    bool bWeek[7];                 ///< 星期几是否上班[星期一-0 ~ 星期天-6]
}S_NEW_INSPECT_DATEGROUPSHOW;

///< 主动巡查班次信息操作(211-int)
typedef struct
{
    int nCondition;                ///< 条件：1-add,2-mod,3-del
    int nClassID;                  ///< 班次唯一ID
    char chName[64];               ///< 班次名称
    int nDateID;                   ///< 日期组唯一ID
    char chStartTime[32];          ///< 班次开始时间
    char chEndTime[32];            ///< 班次结束时间
    bool bCrossDate;               ///< 是否跨天
    char chRoleIds[1024];          ///< 相关角色ID串(如：1$2$)
}P_NEW_INSPECT_CLASSINFOSET;

///< 主动巡查班次信息获取(212-out)
typedef struct
{
    int nClassID;                  ///< 班次唯一ID
    char chName[64];               ///< 班次名称
    int nDateID;                   ///< 日期组唯一ID
    char chStartTime[32];          ///< 班次开始时间
    char chEndTime[32];            ///< 班次结束时间
    bool bCrossDate;               ///< 是否跨天
    char chRoleIds[1024];          ///< 相关角色ID串(如：1$2$)
}S_NEW_INSPECT_CLASSINFOSHOW;

///< 主动巡查排班信息操作(213-int)
typedef struct
{
    int nCondition;                ///< 条件：1-add,2-mod,3-del,4-set
    int nScheduleID;               ///< 排班ID
    char chName[64];               ///< 班次名称
    char chDateTime[32];           ///< 排班日期
    char chUserName[1024];         ///< 用户名 [nCondition =4时，形式：1$2$]
    char chRoleName[64];           ///< 角色名
    char chChangeMan[64];          ///< 修改人用户名
    char chChangeMemo[512];        ///< 修改备注
}P_NEW_INSPECT_SCHEDULEINFOSET;

///< 主动巡查排班信息获取(214-int)
typedef struct
{
    int nCondition;                ///< 条件：0-全部，1-根据日期获取区间内的相关信息
    char chStartDate[32];          ///< 开始日期
    char chEndDate[32];            ///< 结束日期
}P_NEW_INSPECT_SCHEDULEINFOSHOW;

///< 主动巡查排班信息获取(214-out)
typedef struct
{
    int nScheduleID;               ///< 排班ID
    int nClassID;                  ///< 班次唯一ID
    char chName[64];               ///< 班次名称
    int nUserID;                   ///< 用户ID
    int nRoleID;                   ///< 角色ID
    char chUserName[64];           ///< 用户名
    char chRoleName[64];           ///< 角色名
    char chDateTime[32];           ///< 排班日期
    char chWeekDayName[32];        ///< 星期几
}S_NEW_INSPECT_SCHEDULEINFOSHOW;

///< 主动巡查班次-用户信息获取(215-int)
typedef struct
{
    int nCondition;                ///< 条件：0-全部，1-根据班次名和角色名
    char chClassName[64];          ///< 班次名
    char chRoleName[64];           ///< 角色名
}P_NEW_INSPECT_CLASSUSERINFOSHOW;

///< 主动巡查班次-用户信息获取(215-out)
typedef struct
{
    int nClassID;                  ///< 班次唯一ID
    char chName[64];               ///< 班次名称
    bool bWeek[7];                 ///< 星期几是否上班[星期一-0 ~ 星期天-6]
    int nUserID;                   ///< 用户ID
    int nRoleID;                   ///< 角色ID
    char chUserName[64];           ///< 用户名
    char chRoleName[64];           ///< 角色名
    char chStartTime[32];          ///< 班次开始时间
    char chEndTime[32];            ///< 班次结束时间
    bool bCrossDate;               ///< 是否跨天
    bool bParticipate;             ///< 是否参与排班
}S_NEW_INSPECT_CLASSUSERINFOSHOW;

///< 主动巡查班次模板基本操作(216-int)
typedef struct
{
    int nCondition;                ///< 条件：1-add,2-mod,3-del
    int nModuleID;                 ///< 班次模板唯一ID
    char chName[64];               ///< 班次模板名称
    char chStartTime[32];          ///< 班次模板开始时间
    char chEndTime[32];            ///< 班次模板结束时间
    bool bCrossDate;               ///< 是否跨天
    char chRoleIds[1024];          ///< 相关角色ID串(如：1$2$)
}P_NEW_INSPECT_CLASSMODULESET;

///< 主动巡查任务信息基本操作(217-int)
typedef struct
{
    int nCondition;                ///< 条件：1-add,2-mod
    int nTaskID;                   ///< 任务唯一ID
    char chName[64];               ///< 任务名称
    char chDescription[512];       ///< 任务描述
    int nOperation;                ///< 任务操作类型
    char chEffectiveBeginDate[32]; ///< 有效期开始时间
    char chEffectiveEndDate[32];   ///< 有效期结束时间
    int nLoopMethod;               ///< 循环规则
    char chLoopMemo[512];          ///< 循环备注
    bool bDoTimeRange;             ///< 是否规定任务时间范围
    char chStartTime[32];          ///< 开始时间
    char chEndTime[32];            ///< 结束时间
    bool bStartInTime;             ///< 是否规定准时执行
    bool bEngInTime;               ///< 是否强制要求截止时间
    bool bWarn;                    ///< 是否到点提醒
    int nWarnMinu;                 ///< 到点前X分钟提醒
    bool bTotalTime;               ///< 是否规定任务执行时长
    int nToTalTime;                ///< 任务执行时长
    int nTotalTimes;               ///< 执行次数
    bool bRuleTimes;               ///< 是否强制值班员在执行查看视频时以点击视频预览频幕作为巡检必要动作
    int nRuleTimes;                ///< 每次任务每路视频至少点击次数
    char chInstructions[1024];     ///< 任务指导
    bool bTaskLevel;               ///< 是否规定任务重要等级
    int nTaskLevel;                ///< 任务重要等级（等级表ID）没有规定的时候为0
    bool bError;                   ///< 是否异常参考
    int nError;                    ///< 异常表ID，没有时为0
    char chErrorLabel[128];        ///< 任务标签
    int nClassId;                  ///< 班次唯一ID
    int nStatus;                   ///< 任务状态（1-未下发，2-未完成，3-已下发）
    int nType;                     ///< 任务类型（1-日常任务，2-突发任务）
    char chRoleNames[1024];        ///< 下发对象（角色名称$串）
    char chKeyPartName[128];       ///< 部位名称
    int nObject;                   ///< 虚拟场所为1，具体场所为2
    char chPlaceNames[30000];      ///< 虚拟场所或具体场所名称（$串）
    char chDates[8000];            ///< 日期$串
}P_NEW_INSPECT_TASKINFOSET;

///< 主动巡查快速任务信息基本操作(218-int)
typedef struct
{
    char chName[64];               ///< 任务名称
    char chDescription[512];       ///< 任务描述
    bool bDoTimeRange;             ///< 是否规定任务时间范围
    char chStartTime[32];          ///< 任务开始时间
    char chEndTime[32];            ///< 任务结束时间
    bool bStartInTime;             ///< 是否准时开始执行
    bool bEngInTime;               ///< 是否要求截止时间
    bool bTotalTime;               ///< 是否规定任务执行时长
    int nToTalTime;                ///< 任务时长（单位：分钟）
    char chUserName[64];           ///< 用户名
    int nScheduleID;               ///< 排班ID
}P_NEW_INSPECT_FASTTASKINFOSET;

///< 主动巡查任务模板基本操作(219-int)
typedef struct
{
    int nCondition;                   ///< 条件：1-add,2-mod,3-del
    int nMoudleID;                    ///< 模板ID
    char chName[64];                  ///< 模板任务名称
    char chDescription[512];          ///< 任务描述
    int nOperation;                   ///< 操作类型
    int nLoopMethod;                  ///< 循环方式
    char chLoopMemo[512];             ///< 循环方式备注
    bool bDoTimeRange;                ///< 是否规定任务时间范围
    char chStartTime[32];             ///< 开始执行时间
    char chEndTime[32];               ///< 结束执行时间
    bool bStartInTime;                ///< 是否规定准点执行
    bool bEngInTime;                  ///< 是否强制要求截止时间
    bool bWarn;                       ///< 是否设置到点提醒
    int nWarnMinu;                    ///< 到点前X分钟提醒
    bool bTotalTime;                  ///< 是否规定任务执行时长
    int nToTalTime;                   ///< 执行时长
    int nTotalTimes;                  ///< 执行次数
    bool bRuleTimes;                  ///< 是否强制值班员在执行查看视频时以点击视频预览屏幕作为巡检必要动作
    int nRuleTimes;                   ///< 每次任务每路视频至少点击次数
    char chInstructions[1024];        ///< 任务指导
    bool bTaskLevel;                  ///< 是否规定重要等级
    int nTaskLevel;                   ///< 等级表ID
    bool bError;                      ///< 是否给予异常参考
    int nError;                       ///< 异常表ID，没有异常时传0
    char chErrorLabel[128];           ///< 任务标签
    char chUserName[64];              ///< 模板添加用户名
}P_NEW_INSPECT_TASKMODULESET;        

///< 主动巡查任务执行插入(220-int)
typedef struct
{
    int nTaskDistributeId;                ///< 任务下发ID
    char chAreaName[64];                  ///< 具体网点名称
    int nDoError;                         ///< 异常类型值
    bool bDoCarry;                        ///< 是否为关注任务巡检
    char chBeginTime[32];                 ///< 开始巡检时间
    char chError[512];                    ///< 异常$串
    char chOperate[512];                  ///< 操作$串
    char chAnnex[2048];                   ///< 附件
    char EPlanName[128];                  ///< 预案名称
    bool bIsQualified;                    ///< 是否合格
    char chReadRecord[8000];              ///< 批阅记录
    char chMemo[512];                     ///< 备注
    char chActionNos[8000];               ///< 处理步骤编号$串
    char chActionNames[8000];             ///< 处理步骤名称$串
    char chHandleMans[8000];              ///< 处理人$串
    char chDoBeginTimes[8000];            ///< 开始处理时间$串
    char chDoEndTimes[8000];              ///< 结束处理时间$串
    char chAttachments[8000];             ///< 附件$串
    char chDoSuccesses[8000];             ///< 是否执行成功$串
    char chMemos_VarC[8000];              ///< 备注$串
	char chTerminalIds[4000];			   ///<终端ID，用$分割
    char chChannelNos[2000];			   ///<通道ID，用$分割
    char chBeginTimes[8000];			   ///<开始时间，用$分割
    char chEndTimes[8000];				   ///<结束时间，用$分割
}P_NEW_INSPECT_TASKEXCUTESET;

///< 主动巡查批阅记录添加(221-int)
typedef struct
{
    int nTaskID;                  ///< 任务巡检ID
    char chTaskCheckTime[32];     ///< 任务批阅时间
    char chTaskCheckContent[512]; ///< 任务批阅内容
    char chTaskCheckUser[64];     ///< 任务批阅人用户名
}P_NEW_INSPECT_CHECKRECORDSET;       

///< 主动巡查任务下发状态修改(222-int)
typedef struct
{
    int nTaskID;                  ///< 任务ID
    int nStatusType;              ///< 任务状态类型
    char chRevokeUser[64];        ///< 任务撤销人用户名
    char chTaskMemo[512];         ///< 任务撤销备注
}P_NEW_INSPECT_TASKSTATUSMOD;

///< 主动巡查异常表合格状态修改(223-int)
typedef struct
{
    int nTaskID;                  ///< 任务巡检ID
    bool bIsQualified;            ///< 是否合格
}P_NEW_INSPECT_ISQUALIFIEDMOD;

///< 主动巡查异常表插入(224-int)
typedef struct
{
    int nTaskID;                  ///< 任务执行ID
    bool bDoError;                ///< 是否有异常
    char chErrorNames[256];       ///< 异常名称$串
    char chOperate[128];          ///< 操作名称
    char chAnnex[2048];           ///< 附件
    bool bIsSelfDefinite;         ///< 是否自定义
    char chErrorTypeDefinite[256];///< 自定义异常类型
    char chErrorOperateDefinite[512]; ///< 自定义处理方式
    bool bIsQualified;            ///< 是否合格
    char chMemo[512];             ///< 备注
}P_NEW_INSPECT_EXCUTEERRORSET;

///< 获取当前值班人员信息(225-out)
typedef struct
{
    int nUserID;                   ///< 用户ID
    char chName[64];               ///< 用户名
    int nScheduleID;               ///< 排班ID
}S_NEW_INSPECT_CURDUTYPEOPLEINFO;

///< 获取所有任务详细信息(226-int)
typedef struct
{
    int nCondition;                ///< 条件：0-全部，1-根据任务ID，2-自定义
    int nTaskID;                   ///< 任务ID[nCondition = 1]
    int nStatus;                   ///< 任务状态：1-未下发，2-已下发[nCondition = 2]
    char chTask[64];               ///< 任务名称[nCondition = 2]
    char chOppTask[32];            ///< 任务操作[nCondition = 2]
    char chClass[32];              ///< 班次名称[nCondition = 2]
    char chRole[32];               ///< 角色名称[nCondition = 2]
    char chOppObject[64];          ///< 任务对象[nCondition = 2]
}P_NEW_INSPECT_SHOWALLTASKINFO;

///< 获取所有任务详细信息(226-out) [nCondition = 0]
typedef struct
{
    int nTI_Id_Int;                           ///< 任务ID
    char chTI_Name_VarC[64];                  ///< 任务名称
    char chOI_Name_VarC[32];                  ///< 操作类型名称
    char chCI_Name_VarC[32];                  ///< 班次名称
    char chRI_RoleName_VarC[32];              ///< 角色名称
    char chTI_EffectiveBeginDate_Date[32];    ///< 有效期开始时间
    char chTI_EffectiveEndDate_Date[32];      ///< 有效期结束时间
    char chTI_StartTime_VarC[32];             ///< 开始时间
    char chTI_EndTime_VarC[32];               ///< 结束时间
    bool bTI_Warn_Bit;                        ///< 是否到点提醒
    char chTI_Status_Int[32];                 ///< 任务状态（未下发，未完成，已下发）
    char chTI_Type_Int[32];                   ///< 任务类型（日常任务，突发任务）
    char chOppObject[64];                     ///< 操作对象
}S_NEW_INSPECT_SHOWALLTASKINFO_ALL;

///< 获取所有任务详细信息(226-out) [nCondition = 1]
typedef struct
{
    int nTI_Id_Int;                           ///< 任务ID
    char chTI_Description_VarC[512];          ///< 任务描述
    int nTI_Operation_Int;                    ///< 任务操作类型
    int nTI_LoopMethod_Int;                   ///< 循环规则
    char chTI_LoopMemo_VarC[512];             ///< 循环备注
    bool bTI_DoTimeRange_Bit;                 ///< 是否规定任务时间范围
    bool bTI_StartInTime_Bit;                 ///< 是否规定准时执行
    bool bTI_EngInTime_Bit;                   ///< 是否强制要求截止时间
    int nTI_WarnMinu_Int;                     ///< 到点前X分钟提醒
    bool bTI_TotalTime_Bit;                   ///< 是否规定任务执行时长
    int nTI_ToTalTime_Int;                    ///< 任务执行时长
    int nTI_TotalTimes_Int;                   ///< 执行次数
    bool bTI_RuleTimes_Bit;                   ///< 是否强制值班员在执行查看视频时以点击视频预览频幕作为巡检必要动作
    int nTI_RuleTimes_Int;                    ///< 每次任务每路视频至少点击次数
    char chTI_Instructions_VarC[1024];        ///< 任务指导
    bool bTI_TaskLevel_Bit;                   ///< 是否规定任务重要等级
    int nTI_TaskLevel_Int;                    ///< 任务重要等级（等级表ID）没有规定的时候为0
    bool bTI_Error_Bit;                       ///< 是否异常参考
    int nTI_Error_Int;                        ///< 异常表ID，没有时为0
    char chTI_ErrorLabel_VarC[128];           ///< 任务标签
    int nTI_ClassId_Int;                      ///< 班次ID
    char chTI_Name_VarC[64];                  ///< 任务名称
    int nOI_Id_Int;                           ///< 操作类型
    char chOI_Name_VarC[32];                  ///< 操作类型名称
    int nTOR_Object_Int;                      ///< 虚拟场所为1，具体场所为2
    int nTOR_PlaceId_Int;                     ///< 场所ID
    int nTOR_KeyPartId_Int;                   ///< 部位ID
    char chCI_Name_VarC[32];                  ///< 班次名称
    bool bCI_IsCrossDate_Bit;                 ///< 是否跨天
    char chCI_StartTime_VarC[32];             ///< 班次开始时间
    char chCI_EndTime_VarC[32];               ///< 班次结束时间
    bool bWeek[7];                            ///< 星期几是否上班[星期一-0 ~ 星期天-6]
    int nRI_Id_Int;                           ///< 角色ID
    char chRI_RoleName_VarC[32];              ///< 角色名称
    char chTI_EffectiveBeginDate_Date[32];    ///< 有效期开始时间
    char chTI_EffectiveEndDate_Date[32];      ///< 有效期结束时间
    char chTI_StartTime_VarC[32];             ///< 开始时间
    char chTI_EndTime_VarC[32];               ///< 结束时间
    bool bTI_Warn_Bit;                        ///< 是否到点提醒
    char chTI_Status_Int[32];                 ///< 任务状态（未下发，未完成，已下发）
    char chTI_Type_Int[32];                   ///< 任务类型（日常任务，突发任务）
    char chOppObject[64];                     ///< 操作对象[场所]
    char chKeyPart[128];                      ///< 关键部位
}S_NEW_INSPECT_SHOWALLTASKINFO;

///< 获取任务操作类型信息(227-out)
typedef struct
{
    int nOperationId;           ///< 操作类型ID
    int nType;                  ///< 1-查看视频 2-回放视频
    char chName[32];            ///< 操作类型名称
    char chMemo[128];           ///< 备注
}S_NEW_INSPECT_TASKOPERATIONINFOSHOW;

///< 获取任务重要程度信息(228-out)
typedef struct
{
    int nTaskLevelId;           ///< 等级ID
    int nType;                  ///< 等级类型 1-普通 2-重要
    char chName[32];            ///< 等级名称
}S_NEW_INSPECT_TASKLEVELINFOSHOW;

///< 获取任务模板信息(229-int)
typedef struct
{
    int nCondition;                ///< 条件：0-全部，1-根据任务模板ID
    int nTaskModuleID;             ///< 任务模板ID
}P_NEW_INSPECT_TASKMODULEINFOSHOW;

///< 获取任务模板信息(229-out)[nCondition == 0]
typedef struct
{
    int nTaskModuleID;             ///< 任务模板唯一ID
    char chName[64];               ///< 任务模板名称
    char chUserName[64];           ///< 模板添加用户名
    char chAddTime[32];            ///< 模板添加时间
}S_NEW_INSPECT_TASKMODULEINFOSHOW_ALL;

///< 获取任务模板信息(229-out)[nCondition == 1]
typedef struct
{
    int nTaskModuleID;             ///< 任务模板唯一ID
    char chName[64];               ///< 任务模板名称
    char chDescription[512];       ///< 任务描述
    int nOperation;                ///< 任务操作类型 1-查看视频 2-录像回放
    int nLoopMethod;               ///< 循环规则 1-每天 2-每周 3-每月
    char chLoopMemo[512];          ///< 循环规则备注
    char chStartTime[32];          ///< 开始执行时间
    char chEndTime[32];            ///< 结束执行时间
    bool bDoTimeRange;             ///< 是否规定任务时间范围
    bool bStartInTime;             ///< 是否规定准时执行
    bool bEngInTime;               ///< 是否强制要求截止时间
    bool bWarn;                    ///< 是否到点提醒
    int nWarnMinu;                 ///< 到点前X分钟提醒
    int nToTalTime;                ///< 任务执行时长（单位：分钟）
    int nTotalTimes;               ///< 执行次数
    bool bTotalTime;               ///< 是否规定任务执行时长
    bool bRuleTimes;               ///< 是否强制值班员在执行查看视频时以点击视频预览频幕作为巡检必要动作
    bool bTaskLevel;               ///< 是否规定任务重要等级
    bool bError;                   ///< 是否异常参考
    int nRuleTimes;                ///< 每次任务每路视频至少点击次数
    int nTaskLevel;                ///< 任务重要等级（等级表ID）没有规定的时候为0
    char chTaskLevelName[32];      ///< 任务重要等级名称
    int nError;                    ///< 异常表ID，没有时为0
    char chErrorName[64];          ///< 异常类型名称
    char chInstructions[1024];     ///< 任务指导
    char chErrorLabel[128];        ///< 任务标签
    char chUserName[64];           ///< 模板添加用户名
    char chAddTime[32];            ///< 模板添加时间
}S_NEW_INSPECT_TASKMODULEINFOSHOW;

///< 获取所有通道部位信息(230-out)
typedef struct
{ 
    unsigned int nDevId;          ///< 设备ID
    int nChannelId;               ///< 通道ID
    int nChannelNo;               ///< 通道号
    char chKeyPartName[128];      ///< 部位名称
}S_NEW_INSPECT_CHANNELKEYPARTINFOSHOW;

///< 根据角色获取其权限信息(231-int)
typedef struct
{
    int nRoleID;                    ///< 角色ID
    int nTypeInt;                   ///< 权限类型[1-视频预览，2-视频回放]
}P_NEW_INSPECT_ROLEDEVINFOSHOW;

///< 根据角色获取其权限信息(231-out)
typedef struct
{
    unsigned int nDevId;           ///< 设备ID
    unsigned int Purview[8];       ///< 权限值
}S_NEW_INSPECT_ROLEDEVINFOSHOW;

///< 根据班次获取任务下发角色(232-int)
typedef struct
{
    char chClassName[32];         ///< 班次名称
}P_NEW_INSPECT_TASKSENDROLEINFO;

///< 根据班次获取任务下发角色(232-out)
typedef struct
{
    int nRoleId;                  ///< 角色ID
    char chRoleName[64];          ///< 角色名称
}S_NEW_INSPECT_TASKSENDROLEINFO;

///< 获取任务对象信息(233-int)
typedef struct
{
    int nCondition;                ///< 条件：1-获取全部,2-根据某具体角色获取,3-根据角色串获取
    int nOperation;                ///< 任务操作类型 1-查看视频 2-录像回放
    char chRoleList[640];          ///< 条件为2时，仅赋值角色名称（角色1）；为3时，该参数赋值为角色名称串（角色1$角色2$）
}P_NEW_INSPECT_TASKOBJECTINFO;

///< 获取任务对象信息(233-out)
typedef struct
{
    int nObjectId;                 ///< 虚拟场所ID
    int nObjectType;               ///< 虚拟场所类型
    char chObjectName[64];         ///< 虚拟场所名称
    int nPlaceId;                  ///< 具体场所ID 当查询条件为角色串时，将不会获取到具体场所
    char chPlaceName[64];          ///< 具体场所名称
}S_NEW_INSPECT_TASKOBJECTINFO;

///< 上、下班签到设置(234-int)
typedef struct
{
    int nCondition;                ///< 条件：1-上班，2-下班
    int nScheduleID;               ///< 排班ID
}P_NEW_INSPECT_CLASSCONFIRMSETINFO;

///< 获取某用户的今日任务(235-int)
typedef struct
{
    int nScheduleId;              ///< 排班ID
    int nTaskType;                ///< 任务类型[0-默认全部，1-普通，2-快速]
}P_NEW_INSPECT_TODAYTASKINFOSHOW;

///< 获取某用户的今日任务(235-out)
typedef struct
{
    int nTaskId;                  ///< 任务ID
    char chTaskName[64];          ///< 任务名称
    int nTaskLevel;               ///< 任务重要等级
    float fPTask;                 ///< 任务完成率
    char chStartTime[32];         ///< 开始执行时间
    char chEndTime[32];           ///< 结束执行时间
    bool bStartInTime;            ///< 是否规定准时执行
    bool bEngInTime;              ///< 是否强制要求截止时间
    bool bWarn;                   ///< 是否到点提醒
    int nWarnMinu;                ///< 到点前X分钟提醒
    int nTaskNextID;              ///< 任务下发ID
}S_NEW_INSPECT_TODAYTASKINFOSHOW;

///< 获取某条下发任务的执行信息(236-int)
typedef struct
{
    int nCondition;               ///< 0-获取某条下发任务的执行信息 1-获取任务对象信息 2-获取任务执行情况
    int nTaskId;                  ///< 下发任务ID
    int nScheduleID;              ///< 排班ID[nCondition = 2]
}P_NEW_INSPECT_TODAYTASKALLINFOSHOW;

///< 获取某条下发任务的执行信息(236-out)[nCondition = 0]
typedef struct
{
    char chTaskName[64];          ///< 任务名称
    char chInstructions[1024];    ///< 任务指导
    bool bTotalTime;              ///< 是否规定任务执行时长
    bool bRuleTimes;              ///< 是否强制值班员在执行查看视频时以点击视频预览频幕作为巡检必要动作
    int nToTalTime;               ///< 任务执行时长（单位：分钟）
    int nRuleTimes;               ///< 每次任务每路视频至少点击次数
    char chErrorNameList[1024];   ///< 异常项
}S_NEW_INSPECT_TODAYTASKALLINFOSHOW;

///< 获取某条下发任务的执行信息(236-out)[nCondition = 1]
typedef struct
{
    int nObjectId;                ///< 场所编号
    char chObjectName[64];        ///< 场所名称
    int nKeyPartID;               ///< 部位ID
    int nObject_Int;              ///< 操作类型
}S_NEW_INSPECT_TODAYTASKOBJECTINFOSHOW;

///< 获取某条下发任务的执行信息(236-out)[nCondition = 2]
typedef struct
{
    char chAreaName[64];          ///< 网点名称
    char chSubmitTime[32];        ///< 任务提交时间
    bool bError;                  ///< 是否异常
}S_NEW_INSPECT_TODAYTASKDOINFOSHOW;

///< 获取用户多日任务(237-int)
typedef struct
{
    char chUserName[64];          ///< 用户名称
    char chBeginTime[32];         ///< 查询起始日期
    char chEndTime[32];           ///< 查询结束日期
}P_NEW_INSPECT_USERTASKINFOSHOW;

///< 获取用户多日任务(237-out)
typedef struct
{
    int nTaskId;                  ///< 任务编号
    char chTaskName[64];          ///< 任务名称
    char chDateTime[32];          ///< 任务日期
}S_NEW_INSPECT_USERTASKINFOSHOW;

///< 任务查询(238-in)
typedef struct
{
    char chUserName[64];          ///< 用户名称
    char chTaskName[64];          ///< 任务名称
    char chRoleName[64];          ///< 角色名称
    int  nError;                  ///< 异常类型值 0-无异常，1-执行时间过短，2-执行不准时，3-巡检有异常
    int  nClassId;                ///< 班次ID
    char chBeginDate[32];         ///< 查询起始日期
    char chEndDate[32];           ///< 查询结束日期(结束时间最好不要大于当前日期，之后的日期是无结果的)238
}P_NEW_INSPECT_CHECKTASKINFOSHOW;

///< 任务查询(238,294-out)
typedef struct
{
    int nTaskId;                  ///< 任务编号
    char chTaskName[64];          ///< 任务名称
    char chRoleName[64];          ///< 角色名
    char chUserName[64];          ///< 用户名称
    char chTaskLevel[32];         ///< 任务等级
    int nErrorType;               ///< 异常类型编号（0-无异常，1-执行时间过短，2-执行不准时，3-巡检有异常）
	int nProperty;                ///< 锁定状态：0-解锁；1-锁定；
}S_NEW_INSPECT_CHECKTASKINFOSHOW;

///< 任务复核信息(239-int)
typedef struct
{
    int nTaskId;                ///< 任务执行ID
}P_NEW_INSPECT_SHOWTASKCHECKINFO;


///<获取任务执行关联通道的信息（239-out）
typedef struct _TaskExecute_Relate_Show
{
	char chTerminalIds[4000];			   ///<终端ID，用$分割
	char chChannelNos[2000];			   ///<通道ID，用$分割
	char chBeginTimes[8000];			   ///<开始时间，用$分割
	char chEndTimes[8000];				   ///<结束时间，用$分割
}TaskExecuteRelate_S;

///< 任务复核信息(239-out)
typedef struct
{
    int nTaskId;                ///< 任务执行ID
    int nDoError;               ///< 操作异常
    int nProperty;              ///< 是否已批阅
    char chBeginTime[32];       ///< 开始执行时间
    char chEndTime[32];         ///< 结束执行时间
    char chAreaName[64];        ///< 网点名称
    char chAddress[128];        ///< 网点地址
    char chContactMan[256];     ///< 联系人
    char chContactInfo[256];    ///< 联系人联系方式
    char chErrors[512];         ///< 异常项$串
    char chUserName[32];        ///< 任务执行人用户名称
    char chRoleName[32];        ///< 任务执行人角色名称
    char chFindPSWQ[64];        ///< 任务执行人联系方式
    char chHeadPortrait[512];   ///< 头像
    char chOperates[512];       ///< 操作$串
    char chMemo[512];           ///< 备注
    char chAnnex[2048];         ///< 附件
    char chReadRecord[8000];    ///< 批阅记录
    char chEPlanName[128];      ///< 预案名称
    bool bDoCarry;              ///< 是否被关注
    bool bIsQualified;          ///< 是否合格
	TaskExecuteRelate_S T_TaskRelate;    ///<任务关联信息
	int nLockProperty;		    ///< 锁状态：0-解锁；1-锁定；
	
}S_NEW_INSPECT_SHOWTASKCHECKINFO;

///< 任务相关预案信息(240-int)
typedef struct
{
    int nTaskId;                  ///< 任务编号
}P_NEW_INSPECT_SHOWTASKEPLANINFO;

///< 任务相关预案信息(240-out)
typedef struct
{
    int nTaskId;                  ///< 任务编号
    int nActionNo;                ///< 动作编号
    int nSequece;                 ///< 序号
    char chActionName[64];        ///< 动作名
    char chBeginTime[32];         ///< 开始时间
    char chEndTime[32];           ///< 结束时间
    char chHandleMan[64];         ///< 处理人
    char chAttachment[1024];      ///< 附件
    char chMemo[512];             ///< 备注
    bool bDoSuccess;              ///< 是否成功
}S_NEW_INSPECT_SHOWTASKEPLANINFO;

///< 某具体网点异常项发生情况(241-int)
typedef struct
{
    int nCondition;               ///< 0-全部 1-根据ID 2-根据名称
    int nAreaId;                  ///< 网点ID
    char chAreaName[64];          ///< 网点名称
}P_NEW_INSPECT_SHOWAREAERRORINFO;

///< 某具体网点异常项发生情况(241-out)
typedef struct
{
    int nAreaId;                  ///< 网点ID
    int nErrorNum;                ///< 异常发生次数
    char chAreaName[64];          ///< 网点名称
    char chErrorName[64];         ///< 异常名称
}S_NEW_INSPECT_SHOWAREAERRORINFO;

///< 网点的异常率(242-int)
typedef struct
{
    int nCondition;               ///< 0-全部 1-根据ID 2-根据名称
    int nAreaId;                  ///< 网点ID
    char chAreaName[64];          ///< 网点名称
}P_NEW_INSPECT_SHOWAREAERRORATEINFO;

///< 网点的异常率(242-out)
typedef struct
{
    int nAreaId;                  ///< 网点ID
    int nErrorNum;                ///< 异常发生次数
    int nTotalNum;                ///< 巡检总次数
    char chAreaName[64];          ///< 网点名称
    float fErrorRate;             ///< 异常率
}S_NEW_INSPECT_SHOWAREAERRORATEINFO;

///< 巡检覆盖率(243-int)
typedef struct
{
    int nDay;                     ///< N日
}P_NEW_INSPECT_SHOWCOVERRATEINFO;

///< 巡检覆盖率(243-out)
typedef struct
{
    int nTaskId;                  ///< 任务编号
    float fCoverRate;             ///< 覆盖率
}S_NEW_INSPECT_SHOWCOVERRATEINFO;

///< 单位时间内的网点异常数量统计(244-int)
///< nCondition:
///< 1--TOP 排行
///< 2--网点单位时间内产生的异常项分类,每个分类数量
///< 3--某一分类的时间段分布
typedef struct
{
    int nCondition;               ///< 条件
    char chBeginTime[32];         ///< 开始时间 [3:时间段]
    char chEndTime[32];           ///< 结束时间 [3:时间段]
    char chAreaName[64];          ///< 网点名称[2,3]
    int nDay;                     ///< N日[3]
}P_NEW_INSPECT_SHOWAREAERRORNUMINFO;

///< 单位时间内的网点异常数量统计(244-out)
typedef struct
{
    int nAreaId;                  ///< 网点ID
    int nErrorNum;                ///< 异常发生次数
    char chAreaName[64];          ///< 网点名称
    char chErrorName[64];         ///< 异常名称[2,3]
    char chBeginTime[32];         ///< 开始时间[3]
}S_NEW_INSPECT_SHOWAREAERRORNUMINFO;

///< 异常的复查合格率(245-out)
typedef struct
{
    char chUserName[64];          ///< 用户名
    int nExcuteNum;               ///< 合格次数
    int nTotalNum;                ///< 执行总次数
    float fRate;                  ///< 合格率
}S_NEW_INSPECT_SHOWERRORCHECKRATEINFO;

///< 提醒(246-int)
typedef struct
{
    int nScheduleID;               ///< 排班ID
}P_NEW_INSPECT_SHOWALARMRECORINFO;

///< 提醒(246-out)
typedef struct
{
    char chSuggestion[1024];      ///< 描述
}S_NEW_INSPECT_SHOWALARMRECORINFO;

///< 设备类型、品牌、型号信息查询(247-int)
typedef struct
{
    int nCondition;               ///< 条件
    char chType[32];              ///< 类型
    char chManufa[32];            ///< 品牌
}P_NEW_SHOW_JH_DEVICEINFO;

///< 设备类型、品牌、型号信息查询(247-out)
typedef struct
{
    char chName[128];              ///< 名称
}S_NEW_SHOW_JH_DEVICEINFO;

///< 设备管理信息查询(248-int)
typedef struct
{
    int nCondition;               ///< 条件
    char chStart[32];             ///< 开始时间
    char chEnd[32];               ///< 结束时间
    char chType[32];              ///< 类型
    char chManufa[32];            ///< 品牌
    char chModelNo[128];          ///< 型号
    int nStart;                   ///< 开始条数
    int nEnd;                     ///< 结束条数
}P_NEW_CHECK_JH_DEVICEINFO;

///< 设备管理信息查询(248-out)
typedef struct
{
    char chCode[64];              ///< 编号
    char chName[64];              ///< 名称
    char chManufa[32];            ///< 品牌
    char chModelNo[128];          ///< 型号
    char chIP[32];                ///< IP地址
    char chTime[32];              ///< 添加日期
    int nCount;                   ///< 总条数[nCondition =1]
}S_NEW_CHECK_JH_DEVICEINFO;

///< 设备管理信息统计(249-int)
typedef struct
{
    int nCondition;               ///< 条件
    char chStart[32];             ///< 开始时间
    char chEnd[32];               ///< 结束时间
}P_NEW_STATICS_JH_DEVICEINFO;

///< 设备管理信息统计(249-out)
typedef struct
{
    char chName[128];              ///< 名称
    int nCount;                    ///< 条数
}S_NEW_STATICS_JH_DEVICEINFO;

///<报警处理信息的综合查询(251-in)
typedef struct
{
    int nPage;                     ///< 页数
    int nCount_Page;               ///< 每页显示记录条数
    char chBeginTime[32];          ///< 开始时间
    char chEndTime[32];            ///< 结束时间
    char chAreaNames[2048];        ///< 地点编号串
    char chAlarmTypes[1024];       ///< 报警类型串
    char chAlarmlevels[32];        ///< 报警等级串
    char chHandleMan[32];          ///< 处理人
    char chProcessType[32];        ///< 警情类型
    int nProcessStates;            ///< 处理状态
}P_NEW_JH_COMPLEXCHECK;

///<报警处理信息的综合查询(251,295-out)
typedef struct
{
    char chAlarmTypeName[64];      ///< 报警类型名称
    char chAlarmSource[64];        ///< 报警源
    int nAlarmSourceType;          ///< 报警源类型：0-主机，1-摄像头
    char chAlarmArea[64];          ///< 报警地点
    int nSumCount;                 ///< 总记录条数
    int nSumPage;                  ///< 总页数
    char chBeginTime[32];          ///< 报警日志开始时间（2012-01-01 00:00:00）
    char chBeginDay[32];           ///< 报警日志开始日期（2012-01-01）
    char chBeginMonth[32];         ///< 报警日志开始月份（2012-01）
    int nAlarmTypeID;              ///< 报警信息ID
    int nProcessState;             ///< 处理状态
    char chProcessUser_VarC[64];   ///< 处理人
    char chProcessDate_Date[32];   ///< 处理日期
    char chProcessType[32];        ///< 警情类型
    char chProcessMemo_VarC[512];  ///< 备注
    int nAlarmLevel;               ///< 报警等级
    char chPalnName[64];           ///< 对应预案
    char chProcessBeginTime[32];   ///< 处理开始时间
    char chProcessEndTime[32];     ///< 处理结束时间
    char chMemo[128];              ///< 备注信息[人名、部门、出入时间信息]
    char chKeyPart[128];           ///< 部位信息
	int nProperty;                 ///< 锁定状态：0-解锁；1-锁定；
	char chGUID[128];			   ///< 报警GUID
}S_NEW_JH_COMPLEXCHECK;

///< 查询数据库配置字符串(252-out)
typedef struct
{
    char chIp[20];         ///< IP地址
    char chUser[32];       ///< 用户名
    char chPassword[32];   ///< 密码
    char chDatabase[32];   ///< 数据库名
    int nPort;             ///< 连接端口
}S_NEW_JH_DATABASEINFO;

///< 任务添加类统计信息(253-int)
/** nCondition:
*   1: 具体网点任务安排数量
*   2: 任务安排时间周期内每日任务数量
*   3: 选择某一角色后，显示该角色所被安排任务数量
*   4: 选择某一班次后，显示该班次所被安排任务数量
*   5: 某一具体网点重要等级划分
*   6: 某一具体网点操作类型划分
*   7: 某一具体网点任务时段覆盖
*   8: 某一虚拟网点重要等级划分
*   9: 某一虚拟网点操作类型划分
**/
typedef struct
{
    int nCondition;        ///< 条件
    char chName[64];       ///< 传入值
    char chStart[32];      ///< 开始时间
    char chEnd[32];        ///< 结束时间
}P_NEW_INSPECT_STATICS_TASKADDINFO;

///< 任务添加类统计信息(253-out)
typedef struct
{
    char chName[64];       ///< 传出值
    union
    {
        int nNum;          ///< 数量
        char chTime[10];   ///< 时间(nCondition == 7)
    }Data;
}S_NEW_INSPECT_STATICS_TASKADDINFO;

///< 员工的能力分析统计信息(254-int)
typedef struct
{
    char chName[64];       ///< 用户名
}P_NEW_INSPECT_STATICS_EMPLOYANALY;

///< 员工的能力分析统计信息(254-out)
typedef struct
{
    float fTaskExecuteRate;       ///< 任务完成率
    float fQualifiedRate;         ///< 巡检异常合格率
    float fStandardRate;          ///< 巡检规范率
    float fEPlanRate;             ///< 预案处理能力
    float fHighLevelAlarmRate;    ///< 高等级报警处理能力
}S_NEW_INSPECT_STATICS_EMPLOYANALY;

///< 员工管理类统计信息(255-int)
/** nCondition:
*   1: 执行任务等级
*   2: 个人巡检异常不合格时间段分布分析
*   3: 处理报警等级
**/
typedef struct
{
    int nCondition;        ///< 条件
    char chName[64];       ///< 传入值
}P_NEW_INSPECT_STATICS_EMPLOYMANAGER;

///< 员工管理类统计信息(255-out)
typedef struct
{
    int nLevelOrTimes;     ///< 等级值or次数
    union
    {
        int nNum;          ///< 数量
        float fExRate;     ///< 异常率(nCondition == 2)
    }Data;
}S_NEW_INSPECT_STATICS_EMPLOYMANAGER;

///< 用户IP池设置(256-int)
typedef struct
{
    char chAllow[4096];    ///< 有效范围
    char chBan[4096];      ///< 无效范围
}P_NEW_IP_POOL_SET;

///< 用户IP池信息获取(257-out)
typedef struct
{
    char chStart[20];      ///< 起始IP
    char chEnd[20];        ///< 结束IP
    bool bAllow;           ///< 有效/无效范围
}S_NEW_IP_POOL_SHOW;

///< 密码有效期(258-int,259-out)
typedef struct
{
    int nID;              ///< ID索引
    int nDays;            ///< 密码有效期(以天为单位)
}S_NEW_USEFULPSW_INFO;

///< 服务器获取用户密码信息(260)[MD5-int]
typedef struct
{
    int nCondition;       ///< 0-默认全部，1-特定用户
    char chName[64];      ///< 特定用户名
}P_NEW_USERPSWINFO_SHOW;

///< 服务器获取用户密码信息(260)[MD5-out)
typedef struct
{
    char chUsername[64];          ///< 用户名
    char chPassword[64];          ///< 用户密码
    int  nPrity;                  ///< 用户等级
    TJTY_TIME TValiadStartTime;   ///< 有效期开始时间
    TJTY_TIME TValiadEndTime;     ///< 有效期结束时间
    TJTY_TIME TValiadPswStart;    ///< 用户密码开启时间
    bool bUseful;                 ///< 用户启用/禁用状态
}S_NEW_USERPSWINFO_SHOW;

///< 有效报警类型获取(261-out)
typedef struct
{
    int nAlarmTypeID;             ///< 报警类型ID
    char chAlarmType[64];         ///< 报警类型名称
}S_NEW_ALARMDISPOSAL_USEFULTYPE;

///< 有效场所部位信息获取(262-out)
typedef struct
{
    int nPlaceID;                 ///< 场所ID
    char chPlace[64];             ///< 场所名称
    int nKeyPartID;               ///< 部位ID
    char chKeyPart[64];           ///< 部位名称
}S_NEW_ALARMDISPOSAL_USEFULPLACEKEY;

///< 根据用户名获取报警处置权限(263-int)
/* 模块标识
* 1 - 排班模块
* 2 - 日常巡查模块
* 3 - 报警处置模块
* 4 - 第三方认证模块
* 5 - 智能运维模块
*/
typedef struct
{
    char chName[64];      ///< 特定用户名
    char chModule[32];    ///< 模块串：如1,2,3
}P_NEW_ALARMDISPOSAL_AUTH_SHOW;

///< 根据用户名获取报警处置权限(263-out)
/* 权限标记
* 1 - 排班权限 [排班模块]
* 2 - 任务安排权限 [排班模块]
* 3 - 任务复核权限 [日常巡查模块]
* 4 - 值班长交接班权限 [日常巡查模块]
* 5 - 参与排班权限 [排班模块]
* 6 - 任务复核权限 [报警处置模块]
* 7 - 任务分配权限 [报警处置模块]
* 8 - 警情、等级修改权限 [报警处置模块]
* 9 - 定性权限 [报警处置模块]
* 10 - 人员增删改 [第三方认证模块]
* 11 - 录入审核 [第三方认证模块]
* 12 - 认证处置 [第三方认证模块]
* 13 - 审核权限 [第三方认证模块]
* 14 - 记录查询 [第三方认证模块]
* 15 - 普通使用权限 [智能运维模块]
* 16 - 设备信息管理权限 [智能运维模块]
*/
typedef struct
{
    bool bModuleAuth[128];          ///< 具体权限
}S_NEW_ALARMDISPOSAL_AUTH_SHOW;

///< 获取报警等级处置策略(264-out)
/* 具体的权限类型值
* 1 - 允许关闭
* 2 - 全区接收
* 3 - 人工干预
* 4 - 延迟处置
* 5 - 超时设置
* 6 - 处置等待
* 7 - 报警照规则分发
* 8 - 预案处置
* 9 - 按步执行

* 10 - 上级复核
*/
typedef struct
{
    int nALId;             ///< 报警级别ID
    int nAlarmLevel;       ///< 报警级别值
    char chAlarmLevel[64]; ///< 报警级别名
    int nAMId;             ///< 权限ID
    int nMethodId;         ///< 权限值
    char chMethodName[32]; ///< 权限名
    int nRelatedUserId;    ///< 用户ID
    char chUserName[64];   ///< 用户名
    int nEPlanId;          ///< 预案ID
    char chPlanName[64];   ///< 预案名
    int nConfigTime;       ///< 配置时间值
}S_NEW_ALARMDISPOSAL_PLOY_SHOW;

///< 设置值班员状态(265-int)
/*  用户状态
* 1 - 空闲
* 2 - 报警处置中
* 3 - 巡查中
* 4 - 离线
*/
typedef struct
{
    int nUserID;         ///< 用户ID
    char chName[64];     ///< 用户名
    int nStatus;         ///< 用户状态
}P_NEW_ALARMDISPOSAL_DUTYSTATUS_SET;

///< 设置报警信息处置状态(266-int)
/* 处理状态
* 1 - 未处理
* 2 - 处理中
* 3 - 延迟处理
* 4 - 暂停处理
* 5 - 待复核
* 6 - 已处理
* 7 - 已定性
*/
typedef struct
{
    int nAlarmInfoId;              ///< 报警信息ID
    char chAlarmSource[128];       ///< 报警源
    int nSourceType;               ///< 报警源类型 1-主机，2-摄像头
    char chAlarmType[128];         ///< 报警类型
    char chAlarmDateTime[32];      ///< 报警发生时间(yyyy-mm-dd hh:mm::ss)
    int nStatus;                   ///< 处置状态
}P_NEW_ALARMDISPOSAL_STATUS_SET;

///< 设置报警信息处置人(267-int)
typedef struct
{
    int nCondition;                ///< 条件1-add,2-mod(该报警是否已处置过)
    int nAlarmInfoId;              ///< 报警信息ID
    char chAlarmSource[128];       ///< 报警源
    int nSourceType;               ///< 报警源类型 1-主机，2-摄像头
    char chAlarmType[128];         ///< 报警类型
    char chAlarmDateTime[32];      ///< 报警发生时间(yyyy-mm-dd hh:mm::ss)
    char chHandleMan[64];          ///< 处置人
    char chActPerson[64];          ///< 原处置人
}P_NEW_ALARMDISPOSAL_PEOPLE_SET;

///< 提交报警处置结果(268-int)
typedef struct
{
    int nAlarmID;                  ///< 报警信息ID
    char chAlarmGUID[64];          ///< 报警流水号
    char chAlarmSource[128];       ///< 报警源
    int nSourceType;               ///< 报警源类型 0-主机，1-摄像头
    char chAlarmType[128];         ///< 报警类型
    char chAlarmDateTime[32];      ///< 报警发生时间(yyyy-mm-dd hh:mm::ss)
    int nAlarmLevel;               ///< 报警级别
    char chKeyPart[128];           ///< 关键部位
    int nProcessType;              ///< 处理方式
    char chMemo[512];              ///< 备注
    int nEPlanType;                ///< 预案类型(1-普通预案，2-事件)
    char chPlanName[128];          ///< 预案名
    char chHandleMan[128];         ///< 处理人
    char chAttachment[1024];       ///< 报警附件
    bool bDoFinish;                ///< 是否处理完成
    char chActionNos[1000];        ///< 预案步骤ID串
    char chActionNames[2048];      ///< 预案步骤名字串
    char chDoBeginTimes[2048];     ///< 预案步骤开始时间串
    char chDoEndTimes[2048];       ///< 预案步骤结束时间串
    char chAttachments[8000];      ///< 预案步骤附件串
    char chDoSuccesses[800];       ///< 预案步骤处理完成拼接字符串
    char chDoMans[2048];           ///< 预案步骤处理人串
    char chDoMemos[8000];          ///< 预案步骤处理描述串
    char chMustBeDones[8000];      ///< 预案步骤是否必须执行串
    char chAlarmCategory[32];      ///< 警情描述
    char chCheckStatus[32];        ///< 定性戳
}P_NEW_ALARMDISPOSAL_DEALSULT_SET;

///< 获取用户空闲状态(269-int)
/* nCondition:
* 0 - 获取所有用户状态
* 1 - 获取所有空闲用户
* 2 - 根据用户名串获取用户状态
*/
typedef struct
{
    int nCondition;                ///< 条件
    char chUsers[3072];            ///< 用户串：如: 'use1','user2'
}P_NEW_ALARMDISPOSAL_USERSTATUS_SHOW;

///< 获取用户空闲状态(269-out)
typedef struct
{
    char chName[64];              ///< 用户
    int nStatus;                  ///< 用户状态
}S_NEW_ALARMDISPOSAL_USERSTATUS_SHOW;

///< 报警等级策略设置(270-int)
typedef struct
{
    int nLevelVaule;             ///< 报警级别类型值
    char chMethodIds[1024];      ///< 权限类型值串$
    char chUserIds[1024];        ///< 用户ID串$
    char chConfigTimes[1024];    ///< 配置时间串$
    char chEPlanIds[1024];       ///< 预案ID串$
}P_NEW_ALARMDISPOSAL_ALM_SET;

///< 获取用户能处理的报警等级(271-int)
/* nCondition:
* 0 - 全部
* 1 - 特定用户
*/
typedef struct
{
    int nCondition;              ///< 条件
    char chName[64];             ///< 特定用户名
}P_NEW_ALARMDISPOSAL_USERAL_SHOW;

///< 获取用户能处理的报警等级(271-out)
typedef struct
{
    char chName[64];             ///< 特定用户名
    char chLevels[64];           ///< 报警级别类型值串$
}S_NEW_ALARMDISPOSAL_USERAL_SHOW;

///< 警情类型、定性戳信息设置(272-int)(add、mod、del)
typedef struct
{
    int nCondition;              ///< 条件: 1,2,3-警情，4,5,6-定性戳
    int nTypeID;                 ///< 唯一ID
    char chName[32];             ///< 名称
    int nTypeValue;              ///< 类型值
}P_NEW_ALARMDISPOSAL_ACATEGORY_SET;

///< 警情类型、定性戳信息获取(273-int)
typedef struct
{
    int nCondition;              ///< 条件: 1-警情，2-定性戳
}P_NEW_ALARMDISPOSAL_ACATEGORY_SHOW;

///< 警情类型、定性戳信息获取(273-out)
typedef struct
{
    int nTypeID;                 ///< 唯一ID
    char chName[32];             ///< 名称
    int nTypeValue;              ///< 类型值
}S_NEW_ALARMDISPOSAL_ACATEGORY_SHOW;

///< 模块权限信息获取(274-int)
typedef struct
{
    int nCondition;             ///< 条件: 0-所有，1-根据具体的模块、权限，2-报警等级权限块信息
    char chModules[64];         ///< 模块: 1,2,3
    char chAuths[128];          ///< 权限：1,2,3,4
}P_NEW_ALARMDISPOSAL_MODULEANTH_SHOW;

///< 模块权限信息获取(274-out)
typedef struct
{
    char chAuth[32];            ///< 权限名
    int nAuthValue;             ///< 权限值
    char chModule[32];          ///< 所属模块
}S_NEW_ALARMDISPOSAL_MODULEANTH_SHOW;

///< 根据报警等级获取报警权限信息(275-int)
typedef struct
{
    int nCondition;             ///< 条件: 0-根据等级ID，1-根据等级值，2-根据等级名称
    int nID;                    ///< 等级ID
    int nLevel;                 ///< 等级值
    char chName[64];            ///< 等级名
}P_NEW_ALARMDISPOSAL_AMA_SHOW;

///< 根据报警等级获取报警权限信息(275-out)
typedef struct
{
    bool bAuths[32];           ///< 权限信息
    int nTimeOut;              ///< 超时时间
    int nUserID;               ///< 用户ID
    char chUserName[64];       ///< 上报人
    int nPlanID;               ///< 预案ID
    char chPlanName[64];       ///< 预案名
    int nReverseTime;          ///< 倒计时
    int nDelayTime;            ///< 录制延时
}S_NEW_ALARMDISPOSAL_AMA_SHOW;

///< 人工干预报警插入(276-int)
typedef struct
{
    int nDeviceID;             ///< 设备ID
    int nChannelNo;            ///< 通道号
    int nAID;                  ///< 报警类型ID
    int nLevel;                ///< 报警等级值
    int nStstus;               ///< 报警状态
    char chMemo[128];          ///< 备注
    char chName[64];           ///< 处置人
    TJTY_TIME tTime;           ///< 报警时间
}P_NEW_ALARMDISPOSAL_ASSINGLE_SET;

///< 根据名称(277、278、279、280-int)
typedef struct
{
    int nAlramID;             ///< 报警信息ID
    char chName[64];          ///< 名称
}P_NEW_ALARMDISPOSAL_ASMO_SHOW;

///< 某用户未处理完成的报警信息(277-out)
typedef struct
{
    int nAlramID;             ///< 报警信息ID
    char chAlramDate[32];     ///< 报警发生时间
    char chAlramSource[64];   ///< 报警源
    char chAlramType[64];     ///< 报警类型
    int nAlarmLevel;          ///< 报警等级
    char chAlramArea[64];     ///< 报警区域
    char chName[64];          ///< 处理人
    int nStstus;              ///< 报警状态
    char chDateTime[32];      ///< 更新时间
    char chKeyPart[128];      ///< 部位信息
	char chGUID[128];	      ///< 报警GUID
}S_NEW_ALARMDISPOSAL_ASINFO_SHOW;

///< 获取所有用户下属信息(278-out)
typedef struct
{
    int nUserID;              ///< 用户ID
    char chName[64];          ///< 名称
}S_NEW_ALARMDISPOSAL_ANEXT_SHOW;

///< 根据报警ID获取报警批注记录信息(279-out)
typedef struct
{
    char chName[64];          ///< 用户名称
    char chDateTime[32];      ///< 批注时间
    char chMemo[128];         ///< 批注信息
}S_NEW_ALARMDISPOSAL_AM_SHOW;

///< 根据报警ID获取操作记录信息(280-out)
typedef struct
{
    char chName[64];          ///< 操作用户
    char chOpType[64];        ///< 操作类型
    char chMemo[128];         ///< 记录信息
    char chDateTime[32];      ///< 更新时间
}S_NEW_ALARMDISPOSAL_AO_SHOW;

///< 添加批阅记录(281-int)
typedef struct
{
    int nAlramID;             ///< 报警ID
    char chName[64];          ///< 用户
    char chMemo[512];         ///< 备注
    char chDate[32];          ///< 时间
}P_NEW_ALARMDISPOSAL_CRM_SET;

///< 报警复核(282-int)
typedef struct
{
    int nAlramID;               ///< 报警ID
    char chAlarmLevel[64];      ///< 报警等级
    char chAlarmCategory[32];   ///< 警情类型
    char chCheckStatus[32];     ///< 复核状态
    char chIsQualified[64];     ///< 定性戳
    char chCheckMan[64];        ///< 复核人
    char chCheckDate[32];       ///< 复核时间
}P_NEW_ALARMDISPOSAL_AC_SET;

///< 报警复核日志插入(283-int)
typedef struct
{
    int nAlarmId;              ///< 报警ID
    char chActType[64];        ///< 操作类型
    char chActMemo[1024];      ///< 操作备注
    char chActPerson[64];      ///< 操作人
    char chActDate[32];        ///< 操作时间
}P_NEW_ALARMDISPOSAL_ACI_SET;

///< 报警延时处置存储(284-int)
typedef struct
{
    int nAlramID;             ///< 报警ID
    char chAlramSource[64];   ///< 报警源
    char chAlramType[64];     ///< 报警类型
    char chAlramArea[64];     ///< 报警区域
    int nStstus;              ///< 报警状态
    char chDateTime[32];      ///< 更新时间
    char chName[64];          ///< 处理人
}P_NEW_ALARMDISPOSAL_AD_SET;

typedef struct
{
    char chOldName[128];  ///<原处置人姓名
    char chNewName[128];  ///<新处置人姓名
    char chProperty[128]; ///<需修改的状态值 以$拼接以$结束

}TAG_NEW_ALARMDISPOSAL_BATCHSET_P, *PTAG_NEW_ALARMDISPOSAL_BATCHSET_P;

///<报警增加用户信息（288-out）
typedef struct
{
    char chUserName[64];     ///<用户名
    char chHeadImage[64];    ///<头像
    char chWorkNum[16];      ///<工号
    char chId[64];           ///<身份证号
    char charDepartmentName[20];           ///<部门
    int  nUserType;                        ///<用户类型
    char chBeginDate[32];                  ///<人员有效期开始时间
    char chEndDate[32];                    ///<人员有效期结束时间
    char chCardNum[16];                    ///<卡号
    char chCardBeginDate[32];              ///<卡有效期开始时间
    char chCardEndDate[32];                ///<卡有效期结束时间 
}TAGASUSERADD_P, *PTAGASUSERADD_P;

///<获取用户信息（289-out）
typedef struct
{
    char chUserName[64];                   ///<用户名
    char chHeadImage[64];                  ///<头像
    char chWorkNum[16];                    ///<工号
    char chId[64];                         ///<身份证号
    char charDepartmentName[20];           ///<部门
    int  nUserType;                        ///<用户类型
    char chBeginDate[32];                  ///<卡有效期开始时间
    char chEndDate[32];                    ///<卡有效期结束时间
    char chCardNum[16];                    ///<卡号
}TAGASUSERGET_S, *PTAGASUSERGET_S;

///<显示管控等级信息(400-out)
typedef struct
{
    int nLevelId;          ///< 等级ID
    int nLevelValue;       ///< 等级值
    char chLevelName[64];  ///< 等级名称
}S_NEW_SHOWCTRLLEVEL;

///<管控等级修改（401-in）
typedef struct
{
    int nCondition;           ///< 条件: 1-add,2-mod,3-del
    int nValue;               ///< 管控级别值
    char chName[128];         ///< 管控级别名
}P_NEW_OPCTRLLEVELINFO;

///<管控等级划分（402-out）
typedef struct
{
    char chLevelName[128];     ///<等级名称
    char chPlaceName[64];      ///<场所名称
    char chKeyPartName[128];   ///<部位名称
    char chDeviceName[64];     ///<设备名称
}S_NEW_CTRLLEVELINFO;

///<刷卡开门(403)
typedef struct
{
    int nApplyId;                    ///<开门申请ID
    char chDeviceName[64];           ///<门禁名称
    char chAccessDate[32];           ///<刷卡时间
}TAGOPENDOOR_P, *PTAGOPENDOOR_P;

///<开门认证预案信息 (404)
typedef struct
{
    int nId;                        ///<开门申请ID
    char chActionNos[8000];         ///<动作编号
    char chActionNames[8000];       ///<动作名称
    char chHandleMans[8000];        ///<处置人
    char chDoBeginTimes[8000];      ///< 开始处置时间
    char chDoEndTimes[8000];        ///< 结束处置时间
    char chAttachments[8000];       ///< 附件
    char chDoSuccesses[8000];       ///< 是否执行成功
    char chMustBeDones[8000];       ///< 是否必须执行
    char chMemos[8000];             ///< 操作内容等信息
}TAGOPENDOORPLANINFO_P, *PTAGOPENDOORPLANINFO_P;

///<处置方式 (405)
typedef struct
{
    int nId;                           ///<开门申请ID
    int nMethod;                       ///<处置方式值 -1-未处理  0-开门1-申请授权 2-应急处置  3-申请特批 4-拒绝开门
}TAGDOOROPENAPPLY_METHOD_P, *PTAGDOOROPENAPPLY_METHOD_P;

///<认证状态 (406)
typedef struct
{
    int nId;                ///<开门申请ID
    int nProcessStatus;       ///< 认证状态值 1-未处置2-处置中 3-待审核4-已处理5-已失效
    char chHandleDate[20];             ///<处置时间
}TAGDOA_PROCESSSTATUS_P, *PTAGDOA_PROCESSSTATUS_P;

///<开门申请审核 (407)
typedef struct
{
    int nId;                             ///<开门申请ID
    int nProcessType;                    ///<审核状态	1-通过 2-拒绝
    int nProcessStatus;                  ///<认证状态值 1-未处 2-处置中 3-待审核 4-已处理 5-已失效
    int nPassStatus;                     ///< 通行情况	1-同意开门 2-拒绝进入
    char chAuditor[128];                 ///<审核人名称
    char chAuditDate[20];                  ///<审核时间
}TAGDOA_AUDITOR_P, *PTAGDOA_AUDITOR_P;

///<开门申请收藏(408)
typedef struct
{
    int nId;                            ///<开门申请ID
    int nIsCollection;                  ///<是否收藏 1-收藏 0-不
}TAGDOA_ISCOLLECTION_P, *PTAGDOA_ISCOLLECTION_P;

///<开门申请信息(409-in)
typedef struct
{
    char chDeviceName[64];              ///<设备名称
    char chAreaName[64];                ///<所在网点名称
    char chKeyPart[128];                ///<部位名称
    char chContactPerson[128];          ///<联系人名称
    char chHappenDate[32];              ///<触发时间
    char chContactInfo[16];             ///<联系方式
    int nMethod;                        ///<处置方式
    char chPlanName[128];               ///<预案名称
    int nProcessType;                   ///<审核状态	1-通过 2-拒绝
    int nProcessStatus;                 ///<认证状态值 1-未处 2-处置中 3-待审核 4-已处理 5-已失效
    int nIsCollection;                  ///<是否收藏 1-收藏 0-不
    int nPassStatus;                    ///<通行情况	1-同意开门 2-拒绝进入
    int nIsNormal;                      ///<是否正常输入
    char chHandleMan[128];              ///<处置人
    char chApplyType[512];              ///<认证模式
}TAGDOA_INFO_P, *PTAGDOA_INFO_P;

///<开门申请信息返回（409,612-out）
 typedef struct
{
    char chReturn[256];        ///< 执行增删改返回值(默认"1"为执行成功，反之为异常字串) 实际用来返回申请的时候传入的guid，相当于一个userdata
    int  nId;
}TAGDOA_INFO_S;

///<用户认证(410)
typedef struct
{
    char chUserName[64];                 ///<用户名
    char chPassword[256];                ///<密码
    int nDoShow;                         ///<悬浮窗是否显示 1-显示 0-不
}TAGDOA_USERINFO_P, *PTAGDOA_USERINFO_P;

///<认证动作日志表(411)
typedef struct
{
    int nId;                            ///<开门申请ID
    int nActType;                       ///<动作类性值
    char chActName[64];                 ///<动作名称
    char chAttachment[1024];            ///<附件
}TAGDOA_ATTACHMENT_P, *PTAGDOA_ATTACHMENT_P;

///<认证系统日志 (412)
typedef struct
{
    int nId;                            ///<开门申请ID
    char chActType[64];                 ///<操作名称
    char chActDate[32];                 ///<操作时间
    char chActPerson[64];               ///<操作人
}TAGDOA_APPLYACTLOG_P, *PTAGDOA_APPLYACTLOG_P;

///<认证处理意见(413)
typedef struct
{
    int nId;                              ///<开门申请ID
    char chContent[256];                 ///<处理意见
    char chProcessDate[32];              ///<处理时间
    char chProcessMan[64];               ///<处理人
}TAGDOA_PROCESSMEMO_P, *PTAGDOA_PROCESSMEMO_P;

///<刷卡信息(414)
typedef struct
{
    int nStatus;                         ///<刷卡状态 	1-合法2-不合法3-无效卡
    int nId;                             ///<设备ID
    char chCardNum[16];                  ///<卡号
    char chPersonId[32];                 ///<身份证号
    char chAccessDate[32];               ///<刷卡时间
}TAGDOA_LOG_P, *PTAGDOA_LOG_P;

///<班次(415)
typedef struct
{
    char chDeviceName[64];            ///<设备名称
    char chDate[10];                 ///<排班日期
    char chBeginDate[32];            ///<开始时间
    char chEndDate[32];              ///<结束时间
    char chIds[1000];                ///<排班人员ID串 $拼接
}TAGDOA_CLASSSCHEDULE_P, *PTAGDOA_CLASSSCHEDULE_P;

///<(416-in)
typedef struct
{
    char chUserName[64];            ///<用户姓名
}TAGDOAPPASSWORD_P;

///<(416-0ut)
typedef struct
{
    int nUserId;                     ///<用户ID
    char chUserName[64];             ///<用户姓名
    char chPassword[256];            ///<密码
    bool bDoShow;                    ///<是否显示悬浮窗
}TAGDOAPPASSWORD_S;

///<(420-0ut)
typedef struct  
{
    char chUserName[64];             ///<用户姓名
    char chHeadImage[64];            ///<头像
    char chId[64];                   ///<身份证
    char chWorkNum[16];              ///<工号
    int  nDepartmentId;              ///<部门编号
    int  nUserType;                  ///<状态\分类 1-内部 2-外部  
	char chCardNum[64];				///<卡号
    char chDepartmentName[64];		///<部门名称
    char chUserType[32];			///<用户类型
    char chBeginTime[20];			///<启用开始时间
    char chEndTime[20];				///<启用结束时间
    char chSex[10];					///<性别
    int nStatus;					///<人员状态
    int nId;						///<人员ID
	
}TAGDOAPERSONINFO_S;

///<(417-0ut)
typedef struct
{
    int nID;                    ///< 设备ID
    char chDevCode[64];         ///< 设备编码
    char chDevName[128];        ///< 设备名称
    char chDevIp[32];           ///< 设备IP地址
    char chAreaCode[64];        ///< 所在区域编码
    int nDeviceType;            ///< 设备类型(9、11、14)
    int nDevTypeID;             ///< 设备类型ID（品牌ID）
    char chDevModelNo[128];     ///< 设备型号
    char chDevManufacture[64];  ///< 品牌名称
    int nDevManufatureID;       ///< 品牌编号
    char chCenterNo[128];       ///< 中心编号
    char chFatherCenterNo[128]; ///< 父中心编号
    int nDevTypeCode;           ///< 设备类型编号（2*n）
    int nKeyPart;               ///< 部位
    BOOL bCanSpreak;            ///<能否对讲  （第三方认证里面用于判断是否是授权设备）
    BOOL bIsConnect;            ///<是否需要连接 （第三方认证里面用于判断是否是认证设备）
}TAGDOAACCESSINFO_S;   
 
///<查询认证历史信息(422-in)
typedef struct
{
    char chBeginDate[32];            ///<认证申请时间  开始
    char chEndDate[32];              ///<认证时间结束
    char chAreaName[64];             ///<区域名称
    int  nPassStatus;                ///<通行状态0-全部 1-同意开门 2-拒绝进入
    int  nProcessStatus;             ///<处理状态0-全部 1-未处置 2-处置中 3-待审核
    int  nIsCollection;              ///<是否收藏 0-全部 1-收藏 2-未收藏
    int  nIsNomal;                   ///<录入方式 0-全部 1-正常录入 2-非正常录入
    int  nMethod;                    ///<处置模式 0-全部
    int  nProcessType;               ///<审核状态 0-全部 1-通过(合格) 2-拒绝(不合格)
    int  nPages;                     ///<页数
    int  nRecords;                   ///<每页显示记录数
}TAGDOAHISTORYINFO_P;

///<查询认证历史信息(422,296-out)
typedef struct
{
    int  nId;                        ///<认证Id
    char chAreaName[64];             ///<区域名称
    char chDeviceName[64];           ///<门禁名称
    char chHappenDate[32];           ///<认证申请时间
    int  nMethod;                    ///<处理方式
    int  nProcessStatus;             ///<处理状态 1-未处置 2-处置中 3-待审核
    int  nProcessType;               ///<审核状态 1-通过(合格) 2-拒绝(不合格)
    int  nPassStatus;                ///<通行状态1-同意开门 2-拒绝进入
    char chHandleMan[128];           ///<处置人
    char chHandleDate[20];           ///<处置时间
    char chAuditor[128];             ///<审核人
    char chAuditDate[20];            ///<审核时间
    bool bIsCollection;              ///<是否收藏
    bool bIsNormal;                  ///<是否正常录入
    char chApplyType[128];           ///<认证模式
	int nProperty;                 ///< 锁定状态：0-解锁；1-锁定；
    int  nSumPage;                   ///<总页数
}TAGDOAHISTORYINFO_S;

///<查询认证历史详细信息-认证详情(423-out)
typedef struct
{
    int  nId;                            ///<认证Id
    char chDeviceName[64];               ///<门禁名称
    char chHappenDate[32];               ///<认证申请时间
    char chAreaName[64];                 ///<区域名称
    char chKeyPart[128];                 ///<部位名称
    char chContactPerson[128];           ///<联系人名称
    char chContactInfo[16];              ///<联系方式
    char chHandleMan[128];               ///<处置人
    char chRoleName[64];
    char chPSWQ[50];                     ///<手机
    char chPSWA[50];                     ///<邮箱
    char chHandleDate[20];               ///<处置时间
    char chAuditor[128];                 ///<审核人
    char chAuditDate[20];                ///<审核时间
    char chPlanName[64];
    bool bIsCollection;                  ///<是否收藏
    bool bIsNormal;                      ///<是否正常录入
    char chApplyType[128];               ///< 认证模式
    int  nMethod;                        ///<处理方式
    int  nProcessStatus;                ///<认证状态
    int  nProcessType_Int;              ///<审核状态
    int  nPassStatus_Int;               ///<通行情况
	int nProperty;				        ///< 锁状态：0-解锁；1-锁定；
}TAGDOAAPPLYDETAIL_S;

 ///<查询认证历史详细信息-操作列表(424-out)
typedef struct
{
    int nApplyId;                       ///<申请ID
    int nActType;                       ///<操作类型值
    char chActName[64];                 ///<操作类型名称
    char chAttachment[1024];            ///<附件
}TAGDOAATTACHMENT_S;

///<查询认证历史详细信息-预案步骤信息(425-in)
typedef struct
{
    int nApplyId;                       ///<申请ID
    int nActionNo;                      ///<操作编号
    int nSequence;                      ///<操作顺序
    char chActName[128];                ///<操作类型名称
    char chHandleMan[128];              ///<操作人
    char chDoBeginTime[32];
    char chDoEndTime[32];
    char chAttachment[1024];            ///<附件
    bool bDoSuccess;                    ///<是否执行成功 0-不成功1-成功
    bool bMustBeDone;                   ///<是否必须执行 1-是 0-否
    char chMemo[512];                   ///<备注，操作内容
    int  nProporty;                     ///<整形备用字段
    char chProporty[128];               ///<字符型备用字段
    char chLastModify_Date[32];         ///<最后修改时间
}TAGDOAACTIONDETAIL_S;

///<查询认证历史详细信息-认证处理意见列表(426-out)
typedef struct
{
    int nApplyId;                       ///<申请ID
    char chContent[256];                ///<处理意见
    char chProcessDate[32];             ///<处理时间
    char chProcessMan[64];              ///<处理人
}TAGDOAPROCESSMEMO_S;

///<查询认证历史详细信息-认证处理意见列表(427-out)
typedef struct
{
    int nApplyId;                       ///<申请ID
    char chActType[64];                 ///<操作类型
    char chActDate[32];                 ///<操作时间
    char chActPerson[64];               ///<执行人
}TAGDOAACTLOG_S;

///<查询认证历史详细信息-认证关联刷卡信息列表(428-in)
typedef struct
{
    int nId;                        ///<申请ID
}TAGDOADOORACCESSLOG_P;

///<查询认证历史详细信息-认证关联刷卡信息列表(428-out)
typedef struct
{
    int nApplyId;                        ///<申请ID
    char chDeviceName[64];               ///<门禁名称
    char chAreaName[64];                 ///<区域名称
    char chKeyPart[128];                 ///<部位名称
    char chCardNum[16];                  ///<卡号
    char chName[128];                    ///<姓名
    char chId[64];
    int  nUserType;                      ///<
    int  nStatus;                        ///<权限状态 1-合格 2-不合格 
    char chType[64];                     ///<分类
    char chWorkNum[16];                  ///<工号
    char chDepartment[32];               ///<部门
    char chAccessDate[32];               ///<刷卡时间
    ///<char chPersonId[32];               ///<身份证号
    char chMemo[512];                    ///<录入原因
}TAGDOADOORACCESSLOG_S;

 ///<查询刷卡历史信息(429-in)
 typedef struct
 {
     char chBeginTime[32];       ///<开始时间
     char chEndTime[32];         ///<结束时间
     char chAreaName[64];        ///<区域名称
     char chCompanyName[64];     ///<单位名称
     int  nStatus;               ///<权限状态0-全部 1-合格 2-不合格 3-无效
     char chWorkNum[16];         ///<工号
     char chPersonId[32];        ///<身份证号
     int  nPages;                ///<页数
     int  nRecords;              ///<每页显示记录数
     char chName[32];            ///<刷卡人姓名
 }TAGDOABYCARDINFO_P;

 ///<查询刷卡历史信息(429-out)
 typedef struct
 {
     char chName[32];                     ///<刷卡人姓名
     int  nUserType;                      ///<
     int  nStatus;                        ///<权限状态 1-合格 2-不合格
     char chType[64];                     ///<分类
     char chPersonId[32];                 ///<身份证号
     char chWorkNum[16];                  ///<工号
     char chDepartment[32];               ///<单位
     char chKeyPart[128];                 ///<部位名称
     char chAccessDate[32];               ///<刷卡时间
     char chAreaName[64];                 ///<区域名称
     char chMemo[512];                    ///<录入原因
     int  nSumPage;                       ///<总页数
     int  nApplyId;                       ///<认证ID
 }TAGDOABYCARDINFO_S;

///<查询统计信息(430-in)
 typedef struct
 {
     int  nStatisticsType;              ///<统计类型
     char chBeginTime[32];              ///<开始时间
     char chEndTime[32];                ///<结束时间
     char chAreaName[80000];            ///<区域名称  所选节点一下所有网点名称 按$拼接
     char chDepartment[64];             ///<单位名称
     char chPassStatus[8000];           ///<通行状态     通行状态值$串
     char chProcessStatus[8000];        ///<处理状态     处理状态值$串
     char chHandleMan[8000];            ///<处理人       处理人名$串
     int  nGraphType;                   ///<图表类型 1-折线图/柱状图 2-饼状图
 }TAGDOASTATISTICS_P;

 ///<查询统计信息(430-out)
 typedef struct
 {
     char chStatisticsTime[32];       ///< 时间
     char chStatisticsItem[128];      ///<统计项
     int  nNum;                       ///<数量
 }TAGDOASTATISTICS_S;

 ///<异常数卡信息插入(431-in)
 typedef struct
 {
     char chDeviceName[64];     ///<设备名称
     char chAreaName[64];       ///<区域名称
     char chKeyPart[128];       ///<关键部位名称
     char chCardNum[16];        ///<卡号
     char chName[128];          ///<姓名
     char chId[64];             ///<身份证号
     int  nUserType;            ///< 性质
     char chType[64];           ///<分类
     int nStatus;               ///<权限
     char chWorkNum[16];        ///<工号
     char chDepartment[32];     ///<部门
     char chAccessDate[32];     ///<刷卡时间
     char chMemo[512];          ///<录入原因
 }TAGDOAEXCEPINFO_P;

 ///<(432-out)
 typedef struct
{
    char chReturn[256];        ///< 执行增删改返回值(默认"1"为执行成功，反之为异常字串)
    int  nId;
}TAGDOAEXCEPINFO_S;

///<门禁设备主从关联（432-in）
 typedef struct
{
    char chDeviceCode[64];      ///< 主门禁编号
    char chDeviceName[50];      ///< 从门禁名称
}TAGDOACCESSRELATIONSET_S;

///<门禁设备主从关联（433-out）
 typedef struct
{
    int nMasterAccessId;      ///< 主门禁ID
	char chMasterName[50];	  ///< 主门禁名称
    int nSlaveAccessId;       ///< 从门禁ID
	char chSlaveName[50];	  ///< 从门禁名称
}TAGDOACCESSRELATION_S;

///<获取管控等级策略(434-out)
typedef struct
{
    int nLevelId;            ///<管控等级id
    int nLevelType;          ///<管控等级类型值
    char chLevelName[128];   ///<管控等级名称
    int nPlanId;             ///<管控策略id
    int nPlanType;           ///<管控策略类型值
    char chPlanName[64];     ///<管控策略类型名称
    int  nMethodId;          ///<管控策略策略值
    char chMethodName[64];   ///<管控策略策略名称
    int nSetItem1;            ///<设置属性整形1
    int nSetItem2;            ///<设置属性整形2
    int nSetItem3;            ///<设置属性整形3
    char chSetItem4[128];     ///<设置属性字符形1
    char chSetItem5[128];     ///<设置属性字符形2
}TAGCTRLEVELPLAN_S;

///<获取部门信息（435-out）
typedef struct
{
   int nId;                           ///<部门ID
   char chDepartMentName[20];         ///<部门名称
}TAGDOADEPARTMENTINFO_S;

///<策略设置项(438-out)
typedef struct
{
    int  nTypeId;             ///< 策略类型ID
    char chTypeName[64];      ///< 策略类型名称
    int  nMethodId;           ///< 策略ID
    char chMethodName[64];    ///< 策略名称
}TAGDOAPLANPROJECT_S;

///<查询管控策略信息(439-int)
typedef struct
{
    int nCondition;                ///< 条件: 0-全部,1-根据等级,2-根据场所、部位
    char chLevelName[32];          ///< 管控级别名
    char chPlace[64];              ///< 场所名称
    char chKeyPart[64];            ///< 关键部位名称
}P_NEW_SHOWMULCTRLLEVEL;

///<管控策略信息-设备的管控等级划分信息(439-out)
typedef struct
{
    int  nCtrlLevelNum;           ///< 管控级别数量
    char chLevelName[32];         ///< 管控级别名
    char chPlaceName[64];         ///< 场所名称
    char chKeyPartName[64];       ///< 部位名称
    char chDeviceName[64];        ///< 设备名称
    int  nLC_ID;                  ///< 记录编号
}S_NEW_SHOWMULCTRLLEVEL;

///<获取策略设置项配置信息(440-In)
typedef struct
{
    int  nId;                 ///<管控等级ID
}TAGDOAPLANPROJECTCONFIG_P;

///<获取策略设置项配置信息(440-out)
typedef struct
{
    int  nCtrlLevelId;        ///<管控等级ID
    int  nLevel;              ///<管控等级类型值
    char chLevelName[128];    ///<管控等级名称
    int  nControlStrategyId;  ///<管控策略ID
    int  nTypeId;             ///<策略类型ID
    char chTypeName[64];      ///<策略类型名称
    int  nMethodId;           ///<策略ID
    char chMethodName[64];    ///<策略名称
    int  nSetItem1;           ///<参数1
    int  nSetItem2;           ///<参数2
    int  nSetItem3;           ///<参数3
    char chSetItem4[128];     ///<参数4
    char chSetItem5[128];     ///<参数5
}TAGDOAPLANPROJECTCONFIG_S;

///<设置策略设置项配置信息(441-in)
typedef struct
{
    int  nCtrlLevelId;                ///<管控等级ID
    char chControlStrategyId[100];    ///<策略ID串 以$拼接
    char chSetItem1[1000];            ///<参数1
    char chSetItem2[1000];            ///<参数2
    char chSetItem3[1000];            ///<参数3
    char chSetItem4[2000];            ///<参数4  预案名称
}TAGDOAPLANPROJECT_P;

///<获取IP对讲设备信息(442-out)
typedef struct
{
    int nId;
    char chDeviceName[128];
    char chDeviceCode[128];
}TAGDOAIPTALKINFO_S;

///<获取IP对讲设备信息(443-in)
typedef struct
{
    char chDeviceCode[128];
}TAGDOAIPTALKPANELINFO_P;

///<获取IP对讲设备信息(443-out)
typedef struct
{
    int nId;
    char chFrontendName[128];
}TAGDOAIPTALKPANELINFO_S;

///<门禁对讲联动设置(444-in)
typedef struct
{
    char chDeviceCode[64];
    char chFrontendName[50];
}TAGDOAIPTALKACCESS_P;

///<门禁对讲联动获取（445-in）
typedef struct
{
    int nDevId; ///<门禁ID
}TAGDOAIPTALKACCESSGET_P;

///<门禁对讲联动获取（445-out）
typedef struct
{
    char chDeviceName[20];
    char chFrontendName[50];
}TAGDOAIPTALKACCESSGET_S;

///<管控等级划分设置（446-in）
typedef struct
{
    int  nContion;                     ///<条件：1-添加 2-删除
    char chLevelName[128];             ///<管控等级名称
    char chPlaceNames[1000];           ///<场所名称串
    char chKeyPartNames[1000];         ///<部位名称串
}TAGDOACTRLLEVELSET_P;

///<获取BSAPP版本信息（447-out）
typedef struct
{
    int nField1;      	///<版本字段1
	int nField2;		///<版本字段2
	int nField3;		///<版本字段3
	int nField4;		///<版本字段4
}BSAPPVERSIONGET_S;

///<配置客户端门禁主从关系获取（448-in）
typedef struct
{
    int nMasterId;                  ///<主门禁ＩＤ
}TAGDOQASSESSMSSCS_P;

///<配置客户端门禁主从关系获取（448-out）
typedef struct
{
    char chDeviceName[50];         ///<从门禁名称
}TAGDOQASSESSMSSCS_S;

///<获取位置信息，配置客户端右键使用（290-out）
typedef struct
{
    int nKeyPartID;				//部位ID
	int nKeyPartValue;			//部位值
	char chKeyPartName[50];		//部位名称
}POSITIONINFOGET_S_NEW;


///<资产信息相关操作：增加、修改、批量修改（500-in）
typedef struct
{
	int nCondition;					///<条件		 @note   1-增加；2-修改；3-批量修改
	char chDeviceCode[64];			///<设备编码   @note   原添加设备时生成的编码，condition=2,3时不传
	int nDeviceType;				///<设备类型 	 @note   1-主机;2-摄像机,condition=2,3时不传
	char chCapitalCode[8000];		///<资产编号   @note  （客户端传入）,批量修改时用$隔开,一次最多可传入100条信息
	char chSN[64];					///<SN码     @note   （备用，可空）
	char chManufactureName[128];	///<品牌		 @note   设备的品牌信息
	char chModelNo[128];			///<型号		 @note   设备的具体型号
	char chSupplierName[128];		///<供应商	 @note   设备的供应商
	char chSTName[128];				///<工程商	 @note   施工单位
	char chMaintenceName[128];		///<维保商	 @note   设备的维保公司
	int nMaintenceMonth;			///<维保月数	 @note   维保的时长，以月为单位
	char chMaintenceTele[32];		///<维保电话   @note   维保公司联系人电话
	char chStorageDate[20];			///<入库时间   @note   设备入库时间，只传入日期
	int nStatus;					///<资产状态   @note   1-正常使用；2-维修中；3-报废  (批量修改时不传)
 
}CAPITALINFOOPERATION_P;

	
///<巡检模板计划设置（501-in）
typedef struct
{
	int nModelType;				///<模板类型号  @note   客户端自行定义，对应即可  包括：主机状态、时钟状态、硬盘状态、通道状态
	char chBeginTime[10];		///<开始时间    @note   不包括日期 例如：12:13:59
	char chEndTime[10];			///<结束时间	  @note   不包括日期
	int nCycle;					///<周期值     @note   数字1-100等
	int nCycleType;				///<周期类型    @note   1-时；2-分
	char chSchedule[128];	    ///<周期星期    @note   每天，每周
	int nCheckDays;				///<检查值	  @note   录像完整性检查使用，值范围1-365
	bool bIsEnable;			    ///<是否启用    @note   是否生效
 
}DETECTSCHEDULESET_P;


///<故障报修信息插入（502-in）
typedef struct
{
	char chMalfunctionCode[64];   	///<故障单号    
	char chCapitalCode[64];			///<资产编号    @note  设备的资产信息编号
	char chDeviceType[64];			///<设备类型    @note  设备的类型，主机，摄像机等
	char chManufactureName[128];	///<品牌		  @note   设备的品牌
	char chModelNo[128];			///<型号		  @note   设备的具体型号
	char chFirstLevel[64];			///<总行       @note   设备所属的总行
	char chSecondLevel[256];		///<支行       @note   设备所属的支行，如果总行和网点之间有多个，用$拼接
	char chThirdLevel[128];			///<网点       @note   设备所属的网点
	char chMaintenceName[128];		///<维保商     @note    设备的维保单位
	char chMaintenceTele[32];		///<维保电话    @note   设备维保单位的联系电话
	char chFaultType[128];			///<故障类型    @note   设备的故障类型，网络掉线，硬盘损坏等
	char chFaultNames[1024];		///<故障现象    @note   蓝屏，无视频信号等
	char chDescribe[512];			///<描述       @note   对故障现象的具体描述
	int nStatus;					///<故障状态    @note   1-已修复；2-维修中；3-报废；
	char chHandleDate[20];			///<报修时间    @note   记录报修的时间
	char chHandleMan[64];			///<报修人      @note   记录报修的人
 
}MALFUNCTIONINSERT_P;


///<增加维修记录（503-in）
typedef struct
{
	int nMalfunctionId;			///<报修单ID    @note  故障记录ID
	char chMaintenceDate[20];		///<维修时间     @note  实际维修时间
	char chMemo[512];				///<备注        
	int nStatus;				///<维修状态     @note  1-已修复；2-维修中；3-报废；
	char chRecordMan[64];			///<记录人      @note   添加记录的人
 
}MAINTENCEINFOINSERT_P;


///<运维服务器相关操作：增，删，改（504-in）
typedef struct
{
	int nCondition;			    ///<操作条件         @note  1-插入；2-修改；3-删除；
	char chOMServerCode[30];	///<运维服务器编号    @note  运维服务器的编号
	char chName[64];			///<服务器名称	   @note   运维服务器名称
	char chPassword[64];		///<密码            @note   登录运维服务器的密码
	char chIP[32];				///<IP地址          @note   运维服务器ip地址
	char chMemo[512];			///<备注  
	char chUserName[64];		///<Conficlient
}OMSERVEROPERATION_P;


///<巡检模板设置：插入，修改（505-in）
typedef struct
{
	int nCondition;				///<条件			@note   1-插入；2-修改；3-删除
	int nModuleId;				///<模板ID		@note   巡检模板ID，数据库生成，删除时使用
	char chModuleName[128];		///<模板名称		@note   巡检模板的名称
	char chWeekdays[128];		///<星期拼接字符串，用$分割		@note  星期拼接字符串，用$分割，如：星期一$星期二
	bool bIsEnable;			    ///<是否启用
	char chCreateMan[64];		///<创建人
	char chCreateDate[20];		///<创建日期
	char chTypes[8000];			///<时间段类型字符串，1-布防；2-撤防		@note  时间段类型字符串，1-布防；2-撤防  如：1$2$
	char chSequences[8000];		///<时间段顺序串		@note  时间段按顺序拼接的字符串  如：00:00:00-23:59:59$
	char chBeginTimes[8000];	///<开始时间串，用$拼接   @note  开始时间串，用$拼接
	char chEndTimes[8000];		///<结束时间串，用$拼接   @note  结束时间串，用$拼接
	char chTerminalIds[8000];	///<主机ID串，用$拼接    @note  主机ID串，用$拼接
	char chPartitionses[8000];	///<分区串，用$拼接，目前可为空    @note  分区串，用$拼接，目前可为空
	char chUserName[128];		///<Configclient
}DETECTMODULEOPERATION_P;


///<通道检查模板相关操作:添加，修改（506-in）
typedef struct
{
	int nCondition;				///<条件               @note  1-添加；2-修改；3-删除
	int nModuleId;				///<通道巡检模板ID		  @note  通道巡检模板ID,数据库生成，删除时使用
	char chModuleName[128];		///<通道巡检模板名称     @note   通道巡检模板名称
	int nDays;					///<应存储的天数		  @note  要巡检的通道，需要存储的天数
	char chCreateMan[64];		///<创建人
	char chCreateDate[20];		///<创建日期
	char chFrontendIds[8000];	///<通道ID串，用$拼接    @note  要巡检的通道ID串，用$拼接
	char chUserName[128];
}CHANNELDETECTMODULEOPERATION_P;


///<运维服务器划分（507-in）
typedef struct
{
	int nCondition;					///<条件：1-先清空再设置；2-追加
	char chOMServerName[64];		///<运维服务器名称    @note  运维服务器名称
	char chDeviceNames[8000];		///<设备名称串，用$拼接   @note  设备名称串，用$拼接,每次操作不能超过100台
	char chUserName[128];
}OMSERVERDIVIDESET_P;


///<故障现象相关操作（508-in）
typedef struct
{
	int nCondition;				///<条件           @note  1-增加；2-修改；3-删除;
	int nFaultInfoId;			///<故障现象ID	  @note  故障现象ID,数据库生成，删除时使用
	char chFaultName[128];		///<故障现象名称	  @note  故障现象名称
	int nFaultType;				///<故障类型值      @note  故障类型值 
	char chSetMan[128];			///<设置人         @note  故障现象设置人
	char chSetDate[20];			///<设置时间       @note  故障现象设置时间
	bool bIsEnable;				///<是否启用
	char chUserName[128];
}FAULTINFOOPERATION_P;

///<获取设备品牌信息（只包含资产信息中存在的）(544-in)
typedef struct
{
	int nCondition;				///<条件：    @note  nCondition=3,获取资产信息中存在的设备型号
}DEVICEMANUFACTUREINFOINCAPITALGET_S;
	
///<获取设备品牌信息(509-out，544-out)
typedef struct
{
	char chManufactureName[128];  ///<品牌名称    @note  设备品牌名称
}DEVICEMANUFACTUREINFOGET_S;

///<获取型号信息(510-in)
typedef struct
{
	int nCondition;					///<条件   @note 0-查询所有；1-根据品牌查询；3-获取资产信息中存在的
	char chManufactureName[128];    ///<品牌名称    @note  设备品牌名称
}DEVICEMODELINFOGET_IN_P;

///<获取型号信息(510-out)
typedef struct
{
	char chModelName[128];  ///<型号名称   @note  设备型号名称
}DEVICEMODELINFOGET_OUT_S;

///<获取供应商信息(511-out)
typedef struct
{
	char chSupplierName[128];  ///<供应商名称   @note  设备供应商名称
}SUPPLIERINFOGET_S;

///<获取维保商信息(512-out)
typedef struct
{
	char chMaintenceCompany[128];  ///<维保商名称   @note  设备供应商名称
}MAINTENCECOMPANYGET_S;

///<获取工程商信息(513-out)
typedef struct
{
	char chEngineeringInfo[128];  ///<工程商名称   @note  设备安装单位名称
}ENGINEERINGINFOGET_S;


///<获取获取设备基础信息(514-in)
typedef struct
{
	char chDeviceType[100];			///<设备类型
	char chManufactureName[128];	///<品牌
	char chModelNo[128];			///<型号
	char chSupplierName[128];		///<供应商
	char chMaintenceName[128];		///<维保商
	char chSTName[128];				///<工程商
	char chStorageDateBegin[20];	///<入库开始时间
	char chStorageDateEnd[20];		///<入库结束时间
	char chAreaName[64];			///<所属网点
	char chMaintenceTele[32];		///<维保电话
	char chStatus[100];				///<使用状态
	int nPage;						///<当前页数
	int nNumberPerPage;				///<每页条数	
}DEVICEBASEINFOGET_IN_P;

///</<获取获取设备基础信息(514-out)
typedef struct
{
	char chCapitalCode[64];			///<资产编号
	char chDeviceCode[64];			///<设备编码
	char chDeviceType[100];			///<设备类型
	char chAreaName[64];			///<所属网点
	char chManufactureName[128];	///<品牌
	char chModelNo[128];			///<型号
	char chStorageDate[20];			///<入库时间
	char chSupplierName[128];		///<供应商
	char chSTName[128];				///<工程商
	char chMaintenceName[128];		///<维保商
	int nMaintenceMonth;			///<维保月数
	char chMaintenceTele[32];		///<维保电话
	char chStatus[100];				///<使用状态
	int nTotalNum;					///<总条数	
}DEVICEBASEINFOGET_OUT_S;


///<报修记录信息查询(515-in)
typedef struct
{
	char chDeviceType[64];			///<设备类型
	char chManufactureName[128];	///<品牌
	char chModelNo[128];			///<型号
	char chThirdLevel[128];			///<所属网点
	char chStatus[128];				///<维修状态
	char chHandleDateBegin[20];		///<报修开始时间
	char chhandleDateEnd[20];		///<报修结束时间
	int nPage;						///<当前页数
	int nNumberPerPage;				///<每页条数
}MALFUNCTIONINFOGET_IN_P;

///</</<报修记录信息查询(515-out)
typedef struct
{
	int nId;						///<报修单ID
	char chMalfunctionCode[64];		///<报修单号
	char chCapitalCode[64];			///<资产编码
	char chDeviceType[64];			///<设备类型
	char chManufactureName[128];	///<品牌
	char chModelNo[128];			///<型号
	char chThirdLevel[128];			///<所属网点
	char chHandleDate[20];			///<报修时间
	char chHandleMan[32];			///<报修人
	char chFaultNames[1024];		///<故障名，用$分割
	char chDescribe[128];			///<故障描述
	char chStatus[128];				///<维修状态
	int nTotalNum;					///<总条数
}MALFUNCTIONINFOGET_OUT_S;

///<获取故障现象(516-out)
typedef struct
{
	char chFaultName[128];  ///<故障现象
}FAULTNAMEGET_S;

///<维修记录信息获取(517-in)
typedef struct
{
	int nId;					///<报修单ID
}MAINTENCEINFOIN_P;

///<维修记录信息获取(517-out)
typedef struct
{
	int nId;					///<报修单ID
	char chMaintenceDate[128];	///<维修时间
	char chMemo[256];			///<备注
	char chMaintStatus[128];	///<维修状态
	char chRecordMan[64];		///<记录人
}MAINTENCEINFOGET_S;

///<获取维保商信息包含电话(518-out)
typedef struct
{
	char chMaintencePhone[32];		///<维保商电话
}MAINTENCEINFOPHONE_S;

///<报警主机布撤防计划获取(519-out)
typedef struct
{
	int nModelId;			///<模板ID	
	char chModelName[128];	///<模板名称
	char chWeekdays[128];	///<启用星期串 配置客户端自行拼接拆分
	bool bIsEnable;			///<是否启用
	int nType;				///<时间类型 1-布防 2-撤防
	int nSequence;			///<时间段顺序
	char chBeginTime[20];	///<开始时间
	char chEndTime[20];		///<结束时间
	int nAlarmId;			///<报警主机ID
	char chDeviceName[64];	///<报警主机名称
	char chPartitions[128];	///<分区串（暂时不用）
}ALARMARMDISARMPLAN_S;

///<设备基本信息统计(520-in)
typedef struct
{
	int nStatisticsType;			///<1-设备类型 2-设备型号 3-设备品牌 4-区域 5-供应商 6-设备状态 7-工程商 8-维保商
	int nGraphType;					///<1-线图 2-饼图 柱状图，次参数目前客户端不用，app默认值传2,或者不调用就可以了
	char chDeviceTypes[1000];		///<设备类型名称串 $拼接
	char chModelNos[8000];			///<设备型号名串 $拼接
	char chManufactureNames[8000];	///<品牌名串 $拼接
	char chAreaNames[8000];			///<区域名称串 $拼接
	char chSupplierNames[8000];		///<供应商名称串 $拼接
	char chStatuses[1000];			///<设备状态名称串 $拼接
	char chSTNames[8000];			///<工程商名称串 $拼接
	char chMaintenceNames[8000];	///<维保商名称串 $拼接
	char chStorageDateBegin[20];	///<入库时间开始
	char chStorageDateEnd[20];		///<入库时间结束
}CAPITALINFOSTATISTICS_IN_P;

///<设备基本信息统计(520-out)
typedef struct
{
	char chStatisticsType[128];	///<统计项
	int nTotal;					///<数量
}CAPITALINFOSTATISTICS_OUT_S;

///<故障信息统计(521-in)
typedef struct
{
	int nStatisticsType;			///<1-设备类型 2-设备品	牌 3-设备型号 4-区域 5-设备状态
	int nGraphType;					///<1-线图 2-饼图 柱状图
	char chDeviceTypes[1000];			///<设备类型名称串 $拼接
	char chManufactureNames[8000];		///<品牌名称串 $拼接
	char chModelNos[8000];				///<型号名称串 $拼接
	char chThirdLevels[8000];			///<区域名称串 $拼接
	char chStatuses[1000];				///<状态名称串 $拼接 客户端暂时不用 传入’’或者不赋值
	char chHandleMans[1000];			///<报修人名称串 $拼接
	char chHandleDateBegin[20];		///<报修时间开始
	char chHandleDateEnd[20];		///<报修时间结束
}MALFUNCTIONINFOSTATISTICS_IN_P;

///<故障信息统计(521-out)
typedef struct
{
	char chStatisticsType[128];	///<统计项
	char chStatisticsDate[20];	///<时间	GraphType为1时返回
	int nTotal;					///<数量
}MALFUNCTIONINFOSTATISTICS_OUT_S;

///<主机使用状态获取(522-out)
typedef struct
{
	int nDeviceId;					///<设备编号
	int nStatus;					///<使用状态   @note  1-正常使用；2-维修中；3-报废
}HOSTUSESTATUSGET_S;

///<探头使用状态获取(523-out)
typedef struct
{
	int nDeviceId;					///<设备编号
	int nStatus;					///<使用状态   @note  1-正常使用；2-维修中；3-报废
}DETECTORUSESTATUSGET_S;

///<获取巡检计划(524-out)
typedef struct
{
	int nType;				///<巡检计划类型 1-主机状态 2-时钟状态  3-硬盘状态 4-通道状态 5-录像完整性
	char chBeginTime[20];	///<开始时间
	char chEndTime[20];		///<结束时间
	int nCycle;				///<刷新时间
	int nCycleType;			///<刷新时间单位
	bool bWeekDays[7];		///<执行规则
	int nCheckDays;			///<检查项
	bool bIsEnable;		    ///<是否启用
}DETECTSCHEDULEGET_S;

///<获取模板总览信息(525-out)
typedef struct
{
	char chModuleName[64];		///<模板名称
	char chModuleType[64];		///<模板类型
	char chCreateMan[64];		///<创建人
	char chCreateDate[20];		///<创建时间
}MODULEINFOGET_S;

///<根据设备编号获取设备基本信息_客户端(526-in)
typedef struct
{
	char chCapitalCode[64];		///<资产编码
}DEVICEBASEINFOBYIDGET_CLIENT_P;

///<根据设备编号获取设备基本信息_配置客户端(527-in)
typedef struct
{
	int nDeviceType;		    ///<设备表类型   @note  区分数据库表
	int nDeviceId;				///<设备ID
	
}DEVICEBASEINFOBYIDGET_SOFTSET_P;

///<根据设备编号获取设备基本信息(526,527-out)
typedef struct
{
	int nDeviceId;					///<设备ID
	int nDeviceType;				///<设备类型
	char chCapitalCode[64];			///<资产编号
	char chNodeName[32];			///<设备类型名称
	char chManufactureName[128];	///<品牌
	char chModelNo[128];			///<型号
	char chSupplierName[128];		///<供应商
	char chStorageDate[20];			///<入库时间
	char chSTName[128];				///<工程商
	char chMaintenceName[128];		///<维保商
	int nMaintenceMonth;			///<维保月数
	char chMaintenceTele[32];		///<维保电话
	char chStatus[100];				///<使用状态
}DEVICEBASEINFOBYIDGET_S;


///<OM服务器名称(528,532,534-in)
typedef struct
{
	char chOMName[32];   ///<OM服务器名称
	
}OMSERVERNAME_P;

///<获取OM设备信息(528-out)
typedef struct
{
	int nDeviceId;				///<设备ID
	char chDeviceName[40];		///<设备名称
	char chDeviceCode[20];		///<设备编码
	char chIP[20];				///<IP地址
	char chUpperNode[20];		///<上级节点编码
	int nPortNo;				///<端口号
	int nDeviceType;			///<设备类型
	char chManufactureName[32];	///<设备厂家名称
	int nManufactureCode;		///<设备厂家编号
	char chModelNo[32];			///<设备型号
	char chUserName[20];		///<登录用户名
	char chPassword[35];		///<登录密码
	bool bIsConnected;			///<是否需要连接
	
}OMDEVICEINFOGET_S;


///<获取OM通道信息划分(529-in)
typedef struct
{
	int nCondition;		 ///<条件：（0，预留）
	char chOMName[32];   ///<OM服务器名称
	
}OMCHANNELINFODIVIDEGET_P;

///<获取OM通道信息划分(529-out)
typedef struct
{
	int nChannelId;				///<通道ID
	char chChannelName[32];		///<通道名称
	int nChannelNo;				///<通道号
	int nChannelType;			///<通道类型
	int nDeviceId;				///<所属设备ID
	
}OMCHANNELINFODIVIDEGET_S;


///<显示OM分区信息(530-in)
typedef struct
{
	int nCondition;		 ///<条件：（0，预留）
	char chOMName[32];   ///<OM服务器名称
	
}OMPARTATIONINFOGET_P;

///<显示OM分区信息(530-out)
typedef struct
{
    int nDevID;                 	    ///<设备ID
    char chDevName[32];          		///<设备名
	int nPartNum;                 		///<分区数目
	PartionInformation Part[33];		///<分区详细信息 
	
}OMPARTATIONINFOGET_S;

typedef struct
{
	char chBeginTime[20];	///<开始时间
	char chEndTime[20];		///<结束时间
	
}TimeModule;

///<OM获取布撤防模板(531-out)
typedef struct
{
	int nModelId;				///<模板ID
	char chModelName[32];		///<模板名称
	bool bWeekDays[7];			///<星期
	int nArmTimeCount;			///<布防时间段数量
	int nDisArmTimeCount;		///<布防时间段数量
	TimeModule arrArm[6];		///<布防时间段
	TimeModule arrDisArm[6];	///<撤防时间段
	
}OMARMDISARMMODULEGET_S;

///<OM获取分区布撤防计划(532-out)
typedef struct
{
	int nDeviceId;	///<设备ID
	int nModuleId;	///<模板ID
	
}OMARMDISARMSCHEDULEGET_S;

///<OM获取录像天数模板(533-out)
typedef struct
{
	int nModuleId;			///<模板ID
	char chModuleName[32];	///<模板名称
	int nRecordDays;		///<录像天数
	
}OMRECORDDAYSMODULEGET_S;

///<OM获取录像天数模板(534-out)
typedef struct
{
	int nChannelId;	///<通道ID
	int nModuleId;	///<模板ID
	
}OMCHANNELRECORDDAYSGET_S;


///<获取故障信息详情(535-out)
typedef struct
{
	int nId;				///<故障现象ID
	char chFaultName[128];	///<故障现象名称
	char chSetDate[20];		///<录入日期
	char chSetMan[32];		///<录入人
	bool bIsEnable;		///<是否启用
	int nFaultType;			///<故障类型
	
}FAULTINFODETAILGET_S;

///<AS获取分区布撤防计划(536-in)
typedef struct
{
	char chASName[32];   ///<AS服务器名称
	
}ASARMDISARMSCHEDULEGET_P;

///<AS获取分区布撤防计划(536-out)
typedef struct
{
	int nDeviceId;	///<设备ID
	int nModuleId;	///<模板ID
	
}ASARMDISARMSCHEDULEGET_S;


///<报警主机布撤防计划获取通过ID(537-out)
typedef struct
{
	int nModuleId;	///<模板ID
	
}ALARMARMDISARMPLANBYID_P;

///<报警主机布撤防计划获取通过ID(537-out)
typedef struct
{
	int nModelId;			///<模板ID	
	char chModelName[128];	///<模板名称
	char chWeekdays[128];	///<启用星期串 配置客户端自行拼接拆分
	bool bIsEnable;			///<是否启用
	char chType[1024];		///<时间类型 1-布防 2-撤防:用$拼接
	char chSequence[1024];	///<时间段顺序:用$拼接
	char chBeginTime[8000];	///<开始时间:用$拼接
	char chEndTime[8000];	///<结束时间:用$拼接
	char chAlarmId[8000];	///<报警主机ID:用$拼接
	char chDeviceName[8000];	///<报警主机名称:用$拼接
	char chPartitions[8000];	///<分区串（暂时不用）:用$拼接
	
}ALARMARMDISARMPLANBYID_S;

///<配置客户端获取巡检模板信息(538-out)
typedef struct
{
	int nModuleId;			///<模板ID
	char chMuduleName[32];	///<模板名称
	bool bIsEnable;			///<是否启用
	char chCreateMan[32];	///<创建人
	char chCreateDate[20];	///<创建日期
	
}DETECTMODULEINFOGET_S;


///<获取划分给巡检服务器的设备信息(539-in)
typedef struct
{
	char chOMName[32];   ///<OM服务器名称
	
}OMSERVERDIVIDEINFOGET_P;

///<获取划分给巡检服务器的设备信息(539-out)
typedef struct
{
	int nDeviceId;			///<设备ID
	char chDeviceName[64];	///<设备名称
	
}OMSERVERDIVIDEINFOGET_S;

///<获取OM服务器信息(540-in)
typedef struct
{
	char chOMName[32];   ///<OM服务器名称
	
}OMSERVERINFOGET_P;

///<获取OM服务器信息(540-out)
typedef struct
{
	char chOMName[32];		///<OM服务器名称
	char chPassword[64];	///<登录密码
	char chIP[20];			///<IP地址
	
}OMSERVERINFOGET_S;

///<配置客户端获取所有OM信息(541-out)
typedef struct
{
	int nOMId;					///<OM服务器ID
	char chOMServerCode[32];	///<OM服务器编号
	char chOMServerName[32];	///<OM服务器名称
	char chOMPassword[64];		///<OM服务器密码
	char chOMIPAddr[20];		///<OM服务器IP地址
	char chOMMemo[128];			///<OM服务器备注
	
}ALLOMINFOSOFTSETGET_S;

///<根据录像天数模板ID获取关联摄像头(542-in)
typedef struct
{
	int nModuleId;   ///<录像天数模板ID
	
}SOFTSETCHANNELRECORDDAYSGET_P;


///<根据录像天数模板ID获取关联摄像头(542-out)
typedef struct
{
	int nChannelId;	///<通道ID
	int nModuleId;	///<模板ID
	
}SOFTSETCHANNELRECORDDAYSGET_S;


///<报警服务器获取设备信息通过设备状态(543-in)
typedef struct
{
	int nCondition;   ///<1-查询主机，2-查询摄像头
	int nStatus;	  ///<0-全部状态，1-正常使用，2-维修中，3-报废
	
}ASDEVICEINFOBYSTATUSGET_P;


///<报警服务器获取设备信息通过设备状态(543-out)
typedef struct
{
	int nTerminalId;	///<终端ID	nCondition=2时有值
	int nDeviceID;		///<设备ID  nCondition：1-主机ID，2-摄像头ID
	int nChannelNo;		///<通道号	nCondition=2时有值
	int nStatus;		///<使用状态
	
}ASDEVICEINFOBYSTATUSGET_S;


///< 报警插入_NEW(600-in)
typedef struct
{
    int nDeviceID;             ///< 设备ID
    int nChannelNo;            ///< 通道号
    int nAID;                  ///< 报警类型ID
    int nLevel;                ///< 报警等级值
    int nStstus;               ///< 报警状态
    char chMemo[128];          ///< 备注
    char chName[64];           ///< 处置人
    TJTY_TIME tTime;           ///< 报警时间
	char chGUID[128];		   ///< 报警服务器生成唯一ID
}P_ALARMDISPOSAL_ASSINGLE_SET_NEW;

///< 报警联动存储文件锁定、解锁(601-in)
typedef struct
{
    char chGUIDs[8000];		  ///<要锁定、解锁的ID,1-报警处置；2-主动巡查；3-三方认证；
									///<类型ID$对应ID值$；例如：1$100$101$
	bool bIsLocked;			  ///<是否锁定：1-锁定；0-解锁
		
}ALARMSTORAGEFILELOCKED_SET_P;

///< 媒体存储文件信息写入(602-in)
typedef struct
{
	char chFileCode[10];	// 文件编码
	long nDevID;            // 设备ID
	int nChannel;           // 通道号
	char chFileName[50];    // 录像文件名
	char chFilePath[250];   // 录像文件路径
	char chBeginTime[64];	// 开始时间
	char chEndTime[64];  	// 结束时间
	char chLastRead[20];    // 最后读取时间
	int nReadTimes;			// 读取次数
	int nDateType;			// 数据类型
	int nAlarmType;      	// 报警类型
	int nAlarmLevel;        // 报警级别
	bool bIsLocked;		    // 是否锁定
	char chMemo[500];		// 备注
	int nStorageType;		// 存储类型:1-视频 ;2-图片 ;3-音频
	int nStorageModule;		// 存储模块:1-报警处置;2-日常巡查;3-门禁认证
	char chGUID[128];	    // GUID
		
}MEDIASTORAGEFILEINFO_INSERT_P;


///< 报警类型增加、修改_NEW(603-in)(add、mod)
typedef struct
{
    int  nCondition;                ///< 条件:1-add,2-mod
    int nID;                        ///< 编号
    int nAC;                        ///< AC编号
    char strTypeName[64];           ///< 类型名
    char strTimeStart[64];          ///< 开始时间
    char strTimeEnd[64];            ///< 结束时间
    char strSound[256];             ///< 报警声音
    int  ConfigSequence;            ///< 报警时间段ID
    int  nPriority;                 ///< 报警优先级
    int  bFliter;                   ///< 是否过滤
    int  nFliterTimeInterval;       ///< 过滤时间间隔
    int  bWord;                     ///< 是否过滤文字
    int  bVideoStore;               ///< 是否联动存储
    int  nVideoStoreTime;           ///< 视频存储时间
    int  bAlarmInfoStore;           ///< 报警信息是否存储
	bool bDoCapture;				///< 是否抓图
	int nCaptureCount;				///< 抓图数量
	
}ALARMTYPEOPERATION_NEW_P;

///< 清盘策略设置(604、606、607-IN)
typedef struct
{
	int nModuleType;			//模块类型：1-报警处置；2-日常巡查；3-门禁认证
	int nStorageType;			//存储类型：1-视频；2-图片；3-音频
	int nStorageDays;			//存储天数
	bool bIsEnable;	            //是否启用
	
}CLEANDISKSTORAGE_SET_P;

///< 清盘策略设置获取(605-out)
typedef struct
{
	int nModuleType;			//模块类型：1-报警处置；2-日常巡查；3-门禁认证
	int nStorageType;			//存储类型：1-视频；2-图片；3-音频
	int nStorageDays;			//存储天数
	bool bIsEnable;	            //是否启用
	char chModuleDesc[16];		//模块类型描述
	char chStorageTypeDesc[8];	//存储类型描述
	
}CLEANDISKSTORAGE_GET_S;


///< 获取要删除的文件信息(607-out)
typedef struct
{
	char chFileName[50];		//文件名称
	char chFilePath[250];		//文件路径
	
}DELETEFILEINFO_GET_S;


///< 获取报警配置_NEW(608-out)
typedef struct
{
    int nID;                        ///< 报警编号
    int nAC;                        ///< AC编号
    char strTypeName[64];           ///< 类型名
    int  ConfigSequence;            ///< 时间段
    char strTime[64];               ///< 起始时间
    bool  bWord;                    ///< 是否过滤文字
    bool  bVideoStore;              ///< 是否联动存储
    int  nVideoStoreTime;           ///< 视频存储时间
    bool  bFliter;                  ///< 是否过滤
    int  nFliterTimeInterval;       ///< 过滤时间间隔
    bool  bAlarmDeal;               ///< 报警是否处理
	bool bDoCapture;				///< 是否抓图
	int nCaptureCount;				///< 抓图数量
	
}ALARMCONFIG_GET_NEW_S;


///<报警消息处理
typedef struct
{
    int nFiltrateFlag;  			///<0：不过滤；1：过滤；2：不处理
    int nInterval;      			///<过滤间隔，单位为秒
    unsigned char ucIsSaveText;		///<是否存储报警文字，1:存储；0:不存储
    unsigned char ucIsSaveVideo;	///<是否联动视频存储，1:联动；0:不联动
    int nSaveTime;               	///<存储时长（S）
	bool bDoCapture;		        ///<是否启用抓图
    int nCaptureCount;              ///<抓图数量
}T_ALARM_DEALINFO_NEW;


///<报警服务器获取报警处置策略信息_NEW(609)
typedef struct
{
    int nAlarmType;  						///<报警类型
	char chAlarmTypeName[128];      		///<报警类型名
    T_ALARM_TIMESEGMENT TimeSegment[6];		///<时间段
    T_ALARM_DEALINFO_NEW T_AlarmDeal[6]; 	///<报警处理详情
}ALARMDEALSTRATEGY_GET_NEW;

///<客户端获取媒体存储的附件(610-in)
typedef struct
{
    int nCondition;      ///< 1-根据GUID查询报警处置关联附件；2-根据AlarmId查询报警处置关联附件；3-根据任务执行ID查询日常巡查关联附件；4-根据认证ID查询三方认证关联附件；
	char chGUID[64];	 ///< GUID
	int nAlarmId;		 ///< 报警ID
	
}CLIENTGETMEDIASTORAGEATTACHMENT_P;

///<客户端获取媒体存储的附件(610-out)
typedef struct
{
	char chDeviceName[128];	///<设备ID
	int nChannelNum;		///<通道号
	char chFileName[50];	///<文件名
	char chFilePath[250];	///<文件路径
	char chBeginDate[64];	///<开始时间
	char chEndDate[64];		///<结束时间
	int nDateType;			///<数据类型：1-视频 ;2-图片 ;3-音频(老接口使用)
	int nStorageType;		///<存储类型：1-视频 ;2-图片 ;3-音频
	int nStorageModule;		///<存储模块：1-报警处置;2-日常巡查;3-门禁认证
	char chGUID[64];		///<报警生成的GUID
	
}CLIENTGETMEDIASTORAGEATTACHMENT_S;

///< 主动巡查任务执行插入_NEW(611-in)
typedef struct
{
    int nTaskDistributeId;                ///< 任务下发ID
    char chAreaName[64];                  ///< 具体网点名称
    int nDoError;                         ///< 异常类型值
    bool bDoCarry;                        ///< 是否为关注任务巡检
    char chBeginTime[32];                 ///< 开始巡检时间
    char chError[512];                    ///< 异常$串
    char chOperate[512];                  ///< 操作$串
    char chAnnex[2048];                   ///< 附件
    char EPlanName[128];                  ///< 预案名称
    bool bIsQualified;                    ///< 是否合格
    char chReadRecord[8000];              ///< 批阅记录
    char chMemo[512];                     ///< 备注
    char chActionNos[8000];               ///< 处理步骤编号$串
    char chActionNames[8000];             ///< 处理步骤名称$串
    char chHandleMans[8000];              ///< 处理人$串
    char chDoBeginTimes[8000];            ///< 开始处理时间$串
    char chDoEndTimes[8000];              ///< 结束处理时间$串
    char chAttachments[8000];             ///< 附件$串
    char chDoSuccesses[8000];             ///< 是否执行成功$串
    char chMemos_VarC[8000];              ///< 备注$串
	char chTerminalIds[4000];			   ///<终端ID，用$分割
    char chChannelNos[2000];			   ///<通道ID，用$分割
    char chBeginTimes[8000];			   ///<开始时间，用$分割
    char chEndTimes[8000];				   ///<结束时间，用$分割
	char chTaskGUID[128];				   ///<任务GUID(客户端生成)
}P_NEW_INSPECT_TASKEXCUTESET_NEW;

///<开门申请信息插入_NEW(612-in)
typedef struct
{
    char chDeviceName[64];              ///<设备名称
    char chAreaName[64];                ///<所在网点名称
    char chKeyPart[128];                ///<部位名称
    char chContactPerson[128];          ///<联系人名称
    char chHappenDate[32];              ///<触发时间
    char chContactInfo[16];             ///<联系方式
    int nMethod;                        ///<处置方式
    char chPlanName[128];               ///<预案名称
    int nProcessType;                   ///<审核状态	1-通过 2-拒绝
    int nProcessStatus;                 ///<认证状态值 1-未处 2-处置中 3-待审核 4-已处理 5-已失效
    int nIsCollection;                  ///<是否收藏 1-收藏 0-不
    int nPassStatus;                    ///<通行情况	1-同意开门 2-拒绝进入
    int nIsNormal;                      ///<是否正常输入
    char chHandleMan[128];              ///<处置人
    char chApplyType[512];              ///<认证模式
	char chDoorGUID[128];				///<认证GUID(客户端生成)
}TAGDOA_INFO_P_NEW;

///<获取用户门禁摄像机关联-配置客户端(449-in)
typedef struct
{
	char chDeviceCode[64];		///<门禁设备编码
	
}USERDOORCAMERARELATION_GET_P;

///<获取用户门禁摄像机关联-配置客户端(449-out)
typedef struct
{
	char chDoorCode[64];		///<门禁设备编码
	char chUserName[128];		///<关联的用户名称
	char chCameraName[128];		///<关联的摄像机名称
	bool bIsEnable;				///<是否启用
	
}USERDOORCAMERARELATION_GET_S;


 ///<查询刷卡历史信息_NEW(450-in)
 typedef struct
 {
     char chBeginTime[32];       ///<开始时间
     char chEndTime[32];         ///<结束时间
     char chAreaName[64];        ///<区域名称
     char chCompanyName[64];     ///<单位名称
     int  nStatus;               ///<权限状态0-全部 1-合格 2-不合格 3-无效
     char chWorkNum[16];         ///<工号
     char chPersonId[32];        ///<身份证号
     int  nPages;                ///<页数
     int  nRecords;              ///<每页显示记录数
     char chName[32];            ///<刷卡人姓名
	 char chContrlLevel[32];	 ///<管控等级
 }TAGDOABYCARDINFO_NEW_P;

 ///<查询刷卡历史信息_NEW(450-out)
 typedef struct
 {
     char chName[32];                     ///<刷卡人姓名
     int  nUserType;                      ///<
     int  nStatus;                        ///<权限状态 1-合格 2-不合格
     char chType[64];                     ///<分类
     char chPersonId[32];                 ///<身份证号
     char chWorkNum[16];                  ///<工号
     char chDepartment[32];               ///<单位
     char chKeyPart[128];                 ///<部位名称
     char chAccessDate[32];               ///<刷卡时间
     char chAreaName[64];                 ///<区域名称
     char chMemo[512];                    ///<录入原因
     int  nSumPage;                       ///<总页数
     int  nApplyId;                       ///<认证ID
	 char chContrlLevel[32];	 		  ///<管控等级
 }TAGDOABYCARDINFO_NEW_S;

///<获取用户门禁摄像机关联-客户端(451-out)
typedef struct
{
	int nDoorId;			///<门禁设备ID
	char chUserName[128];	///<关联的用户名称
	int nDeviceId;			///<关联的摄像头所属设备ID
	int nChannelNo;			///<关联的摄像头通道号
	int nCenterNo;			///<中心编号
	
}USERDOORCAMERARELATION_CLIENT_GET_S;

 ///<用户门禁摄像机关联设置(452-in)
 typedef struct
 {
	char chDoorCode[64];		///<门禁设备编码
	char chUserName[128];		///<关联的用户名称
	char chCameraName[128];		///<关联的摄像机名称
	bool bIsEnable;				///<是否启用
	
 }USERDOORCAMERARELATION_SET_P;


///<获取设备信息包含资产编码(545-out)
typedef struct
{
	char chIP[20];			///<IP地址
	char chDeviceCode[32];	///<设备编码
	char chDeviceName[128];	///<设备名称
	char chUpperCode[32];	///<上级编码
	int nCenterNo;			///<中心ID
	int nFatherCenterNo;	///<父中心ID
	int nDeviceId;			///<设备ID
	int nDeviceLevel;		///<设备等级
	char chCapitalCode[32];	///<资产编码
	
}DEVICEINFOWITHCAPITAL_GET_S;

///<获取设备信息包含资产编码(546-out)
typedef struct
{
	char chFrontendCode[32];	///<前端设备编码
	char chFrontendName[128];	///<前端设备名称
	char chUpperCode[32];		///<上级编码
	char chDeviceCode[32];		///<所属设备编码
	int nCenterNo;				///<中心ID
	int nFatherCenterNo;		///<父中心ID
	int nDeviceId;				///<设备ID
	int nDeviceLevel;			///<设备等级
	int nChannelNo;				///<通道号
	char chCapitalCode[32];		///<资产编码
	
}FRONTENDNODEINFOWITHCAPITAL_GET_S;
 

///<获取文件服务器配置信息(291-out,292-in)
typedef struct
{
	int nFileType;				//文件类型：1-文件服务器
	char chFilePath[256];		//文件服务器URL路径
	char chFileName[128];		//备用	
	
}FILESERVERINFO_GET_SP;
 
///<动作库基本操作_NEW(293-in)
typedef struct
{
    int nCondition;    ///< 条件: 1-add,2-mod,3-del
    int nActionID;     ///< 动作ID;
	int nActionNo;	   ///< 动作编号;
	int nProperty;	   ///< 标识：0-众译执行；1-固定类型；2-考拉执行；
    char chName[64];   ///< 动作名称
	char chProperty[128];	///< 属性，目前传电话号码，增加众译执行或考拉执行
}P_NEW_OPACTIONLIB_NEW;
 
 
///< 任务查询_NEW(294-in)
typedef struct
{
    char chUserName[64];          ///< 用户名称
    char chTaskName[64];          ///< 任务名称
    char chRoleName[64];          ///< 角色名称
    int  nError;                  ///< 异常类型值 0-无异常，1-执行时间过短，2-执行不准时，3-巡检有异常
    int  nClassId;                ///< 班次ID
    char chBeginDate[32];         ///< 查询起始日期
    char chEndDate[32];           ///< 查询结束日期(结束时间最好不要大于当前日期，之后的日期是无结果的)
	int nProperty;                ///< 锁定状态：-1-全部；0-解锁；1-锁定；
}P_NEW_INSPECT_CHECKTASKINFOWITHLOCK; 

///<报警处理信息的综合查询withlock(295-in)
typedef struct
{
    int nPage;                     ///< 页数
    int nCount_Page;               ///< 每页显示记录条数
    char chBeginTime[32];          ///< 开始时间
    char chEndTime[32];            ///< 结束时间
    char chAreaNames[2048];        ///< 地点编号串
    char chAlarmTypes[1024];       ///< 报警类型串
    char chAlarmlevels[32];        ///< 报警等级串
    char chHandleMan[32];          ///< 处理人
    char chProcessType[32];        ///< 警情类型
    int nProcessStates;            ///< 处理状态
	int nProperty;                ///< 锁定状态：-1-全部；0-解锁；1-锁定；
}P_NEW_JH_COMPLEXCHECKWITHLOCK;
 
///<查询认证历史信息withlock(296-in)
typedef struct
{
    char chBeginDate[32];            ///<认证申请时间  开始
    char chEndDate[32];              ///<认证时间结束
    char chAreaName[64];             ///<区域名称
    int  nPassStatus;                ///<通行状态0-全部 1-同意开门 2-拒绝进入
    int  nProcessStatus;             ///<处理状态0-全部 1-未处置 2-处置中 3-待审核
    int  nIsCollection;              ///<是否收藏 0-全部 1-收藏 2-未收藏
    int  nIsNomal;                   ///<录入方式 0-全部 1-正常录入 2-非正常录入
    int  nMethod;                    ///<处置模式 0-全部
    int  nProcessType;               ///<审核状态 0-全部 1-通过(合格) 2-拒绝(不合格)
    int  nPages;                     ///<页数
    int  nRecords;                   ///<每页显示记录数
	int nProperty;                ///< 锁定状态：-1-全部；0-解锁；1-锁定；
}TAGDOAHISTORYINFOWITHLOCK_P; 
 

///<人员信息相关操作(453-in)
typedef struct
{
	int nCondition;				///<条件：1-新增；2-修改；3-删除；4-导入
	int nStaffId;				///<人员编号
	char chUserName[64];		///<姓名
	char chSex[10];				///<性别
	char chPhone[32];			///<联系电话
	char chHeadImage[64];		///<头像
	char chWorkNum[16];			///<工号
	char chIdentityCard[64];	///<身份证号
	char chDepartmentName[20];	///<部门
	int nUserType;				///<用户类型：1-内部；2-外部；3-临时
	char chBeginTime[20];		///<人员有效期开始时间
	char chEndTime[20];			///<人员有效期结束时间
	char chCardNum[16];			///<卡号
	char chAuthGroup[1000];		///<权限组,用$分割（导入信息：厂家id$权限组名称$厂家数据库人员id$）
	int nUserStatus;			///<用户状态：0-正常；1-注销
	char chAttachment[128];		///<附件信息
	int nLogoutReason;			///<注销原因：0-正常；1-离职；2-调离；3-退休；4-开除；5-其他
	char chLogoutDesc[256];		///<注销描述
	int nCheckStatus;			///<审核状态：1-已审核；2-待审核；3-审核未通过
	char chCheckNumber[64];		///<审核编号
	char chLoginUser[32];		///<登录的用户
}STAFFINFOOPERATION_P; 
 

///<部门信息相关操作(454-in)
typedef struct
{
	int nCondition;				///<条件：1-新增；2-修改；3-删除
	int nDepartmentId;			///<部门ID
	char chDepartmentName[32];	///<部门名称
	char chMemo[128];			///<备注信息	
	char chLoginUser[32];		///<操作用户 	
}DEPARTMENTINFOOPERATION_P; 


///<人员状态设置(455-in)
typedef struct
{
	int nStaffId;			///<人员编号
	int nStatus;			///<人员状态：0-正常；1-注销；
	int nLogoutReason;		///<注销原因：0-正常；1-离职；2-调离；3-退休；4-开除；5-其他
	char chLoginUser[32];	///<操作用户 	 	
}STAFFSTATUS_SET_P;
 
///<获取部门信息(456-in)
typedef struct
{
	int nCondition;			///<条件：0-获取所有；1-根据部门名称模糊查询
	char chDepartment[32];	///<部门名称 	
}DEPARTMENTINFO_GET_P;

///<获取部门信息(456-out)
typedef struct
{
	int nDepartmentId;			///<部门ID
	char chDepartmentName[32];	///<部门名称
	char chMemo[128];			///<备注信息		
}DEPARTMENTINFO_GET_S;

///<获取权限组信息(457-out)
typedef struct
{
	char chAuthGroup[32];	///<权限组	
}AUTHGROUP_GET_S;
 
///<获取人员信息(458-in)
typedef struct
{
	char chDepName[32];			///<部门名称
	char chAuthGroup[32];		///<权限组
	char chStaffType[16];		///<用户类型：内部，外部等
	char chStaffStatus[16];		///<用户状态：正常，离职，调离等
	char chQuery[32];			///<查询条件：姓名或身份证的模糊条件
	int nPage;					///<当前页号
	int nPageNum;				///<每页显示的数量	
}STAFFINFO_GET_P;

///<获取人员信息(458-out)
typedef struct
{
	int nStaffId;				///<人员编号
	char chUserName[64];			///<姓名
	char chSex[10];				///<性别
	char chPhone[32];			///<联系电话
	char chHeadImage[64];		///<头像
	char chWorkNum[16];			///<工号
	char chIdentityCard[32];		///<身份证号
	char chDepartmentName[32];	///<部门
	char chUserType[16];			///<用户类型：1-内部；2-外部；3-临时
	char chBeginTime[20];		///<人员有效期开始时间
	char chEndTime[20];			///<人员有效期结束时间
	char chCardNum[16];			///<卡号
	char chAuthGroup[20];		///<权限组,用$分割
	int nUserStatus;			///<用户状态：0-正常；1-注销
	char chAttachment[128];		///<附件信息
	char chLogoutReason[10];		///<注销原因：0-正常；1-离职；2-调离；3-退休；4-开除；5-其他
	char chLogoutDesc[256];		///<注销描述
	char chCheckStatus[10];		///<审核状态：0-已审核；1-待审核；2-审核未通过
	char chCheckNumber[64];		///<审核编号
	int nTotalNum;				///<总记录数
	int nPageNum;				///<每页条数	
}STAFFINFO_GET_S;
 

///<获取人员操作信息(459-in)
typedef struct
{
	char chUserName[64];		///<操作的用户
	int nOperateObject;			///<操作对象：1-人员、2-部门
	int nOperateType;			///<操作类型：1-新增、2-修改、3-删除
	char chContent[64];			///<操作内容
	char chBeginTime[20];		///<操作开始时间
	char chEndTime[20];			///<操作结束时间
	int nPage;					///<当前页数
	int nPageNum;				///<每页条数	
}STAFFOPERATION_GET_P;

///<获取人员操作信息(459-out)
typedef struct
{
	int nId;					///<操作日志ID
	char chUserName[64];		///<操作的用户
	char chOperateObject[16];	///<操作对象：人员、部门
	char chOperateType[16];		///<操作类型：新增、修改、删除
	char chMemo[64];			///<操作内容
	char chOperateTime[20];		///<操作时间
	int nTotalNum;				///<总记录数
	int nPageNum;				///<每页条数	
}STAFFOPERATION_GET_S;
 
 
///< 获取最早的未锁定的文件(613-in)
typedef struct
{
	char chServerName[64];		///<服务器名称
	
}GETFIRSTDAYFILEINFO_GET_P;
 
 
///< 获取最早的未锁定的文件(613-out)
typedef struct
{
	char chFileName[50];		///<文件名称
	char chFilePath[250];		///<文件路径
	char chDelDate[12];			///<要删除的日期
	
}GETFIRSTDAYFILEINFO_GET_S;

///< 删除指定日期未锁定的文件(614-in)
typedef struct
{
	char chDelDate[12];			///<要删除的日期
	char chServerName[64];		///<服务器名称
	
}DELETEFILEINFOBYDATE_P;


///< 动作库相关操作_Koala(700-in)
typedef struct
{
	int nCondition;			///<条件：1-添加；2-修改；3-删除
	int nActionID;			///<动作ID:众译修改删除使用
	char chActionName[64];	///<动作名称
	int nProperty;			///<标识：0-众译执行；1-固定类型
	char chProperty[64];	///<属性，目前传电话号码
	int nActionNo;			///<动作编号
	char chMemo[256];		///<备注：可为空
	char chGUID[128];		///<动作唯一标识
	
}ACTIONOPERATION_KOALA_P;

///< 预案库相关操作_Koala(701-in)
typedef struct
{
    int nCondition;            ///< 条件: 1-koala增加,2-koala修改,3-koala删除，4-SoftSet增加；5-SoftSet修改
    int nPlanID;               ///< 预案ID
    char chName[64];           ///< 预案名称
    char chMan[64];            ///< 创建人
    char chActionID[2000];     ///< 动作ID串，用$分割(koala传入GUID串，配置客户端传入ID串)
    char chMustBeDos[128]; 	   ///< 动作是否必须执行，用$分割：0-不是必须；1-必须
	char chExecuteType[128];   ///<	动作执行类型，用$分割：0-众绎执行；2-考拉执行
    char chGUID[128]; 		   ///< 预案唯一标识
	
}PREPLANOPERATION_KOALA_P;


///< 事件库相关操作_NEW,配置客户端使用(702-in)
typedef struct
{
    int nCondition;            ///< 条件: 1-add;2-modify
    int nEventID;              ///< 事件ID
    char chName[64];           ///< 事件名称
    int nAlarmValue;           ///< 报警等级值
    char chActionID[128]; 	   ///< 动作ID串,用$分割
    char chMustBeDos[128];     ///< 动作是否必须执行，用$分割：0-不是必须；1-必须
	char chExecuteType[128];   ///<	动作执行类型，用$分割：0-众绎执行；2-考拉执行
    char chGUID[128];     	   ///< 事件唯一标识
	
}EVENTOPERATION_SOFTSET_P;

///< 报警处置考拉信息写入(703-in)
typedef struct
{
	int nActionType;		///<动作类型：1-请求协助;2-进度上报;3-处置结束;4-手动报警;5-报警附件;6-确认警情反馈;7-指派人员
	char chZoneeUser[64];	///<指派者，众译用户
	char chKoalaUser[256];	///<指派的考拉人员或上传附件的用户,如果动作类型为7时，用$分割，第一个为主负责人
	int nOperationType;		///<操作类型：对应考拉操作类型
	char chDescribe[256];	///<描述，与动作类型对应
	char chTime[20];		///<与动作类型对应，如：1-请求协助时间；7-指派时间等
	int nAssignStatus;		///<指派反馈状态：0-接受；1-拒绝
	char chBeginTime[20];	///<开始时间
	char chEndTime[20];		///<结束时间
	char chAttachMent[1024];///<附件串
	char chRefuseReason[256];///<拒绝原因
	char chEPlanName[128];	///<预案GUID,动作类型=2的时候传入
	int nProperty;			///<备用
	char chProperty[256];	///<备用,动作类型=2的时候传入动作的GUID
	char chGUID[64];		///<报警GUID
	
}ALARMDEALKOALAINFO_INSERT_P;

///< 获取动作库_Koala(704-in)
typedef struct
{
	int nCondition;			///<条件：0-全部，1-根据GUID获取
	char chGUID[128];		///<动作GUID
	
}GETACTIONLIB_KOALA_P;

///< 获取动作库_Koala(704-out)
typedef struct
{
    int nID;           ///< 唯一编号
    int nActionID;     ///< 动作编号
    char chName[64];    ///< 动作名称
    char chProperty[64]; ///< 属性，目前填写电话号码，增加众译执行或考拉执行
    int nProperty;		///<标识：0-众译执行；2-考拉执行；
    char chMemo[256];	///<备注
    char chGUID[128];	///<动作唯一标识
	
}GETACTIONLIB_KOALA_S;

///< 获取预案库_Koala(705-in)
typedef struct
{
	int nCondition;			///<条件：0-全部，1-根据预案ID，2-根据预案名, 3- 不带联动动作；4-根据GUID获取
	int nPlanID;			///<预案ID
	char chPlanName[128];		///<预案名称，condition=4时传GUID
	
}GETPREPLANLIB_KOALA_P;

typedef struct
{
    int nID;           ///< 唯一编号
    int nActionID;     ///< 动作编号
    char chName[64];    ///< 动作名称
    char chProperty[64];  ///< 属性，目前填写电话号码，增加众译执行或考拉执行
    int nProperty;		///<标识：0-众译执行；2-考拉执行；
    char chMemo[256];		///<备注
    char chGUID[128];		///<动作唯一标识
    int nSequence;		///<执行顺序
    int nMustDo;		///<是否必须执行：0-可跳过；1-必须执行
	
}ACTIONINFO_KOALA;


///< 获取预案库_Koala(705-out)
typedef struct
{
    int nPlanID;              ///< 预案ID
    char chPlanName[64];       ///< 预案名称
    char chMan[64];            ///< 创建人
    char chGUID[128];		 ///< 预案唯一标识
	int nActionNum;			///< 关联动作的数量
	ACTIONINFO_KOALA actions[20];///<预案关联的动作
	
}GETPREPLANLIB_KOALA_S;

///< 获取事件库_Koala(706-in)
typedef struct
{
	int nCondition;			///<条件：0-全部；1-根据事件ID；2-根据事件名；3- 不带联动动作；4-根据GUID获取
	int nEventID;			///<事件ID
	char chEventName[128];		///<事件名称，condition=4时传GUID
	
}GETEVENTLIB_KOALA_P;

///< 获取事件库_Koala(706-out)
typedef struct
{
    int nEventID;           ///< 事件ID
    char chEventName[64];    ///< 事件名称
    int nAlarmValue;        ///< 报警等级值
    char chAlarmLevel[64];   ///< 报警等级名
    char chGUID[128];		///< 事件唯一标识
	int nActionNum;			///< 关联动作的数量
	ACTIONINFO_KOALA actions[20];///<预案关联的动作
	
}GETEVENTLIB_KOALA_S;

///< 获取Koala报警附件(707-in)
typedef struct
{
	int nCondition;			///<条件：0-全部；1-根据对应类型获取相应的附件；2-获取处置过程中的附件；3-获取进度上报信息
	int nType;			    ///<动作类型：1-请求协助;2-进度上报;3-处置结束;4-手动报警;5-报警附件;6-确认警情反馈;7-指派人员
	char chGUID[128];		///<报警GUID（必传）
	
}GETALARMATTACHMENT_KOALA_P;

///< 获取Koala报警附件(707-out)
typedef struct
{
	char chKoalaUser[64];	///<指派的考拉人员或上传附件的用户,如果动作类型为7时，用$分割，第一个为主负责人
	int nIsMasterUser;		///<是否主负责人：0-不是；1-是
	char chDescribe[256];	///<描述，与动作类型对应
	char chTime[20];		///<与动作类型对应，如：1-请求协助时间；7-指派时间等
	char chBeginTime[20];	///<开始时间
	char chEndTime[20];		///<结束时间
	char chAttachMent[2000];///<附件串
	char chRefuseReason[256];///<拒绝原因，condition=3时，此处为动作的GUID
	int nEPlanName;			///<预案ID
	
}GETALARMATTACHMENT_KOALA_S;


///< 人员同步标志设置(460-in)
typedef struct
{
	char chIds[1000];  ///<记录ID串，用$分割
	int nSyncDay;	///<要同步天数
	int nStatus;	///<同步状态，1-已同步
	
}STAFFSYNCFLAG_SET_P;



///< 人员权限组获取(461-in)
typedef struct
{
	int nStaffId;   ///<人员ID
	
}STAFFAUTHINFO_GET_P;

///< 人员权限组获取(461-out)
typedef struct
{
	int nAuthId;					///<权限组id
	char chAuthName[64];			///<权限组名称
	char chManufacturerName[64];	///<厂家名称
	int nIsHas;						///<否是有该权限
	
}STAFFAUTHINFO_GET_S;


///< 获取同步人员信息(462-in)
typedef struct
{
	int nSyncDay;  		 ///<要同步的天数
	
}STAFFSYNCINFO_GET_P;

///< 获取同步人员信息(462-out)
typedef struct
{
	int nRecordId;				///<记录ID
	int nOperateType;			///<操作类型：1-添加；2-修改；3-删除；4-注销；5-恢复注销
	int nManufactureId;			///<厂家对应的人员ID
	int nManufactureCode;		///<厂家编号
	char chAuthGroupName[64];	///<权限组名称
	char chUserName[64];		///<人员名称
	char chWordNum[64];			///<工号
	char chIdentity[64];		///<身份证
	char chDepName[64];			///<部门名称
	char chSex[10];				///<性别
	char chBeginTime[20];		///<有限期开始时间
	char chEndTime[20];			///<有效期结束时间
	
}STAFFSYNCINFO_GET_S;


///< 门禁关联守押设置(463-in)
typedef struct
{
	char chDeviceCode[64];		///<设备编码
	char chDeviceNames[256];	///<关联的设备名称，用$分割
	char chRelationTypes[64];	///<关联类型，用$分割：0-押运认证设备；1-押运路线探头
	char chDeviceTypes[256];	///<设备类型，用$分割：0-探头；1-车辆识别设备；2-人员识别设备
	char chIsEnables[64];		///<是否启用，用$分割：0-禁用；1-启用
	
}ACCESSSYRELATION_SET_P;

///< 认证守押信息关联(464-in)
typedef struct
{
	int nOpenDoorId;				///<认证ID
	char chAreaName[128];			///<网点名称
	char chLineName[128];			///<押运线路名称
	int nLineStatus;				///<路线认证状态：0-正常；1-异常；-1-追加信息
	char chLineAreaNodes[8000];		///<押运线路网点列表，用$分割
	char chLineAreaNodeStatus[1024];///<押运线路网点状态，用$分割，与网点一一对应：0-正常(绿色)；1-轻微异常(橙色)；2-严重异常(红色)
	char chPlanTime[20];			///<预计到达时间
	char chRealTime[20];			///<实际到达时间
	char chPlanCarImage[128];		///<预计到达车辆图片
	char chRealCarImage[128];		///<实际到达车辆图片
	char chPlanCarNum[128];			///<预计到达车牌号
	char chRealCarNum[128];			///<实际到达车牌号
	char chPlanCarDriver[128];		///<预计到达驾驶员
	char chRealCarDriver[128];		///<实际到达驾驶员
	char chPlanStaffImage[256];		///<预计到达人员照片,用$分割
	char chRealStaffImage[256];		///<实际到达人员照片,用$分割
	char chPlanStaffName[256];		///<预计到达人员姓名,用$分割
	char chRealStaffName[256];		///<实际到达人员姓名,用$分割
	char chPlanStaffNum[256];		///<预计到达人员身份证,用$分割
	char chRealStaffNum[256];		///<实际到达人员身份证,用$分割
	char chPlanDepartment[256];		///<预计到达人员部门,用$分割
	char chRealDepartment[256];		///<实际到达人员部门,用$分割
	char chRealStaffStatus[256];	///<人员到达状态，,用$分割：0-正常；1-异常
	char chRFIDNum[1024];			///<款箱编号,用$分割
	char chRFIDTime[1024];			///<款箱到达时间,用$分割
	int nProperty;					///<备用
	char chProperty[256];			///<备用
	
}DOOROPENSYRELATION_SET_P;

///< 门禁关联守押设备获取(465-in)
typedef struct
{
	int nCondition;			///<条件：0-全部；1-根据设备id获取；2-根据设备编码获取
	int nDeviceId;			///<设备ID
	char chDeviceCode[64];	///<设备编码
	
}ACCESSSYRELATION_GET_P;

///< 门禁关联守押设备获取(465-out)
typedef struct
{
	int nDoorId;					///<门禁设备ID
	char chMasterDeviceCode[64];	///<门禁设备编码
	char chMasterDeviceName[64];	///<门禁设备名称
	int nDeviceId;					///<联动设备的ID
	char chRelationDeviceCode[64];	///<联动设备的编码
	char chRelationDeviceName[64];	///<联动设备的名称
	int nRelationType;				///<关联类型：0-押运认证设备；1-押运路线探头
	int nDeviceType;				///<设备类型：0-探头；1-车辆识别设备；2-人员识别设备
	int nIsEnable;					///<是否启用：0-禁用；1-启用
	
}ACCESSSYRELATION_GET_S;

///< 认证守押信息关联获取(466-in)
typedef struct
{
	int nCondition;			///<条件：1-根据认证id获取；
	int nDoorOpenId;		///<认证id
	
}DOOROPENSYRELATION_GET_P;

///< 认证守押信息关联获取(466-out)
typedef struct
{
	int nOpenDoorId;				///<认证ID
	char chAreaName[128];			///<网点名称
	char chLineName[128];			///<押运线路名称
	int nLineStatus;				///<路线认证状态：0-正常；1-异常
	char chLineAreaNodes[8000];		///<押运线路网点列表，用$分割
	char chLineAreaNodeStatus[1024];///<押运线路网点状态，用$分割，与网点一一对应：0-正常(绿色)；1-轻微异常(橙色)；2-严重异常(红色)
	char chPlanTime[20];			///<预计到达时间
	char chRealTime[20];			///<实际到达时间
	char chPlanCarImage[128];		///<预计到达车辆图片
	char chRealCarImage[128];		///<实际到达车辆图片
	char chPlanCarNum[128];			///<预计到达车牌号
	char chRealCarNum[128];			///<实际到达车牌号
	char chPlanCarDriver[128];		///<预计到达驾驶员
	char chRealCarDriver[128];		///<实际到达驾驶员
	char chPlanStaffImage[256];		///<预计到达人员照片,用$分割
	char chRealStaffImage[256];		///<实际到达人员照片,用$分割
	char chPlanStaffName[256];		///<预计到达人员姓名,用$分割
	char chRealStaffName[256];		///<实际到达人员姓名,用$分割
	char chPlanStaffNum[256];		///<预计到达人员身份证,用$分割
	char chRealStaffNum[256];		///<实际到达人员身份证,用$分割
	char chPlanDepartment[256];		///<预计到达人员部门,用$分割
	char chRealDepartment[256];		///<实际到达人员部门,用$分割
	char chRealStaffStatus[256];	///<人员到达状态，,用$分割：0-正常；1-异常
	char chRFIDNum[1024];			///<款箱编号,用$分割
	char chRFIDTime[1024];			///<款箱到达时间,用$分割
	int nProperty;					///<备用
	char chProperty[256];			///<备用
	
}DOOROPENSYRELATION_GET_S;


///<查询认证历史信息_SY(467-in)
typedef struct
{
    char chBeginDate[32];            ///<认证申请时间  开始
    char chEndDate[32];              ///<认证时间结束
    char chAreaName[64];             ///<区域名称
    int  nPassStatus;                ///<通行状态0-全部 1-同意开门 2-拒绝进入
    int  nProcessStatus;             ///<处理状态0-全部 1-未处置 2-处置中 3-待审核
    int  nIsCollection;              ///<是否收藏 0-全部 1-收藏 2-未收藏
    int  nIsNomal;                   ///<录入方式 0-全部 1-正常录入 2-非正常录入
    int  nMethod;                    ///<处置模式 0-全部
    int  nProcessType;               ///<审核状态 0-全部 1-通过(合格) 2-拒绝(不合格)
    int  nPages;                     ///<页数
    int  nRecords;                   ///<每页显示记录数
	int nProperty;                   ///< 锁定状态：-1-全部；0-解锁；1-锁定；
	int  nAuthType;					 ///< 认证类型：-1-全部；0-原三方认证；1-守押认证
}QUERYHISTORYINFO_SY_GET_P; 

///<查询认证历史信息_SY(467-out)
typedef struct
{
    int  nId;                        ///<认证Id
    char chAreaName[64];             ///<区域名称
    char chDeviceName[64];           ///<门禁名称
    char chHappenDate[32];           ///<认证申请时间
    int  nMethod;                    ///<处理方式
    int  nProcessStatus;             ///<处理状态 1-未处置 2-处置中 3-待审核
    int  nProcessType;               ///<审核状态 1-通过(合格) 2-拒绝(不合格)
    int  nPassStatus;                ///<通行状态1-同意开门 2-拒绝进入
    char chHandleMan[128];           ///<处置人
    char chHandleDate[20];           ///<处置时间
    char chAuditor[128];             ///<审核人
    char chAuditDate[20];            ///<审核时间
    bool bIsCollection;              ///<是否收藏
    bool bIsNormal;                  ///<是否正常录入
    char chApplyType[128];           ///<认证模式
	int nProperty;                   ///< 锁定状态：0-解锁；1-锁定；
	int  nAuthType;				     ///< 认证类型：0-原三方认证；1-守押认证
    int  nSumPage;                   ///<总页数
}QUERYHISTORYINFO_SY_GET_S;


///<根据报警源获取最近一条报警的报警处置状态(297-in)
typedef struct
{
    int nCondition;            	///<条件：0-获取最近一条报警的报警处置状态
    char chAlarmSource[64];     ///<报警源
	char chParam[64];           ///<参数：备用
}LASTALARMDEALSTATUS_GET_P; 

///<根据报警源获取最近一条报警的报警处置状态(297-out)
typedef struct
{
    int nDealStatus;			///<处置状态：0-非进行状态；2-未处理；3-处理中；4-延迟处理；5-暂停处理

}LASTALARMDEALSTATUS_GET_S;














/**************************************************************************/

///<------------------------------------------------------------------------------
#endif