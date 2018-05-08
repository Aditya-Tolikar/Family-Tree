/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Copyright (NR) 'Electrocution Strauss' of ECE - 1 2015-2019/20 Thapar Institute of Engineering and Technology, Patiala////
///May be distributed as far as the credit of the code and any derivatives is given to the programmers///////////////////////
///Denying credit of this code to the makers of this code will be considered a criminal and personal offence/////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "treeclass.h"
typedef int PID;

familyMember::familyMember()
{
	myPID = gen_rand_PID();

	Father = 0; Mother = 0; Wife = 0; Husband = 0; nofBrother = 0; nofDaughter = 0; nofOther = 0; nofSister = 0; nofSon = 0; Sister = nullptr; Brother = nullptr; Other = nullptr; Son = nullptr; Daughter = nullptr;

}

familyMember::familyMember(string name, int gender)
{
	myPID = gen_rand_PID();
	myName = name;
	switch (gender)
	{
	case 0:
		male = false;
		female = false;
		break;
	case 1:
		male = true;
		female = false;
		break;
	case 2:
		male = false;
		female = true;
		break;
	default:
		male = false;
		female = false;
		break;
	}
	Father = 0; Mother = 0; Wife = 0; Husband = 0; nofBrother = 0; nofDaughter = 0; nofOther = 0; nofSister = 0; nofSon = 0; Sister = nullptr; Brother = nullptr; Other = nullptr; Son = nullptr; Daughter = nullptr;

}

familyMember::familyMember(string name, int gender, DOB dob)
{
	myPID = gen_rand_PID();
	myName = name;
	switch (gender)
	{
	case 0:
		male = false;
		female = false;
		break;
	case 1:
		male = true;
		female = false;
		break;
	case 2:
		male = false;
		female = true;
		break;
	default:
		male = false;
		female = false;
		break;
	}
	RealDOB = dob;
	switch (dob.month)
	{
	case 1:
		RealDOB.Month = January;
		break;

	case 2:
		RealDOB.Month = February;
		break;

	case 3:
		RealDOB.Month = March;
		break;

	case 4:
		RealDOB.Month = April;
		break;

	case 5:
		RealDOB.Month = May;
		break;

	case 6:
		RealDOB.Month = June;
		break;

	case 7:RealDOB.Month = July;
		break;

	case 8:
		RealDOB.Month = August;
		break;

	case 9:
		RealDOB.Month = September;
		break;

	case 10:
		RealDOB.Month = October;
		break;

	case 11:
		RealDOB.Month = November;
		break;

	case 12:
		RealDOB.Month = December;
		break;

	default:
		break;

	}
	Father = 0; Mother = 0; Wife = 0; Husband = 0; nofBrother = 0; nofDaughter = 0; nofOther = 0; nofSister = 0; nofSon = 0; Sister = nullptr; Brother = nullptr; Other = nullptr; Son = nullptr; Daughter = nullptr;

}

familyMember::familyMember(PID pid, string name, DOB dob, int gender, int nofSis, int nofBro, int nofOth, int noSon, int nofDaugh, PID Fath, PID Moth, PID Wif, PID Husb, PID Sis[], PID BRO[], PID Oth[], PID Sonny[], PID Daugh[])
{/*This one is to load from saved file*/
	myPID = pid;
	myName = name;
	switch (gender)
	{
	case 0:
		male = false;
		female = false;
		break;
	case 1:
		male = true;
		female = false;
		break;
	case 2:
		male = false;
		female = true;
		break;
	default:
		male = false;
		female = false;
		break;
	}
	RealDOB = dob;
	switch (dob.month)
	{
	case 1:
		RealDOB.Month = January;
		break;

	case 2:
		RealDOB.Month = February;
		break;

	case 3:
		RealDOB.Month = March;
		break;

	case 4:
		RealDOB.Month = April;
		break;

	case 5:
		RealDOB.Month = May;
		break;

	case 6:
		RealDOB.Month = June;
		break;

	case 7:RealDOB.Month = July;
		break;

	case 8:
		RealDOB.Month = August;
		break;

	case 9:
		RealDOB.Month = September;
		break;

	case 10:
		RealDOB.Month = October;
		break;

	case 11:
		RealDOB.Month = November;
		break;

	case 12:
		RealDOB.Month = December;
		break;

	default:
		break;

	}
	Father = Fath; Mother = Moth; Wife = Wif; Husband = Husb; nofBrother = nofBro; nofDaughter = nofDaughter; nofOther = nofOth; nofSister = nofSis; nofSon = noSon; Sister = Sis; Brother = BRO; Other = Oth; Son = Sonny; Daughter = Daugh;

}

int familyMember::setGender(int gender)
{
	switch (gender)
	{
	case 0:
		male = false;
		female = false;
		break;
	case 1:
		male = true;
		female = false;
		break;
	case 2:
		male = false;
		female = true;
		break;
	default:
		male = false;
		female = false;
		break;
	}
	return 0;
}

int familyMember::enterDOB(int date, int month, int year)
{
	RealDOB.date = date;
	RealDOB.month = month;
	RealDOB.year = year;
	switch (month)
	{
	case 1:
		RealDOB.Month = January;
		break;

	case 2:
		RealDOB.Month = February;
		break;

	case 3:
		RealDOB.Month = March;
		break;

	case 4:
		RealDOB.Month = April;
		break;

	case 5:
		RealDOB.Month = May;
		break;

	case 6:
		RealDOB.Month = June;
		break;

	case 7:RealDOB.Month = July;
		break;

	case 8:
		RealDOB.Month = August;
		break;

	case 9:
		RealDOB.Month = September;
		break;

	case 10:
		RealDOB.Month = October;
		break;

	case 11:
		RealDOB.Month = November;
		break;

	case 12:
		RealDOB.Month = December;
		break;

	default:
		break;

	}
	return 0;
}

int familyMember::spawnSisters()
{
	Sister = new PID[nofSister];
	return 0;
}

int familyMember::spawnSisters(int number_of_sisters)
{
	nofSister = number_of_sisters;
	Sister = new PID[nofSister];
	return 0;
}

int familyMember::setSisters()
{
	return 0;
}

int familyMember::listSisters()
{
	cout << endl << "Sisters of " << myName << ":" << endl;
	for (int i = 0; i < nofSister; i++)
	{
		cout << Sister[i] << endl;
	}
	return 0;
}

int familyMember::spawnBrothers()
{
	Brother = new PID[nofBrother];
	return 0;
}

int familyMember::spawnBrothers(int number_of_brothers)
{
	nofBrother = number_of_brothers;
	Brother = new PID[nofBrother];
	return 0;
}

int familyMember::setBrothers(int No_, PID BroPID)
{
	Brother[No_] = BroPID;
	return 0;
}

int familyMember::listBrothers()
{
	cout << endl << "Brothers of " << myName << ":" << endl;
	for (int i = 0; i < nofBrother; i++)
	{
		cout << Brother[i] << endl;
	}
	return 0;
}

int familyMember::spawnOthers()
{
	Other = new PID[nofOther];
	return 0;
}

int familyMember::spawnOthers(int number_of_others)
{
	nofOther = number_of_others;
	Other = new PID[nofOther];
	return 0;
}

int familyMember::setOthers()
{
	return 0;
}

int familyMember::listOthers()
{
	cout << endl << "Others related to " << myName << ":" << endl;
	for (int i = 0; i < nofOther; i++)
	{
		cout << Other[i] << endl;
	}
	return 0;
}

int familyMember::spawnSons()
{
	Son = new PID[nofSon];
	return 0;
}

int familyMember::spawnSons(int number_of_sons)
{
	nofSon = number_of_sons;
	Son = new PID[nofSon];
	return 0;
}

int familyMember::setSons()
{

	return 0;
}

int familyMember::listSons()
{
	cout << endl << "Sons of " << myName << ":" << endl;
	for (int i = 0; i < nofSon; i++)
	{
		cout << Son[i] << endl;
	}
	return 0;
}

int familyMember::spawnDaughters()
{
	Daughter = new PID[nofDaughter];
	return 0;
}

int familyMember::spawnDaughters(int number_of_daughters)
{
	nofDaughter = number_of_daughters;
	Daughter = new PID[nofDaughter];
	return 0;
}

int familyMember::setDaughters()
{
	return 0;
}

int familyMember::listDaughters()
{
	cout << endl << "Daughters of " << myName << ":" << endl;
	for (int i = 0; i < nofDaughter; i++)
	{
		cout << Daughter[i] << endl;
	}
	return 0;
}

int familyMember::setFather()
{
	return 0;
}

int familyMember::setMother()
{
	return 0;
}

int familyMember::setWife()
{
	return 0;
}

int familyMember::setHusband()
{
	return 0;
}

int familyMember::saveMember(ofstream *fout)
{
	(*fout).write("\0", 1);
	(*fout).write((char*) (&myPID), sizeof(PID));
	(*fout).write("\0", 1);
	(*fout).write((char*) &myName, sizeof(string));
	(*fout).write("\0", 1);
	(*fout).write((char*) &RealDOB, sizeof(DOB));
	(*fout).write("\0", 1);
	int gender = 0;
	if (male)
		gender = 1;
	else if (female)
		gender = 2;
	(*fout).write((char*)&gender, sizeof(int));
	(*fout).write("\0", 1);
	(*fout).write((char*)&Father, sizeof(PID));
	(*fout).write("\0", 1);
	(*fout).write((char*)&Mother, sizeof(PID));
	(*fout).write("\0", 1);
	(*fout).write((char*)&Husband, sizeof(PID));
	(*fout).write("\0", 1);
	(*fout).write((char*)&Wife, sizeof(PID));
	(*fout).write("\0", 1);

	(*fout).write((char*)&nofSister, sizeof(int));
	(*fout).write("\0", 1);
	for (int i = 0; i < nofSister; i++)
	{
		(*fout).write((char*)&Sister[i], sizeof(PID));
		(*fout).write("\0", 1);
	}

	(*fout).write((char*)&nofBrother, sizeof(int));
	(*fout).write("\0", 1);
	for (int i = 0; i < nofBrother; i++)
	{
		(*fout).write((char*)&Brother[i], sizeof(PID));
		(*fout).write("\0", 1);
	}

	(*fout).write((char*)&nofOther, sizeof(int));
	(*fout).write("\0", 1);
	for (int i = 0; i < nofOther; i++)
	{
		(*fout).write((char*)&Other[i], sizeof(PID));
		(*fout).write("\0", 1);
	}

	(*fout).write((char*)&nofSon, sizeof(int));
	(*fout).write("\0", 1);
	for (int i = 0; i < nofSon; i++)
	{
		(*fout).write((char*)&Son[i], sizeof(PID));
		(*fout).write("\0", 1);
	}

	(*fout).write((char*)&nofDaughter, sizeof(int));
	(*fout).write("\0", 1);
	for (int i = 0; i < nofDaughter; i++)
	{
		(*fout).write((char*)&Daughter[i], sizeof(PID));
		(*fout).write("\0", 1);
	}
	(*fout).write("\n", sizeof("\n"));

	return 0;
}
