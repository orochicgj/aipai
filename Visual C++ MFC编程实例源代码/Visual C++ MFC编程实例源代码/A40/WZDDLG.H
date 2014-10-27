#if !defined(AFX_WZDDIALOG_H__AC742082_EC9C_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_WZDDIALOG_H__AC742082_EC9C_11D1_A18D_DCB3C85EBD34__INCLUDED_

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
	BOOL	m_bCheck;
	CString	m_sName;
	int		m_nRadio;
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
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDDIALOG_H__AC742082_EC9C_11D1_A18D_DCB3C85EBD34__INCLUDED_)
