#if !defined(AFX_WZDSHEET_H__A846F4D6_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_WZDSHEET_H__A846F4D6_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SampleWzdSheet.h : header file
//

#include "afxtempl.h"

struct SAMPLES{
	CString *pName;
	CArray <SAMPLES*,SAMPLES*> *pSamples;
};

typedef CArray<SAMPLES*,SAMPLES*> CSAMPLEARRAY;

class CSampleWzdSheet;
class CPage1;
class CPage2;
class CPage3;
class CPage4;
class CPage5;
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"
#include "Page4.h"
#include "Page5.h"

/////////////////////////////////////////////////////////////////////////////
// CSampleWzdSheet

class CSampleWzdSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSampleWzdSheet)

// Construction
public:
	CSampleWzdSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSampleWzdSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CPage1 m_Page1;
	CPage2 m_Page2;
	CPage3 m_Page3;
	CPage4 m_Page4;
	CPage5 m_Page5;
	CSAMPLEARRAY m_samples;
	CSAMPLEARRAY *m_pSection;
	CSAMPLEARRAY *m_pChapter;
	CString m_sCwdDir;
	CString m_sExeDir;
	CString m_sExample;
	CString m_sTargetDir;
	CString m_sSourceRootDir;
	CString m_sSubstitution;
	CString m_sLowerSub;
	CString m_sUpperSub;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleWzdSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSampleWzdSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSampleWzdSheet)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif //!defined(AFX_WZDSHEET_H__A846F4D6_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_)
