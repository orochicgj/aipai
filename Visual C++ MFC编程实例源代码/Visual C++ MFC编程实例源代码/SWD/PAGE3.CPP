// Page3.cpp : implementation file
//

#include "stdafx.h"
#include "SampWzd.h"
#include "SampWzdS.h"
#include "Page3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage3 property page

IMPLEMENT_DYNCREATE(CPage3, CPropertyPage)

CPage3::CPage3() : CPropertyPage(CPage3::IDD)
{
	//{{AFX_DATA_INIT(CPage3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPage3::~CPage3()
{
}

void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage3)
	DDX_Control(pDX, IDC_LIST1, m_ctrlExample);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage3, CPropertyPage)
	//{{AFX_MSG_MAP(CPage3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage3 message handlers

BOOL CPage3::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_pSheet=(CSampleWzdSheet*)GetOwner();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CPage3::OnSetActive() 
{
	m_pSheet->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);
	
	// fill m_ctrlSection with sections from m_samples in Property Sheet
	m_ctrlExample.ResetContent();
	for (int i=0;i<m_pSheet->m_pChapter->GetSize();i++)
	{
		SAMPLES *pSamples=(*m_pSheet->m_pChapter)[i];
		m_ctrlExample.AddString(*pSamples->pName);
	}
	// select first item
	m_ctrlExample.SetCurSel(0);

	return CPropertyPage::OnSetActive();
}

LRESULT CPage3::OnWizardNext() 
{
	// get selection and set m_pChapter in Property Sheet
	int i=m_ctrlExample.GetCurSel();
	CString str;
	m_ctrlExample.GetText(i,str);
	m_pSheet->m_sExample = str.Left(str.Find(' '));
	
	return CPropertyPage::OnWizardNext();
}
