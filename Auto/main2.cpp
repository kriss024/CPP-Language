#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void fun1(int x)
{
    cout << x << " ";
}

struct Class1
{
    void operator() (int x)
    {
        cout << x << " ";
    }
} obj1;


int main()
{
    int arr[] = {11, 21, 4, 13};
    for_each(arr, arr + 4, fun1);
    cout << endl;
    for_each(arr, arr + 4, obj1);
    cout << endl;

    vector<int> v1;
    v1.push_back(11);
    v1.push_back(23);
    v1.push_back(4);
    v1.push_back(15);

    for_each(v1.begin(), v1.end(), fun1);
    cout << endl;
    for_each(v1.begin(), v1.end(), obj1);

    getchar();
    return 0;
}
