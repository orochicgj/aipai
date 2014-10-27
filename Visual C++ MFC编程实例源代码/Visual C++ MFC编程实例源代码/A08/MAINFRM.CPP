// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include <afxpriv.h>

#include "Wzd.h"
#include "WzdDoc.h"

#include "MainFrm.h"

#include "WzdPrjct.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_OPTIONS_PREFERENCES, OnOptionsPreferences)
	//}}AFX_MSG_MAP
	ON_MESSAGE_VOID(WM_APPLY,OnApply)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_bFirstOption1=TRUE;
	m_sFirstOption2=_T("Test");
	m_nSecondOption1=1;
	m_sSecondOption2=_T("Empty");
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CMDIFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnOptionsPreferences() 
{
	CPropertySheet sheet(_T("Preferences"),this);
	m_pFirstPage=new CFirstPage;
	m_pSecondPage=new CSecondPage;

	sheet.AddPage(m_pFirstPage);
	sheet.AddPage(m_pSecondPage);

	m_pFirstPage->m_bOption1 = m_bFirstOption1;
	m_pFirstPage->m_sOption2 = m_sFirstOption2;
	m_pSecondPage->m_nOption1 = m_nSecondOption1;
	m_pSecondPage->m_sOption2 = m_sSecondOption2;

	if (sheet.DoModal()==IDOK)
	{
		OnApply();
	}
	delete m_pFirstPage;
	delete m_pSecondPage;
}

void CMainFrame::OnApply()
{
	m_bFirstOption1 = m_pFirstPage->m_bOption1; 
	m_sFirstOption2 = m_pFirstPage->m_sOption2; 
	m_nSecondOption1 = m_pSecondPage->m_nOption1;
	m_sSecondOption2 = m_pSecondPage->m_sOption2;
}
