#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << endl;
    Swap(i,j);
    cout << "Now i, j = " << i << ", " << j << endl;

    double x = 2.5;
    double y = 8.7;
    cout << "x, y = " << x << ", " << y << endl;
    Swap(x,y);
    cout << "Now x, y = " << x << ", " << y << endl;

    return 0;
}

