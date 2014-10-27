#if !defined(AFX_WZDDIALOG_H__FE0C19C4_E025_11D1_9B77_00AA003D8695__INCLUDED_)
#define AFX_WZDDIALOG_H__FE0C19C4_E025_11D1_9B77_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdDlg.h : header file
//

#include "WzdBtmap.h"
#include "WzdBttn.h"
/////////////////////////////////////////////////////////////////////////////
// CWzdDialog dialog

class CWzdDialog : public CDialog
{
// Construction
public:
	CWzdDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWzdDialog)
	enum { IDD = IDD_WZD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWzdDialog)
	afx_msg void OnWzdButton1();
	afx_msg void OnWzdButton2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CWzdBitmap m_bitmap;
	CWzdButton m_bitmapButton2;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDDIALOG_H__FE0C19C4_E025_11D1_9B77_00AA003D8695__INCLUDED_)
