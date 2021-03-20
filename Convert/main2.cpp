#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    double fLiczba = 123.456;
    string sLiczba = to_string(fLiczba);
    cout << "fLiczba = " << fLiczba << "; sLiczba = " << sLiczba << ";" << endl;

    int iLiczba = 42;
    ostringstream ostr;
    ostr << iLiczba;
    string sLiczba2 = ostr.str();
    cout << "iLiczba = " << iLiczba << "; sLiczba = " << sLiczba2 << ";" << endl;
    return 0;
}
