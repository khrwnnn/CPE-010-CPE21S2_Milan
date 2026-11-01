#include <iostream>
#include <vector>
#include <chrono>
bool unique(const std::vector<int>& A, long long& cmp) {
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) { cmp++; if (A[i] == A[j]) return false; }
    return true;
}
int main() {
    for (int n : {10, 50, 250, 1250}) {
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) A[i] = i;   // all unique = worst case
        long long cmp = 0;
        auto b = std::chrono::steady_clock::now();
        unique(A, cmp);
        auto e = std::chrono::steady_clock::now();
        std::cout << n << " | comparisons=" << cmp << " | "
                  << std::chrono::duration_cast<std::chrono::microseconds>(e - b).count() << " us\n";
    }
}