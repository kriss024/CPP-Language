#include "matrix.h"
#include <iostream>

using namespace std;


int main(int argc, char **argv) {
	QSMatrix<double> mat1(10, 10, 1.0);
	QSMatrix<double> mat2(10, 10, 2.0);

	QSMatrix<double> mat3 = mat1 + mat2;

	for (int i = 0; i<mat3.get_rows(); i++) {
		for (int j = 0; j<mat3.get_cols(); j++) {
			cout << mat3(i, j) << ", ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}