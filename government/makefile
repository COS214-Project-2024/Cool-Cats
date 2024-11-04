# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++23 -fprofile-arcs -ftest-coverage

# Executable name
EXEC = city_simulation
MAIN_BINARY = main

# Source files
SOURCES = main.cpp \
          Government.cpp \
          GovernmentInvoker.cpp \
          TaxationCommand.cpp \
          PolicyImplementationCommand.cpp \
          Materials.cpp \
          Energy.cpp \
          Water.cpp \
          CityResourceMediator.cpp \
          Budget.cpp \
          BudgetAllocationCommand.cpp \
          Taxes.cpp \
          TaxMemento.cpp \
          Citizen.cpp \
          Mayor.cpp \
          HighCitizen.cpp \
          MiddleCitizen.cpp \
          LowCitizen.cpp \
          AllCitizenIterator.cpp \
          CitizenIterator.cpp \
          Creator.cpp \
          HighCitizenCreator.cpp \
          LowCitizenCreator.cpp \
          MayorCreator.cpp \
          MayorIterator.cpp \
          MiddleCitizenCreator.cpp \
          Income.cpp 
          
# Header files
HEADERS = Government.h \
          GovernmentInvoker.h \
          GovernmentCommand.h \
          TaxationCommand.h \
          PolicyImplementationCommand.h \
          Materials.h \
          Energy.h \
          Water.h \
          CityResourceMediator.h \
          Budget.h \
          BudgetAllocationCommand.h \
          Taxes.h \
          TaxMemento.h \
          Citizen.h \
          Mayor.h \
          HighCitizen.h \
          MiddleCitizen.h \
          LowCitizen.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Main target to build the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Compile .cpp files into .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
.PHONY: run
run: $(EXEC)
	./$(EXEC)

# Generate coverage reports
ccov: $(OBJECTS)
	gcov $(OBJECTS)

coverage: ccov
	gcovr -r . --html --html-details -o coverage.html

# Clean up generated files
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXEC) *.gcda *.gcno *.gcov *.zip *.gcov.json.gz *.gcov
	clear

# Check for memory leaks
.PHONY: leak
leak: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(EXEC)
