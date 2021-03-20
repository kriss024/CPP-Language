#include <iostream>
#include <vector>    // vector
#include <algorithm> // sort

using namespace std;

int main()
{
    vector<int> dane;

    dane.push_back(7);
    dane.push_back(6);
    dane.push_back(5);
    dane.push_back(4);
    dane.push_back(3);
    dane.push_back(2);
    dane.push_back(1);

    for(vector<int>::const_iterator it = dane.begin(); it != dane.end(); ++it)
    {
      cout << *it << ", ";
    }
    cout << endl;
    
    sort(dane.begin(),dane.end());
    
    for(vector<int>::const_iterator it = dane.begin(); it != dane.end(); ++it)
    {
      cout << *it << ", ";
    }
    cout << endl;

    for (unsigned i=0; i<dane.size(); i++)  cout << dane[i] << ". ";

    cout << endl;

    for (unsigned i=0; i<dane.size(); i++)  cout << dane.at(i) << ".. ";

    cout << endl;

    cout << "size: "<< dane.size() << endl;
    cout << "max_size in Megabyte: "<< dane.max_size()/(1024*1024) << endl;
    dane.clear();
    cout << "size: "<< dane.size() << endl;

    cin.ignore();
    return 0;

}
