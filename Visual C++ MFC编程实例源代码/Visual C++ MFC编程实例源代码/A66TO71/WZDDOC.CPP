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

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CWzdDoc serialization

void CWzdDoc::Serialize(CArchive& ar)
{
	int nCount;
	if (ar.IsStoring())
	{
		nCount = m_WzdInfo1List.GetCount();
		ar << nCount;
		for (POSITION pos = m_WzdInfo1List.GetHeadPosition(); pos; )
		{
			CWzdInfo1 *pInfo = m_WzdInfo1List.GetNext(pos);
			pInfo->Serialize(ar);
		}
	}
	else
	{
		ar >> nCount;
		while (nCount-- > 0)
		{
			CWzdInfo1* pInfo = new CWzdInfo1;
			pInfo->Serialize(ar);
			m_WzdInfo1List.AddTail(pInfo);
		}
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
	// called with new and open document
	// opportunity to initialize the data collections that make up our document
	while (!m_WzdInfo1List.IsEmpty())
	{
		delete m_WzdInfo1List.RemoveHead();
	}


	CDocument::DeleteContents();
}
