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
	ON_UPDATE_COMMAND_UI(IDC_WZD1_TYPE, OnUpdateWzd1Type)
	ON_UPDATE_COMMAND_UI(IDC_WZD2_TYPE, OnUpdateWzd2Type)
	ON_UPDATE_COMMAND_UI(IDC_WZD3_TYPE, OnUpdateWzd3Type)
	ON_COMMAND(IDC_WZD1_TYPE, OnWzd1Type)
	ON_COMMAND(IDC_WZD2_TYPE, OnWzd2Type)
	ON_COMMAND(IDC_WZD3_TYPE, OnWzd3Type)
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

void CWzdView::OnUpdateWzd1Type(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_nWzdMode==CWzdView::mode1);
}

void CWzdView::OnUpdateWzd2Type(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_nWzdMode==CWzdView::mode2);
}

void CWzdView::OnUpdateWzd3Type(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio(m_nWzdMode==CWzdView::mode3);
}

void CWzdView::OnWzd1Type() 
{
	m_nWzdMode=CWzdView::mode1;
}

void CWzdView::OnWzd2Type() 
{
	m_nWzdMode=CWzdView::mode2;
}

void CWzdView::OnWzd3Type() 
{
	m_nWzdMode=CWzdView::mode3;
}
