#if !defined(AFX_WZDRECORDSET_H__1BAF29CC_E67E_11D1_9B84_00AA003D8695__INCLUDED_)
#define AFX_WZDRECORDSET_H__1BAF29CC_E67E_11D1_9B84_00AA003D8695__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WzdRSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdRecordset DAO recordset

class CWzdRecordset : public CDaoRecordset
{
public:
	CWzdRecordset(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CWzdRecordset)

// Field/Param Data
	//{{AFX_FIELD(CWzdRecordset, CDaoRecordset)
	CString	m_CustomerID;
	CString	m_CompanyName;
	CString	m_ContactName;
	CString	m_ContactTitle;
	CString	m_Address;
	CString	m_City;
	CString	m_Region;
	CString	m_PostalCode;
	CString	m_Country;
	CString	m_Phone;
	CString	m_Fax;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdRecordset)
	public:
	virtual CString GetDefaultDBName();		// Default database name
	virtual CString GetDefaultSQL();		// Default SQL for Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDRECORDSET_H__1BAF29CC_E67E_11D1_9B84_00AA003D8695__INCLUDED_)
