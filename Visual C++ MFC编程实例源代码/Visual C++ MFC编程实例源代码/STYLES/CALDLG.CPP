// CalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "CalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalenderDlg dialog


CCalenderDlg::CCalenderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalenderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalenderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCalenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalenderDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCalenderDlg, CDialog)
	//{{AFX_MSG_MAP(CCalenderDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalenderDlg message handlers

#define NSTYLES 5
#define XSPACING 7
#define YSPACING 20

int CCalenderDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	0,
	MCS_DAYSTATE   ,
	MCS_MULTISELECT,
	MCS_WEEKNUMBERS,
	MCS_NOTODAY
	};

	CString sStyles[NSTYLES]={ 
	"Default",
	"MCS_DAYSTATE",
	"MCS_MULTISELECT",
	"MCS_WEEKNUMBERS",
	"MCS_NOTODAY"
	};

// undrawn
//			BS_OWNERDRAW        0x0000000BL
//			BS_ICON             0x00000040L
//			BS_BITMAP           0x00000080L
//			BS_NOTIFY,           0x00004000L
//			BS_AUTOCHECKBOX,
//			BS_AUTO3STATE,
//			BS_USERCalender,
//			BS_AUTORADIOCalender,
//			"BS_VCENTER",   

	CSize szStatic(160,40);
	CSize szCalender(200,160);
	CRect rect(9999,-szCalender.cy+YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szCalender.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CMonthCalCtrl *pCalender=new CMonthCalCtrl;
			m_CalenderList.AddTail(pCalender);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szCalender.cx;
			rect.bottom=rect.top+szCalender.cy;
			pCalender->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szCalender.cx+XSPACING,0);


			switch(styles[i])
			{
			case BS_CHECKBOX:
			case BS_LEFTTEXT|BS_CHECKBOX:
			case BS_PUSHLIKE|BS_CHECKBOX:
				break;
			case BS_MULTILINE:
				pCalender->SetWindowText("Calender Calender");
				break;
			case BS_3STATE:
				break;

			}

			i++;
		}
	}
	
	return 0;
}

void CCalenderDlg::PostNcDestroy() 
{
	while (m_CalenderList.GetCount())
	{
		delete m_CalenderList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
