// Page4.cpp : implementation file
//

#include "stdafx.h"
#include "SampWzd.h"
#include "SampWzdS.h"
#include "Page4.h"
#include "DirDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define SETTINGS_KEY "Settings"
#define ROOT_KEY "Root Directory"
#define SUB_KEY "Substitution String"

/////////////////////////////////////////////////////////////////////////////
// CPage5 property page

IMPLEMENT_DYNCREATE(CPage4, CPropertyPage)

CPage4::CPage4() : CPropertyPage(CPage4::IDD)
{
	//{{AFX_DATA_INIT(CPage4)
	m_sRootDir = _T("");
	m_sTargetDir = _T("");
	m_sSub = _T("");
	//}}AFX_DATA_INIT
}

CPage4::~CPage4()
{
}

void CPage4::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage4)
	DDX_Text(pDX, IDC_EDIT1, m_sRootDir);
	DDX_Text(pDX, IDC_EDIT2, m_sTargetDir);
	DDX_Text(pDX, IDC_EDIT3, m_sSub);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage4, CPropertyPage)
	//{{AFX_MSG_MAP(CPage4)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage4 message handlers

BOOL CPage4::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_pSheet=(CSampleWzdSheet*)GetOwner();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CPage4::OnSetActive() 
{
	m_pSheet->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);

	// get examples directory
	m_sRootDir=AfxGetApp()->GetProfileString(SETTINGS_KEY,ROOT_KEY,m_pSheet->m_sExeDir);
	FixupDirectory(m_sRootDir);

	// get target directory
	m_sTargetDir=m_pSheet->m_sCwdDir;
	FixupDirectory(m_sTargetDir);

	// get substitution string
	m_sSub=AfxGetApp()->GetProfileString(SETTINGS_KEY,SUB_KEY,"My");

	UpdateData(FALSE);	

	return CPropertyPage::OnSetActive();
}

LRESULT CPage4::OnWizardBack() 
{
	StoreValues();
	return CPropertyPage::OnWizardBack();
}

LRESULT CPage4::OnWizardNext() 
{
	StoreValues();
	return CPropertyPage::OnWizardNext();
}

void CPage4::OnButton1() 
{
	CDirDialog dlg;
	dlg.m_sDir = m_sRootDir;
	if (dlg.DoModal()==IDOK)
	{
		m_sRootDir=dlg.m_sDir;
		UpdateData(FALSE);
	}
	
}

void CPage4::OnButton2() 
{
	CDirDialog dlg;
	dlg.m_sDir = m_sTargetDir;
	if (dlg.DoModal()==IDOK)
	{
		m_sTargetDir=dlg.m_sDir;
		UpdateData(FALSE);
	}
	
}

void CPage4::StoreValues() 
{
	UpdateData(TRUE);
	FixupDirectory(m_sRootDir);
	FixupDirectory(m_sTargetDir);

	if (!m_sSub.GetLength())
	{
		AfxMessageBox("Warning--The substitution box is empty\nIt is highly recommended that you provide\na substitution value!");
	}

	// store in property sheet 
	m_pSheet->m_sSourceRootDir=m_sRootDir;
	m_pSheet->m_sTargetDir=m_sTargetDir;
	m_pSheet->m_sSubstitution=m_pSheet->m_sUpperSub=m_pSheet->m_sLowerSub=m_sSub;
	m_pSheet->m_sUpperSub.MakeUpper();
	m_pSheet->m_sLowerSub.MakeLower();

	// store in system registry
	AfxGetApp()->WriteProfileString(SETTINGS_KEY,ROOT_KEY  ,m_sRootDir  );
	AfxGetApp()->WriteProfileString(SETTINGS_KEY,SUB_KEY   ,m_sSub      );
}

void CPage4::FixupDirectory(CString &str) 
{
	int i;
	str.TrimRight();
	if ((i=str.GetLength()) && str[i-1]!='\\')
	{
		str+="\\";
	}
}

