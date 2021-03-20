// in myclass.cpp

#include <iostream>

using namespace std;

class MyClass
{
public:
  MyClass();
  ~MyClass();
  void ustawX(int a);
  int jakiX();
private:
  int x;
};

MyClass::MyClass()
{
  cout << "Witaj w MyClass C++" << endl;
}

MyClass::~MyClass()
{
  cout << "Usuwanie obiektu MyClass" << endl;
}

void MyClass::ustawX(int a)
{
  this->x=a;
}

int MyClass::jakiX()
{
  return this->x;
}

int dodaj(int x, int y){

    return (x+y);
}
