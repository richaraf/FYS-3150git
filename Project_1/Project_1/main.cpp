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
    double *x = new double[n+1];
    double *btild = new double[n+1];

    double h = 1.0/(n+1); // declaring the step length h
    //cout << h << endl; // printing step length h


    for (int i = 1; i <= n+2; i++) // for-loop to generate the x-vectors elements
    {
        x[i] = i*h;
        // cout << i*h << endl;
    }
    d[1] = 2;
    a[1] = -1;
    c[1] = -1;
    k[1] = pow(h,2.0)*fofx(x[1]);

    for (int i = 2; i <= n+1; i++)
    {
        // First fill the known vectors a, b, c and btild with their values.
        a[i] = -1;
        b[i] = 2;
        c[i] = -1;
    }


    // Start timer
    clock_t start, finish;
    start = clock();


    // Implementation of gaussian elimination:
    for (int i = 2; i <= n+1; i++)
    {
        btild[i] = pow(h, 2.0)*fofx(x[i]);

        // Here we do the forward substitution.
        d[i] = b[i] - (a[i-1]/d[i-1])*c[i-1];
        k[i] = btild[i] - (a[i-1]/d[i-1])*k[i-1];
    }

    // Implementation of backward substitution:
    for (int i = n; i >= 0; i--)
    {
        v[i] = (k[i] - c[i]*v[i+1])/d[i];
        // Here we can print to see if the numerical values match with the analytical solution.
        //cout << "num = " << v[i] << "ana = " << AnalyticalSolution(x[i]) << endl;
    }

    // End timer
    finish = clock();
    ((finish-start)/CLOCKS_PER_SEC);
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
    cout << setiosflags(ios::showpoint | ios::uppercase);
    cout << setprecision(10) << setw(20) << "Time used =" << timeused  << endl;


    /*
    // writing to txt file v:
    ofstream outputFile;
    outputFile.open("1btesting.txt");

    for (int i = 1; i <= n-1; i++)
    {
        outputFile << setiosflags(ios::showpoint | ios::uppercase);
        outputFile << setprecision(10) << setw(20) << v[i] << endl;
    }
    outputFile << setprecision(10) << setw(20) << v[n];
    outputFile.close();
    */

    cout << "Program completed without crash!" << endl;
    return 0;
}
