// ProgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "ProgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog


CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgressDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgressDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
	//{{AFX_MSG_MAP(CProgressDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg message handlers

#define NSTYLES 3
#define XSPACING 7
#define YSPACING 20

int CProgressDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	0,
	PBS_VERTICAL ,
	PBS_SMOOTH
	};

	CString sStyles[NSTYLES]={ 
	"Default",
	"PBS_VERTICAL" ,
	"PBS_SMOOTH" 
	};

// undrawn
//			PBS_SMOOTH

	CSize szStatic(160,40);
	CSize szProgress1(100,30);
	CSize szProgress2(30,100);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szProgress1.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CSize szProgress;
			if (j==0)
				szProgress=szProgress1;
			else
				szProgress=szProgress2;

			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CProgressCtrl *pProgress=new CProgressCtrl;
			m_ProgressList.AddTail(pProgress);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szProgress.cx;
			rect.bottom=rect.top+szProgress.cy;
			pProgress->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szProgress.cx+XSPACING,0);

			pProgress->SetRange(0,100);
			pProgress->SetPos(33);

			i++;
		}
	}
	
	return 0;
}

void CProgressDlg::PostNcDestroy() 
{
	while (m_ProgressList.GetCount())
	{
		delete m_ProgressList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
