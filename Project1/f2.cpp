#pragma once
#include "stdafx.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void f2(const char *a)
{
	string str;
	ifstream in(a);
	//ofstream out("D:/C++/f1.dat");
	ofstream out("f1.dat");

	while (getline(in, str))
	{
		str.erase(0, 10); // 10 или 11, в зависимости от файла
		out << str << "\n";
		//out << "-1\n";  //1 или -1  (эту строчку убрать для подготовки файла для тренировки)
	}
	in.close();
	out.close();
	remove(a);
	//rename("D:/C++/f1.dat", a);
	rename("f1.dat", a);
}