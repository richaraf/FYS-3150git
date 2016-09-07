#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

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
    int *a = new int[n+1]; // declaring vectors
    int *b = new int[n+1];
    int *c = new int[n+1];
    double *d = new double[n+1]; // declaring more vector
    double *k = new double[n+1];
    double *v = new double[n+1];
    double *x = new double[n+2];
    double *btild = new double[n+1];
    double *f = new double[n+2];

    /*double *p = new double[n+1];
    for (int i=1;i<=n+1;i++)
    {
        p[i] = p[i-1]*i + i;
        cout << p[i] << endl;;
    }
    */
    double h = 1.0/(n+1); // declaring the step length h
    //cout << h << endl; // printing step length h

    for (int i = 1; i <= n+2; i++) // for-loop to generate the x-vectors elements
    {
        x[i] = i*h;
        // cout << i*h << endl;
    }
    for (int i = 1; i <= n+1; i++) // filling a, b and c
    {
        a[i] = -1;
        b[i] = 2;
        c[i] = -1;
        //cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }
    // filling f with f(x) and btild
    for (int i =1; i <= n+1; i++)
    {
        f[i] = fofx(x[i]);
        btild[i] = pow(h, 2.0)*f[i];
        //cout << "x = " << x[i] << " fi " << f[i] << " btildi " << btild[i] << endl;
    }
    d[0] = b[1];
    // gaussian elimination in for-loop:
    for (int i = 1; i <= n+1; i++)
    {
        d[i] = b[i] - (a[i-1]/d[i-1])*c[i-1];
        k[i] = btild[i] - (a[i-1]/d[i-1])*k[i-1];
        // cout << d[i] << " " << k[i] << endl;
    }
    // backward substitution:
    for (int i = n; i >= 0; i--)
    {
        v[i] = (k[i] - c[i]*v[i+1])/d[i];
        // cout << v[i] << endl;
    }
    for (int i = n-400; i<= n-380; i++)
    {
        // cout << "solution: " << AnalyticalSolution(x[i]) << " numerical: " << v[i] << endl;
    }

    // writing to txt file v:
    ofstream outputFile;
    outputFile.open("1b.txt");

    for (int i = 1; i <= n-1; i++)
    {
        outputFile << setiosflags(ios::showpoint | ios::uppercase);
        outputFile << setprecision(10) << setw(20) << v[i] << endl;
    }
    outputFile << setprecision(10) << setw(20) << v[n];
    outputFile.close();
    cout << "Program completed without crash!" << endl;
    return 0;
}
