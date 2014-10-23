// CMDProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <afx.h>
#include <atltime.h>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{	
	/*如果是3月，getMonth返回的是3，而不是03，其他同理。*/
	CTime currentTime = CTime::GetCurrentTime();
	CString string_date;
	CString string_year;
	CString string_month;
	CString string_day;
	int year = currentTime.GetYear();
	int month = currentTime.GetMonth();
	int day = currentTime.GetDay();
	string_year.Format(_T("%d"),year);
	string_month.Format(_T("%d"),month);
	string_day.Format(_T("%d"),day);
	string_date = string_year + string_month + string_day;
	printf("date = %S\n",string_date);
	printf("\nyear = %d\nmonth = %d\n day = %d\n",year,month,day);

	/* GB2312 */
	CString string_keyWord = _T("大码女装");
	string_keyWord.MakeReverse();

	char * test = new char[string_keyWord.GetLength() + 1];
	_tcscpy_s(test,string_keyWord.GetAllocLength()+1,string_keyWord);
	int length = string_keyWord.GetLength();
	std::cout << "length = " << string_keyWord.GetLength();
	std::cout << test << std::endl;
	char buf[100];
	for(int i = 0; i < length ; i=i+2){
		sprintf(buf+i,"%X",(*(int*)(test+i)) & 0xffff);
	}
	//sprintf(buf,"%p",*(int*)test);
	std::cout << "buf = " << buf << std::endl;


	
	getchar();
	return 0;
}

