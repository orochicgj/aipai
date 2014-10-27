// SampleWzdSheet.cpp : implementation file
//

#include "stdafx.h"
#include <direct.h>
#include "SampWzd.h"
#include "SampWzdS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSampleWzdSheet

IMPLEMENT_DYNAMIC(CSampleWzdSheet, CPropertySheet)

CSampleWzdSheet::CSampleWzdSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CSampleWzdSheet::CSampleWzdSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_Page1);
	AddPage(&m_Page2);
	AddPage(&m_Page3);
	AddPage(&m_Page4);
	AddPage(&m_Page5);
	SetWizardMode();
}

CSampleWzdSheet::~CSampleWzdSheet()
{
	for (int i=0;i<m_samples.GetSize();i++)
	{
		delete m_samples[i]->pName;
		CSAMPLEARRAY *pChapter=m_samples[i]->pSamples;
		for (int j=0;j<pChapter->GetSize();j++)
		{
			SAMPLES *pCSamples=(*pChapter)[j];
			delete pCSamples->pName;
			CSAMPLEARRAY *pExamples=pCSamples->pSamples;
			for (int k=0;k<pExamples->GetSize();k++)
			{
				SAMPLES *pESamples=(*pExamples)[k];
				delete pESamples->pName;
				delete pESamples;
			}
			delete pExamples;
			delete pCSamples;
		}
		delete pChapter;
		delete m_samples[i];
	}
}


BEGIN_MESSAGE_MAP(CSampleWzdSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CSampleWzdSheet)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSampleWzdSheet message handlers

int CSampleWzdSheet::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CPropertySheet::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	
	// open SampWzd.ini
	CStdioFile file;
	CString sPath,sFile,sRecord;
	char szBuffer[128];
	::GetModuleFileName(AfxGetInstanceHandle(), szBuffer, sizeof(szBuffer));
	char *p=strrchr( szBuffer, '\\')+1;
	*p=0;
	sPath=szBuffer;
	sFile=sPath+"SampWzd.ini";
	if (!file.Open( sFile, CFile::modeRead | CFile::typeText ))
	{
		CString msg;
		msg.Format("Failed to open %s.",sFile);
		AfxMessageBox(msg);
		return TRUE;  // return TRUE  unless you set the focus to a control
	}

	// read next section
	while (file.ReadString(sRecord))
	{
		sRecord.TrimLeft();
		if (!sRecord.GetLength()||sRecord[0]=='{'||sRecord[0]=='}'||sRecord[0]==';') continue;

		SAMPLES *pSection=new SAMPLES;
		pSection->pName=new CString;
		*pSection->pName=sRecord;
		pSection->pSamples=new CSAMPLEARRAY;

		m_samples.Add(pSection);

		// read next chapter
		while (file.ReadString(sRecord))
		{
			sRecord.TrimLeft();
			if (!sRecord.GetLength()||sRecord[0]=='{'||sRecord[0]==';') continue;
			if (sRecord[0]=='}') break;

			SAMPLES *pChapter=new SAMPLES;
			pChapter->pName=new CString;
			*pChapter->pName=sRecord;
			pChapter->pSamples=new CSAMPLEARRAY;

			pSection->pSamples->Add(pChapter);

			// read next example
			while (file.ReadString(sRecord))
			{
				sRecord.TrimLeft();
				if (!sRecord.GetLength()||sRecord[0]=='{'||sRecord[0]==';') continue;
				if (sRecord[0]=='}') break;

				SAMPLES *pExample=new SAMPLES;
				pExample->pName=new CString;
				*pExample->pName=sRecord;

				pChapter->pSamples->Add(pExample);
			}
		}
	}

	// close file
	file.Close();
	
	return 0;
}

BOOL CSampleWzdSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();

	GetDlgItem(9)->ShowWindow(SW_HIDE); // hide the help button
										// the id of 9 was found using Spy.exe

	// get directory of SampleWizard's exe file
	char szBuffer[128];
	::GetModuleFileName(AfxGetInstanceHandle(), szBuffer, sizeof(szBuffer));
	char *p=strrchr( szBuffer, '\\')+1;
	*p=0;
	m_sExeDir=szBuffer;

	// get current working directory
	_getcwd(szBuffer, sizeof(szBuffer));
	m_sCwdDir=szBuffer;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
