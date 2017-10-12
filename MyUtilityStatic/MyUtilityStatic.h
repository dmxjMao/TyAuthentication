#pragma once



/*��*/
//ɾ��ָ��
#define MySafeDelete(p)	\
if((p)){	\
delete (p); (p) = nullptr;	\
}

//�ṹ��תPBYTE
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


//��ȡ����·��
CString MyGetExePath();
//ʹ��ϵͳ����
LRESULT EnableWindowTheme(HWND hwnd, LPCWSTR classList, LPCWSTR subApp, LPCWSTR idlist);