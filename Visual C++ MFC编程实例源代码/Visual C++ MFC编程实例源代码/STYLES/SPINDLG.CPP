// SpinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "SpinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpinDlg dialog


CSpinDlg::CSpinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpinDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpinDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSpinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpinDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpinDlg, CDialog)
	//{{AFX_MSG_MAP(CSpinDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpinDlg message handlers

#define NSTYLES 2
#define XSPACING 7
#define YSPACING 20

int CSpinDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	0,
	UDS_HORZ        
	};

	CString sStyles[NSTYLES]={ 
	"Default",
	"UDS_HORZ"
	};

// undrawn
//	"UDS_WRAP        ",
//	"UDS_SETBUDDYINT ",
//	"UDS_ALIGNRIGHT  ",
//	"UDS_ALIGNLEFT   ",
//	"UDS_AUTOBUDDY   ",
//	"UDS_ARROWKEYS   ",
//	"UDS_NOTHOUSANDS ",
//	"UDS_HOTTRACK    "

	CSize szStatic(160,40);
	CSize szSpin(60,40);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szSpin.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CSpinButtonCtrl *pSpin=new CSpinButtonCtrl;
			m_SpinList.AddTail(pSpin);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szSpin.cx;
			rect.bottom=rect.top+szSpin.cy;
			pSpin->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szSpin.cx+XSPACING,0);


			switch(styles[i])
			{
			case BS_CHECKBOX:
			case BS_LEFTTEXT|BS_CHECKBOX:
			case BS_PUSHLIKE|BS_CHECKBOX:
				break;
			case BS_MULTILINE:
				pSpin->SetWindowText("Spin Spin");
				break;
			case BS_3STATE:
				break;

			}

			i++;
		}
	}
	
	return 0;
}

void CSpinDlg::PostNcDestroy() 
{
	while (m_SpinList.GetCount())
	{
		delete m_SpinList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
