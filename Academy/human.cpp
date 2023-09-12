#include"human.h"

const std::string& Human::get_last_name()const
{
	return last_name;
}
const std::string& Human::get_first_name()const
{
	return first_name;
}
int Human::get_age()const
{
	return age;
}
void Human::set_last_name(const std::string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const std::string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(int age)
{
	this->age = age;
}

//Constructor
Human::Human(const std::string& last_name, const std::string& first_name, int age)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	std::cout << "HConstructor:\t" << this << std::endl;
}
Human::~Human()
{
	std::cout << "HDestructor:\t" << this << std::endl;
}

//Methods
void Human::print()const
{
	std::cout << last_name << " " << first_name << " " << age << " y/o\n";
}