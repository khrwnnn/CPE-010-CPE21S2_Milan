#include <iostream>
using namespace std;

int main() {
    double quiz1, quiz2, quiz3;
    double total, average;

    cout << "Enter Quiz 1 score: ";
    cin >> quiz1;

    cout << "Enter Quiz 2 score: ";
    cin >> quiz2;

    cout << "Enter Quiz 3 score: ";
    cin >> quiz3;

    total = quiz1 + quiz2 + quiz3;
    average = total / 3;

    cout << "Total Score: " << total << endl;
    cout << "Average Score: " << average << endl;

    return 0;
}