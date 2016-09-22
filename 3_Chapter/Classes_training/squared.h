#ifndef SQUARED_H
#define SQUARED_H

template<class T>
class Squared
{
public:
    // Default constructor
    Squared(){};

    // Overload the functioin operator()
    T operator()(T x){return x*x;}
};

#endif // SQUARED_H
