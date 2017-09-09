#include <iostream>
#include "squared.h"

using namespace std;

int main(){
    Squared<double> s;
    double var = 3.341;
    cout << s(var) << endl;
    cout << s.cubed(var) << endl;
    return 0;
}
