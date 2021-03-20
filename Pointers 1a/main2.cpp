#include <iostream>
#include <locale>
#include <cstdlib>

using namespace std;

void my_int_func(int x)
{
    cout <<"Wartoœæ x: "<< x << endl;
}


int main()
{
	setlocale(LC_ALL, "polish");
    void (*foo)(int);
    foo = &my_int_func;

    /* call my_int_func (note that you do not need to write (*foo)(2) ) */
    foo( 2 );
    /* but if you want to, you may */
    (*foo)( 2 );

	system("PAUSE");
	return EXIT_SUCCESS;
}