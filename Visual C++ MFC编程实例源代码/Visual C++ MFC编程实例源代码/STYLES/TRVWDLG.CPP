// BttnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "TrVwDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeViewDlg dialog


CTreeViewDlg::CTreeViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTreeViewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTreeViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreeViewDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTreeViewDlg, CDialog)
	//{{AFX_MSG_MAP(CTreeViewDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeViewDlg message handlers

#define NSTYLES 6
#define XSPACING 7
#define YSPACING 20

int CTreeViewDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	0,
	TVS_HASBUTTONS         ,
	TVS_HASLINES           ,
	TVS_CHECKBOXES         ,
	TVS_TRACKSELECT        ,
	TVS_HASBUTTONS | TVS_HASLINES|TVS_LINESATROOT
	};

	CString sStyles[NSTYLES]={ 
	"Default",
	"TVS_HASBUTTONS"  ,
	"TVS_HASLINES"  ,
	"TVS_CHECKBOXES"  ,
	"TVS_TRACKSELECT"  ,
	"TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT"
	};

//	"TVS_SHAREDIMAGELISTS "  ,
//	"TVS_PRIVATEIMAGELISTS"
// undrawn
//	TVS_EDITLABELS         ,
//	TVS_DISABLEDRAGDROP    ,
//	TVS_SHOWSELALWAYS      ,
//	TVS_RTLREADING         ,
//	TVS_NOTOOLTIPS         ,

	CSize szStatic(160,60);
	CSize szTreeView(200,80);
	CRect rect(9999,-YSPACING,0,0);

	m_imageState.Create(IDB_STATUS_BITMAP, 16, 1, RGB(0,0,0));
	m_imageSmall.Create(IDB_SMALL_BITMAP, 16, 1, RGB(0,0,0));

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szTreeView.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CTreeCtrl *pTreeView=new CTreeCtrl;
			m_TreeViewList.AddTail(pTreeView);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szTreeView.cx;
			rect.bottom=rect.top+szTreeView.cy;
			pTreeView->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szTreeView.cx+XSPACING,0);

///////////////////////////////////////////////////////////////
			pTreeView->SetImageList(&m_imageSmall, LVSIL_NORMAL);
			pTreeView->SetImageList(&m_imageState, LVSIL_STATE);

			char pszItem1[]={"Item 1"};
			char pszItem2[]={"Item 2"};
			char pszItem3[]={"Item 3"};
			char pszItem4[]={"Item 4"};
			char pszItem5[]={"Item 5"};

			TV_INSERTSTRUCT		tvi;
			tvi.item.mask = TVIF_IMAGE | TVIF_TEXT |TVIF_SELECTEDIMAGE;//|TVIF_STATE;

			tvi.hParent = TVI_ROOT;
			tvi.hInsertAfter = TVI_LAST;
			tvi.item.iImage = tvi.item.iSelectedImage =0;
			tvi.item.pszText = pszItem1;
			tvi.item.stateMask=TVIS_STATEIMAGEMASK;
			tvi.item.state=INDEXTOSTATEIMAGEMASK(1);
			HTREEITEM hTreeRoot = pTreeView->InsertItem(&tvi);

			tvi.hParent = hTreeRoot;
			tvi.hInsertAfter = TVI_LAST;
			tvi.item.iImage = tvi.item.iSelectedImage =1;
			tvi.item.pszText = pszItem2;
			tvi.item.stateMask=TVIS_STATEIMAGEMASK;
			tvi.item.state=INDEXTOSTATEIMAGEMASK(2);
			HTREEITEM hTreeItem1 = pTreeView->InsertItem(&tvi);

			tvi.hParent = hTreeItem1;
			tvi.hInsertAfter = TVI_LAST;
			tvi.item.iImage = tvi.item.iSelectedImage =2;
			tvi.item.pszText = pszItem3;
			tvi.item.stateMask=TVIS_STATEIMAGEMASK;
			tvi.item.state=INDEXTOSTATEIMAGEMASK(0);
			pTreeView->InsertItem(&tvi);

			tvi.hParent = TVI_ROOT;
			tvi.hInsertAfter = TVI_LAST;
			tvi.item.iImage = tvi.item.iSelectedImage =3;
			tvi.item.pszText = pszItem4;
			tvi.item.stateMask=TVIS_STATEIMAGEMASK;
			tvi.item.state=INDEXTOSTATEIMAGEMASK(1);
			pTreeView->InsertItem(&tvi);

			tvi.item.mask = TVIF_IMAGE | TVIF_TEXT |TVIF_SELECTEDIMAGE|TVIF_STATE;
			tvi.hParent = hTreeItem1;
			tvi.hInsertAfter = TVI_LAST;
			tvi.item.iImage = tvi.item.iSelectedImage =4;
			tvi.item.pszText = pszItem5;
			tvi.item.stateMask=TVIS_STATEIMAGEMASK;
			tvi.item.state=INDEXTOSTATEIMAGEMASK(1);
			pTreeView->InsertItem(&tvi);


			i++;
		}
	}
	
	return 0;
}

void CTreeViewDlg::PostNcDestroy() 
{
	while (m_TreeViewList.GetCount())
	{
		delete m_TreeViewList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
