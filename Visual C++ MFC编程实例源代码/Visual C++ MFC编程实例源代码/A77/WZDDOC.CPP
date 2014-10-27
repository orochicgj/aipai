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

//////////////////////////////
// Map of Classes using Int //
//////////////////////////////
	CWzdInfo info1("first",1);
	CWzdInfo info2("new",1);
	CWzdInfo info3("newer",1);

	// add to class list
	m_WzdClassArray.SetSize(10);
	m_WzdClassArray[2]=info1;
	m_WzdClassArray[3]=info2;
	m_WzdClassArray[9]=info3;

	// iterate the class map
	CWzdInfo info;
	for (int i=0;i<m_WzdClassArray.GetUpperBound();i++)
	{
		info=m_WzdClassArray[i];

		/////

	}

	// remove from class map
	info=m_WzdClassArray[3];
	m_WzdClassArray.RemoveAt(3);

	// destroy map of classes and their objects
	m_WzdClassArray.RemoveAll(); // or just let it deconstruct itself


/////////////////////////
// Array of Pointers /////
/////////////////////////
	CWzdInfo *pInfo;

	// add to array of pointers
	m_WzdPtrArray.SetSize(10);
	m_WzdPtrArray[4]=new CWzdInfo("eight",10);
	m_WzdPtrArray[6]=new CWzdInfo("nine",14);
	m_WzdPtrArray[8]=new CWzdInfo("ten",14);


	// iterate the pointer array
	for (i=0;i<m_WzdPtrArray.GetUpperBound();i++)
	{
		pInfo=m_WzdPtrArray[i];

		/////

	}

	// remove from pointer array
	pInfo=m_WzdPtrArray[6];
	m_WzdPtrArray.RemoveAt(6);

	// (make sure you delete this object at some point)
	delete pInfo;

	// destroy an array of pointers and the objects they point to
	while (m_WzdPtrArray.GetUpperBound()>-1)
	{
		delete m_WzdPtrArray[0];
		m_WzdPtrArray.RemoveAt(0);
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
