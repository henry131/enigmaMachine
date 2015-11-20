#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector {
private:
	static const int MAX_SIZE = 26;
	int reflector_map[MAX_SIZE];
public:
	//Construtor: initialises object
	Reflector ();
	//Fills reflector_map with input from filename checking for errors 
	int configure (const char* filename);
	//Maps integer a and returns its corresponding pair based on the config
	int output (const int& a);
	//Prints plugbaord mapping configuration (for debugging)
	void print ();
};

#endif
