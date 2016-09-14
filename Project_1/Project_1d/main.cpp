#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "time.h"
#include <algorithm>
using namespace std;

// analytical solution of u(x)
double AnalyticalSolution(double x) {return 1 - (1 - exp(-10))*x - exp(-10*x);}
// function for generating f(x) for the discrete points
double fofx(double x) {return 100.0*exp(-10.0*x);}

int main()
{
    int m = 0;
    cout << "Give the max potens: " << endl;
    cin >> m;
    double *error = new double[m+1];
    error[0] = 0.0;
    int n = 0; // dimensions of n x n matrix

    for (int j = 1; j <= 2*m; j++)
    {

        //cout << "Give me the dimension n for the n x n matrix: " << endl;
        //cin >> n;
        double pot = j/2.0;
        n = pow(10,pot);
        cout << n << endl;
        double *d = new double[n+1]; // declaring more vector
        double *k = new double[n+1];
        double *v = new double[n+1];
        double *x = new double[n+2];
        double *btild = new double[n+1];
        double *epsilon = new double[n+1];

        double h = 1.0/(n+1); // declaring the step length h
        //cout << h << endl; // printing step length h

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
        }


        // find errors for this n:
        double lowvalue = -100.0;
        for (int i = 1; i <= n; i++)
        {
            epsilon[i] = log10(abs((v[i]-AnalyticalSolution(x[i]))/AnalyticalSolution(x[i])));
            if (epsilon[i] > lowvalue)
            {
                lowvalue = epsilon[i];
                error[j] = lowvalue;
                //cout << j << endl;
            }
        }


        cout << j/2.0 << endl;
        cout << error[j] << endl;

        for (int i = n; i >= (n-10); i--)
        {
            //cout << "num = " << v[i] << " ana = " << AnalyticalSolution(x[i]) << endl;
            //cout << "eps = " << epsilon[i] << endl;
        }
        cout << endl;
    }

    // writing to txt file v:
    ofstream outputFile;
    outputFile.open("1d.txt");

    for (int j = 1; j <= 2*m; j++)
    {
        outputFile << setiosflags(ios::showpoint | ios::uppercase);
        outputFile << setprecision(10) << setw(20) << error[j] << endl;
    }
    outputFile.close();



    return 0;
}
