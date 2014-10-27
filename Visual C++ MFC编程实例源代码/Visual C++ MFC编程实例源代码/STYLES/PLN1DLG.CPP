// Pln1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "Pln1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlain1Dlg dialog


CPlain1Dlg::CPlain1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlain1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlain1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(255,255,255));
}


void CPlain1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlain1Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlain1Dlg, CDialog)
	//{{AFX_MSG_MAP(CPlain1Dlg)
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlain1Dlg message handlers

#define NSTYLES 12
#define XSPACING 7
#define YSPACING 20

int CPlain1Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
		WS_CAPTION,
		WS_CAPTION|WS_SYSMENU,
		WS_CAPTION|WS_SYSMENU|WS_MAXIMIZEBOX|WS_MINIMIZEBOX,
		WS_CAPTION|WS_HSCROLL|WS_VSCROLL,
		WS_CAPTION|WS_SYSMENU,
		WS_CAPTION|WS_SYSMENU,
		WS_BORDER,
		WS_DLGFRAME,
		0,
		0,
		WS_DLGFRAME,
		WS_DLGFRAME
	};

	UINT exstyles[NSTYLES]={ 
		0,
		0,
		0,
		0,
		WS_EX_CONTEXTHELP,
		WS_EX_TOOLWINDOW,
		0,
		0,
		WS_EX_CLIENTEDGE,
		WS_EX_STATICEDGE,
		WS_EX_CLIENTEDGE,
		WS_EX_STATICEDGE
	};

	CString sStyles[NSTYLES]={ 
		"WS_CAPTION",
		"WS_CAPTION | WS_SYSMENU",
		"WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX",
		"WS_CAPTION | WS_HSCROLL | WS_VSCROLL",
		"WS_CAPTION | WS_SYSMENU and WS_EX_CONTEXTHELP",
		"WS_CAPTION | WS_SYSMENU and WS_EX_TOOLWINDOW",
		"WS_BORDER",
		"WS_DLGFRAME",
		"WS_EX_CLIENTEDGE",
		"WS_EX_STATICEDGE",
		"WS_DLGFRAME and WS_EX_CLIENTEDGE",
		"WS_DLGFRAME and WS_EX_STATICEDGE"
	};

// undrawn
//		WS_CHILD,
//		WS_OVERLAPPED,
//		WS_POPUP,
//		WS_EX_TOPMOST,
//		WS_THICKFRAME==WM_DLGFRAME except sizable,
//		WS_EX_DLGMODALFRAME==WM_DLGFRAME except...

	CSize szStatic(180,80);
	CSize szPlain1(150,80);
	CRect rect(9999,-szPlain1.cy+YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szPlain1.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CWnd *pPlain1=new CWnd;
			m_Plain1List.AddTail(pPlain1);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szPlain1.cx;
			rect.bottom=rect.top+szPlain1.cy;
			pPlain1->CreateEx(exstyles[i],AfxRegisterWndClass(0),"Plain", styles[i]|WS_VISIBLE|WS_CHILD, rect, this, 1000+i);
//			pPlain1->ShowWindow(SW_SHOW);
			rect.OffsetRect(szPlain1.cx+XSPACING,0);



			i++;
		}
	}
	
	return 0;
}

void CPlain1Dlg::PostNcDestroy() 
{
	while (m_Plain1List.GetCount())
	{
		delete m_Plain1List.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}

HBRUSH CPlain1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	hbr=(HBRUSH)m_brush.m_hObject;			
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
