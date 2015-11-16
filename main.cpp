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
bool debug = true;


char encrypt (char c, int rotor_count);
void rotate_rotors(int count);

int main(int argc, char** argv){

	if (debug) 
		cout << "Number of args to main: " << argc << endl;

	if (argc < 4)
	{
		cout << "Run program passing 1 plugboard, 1 reflector,";
		cout << "0 to 26 rotor and 1 rotor positioning file(s)" << endl;
		//INSUFFICIENT_NUMBER_OF_PARAMETERS
		return 1;	
	}
	
	//Get plugboard config (second arg)
	
	if (checkPbFileName (argv[1]))
	{
		plugboard = new Plugboard (argv[1]);
		if (debug)
		{
			cout << "Plugboard config " << argv[1] << " added" << endl;
			for (int i = 0; i <= 25; i++)
			{
			cout << i << " -> " << plugboard->output(i) << endl;
			}
		}
	}
	else
	{
		cout << "Pass a '.pb' file as the second argument" << endl;
		return 1;
	}
	
	//Get reflector config (third arg)
	
	if (checkRefFileName (argv[2]))
	{
		reflector = new Reflector (argv[2]);
		if (debug)
		{
			cout << "Reflector config " << argv[2] << " added" << endl;
			for (int i = 0; i <= 25; i++)
			{
			cout << i << " -> " << reflector->output(i) << endl;
			}
		}
	}
	else
	{
		cout << "Pass a '.rf' file as the third argument" << endl;
		return 1;
	}
	
	//Get rotors config (not first three or last arg)
	
	int rotor_count = 0;
		
	for (int i = 3; i < argc-1; i++)
	{	
		if (checkRotFileName (argv[i]))
		{
			rotors[rotor_count] = new Rotor(argv[i]);
			if (debug)
			{
				cout << "Rotor " << argv[i] << " added" << endl;
				rotors[rotor_count]->print();
			}
			rotor_count++;
		}
		else
		{
			cout << "Pass '.rot' files for the rotors" << endl;
			return 1;
		}
	}
	if (debug)
		cout << rotor_count << " rotor(s) added" << endl;

	//Get rotors positioning (last arg)
	
	if (checkRotPosFileName (argv[argc-1]))
	{
		ifstream in;
		in.open(argv[argc-1]);
		if (!in)
		{
			cout << "Rotor positioning file " << argv[argc-1];
			cout << " failed to open" << endl;
			exit(1);
		}
		int position = 0;
		in.close();
		for (int i = rotor_count - 1; i <= 0; i--)
		{
			//peel to check not empty etc.
			in >> position;
			//invlaid index, non numeric character etc.
			rotors[i]->get_start_position(position);
		}
		if (debug)
		{
			cout << "Rotor positioning " << argv[argc-1] << " added" << endl;
		}
	}
	else
	{
		cout << "Pass a '.pos' file as the last argument" << endl;
		return 1;
	}

	//Encryption input and output
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
		for (int i = rotor_count - 1; i <= 0; i--)
			{
				rotors[i]->reset_position();
				rotors[i]->set_start_position();
			}
	}
	cout << endl;
	
	return 0;
}

char encrypt (char c, int rotor_count) {

	int a = charToInt(c);

	rotate_rotors(rotor_count);
	
	//Through Plugboard
	a = plugboard->output(a);
	
	//Through rotors forward
	for (int i = 0; i < rotor_count; i++)
	{
		rotors[i]->set_fwd_encode();
		a = rotors[i]->output(a);
	}
	
	//Through reflector
	a = reflector->output(a);
	
	//Through rotors backwards
	for (int i = rotor_count - 1; i >=0; i--)
	{
		rotors[i]->set_bck_encode();
		a = rotors[i]->output(a);	
	}
	
	//Through plugboard again
	a = plugboard->output(a);

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

 

