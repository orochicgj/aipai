#include "stdafx.h"
#include <afx.h>
#include <atltime.h>
#include <iostream>
#include <fstream>
#include <UrlMon.h>
#pragma comment(lib, "urlmon.lib")

typedef unsigned char BYTE;
inline BYTE toHex(const BYTE &x)
{
	return x > 9 ? x + 55 : x + 48;
}

CStringArray valid_user;

CString generateUrlDate();
CString generateUrlKeyWord(CString &sIn);
CString generateUrlPage(int iPage);
int searchLocation(CString &filePath, CString &keyWord);
int checkUser(CString string_id);

int _tmain(int argc, _TCHAR* argv[])
{	
	/* add valid user */
	valid_user.Add(_T("mr_timon"));
	valid_user.Add(_T("mr_pumbaa"));
	valid_user.Add(_T("star_patrick"));
	valid_user.Add(_T("�������ҵ�Ŷ"));
	valid_user.Add(_T("457800643xc"));
	valid_user.Add(_T("lingzhiji�����콢��"));
	valid_user.Add(_T("�غ���"));
	//valid_user.Add(_T("star"));
	//valid_user.Add(_T("lele"));

	if(checkUser(argv[2])){
		std::cout << std::endl << std::endl << "       you are not a valid user!          " << std::endl << std::endl << std::endl;
		return 0;
	}

	CString URL;
	CString url_date;
	CString url_spm = _T("spm=1.7274553.1997520841.1");
	CString url_keyWord ;
	CString url_option = _T("commend=all&ssid=s5-e&search_type=item&sourceId=tb.index");
	CString url_head = _T("http://s.taobao.com/search?");
	CString url_page;

	CString filePath = _T("dist");
	//CString string_keyWord = _T("��ͯ��������ñ��");
	//CString string_id = _T("mr_timon");
	CString string_keyWord = argv[1];
	CString string_id = argv[2];


	url_date = _T("initiative_id=tbindexz_") + generateUrlDate();
	url_keyWord = _T("q=") + generateUrlKeyWord(string_keyWord);

	for(int i = 1; i <= 100; i++){
		url_page = generateUrlPage(i);
		if((i - 1)%10 == 0){
			std::cout << "     searching";
			for(int j = 0; j < i/10; j++){
				std::cout << ".";
			}
			std::cout << std::endl;
		}
		if(i != 1){
			URL = url_head + url_keyWord + _T("&") + url_spm + _T("&") + url_option+ _T("&") + url_date + _T("&") + url_page;
		}else{
			URL = url_head + url_keyWord + _T("&") + url_spm + _T("&") + url_option+ _T("&") + url_date;
		}

		/*   ��������Դ���ӵĻ������԰Ѷ�Ӧ����Դ��������   */
		//URL = _T("http://www.jojomamanbebe.co.uk/products/images/large/B2755C.jpg");
		
		HRESULT result =  URLDownloadToFile(0, URL, filePath, 0, NULL);
		if(result == S_OK){
			//std::cout << "down\n";
			if(!searchLocation(filePath,string_id)){
				std::cout << "            page = " << i << std::endl << std::endl << std::endl;
				break;
			}else{
				if(i == 100)
					std::cout << std::endl << std::endl << "*************  sorry,we don't have found it  *************" << std::endl << std::endl << std::endl ;
			}
		}else{
			std::cout << "URLDownloadToFile failed\n";
			return 1;
		}
	}

	//std::cout << "real_url = " << URL << std::endl;

	std::ofstream fout("currentURL.txt");
	fout << URL;
	fout.flush();
	fout.close();
	
	//getchar();
	return 0;
}

CString generateUrlDate(){
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

CString generateUrlKeyWord(CString &sIn){
	//std::cout << "key word length = " << sIn.GetLength() << std::endl;
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

CString generateUrlPage(int iPage){
	CString offset;
	CString sOut;
	offset.Format("%d",(iPage - 1)*44);
	sOut = _T("tab=all&bcoffset=1&s=") + offset;
	return sOut;
}

int searchLocation(CString &filePath, CString &ID){
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
			//std::cout << "not find in this page" << std::endl;
			flag = NULL;
			return 1;
		}
	}else{
		std::cout << "            read File(dist) to buffer error" << std::endl;
		return 1;
	}
	delete [] buffer;
	flag = NULL;
	return 0;
}

int checkUser(CString string_id){
	int count = valid_user.GetCount();
	//std::cout << " i ============= " << count << std::endl;
	for(int i = 0; i < count; i++){
		if(string_id == valid_user.GetAt(i))
			return 0;
		else 
			continue;
	}
	return 1;
}


/*
std::string urlEncoding( std::string &sIn )
{
	cout << "size: " << sIn.size() << endl;
	string sOut;
	for( int ix = 0; ix < sIn.size(); ix++ )
	{
		BYTE buf[4];
		memset( buf, 0, 4 );
		if( isalnum( (BYTE)sIn[ix] ) )//�ж��Ƿ������ֻ���ĸ���Ǿͷ��ط��㡣��ͷ���0
		{
			buf[0] = sIn[ix];
		}
		else if ( isspace( (BYTE)sIn[ix] ) )
		{
			buf[0] = '+';
		}
		else
		{
			buf[0] = '%';
			buf[1] = toHex( (BYTE)sIn[ix] >> 4 );
			buf[2] = toHex( (BYTE)sIn[ix] % 16);
		}
		sOut += (char *)buf;
	}
	return sOut;
}//*/