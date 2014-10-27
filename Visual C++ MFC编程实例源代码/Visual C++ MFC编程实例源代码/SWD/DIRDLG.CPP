// DirDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SampWzd.h"
#include "DirDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDirDialog dialog


CDirDialog::CDirDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDirDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDirDialog)
	m_sDir = _T("");
	//}}AFX_DATA_INIT
	m_sDrive=_T("");
}


void CDirDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDirDialog)
	DDX_Control(pDX, IDC_COMBO1, m_ctrlComboBox);
	DDX_Control(pDX, IDC_LIST1, m_ctrlListbox);
	DDX_Text(pDX, IDC_EDIT1, m_sDir);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDirDialog, CDialog)
	//{{AFX_MSG_MAP(CDirDialog)
	ON_CBN_CLOSEUP(IDC_COMBO1, OnCloseupCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDirDialog message handlers

BOOL CDirDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// update listbox and combobox
	char buf[128];
	strcpy(buf,m_sDir);
	DlgDirList( buf, IDC_LIST1, 0, DDL_DIRECTORY|DDL_EXCLUSIVE);
	DlgDirListComboBox( buf, IDC_COMBO1, 0, DDL_DRIVES);

	int c=m_sDir[0];
	if (__isascii(c) && m_sDir[1]==':')
	{
		m_sDrive.Format("[-%c-]",c);
		m_sDrive.MakeLower();
		m_ctrlComboBox.SetWindowText(m_sDrive);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDirDialog::OnCloseupCombo1() 
{
}

void CDirDialog::OnSelchangeCombo1() 
{
	int i;
	if ((i=m_ctrlComboBox.GetCurSel())!=CB_ERR)
	{
		// if changed, update editbox and directory
		CString str;
		m_ctrlComboBox.GetLBText(i,str);
		if (str!=m_sDrive)
		{
			m_sDrive=str;
			m_sDir.Format("%c:\\",str[2]);
			UpdateData(FALSE);

			// update listbox
			char buf[128];
			strcpy(buf,m_sDir);
			if (!DlgDirList( buf, IDC_LIST1, 0, DDL_DIRECTORY|DDL_EXCLUSIVE))
			{
				AfxMessageBox("Could not open selected device!");
				m_ctrlListbox.ResetContent();
				m_sDrive="";
			}
		}
	}
}

void CDirDialog::OnDblclkList1() 
{
	int i;
	if ((i=m_ctrlListbox.GetCurSel())!=LB_ERR)
	{
		CString str;
		m_ctrlListbox.GetText(i,str);
		str=str.Mid(1,str.GetLength()-2);
		if (str=="..")
		{
			// go down one directory
			str=m_sDir.Left(m_sDir.ReverseFind( '\\' ));
			str=str.Left(str.ReverseFind( '\\' ));
			m_sDir=str;
		}
		else
		{
			// go up one directory
			m_sDir+=str;
		}
		m_sDir+="\\";
		UpdateData(FALSE);

		char buf[128];
		strcpy(buf,m_sDir);
		DlgDirList( buf, IDC_LIST1, 0, DDL_DIRECTORY|DDL_EXCLUSIVE);
	}
}
