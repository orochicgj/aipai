// WzdView.cpp : implementation of the CWzdView class
//

#include "stdafx.h"
#include "Wzd.h"

#include "WzdDoc.h"
#include "WzdView.h"

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
	ON_COMMAND(ID_WZD_TYPE, OnWzdType)
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

void CWzdView::OnWzdType() 
{
	CString msg;
	CString sFilename("wzd.tmp");

	// simple message
	AfxMessageBox("Hello");

	// simple message using resource string
	AfxMessageBox(IDS_HELLO);

	// stick text strings in a resource string to create a message
	//  example: IDS_HELLO_1 is "Hello %1"
	AfxFormatString1( msg, IDS_HELLO_1, "Goodbye");
	AfxMessageBox(msg);


	// same as above but two input strings are allowed
	// example: IDS_HELLO_2 is "Hello %1 %2"
	AfxFormatString2(msg, IDS_HELLO_2, "and", "Goodbye");
	AfxMessageBox(msg);

	// simple prompt
	msg.Format("Delete this file:\n%s?",sFilename);
	if (AfxMessageBox(msg, MB_YESNO)==IDYES)
	{
	}
	// also available: MB_ABORTRETRYIGNORE,MB_OKCANCEL,MB_RETRYCANCEL,MB_YESNO,MB_YESNOCANCEL
	// for the test: IDNO, IDABORT, IDCANCEL, IDIGNORE, IDOK and IDRETRY

	// prompt with yes/no/cancel and no as the default button
	if (AfxMessageBox(msg,MB_YESNO|MB_DEFBUTTON2)==IDYES)
	{
	}
	// also avalable: MB_DEFBUTTON3


	// change exclamation point to an error sign
	AfxMessageBox(msg,MB_ICONSTOP);
	//also available MB_ICONINFORMATION and MB_ICONQUESTION

}
