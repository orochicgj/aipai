// WzdView.cpp : implementation file
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

IMPLEMENT_DYNCREATE(CWzdView, CFormView)

CWzdView::CWzdView()
	: CFormView(CWzdView::IDD)
{
	//{{AFX_DATA_INIT(CWzdView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CWzdView::~CWzdView()
{
}

void CWzdView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWzdView)
	DDX_Control(pDX, IDC_WZD_LIST, m_ctrlWzdList);
	DDX_Control(pDX, IDC_WZD_BUTTON2, m_ctrlWzdButton2);
	DDX_Control(pDX, IDC_WZD_BUTTON1, m_ctrlWzdButton1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdView, CFormView)
	//{{AFX_MSG_MAP(CWzdView)
	ON_BN_CLICKED(IDC_WZD_BUTTON1, OnWzdButton1)
	ON_BN_CLICKED(IDC_WZD_BUTTON2, OnWzdButton2)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdView diagnostics

#ifdef _DEBUG
void CWzdView::AssertValid() const
{
	CFormView::AssertValid();
}

void CWzdView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWzdView message handlers

void CWzdView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();

	// make frame the size of the original dialog box
	ResizeParentToFit();

	// get rid of those pesky scroll bars
	SetScrollSizes( MM_TEXT, CSize(20,20));
}

void CWzdView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// store any data from document into member variables here
	
	UpdateData(FALSE);
}


void CWzdView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);

	if (m_ctrlWzdList.m_hWnd)
	{

		CRect rect;
		m_ctrlWzdButton1.GetClientRect(&rect);

		// list control is always 10 pixels from corners and above buttons
		//  (last two arguments are width & height)
		m_ctrlWzdList.MoveWindow(10,10,cx-20,cy-rect.Height()-30);

		// buttons are always the size they started 10 pixels from bottom, 
		//  20 from each other and centered
		int strt = (cx - (rect.Width()*2+20))/2;

		rect.OffsetRect(strt,cy-rect.Height()-10);
		m_ctrlWzdButton1.MoveWindow(rect);

		rect.OffsetRect(rect.Width()+20,0);
		m_ctrlWzdButton2.MoveWindow(rect);
	}
	
}

void CWzdView::OnWzdButton1() 
{
	// TODO: Add your control notification handler code here
	
}

void CWzdView::OnWzdButton2() 
{
	// TODO: Add your control notification handler code here
	
}
