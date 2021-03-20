#include <iostream>
#include <memory> //auto_ptr
using namespace std;

class X {
	int b;
public:
	X() {
		static int a = 0;
		cout << "constructing" << endl;
		a++;
		b = a;
	}
	~X() {
		cout << "destructing" << endl;
	}
	void f() {
		cout << b << endl;
	}
};

int main()
{
	auto_ptr<X> p1(new X), p2;

	p2 = p1;            // transfer ownership
	p2->f();

	X *ptr = p2.get();  // can assign to a normal pointer
	ptr->f();

	cin.ignore();
	return 0;
}
