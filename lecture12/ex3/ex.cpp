#include<iostream>
#include<vector>
#include<random>
#include<algorithm>

typedef unsigned int uint;

void print(std::vector<uint> vec){

    for(uint val : vec){

        std::cout << val << " ";
    }
    std::cout << "\n" << std::flush;
}

int main(){

    std::random_device rd;
    std::default_random_engine eng{rd()};
    std::uniform_int_distribution<uint> unif{0, 9};

    std::vector<uint> vec(100);
    for(auto &n : vec){
        n = unif(eng);
    }

    print(vec);

    std::sort(vec.begin(), vec.end());

    print(vec);



    return 0;
}



