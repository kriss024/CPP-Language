#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class paraLiczb {
public:
	int liczba;
	int suma;
};

int main() {

	vector<paraLiczb*> wektorLiczb;
	multimap<int, int> mapLiczby;
	paraLiczb *ptrWiersz;
	fstream plik;
	string napis, znak;
	int suma, cyfra, liczba, index;

	plik.open("C:\\Work\\cyfry.txt", ios::in);

	if (plik.is_open())
	{
		while (!plik.eof())
		{
			getline(plik, napis);
			
			istringstream is(napis);
			is >> liczba;

			suma = 0;
			
			for (int i = 0; i < napis.length(); i++) {

				znak = napis.substr(i, 1);
				istringstream is(znak);
				is >> cyfra;
				suma = suma + cyfra;

			}

			if (liczba > 0 && suma > 0) {

				ptrWiersz = new paraLiczb();
				ptrWiersz->liczba = liczba;
				ptrWiersz->suma = suma;
				wektorLiczb.push_back(ptrWiersz);

			}

		}
		plik.close();
	}
	else cerr << "Error! Nie uda³o siê otworzyæ pliku!" << endl;

	index = wektorLiczb.size();

	cout << "Wczytano " << index <<" liczb" << endl;

	cout << "^^^^^^^^^^^^^^^^^^^^" << endl;

	for (vector<paraLiczb*>::const_iterator it = wektorLiczb.begin(); it != wektorLiczb.end(); it++)
	{
		ptrWiersz = *it;
		cout << ptrWiersz->liczba << ", " << ptrWiersz->suma << endl;
		mapLiczby.insert(make_pair(ptrWiersz->suma, ptrWiersz->liczba));
	}
	wektorLiczb.clear();
	cout << "^^^^^^^^^^^^^^^^^^^^" << endl;

	for (multimap<int, int>::iterator it = mapLiczby.begin(); it != mapLiczby.end(); it++)
		cout << it->first << " :: " << it->second << std::endl;

	cout << "^^^^^^^^^^^^^^^^^^^^" << endl;

	multimap<int, int>::iterator itb = mapLiczby.begin();

	cout << "Minimalny element: " << itb->first << " :: " << itb->second << endl;

	multimap<int, int>::iterator ite = mapLiczby.end();
	--ite;

	cout << "Maksymalny element: " << ite->first << " :: " << ite->second << endl;

	getchar();
	return 0;
}