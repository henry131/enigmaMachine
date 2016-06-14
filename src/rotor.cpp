/*---------------------------------------------------------
Last Edited: 23rd November 2015
Author: Henry Williams, hw5115, 01141713
Description: Reflector Class			
---------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "rotor.h"
#include "errors.h"

using namespace std;

//Constructor, initialise attributes to neutral

Rotor::Rotor()
{
	rotations = 0;
	fwd_encode = true;
	start_position = 0;
}

//Configures the rotor mapping from input of filename
//Forward mapping is put in fwd[], reverse mapping in bck[]
//Notches are kept in notch[] with how many there are stored in notches
//Will return relevant errors so that they can be returned from main

int Rotor::configure (const char* filename)
{
	ifstream in;
	in.open(filename);
	
	//Check for error opening file
	if (!in)
	{
		cerr << "Rotor: Error Opening Configuration File" << endl;
		return ERROR_OPENING_CONFIGURATION_FILE;
	}
	
	int a;
	int count = 0;
	in >> a;
	
	while ( !in.eof() )
	{
	
		//Check input is numeric character
		if ( (in.peek() < 48 || in.peek() > 59) && !isspace(in.peek()) )
		{
			cerr << "Non-numeric character for mapping in rotor file";
			cerr << " rotor.rot" << endl;
			return NON_NUMERIC_CHARACTER;
		}
		
		//Check input within range (0-25 : A-Z)
		if ( a < 0 || a > 25 )
		{
			cerr << "Rotor: Invalid Index Error" << endl;;
			return INVALID_INDEX;
		}
		
		//For first 26 inputs, set mapping arrays: forward and backwards
		if ( count < SIZE )
		{
			fwd[count] = a;
			bck[a] = count;
		}
		else  //Remaining inputs are notches
		{
		
			//Check mapping provided for all 26 inputs by ensuring no duplicates
			if ( count == SIZE )
			{
				for (int i = 0; i < count; i++)
				{
					for (int j = i+1; j < count; j++)
					{
						if ( fwd[j] == fwd[i] )
						{
							cerr << "Invalid Rotor Mapping Error" << endl;
							return INVALID_ROTOR_MAPPING;
						}
					}  
				}
			}
			
			//Check no notch input is repeated
			for (int i = 0; i < count - SIZE; i++)
			{
				if ( a == notch[i] )
				{
					cerr << "Invalid Rotor Mapping Error: repeated notch" << endl;
					return INVALID_ROTOR_MAPPING;
				}
			}
		
			//Input notch into array
			notch[count - SIZE] = a;
			
		}

		count++;
		in >> a;
	}
	
	in.close();
	
	//If loop exits before 26 inputs, insufficient input for mapping rotor
	if ( count < SIZE )
	{
				cerr << "Not all inputs mapped in rotor file: rotor.rot" << endl;
				return INVALID_ROTOR_MAPPING;
	}
	
	//If loop exits before 27 inputs, no notch mapped
	else if ( count < SIZE + 1 )
	{
				cerr << "N.B. No notches added to Rotor. Encryption continuing ";
				cerr << "regardless" << endl;
	}
	
	//Record number of notches on rotor
	notches = count - SIZE;
	
	return NO_ERROR;
}

//position is starting position of rotor from Rotor Starting Positon file

void Rotor::input_start_position (const int& position)
{
	start_position = position;
}

//rotates rotor to be in the position stored in start_position

void Rotor::set_start_position()
{
	for (int i = 0; i < start_position; i++)
	{
		rotate();
	}
}

//rotates rotor to be at normalised position 0 ('A') - (debugging)

void Rotor::reset_position()
{
	int normalise = SIZE - ( rotations % SIZE );
	for (int i = 0; i < normalise; i++)
	{
		rotate();
	}
	rotations = 0;
}

//rotates rotor once by shifitng fwd[] and bck[] arrays round once

void Rotor::rotate()
{
	//Store last element
	int fwd_first_element = fwd[0];
	int bck_first_element = bck[0];
	
	//Shift all elements up 1
	for (int i = 0; i < SIZE - 1; i++)
	{
		fwd[i] = fwd[i+1];
		bck[i] = bck[i+1];
	}
	
	//Return last elements to front
	fwd[SIZE-1] = fwd_first_element;
	bck[SIZE-1] = bck_first_element;
	
	//tick up number of rotations / reset to 0 if done full rotation
	rotations++;
	if (rotations == 26)
	{
		rotations = 0;
	}
}

//checks to see if notch has been triggered in rotors current position

bool Rotor::notch_triggered ()
{
	for(int i = 0; i < notches; i++)
	{
		if ((rotations % SIZE) == notch[i])
		{
			return true;
		} 
	}
	return false;
}

//Returns what int a maps to based on configuration contained in rotor
//arrays fwd[] or bck[] (depending on whether fwd_encode bool is true/false)
//int a must be within enigma range (0-25 : A-Z)

int Rotor::output (const int& a)
{
	if ( a < 0 || a >= SIZE )
	{
		cout << "Rotor output error" << endl;
	}

	int output;

	if (fwd_encode)
	{
		output = fwd[a] - rotations;
	}
	else
	{
		output = bck[a] - rotations;
	}

	if (output < 0)
	{
		return output + SIZE; 
	}

	return output;
}

//Sets fwd_encode bool to true for when encryption goes through rotors

void Rotor::set_fwd_encode ()
{
	fwd_encode = true;

}

//Sets fwd_encode bool to false for when encryption goes back through rotors

void Rotor::set_bck_encode ()
{
	fwd_encode = false;
}

//Prints mapping of rotor (fwd[], bck[]) and notch(es) - (debugging)

void Rotor::print ()
{
	cout << "Print forward array" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << fwd[i] << " ";
	}
	cout << endl;
	
	cout << "Print backward array" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << bck[i] << " ";
	}
	cout << endl;
	
	cout << "Notch Position(s): ";
	for (int i = 0; i < notches; i++)
	{
		cout << notch[i] << " ";
	}
	cout <<endl;
}

