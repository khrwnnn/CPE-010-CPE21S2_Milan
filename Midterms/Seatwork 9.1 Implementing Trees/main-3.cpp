#include <iostream>
#include "binaryTree.h"

int main(){

    //creating the root node
    BinaryTree<char>* root = new BinaryTree<char>('A');

    //creating children of root node "A"
    root->insertLeftChild('B');
    root->insertRightChild('C');

    //adding a child to a child
    root->getLeftChild()->insertLeftChild('D');
    root->getLeftChild()->insertRightChild('F');

    root->getRightChild()->insertLeftChild('E');

    //printing the root node
    std::cout << "Root value: " << root->getKey() << '\n';
    std::cout << "Left child of root: " << root->getLeftChild()->getKey() << '\n';
    std::cout << "Right child of root: " << root->getRightChild()->getKey() << '\n';

    std::cout << "Left child of root: " << root->getLeftChild()->getLeftChild()->getKey() << '\n';
    std::cout << "Right child of root: " << root->getLeftChild()->getRightChild()->getKey() << '\n';

    //replacing child F
    root->getLeftChild()->getRightChild()->changeKey('K');
    std::cout << "Right child of root: " << root->getLeftChild()->getRightChild()->getKey() << '\n';
    return 0;
}