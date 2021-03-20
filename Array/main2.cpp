#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    char greeting[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' };

    cout << "C-Strings: ";
    cout << greeting << endl;

    for (int i=0; i<strlen(greeting); i++){

       cout << greeting[i];
    }
    cout << endl;

    return EXIT_SUCCESS;

}