#include<iostream>
#include<fstream>

void main() 
{
	setlocale(LC_ALL, "");

	std::ofstream fout;			// Создаем поток
	fout.open("File.txt");		// Открывает поток
	fout << "Hello Files";		//Пишем в поток
	fout.close();				//Когда поток не нужен его нужно закрыть 

	system("notepad File.txt");  // 'system' позволяет вызвать любую команду из командной строки
}