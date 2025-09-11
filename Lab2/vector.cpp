#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief prints the elements in the vector and their memory locations
 * 
 * @param v - vector of integers
 */

 void printMemVec(int vector(), int size){
    printf ("Vector - Each int is worth %lu bytes\n", sizeof(vector()));
    for (int i = 0; i < size; i++){
        printf("Value %i at Memory Location: %p\n", vector[i], vector + i);
    }
 }