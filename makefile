
all: dij dijH dijS gen


dij: dij.cpp Graph.h pqueue.h
	g++ -std=c++11 dij.cpp  -o dij -g

gen: gen.cpp
	g++ -std=c++11 gen.cpp  -o gen -g

gen2: gen2.cpp
	g++ -std=c++11 gen2.cpp  -o gen2

dijH: dijH.cpp Graph.h pqueue.h
	g++ -std=c++11 dijH.cpp  -o dijH -g

dijS: dijS.cpp Graph.h pqueue.h
	g++ -std=c++11 dijS.cpp  -o dijS -g

clean: 
	rm -f dij dijH dijS gen
