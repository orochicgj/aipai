#ifndef WZDINFO_H
#define WZDINFO_H


class CWzdInfo : public CObject
{
public:
    DECLARE_SERIAL( CWzdInfo )

    CWzdInfo();
    CWzdInfo(CString sFirst,CString sLast);

	//misc info
	CString m_sFirst;
	CString	m_sLast;

	CWzdInfo& operator=(CWzdInfo& src);

};
#endif
