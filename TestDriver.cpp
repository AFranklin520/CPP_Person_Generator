/*
Anthony Franklin
afranklin18@cnm.edu
Person Generator which randomly generates males/females of random ages within a range with valid birthdates
Demonstrates objects, pointers to objects, and double pointers to objects
1/27/2022
Test Driver
*/

#include "PersonGen.h"
#include <iostream>

using namespace std;

int main()
{
	/*Uncomment the following to create file of N Person objects*/


	//PersonGen* pg = new PersonGen;   //constructor default generator, age span toddler to elderly
	////check to make sure files were all opened and read
	//if (pg->IsTextFileRead() == false)
	//{
	//	cout << "\n\n Whoops!  A text file was not read.";

	//}
	//else
	//{
	//	bool bOK;
	//	bOK = pg->CreateFile("Persons15.txt", 15);   //Modify this line to change default filename and number of Person objects

	//	if (bOK)
	//	{
	//		cout << "File created, all ok";
	//	}
	//	else
	//	{
	//		cout << "\n no file created";
	//	}
	//}


	
	PersonGen* pg = new PersonGen;   //constructor default generator, age span toddler to elderly
	if (pg->IsTextFileRead() == false)
		cout << "\n\nWhoops!  A text file was not read.";

	bool bOK;
	bOK = pg->UseFile("Persons15.txt");
	if (bOK)
	{
		cout << "\nfile found, will use names from file first";
	}
	else
	{
		cout << "\nno file found, will create all Persons randomly";
	}

	//Array of 10 person objects
	cout << "\nCreating array of 10 person objects here: \n" << endl;
	Person people[10];
	int count{ 1 };
	for (Person p : people)
	{
		p = pg->GetPerson();
		cout << "\n" << count << ": " << p.GetFullDesc();
		count++;
	}

	//New array of 10 person objects
	cout << "\nCreating New array of 10 person objects here: \n" << endl;
	Person* peoplePointer = new Person[10];
	try 
	{
		for (int i{ 0 }; i < 10; ++i)
		{
			peoplePointer[i] = pg->GetPerson();
			cout << "\n" << i + 1 << ": " << peoplePointer[i].GetFullDesc();
		}
	}
	
	catch (exception exc)
	{
		cout << "Error! \nException caught: " << exc.what();
	}
	delete[] peoplePointer;
	peoplePointer = nullptr;

	//Array of 10 new person objects
	cout << "\nCreating array of 10 new person objects here: \n" << endl;
	Person* ppl[10];
	try
	{
		for (int i{ 0 }; i < 10; ++i)
		{
			ppl[i] = pg->GetNewPerson();
			cout << "\n" << i + 1 << ": " << ppl[i]->GetFullDesc();
		}
		for (int i{ 0 }; i < 10; i++) 
		{
			delete ppl[i];
			ppl[i] = nullptr;
		}

		delete[] ppl;
	}

	catch (exception exc)
	{
		cout << "Error! \nException caught: " << exc.what();
	}

	//New Array of 10 new person objects
	cout << "\nCreating new array of 10 new person objects here: \n" << endl;
	Person** newPeeps = new Person * [10];
	try
	{
		for (int i{ 0 }; i < 10; ++i)
		{
			newPeeps[i] = pg->GetNewPerson();
			cout << "\n" << i + 1 << ": " << newPeeps[i]->GetFullDesc();
		}
		for (int i{ 0 }; i < 10; i++)
		{
			delete newPeeps[i];
			newPeeps[i] = nullptr;
		}
		delete[] newPeeps;
		newPeeps = nullptr;
	}

	catch (exception exc)
	{
		cout << "Error! \nException caught: " << exc.what();
	}

	//Loop to create 5 person objects
	cout << "\nLoop to create person objects here: \n" << endl;
	for (int i{ 0 }; i < 5; i++)
	{
		Person p{ pg->GetPerson() };
		cout << "\n" << i+1 << ": " << p.GetFullDesc();
	}
		
	

	return 0;
}
