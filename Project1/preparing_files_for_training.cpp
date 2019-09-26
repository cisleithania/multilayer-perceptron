#include "stdafx.h"
#include "fann.h"
#include "floatfann.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "f0.h"
#include "f1.h" 
#include "f2.h"
#include "f3.h"
#include "f4.h"
using namespace std;

void preparing_files_for_training()
{
	f0();
	//ofstream out("D:/C++/training/nn.data");

	WIN32_FIND_DATAW wfd;
	int iter = 0;
	int j = 0;
	wstring ggg[1000];  //������ ��� �������� �������� ������ (������� ������ w_)

	//HANDLE const hFind = FindFirstFileW(L"D:\\C++\\train\\files_for_training\\*", &wfd); //����������, ��� ������ �����
	HANDLE const hFind = FindFirstFileW(L"D:/C++/train/files_for_training/*", &wfd); //����������, ��� ������ �����

	if (INVALID_HANDLE_VALUE != hFind)
	{
		do
		{
			std::wcout << &wfd.cFileName[0] << std::endl;
			iter++;
			ggg[j] = &wfd.cFileName[0];
			j++;
		} while (NULL != FindNextFileW(hFind, &wfd));

		FindClose(hFind);
	}

	int o = iter - 2; //���������� ������ � ����� (-2 - ������ ���, �� ��������� ��������� ����� �� ��� ������)
	cout << "���������� ������ � �����: " << o << endl;

	//cout << "��� ����������� ������ ��������� ������� ����� �������..." << endl;
	//cin.get();

	for (int t = 0; t < iter; t++) {   //(int t = 0; t < 100; t++)
		std::wcout << ggg[t] << std::endl; //����� �� ����� �������� ������
	}

	for (int q = 0; q < o; q++)
	{

		cout << "�� ���������� � ����� q = " << q << endl;
		//cin.get();

		// 0 - .; 1 - ..; 2 - ������ ����; 3 - ������ ���� � �.�.
		wstring abc = ggg[q + 2];   wcout << abc << endl; //������ ���� ������������ ���� ��� �������� 

														  //**************** wstring --> string ****************************
		string s(abc.begin(), abc.end());
		s.assign(abc.begin(), abc.end());
		cout << s << endl;
		//***************************************************************

		const char * c = s.c_str(); //string --> char

		cout << "change string s: " << s[24] << endl;
		char s1 = s[24];
		cout << "s1 = : " << s1 << endl;
		int change = s1;
		cout << "change = : " << s1 << endl;   //� ascii ���� ���������� �� 48. 
		int change1 = change - 48;
		cout << "change1 = : " << change1 << endl;

		cout << "change string s: " << s[25] << endl;
		char s2 = s[25];
		cout << "s1 = : " << s2 << endl;
		int change0 = s2;
		cout << "change = : " << s2 << endl;   //� ascii ���� ���������� �� 48. 
		int change2 = change0 - 48;
		cout << "change1 = : " << change2 << endl;

		//**************** ����������� ���� ����� - char �� *************
		//char ddm[70] = "D:/C++/train/files_for_training/";
		char ddm[70] = "D:/C++/train/files_for_training/";
		strcat(ddm, c);
		cout << "ddm = " << ddm << endl;
		//**************************************************************

		if ((change1 == 1) || (change2 == 1)) {
			f1(ddm);
		}

		if ((change1 == 2) || (change2 == 2)) {
			f2(ddm);
		}

		f3(ddm, o);
	}

	//char ddf[] = "D:/C++/training/nn.data";
	char ddf[] = "training/nn.data";
	f4(ddf, o);
}