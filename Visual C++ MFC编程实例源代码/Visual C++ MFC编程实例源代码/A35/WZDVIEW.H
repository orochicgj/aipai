#if !defined(AFX_WZDVIEW_H__1EC84993_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
#define AFX_WZDVIEW_H__1EC84993_C589_11D1_9B5C_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CWzdView : public CFormView
{
protected:
	CWzdView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CWzdView)

// Form Data
public:
	//{{AFX_DATA(CWzdView)
	enum { IDD = IDD_WZD_DIALOG };
	CListCtrl	m_ctrlWzdList;
	CButton	m_ctrlWzdButton2;
	CButton	m_ctrlWzdButton1;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWzdView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CWzdView)
	afx_msg void OnWzdButton1();
	afx_msg void OnWzdButton2();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDVIEW_H__1EC84993_C589_11D1_9B5C_00AA003D8695__INCLUDED_)
