#include<iostream>

class DataProcessor{

    public:

        // Default constructor
        DataProcessor(const double* input_data, const unsigned int input_size)
            : data{new double[input_size]}, size{input_size}
            {
                for(int i=0; i < this->size; i++){
                    data[i] = input_data[i];
                }
            }
        

        // Copy constructor
        DataProcessor(const DataProcessor& other){
            this->data = new double[other.size];

            for(int i = 0; i < other.size; i++){

                this->data[i] = other.data[i];
            }

            this->size = other.size;
        }


        // Copy assignement operator
        DataProcessor& operator=(const DataProcessor other){
            
            delete[] data;
            data = new double(other.size);

            for(int i = 0; i < other.size; i++){

                this->data[i] = other.data[i];
            }
            this->size = other.size;

            return (*this);
        }


        // Destructor
        ~DataProcessor(){
            delete[] data;
        }


        // Method for returning size of the data
        const unsigned int n_elements(){
            return this->size;
        }


        // Method to compute the mean of the data
        const double mean(){
            
            double val = 0;
            for (int i = 0; i < this->size; i++){

                val += this->data[i];
            }
            
            return val / this->size;
        }

        // returns min and max of the data
        double* minmax(){

            double* vals = new double[2];
            vals[0] = this->data[0];
            vals[1] = this->data[0];

            for (int i = 0; i < this->size; i++){

                vals[0] = (this->data[i] < vals[0]) ? this->data[i] : vals[0];
                vals[1] = (this->data[i] > vals[1]) ? this->data[i] : vals[1];
            }
        
        return vals;
        }


    private:
        double* data;
        unsigned int size;
};



int main(){
    
    const double data1[] = {1.22, 3212.32, -32.43, 12.23, 34.08};

    DataProcessor dp1(data1, 5);
    DataProcessor dp2(dp1);
    
    std::cout << "Obj1 has " << dp1.n_elements() << " elements, and its copy also has " << dp2.n_elements() << " elements" << std::endl;
    
    std::cout << "The mean of the data is " << dp1.mean() << std::endl;

    std::cout << "The minimum and the maximum of the data are " << dp1.minmax()[0] << " and " << dp1.minmax()[1] << std::endl;

    return 0;
}






