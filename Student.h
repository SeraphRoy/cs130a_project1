#include <iostream>
#include <string>

using namespace std;

class Student{
private:
  string name;
  double gpa;
public:
  Student(){name = ""; gpa = 0.0;}
  Student(string name, double gpa);
  string getName();
  double getGpa();
  void setName(string name);
  void setGpa(double gpa);
};

  
