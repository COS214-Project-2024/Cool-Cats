CXX=g++
CFLAGS=-Wall
TARGET=main
OBJS= PowerUtility.o SewageUtility.o Utilities.o WasteUtility.o WaterUtility.o CityResourceMediator.o Energy.o Materials.o Water.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(TARGET) $(OBJS)

valgrind:
	valgrind --leak-check=full ./$(TARGET)

zip: 
	zip -r u22511726.zip *.cpp *.h