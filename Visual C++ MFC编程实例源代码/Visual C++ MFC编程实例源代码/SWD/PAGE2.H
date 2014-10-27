#if !defined(AFX_PAGE2_H__A846F4D4_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_PAGE2_H__A846F4D4_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Page2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage2 dialog

class CPage2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPage2)

// Construction
public:
	CPage2();
	~CPage2();

// Dialog Data
	//{{AFX_DATA(CPage2)
	enum { IDD = IDD_PAGE2 };
	CListBox	m_ctrlChapter;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPage2)
	public:
	virtual LRESULT OnWizardNext();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPage2)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CSampleWzdSheet *m_pSheet;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE2_H__A846F4D4_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_)
