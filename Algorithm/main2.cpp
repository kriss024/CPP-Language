#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

double pow_of_two() {
	static double val = 1.0;
	double t;
	t = val;
	val += val;
	return t;
}

int main()
{
	auto ones = []() { return 1.0; };

	vector<double> v(5);
	vector<double> o(5);
	generate(v.begin(), v.end(), pow_of_two);
	generate(o.begin(), o.end(), ones);

	cout << "Powers of 2: ";
	for (unsigned i = 0; i < v.size(); ++i)
		cout << v[i] << " ";

	cout << endl;

	cout << "Ones: ";
	for (vector<double>::iterator it = o.begin(); it != o.end(); ++it) {
		cout << *it << " ";
	}

	cin.ignore();
	cin.get();
	return 0;
}