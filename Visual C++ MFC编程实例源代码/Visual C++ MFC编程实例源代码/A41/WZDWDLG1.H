#if !defined(AFX_WZDWAITDIALOG_H__57255324_E732_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_WZDWAITDIALOG_H__57255324_E732_11D1_A18D_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdDlg1.h : header file
//
#include "resource.h"
/////////////////////////////////////////////////////////////////////////////
// CWzdWaitDialog dialog

class CWzdWaitDialog : public CDialog
{
// Construction
public:
	CWzdWaitDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWzdWaitDialog)
	enum { IDD = IDD_WAIT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdWaitDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWzdWaitDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDWAITDIALOG_H__57255324_E732_11D1_A18D_DCB3C85EBD34__INCLUDED_)
