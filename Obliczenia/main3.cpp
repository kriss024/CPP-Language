#include <iostream>
#include <math.h>
#include <stdlib.h>  // EXIT_SUCCESS

using namespace std;
int main()
{
    double liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;
	if (cin.good()) {
		cout << "round(" << liczba << ")=" << round( liczba ) << endl;
		cout << "ceil(" << liczba << ")=" << ceil( liczba ) << endl;
		cout << "floor(" << liczba << ")=" << floor( liczba ) << endl;
	}

	if (cin.fail()) {
		cout << "cin fail" << endl;
		exit(EXIT_FAILURE);
	}
	
    getchar();
    return(EXIT_SUCCESS);
}