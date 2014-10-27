// ComboDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "ComboDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboDlg dialog


CComboDlg::CComboDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComboDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComboDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CComboDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComboDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComboDlg, CDialog)
	//{{AFX_MSG_MAP(CComboDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboDlg message handlers

#define NSTYLES 6
#define XSPACING 7
#define YSPACING 20

int CComboDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	CBS_SIMPLE           ,
	CBS_DROPDOWN         ,
	CBS_UPPERCASE        ,
	CBS_LOWERCASE        ,
	CBS_NOINTEGRALHEIGHT ,
	WS_VSCROLL			 
	};

	CString sStyles[NSTYLES]={ 
	"CBS_SIMPLE (Default)",
	"CBS_DROPDOWN",
	"CBS_UPPERCASE",
	"CBS_LOWERCASE",
	"CBS_NOINTEGRALHEIGHT",
	"WS_VSCROLL"
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

	CSize szStatic(180,40);
	CSize szCombo(80,85);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szCombo.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CComboBox *pCombo=new CComboBox;
			m_ComboList.AddTail(pCombo);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szCombo.cx;
			rect.bottom=rect.top+szCombo.cy;
			pCombo->Create(styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szCombo.cx+XSPACING,0);

			pCombo->AddString("Combo 1");
			pCombo->AddString("Combo 2");
			pCombo->AddString("Combo 3");
			pCombo->AddString("Combo 4");
			pCombo->AddString("Combo 5");
			pCombo->AddString("Combo 6");

			i++;
		}
	}
	
	return 0;
}

void CComboDlg::PostNcDestroy() 
{
	while (m_ComboList.GetCount())
	{
		delete m_ComboList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
