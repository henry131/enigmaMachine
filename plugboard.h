#ifndef PLUGBOARD_H
#define PLUGBOARD_H

class Plugboard {
private:
	static const int MAX_SIZE = 26;
	int plugboard_map[MAX_SIZE];
	int input_size;
	int error_code;
public:
	//Construtor: initialises object so its value is string stored in a
	Plugboard(char* filename);
	//Maps integer a and returns its corresponding pair based on the config
	int output (int a);
	//Returns exisitng error code
	int get_error_code();
	//Prints plugbaord mapping configuration (for debugging)
	void print();
};

#endif
