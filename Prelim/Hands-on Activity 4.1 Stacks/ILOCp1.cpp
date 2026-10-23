#include <iostream>
#include <string>

const int MAX = 100;

char stack[MAX];
int top = -1;

//Check if stack is empty
bool isEmpty() {
    return top == -1;
}

//Push a symbol into the stack
void push(char value) {
    if (top == MAX - 1) {
        std::cout << "Stack Overflow." << std::endl;
        return;
    }

    top++;
    stack[top] = value;
}

//Pop a symbol from the stack
char pop() {
    if (isEmpty()) {
        return '\0';
    }

    char value = stack[top];
    top--;

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

    //Reset the stack
    top = -1;

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

            //Pop the opening symbol
            char opening = pop();

            //Check if symbols match
            if (!isMatching(opening, character)) {
                return false;
            }
        }

        //Other characters are ignored
    }

    //If stack is not empty, there is an unmatched symbol
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