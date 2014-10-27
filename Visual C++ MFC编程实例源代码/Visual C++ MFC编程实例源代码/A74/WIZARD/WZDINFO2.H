#ifndef WZDINFO2_H
#define WZDINFO2_H


class CWzdInfo2 : public CObject
{
public:

enum STATES {
	OLD,
	NEW,
	MODIFIED,
	DELETED
};

    DECLARE_SERIAL( CWzdInfo2 )

    CWzdInfo2();
    CWzdInfo2(CString sName,int nVersion);

	void Set(CString sName,CString sComment,int nVersion, int nState);

	//misc info
	CString m_sName;
	CString	m_sComment;
	int m_nVersion;
	int m_nState;

	// new with version 2
	int m_nModNum;

    void Serialize( CArchive& archive );

	CWzdInfo2& operator=(CWzdInfo2& src);

};
#endif
