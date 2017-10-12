#pragma once



/*宏*/
//删除指针
#define MySafeDelete(p)	\
if((p)){	\
delete (p); (p) = nullptr;	\
}

//结构体转PBYTE
//#define MyStructToPBYTE(T, var)	\
//PBYTE pBuf = new BYTE[sizeof(T)];	\
//memset(pBuf, &var, sizeof(T));	\
//return T;
template<typename T>
inline std::shared_ptr<BYTE> MyStructToPBYTE(const T& var) {
	PBYTE pBuf = new BYTE[sizeof(T)];
	memset(pBuf, &var, sizeof(T));

	return std::shared_ptr<BYTE>(pBuf);
}


//获取程序路径
CString MyGetExePath();
//使用系统主题
LRESULT EnableWindowTheme(HWND hwnd, LPCWSTR classList, LPCWSTR subApp, LPCWSTR idlist);