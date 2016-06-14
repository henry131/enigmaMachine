echo "running basic plugboard tests..."
FNAME=I
EXPECTED=0
./enigma plugboards/$FNAME.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=II
EXPECTED=0
./enigma plugboards/$FNAME.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=III
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=IV
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=V
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

echo "running plugboard stress tests..."
FNAME=duplicate
EXPECTED=5
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=extra_whitespace
EXPECTED=0
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=newline
EXPECTED=0
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=null
EXPECTED=0
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=leading_whitespace
EXPECTED=0
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=number_text
EXPECTED=4
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=number_space_text
EXPECTED=4
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=number_text_number
EXPECTED=4
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=number_text_text
EXPECTED=4
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=odd_number
EXPECTED=6
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=return
EXPECTED=0
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=tab
EXPECTED=0
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=text
EXPECTED=4
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=long_number
EXPECTED=4
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=big_number
EXPECTED=3
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=too_many_pairs
EXPECTED=6
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=number_special
EXPECTED=4
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=connect_self
EXPECTED=5
./enigma test/plugboards/${FNAME}.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt 1> test/output/pb_$FNAME.txt 2> test/output/pb_${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt


