#include <iostream>
#include <cmath>

double calculateDistance(double x1, double y1,
                         double x2, double y2);

int main() {
    double x1, y1;
    double x2, y2;
    double distance;

    std::cout << "Enter x1: ";
    std::cin >> x1;

    std::cout << "Enter y1: ";
    std::cin >> y1;

    std::cout << "Enter x2: ";
    std::cin >> x2;

    std::cout << "Enter y2: ";
    std::cin >> y2;

    distance = calculateDistance(x1, y1, x2, y2);

    std::cout << "Distance between the two points: "
              << distance << std::endl;

    return 0;
}

double calculateDistance(double x1, double y1,
                         double x2, double y2) {
    double distance;

    distance = std::sqrt(
        ((x2 - x1) * (x2 - x1)) +
        ((y2 - y1) * (y2 - y1))
    );

    return distance;
}