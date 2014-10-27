// WzdDoc.cpp : implementation of the CWzdDoc class
//

#include "stdafx.h"
#include "Wzd.h"

#include "WzdDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdDoc

IMPLEMENT_DYNCREATE(CWzdDoc, CDocument)

BEGIN_MESSAGE_MAP(CWzdDoc, CDocument)
	//{{AFX_MSG_MAP(CWzdDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDoc construction/destruction

CWzdDoc::CWzdDoc()
{
	// TODO: add one-time construction code here

}

CWzdDoc::~CWzdDoc()
{
}

BOOL CWzdDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;


	// open database
	if(!m_WzdDatabase.Open(
			NULL,								// Data source name, NULL if defined in DSN= below
			FALSE,								// exclusive access, NOT SUPPORTED, should always be false
			FALSE,								// read only access
			"ODBC;DSN=MS Access 97 Database")	// connect string DSN= is data source name,
												// UID= is user id, PSW= is password
			)
	{
		AfxMessageBox("Failed to open database.");
	}
	
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWzdDoc serialization

void CWzdDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWzdDoc diagnostics

#ifdef _DEBUG
void CWzdDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWzdDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWzdDoc commands

void CWzdDoc::DeleteContents() 
{
	// close database
	m_WzdDatabase.Close();
	
	CDocument::DeleteContents();
}
