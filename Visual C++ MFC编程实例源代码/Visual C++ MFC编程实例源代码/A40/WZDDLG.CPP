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
	m_bCheck = FALSE;
	m_sName = _T("");
	m_nRadio = -1;
	//}}AFX_DATA_INIT
}


void CWzdDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWzdDialog)
	DDX_Check(pDX, IDC_CHECK1, m_bCheck);
	DDX_Text(pDX, IDC_EDIT1, m_sName);
	DDX_Radio(pDX, IDC_RADIO1, m_nRadio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdDialog, CDialog)
	//{{AFX_MSG_MAP(CWzdDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog message handlers
