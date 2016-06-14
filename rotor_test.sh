echo "running basic rotor tests..."
FNAME=3_rotors
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=no_rotor
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=lots_of_rotors
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/IV.rot rotors/V.rot rotors/VI.rot rotors/VII.rot rotors/VIII.rot test/rotor/VIII.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=not_enough_rotors
EXPECTED=1
./enigma plugboards/I.pb reflectors/I.rf rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=too_many_rotors
EXPECTED=8
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/IV.rot rotors/V.rot rotors/VI.rot rotors/VII.rot rotors/VIII.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=no_pos
EXPECTED=1
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=no_pos2
EXPECTED=11
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=no_pos3
EXPECTED=11
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt


echo "running rotor stress tests..."


FNAME=invalid
EXPECTED=3
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=3
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt

FNAME=invalid_append
EXPECTED=3
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=3
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt

FNAME=leading_tabs
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt

FNAME=leading_whitespace
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt

FNAME=missing
EXPECTED=7
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=8
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt


FNAME='more'
EXPECTED=3
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt

FNAME=nonnum
EXPECTED=4
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=4
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt

FNAME=nonnum_append
EXPECTED=4
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=4
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt


FNAME=no_notches
EXPECTED=7
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=repeated_notches
EXPECTED=7
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=return
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt


FNAME=same_output
EXPECTED=7
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=special
EXPECTED=4
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=4
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt

FNAME=tabs
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt

FNAME=too_many_notches
EXPECTED=7
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

FNAME=whitespace
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf test/rotor/${FNAME}.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rot_$FNAME.txt 2> test/output/rot_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rot_${FNAME}_err.txt

EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot test/rotor/${FNAME}.pos < test/input/input2.txt 1> test/output/pos_$FNAME.txt 2> test/output/pos_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.pos. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pos_${FNAME}_err.txt

