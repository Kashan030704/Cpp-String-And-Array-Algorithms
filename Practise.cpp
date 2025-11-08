#include <iostream>
int main();

unsigned int longest_run_of_ones(unsigned int n) {
    unsigned int MASK{1};
    MASK = MASK << 31;
    unsigned int result{0};
    int count[40]{0};
    int index{0};
    for(int i{0};i<32;++i) {
        result = (MASK>>i) & n;
        if(result !=0) {
            count[index]+=1;
        } else if(result == 0) {
            index +=1;
        }
    }
    int max {count[0]};
    for(int k{0};k<39;++k) {
        if((count[k] < count [k+1]) && (count[k+1]> max)){
            max = count[k+1];
        }
    }
    return max;
}


int count( int n, double array[], unsigned int capacity) {
    int counter{0};
    for(int k{0}; k< capacity; ++k) {
        if(array[k] == n) {
            counter +=1;
        }
    }
    return counter;
}

int first( int n, double array[], unsigned int capacity) {
    for(int k{0}; k<capacity; ++k) {
        if(array[k] ==n) {
            return k;
        }
    }
}

int last( int n, double array[], unsigned int capacity) {
    for(unsigned int k{capacity-1}; k >=0; --k) {
        if(array[k] ==n) {
            return k;
        }
    }
    return capacity;
}


bool value (int array[], unsigned int capacity, unsigned int n) {
    for(int k{0}; k<capacity; ++k) {
        if(n == array[k]) {
            return true;
        }
    }
        return false;

}




int main () {

    int m{42};
    int n{13};
    while(m!=n) {
        if(m>n) {
            m = m-n;
        }else if(n>m) {
            n = n-m;
        }
    }
    std::cout<<m<<"is the greatest common denominator";

    int num{53890000};
    int divisor{1};
    while(true) {
        int quotient{num/divisor};
        divisor *=10;
    if(quotient < 10) {
        break;
    }
    }
    int s{5};
    while(1 <=s) {
        std::cout<<divisor<<'\t';
        divisor /=10;
        --s;
    }

    int temp{num};
    int temp2{den};
    while(num != den) {
        if(num>den) {
            num -=den;
        } else if(den > num) {
            den -= num;
        }
    }
    int new_num{temp/num};
    int new_den{temp2/den};
    std::cout<<new_num<<'/'<<new_den;



}

unsigned int gcd(int array[], unsigned int capacity) {
    for(unsigned int k{0}; k< (capacity-1); ++k) {
        while(array[k] != array[k+1]) {
            if(array[k]>array[k+1]){
                array[k] -= array[k+1];
            } else if(array[k+1] > array[k]) {
                array[k+1] -= array[k];
            }
        }
    }
    return array[k];
}

unsigned int lcd(int array[], unsigned int capacity) {
    int k{0};
    int temp{array[k]};
    int temp2{array[k+1]};
    int gcd{};
    int lcd{};
    while(temp != temp2) {
            if(temp>temp2){
                temp -= temp2;
            } else if( temp2> temp)  {
               temp2 -= temp;
            }
        }
    gcd = temp;
    lcd = (array[k]*array[k+1])/gcd;
    while(k< (capacity -2)) {
        int temp3{array[k+2]};
        int temp4{lcd};
        while(temp3 != temp4) {
            if(temp3>temp4){
                temp3 -= temp4;
            } else if( temp4> temp3)  {
                temp4 -= temp3;
            }
        }
    gcd = temp4;
    lcd = (lcd*array[k+2])/gcd;
    ++k;
    }
    return lcd;
    

}