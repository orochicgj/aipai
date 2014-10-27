// Page2.cpp : implementation file
//

#include "stdafx.h"
#include "SampWzd.h"
#include "SampWzdS.h"
#include "Page2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage2 property page

IMPLEMENT_DYNCREATE(CPage2, CPropertyPage)

CPage2::CPage2() : CPropertyPage(CPage2::IDD)
{
	//{{AFX_DATA_INIT(CPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage2)
	DDX_Control(pDX, IDC_LIST1, m_ctrlChapter);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CPage2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage2 message handlers

BOOL CPage2::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_pSheet=(CSampleWzdSheet*)GetOwner();

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CPage2::OnSetActive() 
{
	m_pSheet->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);

	// fill m_ctrlSection with sections from m_samples in Property Sheet
	m_ctrlChapter.ResetContent();
	for (int i=0;i<m_pSheet->m_pSection->GetSize();i++)
	{
		SAMPLES *pSamples=(*m_pSheet->m_pSection)[i];
		m_ctrlChapter.AddString(*pSamples->pName);
	}
	// select first item
	m_ctrlChapter.SetCurSel(0);
	
	return CPropertyPage::OnSetActive();
}

LRESULT CPage2::OnWizardNext() 
{
	// get selection and set m_pChapter in Property Sheet
	int i=m_ctrlChapter.GetCurSel();
	SAMPLES *pSamples=(*m_pSheet->m_pSection)[i];
	m_pSheet->m_pChapter=pSamples->pSamples;

	return CPropertyPage::OnWizardNext();
}
