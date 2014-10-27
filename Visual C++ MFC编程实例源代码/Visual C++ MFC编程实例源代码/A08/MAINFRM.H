// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__CA9038EA_B0DF_11D1_A18C_DCB3C85EBD34__INCLUDED_)
#define AFX_MAINFRM_H__CA9038EA_B0DF_11D1_A18C_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "FrstPage.h"
#include "ScndPage.h"

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:
	BOOL m_bFirstOption1;
	CString m_sFirstOption2;
	int m_nSecondOption1;
	CString m_sSecondOption2;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnOptionsPreferences();
	//}}AFX_MSG
	afx_msg void OnApply();
	DECLARE_MESSAGE_MAP()
private:
	CFirstPage *m_pFirstPage;
	CSecondPage *m_pSecondPage;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__CA9038EA_B0DF_11D1_A18C_DCB3C85EBD34__INCLUDED_)
