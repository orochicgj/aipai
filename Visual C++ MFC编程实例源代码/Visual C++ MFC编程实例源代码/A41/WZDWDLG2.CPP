// WzdDlg2.cpp : implementation of the CWzdWaitDlg class
//

#include "stdafx.h"
#include "resource.h"
#include "WzdWDlg2.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdWaitDlg

CWzdWaitDlg::CWzdWaitDlg()
{
	m_pDlg=new CWzdWaitDialog();
	m_pDlg->Create(IDD_WAIT_DIALOG);
	m_pDlg->ShowWindow(SW_SHOW);
	// and since the function that constructs this class
	// might not allow the normal WM_PAINT message to get thru:
	m_pDlg->UpdateWindow();
}

CWzdWaitDlg::~CWzdWaitDlg()
{
	m_pDlg->DestroyWindow();
	delete m_pDlg;
}
