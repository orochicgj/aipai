// SampWzd.h : main header file for the SAMPLEWZD application
//

#if !defined(AFX_WZD_H__A846F4C9_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_)
#define AFX_WZD_H__A846F4C9_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSampleWzdApp:
// See SampWzd.cpp for the implementation of this class
//

class CSampleWzdApp : public CWinApp
{
public:
	CSampleWzdApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleWzdApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSampleWzdApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif //!defined(AFX_WZD_H__A846F4C9_ECA0_11D1_A18D_DCB3C85EBD34__INCLUDED_)
