#if !defined(AFX_WZDDIALOG_H__BA398475_BE65_11D1_9B54_00AA003D8695__INCLUDED_)
#define AFX_WZDDIALOG_H__BA398475_BE65_11D1_9B54_00AA003D8695__INCLUDED_

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
	CComboBox	m_ctrlCombo;
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
	afx_msg void OnCloseupWzdCombo();
	afx_msg void OnDropdownWzdCombo();
	afx_msg void OnSelchangeWzdCombo();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString	m_sSelection;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDDIALOG_H__BA398475_BE65_11D1_9B54_00AA003D8695__INCLUDED_)
