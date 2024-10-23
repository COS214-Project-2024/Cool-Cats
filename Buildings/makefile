ofiles = main.o Structure.o BasicStructure.o CstructureIterator.o CStructureGroup.o MaintenanceCostReducer.o ResourceEfficiencyEnhancer.o SatisfactionEnhancer.o StructureDecorator.o StructureGroup.o StructureIterator.o 
gpp_o = g++ -c -std=c++23 -fprofile-arcs -ftest-coverage

main: $(ofiles)
	g++ -std=c++23 -fprofile-arcs -ftest-coverage $(ofiles) -o main

main.o: main.cpp 
	$(gpp_o) main.cpp

Structure.o: Structure.cpp Structure.h
	$(gpp_o) Structure.cpp

BasicStructure.o: BasicStructure.cpp BasicStructure.h Structure.h
	$(gpp_o) BasicStructure.cpp

CstructureIterator.o: CstructureIterator.cpp CstructureIterator.h StructureIterator.h Structure.h
	$(gpp_o) CstructureIterator.cpp

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

StructureIterator.o: StructureIterator.cpp StructureIterator.h Structure.h
	$(gpp_o) StructureIterator.cpp


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
	zip -r u23538318,u23544148.zip *.cpp *.h *vpp