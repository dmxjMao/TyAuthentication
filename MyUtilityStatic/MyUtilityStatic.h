#pragma once



/*宏*/
//删除指针
#define MySafeDelete(p)	\
if((p)){	\
delete (p); (p) = nullptr;	\
}


//获取程序路径
CString MyGetExePath();
//使用系统主题
LRESULT EnableWindowTheme(HWND hwnd, LPCWSTR classList, LPCWSTR subApp, LPCWSTR idlist);