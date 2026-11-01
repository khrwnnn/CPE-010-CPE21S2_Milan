#include <iostream>
#include <vector>
#include <chrono>

bool Unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j])
                return false;
        }
    }
    return true;
}

int main() {
    int sizes[] = {1000, 2000, 4000, 8000, 16000};

    std::cout << "n, time (microseconds)" << std::endl;
    for (int n : sizes) {
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) A[i] = i;

        auto begin = std::chrono::steady_clock::now();
        bool r = Unique(A);
        auto end = std::chrono::steady_clock::now();

        std::cout << n << ", "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
                  << " (result = " << (r ? "true" : "false") << ")" << std::endl;
    }
    return 0;
}
