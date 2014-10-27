// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Wzd.h"
#include "WzdPrjct.h"

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
	ON_WM_CLOSE()
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
	m_sOption1=_T("new");
	m_nOption2=3;
	m_dOption3=33.3;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	LoadOptions1();
	
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

void CMainFrame::OnClose() 
{
	SaveOptions1();
	
	CMDIFrameWnd::OnClose();
}

void CMainFrame::LoadOptions1()
{
	// string options
	m_sOption1=AfxGetApp()->GetProfileString(SETTINGS_KEY,OPTION1_KEY,"Default");

	// integer options
	m_nOption2=AfxGetApp()->GetProfileInt(SETTINGS_KEY,OPTION2_KEY, 3 );

	// binary options
	BYTE *p;
	UINT size;
	m_dOption3=33.3;
	if (AfxGetApp()->GetProfileBinary(SETTINGS_KEY,OPTION3_KEY, &p, &size ))
	{
		memcpy(&m_dOption3,p,size);
		delete []p;
	}
}

void CMainFrame::SaveOptions1()
{
	// string options
	AfxGetApp()->WriteProfileString(SETTINGS_KEY,OPTION1_KEY,m_sOption1);

	// integer options
	AfxGetApp()->WriteProfileInt(SETTINGS_KEY,OPTION2_KEY, m_nOption2 );

	// binary options
	AfxGetApp()->WriteProfileBinary(SETTINGS_KEY, OPTION3_KEY, (BYTE*)&m_dOption3, sizeof(m_dOption3));

}

void CMainFrame::LoadOptions2()
{
	HKEY key;
	DWORD size, type;
	if(RegOpenKeyEx( HKEY_CURRENT_USER,APPLICATION_KEY,0,KEY_READ,&key) == ERROR_SUCCESS )
	{
		// string
		size=128;
		type = REG_SZ;
		LPSTR psz = m_sOption1.GetBuffer(size);
		RegQueryValueEx( key,OPTION1_KEY,0,&type,(LPBYTE)psz,&size );
		m_sOption1.ReleaseBuffer();

		// int 32
		size=4;
		type = REG_DWORD;
		RegQueryValueEx( key,OPTION2_KEY,0,&type,(LPBYTE)&m_nOption2,&size );

		// everything else
		size=sizeof(DOUBLE);
		type = REG_BINARY;
		RegQueryValueEx( key,OPTION3_KEY,0,&type,(LPBYTE)&m_dOption3,&size );

		RegCloseKey( key );
	}
}

void CMainFrame::SaveOptions2()
{
	// save size of screen
	HKEY key;
	DWORD size, type, disposition;
	if (RegOpenKeyEx( HKEY_CURRENT_USER,APPLICATION_KEY,0,
           KEY_WRITE,&key)!=ERROR_SUCCESS)
	{
		RegCreateKeyEx( HKEY_CURRENT_USER,APPLICATION_KEY,0,"",
        		REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,
					&key,&disposition);
	}

	// string
	type = REG_SZ;
	size = m_sOption1.GetLength();
	RegSetValueEx( key,OPTION1_KEY,0,type,(LPBYTE)LPCSTR(m_sOption1),size );

	// int
	type = REG_DWORD;
	size = 4;
	RegSetValueEx( key,OPTION2_KEY,0,type,(LPBYTE)&m_nOption2,size );

	// everything else
	type = REG_BINARY;
	size = sizeof(DOUBLE);
	RegSetValueEx( key,OPTION3_KEY,0,type,(LPBYTE)&m_dOption3,size );


	RegCloseKey( key );

}