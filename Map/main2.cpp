#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	multimap<string, int> m;
	
	int employeeID = 0;
	m.insert(pair<string, int>("Kowalski", employeeID++));
	m.insert(pair<string, int>("Nowak", employeeID++));
	m.insert(pair<string, int>("Matuszak", employeeID++));
	m.insert(pair<string, int>("Kowalski", employeeID++));
	m.insert(pair<string, int>("Matuszak", employeeID++));
	m.insert(pair<string, int>("Matuszak", employeeID++));

	cout << "Liczba pracownikow o nazwisku 'Kowalski': " << m.count("Kowalski") << endl;
	cout << "Liczba pracownikow o nazwisku 'Nowak': " << m.count("Nowak") << endl;
	cout << "Liczba pracownikow o nazwisku 'Matuszak': " << m.count("Matuszak") << endl;

	cout << endl;
	cout << "Lista pracownikow: " << endl;
	for (multimap<string, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
		cout << " Nazwisko: '" << iter->first << "', ID #" << iter->second << endl;
	}

	getchar();
	return 0;
}