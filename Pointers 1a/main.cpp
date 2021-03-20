#include <iostream>
#include <cstdlib>
#include <cmath>  

using namespace std;

typedef double (*D2D)(double);

const int w=4;

double my_func(double x);

D2D D2D_arr[w]={&my_func,&sin,&cos,&exp};

D2D funkcja;

double eps=10e-4;

double adres=0;

D2D wfun(D2D* tab,int size, double a, double b, double& pxmax);


int main()
{
	funkcja = wfun(D2D_arr,w,1,5,adres);
	cout  <<  "Wartości funkcji: "<< funkcja(adres) <<  " x: "  << adres  <<  endl;
	system("pause");
    return 0;
}


double my_func(double x)
{
    return sin(x)*cos(x);
}

D2D wfun(D2D* tab,int size, double a, double b, double& pxmax){
	
	D2D fun_local;
	D2D best_fun;
	fun_local=*tab;
	double max_f=fun_local(a);
	
	for (int i=0; i<size; i++){
		
		fun_local = *(tab+i);
		
		for( double x = a; x <b; x += eps )
			{
				if (fun_local(x)>max_f){
					max_f=fun_local(x);
					best_fun = *(tab+i);
					pxmax = x;
				}
			}

	}
	return best_fun;
}
