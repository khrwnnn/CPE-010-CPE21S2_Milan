#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int unsortedArr[maxSize];
    srand(time(0));

    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 100;
    }
    std::cout << "Original Unsorted Array (100 Elements):\n";
    displayArr(unsortedArr);

    int shellArr[maxSize], mergeArr[maxSize], quickArr[maxSize];
    for (int i = 0; i < maxSize; i++) {
        shellArr[i] = unsortedArr[i];
        mergeArr[i] = unsortedArr[i];
        quickArr[i] = unsortedArr[i];
    }

    std::cout << "\nShell Sort Output:\n";
    shellSort(shellArr, maxSize);
    displayArr(shellArr);

    std::cout << "\nMerge Sort Output:\n";
    mergeSort(mergeArr, 0, maxSize - 1);
    displayArr(mergeArr);

    std::cout << "\nQuick Sort Output:\n";
    quickSort(quickArr, 0, maxSize - 1);
    displayArr(quickArr);

    return 0;
}