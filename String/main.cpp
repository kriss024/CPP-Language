#include <iostream> 
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	string napis;
	napis = "  -0.123456789 ";
	cout << napis << endl;
	double liczba;
	liczba = stod(napis);
	cout << liczba << endl;
	double liczba2;
	liczba2 = atof(napis.c_str());
	cout << liczba2 << endl;
	//#############################

	string str("Somewhere down the road");

	for (auto c : str) {
		c = toupper(c);
		cout << c << ' ';
	}
	
	//#############################

	cout << endl;

	string s = "1 2 3 4";
	istringstream iss(s);
	int n;

	while (iss >> n) {
		cout << "* " << n << endl;
	}

	cout << endl;

	string s2 = "jedne dwa trzy cztery";
	string s3;
	istringstream iss2(s2);

	while (iss2 >> s3) {
		cout << "* " << s3 << endl;
	}


	cin.ignore();
	return 0;
}