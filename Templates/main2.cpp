#include <iostream>

using namespace std;

template <int ilosc, class typ>
struct tablica
{
    typ calatablica[ilosc];
}; //nasza tablica

int main()
{
    const int a = 2;
    tablica <a, int> liczby; //możemy szybko stworzyć tablicę o dowolnym typie

    liczby.calatablica[0] = 5;
    cout << liczby.calatablica[0] << endl;

    return 0;
}
