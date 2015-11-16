/*---------------------------------------------------------
Date: 12th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Plugboard Class
Includes:	constructor
					destructor (blank)
					output
---------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "plugboard.h"

using namespace std;

Plugboard::Plugboard(char* filename)
{
	ifstream in;
	int a;
	
	in.open(filename);
	if (!in)
	{
		cout << "Plugboard file could not be opened" << endl;
		exit(1);
	}

	in >> a;
	size = 0;

	while (!in.eof())
	{
		if (a < 0 || a > 25)
		{
			//INVALID_INDEX
			cout << "II" << endl;
		}
		
		//If a is not numeric character
		//if a < 10 (direct ACSII char comp)
		//If a > 10 
		//NON_NUMERIC_CHARACTER
		
		if (size > 0)
		{
			for (int i = 0; i < size; i++) 
			{
				if (a == plugboard_map[i])
				{
					//IMPOSSIBLE_PLUGBOARD_CONFIGURATION
					cout << "IPG" << endl;
				}
			}
		}
		
		plugboard_map[size] = a;
		size++;
		in >> a;
	}
	for (int i = 0; i <= size; i++)
		cout << plugboard_map[i] << endl;
	
	while (size < MAX_SIZE) {
		plugboard_map[size] = -1;
		size++;
	}
	in.close();
}

Plugboard::~Plugboard()
{
	//Blank
}

int Plugboard::output(int a)
{
	int i;
	for (i = 0; i < MAX_SIZE; i++)
	{
		if (plugboard_map[i] == a)
		{
			if ( (i % 2) == 0 )
			{
				return plugboard_map[i+1];
			}
			else
			{
				return plugboard_map[i-1];  
			}
		}
	}
	return a; 
}
