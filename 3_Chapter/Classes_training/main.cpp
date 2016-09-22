#include <iostream>
#include "squared.h"

using namespace std;

int main(){
    Squared<double> s;
    cout << s(3) << endl;
    return 0;
}
