// WzdSlct.cpp : implementation of the CWzdSelect class
//

#include "stdafx.h"
#include <afxadv.h>
#include <afxole.h>
#include "WzdSlct.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdSelect

IMPLEMENT_SERIAL( CWzdSelect, CObject, 1 )

CWzdSelect::CWzdSelect()
{
	m_pActiveSelection=NULL;
	m_clipboardFormat = ::RegisterClipboardFormat("CWzdInfo1");
}

CWzdSelect::~CWzdSelect()
{
}
////////////////////////////////////////////////////////////////////
//CWzdSelect Methods

void CWzdSelect::Serialize( CArchive& ar )
{
	int nCount;
    CObject::Serialize( ar );
    if( ar.IsStoring() )
	{
		nCount = m_WzdSelectionList.GetCount();
		ar << nCount;
		for (POSITION pos = m_WzdSelectionList.GetHeadPosition(); pos; )
		{
			m_WzdSelectionList.GetNext(pos)->Serialize(ar);
		}
	}
    else
	{
		ar >> nCount;
		while (nCount-- > 0)
		{
			CWzdInfo1* pInfo = new CWzdInfo1;
			pInfo->Serialize(ar);
			m_WzdSelectionList.AddTail(pInfo);
		}
	}
}

void CWzdSelect::Select(CWzdInfo1 *pInfo)
{
	m_pActiveSelection=pInfo;
	if (!m_WzdSelectionList.Find(pInfo))
	{
		m_WzdSelectionList.AddTail(pInfo);
	}
}

int CWzdSelect::SelectionCount()
{
	return m_WzdSelectionList.GetCount();
}

void CWzdSelect::CutSelections(CList<CWzdInfo1*,CWzdInfo1*> *pList)
{
	CopySelections(pList);
}

void CWzdSelect::CopySelections(CList<CWzdInfo1*,CWzdInfo1*> *pList /*=NULL*/)
{
	if (m_WzdSelectionList.GetCount() <= 0) return;

	// create an archive to a memory file and selection list to it
	CSharedFile file;
	CArchive ar(&file, CArchive::store);
	Serialize(ar);

	// close archive and put it in clipboard
	ar.Close();
	COleDataSource *pDS = new COleDataSource();
	pDS->CacheGlobalData(m_clipboardFormat, file.Detach());
	pDS->SetClipboard();

	// if cutting, delete items in selection list from document
	if (pList)
	{
		for (POSITION pos=m_WzdSelectionList.GetHeadPosition();pos; )
		{
			CWzdInfo1 *pInfo=m_WzdSelectionList.GetNext(pos);

			POSITION posx;
			if (posx=pList->Find(pInfo))
			{
				pList->RemoveAt(posx);
			}
			delete pInfo;
		}
	}

	// kill selections
	m_WzdSelectionList.RemoveAll();
	m_pActiveSelection=NULL;
}

BOOL CWzdSelect::CanPasteClipboard()
{
	COleDataObject object;
	return (object.AttachClipboard() && object.IsDataAvailable(m_clipboardFormat));
}

void CWzdSelect::PasteClipboard(CList<CWzdInfo1*,CWzdInfo1*> *pList)
{
	// reset selections
	m_WzdSelectionList.RemoveAll();
	m_pActiveSelection=NULL;

	// open archive to clipboard and serialize into selection list
	COleDataObject object;
	object.AttachClipboard();
	CFile* pFile = object.GetFileData(m_clipboardFormat);
	if (!pFile) return;
	CArchive ar(pFile, CArchive::load);
	Serialize(ar);
	ar.Close();
	delete pFile; //deletes file

	// add selection back into document
	for (POSITION pos=m_WzdSelectionList.GetHeadPosition();pos; )
	{
		m_pActiveSelection=m_WzdSelectionList.GetNext(pos);
		pList->AddTail(m_pActiveSelection);
	}
}



