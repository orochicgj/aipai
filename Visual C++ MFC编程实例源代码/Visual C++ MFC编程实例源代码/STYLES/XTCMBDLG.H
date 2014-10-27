#if !defined(AFX_ExtComboDLG_H__D8E5B436_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_ExtComboDLG_H__D8E5B436_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// XtCmbDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtComboDlg dialog

#include "afxtempl.h"
class CExtComboDlg : public CDialog
{
// Construction
public:
	CExtComboDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExtComboDlg)
	enum { IDD = IDD_BUTTONS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtComboDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExtComboDlg)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CList<CComboBoxEx*,CComboBoxEx*> m_ExtComboList;
	CList<CStatic*,CStatic*> m_staticList;
	CImageList m_imageList;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ExtComboDLG_H__D8E5B436_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_)
