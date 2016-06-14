#ifndef GENERAL_H
#define GENERAL_H

/** Class Forward Declarations **/
class Rotor;
class Plugboard;
class Reflector;

/** Debug trigger(s) **/
const bool debug = false;

/** Function declarations **/

//CHECK filename HAS VALID PLUGBOARD FILE EXTENSION
bool checkPbFileName (const char* filename);

//CHECK filename HAS VALID REFLECTOR FILE EXTENSION
bool checkRefFileName (const char* filename);

//CHECK filename HAS VALID ROTOR FILE EXTENSION
bool checkRotFileName (const char* filename);

//CHECK filename HAS VALID ROTOR POSITIONING FILE EXTENSION
bool checkRotPosFileName (const char* filename);

//CONVERT INTEGER i (0-25) TO CORRESPONDING CAPITALISED CHARACTER (A-Z)
char intToChar (int i);

//CONVERT CAPATILISED CHARACTER c (A-Z) TO CORRESPONDING INTEGER (0-25)
int charToInt (char c);

//PRINTS INTRODDUCTORY MESSAGE TO THE SCREEN
void intro_message ();

//SETS STARTING POSITION OF rotor_count ROTORS IN r[] WITH filename INPUT
int rotor_positioning(const char* filename, int rotor_count, Rotor r[]);

//STEPS THROUGH ENIGMA MACHING PROCESS ENCRYPTING CHARACTER c
char encrypt (char c, const int& rotor_count, 
							Rotor r[], Plugboard pb, Reflector rf);
							
//ROTATES rotor_count ROTORS in r[] ACCORDING TO PRECONFIGURED NOTCHES
void rotate_rotors(const int& count, Rotor r[]);

#endif
