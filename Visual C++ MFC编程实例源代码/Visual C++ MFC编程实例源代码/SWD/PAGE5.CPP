// Page5.cpp : implementation file
//

#include "stdafx.h"
#include <direct.h>
#include "SampWzd.h"
#include "SampWzdS.h"
#include "Page5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define README_SIZE 10000

/////////////////////////////////////////////////////////////////////////////
// CPage5 property page

IMPLEMENT_DYNCREATE(CPage5, CPropertyPage)

CPage5::CPage5() : CPropertyPage(CPage5::IDD)
{
	//{{AFX_DATA_INIT(CPage5)
	m_bClipboard = FALSE;
	m_bFiles = FALSE;
	//}}AFX_DATA_INIT
	m_bClipboard = TRUE;
}

CPage5::~CPage5()
{
}

void CPage5::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage5)
	DDX_Check(pDX, IDC_CHECK1, m_bClipboard);
	DDX_Check(pDX, IDC_CHECK2, m_bFiles);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEditbox);
}


BEGIN_MESSAGE_MAP(CPage5, CPropertyPage)
	//{{AFX_MSG_MAP(CPage5)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage5 message handlers

BOOL CPage5::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_pSheet=(CSampleWzdSheet*)GetOwner();
	m_ctrlEditbox.SetTabStops(15);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CPage5::OnSetActive() 
{
	m_pSheet->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);


	// open readme.wzd file using root directory and example name
	CFile file;
	CString msg;

	m_sPath = m_pSheet->m_sSourceRootDir + m_pSheet->m_sExample + "\\Wizard\\";
	CString sFile = m_sPath + "readme.wzd";

	if (!file.Open( sFile, CFile::modeRead))
	{
		msg.Format("Failed to open %s.",sFile);
		AfxMessageBox(msg);
		m_ctrlEditbox.SetWindowText("");
		m_pSheet->SetWizardButtons(PSWIZB_BACK);
		return CPropertyPage::OnSetActive();
	}

	// read readme.wzd file in one large chunk
	char *pBuffer=new char[README_SIZE];
	memset(pBuffer,0,10000);
	if (file.Read(pBuffer,README_SIZE)==README_SIZE)
	{
		AfxMessageBox("Warning--Readme.wzd file too large!");
	}
	CString sBuffer=pBuffer;
	delete []pBuffer;

	// close file
	file.Close();

	// substitute WZD
	SubstituteWzd(sBuffer);
	
	// store in editbox
	m_ctrlEditbox.SetWindowText(sBuffer);

	return CPropertyPage::OnSetActive();
}

BOOL CPage5::OnWizardFinish() 
{
	UpdateData(TRUE);

	// if copy into clipboard, select all of editbox into clipboard
	if (m_bClipboard)
	{
		m_ctrlEditbox.SetSel(0,-1);
		m_ctrlEditbox.Copy();
	}


	// if copy into a target directory
	if (m_bFiles)
	{

		// open wzd.dir file
		CStdioFile file;
		CFileStatus status;
		CString msg;
		CString sFile = m_sPath + "wzd.dir";
		if (!file.Open( sFile, CFile::modeRead | CFile::typeText ))
		{
			AfxMessageBox("No example files to copy.");
			return CPropertyPage::OnWizardFinish();
		}

		// read a file name
		CString sRecord;
		while (file.ReadString(sRecord))
		{
			// open source file
			CStdioFile srcfile;
			CString sSource = m_sPath + sRecord;
			if (!srcfile.Open( sSource, CFile::modeRead | CFile::typeText ))
			{
				msg.Format("%Could not copy %s",sSource);
				AfxMessageBox(msg);
				continue;
			}

			// substitute WZD in filename
			SubstituteWzd(sRecord);

			// create filename in target--if exist, ask to overwrite
			CString sTarget = m_pSheet->m_sTargetDir + sRecord;
			if (CFile::GetStatus(sTarget,status))
			{
				msg.Format("%s already exists. Overwrite?",sTarget);
				if (AfxMessageBox(msg, MB_YESNO)!=IDYES)
				{
					srcfile.Close();
					continue;
				}
			}

			// create and open file for write
			CFileException e; 
			CStdioFile trgfile;
retry:
			if( !trgfile.Open( sTarget, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &e ))
			{
				if (e.m_cause==CFileException::badPath)
				{
					if (AfxMessageBox("Target path does not exist. Create?",MB_YESNO)==IDYES)
					{
						if (_mkdir(m_pSheet->m_sTargetDir))
						{
							AfxMessageBox("Could not create target path!");
							goto exit;
						}
						goto retry;
					}
				}
				msg.Format("Failed to create %s.",sFile);
				srcfile.Close();
				continue;
			}

			// copy file over
			CString sLine;
			while (srcfile.ReadString(sLine))
			{
				SubstituteWzd(sLine);
				sLine+="\n";
				trgfile.WriteString(sLine);
			}
			srcfile.Close();
			trgfile.Close();
		}
exit:
		file.Close();
	}
	
	return CPropertyPage::OnWizardFinish();
}

void CPage5::SubstituteWzd(CString &str)
{
	int i;
	CString in,tmp;
	in=tmp=str;
	str="";
	tmp.MakeLower();
	while ((i=tmp.Find("wzd"))>-1)
	{
		str+=in.Left(i);
		if (in[i]=='w')
			str+=m_pSheet->m_sLowerSub;
		else if (in[i+1]=='Z')
			str+=m_pSheet->m_sUpperSub;
		else
			str+=m_pSheet->m_sSubstitution;
		tmp=in.Right(in.GetLength()-i-3);
		in=tmp;
		tmp.MakeLower();
	}
	str+=in;
}
