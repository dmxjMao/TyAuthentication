#pragma once



/*��*/
//ɾ��ָ��
#define MySafeDelete(p)	\
if((p)){	\
delete (p); (p) = nullptr;	\
}


//��ȡ����·��
CString MyGetExePath();
