#include "newton.hpp"
#include <functional>
#include <iostream>
#include <limits>

double f(const double &x){return x * x - 1;}
double df(const double &x){return 2 * x;}


int main() {
  // Function with real root: f(x) = x^2 - 1 = 0.
  {
    // Define function and its derivative.
    // ...

    // Create a NewtonSolver instance and find the root.
    const double x0 = 1;
    NewtonSolver solver(f, df, x0);

    const double root = solver.solve();

    if (root != std::numeric_limits<double>::quiet_NaN()) {
      std::cout << "Approximate root: " << root << std::endl;
    } else {
      std::cout << "Failed to converge to a root." << std::endl;
    }
  }

  return 0;
}