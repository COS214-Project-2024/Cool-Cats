ofiles = main.o Transport.o Transportation.o PublicVehicle.o PublicTransport.o Bus.o Taxi.o TrainTransport.o TrainVehicle.o Metro.o Tram.o Freight.o AirportTransport.o AirVehicle.o Passenger.o Cargo.o RoadState.o RoadState.o Road.o UnderConstruction.o ConcreteObserver.o RoadSubject.o Working.o BasicStructure.o CStructIterator.o MaintenanceCostReducer.o ResourceEfficiencyEnhancer.o SatisfactionEnhancer.o StructureDecorator.o StructureGroup.o
gpp_o = g++ -c -std=c++11 -fprofile-arcs -ftest-coverage

main: $(ofiles)
	g++ -std=c++11 -fprofile-arcs -ftest-coverage $(ofiles) -o main

main.o: main.cpp 
	$(gpp_o) main.cpp

Transport.o: Transport.cpp Transport.h 
	$(gpp_o) Transport.cpp

Transportation.o: Transportation.cpp Transportation.h Transport.h
	$(gpp_o) Transportation.cpp



PublicVehicle.o: PublicVehicle.cpp PublicVehicle.h
	$(gpp_o) PublicVehicle.cpp

PublicTransport.o: PublicTransport.cpp PublicTransport.h Transport.h PublicVehicle.h
	$(gpp_o) PublicTransport.cpp

Bus.o: Bus.cpp Bus.h PublicVehicle.h
	$(gpp_o) Bus.cpp

Taxi.o: Taxi.cpp Taxi.h PublicVehicle.h
	$(gpp_o) Taxi.cpp



TrainVehicle.o: TrainVehicle.cpp TrainVehicle.h
	$(gpp_o) TrainVehicle.cpp

TrainTransport.o: TrainTransport.cpp TrainTransport.h Transport.h TrainVehicle.h
	$(gpp_o) TrainTransport.cpp

Metro.o: Metro.cpp Metro.h TrainVehicle.h
	$(gpp_o) Metro.cpp

Tram.o: Tram.cpp Tram.h TrainVehicle.h
	$(gpp_o) Tram.cpp

Freight.o: Freight.cpp Freight.h TrainVehicle.h
	$(gpp_o) Freight.cpp



AirVehicle.o: AirVehicle.cpp AirVehicle.h
	$(gpp_o) AirVehicle.cpp

AirportTransport.o: AirportTransport.cpp AirportTransport.h Transport.h AirVehicle.h
	$(gpp_o) AirportTransport.cpp

Passenger.o: Passenger.cpp Passenger.h AirVehicle.h
	$(gpp_o) Passenger.cpp

Cargo.o: Cargo.cpp Cargo.h AirVehicle.h
	$(gpp_o) Cargo.cpp



RoadSubject.o: RoadSubject.cpp RoadSubject.h Transportation.h Structure.h
	$(gpp_o) RoadSubject.cpp

RoadState.o: RoadState.cpp RoadState.h 
	$(gpp_o) RoadState.cpp

Road.o: Road.cpp Road.h RoadSubject.h
	$(gpp_o) Road.cpp

UnderConstruction.o: UnderConstruction.cpp UnderConstruction.h RoadState.h
	$(gpp_o) UnderConstruction.cpp

Working.o: Working.cpp Working.h RoadState.h
	$(gpp_o) Working.cpp

ConcreteObserver.o: ConcreteObserver.cpp ConcreteObserver.h Transportation.h Road.h
	$(gpp_o) ConcreteObserver.cpp

#Khomotjo Building stuff
BasicStructure.o: BasicStructure.cpp BasicStructure.h Structure.h
	$(gpp_o) BasicStructure.cpp

CStructIterator.o: CStructIterator.cpp CStructIterator.h StructureIterator.h Structure.h
	$(gpp_o) CStructIterator.cpp

MaintenanceCostReducer.o: MaintenanceCostReducer.cpp MaintenanceCostReducer.h StructureDecorator.h
	$(gpp_o) MaintenanceCostReducer.cpp

ResourceEfficiencyEnhancer.o: ResourceEfficiencyEnhancer.cpp ResourceEfficiencyEnhancer.h StructureDecorator.h
	$(gpp_o) ResourceEfficiencyEnhancer.cpp

SatisfactionEnhancer.o: SatisfactionEnhancer.cpp SatisfactionEnhancer.h ResourceEfficiencyEnhancer.h StructureDecorator.h
	$(gpp_o) SatisfactionEnhancer.cpp

StructureDecorator.o: StructureDecorator.cpp StructureDecorator.h Structure.h
	$(gpp_o) StructureDecorator.cpp

StructureGroup.o: StructureGroup.cpp StructureGroup.h Structure.h StructureIterator.h
	$(gpp_o) StructureGroup.cpp


run: main
	./main

ccov: $(ofiles)
	gcov $(ofiles)

coverage: ccov
	gcovr -r . --html --html-details -o coverage.html

clean:
	rm *.o main -f
	rm *.gcda main -f
	rm *.gcov.json.gz main -f
	rm *.gcno main -f
	rm *.zip -f
	rm *.gcov -f
	clear

leak:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main

zip: 
	zip -r u23538318.zip *.cpp *.h