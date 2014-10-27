// WzdDllCp.cpp : Non-MFC "C++" Dll Using the Win32 API directly
//

#include <windows.h>
#include <stdlib.h>
#include "WzdDllCp.h"

CWzdDllCpp::CWzdDllCpp()
{
	m_bFlag=FALSE;
} 

CWzdDllCpp::~CWzdDllCpp()
{
}

// must call the Win32 API directly
void CWzdDllCpp::WzdMessageBox(LPSTR pszString)
{
	MessageBox(NULL,pszString,"Wzd DLL Cpp",MB_OK);
}

void CWzdDllCpp::DestroyWzdWindow(HWND hWnd)
{
	DestroyWindow(hWnd);
}

void CWzdDllCpp::WzdFunc3(BOOL b)
{
	m_bFlag=b;	
}
