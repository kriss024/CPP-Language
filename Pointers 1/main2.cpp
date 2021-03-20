#include <iostream>
#include <locale>
#include <cstdlib>
using namespace std;

int * funkcja_int(int &i);
int * obsluga_fun(int (*fun));

int main()
{  
	setlocale(LC_ALL, "polish");
	char * const wsk = new char[4];
	char * tab = wsk;
	tab[0]='a';
	tab[1]='b';
	tab[2]='c';
	tab[3]='\0';
	while (*tab)
	{
	cout << *tab++;
	}
	delete[] wsk;
	tab=NULL;
	cout << endl;
	//------------------------------
	int * wsk_fun;
	int w=5;
	int * (*foo)(int);
	wsk_fun = funkcja_int(w);
	cout <<"Wartoœæ: "<< *wsk_fun <<", adres: "<<wsk_fun << endl;
	cout <<"Wartoœæ obs³ugi fun: "<< *obsluga_fun(wsk_fun) <<", adres obs³ugi fun: "<<obsluga_fun(wsk_fun) << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;
	 
}
//Zwracanie wskaŸnika do fukncji
int * funkcja_int(int &i){

	return &i;
}

int * obsluga_fun(int (*fun)){
	int *fnc = new int;
	*fnc=(*fun)*2;
	return fnc;
}
