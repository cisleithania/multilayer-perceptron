#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �������� �������� ���� � ��� ������
	Project1::MyForm form1;
	Application::Run(%form1);
	return 0;
}