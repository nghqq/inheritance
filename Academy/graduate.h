#pragma once
#include "human.h"
#include "student.h"
#define GRADUATE_TAKE_PARAMETERS  const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject
#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const;
	void set_subject(const std::string& subject);

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS);
	~Graduate();
	// Methods
	void print()const;
};