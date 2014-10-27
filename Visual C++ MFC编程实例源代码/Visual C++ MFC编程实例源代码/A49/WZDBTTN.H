#if !defined(AFX_WZDBUTTON_H__1504C315_EC04_11D1_9B8C_00AA003D8695__INCLUDED_)
#define AFX_WZDBUTTON_H__1504C315_EC04_11D1_9B8C_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdBttn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdButton window

class CWzdButton : public CBitmapButton
{
// Construction
public:
	CWzdButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWzdButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWzdButton)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDBUTTON_H__1504C315_EC04_11D1_9B8C_00AA003D8695__INCLUDED_)
