// Pln2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "Pln2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlain2Dlg dialog


CPlain2Dlg::CPlain2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlain2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlain2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(255,255,255));
}


void CPlain2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlain2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlain2Dlg, CDialog)
	//{{AFX_MSG_MAP(CPlain2Dlg)
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlain2Dlg message handlers

#define NSTYLES 8
#define XSPACING 7
#define YSPACING 20

int CPlain2Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
		WS_CAPTION|WS_DLGFRAME,
		WS_CAPTION|WS_SYSMENU|WS_MAXIMIZEBOX|WS_MINIMIZEBOX|WS_DLGFRAME,
		WS_CAPTION|WS_SYSMENU|WS_MAXIMIZEBOX|WS_MINIMIZEBOX|WS_HSCROLL|WS_VSCROLL,
		WS_DLGFRAME,
		0,
		WS_DLGFRAME,
		0,
		WS_DLGFRAME
	};

	UINT exstyles[NSTYLES]={ 
		WS_EX_CLIENTEDGE,
		WS_EX_CLIENTEDGE,
		0,
		0,
		WS_EX_CLIENTEDGE,
		WS_EX_CLIENTEDGE,
		WS_EX_STATICEDGE,
		WS_EX_CLIENTEDGE
	};

	CString sStyles[NSTYLES]={ 
		"WS_CAPTION | WS_DLGFRAME and WS_EX_CLIENTEDGE",
		"Everything w/ WS_DLGFRAME and WS_EX_CLIENTEDGE",
		"Button with the works",
		"Button w/ WS_DLGFRAME",
		"Button w/ WS_EX_CLIENTEDGE",
		"Button w/ WS_DLGFRAME and WS_EX_CLIENTEDGE",
		"Button w/ WS_EX_STATICEDGE",
		"MonthCal w/ WS_DLGFRAME and WS_EX_CLIENTEDGE"
	};

	CString sClasses[NSTYLES]={
		"",
		"",
		"BUTTON",
		"BUTTON",
		"BUTTON",
		"BUTTON",
		"BUTTON",
		"SysMonthCal32"
	};

	CSize szStatic(180,80);
	CSize szPlain2(150,80);
	CRect rect(9999,-szPlain2.cy+YSPACING,0,0);

	CString classx=AfxRegisterWndClass(0);
	for (int x=0;x<NSTYLES;x++)
	{
		if (sClasses[x].IsEmpty()) sClasses[x]=classx;
	}


	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szPlain2.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CWnd *pPlain2=new CWnd;
			m_Plain2List.AddTail(pPlain2);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szPlain2.cx;
			rect.bottom=rect.top+szPlain2.cy;
			
			CString str;
			if (i>1)
				str="Button";
			else
				str="Plain";

			pPlain2->CreateEx(exstyles[i],sClasses[i],str, styles[i]|WS_VISIBLE|WS_CHILD, rect, this, 1000+i);
			rect.OffsetRect(szPlain2.cx+XSPACING,0);



			i++;
		}
	}
	
	return 0;
}

void CPlain2Dlg::PostNcDestroy() 
{
	while (m_Plain2List.GetCount())
	{
		delete m_Plain2List.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}

HBRUSH CPlain2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
//	hbr=(HBRUSH)m_brush.m_hObject;			
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
