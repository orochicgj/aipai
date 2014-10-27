#if !defined(AFX_TESTDLG_H__B8B81F01_CED5_11D1_9B63_00AA003D8695__INCLUDED_)
#define AFX_TESTDLG_H__B8B81F01_CED5_11D1_9B63_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TestDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_TEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush m_brush;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__B8B81F01_CED5_11D1_9B63_00AA003D8695__INCLUDED_)
