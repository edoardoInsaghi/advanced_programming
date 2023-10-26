#include <iostream>
#include <numeric>

class Product{
public: 

	Product(std::string name, double value) : name(name), val(value){}

	std::string name;
	double val;
};


int main(){

  	const std::vector<Product> products = {{"Smartphone", 799.99},
  	                                       {"Laptop", 1299.99},
  	                                       {"Tablet", 349.99},
  	                                       {"Headphones", 99.99},
  	                                       {"Smartwatch", 249.99}};


	auto f = [](const double &sum, const Product &p){return sum + p.val;};
	const double total_cost = std::accumulate(products.begin(), products.end(), 0.0, f);

	return 0;
}

















