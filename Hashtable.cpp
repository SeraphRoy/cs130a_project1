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



pair<int, int>  Hashtable::helpInsert(int key){
  int index = hash1(key);
  if(colsolv == "linearprobing"){
    while(table[index] && table[index]->first > 0 && table[index]->first != key)
      index  = (index + 1) % table_size;
  }else{
      int index2 = hash2(key);
      if (index2 == 0)
          index2 = 1;
      while(table[index] && table[index]->first > 0 && table[index]->first != key){
          index = (index + index2) % table_size;
      }
  }
  if(table[index] && table[index]->first == key){
    pair<int ,int> result((-1)*index, 1);
    return result;
  }
    pair<int ,int> result(index, 0);
    return result;
}

void Hashtable::insertMessage(int key, Student value){
  bool flag = insert(key, value);
  if(flag)
    cout << "item successfully inserted" << endl;
  else
    cout << "item already present" << endl;    
}    

bool Hashtable::insert(int key, Student value){
  pair<int, int> temp0 = helpInsert(key);
  int msg = temp0.second;
  if(msg == 0){
    msg = temp0.first;
    if(static_cast<double>(load + 1)/static_cast<double>(table_size) > 0.7){
    	load = 0;
    	pair<int, Student>** newTable = new pair<int, Student>* [getSize()];
    	for(int i  = 0; i < table_size; i++){
	  newTable[i] = table[i];
      	  table[i] = NULL;
    	}
    	delete [] table;
        int old_size = table_size;
    	table_size = table_size*2 + 1;
    	while(!isPrime(table_size))
      	  table_size++;
    	table = new pair<int, Student>* [getSize()];
    	for(int i = 0; i < table_size; i++)
      	  table[i] = NULL;
    	for(int i = 0; i < old_size; i++){
          if(newTable[i])
            insert(newTable[i]->first, newTable[i]->second);
	}
    	cout << "table doubled" << endl;
    }
    pair<int, Student>* temp = new pair<int, Student>(key, value);
    msg = helpInsert(key).first;
    if(table[msg])
      delete table[msg];
    table[msg] = temp;
    load ++;
    return true;
  }
  else
    return false;
}

void Hashtable::lookup(int key){
  pair<int, int> temp = helpInsert(key);
  int msg = temp.second;
  if(msg == 1){
    msg = temp.first;
    msg *= -1;
    cout << "item found; " << table[msg]->second.getName() << " " << msg << endl;
    return;
  }
  else
    cout << "item not found" << endl;
}

void Hashtable::remove(int key){
  pair<int, int> temp = helpInsert(key);
  int msg = temp.second;
  if(msg == 0){
    cout << "item not present in the table" << endl;
    return;
  }
  else{
    msg = temp.first;
   msg *= -1;
   table[msg]->first = -10;
   load --;
   cout << "item successfully deleted" << endl;
  }
}

void Hashtable::print(){
  for(int i = 0; i < table_size; i++){
    if(table[i] && table[i]->first >= 0){
      cout << "(" << table[i]->first << "," << table[i]->second.getName() << ",";
      cout << std::fixed << std::setprecision(1)<< table[i]->second.getGpa();
      cout << ")";
    }
  }
  cout << "\n";
}

void Hashtable::setMode(int num){
  if(num == 1)
      colsolv = "doublehashing";
  else
      colsolv = "linearprobing";
}
