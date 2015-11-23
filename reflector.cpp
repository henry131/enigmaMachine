/*---------------------------------------------------------
Date: 12th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Reflector Class
Includes:	constructor
					destructor (blank)
					output
---------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "reflector.h"
#include "errors.h"

using namespace std;

Reflector::Reflector ()
{
//blank
}

int Reflector::configure (const char* filename)
{
	ifstream in;
	int a;
	int input_size = 0;
	
	in.open(filename);
	if (!in)
	{
		cerr << "Reflector: Error Opening Configuration File" << endl;
		return ERROR_OPENING_CONFIGURATION_FILE;
	}

	in >> a;

	while (!in.eof())
	{	
		if (input_size >= MAX_SIZE)
		{
			cerr << "Incorrect (odd) number of parameters in reflector file";
			cerr << " reflector.rf" << endl;
			return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
		}
		
		if ((in.peek()<48||in.peek()>59) && !isspace(in.peek()))
		{
			cerr << "Non-numeric character in reflector file reflector.rf" << endl;
			return NON_NUMERIC_CHARACTER;
		}
		
		if (a < 0 || a > 25)
		{
			cerr << "Reflector: Invalid Index Error" << endl;
			return INVALID_INDEX;
		}
		
		for (int i = 0; i < input_size; i++) 
		{
			if (a == reflector_map[i])
			{
				cerr << "Invalid Reflector Mapping" << endl;
				return INVALID_REFLECTOR_MAPPING;
			}
		}
		
		reflector_map[input_size] = a;
		input_size++;
		in >> a;
	}
	in.close();

	if (input_size != MAX_SIZE)
	{
		cerr << "Insufficient number of mappings in reflector file: reflector.rf";
		cerr << endl;
		return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
	}
	return 0;
}

int Reflector::output (const int& a)
{
	int i;
	for (i = 0; i < MAX_SIZE; i++)
	{
		if (reflector_map[i] == a)
		{
			if ( (i % 2) == 0 )
			{
				return reflector_map[i+1];
			}
			else
			{
				return reflector_map[i-1];  
			}
		}
	}
	cout << "Error in  reflector pairs" << endl;
	return a; 
}

void Reflector::print ()
{
	cout << "Printing reflector configuration:" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << i << " -> " << output(i) << endl;
	}
	
}
