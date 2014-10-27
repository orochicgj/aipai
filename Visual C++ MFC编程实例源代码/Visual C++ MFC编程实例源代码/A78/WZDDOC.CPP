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

/////////////////////
// List of Classes //
/////////////////////
	CWzdInfo info;
	CWzdInfo info1("first",1);
	CWzdInfo info2("new",1);
	CWzdInfo info3("newer",1);

	// add to class list
	m_WzdList.AddTail(info1);
	m_WzdList.AddHead(info2);
	m_WzdList.AddHead(info3);

	// iterate the class list
	for (POSITION pos=m_WzdList.GetHeadPosition();pos;)
	{
		info=m_WzdList.GetNext(pos);

		/////
	}

	// find 2nd element in list
	pos=m_WzdList.FindIndex(1);

	// remove from class list
	info=m_WzdList.GetAt(pos);
	m_WzdList.RemoveAt(pos);


	// destroy list of classes and their objects
	m_WzdList.RemoveAll(); // or just let it deconstruct itself


/////////////////////////
// List of Pointers /////
/////////////////////////

	CWzdInfo *pInfo;

	// add to list of pointers
	m_WzdPtrList.AddTail(new CWzdInfo("eight",10));
	m_WzdPtrList.AddHead(new CWzdInfo("nine",14));
	m_WzdPtrList.AddHead(new CWzdInfo("ten",14));


	// iterate the pointer list
	for (pos=m_WzdPtrList.GetHeadPosition();pos;)
	{
		CWzdInfo *pInfo=m_WzdPtrList.GetNext(pos);

		/////
	}

	// find 2nd element in list
	pos=m_WzdPtrList.FindIndex(1);

	// remove from class list
	pInfo=m_WzdPtrList.GetAt(pos);
	m_WzdPtrList.RemoveAt(pos);

	// (make sure you delete this object at some point)
	delete pInfo;

	// destroy a list of pointers and the objects they point to
	while (!m_WzdPtrList.IsEmpty())
	{
		delete m_WzdPtrList.RemoveHead();
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
