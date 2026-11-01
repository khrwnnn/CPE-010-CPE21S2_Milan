#ifndef SORTINGALGO_H
#define SORTINGALGO_H
//
template <typename T>
void bubbleSort(T arr[], size_t arrSize){
    //step1: for i = 0 to N-1 repeat inner loop
    for (size_t i = 0 ; i < arrSize; i++){
        // step 2 inner loop that for k = i+1 to N-1 repeat step 3
        for(size_t j = i+1; j < arrSize; j++){
            //step 3:swap if arr[i] > arr[j]
            if(arr[i] > arr[j]){
                // swap arr[i] and arr[j]
                std::swap(arr[i], arr[j]);
            }
        }
    }
}
template <typename T>
void insertionSort(T arr[], size_t arrSize){
    for (int K = 1; K < (int)arrSize; K++){
        T temp = arr[K];
        int J = K - 1;
        for (; J >= 0 && temp <= arr[J]; J--){
            arr[J+1] = arr[J];
        }
        arr[J+1] = temp;
    }
}
#endif