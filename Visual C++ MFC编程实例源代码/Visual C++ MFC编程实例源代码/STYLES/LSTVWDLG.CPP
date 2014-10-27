// LstVwDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "ListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListViewDlg dialog


CListViewDlg::CListViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListViewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CListViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListViewDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CListViewDlg, CDialog)
	//{{AFX_MSG_MAP(CListViewDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListViewDlg message handlers

#define NSTYLES 7
#define XSPACING 7
#define YSPACING 20

int CListViewDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	LVS_ICON|LVS_ALIGNTOP,
	LVS_REPORT         ,
	LVS_SMALLICON      ,
	LVS_LIST           ,
	LVS_NOCOLUMNHEADER | LVS_REPORT ,
	LVS_NOSORTHEADER | LVS_REPORT,   
	LVS_REPORT         ,
	};

	CString sStyles[NSTYLES]={ 
	"LVS_ICON | LVS_ALIGNTOP (Default)",
	"LVS_REPORT",
	"LVS_SMALLICON",
	"LVS_LIST",
	"LVS_REPORT | LVS_NOCOLUMNHEADER",
	"LVS_REPORT | LVS_NOSORTHEADER",
	"LVS_REPORT w/ LVS_EX_GRIDLINES"
	};

// undrawn
//LVS_TYPEMASK            0x0003
//LVS_TYPESTYLEMASK       0xfc00
//LVS_ALIGNMASK           0x0c00
//	LVS_NOSCROLL       ,
//	LVS_SINGLESEL      ,
//	LVS_SHOWSELALWAYS  ,
//	LVS_SORTASCENDING  ,
//	LVS_SORTDESCENDING ,
//	LVS_SHAREIMAGELISTS,
//	LVS_NOLABELWRAP    ,
//	LVS_AUTOARRANGE    ,
//	LVS_EDITLABELS     ,
//	LVS_OWNERDATA      ,
//	LVS_OWNERDRAWFIXED ,

	CSize szStatic(180,40);
	CSize szListView(200,80);
	CRect rect(9999,-szListView.cy+YSPACING,0,0);

	m_imageState.Create(IDB_STATUS_BITMAP, 16, 1, RGB(0,0,0));

	m_imageSmall.Create(IDB_SMALL_BITMAP, 16, 1, RGB(0,0,0));

	m_imageLarge.Create(IDB_LARGE_BITMAP, 32, 1, RGB(0,0,0));


	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szListView.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CListCtrl *pListView=new CListCtrl;
			m_ListViewList.AddTail(pListView);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szListView.cx;
			rect.bottom=rect.top+szListView.cy;
			pListView->CreateEx(WS_EX_CLIENTEDGE,_T("SysListView32"),"", styles[i]|WS_VISIBLE|WS_CHILD, rect, this, 1000+i);
			rect.OffsetRect(szListView.cx+XSPACING,0);


/////////////////////////////////////////////////////////////////////////////////

			pListView->SetImageList(&m_imageLarge, LVSIL_NORMAL);
			pListView->SetImageList(&m_imageSmall, LVSIL_SMALL);
			pListView->SetImageList(&m_imageState, LVSIL_STATE);

			if (i==6)
				pListView->SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE,0,LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);


			CDC* dc = GetDC();
	
			TEXTMETRIC tm;
			dc->GetTextMetrics(&tm);
			ReleaseDC(dc);

			pListView->InsertColumn(0,"Column 1",LVCFMT_LEFT,10*tm.tmAveCharWidth,0);
			pListView->InsertColumn(1,"Column 2",LVCFMT_LEFT,10*tm.tmAveCharWidth,1);

			LV_ITEM lvi;
			lvi.mask = LVIF_TEXT | LVIF_IMAGE;
			lvi.iItem = 0;
			lvi.iSubItem = 0;

			lvi.pszText = "Item 1";
			lvi.iImage = 1;
			int inx=pListView->InsertItem(&lvi);
			pListView->SetItemText(inx, 1,  "Sub Item 1");
			pListView->SetItemState(inx, INDEXTOSTATEIMAGEMASK(1), 
							LVIS_STATEIMAGEMASK);

			lvi.pszText = "Item 2";
			lvi.iImage = 2;
			inx=pListView->InsertItem(&lvi);
			pListView->SetItemText(inx, 1,  "Sub Item 2");

			lvi.pszText = "Item 3";
			lvi.iImage = 1;
			inx=pListView->InsertItem(&lvi);
			pListView->SetItemText(inx, 1,  "Sub Item 3");

			lvi.pszText = "Item 4";
			lvi.iImage = 2;
			inx=pListView->InsertItem(&lvi);
			pListView->SetItemText(inx, 1,  "Sub Item 4");

			lvi.pszText = "Item 5";
			lvi.iImage = 1;
			inx=pListView->InsertItem(&lvi);
			pListView->SetItemText(inx, 1,  "Sub Item 5");
			pListView->SetItemState(inx, INDEXTOSTATEIMAGEMASK(2), 
							LVIS_STATEIMAGEMASK);

			lvi.pszText = "Item 6";
			lvi.iImage = 2;
			inx=pListView->InsertItem(&lvi);
			pListView->SetItemText(inx, 1,  "Sub Item 6");


			i++;
		}
	}
	
	return 0;
}

void CListViewDlg::PostNcDestroy() 
{
	while (m_ListViewList.GetCount())
	{
		delete m_ListViewList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
