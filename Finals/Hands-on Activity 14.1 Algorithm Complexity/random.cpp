#include <iostream>
#include <chrono>
#include "SortingAlgo.h"
const int maxSize = 15;
void displayArr(int arr[]);
//Procedure
int main(){
    //create two copies of the same unsorted list
    int bubbleArr[maxSize] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int insertionArr[maxSize] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};


    std::cout << "Unsorted Array:\n";
    displayArr(bubbleArr);


    //bubble sort
    auto begin = std::chrono::steady_clock::now();
    bubbleSort(bubbleArr, maxSize);
    auto end = std::chrono::steady_clock::now();
    std::cout << "\nSorted using bubble sort:\n";
    displayArr(bubbleArr);
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " ns\n";


    //insertion sort
    begin = std::chrono::steady_clock::now();
    insertionSort(insertionArr, maxSize);
    end = std::chrono::steady_clock::now();
    std::cout << "\nSorted using insertion sort:\n";
    displayArr(insertionArr);
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " ns\n";


    return 0;
}
void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
        if ((i%10) == 9){
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}