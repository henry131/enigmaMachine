#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor
{
	static const int SIZE = 26;
	int fwd[SIZE];
	int bck[SIZE];
	int start_position;
	int rotations;
	int notches;
	int notch[SIZE];
	bool fwd_encode;
public:
	Rotor();
	int configure (const char* filename);
	void input_start_position(const int& position);
	void set_start_position();
	void reset_position();
	void set_fwd_encode();
	void set_bck_encode();
	void rotate();
	bool notch_triggered();
	int output(const int& a);
	void print();
};

#endif
