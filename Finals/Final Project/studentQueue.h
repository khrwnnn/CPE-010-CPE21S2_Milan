#ifndef STUDENT_QUEUE_H
#define STUDENT_QUEUE_H

#include <iostream>
#include <string>

struct StudentRequest{
    std::string studentName;
    std::string studentID;
    int targetLockerID;
    std::string requestType;
    StudentRequest* next;
};

class StudentQueue{
private:
    StudentRequest* front = nullptr;
    StudentRequest* rear = nullptr;
    int count = 0;

public:
    StudentQueue() = default;

    ~StudentQueue(){
        while (!isEmpty()){ 
            dequeue(); 
        }
    }

    bool isEmpty() const {
            return front == nullptr;
    }

    void enqueue(std::string name, std::string id, int lockerID, std::string request){
        StudentRequest* newNode = new StudentRequest{name, id, lockerID, request, nullptr};
        if (isEmpty()){
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        std::cout << "\n" << name << " (ID: " << id << ") added to the waiting queue for Locker #" << lockerID << ".\n";
    }
    
    void dequeue(){
        if (isEmpty()){
            std::cout << "No pending requests in the queue.\n";
            return;
        }
        StudentRequest* temp = front;
        front = front->next;
        if (front == nullptr){
            rear = nullptr; 
        }

        std::cout << "\nProcessing locker assignment for: " << temp->studentName  << " (ID: " << temp->studentID << ")\n";
        delete temp;
        count--;
    }

    // Input and Enqueue
    void requestLockerFromInput(){
        std::string name, id;
        int lockerID;
        std::cout << "\n=== Request / Release a Locker ===\n";
        std::cout << "Enter Student Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Student ID: ";
        std::cin >> id;
        std::cout << "Enter Target Locker ID: ";
        std::cin >> lockerID;

        enqueue(name, id, lockerID, "Locker Request");
    }

    void processFrontQueue(LockerItem lockers[], int totalLockers) {
        if (isEmpty()) {
            std::cout << "No pending requests in the queue.\n";
            return;
        }

        StudentRequest* req = front;

        for (int i = 0; i < totalLockers; ++i) {
            if (lockers[i].id == req->targetLockerID) {
                // If owned by this student
                if (lockers[i].assignedTo == req->studentID) {
                    lockers[i].isAvailable = true;
                    lockers[i].assignedTo = "Available";
                    std::cout << "\n Locker #" << req->targetLockerID << " is now released.\n";
                } 
                // If available 
                else if (lockers[i].isAvailable) {
                    lockers[i].isAvailable = false;
                    lockers[i].assignedTo = req->studentID;
                    std::cout << "\nLocker #" << req->targetLockerID << " assigned to " << req->studentName << ".\n";
                } 
                else {
                    std::cout << "\nLocker #" << req->targetLockerID << " is occupied by someone else.\n";
                }

                dequeue();
                return;
            }
        }
        // if not found
        std::cout << "\nLocker ID #" << req->targetLockerID << " not found.\n";
        dequeue();
    }

    void displayQueue() const {
        if (isEmpty()){
            std::cout << "\nQueue is currently empty.\n";
            return;
        }

        StudentRequest* current = front;
        int pos = 1;
        std::cout << "\n--- Locker Request Waiting Line (" << count << " Waiting) ---\n";
        while (current != nullptr){
            std::cout << pos << ". " << current->studentName << " | ID: " << current->studentID  << " | Locker #" << current->targetLockerID << "\n";
            current = current->next;
            pos++;
        }
        std::cout << "-----------------------------------------------------\n";
    }
};
#endif