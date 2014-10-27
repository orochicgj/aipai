// WzdPrjct.h : project include file
//
/////////////////////////////////////////////////////////////////////////////

#if !defined WZDPROJECT_H
#define WZDPROJECT_H


////////// define message /////////////
#define WM_WZD_MESSAGE WM_USER+1


///////// define message macro ////////////////
#define ON_WZD_MESSAGE() \
{WM_WZD_MESSAGE, 0, 0, 0, AfxSig_vW, (AFX_PMSG)(AFX_PMSGW)(void \
(AFX_MSG_CALL CWnd::*)(CWnd *))&OnWzdMessage},

// NOTE: other values for AfxSig_vW are in AFXMSG_.H


#endif
