#pragma once



/*��*/
//ɾ��ָ��
#define MySafeDelete(p)	\
if((p)){	\
delete (p); (p) = nullptr;	\
}


//��ȡ����·��
CString MyGetExePath();
//ʹ��ϵͳ����
LRESULT EnableWindowTheme(HWND hwnd, LPCWSTR classList, LPCWSTR subApp, LPCWSTR idlist);