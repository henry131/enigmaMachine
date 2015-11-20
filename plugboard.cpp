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

Plugboard::Plugboard()
{
	input_size = 0;
}

int Plugboard::configure(const char* filename)
{
	//Open .pb file passed in command line
	ifstream in;
	in.open(filename);
	if (!in)
	{
		cerr << "Plugboard: Error Opening Configuration File" << endl;
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	
	//Take first input from file into variable a
	int a;
	in >> a;
	
	//Cycle through file putting input into plugboard_map array
	while (!in.eof())
	{
		if (input_size >= MAX_SIZE)
		{
			cerr << "Incorrect number of parameters in plugboard file";
			cerr << "plugboard.pb" << endl;
			return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
		}
		
		if ((in.peek()<48||in.peek()>59) && !isspace(in.peek()))
		{
			cerr << "Non-numeric character in plugboard file plugboard.pb" << endl;
			return NON_NUMERIC_CHARACTER;
		}
		
		if (a < 0 || a > 25)
		{
			cerr << "Plugboard: Invalid Index Error" << endl;;
			return INVALID_INDEX;
		}

		for (int i = 0; i < input_size; i++) 
		{
			if (a == plugboard_map[i])
			{
				cerr << "Impossible Plugboard Configuration Error" << endl;
				return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
			}
		}
		
		plugboard_map[input_size] = a;
		input_size++;
		in >> a;
	}
	
	in.close();
	
	if (input_size % 2 != 0)
	{
		cerr << "Incorrect number of parameters in plugboard file";
		cerr << "plugboard.pb" << endl;
		return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
	}
	
	//Input -1 to rest of array to ensure no effect on encryption
	while (input_size < MAX_SIZE) 
	{
		plugboard_map[input_size] = -1;
		input_size++;
	}
	return 0;
}

int Plugboard::output(const int& a)
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

void Plugboard::print()
{
	cout << "Printing plugboard configuration:" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << i << " -> " << output(i) << endl;
	}
	
}
