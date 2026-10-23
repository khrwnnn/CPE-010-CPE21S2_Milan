#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double item1, item2, item3;
    double total, payment, change;

    cout << "Enter price of Item 1: ";
    cin >> item1;

    cout << "Enter price of Item 2: ";
    cin >> item2;

    cout << "Enter price of Item 3: ";
    cin >> item3;

    total = item1 + item2 + item3;

    cout << "Enter payment amount: ";
    cin >> payment;

    change = payment - total;

    cout << fixed << setprecision(2);

    cout << "TRANSACTION RECEIPT" << endl;
    cout << "Item 1 Price: PHP " << item1 << endl;
    cout << "Item 2 Price: PHP " << item2 << endl;
    cout << "Item 3 Price: PHP " << item3 << endl;
    cout << "Total Price: PHP " << total << endl;
    cout << "Payment: PHP " << payment << endl;
    cout << "Change: PHP " << change << endl;
    

    return 0;
}