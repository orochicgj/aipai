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
}

CWzdEdit::~CWzdEdit()
{
}


BEGIN_MESSAGE_MAP(CWzdEdit, CEdit)
	//{{AFX_MSG_MAP(CWzdEdit)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_EDIT_UNDO, OnUndo)
	ON_COMMAND(ID_EDIT_CUT, OnCut)
	ON_COMMAND(ID_EDIT_COPY, OnCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnPaste)
	ON_COMMAND(ID_EDIT_CLEAR, OnDelete)
	ON_COMMAND(ID_EDIT_SELECT_ALL, OnSelectAll)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdEdit message handlers


void CWzdEdit::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CMenu menu;
	// load a menu from the resources
	menu.LoadMenu(IDR_SELECTION_MENU);

	// get a pointer to actual popup menu
	CMenu* pPopup = menu.GetSubMenu(0);

	// enable/disable Undo command
	UINT nUndo=(CanUndo() ? 0 : MF_GRAYED);
	pPopup->EnableMenuItem( ID_EDIT_UNDO,  MF_BYCOMMAND|nUndo );

	// enable/disable selection commands
	int beg,end;
	GetSel(beg,end);
	UINT nSel=((beg!=end) ? 0 : MF_GRAYED);
	pPopup->EnableMenuItem(ID_EDIT_CUT, MF_BYCOMMAND|nSel );
	pPopup->EnableMenuItem(ID_EDIT_COPY, MF_BYCOMMAND|nSel );
	pPopup->EnableMenuItem(ID_EDIT_CLEAR, MF_BYCOMMAND|nSel );

	// enable/disable Paste command
	UINT nPaste=(::IsClipboardFormatAvailable(CF_TEXT) ? 0 : MF_GRAYED);
	pPopup->EnableMenuItem( ID_EDIT_PASTE, MF_BYCOMMAND|nPaste );

	// pop up the menu
	CPoint pt;
	GetCursorPos(&pt); 
	pPopup->TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);
	pPopup->DestroyMenu();

	CEdit::OnRButtonDown(nFlags, point);
}
