#if !defined(AFX_WZDDIALOGBAR_H__1EDD5D45_B9C0_11D1_9B4E_00AA003D8695__INCLUDED_)
#define AFX_WZDDIALOGBAR_H__1EDD5D45_B9C0_11D1_9B4E_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdDlgBr.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdDialogBar dialog

class CWzdDialogBar : public CDialogBar
{
// Construction
public:
	CWzdDialogBar(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWzdDialogBar)
	enum { IDD = IDD_WZD_DIALOG };
	CString	m_sRerouted;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdDialogBar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWzdDialogBar)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	afx_msg void OnWzdOptions();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDDIALOGBAR_H__1EDD5D45_B9C0_11D1_9B4E_00AA003D8695__INCLUDED_)
