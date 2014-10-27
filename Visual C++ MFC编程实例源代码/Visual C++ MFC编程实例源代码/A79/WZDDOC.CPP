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

	// add to map
	m_WzdIntToClassMap[2]=info1;
	m_WzdIntToClassMap[3]=info2;
	m_WzdIntToClassMap[9]=info3;

	// iterate the map
	int i;
	CWzdInfo info;
	for (POSITION pos = m_WzdIntToClassMap.GetStartPosition(); pos;)
	{
		m_WzdIntToClassMap.GetNextAssoc(pos,i,info);

		// i contains key
		// info contains data

	}

	// remove from class map
	info=m_WzdIntToClassMap[3];
	m_WzdIntToClassMap.RemoveKey(3);

	// destroy map of classes and their objects
	m_WzdIntToClassMap.RemoveAll(); // or just let it deconstruct itself


/////////////////////////
// Map of Pointers /////
/////////////////////////
	{

	CWzdInfo *pInfo;

	// add to string map
	m_WzdStringToPtrMap["them"]=new CWzdInfo("eight",10);
	m_WzdStringToPtrMap["these"]=new CWzdInfo("nine",14);
	m_WzdStringToPtrMap["those"]=new CWzdInfo("ten",14);


	// iterate the map
	CString str;
	for (POSITION pos = m_WzdStringToPtrMap.GetStartPosition(); pos;)
	{
		m_WzdStringToPtrMap.GetNextAssoc(pos,str,pInfo);

		// str contains key
		// pInfo contains pointer to data

	}

	// remove from map
	pInfo=m_WzdStringToPtrMap["them"];
	m_WzdStringToPtrMap.RemoveKey("them");

	// (make sure you delete this object at some point)
	delete pInfo;

	// destroy this map and the objects it points to
	for (pos = m_WzdStringToPtrMap.GetStartPosition(); pos;)
	{
		m_WzdStringToPtrMap.GetNextAssoc(pos,str,pInfo);
		m_WzdStringToPtrMap.RemoveKey(str);
		delete pInfo;
	}

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
