#if !defined(AFX_WZDSTATUSBAR_H__DDA34AC3_D491_11D1_9B68_00AA003D8695__INCLUDED_)
#define AFX_WZDSTATUSBAR_H__DDA34AC3_D491_11D1_9B68_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdStBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdStatusBar window

class CWzdStatusBar : public CStatusBar
{
// Construction
public:
	CWzdStatusBar();

// Attributes
public:
	CButton &GetButton(){return m_WzdButton;};
	CProgressCtrl &GetProgressCtrl(){return m_WzdProgressCtrl;};

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdStatusBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWzdStatusBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWzdStatusBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	CButton	m_WzdButton;
	CProgressCtrl m_WzdProgressCtrl;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDSTATUSBAR_H__DDA34AC3_D491_11D1_9B68_00AA003D8695__INCLUDED_)
