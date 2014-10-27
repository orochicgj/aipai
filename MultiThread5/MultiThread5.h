// MultiThread5.h : main header file for the MULTITHREAD5 application
//

#if !defined(AFX_MULTITHREAD5_H__27D220B8_B872_421B_A22F_7D954C804D93__INCLUDED_)
#define AFX_MULTITHREAD5_H__27D220B8_B872_421B_A22F_7D954C804D93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThread5App:
// See MultiThread5.cpp for the implementation of this class
//

class CMultiThread5App : public CWinApp
{
public:
	CMultiThread5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThread5App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD5_H__27D220B8_B872_421B_A22F_7D954C804D93__INCLUDED_)
