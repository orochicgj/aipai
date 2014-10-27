// EditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog


CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	//{{AFX_MSG_MAP(CEditDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDlg message handlers

#define NSTYLES 8
#define XSPACING 7
#define YSPACING 20

int CEditDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	ES_LEFT		  ,	
	ES_MULTILINE  ,
	ES_MULTILINE|ES_CENTER     ,
	ES_MULTILINE|ES_RIGHT      ,
	ES_UPPERCASE  ,
	ES_LOWERCASE  ,
	ES_PASSWORD   ,
	ES_READONLY   ,
	};

	CString sStyles[NSTYLES]={ 
	"ES_LEFT (Default)"		  ,	
	"ES_MULTILINE",
	"ES_MULTILINE | ES_CENTER",
	"ES_MULTILINE | ES_RIGHT",
	"ES_UPPERCASE",
	"ES_LOWERCASE",
	"ES_PASSWORD",
	"ES_READONLY"
	};

// undrawn
//	ES_AUTOVSCROLL,
//	ES_AUTOHSCROLL,
//	ES_NOHIDESEL  ,
//	ES_OEMCONVERT ,
//	ES_WANTRETURN ,
//	ES_NUMBER     

	CSize szStatic(160,40);
	CSize szEdit(100,60);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szEdit.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CEdit *pEdit=new CEdit;
			m_EditList.AddTail(pEdit);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szEdit.cx;
			rect.bottom=rect.top+szEdit.cy;
			pEdit->CreateEx(WS_EX_CLIENTEDGE,_T("EDIT"),"", styles[i]|WS_VISIBLE|WS_CHILD, rect, this, 1000+i);
			rect.OffsetRect(szEdit.cx+XSPACING,0);

			pEdit->SetWindowText("Edit Edit Edit Edit Edit Edit Edit Edit");


			i++;
		}
	}
	
	return 0;
}

void CEditDlg::PostNcDestroy() 
{
	while (m_EditList.GetCount())
	{
		delete m_EditList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
