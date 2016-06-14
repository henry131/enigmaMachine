echo "running basic reflector tests..."
FNAME=I
EXPECTED=0
./enigma plugboards/I.pb reflectors/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=II
EXPECTED=0
./enigma plugboards/I.pb reflectors/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=III
EXPECTED=0
./enigma plugboards/I.pb reflectors/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt


FNAME=IV
EXPECTED=0
./enigma plugboards/I.pb reflectors/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=V
EXPECTED=0
./enigma plugboards/I.pb reflectors/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=no_reflector
EXPECTED=11
./enigma plugboards/I.pb rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt


echo "running reflector stress tests..."


FNAME=dupe
EXPECTED=9
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=invalidIndex
EXPECTED=3
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=itself
EXPECTED=9
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=lessthan13
EXPECTED=10
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt


FNAME=morethan13
EXPECTED=10
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt


FNAME=non-numeric
EXPECTED=4
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt


FNAME=leading_return
EXPECTED=0
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=leading_tab
EXPECTED=0
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=leading_whitespace
EXPECTED=0
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt


FNAME=return
EXPECTED=0
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=tab
EXPECTED=0
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=whitespace
EXPECTED=0
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=special1
EXPECTED=4
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=special2
EXPECTED=4
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt


FNAME=big_number
EXPECTED=3
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=long_number
EXPECTED=4
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=null
EXPECTED=10
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=number_space_text
EXPECTED=4
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt

FNAME=trailing_text
EXPECTED=4
./enigma plugboards/I.pb test/reflector/${FNAME}.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/rf_$FNAME.txt 2> test/output/rf_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME.rot. Expected err = $EXPECTED, got $RETVAL" && cat test/output/rf_${FNAME}_err.txt
