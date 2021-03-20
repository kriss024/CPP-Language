#include <iostream>
#include <cstdlib>
#include "myclass.h"

using namespace std;

MyClass *a;

int main(int argc, char** argv) {

a = new MyClass;
a->ustawX(3);

cout << "x w MyClas to: "<< a->jakiX() << endl;
cout << "5+3 to: " << dodaj(5,3) << endl;

delete a;

getchar();
return EXIT_SUCCESS;
}

