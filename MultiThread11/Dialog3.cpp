// Dialog3.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread11.h"
#include "Dialog3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog3 dialog

UINT ThreadFunc2(LPVOID LPARAM);
volatile BOOL m_trueflag = TRUE;

CDialog3::CDialog3(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog3)
	m_ncount = 0;
	//}}AFX_DATA_INIT
	m_count =0;
}


void CDialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog3)
	DDX_Text(pDX, IDC_EDIT1, m_ncount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog3, CDialog)
	//{{AFX_MSG_MAP(CDialog3)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog3 message handlers

void CDialog3::OnButton1() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	while(m_trueflag)
	{
		if (CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadFunc2,NULL,0,&ThreadID3) == NULL)
		{
			m_trueflag = false;
			break;
		}
		else
			m_count++;
	}
	Sleep(2000);
	m_ncount = m_count;
	UpdateData(FALSE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
}


UINT ThreadFunc2(LPVOID LPARAM)
{
	while (m_trueflag)
		Sleep(1000);
	return 1;
}