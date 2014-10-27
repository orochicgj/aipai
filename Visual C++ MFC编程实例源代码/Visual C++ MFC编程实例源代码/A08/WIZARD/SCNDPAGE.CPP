// ScndPage.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "ScndPage.h"
#include "WzdPrjct.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSecondPage property page

IMPLEMENT_DYNCREATE(CSecondPage, CPropertyPage)

CSecondPage::CSecondPage() : CPropertyPage(CSecondPage::IDD)
{
	//{{AFX_DATA_INIT(CSecondPage)
	m_sOption2 = _T("");
	m_nOption1 = -1;
	//}}AFX_DATA_INIT
}

CSecondPage::~CSecondPage()
{
}

void CSecondPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSecondPage)
	DDX_CBString(pDX, IDC_COMBO, m_sOption2);
	DDX_Radio(pDX, IDC_RADIO1, m_nOption1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSecondPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSecondPage)
	ON_CBN_SELCHANGE(IDC_COMBO, OnChange)
	ON_BN_CLICKED(IDC_RADIO1, OnChange)
	ON_BN_CLICKED(IDC_RADIO2, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSecondPage message handlers


void CSecondPage::OnChange() 
{
	SetModified(TRUE);	
}
