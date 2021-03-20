#include <iostream>
using namespace std;

class CRectangle {
    int x, y;
  public:
  	CRectangle(); // This is the constructor
  	CRectangle(const  CRectangle &p); // Copy constructor
    void set_values (int, int);
    int area () {return (x*y);}
    void print();
};

CRectangle::CRectangle() {
  x = 1;
  y = 1;
}

CRectangle::CRectangle(const CRectangle &p){
 x = p.x;
 y = p.y;	
}

void CRectangle::set_values (int a, int b) {
  x = a;
  y = b;
}
void CRectangle::print() {
	cout << "x = " << x << ", y = " << y <<  endl;	
}

int main() {
  CRectangle rect;
  rect.print();
  rect.set_values(3,4);
  cout << "area: " << rect.area() << endl;
  CRectangle rect2 = rect;
  rect2.print();
  cout << "area: " << rect2.area() << endl;
  return 0;
}