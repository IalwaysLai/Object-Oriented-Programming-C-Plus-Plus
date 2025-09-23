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
    vector<int> vec(SIZE);
    for (int i = 0; i < SIZE; i++){
        vec[i] = 100 + i;
    }
    printf("Before-----------------\n");
    printMemVec(vec);

    //change the value.
    incVecBy10(vec);
    printf("After-----------------\n");
    printMemVec(vec);

    printf("After Pop--------------\n");
    vec.pop_back();
    vec.pop_back();
    printMemVec(vec);

    printf("After Push--------------\n");
    vec.push_back(101);
    vec.push_back(102);
    printMemVec(vec);


    return 0;
}