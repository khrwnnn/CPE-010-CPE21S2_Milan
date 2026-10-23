//ILOCp2
#include <iostream>
#include <string>

class Node {
public:
    char data;
    Node* next;
};

Node* top = nullptr;


//Check if stack is empty
bool isEmpty() {
    return top == nullptr;
}


//Push a symbol into the stack
void push(char value) {

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}


//Pop a symbol from the stack
char pop() {
    if (isEmpty()) {
        return '\0';
    }
    Node* temporary = top;
    char value = temporary->data;
    top = top->next;
    delete temporary;
    return value;
}


//Check if opening and closing symbols match
bool isMatching(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return true;
    if (opening == '[' && closing == ']')
        return true;
    if (opening == '{' && closing == '}')
        return true;
    return false;
}


//Check if symbols are balanced
bool checkBalanced(std::string expression) {
    //Make sure the stack starts empty
    top = nullptr;

    //Read each character
    for (char character : expression) {
        //If opening symbol, push onto stack
        if (character == '(' ||
            character == '[' ||
            character == '{') {
            push(character);
        }
        //If closing symbol
        else if (character == ')' ||
                 character == ']' ||
                 character == '}') {
            //Report error if stack is empty
            if (isEmpty()) {
                return false;
            }
            //Pop the stack
            char opening = pop();
            //Check if symbols match
            if (!isMatching(opening, character)) {
                return false;
            }
        }
    }

    //At the end stack should be empty
    return isEmpty();
}

int main() {
    std::string expression;
    std::cout << "Enter expression: ";
    std::getline(std::cin, expression);
    if (checkBalanced(expression)) {
        std::cout << "The symbols are balanced." << std::endl;
    }
    else {
        std::cout << "The symbols are not balanced." << std::endl;
    }
    return 0;
}