#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student(){
  name = "";
  gpa = 0.0;
}

Student::Student(string name, double gpa){this-> name = name; this->gpa = gpa;}

string Student::getName(){return name;}

double Student::getGpa(){return gpa;}

void Student::setName(string name){this->name = name;}

void Student::setGpa(double gpa){this->gpa = gpa;}
