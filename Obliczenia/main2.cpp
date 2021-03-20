#include <iostream>
#include <stdlib.h> 

using namespace std;

int main()
{
	int n;
	cout << "Podaj ile liczb chcesz wczytać: ";
	cin >> n;
	cout << "Podaj liczbę i <ENTER>" << endl;
	double liczba;
	double *tablica = new double[n];

	for (int i=0; i < n; i++) {
		cin >> liczba;
		*(tablica + i) = liczba;
	}

	double suma = 0;
	double srednia = 0;
	for (int i = 0; i < n; i++) {
		suma = suma + *(tablica + i);
	}
	srednia = suma / static_cast<double>(n);
	cout << "Suma to: " << suma << endl;
	cout << "Średnia to: " << srednia << endl;

	delete[] tablica;
	cin.ignore();
	cin.sync();
	getchar();
	return EXIT_SUCCESS;
}