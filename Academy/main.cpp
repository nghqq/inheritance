#include <iostream>

#define HUMAN_TAKE_PARAMETERS const std::string& first_name, const std::string& last_name, int age
#define HUMAN_GIVE_PARAMETERS first_name, last_name, age

class Human 
{
	std::string first_name;
	std::string last_name;
	int age;

public:
	const std::string& get_first_name()const 
	{
		return first_name;
	}
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const int get_age()const
	{
		return age;
	}
	void set_first_name(const std::string& first_name) 
	{
		this->first_name = first_name;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

			// Constructor

	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_first_name(first_name);
		set_last_name(last_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;
	}

	~Human() 
	{
		std::cout << "HDestructor:\t" << this << std::endl;
	}
					//Methods

	void print()const 
	{
		std::cout << last_name << " " << first_name << " " << age << std::endl;
	} 
};

class Student :public Human 
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;

public:
	const std::string& get_speciality() const 
	{
		return speciality;
	}
	const std::string& get_group() const
	{
		return speciality;
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

	// Constructor
#define STUDENT_TAKE_PARAMETERS std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality,group,rating,attendance
	Student(
		HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	void print()const
	{
		Human::print();
		std::cout << speciality << " " << group << " " << rating << " " << attendance << std::endl;
	}

};
class Teacher :public Human 
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const 
	{
		return speciality;
	}
	int get_experience()const 
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

				//TConstuctor
	Teacher(HUMAN_TAKE_PARAMETERS, const std::string& speciality, int experience) :Human(HUMAN_GIVE_PARAMETERS) 
	{
		set_speciality(speciality);
		set_experience(experience);
	}

};
class Graduate : public Student
{
	std::string subject;
public:
	const:
};

void main()
{
	setlocale(LC_ALL, "");

	Human human("Montano", "Antonio", 35);
	human.print();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 90, 95);
	student.print();
}