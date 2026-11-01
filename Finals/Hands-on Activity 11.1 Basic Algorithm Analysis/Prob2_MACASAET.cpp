#include <iostream>
#include <chrono>
typedef unsigned long long ull;
long long calls;
ull rpower(ull x, int n) { calls++; if (n == 0) return 1; return x * rpower(x, n - 1); }
ull brpower(ull x, int n) {
    calls++;
    if (n == 0) return 1;
    ull y = brpower(x, n / 2);
    return (n % 2) ? x * y * y : y * y;
}
int main() {
    for (int n : {10, 20, 40, 80}) {
        calls = 0;
        auto b = std::chrono::steady_clock::now(); rpower(2, n);
        auto e = std::chrono::steady_clock::now();
        std::cout << "rpower  n=" << n << " calls=" << calls << " "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(e - b).count() << " ns\n";
        calls = 0;
        b = std::chrono::steady_clock::now(); brpower(2, n);
        e = std::chrono::steady_clock::now();
        std::cout << "brpower n=" << n << " calls=" << calls << " "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(e - b).count() << " ns\n";
    }
}