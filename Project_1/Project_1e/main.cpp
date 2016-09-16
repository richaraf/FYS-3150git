#include <iostream>
#include <armadillo>
#include <cmath>
#include <iomanip>

using namespace arma;
using namespace std;

// analytical solution of u(x)
double AnalyticalSolution(double x) {return 1 - (1 - exp(-10))*x - exp(-10*x);}
// function for generating f(x) for the discrete points
double fofx(double x) {return 100.0*exp(-10.0*x);}


int main()
  {
    int n = 0; // dimensions of n x n matrix
    cout << "Give me the dimension n for the n x n matrix: " << endl;
    cin >> n;
    mat A = zeros<mat>(n,n);
    mat L = zeros<mat>(n,n);
    mat U = zeros<mat>(n,n);
    mat btilde = zeros<mat>(n,1);
    double h = 1.0/(n+1);
    double *xcoord = new double[n+1];

    int diag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diag = 0;
            if (i == j){
                A(i, j) = 2;
                diag = 1;
            }
            if (i == j+1 || j == i+1 ){
                A(i, j) = -1;
                diag = 1;
            }
            if (diag == 0){
                A(i, j) = 0;
            }

        }
    }

    for (int i = 0; i < n; i++)
    {
        xcoord[i] = i*h;
        btilde[i] = pow(h, 2.0)*fofx(xcoord[i]);
    }

    // Start timer
    clock_t start, finish;
    start = clock();

    lu(L,U,A);

    vec y = solve(L,btilde);
    vec v = solve(U,y);
    // /*
    for (int i = 0; i< n; i++)
        {
            cout << "num: " << v[i] << "ana: " << AnalyticalSolution(xcoord[i+1]) << endl;
        }
// */
    // End timer
    finish = clock();
    ((finish-start)/CLOCKS_PER_SEC);
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
    cout << setiosflags(ios::showpoint | ios::uppercase);
    cout << setprecision(10) << setw(20) << "Time used =" << timeused  << endl;

    cout << "Program completed without crash!" << endl;

    return 0;
  }
