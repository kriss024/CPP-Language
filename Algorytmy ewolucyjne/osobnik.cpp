#include "osobnik.h"

double Osobnik::FeneMinimum = -100.0;
double Osobnik::FeneMaximum = 100.0;

// Konstruktor domyslny
Osobnik::Osobnik()
{
    N = 0;
}

// Konstruktor tworzacy losowego, n-wymiarowego osobnika.
Osobnik::Osobnik(const int& n)
{
    N = n;     // Rozmiar osobnika N okresla, ilu-wymiarowy jest dany osobnik, czyli jak dlugi jest wektor zmiennych (fenotyp).
    Fenotype.resize(N); // Fenotyp - Wektor liczb - zmiennych w funkcji Schaffera F7
    for (int i=0; i<N; ++i)
    {
        // Wartosci fenów losujemy z rozkladem równomiernym.
        Fenotype[i] = XRand::Uniform(FeneMinimum, FeneMaximum);
    }
    Test();
}

Osobnik::Osobnik(const Osobnik& base)
{
    N = base.N;
    Fenotype = base.Fenotype;
    Value = base.Value;
}

Osobnik::~Osobnik()
{
}

// Zwraca wartosc funkcji celu dla danego osobnika.
double Osobnik::GetValue()
{
    return Value;
}

// Zwraca wartosc konkretnego fenu osobnika.
double Osobnik::GetFene(const int& i)
{
    return Fenotype.at(i);
}

// Metoda sprawdza dopasowanie osobnika przy pomocy funkcji Schaffera.
double Osobnik::Test()
{
    double sum = 0.0;
    // Funkcja Schaffera F7:  f(x) = (sum (x(i))^2)^0,25  *  [ sin^2 (50 * (sum(x(i)^2)^0,1  + 1]
    Value = 0;
    for (int i=0; i<N; ++i)
    {
        sum += Fenotype[i] * Fenotype[i];
    }
    double const a = pow(sum,0.25);
    double const b = pow(sum,0.1);
    Value =  a * ( sin(50*b) * sin(50*b) +1 );
    return Value;
}

// Krzyzowanie osobników.
void Crossover(Osobnik& p1, Osobnik& p2, Osobnik& ch1, Osobnik& ch2)
{
    int N = p1.N;
    int r = XRand::Uniform(0, N);
    for (int i=0; i<r; ++i)
    {
        ch1.Fenotype[i] = p1.Fenotype[i] + ( XRand::Normal() * (p2.Fenotype[i] - p1.Fenotype[i]) );
        ch2.Fenotype[i] = p2.Fenotype[i] + p1.Fenotype[i] - ch1.Fenotype[i];
    }
}

void Crossover(Osobnik& p1, Osobnik& p2, Osobnik& ch)
{
    int N = p1.N;
    int r = XRand::Uniform(0,N);
    for (int i=0; i<r; ++i)
    {
       ch.Fenotype[i] = p1.Fenotype[i] + ( XRand::Normal() * (p2.Fenotype[i] - p1.Fenotype[i]) );
    }
}
// Mutacja jest operatorem genetycznym, który tworzy nowe osobniki poprzez modyfikacje genów istniejących osobników.
// Z mutacją jest związany parametr zwany prawdopodobieństwem mutacji pm określający, z jakim prawdopodobieństwem
// dany  gen  zostanie  zmodyfikowany.
// Metoda przeprowadza mutacje osobnika z rozkladem normalnym.
// Prawdopodobienstwo mutacji i odchylenie standardowe przekazane sa jako parametry.

void Osobnik::Mutate(double mp, double stdev)
{
    for (int i=0; i<N; ++i)
    {
        if (XRand::Binary(mp))
        {
            Fenotype[i] += XRand::Normal(0.0, stdev);
        }
    }
}

// Przeciazony operator < porównuje osobniki pod katem wartosci skladowej Value.
bool Osobnik::operator < (const Osobnik& s) const
{
    return Value < s.Value;
}

// Przeciazony operator = zmienia osobnika tak, aby byl identyczny z podanym.
Osobnik& Osobnik::operator = (const Osobnik& s)
{
    N = s.N;
    Fenotype = s.Fenotype;
    Value = s.Value;

    return *this;
}

