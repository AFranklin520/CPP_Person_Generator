/*
Anthony Franklin
afranklin18@cnm.edu
Person Generator which randomly generates males/females of random ages within a range with valid birthdates
Demonstrates objects, pointers to objects, and double pointers to objects
1/27/2022
PersonGen.cpp
*/

#include "PersonGen.h"

bool PersonGen::ReadFile(string file, string vn[])
{
	ifstream another;
	int linesRead{ 0 };
	another.open(file);
	//if not open return false; else read lines into array of 300, close file, return true
	if (!(another.is_open()))
	{
		return false;
		fileRead = false;
	}
	else
	{
		fileRead = true;
		while(!another.eof())
		{
			another >> vn[linesRead];
			linesRead++;
		}
		return true;
	}
	
}

void PersonGen::NameGen()
{
	uniform_int_distribution<int> dist(0, 299);
	int lastNameIndex = dist(engine);
	//Repeat for first names
	int firstNameIndex = dist(engine);
	//Randomly choose m or f and create full name
	uniform_int_distribution<int> d2(0, 1);
	int gender{ 0 };
	gender = d2(engine);
	(gender == 0) ? name = last[lastNameIndex] + ", " + maleFirst[firstNameIndex] : name = last[lastNameIndex] + ", " + femFirst[firstNameIndex];

}

void PersonGen::ReadUseFile()
{
	static int linesRead{ 0 };
	if (linesRead == fileCount)
	{
		//close file
		input.close();
		bUseFile = false;
		NameGen();
		BirthdayGen(yAge, oAge);
	}
	else
	{
		//still reading useFile; set name, m, d, y in member vars (ONLY one line)
		string n, mon, day, yr;
		
		getline(input, n, '|');
		getline(input, mon, '|');
		getline(input, day, '|');
		getline(input, yr);
		name = n;
		m = stoi(mon);
		d = stoi(day);
		y = stoi(yr);

		linesRead++;
	}
}

void PersonGen::BirthdayGen(int youngAge, int oldAge)
{
	Date bday{ 0, 0, 0, name };
	while(!bday.GetYearMonthDay().ok())
	{
		//Get random num for month, day, year and if ok, set into member vars(randBday.SetDate())
		uniform_int_distribution<int> mDist(0, 11);
		int mon = mDist(engine) + 1;
		uniform_int_distribution<int> dDist(0, 31);
		int day = dDist(engine) + 1;
		uniform_int_distribution<int> yDist(oldAge, youngAge);
		int yr = yDist(engine) + 1;
		bday.SetDate(mon, day, yr, name);
	}
	m = bday.GetMonth();
	d = bday.GetDay();
	y = bday.GetYear();
}

PersonGen::PersonGen() : PersonGen{ yAge, oAge }
{
}

PersonGen::PersonGen(int youngAge, int oldAge)
{
	//Call ReadFile 3x - once for each .txt file - and read into array
	ReadFile("FirstMale.txt", maleFirst);
	ReadFile("FirstFemale.txt", femFirst);
	ReadFile("Last.txt", last);
	//Seed random num gen.
	seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
	engine.seed(std::chrono::system_clock::now().time_since_epoch().count());

}

Person PersonGen::GetPerson()
{
	//Returns default person object; either contained within UseFile or randomly generated if none in file
	if (bUseFile == false)
	{
		NameGen();
		BirthdayGen(yAge, oAge);
	}
	else
	{

		ReadUseFile();
	}

	Person p(name, m, d, y);
	return p;
}

Person* PersonGen::GetNewPerson()
{
	
	if (bUseFile == false)
	{
		NameGen();
		BirthdayGen(yAge, oAge);
	}
	else
	{

		ReadUseFile();
	}

	Person* p = new Person(name, m, d, y);
	return p;
}

bool PersonGen::IsTextFileRead()
{
	//Return whether all ReadFIle calls were successful using bool fileRead; if not return false
	return fileRead;
}

bool PersonGen::CreateFile(string filename, int numOfPersons)
{
	ofstream outputFile;
	outputFile.open(filename);
	if(fileRead)
	{
		outputFile << numOfPersons << endl;
		for (int i {0}; i < numOfPersons; i++)
		{
			Person p = GetPerson();
			Date d = p.GetBirthDay();
			outputFile  << p.GetName() << " | " << d.GetMonth() << " | " << d.GetDay() << " | " << d.GetYear() << endl;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool PersonGen::UseFile(string filename)
{
	input.open(filename.c_str());
	//Check input, set bUseFile to false if false; otherwise set to true and continue.

	//Read first line to get num of entries in file
	if (input.is_open())
	{
		input >> fileCount;
		bUseFile = true;
	}
	else
	{
		bUseFile = false;
	}

	return bUseFile;
}
