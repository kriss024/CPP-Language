#include <fstream>
#include <string>
#include <windows.h> 

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	fstream plik;
	string napis;
	UINT out = 33;

	plik.open("program.cfg", ios::in);

	if (plik.is_open())
	{
		while (!plik.eof() && out > 31)
		{
			getline(plik, napis);
			out = WinExec(napis.c_str(), SW_SHOWNORMAL);
		}
		plik.close();
	}
	else {
		MessageBox(NULL, "Brak pliku konfiguracyjnego program.cfg.", "Uwaga", MB_ICONEXCLAMATION | MB_OK);
		return EXIT_FAILURE;
		}
		
	return EXIT_SUCCESS;
}