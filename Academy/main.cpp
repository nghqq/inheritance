#include <iostream>
#include <fstream>
#define delimeter "\n------------------------------------\n"
#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
class Human 
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const 
	{
		return last_name;
	}
	const std::string& get_first_name()const 
	{
		return first_name;
	}
	int get_age()const 
	{
		return age;
	}
	void set_last_name(const std::string& last_name) 
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name) 
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

						//Constructor
	Human(const std::string& last_name, const std::string& first_name, int age) 
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;
	}
	virtual~Human() 
	{
		std::cout << "HDestructor:\t" << this << std::endl;
	}

				//Methods
	virtual void print()const 
	{
		std::cout << last_name << " " << first_name << " " << age << " y/o\n";
	}
};
std::ostream& operator<<(std::ostream& os, const Human& obj) 
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " лет.";
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Student:public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const 
	{
		return speciality;
	}
	const std::string& get_group()const 
	{
		return group;
	}
	double get_rating()const 
	{
		return rating;
	}
	double get_attendance()const 
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality) 
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group) 
	{
		this->group = group;
	}
	void set_rating(double rating) 
	{
		this->rating = rating;
	}
	void set_attendance(double attendance) 
	{
		this->attendance = attendance;
	}
			
		//Constructor
	Student
	(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_TAKE_PARAMETERS
	):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	~Student() 
	{
		std::cout << "SDestructor:\t" << this << std::endl;
	}
	//Methods
	void print()const
	{
		Human::print();
		std::cout << speciality << " " << group << " " << rating << " " << attendance << std::endl;
	}
};
#define TEACHER_GIVE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_TAKE_PARAMETERS speciality,experience
class Teacher:public Human
{
	std::string speciality;
	int experience;
	
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_exprerience()const 
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience) 
	{
		this->experience = experience;
	}

			//Constructor
	Teacher
	(HUMAN_TAKE_PARAMETERS,TEACHER_GIVE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~Teacher() 
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}

				// Methods
	void print()const 
	{
		Human::print();
		std::cout << speciality << " " << experience << " years\n";
	}
};

#define GRADUATE_TAKE_PARAMETERS  const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject
class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}
	void print()const
	{
		Student::print();
		std::cout << subject << std::endl;
	}
};
void print(Human* group[], const int n);
void save(Human* group[], const int n, const char sz_filename[]);

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
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 80, 70, "How to catch Heisenberg"),
		new Student("Vercetti","Thomas",30,"Theft","Vice",98,80),
		new Teacher("Diaz","Ricardo",50,"Weapon distribution",25),
	};
	print(group, sizeof(group) / sizeof(group[0]));

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}

void print(Human* group[], const int n)
{
	std::cout << delimeter << std::endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		std::cout << *group[i];
		std::cout << delimeter << std::endl;
	}
}
void save(Human* group[], const int n, const char sz_filename[]) 
{
	std::ofstream fout(sz_filename);

	fout.close();
}

