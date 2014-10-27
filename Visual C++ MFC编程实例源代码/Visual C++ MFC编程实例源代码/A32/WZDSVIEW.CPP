// WzdSView.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdScrollView

IMPLEMENT_DYNCREATE(CWzdScrollView, CScrollView)

CWzdScrollView::CWzdScrollView()
{
}

CWzdScrollView::~CWzdScrollView()
{
}


BEGIN_MESSAGE_MAP(CWzdScrollView, CScrollView)
	//{{AFX_MSG_MAP(CWzdScrollView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdScrollView drawing

void CWzdScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	sizeTotal.cx = 250; // size required to display image
	sizeTotal.cy = 250; // size required to display image
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CWzdScrollView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();

//	pDC->SetViewportOrg(GetScrollPosition().x,GetScrollPosition().y);

	CPen pen(PS_SOLID,8,RGB(100,100,100));
	CPen *pOPen=pDC->SelectObject(&pen);

	CBrush brush(RGB(0,0,255));
	CBrush *pOBrush=pDC->SelectObject(&brush);

	// draw object(s)
	pDC->Rectangle(50,50,150,150);

	// unselect everything
	pDC->SelectObject(pOPen);
	pDC->SelectObject(pOBrush);

}

/////////////////////////////////////////////////////////////////////////////
// CWzdScrollView diagnostics

#ifdef _DEBUG
void CWzdScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CWzdScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWzdScrollView message handlers
