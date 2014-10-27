#if !defined(AFX_WZDTOOLBAR_H__3A5CD903_E412_11D1_9B7D_00AA003D8695__INCLUDED_)
#define AFX_WZDTOOLBAR_H__3A5CD903_E412_11D1_9B7D_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdTlBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdToolBar window

typedef struct t_TOOLTEXT {
	UINT idCommand;
	UINT idString;
} TOOLTEXT;

class CWzdToolBar : public CToolBar
{
// Construction
public:
	CWzdToolBar();

// Attributes
public:

// Operations
public:
	BOOL LoadToolBarEx(UINT nID,TOOLTEXT *pToolText,int nCnt);

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
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDTOOLBAR_H__3A5CD903_E412_11D1_9B7D_00AA003D8695__INCLUDED_)
