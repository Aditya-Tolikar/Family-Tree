#pragma once
#include"Header.h"
using namespace std;

class familyMember
{
public:
	string myName;
	familyMember *Father, *Mother, **Sister, **Brother, **Other, **Son, **Daughter, *Wife, *Husband;
	bool male, female;
	int nofSister, nofBrother, nofOther, nofSon, nofDaughter;


	struct DOB
	{
		int date;
		int month;
		int year;
		enum Month { January = 1, February, March, April, May, June, July, August, September, October, November, December };
	};
	DOB RealDOB, *ImitDOB;

	familyMember();
	familyMember(string name, int gender);
	familyMember(string name, int gender, DOB dob);
	/*Gender: 1 = Male, 2 = Female, 0 = Other|Not specified*/

	int spawnSisters();
	int spawnSisters(int);



private:
	string fatherName, motherName;
}; 
