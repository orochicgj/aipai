#if !defined(AFX_WZDDIALOGBAR_H__1EC84998_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
#define AFX_WZDDIALOGBAR_H__1EC84998_C589_11D1_9B5C_00AA003D8695__INCLUDED_

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

	BOOL InitDialog();

// Dialog Data
	//{{AFX_DATA(CWzdDialogBar)
	enum { IDD = IDD_WZD_DIALOG };
		// NOTE: the ClassWizard will add data members here
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
	afx_msg void OnWzdButton1();
	afx_msg void OnWzdButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDDIALOGBAR_H__1EC84998_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
