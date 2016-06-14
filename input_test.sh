echo "running basic input tests..."

./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input1.txt 1> test/output/input2.txt 2> test/output/input2_err.txt
RETVAL=$?
EXPECTED=0
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL"

FNAME=input2
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/input2.txt > test/output/${FNAME}.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
if [ $RETVAL -eq $EXPECTED ]
then
	diff -q test/input/input1.txt test/output/${FNAME}.txt
	[ $? -eq 0 ] && echo "Success"
else
	echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL"
fi

echo "running input stress tests..."
FNAME=lowercase
EXPECTED=2
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=lowercase_2
EXPECTED=2
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=number
EXPECTED=2
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=text_number
EXPECTED=2
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=special
EXPECTED=2
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=special2
EXPECTED=2
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=leading_return
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=leading_space
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=leading_tab
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=null
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=returns
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=spaces
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt

FNAME=tabs
EXPECTED=0
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test/input/${FNAME}.txt 1> test/output/$FNAME.txt 2> test/output/${FNAME}_err.txt
RETVAL=$?
[ $RETVAL -eq $EXPECTED ] && echo "Success"
[ $RETVAL -ne $EXPECTED ] && echo "Failure on $FNAME. Expected err = $EXPECTED, got $RETVAL" && cat test/output/pb_${FNAME}_err.txt









