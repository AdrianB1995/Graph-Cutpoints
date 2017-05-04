main: graph.o cut_tester.o
	g++ -Wall graph.o cut_tester.o -o main

cut_tester.o: cut_tester.cpp
	g++ -Wall -c cut_tester.cpp

graph.o: graph.cpp
	g++ -Wall -c graph.cpp

clean:
	rm *.o
