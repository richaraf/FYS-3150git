#include <iostream>

using namespace std;

void doSomething(int *a, int *b) {
    // cout << " Address of a inside: " << (long)&a << endl;
    *a = 2*(*a);
    *b = 2*(*b);
}

int main(int argc, char *argv[])
{
    // Two operators:
    // & address-of operator
    // * dereference operator

    int a = 10;
    int b = 20;
    // cout << " Address of a outside: " << (long)&a << endl;
    doSomething(&a,&b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    //int *array = new int[10000000];
    // int array2[10000000];

    //cout << 3 << endl;
    return 0;
}
