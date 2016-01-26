CXX = g++
#CXX = clang++

BINARIES = Student HashTable

all: Main.o Student.o Hashtable.o
	g++ Main.o Student.o Hashtable.o -o prog1

Main.o: Main.cpp
	g++ -c Main.cpp

Student.o: Student.cpp
	g++ -c Student.cpp

Hashtable.o: Hashtable.cpp
	g++ -c Hashtable.cpp

clean:
	/bin/rm -f *o *~ \#* ${BINARIES}
