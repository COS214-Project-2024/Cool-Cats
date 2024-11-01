# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Executable name
EXEC = city_simulation

# Source files
SOURCES = main.cpp \
          Government.cpp \
          GovernmentInvoker.cpp \
          TaxationCommand.cpp \
          PolicyCommand.cpp \
          Materials.cpp \
          Energy.cpp \
          Water.cpp \
          CityResourceMediator.cpp

# Header files
HEADERS = Government.h \
          GovernmentInvoker.h \
          Command.h \
          TaxationCommand.h \
          PolicyCommand.h \
          Materials.h \
          Energy.h \
          Water.h \
          CityResourceMediator.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Build the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Compile .cpp files into .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(EXEC)

# Run the program
run: $(EXEC)
	./$(EXEC)

# Phony targets
.PHONY: clean run
