/*
Anthony Franklin
afranklin18@cnm.edu
Person Generator which randomly generates males/females of random ages within a range with valid birthdates
Demonstrates objects, pointers to objects, and double pointers to objects
1/27/2022
PersonGen.h
*/

#ifndef  _PERSONGEN_H
#define  _PERSONGEN_H

#include <string>
#include "Person.h"
#include <fstream>
#include <random>
#include <iostream>

class PersonGen
{
	private:
		ifstream input;
		unsigned seed;
		default_random_engine engine;
		string maleFirst[300];
		string femFirst[300];
		string last[300];

		int fileCount{ 0 };
		Date Today;
		Date bDay;
		int yAge{ Today.GetYear() -4 };
		int oAge{ Today.GetYear() -85 };
		int m, d, y{ 0 };

		string name;

		bool bUseFile{ false };
		bool fileRead{ false };

		//Read txt file and assign to array vn
		bool ReadFile(string file, string vn[]);
		//Randomly generate name
		void NameGen();
		//Access Person data in the use file to get name and bday
		void ReadUseFile();
		//Randomly generate bday from young to old
		void BirthdayGen(int youngAge, int oldAge);

	public:
		//default creation, alternate male, female, age range toddler to elderly
		PersonGen();	

		//overloaded constructor, specify age range of persons
		PersonGen( int youngAge, int oldAge);	

		//returns a Person object, created locally in class, not using new
		Person GetPerson();		

		//return a Person created via the new operator
		Person* GetNewPerson();	

		//return a bool indicating that the text files were correctly opened
		//and read.  Returns false if any file was not opened and read.
		bool IsTextFileRead();
	

		//createFile creates a file with number of persons, 
		//return true if file successfully written, false if not.
		bool   CreateFile(string filename, int numOfPersons); 

		//useFile directs the generator to use the person data that is 
		//stored in the file instead of random creation. 
		//Return true indicates it was able to locate and open the file. 
		//Returns false file not found. 
		//When this method is called, the generator will only read the file 
		//line-by-line to pull out person data AS NEEDED. It DOES NOT read 
		//the entire file and store the data. If the file runs out of names, 
		//begin generating the persons randomly. 
		bool  UseFile(string filename);	
}; 
#endif
