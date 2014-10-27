// WzdCmbBx.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdCmbBx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdComboBox

CWzdComboBox::CWzdComboBox()
{
}

CWzdComboBox::~CWzdComboBox()
{
}


BEGIN_MESSAGE_MAP(CWzdComboBox, CComboBox)
	//{{AFX_MSG_MAP(CWzdComboBox)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdComboBox message handlers

int CWzdComboBox::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CComboBox::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	return 0;
}
