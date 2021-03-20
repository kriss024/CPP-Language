#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "error.h"      

using namespace std;

//------------------------------------------------

void WczytajMacierz(string nazwa, vector<double>& wektor,int& k, int& w){
	int wiersze = 0;
	int kolumny = 0;	
	string line;
    double liczba;
    wektor.clear();
    
 	ifstream file(nazwa.c_str());
    
 	
 	if (file.is_open()){
	  

    	while (getline(file, line))  
    	{	
    		
    		wiersze++;
    		kolumny = 0;
        	istringstream iss(line);

        	while (iss.good())
        	{
        		string elem;
            	iss >> elem;
            	liczba = atof(elem.c_str());
            	wektor.push_back(liczba);
            	kolumny++;          
        	}
    	}	
	file.close();
	
	if (wektor.size()==0){
		cout << komunikat_err(4) << endl; 
		exit(1);
	}
	
	k=kolumny;
	w=wiersze;
	cout << "Nazwa pliku: "<< nazwa << endl; 
	cout << "Wiersze: "<< w << endl; 
	cout << "Kolumny: "<< k << endl; 
	cout << "Liczba wczytanych komórek: "<< wektor.size()  << endl; 
	
	
	
} else {
		cout << komunikat_err(1) << nazwa << endl; 
		exit(1);
	}
	
}

//------------------------------------------------

void PokazMacierz(vector<double>& wektor,int& k, int& w){
int a=0;
for(int y = 0; y < w; y++){
	for(int x = 0; x < k; x++){
		cout << wektor[a] << " ";
		a++;
	   }
	   cout << endl;
}	
	
}	

//------------------------------------------------

void MnozenieMacierzy(vector<double>& wektor1,int& k1, int& w1,vector<double>& wektor2,int& k2, int& w2,vector<double>& wektor3,int& k3, int& w3){
double macierz1[w1][k1];
double macierz2[w2][k2];
int a=0;
for(int y = 0; y < w1; y++){
	for(int x = 0; x < k1; x++){
		macierz1[y][x] = wektor1[a];
		a++;
	   }
}	

a=0;
for(int y = 0; y < w2; y++){
	for(int x = 0; x < k2; x++){
		macierz2[y][x] = wektor2[a];
		a++;
	   }
}	

if (k1!=w2) {
		cout << komunikat_err(3) << endl; 
		exit(1);
} else {
	
//--------------	

wektor3.clear();
k3=k2;
w3=w1;	
double wynik[w1][k2];	
double liczba=0;

for(int y = 0; y < w1; y++){
	for(int x = 0; x < k2; x++){
		liczba=0;
		for(int r = 0; r< k1; r++){
			liczba = liczba + macierz1[y][r]*macierz2[r][x];
		} 
		wynik[y][x] = liczba;
		wektor3.push_back(wynik[y][x]);
	   }
}	
	
//--------------	
	
}

	
}	


//------------------------------------------------

void ZapisDoPliku(vector<double>& wektor,int& k, int& w,string nazwa){

cout << "Zapisywanie do pliku "<< nazwa << endl;

ofstream file (nazwa.c_str());
  if (file.is_open())
  {
    int a=0;
	for(int y = 0; y < w; y++){
	for(int x = 0; x < k; x++){
		file << wektor[a] << " ";
		a++;
	   }
	   file << endl;
}	

    file.close();
  }
  else cout << komunikat_err(2) << nazwa << endl; 

}	

	
//------------------------------------------------
int main(int argc, char** argv) {
	
	int wiersz1;
	int kolumn1;	
	int wiersz2;
	int kolumn2;	
	int wiersz3;
	int kolumn3;	
		
	vector <double> wektor1;
	vector <double> wektor2;
	vector <double> wynik;
	
    
	WczytajMacierz("plik1.txt",wektor1,kolumn1,wiersz1);
	PokazMacierz(wektor1,kolumn1,wiersz1);
	
	WczytajMacierz("plik2.txt",wektor2,kolumn2,wiersz2);
	PokazMacierz(wektor2,kolumn2,wiersz2);	
	
	MnozenieMacierzy(wektor1,kolumn1,wiersz1,wektor2,kolumn2,wiersz2,wynik,kolumn3,wiersz3);
	cout << "Mno¿enie macierzy"<< endl; 
	PokazMacierz(wynik,kolumn3,wiersz3);
	ZapisDoPliku(wynik,kolumn3,wiersz3,"plik3.txt");
	
    cout << "Naciœnij Enter."<< endl; 
    cin.get();
    return EXIT_SUCCESS;
}


