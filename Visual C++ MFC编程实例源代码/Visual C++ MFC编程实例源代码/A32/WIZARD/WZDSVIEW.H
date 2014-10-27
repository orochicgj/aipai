#if !defined(AFX_WZDSCROLLVIEW_H__9A0B9501_E043_11D1_9B77_00AA003D8695__INCLUDED_)
#define AFX_WZDSCROLLVIEW_H__9A0B9501_E043_11D1_9B77_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdSView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdScrollView view

class CWzdScrollView : public CScrollView
{
protected:
	CWzdScrollView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CWzdScrollView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdScrollView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWzdScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CWzdScrollView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDSCROLLVIEW_H__9A0B9501_E043_11D1_9B77_00AA003D8695__INCLUDED_)
