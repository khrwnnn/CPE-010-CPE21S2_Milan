//ILOB2
#include <iostream>

class Node {
public:
    int data;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;


void push(int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    if (head == NULL) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}


int pop() {
    int tempVal;
    Node* temp;
    if (head == NULL) {
        head = tail = NULL;
        std::cout << "Stack Underflow."
                  << std::endl;
        return -1;
    }
    temp = head;
    tempVal = temp->data;
    head = head->next;
    delete temp;
    return tempVal;
}


void Top() {
    if (head == NULL) {
        std::cout << "Stack is Empty."
                  << std::endl;
        return;
    }
    std::cout << "Top of Stack: "
              << head->data
              << std::endl;
}


void display() {
    if (head == NULL) {
        std::cout << "Stack is Empty."
                  << std::endl;
        return;
    }
    Node* current = head;
    std::cout << "Stack elements: ";
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


int main() {
    push(1);
    std::cout << "After the first PUSH: ";
    Top();
    push(5);
    std::cout << "After the second PUSH: ";
    Top();
    std::cout << "\nAll elements: ";
    display();
    pop();
    std::cout << "After the first POP: ";
    Top();
    pop();
    std::cout << "After the second POP: ";
    Top();
    pop();

    return 0;
}