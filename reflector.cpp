/*---------------------------------------------------------
Last Edited: 23rd November 2015
Author: Henry Williams, hw5115, 01141713
Description: Reflector Class
---------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "reflector.h"
#include "errors.h"

using namespace std;

//Constructor

Reflector::Reflector ()
{
	// intentionally blank
}

//Configures the reflector mapping from input of filename
//Will return relevant errors so that they can be returned from main

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

	//Cycle through file putting input into reflector_map array
	while ( !in.eof() )
	{	
		if ( input_size >= SIZE )
		{
			cerr << "Too many parameters in reflector file: ";
			cerr << "reflector.rf" << endl;
			return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
		}
		
		if ( (in.peek() < 48 || in.peek() > 59) && !isspace(in.peek()) )
		{
			cerr << "Non-numeric character in reflector file: reflector.rf" << endl;
			return NON_NUMERIC_CHARACTER;
		}
		
		if ( a < 0 || a > 25 )
		{
			cerr << "Reflector: Invalid Index Error" << endl;
			return INVALID_INDEX;
		}
		
		for (int i = 0; i < input_size; i++) 
		{
			if ( a == reflector_map[i] )
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

	if ( input_size != SIZE )
	{	
		if (input_size % 2 != 0)
		{
			cerr << "Incorrect (odd) number of parameters in reflector file: ";
			cerr << "reflector.rf";
		}
		else
		{
			cerr << "Insufficient number of mappings in reflector file: ";
			cerr << "reflector.rf";
		}
		return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
	}
	
	return NO_ERROR;
}

//Returns what int a maps to based on configuration contained in 
//reflector_map. int a must be within enigma range (0-25 : A-Z)

int Reflector::output (const int& a)
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		if ( reflector_map[i] == a )
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
	
	//If reaches here then reflector mapping not correct
	cout << "!!!! Error in  reflector pairs !!!!" << endl;
	return a; 
}

//Prints mapping of reflector_map to standard output stream (debugging)

void Reflector::print ()
{
	cout << "Printing reflector configuration:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << " -> " << output(i) << endl;
	}
	
}
