#if !defined(AFX_WZDCOMBOBOX_H__1EC84997_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
#define AFX_WZDCOMBOBOX_H__1EC84997_C589_11D1_9B5C_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdCmbBx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdComboBox window

class CWzdComboBox : public CComboBox
{
// Construction
public:
	CWzdComboBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWzdComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWzdComboBox)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDCOMBOBOX_H__1EC84997_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
