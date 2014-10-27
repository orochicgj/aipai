// WzdView.cpp : implementation of the CWzdView class
//

#include "stdafx.h"
#include "Wzd.h"

#include "WzdDoc.h"
#include "WzdView.h"
#include "WzdRSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdView

IMPLEMENT_DYNCREATE(CWzdView, CView)

BEGIN_MESSAGE_MAP(CWzdView, CView)
	//{{AFX_MSG_MAP(CWzdView)
	ON_COMMAND(ID_TEST_WZD, OnTestWzd)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdView construction/destruction

CWzdView::CWzdView()
{
	// TODO: add construction code here

}

CWzdView::~CWzdView()
{
}

BOOL CWzdView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWzdView drawing

void CWzdView::OnDraw(CDC* pDC)
{
	CWzdDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CWzdView printing

BOOL CWzdView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWzdView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWzdView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWzdView diagnostics

#ifdef _DEBUG
void CWzdView::AssertValid() const
{
	CView::AssertValid();
}

void CWzdView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWzdDoc* CWzdView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWzdDoc)));
	return (CWzdDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWzdView message handlers

void CWzdView::OnTestWzd() 
{
// create record set object
	CWzdRecordSet wzdSet(GetDocument()->GetDatabase());

// open all records in table
	wzdSet.Open();

// scroll through records
	while (! wzdSet.IsEOF())
	{
		// values can be accessed from record set member variables:
		//		wzdSet.m_CustomerID  
		//		wzdSet.m_CompanyName 
		//		wzdSet.m_ContactName 
		//			etc.

		wzdSet.MoveNext();
	}

// if we can't update or append records, leave now
	if (!wzdSet.CanUpdate() || !wzdSet.CanAppend())
		return;

// add a record
	try
	{
		// add new record
		wzdSet.AddNew();

		// initialize each field
		wzdSet.m_CustomerID="ABCDE";
		wzdSet.m_CompanyName="ABC Inc.";
		//etc.

		// update database
		wzdSet.Update();
	}
	catch (CDBException *e)
	{
		// AddNew failed
 		AfxMessageBox(e->m_strError);
		e->Delete();
	}

// edit a record
	wzdSet.MoveFirst();
	try
	{
		wzdSet.Edit();

		// update affected fields
		wzdSet.m_CompanyName="ABCEF Inc.";
		wzdSet.m_ContactName="Frank";
		//etc.

		// update database
		wzdSet.Update();
	}
	catch (CDBException *e)
	{
		// Edit failed
 		AfxMessageBox(e->m_strError);
		e->Delete();
	}


// delete a record
	try
	{
		// delete record to which we're currently opened
		wzdSet.Delete();
	}
	catch (CDBException *e)
	{
		// Delete failed
 		AfxMessageBox(e->m_strError);
		e->Delete();
	}

// close record set
	wzdSet.Close();

///////////////////////////////////
// RECORD FILTERING         ///////
///////////////////////////////////
// open record set with a simple "WHERE" SQL filter
	wzdSet.m_strFilter = "[Country]='UK'";
	if(!wzdSet.Open() || wzdSet.IsEOF())
	{
		AfxMessageBox("Cannot find records.");
	}

	// scroll through records as above...
	while (! wzdSet.IsEOF())
	{
		wzdSet.MoveNext();
	}
	wzdSet.Close();


	// open a record set with a complete SQL SELECT statement
	wzdSet.m_strFilter = ""; // appended to the following!
	if (!wzdSet.Open(AFX_DB_USE_DEFAULT_TYPE,
	 	"SELECT [CustomerID], [CompanyName], [ContactName], \
[ContactTitle], [Address], [City], [Region], [PostalCode], [Country], [Phone], [Fax] \
FROM [Customers] WHERE [Country] = 'Mexico'") ||
			wzdSet.IsEOF())
	{
		AfxMessageBox("Cannot find records.");
	}

	// scroll through records as above...
	while (! wzdSet.IsEOF())
	{
		wzdSet.MoveNext();
	}
	wzdSet.Close();

////////////////////////////////////
// MULTIPLE TABLE TRANSACTIONS /////
////////////////////////////////////

// NOTE: when performing related operations on more then one database
// table at a time, an error in any one of these transactions should undo
// or "rollback" all of the changes made

	// Create a transaction we can rollback
	GetDocument()->GetDatabase()->BeginTrans();
	try
	{
		// perform transactions on several database tables/records
		wzdSet.Open();
		wzdSet.Update();
		// Success
		GetDocument()->GetDatabase()->CommitTrans();
	}
	catch (CDBException *e)
	{
		// An exception occurred, rollback the transaction
		GetDocument()->GetDatabase()->Rollback();
 		AfxMessageBox(e->m_strError);
		e->Delete();
	}
	// since this was allocated on stack, returning will also close record set
	wzdSet.Close(); 


}
