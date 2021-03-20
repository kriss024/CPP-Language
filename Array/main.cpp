#include <iostream>

using namespace std;

int main()
{
	int days[] = { 1,2,3,4,5,6,7 };
	int *ptr = days;
	cout << "Size of array: " << sizeof(days) << endl;
	cout << "Size of one element in array: " << sizeof(ptr) << endl;
	int elements = sizeof(days) / sizeof(days[0]); //total size of array/size of array data type
	cout << "Number elements in array: " << elements << endl;

	for (int i = 0; i < elements; i++) {
		cout << *(ptr + i) << ", ";
	}
	cout << endl;

	elements = 1000;
	int *p = new int[elements];
	cout << "Size of one element in array: " << sizeof(*p) << endl;
	cout << "Number elements in array: " << elements << endl;
	delete[] p;

	getchar();
	return 0;
}