#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

string command, key, name;

int main(){
  int rand1, rand2, rand3;
  ofstream myfile;
  int haha = 0;
  myfile.open ("input.txt");
  for(int i = 0; i < 10000; i++){
    rand2 = rand()%9999999 + 1000;
    rand1 = rand()%4;
    rand3 = rand()%100;
    switch(rand1){
    case 0:
      myfile << "print\n";
      break;
    case 1:
      myfile << "insert " << rand2 << " " << rand3 << " 2.3\n";
      break;
    case 2:
      myfile << "lookup " << rand2 << "\n";
      break;
    default:
      myfile << "delete " << rand2 << "\n";
    }
  }
  return 0;
}
