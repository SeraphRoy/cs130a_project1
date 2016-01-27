#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class Hashtable{
private:
  pair<int, Student>** table;
public:
  Hashtable();
  int hash1(int key);
  int hash2(int key);
  int table_size;
  bool insert(int key, Student value);
  void insertMessage(int key, Student value);
  void lookup(int key);
  void remove(int key);
  void print();
  string colsolv;
  int load;
  int helpInsert(int key);
  int getSize(){ return table_size;}
  void setMode(int num);
};

#endif
