// LstBxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Styles.h"
#include "Listbox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListboxDlg dialog


CListboxDlg::CListboxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListboxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListboxDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CListboxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListboxDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CListboxDlg, CDialog)
	//{{AFX_MSG_MAP(CListboxDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListboxDlg message handlers

#define NSTYLES 8
#define XSPACING 7
#define YSPACING 20

int CListboxDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT styles[NSTYLES]={ 
	0,
	LBS_MULTIPLESEL      ,
	LBS_USETABSTOPS      ,
	LBS_NOINTEGRALHEIGHT ,
	LBS_MULTICOLUMN     ,
	LBS_NOSEL            ,
	WS_VSCROLL,
	LBS_MULTICOLUMN |WS_HSCROLL
	};

	CString sStyles[NSTYLES]={ 
	"Default",
	"LBS_MULTIPLESEL" ,
	"LBS_USETABSTOPS" ,
	"LBS_NOINTEGRALHEIGHT" ,
	"LBS_MULTICOLUMN" ,
	"LBS_NOSEL" ,
	"WS_VSCROLL",
	"LBS_MULTICOLUMN |WS_HSCROLL"
	};

// undrawn
//	LBS_NOTIFY           ,
//	LBS_SORT             ,
//	LBS_NOREDRAW         ,
//	LBS_OWNERDRAWFIXED   ,
//	LBS_OWNERDRAWVARIABLE,
//	LBS_HASSTRINGS       ,
//	LBS_EXTENDEDSEL      ,
//	LBS_WANTKEYBOARDINPUT,
//	LBS_DISABLENOSCROLL  ,
	// WS_HSCROLL only works w/ multicolumn

	CSize szStatic(180,40);
	CSize szListbox(100,80);
	CRect rect(9999,-YSPACING,0,0);

	int i=0;
	while (i<NSTYLES)
	{
		rect.left=XSPACING;
		rect.top+=szListbox.cy+YSPACING;

		for (int j=0;j<2&&i<NSTYLES;j++)
		{
			CStatic *pStatic=new CStatic;
			m_staticList.AddTail(pStatic);
			CListBox *pListbox=new CListBox;
			m_ListboxList.AddTail(pListbox);
			rect.right=rect.left+szStatic.cx;
			rect.bottom=rect.top+szStatic.cy;
			pStatic->Create(sStyles[i],SS_RIGHT|WS_VISIBLE|WS_CHILD,rect,this);
			rect.OffsetRect(szStatic.cx+XSPACING,0);
			rect.right=rect.left+szListbox.cx;
			rect.bottom=rect.top+szListbox.cy;
			pListbox->CreateEx(WS_EX_CLIENTEDGE,_T("LISTBOX"),"", styles[i]|WS_VISIBLE|WS_CHILD, rect, this, 1000+i);
			rect.OffsetRect(szListbox.cx+XSPACING,0);

			pListbox->AddString("ListBox 1");
			pListbox->AddString("ListBox 2");
			pListbox->AddString("ListBox 3");
			pListbox->AddString("ListBox 4");
			pListbox->AddString("ListBox 5");
			pListbox->AddString("ListBox 6");
			pListbox->AddString("ListBox 7");
			pListbox->AddString("ListBox 8");

			switch (styles[i])
			{
			case LBS_USETABSTOPS:
				pListbox->ResetContent();
				pListbox->AddString("List\tBox1");
				pListbox->AddString("List\tBox2");
				pListbox->AddString("List\tBox3");
				pListbox->AddString("List\tBox4");
				pListbox->AddString("List\tBox5");
				pListbox->AddString("List\tBox6");
				break;
			case LBS_MULTICOLUMN:
				pListbox->SetColumnWidth(60);
				break;
			case WS_HSCROLL:
				pListbox->ResetContent();
				pListbox->AddString("ListBox1 ListBox1ListBox1");
				pListbox->AddString("ListBox2 ListBox2ListBox2");
				pListbox->AddString("ListBox3 ListBox3ListBox3");
				pListbox->AddString("ListBox4 ListBox4ListBox4");
				pListbox->AddString("ListBox5 ListBox5ListBox5");
				pListbox->AddString("ListBox6 ListBox6ListBox6");
				break;
			}



			i++;
		}
	}
	
	return 0;
}

void CListboxDlg::PostNcDestroy() 
{
	while (m_ListboxList.GetCount())
	{
		delete m_ListboxList.RemoveHead();
	}
	while (m_staticList.GetCount())
	{
		delete m_staticList.RemoveHead();
	}
	
	CDialog::PostNcDestroy();
}
