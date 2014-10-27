/*
 * WzdStatic.c : Non-MFC "C" Static Library Using the Win32 API directly
 */

#include <windows.h>
#include <stdlib.h>
#include "WzdStat.h"

BOOL flag=FALSE;

// must call Win32 API directly
void WzdMessageBox(LPSTR pszString)
{
	MessageBox(NULL,pszString,"Wzd Static Library",MB_OK);
}

void DestroyWzdWindow(HWND hWnd)
{
	DestroyWindow(hWnd);
}

void WzdFunc3(BOOL b)
{
	flag=b;	
}
