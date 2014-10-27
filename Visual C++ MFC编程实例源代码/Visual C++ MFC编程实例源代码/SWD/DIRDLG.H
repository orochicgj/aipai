#if !defined(AFX_DIRDIALOG_H__36EF7674_3C42_11D2_9BEF_00AA003D8695__INCLUDED_)
#define AFX_DIRDIALOG_H__36EF7674_3C42_11D2_9BEF_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DirDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDirDialog dialog

class CDirDialog : public CDialog
{
// Construction
public:
	CDirDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDirDialog)
	enum { IDD = IDD_DIALOG1 };
	CComboBox	m_ctrlComboBox;
	CListBox	m_ctrlListbox;
	CString	m_sDir;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDirDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDirDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnCloseupCombo1();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnDblclkList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_sDrive;
	void UpdateCtrls();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRDIALOG_H__36EF7674_3C42_11D2_9BEF_00AA003D8695__INCLUDED_)
