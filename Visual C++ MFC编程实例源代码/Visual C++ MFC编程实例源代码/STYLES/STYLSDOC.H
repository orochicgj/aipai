// StylsDoc.h : interface of the CStylesDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STYLESDOC_H__D8E5B42C_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_STYLESDOC_H__D8E5B42C_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CStylesDoc : public CDocument
{
protected: // create from serialization only
	CStylesDoc();
	DECLARE_DYNCREATE(CStylesDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStylesDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStylesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStylesDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STYLESDOC_H__D8E5B42C_BBF1_11D1_A18D_DCB3C85EBD34__INCLUDED_)
