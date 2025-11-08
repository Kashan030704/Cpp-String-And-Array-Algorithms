#include <iostream>
#include <cassert>
//Author: Kashan Khan

//First Required Function
    void pattern (unsigned int n) {

        //Printing for the First Triangle (downwards)
        for(unsigned int row{1}; row <= (n+1); ++row) {

            //Printing Spaces
            for(unsigned int space{1}; (space<= (row-1)) && (row <= n+1); ++space) {
                std::cout<<" ";
            }

            //Printing Asterisks
            for(unsigned int asterisk{1}; asterisk <= (2*n+1+2-2*row) && (row <= n+1); ++asterisk) {  
                std::cout<<"*";
            }

            std::cout<<std::endl;
        }

        //Printing for the Second Triangle (upwards)
        for(unsigned int row{1}; row <= n; ++row) {

            //Printing Spaces
            for(unsigned int space{1}; (space <= (n-row)); ++space) {
                std::cout<<" ";
            }

            //Printing Asterisks
            for(unsigned int asterisk{1}; asterisk <= (1 + 2*row); ++asterisk) {  
                std::cout<<"*";
            }

            std::cout<<std::endl;
        }



    
    }



//Second Required Function

unsigned int log10(unsigned int n) {
    assert(n != 0);
    unsigned long long counter{1};
        for(unsigned int m{1};true;++m){
            counter*=10ULL;
            if((counter<=n) && (n <counter*10ULL)) {
                return m;
            }else if(n == 1) {
                return m-1;
            }
        }
        return 0;
    /*if(n>=100) {
        for(double i{10};is_found;++i) {
        //For values of n greater than or equal to 10
        for(double m{1};m<=i;++m) {
            counter = counter * 10;
            if(counter == n){
            return m;
            is_found = false;
            } 
            }
        }
    }*/
}   




//Third Required Function

unsigned int count(unsigned int n, unsigned int bit) {
    assert( bit == 0 || bit == 1);
    unsigned int counter_1{0};
    unsigned int counter_0{0};

    unsigned int MASK{1};
    for(unsigned int i{0};i<32;++i) {
        unsigned int k{n>>i};
        //LSB with n's LSB
        if(k & MASK) {
            counter_1 = counter_1 + 1;
        }else {
            counter_0 = counter_0 + 1;
        }
    }
    if (bit == 1) {
        return counter_1;
    }else if(bit == 0){
        return counter_0;
    }
    return 0;
}


//Fourth Required Function

unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1) {
    assert(((b0 >= 0 ) && (b0 <= 3) && (b1 >= 0) && (b1 <= 3)));
    if (b0 == b1) {
        return n;
    } else {
        unsigned int byte_0{0x000000ff};
        unsigned int byte_1{0x0000ff00};
        unsigned int byte_2{0x00ff0000};
        unsigned int byte_3{0xff000000};
        if((b0 == 0 && b1==3) || (b1==0 && b0==3)) {
            return ((byte_0 & n) << 24) | ((byte_3 & n) >> 24) | (byte_1 & n) | (byte_2 & n);
        } else if ((b0 == 0 && b1==1) || (b1==0 && b0==1)) {
            return ((byte_0 & n) << 8) | ((byte_1 & n)>> 8) | ((byte_2 & n)) | (byte_3 & n);
        } else if ((b0 == 0 && b1==2) || (b1==0 && b0==2)) {
            return ((byte_0 & n) << 16) | ((byte_2 & n) >> 16) | (byte_3 & n) | (byte_1 & n);
        } else if ((b0 == 1 && b1==3) || (b1==1 && b0==3)) {
            return ((byte_1 & n)<< 16) | ((byte_3 & n) >> 16) | (byte_2 & n) | (byte_0 & n); 
        } else if ((b0 == 1 && b1==2) || (b1==1 && b0==2)) {
            return ((byte_1 & n) << 8) | ((byte_2 & n)>> 8) | (byte_3 & n) | (byte_0 & n);
        } else if((b0 == 2 && b1==3) || (b1==2 && b0==3)){
            return ((byte_2 & n) << 8) | ((byte_3 & n) >> 8) | (byte_1 & n) | (byte_0 & n);
        }
    } 
    return n;

}
    







int main();

int main() {
    std::cout << "n = 1:" << std::endl;
    pattern( 1 );
    for ( unsigned int n{ 2 }; n <= 5; ++n ) {
        std::cout << std::endl;
        std::cout << "n = " << n << ":" << std::endl;
        pattern( n );
    }

    std::cout<< log10(2147483647)<<std::endl;
    std::cout<<count(1,0) <<std::endl;
    std::cout<<swap_bytes(12000000,2,3);
    
    return 0;


}