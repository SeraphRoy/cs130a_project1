#CXX = g++
CXX = clang++

BINARIES = Student HashTable


all: Main.o Student.o Hashtable.o
	${CXX} -g Main.o Student.o Hashtable.o -o prog1

test1:
	${CXX} -Wall Main.o Student.o Hashtable.o -o prog1
	./prog1 < Sample1.txt > out1.txt
	diff Sample1_out.txt out1.txt
test2:
	${CXX} -Wall Main.o Student.o Hashtable.o -o prog1
	./prog1 < Sample2.txt > out2.txt
	diff Sample2_out.txt out2.txt
test3:
	${CXX} -Wall Main.o Student.o Hashtable.o -o prog1
	./prog1 < Sample3.txt > out3.txt
	diff Sample3_out.txt out3.txt
test4:
	${CXX} -Wall Main.o Student.o Hashtable.o -o prog1
	./prog1 < Sample4.txt > out4.txt
	diff Sample4_out.txt out4.txt
test5:
	${CXX} -Wall Main.o Student.o Hashtable.o -o prog1
	./prog1 < Sample5.txt > out5.txt
	diff Sample5_out.txt out5.txt

Main.o: Main.cpp
	${CXX} -c Main.cpp

Student.o: Student.cpp
	${CXX} -c Student.cpp

Hashtable.o: Hashtable.cpp
	${CXX} -c Hashtable.cpp

clean:
	/bin/rm -f *o *~ \#* ${BINARIES}
