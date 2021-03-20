#include <iostream>
using namespace std;

class Date
{
private:
	int mo, da, yr;
public:
	Date()
	{
		mo = 0; da = 0; yr = 0;
	}
	Date(int m, int d, int y)
	{
		mo = m; da = d; yr = y;
	}
	Date operator +(const Date& dt)
	{
		return Date(this->mo + dt.mo, this->da + dt.da, this->yr + dt.yr);
	}
	Date operator -(const Date& dt)
	{
		return Date(this->mo - dt.mo, this->da - dt.da, this->yr - dt.yr);
	}

	friend ostream& operator<<(ostream& os, const Date& dt);
};

ostream& operator<<(ostream& os, const Date& dt)
{
	os << dt.mo << '/' << dt.da << '/' << dt.yr;
	return os;
}

int main()
{
	Date dt1(5, 6, 92);
	cout << dt1 << endl;
	Date dt2(1, 1, 1);
	cout << dt2 << endl;

	Date dt3;
	dt3 = dt1 + dt2;
	cout << dt3 << endl;
	
	getchar();
	return 0;
}