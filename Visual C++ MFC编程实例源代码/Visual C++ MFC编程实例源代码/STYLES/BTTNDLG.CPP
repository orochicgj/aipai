// BttnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "BttnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CButtonDlg dialog


CButtonDlg::CButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CButtonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CButtonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CButtonDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CButtonDlg, CDialog)
	//{{AFX_MSG_MAP(CButtonDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonDlg message handlers

#define NSTYLES 14
#define XSPACING 7
#define YSPACING 20

int CButtonDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
			BS_PUSHBUTTON,
			BS_DEFPUSHBUTTON,
			BS_CHECKBOX,
			BS_LEFTTEXT|BS_CHECKBOX,
			BS_PUSHLIKE|BS_CHECKBOX,  
			BS_3STATE,
			BS_RADIOBUTTON,
			BS_FLAT,       
			BS_LEFT,      
			BS_RIGHT,     
			BS_TOP    ,   
			BS_BOTTOM,    
			BS_MULTILINE, 
			BS_GROUPBOX
	};

	CString sStyles[NSTYLES]={ 
			"BS_PUSHBUTTON (Default)",
			"BS_DEFPUSHBUTTON",
			"BS_CHECKBOX",
			"BS_CHECKBOX | BS_LEFTTEXT",
			"BS_CHECKBOX | BS_PUSHLIKE",  
			"BS_3STATE",
			"BS_RADIOBUTTON",
			"BS_FLAT"       ,
			"BS_LEFT",      
			"BS_RIGHT",     
			"BS_TOP"    ,   
			"BS_BOTTOM",    
			"BS_MULTILINE", 
			"BS_GROUPBOX"
	};

// undrawn
//			BS_OWNERDRAW        0x0000000BL
//			BS_ICON             0x00000040L
//			BS_BITMAP           0x00000080L
//			BS_NOTIFY,           0x00004000L
//			BS_AUTOCHECKBOX,
//			BS_AUTO3STATE,
//			BS_USERBUTTON,
//			BS_AUTORADIOBUTTON,
//			"BS_VCENTER",   

	CSize szStatic(160,40);
	CSize szButton(60,40);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szButton.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CButton *pButton=new CButton;
			m_buttonList.AddTail(pButton);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szButton.cx;
			rect.bottom=rect.top+szButton.cy;
			pButton->Create("Button", styles[i]|WS_VISIBLE|WS_CHILD, rect,this,1000+i );
			rect.OffsetRect(szButton.cx+XSPACING,0);


			switch(styles[i])
			{
			case BS_CHECKBOX:
			case BS_LEFTTEXT|BS_CHECKBOX:
			case BS_PUSHLIKE|BS_CHECKBOX:
			case BS_RADIOBUTTON:
				pButton->SetCheck(TRUE);
				break;
			case BS_MULTILINE:
				pButton->SetWindowText("Button Button");
				break;
			case BS_3STATE:
				pButton->SetCheck(2);
				break;

			}

			i++;
		}
	}
	
	return 0;
}

void CButtonDlg::PostNcDestroy() 
{
	while (m_buttonList.GetCount())
	{
		delete m_buttonList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
