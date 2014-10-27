// WzdBtmap.cpp : implementation of the CWzdBitmap class
//

#include "stdafx.h"
#include "WzdBtmap.h"
#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdBitmap

IMPLEMENT_DYNAMIC(CWzdBitmap, CBitmap)


CWzdBitmap::CWzdBitmap()
{
	m_Width=0;
	m_Height=0;
}

CWzdBitmap::~CWzdBitmap()
{
}

void CWzdBitmap::CreateBitmapEx(CSize size)
{
	CDC dcMem;
	CDC dcScreen;
	dcScreen.Attach(::GetDC(NULL));

	// create our bitmap in memory
	dcMem.CreateCompatibleDC(&dcScreen);
	CreateCompatibleBitmap(&dcScreen, size.cx, size.cy);
	dcMem.SelectObject(this);

	// do our drawing
	CBrush bluebrush,greenbrush;
	bluebrush.CreateSolidBrush(RGB(0,0,255));
	greenbrush.CreateSolidBrush(RGB(0,255,0));
	dcMem.FillRect(CRect(0,0,size.cx,size.cy), &bluebrush);
	dcMem.SelectObject(&greenbrush);
	dcMem.Ellipse(0,0, size.cx, size.cy);
	HICON hicon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	dcMem.DrawIcon((size.cx-32)/2,(size.cy-32)/2,hicon);

	// delete and release device contexts
	dcMem.DeleteDC();
	::ReleaseDC(NULL, dcScreen.Detach());

	m_Width=size.cx;
	m_Height=size.cy;

}
