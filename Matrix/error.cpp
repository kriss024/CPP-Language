#include <iostream>
#include <string>

using namespace std;

string komunikat_err(int nr_komunikatu){
string komunikat;

switch(nr_komunikatu)
   {
   case 1:
      komunikat = "Nie mo¿na otworzya pliku ";
      break;
   case 2:
      komunikat = "Nie mo¿na zapisaæ pliku ";
      break;
   case 3:
      komunikat = "Liczba kolumn w pierwszej macierzy musi zgadzaæ siê z liczb¹ wierszy drugiej macierzy.";
      break;
   case 4:
      komunikat = "Macierz pusta.";
      break;
   default :
      komunikat =  "B³¹d nieokreœlony.";
}

return komunikat;
	
}
