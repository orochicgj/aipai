// CWzdDlgBr.cpp : implementation file
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
	m_sRerouted = _T("");
	//}}AFX_DATA_INIT
}


void CWzdDialogBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWzdDialogBar)
	DDX_Text(pDX, IDC_REROUTE_STATIC, m_sRerouted);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdDialogBar, CDialogBar)
	//{{AFX_MSG_MAP(CWzdDialogBar)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_COMMAND(IDC_WZD_OPTIONS, OnWzdOptions)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDialogBar message handlers

void CWzdDialogBar::OnWzdOptions() 
{
	m_sRerouted="Rerouted";
	UpdateData(FALSE);
}
