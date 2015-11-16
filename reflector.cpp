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

using namespace std;

Reflector::Reflector(char* filename)
{
	ifstream in;
	int a;
	
	in.open(filename);
	if (!in)
	{
		cout << "Reflector file could not be opened" << endl;
		exit(1);
	}

	in >> a;
	count = -1;

	while (!in.eof())
	{
		count++;
		reflector_map[count] = a;
		in >> a;
	}
	in.close();

	if (count != MAX_SIZE - 1)
	{
		cout << "Reflector pairs not complete" << endl;
	}
}

Reflector::~Reflector()
{
	//Blank
}

int Reflector::output(int a)
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
