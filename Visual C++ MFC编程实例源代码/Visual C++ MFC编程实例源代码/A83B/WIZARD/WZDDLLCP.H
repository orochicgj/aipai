// WzdDllCp.h : C++ Non-MFC Dll
//


#if !defined WZDDLLCPP_H
#define WZDDLLCPP_H

#ifdef WZDDLL_BLD
#define DLL __declspec( dllexport )
#else
#define DLL
#endif

class DLL CWzdDllCpp
{
	BOOL	m_bFlag;

public:
	CWzdDllCpp();
	~CWzdDllCpp();

	void WzdMessageBox(LPSTR pszString);
	void DestroyWzdWindow(HWND hWnd);
	void WzdFunc3(BOOL b);

};


#endif
