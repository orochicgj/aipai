#if !defined(AFX_SECONDPAGE_H__B4329416_BF2A_11D1_9B55_00AA003D8695__INCLUDED_)
#define AFX_SECONDPAGE_H__B4329416_BF2A_11D1_9B55_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ScndPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSecondPage dialog

class CSecondPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSecondPage)

// Construction
public:
	CSecondPage();
	~CSecondPage();

// Dialog Data
	//{{AFX_DATA(CSecondPage)
	enum { IDD = IDD_SECOND_PAGE };
	CString	m_sOption2;
	int		m_nOption1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSecondPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSecondPage)
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECONDPAGE_H__B4329416_BF2A_11D1_9B55_00AA003D8695__INCLUDED_)
