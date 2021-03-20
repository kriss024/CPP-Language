#include <iostream>
#include <thread>
#include <string>

using namespace std;

void ThreadTask(string name)
{
	for (unsigned int i = 0; i < 20; ++i)
	{
		cout << "Output from " << name << " thread " << endl;
	}
}

int main(int argc, char* argv[])
{
	const unsigned int numberOfProcessors{ thread::hardware_concurrency() };
	cout << "This system can run " << numberOfProcessors << " concurrent tasks" << endl;

	if (numberOfProcessors > 1)
	{
		thread myThread(ThreadTask, "task 1");
		thread myThread2(ThreadTask, "task 2");
		cout << "Output from main" << endl;

		myThread.join();
		myThread2.join();
		cout << "All threads finish" << endl;
	}
	else
	{
		cout << "CPU does not have multiple cores." << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}