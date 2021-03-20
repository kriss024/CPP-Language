#include <iostream>
#include <stdlib.h>
#include "plik1.h"

using namespace std; 

 int GlobalVariable;
 
 int global_name = 1001;

int main(int argc, char** argv) {
	
	GlobalVariable=20;
	
	int global_name = 1;  // Local variable
	
	cout << "GlobalVariable " << GlobalVariable << endl; 
	SomeFunction();
	cout << "GlobalVariable " << GlobalVariable << endl;
    cout << "Local variable value " << global_name << endl;
    cout << "Global variable value " << ::global_name << endl;
	
	system("pause");
	
	return 0;
}

