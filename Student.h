#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>

using namespace std;

class Student{
private:
  string name;
  double gpa;
public:
  Student();
  Student(string name, double gpa);
  string getName();
  double getGpa();
  void setName(string name);
  void setGpa(double gpa);
};

#endif
