// WzdTlBar.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdTlBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define COMBOPOS 3		//position of combo box in toolbar
#define COMBOLEN 120	// length of combobox in pixels
#define COMBODROP 100	//length of drop of combo box in pixels

/////////////////////////////////////////////////////////////////////////////
// CWzdToolBar

CWzdToolBar::CWzdToolBar()
{
	m_sSelection=_T("");
}

CWzdToolBar::~CWzdToolBar()
{
}


BEGIN_MESSAGE_MAP(CWzdToolBar, CToolBar)
	//{{AFX_MSG_MAP(CWzdToolBar)
	//}}AFX_MSG_MAP
	ON_CBN_CLOSEUP(IDC_WZD_COMBO, OnCloseupCombo)
	ON_CBN_DROPDOWN(IDC_WZD_COMBO, OnDropdownCombo)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdToolBar message handlers

BOOL CWzdToolBar::LoadToolBarEx(UINT id)
{
	// load toolbar info
	BOOL bRet;
	bRet=CToolBar::LoadToolBar(id);

	// find where our combo box will go
	int pos=CommandToIndex(IDC_WZD_COMBO);

	// covert button in toolbar into a spacer for our combo box
	SetButtonInfo(pos,IDC_WZD_COMBO,TBBS_SEPARATOR,COMBOLEN);

	// create combo box
	CRect rect;
	GetItemRect(pos,&rect);
	rect.bottom+=COMBODROP; //how far will combo drop down?
	m_ctrlWzdCombo.Create(WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST, rect, this, IDC_WZD_COMBO );

	return bRet;
}


void CWzdToolBar::OnDropdownCombo() 
{
	m_ctrlWzdCombo.ResetContent();

	m_ctrlWzdCombo.AddString("Monday");
	m_ctrlWzdCombo.AddString("Tuesday");
	m_ctrlWzdCombo.AddString("Wednesday");
 	m_ctrlWzdCombo.SelectString(-1,m_sSelection);
}

void CWzdToolBar::OnCloseupCombo() 
{
	int i;
 	if ((i=m_ctrlWzdCombo.GetCurSel())!=CB_ERR)
	{
		m_ctrlWzdCombo.GetLBText( i, m_sSelection );
	}
	else
	{
		m_ctrlWzdCombo.AddString(m_sSelection);
 		m_ctrlWzdCombo.SelectString(-1,m_sSelection);
	}
}
