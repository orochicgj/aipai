#ifndef WZDINFO_H
#define WZDINFO_H


class CWzdInfo : public CObject
{
public:

enum STATES {
	OLD,
	NEW,
	MODIFIED,
	DELETED
};

    DECLARE_SERIAL( CWzdInfo )

    CWzdInfo();
    CWzdInfo(CString sName,CString sComment,int nState);

	void Set(CString sName,CString sComment,int nVersion, int nState);

	//misc info
	CString m_sName;
	CString	m_sComment;
	int m_nVersion;
	int m_nState;

	CWzdInfo& operator=(CWzdInfo& src);

};
#endif
