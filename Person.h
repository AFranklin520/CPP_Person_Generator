//Anthony Franklin afranklin18@cnm.edu
//1/27/2022
//MUST include FranklinPerson.lib
//Person.h

#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include "Date.h"
using namespace std;

class  Person
{
private:
	string name;
	int age{ 0 };
	Date bday;
	void CalcAge();

public:
	Person() = default;		//default constructor		
	Person(string p, Date d);
	Person(string p, int m, int d, int y);

	//Setters
	void SetName(string n) { name = n; }
	void SetBirthday(int m, int d, int y);
	void SetBirthday(Date d);

	//Getters
	string GetName() { return name; }
	string GetNameAge();
	string GetFullDesc();
	Date GetBirthDay();
	//overloaded operators
	bool operator < (Person p);
	bool operator > (Person p);
};
#endif
