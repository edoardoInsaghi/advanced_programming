#ifndef NEWTON_HPP_
#define NEWTON_HPP_


#include<functional>
typedef unsigned int uint;

template <typename T> class NewtonSolver{
public:
    NewtonSolver(const std::function<T(const T &)> &f,
                 const std::function<T(const T &)> &df, 
                 const T &x0,
                 const double &tolerance = 1e-12,
                 const uint &maxIters = 100);

    T solve();

private:
    const std::function<T(const T &)> f;
    const std::function<T(const T &)> df;
    const T x0;
    const double tolerance;
    const unsigned int maxIters;
};

#endif