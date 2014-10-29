#ifndef __SEARCHER_H__
#include "stdafx.h"

class searcher{
private:
	CString URL;
	CString url_date;
	CString url_spm ;
	CString url_keyWord ;
	CString url_option;
	CString url_head;
	CString url_page;

	CString filePath;
	CString string_keyWord;
	CString string_id;
	CString showPage;
public:
	searcher(CString &edit1, CString &cbb);

	int fun_main(int page);
	CString generateUrlDate();
	CString generateUrlKeyWord();
	CString generateUrlPage(int iPage);
	int searchLocation(CString &filePath, CString &keyWord);
};
#endif