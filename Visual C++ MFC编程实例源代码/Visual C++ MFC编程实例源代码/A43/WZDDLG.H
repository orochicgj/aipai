#if !defined(AFX_WZDDIALOG_H__3A5CD906_E412_11D1_9B7D_00AA003D8695__INCLUDED_)
#define AFX_WZDDIALOG_H__3A5CD906_E412_11D1_9B7D_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdDlg.h : header file
//

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
	CAnimateCtrl	m_ctrlAnimate;
	//}}AFX_DATA


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
	afx_msg void OnStopButton();
	afx_msg void OnStrtButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDDIALOG_H__3A5CD906_E412_11D1_9B7D_00AA003D8695__INCLUDED_)
