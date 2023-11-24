#include"newton.hpp"
#include<cmath>
#include<complex>
#include<iostream>


template<typename T>
NewtonSolver<T>::NewtonSolver(const std::function<T(const T &)> &f, 
                              const std::function<T(const T &)> &df,
                              const T &x0,
                              const double &tolerance,
                              const uint &maxIters):

                              f(f), df(df), x0(x0), tolerance(tolerance), maxIters(maxIters){}

template<typename T> T NewtonSolver<T>::solve(){
    T x = x0;

    uint i = 0;
    while(i <= maxIters){

        T dx = f(x) / df(x);
        x -= dx;

        if (std::abs(dx) < tolerance){

            std::cout << "Algorithm converged in " << i + 1 << " iterations." << std::endl;
            return x;
        }
    }

    ++i;

    std::cout << "Algorithm failed to converge.";
    return x;
}

template class NewtonSolver<double>;
template class NewtonSolver<std::complex<double>>;

