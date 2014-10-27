// WzdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog dialog


CWzdDialog::CWzdDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CWzdDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWzdDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWzdDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWzdDialog)
	DDX_Control(pDX, IDC_WZD_EDIT, m_ctrlEdit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdDialog, CDialog)
	//{{AFX_MSG_MAP(CWzdDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog message handlers
