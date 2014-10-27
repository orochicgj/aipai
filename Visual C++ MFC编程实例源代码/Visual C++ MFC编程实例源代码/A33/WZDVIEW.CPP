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
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_WZD_DRAWMODE, OnWzdDrawmode)
	ON_UPDATE_COMMAND_UI(ID_WZD_DRAWMODE, OnUpdateWzdDrawmode)
	ON_WM_LBUTTONDOWN()
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
	m_bDrawMode=FALSE;	
}

CWzdView::~CWzdView()
{
}

BOOL CWzdView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS,
						AfxGetApp()->LoadStandardCursor(IDC_CROSS),
						(HBRUSH)(COLOR_WINDOW+1),
						AfxGetApp()->LoadIcon(IDR_MAINFRAME));

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

BOOL CWzdView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if 	(m_bDrawMode)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_DRAW_CURSOR));
		return TRUE;
	}

	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CWzdView::OnWzdDrawmode() 
{
	m_bDrawMode=!m_bDrawMode;
}

void CWzdView::OnUpdateWzdDrawmode(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bDrawMode);
}

void CWzdView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	::SetCursor(AfxGetApp()->LoadCursor(IDC_DRAW_CURSOR1));
	
	CView::OnLButtonDown(nFlags, point);
}
