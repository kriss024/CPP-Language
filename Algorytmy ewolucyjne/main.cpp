#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <time.h>
#include "osobnik.h"

using namespace std;

int _N = 2;      // Rozmiar osobników (ilość wymiarów)
int _EliteSize = 4;  // Rozmiar elity z osobników rodzicielskich
int _Mi = 20;    // Ilość osobników rodzicielskich (juz bez elity)
int _Lambda = 168;  //Ilość osobników potomnych
int _Iterations = 3; // Ilosc iteracji algorytmu
double _MutationProbability = 0.5; // Prawdopodobienstwo wystapienia mutacji
double _MutationStdDev = 0.1;  // Odchylenie standardowe mutacji
double _FeneMinimum = -100.0;  // Dolne ograniczenie wartosci fenu
double _FeneMaximum = 100.0;   // Górne ograniczenie wartosci fenu

int main(int argc, char* argv[])
{
    // Odczytujemy parametry uruchomienia programu
    switch (argc)
    {
        case 10: _FeneMaximum = atof(argv[9]);
        case  9: _FeneMinimum = atof(argv[8]);
        case  8: _MutationStdDev = atof(argv[7]);
        case  7: _MutationProbability = atof(argv[6]);
        case  6: _Iterations = atoi(argv[5]);
        case  5: _EliteSize = atoi(argv[4]);
        case  4: _Lambda = atoi(argv[3]);
        case  3: _Mi = atoi(argv[2]);
        case  2: _N = atoi(argv[1]);
    }

    // Sprawdzenie poprawnosci podanych na wstępie parametrów
    if (
        _N < 1 ||
        _EliteSize < 1 || _EliteSize > _Lambda ||
        _Mi < 1 ||
        _Lambda < 1 ||
        _Mi < _EliteSize ||
        _Iterations < 1 ||
        _MutationProbability < 0.0 || _MutationProbability > 1.0 ||
        _MutationStdDev < 0.0 ||
        _FeneMinimum >= _FeneMaximum
    )
    {
        exit(1);
    }

    // Ustawiamy dolne i górne ograniczenie dla poczatkowej wartosci fenów osobnika.
    Osobnik::FeneMinimum = _FeneMinimum;
    Osobnik::FeneMaximum = _FeneMaximum;


    // W strategii mi+lambda do kolejnej epoki przechodzi mi wybranych osobników
    // rodzicielskich (niezmienionych) i lambda ich potomków.
    // Dodatkowo stosujemy sukcesję elitarną, więc zadana ilość najlepszych
    // osobników przejdzie bezpośrednio do kolejnej populacji (bez selekcji).
    // Rozmiar populacji ustalamy tak, aby pomieściła ona osobniki elitarne
    // (_EliteSize), rodzicielskie (_Mi) i potomne (_Lambda).
    int P = _EliteSize + _Mi + _Lambda;


    XRand::Randomize(); // Inicjujemy generator liczb losowych
     time_t CzasZnaki = time(0);
     stringstream ss;
     string CzasLancuch;
     ss << CzasZnaki;
     ss >> CzasLancuch;
     string NazwaPliku = CzasLancuch+"_result.txt"; // Plik wynikowy z datą wykonania w nazwie pliku
     ofstream PlikWynikowy( NazwaPliku.c_str() );

    vector<Osobnik>* BasePopulation;  // Populacja bazowa
    vector<Osobnik>* NextPopulation;  // Populacja potomna
    vector<Osobnik>* TempPopulation;  // Populacja tymczasowa
    vector<Osobnik>* Temp;            // Pomocniczy wskaznik

    vector<Osobnik>::iterator BestOsobnikInPopulation; // Iterator (wskaznik) do najlepszego osobnika w populacji
    Osobnik BestOsobnik(_N);  // Kopia najlepszego osobnika w calym przebiegu algorytmu
    BasePopulation = new vector<Osobnik>(P, _N);  // Inicjowanie populacji wyjsciowej
    TempPopulation = new vector<Osobnik>(P, _N);  // Inicjowanie populacji tymczasowej
    NextPopulation = new vector<Osobnik>(P, _N);  // Inicjowanie populacji potomnej
    //NextPopulation = new vector<Osobnik>(P, BasePopulation->at(0)); //W nowej populacji umieszczamy kopie pierwszego osobnika z populacji bazowej


int i, j;
    // ------ocena populacji wyjściowej -------
    // Wybieramy najlepszego osobnika z losowej populacji bazowej (wyjściowej) i kopiujemy go jako pierwszego najlepszego osobnika.
    // Najlepszy osobnik, to ten o najmniejszej wartości składowej "Value". Klasa Osobnik ma przeciążony operator <,
    // który porównuje osobniki na podstawie tej właśnie składowej, więc wystarczy wykorzystać funkcję min_element.
    BestOsobnik = *min_element(BasePopulation->begin(), BasePopulation->end());
    // Informacja o najlepszym osobniku w populacji wyjsciowej (losowej) jest zapisywana w pliku wynikowym.
    // Kazda kolejna linia w pliku wynikowym bedzie zawierala informacje o najlepszym osobniku w kolejnych epokach.
    // W kazdej linii znajdzie sie numer epoki, wartosci poszczególnych fenów najlepszego osobnika i wartosc funkcji celu dla tych wartosci.
    PlikWynikowy << "0000000:";
    for (j=0; j<_N; ++j)
    {
        PlikWynikowy
            << fixed << setprecision(12)
            << "\t" << BestOsobnik.GetFene(j);
    }
    PlikWynikowy
        << fixed << setprecision(12)
        << "\t\t" << BestOsobnik.GetValue() << endl;


    //---------------------------------------------------------------------------------------------
    // Petla algorytmu strategii ewolucyjnej mi+lambda.
    //---------------------------------------------------------------------------------------------

    for (i=1; i<=_Iterations; ++i)
    {
        //------wybór elity - najlepszych osobników w danej populacji bazowej -------
        // Selekcja deterministyczna, sukcesja elitarna.  Sortujemy osobniki w populacji i określoną parametrem _EliteSize liczbę najlepszych
        // osobników kopiujemy do następnej populacji. Osobniki te przechodzą bez zmian do następnej populacji.
        sort(BasePopulation->begin(), BasePopulation->end());
        for (j=0; j<_EliteSize; ++j)
        {
            (*TempPopulation)[j] = (*BasePopulation)[j];  //wybór 4 najlepszych osobników  - tzw. elity
        }

        // Reprodukcja (preselekcja)– powielenie losowo wybranych elementów z populacji bazowej do populacji tymczasowej;
        // Kopie powstałe w wyniku reprodukcji – osobniki rodzicielskie – populacja tymczasowa
        for (j=_EliteSize; j<(_EliteSize+_Mi); ++j)
        {
            (*TempPopulation) [j] = *min_element(BasePopulation->begin(), BasePopulation->end());
        }


        //--------------krzyżowanie--------------
        if (_Lambda%2)
        {
            // Jesli ilosc miejsc w populacji tymczasowej dostepnych dla osobników potomnych jest nieparzysta,
            // to wykonujemy raz krzyzowanie uśredniające, którego wynikiem jest jeden potomek.
            Crossover(
                (*TempPopulation)[XRand::Uniform(0, _Mi)],
                (*TempPopulation)[XRand::Uniform(0, _Mi)],
                (*TempPopulation)[j++]
            );
        }
        while (j<P)
        {
            // Jeśli ilość miejsc dostępnych dla osobników potomnych jest parzysta, to dopóki jest miejsce
            // w populacji tymczasowej określone poprzez _P_mi_lambda, to przeprowadzamy operacje krzyzowania,
            // w której para losowych rodziców generuje dwóch potomków. Rodzice są losowani z pozycji od 0 do _Mi,
            // kolejne miejsca w populacji tymczasowej zajmują osobniki potomne
            Crossover(
                (*TempPopulation)[XRand::Uniform(0, _Mi)],
                (*TempPopulation)[XRand::Uniform(0, _Mi)],
                (*TempPopulation)[j++],
                (*TempPopulation)[j++]
            );
        }

        // -------------- Mutacja i testowanie potomków--------------------
        // Kazdy z potomków w populacji tymczasowej jest poddawany operacji mutowania z zadanym
        // prawdopodobienstwem mutacji i odchyleniem standardowym.
        // Po tej operacji potomek jest oceniany przy pomocy funkcji celu.
        for (j=(_EliteSize + _Mi); j<P; ++j)
        {
            (*TempPopulation)[j].Mutate(_MutationProbability, _MutationStdDev);
            (*TempPopulation)[j].Test();
        }


        //-----------wybór nowej populacji bazowej-----------------
        // Selekcja deterministyczna. Sukcesja elitarna. Do kolejnej epoki trafi _Mi najlepiej przystosowanych
        // osobników z populacji rodzicielskiej i potomnej i stworzy nową populację bazową
        sort(TempPopulation->begin(), TempPopulation->end());
        for (j=0; j<_Mi; ++j)
        {
            (*NextPopulation)[j] = (*TempPopulation)[j];  // wybór _Mi najlepszych osobników z całej populacji tymczasowej
        }

        // Aby nie kopiować wartości wszystkich osobników z powrotem do populacji bazowej,
        // zamieniamy miejscami populację bazową z populacją następną (obie mają ten sam rozmiar).
        // Dzięki temu kopiujemy tylko wartości wskaźników, a nie wartości każdego osobnika.
        Temp = BasePopulation;
        BasePopulation = NextPopulation;
        NextPopulation = Temp;

        // Wybieramy najlepszego osobnika w nowej populacji bazowej.
        BestOsobnikInPopulation = min_element(
            BasePopulation->begin(), BasePopulation->end()
        );

        // Jeśli najlepszy osobnik w nowej populacji jest lepszy od dotychczasowego najlepszego osobnika,
        // kopiujemy go jako nowego najlepszego osobnika.
        if (BestOsobnikInPopulation->GetValue() < BestOsobnik.GetValue())
        {
            BestOsobnik = *BestOsobnikInPopulation;
        }

        // Wypisujemy do pliku informację o najlepszym osobniku w danej epoce.
        PlikWynikowy << setfill('0') << setw(7) << i << ":";
        for (j=0; j<_N; ++j)
        {
            PlikWynikowy
                << fixed << setprecision(12)
                << "\t" << BestOsobnikInPopulation->GetFene(j);
        }
        PlikWynikowy
            << fixed << setprecision(12)
            << "\t\t" << BestOsobnikInPopulation->GetValue() << endl;
    }

    // Wypisujemy do pliku wynikowego informację o najlepszym osobniku w całym przebiegu algorytmu.
    PlikWynikowy << endl << "   BEST:";
    for (j=0; j<_N; ++j)
    {
        PlikWynikowy
            << fixed << setprecision(12)
            << "\t" << BestOsobnik.GetFene(j);
    }
    PlikWynikowy
        << fixed << setprecision(12)
        << "\t\t" << BestOsobnik.GetValue() << endl;

    // Wyświetlamy najlepszy wynik na konsoli.
    cout<< fixed << setprecision(12) << BestOsobnik.GetValue() << "\t";

    // Zamykamy plik wynikowy.
    PlikWynikowy.close();

    // Zwalniamy pamięć zajmowaną przez populacje.
    delete BasePopulation;
    delete NextPopulation;
    delete TempPopulation;

    return 0;
}
