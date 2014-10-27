#if !defined(AFX_DIALOG3_H__B0CA1B4D_FD10_4AE3_AAE9_3E8795D221C5__INCLUDED_)
#define AFX_DIALOG3_H__B0CA1B4D_FD10_4AE3_AAE9_3E8795D221C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog3 dialog

class CDialog3 : public CDialog
{
// Construction
public:
	CDialog3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog3)
	enum { IDD = IDD_DIALOG3 };
	int		m_ncount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HANDLE hThread3;//分别代表线程的句柄和ID
	DWORD ThreadID3;
	int m_count;
	// Generated message map functions
	//{{AFX_MSG(CDialog3)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG3_H__B0CA1B4D_FD10_4AE3_AAE9_3E8795D221C5__INCLUDED_)
