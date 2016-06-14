#ifndef PLUGBOARD_H
#define PLUGBOARD_H

class Plugboard {
private:
	static const int MAX_SIZE = 26;
	int plugboard_map[MAX_SIZE];
	int input_size;
public:

	//CONSTRUCTOR: SETS input_size TO ZERO
	Plugboard ();
	
	//CONFIGURES PLUGBOARD MAPPING WITH INPUT FROM filename, RETURNS ERROR
	int configure (const char* filename);
	
	//RETURNS OUTPUT AFTER INPUT a GOES THROUGH PLUGBOARD MAPPING
	int output (const int& a);
	
	//PRINTS PLUGBOARD MAPPING (for debugging)
	void print();
};

#endif
