/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Copyright (NR) 'Electrocution Strauss' of ECE - 1 2015-2019/20 Thapar Institute of Engineering and Technology, Patiala////
///May be distributed as far as the credit of the code and any derivatives is given to the programmers///////////////////////
///Denying credit of this code to the makers of this code will be considered a criminal and personal offence/////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once
#include"Header.h"
using namespace std;

typedef int PID;
enum Month_of_Year { January = 1, February, March, April, May, June, July, August, September, October, November, December };

struct DOB
{
	int date;
	int month;
	int year;
	Month_of_Year Month;
};

class familyMember
{
public:
	PID myPID;
	string myName;
	PID Father, Mother, *Sister, *Brother, *Other, *Son, *Daughter, Wife, Husband;


	bool male, female;
	int nofSister, nofBrother, nofOther, nofSon, nofDaughter;



	DOB RealDOB;

	familyMember();
	familyMember(string name, int gender);
	familyMember(string name, int gender, DOB dob);
	/*Gender: 1 = Male, 2 = Female, 0 = Other|Not specified*/

	familyMember(PID myPID, string name, DOB dob, int gender, int nofSis, int nofBro, int nofOther, int nofSon, int nofDaugh, PID Father, PID Mother, PID Wife, PID Husband, PID Sis[], PID BRO[], PID Other[], PID Son[], PID Daugh[]);//This one is for loading from saved state

	int setGender(int gender);
	int enterDOB(int date, int month, int year);

	int spawnSisters();
	int spawnSisters(int number_of_sisters);
	int setSisters();
	int listSisters();

	int spawnBrothers();
	int spawnBrothers(int number_of_brothers);
	int setBrothers(int,PID);
	int listBrothers();

	int spawnOthers();
	int spawnOthers(int number_of_others);
	int setOthers();
	int listOthers();

	int spawnSons();
	int spawnSons(int number_of_brothers);
	int setSons();
	int listSons();

	int spawnDaughters();
	int spawnDaughters(int number_of_brothers);
	int setDaughters();
	int listDaughters();

	int setFather();
	int setMother();
	int setWife();
	int setHusband();


	int saveMember(ofstream*);

private:
	string fatherName, motherName;
}; 
