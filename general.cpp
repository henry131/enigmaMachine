/*---------------------------------------------------------
Date: 12th November 2015
Author: Henry Williams, hw5115, 01141713
Description: General fucntions for entire program
Includes:	check valid input file names
					char to int and int to char
					encrypt function
---------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include "general.h"

using namespace std;

bool checkPbFileName (char* filename)
{
	int length = strlen(filename);
	if (filename[length - 3]!='.')
		return false;
	if (filename[length - 2]!='p')
		return false;
	if (filename[length - 1]!='b')
		return false;
	return true;
}

bool checkRefFileName (char* filename)
{
	int length = strlen(filename);
	if (filename[length - 3]!='.')
		return false;
	if (filename[length - 2]!='r')
		return false;
	if (filename[length - 1]!='f')
		return false;
	return true;
}

bool checkRotFileName (char* filename)
{
	int length = strlen(filename);
	if (filename[length - 4]!='.')
		return false;
	if (filename[length - 3]!='r')
		return false;
	if (filename[length - 2]!='o')
		return false;
	if (filename[length - 1]!='t')
		return false;
	return true;
}

bool checkRotPosFileName (char* filename)
{
	int length = strlen(filename);
	if (filename[length - 4]!='.')
		return false;
	if (filename[length - 3]!='p')
		return false;
	if (filename[length - 2]!='o')
		return false;
	if (filename[length - 1]!='s')
		return false;
	return true;
}

char intToChar (int i)
{
	if (i < 0 || i > 25)
		return '?';
	return i + (int) 'A';
}

int charToInt (char c)
{
	if (c < 'A' || c > 'Z')
		return -1;
	return (c - 'A');
}



