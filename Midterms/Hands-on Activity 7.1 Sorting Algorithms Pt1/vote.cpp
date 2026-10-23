#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int NUM_VOTES = 100;
const int NUM_CANDIDATES = 5;

const std::string candidateNames[NUM_CANDIDATES] = {
    "Bo Dalton Capistrano",
    "Cornelius Raymon Agustin",
    "Deja Jayla Banaga",
    "Lalla Brielle Yabut",
    "Franklin Relano Castro"
};

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i];
        if(i != size-1) std::cout << ", ";
        if((i+1) % 20 == 0) std::cout << "\n";
    }
    std::cout << std::endl;
}

int main(){
    srand(5); 

    int votes[NUM_VOTES];
    for(int i = 0; i < NUM_VOTES; i++){
        votes[i] = (rand() % NUM_CANDIDATES) + 1; 
    }

    std::cout << "Unsorted Vote Array (100 votes, candidate 1-5)\n";
    printArray(votes, NUM_VOTES);

    insertionSort(votes, NUM_VOTES);

    std::cout << "\nSorted Vote Array\n";
    printArray(votes, NUM_VOTES);

    int tally[NUM_CANDIDATES + 1] = {0}; // index 1..5 used

    for(int i = 0; i < NUM_VOTES; i++){
        tally[votes[i]]++;
    }

    std::cout << "\nVote Count Result\n";
    int winner = 1;
    for(int c = 1; c <= NUM_CANDIDATES; c++){
        std::cout << "Candidate " << c << " (" << candidateNames[c-1] << "): "
                   << tally[c] << " votes\n";
        if(tally[c] > tally[winner]) winner = c;
    }

    std::cout << "\nWinner: Candidate " << winner << " - "
               << candidateNames[winner-1] << " with " << tally[winner]
               << " votes.\n";

    return 0;
}