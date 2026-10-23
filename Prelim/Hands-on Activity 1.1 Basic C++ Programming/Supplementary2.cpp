#include <iostream>

double convertToFahrenheit(double kelvin);

int main() {
    double kelvin;
    double fahrenheit;

    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;

    if (kelvin < 0) {
        std::cout << "Kelvin cannot be negative." << std::endl;
    } else {
        // Function call
        fahrenheit = convertToFahrenheit(kelvin);

        std::cout << "Temperature in Fahrenheit: "
                  << fahrenheit << std::endl;
    }

    return 0;
}

double convertToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}