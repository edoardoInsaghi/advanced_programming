#include <iostream>
#include "../include/calculator.hpp"


int main(){

	double x = 5;
	double y = 10;

	std::cout << "The sum of 5 and 10 is " << calculator::sum(x, y) << std::endl;
	std::cout << "Subtracting 10 from 5 yields " << calculator::subtraction(x, y) << std::endl;
	std::cout << "The product of 5 and 10 is " << calculator::product(x, y) << std::endl;
	std::cout << "Dividing 5 by 10 yields " << calculator::division(x, y) << std::endl;

	return 0;
}


