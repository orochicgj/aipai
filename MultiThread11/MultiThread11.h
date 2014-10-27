// MultiThread11.h : main header file for the MULTITHREAD11 application
//

#if !defined(AFX_MULTITHREAD11_H__AA7A3EE5_DB9D_4215_9102_B2F1BB6BA1FA__INCLUDED_)
#define AFX_MULTITHREAD11_H__AA7A3EE5_DB9D_4215_9102_B2F1BB6BA1FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThread11App:
// See MultiThread11.cpp for the implementation of this class
//

class CMultiThread11App : public CWinApp
{
public:
	CMultiThread11App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread11App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThread11App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD11_H__AA7A3EE5_DB9D_4215_9102_B2F1BB6BA1FA__INCLUDED_)
