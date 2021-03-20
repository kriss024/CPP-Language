#include <iostream>
#include <string>

using namespace std;

int main()
{
    string film("Pingwiny z Madagaskaru");
    cout << film[0] << endl;
    cout << film[9] << endl;

    cout << film.empty() << endl;

    cout << film.substr(11,10) << endl;

    cout << film.length() << endl;
    cout << film.size() << endl;

    cout << film.max_size() << endl;

    film.resize(8);
    cout << film << endl;

    film.resize(25);
    cout << film << "<:" << endl;

    film.clear();
    cout << film << "<:" << endl;

    cout << film.empty() << endl;

    return 0;
}
