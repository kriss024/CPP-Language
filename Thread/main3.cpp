#include <future>
#include <iostream>

using namespace std;

long long Factorial(unsigned int value)
{
	cout << "ThreadTask thread: " << this_thread::get_id() << endl;
	if (value > 1)
		return value * Factorial(value - 1);
	else
		return 1;
}

int main(int argc, char* argv[])
{

	auto taskFuture1 = async(Factorial, 12);
	auto taskFuture2 = async(launch::async, Factorial, 10);

	cout << "waiting..." << endl;

	cout << "Factorial 10! result was " << taskFuture2.get() << endl;
	cout << "Factorial 12! result was " << taskFuture1.get() << endl;

	cin.ignore();
	return 0;
}