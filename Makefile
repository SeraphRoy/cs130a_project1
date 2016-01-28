#CXX = g++
CXX = clang++

BINARIES = Student HashTable


all: Main.o Student.o Hashtable.o
	${CXX} -Wall -g Main.o Student.o Hashtable.o -o prog1

test:
	rm -f input.txt *.o
	g++ genTest.cpp
	./a.out
	./prog1

Main.o: Main.cpp
	${CXX} -c Main.cpp

Student.o: Student.cpp
	${CXX} -c Student.cpp

Hashtable.o: Hashtable.cpp
	${CXX} -c Hashtable.cpp

clean:
	/bin/rm -f *o *~ \#* ${BINARIES}
