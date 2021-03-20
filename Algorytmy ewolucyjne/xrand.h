#ifndef XRAND_H_INCLUDED
#define XRAND_H_INCLUDED

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	// Generator liczb losowych.
	// Jest to statyczna klasa, pozwalajaca na generowanie losowych wartosci
	// z wybranym rozkladem prawdopodobienstwa.

class XRand
{
private:
    // Rejestry generatora.
    static double a;
    static double b;
    static double c;
public:
    // Losowe inicjowanie generatora.
    // Wywolanie tej metody spowoduje losowe wybranie wartosci rejestrów generatora.
    // Wbudowany generator liczb losowych inicjowany jest przy pomocy czasu systemowego,
    // po czym wartosci rejestrów losowane sa funkcja rand().
    static void Randomize();

    // Inicjowanie generatora do wybranego stanu.
    // Dzieki tej metodzie mozemy zainicjowac wartosc rejestrów generatora
    // do wybranych wartosci. Przydatne, gdy potrzebujemy uzyskac taki sam
    // losowy ciag kilka razy.
    static void Randomize(const int& r1, const int& r2, const int& r3);

    // Rozkla równomierny.
    // Generuje liczby losowe z rozkladem U(0,1).
    static double Uniform();

    // Rozklad równomierny.
    // Generuje liczby losowe z rozkladem U(min,max).
    static double Uniform(const double& min, const double& max);

    // Rozklad równomierny.
    // Generuje liczby losowe (calkowite) z rozkladem U(min,max).
    static int Uniform(const int& min, const int& max);

    // Rozklad normalny.
    // Generuje liczby losowe z rozkladem N(0,1).
    static double Normal();

    // Rozklad normalny.
    // Generuje liczby losowe z rozkladem N(avg,dev).
    static double Normal(const double& avg, const double& dev);

    // Rozklad geometryczny.
    // Generuje liczby losowe z rozkladem G(p).
    static int Geometric(const double& p);

    // Rozklad dwumianowy.
    // Generuje liczby losowe z rozkladem B(n,p).
    static int Binominal(int n, const double& p);

    // Rozklad binarny (Bernoulliego).
    // Generuje liczby losowe z rozkladem B(0.5).
    static bool Binary();

    // Rozklad binarny (Bernoulliego).
    // Generuje liczby losowe z rozkladem B(p).
    static bool Binary(const double& p);
};

#endif // XRAND_H_INCLUDED
