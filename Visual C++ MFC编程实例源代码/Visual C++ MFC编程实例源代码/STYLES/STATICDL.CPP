// StaticDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "StaticDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticDlg dialog


CStaticDlg::CStaticDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStaticDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStaticDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CStaticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStaticDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStaticDlg, CDialog)
	//{{AFX_MSG_MAP(CStaticDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticDlg message handlers

#define NSTYLES 14
#define XSPACING 7
#define YSPACING 20

int CStaticDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
			SS_LEFT          ,
			SS_CENTER        ,
			SS_RIGHT         ,
			SS_NOPREFIX      ,
			SS_SUNKEN        ,
			SS_ETCHEDHORZ    ,
			SS_ETCHEDVERT    ,
			SS_ETCHEDFRAME   ,
			SS_BLACKRECT     ,
			SS_GRAYRECT      ,
			SS_WHITERECT     ,
			SS_BLACKFRAME    ,
			SS_GRAYFRAME     ,
			SS_WHITEFRAME    
	};

	CString sStyles[NSTYLES]={ 
			"SS_LEFT (Default)",
			"SS_CENTER",
			"SS_RIGHT",
			"SS_NOPREFIX",
			"SS_SUNKEN",
			"SS_ETCHEDHORZ",
			"SS_ETCHEDVERT",
			"SS_ETCHEDFRAME",
			"SS_BLACKRECT",
			"SS_GRAYRECT",
			"SS_WHITERECT",
			"SS_BLACKFRAME",
			"SS_GRAYFRAME",
			"SS_WHITEFRAME"
	};

// undrawn
//			SS_TYPEMASK      ,
//			SS_ELLIPSISMASK  
//			SS_ICON          ,
//			SS_USERITEM      ,
//			SS_OWNERDRAW     ,
//			SS_BITMAP        ,
//			SS_ENHMETAFILE   ,
//			SS_NOTIFY        ,
//			SS_CENTERIMAGE   ,
//			"SS_REALSIZEIMAGE ",
//			"SS_ENDELLIPSIS   ",
//			"SS_PATHELLIPSIS  ",
//			"SS_WORDELLIPSIS  "
//			"SS_RIGHTJUST     ",

	CSize szStatic(160,40);
	CSize szStatics(60,40);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szStatics.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CStatic *pStatics=new CStatic;
			m_StaticsList.AddTail(pStatics);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szStatics.cx;
			rect.bottom=rect.top+szStatics.cy;
			pStatics->Create("&Static", styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szStatics.cx+XSPACING,0);


			i++;
		}
	}
	
	return 0;
}

void CStaticDlg::PostNcDestroy() 
{
	while (m_StaticsList.GetCount())
	{
		delete m_StaticsList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
