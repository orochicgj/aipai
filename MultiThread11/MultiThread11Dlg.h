// MultiThread11Dlg.h : header file
//
#include "Dialog1.h"
#include "Dialog2.h"
#include "Dialog3.h"
#if !defined(AFX_MULTITHREAD11DLG_H__1C838464_4EC3_4938_82F0_0F245AE8AFEA__INCLUDED_)
#define AFX_MULTITHREAD11DLG_H__1C838464_4EC3_4938_82F0_0F245AE8AFEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include "CTabsheet.h"
/////////////////////////////////////////////////////////////////////////////
// CMultiThread11Dlg dialog
//volatile BOOL m_flag = TRUE;
class CMultiThread11Dlg : public CDialog
{
// Construction
public:
	CMultiThread11Dlg(CWnd* pParent = NULL);	// standard constructor
	CDialog1 m_dialog1;
	CDialog2 m_dialog2;
	CDialog3 m_dialog3;
// Dialog Data
	//{{AFX_DATA(CMultiThread11Dlg)
	enum { IDD = IDD_MULTITHREAD11_DIALOG };
	CTabCtrl	m_tabctrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread11Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	//{{AFX_MSG(CMultiThread11Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD11DLG_H__1C838464_4EC3_4938_82F0_0F245AE8AFEA__INCLUDED_)
