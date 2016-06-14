
Enigma Use
=======================================================

Enter repository

To create the executable (enigma):

make

To run the program:

note there are sample
	plugboard configuration files in plugboards/
	reflector configuration files in reflectors/
	rotor configuration files in rotors/ (incl. strating rotor positions)
	
./enigma plugboard-file reflector-file (<rotor-file>* rotor-positions)?

For example,

./enigma plugboards/II.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos


Enigma Testing
=======================================================

To run tests (thanks to github user: ysn2233):

./run.sh

