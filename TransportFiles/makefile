ofiles = main.o Transport.o Transportation.o PublicVehicle.o PublicTransport.o Bus.o RoadState.o RoadState.o Road.o UnderConstruction.o ConcreteObserver.o RoadSubject.o Working.o
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


RoadSubject.o: RoadSubject.cpp RoadSubject.h Transportation.h
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