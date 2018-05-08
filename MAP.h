/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Copyright (NR) 'Electrocution Strauss' of ECE - 1 2015-2019/20 Thapar Institute of Engineering and Technology, Patiala////
///May be distributed as far as the credit of the code and any derivatives is given to the programmers///////////////////////
///Denying credit of this code to the makers of this code will be considered a criminal and personal offence/////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once
#include "Header.h"

typedef int PID;

struct map_entry
{
	PID memPID;
	class familyMember * memptr;

	map_entry();
	int entry_alloc(class familyMember *me);
};

PID gen_rand_PID();
PID gen_rand_PID(map_entry map[]);