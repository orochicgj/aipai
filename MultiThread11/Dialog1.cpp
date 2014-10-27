// Dialog1.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread11.h"
#include "Dialog1.h"
extern m_flag;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog1 dialog

BOOL m_flag = TRUE;
CDialog1::CDialog1(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog1)
	//}}AFX_DATA_INIT
}


void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog1)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog1, CDialog)
	//{{AFX_MSG_MAP(CDialog1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog1 message handlers
void  ThreadFunc(LPVOID pParam)
{
	CString strTime;
	CDialog1 *dlg;
	dlg = (CDialog1 *)pParam;
	CTime time;
	m_flag = TRUE;
	while(m_flag)
	{
		time = CTime::GetCurrentTime();
		strTime=time.Format("%H:%M:%S");
		::SetDlgItemText(dlg->m_hWnd,IDC_EDIT1,strTime);
	//	GetDlgItem(IDC_EDIT1)->setwindow
		Sleep(1000);
	}
	ExitThread(1);
	
}

void CDialog1::OnButton1() //启动线程//传递的参数 是 窗口对象指针
{
	// TODO: Add your control notification handler code here
	hThread=CreateThread(NULL,
		0,
		(LPTHREAD_START_ROUTINE)ThreadFunc,
		this,
		0,
&ThreadID);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	
}

void CDialog1::OnButton2() 
{
	// TODO: Add your control notification handler code here
	m_flag = false;
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
}

void CDialog1::OnButton3() 
{
	// TODO: Add your control notification handler code here
	TerminateThread(hThread,1);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
}
