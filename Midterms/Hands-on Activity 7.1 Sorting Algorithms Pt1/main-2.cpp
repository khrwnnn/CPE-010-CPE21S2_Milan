#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int ARR_SIZE = 100;

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i];
        if(i != size-1) std::cout << ", ";
        if((i+1) % 10 == 0) std::cout << "\n";
    }
    std::cout << std::endl;
}

void copyArray(int source[], int dest[], int size){
    for(int i = 0; i < size; i++) dest[i] = source[i];
}

int main(){
    srand(7); 

    int original[ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++){
        original[i] = rand() % 1000; 
    }

    std::cout << "Unsorted Array (100 elements)\n";
    printArray(original, ARR_SIZE);

    int bubbleArr[ARR_SIZE];
    copyArray(original, bubbleArr, ARR_SIZE);
    bubbleSort(bubbleArr, ARR_SIZE);
    std::cout << "\nBubble Sort Result\n";
    printArray(bubbleArr, ARR_SIZE);

    int selectionArr[ARR_SIZE];
    copyArray(original, selectionArr, ARR_SIZE);
    selectionSort(selectionArr, ARR_SIZE);
    std::cout << "\nSelection Sort Result\n";
    printArray(selectionArr, ARR_SIZE);

    int insertionArr[ARR_SIZE];
    copyArray(original, insertionArr, ARR_SIZE);
    insertionSort(insertionArr, ARR_SIZE);
    std::cout << "\nInsertion Sort Result\n";
    printArray(insertionArr, ARR_SIZE);

    return 0;
}