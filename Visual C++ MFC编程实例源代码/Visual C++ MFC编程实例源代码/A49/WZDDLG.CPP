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
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdDialog, CDialog)
	//{{AFX_MSG_MAP(CWzdDialog)
	ON_BN_CLICKED(IDC_WZD_BUTTON1, OnWzdButton1)
	ON_BN_CLICKED(IDC_WZD_BUTTON2, OnWzdButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog message handlers

BOOL CWzdDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_bitmap.LoadBitmapEx(IDB_WZD_BUTTON,TRUE);
	((CButton *)GetDlgItem(IDC_WZD_BUTTON1))->SetBitmap(m_bitmap);

	m_bitmapButton2.AutoLoad(IDC_WZD_BUTTON2,this);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWzdDialog::OnWzdButton1() 
{
	// TODO: Add your control notification handler code here
}

void CWzdDialog::OnWzdButton2() 
{
	// TODO: Add your control notification handler code here
}
