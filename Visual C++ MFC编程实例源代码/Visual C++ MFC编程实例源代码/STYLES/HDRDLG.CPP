// HdrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "HdrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHeaderDlg dialog


CHeaderDlg::CHeaderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHeaderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHeaderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHeaderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHeaderDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHeaderDlg, CDialog)
	//{{AFX_MSG_MAP(CHeaderDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHeaderDlg message handlers

#define NSTYLES 2
#define XSPACING 7
#define YSPACING 20

int CHeaderDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	HDS_HORZ     ,
	HDS_BUTTONS  , 
	};

	CString sStyles[NSTYLES]={ 
	"HDS_HORZ (Default)"    ,
	"HDS_BUTTONS", 
	};

// undrawn
//	HDS_HOTTRACK , 
//	HDS_HIDDEN   , 
//	HDS_DRAGDROP , 
//	HDS_FULLDRAG   

	CSize szStatic(160,40);
	CSize szHeader(400,25);
	CRect rect(9999,-YSPACING,0,0);

	m_bitmap.LoadBitmap(IDB_ONE_BITMAP);
	m_imageList.Create(IDB_COMBO_BITMAP, 15, 1, RGB(0,0,0));

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szHeader.cy+YSPACING;

		for (int j=0;j<1&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CHeaderCtrl *pHeader=new CHeaderCtrl;
			m_HeaderList.AddTail(pHeader);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szHeader.cx;
			rect.bottom=rect.top+szHeader.cy;
			pHeader->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szHeader.cx+XSPACING,0);

			char pszHeader1[]={"Header1"};
			char pszHeader2[]={"Header2"};
			char pszHeader4[]={"Header4"};

			HD_ITEM hdi;
			hdi.mask=HDI_TEXT|HDI_WIDTH|HDI_FORMAT;
			hdi.fmt=HDF_CENTER|HDF_STRING ;
			hdi.cxy=100;
			hdi.pszText=pszHeader1;
			hdi.cchTextMax=sizeof(pszHeader1);
			pHeader->InsertItem(0,&hdi);
			hdi.pszText=pszHeader2;
			hdi.cchTextMax=sizeof(pszHeader2);
			pHeader->InsertItem(1,&hdi);

		    hdi.mask = HDI_FORMAT | HDI_WIDTH | HDI_BITMAP; 
		    hdi.fmt = HDF_CENTER|HDF_BITMAP;
			hdi.cxy = 100;
			hdi.hbm = HBITMAP(m_bitmap); 
			pHeader->InsertItem(2,&hdi);

			pHeader->SetImageList(&m_imageList);
			hdi.mask=HDI_IMAGE	| HDI_FORMAT| HDI_TEXT;
			hdi.fmt=HDF_LEFT |HDF_IMAGE | HDF_STRING;
			hdi.pszText=pszHeader4;
			hdi.cchTextMax=sizeof(pszHeader4);
			hdi.iImage= 1;
			hdi.cxy=100;
			pHeader->InsertItem(3,&hdi);

			i++;
		}
	}
	
	return 0;
}

void CHeaderDlg::PostNcDestroy() 
{
	while (m_HeaderList.GetCount())
	{
		delete m_HeaderList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
