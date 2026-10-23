//ILOA
#include <iostream>
#include <stack>

int main() {

    std::stack<int> stack1;

    //Testing empty
    std::cout << "Testing empty(): "
              << stack1.empty() << std::endl;

    //Testing push
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    std::cout << "After push(): "
              << stack1.top() << std::endl;

    //Testing top
    std::cout << "Testing top(): "
              << stack1.top() << std::endl;

    //Testing size
    std::cout << "Testing size(): "
              << stack1.size() << std::endl;

    //Testing pop
    stack1.pop();

    std::cout << "After pop(), top is: "
              << stack1.top() << std::endl;

    //Testing size again
    std::cout << "Size after pop(): "
              << stack1.size() << std::endl;

    //Testing emplace
    stack1.emplace(40);

    std::cout << "After emplace(), top is: "
              << stack1.top() << std::endl;

    //Creating another stack for swap
    std::stack<int> stack2;

    stack2.push(100);
    stack2.push(200);

    //Testing swap
    stack1.swap(stack2);

    std::cout << "After swap(), stack1 top is: "
              << stack1.top() << std::endl;

    return 0;
}