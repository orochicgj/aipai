// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Wzd.h"

#include "MainFrm.h"

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
	ON_COMMAND(ID_VIEW_DIALOGBAR, OnViewDialogbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DIALOGBAR, OnUpdateViewDialogbar)
	//}}AFX_MSG_MAP
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
	// TODO: add member initialization code here
	
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

	// create wizard dialog bar
	if (!m_WzdDialogBar.Create(this, IDD_WZD_DIALOG,
		CBRS_TOP,	// control bar is initially at top of frame
//		CBRS_BOTTOM,// control bar is initially at bottom of frame
//		CBRS_LEFT,	// control bar is initially on left side of frame
//		CBRS_RIGHT,	// control bar is initially on right side of frame
		-1) ||
		!m_WzdDialogBar.InitDialog())
	{
		TRACE0("Failed to create dialog bar\n");
		return -1;      // fail to create
	}
		
   	m_WzdDialogBar.EnableDocking(
		CBRS_ORIENT_HORZ	// control bar will only dock to top or bottom of frame
//		CBRS_ORIENT_VERT	// control bar will only dock to left or right side of frame
//		CBRS_ORIENT_ANY		// control bar will dock to any side of frame
		);
	DockControlBar(&m_WzdDialogBar);

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
//经过命令接口更新到控制
BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	if (m_WzdDialogBar.OnCmdMsg(nID,nCode,pExtra,pHandlerInfo))
		return TRUE;
	
	return CMDIFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnViewDialogbar() //隐藏\显示对话条
{
	ShowControlBar(&m_WzdDialogBar, (m_WzdDialogBar.GetStyle() & WS_VISIBLE) == 0, FALSE);	
}

void CMainFrame::OnUpdateViewDialogbar(CCmdUI* pCmdUI) //更新用户界面，即菜单前面是否出现对钩
{
	pCmdUI->SetCheck((m_WzdDialogBar.GetStyle() & WS_VISIBLE) != 0);
}
