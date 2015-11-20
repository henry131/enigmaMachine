#ifndef GENERAL_H
#define GENERAL_H

//CHECK filename HAS VALID PLUGBOARD FILE EXTENSION
bool checkPbFileName (const char* filename);
//CHECK filename HAS VALID REFLECTOR FILE EXTENSION
bool checkRefFileName (const char* filename);
//CHECK filename HAS VALID ROTOR FILE EXTENSION
bool checkRotFileName (const char* filename);
//CHECK filename HAS VALID ROTOR POSITIONING FILE EXTENSION
bool checkRotPosFileName (const char* filename);

//CONVERT INTEGER i TO CORRESPONDING CHARACTER
char intToChar (int i);
//CONVERT CHARACTER c TO CORRESPONDING INTEGER
int charToInt (char c);

//PRINTS INTRODDUCTORY MESSAGE TO THE SCREEN
void intro_message ();

#endif
