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
	//имена файлов заносятся в массив
	//и для него делается цикл
	//который включает открытие, считывание, закрытие

	//массив, куда записывается только имя файла, которое нужно открыть. На этот массив надо ссылаться, и в этот массив должен каждый цикл
	//записываться новое название файла


	//**********************путь к файлам в определенной директории********************
	WIN32_FIND_DATAW wfd;
	int iter = 0;
	int j = 0;
	wstring m[100];  //массив где хранятся названия файлов

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

	cout << "Количество файлов в папке: " << iter - 2 << endl; //количество файлов в папке (-2 - потому что, по умолчанию выводится число на два больше)

	for (int q = 0; q < 100; q++) {
		std::wcout << "q= " << m[q] << std::endl;
	}
	//**********************путь к файлам в определенной директории******************



	for (int q = 0; q < 1; q++) {

		// 0 - .; 1 - ..; 2 - первый файл; 3 - второй файл и т.д.
		wstring abc = m[q + 2];   wcout << "asc= " << abc << endl; //строка куда записывается файл для обучения 

																   //**************** wstring --> string **********************
		string s(abc.begin(), abc.end());
		s.assign(abc.begin(), abc.end());
		cout << "s= " << s << endl;
		//**********************************************************

		const char * c = s.c_str(); //string --> char

									//**************** объединение двух строк - char ов ************
									//char ddd[] = "D:/C++/training/";
		strcat(ddd1, c);
		cout << "ddd1= " << ddd1 << endl;
		cout << "Для продолжения работы программы нажмите любую клавишу..." << endl;
		cin.get();
		//************************
		// вместо strcat можно написать strcat_s, но тогда выдает ошибку связанную с L"D:\\C++\\training\\*"(77 строка), именно L не нравится

		//все очень криво работает - но работает

		//const char c[] = "D:/C++/training/one.data"; //пока не нужно 

		//f1(ddd); //вызов функции
	}
}