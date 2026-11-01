#include <iostream>
#include <iomanip>
#include <thread>
#include <ctime>
#include <cstdlib>

const int N = 5000;

int original[N];
int bubbleArr[N];
int selectionArr[N];
int insertionArr[N];

void bubbleSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

void selectionSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// sorts one array and saves how long it took (in ms)
void runSort(void (*sortFn)(int *, int), int *arr, int n, double *timeMs) {
    std::clock_t start = std::clock();
    sortFn(arr, n);
    std::clock_t end = std::clock();
    *timeMs = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
}

// prints only the first 10 numbers so the output stays short
void printArray(int *a) {
    for (int i = 0; i < 10; i++) std::cout << a[i] << " ";
    std::cout << "...\n";
}

int main() {
    std::srand(std::time(nullptr));

    for (int i = 0; i < N; i++) {
        original[i] = std::rand() % 99 + 1;
        bubbleArr[i] = original[i];       // each thread gets its own copy
        selectionArr[i] = original[i];
        insertionArr[i] = original[i];
    }

    double bubbleTime = 0, selectionTime = 0, insertionTime = 0;

    std::cout << "Unsorted Array (first 10):\n";
    printArray(original);
    std::cout << "\n-----------------------------\n\n";
    std::cout << "Sorting started concurrently...\n\n";

    std::thread t1(runSort, bubbleSort, bubbleArr, N, &bubbleTime);
    std::thread t2(runSort, selectionSort, selectionArr, N, &selectionTime);
    std::thread t3(runSort, insertionSort, insertionArr, N, &insertionTime);

    t1.join();
    t2.join();
    t3.join();

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Bubble Sort finished in " << bubbleTime << " ms\n";
    std::cout << "Selection Sort finished in " << selectionTime << " ms\n";
    std::cout << "Insertion Sort finished in " << insertionTime << " ms\n";

    std::cout << "\n========== SORTED ARRAYS (first 10) ==========\n\n";
    std::cout << "Bubble Sort Result:\n";
    printArray(bubbleArr);
    std::cout << "\nSelection Sort Result:\n";
    printArray(selectionArr);
    std::cout << "\nInsertion Sort Result:\n";
    printArray(insertionArr);

    std::cout << "\n========== FASTEST ALGORITHM ==========\n";
    if (bubbleTime <= selectionTime && bubbleTime <= insertionTime)
        std::cout << "Bubble Sort was the fastest!\n";
    else if (selectionTime <= bubbleTime && selectionTime <= insertionTime)
        std::cout << "Selection Sort was the fastest!\n";
    else
        std::cout << "Insertion Sort was the fastest!\n";

    return 0;
}