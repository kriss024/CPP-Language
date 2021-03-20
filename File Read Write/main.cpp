#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream plik;

	plik.open("C:\\Work\\example.txt", ios::out);

	if (plik.is_open())
	{
		cout << "Plik otwarto pomy�lnie\n";

		plik << "testowy tekst id�cy do pliku 1\n";
		plik << "testowy tekst id�cy do pliku 2\n";
		plik << "testowy tekst id�cy do pliku 3";

		plik.close();
	} else cerr << "Error! Nie uda�o otworzy� si� pliku!\n";

	//----------------------------------

	string napis;

	plik.open("C:\\Work\\example.txt", ios::in);

	if (plik.is_open())
	{
		while (!plik.eof())
		{
			getline(plik, napis);
			cout << napis << '\n';
		}
		plik.close();
	} else cerr << "Error! Nie uda�o otworzy� si� pliku!\n";

	cout << "*** Koniec\n";
	//----------------------------------

	getchar();
	return 0;
}
