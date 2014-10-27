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
	ON_COMMAND(IDC_WZD_TYPE, OnWzdType)
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
	// Get the Main Menu
	CMenu* pMainMenu = AfxGetMainWnd()->GetMenu();

	// Get the Options submenu
	CMenu* pSubMenu = NULL;
	for (int i=0; i<(int)pMainMenu->GetMenuItemCount(); i++)//最顶层菜单循环
	{
		pSubMenu = pMainMenu->GetSubMenu(i);//在子菜单项中循环查找
		if (pSubMenu && pSubMenu->GetMenuItemID(0) == IDC_WZD_TYPE)
		{
			break;
		}
	}
	ASSERT(pSubMenu);

	// Append a IDC_WZD2_TYPE command called "Wzd2"
	pSubMenu->AppendMenu(0,IDC_WZD2_TYPE,"Wzd&2");

	// Insert a IDC_WZD3_TYPE command called "Wzd3" before IDC_WZD2_TYPE
	pSubMenu->InsertMenu(IDC_WZD2_TYPE,MF_BYCOMMAND,IDC_WZD3_TYPE,"Wzd&3");


	// Make "Wzd2" into "Wzd4"
	pSubMenu->ModifyMenu(IDC_WZD2_TYPE,MF_BYCOMMAND,IDC_WZD4_TYPE,"Wzd&4");


	// Remove the 2nd menu item (zero based)
	//很显然，当第一次点击此菜单项后，此句删除了IDC_WZD3_TYPE command called "Wzd3"
	pSubMenu->RemoveMenu(1,MF_BYPOSITION);
}
