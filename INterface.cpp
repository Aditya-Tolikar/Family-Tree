/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Copyright (NR) 'Electrocution Strauss' of ECE - 1 2015-2019/20 Thapar Institute of Engineering and Technology, Patiala////
///May be distributed as far as the credit of the code and any derivatives is given to the programmers///////////////////////
///Denying credit of this code to the makers of this code will be considered a criminal and personal offence/////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#include"Header.h"
#include<iostream>
using namespace std;



int main()
{
	cout << "______________________________________________________________________________________________" << endl;
	cout << "|////////////////////////////////////////////////////////////////////////////////////////////|" << endl;
	cout << "|//////////Project made by group 'Electrocution Strauss' of ECE - 1 2015-2019/20/////////////|" << endl;
	cout << "|//////////////////Thapar Institute of Engineering and Technology, Patiala///////////////////|" << endl;
	cout << "|//////////////        Project title : Family Tree storage application        ///////////////|" << endl;
	cout << "|///////////////////Submitted to: Ms. Diksha Hooda [LAB Teacher UCS 613]/////////////////////|" << endl;
	cout << "|//Made by:                                             /////////////////////////////////////|" << endl;
	cout << "|////////////Aditya Tolikar  (401506003)                /////////////////////////////////////|" << endl;
	cout << "|////////////Aashima Gautam  (101506001)                /////////////////////////////////////|" << endl;
	cout << "|////////////Akashdeep Kaur  (101506017)                /////////////////////////////////////|" << endl;
	cout << "|////////////Gaurav Wadhwa   (101686002)                /////////////////////////////////////|" << endl;
	cout << "|////////////Vincy Sharma    (101686015)                /////////////////////////////////////|" << endl;
	cout << "|////////////////////////////////////////////////////////////////////////////////////////////|" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl << endl << endl;

	familyMember *a = nullptr;
	map_entry *map = nullptr;
	int FamilySize = NULL;
	int choice1 = NULL;
	while (choice1 != 101)
	{
		cout << "What would you like to do?" << endl;
		cout << "0. Load File\n 1. Create new member \n 11. Set number of ppl in family\n 12. Map member PID\n 2. Select member \n 3. Set number of relatives [for Sisters, Brothers, Sons, Daughters, Others] \n 4. Link to father,mother,wife,husband 5. Link to Sister, Brother, Son, Daughter\n 7. Map out\n 8.Select Relative\n 9. List all my relatives\n 100. Save\n 101. Exit without saving" << endl;
		cin >> choice1;

		if (choice1 == 0)
		{
			string filename;
			cout << "Please enter filename" << endl;
			cin >> filename;
			FamilySize = load_file(filename, map);
		}

		else if (choice1 == 1)//Make new person
		{
			cout << "Currently selected member will be lost if not saved to map" << endl;
			string name;
			int gender;
			DOB dob;
			cout << "Enter name\t" << endl;
			cin >> name;
			cout << "Gender: 0 to leave it for later, 1 for Male, 2. for Female" << endl;
			cin >> gender;
			cout << "DOB:\nDate:\t";
			cin >> dob.date;
			cout << "Month number:\t";
			cin >> dob.month;
			cout << "Year:\t";
			cin >> dob.year;

			a = new familyMember(name, gender, dob);

			if (map != nullptr)
			{
				int i;
				for (i = 0; i < FamilySize && map[i].memPID != 0; i++);
				//map[i].memPID = a->myPID;
				if (i != FamilySize)
				{
					map[i].entry_alloc(a);
					cout << "PID saved to map." << a->myPID << endl;
				}
			}
		}
		else if (choice1 == 12)//Save person to map
		{
			if (a == nullptr)
			{
				cout << "No person selected" << endl;
			}
			else if (map != nullptr)
			{
				int i;
				for (i = 0; i < FamilySize && map[i].memPID != 0; i++);
				//map[i].memPID = a->myPID;
				map[i].entry_alloc(a);
				cout << "PID saved to map." << endl;
			}
			else if (map == nullptr)
			{
				cout << "Map does not exist" << endl;
			}
		}
		else if (choice1 == 3)//Set number of people in array;
		{
			int type, number;
			cout << " Which type of relative? \t 1.Sisters; 2.Brothers; 3.Daughters; 4.Sons; 5.Others" << endl;
			cin >> type;
			cout << "How many ?\t";
			cin >> number;
			switch (type)
			{
			case 1:
				a->spawnSisters(number);
				break;

			case 2:
				a->spawnBrothers(number);
				break;

			case 3:
				a->spawnDaughters(number);
				break;

			case 4:
				a->spawnSons(number);
				break;

			case 5:
				a->spawnOthers(number);
				break;

			default:
				cout << "Wrong option" << endl;
				break;
			}
		}
		else if (choice1 == 4)//Connect to father/mother/wife/husband
		{
			int person;
			string name;
			cout << "Relationship of the person\n1.Father 2.Mother 3.Husband 4.Wife" << endl;
			cin >> person;
			cout << "Name of person (as saved)\t";
			cin >> name;
			for (int i = 0; i < FamilySize; i++)
			{
				if (name.compare(map[i].memptr->myName) == 0)
				{
					switch (person)
					{
					case 1:
						a->Father = map[i].memPID;
						break;
					case 2:
						a->Mother = map[i].memPID;
						break;
					case 3:
						a->Husband = map[i].memPID;
						break;
					case 4:
						a->Wife = map[i].memPID;
						break;
					}
				}
			}
		}
		else if (choice1 == 5)//Connect to Sister/Brother/Son/Daughter
		{
			int person, no_;
			string name;
			cout << "Relationship of the person\n1.Sister 2.Brother 3.Son 4.Daughter" << endl;
			cin >> person;
			cout << "What number ?\t";
			cin >> no_;
			cout << "Name of person (as saved)\t";
			cin >> name;
			for (int i = 0; i < FamilySize; i++)
			{
				if (name.compare(map[i].memptr->myName) == 0)
				{
					switch (person)
					{
					case 1:
						a->Sister[no_] = map[i].memPID;
						break;
					case 2:
						//a->Brother[no_] = map[i].memPID;
						a->setBrothers(no_, map[i].memPID);
						break;
					case 3:
						a->Son[no_] = map[i].memPID;
						break;
					case 4:
						a->Daughter[no_] = map[i].memPID;
						break;
					}
					break;
				}
			}

		}
		else if (choice1 == 2)//Change selection
		{
			string name;
			cout << "Enter name of person:\t";
			cin >> name;
			int i;
			for (i = 0; i < FamilySize && map[i].memPID != 0; i++)
			{
				if (name.compare(map[i].memptr->myName) == 0)
				{
					a = map[i].memptr;
					cout << a->myName << endl << endl;
					break;
				}
			}
		}
		else if (choice1 == 7)//Output map
		{
			for (int i = 0; i < FamilySize; i++)
			{
				cout << map[i].memPID << '\t';
				if (map[i].memPID != 0)
					cout << map[i].memptr->myName;
				cout << endl;
			}
		}
		else if (choice1 == 8)//Go to Relative
		{
			int choice2;
			cout << "1.Sister 2.Brother 3. Other 4. Son 5. Daughter 6. Father 7. Mother 8. Wife 9. Husband";
			cin >> choice2;
			if (choice2 < 6)
			{
				int personNo;
				cout << "Which number?" << endl;
				cin >> personNo;
				if (choice2 == 1)
				{
					for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
					{
						a->listSisters();
						if (map[i].memPID == a->Sister[personNo])
						{
							a = map[i].memptr;
							cout << a->myName;
						}
					}
				}
				else if (choice2 == 2)
				{
					a->listBrothers();
					for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
					{
						if (map[i].memPID == a->Brother[personNo])
						{
							a = map[i].memptr;
							cout << a->myName;
						}
					}
				}
				else if (choice2 == 3)
				{
					a->listOthers();
					for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
					{
						if (map[i].memPID == a->Other[personNo])
						{
							a = map[i].memptr;
							cout << a->myName;
						}
					}
				}
				else if (choice2 == 4)
				{
					a->listSons();
					for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
					{
						if (map[i].memPID == a->Son[personNo])
						{
							a = map[i].memptr;
							cout << a->myName;
						}
					}
				}
				else if (choice2 == 3)
				{
					
					for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
					{
						if (map[i].memPID == a->Daughter[personNo])
						{
							a = map[i].memptr;
							cout << a->myName;
						}
					}
				}
			}
			else
			{
				if (choice2 == 7)
				{
					
					for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
					{
						if (map[i].memPID == a->Mother)
						{
							a = map[i].memptr;
							cout << a->myName;
						}
					}
				}
				else if (choice2 == 6)
				{
					
					for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
					{
						if (map[i].memPID == a->Father)
						{
							a = map[i].memptr;
							cout << a->myName;
						}
					}
				}
				else if (choice2 == 8)
				{
					
					for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
					{
						if (map[i].memPID == a->Wife)
						{
							a = map[i].memptr;
							cout << a->myName;
						}
					}
				}
				else if (choice2 == 9)
				{
					
					for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
					{
						if (map[i].memPID == a->Husband)
						{
							a = map[i].memptr;
							cout << a->myName;
						}
					}
				}

			}

		}
		else if (choice1 == 9)
		{
			a->listBrothers();
			a->listSisters();
			a->listDaughters();
			a->listSons();
			a->listOthers();
			cout << "Father\t" << a->Father << endl << "Mother\t" << a->Mother << endl << "Wife\t" << a->Wife << endl << "Husband\t" << a->Husband << endl;
		}
		else if (choice1 == 10)
		{

		}
		else if (choice1 == 100)
		{
			string filename;
			cout << "Please enter filename" << endl;
			cin >> filename;
			save_file(filename, map, FamilySize);

		}
		else if (choice1 == 11)
		{
			cout << "No. of people:\t";
			cin >> FamilySize;
			map = new map_entry[FamilySize];
			//cout << "Map size\t" << sizeof(&map) << endl;
			cout << "mapped" << endl;
		}
	}
	
	cin.ignore();

	return 0;
}


int load_file(string filename ,map_entry *map)
{
	int FamilySize;
	familyMember *a;
	PID pid = NULL;
	string name;
	PID Father, Mother, *Sister, *Brother, *Other, *Son, *Daughter, Wife, Husband;
	int gender;
	int nofSister, nofBrother, nofOther, nofSon, nofDaughter;
	DOB RealDOB;
	char* nullin = new char;
	ifstream fin(filename, ios::binary);
	fin.read((char*)&FamilySize, sizeof(int));
	fin.read(nullin, 1);
	cout << FamilySize << endl << endl;
	map = new map_entry[FamilySize];
	cout << "Mapped size = " << FamilySize << endl;
	for (int i = 0; i < FamilySize && map + i != nullptr; i++)
	{

		fin.read(nullin, 1);
		fin.read((char*)(&pid), sizeof(PID));
		fin.read(nullin, 1);
		fin.read((char*)&name, sizeof(string));
		fin.read(nullin, 1);
		fin.read((char*)&RealDOB, sizeof(DOB));
		fin.read(nullin, 1);
		
		fin.read((char*)&gender, sizeof(int));
		fin.read(nullin, 1);
		fin.read((char*)&Father, sizeof(PID));
		fin.read(nullin, 1);
		fin.read((char*)&Mother, sizeof(PID));
		fin.read(nullin, 1);
		fin.read((char*)&Husband, sizeof(PID));
		fin.read(nullin, 1);
		fin.read((char*)&Wife, sizeof(PID));
		fin.read(nullin, 1);

		fin.read((char*)&nofSister, sizeof(int));
		fin.read(nullin, 1);
		Sister = new PID[nofSister];
		for (int i = 0; i < nofSister; i++)
		{
			fin.read((char*)&Sister[i], sizeof(PID));
			fin.read(nullin, 1);
		}

		fin.read((char*)&nofBrother, sizeof(int));
		fin.read(nullin, 1);
		Brother = new PID[nofBrother];
		for (int i = 0; i < nofBrother; i++)
		{
			fin.read((char*)&Brother[i], sizeof(PID));
			fin.read(nullin, 1);
		}

		fin.read((char*)&nofOther, sizeof(int));
		fin.read(nullin, 1);
		Other = new PID[nofOther];
		for (int i = 0; i < nofOther; i++)
		{
			fin.read((char*)&Other[i], sizeof(PID));
			fin.read(nullin, 1);
		}

		fin.read((char*)&nofSon, sizeof(int));
		fin.read(nullin, 1);
		Son = new PID[nofSon];
		for (int i = 0; i < nofSon; i++)
		{
			fin.read((char*)&Son[i], sizeof(PID));
			fin.read(nullin, 1);
		}

		fin.read((char*)&nofDaughter, sizeof(int));
		fin.read(nullin, 1);
		Daughter = new PID[nofDaughter];
		for (int i = 0; i < nofDaughter; i++)
		{
			fin.read((char*)&Daughter[i], sizeof(PID));
			fin.read(nullin, 1);
		}
		fin.read(nullin, sizeof("\n"));
		cout << "____________" << endl;
		a = new familyMember(pid, name, RealDOB, gender, nofSister, nofBrother, nofOther, nofSon, nofDaughter, Father, Mother, Wife, Husband, Sister, Brother, Other, Son, Daughter);

		{
			int i;
			for (i = 0; i < FamilySize && map[i].memPID != 0; i++);
			//map[i].memPID = a->myPID;
			if (i != FamilySize)
			{
				map[i].entry_alloc(a);
				cout << "PID saved to map." << a->myPID << endl;
			}
		}
		name.erase();
		delete[] Sister; Sister = nullptr;
		delete[] Brother; Brother = nullptr;
		delete[] Other; Other = nullptr;
		delete[] Son; Son = nullptr;
		delete[] Daughter; Daughter = nullptr;
		a = nullptr;
		
	}

	return FamilySize;
}

int save_file(string filename, map_entry *map, int FamilySize)
{
	ofstream fout(filename, ios::binary);
	fout.write((char*)&FamilySize, sizeof(int));
	fout.write((char*)"\0", 1);
	for (int i = 0; i < FamilySize && map[i].memPID != 0; i++)
	{
		(map[i].memptr)->saveMember(&fout);
		fout.write("\0", 1);
	}
	fout.write((char*)"\0", 1);
	fout.close();
	return 0;
}