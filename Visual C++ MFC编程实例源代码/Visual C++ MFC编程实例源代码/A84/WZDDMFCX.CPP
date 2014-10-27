// WzdDMFC.cpp : MFC Dll
//

#include "stdafx.h"
#include "WzdDMFCx.h"

CWzdDllMFC::CWzdDllMFC()
{
	m_bFlag=FALSE;
} 

CWzdDllMFC::~CWzdDllMFC()
{
}

// can use MFC classes and static functions
void CWzdDllMFC::WzdMessageBox(LPSTR pszString)
{
	AfxMessageBox(pszString);
}

void CWzdDllMFC::DestroyWzdWindow(HWND hWnd)
{
	CWnd wnd;
	wnd.Attach(hWnd);
	wnd.DestroyWindow();
}

void CWzdDllMFC::WzdFunc3(BOOL b)
{
	m_bFlag=b;	
}
