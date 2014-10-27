// WzdRSet.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdRSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdRecordset

IMPLEMENT_DYNAMIC(CWzdRecordset, CDaoRecordset)

CWzdRecordset::CWzdRecordset(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CWzdRecordset)
	m_CustomerID = _T("");
	m_CompanyName = _T("");
	m_ContactName = _T("");
	m_ContactTitle = _T("");
	m_Address = _T("");
	m_City = _T("");
	m_Region = _T("");
	m_PostalCode = _T("");
	m_Country = _T("");
	m_Phone = _T("");
	m_Fax = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}


CString CWzdRecordset::GetDefaultDBName()
{
	return _T("D:\\Visual C++ MFC±à³ÌÊµÀý\\A72\\fe.mdb");
}

CString CWzdRecordset::GetDefaultSQL()
{
	return _T("[Customers]");
}

void CWzdRecordset::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CWzdRecordset)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Text(pFX, _T("[CustomerID]"), m_CustomerID);
	DFX_Text(pFX, _T("[CompanyName]"), m_CompanyName);
	DFX_Text(pFX, _T("[ContactName]"), m_ContactName);
	DFX_Text(pFX, _T("[ContactTitle]"), m_ContactTitle);
	DFX_Text(pFX, _T("[Address]"), m_Address);
	DFX_Text(pFX, _T("[City]"), m_City);
	DFX_Text(pFX, _T("[Region]"), m_Region);
	DFX_Text(pFX, _T("[PostalCode]"), m_PostalCode);
	DFX_Text(pFX, _T("[Country]"), m_Country);
	DFX_Text(pFX, _T("[Phone]"), m_Phone);
	DFX_Text(pFX, _T("[Fax]"), m_Fax);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CWzdRecordset diagnostics

#ifdef _DEBUG
void CWzdRecordset::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CWzdRecordset::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
