// SldrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "SldrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSliderDlg dialog


CSliderDlg::CSliderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSliderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSliderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSliderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSliderDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSliderDlg, CDialog)
	//{{AFX_MSG_MAP(CSliderDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSliderDlg message handlers

#define NSTYLES 11
#define XSPACING 7
#define YSPACING 20

int CSliderDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	TBS_HORZ          ,
	TBS_VERT          ,
	TBS_TOP           ,
	TBS_BOTTOM        ,
	TBS_LEFT|TBS_VERT          ,
	TBS_RIGHT|TBS_VERT         ,
	TBS_BOTH          ,
	TBS_BOTH|TBS_VERT          ,
	TBS_NOTICKS       ,
	TBS_ENABLESELRANGE,
	TBS_NOTHUMB       ,
	};

	CString sStyles[NSTYLES]={ 
	"TBS_HORZ (Default)"         ,
	"TBS_VERT"          ,
	"TBS_TOP"           ,
	"TBS_BOTTOM"        ,
	"TBS_LEFT | TBS_VERT"          ,
	"TBS_RIGHT | TBS_VERT"         ,
	"TBS_BOTH"          ,
	"TBS_BOTH | TBS_VERT"          ,
	"TBS_NOTICKS"       ,
	"TBS_ENABLESELRANGE",
	"TBS_NOTHUMB"       ,
	};

// undrawn
//	TBS_AUTOTICKS     ,
//	TBS_FIXEDLENGTH   ,
//	TBS_TOOLTIPS      

	CSize szStatic(160,40);
	CSize szSlider(80,80);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szSlider.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CSliderCtrl *pSlider=new CSliderCtrl;
			m_SliderList.AddTail(pSlider);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szSlider.cx;
			rect.bottom=rect.top+szSlider.cy;
			pSlider->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szSlider.cx+XSPACING,0);

			pSlider->SetRange(0,100);
			pSlider->SetSelection(30,60);


			i++;
		}
	}
	
	return 0;
}

void CSliderDlg::PostNcDestroy() 
{
	while (m_SliderList.GetCount())
	{
		delete m_SliderList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
