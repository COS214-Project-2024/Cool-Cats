CXX=g++
CFLAGS=-Wall
TARGET=main
OBJS= PowerUtility.o main.o SewageUtility.o Utilities.o WasteUtility.o WaterUtility.o CityResourceMediator.o Energy.o Materials.o Water.o Transport.o Transportation.o PublicVehicle.o PublicTransport.o Bus.o Taxi.o TrainTransport.o TrainVehicle.o Metro.o Tram.o Freight.o AirportTransport.o AirVehicle.o Passenger.o Cargo.o RoadState.o RoadState.o Road.o UnderConstruction.o ConcreteObserver.o RoadSubject.o Working.o BasicStructure.o CStructIterator.o MaintenanceCostReducer.o ResourceEfficiencyEnhancer.o SatisfactionEnhancer.o StructureDecorator.o StructureGroup.o AllCitizenIterator.o Citizen.o CitizenIterator.o Creator.o HighCitizen.o HighCitizenCreator.o Income.o LowCitizen.o LowCitizenCreator.o MainCitizen.o Mayor.o MayorCreator.o MayorIterator.o MiddleCitizen.o MiddleCitizenCreator.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(TARGET) $(OBJS)
	clear

valgrind:
	valgrind --leak-check=full ./$(TARGET)

zip: 
	zip -r u22511726.zip *.cpp *.h