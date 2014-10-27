#if !defined(AFX_DateTimeDLG_H__D8E5B436_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_DateTimeDLG_H__D8E5B436_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DtTimDlg.h : header file
//
#include "AFXDTCTL.H"
/////////////////////////////////////////////////////////////////////////////
// CDateTimeDlg dialog

#include "afxtempl.h"
class CDateTimeDlg : public CDialog
{
// Construction
public:
	CDateTimeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDateTimeDlg)
	enum { IDD = IDD_BUTTONS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDateTimeDlg)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CList<CDateTimeCtrl*,CDateTimeCtrl*> m_DateTimeList;
	CList<CStatic*,CStatic*> m_staticList;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DateTimeDLG_H__D8E5B436_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_)
