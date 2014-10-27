// WzdView.cpp : implementation of the CWzdView class
//

#include "stdafx.h"
#include "Wzd.h"

#include "WzdDoc.h"
#include "WzdView.h"
#include "WzdInfo1.h"
#include "WzdInfo2.h"

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
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_TEST_SELECT, OnTestSelect)
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
	// create some dummy data
	CWzdInfo1 *pInfo;

	pInfo=new CWzdInfo1;
	pInfo->m_sGroupName="Test Group Name 1";
	pInfo->m_sComment="Test Comment 1";
	pInfo->m_WzdInfo2List.AddTail(new CWzdInfo2("Name1",0));
	pInfo->m_WzdInfo2List.AddTail(new CWzdInfo2("Name2",0));
	GetDocument()->GetInfo1List()->AddTail(pInfo);

	pInfo=new CWzdInfo1;
	pInfo->m_sGroupName="Test Group Name 2";
	pInfo->m_sComment="Test Comment 2";
	pInfo->m_WzdInfo2List.AddTail(new CWzdInfo2("Name3",0));
	GetDocument()->GetInfo1List()->AddTail(pInfo);

	GetDocument()->SetModifiedFlag(TRUE);

}


void CWzdView::OnTestSelect() 
{
	m_select.Select(GetDocument()->GetInfo1List()->GetHead());
}


void CWzdView::OnEditCut() 
{
	m_select.CutSelections(GetDocument()->GetInfo1List());
}

void CWzdView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_select.SelectionCount());
}

void CWzdView::OnEditCopy() 
{
	m_select.CopySelections();
}

void CWzdView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_select.SelectionCount());
}

void CWzdView::OnEditPaste() 
{
	m_select.PasteClipboard(GetDocument()->GetInfo1List());
}

void CWzdView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_select.CanPasteClipboard());
}
