#if !defined(AFX_FIRSTPAGE_H__B4329415_BF2A_11D1_9B55_00AA003D8695__INCLUDED_)
#define AFX_FIRSTPAGE_H__B4329415_BF2A_11D1_9B55_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// FirstPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFirstPage dialog

class CFirstPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CFirstPage)

// Construction
public:
	CFirstPage();
	~CFirstPage();

// Dialog Data
	//{{AFX_DATA(CFirstPage)
	enum { IDD = IDD_FIRST_PAGE };
	BOOL	m_bOption1;
	CString	m_sOption2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CFirstPage)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CFirstPage)
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIRSTPAGE_H__B4329415_BF2A_11D1_9B55_00AA003D8695__INCLUDED_)
