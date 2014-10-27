#if !defined(AFX_WZDEDIT_H__19B437E6_E7F5_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_WZDEDIT_H__19B437E6_E7F5_11D1_A18D_DCB3C85EBD34__INCLUDED_

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
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWzdEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWzdEdit)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg void OnUndo(void){Undo();};
	afx_msg void OnCut(void){Cut();};
	afx_msg void OnCopy(void){Copy();};
	afx_msg void OnPaste(void){Paste();};
	afx_msg void OnDelete(void){Clear();};
	afx_msg void OnSelectAll(void){SetSel(0,-1);};
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDEDIT_H__19B437E6_E7F5_11D1_A18D_DCB3C85EBD34__INCLUDED_)
