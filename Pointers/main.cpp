#include <iostream>
#include <cstdlib>

using namespace std;

int a, b;
int x = 4;
int * pA = 0, *pB = 0, *pC = 0;
void *pV;
int n = 5, out = 20;;
int *pN = &n;

void wskaznik();
void zwieksz_liczbe(int *liczba);
void zmniejsz_liczbe(int &liczba);
void tablica();
int dodawanie(int pierwszy, int drugi);
void teksty();

void wskaznik() {
	a = 10;
	pA = &a;
	pB = &b;
	*pB = 20;
	pC = pB;
	pV = &x;
	cout << "Wskaźniki w C++ " << endl;
	cout << " a to " << *pA << "\t adres zmiennej to " << &a << endl;
	cout << " b to " << b << "\t adres zmiennej to " << &b << endl;
	cout << "pC to " << *pC << "\t adres zmiennej to " << pC << endl;
	cout << "pV  to " << *(int*)pV << "\t adres zmiennej to " << pV << endl;
	cout << " n to " << *pN << "\t adres zmiennej to " << &n << endl;
	zwieksz_liczbe(&n);
	cout << " n to " << *pN << "\t adres zmiennej to " << &n << endl;
	zmniejsz_liczbe(n);
	cout << " n to " << *pN << "\t adres zmiennej to " << &n << endl;
	int(*plus)(int, int) = dodawanie;
	cout << " dodawanie " << plus(3,4) <<" "<< (*plus)(3, 4) << "\t adres funkcji to " << &plus << endl;
}

void zwieksz_liczbe(int *liczba)
{
	*liczba += 5;
}

void zmniejsz_liczbe(int &liczba)
{
	liczba -= 5;
}


void tablica() {

	cout << "Tablice i wskaźniki w C++ " << endl;

	int *numbers = new int[5]{ 1,2,3,4,5 };

	for (int i = 0; i < 5; i++) {
		numbers[i] = i + 2;
	}
	cout << *numbers << endl;

	int *pnumbers = numbers;
	for (int i = 0; i<5; i++) {
		cout << *(pnumbers + i) << " ";
	}
	cout << endl;
}

int dodawanie(int pierwszy, int drugi) {
	return pierwszy + drugi;
}


void teksty() {

	cout << "Łańcuch znaków i wskaźniki w C++ " << endl;

	string *zdanie = new string;
	*zdanie = "Hello, world!";
	cout << zdanie->c_str() << endl;
}


int main(int argc, char** argv) {

	wskaznik();

	cout << endl;

	cout << endl;

	tablica();

	cout << endl;

	teksty();

	getchar();

	return EXIT_SUCCESS;
}
