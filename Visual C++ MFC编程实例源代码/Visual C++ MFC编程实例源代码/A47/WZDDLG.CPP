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
	DDX_Control(pDX, IDC_WZD_COMBO, m_ctrlComboBox);
	DDX_Control(pDX, IDC_WZD_EDIT, m_ctrlEdit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdDialog, CDialog)
	//{{AFX_MSG_MAP(CWzdDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog message handlers

BOOL CWzdDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// subclass an edit control the hard way
	HWND hWnd;
	GetDlgItem(IDC_WZD_EDIT2, &hWnd);
	m_ctrlEdit2.SubclassWindow(hWnd);


	// subclass the edit control of a combo box
	char className[8];
	CWnd* pWnd = m_ctrlComboBox.GetWindow(GW_CHILD);
	do {
		::GetClassName(pWnd->m_hWnd, className, 8);
		if(!stricmp("Edit", className))
		{
			m_ctrlComboEditBox.SubclassWindow(pWnd->m_hWnd);
		}
	} while((pWnd = pWnd->GetWindow(GW_HWNDNEXT)));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
