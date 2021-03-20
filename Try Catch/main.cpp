#include <iostream>
#include <vector>

using namespace std;

int main()
{
	const int size = 1024 * 1024;
	const int max_iter = 5000;
	auto act_iter = 0;
	vector<char*> v;

	try {
		for (auto i = 0; i < max_iter; i++)
		{
			cout << "Attempting to allocate " << i + 1 << " MB...";
			char * p = new char[size];
			for (auto i = 1; i < size; i++)
			{
				p[i] = 'A';
			}
			v.push_back(p);
			act_iter = i;
			cout << "Ok\n";
		}

	}
	catch (bad_alloc) {
		cerr << "Memory exhausted!\n";
		for (auto i = 0; i <act_iter; i++)
		{
			char * p;
			p = v.at(i);
			delete[] p;
		}
		cout << "Memory clear!\n";
	}

	cin.get();
	return 0;
}