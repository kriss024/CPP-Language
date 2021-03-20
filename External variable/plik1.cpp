#include <stdio.h>
#include <stdlib.h>
 
 extern int GlobalVariable;  // explicit declaration
 
  void SomeFunction() {       // function header (definition)
    ++GlobalVariable;
  }


