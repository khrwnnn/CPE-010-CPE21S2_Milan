#include <iostream>
#include <stack>

int main(){

    std::stack<int> stack1;
    std::stack<int> stack2;
    std::cout<<"Testing the stack STL"<<std::endl;

    //isEmpty
    std::cout<<"is the stack empty? "<< stack1.empty()<<std::endl;
    //push
    stack1.push(10);
    std::cout<< "The top of the stack is " << stack1.top()<<std::endl;

    stack1.push(9);
    std::cout<< "The top of the stack is " << stack1.top()<<std::endl;

    stack1.push(8);
    std::cout<< "The top of the stack is " << stack1.top()<<std::endl;

    stack1.push(7);
    std::cout<< "The top of the stack is " << stack1.top()<<std::endl;

    stack1.pop();
    std::cout<<"The top of the stack is "<< stack1.top() <<std::endl;

    std::cout<<"is the stack empty? "<<stack1.empty()<<std::endl;

    std::cout<<"the size of the stack is: " << stack1.size()<<std::endl;

    

    stack1.emplace(6);
    std::cout<<"the top of the stack is " <<stack1.top() <<std::endl;

    stack1.emplace(5);
    std::cout<<"the top of the stack is " <<stack1.top() <<std::endl;
    
    stack1.emplace(4);
    std::cout<<"the top of the stack is " <<stack1.top() <<std::endl;

    stack1.emplace(3);
    std::cout<<"the top of the stack is " <<stack1.top() <<std::endl;


    stack1.swap(stack2);
    std::cout << "After swap, stack1 size is: " << stack1.size() << std::endl;





    return 0;


    




}