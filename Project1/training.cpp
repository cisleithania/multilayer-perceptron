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

void training(char *ddd1)
{
	//����� ������ ��������� � ������
	//� ��� ���� �������� ����
	//������� �������� ��������, ����������, ��������

	//������, ���� ������������ ������ ��� �����, ������� ����� �������. �� ���� ������ ���� ���������, � � ���� ������ ������ ������ ����
	//������������ ����� �������� �����


	//**********************���� � ������ � ������������ ����������********************
	WIN32_FIND_DATAW wfd;
	int iter = 0;
	int j = 0;
	wstring m[100];  //������ ��� �������� �������� ������

	//HANDLE const hFind = FindFirstFileW(L"D:\\C++\\training\\*", &wfd);
	HANDLE const hFind = FindFirstFileW(L"D:/C++/train/files_for_training/*", &wfd);
	setlocale(LC_ALL, "");

	if (INVALID_HANDLE_VALUE != hFind)
	{
		do
		{
			std::wcout << &wfd.cFileName[0] << std::endl;
			iter++;
			m[j] = &wfd.cFileName[0];
			j++;
		} while (NULL != FindNextFileW(hFind, &wfd));

		FindClose(hFind);
	}

	cout << "���������� ������ � �����: " << iter - 2 << endl; //���������� ������ � ����� (-2 - ������ ���, �� ��������� ��������� ����� �� ��� ������)

	for (int q = 0; q < 100; q++) {
		std::wcout << "q= " << m[q] << std::endl;
	}
	//**********************���� � ������ � ������������ ����������******************



	for (int q = 0; q < 1; q++) {

		// 0 - .; 1 - ..; 2 - ������ ����; 3 - ������ ���� � �.�.
		wstring abc = m[q + 2];   wcout << "asc= " << abc << endl; //������ ���� ������������ ���� ��� �������� 

																   //**************** wstring --> string **********************
		string s(abc.begin(), abc.end());
		s.assign(abc.begin(), abc.end());
		cout << "s= " << s << endl;
		//**********************************************************

		const char * c = s.c_str(); //string --> char

									//**************** ����������� ���� ����� - char �� ************
									//char ddd[] = "D:/C++/training/";
		strcat(ddd1, c);
		cout << "ddd1= " << ddd1 << endl;
		cout << "��� ����������� ������ ��������� ������� ����� �������..." << endl;
		cin.get();
		//************************
		// ������ strcat ����� �������� strcat_s, �� ����� ������ ������ ��������� � L"D:\\C++\\training\\*"(77 ������), ������ L �� ��������

		//��� ����� ����� �������� - �� ��������

		//const char c[] = "D:/C++/training/one.data"; //���� �� ����� 

		//f1(ddd); //����� �������
	}
}