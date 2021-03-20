#include <iostream>
#include <memory>
using namespace std;

int main()
{
	double* pvalue = NULL; // Pointer initialized with null
	pvalue = new double;   // Request memory for the variable

	*pvalue = 29494.99;     // Store value at allocated address
	cout << "Value of pvalue : " << *pvalue << endl;

	delete pvalue;         // free up the memory.

	pvalue = NULL;

	auto_ptr<int> ptr (new int);
	*ptr = 12;

	cout << "Value of ptr : " << *ptr << endl;

	getchar();
	return 0;
}
