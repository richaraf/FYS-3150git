#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "time.h"
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
    double *d = new double[n+1]; // declaring more vector
    double *k = new double[n+1];
    double *v = new double[n+1];
    double *x = new double[n+2];
    double *btild = new double[n+1];

    double h = 1.0/(n+1); // declaring the step length h
    //cout << h << endl; // printing step length h

    // Start timer
    clock_t start, finish;
    start = clock();


    for (int i = 1; i <= n+2; i++) // for-loop to generate the x-vectors elements
    {
        x[i] = i*h;
        // cout << i*h << endl;
    }
    d[1] = 2;
    k[1] = pow(h,2.0)*fofx(x[1]);

    // gaussian elimination in for-loop:
    for (int i = 2; i <= n+1; i++) // filling btild, and d and k.
    {
        btild[i] = pow(h, 2.0)*fofx(x[i]);
        d[i] = 2-1.0/d[i-1];  //b[i] - (a[i-1]/d[i-1])*c[i-1];
        k[i] = btild[i] + k[i-1]/d[i-1]; //btild[i] - (a[i-1]/d[i-1])*k[i-1];
        //cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }

    // backward substitution:
    for (int i = n; i >= 0; i--)
    {
        v[i] = (k[i] + v[i+1])/d[i]; // (k[i] + v[i+1])/d[i];
        //cout << "num = " << v[i] << "ana = " << AnalyticalSolution(x[i]) << endl;
    }

    // End timer
    finish = clock();
    ((finish-start)/CLOCKS_PER_SEC);
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
    cout << setiosflags(ios::showpoint | ios::uppercase);
    cout << setprecision(10) << setw(20) << "Time used =" << timeused  << endl;

    return 0;
}
