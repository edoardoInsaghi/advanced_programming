#include <iostream>
#include <cstdlib>

void find_min_max(int* numbers, int n){

	int min = numbers[0];
	int max = numbers[0];

	for(int i = 1; i < n; i++){

		max = (numbers[i] > max) ? numbers[i] : max;
		min = (numbers[i] < min) ? numbers[i] : min;
	}

	std::cout << "min and max are " << min << " and " << max << " respectively" << std::endl;
}



int main(){

	int n;
	std::cout << "Provide length of the array. " << std::endl;
	std::cin >> n;

	int* numbers = new int[n];

	for(int i = 0; i<n; i++){

		numbers[i] = std::rand() % 100;
	}


		for(int i = 0; i<n; i++){

		std::cout << numbers[i] << std::endl;
	}

	find_min_max(numbers, n);

	delete[] numbers;

	return 0;
}




