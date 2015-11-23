/*-------------------------------------------------------------------
Program Title: enigma
Course: C++ Programming - Assessed Exercise No.2
Deadline: 23rd November 2015

Date: 12th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Main function
-------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <cctype>
#include "errors.h"
#include "general.h"
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

using namespace std;


/*************************Main Function*****************************/


int main(int argc, char** argv)
{

	//Initialise error variable to be returned by main
	int error = 0;
	
	// List command line parameters (debugging only)
	if (debug)
	{
		cout << endl << "/********Program Start********/" << endl;
		cout << "Number of arguments to main: " << argc << endl;
		for (int i = 0; i < argc; i++)
		{
			cout << argv[i] << endl;
		}
	}
	
	//Check if sufficient commnand line parameters have been passed
	//3 (./enigma pb rf) or 5+ parameters can be passed but not 4 
	
	if ( argc < 3 || argc == 4 )
	{
		cerr << "usage: enigma plugboard-file reflector-file";
		cerr << " (<rotor-file>* rotor-positions)?"<< endl;
		return INSUFFICIENT_NUMBER_OF_PARAMETERS;
	}
	
	// Get plugboard config (second arg)
	
	Plugboard plugboard;
	
	if ( checkPbFileName (argv[1]) )
	{
		error = plugboard.configure(argv[1]);
		if (error != 0)
		{
			return error;
		}
		
		if (debug)
		{
			cout << endl;
			plugboard.print();
		}
	}
	else
	{
		cerr << "Plugboard: Error Opening Configuration File" << endl;
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	
	//Get reflector config (third arg)
	
	Reflector reflector;
	
	if ( checkRefFileName (argv[2]) )
	{
		error = reflector.configure(argv[2]);
		if (error != 0)
		{
			return error;
		}
		if (debug)
		{
			cout << endl;
			reflector.print();
		}
	}
	else
	{
		cerr << "Reflector: Error Opening Configuration File" << endl;
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	
	//Get rotors config (not first three or last arg)
	
	int index = 3;
	int rotor_count = 0;
	
	Rotor* rotors;
	
	if (argc > index)
	{
		//Check rotor positioning file not passed without rotors
		if ( checkRotPosFileName(argv[3]) )
		{
			cerr << "Insufficient Number Of Parameters Error" << endl;
			return INSUFFICIENT_NUMBER_OF_PARAMETERS;
		}
		
		rotor_count = argc - index - 1;
		rotors = new Rotor[rotor_count];
	
		if (debug)
		{
			cout << endl << rotor_count << " rotor(s) to be added" << endl;
		}
		
		for (int i = rotor_count - 1; i >= 0; i--)
		{	
			if ( checkRotFileName (argv[index]) )
			{
				error = rotors[i].configure(argv[index]);
				if (error != 0)
				{
					return error;
				}
				
				if (debug)
				{
					cout << endl;
					cout << "**Printing Rotor " << i+1 << " ("<< argv[index] << ")**";
					cout << endl << endl;
					rotors[i].print();
					cout << endl;
				}
				
				index++;
			}
			else
			{
				cerr << "Rotor: Error Opening Configuration File" << endl;
				return ERROR_OPENING_CONFIGURATION_FILE;
			}
		}
	
	//Get rotors positioning (last arg)
	
	if ( checkRotPosFileName (argv[rotor_count + 3]) )
		{	
			error = rotor_positioning(argv[rotor_count + 3], rotor_count, rotors);
			if (error != 0)
			{
				return error;
			}
		}
		else
		{
			cerr << "Rotor Pos: Error Opening Configuration File" << endl;
			return ERROR_OPENING_CONFIGURATION_FILE;
		}
	}
	else
	{
		if (debug)
		{
			cout << "No rotor files added" << endl;
		}
	}
	
	//Encryption input and output:
	
	char character;
	
	if (debug)
	{
		intro_message();
	}
	
	while (cin)
	{
			character = cin.get();
			if ( isspace(character) )
			{
				cin >> ws;
			}
			if ( islower(character) || isdigit(character) || ispunct(character) )
			{
				cerr << endl;
				cerr << character << " is not a valid input character ";
				cerr << "(input characters must be upper case letters (A-Z)!" << endl;
				return INVALID_INPUT_CHARACTER;
			}
			if (isupper(character))
			{
					cout << encrypt(character,rotor_count,rotors,plugboard,reflector);
			}
	}

	//Free memory if rotors used
	
	if (argc > 4)
	{
		delete [] rotors;
	}
	
	return 0;
}

 

