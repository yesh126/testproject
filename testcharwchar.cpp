// testcharwchar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void TestChar()
{
	char ch1 = 's';             // 正确
	cout << "ch1:" << ch1 << endl;
	char ch2 = '中';             // 错误,一个char不能完整存放一个汉字信息
	cout << "ch2:" << ch2 << endl;

	char str[4] = "中";          //前三个字节存放汉字'中',最后一个字节存放字符串结束符\0
	cout << "str:" << str << endl;
	//char str2[2] = "国";       // 错误：'str2' : array bounds overflow
	//cout << str2 << endl;
}


void TestWchar_t()
{
	try
	{ 
	wcout.imbue(locale("chs"));     // 将wcout的本地化语言设置为中文

	wchar_t wch1 = L's';            // 正确
	wcout << "wch1:" << wch1 << endl;
	wchar_t wch2 = L'中';            // 正确,一个汉字用一个wchar_t表示
	wcout << "wch2:" << wch2 << endl;

	wchar_t wstr[2] = L"中";         // 前两个字节(前一个wchar_t)存放汉字'中',最后两个字节(后一个wchar_t)存放字符串结束符\0
	wcout << "wstr:" << wstr << endl;
	wchar_t wstr2[3] = L"中国";
	wcout << "wstr2:" << wstr2 << endl;
	}
	catch (...)
	{
		wcout << "exception";
	}
}

void TestWchar_t_2()
{
	try
	{
		cout.imbue(locale("chs"));     // 将wcout的本地化语言设置为中文

		wchar_t wch1 = L's';            // 正确
		cout << "wch1:" << wch1 << endl;
		wchar_t wch2 = L'中';            // 正确,一个汉字用一个wchar_t表示
		cout << "wch2:" << wch2 << endl;

		wchar_t wstr[2] = L"中";         // 前两个字节(前一个wchar_t)存放汉字'中',最后两个字节(后一个wchar_t)存放字符串结束符\0
		cout << "wstr:" << wstr << endl;
		wchar_t wstr2[3] = L"中国";
		cout << "wstr2:" << wstr2 << endl;
	}
	catch (...)
	{
		wcout << "exception";
	}
}

int main()
{
	//TestChar();

	//TestWchar_t_2();


#define LEN  800 * 4567 //3653600
	try
	{
		char * buffer = new char[LEN];
		memset(buffer, 'a', LEN);
		size_t  size = strlen(buffer);
		std::cout << size << std::endl;

		char* buf = new char[1];
		sprintf(buf, "hello");

		//std::ostringstream ss("");
		//ss << buffer;
		//std::cout << ss.str();


		std::stringstream sstr;
		sstr << fixed << std::setprecision(4) << 123.456;
		sstr << setw(8) << setfill('0') << 123;
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what();
	}
	std::cin.get();


    return 0;
}

