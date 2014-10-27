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

BOOL CWzdView::PreTranslateMessage(MSG* pMsg) 
{

	// ALT key is not pressed or is pressed with CTRL key....
	if (pMsg->message==WM_KEYDOWN)
	{
		BOOL bCtrl=::GetKeyState(VK_CONTROL)&0x8000;
		BOOL bShift=::GetKeyState(VK_SHIFT)&0x8000;
		BOOL bAlt=::GetKeyState(VK_MENU)&0x8000; //only gets here if CTRL key is pressed
		switch(pMsg->wParam)
		{
			case 'N':
				if (bAlt&&bShift) //&&bCtrl assumed
					SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				else if (bShift&&bCtrl)
					SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				else if (bAlt) //&&bCtrl assumed
					SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				else if (bCtrl)
					SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				else if (bShift)
					SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				else
					SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				return TRUE; // translated

			case VK_ESCAPE:
				if (bShift)
					SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				return TRUE; // translated


			case VK_DELETE:
				SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				return TRUE; // translated

			case VK_INSERT:
				SendMessage(WM_COMMAND,ID_EDIT_PASTE);
				return TRUE; // translated
		}
	}
	// ALT key is pressed but not with CTRL key....
	else if (pMsg->message==WM_SYSKEYDOWN)
	{
		BOOL bShift=::GetKeyState(VK_SHIFT)&0x8000;
		switch(pMsg->wParam)
		{
			case 'N':
				if (bShift)
					SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				else
					SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				return TRUE; // translated


			case VK_DELETE:
				SendMessage(WM_COMMAND,ID_EDIT_CLEAR);
				return TRUE; // translated

			case VK_INSERT:
				SendMessage(WM_COMMAND,ID_EDIT_PASTE);
				return TRUE; // translated
		}
	}
	
	return CView::PreTranslateMessage(pMsg);
}
