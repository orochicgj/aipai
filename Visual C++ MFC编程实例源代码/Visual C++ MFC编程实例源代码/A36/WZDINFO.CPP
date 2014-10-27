// WzdInfo.cpp : implementation of the CWzdInfo class
//

#include "stdafx.h"
#include "WzdInfo.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdInfo

IMPLEMENT_SERIAL( CWzdInfo, CObject, 1 )


CWzdInfo::CWzdInfo()
{
	m_sName=_T("");
	m_sComment=_T("");
	m_nVersion=1;
	m_nState=CWzdInfo::NEW;
}

CWzdInfo::CWzdInfo(CString sName,CString sComment,int nState) :
		m_sName(sName),m_sComment(sComment),m_nState(nState)
{
}

void CWzdInfo::Set(CString sName,CString sComment,int nVersion, int nState)
{
	m_sName=sName;
	m_sComment=sComment;
	m_nVersion=nVersion;
	m_nState=nState;
}

CWzdInfo& CWzdInfo::operator=(CWzdInfo& src)
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
