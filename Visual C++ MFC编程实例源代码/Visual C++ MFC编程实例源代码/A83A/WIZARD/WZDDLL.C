/*
 * WzdDll.c : Non-MFC "C" Dll Using the Win32 API directly
 */

#include <windows.h>
#include <stdlib.h>
#include "WzdDll.h"

BOOL flag=FALSE;

// must call Win32 API directly
void DLL WzdMessageBox(LPSTR pszString)
{
	MessageBox(NULL,pszString,"Wzd DLL",MB_OK);
}

void DLL DestroyWzdWindow(HWND hWnd)
{
	DestroyWindow(hWnd);
}

void DLL WzdFunc3(BOOL b)
{
	flag=b;	
}
