#if !defined WZDCOMMANDLINEINFO_H
#define WZDCOMMANDLINEINFO_H

// WzdCmdFo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWzdCommandLineInfo window

class CWzdCommandLineInfo : public CCommandLineInfo
{
// Construction
public:
	CWzdCommandLineInfo();

// Attributes
public:
	BOOL m_bAFlag;
	BOOL m_bCFlag;
	BOOL m_bDAFlag;
	CString m_sArg;

// Operations
public:
	void ParseParam(const TCHAR* pszParam,BOOL bFlag,BOOL bLast);

// Overrides

// Implementation
public:
	virtual ~CWzdCommandLineInfo();

};

/////////////////////////////////////////////////////////////////////////////

#endif
