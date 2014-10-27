// MultiThread5Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD5DLG_H__AC95A2FE_D31C_470B_AECA_F1E2E3AE2E48__INCLUDED_)
#define AFX_MULTITHREAD5DLG_H__AC95A2FE_D31C_470B_AECA_F1E2E3AE2E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThread5Dlg dialog
struct threadInfo
{
	UINT nMilliSecond;
	CProgressCtrl* pctrlProgress;
};
UINT ThreadFunc(LPVOID lpParam); 
UINT ThreadFunc2(LPVOID lpParam); 

class CMultiThread5Dlg : public CDialog
{
// Construction
public:
	CMultiThread5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThread5Dlg)
	enum { IDD = IDD_MULTITHREAD5_DIALOG };
	CProgressCtrl	m_ctrlProgress2;
	CProgressCtrl	m_ctrlProgress;
	int		m_nMilliSecond;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread5Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread5Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	CWinThread* pThread;
	CWinThread* pThread2;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD5DLG_H__AC95A2FE_D31C_470B_AECA_F1E2E3AE2E48__INCLUDED_)
