kCXX = g++
CXXFLAGS = -Wall -std=c++11 

OBJECTS = graphsearch.o main.o

main: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o sixdegrees graphsearch.o main.o

graphsearch.o: graphsearch.cpp graphsearch.h
	$(CXX) -g $(CXXFLAGS) -c graphsearch.cpp
	
main.o: graphsearch.cpp graphsearch.h main.cpp
	$(CXX) -g $(CXXFLAGS) -c main.cpp

clean: 
	rm -f *.o
	rm main