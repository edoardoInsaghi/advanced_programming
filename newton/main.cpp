#include"newton.hpp"
#include <complex>
#include <functional>
#include <iostream>



int main(){
    {
    auto f = [](const double &x) {return x * x - 1.0;};
    auto df = [](const double &x) {return 2.0 * x;};

    const double x0 = 0.5;
    NewtonSolver<double> solver(f, df, x0);

    const double root = solver.solve();
    std::cout << "Root = " << root << std::endl;
    }

    {
    auto f = [](const std::complex<double> &x) {return x * x + 1.0;};
    auto df = [](const std::complex<double> &x) {return 2.0 * x;};

    const std::complex<double> x0{9, -12};
    NewtonSolver<std::complex<double>> solver(f, df, x0);

    const std::complex<double> root = solver.solve();
    std::cout << "Root = " << root << std::endl;
    }

    return 0;
}
