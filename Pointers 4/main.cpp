#include <iostream>
#include <cstdlib>

using namespace std;

void my_int_func(int x)
{
	cout << "x = " << x << endl;
}

void func(int* x)
{
	*x += 1;
}

int main()
{
	void(*foo)(int);
	foo = &my_int_func;

	/* call my_int_func (note that you do not need to write (*foo)(2) ) */
	foo(2);
	/* but if you want to, you may */
	(*foo)(2);


	int x = 3;
	cout << "x = " << x << endl;

	func(&x);
	cout << "x = " << x << endl;

	cin.get();
	return EXIT_SUCCESS;
}