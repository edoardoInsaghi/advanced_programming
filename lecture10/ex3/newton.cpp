#include "newton.hpp"
#include <limits>
#include <cmath>

NewtonSolver::NewtonSolver(const std::function<double(const double&)> &f,
                           const std::function<double(const double&)> &df,
                           const double &x0, const double &tolerance,
                           const unsigned int &max_iterations)
    : f(f), df(df), tolerance(tolerance), max_iterations(max_iterations), x0(x0){}

double NewtonSolver::solve() {
  double x = x0;

  unsigned int it = 0;

  while (it < max_iterations) {
    // Update x.
    double old_x = x;
    x -= f(x) / df(x);

    // Check convergence.
    if(std::abs(old_x - x)){return x;}

    ++it;
  }

  // Indicates failure to converge.
  return std::numeric_limits<double>::quiet_NaN();
}