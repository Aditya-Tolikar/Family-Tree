/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Copyright (NR) 'Electrocution Strauss' of ECE - 1 2015-2019/20 Thapar Institute of Engineering and Technology, Patiala////
///May be distributed as far as the credit of the code and any derivatives is given to the programmers///////////////////////
///Denying credit of this code to the makers of this code will be considered a criminal and personal offence/////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "treeclass.h"
#include "MAP.h"
typedef int PID;


int load_file(std::string,  struct map_entry*);
int save_file(std::string,  struct map_entry*, int);