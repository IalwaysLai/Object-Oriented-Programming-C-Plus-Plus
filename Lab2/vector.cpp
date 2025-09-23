#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief prints the elements in the vector and their memory locations
 * 
 * @param v - vector of integers
 */

 void printMemVec(const vector<int>& vec){
    printf ("Vector - Each int is worth %lu bytes \n", sizeof(vec[0]));
    for (int i = 0; i < vec.size(); i++){
        printf ("Value %i at Memory Location: %p\n", vec[i], &vec[i]);
    }
}
 void incVecBy10(vector<int>& vec){
    for (int i = 0; i < vec.size(); i++){
        vec[i] += 10;
    }
}
int main(){
    const int SIZE = 5;
    vector<int> arr(SIZE);
    for (int i = 0; i < SIZE; i++){
        arr[i] = 100 + i;
    }
    printf("Before-----------------\n");
    printMemVec(arr);

    //change the value.
    incVecBy10(arr);
    printf("After-----------------\n");
    printMemVec(arr);

    return 0;
}