// WzdDlgBr.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdDlgBr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdDialogBar dialog


CWzdDialogBar::CWzdDialogBar(CWnd* pParent /*=NULL*/)
{
	//{{AFX_DATA_INIT(CWzdDialogBar)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWzdDialogBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWzdDialogBar)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdDialogBar, CDialogBar)
	//{{AFX_MSG_MAP(CWzdDialogBar)
	ON_BN_CLICKED(IDC_WZD_BUTTON1, OnWzdButton1)
	ON_BN_CLICKED(IDC_WZD_BUTTON3, OnWzdButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDialogBar message handlers

BOOL CWzdDialogBar::InitDialog() 
{
	UpdateData(FALSE);
	SetWindowText("Wzd Dialog Bar");
	return TRUE;
}

void CWzdDialogBar::OnWzdButton1() 
{
	int i=0;	
}

void CWzdDialogBar::OnWzdButton3() 
{
	// TODO: Add your control notification handler code here
	
}
