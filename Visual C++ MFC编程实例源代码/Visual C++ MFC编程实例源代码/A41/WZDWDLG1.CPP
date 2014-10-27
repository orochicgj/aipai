// WzdDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdWDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdWaitDialog dialog


CWzdWaitDialog::CWzdWaitDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CWzdWaitDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWzdWaitDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWzdWaitDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWzdWaitDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdWaitDialog, CDialog)
	//{{AFX_MSG_MAP(CWzdWaitDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdWaitDialog message handlers
