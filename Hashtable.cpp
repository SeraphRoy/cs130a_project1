#include <iostream>
#include <string>
#include "Hashtable.h"

using namespace std;

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
    while(table[index] && table[index]->first >= 0 && table[index]->first != key)
      index  = (index + 1) % table_size;
  }else{
    int index2 = hash2(key);
    int i = 0;
    while(table[index] && table[index]->first != key)
      index = (index + i*index2) % table_size;
  }
  if(table[index] && table[index]->first == key)
    return (-1)*index;
  }
return index;
}
  

void Hashtable::insert(int key, Student value){
  int msg = helpInsert(key, value);
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
    }
    for(int i = 0; i < table_size; i++)
      table[i] = NULL;
    delete [] table;
    table_size *= 2;
    table = new pair<int, Student>* [getSize()];
    for(int i = 0; i < table_size/2; i++)
      helpInsert(newTable[i]->first, newTable[i]->second);
    cout << "\ntable doubled";
  }
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

// void remove(int key){
//   int msg = helpInsert(int key);
//   if(msg >= 0){
//     cout << "item not present in the table";
//     return;
//   }
//   else{
//     msg *= -1;
