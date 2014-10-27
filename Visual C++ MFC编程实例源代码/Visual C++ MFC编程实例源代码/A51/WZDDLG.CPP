// WzdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdDlg.h"
#include "WzdInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog dialog


CWzdDialog::CWzdDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CWzdDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWzdDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWzdDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWzdDialog)
	DDX_Control(pDX, IDC_WZD_LIST, m_ctrlList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWzdDialog, CDialog)
	//{{AFX_MSG_MAP(CWzdDialog)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_WZD_LIST, OnColumnclickWzdList)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdDialog message handlers


BOOL CWzdDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// add columns
	m_ctrlList.InsertColumn(0,"First Names",LVCFMT_LEFT,100,0);
	m_ctrlList.InsertColumn(1,"Last Names",LVCFMT_LEFT,100,1);

	// add some data
	m_ctrlList.InsertItem(0,"Bill");
	m_ctrlList.SetItemText(0,1,"Smith");
	m_ctrlList.SetItemData(0,(DWORD)new CWzdInfo("Bill","Smith"));

	m_ctrlList.InsertItem(1,"John");
	m_ctrlList.SetItemText(1,1,"Bradberry");
	m_ctrlList.SetItemData(1,(DWORD)new CWzdInfo("John","Bradberry"));

	m_ctrlList.InsertItem(2,"Robert");
	m_ctrlList.SetItemText(2,1,"Johnson");
	m_ctrlList.SetItemData(2,(DWORD)new CWzdInfo("Robert","Johnson"));

	m_ctrlList.InsertItem(3,"Howard");
	m_ctrlList.SetItemText(3,1,"Thurmon");
	m_ctrlList.SetItemData(3,(DWORD)new CWzdInfo("Howard","Thurmon"));

	m_ctrlList.InsertItem(4,"Jill");
	m_ctrlList.SetItemText(4,1,"Curtis");
	m_ctrlList.SetItemData(4,(DWORD)new CWzdInfo("Jill","Curtis"));

	m_ctrlList.InsertItem(5,"Ted");
	m_ctrlList.SetItemText(5,1,"Thurmon");
	m_ctrlList.SetItemData(5,(DWORD)new CWzdInfo("Ted","Thurmon"));

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CWzdDialog::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// destroy all data items
	int i=0;
	while(i<m_ctrlList.GetItemCount())
	{
		delete (CWzdInfo *)m_ctrlList.GetItemData(i++);
	}
}

int CALLBACK CompareColumnItems( CWzdInfo* pItem1, CWzdInfo* pItem2, LPARAM lCol );

void CWzdDialog::OnColumnclickWzdList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_ctrlList.SortItems( (PFNLVCOMPARE)CompareColumnItems, pNMListView->iSubItem );
	*pResult = 0;
}

// NOTE: We are comparing the data item stored in each list line.
//	Return:
//		-1 if first item should come before second
//		1 if first item should come after second
//		0 if they are equivalent
int CALLBACK CompareColumnItems( CWzdInfo* pItem1, CWzdInfo* pItem2, LPARAM lCol )
{
	int nCmp = 0;
	switch( lCol )
	{
	case 0: //column 1
		nCmp = pItem1->m_sFirst.CompareNoCase( pItem2->m_sFirst );
		break;
	case 1: //column 2
		nCmp = pItem1->m_sLast.CompareNoCase( pItem2->m_sLast );
		break;
	}
	return nCmp;
}
