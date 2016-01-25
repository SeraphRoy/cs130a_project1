#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <string>
#include "Student.cpp"

using namespace std;

class Hashtable{
private:
  static int table_size;
  pair<int, Student>** table;
public:
  Hashtable();
  void insert(int key, Student value);
  Student lookup(int key);
  void remove(int key);
  void print();
  static int hash1(int key){
    return (key % 492113) % table_size;
  }

  static int hash2(int key){
    return (key % 392113) % table_size;
  } 
  string colsolv;
  int load;
  int helpInsert(int key);
  int getSize(){ return table_size;}
};

#endif
