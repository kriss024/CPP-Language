#include <iostream>
#include <string>

using namespace std;

template <class T>
class Ekran
{
private:
    T tresc;
public:
    Ekran(T tresc) {
        this->tresc=tresc;
    }
    void wyswietl() {
            cout << ":> " << tresc << endl;
     }
};


int main()
{

    Ekran<string> napis("START");
    napis.wyswietl();

    Ekran<int> liczba(123);
    liczba.wyswietl();

    Ekran<double> liczba01(123.45);
    liczba01.wyswietl();

    return 0;
}
