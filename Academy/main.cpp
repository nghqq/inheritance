#include"human.h"
#include "student.h"
#include"Teacher.h"
#include "graduate.h"

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
#define GRADUATE_TAKE_PARAMETERS  const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject



//#define INHERITANCE_CHECK
void main() 
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
	Human human("Monatana", "Antonio", 25);
	human.print();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 90, 95);
	student.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 20);
	teacher.print();

	Graduate graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 80, 70, "How to catch Heisenberg");
	graduate.print();
#endif // INHERITANCE_CHECK
	
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 90, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 80, 70, "How to catch Heisenberg")
	};
	std::cout << delimeter << std::endl;
	for (int i = 0; i < sizeof(group[0]); i++)
	{
		group[i]->print();
		std::cout << delimeter << std::endl;
	}
}

