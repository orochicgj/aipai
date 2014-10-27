#if !defined(AFX_WZDDIALOG_H__1EC84995_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
#define AFX_WZDDIALOG_H__1EC84995_C589_11D1_9B5C_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdDlg.h : header file
//

#include "WzdEdit.h"
#include "WzdCmbBx.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog dialog

class CWzdDialog : public CDialog
{
// Construction
public:
	CWzdDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWzdDialog)
	enum { IDD = IDD_WZD_DIALOG };
	//}}AFX_DATA
	CWzdEdit	m_ctrlEdit;
	CWzdEdit	m_ctrlEdit2;

	CWzdComboBox	m_ctrlComboBox;
	CWzdEdit	m_ctrlComboEditBox;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWzdDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDDIALOG_H__1EC84995_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
