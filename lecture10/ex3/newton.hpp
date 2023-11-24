#ifndef NEWTON_HPP__
#define NEWTON_HPP__

#include <functional>

class NewtonSolver {
public:
  NewtonSolver(const std::function<double(const double&)> &f, 
               const std::function<double(const double&)> &df,
               const double &x0,
               const double &tolerance = 1e-12,
               const unsigned int &max_iterations = 100);

  double solve();

private:
  const std::function<double(const double&)> f;
  const std::function<double(const double&)> df;

  const double x0;
  const double tolerance;
  const unsigned int max_iterations;
};

#endif /* NEWTON_HPP__ */