// AnimtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "AnimtDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimateDlg dialog


CAnimateDlg::CAnimateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnimateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAnimateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnimateDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAnimateDlg, CDialog)
	//{{AFX_MSG_MAP(CAnimateDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimateDlg message handlers

#define NSTYLES 5
#define XSPACING 7
#define YSPACING 20

int CAnimateDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	0,
	ACS_CENTER     	,
	ACS_TRANSPARENT	,
	ACS_AUTOPLAY   	,
	ACS_TIMER      
	};

	CString sStyles[NSTYLES]={ 
	"Default",
	"ACS_CENTER     "	,
	"ACS_TRANSPARENT"	,
	"ACS_AUTOPLAY   "	,
	"ACS_TIMER      "
	};

// undrawn
//			BS_OWNERDRAW        0x0000000BL
//			BS_ICON             0x00000040L
//			BS_BITMAP           0x00000080L
//			BS_NOTIFY,           0x00004000L
//			BS_AUTOCHECKBOX,
//			BS_AUTO3STATE,
//			BS_USERAnimate,
//			BS_AUTORADIOAnimate,
//			"BS_VCENTER",   

	CSize szStatic(160,40);
	CSize szAnimate(60,40);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szAnimate.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CAnimateCtrl *pAnimate=new CAnimateCtrl;
			m_AnimateList.AddTail(pAnimate);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szAnimate.cx;
			rect.bottom=rect.top+szAnimate.cy;
			pAnimate->Create( styles[i]|WS_VISIBLE|WS_CHILD, rect, this, 1000+i);
			rect.OffsetRect(szAnimate.cx+XSPACING,0);

			switch(styles[i])
			{
			case BS_CHECKBOX:
			case BS_LEFTTEXT|BS_CHECKBOX:
			case BS_PUSHLIKE|BS_CHECKBOX:
				break;
			case BS_MULTILINE:
				pAnimate->SetWindowText("Animate Animate");
				break;
			case BS_3STATE:
				break;

			}

			i++;
		}
	}
	
	return 0;
}

void CAnimateDlg::PostNcDestroy() 
{
	while (m_AnimateList.GetCount())
	{
		delete m_AnimateList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
