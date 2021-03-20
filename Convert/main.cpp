#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    // Konwersja z C
    long l = atol( "999999999" );
    cout << l << endl;

    int i = atoi("12345678");
    cout << i << endl;

    double d = atof("1.2345678");
    cout << d << endl;

    char buf[32];
    i = 1267;
    itoa(i, buf, 10);
    cout << buf << endl;

    itoa(i, buf, 16);
    cout <<"szesnastkowo: " << buf << endl;

    itoa(i, buf, 2);
    cout << "binarnie: " << buf << endl;

    // Konwersja z C++

    ostringstream os;
    os << i;
    string napis = os.str();
    cout << napis << endl;

    istringstream is(napis);
    i = 0;
    is >> i;
    cout << i << endl;

    return EXIT_SUCCESS;
}
