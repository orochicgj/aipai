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

IMPLEMENT_DYNCREATE(CWzdView, CListView)

BEGIN_MESSAGE_MAP(CWzdView, CListView)
	//{{AFX_MSG_MAP(CWzdView)
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
	m_AveCharWidth=0;
}

CWzdView::~CWzdView()
{
}

BOOL CWzdView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
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
	CListView::AssertValid();
}

void CWzdView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CWzdDoc* CWzdView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWzdDoc)));
	return (CWzdDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWzdView message handlers


void CWzdView::OnInitialUpdate() 
{
	
	m_ImageList.Create(IDB_STATUS_BITMAP, 15, 1, RGB(0,0,0));
	GetListCtrl().SetImageList(&m_ImageList, LVSIL_STATE);
	GetListCtrl().ModifyStyle(0,LVS_REPORT|LVS_SHOWSELALWAYS|LVS_SORTASCENDING);
	GetListCtrl().SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE,0,LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	GetListCtrl().InsertColumn(0,"Name",LVCFMT_LEFT,GetTextExtent(30),0);
	GetListCtrl().InsertColumn(1,"Comment",LVCFMT_LEFT,GetTextExtent(70),1);

	CListView::OnInitialUpdate();
	
}

int CWzdView::GetTextExtent(int len
							   )
{
	CDC* dc = GetDC();
	
	if (! m_AveCharWidth)
	{
		TEXTMETRIC tm;
		dc->GetTextMetrics(&tm);
		m_AveCharWidth = tm.tmAveCharWidth;
	}
	CSize size(m_AveCharWidth * len, 0);
	dc->LPtoDP(&size);
	ReleaseDC(dc);
	return size.cx;
}

void CWzdView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CList<CWzdInfo*,CWzdInfo*> *pList=GetDocument()->GetInfoList();
	GetListCtrl().DeleteAllItems();
	for (POSITION pos = pList->GetHeadPosition(); pos; )
	{
		CWzdInfo *pInfo = pList->GetNext(pos);
		AddItem(-1,pInfo);
	}
}

void CWzdView::AddItem(int i,CWzdInfo *pInfo)
{
	if (i==-1)
	{
		i=GetListCtrl().InsertItem(0, pInfo->m_sName);
	}
	else
	{
		GetListCtrl().SetItemText(i, 0,  pInfo->m_sName);
	}

	GetListCtrl().SetItemText(i, 1,  pInfo->m_sComment);
	GetListCtrl().SetItemData(i,(DWORD)pInfo);
	GetListCtrl().SetItemState(i, INDEXTOSTATEIMAGEMASK(pInfo->m_nState), 
							LVIS_STATEIMAGEMASK);
}


void CWzdView::OnTestWzd() 
{
	// determine if anything was selected
    if (GetListCtrl().GetSelectedCount())
	{
		//yes
	}

	// loop thru selections
	int i=-1;
 	while ((i = GetListCtrl().GetNextItem(i, LVIS_SELECTED)) != -1)                             
 	{                                                                                              
		CWzdInfo *pInfo=(CWzdInfo *)GetListCtrl().GetItemData(i);

	}

// add item to list
	CList<CWzdInfo*,CWzdInfo*> *pList=GetDocument()->GetInfoList();
	CWzdInfo *pInfo=new CWzdInfo("new","comment",CWzdInfo::NEW);
	pList->AddHead(pInfo);
	AddItem(-1,pInfo);

// to modify
	i = 1;
	pInfo=(CWzdInfo *)GetListCtrl().GetItemData(i);
	///
	AddItem(i,pInfo);

// to ensure a line is visible
	GetListCtrl().EnsureVisible(i,FALSE);

// to select a line
	LV_ITEM lvi;
	lvi.mask = LVIF_STATE;
	lvi.iItem = i;
	lvi.stateMask = 0x000f;
	lvi.state = LVIS_SELECTED|LVIS_FOCUSED;
	GetListCtrl().SetItemState(i, &lvi);

// to delete a line
	GetListCtrl().DeleteItem(i);

// to redraw view
	GetListCtrl().Invalidate();
	
}
