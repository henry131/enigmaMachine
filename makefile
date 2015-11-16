OBJ=main.o general.o plugboard.o reflector.o rotor.o
EXE=enigma
CXX=g++
CPPFLAGS=-Wall -g -MMD

$(EXE): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $<

-include $(OBJ:.o=.d)

.PHONY: clean

clean:
	rm -f $(OBJ) $(OBJ:.o=.d)
