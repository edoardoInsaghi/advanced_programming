#include <iostream>

int main(){

	double temp;
	std::cin >> temp;

	char scale;
	std::cin >> scale;

	double new_temp;

	if (scale == 'C' || scale == 'c'){

		new_temp = 9.0/5 * temp + 32;
		std::cout << new_temp;
	}

	else if (scale == 'F' || scale == 'f'){

		new_temp = 5.0/9 * (temp - 32);
		std::cout << new_temp;
	}

	else{
		std::cout << "Scale should be a char with c or C if temperature is expressed in Celsius degrees, and F or f if it is expressed in Farenheit degrees" << std::endl;
	}


	return 0;
}

