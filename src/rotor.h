#ifndef ROTOR_H
#define ROTOR_H

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
	
	//CONSTRUCTOR
	Rotor();
	
	//CONFIGURES ROTOR MAPPING WITH INPUT FROM filename, RETURNS ERROR
	//ALSO CONFIGURES ROTOR NOTCHES, DOES NOT CONFIGURE START POSITION
	int configure (const char* filename);
	
	//SETS ATTRIBUTE start_position TO PASSED INTEGER position
	void input_start_position(const int& position);
	
	//SHIFTS ROTOR TO START IN POSITION CONTAINED IN start_position
	//ROTOR MUST BE AT 0 ('A') POSITION INITIALLY
	void set_start_position();
	
	//RESET ROTOR TO BE AT POSITION 0 ('A') - (debugging)
	void reset_position();
	
	//SET fwd_encode BOOL TO TRUE - USE fwd[] FOR OUTPUT METHOD
	void set_fwd_encode();
	
	//SET fwd_encode BOOL TO FALSE - USE bck[] FOR OUTPUT METHOD
	void set_bck_encode();
	
	//ROTATE ROTOR - SHIFT fwd[] & bck[] AROUND 1 POSITION
	void rotate();
	
	//TRUE IF ROTOR IS AT NOTCH POSTION CONTAINED IN notch[]
	bool notch_triggered();
	
	//RETURNS OUTPUT AFTER INPUT a GOES THROUGH ROTOR MAPPING
	int output(const int& a);
	
	//PRINTS ROTOR fwd[], bck[] & notch[] (debugging)
	void print();
};

#endif
