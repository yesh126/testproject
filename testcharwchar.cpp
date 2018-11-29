// testcharwchar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void TestChar()
{
	char ch1 = 's';             // ��ȷ
	cout << "ch1:" << ch1 << endl;
	char ch2 = '��';             // ����,һ��char�����������һ��������Ϣ
	cout << "ch2:" << ch2 << endl;

	char str[4] = "��";          //ǰ�����ֽڴ�ź���'��',���һ���ֽڴ���ַ���������\0
	cout << "str:" << str << endl;
	//char str2[2] = "��";       // ����'str2' : array bounds overflow
	//cout << str2 << endl;
}


void TestWchar_t()
{
	try
	{ 
	wcout.imbue(locale("chs"));     // ��wcout�ı��ػ���������Ϊ����

	wchar_t wch1 = L's';            // ��ȷ
	wcout << "wch1:" << wch1 << endl;
	wchar_t wch2 = L'��';            // ��ȷ,һ��������һ��wchar_t��ʾ
	wcout << "wch2:" << wch2 << endl;

	wchar_t wstr[2] = L"��";         // ǰ�����ֽ�(ǰһ��wchar_t)��ź���'��',��������ֽ�(��һ��wchar_t)����ַ���������\0
	wcout << "wstr:" << wstr << endl;
	wchar_t wstr2[3] = L"�й�";
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
		cout.imbue(locale("chs"));     // ��wcout�ı��ػ���������Ϊ����

		wchar_t wch1 = L's';            // ��ȷ
		cout << "wch1:" << wch1 << endl;
		wchar_t wch2 = L'��';            // ��ȷ,һ��������һ��wchar_t��ʾ
		cout << "wch2:" << wch2 << endl;

		wchar_t wstr[2] = L"��";         // ǰ�����ֽ�(ǰһ��wchar_t)��ź���'��',��������ֽ�(��һ��wchar_t)����ַ���������\0
		cout << "wstr:" << wstr << endl;
		wchar_t wstr2[3] = L"�й�";
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

