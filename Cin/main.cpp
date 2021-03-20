#include <iostream>
#include <locale>
#include <stdlib.h>  // EXIT_SUCCESS

using namespace std;

int main()
{
	setlocale(LC_ALL, "polish");

	char znak;

	do {
		cout << "podaj jedną literkę T lub t i nacisnij Enter" << endl;
		cin >> znak;
		cin.sync();
		cout << "wprowadzona pierwsza litera to: " << znak << endl;
	} while (znak != 'T' && znak != 't');

	//---------------------------------------------------------
	int za = 0;
	cout << "podaj cyfrę i wciśnij Enter: " << endl;
	do
	{
		cin >> za;
		cout << "dobrze: " << cin.good() << endl;
		cout << "blad: " << cin.fail() << endl;
		cin.clear();
		cin.sync();

		cout << "podałeś : " << za << endl;
		cout << "jeśli chcesz wyjść z programu wciśnij 1 i wciśnij enter" << endl << endl;
	} while (za != 1);

	cin.ignore();	// to wywołanie usunie z bufora znak '\n' pozostawiony przez obiekt "cin"
	cin.clear();	// czyści flagi błędu
	cin.sync();		// czyści bufor strumienia

	//---------------------------------------------------------

	do
	{
		cout << "naciśnij klawisz ENTER aby ostatecznie wyjść z programu...";
	} while (cin.get() != '\n');

	return EXIT_SUCCESS;
}