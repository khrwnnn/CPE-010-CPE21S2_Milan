#ifndef LOCKER_ASSET_SORT_H
#define LOCKER_ASSET_SORT_H

#include <iostream>
#include <string>
#include <iomanip>

// Structure representing a campus locker or asset entry
struct LockerItem {
    int id;                 // Locker / Asset ID (primary numeric key)
    std::string name;       // Name or description (e.g., "Locker A-101", "Digital Multimeter")
    std::string assignedTo; // Student number or "Available"
    bool isAvailable;
};

// 1. Selection Sort (By ID - Ascending)
// Performs at most (n - 1) swaps: O(n^2) time, O(1) space
void selectionSortById(LockerItem arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].id < arr[minIdx].id) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            LockerItem temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

// 2. Short Bubble Sort (By ID - Ascending)
// Features early termination flag: O(n) best-case, O(n^2) worst-case
void bubbleSortById(LockerItem arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].id > arr[j + 1].id) {
                LockerItem temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then array is sorted
        if (!swapped) break;
    }
}

// 3. Selection Sort by Status (Available First)
void sortByAvailability(LockerItem arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i; // Place available (true) items at the front
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].isAvailable && !arr[maxIdx].isAvailable) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            LockerItem temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}

// Utility function to print tabular list
void displayLockerItems(const LockerItem arr[], int n) {
    std::cout << "\n-------------------------------------------------------------\n";
    std::cout << std::left << std::setw(8)  << "ID"
              << std::setw(25) << "Item / Locker Name"
              << std::setw(15) << "Status"
              << std::setw(15) << "Assigned To" << "\n";
    std::cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        std::cout << std::left << std::setw(8)  << arr[i].id
                  << std::setw(25) << arr[i].name
                  << std::setw(15) << (arr[i].isAvailable ? "Available" : "Occupied/Borrowed")
                  << std::setw(15) << arr[i].assignedTo << "\n";
    }
    std::cout << "-------------------------------------------------------------\n";
}

#endif
