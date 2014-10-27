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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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

	// create a pen
	CPen pen(PS_SOLID,2,RGB(128,128,128));
	pDC->SelectObject(pen);

	// create a brush
	CBrush brush(RGB(0,255,0));
	pDC->SelectObject(brush);

	pDC->SetBkMode(TRANSPARENT);

	// draw a line
	pDC->MoveTo(5,5);
	pDC->LineTo(25,25);
	pDC->TextOut(5,30,CString("CDC::MoveTo()/CDC::LineTo()"));

	// rectangle
	pDC->Rectangle(CRect(5,55,50,85));
	pDC->TextOut(5,90,CString("CDC::Rectangle()"));

	pDC->Arc(CRect(5,115,50,145),CPoint(5,115),CPoint(50,115));
	pDC->TextOut(5,150,CString("CDC::Arc()"));

	pDC->RoundRect(CRect(5,185,50,215),CPoint(15,15));
	pDC->TextOut(5,220,CString("CDC::RoundRect()"));

	pDC->Ellipse(CRect(250,5,305,25));
	pDC->TextOut(250,30,CString("CDC::Ellipse()"));

	pDC->Pie(CRect(250,55,305,85),CPoint(250,55),CPoint(305,55));
	pDC->TextOut(250,90,CString("CDC::Pie()"));

 	pDC->DrawEdge( CRect(250,115,305,145),
			EDGE_BUMP, //EDGE_ETCHED,EDGE_RAISED,EDGE_SUNKEN
			BF_RECT ); //BF_LEFT,BF_BOTTOM,BF_RIGHT,BF_TOP  
	pDC->TextOut(250,150,CString("CDC::DrawEdge(EDGE_BUMP)"));

 	pDC->DrawEdge( CRect(250,185,305,215),
			EDGE_SUNKEN, //EDGE_ETCHED,EDGE_RAISED,EDGE_BUMP
			BF_RECT ); //BF_LEFT,BF_BOTTOM,BF_RIGHT,BF_TOP  
	pDC->TextOut(250,220,CString("CDC::DrawEdge(EDGE_SUNKEN)"));

	POINT pt[8];
	pt[0].x=495;
	pt[0].y=5;
	pt[1].x=510;
	pt[1].y=10;
	pt[2].x=515;
	pt[2].y=12;
	pt[3].x=495;
	pt[3].y=15;
	pt[4].x=550;
	pt[4].y=25;
 	pDC->Polyline( pt, 5);
	pDC->TextOut(495,30,CString("CDC::Polyline()"));

	pt[0].x=495;
	pt[0].y=55;
	pt[1].x=550;
	pt[1].y=55;
	pt[2].x=530;
	pt[2].y=65;
	pt[3].x=550;
	pt[3].y=85;
	pt[4].x=520;
	pt[4].y=70;
	pt[5].x=495;
	pt[5].y=85;
	pt[6].x=510;
	pt[6].y=65;
	pt[7].x=495;
	pt[7].y=55;
 	pDC->Polygon( pt, 8);
	pDC->TextOut(495,90,CString("CDC::Polygon()"));
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
