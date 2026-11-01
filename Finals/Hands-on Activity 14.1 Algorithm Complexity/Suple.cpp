#include <iostream>
#include "searching.h"   
int main() {
    int sizes[] = {1000, 10000, 100000};
    const int REPEATS = 1000;   
    std::cout << "Worst-case timing (key is not in the list)\n";
    std::cout << "N\t\tBinary (ns)\tLinear (ns)\n";

    for (int size : sizes) {
        int *data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i * 2;
        }

        int key = -1; 

        double binTime = timeBinarySearch(data, size, key, REPEATS);
        double linTime = timeLinearSearch(data, size, key, REPEATS);

        std::cout << size << "\t\t" << binTime << "\t\t" << linTime << "\n";

        delete[] data;
    }

    return 0;
}

