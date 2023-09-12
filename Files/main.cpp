#include<iostream>
#include<fstream>

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
void main() 
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	std::ofstream fout;			// Создаем поток
	fout.open("File.txt", std::ios_base::app);		// Открывает поток
	fout << "Hello Files";		//Пишем в поток
	fout.close();				//Когда поток не нужен его нужно закрыть 

	system("notepad File.txt");  // 'system' позволяет вызвать любую команду из командной строки  
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		//TODO read file
		const int SIZE = 10240;
		char sz_buffer[SIZE] = {};
		while (!fin.eof())  // End of file
		{
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			std::cout << sz_buffer << std::endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << std::endl; //cerr выводит в канал для ошибок (как cout)
	}
#endif // READ_FROM_FILE

}