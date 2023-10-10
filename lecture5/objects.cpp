#include <iostream>


class Car{
public:
  std::string manufacturer;
  std::string model;
  unsigned int year;

  void start_engine(){
    std::cout << "Engine Started!" << std::endl;
  }

  void print_info(){
    std::cout << "Car model: " 
              << this->model 
              << "\n Year: "
              << this->year
              << std::endl;
  }  
};


class Circle{
public:
  static inline const double PI = 3.14159265359;
  double radius;

  double calculateArea(){
    return PI * radius * radius;
  }
  
  static void print_shape_name(){
    std::cout << "This is a circle." << std::endl;
  }
};


int main(){
  
  Car panda;
  panda.manufacturer = "Fiat";
  panda.model = "1.2_EasyPower";
  panda.year = 1998;
  
  panda.print_info();  

  panda.start_engine();
  
  
  Circle circle;
  circle.radius = 10;
  const double area = circle.calculateArea();
  Circle::print_shape_name();
  
  return 0;
}

