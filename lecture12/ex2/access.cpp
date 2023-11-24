#include<iostream>
#include<set>

typedef unsigned int uint;

class Access{
public:

    void activate(unsigned int code){
        keys.insert(code);
    }

    void deactivate(unsigned int code){
        keys.erase(code);
    }

    bool is_active(unsigned int code) const {
        return keys.count(code);
    }

private:
    std::set<uint> keys;
};





int main(){

    Access A;
    A.activate(1234);
    A.activate(9999);
    A.activate(9876);

    bool valid = 0;
    while(!valid){
        uint value;
        std::cout << "Enter a four digit number. \n" << std::endl;
        std::cin >> value;

        valid = A.is_active(value);
    }

    std::cout << "Welcome. \n" << std::flush;

    return 0;
}
