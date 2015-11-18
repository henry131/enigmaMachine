#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector {
private:
	static const int MAX_SIZE = 26;
	int reflector_map[MAX_SIZE];
	int count;
	int error_code;
public:
	//Construtor: initialises object so its value is string stored in a
	Reflector(char* filename);
	//Maps integer a and returns its corresponding pair based on the config
	int output (int a);
	//Returns exisitng error code
	int get_error_code();
	//Prints plugbaord mapping configuration (for debugging)
	void print();
};

#endif
