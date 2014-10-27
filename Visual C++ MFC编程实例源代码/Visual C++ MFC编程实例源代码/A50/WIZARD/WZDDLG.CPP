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
	m_sSelection="pears";
}


void CWzdDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWzdDialog)
	DDX_Control(pDX, IDC_WZD_COMBO, m_ctrlCombo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdDialog, CDialog)
	//{{AFX_MSG_MAP(CWzdDialog)
	ON_CBN_CLOSEUP(IDC_WZD_COMBO, OnCloseupWzdCombo)
	ON_CBN_DROPDOWN(IDC_WZD_COMBO, OnDropdownWzdCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog message handlers

BOOL CWzdDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrlCombo.SetWindowText(m_sSelection);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWzdDialog::OnDropdownWzdCombo() 
{
	m_ctrlCombo.ResetContent();

	m_ctrlCombo.AddString("apples");
	m_ctrlCombo.AddString("peaches");
	m_ctrlCombo.AddString("bananas");
	m_ctrlCombo.AddString("grapes");
   	m_ctrlCombo.SelectString(-1,m_sSelection);
}

void CWzdDialog::OnCloseupWzdCombo() 
{
	int	nSel;
	if ((nSel=m_ctrlCombo.GetCurSel())!=CB_ERR)
	{
		m_ctrlCombo.GetLBText( nSel, m_sSelection );
	}
	else
	{
		m_ctrlCombo.ResetContent();
		m_ctrlCombo.AddString(m_sSelection);
 		m_ctrlCombo.SelectString(-1,m_sSelection);
	}
}

void CWzdDialog::OnOK() 
{
	m_ctrlCombo.GetWindowText(m_sSelection);
	
	CDialog::OnOK();
}
