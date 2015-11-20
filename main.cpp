/*---------------------------------------------------------
Program Title: enigma
Course: C++ Programming - Assessed Exercise No.2
Deadline: 23rd November 2015

Date: 12th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Main function
---------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "errors.h"
#include "general.h"
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

using namespace std;

Plugboard* plugboard;
Reflector* reflector;
Rotor* rotors[26];

// Debug triggers
const bool debug = false;

/*********************Function declarations**************************/

//Sets starting position of rotors
int rotor_positioning(const char* filename, const int& rotor_count);

//Function to go through steps of engima machine
//c is an upper case character to be encoded
//rotor_count is number of valid rotor files passed in command line
char encrypt (char c, const int& rotor_count);

//rotates rotors once(B postion moving to A position)
//count is the number of created rotors
void rotate_rotors(const int& count);

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
	
	// Check if sufficient commnand line parameters have been passed
	
	if (argc < 3)
	{
		cerr << "usage: enigma plugboard-file reflector-file";
		cerr << "(<rotor-file>* rotor-positions)?"<< endl;
		return INSUFFICIENT_NUMBER_OF_PARAMETERS;
	}
	
	// Get plugboard config (second arg)
	
	if (checkPbFileName (argv[1]))
	{
		plugboard = new Plugboard ();
		error = plugboard->configure(argv[1]);
		if (error != 0)
		{
			return error;
		}
		
		if (debug)
		{
			cout << endl;
			plugboard->print();
		}
	}
	else
	{
		cerr << "Plugboard: Error Opening Configuration File" << endl;
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	
	//Get reflector config (third arg)
	
	if (checkRefFileName (argv[2]))
	{
		reflector = new Reflector ();
		error = reflector->configure(argv[2]);
		if (error != 0)
		{
			return error;
		}
		if (debug)
		{
			cout << endl;
			reflector->print();
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
	

	
	if (argc > index)
	{
	
		//Check rotor positioning file not passed without rotors
		if (checkRotPosFileName(argv[3]))
		{
			cerr << "Insufficient Number Of Parameters Error" << endl;
			return INSUFFICIENT_NUMBER_OF_PARAMETERS;
		}
		
			rotor_count = argc - index - 1;
	
		if (debug)
		{
			cout << endl << rotor_count << " rotor(s) added" << endl;
		}
		for (int i = rotor_count - 1; i >= 0; i--)
		{	
			if (checkRotFileName (argv[index]))
			{
				rotors[i] = new Rotor();
				error = rotors[i]->configure(argv[index]);
				if (error != 0)
				{
					return error;
				}
				if (debug)
				{
					cout << endl;
					cout << "/*Printing Rotor " << i+1 << " ("<< argv[index] << ")*/";
					cout << endl << endl;
					rotors[i]->print();
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
	
		if (checkRotPosFileName (argv[argc-1]))
		{	
			error = rotor_positioning(argv[argc-1], rotor_count);
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
			if (isspace(character))
			{
				cin >> ws;
			}
			if (islower(character)||isdigit(character)||ispunct(character))
			{
				cerr << "Invalid Input Character: lower case" << endl;
				return INVALID_INPUT_CHARACTER;
			}
			if (isupper(character))
			{
				cout << encrypt(character, rotor_count);
			}
	}
	cout << endl;

	//Free memory
	delete plugboard;
	delete reflector;
	for (int i = 0; i < 26; i++)
	{
		delete rotors[i];
	}
	
	return 0;
}

/*KEY FUNCTIONS*/

int rotor_positioning (const char* filename, const int& rotor_count)
{
	ifstream in;
	in.open(filename);
	if (!in)
	{
		cerr << "Rotor Pos: Error Opening Configuration File" << endl;      
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	int position = 0;
	for (int i = rotor_count - 1; i >= 0; i--)
	{
		if (in.eof())
		{
			cerr << "No Rotor Starting Position Error" << endl;
			return NO_ROTOR_STARTING_POSITION;
		}
		
		if ((in.peek()<48||in.peek()>59) && !isspace(in.peek()))
		{
			cerr << "Non-numeric character in rotor positions file rotor.pos";
			cerr << endl;
			in.close();
			return NON_NUMERIC_CHARACTER;
		}
		
		in >> position;
		
		if (position < 0 || position > 25)
		{
			cerr << "Position: Invalid Index Error" << endl;;
			in.close();
			return INVALID_INDEX;
		}
					
		//invlaid index, non numeric character etc.
		rotors[i]->input_start_position(position);
		rotors[i]->set_start_position();
		if (debug)
		{
			cout << endl;
			cout << "Rotor " << i + 1 << " starting position: " << position << endl;
			cout << "/*Reprint after starting position adjustment*/" << endl;
			cout << endl;
			rotors[i]->print();
			cout << endl;
		}
	}
	in.close();
	return 0;
}

char encrypt (char c, const int& rotor_count)
{
	int a = charToInt(c);
	
	//Rotate rotors before each character
	rotate_rotors(rotor_count);
	
	if (debug)
	{
		cout << endl << endl << "Encrypting " << intToChar(a) << endl;
	}
	
	//Through Plugboard
	a = plugboard->output(a);
	if (debug)
	{
		cout << "Through plugboard: " << intToChar(a) << endl;
	}
	
	//Through rotors forward
	for (int i = 0; i < rotor_count; i++)
	{
		rotors[i]->set_fwd_encode();
		a = rotors[i]->output(a);
		if (debug)
		{
			cout << "Through rotor " << i << ": " << intToChar(a) << endl;
		}
	}
	
	//Through reflector
	a = reflector->output(a);
	if (debug)
	{
		cout << "Through reflector: " << intToChar(a) << endl;
	}
	
	//Through rotors backwards
	for (int i = rotor_count - 1; i >=0; i--)
	{
		rotors[i]->set_bck_encode();
		a = rotors[i]->output(a);
		if (debug)
		{
			cout << "Back through rotor " << i << ": " << intToChar(a) << endl;
		}
	}
	
	//Through plugboard again
	a = plugboard->output(a);
	if (debug)
	{
		cout << "Back through plugboard: " << intToChar(a) << endl;
	}
	
	if (debug)
	{
		cout << "Final output is : ";
	}

	return intToChar(a);
}

void rotate_rotors (const int& count)
{
	if (count <= 0)
	{
		return;
	}
	
	rotors[0]->rotate();
	
	for (int i = 0; i < count; i++)
	{
		if (rotors[i]->notch_triggered())
		{
			if (i+1 < count)
			{
				rotors[i+1]->rotate();
			}
		}
	}
}



 

