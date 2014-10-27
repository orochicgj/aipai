// StylsDoc.cpp : implementation of the CStylesDoc class
//

#include "stdafx.h"
#include "Styles.h"

#include "StylsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStylesDoc

IMPLEMENT_DYNCREATE(CStylesDoc, CDocument)

BEGIN_MESSAGE_MAP(CStylesDoc, CDocument)
	//{{AFX_MSG_MAP(CStylesDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStylesDoc construction/destruction

CStylesDoc::CStylesDoc()
{
	// TODO: add one-time construction code here

}

CStylesDoc::~CStylesDoc()
{
}

BOOL CStylesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStylesDoc serialization

void CStylesDoc::Serialize(CArchive& ar)
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
// CStylesDoc diagnostics

#ifdef _DEBUG
void CStylesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStylesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStylesDoc commands
