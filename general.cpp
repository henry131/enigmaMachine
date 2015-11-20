/*---------------------------------------------------------
Date: 12th November 2015
Author: Henry Williams, hw5115, 01141713
Description: General fucntions for entire program
---------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include "general.h"

using namespace std;

bool checkPbFileName (const char* filename)
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

bool checkRefFileName (const char* filename)
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

bool checkRotFileName (const char* filename)
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

bool checkRotPosFileName (const char* filename)
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
	return i + (int) 'A';
}

int charToInt (char c)
{
	return (c - 'A');
}

void intro_message ()
{
	cout << endl;
	cout << "This is a program to simulate the encryption of the " << endl;
	cout << "enigma machine. You should have passed in the command " << endl;
	cout << "line the requisite files to configure the machine" << endl;
	cout << "Please enter the text to encrypt in capital letters:" << endl;
	cout << endl;
}



