// Page1.cpp : implementation file
//

#include "stdafx.h"
#include "SampWzd.h"
#include "SampWzdS.h"
#include "Page1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage1 property page

IMPLEMENT_DYNCREATE(CPage1, CPropertyPage)

CPage1::CPage1() : CPropertyPage(CPage1::IDD)
{
	//{{AFX_DATA_INIT(CPage1)
	//}}AFX_DATA_INIT
}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1)
	DDX_Control(pDX, IDC_LIST1, m_ctrlSection);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CPage1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1 message handlers

BOOL CPage1::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_pSheet=(CSampleWzdSheet*)GetOwner();

	// fill m_ctrlSection with sections from m_samples in Property Sheet
	for (int i=0;i<m_pSheet->m_samples.GetSize();i++)
	{
		m_ctrlSection.AddString(*m_pSheet->m_samples[i]->pName);
	}
	// select first item
	m_ctrlSection.SetCurSel(0);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CPage1::OnSetActive() 
{
	m_pSheet->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}

LRESULT CPage1::OnWizardNext() 
{
	// get selection and set m_pSection in Property Sheet
	int i=m_ctrlSection.GetCurSel();
	m_pSheet->m_pSection=m_pSheet->m_samples[i]->pSamples;

	return CPropertyPage::OnWizardNext();
}
