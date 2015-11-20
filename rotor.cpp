/*---------------------------------------------------------
Date: 12th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Reflector Class			
---------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "rotor.h"
#include "errors.h"

using namespace std;

Rotor::Rotor()
{
	rotations = 0;
}

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
	
	while (!in.eof())
	{
	
		//Check input is numeric character
		if ((in.peek()<48||in.peek()>59) && !isspace(in.peek()))
		{
			cerr << "Rotor: Non-numeric Character Error" << endl;
			in.close();
			return NON_NUMERIC_CHARACTER;
		}
		
		//Check input within range (0-25 : A-Z)
		if (a < 0 || a > 25)
		{
			cerr << "Rotor: Invalid Index Error" << endl;;
			in.close();
			return INVALID_INDEX;
		}
		
		//For first 26 inputs, set mapping arrays: forward and backwards
		if (count < SIZE)
		{
			fwd[count] = a;
			bck[a] = count;
		}
		
		//Remaining inputs are notches
		else
		{
		
			//Check mapping provided for all 26 inputs by ensuring no duplicates
			if (count == SIZE)
			{
				for (int i = 0; i < count; i++)
				{
					for (int j = i+1; j < count; j++)
					{
						if (fwd[j] == fwd[i])
						{
							cerr << "Invalid Rotor Mapping Error" << endl;
							in.close();
							return INVALID_ROTOR_MAPPING;
						}
					}  
				}
			}
			
			//Check no notch input is repeated
			for (int i = 0; i < count - SIZE; i++)
			{
				if (a == notch[i])
				{
					cerr << "Invalid Rotor Mapping Error: repeated notch" << endl;
					return INVALID_ROTOR_MAPPING;
				}
			}
		
			//Input notch into array
			notch[count - SIZE] = a;
			
		}
		
		//Increment count and take next input into a
		count++;
		in >> a;
		
	}
	
	in.close();
	
	//If loop exits before 26 inputs, insufficient input for mapping rotor
	if (count < SIZE)
	{
				cerr << "Invalid Rotor Mapping Error: insufficient mapping" << endl;
				return INVALID_ROTOR_MAPPING;
	}
	
	//If loop exits before 27 inputs, no notch mapped
	else if (count < SIZE + 1)
	{
				cerr << "Invalid Rotor Mapping Error: no notch" << endl;
				return INVALID_ROTOR_MAPPING;
	}
	
	//Record number of notches on rotor
	notches = count - SIZE;
	
	return 0;
}

void Rotor::input_start_position (const int& position)
{
	start_position = position;
}


void Rotor::set_start_position()
{
	for (int i = 0; i < start_position; i++)
	{
		rotate();
	}
}

void Rotor::reset_position()
{
	int normalise = SIZE - (rotations % SIZE);
	for (int i = 0; i < normalise; i++)
	{
		rotate();
	}
	rotations = 0;
}

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
	//tick up number of rotations
	rotations++;
	if (rotations == 26)
	{
		rotations = 0;
	}
}

bool Rotor::notch_triggered()
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

int Rotor::output(const int& a)
{
	if (a < 0 || a >= SIZE)
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

void Rotor::set_fwd_encode()
{
	fwd_encode = true;

}

void Rotor::set_bck_encode()
{
	fwd_encode = false;
}

void Rotor::print()
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

