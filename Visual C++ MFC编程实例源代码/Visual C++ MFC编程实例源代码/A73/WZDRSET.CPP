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
// CWzdRecordSet

IMPLEMENT_DYNAMIC(CWzdRecordSet, CRecordset)

CWzdRecordSet::CWzdRecordSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CWzdRecordSet)
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
	m_nDefaultType = snapshot;
}


CString CWzdRecordSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=MS Access 97 Database");
}

CString CWzdRecordSet::GetDefaultSQL()
{
	return _T("[Customers]");
}

void CWzdRecordSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CWzdRecordSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[CustomerID]"), m_CustomerID);
	RFX_Text(pFX, _T("[CompanyName]"), m_CompanyName);
	RFX_Text(pFX, _T("[ContactName]"), m_ContactName);
	RFX_Text(pFX, _T("[ContactTitle]"), m_ContactTitle);
	RFX_Text(pFX, _T("[Address]"), m_Address);
	RFX_Text(pFX, _T("[City]"), m_City);
	RFX_Text(pFX, _T("[Region]"), m_Region);
	RFX_Text(pFX, _T("[PostalCode]"), m_PostalCode);
	RFX_Text(pFX, _T("[Country]"), m_Country);
	RFX_Text(pFX, _T("[Phone]"), m_Phone);
	RFX_Text(pFX, _T("[Fax]"), m_Fax);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CWzdRecordSet diagnostics

#ifdef _DEBUG
void CWzdRecordSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CWzdRecordSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
