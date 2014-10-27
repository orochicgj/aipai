// MultiThread5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread5.h"
#include "MultiThread5Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

threadInfo Info; 
threadInfo Info2; 
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThread5Dlg dialog

CMultiThread5Dlg::CMultiThread5Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiThread5Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiThread5Dlg)
	m_nMilliSecond = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThread5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiThread5Dlg)
	DDX_Control(pDX, IDC_PROGRESS2, m_ctrlProgress2);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress);
	DDX_Text(pDX, IDC_MILLISECOND, m_nMilliSecond);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiThread5Dlg, CDialog)
	//{{AFX_MSG_MAP(CMultiThread5Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThread5Dlg message handlers

BOOL CMultiThread5Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ctrlProgress.SetRange(0,99);
	m_ctrlProgress2.SetRange(0,99);
	m_nMilliSecond=10;
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMultiThread5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMultiThread5Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMultiThread5Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMultiThread5Dlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Info.nMilliSecond=m_nMilliSecond;
	Info.pctrlProgress=&m_ctrlProgress;
	pThread=AfxBeginThread(ThreadFunc, &Info);

	Info2.nMilliSecond=m_nMilliSecond;
	Info2.pctrlProgress=&m_ctrlProgress2;
	pThread2=AfxBeginThread(ThreadFunc2, &Info2);
	
}

UINT ThreadFunc(LPVOID lpParam)
{
	threadInfo* pInfo=(threadInfo*)lpParam;
	for(int i=0;i<100;i++)
	{
		int nTemp=pInfo->nMilliSecond;
		
		pInfo->pctrlProgress->SetPos(i);
		
		Sleep(nTemp);
	}
	return 0;
}

UINT ThreadFunc2(LPVOID lpParam)
{
	threadInfo* pInfo=(threadInfo*)lpParam;
	for(int i=0;i<100;i++)
	{
		int nTemp=pInfo->nMilliSecond;
		
		pInfo->pctrlProgress->SetPos(i);
		
		Sleep(nTemp);
	}
	return 0;
}
