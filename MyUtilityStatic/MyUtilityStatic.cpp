#include "stdafx.h"
#include "MyUtilityStatic.h"


using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
//using std::placeholders::_1;

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


void SplitString(CString& line, TCHAR ch, std::vector<CString>& vec)
{
	vec.clear();
	line += ch;

	int pos = 0, prev = 0;
	pos = line.Find(ch, prev);
	while (pos != -1) {
		CString& str = line.Mid(prev, pos - prev);
		vec.push_back(str);
		prev = pos + 1;
		pos = line.Find(ch, prev);
	}
	line.TrimRight(ch);
}


void SplitString(string& line, char ch, vector<string>& vec)
{
	vec.clear();
	line += ch;

	size_t pos(0), prev(0);
	pos = line.find_first_of(ch, prev);
	while (pos != string::npos) {
		string& str = line.substr(prev, pos - prev);
		vec.push_back(str);
		prev = pos + 1;
		pos = line.find_first_of(ch, prev);
	}
	line.erase(line.size(), 1);
}



//void CUICfg::SetUICfg(std::string s)
//{
//	boost::sregex_iterator it(s.begin(), s.end(), m_uiregex), itend;
//	for (; it != itend; ++it) {
//		OnMatchUICfg(*it);
//	}
//}
//
//
//bool lambda_FindUICfg(const std::string& s1, const std::string& s2) {
//	return s1 == s2;
//}
//bool CUICfg::HasUICfg(const std::string& str)
//{
//	auto it = std::find_if(m_vecUICfg.begin(), m_vecUICfg.end(),
//		std::bind(lambda_FindUICfg, _1, str));
//	return m_vecUICfg.end() != it;
//}

