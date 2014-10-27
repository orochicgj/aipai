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
	ON_UPDATE_COMMAND_UI(ID_WZD1_BUTTON, OnUpdateWzd1Button)
	ON_UPDATE_COMMAND_UI(ID_WZD2_BUTTON, OnUpdateWzd2Button)
	ON_UPDATE_COMMAND_UI(ID_WZD3_BUTTON, OnUpdateWzd3Button)
	ON_COMMAND(ID_WZD1_BUTTON, OnWzd1Button)
	ON_COMMAND(ID_WZD2_BUTTON, OnWzd2Button)
	ON_COMMAND(ID_WZD3_BUTTON, OnWzd3Button)
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
	m_nWzdMode=CWzdView::mode1;
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

void CWzdView::OnUpdateWzd1Button(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_nWzdMode==CWzdView::mode1);
}

void CWzdView::OnUpdateWzd2Button(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_nWzdMode==CWzdView::mode2);
}

void CWzdView::OnUpdateWzd3Button(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_nWzdMode==CWzdView::mode3);
}

void CWzdView::OnWzd1Button() 
{
	m_nWzdMode=CWzdView::mode1;
}

void CWzdView::OnWzd2Button() 
{
	m_nWzdMode=CWzdView::mode2;
}

void CWzdView::OnWzd3Button() 
{
	m_nWzdMode=CWzdView::mode3;
}
