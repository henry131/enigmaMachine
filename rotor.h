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
	int latches;
	int latch[SIZE];
	bool fwd_encode;
public:
	Rotor(char* filename);
	~Rotor();
	void get_start_position(int position);
	void set_start_position();
	void reset_position();
	void set_fwd_encode();
	void set_bck_encode();
	void rotate();
	bool latch_triggered();
	int output(int a);
	void print();

};

#endif
