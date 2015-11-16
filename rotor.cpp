/*---------------------------------------------------------
Date: 12th November 2015
Author: Henry Williams, hw5115, 01141713
Description: Reflector Class
Includes:	constructor
		destructor (blank)			
---------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "rotor.h"

using namespace std;

Rotor::Rotor(char* filename)
{
	ifstream in;
	in.open(filename);
	if (!in)
	{
		cout << "Rotor file " << filename << "failed to open" << endl;
		exit(1);
	}
	int input, count = 0;
	in >> input;
	while (!in.eof())
	{
		if (count < SIZE)
		{
			fwd[count] = input - count;
			bck[input] = count - input;
		}
		else
		{	
			latch[count - SIZE] = input;
		}
		count++;
		in >> input;
	}
	latches = count - SIZE;
	in.close();
	rotations = 0;
}

Rotor::~Rotor()
{
	//blank
}

void Rotor::get_start_position(int position)
{
	start_position = position;
}


void Rotor::set_start_position()
{
	for (int i = 0; i <= start_position; i++)
	{
		rotate();
	}
}

void Rotor::reset_position()
{
	int normalise = SIZE - (rotations % SIZE);
	for (int i = 0; i <= normalise; i++)
	{
		rotate();
	}
	rotations = 0;
}

void Rotor::rotate()
{
	//Store last element
	int fwd_last_element = fwd[SIZE - 1];
	int bck_last_element = bck[SIZE - 1];
	//Shift all elements up 1
	for (int i = SIZE - 2; i >= 0; i--)
	{
		fwd[i+1] = fwd[i];
		bck[i+1] = bck[i];
	}
	//Return last elements to front
	fwd[0] = fwd_last_element;
	bck[0] = bck_last_element;
	//tick up number of rotations
	rotations++;
}

bool Rotor::latch_triggered()
{
	for(int i = 0; i < latches; i++)
	{
		if ((rotations % SIZE) == latch[i])
		{
			return true;
		} 
	}
	return false;
}

int Rotor::output(int a)
{
	if (a < 0 || a >= SIZE)
	{
		cout << "Rotor output error" << endl;
	}

	int output;

	if (fwd_encode)
	{
		output = a + fwd[a];
	}
	else
	{
		output = a + bck[a];
	}

	if (output < 0)
	{
		return ((output % SIZE) + SIZE); 
	}

	return (output % SIZE);
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
	cout << "Latch Position(s): ";
	for (int i = 0; i < latches; i++)
	{
		cout << latch[i] << " ";
	}
	cout <<endl;
}

