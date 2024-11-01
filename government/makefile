# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = Taxes.cpp TaxMemento.cpp Government.cpp main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = program

# Default target to build the executable
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file into an object file
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean
