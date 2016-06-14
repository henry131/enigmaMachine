#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector {
private:
	static const int SIZE = 26;
	int reflector_map [SIZE];
public:

	//CONSTRUCTOR (blank)
	Reflector ();
	
	//CONFIGURES REFLECTOR MAPPING WITH INPUT FROM filename, RETURNS ERROR
	int configure (const char* filename);
	
	//RETURNS OUTPUT AFTER INPUT a GOES THROUGH REFLECTOR MAPPING
	int output (const int& a);
	
	//PRINTS REFLECTOR MAPPING (for debugging)
	void print ();
};

#endif
