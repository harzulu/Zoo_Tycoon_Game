CC = g++
exe_file = zootycoon
$(exe_file): zoo.o main.o animal.o sealion.o tiger.o bear.o
	$(CC) zoo.o main.o animal.o sealion.o tiger.o bear.o -o $(exe_file)
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
main.o: main.cpp
	$(CC) -c main.cpp
animal.o: animal.cpp
	$(CC) -c animal.cpp
sealion.o: sealion.cpp
	$(CC) -c sealion.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
bear.o: bear.cpp
	$(CC) -c bear.cpp


clean:
	rm –f *.out *.o $(exe_file)