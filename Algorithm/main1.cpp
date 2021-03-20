#include <iostream>
#include <algorithm>
#include <functional>
#include <locale> 

using namespace std;

bool isDivisibleByThree(int d)
{
	return d % 3 == 0;
}

bool isDivisibleByTwo(int d)
{
	return d % 2 == 0;
}

int main()
{
	locale loc("polish");
	setlocale(LC_ALL, "polish");

	int a[8] = { 3, 5, 7, 8, 3, 4, 5, 3 };
	int b[8];

	cout << "liczba 3 wystêpuje " << count(a, a + 8, 3) << " razy\n";
	
	int times = count_if(a, a + 8, isDivisibleByThree);
	cout << times << " liczb jest podzielnych przez 3\n";

	times = count_if(a, a + 8, isDivisibleByTwo);
	cout << times << " liczb jest podzielnych przez 2\n";

	cout << "\n";
	
	sort(a, a + 8);

	cout << "Tablica a posortowana rosn¹co: \n";
	for (auto i = 0; i < 8; i++)
		cout << a[i] << ' ';

	cout << "\n";
	sort(a, a + 8, greater<int>());

	cout << "Tablica a posortowana malej¹co: \n";
	for (auto i = 0; i < 8; i++)
		cout << a[i] << ' ';

	cout << "\n";
	int m = *max_element(a, a + 8);
	cout << "Max: " << m << "\n";
	m = *min_element(a, a + 8);
	cout << "Min: " << m << "\n";

	copy(a, a + 8, b);

	cout << "Tablica a po kopiowaniu: \n";
	for (int i = 0; i < 8; i++)
	{
		cout << b[i] << ' ';
	}

	getchar();
	return 0;
}