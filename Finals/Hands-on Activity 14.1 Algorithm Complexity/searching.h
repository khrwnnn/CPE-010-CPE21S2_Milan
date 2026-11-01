#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include <chrono>
#include "nodes.h"

int linearSearch(int data[], int n, int item, bool show = true) {
    int i = 0;
    while (i < n) {
        if (item == data[i]) {
            if (show) std::cout << "Searching is successful\n";
            return i;
        }
        i++;
    }
    if (show) std::cout << "Searching is Unsuccessful\n";
    return -1;
}


template <typename T>
int linearLS(Node<T> *head, T dataFind, bool show = true) {
    Node<T> *curr = head;
    int pos = 0;
    while (curr != NULL) {
        if (curr->data == dataFind) {
            if (show) std::cout << "Searching is successful\n";
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    if (show) std::cout << "Searching is Unsuccessful\n";
    return -1;
}


int binarySearch(int arr[], int n, int no, bool show = true) {
    int low = 0;
    int up = n - 1;
    while (low <= up) {
        int mid = (low + up) / 2;
        if (no == arr[mid]) {
            if (show) std::cout << "Search element is found!\n";
            return mid;
        } else if (no < arr[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (show) std::cout << "Search element is not found\n";
    return -1;
}


template <typename T>
Node<T> *getMiddle(Node<T> *first, Node<T> *last) {
    if (first == NULL) return NULL;

    Node<T> *slow = first;
    Node<T> *fast = first->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}


template <typename T>
Node<T> *binarySearchLL(Node<T> *head, T key, bool show = true) {
    Node<T> *start = head;
    Node<T> *last = NULL;

    do {
        Node<T> *mid = getMiddle(start, last);

        if (mid == NULL) break;

        if (mid->data == key) {
            if (show) std::cout << "Search element is found!\n";
            return mid;
        } else if (mid->data < key) {
            start = mid->next;
        } else {
            last = mid;
        }
    } while (last == NULL || last != start);

    if (show) std::cout << "Search element is not found\n";
    return NULL;
}


double timeLinearSearch(int data[], int n, int item, int repeats) {
    volatile int sink = 0;   // stops the compiler from removing the loop
    auto start = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < repeats; r++) {
        sink = linearSearch(data, n, item, false);
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::nano>(end - start).count() / repeats;
}

double timeBinarySearch(int arr[], int n, int no, int repeats) {
    volatile int sink = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < repeats; r++) {
        sink = binarySearch(arr, n, no, false);
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::nano>(end - start).count() / repeats;
}

#endif

