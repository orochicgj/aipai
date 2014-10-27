#if !defined(AFX_PAGE3_H__A846F4D5_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_PAGE3_H__A846F4D5_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Page3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage3 dialog

class CPage3 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPage3)

// Construction
public:
	CPage3();
	~CPage3();

// Dialog Data
	//{{AFX_DATA(CPage3)
	enum { IDD = IDD_PAGE3 };
	CListBox	m_ctrlExample;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPage3)
	public:
	virtual LRESULT OnWizardNext();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPage3)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CSampleWzdSheet *m_pSheet;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE3_H__A846F4D5_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_)
