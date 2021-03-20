/* signal example */
#include <iostream>
#include <signal.h>     /* signal, raise, sig_atomic_t */

using namespace std;

sig_atomic_t signaled = 0;

void my_handler(int param)
{
	signaled = 1;
}

int main()
{
	void(*prev_handler)(int);

	prev_handler = signal(SIGINT, my_handler);

	/* ... */
	raise(SIGINT);
	/* ... */

	cout << "signaled is " << signaled << endl;

	getchar();
	return 0;
}