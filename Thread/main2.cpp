// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex      

const int MAX_ITER = 10000001;
const int ITER = 1000000;

using namespace std;

mutex mtx;
 
 void print(int x, const char arr[]){
	 
	 cout << arr <<" value: " << x << endl;

	 }
 
 // -------------------------------------------------
void foo() 
{
  for( int a = 0; a < MAX_ITER; a++ )
   {
       if (a%ITER==0) {
		   mtx.lock();
			print(a,"foo");
		   mtx.unlock();
		}
		   
   }
}

 // -------------------------------------------------

void bar(int x)
{
    for( int b = x; b < MAX_ITER; b++ )
   {
       if (b%ITER==0) {
		   mtx.lock();
			print(b,"bar");
		   mtx.unlock();
		}
   }
}

 // -------------------------------------------------

int main() 
{
  thread first (foo);     // new thread that calls foo()
  thread second (bar,0);  // new thread that calls bar(0)

  cout << "main, foo and bar now execute concurrently..." << endl;

  // synchronize threads:
  first.join();                // main thread waits for first to finish
  second.join();               // main thread waits for second to finish

  cout << "foo and bar completed." << endl;
  cin.ignore();
  return 0;
}