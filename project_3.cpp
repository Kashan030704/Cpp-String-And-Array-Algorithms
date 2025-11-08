//Author: Kashan Khan
#include <iostream>
#include <cassert>


//First Function

double *geometric(double a, double ratio, std::size_t cap) {
        double *array{new double[cap]};
        for(std::size_t k{0}; k < cap;++k) {
            double sum{1};
            for(std::size_t i{0}; i <k; ++i) {
                sum *= ratio;
            }
            array[k] = a*sum;
        }
        return array;
}

//Second Function 
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1){
    assert((cap0+cap1)>= 1);
    double *arr{new double[cap0+cap1-1]{0}};
    for(std::size_t i{0}; i < cap0; ++i){
        for(std::size_t j{0}; j < cap1; ++j){
            arr[i+j] += array0[i]*array1[j];
        }
    }
    return arr;
}


//Third Function - needed so much help on review this 
std::size_t shift_duplicates(int array[], std::size_t capacity){
    std::size_t count_u{0};
//Attempt 4
//bool is_unique {true};
for(int i{0}; i<capacity;++i){
    bool is_duplicate = false;
    for(int k{0}; k<count_u; ++k){
        if(array[i]==array[k]){
            is_duplicate = true;
            break;
        }
    }
    if(!is_duplicate){
        int temp{array[i]};
        array[i]=array[count_u];
        array[count_u]= temp;
        ++count_u;
    }

}
return count_u;
  
}

//Fourth Function
void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0) {
    if(is_array) {
        for(std::size_t k{0}; k<capacity; ++k) {
            ptr[k]=0;
        }
            delete [] ptr;
            ptr = nullptr;
    } else {
        *ptr =0;
        delete ptr;
        ptr = nullptr;
    }
}



