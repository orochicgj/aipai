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
	while (!m_listInfo.IsEmpty())
	{
		delete m_listInfo.RemoveHead();
	}
}

BOOL CWzdDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_listInfo.AddHead(new CWzdInfo("Bill","Short comment",CWzdInfo::OLD));
	m_listInfo.AddHead(new CWzdInfo("John","Long comment",CWzdInfo::DELETED));
	m_listInfo.AddHead(new CWzdInfo("Ted","Medium comment",CWzdInfo::NEW));
	m_listInfo.AddHead(new CWzdInfo("Modified","Modified comment",CWzdInfo::MODIFIED));
	UpdateAllViews(NULL);

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
