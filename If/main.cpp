#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a = 4;
    int b = 10;
    // WARUNEK ? jezeli warunek jest prawdziwy, czyli jest rozny od zera to wykonaj te tutaj instrukcje : w innym wypadku te tutaj;
    string nazwa = a > b ? "a jest wieksze od b" : "a jest mniejsze od b, badz tez rowne b";
        
    cout << nazwa << endl;
        
    cout << (a > b ? a : b) + 10 << endl;
    
    system("pause");
}
