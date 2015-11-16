#ifndef PLUGBOARD_H
#define PLUGBOARD_H

class Plugboard {
private:
	static const int MAX_SIZE = 26;
	int plugboard_map[MAX_SIZE];
	int size;
public:
	//Construtor: initialises object so its value is string stored in a
	Plugboard(char* filename);
	//Destructor: returns dynamic memory to freestore
	~Plugboard();
	//Maps integer a and returns its corresponding pair based on the config
	int output (int a);
};

#endif
