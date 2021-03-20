#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	map<int, string> tydzien;

	tydzien[1] = "niedziela";
	tydzien[3] = "wtorek";
	tydzien[2] = "poniedzialek";
	tydzien[5] = "czwartek";
	tydzien[4] = "sroda";
	tydzien[7] = "sobota";
	tydzien[6] = "piatek";

	cout << "trzeci dzien tygodnia:  " << tydzien[3] << '\n';

	map<int, string>::iterator cur;

	// zwrocenie elementu o kluczu 3
	cur = tydzien.find(3);

	// elementy o kluczach wiêkszych i mniejszych
	map<int, string>::iterator prev = cur;
	map<int, string>::iterator next = cur;
	++next;
	--prev;

	cout << "Wczesniejszy:  " << prev->second << '\n';
	cout << "Nastepny:  " << next->second << '\n';

	for (map<int, string>::iterator ii = tydzien.begin(); ii != tydzien.end(); ++ii)
	{
		cout << (*ii).first << ": " << (*ii).second << endl;
	}

	tydzien.clear();

	//---------------------------
	map <string, int> data{
		{ "Mehmets score", 34 },
		{ "Bobs score", 10 },
		{ "Rockys score", 23 },
		{ "Martys score", 15 },
		{ "Rockys score", 22 } };

	for (auto& element : data)
	{
		cout << element.first << ": " << element.second << endl;
	}

	getchar();
	return 0;
}