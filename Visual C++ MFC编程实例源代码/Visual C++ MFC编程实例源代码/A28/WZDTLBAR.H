#if !defined(AFX_WZDTOOLBAR_H__27649E31_C807_11D1_9B5D_00AA003D8695__INCLUDED_)
#define AFX_WZDTOOLBAR_H__27649E31_C807_11D1_9B5D_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdTlBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdToolBar window

class CWzdToolBar : public CToolBar
{
// Construction
public:
	CWzdToolBar();

	BOOL LoadToolBarEx(UINT id);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWzdToolBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWzdToolBar)
	//}}AFX_MSG
	afx_msg void OnDropdownCombo();
	afx_msg void OnCloseupCombo();

	DECLARE_MESSAGE_MAP()
private:
	CString	m_sSelection;
	CComboBox	m_ctrlWzdCombo;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDTOOLBAR_H__27649E31_C807_11D1_9B5D_00AA003D8695__INCLUDED_)
