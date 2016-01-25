CXX = g++
#CXX = clang++

BINARIES = Student HashTable

all: ${BINARIES} prog1

clean:
	/bin/rm -f *o *~ \#* ${BINARIES}
