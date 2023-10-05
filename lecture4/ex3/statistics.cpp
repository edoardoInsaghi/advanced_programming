#include "statistics.hpp"
#include <algorithm>
#include <cmath>

namespace stat {
  // Function to calculate the mean of a set of numbers.
  double calculate_mean(const std::vector<double> &numbers){
  
    double sum = 0;
    int n = numbers.size();
  
    for(int i = 0; i < n; i++){
  
      sum += numbers[i];
    }
  
    double mean = sum / n;
  
    return mean;
  }
  
  
  // Function to calculate the median of a set of numbers.
  double calculate_median(const std::vector<double> &numbers) {
  
    int n = numbers.size();
    std::vector<double> numbers_cpy(n);
  
    for(int i = 0; i < n; i++){
  
      numbers_cpy[i] = numbers[i];
    }
  
    std::sort(numbers_cpy.begin(), numbers_cpy.end());
  
    double median = (n % 2 == 1) ? numbers_cpy[(n + 1) / 2] : (numbers_cpy[n/2] + numbers_cpy[n/2 + 1]) / 2;
  
    return median;
  }
  
  
  
  // Function to calculate the standard deviation of a set of numbers.
  double calculate_standard_deviation(const std::vector<double> &numbers) {

    int n = numbers.size();
    double x_bar = stat::calculate_mean(numbers);

    double var = 0;
    for(int i = 0; i < n; i++){

      var += pow(numbers[i] - x_bar, 2);
    }

    double sd = sqrt(var / (n - 1));

    return sd;
  }
} // namespace stat











