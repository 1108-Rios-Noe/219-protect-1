reader: main.o functions.o
	g++ -o reader main.o functions.o

main.o: main.cpp functions.h
	g++ -c main.cpp -g

functions.o: functions.cpp functions.h
	g++ -c functions.cpp -g

cleano: 
	rm *.o

clean:
	rm reader *.o