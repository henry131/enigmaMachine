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
#include "errors.h"

using namespace std;

Plugboard::Plugboard(char* filename)
{
	//Set error_code to no error status and input_size to 0
	error_code = 0;
	input_size = 0;
	
	//Open .pb file passed in command line
	ifstream in;
	in.open(filename);
	if (!in)
	{
		cerr << "Unable to open Plugboard configuration file" << endl;
		error_code = ERROR_OPENING_CONFIGURATION_FILE;
		return;
	}
	
	//Take first input from file into variable a
	int a;
	in >> a;
	
	//Cycle through file putting input into plugboard_map array
	while (!in.eof())
	{
		if (a < 0 || a > 25)
		{
			cerr << filename << " contains number that is not between 0 & 25";
			cerr << endl;
			error_code = INVALID_INDEX;
			in.close();
			return;
		}
		
		//If a is not numeric character
		//if a < 10 (direct ACSII char comp)
		//If a > 10 
		//error_code = NON_NUMERIC_CHARACTER;
		//in.close();
		//return;
		
		if (input_size > 0)
		{
			for (int i = 0; i < input_size; i++) 
			{
				if (a == plugboard_map[i])
				{
					cerr << filename << " attempted to pair contact with already";
					cerr << "inputted contact in Plugboard" << endl;
					error_code = IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
					in.close();
					return;
				}
			}
		}
		
		plugboard_map[input_size] = a;
		input_size++;
		in >> a;
	}
	
	in.close();
	
	if (input_size % 2 != 0)
	{
		cerr << filename << " contains an odd number of numbers" << endl;
		error_code = INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
		return;
	}
	
	//Input -1 to rest of array to ensure no effect on encryption
	while (input_size < MAX_SIZE) 
	{
		plugboard_map[input_size] = -1;
		input_size++;
	}	
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

int Plugboard::get_error_code()
{
	return error_code;
}

void Plugboard::print()
{
	cout << "Printing plugboard configuration:" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << i << " -> " << output(i) << endl;
	}
	
}
