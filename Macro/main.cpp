#include <iostream>

using namespace std;

int main()
{
	#define stars "*****"
	#define n 5
	int *array = new int[n];
	int liczba, min, max;

	cout << "Podaje " << n << " liczba: ";
	
	for (int a = 0; a < n; a++) {
		cin >> liczba;
		array[a] = liczba;
	}

	#define getmax(a, b) ((a)>(b)?(a):(b))
	#define getmin(a, b) ((a)<(b)?(a):(b))
	#define square(x) (x*x)

	min = array[0];
	max = array[0];
	for (int a = 1; a < n; a++) {
		max = getmax(max, array[a]);
		min = getmin(min, array[a]);
	}
	cout << stars << endl;
	#define simple(s1, n1) cout << #s1 << n1 << endl

	simple(Maksimum: , max);
	simple(Minimum: , min);
	simple(Kwadrat: , square(max));

	cin.ignore();
	cin.get();
	delete[] array;

	return 0;
}