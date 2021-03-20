#ifndef OSOBNIK_H_INCLUDED
#define OSOBNIK_H_INCLUDED

#include "xrand.h"
#include <vector>

using namespace std;

// Klasa reprezentujaca osobnika - rozwiazanie N-wymiarowej funkcji Schaffera F7.
class Osobnik
{
private:
    // Rozmiar osobnika.
    // N okresla, ilu-wymiarowy jest dany osobnik, czyli jak dlugi jest wektor zmiennych (fenotyp).
    int N;

    // Fenotyp.
    // Wektor liczb - zmiennych w funkcji Schaffera F7, ktory stanowi fenotyp danego osobnika.
    vector<double> Fenotype;

    // Wartosc funkcji Schaffera F7 dla danego osobnika.
    // Im mniejsza wartosc funkcji, tym lepiej dopasowany jest osobnik.
    double Value;

public:
    // Konstruktor domyslny
    Osobnik();

    // Konstruktor tworzacy losowego, n-wymiarowego osobnika.
    Osobnik(const int& n);

    // Konstruktor kopiujacy - tworzacy dokladna kopie podanego osobnika.
    Osobnik(const Osobnik& base);

    // Destruktor.
    ~Osobnik();

    // Pobieranie wartosci funkcji.
    // Zwraca wartosc funkcji celu dla danego osobnika.
    double GetValue();

    // Pobieranie wartosci fenu.
    // Zwraca wartosc konkretnego fenu osobnika.
    double GetFene(const int& i);

    // Testowanie osobnika.
    // Metoda sprawdza dopasowanie osobnika przy pomocy funkcji Schaffera.
    double Test();

    // Krzyzowanie osobników.
    friend void Crossover(Osobnik& p1, Osobnik& p2, Osobnik& ch1, Osobnik& ch2);
    friend void Crossover(Osobnik& p1, Osobnik& p2, Osobnik& ch);

    // Mutacja.
    // Metoda przeprowadza mutacje osobnika z rozkladem normalnym.
    // Prawdopodobienstwo mutacji i odchylenie standardowe przekazane sa jako parametry.
    void Mutate(double mp, double stdev);

    // Operator <.
    // Przeciazony operator < porównuje osobniki pod katem wartosci skladowej Value.
    // Osobnik, który ma mniejsza wartosc tej skladowej, bedzie mniejszy przy porównywaniu z tym operatorem.
    bool operator < (const Osobnik& s) const;

    // Operator =.
    // Przeciazony operator = zmienia osobnika tak, aby byl identyczny z podanym.
    Osobnik& operator = (const Osobnik& s);

    // Minimalna wartosc dla fenów.
    // Statyczna zmienna okreslajaca dolna granice dla wartosci fenów osobnika przy ich losowaniu.
    static double FeneMinimum;

    // Maksymalna wartosc dla fenów
    // Statyczna zmienna okreslajaca górna granice dla wartosci fenów osobnika przy ich losowaniu.
    static double FeneMaximum;
};

#endif // OSOBNIK_H_INCLUDED
