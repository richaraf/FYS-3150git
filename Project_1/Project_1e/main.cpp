#include <iostream>
#include <armadillo>
using namespace arma;
using namespace std;

int main()
  {
   mat A = randu<mat>(5,5);
   mat B = randu<mat>(5,5);
   //cout << A+B << endl;
   cout << A*B;
  return 0;
  }
