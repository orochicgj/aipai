// WzdBttn.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdBttn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdButton

CWzdButton::CWzdButton()
{
}

CWzdButton::~CWzdButton()
{
}


BEGIN_MESSAGE_MAP(CWzdButton, CBitmapButton)
	//{{AFX_MSG_MAP(CWzdButton)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdButton message handlers

void CWzdButton::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	SendMessage(WM_LBUTTONDOWN, (WPARAM)nFlags, (LPARAM)MAKELONG(point.x, point.y));
}
