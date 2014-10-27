// StylsVw.cpp : implementation of the CStylesView class
//

#include "stdafx.h"
#include "Styles.h"

#include "StylsDoc.h"
#include "StylsVw.h"

#include "BttnDlg.h"
#include "AnimtDlg.h" 
#include "CalDlg.h" 
#include "Combodlg.h" 
#include "datetime.h" 
#include "editdlg.h" 
#include "XtCmbDlg.h" 
#include "HdrDlg.h" 
#include "listbox.h" 
#include "listview.h" 
#include "ProgDlg.h" 
#include "ScrllDlg.h" 
#include "SldrDlg.h" 
#include "spindlg.h" 
#include "StaticDlg.h" 
#include "tabdlg.h" 
#include "TrVwDlg.h" 
#include "testdlg.h"
#include "Pln1Dlg.h"
#include "Pln2Dlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStylesView

IMPLEMENT_DYNCREATE(CStylesView, CView)

BEGIN_MESSAGE_MAP(CStylesView, CView)
	//{{AFX_MSG_MAP(CStylesView)
	ON_COMMAND(IDC_BUTTON_STYLES, OnButtonStyles)
	ON_COMMAND(ID_STYLES_ANIMATION, OnStylesAnimation)
	ON_COMMAND(ID_STYLES_CALENDER, OnStylesCalender)
	ON_COMMAND(ID_STYLES_COMBOS, OnStylesCombos)
	ON_COMMAND(ID_STYLES_DATETIME, OnStylesDatetime)
	ON_COMMAND(ID_STYLES_EDITS, OnStylesEdits)
	ON_COMMAND(ID_STYLES_EXTENDEDCOMBO, OnStylesExtendedcombo)
	ON_COMMAND(ID_STYLES_HEADER, OnStylesHeader)
	ON_COMMAND(ID_STYLES_LISTBOXES, OnStylesListboxes)
	ON_COMMAND(ID_STYLES_LISTVIEW, OnStylesListview)
	ON_COMMAND(ID_STYLES_PROGRESS, OnStylesProgress)
	ON_COMMAND(ID_STYLES_SCROOLBARS, OnStylesScroolbars)
	ON_COMMAND(ID_STYLES_SLIDER, OnStylesSlider)
	ON_COMMAND(ID_STYLES_SPIN, OnStylesSpin)
	ON_COMMAND(ID_STYLES_STATICS, OnStylesStatics)
	ON_COMMAND(ID_STYLES_TAB, OnStylesTab)
	ON_COMMAND(ID_STYLES_TREEVIEW, OnStylesTreeview)
	ON_COMMAND(ID_STYLES_PLAIN1, OnStylesPlain1)
	ON_COMMAND(ID_STYLES_PLAIN2, OnStylesPlain2)
	ON_COMMAND(ID_STYLES_DIALOG, OnStylesDialog)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStylesView construction/destruction

CStylesView::CStylesView()
{
	// TODO: add construction code here

}

CStylesView::~CStylesView()
{
}

BOOL CStylesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStylesView drawing

void CStylesView::OnDraw(CDC* pDC)
{
	CStylesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStylesView printing

BOOL CStylesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStylesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStylesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStylesView diagnostics

#ifdef _DEBUG
void CStylesView::AssertValid() const
{
	CView::AssertValid();
}

void CStylesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStylesDoc* CStylesView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStylesDoc)));
	return (CStylesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStylesView message handlers

void CStylesView::OnButtonStyles() 
{
	CButtonDlg dlg;
	dlg.DoModal();
}

void CStylesView::OnStylesAnimation() 
{
	CAnimateDlg dlg; 
	dlg.DoModal();
}

void CStylesView::OnStylesCalender() 
{
	CCalenderDlg dlg; 
	dlg.DoModal();
}

void CStylesView::OnStylesCombos() 
{
	CComboDlg dlg; 
	dlg.DoModal();
	
}
void CStylesView::OnStylesDatetime() 
{
	CDateTimeDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesEdits() 
{
	CEditDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesExtendedcombo() 
{
	CExtComboDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesHeader() 
{
	CHeaderDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesListboxes() 
{
	CListboxDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesListview() 
{
	CListViewDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesProgress() 
{
	CProgressDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesScroolbars() 
{
	CScrollDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesSlider() 
{
	CSliderDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesSpin() 
{
	CSpinDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesStatics() 
{
	CStaticDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesTab() 
{
	CTabDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesTreeview() 
{
	CTreeViewDlg dlg; 
	dlg.DoModal();
	
}

void CStylesView::OnStylesPlain1() 
{
	CPlain1Dlg dlg;
	dlg.DoModal();
}

void CStylesView::OnStylesPlain2() 
{
	CPlain2Dlg dlg;
	dlg.DoModal();
}

void CStylesView::OnStylesDialog() 
{
	CTestDlg dlg;
	dlg.DoModal();
}
