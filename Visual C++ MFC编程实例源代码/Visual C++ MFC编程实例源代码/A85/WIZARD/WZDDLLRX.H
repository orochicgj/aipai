// WzdDllRc.h : MFC Dll
//

#if !defined WZDDLLRC_H
#define WZDDLLRC_H

#ifdef _WINDLL
#define DLL __declspec( dllexport )
#else
#define DLL
#endif

class DLL CWzdDllRc
{

public:
	CWzdDllRc();
	~CWzdDllRc();
};


#endif
