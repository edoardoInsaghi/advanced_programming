#include <iostream>


int main(){

	std::cout<< "Hello World!" << std::endl;

	std::cout<< "Finding Machine Epsilon" << std::endl;
	double epsilon = 1.0; // Machine epsilon.

	while (1.0 + epsilon != 1.0) {
    	epsilon /= 2.0;
	}

	// absolute value
	// std::abs()

	char comma = ",";
	std::string name = "John";

	// Concatenate strings.
	std::string message = greeting + comma + ' ' + name;

	bool is_true true;


	// initialization
	int x = 5; // Direct initialization.
	int y(10); // Constructor-style initialization.
	int z{15}; // Uniform initialization (preferred).

	auto a{42};       // int.
	auto b{12L};      // long.
	auto c{5.0F};     // float.
	auto d{10.0};     // double.
	auto e{false};    // bool.
	auto f{"string"}; // char[7].
	

	// C++11.
	auto fun1(const int i) -> int { return 2 * i; }
	
	// C++14.
	auto fun2(const int i) { return 2 * i; }



	// pointers
	int stack_var; //stack variable
	int* stack_ptr = &stack_var; //pointer to stack variable

	int* heap_ptr = new int(42); //pointer to heap variable
	//...
	delete heap_ptr;


	// const int declares a constant int, cannot be modified

	int stack_var = 42; // Stack variable.
	int* stack_ptr = &stack_var; // Pointer to stack variable.
	


	int number = 42;
	int* pointer = &number; // Pointer to 'number'.
	
	// Create a dynamic integer with new.
	int* dynamic_variable = new int;
	*dynamic_variable = 5;

	// Deallocate it.
	delete dynamic_variable;


	int* arr = new int[5]; // Dynamically allocate an integer array.

	// Access and use the array beyond its allocated size.
	for (int i = 0; i <= 5; i++) {
	    arr[i] = i;
	}
	
	// Forgot to delete the dynamically allocated array, causing a memory leak.
	// delete[] arr;
	
	// Attempt to access memory beyond the allocated array's bounds, causing undefined behavior.
	std::cout << arr[10] << std::endl;


	int a = 10;
	int& ref = a; // Reference to 'a'.
	
	ref = 20; // Modifies 'a'.
	
	int b = 10;
	ref = b;
	ref = 5; // What's now the value of 'a' and 'b'? 5 and 10


	switch (expression){
    case constant1:
        // Code to execute if expression == constant1.
        break;
    case constant2:
        // Code to execute if expression == constant2.
        break;
    // ... more cases ...
    default:
        // Code to execute if expression doesn't match any case.
	}



	// passing arguments by value and by reference
	void modify_by_copy(int x) {
    	// Creates a copy of 'x' inside the function.
    	x = 20; // Changes the copy 'x', not the original value.
	}
	
	void modify_by_ptr(int* ptr) {
	    *ptr = 30; // Modifies the original value via the pointer.
	}
	
	void modify_by_ref(int& ref) {
	    ref = 40; // Modifies the original value through the reference.
	}


	// Function overloading, same function name, different argument types
	void print(int x) {
    	std::cout << "Integer value: " << x << std::endl;
	}
	
	void print(double x) {
	    std::cout << "Double value: " << x << std::endl;
	}
	
	print(3); // Calls the int version.
	print(2.5); // Calls the double version.



	// User defined types

	// enum
	enum Color : unsigned int {
    Red = 0,
    Green,
    Blue
	};

	Color my_color = Green;


	// union
	union Duration {
	    int seconds;
	    short hours;
	};
	
	Duration d;
	d.seconds = 259200;

	short h = d.hours; // Contains garbage: undefined behavior.


	// struct
	struct Point {
	    int x;
	    int y;
	};
	
	Point p;
	p.x = 3;
	p.y = 5; 

	return 0;

}





