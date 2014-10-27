// TabDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "TabDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabDlg dialog


CTabDlg::CTabDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTabDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTabDlg, CDialog)
	//{{AFX_MSG_MAP(CTabDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabDlg message handlers

#define NSTYLES 8
#define XSPACING 7
#define YSPACING 20

int CTabDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	0,
	TCS_BOTTOM           ,
	TCS_VERTICAL         ,
	TCS_RIGHT|TCS_VERTICAL ,
	TCS_BUTTONS          ,
	TCS_MULTILINE        ,
	TCS_FIXEDWIDTH       ,
	TCS_SCROLLOPPOSITE   
	};

	CString sStyles[NSTYLES]={ 
	"Default",
	"TCS_BOTTOM",
	"TCS_VERTICAL",
	"TCS_RIGHT | TCS_VERTICAL",
	"TCS_BUTTONS",
	"TCS_MULTILINE",
	"TCS_FIXEDWIDTH",
	"TCS_SCROLLOPPOSITE"
	};

// undrawn
//	TCS_OWNERDRAWFIXED   ,
//	TCS_TOOLTIPS         ,
//	TCS_FOCUSNEVER       
//	TCS_MULTISELECT      ,
//	"TCS_FORCEICONLEFT    ",
//	"TCS_FORCELABELLEFT   ",
//	"TCS_SINGLELINE       ",
//	"TCS_RIGHTJUSTIFY     ",
//	"TCS_RAGGEDRIGHT      ",
//	"TCS_FOCUSONBUTTONDOWN"

	CSize szStatic(160,40);
	CSize szTab(200,120);
	CRect rect(9999,-szTab.cy+YSPACING,0,0);

	char pszTab1[]="Tab1";
	char pszTab2[]="Tab2";
	char pszTab3[]="Tab3";
	char pszTab4[]="Tab4";
	char pszTab5[]="Tab5";
	char pszTab6[]="Tab6";

	m_imageList.Create(IDB_IMAGE_BITMAP, 15, 1, RGB(0,0,0));

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szTab.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CTabCtrl *pTab=new CTabCtrl;
			m_TabList.AddTail(pTab);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szTab.cx;
			rect.bottom=rect.top+szTab.cy;
			pTab->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szTab.cx+XSPACING,0);

		// add some tabs
			pTab->SetImageList(&m_imageList);
			TC_ITEM tc;
			tc.mask=TCIF_TEXT|TCIF_IMAGE;
			tc.pszText=pszTab1;
			tc.iImage=0;
			pTab->InsertItem(0,&tc);
			tc.pszText=pszTab2;
			tc.iImage=1;
			pTab->InsertItem(1,&tc);
			tc.pszText=pszTab3;
			tc.iImage=2;
			pTab->InsertItem(2,&tc);
			tc.pszText=pszTab4;
			tc.iImage=3;
			pTab->InsertItem(3,&tc);
			tc.pszText=pszTab5;
			tc.iImage=4;
			pTab->InsertItem(4,&tc);
			tc.pszText=pszTab6;
			tc.iImage=5;
			pTab->InsertItem(5,&tc);



			i++;
		}
	}
	
	return 0;
}

void CTabDlg::PostNcDestroy() 
{
	while (m_TabList.GetCount())
	{
		delete m_TabList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
