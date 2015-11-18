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
bool debug = true;

//Sets starting position of rotors
int rotor_positioning(const char* filename, const 
int rotor_count);

/*
	Function to go through steps of engima machine
	c is an upper case character to be encoded
	rotor_count is number of valid rotor files passed in command line
*/
char encrypt (char c, int rotor_count);

/*
	rotates rotors once(B postion moving to A position)
	count is the number of created rotors
*/
void rotate_rotors(int count);

int main(int argc, char** argv)
{
	// List command line parameters (debugging only)
	
	if (debug)
	{
		cout << "Number of arguments to main: " << argc << endl;
		for (int i = 0; i < argc; i++)
		{
			cout << argv[i] << endl;
		}
	}
	
	// Check if sufficient commnand line parameters have been passed
	
	if (argc < 3)
	{
		cerr << "Run program passing 1 plugboard, 1 reflector,";
		cerr << "0 to 26 rotor and 0 to 1 rotor positioning file(s)" << endl;
		return INSUFFICIENT_NUMBER_OF_PARAMETERS;
	}
	
	// Get plugboard config (second arg)
	
	if (checkPbFileName (argv[1]))
	{
		plugboard = new Plugboard (argv[1]);
		if (debug)
		{
			cout << endl;
			plugboard->print();
		}
	}
	else
	{
		cerr << "Pass a '.pb' file as the second argument" << endl;
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	
	//Get reflector config (third arg)
	
	if (checkRefFileName (argv[2]))
	{
		reflector = new Reflector (argv[2]);
		if (debug)
		{
			cout << endl;
			reflector->print();
		}
	}
	else
	{
		cerr << "Pass a '.rf' file as the third argument" << endl;
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	
	//Get rotors config (not first three or last arg)
	int index = 3;
	int rotor_count = argc - index - 1;
	if (debug)
	{
		cout << endl << rotor_count << " rotor(s) added" << endl;
	}
	for (int i = rotor_count - 1; i >= 0; i--)
	{	
		if (checkRotFileName (argv[index]))
		{
			rotors[i] = new Rotor(argv[index]);
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
			cerr << "Pass '.rot' files for the rotors" << endl;
			return ERROR_OPENING_CONFIGURATION_FILE;
		}
	}
	
	//Get rotors positioning (last arg)

	if (checkRotPosFileName (argv[argc-1]))
	{	
		int rot_pos_error = rotor_positioning(argv[argc-1], rotor_count);
		if (rot_pos_error != 0)
		{
			return ERROR_OPENING_CONFIGURATION_FILE;
		}
	}
	else
	{
		cerr << "If you pass any rotor files then you must also pass a rotor";
		cerr << "position file : pass a '.pos' file as the last argument" << endl;
		return ERROR_OPENING_CONFIGURATION_FILE;
	}

	//Encryption input and output: REDO!
	char character;
	char answer = 'y';
	while (answer == 'y')
	{
		cout << "Enter message to be encrypted in capital letters:" << endl;
		cout << "Enter '0' to break input" << endl;
		while (cin)
		{
			character = cin.get();
			if (character == '0')
				break;
			if (isspace(character))
			{
				cout << character;
			}
			if (isupper(character))
			{
				cout << encrypt(character, rotor_count);
			}
		}
		cout << "would you like to repeat (y/n?)";
		cin >> answer;
		for (int i = rotor_count - 1; i >= 0; i--)
		{
			rotors[i]->reset_position();
			rotors[i]->set_start_position();
		}
	}
	cout << endl;
	return 0;
}

int rotor_positioning(const char* filename, const int rotor_count)
{
	ifstream in;
	in.open(filename);
	if (!in)
	{
		cerr << "Rotor positioning file " << filename << " failed to open" << endl;      
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	int position = 0;
	for (int i = rotor_count - 1; i >= 0; i--)
	{
		in >> position;
					
		//invlaid index, non numeric character etc.
		rotors[i]->get_start_position(position);
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

char encrypt (char c, int rotor_count) {

	int a = charToInt(c);
	
	//Rotate rotors before each character
	rotate_rotors(rotor_count);
	
	if (debug)
	{
		cout << endl << "Encrypting " << intToChar(a) << endl;
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

void rotate_rotors(int count)
{
	rotors[0]->rotate();
	for (int i = 0; i < count; i++)
	{
		if (rotors[i]->latch_triggered())
		{
			if (i+1 < count)
			{
				rotors[i+1]->rotate();
			}
		}
	}
}



 

