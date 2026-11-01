#include <iostream>
#include <thread>

int globalVar = 0;

void add(int value) {
    for (volatile long i = 0; i < value * 50000000L; i++) { }   // simulated work
    globalVar += value;
}

int main() {
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout << "Display 1 (before any join): " << globalVar << std::endl;
    T1.join();
    std::cout << "Display 2 (after T1.join):   " << globalVar << std::endl;
    T2.join();
    std::cout << "Display 3 (after T2.join):   " << globalVar << std::endl;
    T3.join();
    std::cout << "Display 4 (after T3.join):   " << globalVar << std::endl;

    return 0;
}



