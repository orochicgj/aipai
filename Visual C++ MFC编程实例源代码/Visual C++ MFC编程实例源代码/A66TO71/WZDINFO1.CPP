// WzdInfo1.cpp : implementation of the CWzdInfo class
//

#include "stdafx.h"
#include "WzdInfo1.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdInfo
template <> void AFXAPI SerializeElements <CWzdInfo2> ( CArchive& ar, CWzdInfo2* pNewPersons, int nCount )
{
    for ( int i = 0; i < nCount; i++, pNewPersons++ )
    {
        // Serialize each CPerson object
        pNewPersons->Serialize( ar );
    }
}
CWzdInfo1::CWzdInfo1()
{
	m_sGroupName=_T("");
	m_sComment=_T("");
}

CWzdInfo1::~CWzdInfo1()
{
	while (!m_WzdInfo2List.IsEmpty())
	{
		delete m_WzdInfo2List.RemoveHead();
	}
}


void CWzdInfo1::Serialize( CArchive& ar )
{
	int version=1;
    CObject::Serialize( ar );
	int nCount;
	if (ar.IsStoring())
	{
		// version
		ar << version;

		// name and comment
		ar << m_sGroupName;
		ar << m_sComment;

		// other list
		m_WzdInfo2List.Serialize(ar);
#if 0
		nCount = m_WzdInfo2List.GetCount();
		ar << nCount;
		for (POSITION pos = m_WzdInfo2List.GetHeadPosition(); pos; )
		{
			CWzdInfo2 *pInfo = m_WzdInfo2List.GetNext(pos);
			ar << pInfo;
		}
#endif
	}
	else
	{
		// version
		ar >> version;

		// name and comment
		ar >> m_sGroupName;
		ar >> m_sComment;

		// other list
		m_WzdInfo2List.Serialize(ar);
		ar >> nCount;
		CObject *pInfo;
		while (nCount-- > 0)
		{
			ar >> pInfo;
			m_WzdInfo2List.AddTail((CWzdInfo2*)pInfo);
		}
	}
}
