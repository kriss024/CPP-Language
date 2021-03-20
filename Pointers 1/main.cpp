#include <iostream>
#include <cstdlib>
#include <cmath>   
using namespace std;

double*  aver(double*  arr,  size_t  size,  double&  average);

int main(int argc, char** argv) {
	
	double  arr[]  =  {1,2,3,4,5,7};
	size_t size  =  sizeof(arr)/sizeof(arr[0]);
	double  average  =  0;
	double*  p  =  aver(arr,size,average);
	cout  <<  *p  <<  "  "  <<  average  <<  endl;
	return 0;
}

double*  aver(double*  arr,  size_t  size,  double&  average)
{
  average = 0;
  for (int i=0; i<size; i++) {
    average =  average + *(arr+i);
  }
  average = average/size;
  double  min  =  abs(average - *arr);
  int index = 0;
  
  for (int i=0; i<size; i++) {
  	
  	if( abs(average - *(arr+i)) < min ) {
  		min  =  abs(average - *(arr+i));
  		index = i; 		
  	}

  }

  return arr+index;
}
