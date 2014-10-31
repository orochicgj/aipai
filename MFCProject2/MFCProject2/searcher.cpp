#include "searcher.h"
#include <iostream>
#include <fstream>
#include <UrlMon.h>
#pragma comment(lib, "urlmon.lib")
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

typedef unsigned char BYTE;
inline BYTE toHex(const BYTE &x)
{
	return x > 9 ? x + 55 : x + 48;
}

searcher::searcher(CString &edit1, CString &cbb){
	url_spm = _T("spm=1.7274553.1997520841.1");
	url_option = _T("commend=all&ssid=s5-e&search_type=item&sourceId=tb.index");
	url_head = _T("http://s.taobao.com/search?");
	filePath = _T("dist");

	string_keyWord = edit1;
	string_id = cbb;
}

int searcher::fun_main(int page){	
	url_date = _T("initiative_id=tbindexz_") + generateUrlDate();
	url_keyWord = _T("q=") + generateUrlKeyWord(); 
	url_page = generateUrlPage(page);
	if(page != 1){
		URL = url_head + url_keyWord + _T("&") + url_spm + _T("&") + url_option+ _T("&") + url_date + _T("&") + url_page;
	}else{
		URL = url_head + url_keyWord + _T("&") + url_spm + _T("&") + url_option+ _T("&") + url_date;
	}
	//DeleteUrlCacheEntry(URL);
	HRESULT result =  URLDownloadToFile(0, URL, filePath, 0, NULL);
	if(result == S_OK){
		if(!searchLocation(filePath,string_id)){
			HWND handle = AfxGetMainWnd() -> m_hWnd;
			PostMessage(handle,MESSAGE_UPDATE_EDIT, page, 1);
			std::cout << "find it!";
			std::ofstream ffout("currentURL.txt");
			ffout << URL;
			ffout.flush();
			ffout.close();
		}else{
			if(page == 100){
				HWND handle = AfxGetMainWnd() -> m_hWnd;
				PostMessage(handle,MESSAGE_UPDATE_EDIT, page, 0);
				std::cout << "not find!";
				return 1;
			}else{
				return 1;
			}
		}
		return 0;
	}else{
		std::cout << "URLDownloadToFile error";
		return 1;
	}//*/
}

CString searcher::generateUrlDate(){
	CTime currentTime = CTime::GetCurrentTime();
	CString string_year;
	CString string_month;
	CString string_day;

	int year = currentTime.GetYear();
	int month = currentTime.GetMonth();
	int day = currentTime.GetDay();

	string_year.Format(_T("%d"),year);
	string_month.Format(_T("%02d"),month);
	string_day.Format(_T("%02d"),day);

	return(string_year + string_month + string_day);
}

CString searcher::generateUrlKeyWord(){
	//std::cout << "key word length = " << sIn.GetLength() << std::endl;
	CString sIn = string_keyWord;
	CString sOut;
	BYTE buf[4];
	for( int ix = 0; ix < sIn.GetLength(); ix++){
		memset(buf, 0, 4);
		if( isalnum((BYTE)sIn[ix])){
			buf[0] = sIn[ix];
		}
		else if( isspace((BYTE)sIn[ix])){
			buf[0] = '+';
		}
		else{
			buf[0] = '%';
			buf[1] = toHex( (BYTE)sIn[ix] >> 4 );
			buf[2] = toHex( (BYTE)sIn[ix] % 16);
		}
		sOut += (char *)buf;
	}
	return sOut;
}

CString searcher::generateUrlPage(int iPage){
	CString offset;
	CString sOut;
	offset.Format("%d",(iPage - 1)*44);
	sOut = _T("tab=all&bcoffset=1&s=") + offset;
	return sOut;
}

int searcher::searchLocation(CString &filePath, CString &ID){
	std::ifstream is(filePath);
	std::streamoff length;
	char * buffer = NULL;
	char * flag = NULL;
	if(is){
		is.seekg (0, is.end);
		length = is.tellg();
		is.seekg (0, is.beg);
		buffer = new char [length];
		is.read (buffer,length);
		is.close();
		flag = std::strstr(buffer,ID);
		if(flag != NULL){
			std::cout << std::endl << std::endl << "            find it" << std::endl;

			std::ofstream ffout("current.html");
			ffout << buffer;
			ffout.flush();
			ffout.close();

		}else{
			std::cout << "not find in this page" << std::endl;
			is.close();
			delete [] buffer;
			flag = NULL;
			return 1;
		}
	}else{
		std::cout << "            read File(dist) to buffer error" << std::endl;
		return 1;
	}
	is.close();
	delete [] buffer;
	flag = NULL;
	return 0;
}

