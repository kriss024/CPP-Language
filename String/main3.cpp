#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string str = "  -0.535345  ";
	cout << str << endl;

	int	some_number;
	float some_float;
	
	istringstream is(str);
		
	is >> some_number >> some_float;

	if (is.fail())
	{
		cerr << "Error in parsing!" << endl;
	}
	else
	{
		cout << "Parsed items: " << endl
			<< some_number << endl
			<< some_float << endl;
	}

	getchar();
	return 0;
}