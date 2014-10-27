// WzdEdit.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdEdit

CWzdEdit::CWzdEdit()
{
	m_brush.CreateHatchBrush( HS_BDIAGONAL, RGB(0,255,0) );
}

CWzdEdit::~CWzdEdit()
{
}


BEGIN_MESSAGE_MAP(CWzdEdit, CEdit)
	//{{AFX_MSG_MAP(CWzdEdit)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdEdit message handlers

HBRUSH CWzdEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	return m_brush;
}

BOOL CWzdEdit::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_KEYDOWN &&
		(pMsg->wParam == VK_UP || pMsg->wParam == VK_DOWN || pMsg->wParam == VK_RETURN))
	{
		int nextprev=GW_HWNDNEXT;
		int firstlast=GW_HWNDFIRST;
		if (pMsg->wParam == VK_UP)
		{
			nextprev=GW_HWNDPREV;
			firstlast=GW_HWNDLAST;
		}
		HWND hWnd = m_hWnd;
		while (hWnd)
		{
			HWND hWndx=hWnd;
			if ((hWnd = ::GetWindow(hWnd, nextprev))==NULL)
				hWnd = ::GetWindow(hWndx, firstlast);
			long style=::GetWindowLong(hWnd,GWL_STYLE);
			if ((style&WS_TABSTOP && !(style&WS_DISABLED) && style&WS_VISIBLE) || hWnd==m_hWnd)
				break;
		}
		::SetFocus(hWnd);

		return TRUE;
	}
	
	return CEdit::PreTranslateMessage(pMsg);
}
