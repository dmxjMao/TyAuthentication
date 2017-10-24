#pragma once


/*宏*/
//删除指针
#define MySafeDelete(p)	\
if((p)){	\
delete (p); (p) = nullptr;	\
}

//结构体转PBYTE
template<typename T>
inline std::shared_ptr<BYTE> MyStructToPBYTE(const T& var) {
	PBYTE pBuf = new BYTE[sizeof(T)];
	memcpy(pBuf, &var, sizeof(T));

	return std::shared_ptr<BYTE>(pBuf);
}


//获取程序路径
CString MyGetExePath();
//使用系统主题
LRESULT EnableWindowTheme(HWND hwnd, LPCWSTR classList, LPCWSTR subApp, LPCWSTR idlist);
//分割字符串
void SplitString(CString& line, TCHAR ch, std::vector<CString>& vec);
void SplitString(std::string& line, char ch, std::vector<std::string>& vec);



//无法链接：提示boost命名空间不存在！
//UI界面配置
//class CUICfg {
//public:
//	//设置ui属性
//	void SetUICfg(std::string s);
//
//private:
//	//匹配到ui属性
//	virtual bool OnMatchUICfg(const boost::smatch& what) = 0;
//	//是否有ui属性
//	bool HasUICfg(const std::string& str);
//
//protected:
//	//构造函数初始化
//	std::vector<std::string> m_vecUICfg;//ui配置
//	boost::regex m_uiregex;//ui正则
//};
