#ifndef GENERAL_H
#define GENERAL_H

//CHECK filename HAS VALID PLUGBOARD FILE EXTENSION
bool checkPbFileName (char* filename);
//CHECK filename HAS VALID REFLECTOR FILE EXTENSION
bool checkRefFileName (char* filename);
//CHECK filename HAS VALID ROTOR FILE EXTENSION
bool checkRotFileName (char* filename);
//CHECK filename HAS VALID ROTOR POSITIONING FILE EXTENSION
bool checkRotPosFileName (char* filename);

//CONVERT INTEGER i TO CORRESPONDING CHARACTER
char intToChar (int i);
//CONVERT CHARACTER c TO CORRESPONDING INTEGER
int charToInt (char c);



#endif
