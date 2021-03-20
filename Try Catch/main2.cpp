#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(7);

	try
	{
		arr.at(2);
	}
	catch (exception& e)
	{
		cout << "Exception happened: " << e.what() << endl;
	}

	cin.ignore();
	return 0;
}
