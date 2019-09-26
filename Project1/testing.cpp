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

	const int n = 248; //количество строк в файле
					   //cout << "Введите количество строк в файле ";
					   //(cin >> n).get();

					   //fann_type m[n];  //массив(вектор), куда будут записываться все выходные нейроны тестируемого файла, 248 штук
	
	//string abcdef = experimental::filesystem::absolute("unite_14.net").generic_string(); //полный путь к созданному файлу нейросети
	//const char * ccc = abcdef.c_str(); //string->char

	struct fann *ann = fann_create_from_file("C:/Users/danis/Documents/Visual Studio 2015/Projects/Project1/Project1/nn_unite.net"); // <--31.03.2018 нейронная сеть
	//struct fann *ann = fann_create_from_file("NN/nn_unite.net"); // <--31.03.2018 нейронная сеть
	const int a = 23; //количество столбцов в файле



					  //**********************путь к файлам в определенной директории*************
	WIN32_FIND_DATAW wfd;
	int iter = 0;
	int j = 0;
	wstring ggg[1000];  //строка где хранятся названия файлов (широкий символ w_)

	//HANDLE const hFind = FindFirstFileW(L"D:\\C++\\train\\files_for_testing\\*", &wfd); //директория, где ищутся файлы
	HANDLE const hFind = FindFirstFileW(L"D:/C++/train/files_for_testing/*", &wfd); //директория, где ищутся файлы

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

	o = iter - 2; //количество файлов в папке (-2 - потому что, по умолчанию выводится число на два больше)
	cout << "Количество файлов в папке: " << o << endl;

	cout << "Для продолжения работы программы нажмите любую клавишу..." << endl;
	//cin.get();

	//////////////**************float *o2 = new float[o]; //массив, величиной с количество файлов в директории, куда будут записываться результаты каждого файла

	for (int t = 0; t < iter; t++) {   //(int t = 0; t < 100; t++)
		std::wcout << ggg[t] << std::endl; //вывод на экран названий файлов
	}
	//**********************путь к файлам в определенной директории*********************


	//теперь эти 23 числа пропускаем через нейронную сеть, на выходе получаем одно число(выходной нейрон), которое записывается в массив m
	for (int q = 0; q < o; q++) { //вместо q<1 поставить q<o

		cout << "вы находитесь в цикле q = " << q << endl;
		//cin.get();


		fann_type *m = new fann_type[n];

		// 0 - .; 1 - ..; 2 - первый файл; 3 - второй файл и т.д.
		wstring abc = ggg[q + 2];   wcout << abc << endl; //строка куда записывается файл для обучения 

		//**************** wstring --> string ****************************
		string s(abc.begin(), abc.end());
		s.assign(abc.begin(), abc.end());
		cout << s << endl;
		//***************************************************************

		//ЗДЕСЬ ИЗ СТРОКИ S НЕОБХОДИМО УЗНАТЬ change КАЖДОГО КОНКРЕТНОГО ФАЙЛА (1 ИЛИ 2) 24/25
		cout << "string s: " << s << endl;



		const char * c = s.c_str(); //string --> char

		cout << "change string s: " << s[24] << endl;
		char s1 = s[24];
		cout << "s1 = : " << s1 << endl;
		int change = s1;
		cout << "change = : " << s1 + 3 << endl;   //в ascii коды начинаются от 48. 
		int change1 = change - 48;
		cout << "change1 = : " << change1 + 3 << endl;

		cout << "change string s: " << s[25] << endl;
		char s2 = s[25];
		cout << "s1 = : " << s2 << endl;
		int change0 = s2;
		cout << "change = : " << s2 + 3 << endl;   //в ascii коды начинаются от 48. 
		int change2 = change0 - 48;
		cout << "change1 = : " << change2 + 3 << endl;

		//**************** объединение двух строк - char ов ******************************
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
			for (int j = 0; j < i; j++) // пропускаем n - 1 строки
				f.ignore(255, '\n');

			if (!f.eof()) // если не конец файла
			{
				getline(f, str); // считали нужную строку
				cout << "str = " << str; // вывели то, что считали, на экран 
			}
			else cout << "Такой строки в файле нет." << endl;
			f.close();

			fann_type input[a];
			istringstream ss(str);
			//istringstream - это строковой поток ввода. Конструктор istringstream() со строковым аргументом прикрепляет создаваемый объект потока к указанной строке. 
			//То есть теперь информация будет считываться из стандартной строки точно таким же образом, как и из cin, объекта класса потока ввода istream.
			//cin считывает не из потока (он сам является потоком), а откуда-то из стандартного приемника (из консоли)
			cout << endl;
			for (int k = 0; k < a; ++k)
			{
				ss >> input[k]; //запись содержимого строки str в input
								//cout<<input[k]<<endl;
			}

			//fann_type - тип, используемый для весов, входов и выходов нейронной сети.
			//При подключении fann.h или floatfann.h, fann_type определяется как тип float. 

			fann_type *b; //указатель на переменную b типа float 

						  //struct fann *ann = fann_create_from_file("neural_network_2.net");   <-- это убрал 31.03.2018
						  //ann - Artificial neural network(искусственная нейронная сеть)
						  //fann_create_from_file - Создает нейронную сеть backpropagation из файла конфигурации, которые были сохранены fann_save.
						  //backpropagation - Метод обратного распространения ошибки (метод обучения многослойного перцептрона) 
						  //файл xor_float.net - файл конфигурации, созданная в проекте neuron_01, где сохранена обученная нейронная сеть.
						  //*ann - указатель на структурную переменную типа funn. Нейронная сеть.

						  //input[0] = 1; //Первый элемент массива input - значение первого входа.
						  //input[1] = 1;  //Второй элемент массива input - значение второго входа.

			//fann_type c;

			/*useGPU obj;
			obj.adding(ann, input, b);
			*/


			b = fann_run(ann, input);

			//fann_run - будет запускать вход через нейронную сеть, возвращая массив выходов, число которых равно числу нейронов в выходном слое.

			//cout<< input[0] << input[1] << input[2] << input[3] << input[4] << input[5] << input[6] << input[7] << input[8] << input[9] 
			//<< input[10] << input[11] << input[12] << input[13] << input[14] << input[15] << input[16] << input[17] << input[18] << input[19] 
			//<< input[20] << input[21] << input[22] << endl <<"test= " << b[0] <<endl;
			//cout << "input i = " << input[i] << endl; 

			cout << "Выходной нейрон " << i + 1 << " = " << b[0] << endl;
			m[i] = b[0];//запись в массив
			cout << "записалось в m[i]" << " = " << m[i] << endl;
			//вывод на экран значений первого входа, затем следующих входов и значения выхода.
			////////////////////////
		}
		////////*//*/*//*/*} // ТУТ БЫЛО ЗАКРЫТИЕ ФУНКЦИИ q


		for (int p = 0; p < n; p++)
		{
			cout << "Выходной нейрон " << p + 1 << " = " << m[p] << endl;
		}

		float sum = 0;
		for (int r = 0; r < n; r++) {
			sum += m[r];
		}
		float x = sum / n;
		//cout << "Среднее арифметическое = " << x << endl;
		//////////***********o2[o] = x;
		//float x необходимо передать в массив o2
		cout << "x= " << x << endl;

		if (x > 0)
		{
			cout << "Среднее арифметическое = " << x << " ,файл относится к первому типу." << endl;
		}
		if (x < 0)
		{
			cout << "Среднее арифметическое = " << x << " ,файл относится ко второму типу." << endl;
		}
		if (x == 0)
		{
			cout << "Среднее арифметическое = " << x << " ,не удалось опознать файл." << endl;
		}
		///////////////*************cout << "o2[o] = " << o2[o] <<endl;
		cout << "x= " << x << endl;
		if (((change1 == 2) || (change2 == 2)) && (x < 0))//необходимо change сделать численным типом; там находится символ "2", а должна цифра 2
			two += 1;

		if (((change1 == 1) || (change2 == 1)) && (x > 0))
			one += 1;

		if (x == 0)
			equally += 1;

		cout << "Для продолжения работы программы нажмите любую клавишу..." << endl;
		//cin.get();
		delete[]m;
	}


	/////////************ПОКА НЕ РАБОТАЕТ o2
	/*for(int z = 0; z < o; z++){
	if (o2[z] > 0)
	cout << "Файл " << o << " относится к первому типу." << endl;
	if (o2[z] < 0)
	cout << "Файл " << o << " относится ко второму типу." << endl;
	if (o2[z] = 0)
	cout << "Не удалось опознать файл " << o << endl;
	}*/


	/////////*********delete []o2; // очистка памяти


	/*
	fann_destroy(ann);//уничтожение нейронной сети
	*/

	cout << "generally= " << o << endl;
	cout << "two= " << two << endl;
	cout << "one= " << one << endl;
	cout << "equally= " << equally << endl;

	percent = (two + one) * 100 / o;
	cout << "percent = " << percent << "%" << endl;


}