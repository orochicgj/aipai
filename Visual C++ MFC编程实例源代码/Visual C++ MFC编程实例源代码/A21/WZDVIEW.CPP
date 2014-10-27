// WzdView.cpp : implementation of the CWzdView class
//

#include "stdafx.h"
#include "resource.h"
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
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDC_WZD1_TYPE, OnWzd1Type)
	ON_COMMAND(IDC_WZD2_TYPE, OnWzd2Type)
	ON_COMMAND(IDC_WZD3_TYPE, OnWzd3Type)
	ON_COMMAND(IDC_WZD4_TYPE, OnWzd4Type)
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

void CWzdView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// create popup menu
	CMenu menu;
	menu.CreatePopupMenu();
   
	// add plain menu item
	menu.AppendMenu(0, IDC_WZD1_TYPE, "Wzd&1");

	// add menu item with check mark
	menu.AppendMenu(MF_CHECKED, IDC_WZD2_TYPE, "Wzd&2");

	// add a separator
	menu.AppendMenu(MF_SEPARATOR, 0, "");

	// add a disabled(greyed) menu item
	menu.AppendMenu(MF_GRAYED, IDC_WZD3_TYPE, "Wzd&3");

	// add menu item with check mark
	menu.AppendMenu(0, IDC_WZD4_TYPE, "Wzd&4");
	menu.CheckMenuRadioItem(IDC_WZD3_TYPE,IDC_WZD4_TYPE,IDC_WZD4_TYPE,MF_BYCOMMAND);

	// display popup menu at cursor position
	CPoint pt;
	GetCursorPos(&pt); 
	menu.TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);

	// destroy menu
	menu.DestroyMenu();

	// load a menu from the resources
	menu.LoadMenu(IDR_WZD_MENU);

	// get a pointer to actual popup menu
	CMenu* pPopup = menu.GetSubMenu(0);

	// disable a menu item entry by menu command
	pPopup->EnableMenuItem( ID_POPUP_WZD1, MF_BYCOMMAND|MF_GRAYED );

	// check a menu item by zero based position
	pPopup->CheckMenuItem( 2,MF_BYPOSITION|MF_CHECKED);

	// and display at current point
	GetCursorPos(&pt); 
	pPopup->TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);

	// and destroy
	menu.DestroyMenu();

	CView::OnRButtonDown(nFlags, point);
}

void CWzdView::OnWzd1Type() 
{
	// TODO: Add your command handler code here
}

void CWzdView::OnWzd2Type() 
{
	// TODO: Add your command handler code here
	
}

void CWzdView::OnWzd3Type() 
{
	// TODO: Add your command handler code here
	
}

void CWzdView::OnWzd4Type() 
{
	// TODO: Add your command handler code here
	
}
