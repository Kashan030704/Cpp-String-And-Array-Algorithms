#include <iostream>
#include <algorithm> 
#include <cassert>
#include <fstream>
#include "p_4_header.hpp"
//Author: Kashan Khan


//First Function
std::size_t length(char const *a) {
    std::size_t count{0};
    while( *(a+count) != '\0'){
        ++count;
    }
    return count;
}

//Second Function
int compare( char const *str1, char const *str2 ) {
    int k{0};
    while(*(str1+k)==*(str2 +k)){
        if(*(str1+k) == '\0') {
            return 0;
        }
        ++k;
    }
    if( *(str1+k)> *(str2+k)){
        return 1;
    }else {
        return -1;
    }

}


//Third Function - 2.3
void assign(char *str1, char const *str2){
    for(int k{0};true;++k){
        str1[k]=str2[k];
        if(str1[k]=='\0'){
            break;
        }
        }
}

//2.4
unsigned int distance( char const *str1, char const *str2 ) {
    if(*str1=='\0'){
        return length(str2);
    } else if(*str2 == '\0'){
        return length(str1);
    } else if(*str1==*str2){
        return distance(str1+1,str2+1);
    }else if(*str1!=*str2){
        return 1+std::min({distance(str1+1,str2+1),distance(str1+1,str2),distance(str1,str2+1)});
    }
    return 0;
}

//Helper function to 2.4
/*int l(char const *str){
    int i{0};
    while (*(str+i)!='\0'){
        ++i;
    }
    return i;
}*/ 








//2.5
std::size_t is_sorted( char *array[], std::size_t capacity ) {
    for(int k{0}; k<capacity -1;++k){
        if(compare(array[k],array[k+1])>0){
            return k+1; 
        }
    }
    return capacity;
}

//2.6 --- Done
void insert( char *array[], std::size_t capacity ) {
   char *p_unsort{new char[length(array[capacity-1])+1]};
   assign(p_unsort,array[capacity-1]);
   bool inserted{false};
    for(int k{0}; k<capacity-1;++k){
        if(compare(p_unsort, array[k])<0) {
            for(int i{capacity-1};i>k;--i){
                assign(array[i],array[i-1]);
            }
            assign(array[k],p_unsort);
            inserted=true;//added a boolean value
            break;
        }
    }

    if(!inserted){
        assign(array[capacity-1],p_unsort);

    }
    delete [] p_unsort;
    p_unsort = nullptr;

}

//2.7 Done
void insertion_sort( char *array[], std::size_t capacity ) {
    for(int k{1}; k<=capacity-1; ++k){
        insert(array,k+1);//added one
    }
}

//helper function to 2.8
void swap(char *str1, char *str2) {
    if(length(str1)>length(str2)){
    char *temp{new char[length(str1)+1]};
    assign(temp,str1);
    assign(str1,str2);
    assign(str2,temp);
     delete [] temp;
    temp = nullptr;
    } else {
    char *temp{new char[length(str2)+1]};
    assign(temp,str1);
    assign(str1,str2);
    assign(str2,temp);
    delete [] temp;
    temp = nullptr;
    }
}

//2.8 progress
std::size_t remove_duplicates( char *array[], std::size_t capacity ) {
    std::size_t duplicate{0};
    for(std::size_t k{capacity -1}; k>0;--k){
        for(std::size_t i{0};i<k;++i){
            if(compare(array[k],array[i])==0){
                for(std::size_t l{i};l<capacity-1;++l){
                    swap(array[l],array[l+1]);
                }
                ++duplicate;

            }
        }
    }

    return capacity-duplicate;
}



//2.9 - Finding a String supposed to return the index of the mnimum of the distance 
std::size_t find( char *array[], std::size_t capacity, char const *str ) {
    for(std::size_t k{0}; k<capacity; ++k){
        if(compare(array[k],str)==0){
            return k;
        }
    }
    std::size_t min {distance(array[0],str)};
    for(std::size_t k{0}; k < capacity; ++k){
        if(distance(array[k],str) < min){
            min = distance(array[k],str);
        }
    }
    for(std::size_t i{0}; i< capacity; ++i){
        if(min == distance(array[i],str)){
            return i;
        }
    }
}

//2.11 - Done
 void free_word_array( char** word_array ) {
    delete [] word_array[0];
    delete [] word_array;
 }


