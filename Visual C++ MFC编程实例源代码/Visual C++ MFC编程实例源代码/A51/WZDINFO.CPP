// WzdInfo.cpp : implementation of the CWzdInfo class
//

#include "stdafx.h"
#include "WzdInfo.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdInfo

IMPLEMENT_SERIAL( CWzdInfo, CObject, 1 )


CWzdInfo::CWzdInfo()
{
	m_sFirst=_T("");
	m_sLast=_T("");
}

CWzdInfo::CWzdInfo(CString sFirst,CString sLast) :
		m_sFirst(sFirst),m_sLast(sLast)
{
}

CWzdInfo& CWzdInfo::operator=(CWzdInfo& src)
{
	if( this != &src)
	{
	    m_sFirst = src.m_sFirst;
	    m_sLast = src.m_sLast;
	}
	return *this;
}
