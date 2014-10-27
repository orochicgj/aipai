#if !defined(AFX_DIALOG2_H__1147B0D5_3A4C_4DEA_8873_535BA556B01F__INCLUDED_)
#define AFX_DIALOG2_H__1147B0D5_3A4C_4DEA_8873_535BA556B01F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog2 dialog

class CDialog2 : public CDialog
{
// Construction
public:
	CDialog2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog2)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_ct;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HANDLE hThread2;//分别代表线程的句柄和ID
	DWORD ThreadID2;
	int m_count;
	// Generated message map functions
	//{{AFX_MSG(CDialog2)
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG2_H__1147B0D5_3A4C_4DEA_8873_535BA556B01F__INCLUDED_)
