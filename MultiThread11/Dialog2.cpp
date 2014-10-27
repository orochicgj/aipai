// Dialog2.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread11.h"
#include "Dialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog2 dialog
VOID  ThreadFun1(LPVOID pParam);//申明一个线程函数

CDialog2::CDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog2)
	//}}AFX_DATA_INIT
	m_count = 5;

}


void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog2)
	DDX_Control(pDX, IDC_EDIT_CAO, m_ct);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog2, CDialog)
	//{{AFX_MSG_MAP(CDialog2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog2 message handlers

void CDialog2::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString strend="播放音乐结束";
	CString strstart = "正在播放音乐";

	int inter = m_count;
	//HWND hActive = GetActiveWindow();
	GetDlgItem(IDC_EDIT_CAO)->SetWindowText(strstart);
	//SetWindowText()
	//m_ct.SetWindowText(strstart);
	//Sleep(2000);
	hThread2 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadFun1,(VOID *)&m_ct,0,&ThreadID2);	
		
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	//WaitForSingleObject(hThread2,15000);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	
	//GetDlgItem(IDC_EDIT1)->SetWindowText(strend);
	//::SetDlgItemText(this->GetSafeHwnd(),IDC_EDIT_CAO,strend);
	//m_ct.SetWindowText(strend);
	
}

void CDialog2::OnButton3() 
{
	// TODO: Add your control notification handler code here
	//TerminateThread()
}
VOID ThreadFun1(LPVOID pParam)
{

	unsigned FREQUENCY[] = {392,392,440,392,523,494,  
		392,392,440,392,587,523,  
		392,392,784,659,523,494,440,  
		689,689,523,587,523};  
	
    unsigned DELAY[] = {375,125,500,500,500,1000,  
		375,125,500,500,500,1000,  
		375,125,500,500,500,500,1000,  
              375,125,500,500,500,1000}; 
	int i;
	//CDialog2 *dlg2;
	//dlg2 = (CDialog2 *)pParam;
	CEdit *meidt;
	meidt = (CEdit *)pParam;
	CString strcao = "正在播放生日快乐歌曲";
	CString strct;
	CString strdb;
	CString strend = "播放音乐结束";
	for(i=0;i<25;i++)
	{
		if (i%5==0)
			strdb="";
		strdb = strdb+'.';
		Beep(FREQUENCY[i], DELAY[i]);  
		//Sleep(1000);
		//::SetDlgItemText(dlg2->m_hWnd,IDC_EDIT_CAO,strcao);
		//((CDialog2*)GetDlgItem(IDD_DIALOG2))->SetWindowText()
		//::SetDlgItemText(this->GetSafeHwnd(),IDC_EDIT1,strend);
		strct =strcao + strdb;
		meidt->SetWindowText(strct);
	}
	meidt->SetWindowText(strend);
	//return 1;
}
