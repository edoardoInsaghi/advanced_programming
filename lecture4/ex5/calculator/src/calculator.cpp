#include "../include/calculator.hpp"
#include <iostream>

namespace calculator{

	double sum(double x, double y){
		return x + y;
	}


	double subtraction(double x, double y){
		return x - y;
	}

	double product(double x, double y){
		return x * y;
	}

	double division(double x, double y){
		if (y == 0){
			std::cout << "Division by 0 is not defined" << std::endl;
		}
		return x / y;
	}
}






