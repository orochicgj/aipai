#if !defined(AFX_WZDEDIT_H__1EC84996_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
#define AFX_WZDEDIT_H__1EC84996_C589_11D1_9B5C_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdEdit window

class CWzdEdit : public CEdit
{
// Construction
public:
	CWzdEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdEdit)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWzdEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWzdEdit)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	CBrush	m_brush;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDEDIT_H__1EC84996_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
