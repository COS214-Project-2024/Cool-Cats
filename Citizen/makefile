ofiles = AllCitizenIterator.o Citizen.o CitizenIterator.o Creator.o HighCitizen.o HighCitizenCreator.o Income.o LowCitizen.o LowCitizenCreator.o MainCitizen.o Mayor.o MayorCreator.o MayorIterator.o MiddleCitizen.o MiddleCitizenCreator.o
gpp_o = g++ -c -std=c++23 -fprofile-arcs -ftest-coverage
MAIN_BINARY = main

# Main target to build the executable
main: $(ofiles)
	g++ -std=c++23 -fprofile-arcs -ftest-coverage $(ofiles) -o $(MAIN_BINARY)

# Rule for building object files
%.o: %.cpp
	$(gpp_o) $<

# Rule for each .o file
MainCitizen.o: MainCitizen.cpp 
	$(gpp_o) MainCitizen.cpp

AllCitizenIterator.o: AllCitizenIterator.cpp
	$(gpp_o) AllCitizenIterator.cpp

Citizen.o: Citizen.cpp
	$(gpp_o) Citizen.cpp

CitizenIterator.o: CitizenIterator.cpp
	$(gpp_o) CitizenIterator.cpp

Creator.o: Creator.cpp
	$(gpp_o) Creator.cpp

HighCitizen.o: HighCitizen.cpp
	$(gpp_o) HighCitizen.cpp

HighCitizenCreator.o: HighCitizenCreator.cpp
	$(gpp_o) HighCitizenCreator.cpp

Income.o: Income.cpp
	$(gpp_o) Income.cpp

LowCitizen.o: LowCitizen.cpp
	$(gpp_o) LowCitizen.cpp

LowCitizenCreator.o: LowCitizenCreator.cpp
	$(gpp_o) LowCitizenCreator.cpp

Mayor.o: Mayor.cpp
	$(gpp_o) Mayor.cpp

MayorCreator.o: MayorCreator.cpp
	$(gpp_o) MayorCreator.cpp

MayorIterator.o: MayorIterator.cpp
	$(gpp_o) MayorIterator.cpp

MiddleCitizen.o: MiddleCitizen.cpp
	$(gpp_o) MiddleCitizen.cpp

MiddleCitizenCreator.o: MiddleCitizenCreator.cpp
	$(gpp_o) MiddleCitizenCreator.cpp

# Run the program
.PHONY: run
run: $(MAIN_BINARY)
	./$(MAIN_BINARY)

# Generate coverage reports
ccov: $(ofiles)
	gcov $(ofiles)

coverage: ccov
	gcovr -r . --html --html-details -o coverage.html

# Clean up generated files
.PHONY: clean
clean:
	rm -f *.o $(MAIN_BINARY) *.gcda *.gcno *.gcov *.zip *.gcov.json.gz *.gcov
	clear

# Check for memory leaks
.PHONY: leak
leak: $(MAIN_BINARY)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(MAIN_BINARY)
