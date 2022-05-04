//Anthony Franklin afranklin18@cnm.edu
//1/27/2022
//MUST include FranklinPerson.lib
//File: Date.h

#ifndef _DATE_H
#define _DATE_H

#include <string>
#include <chrono>
using namespace std;

class Date
{
private:
	int month{ 1 }, day{ 1 }, year{ 2020 };


	string description;
	chrono::year_month_day ymd;

public:
	Date();
	Date(int m, int d, int y, string desc);
	void SetDate(int m, int d, int y, string desc);
	void SetDesc(string d) { description = d; }


	string GetFormattedDate();
	int GetYear() { return year; }
	int GetMonth() { return month; }
	int GetDay() { return day; }
	chrono::year_month_day GetYearMonthDay() const { return ymd; }
};

#endif