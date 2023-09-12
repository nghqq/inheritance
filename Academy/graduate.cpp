#include "human.h"
#include "student.h"
#include "graduate.h"
const std::string& Graduate::get_subject()const
{
	return subject;
}
void Graduate::set_subject(const std::string& subject)
{
	this->subject = subject;
}

Graduate::Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS)
	:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
{
	set_subject(subject);
	std::cout << "GConstructor:\t" << this << std::endl;
}
Graduate::~Graduate()
{
	std::cout << "GDestructor:\t" << this << std::endl;
}
void Graduate::print()const
{
	Student::print();
	std::cout << subject << std::endl;
}