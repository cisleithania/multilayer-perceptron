#pragma once
#include "stdafx.h"
#include "fann.h"
#include "floatfann.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "f2.h"
using namespace std;

void preparing_files_for_testing()
{
	WIN32_FIND_DATAW wfd;
	int iter = 0;
	int j = 0;
	wstring ggg[1000];  //������ ��� �������� �������� ������ (������� ������ w_)

	HANDLE const hFind = FindFirstFileW(L"D:/C++/train/files_for_testing/*", &wfd); //����������, ��� ������ �����
	//HANDLE const hFind = FindFirstFileW(L"files_for_testing\\*", &wfd); //����������, ��� ������ �����

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

	cout << "��� ����������� ������ ��������� ������� ����� �������..." << endl;
	cin.get();

	for (int t = 0; t < iter; t++) {   //(int t = 0; t < 100; t++)
		std::wcout << ggg[t] << std::endl; //����� �� ����� �������� ������
	}

	for (int q = 0; q < o; q++)
	{

		cout << "�� ���������� � ����� q = " << q << endl;
		cin.get();

		// 0 - .; 1 - ..; 2 - ������ ����; 3 - ������ ���� � �.�.
		wstring abc = ggg[q + 2];   wcout << abc << endl; //������ ���� ������������ ���� ��� �������� 

														  //**************** wstring --> string ****************************
		string s(abc.begin(), abc.end());
		s.assign(abc.begin(), abc.end());
		cout << s << endl;
		//***************************************************************

		const char * c = s.c_str(); //string --> char

									//**************** ����������� ���� ����� - char �� *************
		//char ddm[70] = "D:/C++/train/files_for_testing/";
		char ddm[70] = "D:/C++/train/files_for_testing/";
		strcat(ddm, c);
		cout << "ddm = " << ddm << endl;
		//**************************************************************
		f2(ddm);
		cin.get();
	}
}