
// MFCProject2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCProject2App:
// �йش����ʵ�֣������ MFCProject2.cpp
//

class CMFCProject2App : public CWinApp
{
public:
	CMFCProject2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCProject2App theApp;