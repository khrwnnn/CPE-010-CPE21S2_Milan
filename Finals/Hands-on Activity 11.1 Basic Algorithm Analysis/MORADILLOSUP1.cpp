#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

long long comparisons = 0;

// Algorithm Unique(A): true if all elements are unique
bool unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (A[i] == A[j]) return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Worst case (all unique, no early return)\n";
    std::cout << "n\tcomparisons\tn(n-1)/2\ttime (us)\n";
    for (int n : {1000, 2000, 4000, 8000, 16000}) {
        std::vector<int> A(n);
        std::iota(A.begin(), A.end(), 0);
        comparisons = 0;
        auto b = std::chrono::steady_clock::now();
        unique(A);
        auto e = std::chrono::steady_clock::now();
        long long us = std::chrono::duration_cast<std::chrono::microseconds>(e - b).count();
        std::cout << n << "\t" << comparisons << "\t\t" << (long long)n * (n - 1) / 2
                  << "\t\t" << us << "\n";
    }

    std::cout << "\nBest case (A[0] == A[1])\n";
    std::cout << "n\tcomparisons\ttime (us)\n";
    for (int n : {1000, 2000, 4000, 8000, 16000}) {
        std::vector<int> A(n);
        std::iota(A.begin(), A.end(), 0);
        A[1] = A[0];
        comparisons = 0;
        auto b = std::chrono::steady_clock::now();
        unique(A);
        auto e = std::chrono::steady_clock::now();
        long long us = std::chrono::duration_cast<std::chrono::microseconds>(e - b).count();
        std::cout << n << "\t" << comparisons << "\t\t" << us << "\n";
    }
    return 0;
}