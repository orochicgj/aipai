#if !defined(AFX_DIALOG1_H__D1854EA3_5141_45F8_90C9_9644FDF041CE__INCLUDED_)
#define AFX_DIALOG1_H__D1854EA3_5141_45F8_90C9_9644FDF041CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog1 dialog

class CDialog1 : public CDialog
{
// Construction
public:
	CDialog1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog1)
	enum { IDD = IDD_DIALOG1 };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HANDLE hThread;//分别代表线程的句柄和ID
	DWORD ThreadID;
	
	// Generated message map functions
	//{{AFX_MSG(CDialog1)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG1_H__D1854EA3_5141_45F8_90C9_9644FDF041CE__INCLUDED_)
