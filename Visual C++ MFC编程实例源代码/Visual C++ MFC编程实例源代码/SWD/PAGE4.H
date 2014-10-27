#if !defined(AFX_PAGE4_H__041D5D54_26DA_11D2_9BDA_00AA003D8695__INCLUDED_)
#define AFX_PAGE4_H__041D5D54_26DA_11D2_9BDA_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Page4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage4 dialog

class CPage4 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPage4)

// Construction
public:
	CPage4();
	~CPage4();

// Dialog Data
	//{{AFX_DATA(CPage4)
	enum { IDD = IDD_PAGE4 };
	CString	m_sRootDir;
	CString	m_sTargetDir;
	CString	m_sSub;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPage4)
	public:
	virtual LRESULT OnWizardBack();
	virtual LRESULT OnWizardNext();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPage4)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CSampleWzdSheet *m_pSheet;
	void StoreValues();
	void FixupDirectory(CString &str);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE4_H__041D5D54_26DA_11D2_9BDA_00AA003D8695__INCLUDED_)
