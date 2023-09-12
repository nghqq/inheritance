#pragma once
#include"human.h"
#define TEACHER_GIVE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_TAKE_PARAMETERS speciality,experience
class Teacher :public Human
{
	std::string speciality;
	int experience;

public:
	const std::string& get_speciality()const;
	int get_exprerience()const;
	void set_speciality(const std::string& speciality);
	void set_experience(int experience);

	//Constructor
	Teacher
	(HUMAN_TAKE_PARAMETERS, TEACHER_GIVE_PARAMETERS);
	~Teacher();

	// Methods
	void print()const;
};
