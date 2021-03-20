#include <iostream>

using namespace std;

int main()
{
	int v[] = { 0,1,2,3,4,5,6,7,8,9 };

	for (auto x : v)
		cout << x << ' ';

	cout << '\n';
	cout << "type of v: " << typeid(v).name() << '\n';
	
	for (auto x : {10,20,30,40,50,60,70,80,90})
		cout << x << ' ';

	cout << '\n';
		
	getchar();
	return 0;
}