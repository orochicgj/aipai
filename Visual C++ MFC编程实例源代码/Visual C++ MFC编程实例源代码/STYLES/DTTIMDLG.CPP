// DtTimDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "DateTime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDateTimeDlg dialog


CDateTimeDlg::CDateTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDateTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDateTimeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDateTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDateTimeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDateTimeDlg, CDialog)
	//{{AFX_MSG_MAP(CDateTimeDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateTimeDlg message handlers

#define NSTYLES 6
#define XSPACING 7
#define YSPACING 20

int CDateTimeDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	DTS_SHORTDATEFORMAT,
	DTS_LONGDATEFORMAT ,
	DTS_UPDOWN         ,
	DTS_SHOWNONE       ,
	DTS_TIMEFORMAT     ,
	DTS_RIGHTALIGN     
	};

	CString sStyles[NSTYLES]={ 
	"DTS_SHORTDATEFORMAT (Default)",
	"DTS_LONGDATEFORMAT",
	"DTS_UPDOWN",
	"DTS_SHOWNONE",
	"DTS_TIMEFORMAT",
	"DTS_RIGHTALIGN"
	};

// undrawn
//	"DTS_APPCANPARSE    ",

	CSize szStatic(180,40);
	CSize szDateTime(200,28);
	CRect rect(9999,-szDateTime.cy+YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szDateTime.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CDateTimeCtrl *pDateTime=new CDateTimeCtrl;
			m_DateTimeList.AddTail(pDateTime);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szDateTime.cx;
			rect.bottom=rect.top+szDateTime.cy;
			pDateTime->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szDateTime.cx+XSPACING,0);


			switch(styles[i])
			{
			case BS_CHECKBOX:
			case BS_LEFTTEXT|BS_CHECKBOX:
			case BS_PUSHLIKE|BS_CHECKBOX:
				break;
			case BS_MULTILINE:
				pDateTime->SetWindowText("DateTime DateTime");
				break;
			case BS_3STATE:
				break;

			}

			i++;
		}
	}
	
	return 0;
}

void CDateTimeDlg::PostNcDestroy() 
{
	while (m_DateTimeList.GetCount())
	{
		delete m_DateTimeList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
