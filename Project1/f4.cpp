#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void f4(const char *a, int o)
{
	/*ofstream out(a);
	int n = o;
	out << n * 248 << " 23 1\n" << endl;
	out.close();*/

	int n = o;
	string str;
	ifstream in(a);
	//ofstream out("D:/C++/training/f4.data");
	ofstream out("training/f4.data");

	out << n * 248 << " 23 1\n";

	while (getline(in, str))
	{
		//str.erase(0, 11); // 10 ��� 11, � ����������� �� �����
		out << str << "\n";
		//out << "1\n";  //1 ��� -1  (��� ������� ������ ��� ���������� ����� ��� ����������)
	}

	in.close();
	out.close();
	remove(a);
	//rename("D:/C++/training/f4.data", a);
	rename("training/f4.data", a);

}