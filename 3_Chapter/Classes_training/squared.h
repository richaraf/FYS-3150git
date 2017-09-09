#ifndef SQUARED_H
#define SQUARED_H

template<class T>
class Squared
{
public:
    // Default constructor
    Squared(){};

    // Overload the function operator()
    T operator()(T x){return x*x;}
    T cubed(T x);
};
#endif // SQUARED_H
