// WzdInfo2.cpp : implementation of the CWzdInfo class
//

#include "stdafx.h"
#include "WzdInfo2.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdInfo

IMPLEMENT_SERIAL( CWzdInfo2, CObject, 0 )


CWzdInfo2::CWzdInfo2()
{
	m_sName=_T("");
	m_sComment=_T("");
	m_nVersion=1;
	m_nState=CWzdInfo2::NEW;

	// new with version 2
	m_nModNum = 0;
}

CWzdInfo2::CWzdInfo2(CString sName,int nVersion) :
		m_sName(sName),m_nVersion(nVersion)
{
	m_sComment=_T("");
	m_nState=CWzdInfo2::OLD;

	// new with version 2
	m_nModNum = 0;
}

void CWzdInfo2::Set(CString sName,CString sComment,int nVersion, int nState)
{
	m_sName=sName;
	m_sComment=sComment;
	m_nVersion=nVersion;
	m_nState=nState;
	m_nModNum = 0;
}


void CWzdInfo2::Serialize( CArchive& ar )
{
	int version=2;
    CObject::Serialize( ar );
    if( ar.IsStoring() )
	{
		// version
		ar << version;

		// data
		ar << m_sName;
		ar << m_sComment;
		ar << m_nVersion;
		ar << m_nState;

		// new with version 2
		ar << m_nModNum;
			
	}
    else
	{
		// version
		ar >> version;

		// data
		ar >> m_sName;
		ar >> m_sComment;
		ar >> m_nVersion;
		ar >> m_nState;

		// new with version 2
		if (version>=2)
		{
			ar >> m_nModNum;
		}
	}
}


CWzdInfo2& CWzdInfo2::operator=(CWzdInfo2& src)
{
	if( this != &src)
	{
	    m_sName = src.m_sName;
	    m_sComment = src.m_sComment;
	    m_nVersion = src.m_nVersion;
	    m_nState = src.m_nState;
	}
	return *this;
}
