/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Copyright (NR) 'Electrocution Strauss' of ECE - 1 2015-2019/20 Thapar Institute of Engineering and Technology, Patiala////
///May be distributed as far as the credit of the code and any derivatives is given to the programmers///////////////////////
///Denying credit of this code to the makers of this code will be considered a criminal and personal offence/////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "MAP.h"
#include <random>


map_entry::map_entry()
{
	memPID = NULL;
	memptr = nullptr;
}

int map_entry::entry_alloc(familyMember *me)
{
	memPID = me->myPID;
	memptr = me;
	return 0;
}


PID gen_rand_PID()
{
	random_device rd;   // non-deterministic generator  
	mt19937 gen(rd());	// to seed mersenne twister.  
						// replace the call to rd() with a  
						// constant value to get repeatable  
						// results.
	return (PID)gen() % 10000;
}

PID gen_rand_PID(map_entry map[])
{
	random_device rd;   // non-deterministic generator  
	mt19937 gen(rd());	// to seed mersenne twister.  
                        // replace the call to rd() with a  
                        // constant value to get repeatable  
                        // results.
	PID tent;
	bool equal = false;
	do {
		tent = (PID)gen() % 1000000;
		for (int i = 0; i < sizeof(map); i++)
		{
			if (map[i].memPID == (PID)0)
			{
				break;
			}
			else if (map[i].memPID == tent)
			{
				equal = true;
			}
		}
	} while (equal);
		return tent;
}