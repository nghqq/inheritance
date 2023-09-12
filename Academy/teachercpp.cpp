#include"human.h"
#include"Teacher.h"

const std::string& Teacher::get_speciality()const
{
	return speciality;
}
int Teacher::get_exprerience()const
{
	return experience;
}
void Teacher::set_speciality(const std::string& speciality)
{
	this->speciality = speciality;
}
void  Teacher::set_experience(int experience)
{
	this->experience = experience;
}

//Constructor
Teacher::Teacher
(HUMAN_TAKE_PARAMETERS, TEACHER_GIVE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
{
	set_speciality(speciality);
	set_experience(experience);
	std::cout << "TConstructor:\t" << this << std::endl;
}
Teacher::~Teacher()
{
	std::cout << "TDestructor:\t" << this << std::endl;
}

// Methods
void Teacher::print()const
{
	Human::print();
	std::cout << speciality << " " << experience << " years\n";
}