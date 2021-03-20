#include <conio.h>

using namespace System;
using namespace System::Threading;

ref class MyThread
{
public: static void StaticThread()
	{
		for (int i = 0; i < 500; i++)
		{
			if (i % 10 == 0)
				Console::WriteLine("Static Thread {0}", i.ToString());
		}
	}
public: void NonStaticThread(Object ^name)
{
	for (int i = 0; i < 500; i++)
	{

		if (i % 10 == 0)
			Console::WriteLine("Member {0} Thread {1}", name, i.ToString());
	}
}
};


int main()
{
	ThreadStart ^thrStart = gcnew ThreadStart(&MyThread::StaticThread);
	Thread ^thr1 = gcnew Thread(thrStart);

	MyThread ^myThr = gcnew MyThread();
	Thread ^thr2 = gcnew Thread(gcnew ParameterizedThreadStart(myThr, &MyThread::NonStaticThread));

	thr1->IsBackground = true;
	thr1->Start();
	thr2->Start("Parameterized");

	do
	{
		Console::WriteLine("Press Escape to Exit");
	} while (_getch() != 27);
	return 0;
}