// searchkeyword.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <UrlMon.h>
#pragma comment(lib, "urlmon.lib")
using namespace std;

int readKeyWord(const char *filename,const char * key);

int main(int argc, char* argv[])
{
	string url;
	string key;
	string url_;
	url_ = argv[1];
	url = argv[1];
	key = argv[2];
    //strcpy((char *)url.c_str(),argv[1]);
	string str = "&tab=all&bcoffset=4&s=";
	int offset = 0;
	char buf[10];
	ofstream outFile;

	char * hanzi = "����";
	printf("da = %p",*(int*)hanzi);
	char b[100];
	sprintf(b,"%p",*(int*)hanzi);
	printf("dama = %s",b);

	//strcpy(str2,argv[2]);
	//strcpy(str3,argv[3]);
	//_TCHAR *url1 = argv[1];
	//_TCHAR *url2 = argv[2];
	//_TCHAR *key = argv[3];
	/*����ĳ�ʼ���ұ�һ��Ҫ��һ����ʵ��ֵ������char a[] = "hello"��������һ������������char a[] = argv[1],����ָ��ĳ�ʼ���ұ߿�����һ������*/
	for(int i = 0; i < 100; i++){
		if(i%10 == 0)
			printf("���ڲ��� %d ������\n",i);
		offset = i * 44;
		sprintf(buf, "%d", offset);
		//printf("offset = %s\n",buf);
		url = url_;
		url += str;
		url += buf;
		//printf("url = %s\n\n\n",url.c_str());
		bool result = URLDownloadToFile(0,url.c_str(), _T("dist") ,0,NULL);
		int value = readKeyWord("dist",key.c_str());
		if(value == 1){
			printf("�ڼ�ҳ = %d",i+1);
			outFile.open("currentURL.txt",std::ofstream::out | std::ofstream::trunc);
			outFile << url.c_str();
			outFile.flush();
			outFile.close();
			break;
		}
		if(i == 99 && value == 0){
			printf("û���ҵ�\n");
		}
	}
	getchar();
	return 0;
}

int readKeyWord(const char *filename,const char *key){
	ifstream is(filename);
	if(is){
		is.seekg (0, is.end);
		int length = is.tellg();
		is.seekg (0, is.beg);

		char * buffer = new char [length];
		is.read (buffer,length);

		is.close();

		char * ptr = NULL;
		ptr = strstr(buffer,key);
		if (ptr){
			printf("�Ƿ��ҵ� = yes\n");
			ofstream fout("currentHTML.txt");
			fout << buffer;
			fout.flush();
			fout.close();
			return 1;
		}
		else
			;

		delete[] buffer;
	}
	return 0;
}
