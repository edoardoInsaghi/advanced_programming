#include<iostream>
#include<random>

typedef unsigned int uint;

double approximate_pi(uint iters){

    double x = 0;
    double y = 0;

    double pi = 0;

    std::random_device rd;
    std::default_random_engine gen{rd()};
    std::uniform_real_distribution<double> unif{0, 1};

    for(uint i=0; i<iters; i++){

        x = unif(gen);
        y = unif(gen);

        pi += (x*x + y*y <= 1); 
    }

    pi /= iters;

    return 4*pi;
}


int main(){

    uint iters = 1000000;

    double pi = approximate_pi(iters);

    std::cout << pi << "\n" << std::endl;

    return 0;
}


