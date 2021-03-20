#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string tmp;

	if (OpenClipboard(NULL))
	{

		char* ptr = static_cast<char*>(GetClipboardData(CF_OEMTEXT));
		char* buf = static_cast<char*> (LocalAlloc(LPTR, lstrlen(ptr) + 1));

		lstrcpy(buf, ptr);
		CloseClipboard();
		tmp = buf;

		cout << tmp << endl;
	}

	cin.ignore();
	return 0;
}