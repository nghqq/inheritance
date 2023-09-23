#include<iostream>

const char* Hello();
int Summ(int a, int b);

void main() 
{
	setlocale(LC_ALL, "");
	std::cout << Hello << std::endl; // ����� ������� 
	const char* (*pHello)() = Hello;
	std::cout << pHello << std::endl; // ����� ������� ����������� � ���������
	std::cout << pHello() << std::endl; // ����� ������� 'Hello()' ����� ��������� 'pHello'

	std::cout << Summ(2, 3) << std::endl;
	std::cout << Summ << std::endl;
	int (*pSumm)(int a, int b) = Summ;
	std::cout << pSumm << std::endl;
	std::cout << pSumm(2, 3) << std::endl;
}	

const char* Hello() 
{
	return "Hello";
}
int Summ(int a, int b) 
{
	return a + b;
}