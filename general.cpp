/*---------------------------------------------------------
Date: 12th November 2015
Author: Henry Williams, hw5115, 01141713
Description: General functions to support main function
---------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "errors.h"
#include "general.h"
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

using namespace std;

//Returns true if filename ends with '.pb'
bool checkPbFileName (const char* filename)
{
	int length = strlen(filename);
	if ( filename[length - 3]!='.' )
		return false;
	if ( filename[length - 2]!='p' )
		return false;
	if ( filename[length - 1]!='b' )
		return false;
	return true;
}

//Returns true if filename ends with '.rf'
bool checkRefFileName (const char* filename)
{
	int length = strlen(filename);
	if ( filename[length - 3]!='.' )
		return false;
	if ( filename[length - 2]!='r' )
		return false;
	if ( filename[length - 1]!='f' )
		return false;
	return true;
}

//Returns true if filename ends with '.rot'
bool checkRotFileName (const char* filename)
{
	int length = strlen(filename);
	if ( filename[length - 4]!='.' )
		return false;
	if ( filename[length - 3]!='r' )
		return false;
	if ( filename[length - 2]!='o' )
		return false;
	if ( filename[length - 1]!='t' )
		return false;
	return true;
}

//Returns true if filename ends with '.pos'
bool checkRotPosFileName (const char* filename)
{
	int length = strlen(filename);
	if ( filename[length - 4]!='.' )
		return false;
	if ( filename[length - 3]!='p' )
		return false;
	if ( filename[length - 2]!='o' )
		return false;
	if ( filename[length - 1]!='s' )
		return false;
	return true;
}

//Converts integer (0-25) to corresonding capitalised character (A-Z)
char intToChar (int i)
{
	return i + (int) 'A';
}

//Converts capitalised character (A-Z) to corresponding integer (0-25)
int charToInt (char c)
{
	return (c - 'A');
}

//Prints introductory message to the standard output stream (debugging)
void intro_message ()
{
	cout << endl;
	cout << "This is a program to simulate the encryption of the " << endl;
	cout << "enigma machine. You should have passed in the command " << endl;
	cout << "line the requisite files to configure the machine" << endl;
	cout << "Please enter the text to encrypt in capital letters:" << endl;
	cout << endl;
}

//Configures the starting position of the rotors in r[] with the input
//from filename. Sets the "position" attribute of each Rotor object.
int rotor_positioning (const char* filename, int rotor_count, Rotor r[])
{
	ifstream in;
	in.open(filename);
	if (in.fail())
	{
		cerr << "Rotor Pos: Error Opening Configuration File" << endl;      
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	
	int position;
	in >> position;
	
	while (!in.eof() && (rotor_count - 1) >= 0)
	{
		//Check for non-numeric input from file
		if ( (in.peek() < 48 || in.peek() > 59) && !isspace(in.peek()) )
		{
			cerr << "Non-numeric character in rotor positions file rotor.pos";
			return NON_NUMERIC_CHARACTER;
		}
		
		//Check for numeric input outside of range (0-25: A-Z) from file
		if ( position < 0 || position > 25 )
		{
			cerr << "Invalid Index Error in rotor positions file rotor.pos";
			cerr << endl;
			return INVALID_INDEX;
		}
		
		//Set initial position of rotors
		r[rotor_count - 1].input_start_position(position);
		r[rotor_count - 1].set_start_position();
		
		if (debug)
		{
			cout << endl;
			cout << "Rotor " << rotor_count + 1 << " starting position: ";
			cout << position << endl;
			cout << "**Reprint after starting position adjustment**" << endl;
			cout << endl;
			r[rotor_count - 1].print();
			cout << endl;
		}
		
		in >> position;
		rotor_count--;
	}
	
	//Check if position has been set for all rotors
	if ( rotor_count != 0 )
	{
		cerr << "Inusfficient Rotor Starting Positions Error" << endl;
		return NO_ROTOR_STARTING_POSITION;
	}
	
	//Check to see if file is corrupted with invalid input past rotor_count
	int overflow = 0;
	while ( !in.eof() )
	{
		overflow++;
		
		if ( (in.peek() < 48 || in.peek() > 59) && !isspace(in.peek()) )
		{
			cerr << "Non-numeric character in rotor positions file rotor.pos";
			cerr << endl;
			return NON_NUMERIC_CHARACTER;
		}
		
		if ( position < 0 || position > 25 )
		{
			cerr << "Invalid Index Error in rotor positions file rotor.pos";
			cerr << endl;
			return INVALID_INDEX;
		}
		
		in >> position;
	}
	
	//Notify user that more valid rotor positions than necessary were input
	if (overflow > 0)
	{
		cerr << "N.B. Attempted to input more rotor positions than ";
		cerr << "rotors configured. Encryption continued ignoring final ";
		cerr << overflow << " rotor positions" << endl;
	}

	in.close();
	
	return NO_ERROR;
}

//Returns encrypted character from inputted character c
//c must be capitalised character (A-Z)
char encrypt (char c, const int& rotor_count, 
							Rotor r[], Plugboard pb, Reflector rf)
{
	int a = charToInt(c);
	
	//Rotate rotors before each character if rotor(s) have been added
	if (rotor_count > 0)
	{
		rotate_rotors(rotor_count, r);
	}
	
	if (debug)
	{
		cout << endl << endl << "Encrypting " << intToChar(a) << endl;
	}
	
	//Through Plugboard
	a = pb.output(a);
	if (debug)
	{
		cout << "Through plugboard: " << intToChar(a) << endl;
	}
	
	//Through rotors forward
	for (int i = 0; i < rotor_count; i++)
	{
		r[i].set_fwd_encode();
		a = r[i].output(a);
		if (debug)
		{
			cout << "Through rotor " << i << ": " << intToChar(a) << endl;
		}
	}
	
	//Through reflector
	a = rf.output(a);
	if (debug)
	{
		cout << "Through reflector: " << intToChar(a) << endl;
	}
	
	//Through rotors backwards
	for (int i = rotor_count - 1; i >=0; i--)
	{
		r[i].set_bck_encode();
		a = r[i].output(a);
		if (debug)
		{
			cout << "Back through rotor " << i << ": " << intToChar(a) << endl;
		}
	}
	
	//Through plugboard again
	a = pb.output(a);
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

//Rotates the rotors in r []
//The first rotor will always rotate but all subsequent rotors will only
//rotate when the prior rotor triggers its notch
void rotate_rotors (const int& count, Rotor r[])
{
	if (count <= 0)
	{
		return;
	}
	
	r[0].rotate();
	
	//Check if notch triggered - rotate next rotor
	
	for (int i = 0; i < count; i++)
	{
		if (r[i].notch_triggered())
		{
			//Check if further rotor to one where notch triggered, if so rotate it
			if (i+1 < count)
			{
				r[i+1].rotate();
			}
		}
	}
}




