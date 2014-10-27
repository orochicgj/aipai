// WzdStBar.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdStBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdStatusBar

CWzdStatusBar::CWzdStatusBar()
{
}

CWzdStatusBar::~CWzdStatusBar()
{
}


BEGIN_MESSAGE_MAP(CWzdStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CWzdStatusBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdStatusBar message handlers

int CWzdStatusBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatusBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect rect(0,0,0,0);
	m_WzdButton.Create("Wzd",WS_CHILD,rect,this,IDC_WZD_BUTTON);
	CFont *pFont=CFont::FromHandle((HFONT)::GetStockObject(ANSI_VAR_FONT));
	m_WzdButton.SetFont(pFont);

	m_WzdProgressCtrl.Create(WS_CHILD|WS_VISIBLE,rect,this,IDC_WZD_PROGRESS);

	return 0;
}

void CWzdStatusBar::OnSize(UINT nType, int cx, int cy) 
{
	CStatusBar::OnSize(nType, cx, cy);

	UINT inx;
	CRect rect;

	inx=CommandToIndex(ID_INDICATOR_WZDBUTTON);
	GetItemRect(inx,&rect);
	m_WzdButton.MoveWindow(rect);

	inx=CommandToIndex(ID_INDICATOR_WZDPROGRESS);
	GetItemRect(inx,&rect);
	m_WzdProgressCtrl.MoveWindow(rect);

}
