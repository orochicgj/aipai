#ifndef WZDINFO1_H
#define WZDINFO1_H

#include "afxtempl.h"
#include "WzdInfo2.h"

class CWzdInfo1 : public CObject
{
public:
    CWzdInfo1();
    ~CWzdInfo1();

	//misc info
	CString m_sGroupName;
	CString	m_sComment;
	CList<CWzdInfo2*,CWzdInfo2*> m_WzdInfo2List;
    void Serialize( CArchive& archive );

};
#endif
