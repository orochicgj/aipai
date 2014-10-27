// ScrllDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "ScrllDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScrollDlg dialog


CScrollDlg::CScrollDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScrollDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScrollDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CScrollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScrollDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScrollDlg, CDialog)
	//{{AFX_MSG_MAP(CScrollDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollDlg message handlers

#define NSTYLES 7
#define XSPACING 7
#define YSPACING 20

int CScrollDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	SBS_HORZ                    ,
	SBS_VERT                    ,
	SBS_TOPALIGN                ,
	SBS_BOTTOMALIGN             ,
	SBS_VERT|SBS_LEFTALIGN               ,
	SBS_VERT|SBS_RIGHTALIGN              ,
	SBS_SIZEGRIP                
	};

	CString sStyles[NSTYLES]={ 
	"SBS_HORZ (Default)" ,
	"SBS_VERT" ,
	"SBS_TOPALIGN" ,
	"SBS_BOTTOMALIGN" ,
	"SBS_VERT | SBS_LEFTALIGN" ,
	"SBS_VERT | SBS_RIGHTALIGN" ,
	"SBS_SIZEGRIP" 
	};

// undrawn
//	"SBS_SIZEBOXTOPLEFTALIGN    " ,
//	"SBS_SIZEBOXBOTTOMRIGHTALIGN" ,
//	"SBS_SIZEBOX                " 

	CSize szStatic(160,40);
	CSize szScroll(80,80);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szScroll.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CScrollBar *pScroll=new CScrollBar;
			m_ScrollList.AddTail(pScroll);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szScroll.cx;
			rect.bottom=rect.top+szScroll.cy;
			pScroll->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szScroll.cx+XSPACING,0);


			switch(styles[i])
			{
			case BS_CHECKBOX:
			case BS_LEFTTEXT|BS_CHECKBOX:
			case BS_PUSHLIKE|BS_CHECKBOX:
				break;
			case BS_MULTILINE:
				pScroll->SetWindowText("Scroll Scroll");
				break;
			case BS_3STATE:
				break;

			}

			i++;
		}
	}
	
	return 0;
}

void CScrollDlg::PostNcDestroy() 
{
	while (m_ScrollList.GetCount())
	{
		delete m_ScrollList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
