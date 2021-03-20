#include <iostream>
#include <cstdlib>
#include <stdlib.h>  // EXIT_SUCCESS

using namespace std;

typedef unsigned int UINT;
enum suits_num { Spades = 1, Clubs = 2, Hearts = 4, Diamonds = 6 };

inline double oblicz(UINT &a, UINT &b); //deklaracja

void obliczenia(UINT &a, UINT &b)
{
	register unsigned int c;
	register double d, e, f;
	cout << "Obliczenia w C++ " << endl;
	c = a / b;
	cout << "int = a/b " << c << endl;
	d = a / b;
	cout << "double = a/b " << d << endl;
	e = double(a / b);
	cout << "double = double(a/b) " << e << endl;
	f = static_cast<double>(a) / b;
	cout << "double = static_cast<double>(a)/b " << f << endl;
	cout << "oblicz(a,b) " << oblicz(a, b) << endl;
}

int main(int argc, char** argv) {

	UINT x = 100;
	UINT y = 400;
		
	suits_num suits;

	obliczenia(x, y);

	suits = Diamonds;

	cout << "suits " << suits << endl;

	getchar();

	return EXIT_SUCCESS;
}

inline double oblicz(UINT &a, UINT &b)  //definicja
{	
	double c = (double)a;
	return c / b;
}
