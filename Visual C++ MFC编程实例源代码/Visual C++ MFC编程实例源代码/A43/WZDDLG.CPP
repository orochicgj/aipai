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
	DDX_Control(pDX, IDC_WZD_ANIMATE, m_ctrlAnimate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdDialog, CDialog)
	//{{AFX_MSG_MAP(CWzdDialog)
	ON_BN_CLICKED(IDC_STOP_BUTTON, OnStopButton)
	ON_BN_CLICKED(IDC_STRT_BUTTON, OnStrtButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog message handlers

BOOL CWzdDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_ctrlAnimate.ShowWindow(SW_HIDE);
	m_ctrlAnimate.Open(IDR_FILECOPY);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWzdDialog::OnStrtButton() 
{
	m_ctrlAnimate.ShowWindow(SW_SHOW);
	m_ctrlAnimate.Play(0,-1,-1);
}

void CWzdDialog::OnStopButton() 
{
	m_ctrlAnimate.ShowWindow(SW_HIDE);
	m_ctrlAnimate.Stop();
}
