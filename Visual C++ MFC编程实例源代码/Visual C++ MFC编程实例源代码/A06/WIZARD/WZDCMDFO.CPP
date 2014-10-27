// WzdCmdFo.cpp : implementation file
//

#include "stdafx.h"
#include "wzd.h"
#include "WzdCmdFo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdCommandLineInfo

CWzdCommandLineInfo::CWzdCommandLineInfo()
{
	m_bAFlag = FALSE;
	m_bCFlag = FALSE;
	m_bDAFlag = FALSE;
	m_sArg=_T("");
}

CWzdCommandLineInfo::~CWzdCommandLineInfo()
{
}

/////////////////////////////////////////////////////////////////////////////

void CWzdCommandLineInfo::ParseParam(const TCHAR* pszParam,BOOL bFlag,BOOL bLast)
{
	CString sArg(pszParam);
	if (bFlag)
	{
		m_bAFlag = !sArg.CompareNoCase("a");
		m_bCFlag = !sArg.CompareNoCase("c");
		m_bDAFlag = !sArg.CompareNoCase("da");
	}
	// m_strFileName gets the first nonflag name
	else if (m_strFileName.IsEmpty())
	{
		m_sArg=sArg;
	}

	CCommandLineInfo::ParseParam(pszParam,bFlag,bLast);
}
