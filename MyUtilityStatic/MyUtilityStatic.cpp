#include "stdafx.h"
#include "MyUtilityStatic.h"

//��������Ŀ¼
CString MyGetExePath()
{
	TCHAR szPath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szPath, MAX_PATH);
	TCHAR* pFind = _tcsrchr(szPath, '\\');
	szPath[_tcslen(szPath) - _tcslen(pFind) + 1] = '\0';
	return szPath;
}