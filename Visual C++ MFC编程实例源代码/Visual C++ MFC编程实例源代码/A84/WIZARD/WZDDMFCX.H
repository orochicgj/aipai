// WzdDMFC.h : MFC Dll
//

#if !defined WZDDLLMFC_H
#define WZDDLLMFC_H

#ifdef _WINDLL
#define DLL __declspec( dllexport )
#else
#define DLL
#endif

class DLL CWzdDllMFC
{
	BOOL	m_bFlag;

public:
	CWzdDllMFC();
	~CWzdDllMFC();

	void WzdMessageBox(LPSTR pszString);
	void DestroyWzdWindow(HWND hWnd);
	void WzdFunc3(BOOL b);

};


#endif
