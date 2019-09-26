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
	wstring ggg[1000];  //строка где хранятся названия файлов (широкий символ w_)

	//HANDLE const hFind = FindFirstFileW(L"D:\\C++\\train\\files_for_training\\*", &wfd); //директория, где ищутся файлы
	HANDLE const hFind = FindFirstFileW(L"D:/C++/train/files_for_training/*", &wfd); //директория, где ищутся файлы

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

	int o = iter - 2; //количество файлов в папке (-2 - потому что, по умолчанию выводится число на два больше)
	cout << "Количество файлов в папке: " << o << endl;

	//cout << "Для продолжения работы программы нажмите любую клавишу..." << endl;
	//cin.get();

	for (int t = 0; t < iter; t++) {   //(int t = 0; t < 100; t++)
		std::wcout << ggg[t] << std::endl; //вывод на экран названий файлов
	}

	for (int q = 0; q < o; q++)
	{

		cout << "вы находитесь в цикле q = " << q << endl;
		//cin.get();

		// 0 - .; 1 - ..; 2 - первый файл; 3 - второй файл и т.д.
		wstring abc = ggg[q + 2];   wcout << abc << endl; //строка куда записывается файл для обучения 

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
		cout << "change = : " << s1 << endl;   //в ascii коды начинаются от 48. 
		int change1 = change - 48;
		cout << "change1 = : " << change1 << endl;

		cout << "change string s: " << s[25] << endl;
		char s2 = s[25];
		cout << "s1 = : " << s2 << endl;
		int change0 = s2;
		cout << "change = : " << s2 << endl;   //в ascii коды начинаются от 48. 
		int change2 = change0 - 48;
		cout << "change1 = : " << change2 << endl;

		//**************** объединение двух строк - char ов *************
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