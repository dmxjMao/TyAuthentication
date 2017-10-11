#include "stdafx.h"
#include "MyUtilityStatic.h"

//程序所在目录
CString MyGetExePath()
{
	TCHAR szPath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szPath, MAX_PATH);
	TCHAR* pFind = _tcsrchr(szPath, '\\');
	szPath[_tcslen(szPath) - _tcslen(pFind) + 1] = '\0';
	return szPath;
}



LRESULT EnableWindowTheme(HWND hwnd, LPCWSTR classList, LPCWSTR subApp, LPCWSTR idlist)
{
	LRESULT lResult = S_FALSE;

	HRESULT(__stdcall *pSetWindowTheme)(HWND hwnd, LPCWSTR pszSubAppName, LPCWSTR pszSubIdList);
	HANDLE(__stdcall *pOpenThemeData)(HWND hwnd, LPCWSTR pszClassList);
	HRESULT(__stdcall *pCloseThemeData)(HANDLE hTheme);

	HMODULE hinstDll = ::LoadLibrary(_T("UxTheme.dll"));
	if (hinstDll)
	{
		(FARPROC&)pOpenThemeData = ::GetProcAddress(hinstDll, "OpenThemeData");
		(FARPROC&)pCloseThemeData = ::GetProcAddress(hinstDll, "CloseThemeData");
		(FARPROC&)pSetWindowTheme = ::GetProcAddress(hinstDll, "SetWindowTheme");
		if (pSetWindowTheme && pOpenThemeData && pCloseThemeData)
		{
			HANDLE theme = pOpenThemeData(hwnd, classList);
			if (theme != NULL)
			{
				VERIFY(pCloseThemeData(theme) == S_OK);
				lResult = pSetWindowTheme(hwnd, subApp, idlist);
			}
		}
		::FreeLibrary(hinstDll);
	}
	return lResult;
}