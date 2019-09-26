#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void f3(const char *a, int o)
{
	string str;
	ifstream in(a);
	//ofstream out("D:/C++/training/nn.data", ios_base::app);
	ofstream out("training/nn.data", ios_base::app);

	int n = o;
	const int size = 256;
	char mas[size];
	//out << n*248 <<" 23 1\n";

	while(in.getline(mas, size))
	{
		out << mas << endl;
	}

	in.close();
	out.close();
	//remove(a);
	//rename("D:/C++/train/files_for_training/f1.dat", a);
}