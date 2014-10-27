// FirstPage.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "FrstPage.h"
#include "WzdPrjct.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFirstPage property page

IMPLEMENT_DYNCREATE(CFirstPage, CPropertyPage)

CFirstPage::CFirstPage() : CPropertyPage(CFirstPage::IDD)
{
	//{{AFX_DATA_INIT(CFirstPage)
	m_bOption1 = FALSE;
	m_sOption2 = _T("");
	//}}AFX_DATA_INIT
}

CFirstPage::~CFirstPage()
{
}

void CFirstPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFirstPage)
	DDX_Check(pDX, IDC_CHECK, m_bOption1);
	DDX_Text(pDX, IDC_EDIT, m_sOption2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFirstPage, CPropertyPage)
	//{{AFX_MSG_MAP(CFirstPage)
	ON_BN_CLICKED(IDC_CHECK, OnChange)
	ON_EN_CHANGE(IDC_EDIT, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFirstPage message handlers

void CFirstPage::OnChange() 
{
	SetModified(TRUE);	
}

// only needed on one page!
void CFirstPage::OnOK() 
{
	AfxGetMainWnd()->SendMessage(WM_APPLY);
	SetModified(FALSE);
	
	CPropertyPage::OnOK();
}
