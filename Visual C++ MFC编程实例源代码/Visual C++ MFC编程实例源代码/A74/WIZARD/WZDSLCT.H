#ifndef WZDSELECT_H
#define WZDSELECT_H

#include "afxtempl.h"
#include "WzdInfo1.h"

class CWzdSelect : public CObject
{
public:
    DECLARE_SERIAL( CWzdSelect )

    CWzdSelect();
    ~CWzdSelect();

	void Select(CWzdInfo1 *pInfo);
	int SelectionCount();
	void CutSelections(CList<CWzdInfo1*,CWzdInfo1*> *pList);
	void CopySelections(CList<CWzdInfo1*,CWzdInfo1*> *pList=NULL);
	BOOL CanPasteClipboard();
	void PasteClipboard(CList<CWzdInfo1*,CWzdInfo1*> *pList);
    void Serialize( CArchive& archive );

private:
	int m_clipboardFormat;
	CWzdInfo1 *m_pActiveSelection;
	CList<CWzdInfo1*,CWzdInfo1*> m_WzdSelectionList;

};
#endif
