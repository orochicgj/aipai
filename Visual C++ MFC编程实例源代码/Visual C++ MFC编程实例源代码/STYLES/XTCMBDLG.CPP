// XtCmbDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "XtCmbDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtComboDlg dialog


CExtComboDlg::CExtComboDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExtComboDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExtComboDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CExtComboDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExtComboDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExtComboDlg, CDialog)
	//{{AFX_MSG_MAP(CExtComboDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExtComboDlg message handlers

#define NSTYLES 2
#define XSPACING 7
#define YSPACING 20

int CExtComboDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	CBS_SIMPLE           ,
	CBS_DROPDOWN         
	};

	CString sStyles[NSTYLES]={ 
	"CBS_SIMPLE (Default)",
	"CBS_DROPDOWN"
	};

// undrawn
//	CBS_OWNERDRAWFIXED   ,
//	CBS_OWNERDRAWVARIABLE,
//	CBS_AUTOHSCROLL      ,
//	CBS_OEMCONVERT       ,
//	"CBS_DROPDOWNLIST     ",
//	"CBS_SORT             ",
//	"CBS_HASSTRINGS       ",
	//CBS_DISABLENOSCROLL|WS_VSCROLL

	CSize szStatic(160,40);
	CSize szExtCombo(200,80);
	CRect rect(9999,-YSPACING,0,0);

	m_imageList.Create(IDB_COMBO_BITMAP, 15, 1, RGB(0,0,0));

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szExtCombo.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CComboBoxEx *pExtCombo=new CComboBoxEx;
			m_ExtComboList.AddTail(pExtCombo);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szExtCombo.cx;
			rect.bottom=rect.top+szExtCombo.cy;
			pExtCombo->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szExtCombo.cx+XSPACING,0);

			pExtCombo->SetImageList(&m_imageList);
	
			COMBOBOXEXITEM cbei;
			cbei.mask = CBEIF_INDENT | CBEIF_TEXT | 
						CBEIF_IMAGE; //| CBEIF_SELECTEDIMAGE;
			char pszItem1[]={"Item 1"};
			char pszItem2[]={"Item 2"};
			char pszItem3[]={"Item 3"};
			char pszItem4[]={"Item 4"};
			
			cbei.iItem          = 0;
			cbei.pszText        = pszItem1;
			cbei.cchTextMax     = sizeof(pszItem1);
			cbei.iImage         = 0;
			cbei.iSelectedImage = 1;
			cbei.iIndent        = 0;
			pExtCombo->InsertItem(&cbei);

			cbei.iItem          = 1;
			cbei.pszText        = pszItem2;
			cbei.cchTextMax     = sizeof(pszItem2);
			cbei.iImage         = 2;
			cbei.iSelectedImage = 3;
			cbei.iIndent        = 1;
			pExtCombo->InsertItem(&cbei);

			cbei.iItem          = 2;
			cbei.pszText        = pszItem3;
			cbei.cchTextMax     = sizeof(pszItem3);
			cbei.iImage         = 4;
			cbei.iSelectedImage = 5;
			cbei.iIndent        = 2;
			pExtCombo->InsertItem(&cbei);

			cbei.iItem          = 3;
			cbei.pszText        = pszItem4;
			cbei.cchTextMax     = sizeof(pszItem4);
			cbei.iImage         = 0;
			cbei.iSelectedImage = 1;
			cbei.iIndent        = 0;
			pExtCombo->InsertItem(&cbei);


			i++;
		}
	}
	
	return 0;
}

void CExtComboDlg::PostNcDestroy() 
{
	while (m_ExtComboList.GetCount())
	{
		delete m_ExtComboList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
