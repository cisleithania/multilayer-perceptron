#pragma once
#include "stdafx.h"
#include "fann.h"
#include "floatfann.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
//#include <filesystem>
#include "f2.h"
#include "GPU_1.h"
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include "device_launch_parameters.h"
using namespace std;

void testing(int &o, int &one, int &two, int &equally, int &percent)
{

	const int n = 248; //���������� ����� � �����
					   //cout << "������� ���������� ����� � ����� ";
					   //(cin >> n).get();

					   //fann_type m[n];  //������(������), ���� ����� ������������ ��� �������� ������� ������������ �����, 248 ����
	
	//string abcdef = experimental::filesystem::absolute("unite_14.net").generic_string(); //������ ���� � ���������� ����� ���������
	//const char * ccc = abcdef.c_str(); //string->char

	struct fann *ann = fann_create_from_file("C:/Users/danis/Documents/Visual Studio 2015/Projects/Project1/Project1/nn_unite.net"); // <--31.03.2018 ��������� ����
	//struct fann *ann = fann_create_from_file("NN/nn_unite.net"); // <--31.03.2018 ��������� ����
	const int a = 23; //���������� �������� � �����



					  //**********************���� � ������ � ������������ ����������*************
	WIN32_FIND_DATAW wfd;
	int iter = 0;
	int j = 0;
	wstring ggg[1000];  //������ ��� �������� �������� ������ (������� ������ w_)

	//HANDLE const hFind = FindFirstFileW(L"D:\\C++\\train\\files_for_testing\\*", &wfd); //����������, ��� ������ �����
	HANDLE const hFind = FindFirstFileW(L"D:/C++/train/files_for_testing/*", &wfd); //����������, ��� ������ �����

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

	o = iter - 2; //���������� ������ � ����� (-2 - ������ ���, �� ��������� ��������� ����� �� ��� ������)
	cout << "���������� ������ � �����: " << o << endl;

	cout << "��� ����������� ������ ��������� ������� ����� �������..." << endl;
	//cin.get();

	//////////////**************float *o2 = new float[o]; //������, ��������� � ���������� ������ � ����������, ���� ����� ������������ ���������� ������� �����

	for (int t = 0; t < iter; t++) {   //(int t = 0; t < 100; t++)
		std::wcout << ggg[t] << std::endl; //����� �� ����� �������� ������
	}
	//**********************���� � ������ � ������������ ����������*********************


	//������ ��� 23 ����� ���������� ����� ��������� ����, �� ������ �������� ���� �����(�������� ������), ������� ������������ � ������ m
	for (int q = 0; q < o; q++) { //������ q<1 ��������� q<o

		cout << "�� ���������� � ����� q = " << q << endl;
		//cin.get();


		fann_type *m = new fann_type[n];

		// 0 - .; 1 - ..; 2 - ������ ����; 3 - ������ ���� � �.�.
		wstring abc = ggg[q + 2];   wcout << abc << endl; //������ ���� ������������ ���� ��� �������� 

		//**************** wstring --> string ****************************
		string s(abc.begin(), abc.end());
		s.assign(abc.begin(), abc.end());
		cout << s << endl;
		//***************************************************************

		//����� �� ������ S ���������� ������ change ������� ����������� ����� (1 ��� 2) 24/25
		cout << "string s: " << s << endl;



		const char * c = s.c_str(); //string --> char

		cout << "change string s: " << s[24] << endl;
		char s1 = s[24];
		cout << "s1 = : " << s1 << endl;
		int change = s1;
		cout << "change = : " << s1 + 3 << endl;   //� ascii ���� ���������� �� 48. 
		int change1 = change - 48;
		cout << "change1 = : " << change1 + 3 << endl;

		cout << "change string s: " << s[25] << endl;
		char s2 = s[25];
		cout << "s1 = : " << s2 << endl;
		int change0 = s2;
		cout << "change = : " << s2 + 3 << endl;   //� ascii ���� ���������� �� 48. 
		int change2 = change0 - 48;
		cout << "change1 = : " << change2 + 3 << endl;

		//**************** ����������� ���� ����� - char �� ******************************
		//char ddm[70] = "D:/C++/train/files_for_testing/";
		char ddm[70] = "D:/C++/train/files_for_testing/";
		strcat(ddm, c);
		cout << "ddm = " << ddm << endl;
		//puts(ddm);
		//********************************************************************************
		//cin.get();


		for (int i = 0; i < n; i++)
		{

			///////////////////

			ifstream f(ddm);

			//getline(f, S);
			string str;
			for (int j = 0; j < i; j++) // ���������� n - 1 ������
				f.ignore(255, '\n');

			if (!f.eof()) // ���� �� ����� �����
			{
				getline(f, str); // ������� ������ ������
				cout << "str = " << str; // ������ ��, ��� �������, �� ����� 
			}
			else cout << "����� ������ � ����� ���." << endl;
			f.close();

			fann_type input[a];
			istringstream ss(str);
			//istringstream - ��� ��������� ����� �����. ����������� istringstream() �� ��������� ���������� ����������� ����������� ������ ������ � ��������� ������. 
			//�� ���� ������ ���������� ����� ����������� �� ����������� ������ ����� ����� �� �������, ��� � �� cin, ������� ������ ������ ����� istream.
			//cin ��������� �� �� ������ (�� ��� �������� �������), � ������-�� �� ������������ ��������� (�� �������)
			cout << endl;
			for (int k = 0; k < a; ++k)
			{
				ss >> input[k]; //������ ����������� ������ str � input
								//cout<<input[k]<<endl;
			}

			//fann_type - ���, ������������ ��� �����, ������ � ������� ��������� ����.
			//��� ����������� fann.h ��� floatfann.h, fann_type ������������ ��� ��� float. 

			fann_type *b; //��������� �� ���������� b ���� float 

						  //struct fann *ann = fann_create_from_file("neural_network_2.net");   <-- ��� ����� 31.03.2018
						  //ann - Artificial neural network(������������� ��������� ����)
						  //fann_create_from_file - ������� ��������� ���� backpropagation �� ����� ������������, ������� ���� ��������� fann_save.
						  //backpropagation - ����� ��������� ��������������� ������ (����� �������� ������������� �����������) 
						  //���� xor_float.net - ���� ������������, ��������� � ������� neuron_01, ��� ��������� ��������� ��������� ����.
						  //*ann - ��������� �� ����������� ���������� ���� funn. ��������� ����.

						  //input[0] = 1; //������ ������� ������� input - �������� ������� �����.
						  //input[1] = 1;  //������ ������� ������� input - �������� ������� �����.

			//fann_type c;

			/*useGPU obj;
			obj.adding(ann, input, b);
			*/


			b = fann_run(ann, input);

			//fann_run - ����� ��������� ���� ����� ��������� ����, ��������� ������ �������, ����� ������� ����� ����� �������� � �������� ����.

			//cout<< input[0] << input[1] << input[2] << input[3] << input[4] << input[5] << input[6] << input[7] << input[8] << input[9] 
			//<< input[10] << input[11] << input[12] << input[13] << input[14] << input[15] << input[16] << input[17] << input[18] << input[19] 
			//<< input[20] << input[21] << input[22] << endl <<"test= " << b[0] <<endl;
			//cout << "input i = " << input[i] << endl; 

			cout << "�������� ������ " << i + 1 << " = " << b[0] << endl;
			m[i] = b[0];//������ � ������
			cout << "���������� � m[i]" << " = " << m[i] << endl;
			//����� �� ����� �������� ������� �����, ����� ��������� ������ � �������� ������.
			////////////////////////
		}
		////////*//*/*//*/*} // ��� ���� �������� ������� q


		for (int p = 0; p < n; p++)
		{
			cout << "�������� ������ " << p + 1 << " = " << m[p] << endl;
		}

		float sum = 0;
		for (int r = 0; r < n; r++) {
			sum += m[r];
		}
		float x = sum / n;
		//cout << "������� �������������� = " << x << endl;
		//////////***********o2[o] = x;
		//float x ���������� �������� � ������ o2
		cout << "x= " << x << endl;

		if (x > 0)
		{
			cout << "������� �������������� = " << x << " ,���� ��������� � ������� ����." << endl;
		}
		if (x < 0)
		{
			cout << "������� �������������� = " << x << " ,���� ��������� �� ������� ����." << endl;
		}
		if (x == 0)
		{
			cout << "������� �������������� = " << x << " ,�� ������� �������� ����." << endl;
		}
		///////////////*************cout << "o2[o] = " << o2[o] <<endl;
		cout << "x= " << x << endl;
		if (((change1 == 2) || (change2 == 2)) && (x < 0))//���������� change ������� ��������� �����; ��� ��������� ������ "2", � ������ ����� 2
			two += 1;

		if (((change1 == 1) || (change2 == 1)) && (x > 0))
			one += 1;

		if (x == 0)
			equally += 1;

		cout << "��� ����������� ������ ��������� ������� ����� �������..." << endl;
		//cin.get();
		delete[]m;
	}


	/////////************���� �� �������� o2
	/*for(int z = 0; z < o; z++){
	if (o2[z] > 0)
	cout << "���� " << o << " ��������� � ������� ����." << endl;
	if (o2[z] < 0)
	cout << "���� " << o << " ��������� �� ������� ����." << endl;
	if (o2[z] = 0)
	cout << "�� ������� �������� ���� " << o << endl;
	}*/


	/////////*********delete []o2; // ������� ������


	/*
	fann_destroy(ann);//����������� ��������� ����
	*/

	cout << "generally= " << o << endl;
	cout << "two= " << two << endl;
	cout << "one= " << one << endl;
	cout << "equally= " << equally << endl;

	percent = (two + one) * 100 / o;
	cout << "percent = " << percent << "%" << endl;


}