#include <iostream>
#include <string>
#include <iomanip>
#include "Hashtable.h"

using namespace std;

bool isPrime(int num) {
  if (num <= 3) {
    return num > 1;
  } else if (num % 2 == 0 || num % 3 == 0) {
    return false;
  } else {
    for (int i = 5; i * i <= num; i += 6) {
      if (num % i == 0 || num % (i + 2) == 0) {
	return false;
      }
    }
    return true;
  }
}

int Hashtable::hash1(int key){
  return (key % 492113) % table_size;
}

int Hashtable::hash2(int key){
  return (key % 392113) % table_size;
} 


Hashtable::Hashtable(){
  table_size = 5;
  colsolv = "linearprobing";
  load = 0;
  table = new pair<int, Student>* [5];
  for(int i = 0; i < table_size; i++){
    table[i]= NULL;
  }
}



int Hashtable::helpInsert(int key){
  int index = hash1(key);
  if(colsolv == "linearprobing"){
    while(table[index] && table[index]->first > 0 && table[index]->first != key)
      index  = (index + 1) % table_size;
  }else{
    int index2 = hash2(key);
    if (index2 == 0)
      index2 = 1;
    int i = 0;
    while(table[index] && table[index]->first > 0 && table[index]->first != key)
      index = (index + i*index2) % table_size;
  }
  if(table[index] && table[index]->first == key)
    return (-1)*index;
  return index;
}
  

void Hashtable::insert(int key, Student value){
  int msg = helpInsert(key);
  if(msg >= 0){
    pair<int, Student>* temp = new pair<int, Student>(key, value);
    if(table[msg])
      delete table[msg];
    table[msg] = temp;
    load ++;
    cout << "item successfully inserted";
  }
  else
    cout << "item already present";    
  if(load/table_size > 0.7){
    pair<int, Student>** newTable = new pair<int, Student>* [getSize()];
    for(int i  = 0; i < table_size; i++){
      newTable[i] = table[i];
      table[i] = NULL;
    }
    delete [] table;
    table_size = table_size*2 + 1;
    while(!isPrime(table_size))
      table_size++;
    table = new pair<int, Student>* [getSize()];
    for(int i = 0; i < table_size/2; i++)
      insert(newTable[i]->first, newTable[i]->second);
    cout << "\ntable doubled";
  }
  return;
}

void Hashtable::lookup(int key){
  int msg = helpInsert(key);
  if(msg < 0){
    msg *= -1;
    cout << "item found; " << table[msg]->second.getName() << " " << msg;
    return;
  }
  else
    cout << "item not found";
}

void Hashtable::remove(int key){
  int msg = helpInsert(key);
  if(msg >= 0){
    cout << "item not present in the table";
    return;
  }
  else{
   msg *= -1;
   table[msg]->first = -10;
   cout << "item successfully deleted";
  }
}

void Hashtable::print(){
  for(int i = 0; i < table_size; i++){
    if(table[i] && table[i]->first >= 0){
      cout << "(" << table[i]->first << "," << table[i]->second.getName();
      cout << std::fixed << std::setprecision(1)<< table[i]->second.getGpa();
      cout << ")";
    }
  }
}
