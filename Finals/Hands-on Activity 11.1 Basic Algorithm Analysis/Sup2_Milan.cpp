#include <iostream>
#include <chrono>

long long calls_r = 0, calls_b = 0;

long long rpower(long long x, int n) {
    calls_r++;
    if (n == 0) return 1;
    else return x * rpower(x, n - 1);
}

long long brpower(long long x, int n) {
    calls_b++;
    if (n == 0) return 1;
    if (n % 2 == 1) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        long long y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    int ns[] = {10, 100, 1000, 5000, 10000};
    long long x = 1; 

    std::cout << "n, rpower calls, rpower time (ns), brpower calls, brpower time (ns)" << std::endl;
    for (int n : ns) {
        calls_r = 0;
        auto b1 = std::chrono::steady_clock::now();
        long long a = rpower(x, n);
        auto e1 = std::chrono::steady_clock::now();

        calls_b = 0;
        auto b2 = std::chrono::steady_clock::now();
        long long b = brpower(x, n);
        auto e2 = std::chrono::steady_clock::now();

        std::cout << n << ", " << calls_r << ", "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(e1 - b1).count() << ", "
                  << calls_b << ", "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(e2 - b2).count()
                  << " (same answer: " << (a == b ? "yes" : "no") << ")" << std::endl;
    }
    return 0;
}
