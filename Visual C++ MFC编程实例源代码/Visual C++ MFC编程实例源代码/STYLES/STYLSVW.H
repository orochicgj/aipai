// StylsVw.h : interface of the CStylesView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STYLESVIEW_H__D8E5B42E_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_STYLESVIEW_H__D8E5B42E_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CStylesView : public CView
{
protected: // create from serialization only
	CStylesView();
	DECLARE_DYNCREATE(CStylesView)

// Attributes
public:
	CStylesDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStylesView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStylesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStylesView)
	afx_msg void OnButtonStyles();
	afx_msg void OnStylesAnimation();
	afx_msg void OnStylesCalender();
	afx_msg void OnStylesCombos();
	afx_msg void OnStylesDatetime();
	afx_msg void OnStylesEdits();
	afx_msg void OnStylesExtendedcombo();
	afx_msg void OnStylesHeader();
	afx_msg void OnStylesListboxes();
	afx_msg void OnStylesListview();
	afx_msg void OnStylesProgress();
	afx_msg void OnStylesScroolbars();
	afx_msg void OnStylesSlider();
	afx_msg void OnStylesSpin();
	afx_msg void OnStylesStatics();
	afx_msg void OnStylesTab();
	afx_msg void OnStylesTreeview();
	afx_msg void OnStylesPlain1();
	afx_msg void OnStylesPlain2();
	afx_msg void OnStylesDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StylsVw.cpp
inline CStylesDoc* CStylesView::GetDocument()
   { return (CStylesDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STYLESVIEW_H__D8E5B42E_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_)
