// WzdTlBar.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdTlBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdToolBar

CWzdToolBar::CWzdToolBar()
{
}

CWzdToolBar::~CWzdToolBar()
{
}


BEGIN_MESSAGE_MAP(CWzdToolBar, CToolBar)
	//{{AFX_MSG_MAP(CWzdToolBar)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdToolBar message handlers

BOOL CWzdToolBar::LoadToolBarEx(UINT nID,TOOLTEXT *pToolText,int nCnt)
{
	BOOL bRet;
	if (bRet=LoadToolBar(nID))
	{
		// loop thru tooltext adding text to buttons
		for (int i=0;i<nCnt;i++)
		{
			// find button
			TBBUTTON tb;
			int inx=CommandToIndex(pToolText[i].idCommand);
			GetToolBarCtrl().GetButton(inx,&tb);

			// get text for button
			CString str;
			str.LoadString(pToolText[i].idString);

			// add a second NULL to string for AddStrings()
			int nLen = str.GetLength() + 1;
			TCHAR * pStr = str.GetBufferSetLength(nLen);
			pStr[nLen] = 0;

			// add new button using AddStrings
			tb.iString=GetToolBarCtrl().AddStrings(pStr);
			str.ReleaseBuffer();

			// (no ModifyButton() function)
			GetToolBarCtrl().DeleteButton(inx);
			GetToolBarCtrl().InsertButton(inx,&tb);
		}

		// make buttons larger to handle added text
		CSize sizeImage(16,15);
		CSize sizeButton(35,35);
		SetSizes(sizeButton, sizeImage);
	}
	return bRet;
}
