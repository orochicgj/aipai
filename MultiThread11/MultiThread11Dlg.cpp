// MultiThread11Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread11.h"
#include "MultiThread11Dlg.h"

#include "Dialog1.h"
#include "Dialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CMultiThread11Dlg dialog

CMultiThread11Dlg::CMultiThread11Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiThread11Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiThread11Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThread11Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiThread11Dlg)
	DDX_Control(pDX, IDC_TAB1, m_tabctrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiThread11Dlg, CDialog)
	//{{AFX_MSG_MAP(CMultiThread11Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThread11Dlg message handlers

BOOL CMultiThread11Dlg::OnInitDialog()
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
	//CDialog1 *m_dialog1 = new CDialog1;
	m_tabctrl.InsertItem(0,"多线程范例1");
	if (!m_dialog1.Create(IDD_DIALOG1,&m_tabctrl))
		return FALSE;
	

	//CDialog2 *m_dialog2 = new CDialog2;
	m_tabctrl.InsertItem(1,"多线程范例2");
	m_tabctrl.InsertItem(2,"多线程范例3");
	if (!m_dialog2.Create(IDD_DIALOG2,&m_tabctrl))
		return FALSE;

	if(!m_dialog3.Create(IDD_DIALOG3,&m_tabctrl))
		return FALSE;
	//获得IDC_TABTEST客户区大小
	
	CRect rs; 
	m_tabctrl.GetClientRect(&rs); 
	//调整子对话框在父窗口中的位置 
	rs.top+=30; 
	rs.bottom-=10; 
	rs.left+=1; 
	rs.right-=2;
	m_dialog1.MoveWindow(&rs);
	m_dialog2.MoveWindow(&rs);
	m_dialog3.MoveWindow(&rs);
//m_dialog1->SetWindowPos(NULL,10,30,400,100,SWP_SHOWWINDOW);
	/*	m_dialog2->SetWindowPos(NULL,10,30,400,100,SWP_HIDEWINDOW);*/
	
	m_dialog1.ShowWindow(true);
	m_dialog2.ShowWindow(false);
	m_dialog3.ShowWindow(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMultiThread11Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMultiThread11Dlg::OnPaint() 
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
HCURSOR CMultiThread11Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMultiThread11Dlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CRect rc;
	GetClientRect(&rc);
	switch(m_tabctrl.GetCurSel())
	{
	case 0:
		m_dialog1.ShowWindow(SW_SHOW);
		m_dialog2.ShowWindow(SW_HIDE);
		m_dialog3.ShowWindow(SW_HIDE);
		m_dialog1.SetFocus();
		break;
	case 1:
		m_dialog2.ShowWindow(SW_SHOW);
		m_dialog1.ShowWindow(SW_HIDE);
		m_dialog3.ShowWindow(SW_HIDE);
		m_dialog2.SetFocus();
		break;
	case 2:
		m_dialog3.ShowWindow(SW_SHOW);
		m_dialog1.ShowWindow(SW_HIDE);
		m_dialog2.ShowWindow(SW_HIDE);
		m_dialog3.SetFocus();
	default:
		break;
	}
	*pResult = 0;
}
