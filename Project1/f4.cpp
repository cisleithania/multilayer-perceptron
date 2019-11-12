#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void f4(const char *a, int o)
{
	int n = o;
	string str;
	ifstream in(a);
	ofstream out("training/f4.data");

	out << n * 248 << " 23 1\n";

	while (getline(in, str))
	{
		//str.erase(0, 11); // 10 или 11, в зависимости от файла
		out << str << "\n";
		//out << "1\n";  //1 или -1  (эту строчку убрать для подготовки файла для тренировки)
	}

	in.close();
	out.close();
	remove(a);
	rename("training/f4.data", a);

}