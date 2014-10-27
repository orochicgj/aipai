#if !defined(AFX_PAGE5_H__041D5D55_26DA_11D2_9BDA_00AA003D8695__INCLUDED_)
#define AFX_PAGE5_H__041D5D55_26DA_11D2_9BDA_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Page5.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage5 dialog

class CPage5 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPage5)

// Construction
public:
	CPage5();
	~CPage5();

// Dialog Data
	//{{AFX_DATA(CPage5)
	enum { IDD = IDD_PAGE5 };
	BOOL	m_bClipboard;
	BOOL	m_bFiles;
	//}}AFX_DATA
	CEdit	m_ctrlEditbox;


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPage5)
	public:
	virtual BOOL OnWizardFinish();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPage5)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_sPath;
	CSampleWzdSheet *m_pSheet;
	void SubstituteWzd(CString &str);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE5_H__041D5D55_26DA_11D2_9BDA_00AA003D8695__INCLUDED_)
